#include "gpio_api.h"
#include <QDebug>

GPIOController::GPIOController(QObject *parent)
    : QObject(parent)
    , m_chip(nullptr)
    , m_line(nullptr)
    , m_initialized(false)
{
}

GPIOController::~GPIOController() {
    cleanup();
}

void GPIOController::cleanup() {
    QMutexLocker locker(&m_mutex);
    if (m_line) {
        gpiod_line_release(m_line);
        m_line = nullptr;
    }
    if (m_chip) {
        gpiod_chip_close(m_chip);
        m_chip = nullptr;
    }
    m_initialized = false;
}

bool GPIOController::initialize() {
    QMutexLocker locker(&m_mutex);

    if (m_initialized) {
        return true;
    }

    m_chip = gpiod_chip_open_by_name(m_chipname);
    if (!m_chip) {
        emit error("Could not open GPIO chip");
        return false;
    }

    m_line = gpiod_chip_get_line(m_chip, m_lineNum);
    if (!m_line) {
        emit error("Could not get GPIO line");
        cleanup();
        return false;
    }

    int ret = gpiod_line_request_output(m_line, "myapp", 0);
    if (ret < 0) {
        emit error("Could not request GPIO line as output");
        cleanup();
        return false;
    }

    m_initialized = true;
    return true;
}

bool GPIOController::setValue(int value) {
    QMutexLocker locker(&m_mutex);

    if (!m_initialized) {
        emit error("GPIO not initialized");
        return false;
    }

    int ret = gpiod_line_set_value(m_line, value);
    if (ret < 0) {
        emit error("Failed to set GPIO value");
        return false;
    }

    emit stateChanged(value == 1);
    return true;
}

GPIOWorker::GPIOWorker(GPIOController *controller, QObject *parent)
    : QThread(parent)
    , m_controller(controller)
{
}

void GPIOWorker::setGPIOOn() {
    m_controller->setValue(1);
}

void GPIOWorker::setGPIOOff() {
    m_controller->setValue(0);
}





















































