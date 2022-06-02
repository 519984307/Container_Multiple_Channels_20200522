#ifndef LICENSEPLATEZS_H
#define LICENSEPLATEZS_H

#include "LicensePlateZS_global.h"
#include "licenseplateinterface.h"

class LICENSEPLATEZS_EXPORT LicensePlateZS:public LicensePlateInterface
{ 
    Q_OBJECT
    Q_INTERFACES(LicensePlateInterface)
    Q_PLUGIN_METADATA(IID LicensePlateInterfaceIID)

public:

    LicensePlateZS(QObject *parent=nullptr);
    ~LicensePlateZS()Q_DECL_OVERRIDE;

    ///
    /// \brief sendData 发送数据
    /// \param data
    ///
    void sendData(QJsonObject obj);
    
    ///
    /// \brief InterfaceType 插件类型，多插件调用统一接口
    /// \return
    ///
    QString InterfaceType()Q_DECL_OVERRIDE;

    ///
    /// \brief simulationCaptureSlot 模拟抓拍
    ///
    void simulationCaptureSlot()Q_DECL_OVERRIDE;

    ///
    /// \brief liftingElectronicRailingSlot 抬杆/落杆
    ///
    void liftingElectronicRailingSlot(bool gate)Q_DECL_OVERRIDE;

    ///
    /// \brief transparentTransmission485Slot 透明传输
    /// \param dmsg
    ///
    void transparentTransmission485Slot(const QString &msg)Q_DECL_OVERRIDE;

    ///
    /// \brief openTheVideoSlot 打开视频/关闭视频
    /// \param play
    ///
    void openTheVideoSlot(bool play,quint64 winID=0)Q_DECL_OVERRIDE;

    ///
    /// \brief releaseResourcesSlot 释放动态库资源
    ///
    void releaseResourcesSlot()Q_DECL_OVERRIDE;

    ///
    /// \brief initCameraSlot 初始化相机
    /// \param localAddr 本机地址(用户绑定网卡)
    /// \param addr 相机地址
    /// \param port 端口
    /// \param imgPath 图片地址
    /// \param channel 通道号
    /// \param signature 相机特征码
    ///
    void initCamerSlot(const QString &localAddr,const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature)Q_DECL_OVERRIDE;

    ///
    /// \brief getLastPlateSlot 获取最后一次车牌数据
    ///
    void getLastPlateSlot()Q_DECL_OVERRIDE;

    /*****************************
    * @brief:TCP协议链接车牌相机
    ******************************/

    ///
    /// \brief slot_pictureStream 分发图片数据
    /// \param ID
    /// \param arrJpg
    ///
    void slot_pictureStream(int ID,QByteArray arrJpg)Q_DECL_OVERRIDE;

    ///
    /// \brief slot_setCameraID 设置通道登录相机ID
    /// \param ID 登录ID
    /// \param cameraIP 相机地址
    ///
    void slot_setCameraID(int ID,QString cameraIP)Q_DECL_OVERRIDE;

    ///
    /// \brief slot_resultsTheLicensePlate 车牌结果
    /// \param plate
    ///
    void slot_resultsTheLicensePlate(int ID,const QString &plate,const QString &color,const QString &time,const QByteArray &arrImg)Q_DECL_OVERRIDE;

    ///
    /// \brief slot_equipmentState  设备额在线状态
    /// \param state
    ///
    void slot_equipmentState(int ID, bool state)Q_DECL_OVERRIDE;


    /*****************************
    * @brief:TCP协议链接车牌相机
    ******************************/
private slots:

    ///
    /// \brief startLinkSlot 链接到服务器,客户端模式
    ///
    void startLinkSlot();

    ///
    /// \brief heartbeatSlot 定时发送心跳包
    ///
    void heartbeatSlot();

    ///
    /// \brief connectedSlot 链接成功
    ///
    void connectedSlot();

    ///
    /// \brief receiveDataSlot 接收数据
    ///
    void receiveDataSlot();

    ///
    /// \brief disconnectedSlot 链接断开
    ///
    void disconnectedSlot();

    ///
    /// \brief displayErrorSlot 链接错误
    /// \param socketError 链接状态码
    ///
    void displayErrorSlot(QAbstractSocket::SocketError socketError);

    ///
    /// \brief processPlateResultSlot 处理接收的车牌数据
    /// \param data 接收的数据
    /// \param packetSize 数据大小
    ///
    void processPlateResultSlot(QByteArray data, int packetSize);

private:

    ///
    /// \brief pTcpClient 客户端
    ///
    QTcpSocket *pTcpClient;

    ///
    /// \brief pTimerLinkState 心跳包定时器
    ///
    QTimer* pTimerLinkState;

    ///
    /// \brief pTimerAutoLink 定时器链接
    ///
    QTimer* pTimerAutoLink;

    ///
    /// \brief isConnected 客户端链接状态
    ///
    bool isConnected;

    ///
    /// \brief channelNumber 通道号
    ///
    int channelNumber;

    ///
    /// \brief address 地址
    ///
    QString address;

    ///
    /// \brief port 端口
    ///
    quint16 port;

    ///
    /// \brief recvData 接收的数据
    ///
    QByteArray recvData;

    int recvLen;

    int nRecvLen;

    bool recvHead;

private:

    /*****************************
    * @brief:转换数据内容
    ******************************/
    QByteArray bgkToHex(QString str);
    QByteArray strToHex(QString str);
    QByteArray hexStringtoByteArray(QString hex);
    void formatString(QString &org, int n , const QChar &ch);
};

#endif // LICENSEPLATEZS_H
