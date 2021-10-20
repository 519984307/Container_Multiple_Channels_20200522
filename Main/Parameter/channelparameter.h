#ifndef CHANNELPARAMETER_H
#define CHANNELPARAMETER_H

#include <QObject>

class ChannelParameter
{
public:
    ChannelParameter(){}

    /*****************************
    * @brief:other
    ******************************/

    ///
    /// \brief Channel_number 通道号
    ///
    int  Channel_number;

    ///
    /// \brief Alias 通道别名
    ///
    QString Alias;

    ///
    /// \brief Plate_Camera_Model 车牌相机协议
    ///
    int Plate_Camera_Model;

    ///
    /// \brief Container_Camera_Model 箱号相机协议
    ///
    int Container_Camera_Model;

    ///
    /// \brief HCNET_Type 海康相机抓拍类型
    ///
    int HCNET_Capture_Type;

    ///
    /// \brief Camera_Load_Plugin 相机插件加载类型
    ///
    int Camera_Load_Plugin;

    ///
    /// \brief A1ReleasrCap A1释放后多久抓拍图片
    ///
    int A1ReleasrCap;

    /*****************************
    * @brief:camera
    ******************************/

    ///
    /// \brief UserCamer 相机用户名
    ///
    QString UserCamer;

    ///
    /// \brief PasswordCamer 相机密码
    ///
    QString PasswordCamer;

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
    /// \brief ForgroundCamer 后景相机
    ///
    QString ForgroundCamer;

    ///
    /// \brief ProspectsCamer 前景相机
    ///
    QString ProspectsCamer;

    ///
    /// \brief LocalAddr 本地网卡地址
    ///
    QString LocalAddr;

    /*****************************
    * @brief:SerialPort
    ******************************/

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
    /// \brief interfaceModel 信号接口模式
    ///
    int interfaceModel;

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

    ///
    /// \brief controllerAddr 网络控制器地址
    ///
    QString controllerAddr;

    ///
    /// \brief controllerPort 网络控制器端口
    ///
    int controllerPort;

    ///
    /// \brief D1out 网络控制器输出端口
    ///
    int D1out;

    ///
    /// \brief D2out 网络控制器输出端口
    ///
    int D2out;

    ///
    /// \brief D3out 网络控制器输出端口
    ///
    int D3out;

    ///
    /// \brief D4out 网络控制器输出端口
    ///
    int D4out;

    ///
    /// \brief lifthingType 抬杆类型
    ///
    int lifthingType;
};

#endif // CHANNELPARAMETER_H
