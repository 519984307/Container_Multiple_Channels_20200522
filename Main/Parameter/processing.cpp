#include "processing.h"

Processing::Processing(QObject *parent) : QObject(parent)
{
    p_LogController=new LogController ();
}

Processing::~Processing()
{
    qDeleteAll(ParmeterList);
    ParmeterList.clear();

    delete p_LogController;
    p_LogController=nullptr;
}

bool Processing::loadParameter()
{
    QDir mkPath(QCoreApplication::applicationDirPath());
    mkPath.mkdir("Json");
    mkPath.cd("Json");

    QString fileRoot=QDir::toNativeSeparators(QString("%1/System.json").arg(mkPath.path()));

    QFile configurationFolder(fileRoot);
    if(!configurationFolder.open(QIODevice::ReadOnly)){
        qWarning()<<tr("Failed to load the System parameter, create the default parameter error<errorCOde=%1>").arg(configurationFolder.OpenError);
        return false;
    }

    QByteArray arr=configurationFolder.readAll();
    QJsonParseError jsonError;
    QJsonDocument jsonDoc=QJsonDocument::fromJson(arr,&jsonError);

    /* 加载文件 */
    if(!jsonDoc.isNull()&&jsonError.error==QJsonParseError::NoError){
        /* 读取根目录 */
        if(jsonDoc.isObject()){
            QJsonObject obj=jsonDoc.object();
            if(obj.contains("Main")){
                QJsonValue value=obj.value("Main");

                /* 读取子目录 */
                if(value.isObject()){

                    /*****************************
                    * @brief:Channel
                    ******************************/

                    Parameter::ChannelNumber= getJsonValue("Channel","ChannelNumber",value.toObject()).toInt();
                    Parameter::ImageFormat= getJsonValue("Channel","ImageFormat",value.toObject()).toInt();
                    Parameter::ImageNamingRules= getJsonValue("Channel","ImageNamingRules",value.toObject()).toInt();
                    Parameter::ImagePath= getJsonValue("Channel","ImagePath",value.toObject()).toString();

                    /*****************************
                    * @brief:Upload
                    ******************************/
                    Parameter::Ftp=getJsonValue("Upload","Ftp",value.toObject()).toInt();
                    Parameter::FtpAddress= getJsonValue("Upload","FtpAddress",value.toObject()).toString();
                    Parameter::FtpLocalPath= getJsonValue("Upload","FtpLocalPath",value.toObject()).toString();
                    Parameter::FtpPassword= getJsonValue("Upload","FtpPassword",value.toObject()).toString();
                    Parameter::FtpPort= getJsonValue("Upload","FtpPort",value.toObject()).toInt();
                    Parameter::FtpRemotePath= getJsonValue("Upload","FtpRemotePath",value.toObject()).toString();
                    Parameter::FtpUser= getJsonValue("Upload","FtpUser",value.toObject()).toString();
                    Parameter::ReduceImage=getJsonValue("Upload","ReduceImage",value.toObject()).toInt();

                    /*****************************
                    * @brief:Other
                    ******************************/
                    Parameter::Language= getJsonValue("Other","Language",value.toObject()).toInt();
                    Parameter::Minimization= getJsonValue("Other","Minimization",value.toObject()).toInt();
                    Parameter::Automatic=getJsonValue("Other","Automatic",value.toObject()).toInt();
                    Parameter::InfoLog= getJsonValue("Other","InfoLog",value.toObject()).toInt();
                    Parameter::DebugLog= getJsonValue("Other","DebugLog",value.toObject()).toInt();

                    /*****************************
                    * @brief:Recognizer
                    ******************************/
                    Parameter::ResultsTheCheck=getJsonValue("Recognizer","ResultsTheCheck",value.toObject()).toInt();

                    /*****************************
                    * @brief:Service
                    ******************************/
                    Parameter::ServiceModel=getJsonValue("Service","ServiceModel",value.toObject()).toInt();
                    Parameter::Service_Type=getJsonValue("Service","Service_Type",value.toObject()).toInt();
                    Parameter::SingletonAddress=getJsonValue("Service","SingletonAddress",value.toObject()).toString();
                    Parameter::ManyCasesAddress=getJsonValue("Service","ManyCasesAddress",value.toObject()).toString();
                    Parameter::Heartbeat=getJsonValue("Service","Heartbeat",value.toObject()).toInt();
                    Parameter::Resultting=getJsonValue("Service","Resultting",value.toObject()).toInt();

                    configurationFolder.close();
                    return true;
                }
            }
        }
    }
    else {
        configurationFolder.remove();
        QByteArray msg=tr("Load System.json error<errorCode=%1>").arg(jsonError.errorString()).toLocal8Bit();
        qWarning("%s", msg.data());
    }

    configurationFolder.close();

    return false;
}

