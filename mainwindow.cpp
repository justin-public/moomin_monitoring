#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTime>
#include <QTimer>
#include <QMessageBox>

#define SLACK_TOKEN ""
#define CHANNEL "#moommin-prj"
#define CHANNEL1 "#eventdevice"

QString Prj1state_copy = "";
QString Prj2state_copy = "";
QString Prj3state_copy = "";
QString Prj4state_copy = "";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 설정 정보 로드
    config_readFile();

    // 슬랙 메신저
    slackThread = new QThread(this);
    slack = new Slack();
    slack->moveToThread(slackThread);
    connect(slackThread, &QThread::finished, slack, &QObject::deleteLater);
    connect(this, &MainWindow::startMessageSending, slack, &Slack::sendMessage);
    connect(slack, &Slack::messageSent, this, &MainWindow::onMessageSent);
    slackThread->start();

    // 운영 시작 알림
    dailyTimer = new QTimer(this);
    connect(dailyTimer, &QTimer::timeout, this, &MainWindow::sendDailyMessage);
    setDailyTimer();

    // 운영 종료 알림
    dailyTimer1 = new QTimer(this);
    connect(dailyTimer1, &QTimer::timeout, this, &MainWindow::sendDailyendMessage);
    setDailyendTimer();

    // 시스템 리부팅
    worker = new SystemWorker(this);
    QTime rebootTime = QTime(hourvalue,minvalue, 2);
    worker->setRebootTime(rebootTime);
    worker->start();

    // 날씨 상태 모니터링
    weatherThread = new QThread(this);
    weather = new Weather();
    weather->moveToThread(weatherThread);
    connect(weatherThread, &QThread::started, weather, &Weather::fetchWeatherData);
    connect(weather, &Weather::weatherDataReceived, this, &MainWindow::updateWeatherData);
    connect(weatherThread, &QThread::finished, weather, &QObject::deleteLater);
    connect(weatherThread, &QThread::finished, weatherThread, &QObject::deleteLater);
    weatherThread->start();

    // 프로젝터 상태확인
    pjLinkAPI = new PJLinkAPI(this);
    connect(pjLinkAPI, &PJLinkAPI::projectorStatusUpdated,this, &MainWindow::onProjectorStatusUpdated);
    connect(pjLinkAPI, &PJLinkAPI::projectorLampTimeUpdated,this, &MainWindow::lampProjectorStatusUpdated);
    QVector<QString> ipAddresses = {projector1, projector2,projector3, projector4};
    pjLinkAPI->startMonitoring(ipAddresses);

    //PC 상태확인
    setupPingMonitor();

    //온습도 센서 모니터링
    modebusworker = new ModeBus;
    modebusworker->moveToThread(&workerThread);
    //온습도 센서 슬롯 시그널 연결
    connect(&workerThread, &QThread::started, modebusworker, &ModeBus::process);    // 쓰레드 연결
    connect(modebusworker, &ModeBus::temperatureRead, this, &MainWindow::updateTemperature);
    connect(modebusworker, &ModeBus::humidityRead, this, &MainWindow::updateHumidity);

    //온습도 센서 쓰레드 시작
    workerThread.start();

    // GPIO 컨트롤러 초기화
    m_gpioController = new GPIOController(this);
    m_gpioWorker = new GPIOWorker(m_gpioController, this);

    connect(ui->relayControl_bt01, &QPushButton::clicked, m_gpioWorker, &GPIOWorker::setGPIOOn);
    connect(ui->relayControl_bt02, &QPushButton::clicked, m_gpioWorker, &GPIOWorker::setGPIOOff);
    connect(m_gpioController, &GPIOController::stateChanged, this, &MainWindow::handleGPIOStateChanged);
    connect(m_gpioController, &GPIOController::error, this, &MainWindow::handleGPIOError);

    if (!m_gpioController->initialize()){
        ui->relayControl_bt01->setEnabled(false);
        ui->relayControl_bt02->setEnabled(false);
    }

    //장비상태 확인변수
    countsend = 0;

    //로거 인스턴스 생성
    logger = new Logger("HW.log");                  // 하드웨어 로그 기록
    logger1 = new Logger1("Alarm.log");             // 알람 로그 기록

    //이벤트 데이
    eventApi = new EventDayApi(this);
    eventApi->startChecking();
}

