#ifndef ENCRYPTIONINTERFACE_H
#define ENCRYPTIONINTERFACE_H

#include <QObject>

class EncryptionInterface : public QObject
{
    Q_OBJECT

public:
    virtual ~EncryptionInterface(){}

signals:

    ///
    /// \brief GetEncryptedInformation 获取加密信息
    /// \param data 数据
    ///
    void GetEncryptedInformationSignal(const QString& data);

    ///
    /// \brief GetTheEncryptedState 获取加密状态
    /// \param state
    ///
    void GetTheEncryptedStateSignal(bool state);

    ///
    /// \brief messageSignal 日志信息
    /// \param type 日志类型
    /// \param msg 信息体
    ///
    void messageSignal(const QString &type,const QString &msg);

public slots:

    ///
    /// \brief InitializationSlot 初始化参数
    ///
    virtual void InitializationSlot(int dogType,QString dogIdd)=0;

    ///
    /// \brief releaseResourcesSlot 释放动资源
    ///
    virtual void releaseResourcesSlot()=0;

};

/* 福建达远
 * ed302361196401966c72f116402e9297
 * ae68c66368a8e943bc260ae97003747f
*/
/* 辽宁锦州
 * 2895743a6f3c423adfc444d16076e085
*/
/* 惠州key
 * 5e8d317e83c2f7ace3584a929961fcb4
*/
/*沈阳安信
 * f19d15dec81584b5ce4f9edb0aae1789
*/
/*福建平潭
 * ae68c66368a8e943bc260ae97003747f
*/
/* 烟台贝奇
 * f19d15dec81584b5ce4f9edb0aae1789
*/
/* 武汉软著
 * 60b02f171e6d2b28673cdcb5faef01e1
 * 430c4bdbd03296d3f0b2080eceadbe83
 * 92e8b6c3ae9bf38f45654695bc542842
*/

//#define _ENCRYPTION_
#ifdef _ENCRYPTION_
#define EncryptionInterfaceIID "ZBY.ContainerServer.EncryptionInterface/0.0.0.2"
#else
#define EncryptionInterfaceIID "ZBY.ContainerServer.EncryptionInterface/16452187ec9d9da939977d8b352f7c1e"
#endif

Q_DECLARE_INTERFACE(EncryptionInterface,EncryptionInterfaceIID);

#endif // ENCRYPTIONINTERFACE_H
