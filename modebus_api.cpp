#include "modebus_api.h"
#include <QDebug>
#include <QThread>

ModeBus::ModeBus(QObject *parent)
    : QObject(parent), isRunning(true)
{
    serial = new QSerialPort(this);
}

ModeBus::~ModeBus()
{
    if (serial->isOpen()) {
        serial->close();
    }
    delete serial;
}

void ModeBus::stop()
{
    mutex.lock();
    isRunning = false;
    mutex.unlock();
}

bool ModeBus::initializeSerial()
{
    if (serial->isOpen()) {
        return true;
    }

    serial->setPortName("/dev/ttyUSB0");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if (!serial->open(QIODevice::ReadWrite)) {
        emit errorOccurred("Failed to open serial port");
        return false;
    }
    return true;
}

float ModeBus::readSensor(const QByteArray &frame)
{
    QMutexLocker locker(&mutex);

    if (!serial->isOpen()) {
        if (!initializeSerial()) {
            return -999.0f;
        }
    }

    serial->clear();
    serial->write(frame);

    if (!serial->waitForBytesWritten(1000)) {
        emit errorOccurred("Write timeout");
        return -999.0f;
    }

    if (!serial->waitForReadyRead(1000)) {
        emit errorOccurred("Read timeout");
        return -999.0f;
    }

    QByteArray response = serial->read(7);
    if (response.size() != 7) {
        emit errorOccurred("Invalid response size");
        return -999.0f;
    }

    return parseResponse(response);
}

void ModeBus::process()
{
    while (isRunning) {
        if (!serial->isOpen() && !initializeSerial()) {
            QThread::sleep(1);
            continue;
        }

        // Read temperature
        float temp = readSensor(tempFrame);
        if (temp != -999.0f) {
            emit temperatureRead(temp);
        }

        QThread::msleep(1500);

        if (!isRunning) break;

        // Read humidity
        float humid = readSensor(humidFrame);
        if (humid != -999.0f) {
            emit humidityRead(humid);
        }

        QThread::msleep(1500);
    }
}

float ModeBus::parseResponse(const QByteArray &response)
{
    if (response.size() < 5) return -999.0f;
    uint16_t value = ((uint8_t)response[3] << 8) | (uint8_t)response[4];
    return value / 10.0f;
}


































