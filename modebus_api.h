#ifndef MODEBUS_API_H
#define MODEBUS_API_H

#include <QObject>
#include <QSerialPort>
#include <QMutex>
#include <QThread>

class ModeBus : public QObject
{
    Q_OBJECT
    public:
        explicit ModeBus(QObject *parent = nullptr);
        ~ModeBus();

        void stop();

    public slots:
        void process();

    signals:
        void temperatureRead(float temp);
        void humidityRead(float humid);
        void errorOccurred(const QString &error);

    private:
        QSerialPort *serial;
        QMutex mutex;
        volatile bool isRunning;

        const QByteArray tempFrame = QByteArray::fromHex("010400010001600a");
        const QByteArray humidFrame = QByteArray::fromHex("010400020001900a");

        bool initializeSerial();
        float readSensor(const QByteArray &frame);
        float parseResponse(const QByteArray &response);
};

#endif // MODEBUS_API_H
