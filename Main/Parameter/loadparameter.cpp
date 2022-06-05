#include "loadparameter.h"
#include "LocalPar.h"

LoadParameter::LoadParameter(QObject *parent) : QObject(parent)
{
}

LoadParameter::~LoadParameter()
{
    ParmeterMap.clear();
}

bool LoadParameter::loadSysParameter()
{
    QDir mkPath(QCoreApplication::applicationDirPath());
    mkPath.mkdir("Json");
    mkPath.cd("Json");

    QString fileRoot=QDir::toNativeSeparators(QString("%1/System.json").arg(mkPath.path()));

    QFile configurationFolder(fileRoot);
    if(!configurationFolder.open(QIODevice::ReadOnly)){
        qWarning()<<QString("Failed to load the System parameter, create the default parameter error<errorCode=%1>").arg(errCode(configurationFolder.OpenError));
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

                    if(0==Parameter::ChannelNumber){
                        /*****************************
                        * @brief:防止二次加载，覆盖临时数据
                        ******************************/
                        Parameter::ChannelNumber= getJsonValue("Channel","ChannelNumber",value.toObject()).toInt();
                        if(Parameter::ChannelNumber>LocalPar::Channels){
                            Parameter::ChannelNumber=LocalPar::Channels;
                        }
                    }

                    Parameter::ImageFormat= getJsonValue("Channel","ImageFormat",value.toObject()).toInt();
                    Parameter::ImageNamingRules= getJsonValue("Channel","ImageNamingRules",value.toObject()).toInt();
                    Parameter::ImagePath= getJsonValue("Channel","ImagePath",value.toObject()).toString();
                    Parameter::camera_id_placeholder=getJsonValue("Channel","camera_id_placeholder",value.toObject()).toInt();
                    Parameter::channel_id_placeholder=getJsonValue("Channel","channel_id_placeholder",value.toObject()).toInt();

                    /*****************************
                    * @brief:Model
                    ******************************/
                    Parameter::Camera_Load_Plugin=getJsonValue("Model","Camera_Load_Plugin",value.toObject()).toInt();
                    Parameter::HCNET_Capture_Type=getJsonValue("Model","HCNET_Capture_Type",value.toObject()).toInt();
                    Parameter::LogicType=getJsonValue("Model","LogicType",value.toObject()).toInt();
                    Parameter::PlateType=getJsonValue("Model","PlateType",value.toObject()).toInt();
                    Parameter::interfaceModel=getJsonValue("Model","interfaceModel",value.toObject()).toInt();
                    Parameter::loadLibrary_HK=getJsonValue("Model","loadLibrary_HK",value.toObject()).toInt();
                    Parameter::Display_mode=getJsonValue("Model","Display_mode",value.toObject()).toInt();


                    /*****************************
                    * @brief:Upload
                    ******************************/
                    Parameter::Ftp=getJsonValue("Upload","Ftp",value.toObject()).toInt();
                    Parameter::FtpAddress= getJsonValue("Upload","FtpAddress",value.toObject()).toString();
                    Parameter::FtpTimeDIC= getJsonValue("Upload","FtpTimeDIC",value.toObject()).toInt();
                    Parameter::FtpPassword= getJsonValue("Upload","FtpPassword",value.toObject()).toString();
                    Parameter::FtpPort= getJsonValue("Upload","FtpPort",value.toObject()).toInt();
                    Parameter::FtpRemotePath= getJsonValue("Upload","FtpRemotePath",value.toObject()).toString();
                    Parameter::FtpUser= getJsonValue("Upload","FtpUser",value.toObject()).toString();
                    Parameter::ReduceImage=getJsonValue("Upload","ReduceImage",value.toObject()).toInt();
                    Parameter::upload_images=getJsonValue("Upload","upload_images",value.toObject()).toString();

                    /*****************************
                    * @brief:Other
                    ******************************/
                    Parameter::Language= getJsonValue("Other","Language",value.toObject()).toInt();
                    Parameter::Minimization= getJsonValue("Other","Minimization",value.toObject()).toInt();
                    Parameter::FullScreen= getJsonValue("Other","FullScreen",value.toObject()).toInt();
                    Parameter::Automatic= getJsonValue("Other","Automatic",value.toObject()).toInt();
                    Parameter::DelayStart= getJsonValue("Other","DelayStart",value.toObject()).toInt();
                    Parameter::InfoLog= getJsonValue("Other","InfoLog",value.toObject()).toInt();
                    Parameter::DebugLog= getJsonValue("Other","DebugLog",value.toObject()).toInt();

                    /*****************************
                    * @brief:Recognizer
                    ******************************/
                    Parameter::ResultsTheCheck=getJsonValue("Recognizer","ResultsTheCheck",value.toObject()).toInt();
                    Parameter::picture_size=getJsonValue("Recognizer","picture_size",value.toObject()).toInt();


                    /*****************************
                    * @brief:Service
                    ******************************/
                    Parameter::Service_Model=getJsonValue("Service","Service_Model",value.toObject()).toInt();
                    Parameter::Service_Type=getJsonValue("Service","Service_Type",value.toObject()).toInt();
                    Parameter::SingletonAddress=getJsonValue("Service","SingletonAddress",value.toObject()).toString();
                    Parameter::ManyCasesAddress=getJsonValue("Service","ManyCasesAddress",value.toObject()).toString();
                    Parameter::Heartbeat=getJsonValue("Service","Heartbeat",value.toObject()).toInt();
                    Parameter::Resultting=getJsonValue("Service","Resultting",value.toObject()).toInt();
                    Parameter::ShortLink=getJsonValue("Service","ShortLink",value.toObject()).toInt();
                    Parameter::Identify_Protocol=getJsonValue("Service","Identify_Protocol",value.toObject()).toInt();
                    Parameter::newline=getJsonValue("Service","newline",value.toObject()).toInt();
                    Parameter::DataChaneType=getJsonValue("Service","DataChaneType",value.toObject()).toInt();
                    Parameter::SingletonAddressMQ=getJsonValue("Service","SingletonAddressMQ",value.toObject()).toString();
                    Parameter::ManyCasesAddressMQ=getJsonValue("Service","ManyCasesAddressMQ",value.toObject()).toString();
                    Parameter::DataChange_Format=getJsonValue("Service","DataChange_Format",value.toObject()).toInt();
                    Parameter::plate_timeout=getJsonValue("Service","plate_timeout",value.toObject()).toInt();
                    Parameter::container_timeout=getJsonValue("Service","container_timeout",value.toObject()).toInt();
                    Parameter::not_plate_color=getJsonValue("Service","not_plate_color",value.toObject()).toInt();
                    Parameter::same_plate_out=getJsonValue("Service","same_plate_out",value.toObject()).toInt();
                    Parameter::false_plate=getJsonValue("Service","false_plate",value.toObject()).toString();
                    Parameter::dont_false_plate=getJsonValue("Service","dont_false_plate",value.toObject()).toInt();
                    Parameter::bluePlate=getJsonValue("Service","bluePlate",value.toObject()).toInt();
                    Parameter::Interface_Model=getJsonValue("Service","Interface_Model",value.toObject()).toInt();


                    configurationFolder.close();
                    return true;
                }
            }
        }
    }
    else {
        configurationFolder.remove();
        QByteArray msg=QString("Load System.json error<errorCode=%1>").arg(jsonError.errorString()).toLocal8Bit();
        qWarning("%s", msg.data());
    }

    configurationFolder.close();

    return false;
}