MainWindow::~MainWindow()
{
    // 시스템 리부팅 해제
    worker->stopThread();
    worker->wait();

    // 쓰렉 쓰레드 종료
    slackThread->quit();
    slackThread->wait();
    delete slack;

    delete ui;
}

void MainWindow::config_readFile(){
    QFile file("config.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Failed to open file";
        return;
    }
    QTextStream in(&file);
    QString currentSection;
    QString currentKey;

    while(!in.atEnd()){
        QString line = in.readLine().trimmed();
        if (line.startsWith('<') && line.endsWith('>')){
            currentSection = line;
            currentKey = "";
        }
        else if(!line.isEmpty()){
            if (currentSection == "<EMT 세팅>"){
                emtSetting = line;
                QStringList rebootimelist = emtSetting.split(":");
                bool ok1, ok2;
                hourvalue = rebootimelist.value(0).toInt(&ok1);
                minvalue = rebootimelist.value(1).toInt(&ok2);

                if (ok1 && ok2){
                    qDebug() << "시간:" << hourvalue << "분:" << minvalue;
                }
                else {
                    qDebug() << "시간 변환중 오류 발생";
                }
            }
            else if (currentSection == "<<재부팅 시간<<"){
                rebootTime = line;
            }
            // 하드웨어 준비
            else if(currentSection == "<하드웨어주소>")
            {
                if (line.startsWith("<<") && line.endsWith("<<"))
                {
                    currentKey = line;
                }
                else{
                    if(currentKey == "<<Projector#1<<") projector1 = line;
                    if(currentKey == "<<Projector#2<<") projector2 = line;
                    if(currentKey == "<<Projector#3<<") projector3 = line;
                    if(currentKey == "<<Projector#4<<") projector4 = line;
                    if(currentKey == "<<Server PC<<")   serverPC = line;
                    if(currentKey == "<<Display PC<<")  displayPC = line;
                }
            }
            // 업데이트 주기
            else if(currentSection == "<UPDATE 주기>"){
                if(line.startsWith("<<") && line.endsWith("<<")){
                    updateInterval = in.readLine().trimmed().toInt();
                    weather->WeatherPeriod(updateInterval);
                    pingWorker->PingPeriod(updateInterval);
                    pjLinkAPI->PjlinkPeriodvalue(updateInterval);
                }
            }
            // 상시 알림 설정
            else if(currentSection == "<상시 알림 설정>"){
                if(line.startsWith("<<") && line.endsWith("<<")){
                    currentKey = line;
                }
                else{
                    if(currentKey == "<<시작확인 알림채널<<"){
                        startchvalue = line;
                        ui->targetChannel_val01->setText(startchvalue);
                    }
                    if(currentKey == "<<시작확인 알림시간<<"){
                        starttimevalue = line;
                        QStringList starttimelist = starttimevalue.split(":");
                        bool startok1;
                        bool startok2;
                        starthourvalue = starttimelist.value(0).toInt(&startok1);
                        startminutevalue = starttimelist.value(1).toInt(&startok2);
                        if (startok1 && startok2){
                            qDebug() << "시작 시간:" << starthourvalue << "시작 분:" << startminutevalue;
                        }
                    }
                    if(currentKey == "<<종료확인 알림채널<<"){
                        endchvalue = line;
                        ui->targetChannel_val02->setText(endchvalue);
                    }
                    if(currentKey == "<<종료확인 알림시간<<"){
                       endtimevalue = line;
                       QStringList endtimelist = endtimevalue.split(":");
                       bool endok1;
                       bool endok2;
                       endhourvalue = endtimelist.value(0).toInt(&endok1);
                       endminutevalue = endtimelist.value(1).toInt(&endok2);
                       if(endok1 && endok2){
                           qDebug() << "종료 시간:" << endhourvalue << "종료 분:" << endminutevalue;
                       }
                    }
                }
            }
        }
    }
}

