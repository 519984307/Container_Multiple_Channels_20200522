#include "networkcontroller.h"

NetworkController::NetworkController(QObject *parent)
{
    this->setParent(parent);

    pUdpClient=nullptr;
    pTimerProcessData=nullptr;

#ifdef Q_OS_LINUX
    eol = "\n";
#endif
#ifdef Q_OS_WIN
    eol = "\r\n";
#endif
}

NetworkController::~NetworkController()
{
    if(nullptr != pUdpClient){
        pUdpClient->close();
        pUdpClient->abort();
    }
    delete pUdpClient;
    pUdpClient=nullptr;

    if(nullptr != pTimerProcessData){
        pTimerProcessData->stop();
    }
    delete pTimerProcessData;
    pTimerProcessData=nullptr;
}

QString NetworkController::loadAdapterMAC(QString addr)
{
    QList<QNetworkInterface> adapterList = QNetworkInterface::allInterfaces();
    foreach (QNetworkInterface adapter, adapterList) {
        if(adapter.flags().testFlag(QNetworkInterface::IsUp)
                        &&adapter.flags().testFlag(QNetworkInterface::IsRunning)
                        &&adapter.flags().testFlag(QNetworkInterface::CanBroadcast)
                        &&adapter.flags().testFlag(QNetworkInterface::CanMulticast)
                        &&!adapter.flags().testFlag(QNetworkInterface::IsLoopBack))
        {
            QList<QNetworkAddressEntry> addressList = adapter.addressEntries();
            foreach (QNetworkAddressEntry address, addressList) {
                if(address.ip().toString() == addr){
                    qDebug()<<"------------------------------------------------------------";
                    qDebug()<<"Adapter Name:"<<adapter.name();
                    qDebug()<<"Adapter Address:"<<adapter.hardwareAddress();
                    qDebug()<<"IP Address:"<<address.ip().toString();
                    qDebug()<<"IP Mask:"<<address.netmask().toString();
                    qDebug()<<"------------------------------------------------------------";
                    return adapter.hardwareAddress();
                }
            }
        }
    }
    return QString("");
}

void NetworkController::searchEquipmentSlot(QString address, int port)
{
    searchType=1;

    equimentMacList.clear();
    equimentParMap.clear();
    //parMap.clear();

    if(nullptr == pTimerProcessData){
        pTimerProcessData=new QTimer(this);
        pTimerProcessData->setSingleShot(true);
        connect(pTimerProcessData,&QTimer::timeout,this,&NetworkController::timerProcessSlot);
    }

    if(nullptr == pUdpClient){
        pUdpClient=new QUdpSocket(this);
        connect(pUdpClient,&QUdpSocket::readyRead,this,&NetworkController::udpReceiveDataSlot);
    }

    pUdpClient->close();
    pUdpClient->abort();

    /*****************************
    * @brief:读取当前网卡网络地址
    ******************************/
    int pos = address.indexOf("]");
    QString addr=address.mid(1,pos-1);

    if(pUdpClient->bind(QHostAddress(addr),port)){
        qDebug().noquote()<<QString("[%1] %2:%3 bing sucess").arg(this->metaObject()->className(),addr,QString::number(port));
    }
    else {
        qWarning().noquote()<<QString("[%1] %2:%3 bing failure").arg(this->metaObject()->className(),addr,QString::number(port));
    }

    localMAC=loadAdapterMAC(addr);
    if(localMAC.isEmpty()){
        qWarning().noquote()<<QString("[%1] %2 The MAC address of the network adapter fails to be obtained").arg(this->metaObject()->className(),addr);
    }
    else {
        /*****************************
        * @brief:搜索设备
        ******************************/
        QString cmd=QString("<00:00:00:00:00:00>,<%1>,AT%2").arg(localMAC,eol);

        /*****************************
        * @brief:设置环网地址
        ******************************/
        int pos=addr.lastIndexOf('.');
        addr.replace(pos+1,addr.size()-pos,"255");
        loopBackIP=QHostAddress(addr);

        /*****************************
        * @brief:UDP环网发送信息默认端口(5000)
        ******************************/
        if(pUdpClient->writeDatagram(cmd.toLatin1(),cmd.size(),loopBackIP,5000)){
            qDebug().noquote()<<QString("[%1] %2:%3 udp send sucess").arg(this->metaObject()->className(),loopBackIP.toString(),QString::number(5000));
        }
    }
}

void NetworkController::udpReceiveDataSlot()
{
    while (pUdpClient->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(pUdpClient->pendingDatagramSize());
        pUdpClient->readDatagram(datagram.data(), datagram.size(),&loopBackIP);

        if(-1 == datagram.indexOf("<00:00:00:00:00:00>")){
            if(1 == searchType){
                analyticalData(datagram);
            }
            if(2 == searchType){
                QtConcurrent::run(this,&NetworkController::processDataSlot,datagram);
            }
        }
    }
}

