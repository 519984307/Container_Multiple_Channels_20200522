﻿#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QTimer>
#include <QDebug>

class TcpClient : public QObject
{
    Q_OBJECT

public:
    TcpClient(QObject* parent=nullptr,QString addr="127.0.0.1",int port=65000);
    ~TcpClient();

private:

    ///
    /// \brief pTcpClient 客户端
    ///
    QTcpSocket *pTcpClient;

    QString addr;
    int port;

    ///
    /// \brief isConnected 链接状态
    ///
    bool isConnected;

    ///
    /// \brief pTimerLinkState 定时心跳包检测
    ///
    QTimer *pTimerLinkState;

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
    /// \brief heartbeatSlot 心跳检测
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

public slots:

    ///
    /// \brief toSendDataSlot 发送数据
    /// \param channel_number
    /// \param data
    ///
    void toSendDataSlot(int channel_number,const QString &data);

};

#endif // TCPCLIENT_H
