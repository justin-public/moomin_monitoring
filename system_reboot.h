#ifndef SYSTEM_REBOOT_H
#define SYSTEM_REBOOT_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QTime>

class SystemWorker : public QThread{
    Q_OBJECT

public:
    SystemWorker(QObject *parent = nullptr);
    ~SystemWorker();
    void run() override;
    void stopThread();
    void setRebootTime(const QTime &time);

private:
    QMutex mutex;
    bool stoped;
    QTime rebootTime;
};

#endif // SYSTEM_REBOOT_H
