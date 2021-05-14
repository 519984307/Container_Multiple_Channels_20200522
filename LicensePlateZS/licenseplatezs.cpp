#include "licenseplatezs.h"

LicensePlateZS::LicensePlateZS(QObject *parent)
{
    this->setParent(parent);

    isConnected=false;
    cls="LicensePlateZS";
}

LicensePlateZS::~LicensePlateZS()
{    
    delete  pTcpClient;
    pTcpClient=nullptr;
}

QString LicensePlateZS::InterfaceType()
{

}

void LicensePlateZS::simulationCaptureSlot()
{

}

void LicensePlateZS::liftingElectronicRailingSlot(bool gate)
{

}

void LicensePlateZS::transparentTransmission485Slot(const QString &msg)
{

}

void LicensePlateZS::openTheVideoSlot(bool play, quint64 winID)
{

}

void LicensePlateZS::releaseResourcesSlot()
{
    pTcpClient->close();
    pTcpClient->abort();
}

void LicensePlateZS::initCamerSlot(const QString &localAddr, const QString &camerIP, const int &camerPort, const QString &CamerUser, const QString &CamerPow, const QString &signature)
{
    Q_UNUSED(localAddr);
    Q_UNUSED(signature);
    Q_UNUSED(CamerPow);
    Q_UNUSED(CamerUser);

    this->address=camerIP;
    this->port=camerPort;

    pTcpClient=new QTcpSocket(this);

    connect(pTcpClient,&QIODevice::readyRead,this,&LicensePlateZS::receiveDataSlot);
    connect(pTcpClient,&QAbstractSocket::connected,this,&LicensePlateZS::connectedSlot);
    connect(pTcpClient,&QAbstractSocket::disconnected,this,&LicensePlateZS::disconnectedSlot);
    connect(pTcpClient,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this,&LicensePlateZS::displayErrorSlot);

    connect(pTimerLinkState,&QTimer::timeout,this,&LicensePlateZS::startLinkSlot);

    startLinkSlot();
}

void LicensePlateZS::slot_pictureStream(int ID, QByteArray arrJpg)
{

}

void LicensePlateZS::slot_setCameraID(int ID, QString cameraIP)
{

}

void LicensePlateZS::slot_resultsTheLicensePlate(int ID, const QString &plate, const QString &color, const QString &time, const QByteArray &arrImg)
{

}

void LicensePlateZS::slot_equipmentState(int ID, bool state)
{

}

void LicensePlateZS::startLinkSlot()
{
    if(!isConnected){
        pTcpClient->close();
        pTcpClient->abort();
        pTcpClient->connectToHost(address,port);
    }
}

void LicensePlateZS::connectedSlot()
{
    isConnected=true;

    if(!pTimerLinkState->isActive()){
        pTimerLinkState->start(15000);
    }

    emit equipmentStateSignal(address,true);
    qDebug().noquote()<<QString("IP:%1:%2 link successful").arg(address,port);
}

void LicensePlateZS::receiveDataSlot()
{

}

void LicensePlateZS::disconnectedSlot()
{
    isConnected=false;

    emit equipmentStateSignal(address,false);
    qDebug().noquote()<<QString("[%3] %1:%2 disconnected").arg(address,QString::number(port),cls);
}

void LicensePlateZS::displayErrorSlot(QAbstractSocket::SocketError socketError)
{
    isConnected=false;

    if(!pTimerLinkState->isActive()){
        pTimerLinkState->start(15000);
    }
    qWarning().noquote()<<QString("[%4] %1:%3 link error<errorCode=%2>").arg(address,QString::number(socketError),QString::number(port),cls);
}
