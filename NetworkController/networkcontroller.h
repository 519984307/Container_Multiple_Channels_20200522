#ifndef NETWORKCONTROLLER_H
#define NETWORKCONTROLLER_H

#include "NetworkController_global.h"

class NETWORKCONTROLLER_EXPORT NetworkController:public QObject
{
    Q_OBJECT

public:
    NetworkController(QObject *parent=nullptr);
    ~NetworkController();

private:

    ///
    /// \brief loadAdapterMAC 获取网卡MAC地址
    /// \param address 要获取的网卡地址
    /// \return MAC地址
    ///
    QString loadAdapterMAC(QString addr);

    ///
    /// \brief analyticalData 解析数据
    ///
    void analyticalData(QByteArray data);

    ///
    /// \brief pTimerProcessData 延时解析网络继电器数据
    ///
    QTimer *pTimerProcessData;

    ///
    /// \brief pUdpClient Udp客户端
    ///
    QUdpSocket *pUdpClient;

    ///
    /// \brief eol 换行符
    ///
    QString eol;

    ///
    /// \brief searchType 搜索设备指令
    ///
    int searchType;

    ///
    /// \brief loopBackIP 环网地址
    ///
    QHostAddress loopBackIP;

    ///
    /// \brief localMAC 获取的网卡MAC
    ///
    QString localMAC;

    ///
    /// \brief equimentMacList 搜索到设备MAC
    ///
    QStringList equimentMacList;

    ///
    /// \brief equimentParMap 搜索设备参数值
    ///
    QMap<QString,QMap<QString,QString>> equimentParMap;

signals:

    ///
    /// \brief sendEquipmentParSignal 发送搜索到网络控制器参数
    /// \param par
    ///
    void sendEquipmentParSignal(QMap<QString,QMap<QString,QString>> par);

public slots:

    ///
    /// \brief setEquipmentParSlot 设置网络继电器参数
    /// \param addr
    ///
    void setEquipmentParSlot(QString par);

    ///
    /// \brief searchEquipmentSlot 搜索设备
    /// \param address 地址
    /// \param port 端口
    ///
    void searchEquipmentSlot(QString address,int port);

private slots:

    ///
    /// \brief udpReceiveDataSlot UDP接收数据
    ///
    void udpReceiveDataSlot();

    ///
    /// \brief processDataSlot 处理UDP接收到的数据
    /// \param data
    ///
    void processDataSlot(QByteArray par);

    ///
    /// \brief timerProcessEquimentDataSlot 延时加载网络控制器参数
    ///
    void timerProcessSlot();

    ///
    /// \brief processEquimentDataSlot 处理接收到的控制器参数
    ///
    void processEquimentDataSlot();
};

#endif // NETWORKCONTROLLER_H