void NetworkController::analyticalData(QByteArray data)
{
    if(pTimerProcessData->isActive()){
        pTimerProcessData->stop();
    }

    if(-1 != data.indexOf("OK")){
        equimentMacList.append(data.split(',')[0]);
    }

    pTimerProcessData->start(1500);
}

void NetworkController::setEquipmentParSlot(QString par)
{

}

void NetworkController::processDataSlot(QByteArray par)
{
    int sPos=par.indexOf('+');
    int ePos=par.lastIndexOf(':');
    QMap<QString,QString> parMap;
    parMap.insert(par.mid(sPos+1,ePos-sPos-1),par.mid(ePos+1).trimmed());
    equimentParMap.insertMulti(par.split(',')[0],parMap);
    parMap.clear();

    qDebug()<<equimentParMap.values(par.split(',')[0]).size();
    if(equimentParMap.values(par.split(',')[0]).size()==9){
        emit sendEquipmentParSignal(equimentParMap);
    }
}

void NetworkController::timerProcessSlot()
{
    QtConcurrent::run(this,&NetworkController::processEquimentDataSlot);
}

void NetworkController::processEquimentDataSlot()
{
    this->searchType=2;
    foreach (QString mac, equimentMacList) {
        QString cmd=QString("%1,<%2>,AT+IP=?%3").arg(mac,localMAC,eol);
        if(pUdpClient->writeDatagram(cmd.toLatin1(),cmd.size(),loopBackIP,5000)){
            qDebug().noquote()<<QString("[%1] %2:%3 udp send sucess").arg(this->metaObject()->className(),loopBackIP.toString(),QString::number(5000));
        }

        QThread::msleep(10);
        cmd=QString("%1,<%2>,AT+GATEWAY=?%3").arg(mac,localMAC,eol);
        if(pUdpClient->writeDatagram(cmd.toLatin1(),cmd.size(),loopBackIP,5000)){
            qDebug().noquote()<<QString("[%1] %2:%3 udp send sucess").arg(this->metaObject()->className(),loopBackIP.toString(),QString::number(5000));
        }

        QThread::msleep(10);
        cmd=QString("%1,<%2>,AT+MASK=?%3").arg(mac,localMAC,eol);
        if(pUdpClient->writeDatagram(cmd.toLatin1(),cmd.size(),loopBackIP,5000)){
            qDebug().noquote()<<QString("[%1] %2:%3 udp send sucess").arg(this->metaObject()->className(),loopBackIP.toString(),QString::number(5000));
        }

        QThread::msleep(10);
        cmd=QString("%1,<%2>,AT+PORT=?%3").arg(mac,localMAC,eol);
        if(pUdpClient->writeDatagram(cmd.toLatin1(),cmd.size(),loopBackIP,5000)){
            qDebug().noquote()<<QString("[%1] %2:%3 udp send sucess").arg(this->metaObject()->className(),loopBackIP.toString(),QString::number(5000));
        }

        QThread::msleep(10);
        cmd=QString("%1,<%2>,AT+MODEL=?%3").arg(mac,localMAC,eol);
        if(pUdpClient->writeDatagram(cmd.toLatin1(),cmd.size(),loopBackIP,5000)){
            qDebug().noquote()<<QString("[%1] %2:%3 udp send sucess").arg(this->metaObject()->className(),loopBackIP.toString(),QString::number(5000));
        }

        QThread::msleep(10);
        cmd=QString("%1,<%2>,AT+DIP=?%3").arg(mac,localMAC,eol);
        if(pUdpClient->writeDatagram(cmd.toLatin1(),cmd.size(),loopBackIP,5000)){
            qDebug().noquote()<<QString("[%1] %2:%3 udp send sucess").arg(this->metaObject()->className(),loopBackIP.toString(),QString::number(5000));
        }

        QThread::msleep(10);
        cmd=QString("%1,<%2>,AT+DPORT=?%3").arg(mac,localMAC,eol);
        if(pUdpClient->writeDatagram(cmd.toLatin1(),cmd.size(),loopBackIP,5000)){
            qDebug().noquote()<<QString("[%1] %2:%3 udp send sucess").arg(this->metaObject()->className(),loopBackIP.toString(),QString::number(5000));
        }

        QThread::msleep(10);
        cmd=QString("%1,<%2>,AT+WID=?%3").arg(mac,localMAC,eol);
        if(pUdpClient->writeDatagram(cmd.toLatin1(),cmd.size(),loopBackIP,5000)){
            qDebug().noquote()<<QString("[%1] %2:%3 udp send sucess").arg(this->metaObject()->className(),loopBackIP.toString(),QString::number(5000));
        }

        QThread::msleep(10);
        cmd=QString("%1,<%2>,AT+NAME=?%3").arg(mac,localMAC,eol);
        if(pUdpClient->writeDatagram(cmd.toLatin1(),cmd.size(),loopBackIP,5000)){
            qDebug().noquote()<<QString("[%1] %2:%3 udp send sucess").arg(this->metaObject()->className(),loopBackIP.toString(),QString::number(5000));
        }
    }
}

