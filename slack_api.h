#ifndef SLACK_API_H
#define SLACK_API_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class Slack : public QObject{
    Q_OBJECT

public:
    Slack(QObject *parent = nullptr);

public slots:
    void sendMessage(const QString &token, const QString &channel, const QString &text);

signals:
    void messageSent(bool success, const QString &errorString);

private slots:
    void onReplyFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager *networkManager;
    bool stopped;
};

#endif // SLACK_API_H
