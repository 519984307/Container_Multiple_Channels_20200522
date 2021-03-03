#include "tcpserver.h"

TcpServer::TcpServer(QObject *parent):QTcpServer (parent)
{    
    this->setParent(parent);
    pTimerSendHeartPack=nullptr;
    InitializationParameter();
}

void TcpServer::InitializationParameter()
{
    isHeartPack=false;
    pTimerSendHeartPack=new QTimer (this);
    connect(pTimerSendHeartPack,&QTimer::timeout,this,&TcpServer::heartbeatSlot);

    if(!pTimerSendHeartPack->isActive()){
        pTimerSendHeartPack->start(15000);
    }
}

void TcpServer::setServiceType(int serviceType)
{
    this->serviceType=serviceType;
}

void TcpServer::incomingConnection(qintptr socketID)
{
    TcpClient* pClient=new TcpClient (this);
    pClient->setSocketDescriptor(socketID);
    clientSocketIdMap.insert(socketID,pClient);

    emit connectCountSignal(1);
    qDebug().noquote()<<QString("New client in join<IP:%1 PORT:%2>").arg(pClient->peerAddress().toString()).arg(pClient->peerPort());

    connect(pClient,&QIODevice::readyRead,pClient,&TcpClient::receiveDataSlot);
    connect(pClient,&TcpClient::disconnected,this,&TcpServer::disconnectedSlot);
    connect(pClient,&TcpClient::setClientChannelNumberSignal,this,&TcpServer::setClientChannelNumberSlot);
    connect(pClient,&TcpClient::getLastResultSignal,this,&TcpServer::getLastResultSlot);
}

void TcpServer::disconnectedSlot()
{
    TcpClient* pClient=qobject_cast<TcpClient*>(sender());

    emit connectCountSignal(-1);
    qDebug().noquote()<<QString("Client offline <IP:%1 PORT:%2>").arg(pClient->peerAddress().toString()).arg(pClient->peerPort());

    qintptr socketID= clientSocketIdMap.key(pClient);
    clientSocketIdMap.remove(socketID);
    clientChannelMap.remove(clientChannelMap.key(socketID));
}

void TcpServer::setClientChannelNumberSlot(int channel_number, qintptr socketID)
{
    clientChannelMap.insert(channel_number,socketID);
}

void TcpServer::getLastResultSlot(qintptr socktID)
{
    TcpClient* pClient=clientSocketIdMap.value(socktID);
    if(pClient!=nullptr && pClient->isOpen()){
        pClient ->write(resultOfMemory.toLocal8Bit());
        qDebug().noquote()<<QString("Send Data %1:%2:%3").arg(pClient->peerAddress().toString()).arg(pClient->peerPort()).arg(resultOfMemory);
    }
}

void TcpServer::toSendDataSlot(int channel_number, const QString &result)
{
    resultOfMemory=result;

    if(serviceType==0){/* 多服务模式发送到所有链接的客户端 */
        foreach (auto tcp, clientSocketIdMap.values()) {
            tcp->write(result.toLocal8Bit());
        }
    }
    else if (serviceType==1) {/* 单服务模式只发送对应通道客户端 */
        foreach (auto socketID, clientChannelMap.values(channel_number)) {
            TcpClient* pClient=clientSocketIdMap.value(socketID,nullptr);
            if(pClient!=nullptr){
                pClient->write(result.toLocal8Bit());
                qDebug().noquote()<<QString("Send Data %1:%2:%3").arg(pClient->peerAddress().toString()).arg(pClient->peerPort()).arg(result);
            }
        }
    }
}

void TcpServer::heartbeatSlot()
{
    if(isHeartPack){
        foreach (auto client, clientSocketIdMap.values()) {
            client->write("[H]");
            qDebug().noquote()<<QString("Send HeartPackets");
        }
    }
}

void TcpServer::setHeartPacketStateSlot(bool state)
{
    isHeartPack=state;
}

void TcpServer::releaseResourcesSlot()
{
    this->close();

    if(pTimerSendHeartPack!=nullptr){
        pTimerSendHeartPack->stop();
    }

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
