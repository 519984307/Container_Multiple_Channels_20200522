#ifndef INFRAREDLOGIC_IO_H
#define INFRAREDLOGIC_IO_H

#include "InfraredLogic_IO_global.h"
#include "infraredlogicinterface.h"
#include "tcpserver.h"

class INFRAREDLOGIC_IO_EXPORT InfraredLogic_IO:public InfraredlogicInterface
{
    Q_OBJECT
    Q_INTERFACES(InfraredlogicInterface)
    Q_PLUGIN_METADATA(IID InfraredlogicInterfaceIID)

public:
    InfraredLogic_IO(QObject *parent = nullptr);
    ~InfraredLogic_IO() Q_DECL_OVERRIDE;

    ///
    /// \brief InterfaceType 插件类型，多插件调用统一接口
    /// \return
    ///
    QString InterfaceType()Q_DECL_OVERRIDE;

private:

    ///
    /// \brief status 红外信号状态
    ///
    int status[8];

    int tmpStatus[8];

    /* 红外信号值 */
    int valueOne,valueTwo;

    ///
    /// \brief type 模拟抓拍类型
    ///
    int type;

    /* 来车，车头，长箱，双箱，倒车 */
    bool comming,isCar,isLong,isDouble,reversing;

    ///
    /// \brief carInChannel 车辆在通道里面
    ///
    bool carInChannel;

    ///
    /// \brief doubleFrontPut 双22G1箱前面抓拍状态
    ///
    bool doubleFrontPut;

    ///
    /// \brief pTimerFront 前循环抓拍定时器
    ///
    QTimer* pTimerFront;

    ///
    /// \brief pTimerAfter 后循环抓拍定时器
    ///
    QTimer* pTimerAfter;

    ///
    /// \brief pCloseLEDTimer 检测红外状态定时器
    ///
    QTimer* pCloseLEDTimer;

    ///
    /// \brief pTimerStatus 网络控制器定时检测状态
    ///
    QTimer* pTimerStatus;

    ///
    /// \brief channelNum 通道号
    ///
    int channelNum;

    ///
    /// \brief logFile 日志文件
    ///
    QFile logFile;

    ///
    /// \brief lock 写入锁
    ///
    QReadWriteLock lock;

    ///
    /// \brief start 启动创建日志文件状态
    ///
    bool start;

    ///
    /// \brief logicType 红外逻辑类型
    ///
    int logicType;

    ///
    /// \brief A1ReleasrCap a1释放多久抓拍
    ///
    double A1ReleasrCap;

private slots:

    ///
    /// \brief rebootSerialportSlot 重启串口
    ///
    void rebootSerialportSlot();

    ///
    /// \brief delayAfterCaptureSlot 延时抓拍后3张图片.
    ///
    void delayAfterCaptureSlot();

    ///
    /// \brief DelayFrontCaptureSlot 延时抓拍前3张图片.
    ///
    void delayFrontCaptureSlot();

    ///
    /// \brief logicStateslot 红外状态写入日志
    /// \param msg
    ///
    void logicStateslot(int *state);

    ///
    /// \brief serialLogicSlot 逻辑判断
    /// \param status 状态
    ///
    void serialLogicSlot(int *sta);

    ///
    /// \brief timerCloseLEDSlot 延时关闭LED
    ///
    void timerCloseLEDSlot();

    ///
    /// \brief A1ReleasrCapSlot A1释放多少秒后主动抓拍
    ///
    void A1ReleasrCapSlot();

public:

    ///
    /// \brief startSlaveSlot 初始化串口
    /// \param portName1 串口1
    /// \param portName2 串口2
    /// \param address 地址
    /// \param port 端口
    /// \param model 模式
    /// \param channelNum 通道号
    ///
    virtual void startSlaveSlot(const QString &portName1, const QString &portName2,const QString &address,int port,int model,int channelNum)Q_DECL_OVERRIDE;

    ///
    /// \brief simulateTriggerSlot 模拟触发
    /// \param type 逻辑类型
    /// type=1 22G1
    /// type=2 45G1
    /// type=3 Double 22G1_F
    /// type=4 Double 22G1_b
    /// type=5 while
    ///
    void simulateTriggerSlot(int type)Q_DECL_OVERRIDE;

    ///
    /// \brief setAlarmModeSlot 设置红外模式
    /// \param mode 模式(敞开|常闭)
    /// \param logicType 红外逻辑类型
    /// \param A1ReleasrCap a1释放多久抓拍
    ///
    void setAlarmModeSlot(bool model, int logicType ,double A1ReleasrCap)Q_DECL_OVERRIDE;

    ///
    /// \brief DTypeOutSlot 网络控制器输出
    /// \param dType 输出类型
    /// \param lifting 抬杆类型
    ///
    void DTypeOutSlot(QList<int> dType,int lifting)Q_DECL_OVERRIDE;

    ///
    /// \brief releaseResourcesSlot 退出循环
    ///
    void releaseResourcesSlot()Q_DECL_OVERRIDE;

signals:

    ///
    /// \brief signal_releaseResources 释放服务端资源
    ///
    void signal_releaseResources();

/* TCP-------------------------------------------------- */

private:

    ///
    /// \brief eol 换行符
    ///
    QString eol;

    ///
    /// \brief isConnected 客户端链接状态
    ///
    bool isConnected;

    ///
    /// \brief isHeartBeat 心跳包状态
    ///
    int isHeartBeat;

    ///
    /// \brief channel 通道号
    ///
    int channel;

    ///
    /// \brief address 地址
    ///
    QString address;

    ///
    /// \brief port 端口
    ///
    quint16 port;

    ///
    /// \brief model 链接模式
    ///
    int model;

    ///
    /// \brief dOutType 控制器输出类型
    ///
    QList<int> dOutType;

    ///
    /// \brief pTcpClient 客户端
    ///
    QTcpSocket *pTcpClient;

    ///
    /// \brief pTcpServer 服务器
    ///
    TcpServer* pTcpServer;

    ///
    /// \brief pTimerAutoLink 定时自动链接
    ///
    QTimer *pTimerAutoLink;

private slots:

    ///
    /// \brief startLinkSlot 链接到服务器,客户端模式
    ///
    void startLinkSlot();

    ///
    /// \brief startListenSlot 开始监听,服务器模式
    ///
    void startListenSlot();

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
    /// \brief connectCountSignal 服务器模式链接数量
    /// \param count
    ///
    void connectCountSlot(int count);

signals:

    ///
    /// \brief signal_toSendData 服务器模式发送数据
    /// \param channel_number
    /// \param result
    ///
    void signal_toSendData(int channel_number, const QString &result);
};

#endif // INFRAREDLOGIC_IO_H
