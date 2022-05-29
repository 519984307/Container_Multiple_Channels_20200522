#include "tcpclient.h"

TcpClient::TcpClient(QObject *parent) : QObject(parent)
{
    this->setParent(parent);

    isConnected=false;

    pTcpClient=new QTcpSocket(this);
    pTimerAutoLink=new QTimer(this);
    pTimerAutoLink->setSingleShot(true);

    pTimerLinkState=new QTimer(this);

    connect(pTcpClient,&QIODevice::readyRead,this,&TcpClient::receiveDataSlot);
    connect(pTcpClient,&QAbstractSocket::connected,this,&TcpClient::connectedSlot);
    connect(pTcpClient,&QAbstractSocket::disconnected,this,&TcpClient::disconnectedSlot);
    connect(pTcpClient,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this,&TcpClient::displayErrorSlot);
    connect(pTimerLinkState,&QTimer::timeout,this,&TcpClient::heartbeatSlot);
    connect(pTimerAutoLink,&QTimer::timeout,this,&TcpClient::startLinkSlot);

    startLinkSlot();
}

TcpClient::~TcpClient()
{
    if(pTcpClient!=nullptr){
        pTcpClient->close();
        delete  pTcpClient;
        pTcpClient=nullptr;
    }
}

void TcpClient::decectTcpImageSlot(const QString &image, const int& imgNum)
{
    Q_UNUSED(imgNum)

    if(isConnected && pTcpClient->isOpen()){
        qDebug()<<image;
        pTcpClient->write("-i"+image.toLatin1());
    }
}

void TcpClient::releaseResourcesSlot()
{
    if(pTcpClient!=nullptr){
        pTcpClient->close();
        delete  pTcpClient;
        pTcpClient=nullptr;
    }

    pTimerAutoLink->stop();
    delete  pTimerAutoLink;
    pTimerAutoLink=nullptr;

    pTimerLinkState->stop();
    delete pTimerLinkState;
    pTimerLinkState=nullptr;
}

void TcpClient::startLinkSlot()
{
    if(!isConnected){
        pTcpClient->close();
        pTcpClient->abort();
        pTcpClient->connectToHost("127.0.0.1",55550);
    }
}

void TcpClient::heartbeatSlot()
{
    if(pTcpClient->isOpen()){
        pTcpClient->write("");/* 心跳包数据 */
    }
}

void TcpClient::connectedSlot()
{
    isConnected=true;

    emit decectSatusSignal(isConnected);

    if(!pTimerLinkState->isActive()){
        pTimerLinkState->start(5000);
    }
    qInfo().noquote()<<QString("[%1] %2-%3:Connecting to the server succeeded").arg(this->metaObject()->className(),"127.0.0.1",QString::number(55550));
}

void TcpClient::receiveDataSlot()
{
    QByteArray buf=pTcpClient->readAll();
    emit decectRstSignal(buf.data());
    buf.clear();
}

void TcpClient::disconnectedSlot()
{
    isConnected=false;
    emit decectSatusSignal(isConnected);
}

void TcpClient::displayErrorSlot(QAbstractSocket::SocketError socketError)
{
    isConnected=false;
    emit decectSatusSignal(isConnected);

    pTimerAutoLink->start(15000);
    qWarning().noquote()<<QString("[%1] %2-%3:Link server error<errCode=%4>").arg(this->metaObject()->className(),"127.0.0.1",QString::number(55550),QString::number(socketError));
}
