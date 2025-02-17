#include "slack_api.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkRequest>
#include <QUrl>

Slack::Slack(QObject *parent): QObject(parent), networkManager(new QNetworkAccessManager(this)){}

void Slack::sendMessage(const QString &token, const QString &channel, const QString &text){
    QUrl url("https://slack.com/api/chat.postMessage");
    QNetworkRequest request(url);
    request.setRawHeader("Authorization", QString("Bearer %1").arg(token).toUtf8());
    request.setRawHeader("Content-Type", "application/json");

    QJsonObject json;
    json["channel"] = channel;
    json["text"] = text;

    QNetworkReply *reply = networkManager->post(request, QJsonDocument(json).toJson());

    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        onReplyFinished(reply);
    });
}

void Slack::onReplyFinished(QNetworkReply *reply){
    bool success = (reply->error() == QNetworkReply::NoError);
    QString errorString = success ? QString() : reply->errorString();
    emit messageSent(success, errorString);
    reply->deleteLater();
}