void MainWindow::onMessageSent(bool success, const QString &errorString){
    if (success) {
        qDebug() << "Message sent successfully at " << QTime::currentTime().toString();
    }
    else {
        qDebug() << "Error sending message at " << QTime::currentTime().toString() << ": " << errorString;
    }
}

void MainWindow::setupPingMonitor(){
    pingWorker = new PingWorker(this);
    QVector<QString> targets = {
        serverPC,
        displayPC
    };
    connect(pingWorker, &PingWorker::pingResult,this, &MainWindow::handlePingResult);
    pingWorker->setTargets(targets);
    pingWorker->start();
}

void MainWindow::handlePingResult(const QString& address, bool isSuccess){
    //qDebug()<<address<<","<<isSuccess;
    totaldeviceEquiment1(address,isSuccess);
}

void MainWindow::onProjectorStatusUpdated(const QString& address,bool projectorstatus){
    totaldeviceEquiment1(address,projectorstatus);
}

// 프로젝터 램프 시간 업데이트
void MainWindow::lampProjectorStatusUpdated(const QString& address, int currentLampTime){
    if(address == projector1){
       QString projector1lamptime = QString::number(currentLampTime);
       ui->etc_val01->setText(projector1lamptime);
    }
    if(address == projector2){
        QString projector2lamptime = QString::number(currentLampTime);
        ui->etc_val02->setText(projector2lamptime);
    }
    if(address == projector3){
        QString projector3lamptime = QString::number(currentLampTime);
        ui->etc_val03->setText(projector3lamptime);
    }
    if(address == projector4){
        QString projector4lamptime = QString::number(currentLampTime);
        ui->etc_val04->setText(projector4lamptime);
    }
}

// 날씨 정보 업데이트
void MainWindow::updateWeatherData(const QString &temperature, const QString &humidity, const QString &weatherCondition){
    QString weatherDescription;

    currentTemperature = temperature;
    currentHumidity = humidity;

    if (weatherCondition == "0") currentWeatherDescription = "맑음";
    else if (weatherCondition == "1") currentWeatherDescription = "비";
    else if (weatherCondition == "2") currentWeatherDescription = "눈";
    else if (weatherCondition == "3") currentWeatherDescription = "비와 눈";
    else if (weatherCondition == "4") currentWeatherDescription = "소나기";
    else if (weatherCondition == "5") currentWeatherDescription = "천둥번개";
    else if (weatherCondition == "6") currentWeatherDescription = "안개";
    else if (weatherCondition == "7") currentWeatherDescription = "흐림";
    else currentWeatherDescription = "정보 없음";

    ui->localTemp_val->setText(currentTemperature);
    ui->insideHum_val->setText(currentHumidity);
    ui->localWeather_val->setText(currentWeatherDescription);

    //이벤트 날씨 정보 전달
    eventApi->weather_info(currentWeatherDescription);
}

