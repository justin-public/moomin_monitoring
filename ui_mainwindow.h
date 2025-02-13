/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *local_monitoring;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *insideTemp_index;
    QLabel *insideTemp_val;
    QVBoxLayout *verticalLayout_3;
    QPushButton *insideHum_index;
    QLabel *insideHum_val;
    QVBoxLayout *verticalLayout_4;
    QPushButton *localTemp_index;
    QLabel *localTemp_val;
    QVBoxLayout *verticalLayout_5;
    QPushButton *localWeather_index;
    QLabel *localWeather_val;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *hardware_monitoring;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_7;
    QPushButton *deviceName_index;
    QLabel *deviceName_val01;
    QLabel *deviceName_val02;
    QLabel *deviceName_val03;
    QLabel *deviceName_val04;
    QLabel *deviceName_val05;
    QLabel *deviceName_val06;
    QVBoxLayout *verticalLayout_10;
    QPushButton *pwState_index;
    QLabel *pwState_val01;
    QLabel *pwState_val02;
    QLabel *pwState_val03;
    QLabel *pwState_val04;
    QLabel *pwState_val05;
    QLabel *pwState_val06;
    QVBoxLayout *verticalLayout_8;
    QPushButton *etc_index;
    QLabel *etc_val01;
    QLabel *etc_val02;
    QLabel *etc_val03;
    QLabel *etc_val04;
    QLabel *etc_val06;
    QLabel *etc_value06;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *relay_control;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_11;
    QPushButton *relayName_index;
    QLabel *relayName_val01;
    QVBoxLayout *verticalLayout_12;
    QPushButton *relayState_index;
    QLabel *relayState_val01;
    QVBoxLayout *verticalLayout_13;
    QPushButton *relayControl_index;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *relayControl_bt01;
    QPushButton *relayControl_bt02;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_14;
    QGroupBox *alarm_channel;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_15;
    QPushButton *alarmName_index;
    QLabel *alarmName_val01;
    QLabel *alarmName_val02;
    QLabel *alarmName_val03;
    QVBoxLayout *verticalLayout_16;
    QPushButton *targetChannel_index;
    QLabel *targetChannel_val01;
    QLabel *targetChannel_val02;
    QLabel *targetChannel_val03;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(486, 736);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(33, 33, 49, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(49, 49, 73, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(41, 41, 61, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(16, 16, 24, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(22, 22, 33, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        QBrush brush8(QColor(255, 255, 255, 128));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        MainWindow->setPalette(palette);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 451, 141));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        local_monitoring = new QGroupBox(verticalLayoutWidget);
        local_monitoring->setObjectName(QString::fromUtf8("local_monitoring"));
        local_monitoring->setEnabled(true);
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush9(QColor(85, 85, 127, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush9);
        QBrush brush10(QColor(127, 127, 190, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush10);
        QBrush brush11(QColor(106, 106, 158, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        QBrush brush12(QColor(42, 42, 63, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush12);
        QBrush brush13(QColor(57, 57, 85, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush12);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        local_monitoring->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("Yu Gothic"));
        font.setPointSize(10);
        local_monitoring->setFont(font);
        horizontalLayoutWidget = new QWidget(local_monitoring);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 20, 431, 111));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        insideTemp_index = new QPushButton(horizontalLayoutWidget);
        insideTemp_index->setObjectName(QString::fromUtf8("insideTemp_index"));
        insideTemp_index->setEnabled(false);
        QPalette palette2;
        QBrush brush14(QColor(168, 168, 168, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush14);
        QBrush brush15(QColor(78, 78, 115, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush15);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush14);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush14);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush15);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush15);
        QBrush brush16(QColor(168, 168, 168, 128));
        brush16.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush16);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush14);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush15);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush14);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush14);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush15);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush15);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush16);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush15);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush16);
