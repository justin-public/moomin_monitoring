#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "weather_api.h"     // 날씨 정보 업데이트
#include "system_reboot.h"   // 시스템 리부팅 동작
#include "ping_api.h"        // PC 네트워크 상태 확인
#include "pjlink_api.h"      // 프로젝터 상태 확인
#include "modebus_api.h"     // 온습도 센서 모델명 : XY-MD02
#include "gpio_api.h"        // GPIO 제어

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // PC 상태 확인
    void handlePingResult(const QString& address, bool isSuccess);
    // 프로젝터 상태확인
    void onProjectorStatusUpdated(const QString& address,bool projectorstatus);
    // 프로젝터 램프시간 확인
    void lampProjectorStatusUpdated(const QString& address, int currentLampTime);
    // 온습도 센서 모니터링
    void updateTemperature(float temp);
    void updateHumidity(float humid);
    // GPIO
    void handleGPIOStateChanged(bool isOn);
    void handleGPIOError(const QString &message);

private:
    // 시스템 리부팅
    SystemWorker *worker;
    int hourvalue;
    int minvalue;

    // 컨트롤 정보
    void config_readFile();
    QString emtSetting;
    QString rebootTime;
    QString projector1, projector2, projector3, projector4;
    QString serverPC, displayPC;
    int updateInterval;

    QString startchvalue;
    QString starttimevalue;
    QString endchvalue;
    QString endtimevalue;

    QString eventalrmchvalue;          // 이벤트 알림채널 이름
    QString availableTempvalue;        // 허용온도 값
    QString availablehumvalue;         // 허용습도 값
    QString troublechktimevalue;       // 트러블 체크 시간

    //bool eventSingleshotflag;
    bool projector1Singleshotflag;
    int countoffsend;

    int starthourvalue;        // 시작 시간 값
    int startminutevalue;      // 시작 분 값

    int endhourvalue;          // 종료 시간 값
    int endminutevalue;        // 종료 분 값

    int troublechkhour_start;        // Ʈ트러블 체크 시간 시작 시간
    int troublechkminute_start;      // Ʈ트러블 체크 시간 시작 분

    int troublechkhour_end;          // 트러블 체크 시간 종료 시간 Ʈ
    int troublechkminute_end;        // 트러블 체크 시간 종료 분

    QString ServerPCState;
    QString DisplayPCState;

    QString Projector1event;          // 프로젝터 1 이벤트 확인
    QString Projector2event;          // 프로젝터 2 이벤트 확인
    QString Projector3event;          // 프로젝터 3 이벤트 확인
    QString Projector4event;          // 프로젝터 4 이벤트 확인

    QString ServerPCevent;            // 서버 PC 이벤트Ʈ
    QString DisplayPCevent;           // 디스플레이 PC 이벤트

    // 날씨 정보 업데이트
    QThread *weatherThread;
    Weather *weather;
    void updateWeatherData(const QString &temperature, const QString &humidity, const QString &weatherCondition);
    QString currentTemperature;
    QString currentHumidity;
    QString currentWeatherDescription;

    // PC 상태확인
    PingWorker* pingWorker;
    void setupPingMonitor();

    // 프로젝터 상태확인
    PJLinkAPI *pjLinkAPI;
    QString Prj1state;
    QString Prj2state;
    QString Prj3state;
    QString Prj4state;

    // 장비상태 업데이트
    int countsend;
    void totaldeviceEquiment1(const QString& address,bool isSuccess);

    // 온습도 상태 확인
    QThread workerThread;
    ModeBus *modebusworker;

    //GPIO
    GPIOController *m_gpioController;
    GPIOWorker *m_gpioWorker;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H



































