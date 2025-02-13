#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 설정 정보 로드
    config_readFile();

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
}

MainWindow::~MainWindow()
{
    // 시스템 리부팅 해제
    worker->stopThread();
    worker->wait();

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

                }
            }
        }
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
    ui->localWeather_val->setText(currentWeatherDescription);
}

void MainWindow::totaldeviceEquiment1(const QString& address,bool isSuccess){
    QString status = isSuccess ? "ON" : "OFF";
    qDebug()<<"value : "<<address<<","<<status;

    if(address == projector1 && status == "ON"){
        ui->pwState_val01->setText("ON");
        ui->pwState_val01->setStyleSheet("color: rgb(0,255,0);");
        Prj1state = "ON";
    }
    if(address == projector1 && status == "OFF"){
        ui->pwState_val01->setText("OFF");
        ui->pwState_val01->setStyleSheet("color: rgb(255,85,127);");
        Prj1state = "OFF";
    }
    if(address == projector2 && status == "ON"){
        ui->pwState_val02->setText("ON");
        ui->pwState_val02->setStyleSheet("color: rgb(0,255,0);");
        Prj2state = "ON";
    }
    if(address == projector2 && status == "OFF"){
        ui->pwState_val02->setText("OFF");
        ui->pwState_val02->setStyleSheet("color: rgb(255,85,127);");
        Prj2state = "OFF";
    }
    if(address == projector3 && status == "ON"){
        ui->pwState_val03->setText("ON");
        ui->pwState_val03->setStyleSheet("color: rgb(0,255,0);");
        Prj3state = "ON";
    }
    if(address == projector3 && status == "OFF"){
        ui->pwState_val03->setText("OFF");
        ui->pwState_val03->setStyleSheet("color: rgb(255,85,127);");
        Prj3state = "OFF";
    }
    if(address == projector4 && status == "ON"){
        ui->pwState_val04->setText("ON");
        ui->pwState_val04->setStyleSheet("color: rgb(0,255,0);");
        Prj4state = "ON";
    }
    if(address == projector4 && status == "OFF"){
        ui->pwState_val04->setText("OFF");
        ui->pwState_val04->setStyleSheet("color: rgb(255,85,127);");
        Prj4state = "OFF";
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
    if(ServerPCState == "" && DisplayPCState == "")countsend = 0;
    if(ServerPCState == "OFF" && DisplayPCState == "OFF"){

    }
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

void MainWindow::handleGPIOError(const QString &message) {
    QMessageBox::warning(this, "GPIO 연결 문제 발생", message);
}
























