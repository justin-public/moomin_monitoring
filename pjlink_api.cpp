#include "pjlink_api.h"
#include <QDebug>

int PJLinkAPI::projectorperiodvalue;

PJLinkThread::PJLinkThread(int index, const QString &ip, QObject *parent)
    : QThread(parent), projectorIndex(index), ipAddress(ip), socket(nullptr), stopped(false)
{
}

PJLinkThread::~PJLinkThread()
{
    stopThread();
    wait();
}

void PJLinkThread::run()
{
    if (socket) {
        delete socket;
    }
    socket = new QTcpSocket();

    connect(socket, &QTcpSocket::disconnected, this, [this]() {
        qDebug() << "Socket disconnected for IP:" << ipAddress;
            projectorstatus = false;
            emit statusUpdated(ipAddress, projectorstatus);
        });

        while (!stopped) {
            try {
                connectToProjector();

                if (socket->state() == QAbstractSocket::ConnectedState) {
                    checkProjectorStatus();
                    if (projectorstatus) {
                        checkLampTime();
                    }
                }

                mutex.lock();
                condition.wait(&mutex, monitoringInterval * 1000);
                mutex.unlock();

            } catch (const std::exception& e) {
                qDebug() << "Exception in run loop for IP:" << ipAddress << ":" << e.what();
            } catch (...) {
                qDebug() << "Unknown exception in run loop for IP:" << ipAddress;
            }
        }

        delete socket;
        socket = nullptr;
}

void PJLinkThread::stopThread()
{
    mutex.lock();
    stopped = true;
    condition.wakeOne();
    mutex.unlock();
}

void PJLinkThread::connectToProjector()
{
    QMutexLocker locker(&mutex);

    if (socket->state() != QAbstractSocket::ConnectedState){
        if (socket->state() != QAbstractSocket::UnconnectedState){
            socket->abort();  // 기존 연결 강제 종료
        }
        socket->connectToHost(ipAddress, 4352);
        if (socket->waitForConnected(3000)){
            qDebug() << "Successfully connected to projector:" << ipAddress;
            projectorstatus = false;
            emit statusUpdated(ipAddress, projectorstatus);
            emit lampTimeUpdated(ipAddress, 0, 0);
        }
        else{
            qDebug() << "Failed to connect to projector:" << ipAddress;
            projectorstatus = false;
            emit statusUpdated(ipAddress, projectorstatus);
        }
    }
}

void PJLinkThread::checkProjectorStatus(){
    QString powerStatus = sendPJLinkCommand("%1POWR ?\r");
    qDebug() << "프로젝터 전원 상태 확인 : " << ipAddress << ":" << powerStatus;

        // 이전 상태 저장
        bool previousStatus = projectorstatus;

        if (powerStatus == "연결안됨" || powerStatus == "타임아웃" ||
            powerStatus == "통신 오류" || powerStatus == "응답없음") {
            // 통신 문제 발생 시 재연결 시도
            socket->disconnectFromHost();
            connectToProjector();
            return;
        }

        if (powerStatus == "%1POWR=0" || powerStatus == "%1POWR=ERR3") {
            projectorstatus = false;
        }
        else if (powerStatus == "%1POWR=1") {
            projectorstatus = true;
        }

        // 상태가 변경되었을 때만 시그널 발생
        if (previousStatus != projectorstatus) {
            emit statusUpdated(ipAddress, projectorstatus);
        }
}

void PJLinkThread::checkLampTime(){
    QString lampTimeResponse = sendPJLinkCommand("%1LAMP ?\r");
    QStringList lampTimeData = lampTimeResponse.split("=");
    QStringList lampTimeData_1 = lampTimeData[1].split(" ");

    if(lampTimeData_1.size() >= 2){
        int currentLampTime = lampTimeData_1[0].toInt();
        int totalLampCount = lampTimeData_1[1].toInt();
        emit lampTimeUpdated(ipAddress, currentLampTime,totalLampCount);
    }
}

QString PJLinkThread::sendPJLinkCommand(const QString &command){
    QMutexLocker locker(&mutex);

    if (!socket) {
        qDebug() << "Socket is null for IP:" << ipAddress;
        return "소켓 오류";
    }

    try {
        if (socket->state() != QAbstractSocket::ConnectedState) {
            qDebug() << "Socket not connected for IP:" << ipAddress;
            return "연결안됨";
        }

        if (socket->write(command.toUtf8()) == -1) {
            qDebug() << "Failed to write command for IP:" << ipAddress;
            return "전송오류";
        }

        socket->flush();

        // 타임아웃 값 조정
        int timeout = command.contains("POWR") ? 30000 : 5000;  // 전원 명령은 30초로 증가

        if (socket->waitForReadyRead(timeout)) {
            QByteArray response;
            do {
                response += socket->readAll();
            } while (socket->waitForReadyRead(1000));  // 추가 데이터 대기 시간 조정

            if (response.isEmpty()) {
                qDebug() << "Empty response from IP:" << ipAddress;
                return "응답없음";
            }

            return QString::fromUtf8(response).trimmed();
        }

        qDebug() << "Response timeout from IP:" << ipAddress;
        return "타임아웃";

    } catch (const std::exception& e) {
        qDebug() << "Exception for IP:" << ipAddress << ":" << e.what();
        return "예외발생";
    } catch (...) {
        qDebug() << "Unknown exception for IP:" << ipAddress;
        return "알수없는오류";
    }
}

void PJLinkThread::setMonitoringInterval(int interval){
    mutex.lock();
    monitoringInterval = interval;
    mutex.unlock();
}

PJLinkAPI::PJLinkAPI(QObject *parent) : QObject(parent)
{
}

PJLinkAPI::~PJLinkAPI()
{
    stopMonitoring();
}

void PJLinkAPI::startMonitoring(const QVector<QString>& ipAddresses)
{
    for (int i = 0; i < ipAddresses.size(); ++i) {
        PJLinkThread *thread = new PJLinkThread(i, ipAddresses[i], this);
        thread->setMonitoringInterval(projectorperiodvalue);
        connect(thread, &PJLinkThread::statusUpdated,this, &PJLinkAPI::projectorStatusUpdated);
        connect(thread, &PJLinkThread::lampTimeUpdated,this, &PJLinkAPI::projectorLampTimeUpdated);
        projectorThreads.append(thread);
        thread->start();
    }
}

void PJLinkAPI::stopMonitoring()
{
    for (auto thread : projectorThreads) {
        thread->stopThread();
        thread->wait();
    }
    qDeleteAll(projectorThreads);
    projectorThreads.clear();
}

void PJLinkAPI::PjlinkPeriodvalue(int interval){
    projectorperiodvalue = interval;
}





























