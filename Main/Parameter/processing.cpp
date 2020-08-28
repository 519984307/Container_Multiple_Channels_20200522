#include "processing.h"

Processing::Processing(QObject *parent) : QObject(parent)
{
    p_LogController=new LogController (parent);
}

Processing::~Processing()
{
    qDeleteAll(ParmeterList);
    ParmeterList.clear();

    delete p_LogController;
    p_LogController=nullptr;
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

                        configurationFolder.close();
                        p_ChannelParameter=nullptr;
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