void Processing::loadChannelParameter(int Channels)
{
    QDir mkPath(QCoreApplication::applicationDirPath());
    mkPath.mkdir("Json");
    mkPath.cd("Json");

    for(int ind=1;ind<=Channels;++ind){
        QString fileRoot=QDir::toNativeSeparators(QString("%1/Channel_%2.json").arg(mkPath.path()).arg(ind));

        QFile configurationFolder(fileRoot);
        if(!configurationFolder.open(QIODevice::ReadOnly)){
            QByteArray msg=tr("Failed to load the Channel_%1 parameter, create the default parameter error<errorCOde=%2>").arg(ind).arg(configurationFolder.OpenError).toLocal8Bit();
            qWarning("%s", msg.data());
            continue;
        }

        QByteArray arr=configurationFolder.readAll();
        QJsonParseError jsonError;
        QJsonDocument jsonDoc=QJsonDocument::fromJson(arr,&jsonError);

        /* 加载文件 */
        if(!jsonDoc.isNull()&&jsonError.error==QJsonParseError::NoError){
            /* 读取根目录 */
            if(jsonDoc.isObject()){
                QJsonObject obj=jsonDoc.object();
                if(obj.contains(QString("Channel"))){
                    QJsonValue value=obj.value(QString("Channel"));

                    /* 读取子目录 */
                    if(value.isObject()){

                        ChannelParameter *p_ChannelParameter=new ChannelParameter ();
                        //ArrayPointer[ind-1]=*p_ChannelParameter;
                        ParmeterList.append(p_ChannelParameter);

                        /*****************************
                        * @brief:camera
                        ******************************/
                        p_ChannelParameter->AfterCamer= getJsonValue("Camer","AfterCamer",value.toObject()).toString();
                        p_ChannelParameter->FrontCamer= getJsonValue("Camer","FrontCamer",value.toObject()).toString();
                        p_ChannelParameter->LeftCamer= getJsonValue("Camer","LeftCamer",value.toObject()).toString();
                        p_ChannelParameter->RgihtCamer= getJsonValue("Camer","RgihtCamer",value.toObject()).toString();
                        p_ChannelParameter->TopCamer= getJsonValue("Camer","TopCamer",value.toObject()).toString();
                        p_ChannelParameter->PlateCamer= getJsonValue("Camer","PlateCamer",value.toObject()).toString();
                        p_ChannelParameter->UserCamer= getJsonValue("Camer","UserCamer",value.toObject()).toString();
                        p_ChannelParameter->PasswordCamer= getJsonValue("Camer","PasswordCamer",value.toObject()).toString();

                        /*****************************
                        * @brief:other
                        ******************************/
                        p_ChannelParameter->Alias= getJsonValue("Other","Alias",value.toObject()).toString();
                        p_ChannelParameter->Channel_number=getJsonValue("Other","Channel_Number",value.toObject()).toInt();
                        p_ChannelParameter->Plate_Camera_Model=getJsonValue("Other","Plate_Camera_Model",value.toObject()).toInt();
                        p_ChannelParameter->Container_Camera_Model=getJsonValue("Other","Container_Camera_Model",value.toObject()).toInt();


                        /*****************************
                        * @brief:SerialPort
                        ******************************/
                        p_ChannelParameter->PortOne= getJsonValue("SerialPort","PortOne",value.toObject()).toInt();
                        p_ChannelParameter->PortTow= getJsonValue("SerialPort","PortTow",value.toObject()).toInt();
                        p_ChannelParameter->SerialAddrOne= getJsonValue("SerialPort","SerialAddrOne",value.toObject()).toString();
                        p_ChannelParameter->SerialAddrTow= getJsonValue("SerialPort","SerialAddrTow",value.toObject()).toString();
                        p_ChannelParameter->infraredStatus=getJsonValue("SerialPort","infraredStatus",value.toObject()).toInt();
                        p_ChannelParameter->ControllerSignalMode= getJsonValue("SerialPort","ControllerSignalMode",value.toObject()).toInt();
                        p_ChannelParameter->SerialPortTow= getJsonValue("SerialPort","SerialPortTow",value.toObject()).toInt();
                        p_ChannelParameter->SerialPortOne= getJsonValue("SerialPort","SerialPortOne",value.toObject()).toInt();

                        p_ChannelParameter=nullptr;
                        configurationFolder.close();
                        }
                    }
                }
            }
        else {
            configurationFolder.remove();
            QByteArray msg=tr("load Channel_%2.json error<errorCode=%1>").arg(jsonError.errorString()).arg(ind).toLocal8Bit();
            qWarning("%s",msg.data());
            continue;
        }

        configurationFolder.close();
    }
}

QVariant Processing::getJsonValue(const QString &child, const QString &key, QJsonObject obj)
{
    if(obj.contains(child)){
        QJsonValue jsonValue=obj.value(child);
        /* 读取配置子项 */
        if(jsonValue.isObject()){
            obj=jsonValue.toObject();
            /* 读取配置值 */
            if(obj.contains(key)){
                jsonValue=obj.value(key);
                if(jsonValue.isString()){
                    return jsonValue.toString();
                }
                else {
                    return jsonValue.toInt();
                }
            }
        }
    }
    return  QString("");
}