#endif
        insideTemp_index->setPalette(palette2);
        insideTemp_index->setStyleSheet(QString::fromUtf8("background-color : rgb(78, 78, 115);\n"
"color : rgb(168, 168, 168)"));

        verticalLayout_2->addWidget(insideTemp_index);

        insideTemp_val = new QLabel(horizontalLayoutWidget);
        insideTemp_val->setObjectName(QString::fromUtf8("insideTemp_val"));
        insideTemp_val->setEnabled(true);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Yu Gothic"));
        font1.setPointSize(30);
        font1.setBold(true);
        insideTemp_val->setFont(font1);

        verticalLayout_2->addWidget(insideTemp_val, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        verticalLayout_2->setStretch(0, 1);

        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        insideHum_index = new QPushButton(horizontalLayoutWidget);
        insideHum_index->setObjectName(QString::fromUtf8("insideHum_index"));
        insideHum_index->setEnabled(false);
        insideHum_index->setStyleSheet(QString::fromUtf8("background-color : rgb(78, 78, 115);\n"
"color : rgb(168, 168, 168)"));

        verticalLayout_3->addWidget(insideHum_index);

        insideHum_val = new QLabel(horizontalLayoutWidget);
        insideHum_val->setObjectName(QString::fromUtf8("insideHum_val"));
        insideHum_val->setFont(font1);

        verticalLayout_3->addWidget(insideHum_val, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        verticalLayout_3->setStretch(1, 5);

        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        localTemp_index = new QPushButton(horizontalLayoutWidget);
        localTemp_index->setObjectName(QString::fromUtf8("localTemp_index"));
        localTemp_index->setEnabled(false);
        localTemp_index->setStyleSheet(QString::fromUtf8("background-color : rgb(78, 78, 115);\n"
"color : rgb(168, 168, 168)"));

        verticalLayout_4->addWidget(localTemp_index);

        localTemp_val = new QLabel(horizontalLayoutWidget);
        localTemp_val->setObjectName(QString::fromUtf8("localTemp_val"));
        localTemp_val->setFont(font1);

        verticalLayout_4->addWidget(localTemp_val, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        verticalLayout_4->setStretch(1, 5);

        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        localWeather_index = new QPushButton(horizontalLayoutWidget);
        localWeather_index->setObjectName(QString::fromUtf8("localWeather_index"));
        localWeather_index->setEnabled(false);
        localWeather_index->setStyleSheet(QString::fromUtf8("background-color : rgb(78, 78, 115);\n"
"color : rgb(168, 168, 168)"));

        verticalLayout_5->addWidget(localWeather_index);

        localWeather_val = new QLabel(horizontalLayoutWidget);
        localWeather_val->setObjectName(QString::fromUtf8("localWeather_val"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Yu Gothic"));
        font2.setPointSize(16);
        font2.setBold(true);
        localWeather_val->setFont(font2);

        verticalLayout_5->addWidget(localWeather_val, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        verticalLayout_5->setStretch(1, 5);

        horizontalLayout->addLayout(verticalLayout_5);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);

        verticalLayout->addWidget(local_monitoring);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(20, 170, 451, 241));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        hardware_monitoring = new QGroupBox(verticalLayoutWidget_2);
        hardware_monitoring->setObjectName(QString::fromUtf8("hardware_monitoring"));
        hardware_monitoring->setEnabled(true);
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush10);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush12);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        hardware_monitoring->setPalette(palette3);
        hardware_monitoring->setFont(font);
        horizontalLayoutWidget_2 = new QWidget(hardware_monitoring);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 20, 431, 211));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        deviceName_index = new QPushButton(horizontalLayoutWidget_2);
        deviceName_index->setObjectName(QString::fromUtf8("deviceName_index"));
        deviceName_index->setEnabled(false);
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush14);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush15);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush14);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush14);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush15);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush15);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush16);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush14);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush15);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush14);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush14);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush15);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush15);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush16);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush15);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush14);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush15);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush15);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush16);
#endif
        deviceName_index->setPalette(palette4);
        deviceName_index->setStyleSheet(QString::fromUtf8("background-color : rgb(78, 78, 115);\n"
"color : rgb(168, 168, 168)"));

        verticalLayout_7->addWidget(deviceName_index);

        deviceName_val01 = new QLabel(horizontalLayoutWidget_2);
        deviceName_val01->setObjectName(QString::fromUtf8("deviceName_val01"));

        verticalLayout_7->addWidget(deviceName_val01, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        deviceName_val02 = new QLabel(horizontalLayoutWidget_2);
        deviceName_val02->setObjectName(QString::fromUtf8("deviceName_val02"));

        verticalLayout_7->addWidget(deviceName_val02, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        deviceName_val03 = new QLabel(horizontalLayoutWidget_2);
        deviceName_val03->setObjectName(QString::fromUtf8("deviceName_val03"));

        verticalLayout_7->addWidget(deviceName_val03, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        deviceName_val04 = new QLabel(horizontalLayoutWidget_2);
        deviceName_val04->setObjectName(QString::fromUtf8("deviceName_val04"));

        verticalLayout_7->addWidget(deviceName_val04, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        deviceName_val05 = new QLabel(horizontalLayoutWidget_2);
        deviceName_val05->setObjectName(QString::fromUtf8("deviceName_val05"));

        verticalLayout_7->addWidget(deviceName_val05, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        deviceName_val06 = new QLabel(horizontalLayoutWidget_2);
        deviceName_val06->setObjectName(QString::fromUtf8("deviceName_val06"));

        verticalLayout_7->addWidget(deviceName_val06, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        horizontalLayout_2->addLayout(verticalLayout_7);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        pwState_index = new QPushButton(horizontalLayoutWidget_2);
        pwState_index->setObjectName(QString::fromUtf8("pwState_index"));
        pwState_index->setEnabled(false);
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush14);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush15);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush14);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush14);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush15);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush15);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush16);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush14);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush15);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush14);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush14);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush15);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush15);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush16);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush15);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush14);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush15);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush15);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush16);
#endif
        pwState_index->setPalette(palette5);
        pwState_index->setStyleSheet(QString::fromUtf8("background-color : rgb(78, 78, 115);\n"
"color : rgb(168, 168, 168)"));

        verticalLayout_10->addWidget(pwState_index);

        pwState_val01 = new QLabel(horizontalLayoutWidget_2);
        pwState_val01->setObjectName(QString::fromUtf8("pwState_val01"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Yu Gothic"));
        font3.setPointSize(9);
        font3.setBold(true);
        pwState_val01->setFont(font3);
        pwState_val01->setStyleSheet(QString::fromUtf8("color:rgb(0, 255, 0)"));

        verticalLayout_10->addWidget(pwState_val01, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        pwState_val02 = new QLabel(horizontalLayoutWidget_2);
        pwState_val02->setObjectName(QString::fromUtf8("pwState_val02"));
        pwState_val02->setFont(font3);
        pwState_val02->setStyleSheet(QString::fromUtf8("color : rgb(255, 85, 127)"));

        verticalLayout_10->addWidget(pwState_val02, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        pwState_val03 = new QLabel(horizontalLayoutWidget_2);
        pwState_val03->setObjectName(QString::fromUtf8("pwState_val03"));
        pwState_val03->setFont(font3);
        pwState_val03->setStyleSheet(QString::fromUtf8("color:rgb(0, 255, 0)"));

        verticalLayout_10->addWidget(pwState_val03, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        pwState_val04 = new QLabel(horizontalLayoutWidget_2);
        pwState_val04->setObjectName(QString::fromUtf8("pwState_val04"));
        pwState_val04->setFont(font3);
        pwState_val04->setStyleSheet(QString::fromUtf8("color:rgb(0, 255, 0)"));

        verticalLayout_10->addWidget(pwState_val04, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        pwState_val05 = new QLabel(horizontalLayoutWidget_2);
        pwState_val05->setObjectName(QString::fromUtf8("pwState_val05"));
        pwState_val05->setFont(font3);
        pwState_val05->setStyleSheet(QString::fromUtf8("color : rgb(255, 85, 127)"));

        verticalLayout_10->addWidget(pwState_val05, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        pwState_val06 = new QLabel(horizontalLayoutWidget_2);
        pwState_val06->setObjectName(QString::fromUtf8("pwState_val06"));
        pwState_val06->setFont(font3);
        pwState_val06->setStyleSheet(QString::fromUtf8("color:rgb(0, 255, 0)"));

        verticalLayout_10->addWidget(pwState_val06, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        horizontalLayout_2->addLayout(verticalLayout_10);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        etc_index = new QPushButton(horizontalLayoutWidget_2);
        etc_index->setObjectName(QString::fromUtf8("etc_index"));
        etc_index->setEnabled(false);
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush14);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush15);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush14);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush14);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush15);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush15);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush16);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush14);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush15);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush14);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush14);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush15);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush15);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush16);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush15);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush14);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush15);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush15);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush16);
#endif
        etc_index->setPalette(palette6);
        etc_index->setStyleSheet(QString::fromUtf8("background-color : rgb(78, 78, 115);\n"
"color : rgb(168, 168, 168)"));

        verticalLayout_8->addWidget(etc_index);

        etc_val01 = new QLabel(horizontalLayoutWidget_2);
        etc_val01->setObjectName(QString::fromUtf8("etc_val01"));

        verticalLayout_8->addWidget(etc_val01, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        etc_val02 = new QLabel(horizontalLayoutWidget_2);
        etc_val02->setObjectName(QString::fromUtf8("etc_val02"));

        verticalLayout_8->addWidget(etc_val02, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        etc_val03 = new QLabel(horizontalLayoutWidget_2);
        etc_val03->setObjectName(QString::fromUtf8("etc_val03"));

        verticalLayout_8->addWidget(etc_val03, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        etc_val04 = new QLabel(horizontalLayoutWidget_2);
        etc_val04->setObjectName(QString::fromUtf8("etc_val04"));

        verticalLayout_8->addWidget(etc_val04, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        etc_val06 = new QLabel(horizontalLayoutWidget_2);
        etc_val06->setObjectName(QString::fromUtf8("etc_val06"));

        verticalLayout_8->addWidget(etc_val06, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        etc_value06 = new QLabel(horizontalLayoutWidget_2);
        etc_value06->setObjectName(QString::fromUtf8("etc_value06"));

        verticalLayout_8->addWidget(etc_value06, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        horizontalLayout_2->addLayout(verticalLayout_8);


        verticalLayout_6->addWidget(hardware_monitoring);

        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(20, 420, 451, 101));
        verticalLayout_9 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        relay_control = new QGroupBox(verticalLayoutWidget_3);
        relay_control->setObjectName(QString::fromUtf8("relay_control"));
        relay_control->setEnabled(true);
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette7.setBrush(QPalette::Active, QPalette::Light, brush10);
        palette7.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette7.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette7.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette7.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush12);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette7.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette7.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette7.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette7.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette7.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette7.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette7.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        relay_control->setPalette(palette7);
        relay_control->setFont(font);
        horizontalLayoutWidget_3 = new QWidget(relay_control);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 20, 431, 71));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        relayName_index = new QPushButton(horizontalLayoutWidget_3);
        relayName_index->setObjectName(QString::fromUtf8("relayName_index"));
        relayName_index->setEnabled(false);
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush14);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush15);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush14);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush14);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush15);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush15);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Active, QPalette::PlaceholderText, brush16);
#endif
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush14);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush15);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush14);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush14);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush15);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush15);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush16);
#endif
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush15);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush14);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush15);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush15);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush16);
#endif
        relayName_index->setPalette(palette8);
        relayName_index->setStyleSheet(QString::fromUtf8("background-color : rgb(78, 78, 115);\n"
"color : rgb(168, 168, 168)"));

        verticalLayout_11->addWidget(relayName_index);

        relayName_val01 = new QLabel(horizontalLayoutWidget_3);
        relayName_val01->setObjectName(QString::fromUtf8("relayName_val01"));

        verticalLayout_11->addWidget(relayName_val01, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        verticalLayout_11->setStretch(0, 1);

        horizontalLayout_3->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        relayState_index = new QPushButton(horizontalLayoutWidget_3);
        relayState_index->setObjectName(QString::fromUtf8("relayState_index"));
        relayState_index->setEnabled(false);
        relayState_index->setStyleSheet(QString::fromUtf8("background-color : rgb(78, 78, 115);\n"
"color : rgb(168, 168, 168)"));

        verticalLayout_12->addWidget(relayState_index);

        relayState_val01 = new QLabel(horizontalLayoutWidget_3);
        relayState_val01->setObjectName(QString::fromUtf8("relayState_val01"));
        relayState_val01->setFont(font3);
        relayState_val01->setStyleSheet(QString::fromUtf8("color:rgb(255, 85, 127)"));

        verticalLayout_12->addWidget(relayState_val01, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        horizontalLayout_3->addLayout(verticalLayout_12);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(0);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setSizeConstraint(QLayout::SetDefaultConstraint);
        relayControl_index = new QPushButton(horizontalLayoutWidget_3);
        relayControl_index->setObjectName(QString::fromUtf8("relayControl_index"));
        relayControl_index->setEnabled(false);
        relayControl_index->setStyleSheet(QString::fromUtf8("background-color : rgb(78, 78, 115);\n"
"color : rgb(168, 168, 168)"));

        verticalLayout_13->addWidget(relayControl_index);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        relayControl_bt01 = new QPushButton(horizontalLayoutWidget_3);
        relayControl_bt01->setObjectName(QString::fromUtf8("relayControl_bt01"));
        relayControl_bt01->setFont(font3);
        relayControl_bt01->setStyleSheet(QString::fromUtf8("background-color:rgb(119, 119, 175);\n"
"color:rgb(255, 255, 255)\n"
""));

        horizontalLayout_4->addWidget(relayControl_bt01, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        relayControl_bt02 = new QPushButton(horizontalLayoutWidget_3);
        relayControl_bt02->setObjectName(QString::fromUtf8("relayControl_bt02"));
        relayControl_bt02->setFont(font3);
        relayControl_bt02->setStyleSheet(QString::fromUtf8("background-color:rgb(119, 119, 175);\n"
"color:rgb(255, 255, 255)\n"
""));

        horizontalLayout_4->addWidget(relayControl_bt02, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout_13->addLayout(horizontalLayout_4);


        horizontalLayout_3->addLayout(verticalLayout_13);


        verticalLayout_9->addWidget(relay_control);

        verticalLayoutWidget_4 = new QWidget(centralwidget);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(20, 530, 451, 151));
        verticalLayout_14 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        alarm_channel = new QGroupBox(verticalLayoutWidget_4);
        alarm_channel->setObjectName(QString::fromUtf8("alarm_channel"));
        alarm_channel->setEnabled(true);
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette9.setBrush(QPalette::Active, QPalette::Light, brush10);
        palette9.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette9.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette9.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush);
        palette9.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette9.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette9.setBrush(QPalette::Active, QPalette::AlternateBase, brush12);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette9.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette9.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette9.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette9.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette9.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette9.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette9.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette9.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette9.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette9.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette9.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        alarm_channel->setPalette(palette9);
        alarm_channel->setFont(font);
        horizontalLayoutWidget_5 = new QWidget(alarm_channel);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(10, 20, 431, 121));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        alarmName_index = new QPushButton(horizontalLayoutWidget_5);
        alarmName_index->setObjectName(QString::fromUtf8("alarmName_index"));
        alarmName_index->setEnabled(false);
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush14);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush15);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush14);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush14);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush15);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush15);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Active, QPalette::PlaceholderText, brush16);
#endif
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush14);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush15);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush14);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush14);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush15);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush15);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush16);
#endif
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush15);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush14);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush15);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush15);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush16);
#endif
        alarmName_index->setPalette(palette10);
        alarmName_index->setStyleSheet(QString::fromUtf8("background-color : rgb(78, 78, 115);\n"
"color : rgb(168, 168, 168)"));

        verticalLayout_15->addWidget(alarmName_index);

        alarmName_val01 = new QLabel(horizontalLayoutWidget_5);
        alarmName_val01->setObjectName(QString::fromUtf8("alarmName_val01"));

        verticalLayout_15->addWidget(alarmName_val01, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        alarmName_val02 = new QLabel(horizontalLayoutWidget_5);
        alarmName_val02->setObjectName(QString::fromUtf8("alarmName_val02"));

        verticalLayout_15->addWidget(alarmName_val02, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        alarmName_val03 = new QLabel(horizontalLayoutWidget_5);
        alarmName_val03->setObjectName(QString::fromUtf8("alarmName_val03"));

        verticalLayout_15->addWidget(alarmName_val03, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        verticalLayout_15->setStretch(0, 1);

        horizontalLayout_7->addLayout(verticalLayout_15);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        targetChannel_index = new QPushButton(horizontalLayoutWidget_5);
        targetChannel_index->setObjectName(QString::fromUtf8("targetChannel_index"));
        targetChannel_index->setEnabled(false);
        targetChannel_index->setStyleSheet(QString::fromUtf8("background-color : rgb(78, 78, 115);\n"
"color : rgb(168, 168, 168)"));

        verticalLayout_16->addWidget(targetChannel_index);

        targetChannel_val01 = new QLabel(horizontalLayoutWidget_5);
        targetChannel_val01->setObjectName(QString::fromUtf8("targetChannel_val01"));
        targetChannel_val01->setFont(font3);
        targetChannel_val01->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255)"));

        verticalLayout_16->addWidget(targetChannel_val01, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        targetChannel_val02 = new QLabel(horizontalLayoutWidget_5);
        targetChannel_val02->setObjectName(QString::fromUtf8("targetChannel_val02"));
        targetChannel_val02->setFont(font3);
        targetChannel_val02->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255)"));

        verticalLayout_16->addWidget(targetChannel_val02, 0, Qt::AlignHCenter);

        targetChannel_val03 = new QLabel(horizontalLayoutWidget_5);
        targetChannel_val03->setObjectName(QString::fromUtf8("targetChannel_val03"));
        targetChannel_val03->setFont(font3);
        targetChannel_val03->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255)"));

        verticalLayout_16->addWidget(targetChannel_val03, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        horizontalLayout_7->addLayout(verticalLayout_16);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 2);

        verticalLayout_14->addWidget(alarm_channel);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 486, 19));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        local_monitoring->setTitle(QCoreApplication::translate("MainWindow", "Local Monitoring", nullptr));
        insideTemp_index->setText(QCoreApplication::translate("MainWindow", "Inside Temp.(\302\260C)", nullptr));
        insideTemp_val->setText(QCoreApplication::translate("MainWindow", "28", nullptr));
        insideHum_index->setText(QCoreApplication::translate("MainWindow", "Insied Hum.(%)", nullptr));
        insideHum_val->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        localTemp_index->setText(QCoreApplication::translate("MainWindow", "Local Temp.(\302\260C)", nullptr));
        localTemp_val->setText(QCoreApplication::translate("MainWindow", "22", nullptr));
        localWeather_index->setText(QCoreApplication::translate("MainWindow", "Local Weather", nullptr));
        localWeather_val->setText(QCoreApplication::translate("MainWindow", "Cloudy", nullptr));
        hardware_monitoring->setTitle(QCoreApplication::translate("MainWindow", "Hardware Monitoring", nullptr));
        deviceName_index->setText(QCoreApplication::translate("MainWindow", "Device Name", nullptr));
        deviceName_val01->setText(QCoreApplication::translate("MainWindow", "Projector #1", nullptr));
        deviceName_val02->setText(QCoreApplication::translate("MainWindow", "Projector #2", nullptr));
        deviceName_val03->setText(QCoreApplication::translate("MainWindow", "Projector #3", nullptr));
        deviceName_val04->setText(QCoreApplication::translate("MainWindow", "Projector #4", nullptr));
        deviceName_val05->setText(QCoreApplication::translate("MainWindow", "Server PC", nullptr));
        deviceName_val06->setText(QCoreApplication::translate("MainWindow", "Display PC", nullptr));
        pwState_index->setText(QCoreApplication::translate("MainWindow", "PW State", nullptr));
        pwState_val01->setText(QCoreApplication::translate("MainWindow", "ON", nullptr));
        pwState_val02->setText(QCoreApplication::translate("MainWindow", "OFF", nullptr));
        pwState_val03->setText(QCoreApplication::translate("MainWindow", "ON", nullptr));
        pwState_val04->setText(QCoreApplication::translate("MainWindow", "ON", nullptr));
        pwState_val05->setText(QCoreApplication::translate("MainWindow", "OFF", nullptr));
        pwState_val06->setText(QCoreApplication::translate("MainWindow", "ON", nullptr));
        etc_index->setText(QCoreApplication::translate("MainWindow", "ETC", nullptr));
        etc_val01->setText(QCoreApplication::translate("MainWindow", "3591", nullptr));
        etc_val02->setText(QCoreApplication::translate("MainWindow", "3591", nullptr));
        etc_val03->setText(QCoreApplication::translate("MainWindow", "3591", nullptr));
        etc_val04->setText(QCoreApplication::translate("MainWindow", "3591", nullptr));
        etc_val06->setText(QCoreApplication::translate("MainWindow", "none", nullptr));
        etc_value06->setText(QCoreApplication::translate("MainWindow", "none", nullptr));
        relay_control->setTitle(QCoreApplication::translate("MainWindow", "Relay Control", nullptr));
        relayName_index->setText(QCoreApplication::translate("MainWindow", "Relay Name", nullptr));
        relayName_val01->setText(QCoreApplication::translate("MainWindow", "Relay #1", nullptr));
        relayState_index->setText(QCoreApplication::translate("MainWindow", "Relay State", nullptr));
        relayState_val01->setText(QCoreApplication::translate("MainWindow", "OFF", nullptr));
        relayControl_index->setText(QCoreApplication::translate("MainWindow", "Relay Control", nullptr));
        relayControl_bt01->setText(QCoreApplication::translate("MainWindow", "ON", nullptr));
        relayControl_bt02->setText(QCoreApplication::translate("MainWindow", "OFF", nullptr));
        alarm_channel->setTitle(QCoreApplication::translate("MainWindow", "Alarm Channel", nullptr));
        alarmName_index->setText(QCoreApplication::translate("MainWindow", "Alarm Name", nullptr));
        alarmName_val01->setText(QCoreApplication::translate("MainWindow", "Start Alarm", nullptr));
        alarmName_val02->setText(QCoreApplication::translate("MainWindow", "Endt Alarm", nullptr));
        alarmName_val03->setText(QCoreApplication::translate("MainWindow", "Event Alarm", nullptr));
        targetChannel_index->setText(QCoreApplication::translate("MainWindow", "Target Channel", nullptr));
        targetChannel_val01->setText(QCoreApplication::translate("MainWindow", "Moomin State_All", nullptr));
        targetChannel_val02->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        targetChannel_val03->setText(QCoreApplication::translate("MainWindow", "Mommin State_Manager", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
