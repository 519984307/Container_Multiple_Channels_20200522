#include "tcpserver.h"

TcpServer::TcpServer(QObject *parent):QTcpServer (parent)
{    
    this->setParent(parent);
    InitializationParameter();
}

TcpServer::~TcpServer()
{
    foreach (auto tcp, clientSocketIdMap.values()){
        tcp->disconnected();
        tcp->abort();
        tcp->close();
        delete tcp;
        tcp=nullptr;
    }

    clientSocketIdMap.clear();
}

void TcpServer::InitializationParameter()
{    
    memset(tmpStatus,0,sizeof (tmpStatus));
}

void TcpServer::incomingConnection(qintptr socketID)
{
    TcpClient* pClient=new TcpClient (this);            
    pClient->setSocketDescriptor(socketID);
    clientSocketIdMap.insert(socketID,pClient);

    emit connectCountSignal(1);
    qDebug().noquote()<<QString("[%1] %2:%3 New client in join").arg(this->metaObject()->className(),pClient->peerAddress().toString(),QString::number(pClient->peerPort()));

    connect(pClient,&TcpClient::logicStatusSignal,this,&TcpServer::logicStatusSignal);
    connect(pClient,&QIODevice::readyRead,pClient,&TcpClient::receiveDataSlot);
    connect(pClient,&TcpClient::disconnected,this,&TcpServer::disconnectedSlot);
}

void TcpServer::disconnectedSlot()
{
    TcpClient* pClient=qobject_cast<TcpClient*>(sender());
    emit logicStatusSignal(tmpStatus);

    emit connectCountSignal(-1);
    qDebug().noquote()<<QString("[%1] %2:%3 Client offline").arg(this->metaObject()->className(),pClient->peerAddress().toString(),QString::number(pClient->peerPort()));

    qintptr socketID= clientSocketIdMap.key(pClient);
    clientSocketIdMap.remove(socketID);
}

void TcpServer::releaseResourcesSlot()
{
    this->close();

    qDebug().noquote()<<QString("[%1] releaseResourcesSlot").arg(this->metaObject()->className());
}

void TcpServer::toSendDataSlot(int channel_number, const QString &result)
{
    Q_UNUSED(channel_number);

    foreach (auto tcp, clientSocketIdMap.values()) {
        tcp->write(result.toLatin1());
    }
}

