#include "ping_api.h"
#include <QProcess>
#include <QDebug>
#include <QOperatingSystemVersion>

QString PingWorker::pingperiodevalue = "";

PingWorker::PingWorker(QObject *parent) : QThread(parent), isRunning(false) {}

void PingWorker::setTargets(const QVector<QString>& addresses){
    targetAddresses = addresses;
}

void PingWorker::stop() {
    isRunning = false;
}

void PingWorker::PingPeriod(int interval){
    pingperiodevalue = QString::number(interval * 1000);
    qDebug() << "PC periode: " << pingperiodevalue;
}

bool PingWorker::pingHost(const QString& address){
    QProcess process;
    QStringList arguments;

    //arguments << "-c" << "1" << "-W" << pingperiodevalue << address;   // �ϵ����� �ֱ� ����
    //arguments << "-c" << "1" << "-W" << "2" << address;

    //process.start("ping", arguments);
    //process.waitForFinished();

    // window os
    if (QOperatingSystemVersion::currentType() == QOperatingSystemVersion::Windows){
        arguments << "-n" << "1" << "-w" << pingperiodevalue << address;
    }
    else {
        // Linux os
        arguments << "-c" << "1" << "-W" << "2" << address;
    }
    process.start("ping", arguments);
    process.waitForFinished();
    return process.exitCode() == 0;
}

void PingWorker::run() {
    isRunning = true;
    while (isRunning) {
        for (const QString& address : targetAddresses) {
            if (!isRunning) break;
            bool success = pingHost(address);
            emit pingResult(address, success);
        }
        if (isRunning) {
            QThread::sleep(5);
        }
    }
}
