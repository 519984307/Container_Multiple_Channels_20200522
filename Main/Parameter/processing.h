#ifndef PROCESSING_H
#define PROCESSING_H

#include <QObject>
#include <QDir>
#include <QFile>
#include <QVariant>
#include <QMessageLogger>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonDocument>
#include <QCoreApplication>

#include "logcontroller.h"
#include "channelparameter.h"

class Processing : public QObject
{
    Q_OBJECT
public:
    explicit Processing(QObject *parent = nullptr);

    ~Processing()Q_DECL_OVERRIDE;

    ///
    /// \brief loadChannelParameter 获取通道配置参数
    /// \param Channels 通道数
    ///
    void loadChannelParameter(int Channels);

    ///
    /// \brief getJsonValue 解析配置文件
    /// \param child
    /// \param key
    /// \param obj
    /// \return
    ///
    QVariant getJsonValue(const QString &child, const QString &key, QJsonObject obj);

    ///
    /// \brief p_LogController 日志类
    ///
    LogController *p_LogController;

    ///
    /// \brief ParmeterList 配置类组
    ///
    QList<ChannelParameter*> ParmeterList;

signals:

};

#endif // PROCESSING_H
