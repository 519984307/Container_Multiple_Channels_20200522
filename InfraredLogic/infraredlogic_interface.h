#ifndef INFRAREDLOGIC_INTERFACE_H
#define INFRAREDLOGIC_INTERFACE_H

#define ZBY_LOG(type)  tr("[%1][%2][%3]").arg(type).arg(Q_FUNC_INFO).arg(__LINE__)

#include <QObject>

class InfraredLogic_Interface : public QObject
{
    Q_OBJECT

public:
    virtual ~ InfraredLogic_Interface(){}

signals:

    ///
    /// \brief messageSignal 日志信息
    /// \param type 日志类型
    /// \param msg 信息体
    ///
    void messageSignal(const QString &type,const QString &msg);

     ///
     /// \brief logicStatus 红外信号状态
     /// \param status 状态码
     ///
     void logicStatusSignal(int* status);

     ///
     /// \brief setLogicPutImage 逻辑抓图
     /// \param putCommnd 逻辑
     ///
     void logicPutImageSignal(const int &putCommnd);

public slots:

     ///
     /// \brief initializationParameter 初始化参数
     ///
   virtual void initializationParameter()=0;

   ///
   /// \brief startSlave 初始化串口
   /// \param portName1 串口1
   /// \param portName2 串口2
   ///
   virtual void startSlaveSlot(const QString &portName1, const QString &portName2)=0;

   ///
   /// \brief simulateTriggerSlot 模拟触发
   /// \param type 逻辑类型
   /// type=1 22G1
   /// type=2 45G1
   /// type=3 Double 22G1_F
   /// type=4 Double 22G1_b
   /// type=5 while
   ///
   virtual void simulateTriggerSlot(int type)=0;

   ///
   /// \brief setAlarmModeSlot 设置红外模式
   /// \param mode 模式(敞开|常闭)
   ///
   virtual void setAlarmModeSlot(bool model)=0;

   ///
   /// \brief exitWhile 退出循环
   /// \param exit
   ///
   virtual void exitWhileSlot(bool exit)=0;
};

#define InfraredLogic_InterfaceIID "ZBY.ContainerServer.InfraredLogic_Interface/1.0"
Q_DECLARE_INTERFACE(InfraredLogic_Interface,InfraredLogic_InterfaceIID);

#endif // INFRAREDLOGICINTERFACE_H
