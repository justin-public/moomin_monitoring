#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QDateTime>

class Logger : public QObject
{
    Q_OBJECT

public:
    explicit Logger(const QString& filename = "log.txt", QObject *parent = nullptr)
        : QObject(parent), m_filename(filename)
    {
        openLogFile();
    }

    ~Logger()
    {
        if (m_file.isOpen()) {
            m_file.close();
        }
    }

public slots:
    void writeLog(const QString& message)
    {
        if (!m_file.isOpen()) {
            if (!openLogFile()) {
                return;
            }
        }

        QTextStream stream(&m_file);
        QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        stream << timestamp << " - " << message << "\n";
        stream.flush();
    }

private:
    bool openLogFile()
    {
        m_file.setFileName(m_filename);
        if (!m_file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
            qDebug() << "Unable to open log file:" << m_filename;
            return false;
        }
        return true;
    }

    QString m_filename;
    QFile m_file;
};

class Logger1 : public QObject
{
    Q_OBJECT

public:
    explicit Logger1(const QString& filename = "log1.txt", QObject *parent = nullptr)
        : QObject(parent), m_filename(filename)
    {
        openLogFile();
    }

    ~Logger1()
    {
        if (m_file.isOpen()) {
            m_file.close();
        }
    }

public slots:
    void writeLog(const QString& message)
    {
        if (!m_file.isOpen()) {
            if (!openLogFile()) {
                return;
            }
        }

        QTextStream stream(&m_file);
        QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        stream << timestamp << " - " << message << "\n";
        stream.flush();
    }

private:
    bool openLogFile()
    {
        m_file.setFileName(m_filename);
        if (!m_file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
            qDebug() << "Unable to open log file:" << m_filename;
            return false;
        }
        return true;
    }

    QString m_filename;
    QFile m_file;
};

#endif // LOGGER_H











































































