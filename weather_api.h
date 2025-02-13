#ifndef WEATHER_API_H
#define WEATHER_API_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class Weather : public QObject{
    Q_OBJECT

    public:
        explicit Weather(QObject *parent = nullptr);
        void fetchWeatherData();
        void  WeatherPeriod(int value);


    signals:
        void weatherDataReceived(const QString &temperature, const QString &humidity, const QString &weatherCondition);
        void errorOccurred(const QString &errorString);

    public slots:
        void onNetworkReply(QNetworkReply *reply);

    private:
        QNetworkAccessManager networkManager;
        static int weatherperiod;

};


#endif // WEATHER_API_H
