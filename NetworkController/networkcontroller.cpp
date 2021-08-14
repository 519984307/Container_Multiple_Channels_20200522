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
    setParState=0;

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
        pUdpClient->readDatagram(datagram.data(), datagram.size()/*,&loopBackIP*/);

        if(-1 == datagram.indexOf("<00:00:00:00:00:00>")){
            if(1 == searchType){
                analyticalData(datagram);
            }
            if(2 == searchType && -1 == datagram.indexOf('?')){
                QtConcurrent::run(this,&NetworkController::processDataSlot,datagram);
            }
            if(3 == searchType && -1 != datagram.indexOf("OK")){
                setParState++;
                /*****************************
                * @brief:6为设置心跳包和注册包
                ******************************/
                if(setParState==15){
                    emit setParSucessSignal();
                    setParState=0;
                }
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

    pTimerProcessData->start(1000);
}

void NetworkController::setEquipmentParSlot(QMap<QString, QMap<QString,QString>> par)
{
    QtConcurrent::run(this,&NetworkController::processEquimentDataSlot,par,2);
}

void NetworkController::processDataSlot(QByteArray par)
{
    int sPos=par.indexOf('+');
    int ePos=par.lastIndexOf(':');
    QString key=par.split(',')[0];
    QMap<QString,QString> parMap;
    parMap.insert(par.mid(sPos+1,ePos-sPos-1),par.mid(ePos+1).trimmed());
    equimentParMap.insertMulti(key,parMap);
    parMap.clear();

    qDebug()<<"processDataSlot"<<par.mid(sPos+1,ePos-sPos-1)<<"|"<<par.mid(ePos+1).trimmed();

    if(equimentParMap.keys().toSet().toList().size()==equimentMacList.size()){
        if(equimentParMap.values(key).size()==9){
            emit sendEquipmentParSignal(equimentParMap);
        }
    }
}

void NetworkController::timerProcessSlot()
{
    QtConcurrent::run(this,&NetworkController::processEquimentDataSlot,equimentParMap, 1);
}

void NetworkController::processEquimentDataSlot(QMap<QString, QMap<QString, QString>> par, int type)
{
    /*****************************
    * @brief:读取参数
    ******************************/
    if(1==type){
        this->searchType=2;
        foreach (QString mac, equimentMacList) {

            QThread::msleep(10);
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
    /*****************************
    * @brief:设置参数
    ******************************/
    if(2==type){
        this->searchType=3;
        if(par.keys().size()==1){
            foreach (QString key, par.keys()) {
                QMap<QString,QString> var=par.value(key);
                if(!var.value("IP","").isEmpty()){
                    QString cmd=QString("%1,<%2>,AT+IP=%3%4").arg(key,localMAC,var.value("IP"),eol);
                    if(pUdpClient->writeDatagram(cmd.toLatin1(),cmd.size(),loopBackIP,5000)){
                        qDebug().noquote()<<QString("[%1] %2:%3 udp send sucess").arg(this->metaObject()->className(),loopBackIP.toString(),QString::number(5000));
                    }
                }

                if(!var.value("GATEWAY","").isEmpty()){
                    QThread::msleep(10);
                    QString cmd=QString("%1,<%2>,AT+GATEWAY=%3%4").arg(key,localMAC,var.value("GATEWAY"),eol);
                    if(pUdpClient->writeDatagram(cmd.toLatin1(),cmd.size(),loopBackIP,5000)){
                        qDebug().noquote()<<QString("[%1] %2:%3 udp send sucess").arg(this->metaObject()->className(),loopBackIP.toString(),QString::number(5000));
                    }
                }

                if(!var.value("MASK","").isEmpty()){
                    QThread::msleep(10);
                    QString cmd=QString("%1,<%2>,AT+MASK=%3%4").arg(key,localMAC,var.value("MASK"),eol);
                    if(pUdpClient->writeDatagram(cmd.toLatin1(),cmd.size(),loopBackIP,5000)){
                        qDebug().noquote()<<QString("[%1] %2:%3 udp send sucess").arg(this->metaObject()->className(),loopBackIP.toString(),QString::number(5000));
                    }
                }

                if(!var.value("PORT","").isEmpty()){
                    QThread::msleep(10);
                    QString cmd=QString("%1,<%2>,AT+PORT=%3%4").arg(key,localMAC,var.value("PORT"),eol);
                    if(pUdpClient->writeDatagram(cmd.toLatin1(),cmd.size(),loopBackIP,5000)){
                        qDebug().noquote()<<QString("[%1] %2:%3 udp send sucess").arg(this->metaObject()->className(),loopBackIP.toString(),QString::number(5000));
                    }
                }

                if(!var.value("MODEL","").isEmpty()){
                    QThread::msleep(10);
                    QString cmd=QString("%1,<%2>,AT+MODEL=%3%4").arg(key,localMAC,var.value("MODEL"),eol);
                    if(pUdpClient->writeDatagram(cmd.toLatin1(),cmd.size(),loopBackIP,5000)){
                        qDebug().noquote()<<QString("[%1] %2:%3 udp send sucess").arg(this->metaObject()->className(),loopBackIP.toString(),QString::number(5000));
                    }
                }

                if(!var.value("DIP","").isEmpty()){
                    QThread::msleep(10);
                    QString cmd=QString("%1,<%2>,AT+DIP=%3%4").arg(key,localMAC,var.value("DIP"),eol);
                    if(pUdpClient->writeDatagram(cmd.toLatin1(),cmd.size(),loopBackIP,5000)){
                        qDebug().noquote()<<QString("[%1] %2:%3 udp send sucess").arg(this->metaObject()->className(),loopBackIP.toString(),QString::number(5000));
                    }
                }

                if(!var.value("DPORT","").isEmpty()){
                    QThread::msleep(10);
                    QString cmd=QString("%1,<%2>,AT+DPORT=%3%4").arg(key,localMAC,var.value("DPORT"),eol);
                    if(pUdpClient->writeDatagram(cmd.toLatin1(),cmd.size(),loopBackIP,5000)){
                        qDebug().noquote()<<QString("[%1] %2:%3 udp send sucess").arg(this->metaObject()->className(),loopBackIP.toString(),QString::number(5000));
                    }
                }

                if(!var.value("WID","").isEmpty()){
                    QThread::msleep(10);
                    QString cmd=QString("%1,<%2>,AT+WID=%3%4").arg(key,localMAC,var.value("WID"),eol);
                    if(pUdpClient->writeDatagram(cmd.toLatin1(),cmd.size(),loopBackIP,5000)){
                        qDebug().noquote()<<QString("[%1] %2:%3 udp send sucess").arg(this->metaObject()->className(),loopBackIP.toString(),QString::number(5000));
                    }
                }

                if(!var.value("NAME","").isEmpty()){
                    QThread::msleep(10);
                    QString cmd=QString("%1,<%2>,AT+NAME=%3%4").arg(key,localMAC,var.value("NAME"),eol);
                    if(pUdpClient->writeDatagram(cmd.toLatin1(),cmd.size(),loopBackIP,5000)){
                        qDebug().noquote()<<QString("[%1] %2:%3 udp send sucess").arg(this->metaObject()->className(),loopBackIP.toString(),QString::number(5000));
                    }

                    QThread::msleep(10);
                    /*****************************
                    * @brief:设置网络注册包
                    ******************************/
                    cmd=QString("%1,<%2>,AT+USRREG=%3%4").arg(key,localMAC,QString("CC_ZBY"),eol);
                    if(pUdpClient->writeDatagram(cmd.toLatin1(),cmd.size(),loopBackIP,5000)){
                        qDebug().noquote()<<QString("[%1] %2:%3 udp send sucess").arg(this->metaObject()->className(),loopBackIP.toString(),QString::number(5000));
                    }

                    QThread::msleep(10);
                    cmd=QString("%1,<%2>,AT+TCPREG=%3%4").arg(key,localMAC,QString("3"),eol);
                    if(pUdpClient->writeDatagram(cmd.toLatin1(),cmd.size(),loopBackIP,5000)){
                        qDebug().noquote()<<QString("[%1] %2:%3 udp send sucess").arg(this->metaObject()->className(),loopBackIP.toString(),QString::number(5000));
                    }

                    QThread::msleep(10);
                    /*****************************
                    * @brief:设置心跳包
                    ******************************/
                    cmd=QString("%1,<%2>,AT+THEARTDT=%3%4").arg(key,localMAC,QString("[H]"),eol);
                    if(pUdpClient->writeDatagram(cmd.toLatin1(),cmd.size(),loopBackIP,5000)){
                        qDebug().noquote()<<QString("[%1] %2:%3 udp send sucess").arg(this->metaObject()->className(),loopBackIP.toString(),QString::number(5000));
                    }

                    QThread::msleep(10);
                    cmd=QString("%1,<%2>,AT+HEART=%3%4").arg(key,localMAC,QString("2,9,5,5"),eol);
                    if(pUdpClient->writeDatagram(cmd.toLatin1(),cmd.size(),loopBackIP,5000)){
                        qDebug().noquote()<<QString("[%1] %2:%3 udp send sucess").arg(this->metaObject()->className(),loopBackIP.toString(),QString::number(5000));
                    }

                    QThread::msleep(10);
                    /*****************************
                    * @brief:输出继电器主动上传
                    ******************************/
                    cmd=QString("%1,<%2>,AT+KPUPLOAD=%3%4").arg(key,localMAC,QString("1"),eol);
                    if(pUdpClient->writeDatagram(cmd.toLatin1(),cmd.size(),loopBackIP,5000)){
                        qDebug().noquote()<<QString("[%1] %2:%3 udp send sucess").arg(this->metaObject()->className(),loopBackIP.toString(),QString::number(5000));
                    }

                    QThread::msleep(10);
                    /*****************************
                    * @brief:输入继电器主动上传
                    ******************************/
                    cmd=QString("%1,<%2>,AT+OCMOD=%3%4").arg(key,localMAC,QString("2,0"),eol);
                    if(pUdpClient->writeDatagram(cmd.toLatin1(),cmd.size(),loopBackIP,5000)){
                        qDebug().noquote()<<QString("[%1] %2:%3 udp send sucess").arg(this->metaObject()->className(),loopBackIP.toString(),QString::number(5000));
                    }
                }
                var.clear();
            }            
            par.clear();
        }
    }
}

