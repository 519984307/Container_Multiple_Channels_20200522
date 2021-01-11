#ifndef DATAPROCESSING_H
#define DATAPROCESSING_H

#include <QObject>

class DataProcessing : public QObject
{
    Q_OBJECT

public:
    explicit DataProcessing(QObject *parent = nullptr);

public slots:

    ///
    /// \brief slot_linkState TCP链接状态
    /// \param address 地址
    /// \param state 状态
    ///
    void slot_linkState(const QString &address,bool state);

    ///
    /// \brief slot_connectCount 链接数量
    /// \param count
    ///
    void slot_connectCount(int count);

    ///
    /// \brief slot_sendDataToLog 发送结果写入到日志
    /// \param channel 通道号
    /// \param result 识别结果
    ///
    void slot_sendDataToLog(int channel_number,const QString& result);

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
    ///
    void  signal_InitializationParameter(const QString &address,const quint16 &port,const int &serviceType,const bool &heartBeat,const int &serviceMode);

    ///
    /// \brief signal_toSendData 发送数据-
    /// \param data 数据体
    ///
    void signal_toSendData(int channel_number, const QString &data);

};

#endif // DATAPROCESSING_H