void MainWindow::totaldeviceEquiment1(const QString& address,bool isSuccess){
    QString status = isSuccess ? "ON" : "OFF";
    qDebug()<<"value : "<<address<<","<<status;

    if(address == projector1 && status == "ON"){
        ui->pwState_val01->setText("ON");
        ui->pwState_val01->setStyleSheet("color: rgb(0,255,0);");
        Prj1state = "ON";
        Prj1state_copy = Prj1state;
    }
    if(address == projector1 && status == "OFF"){
        ui->pwState_val01->setText("OFF");
        ui->pwState_val01->setStyleSheet("color: rgb(255,85,127);");
        Prj1state = "OFF";
        Prj1state_copy = Prj1state;
    }
    if(address == projector2 && status == "ON"){
        ui->pwState_val02->setText("ON");
        ui->pwState_val02->setStyleSheet("color: rgb(0,255,0);");
        Prj2state = "ON";
        Prj2state_copy = Prj2state;
    }
    if(address == projector2 && status == "OFF"){
        ui->pwState_val02->setText("OFF");
        ui->pwState_val02->setStyleSheet("color: rgb(255,85,127);");
        Prj2state = "OFF";
        Prj2state_copy = Prj2state;
    }
    if(address == projector3 && status == "ON"){
        ui->pwState_val03->setText("ON");
        ui->pwState_val03->setStyleSheet("color: rgb(0,255,0);");
        Prj3state = "ON";
        Prj3state_copy = Prj3state;
    }
    if(address == projector3 && status == "OFF"){
        ui->pwState_val03->setText("OFF");
        ui->pwState_val03->setStyleSheet("color: rgb(255,85,127);");
        Prj3state = "OFF";
        Prj3state_copy = Prj3state;
    }
    if(address == projector4 && status == "ON"){
        ui->pwState_val04->setText("ON");
        ui->pwState_val04->setStyleSheet("color: rgb(0,255,0);");
        Prj4state = "ON";
        Prj4state_copy = Prj4state;
    }
    if(address == projector4 && status == "OFF"){
        ui->pwState_val04->setText("OFF");
        ui->pwState_val04->setStyleSheet("color: rgb(255,85,127);");
        Prj4state = "OFF";
        Prj4state_copy = Prj4state;
    }
    if(address == serverPC && status == "ON"){
        ui->pwState_val05->setText("ON");
        ui->pwState_val05->setStyleSheet("color: rgb(0,255,0);");
        ServerPCState = "ON";
    }
    if(address == serverPC && status == "OFF"){
        ui->pwState_val05->setText("OFF");
        ui->pwState_val05->setStyleSheet("color: rgb(255,85,127);");
        ServerPCState = "OFF";
    }
    if(address == displayPC && status == "ON"){
        ui->pwState_val06->setText("ON");
        ui->pwState_val06->setStyleSheet("color: rgb(0,255,0);");
        DisplayPCState = "ON";
    }
    if(address == displayPC && status == "OFF"){
        ui->pwState_val06->setText("OFF");
        ui->pwState_val06->setStyleSheet("color: rgb(255,85,127);");
        DisplayPCState = "OFF";
    }
    if(Prj1state == "ON" && Prj2state == "ON" && Prj3state == "ON" && Prj4state == "ON" && ServerPCState == "ON" && DisplayPCState == "ON")countsend = 0;
    if(Prj1state == "" || Prj2state == "" || Prj3state == "" || Prj4state == "" || ServerPCState == "" || DisplayPCState=="")countsend = 0;
    if(Prj1state == "OFF" || Prj2state == "OFF" || Prj3state == "OFF" || Prj4state == "OFF" || ServerPCState == "OFF" || DisplayPCState == "OFF"){
        countsend++;
        if(countsend == 7){
            QString token = SLACK_TOKEN;
            QDate msgcurrentDate = QDate::currentDate();

            int eventyearmsg = msgcurrentDate.year();
            int eventmonthmsg = msgcurrentDate.month();
            int eventdaymsg = msgcurrentDate.day();

            QString text = QString("%1/%2/%3 Moomin H/W State\nPrj#1 : %4\nPrj#2 : %5\nPrj#3 : %6\nPrj#4 : %7\nServerPC : %8\nDisplayPC : %9")
                                    .arg(eventyearmsg)
                                    .arg(eventmonthmsg)
                                    .arg(eventdaymsg)
                                    .arg(Prj1state_copy)
                                    .arg(Prj2state_copy)
                                    .arg(Prj3state_copy)
                                    .arg(Prj4state_copy)
                                    .arg(ServerPCState)
                                    .arg(DisplayPCState);
            emit startMessageSending(token, CHANNEL1, text);

            QString eventAlarm = QString("send/event alarm / Prj#1:%1 / Prj#2:%2 / Prj#3:%3 / Prj#4:%4 / ServerPC:%5 / DisplayPC : %6")
                                    .arg(Prj1state_copy)
                                    .arg(Prj2state_copy)
                                    .arg(Prj3state_copy)
                                    .arg(Prj4state_copy)
                                    .arg(ServerPCState)
                                    .arg(DisplayPCState);
            logger1->writeLog(eventAlarm);
        }
    }
}

