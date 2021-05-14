#include "licenseplatehcnet.h"

LicensePlateHCNET::LicensePlateHCNET(QObject *parent)
{
    this->setParent(parent);

    signature="";
    imgNumber=-1;
    camerID=-1;
    put=false;
//    imgGetTimeOut=nullptr;
}

LicensePlateHCNET::~LicensePlateHCNET()
{
}

QString LicensePlateHCNET::InterfaceType()
{
    return QString("HCNET_PLATE");
}

bool LicensePlateHCNET::initializationParameter()
{
//    imgGetTimeOut=new QTimer(this);
//    imgGetTimeOut->setSingleShot(true);
//    connect(imgGetTimeOut,SIGNAL(timeout()),this,SLOT(slot_imgGetTimeOut()));
    return false;
}

void LicensePlateHCNET::slot_imgGetTimeOut()
{
    put=false;
    emit imageFlowSignal(nullptr);
}

void LicensePlateHCNET::simulationCaptureSlot()
{
    if(this->signature.isEmpty() || this->signature==signature){
        if(camerID==-1){
            emit imageFlowSignal(nullptr);
            qWarning().noquote()<<QString("IP=%1[%2]:%3").arg(camerIP).arg(signature).arg("Camera not logged in, return null");

            return;
        }
        else {
            emit signal_simulationCapture(camerID);
        }

        qDebug().noquote()<<QString("IP=%1[%2]:%3").arg(camerIP).arg(signature).arg("Capture the image");
        put=true;
    }
}

void LicensePlateHCNET::liftingElectronicRailingSlot(bool gate)
{
    Q_UNUSED(gate);
}

void LicensePlateHCNET::transparentTransmission485Slot(const QString &msg)
{
    Q_UNUSED(msg);
}

void LicensePlateHCNET::openTheVideoSlot(bool play,quint64 winID)
{
    if(this->signature.isEmpty() || this->signature==signature){
        emit signal_openTheVideo(camerID,play,winID);
        qDebug().noquote()<<QString("IP=%1[%2]:%3").arg(camerIP).arg(signature).arg("The camera preview");
    }
}

void LicensePlateHCNET::releaseResourcesSlot()
{
//    if(imgGetTimeOut!=nullptr){
//        imgGetTimeOut->stop();
//    }

    qDebug().noquote()<<QString("LicensePlateHCNET::releaseResourcesSlot");
}

void LicensePlateHCNET::initCamerSlot(const QString &localAddr,const QString &camerIP,const int &camerPort,const QString &CamerUser,const QString &CamerPow,const QString &signature)
{
    this->signature=signature;
    this->camerIP=camerIP;

    if(camerIP.isEmpty() || camerIP=="..."){
        return;
    }
    emit signal_initCamera(localAddr,camerIP,camerPort,CamerUser,CamerPow);
}

void LicensePlateHCNET::getDeviceStatusSlot()
{

}

void LicensePlateHCNET::slot_pictureStream(int ID, QByteArray arrJpg)
{
    if(put && ID==camerID){
        emit imageFlowSignal(arrJpg);
        qDebug().noquote()<<QString("IP=%1[%2] Put Command Sucess").arg(camerIP).arg(signature);

        put=false;
        //imgGetTimeOut->stop();

        if(nullptr==arrJpg){
            qWarning().noquote()<<QString("IP=%1[%2]:%3").arg(camerIP).arg(signature).arg("Capture image data is empty");
        }
    }
}

void LicensePlateHCNET::slot_setCameraID(int ID, QString cameraIP)
{
    if(camerIP==cameraIP && -1==camerID){
        camerID=ID;
        qDebug()<<QString("IP=%1[%2] Set the ID[%3]").arg(cameraIP).arg(signature).arg(ID);
    }
}

void LicensePlateHCNET::slot_resultsTheLicensePlate(int ID, const QString &plate, const QString &color, const QString &time,const QByteArray &arrImg)
{
    if(camerID==ID){
        emit resultsTheLicensePlateSignal(plate,color,time,arrImg);
        qDebug().noquote()<<QString("IP=[%1]: License Plate recognition results:%2 %3").arg(camerIP).arg(plate).arg(time);
    }
}

void LicensePlateHCNET::slot_equipmentState(int ID, bool state)
{
    if(camerID==ID){
        emit equipmentStateSignal(camerIP,state);
        if(!state){
            camerID=-1;
        }
    }
}
