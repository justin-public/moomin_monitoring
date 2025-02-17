QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    eventday_api.cpp \
    gpio_api.cpp \
    main.cpp \
    mainwindow.cpp \
    modebus_api.cpp \
    ping_api.cpp \
    pjlink_api.cpp \
    slack_api.cpp \
    system_reboot.cpp \
    weather_api.cpp

LIBS += -lgpiod

HEADERS += \
    eventday_api.h \
    gpio_api.h \
    logger.h \
    mainwindow.h \
    modebus_api.h \
    ping_api.h \
    pjlink_api.h \
    slack_api.h \
    system_reboot.h \
    weather_api.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