void LoadParameter::loadChannelParameter(int Channels)
{
    QDir mkPath(QCoreApplication::applicationDirPath());
    mkPath.mkdir("Json");
    mkPath.cd("Json");

    int CS=Channels;
    if(Channels>LocalPar::Channels){
        CS=LocalPar::Channels;
    }
    for(int ind=1;ind<=CS;++ind){
        QString fileRoot=QDir::toNativeSeparators(QString("%1/Channel_%2.json").arg(mkPath.path()).arg(ind));

        QFile configurationFolder(fileRoot);
        if(!configurationFolder.open(QIODevice::ReadOnly)){
            QByteArray msg=QString("Failed to load the Channel_%1 parameter, create the default parameter error<errorCode=%2>").arg(ind).arg(errCode(configurationFolder.OpenError)).toLocal8Bit();
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

                        QSharedPointer<ChannelParameter> p_ChannelParameter(new ChannelParameter ());
                        //ArrayPointer[ind-1]=*p_ChannelParameter;
                        ParmeterMap.insert(ind,p_ChannelParameter);

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
                        p_ChannelParameter->ForgroundCamer= getJsonValue("Camer","ForgroundCamer",value.toObject()).toString();
                        p_ChannelParameter->ProspectsCamer= getJsonValue("Camer","ProspectsCamer",value.toObject()).toString();
                        p_ChannelParameter->LocalAddr = getJsonValue("Camer","LocalAddr",value.toObject()).toString();

                        /*****************************
                        * @brief:other
                        ******************************/
                        p_ChannelParameter->Alias= getJsonValue("Other","Alias",value.toObject()).toString();
                        p_ChannelParameter->Channel_number=getJsonValue("Other","Channel_Number",value.toObject()).toInt();
                        p_ChannelParameter->Plate_Camera_Model=getJsonValue("Other","Plate_Camera_Model",value.toObject()).toInt();
                        p_ChannelParameter->Container_Camera_Model=getJsonValue("Other","Container_Camera_Model",value.toObject()).toInt();                                                
                        p_ChannelParameter->Camera_Load_Plugin=getJsonValue("Other","Camera_Load_Plugin",value.toObject()).toInt();
                        p_ChannelParameter->HCNET_Capture_Type=getJsonValue("Other","HCNET_Capture_Type",value.toObject()).toInt();
                        p_ChannelParameter->A1ReleasrCap=getJsonValue("Other","A1ReleasrCap",value.toObject()).toDouble();
                        p_ChannelParameter->PlatePageState=getJsonValue("Other","PlatePageState",value.toObject()).toBool();
                        p_ChannelParameter->ProspectsPageState=getJsonValue("Other","ProspectsPageState",value.toObject()).toBool();
                        p_ChannelParameter->ForegroundPageState=getJsonValue("Other","ForegroundPageState",value.toObject()).toBool();
                        p_ChannelParameter->TopPageState=getJsonValue("Other","TopPageState",value.toObject()).toBool();
                        p_ChannelParameter->Display_address= getJsonValue("Other","Display_address",value.toObject()).toString();
                        p_ChannelParameter->Display_permanent= getJsonValue("Other","Display_permanent",value.toObject()).toString();
                        p_ChannelParameter->Display_temp_prefix= getJsonValue("Other","Display_temp_prefix",value.toObject()).toString();
                        p_ChannelParameter->Display_temp_suffix= getJsonValue("Other","Display_temp_suffix",value.toObject()).toString();


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
                        p_ChannelParameter->controllerAddr= getJsonValue("SerialPort","controllerAddr",value.toObject()).toString();
                        p_ChannelParameter->controllerPort= getJsonValue("SerialPort","controllerPort",value.toObject()).toInt();
                        p_ChannelParameter->D1out= getJsonValue("SerialPort","D1out",value.toObject()).toInt();
                        p_ChannelParameter->D2out= getJsonValue("SerialPort","D2out",value.toObject()).toInt();
                        p_ChannelParameter->D3out= getJsonValue("SerialPort","D3out",value.toObject()).toInt();
                        p_ChannelParameter->D4out= getJsonValue("SerialPort","D4out",value.toObject()).toInt();
                        p_ChannelParameter->interfaceModel= getJsonValue("SerialPort","interfaceModel",value.toObject()).toInt();
                        p_ChannelParameter->lifthingType= getJsonValue("SerialPort","lifthingType",value.toObject()).toInt();

                        p_ChannelParameter=nullptr;
                        configurationFolder.close();
                        }
                    }
                }
            }
        else {
            configurationFolder.remove();
            QByteArray msg=QString("load Channel_%2.json error<errorCode=%1>").arg(jsonError.errorString()).arg(ind).toLocal8Bit();
            qWarning("%s",msg.data());
            continue;
        }

        configurationFolder.close();
    }
}

