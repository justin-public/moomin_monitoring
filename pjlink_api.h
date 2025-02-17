#ifndef PJLINK_API_H
#define PJLINK_API_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>

class PJLinkThread : public QThread
{
    Q_OBJECT
public:
    PJLinkThread(int index, const QString &ip, QObject *parent = nullptr);
    ~PJLinkThread();
    void run() override;
    void stopThread();
    void setMonitoringInterval(int interval);

signals:
    //void statusUpdated(int index, const QString &status);
    //void statusUpdated(const QString &address, const QString &status);
    void statusUpdated(const QString &address,bool projecotstatus);

    void lampTimeUpdated(const QString &address, int currentLampTime, int totalLampCount);

private:
    int projectorIndex;
    QString ipAddress;
    QTcpSocket *socket;
    QMutex mutex;
    QWaitCondition condition;
    bool stopped;

    void connectToProjector();
    void checkProjectorStatus();
    void checkLampTime();
    QString sendPJLinkCommand(const QString &command);

    //void setMonitoringInterval(int interval);
    int monitoringInterval;
    bool projectorstatus;

    // initialize setting
    // int loadtest;
};

class PJLinkAPI : public QObject
{
    Q_OBJECT
public:
    explicit PJLinkAPI(QObject *parent = nullptr);
    ~PJLinkAPI();
    void startMonitoring(const QVector<QString>& ipAddresses);
    void stopMonitoring();
    void PjlinkPeriodvalue(int interval);

signals:
    void projectorStatusUpdated(const QString &address,bool projecotstatus);
    void projectorLampTimeUpdated(const QString &address, int currentLampTime, int totalLampCount);

private:
    QVector<PJLinkThread*> projectorThreads;
    static int projectorperiodvalue;
    //static int getProjectorValue();
};

#endif // PJLINK_API_H
