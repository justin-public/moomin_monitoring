#ifndef EVENTDAY_API_H
#define EVENTDAY_API_H

#include <QObject>
#include <QDate>
#include <QThread>
#include <QString>
#include <QTimer>

class EventDayApi : public QObject {
    Q_OBJECT

public:
    explicit EventDayApi(QObject *parent = nullptr);
    void startChecking();
    void stopChecking();
    // 날씨 정보 전달 연결
    void weather_info(QString value);
    void replace_time_info(int value, int value1);
    void spring_date_info(int value, int value1);
    void autumn_date_info(int value, int value1);

//signals:
    //void seasonChanged(const QString &season, const QString &events);

private:
    void checkSeason();
    void copyFilesByCondition(const QString& season, const QString& weather);

    //QString getCurrentSeason() const;
    //QString getEvents() const;
    void getCurrentSeason();
    void getEvents();

    QThread *thread;
    QTimer *timer;
    QDate lastCheckedDate;

    static QString weathervalue;

    // 이벤트 타이머 함수
    void setDailyTimer();
    static int replacehourvalue;
    static int replaceminutevalue;

    // 봄 일
    static int springdatemonthstart;
    static int springdatedaystart;

    // 가을 일
    static int autumndatemonthstart;
    static int autumndatedaystart;
};

#endif // EVENTDAY_API_H
