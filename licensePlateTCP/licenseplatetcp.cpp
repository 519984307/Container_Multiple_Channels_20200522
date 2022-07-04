#include "licenseplatetcp.h"

LicensePlateTCP::LicensePlateTCP(QObject *parent)
{
    this->setParent(parent);
}

LicensePlateTCP::~LicensePlateTCP()
{
}

QString LicensePlateTCP::InterfaceType()
{
    return  QString("TCP_PLATE");
}

void LicensePlateTCP::simulationCaptureSlot()
{
}

void LicensePlateTCP::liftingElectronicRailingSlot(bool gate)
{
    Q_UNUSED(gate)
}

void LicensePlateTCP::transparentTransmission485Slot(const QString &msg)
{
    Q_UNUSED(msg)
}

void LicensePlateTCP::openTheVideoSlot(bool play, quint64 winID)
{
    Q_UNUSED(play)
    Q_UNUSED(winID)
}

void LicensePlateTCP::releaseResourcesSlot()
{
}

void LicensePlateTCP::initCamerSlot(const QString &localAddr, const QString &camerIP, const int &camerPort, const QString &CamerUser, const QString &CamerPow, const QString &signature)
{
    Q_UNUSED(localAddr)
    Q_UNUSED(camerIP)
    Q_UNUSED(camerPort)
    Q_UNUSED(CamerUser)
    Q_UNUSED(CamerPow)
    Q_UNUSED(signature)

    pTcpServer=new TcpServer (this);
    connect(pTcpServer,&TcpServer::signal_ResultPlate,this,&LicensePlateTCP::slot_ResultPlate);
    connect(pTcpServer,&TcpServer::equipmentStateSignal,this,&LicensePlateTCP::slot_EquipmentState);

    if(!pTcpServer->listen(QHostAddress::AnyIPv4,8080)){/* 服务器使用本机地址 */
        qWarning().noquote()<<QString("IP:%1 Plate Listen error<errocCode=%2>").arg("127.0.0.1").arg(pTcpServer->errorString());
    }
    else {
        qDebug().noquote()<<QString("IP:%1 Plate Start listen.").arg("127.0.0.1");
    }
}

void LicensePlateTCP::getLastPlateSlot()
{
}

void LicensePlateTCP::slot_pictureStream(int ID, QByteArray arrJpg)
{
    Q_UNUSED(ID)
    Q_UNUSED(arrJpg)
}

void LicensePlateTCP::slot_setCameraID(int ID, QString cameraIP)
{
    Q_UNUSED(ID)
    Q_UNUSED(cameraIP)
}

void LicensePlateTCP::slot_resultsTheLicensePlate(int ID, const QString &plate, const QString &color, const QString &time, const QByteArray &arrImg)
{
    Q_UNUSED(ID)
    Q_UNUSED(arrImg)
    Q_UNUSED(plate)
    Q_UNUSED(color)
    Q_UNUSED(time)
}

void LicensePlateTCP::slot_equipmentState(int ID, bool state)
{
    Q_UNUSED(ID)
    Q_UNUSED(state)
}

void LicensePlateTCP::slot_ResultPlate(int channel, QString plate, QString color, QString time,QString addr)
{
    Q_UNUSED(channel)

    qDebug().noquote()<<QString("[%3] %4:8080 License Plate recognition results:%1-%2").arg(plate,time,this->metaObject()->className(),addr);
    emit resultsTheLicensePlateSignal(plate,color,time,nullptr);
}

void LicensePlateTCP::slot_EquipmentState(const QString &camerIP, bool state)
{
    emit equipmentStateSignal(camerIP,state);
}
