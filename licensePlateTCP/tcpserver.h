#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>

#include "licensePlateTCP_global.h"
#include "tcpclient.h"

class TcpServer : public QTcpServer
{
    Q_OBJECT

public:
    explicit TcpServer(QObject *parent=nullptr);
    ~TcpServer();

    ///
    /// \brief incomingConnection 重写客户端接入
    /// \param handle
    ///
    void incomingConnection(qintptr socketID);

private:

    ///
    /// \brief clientSocketIdMap 客户端字典
    ///
    QMap<qintptr,TcpClient*> clientSocketIdMap;

    ///
    /// \brief clientChannelMap 通道字典
    ///
    QMultiMap<int,qintptr> clientChannelMap;

public slots:

    ///
    /// \brief disconnectedSlot 客户端断开信号(从客户端列表删除断开的客户端)
    ///
    void disconnectedSlot();

    ///
    /// \brief releaseResourcesSlot 释放动资源
    ///
    void releaseResourcesSlot();

signals:

    ///
    /// \brief signal_ResultPlate 接收车牌结果
    /// \param channel
    /// \param plate
    /// \param color
    /// \param time
    ///
    void signal_ResultPlate(int channel,QString plate,QString color,QString time,QString addr);

    ///
    /// \brief equipmentState  设备额在线状态
    /// \param state
    ///
    void equipmentStateSignal(const QString &camerIP, bool state);
};

#endif // TCPSERVER_H
