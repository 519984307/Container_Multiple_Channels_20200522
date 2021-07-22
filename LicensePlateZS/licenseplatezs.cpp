#include "licenseplatezs.h"

#ifdef Q_OS_LINUX
    #include <arpa/inet.h>
#endif
#ifdef Q_OS_WIN
    #include <WinSock2.h>
    //#pragma comment(lib, "wsock32.lib")
#endif

LicensePlateZS::LicensePlateZS(QObject *parent)
{
    this->setParent(parent);

    isConnected=false;

    pTcpClient=nullptr;
    pTimerLinkState=nullptr;
    pTimerAutoLink=nullptr;

    recvHead=false;
}

LicensePlateZS::~LicensePlateZS()
{    
}

void LicensePlateZS::sendData(QJsonObject obj)
{
//     字节位 0、 ASCII 字符’V’，整数 86。
//     字节位 1、 ASCII 字符’Z’，整数 90.  字节位 2、 Data 数据类型
//    o 0X00 数据包。
//    o 0X01 心跳包，数据长度为 0， DATA 为空
//     字节位 3、 包序号，包序列号为递增的数值，用于对应请求命令与返回命令；例如
//    发送一个请求命令到服务器端，服务器端在返回结果时，会将请求命令中的包序列
//    号填充到返回数据包的包序列号中，便于客户端这边将返回结果与请求命令进行对
//    应。如果不存在对应问题，则设置为 0 即可。如果编号到 255，则从 0 开始重新编
//    号。
//     字节位 4 – 7、一共四位，代表接下来的数据长度。这个数据是网络字节序，在接收
//    的时候务必调用 htol 这样的函数将网络字节序转换成主机字节序。数据的长度不要
//    大于 1024 * 1024 = 1MB。服务器将不会接收超过 1MB 大小的数据，同样服务器也不
//    会发送超过 1MB 大小的数据包。理论上，除了心跳包之外，其它所有数据的长度都
//    不会是 0。
//     DATA 数据位、根据前面的包头，有不同的数据。    

    QJsonDocument json;
    json.setObject(obj);
    QByteArray data=json.toJson();

    if(pTcpClient!=nullptr){
        char head[8] = {0};
        head[0]='V';
        head[1]='Z';
        int len=htonl(data.size());
        memcpy(&head[4], &len, 4);
        
        if(pTcpClient->write(head,8)>0){
            if(pTcpClient->write(data)>0){
                //qDebug().noquote()<<QString("[%3] %1:%2 %4 send data sucess").arg(address,QString::number(port),this->metaObject()->className(),data.data());
                return;
            }
        }
    }
    qWarning().noquote()<<QString("[%3] %1:%2 %4 send data error").arg(address,QString::number(port),this->metaObject()->className(),data.data());
}

QString LicensePlateZS::InterfaceType()
{
    return  QString("ZS_PLATE");
}

void LicensePlateZS::simulationCaptureSlot()
{
    if(pTcpClient!=nullptr){
        pTcpClient->close();
        pTcpClient->abort();
        pTcpClient->connectToHost(address,port);
    }

    QJsonObject obj;
    obj.insert("cmd","trigger");

    sendData(obj);
    qDebug().noquote()<<QString("[%3] %1:%2  Snap the license plate image manually").arg(address,QString::number(port),this->metaObject()->className());
}

void LicensePlateZS::liftingElectronicRailingSlot(bool gate)
{    
    Q_UNUSED(gate);

    QJsonObject obj;
    obj.insert("cmd","ioctl_resp");
    obj.insert("delay",500);
    obj.insert("io",0);
    obj.insert("value",2);

    sendData(obj);
    qDebug().noquote()<<QString("[%3] %1:%2 Manual lifting lever").arg(address,QString::number(port),this->metaObject()->className());
}

void LicensePlateZS::transparentTransmission485Slot(const QString &msg)
{
    QJsonObject obj;
    obj.insert("cmd","ttransmission");
    obj.insert("subcmd","send");
    obj.insert("datalen",msg.size());
    obj.insert("data",msg);
    obj.insert("comm","rs485-1");

    sendData(obj);
    qDebug().noquote()<<QString("[%3] %1:%2 485 transparently transmits data").arg(address,QString::number(port),this->metaObject()->className());
}

void LicensePlateZS::openTheVideoSlot(bool play, quint64 winID)
{   
    /*****************************
    * @brief:暂时不处理视频
    ******************************/
    Q_UNUSED(play);
    Q_UNUSED(winID);

    QJsonObject obj;
    obj.insert("cmd","get_rtsp_uri");

    sendData(obj);
    qDebug().noquote()<<QString("[%3] %1:%2 Video streaming operation successful").arg(address,QString::number(port),this->metaObject()->className());
}

