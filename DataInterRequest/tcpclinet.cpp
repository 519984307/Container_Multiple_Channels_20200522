#include "tcpclinet.h"

TcpClient::TcpClient(QObject *parent, QString addr, int port)
{
    this->setParent(parent);

    pTcpClient=new QTcpSocket(this);
    connect(pTcpClient,&QIODevice::readyRead,this,&TcpClient::receiveDataSlot);
    connect(pTcpClient,&QAbstractSocket::connected,this,&TcpClient::connectedSlot);
    connect(pTcpClient,&QAbstractSocket::disconnected,this,&TcpClient::disconnectedSlot);
    connect(pTcpClient,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this,&TcpClient::displayErrorSlot);

    pTimerLinkState=new QTimer(this);
    pTimerAutoLink= new QTimer(this);
    connect(pTimerLinkState,&QTimer::timeout,this,&TcpClient::heartbeatSlot);
    connect(pTimerAutoLink,&QTimer::timeout,this,&TcpClient::startLinkSlot);

    isConnected=false;
    this->addr=addr;
    this->port=port;

    startLinkSlot();
}

TcpClient::~TcpClient()
{
    if(pTcpClient != nullptr && pTcpClient->isOpen()){
        pTcpClient->disconnected();
        pTcpClient->close();
        pTcpClient->abort();
    }

    isConnected=false;

    if(pTimerLinkState!=nullptr){
        pTimerLinkState->stop();
    }
    if(pTimerAutoLink!=nullptr){
        pTimerAutoLink->stop();
    }

    delete pTimerLinkState;
    pTimerLinkState=nullptr;

    delete  pTimerAutoLink;
    pTimerAutoLink=nullptr;
}

void TcpClient::startLinkSlot()
{
    if(!isConnected){
        pTcpClient->close();
        pTcpClient->abort();
        pTcpClient->connectToHost(addr,port);
    }
}

void TcpClient::heartbeatSlot()
{
    if(pTcpClient->isOpen()){
        pTcpClient->write("[H]");/* 心跳包数据 */
    }
}

void TcpClient::connectedSlot()
{
    isConnected=true;

    if(!pTimerLinkState->isActive()){
        pTimerLinkState->start(15000);
    }

    qDebug().noquote()<<QString("IP:%1:%2 link successful").arg(addr).arg(port);
}

void TcpClient::receiveDataSlot()
{
    /*****************************
    * @brief:服务器主动取结果
    ******************************/
    QByteArray buf=pTcpClient->readAll();
    qDebug()<<QString("The internal socket receives data:%1").arg(buf.data());
    buf.clear();
}

void TcpClient::disconnectedSlot()
{
    isConnected=false;
}

void TcpClient::displayErrorSlot(QAbstractSocket::SocketError socketError)
{
    isConnected=false;

    pTimerAutoLink->start(15000);
    qWarning().noquote()<<QString("IP:%1:%3  link error<errorCode=%2>").arg(addr).arg(socketError).arg(port);
}

void TcpClient::toSendDataSlot(int channel_number,const QString &data)
{
    Q_UNUSED(channel_number);

    if(!pTcpClient->isOpen()){
        startLinkSlot();
        pTcpClient->waitForConnected(3000);
    }
    pTcpClient->write(data.toUtf8());
}
