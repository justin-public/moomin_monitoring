#include "eventday_api.h"
#include <QDebug>
#include <QDate>
#include <QMutex>
#include <QTime>
#include <QDir>
#include <QProcess>

QString lastSeason;
QString lastWeather;

QMutex mutex;

QString EventDayApi::weathervalue = "";
int EventDayApi::replacehourvalue;
int EventDayApi::replaceminutevalue;

int EventDayApi::springdatemonthstart;
int EventDayApi::springdatedaystart;

int EventDayApi::autumndatemonthstart;
int EventDayApi::autumndatedaystart;

EventDayApi::EventDayApi(QObject *parent) : QObject(parent), thread(nullptr), timer(new QTimer(this)) {
    lastCheckedDate = QDate();
    //checkSeason();

    // 이 부분을 현재는 5초마다 갱신 하지만 이부분 지정된 시간에 옮기는걸로 수정
    connect(timer, &QTimer::timeout, this, &EventDayApi::checkSeason);
    setDailyTimer();
    //timer->start(5000); // Check every minute , 60000
}

void EventDayApi::replace_time_info(int value, int value1){
    replacehourvalue = value;
    replaceminutevalue = value1;
}

void EventDayApi::spring_date_info(int value, int value1){
    springdatemonthstart = value;
    springdatedaystart = value1;
}

void EventDayApi::autumn_date_info(int value, int value1){
    autumndatemonthstart = value;
    autumndatedaystart = value1;
}

void EventDayApi::setDailyTimer(){
    QTime scheduledTime(replacehourvalue, replaceminutevalue, 1);
    QTime currentTime = QTime::currentTime();
    int msecsUntilScheduled = currentTime.msecsTo(scheduledTime);
    if (msecsUntilScheduled < 0) {
        msecsUntilScheduled += 24 * 60 * 60 * 1000;
    }
    timer->start(msecsUntilScheduled);
}

void EventDayApi::weather_info(QString value){
    if(value == "맑음")weathervalue = "clear";
    if(value == "비" || value=="소나기" || value=="천둥번개")weathervalue = "rain";
    if(value == "구름" || value == "안개")weathervalue = "cloud";
    if(value == "눈" || value == "비와 눈")weathervalue = "snow";
}

void EventDayApi::startChecking() {
    if (!thread) {
        thread = new QThread();
        this->moveToThread(thread);
        connect(thread, &QThread::started, this, &EventDayApi::checkSeason);
        connect(thread, &QThread::finished, thread, &QThread::deleteLater);
        thread->start();
    }
}

void EventDayApi::stopChecking() {
    if (thread) {
        thread->quit();
        thread->wait();
        delete thread;
        thread = nullptr;
    }
    timer->stop();
}

void EventDayApi::checkSeason() {
     QMutexLocker locker(&mutex);
     //qDebug() << "Checking season...";
     getCurrentSeason();
     getEvents();
     //emit seasonChanged(season, events);
     lastCheckedDate = QDate::currentDate();
}

void EventDayApi::copyFilesByCondition(const QString& season, const QString& weather){
    //if(season == lastSeason && weather == lastWeather){
       //qDebug() << "Conditions have not changed. Skipping file copy.";
       //return;
    //}
    QString SourcePath = "/home/pi/windowpi1";
    QString targetPath = "/home/pi/windowpi";

    QDir srcDir(SourcePath);
    QDir desDir(targetPath);

    QStringList destFiles = desDir.entryList(QDir::Files);
    foreach (const QString& file, destFiles){
         QString filePath = desDir.absoluteFilePath(file);
         //QFile::remove(filePath);
         QProcess::execute("sudo", QStringList()<< "rm" << "-f" << filePath);
    }

    QString filePattern = season + "_" + weather + "*";
    QStringList files = srcDir.entryList(QStringList() << filePattern,QDir::Files);
    qDebug() << files;
    foreach (const QString& file, files){
        QString srcPath = srcDir.absoluteFilePath(file);
        QString destPath = desDir.absoluteFilePath(file);
        QProcess::execute("sudo", QStringList()<< "cp" << "-f" << srcPath << targetPath);
    }
    //lastSeason = season;
    //lastWeather = weather;
    qDebug() << "Copied files for season: " << season << ", weather: " << weather;
}

/*
void EventDayApi::getCurrentSeason(){
    QDate currentDate = QDate::currentDate();
    int month = currentDate.month();

    qDebug() << "���� ��:" << month;

    // ����, ��¥
    if (month == 12 || month < 3) {
        copyFilesByCondition("winter",weathervalue);
    } else if (month < 6) {
        copyFilesByCondition("spring",weathervalue);
    } else if (month < 9) {
        copyFilesByCondition("summer",weathervalue);
    } else {
        copyFilesByCondition("autumn",weathervalue);
    }
}
*/

void EventDayApi::getCurrentSeason(){
    QDate currentDate = QDate::currentDate();
    int month = currentDate.month();
    int day = currentDate.day();

    //qDebug()<<"현재 월"<<month<<"현재 일"<<day;
    qDebug()<<autumndatemonthstart<<","<<autumndatedaystart;

    // 겨울(11월 11일 ~ 2월 20일)
    if((month == 11 && day >= 11) || month == 12 || month == 1 ||(month == 2 && day <=20)){
        copyFilesByCondition("winter",weathervalue);
    }
    // 봄(2월 21일 ~ 5월 31일)
    else if((month == springdatemonthstart && day >= springdatedaystart) || month == 3 || month == 4 ||(month == 5 && day <=31)){
        copyFilesByCondition("spring",weathervalue);
    }
    // 여름 (6월 1일 ~ 8월 31일)
    else if ((month == 6 && day >= 1) || month == 7 || (month == 8 && day <=31)){
        copyFilesByCondition("summer",weathervalue);
    }
    // 가을 (9월 1일 ~ 11월 10일)
    else if((month == autumndatemonthstart && day >= autumndatedaystart) || month == 10 || (month == 11 && day <=10)){
        copyFilesByCondition("autumn",weathervalue);
    }
}

void EventDayApi::getEvents(){
    QDate currentDate = QDate::currentDate();
    QString events;
    qDebug() << "Checking events for date:" << currentDate;
    if (currentDate.month() == 12 && currentDate.day() == 25) {
        copyFilesByCondition("event","christmas");
    }
    if (currentDate.month() == 5 && currentDate.day() == 5) {
        copyFilesByCondition("event","children");
    }
}

















































