﻿#ifndef INFRAREDLOGIC_INTERFACE_H
#define INFRAREDLOGIC_INTERFACE_H

#include <QObject>

class InfraredlogicInterface:public QObject
{
    Q_OBJECT

public:
    virtual ~InfraredlogicInterface(){}

    ///
    /// \brief InterfaceType 插件类型，多插件调用统一接口
    /// \return
    ///
    virtual QString InterfaceType()=0;

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

     ///
     /// \brief serialPortStateSignal 串口状态
     /// \param com1
     /// \param com2
     ///
     void serialPortStateSignal(bool com1,bool com2);

public slots:

   ///
   /// \brief startSlave 初始化串口
   /// \param portName1 串口1
   /// \param portName2 串口2
   ///
   virtual void startSlaveSlot(const QString &portName1, const QString &portName2,int channelNum)=0;

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
   ///
   virtual void exitWhileSlot()=0;
};

#define InfraredlogicInterfaceIID "ZBY.ContainerServer.InfraredlogicInterface/1.4.5.2"
Q_DECLARE_INTERFACE(InfraredlogicInterface,InfraredlogicInterfaceIID);

#endif // INFRAREDLOGIC_INTERFACE_H