QVariant LoadParameter::getJsonValue(const QString &child, const QString &key, QJsonObject obj)
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
                else if (jsonValue.isBool()) {
                    return jsonValue.toBool();
                }
                else if (jsonValue.isDouble()) {
                    return jsonValue.toDouble();
                }
                else {
                    return jsonValue.toInt();
                }
            }
        }
    }
    return  QString("");
}

QString LoadParameter::errCode(int code)
{
    QString err;
    switch (code) {
    case 1:
        err="An error occurred when reading from the file.";
        break;
    case 2:
        err="An error occurred when writing to the file.";
        break;
    case 3:
        err="A fatal error occurred.";
        break;
    case 4:
        err="Out of resources (e.g., too many open files, out of memory, etc.)";
        break;
    case 5:
        err="The file could not be opened.";
        break;
    case 6:
        err="The operation was aborted.";
        break;
    case 7:
        err="A timeout occurred.";
        break;
    case 8:
        err="An unspecified error occurred.";
        break;
    case 9:
        err="The file could not be removed.";
        break;
    case 10:
        err="The file could not be renamed.";
        break;
    case 11:
        err="The position in the file could not be changed.";
        break;
    case 12:
        err="The file could not be resized.";
        break;
    case 13:
        err="The file could not be accessed.";
        break;
    case 14:
        err="The file could not be copied.";
        break;
    default:
        err="An unknown error";
    }
    return err;
}
