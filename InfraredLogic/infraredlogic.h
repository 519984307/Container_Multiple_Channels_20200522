#ifndef INFRAREDLOGIC_H
#define INFRAREDLOGIC_H

#include "infraredlogic_global.h"
#include "infraredlogicinterface.h"

class INFRAREDLOGICSHARED_EXPORT InfraredLogic:public InfraredlogicInterface
{
    Q_OBJECT
    Q_INTERFACES(InfraredlogicInterface)
    Q_PLUGIN_METADATA(IID InfraredlogicInterfaceIID)

public:
    explicit InfraredLogic(QObject *parent = nullptr);
    ~InfraredLogic() Q_DECL_OVERRIDE;

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

    ///
    /// \brief tmpStatus 临时红外信号
    ///
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
    /// \brief exit 退出循环状态
    ///
    bool exit;

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
    /// \brief pDetectionTimer 检测红外状态定时器
    ///
    QTimer* pDetectionTimer;

    ///
    /// \brief pRealySerialportTimer 重连串口定时器
    ///
    QTimer* pRealySerialportTimer;

    ///
    /// \brief pSerial1 串口1
    ///
    QSerialPort* pSerial1;

    ///
    /// \brief pSerial2 串口2
    ///
    QSerialPort* pSerial2;

    ///
    /// \brief com1 串口打开状态1
    ///
    bool com1;

    ///
    /// \brief com2 串口打开状态2
    ///
    bool com2;

    ///
    /// \brief port1 串口1
    ///
    QString port1;

    ///
    /// \brief port2 串口2
    ///
    QString port2;

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

private:

     ///
     /// \brief compareStatus 比较红外状态
     /// \param before 前一次状态
     /// \param after 后一次状态
     /// \return
     ///
     bool compareStatus(int* before,int* after);

     ///
     /// \brief serialLogicStatus 逻辑判断
     /// \param status 状态
     ///
     void serialLogic(int *status);

     ///
     /// \brief detectionLogicStatus 检测红外状态
     ///
     void detectionLogicStatus(bool com1,bool com2);

private slots:

     ///
     /// \brief delayAfterCaptureSlot 延时抓拍后3张图片.
     ///
     void delayAfterCaptureSlot();

     ///
     /// \brief DelayFrontCaptureSlot 延时抓拍前3张图片.
     ///
     void delayFrontCaptureSlot();

     ///
     /// \brief detectionLogicSlot 定时检测红外状态
     ///
     void detectionLogicSlot();

     ///
     /// \brief realyTheSerialport  串口打开失败重复打开
     ///
     void realyTheSerialport();

     ///
     /// \brief logicStateslot 红外状态写入日志
     /// \param msg
     ///
     void logicStateslot(int* state);

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
     void startSlaveSlot(const QString &portName1, const QString &portName2,const QString &address,int port,int model, int channelNum) Q_DECL_OVERRIDE;

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
     ///
     void setAlarmModeSlot(bool model, int logicType)Q_DECL_OVERRIDE;

     ///
     /// \brief DTypeOutSlot 网络控制器输出
     /// \param dType 输出类型
     /// \param lifting 抬杆类型
     ///
     void DTypeOutSlot(QList<int> dType,int lifting)Q_DECL_OVERRIDE;

     ///
     /// \brief exitWhile 退出循环
     ///
     void releaseResourcesSlot()Q_DECL_OVERRIDE;

signals:

     ///
     /// \brief logicStatesignal 红外状态写入日志
     /// \param msg
     ///
     void logicStatesignal(int* state);
};

#endif // INFRAREDLOGIC_H
