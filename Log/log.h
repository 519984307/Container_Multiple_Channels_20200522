#ifndef LOG_H
#define LOG_H

#include "Log_global.h"

class LOG_EXPORT Log:public QObject
{
    Q_OBJECT

public:
    Log(QObject *parent = nullptr);

    ///
    /// \brief outPutMessage 输出日志
    /// \param type 日志类型
    /// \param context 日志附加信息
    /// \param msg 日志信息
    ///
    void outPutMessage(QtMsgType type,const QMessageLogContext &context,const QString &msg);

signals:

    ///
    /// \brief singal_newLogText 新日志信息
    /// \param value 信息体
    ///
    void singal_newLogText(QString value);

private slots:

    ///
    /// \brief slot_addLog 添加日志信息(回写到UI)
    /// \param value
    ///
    void slot_addLog(QString value);

private:

    ///
    /// \brief writeToLog 日志写入本地
    /// \param value
    ///
    void writeToLog(QString value);

private:

    QFile logFile;

};

#endif // LOG_H