void MainWindow::setDailyTimer(){
    QTime scheduledTime(starthourvalue, startminutevalue, 01);
    QTime currentTime = QTime::currentTime();

    int msecsUntilScheduled = currentTime.msecsTo(scheduledTime);
    if (msecsUntilScheduled < 0) {
        msecsUntilScheduled += 24 * 60 * 60 * 1000;
    }
    dailyTimer->setSingleShot(true);
    dailyTimer->start(msecsUntilScheduled);
}

void MainWindow::setDailyendTimer(){
    QTime scheduledTime(endhourvalue, endminutevalue, 01);
    QTime currentTime = QTime::currentTime();

    int msecsUntilScheduled = currentTime.msecsTo(scheduledTime);
    if (msecsUntilScheduled < 0) {
        msecsUntilScheduled += 24 * 60 * 60 * 1000;
    }
    dailyTimer1->setSingleShot(true);
    dailyTimer1->start(msecsUntilScheduled);
}

void MainWindow::sendDailyMessage(){
    QString token = SLACK_TOKEN;
    QDate msgcurrentDate = QDate::currentDate();

    int yearmsg = msgcurrentDate.year();
    int monthmsg = msgcurrentDate.month();
    int daymsg = msgcurrentDate.day();

    if(startchvalue == "Moomin State_All"){
        QString text = QString("%1/%2/%3 Moomin H/W State\nPrj#1 : %4\nPrj#2 : %5\nPrj#3 : %6\nPrj#4 : %7\nServerPC : %8\nDisplayPC : %9")
                                        .arg(yearmsg)
                                        .arg(monthmsg)
                                        .arg(daymsg)
                                        .arg(Prj1state_copy)
                                        .arg(Prj2state_copy)
                                        .arg(Prj3state_copy)
                                        .arg(Prj4state_copy)
                                        .arg(ServerPCState)
                                        .arg(DisplayPCState);
        emit startMessageSending(token, CHANNEL, text);

        QString startAlarm = QString("send/start alarm / Prj#1:%1 / Prj#2:%2 / Prj#3:%3 / Prj#4:%4 / ServerPC:%5 / DisplayPC : %6")
                                .arg(Prj1state_copy)
                                .arg(Prj2state_copy)
                                .arg(Prj3state_copy)
                                .arg(Prj4state_copy)
                                .arg(ServerPCState)
                                .arg(DisplayPCState);
        logger1->writeLog(startAlarm);
    }
    setDailyTimer();
}

void MainWindow::sendDailyendMessage(){
    QString token = SLACK_TOKEN;

    QDate msgcurrentDate = QDate::currentDate();
    int yearmsg = msgcurrentDate.year();
    int monthmsg = msgcurrentDate.month();
    int daymsg = msgcurrentDate.day();

    if(endchvalue == "Moomin State_All"){
        QString text = QString("%1/%2/%3 Moomin H/W State\nPrj#1 : %4\nPrj#2 : %5\nPrj#3 : %6\nPrj#4 : %7\nServerPC : %8\nDisplayPC : %9")
                            .arg(yearmsg)
                            .arg(monthmsg)
                            .arg(daymsg)
                            .arg(Prj1state_copy)
                            .arg(Prj2state_copy)
                            .arg(Prj3state_copy)
                            .arg(Prj4state_copy)
                            .arg(ServerPCState)
                            .arg(DisplayPCState);
        emit startMessageSending(token, CHANNEL, text);

        QString endAlarm = QString("send/end alarm / Prj#1:%1 / Prj#2:%2 / Prj#3:%3 / Prj#4:%4 / ServerPC:%5 / DisplayPC : %6")
                                .arg(Prj1state_copy)
                                .arg(Prj2state_copy)
                                .arg(Prj3state_copy)
                                .arg(Prj4state_copy)
                                .arg(ServerPCState)
                                .arg(DisplayPCState);
        logger1->writeLog(endAlarm);
    }
    setDailyendTimer();
}

