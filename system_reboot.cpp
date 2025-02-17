#include "system_reboot.h"
#include <QDebug>
#include <QProcess>

SystemWorker::SystemWorker(QObject *parent)
    : QThread(parent), stoped(false)
{
}

SystemWorker::~SystemWorker()
{
    stopThread();
}

void SystemWorker::setRebootTime(const QTime &time)
{
    QMutexLocker locker(&mutex);
    rebootTime = time;
}

void SystemWorker::run()
{
    while (!stoped) {
        QTime currentTime = QTime::currentTime();

        mutex.lock();
        if (currentTime.hour() == rebootTime.hour() && currentTime.minute() == rebootTime.minute() && currentTime.second() == rebootTime.second()) {
            qDebug() << "Rebooting system...";
            QProcess::execute("sudo", QStringList()<< "reboot" << "-f" << "now");
            break;
        }
        mutex.unlock();
        QThread::sleep(1);      // 나중에 이슈가 있으면 조절 필요
    }
}

void SystemWorker::stopThread()
{
    QMutexLocker locker(&mutex);
    stoped = true;
}
