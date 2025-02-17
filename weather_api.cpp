#include "weather_api.h"
#include <QDateTime>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>
#include <QDebug>
#include <QTimer>
#include <QJsonDocument>

#define API_URL "http://apis.data.go.kr/1360000/VilageFcstInfoService_2.0/getUltraSrtNcst"

int Weather::weatherperiod = 0;

Weather::Weather(QObject *parent): QObject(parent){
    connect(&networkManager, &QNetworkAccessManager::finished, this, &Weather::onNetworkReply);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Weather::fetchWeatherData);
    timer->start(weatherperiod * 1000);          // 날씨 업데이트 주기
    //timer->start(5000);
}

void Weather::WeatherPeriod(int value){
    weatherperiod = value;
}

void Weather::fetchWeatherData(){
    QString serviceKey = "";
    QString encodedServiceKey = QUrl::toPercentEncoding(serviceKey);

    QString baseDate = QDate::currentDate().toString("yyyyMMdd");
    QString baseTime = QTime::currentTime().addSecs(-3600).toString("hhmm");

    QUrl url(API_URL);
    QUrlQuery query;

    query.addQueryItem("serviceKey", encodedServiceKey);
    query.addQueryItem("pageNo", "1");
    query.addQueryItem("numOfRows", "1000");
    query.addQueryItem("dataType", "JSON");
    query.addQueryItem("base_date", baseDate);
    query.addQueryItem("base_time", baseTime);
    query.addQueryItem("nx", "59");
    query.addQueryItem("ny", "125");

    url.setQuery(query);
    networkManager.get(QNetworkRequest(url));
}

void Weather::onNetworkReply(QNetworkReply *reply){
    if (reply->error() != QNetworkReply::NoError) {
        emit errorOccurred(reply->errorString());
        return;
    }

    QByteArray responseData = reply->readAll();
    qDebug() << "Response data:" << responseData;

    QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
    if (jsonDoc.isNull()) {
        emit errorOccurred("Failed to parse JSON.");
        return;
    }

    QJsonObject jsonObj = jsonDoc.object();
    QJsonArray items = jsonObj["response"].toObject()["body"].toObject()["items"].toObject()["item"].toArray();

    QString temperature, humidity, weatherCondition;

    for (const QJsonValue &value : items){
        QJsonObject item = value.toObject();
        QString category = item["category"].toString();
        QString obsrValue = item["obsrValue"].toString();

        if (category == "T1H") {
            temperature = obsrValue;
            qDebug() << "Temp:" << temperature;
        } else if (category == "REH") {
            humidity = obsrValue;
        } else if (category == "PTY") {
            weatherCondition = obsrValue;
        }
    }
    emit weatherDataReceived(temperature, humidity, weatherCondition);
}