void MainWindow::updateTemperature(float temp){
    ui->insideTemp_val->setText(QString("%1").arg(temp));
}

void MainWindow::updateHumidity(float humid){
     ui->insideHum_val->setText(QString("%1").arg(humid));
}

void MainWindow::handleGPIOStateChanged(bool isOn){
    ui->relayControl_bt01->setEnabled(!isOn);
    ui->relayControl_bt02->setEnabled(isOn);

    if(isOn == true){
        ui->relayState_val01->setText("ON");
        ui->relayState_val01->setStyleSheet("color: rgb(0,255,0);");
    }
    else if(isOn == false){
        ui->relayState_val01->setText("OFF");
        ui->relayState_val01->setStyleSheet("color: rgb(255,85,127);");
    }
}

void MainWindow::BGMconfig_readFile(){
    QFile file("BGM_config.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Failed to open file";
        return;
    }
    QTextStream in(&file);
    QString currentSection;
    QString currentKey;
    QStringList seasonData;

    while(!in.atEnd()){
        QString line = in.readLine().trimmed();
        if (line.startsWith('<') && line.endsWith('>')){
            currentSection = line;
            currentKey = "";
        }
        else if(!line.isEmpty()){
            if(currentSection == "<BGM 설정>"){
                if (line.startsWith("<<") && line.endsWith("<<")){
                    currentKey = line;
                }
                else{
                    if(currentKey=="<<파일교체시간<<"){
                        qDebug()<<line;
                        QStringList filereplacement = line.split(":");
                        bool replaceok;
                        bool replaceok1;
                        int replacehour = filereplacement.value(0).toInt(&replaceok);
                        int replaceminute = filereplacement.value(1).toInt(&replaceok1);

                        eventApi->replace_time_info(replacehour,replaceminute);
                    }
                    if(currentKey=="<<계절기간<<")seasonData.append(line);
                    if(currentKey=="<<Christmas<<"){
                        qDebug()<<line;
                    }
                    if(currentKey=="<<Children's Day<<"){
                        qDebug()<<line;
                    }
                }
            }
        }
    }
    file.close();
    if(!seasonData.isEmpty()){
        QString spring = seasonData[0];  // 봄 데이터
        QString summer = seasonData[1];  // 여름 데이터
        QString autumn = seasonData[2];  // 가을 데이터
        QString winter = seasonData[3];  // 겨울 데이터

        QStringList springParts = spring.split('/');
        QStringList summerParts = summer.split('/');
        QStringList autumnParts = autumn.split('/');
        QStringList winterParts = winter.split('/');

        qDebug() << "봄 기간" << springParts[1];
        qDebug() << "여름 기간" << summerParts[1];
        qDebug() << "가을 기간" << autumnParts[1];
        qDebug() << "겨울 기간" << winterParts[1];

        QStringList springdatelist = springParts[1].split("~");
        QStringList springdatestart = springdatelist[0].split(".");
        bool springstartok;
        bool springstartok1;

        int springstartmonth = springdatestart.value(0).toInt(&springstartok);
        int springstartday = springdatestart.value(1).toInt(&springstartok1);
        eventApi->spring_date_info(springstartmonth,springstartday);

        QStringList autumndatelist = autumnParts[1].split("~");
        QStringList autumndatestart = autumndatelist[0].split(".");
        bool autumnstartok;
        bool autumnstartok1;

        int autumnstartmonth = autumndatestart.value(0).toInt(&autumnstartok);
        int autumnstartday = autumndatestart.value(1).toInt(&autumnstartok1);
        eventApi->autumn_date_info(autumnstartmonth,autumnstartday);
    }
}

void MainWindow::handleGPIOError(const QString &message) {
    QMessageBox::warning(this, "GPIO 연결 문제 발생", message);
}






































