void LicensePlateZS::releaseResourcesSlot()
{
    if(nullptr != pTimerAutoLink){
        pTimerAutoLink->stop();
    }

    if(nullptr != pTimerLinkState){
        pTimerLinkState->stop();
    }

    if(nullptr != pTcpClient){
        pTcpClient->close();
        pTcpClient->abort();
    }

    if(nullptr != pTimerAutoLink){
        pTimerAutoLink->stop();
    }

    delete pTimerAutoLink;
    pTimerAutoLink=nullptr;

    delete pTimerLinkState;
    pTimerLinkState=nullptr;

    delete  pTcpClient;
    pTcpClient=nullptr;
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
    pTimerLinkState=new QTimer(this);
    pTimerAutoLink=new QTimer(this);
    pTimerAutoLink->setSingleShot(true);

    connect(pTcpClient,&QIODevice::readyRead,this,&LicensePlateZS::receiveDataSlot);
    connect(pTcpClient,&QAbstractSocket::connected,this,&LicensePlateZS::connectedSlot);
    connect(pTcpClient,&QAbstractSocket::disconnected,this,&LicensePlateZS::disconnectedSlot);
    connect(pTcpClient,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this,&LicensePlateZS::displayErrorSlot);

    connect(pTimerLinkState,&QTimer::timeout,this,&LicensePlateZS::heartbeatSlot);
    connect(pTimerAutoLink,&QTimer::timeout,this,&LicensePlateZS::startLinkSlot);

    startLinkSlot();
}

void LicensePlateZS::getLastPlateSlot()
{
    if(pTcpClient!=nullptr){
        pTcpClient->close();
        pTcpClient->abort();
        pTcpClient->connectToHost(address,port);
    }

    QJsonObject obj;
    obj.insert("cmd","getivsresult");
    obj.insert("image",true);
    obj.insert("format","json");

    sendData(obj);
    qDebug().noquote()<<QString("[%3] %1:%2 Get last plate result").arg(address,QString::number(port),this->metaObject()->className());
}

void LicensePlateZS::slot_pictureStream(int ID, QByteArray arrJpg)
{
    Q_UNUSED(ID);
    Q_UNUSED(arrJpg);
}

void LicensePlateZS::slot_setCameraID(int ID, QString cameraIP)
{
    Q_UNUSED(ID);
    Q_UNUSED(cameraIP);
}

void LicensePlateZS::slot_resultsTheLicensePlate(int ID, const QString &plate, const QString &color, const QString &time, const QByteArray &arrImg)
{
    Q_UNUSED(ID);
    Q_UNUSED(plate);
    Q_UNUSED(color);
    Q_UNUSED(time);
    Q_UNUSED(arrImg);
}

void LicensePlateZS::slot_equipmentState(int ID, bool state)
{
    Q_UNUSED(ID);
    Q_UNUSED(state);
}

void LicensePlateZS::startLinkSlot()
{
    if(!isConnected){
        pTcpClient->close();
        pTcpClient->abort();
        pTcpClient->connectToHost(address,port);
    }
}

void LicensePlateZS::heartbeatSlot()
{
    if(nullptr != pTcpClient && pTcpClient->isOpen()){
        char heartBeat[8]={0};
        heartBeat[0]='V';
        heartBeat[1]='Z';
        heartBeat[2]=1;
        pTcpClient->write(heartBeat);
    }
}

void LicensePlateZS::connectedSlot()
{
    isConnected=true;

    /*****************************
    * @brief:设置推送数据方式:
    ******************************/
    QJsonObject obj;
    obj.insert("cmd","ivsresult");
    obj.insert("enable",true);
    obj.insert("format","json");
    obj.insert("image",true);
    obj.insert("image_type",2);
    sendData(obj);
    
    if(!pTimerLinkState->isActive()){
        pTimerLinkState->start(5000);
    }

    pTimerAutoLink->stop();

    emit equipmentStateSignal(address,true);
    //qDebug().noquote()<<QString("[%3] %1:%2 link successful").arg(address,QString::number(port),this->objectName());
}

void LicensePlateZS::receiveDataSlot()
{
    QByteArray buff=pTcpClient->readAll();

    /*****************************
    * @brief:过滤掉配置回复
    ******************************/
    if(buff.size()<=80){
        buff.clear();
    }

    if(!recvHead && buff.size()>0 && buff.at(0)=='V' && buff.at(1)=='Z'){

        recvHead=true;
        memcpy(&recvLen,buff.mid(4,4),4);
        nRecvLen=htonl(recvLen)+8;
        qDebug()<<"nRecvLen:"<<nRecvLen;
        qDebug().noquote()<<QString("[%3] %1:%2 get data size (%4)").arg(address,QString::number(port),this->metaObject()->className(),QString::number(nRecvLen));

    }

    /*****************************
    * @brief:二进制数据模式
    ******************************/
    if(recvHead){

        if(buff.size()>0){
            recvData.append(buff);
        }

        if(recvData.size()>=nRecvLen){
            QtConcurrent::run(this,&LicensePlateZS::processPlateResultSlot,recvData.mid(8),nRecvLen);
            qDebug().noquote()<<QString("[%3] %1:%2 recv data size (%4)").arg(address,QString::number(port),this->metaObject()->className(),QString::number(nRecvLen));
            buff.clear();
            recvData.clear();
            recvLen=0;
            nRecvLen=0;
            recvHead=false;
        }
    }
}

