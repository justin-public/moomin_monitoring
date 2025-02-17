#ifndef PING_API_H
#define PING_API_H

#include <QObject>
#include <QThread>
#include <QString>
#include <QVector>

class PingWorker : public QThread{
    Q_OBJECT

public:
    explicit PingWorker(QObject *parent = nullptr);
    void setTargets(const QVector<QString>& addresses);
    void stop();
    void PingPeriod(int interval);

protected:
    void run() override;

signals:
    void pingResult(const QString& address, bool isSuccess);

private:
    QVector<QString> targetAddresses;
    bool isRunning;
    bool pingHost(const QString& address);
    static QString pingperiodevalue;
};

#endif // PING_API_H
