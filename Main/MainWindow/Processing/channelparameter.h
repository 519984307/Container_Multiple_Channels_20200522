#ifndef CHANNELPARAMETER_H
#define CHANNELPARAMETER_H

#include <QObject>

class ChannelParameter
{
public:
    ChannelParameter(){}

    ///
    /// \brief Channel_number 通道号
    ///
    int  Channel_number;

    ///
    /// \brief Alias 通道别名
    ///
    QString Alias;

    ///
    /// \brief LicensePlate 车牌协议
    ///
    int LicensePlate;

    ///
    /// \brief FrontCamer 前相机
    ///
    QString FrontCamer;

    ///
    /// \brief AfterCamer 后相机
    ///
    QString AfterCamer;

    ///
    /// \brief LeftCamer 左相机
    ///
    QString LeftCamer;

    ///
    /// \brief RgihtCamer 右相机
    ///
    QString RgihtCamer;

    ///
    /// \brief TopCamer 顶部相机
    ///
    QString TopCamer;

    ///
    /// \brief PlateCamer 车牌相机
    ///
    QString PlateCamer;

    ///
    /// \brief PortOne 串口端口1
    ///
    int PortOne;

    ///
    /// \brief PortTow 串口端口2
    ///
    int PortTow;

    ///
    /// \brief SerialAddrOne 串口服务地址1
    ///
    QString SerialAddrOne;

    ///
    /// \brief SerialAddrTow 串口服务地址2
    ///
    QString SerialAddrTow;

    ///
    /// \brief SerialPortTow 串口2
    ///
    int SerialPortTow;

    ///
    /// \brief SerialPortOne 串口1
    ///
    int SerialPortOne;

    ///
    /// \brief ControllerSignalMode 控制器信号模式
    ///
    int ControllerSignalMode;

    ///
    /// \brief infraredStatus 红外状态
    ///
    int infraredStatus;
};

#endif // CHANNELPARAMETER_H