void LicensePlateZS::disconnectedSlot()
{
    isConnected=false;

    recvData.clear();
    recvLen=0;
    nRecvLen=0;
    recvHead=false;

    //pTimerAutoLink->stop();
    //pTimerAutoLink->start(500);

    emit equipmentStateSignal(address,false);
    //qDebug().noquote()<<QString("[%3] %1:%2 disconnected").arg(address,QString::number(port),this->metaObject()->className());
}

void LicensePlateZS::displayErrorSlot(QAbstractSocket::SocketError socketError)
{
    Q_UNUSED(socketError);

    isConnected=false;

    pTimerLinkState->stop();
    if(!pTimerAutoLink->isActive()){
        pTimerAutoLink->start(1000);
    }
    //qWarning().noquote()<<QString("[%4] %1:%3 link error<errorCode=%2>").arg(address,QString::number(socketError),QString::number(port),this->metaObject()->className());
}

void LicensePlateZS::processPlateResultSlot(QByteArray data, int packetSize)
{
    int colorType=5;
    int colorValue=0;
    int imageformat=0;
    int triggerType=0;
    int fullImgSize=0;
    int clipImgSize=0;
    QString license="";

    Q_UNUSED(packetSize);
    Q_UNUSED(imageformat);
    Q_UNUSED(colorValue);
    Q_UNUSED(triggerType);

    int pos=data.indexOf("\xFF\xD8");

    QString plateResult=QTextCodec::codecForName("GB2312")->toUnicode(data.mid(0,pos));
    qDebug()<<"plateResult:"<<plateResult;

    QJsonParseError jsonError;
    QJsonDocument jsonDoc=QJsonDocument::fromJson(plateResult.toLocal8Bit().data(),&jsonError);
    /* 加载文件 */
    if(!jsonDoc.isNull()&&jsonError.error==QJsonParseError::NoError){
        /* 读取根目录 */
        if(jsonDoc.isObject()){
            QJsonObject obj=jsonDoc.object();
            if(obj.contains("PlateResult")){
                QJsonValue value=obj.value("PlateResult");
                /* 读取子目录 */
                if(value.isObject()){
                    if(obj.contains("colorType")){
                        QJsonValue jsonValue=obj.value("colorType");
                        colorType=jsonValue.toInt();
                    }
                    if(obj.contains("colorValue")){
                        QJsonValue jsonValue=obj.value("colorValue");
                        colorValue=jsonValue.toInt();
                    }
//                    if(obj.contains("license")){
//                        QJsonValue jsonValue=obj.value("license");
//                        license=QString::fromLocal8Bit(jsonValue.toString().toLocal8Bit().data());
//                        qDebug()<<"license:"<<license;
//                    }
                    if(obj.contains("imageformat")){
                        QJsonValue jsonValue=obj.value("imageformat");
                        imageformat=jsonValue.toInt();
                    }
                    if(obj.contains("triggerType")){
                        QJsonValue jsonValue=obj.value("triggerType");
                        triggerType=jsonValue.toInt();
                    }
                    if(obj.contains("fullImgSize")){
                        QJsonValue jsonValue=obj.value("fullImgSize");
                        fullImgSize=jsonValue.toInt();
                    }
                    if(obj.contains("clipImgSize")){
                        QJsonValue jsonValue=obj.value("clipImgSize");
                        clipImgSize=jsonValue.toInt();
                    }
                    if(obj.contains("timeString")){
                        QJsonValue jsonValue=obj.value("timeString");
                        qDebug()<<"timeString:"<<jsonValue.toString();
                    }
                }
            }
        }
    }
    else {
        qDebug()<<"get json error:"<<jsonError.errorString();
        return;
    }

    QByteArray fullImg;
    QByteArray clipImg;

    if(pos>=0){
        fullImg=data.mid(pos,fullImgSize);
        clipImg=data.mid(pos+fullImgSize,clipImgSize);
    }

    int std= plateResult.indexOf("colorType");
    int end= plateResult.indexOf(',',std);
    colorType=plateResult.mid(std+11,end-std-11).toInt();

    QString plateColor="";
    switch (colorType) {
    case 0:
        plateColor="未知";
        break;
    case 1:
        plateColor="蓝";
        break;
    case 2:
        plateColor="黄";
        break;
    case 3:
        plateColor="白";
        break;
    case 4:
        plateColor="黑";
        break;
    case 5:
        plateColor="绿";
        break;
    }

    std= plateResult.indexOf("license");
    end= plateResult.indexOf(',',std);
    license=plateResult.mid(std+10,end-std-11);

    if(license.isEmpty()){
        license="无车牌";
    }

    QString dateTime=QDateTime::currentDateTime().toString("yyyy-M-d h:m:s");
    qDebug().noquote()<<QString("[%3] %4:%5 License Plate recognition results:%1-%2").arg(license,dateTime,this->metaObject()->className(),address,QString::number(port));

    emit resultsTheLicensePlateSignal(license,plateColor,dateTime,fullImg);

    fullImg.clear();
    clipImg.clear();
}
