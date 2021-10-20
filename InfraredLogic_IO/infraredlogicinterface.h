#ifndef INFRAREDLOGIC_INTERFACE_H
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
   void serialPortStateSignal(bool com1,bool com2 ,bool socketState);

public slots:

   ///
   /// \brief startSlaveSlot 初始化串口
   /// \param portName1 串口1
   /// \param portName2 串口2
   /// \param address 地址
   /// \param port 端口
   /// \param model 模式
   /// \param channelNum 通道号
   ///
   virtual void startSlaveSlot(const QString &portName1, const QString &portName2,const QString &address,int port,int model, int channelNum)=0;

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
   /// \param logicType 红外逻辑类型
   /// \param A1ReleasrCap a1释放多久抓拍
   ///
   virtual void setAlarmModeSlot(bool model, int logicType ,int A1ReleasrCap)=0;

   ///
   /// \brief DTypeOutSlot 网络控制器输出
   /// \param dType 输出类型
   /// \param lifting 抬杆类型
   ///
   virtual void DTypeOutSlot(QList<int> dType,int lifting)=0;

   ///
   /// \brief releaseResourcesSlot 退出循环
   ///
   virtual void releaseResourcesSlot()=0;
};

#define InfraredlogicInterfaceIID "ZBY.ContainerServer.InfraredlogicInterface/1.5.0.4"
Q_DECLARE_INTERFACE(InfraredlogicInterface,InfraredlogicInterfaceIID);

#endif // INFRAREDLOGIC_INTERFACE_H
