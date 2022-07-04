#include "tcpserver.h"

TcpServer::TcpServer(QObject *parent):QTcpServer (parent)
{
    this->setParent(parent);
}

TcpServer::~TcpServer()
{
    foreach (auto tcp, clientSocketIdMap.values()) {
        tcp->disconnected();
        tcp->abort();
        tcp->close();
        delete tcp;
        tcp=nullptr;
    }

    clientChannelMap.clear();
    clientSocketIdMap.clear();
}

void TcpServer::incomingConnection(qintptr socketID)
{
    TcpClient* pClient=new TcpClient (this);
    pClient->setSocketDescriptor(socketID);

    if(clientSocketIdMap.size()==1){
        qDebug().noquote()<<QString("The number of license plate links reached the upper limit. Procedure");
        pClient->disconnected();
        pClient->abort();
        pClient->close();
        delete pClient;
        pClient=nullptr;
        return;
    }

    clientSocketIdMap.insert(socketID,pClient);

    emit equipmentStateSignal(pClient->peerAddress().toString(),true);
    qDebug().noquote()<<QString("New client in join<IP:%1 PORT:%2>").arg(pClient->peerAddress().toString()).arg(pClient->peerPort());

    connect(pClient,&QIODevice::readyRead,pClient,&TcpClient::receiveDataSlot);
    connect(pClient,&TcpClient::disconnected,this,&TcpServer::disconnectedSlot);
    connect(pClient,&TcpClient::signal_ResultPlate,this,&TcpServer::signal_ResultPlate);
}

void TcpServer::disconnectedSlot()
{
    TcpClient* pClient=qobject_cast<TcpClient*>(sender());

    emit equipmentStateSignal(pClient->peerAddress().toString(),false);
    qDebug().noquote()<<QString("Client offline <IP:%1 PORT:%2>").arg(pClient->peerAddress().toString()).arg(pClient->peerPort());

    qintptr socketID= clientSocketIdMap.key(pClient);
    clientSocketIdMap.remove(socketID);
    clientChannelMap.remove(clientChannelMap.key(socketID));
}

void TcpServer::releaseResourcesSlot()
{
    this->close();
    qDebug().noquote()<<QString("TcpServer::releaseResourcesSlot");
}
