#include "captureimages.h"
#include <QDebug>

CaptureImages::CaptureImages(QObject *parent)
{
    this->setParent(parent);

    imgNumber=-1;
    camerID=-1;
    put=false;
    imgGetTimeOut=new QTimer(this);
    imgGetTimeOut->setSingleShot(true);
    connect(imgGetTimeOut,SIGNAL(timeout()),this,SLOT(slot_imgGetTimeOut()));
}

CaptureImages::~CaptureImages()
{
    qDebug()<<"~CaptureImages";
}

bool CaptureImages::InitializationSlot()
{
    return false;
}

void CaptureImages::initCamerSlot(const QString &camerIP, const int &camerPort,const QString &CamerUser,const QString &CamerPow)
{
    if(camerIP.isEmpty() || camerIP=="..."){
        return;
    }
    qDebug()<<camerIP;
    this->camerIP=camerIP;
    emit signal_initCamera("",camerIP,camerPort,CamerUser,CamerPow);
}

void CaptureImages::getDeviceStatusSlot()
{   
}

void CaptureImages::slot_imgGetTimeOut()
{
    put=false;
    emit pictureStreamSignal(nullptr,imgNumber,imgTime);
}

bool CaptureImages::putCommandSlot( int imgNumber, QString imgTime)
{
    if(camerID==-1){
        emit pictureStreamSignal(nullptr,imgNumber,imgTime);
        return false;
    }
    if(imgGetTimeOut->isActive()){
        emit pictureStreamSignal(nullptr,this->imgNumber,this->imgTime);
        imgGetTimeOut->stop();
    }
    put=true;
    this->imgNumber=imgNumber;
    this->imgTime=imgTime;
    emit signal_simulationCapture(camerID);
    imgGetTimeOut->start(3000);

    return true;
}

void CaptureImages::playStreamSlot(quint64 winID,bool play)
{
    emit signal_openTheVideo(camerID,play,winID);
}

void CaptureImages::liftingElectronicRailingSlot(bool gate)
{
    Q_UNUSED(gate);
}

void CaptureImages::transparentTransmission485Slot(const QString &msg)
{
    Q_UNUSED(msg);
}

void CaptureImages::resizeEventSlot()
{
}

void CaptureImages::releaseResourcesSlot()
{
    imgGetTimeOut->stop();
}

void CaptureImages::slot_pictureStream(int ID, QByteArray arrJpg)
{
    if(put && ID==camerID){
        emit pictureStreamSignal(arrJpg,imgNumber,imgTime);
        //emit messageSignal(ZBY_LOG("INFO"), tr("IP=%1 Put Command Sucess").arg(camerIP));
        qDebug()<<tr("IP=%1 Put Command Sucess").arg(camerIP);
        put=false;
    }
}

void CaptureImages::slot_setCameraID(int ID, QString cameraIP)
{
    if(camerIP==cameraIP && -1==camerID){
        camerID=ID;
        emit messageSignal(ZBY_LOG("INFO"), tr("IP=%1 Set the ID[%2]").arg(cameraIP).arg(ID));
        qDebug()<<tr("IP=%1 Set the ID[%2]").arg(cameraIP).arg(ID);
    }
}

void CaptureImages::slot_resultsTheLicensePlate(int ID, const QString &plate, const QString &color, const QString &time, QByteArray arrImg)
{
    Q_UNUSED(ID);
    Q_UNUSED(plate);
    Q_UNUSED(color);
    Q_UNUSED(time);
    Q_UNUSED(arrImg);

    /*****************************
    * @brief:集装箱不接受车牌信息
    ******************************/
//    if(camerID==ID){
//        saveImg(arrImg,time);
//        emit resultsTheLicensePlateSignal(plate,color,time,arrImg);
//        emit messageSignal(ZBY_LOG("INFO"),tr("License Plate recognition results:%1 %2").arg(plate).arg(time));
//    }
}

void CaptureImages::slot_equipmentState(int ID, bool state)
{
    if(camerID==ID){
        emit camerStateSingal(camerIP,state);
    }
}
