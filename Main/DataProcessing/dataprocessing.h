﻿#ifndef DATAPROCESSING_H
#define DATAPROCESSING_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDateTime>
#include <QDebug>
#include <QStandardPaths>
#include <QDir>
#include <QReadWriteLock>

#include "Parameter/parameter.h"

class DataProcessing : public QObject
{
    Q_OBJECT

public:
    explicit DataProcessing(QObject *parent = nullptr);

private:

    ///
    /// \brief writeDataToLog 发送结果写入到日志
    /// \param channel 通道号
    /// \param result 识别结果
    ///
    void writeDataToLog(int channel_number,const QString& result);

public slots:

    /*****************************
    * @brief:集装箱
    ******************************/

    ///
    /// \brief slot_containerResult 发送集装箱识别结果
    /// \param channel 通道号
    /// \param result 识别结果
    ///
    void slot_containerResult(int channel,const QString& result);

signals:

    ///
    /// \brief signal_InitializationParameter 初始化参数
    /// \param address 地址
    /// \param port 端口
    /// \param serviceType 服务类型
    /// \param heartBeat 心跳包 状态
    /// \param serviceMode 服务模式
    /// \param shortLink 短链接状态
    /// \param newline 换行符
    ///
    void  signal_InitializationParameter(const QString &address,const quint16 &port,const int &serviceType,bool heartBeat,const int &serviceMode,const int& shortLink,const int& newline);

    ///
    /// \brief signal_toSendData 发送数据-
    /// \param data 数据体
    ///
    void signal_toSendData(int channel_number, const QString &data);

    ///
    /// \brief signal_trafficStatistics 数据流量统计到主页面
    /// \param state
    ///
    void signal_trafficStatistics(bool state);

private:
    QJsonObject jsonChild;

    QString today;
    QString time;
    QString content;
    QString CPH;
    QString XH;
    QString roadindex;
    QString cartype;
    QString boxtype;
    QString discern;
    QString SOURCE;
    QString type;
    QString isguard;

    ///
    /// \brief logFile 日志文件
    ///
    QFile logFile;

    ///
    /// \brief lock 写入锁
    ///
    QReadWriteLock lock;
};

#endif // DATAPROCESSING_H
