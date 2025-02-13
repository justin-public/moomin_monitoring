#ifndef GPIO_API_H
#define GPIO_API_H

#include <QObject>
#include <QMutex>
#include <QThread>
#include <gpiod.h>

class GPIOController : public QObject{
    Q_OBJECT

   public:
       explicit GPIOController(QObject *parent = nullptr);
       ~GPIOController();

       bool initialize();
       bool setValue(int value);
       bool isInitialized() const { return m_initialized; }

   signals:
       void stateChanged(bool isOn);
       void error(const QString &message);

   private:
       QMutex m_mutex;
       struct gpiod_chip *m_chip;
       struct gpiod_line *m_line;
       const char* m_chipname = "gpiochip0";
       const unsigned int m_lineNum = 18;
       bool m_initialized;

       void cleanup();
};

class GPIOWorker : public QThread{
    Q_OBJECT

    public:
        explicit GPIOWorker(GPIOController *controller, QObject *parent = nullptr);

    public slots:
        void setGPIOOn();
        void setGPIOOff();

    private:
        GPIOController *m_controller;
};

#endif // GPIO_API_H
