#include "channel_setting_form.h"
#include "ui_channel_setting_form.h"

Channel_Setting_Form::Channel_Setting_Form(int number, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Channel_Setting_Form)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose,true);

    this->setParent(parent);
    this->setHidden(true);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    /*****************************
    * @brief: 初始化参数
    ******************************/
    InitializationParameter(number);
}

Channel_Setting_Form::~Channel_Setting_Form()
{
    delete ui;
}

void Channel_Setting_Form::InitializationParameter(int number)
{
    this->channel_number=number;

    ui->serial_stackedWidget->setCurrentIndex(0);
    ui->D1out_comboBox->setCurrentIndex(0);
    ui->D2out_comboBox->setCurrentIndex(0);
    ui->D3out_comboBox->setCurrentIndex(0);
    ui->D4out_comboBox->setCurrentIndex(0);

    p_ChannelParameter=QSharedPointer<ChannelParameter>(new ChannelParameter());

    /*****************************
    * @brief:创建配置文件夹
    ******************************/
    QDir mkPath(QCoreApplication::applicationDirPath());
    mkPath.mkdir("Json");
    mkPath.cd("Json");

    fileRoot=QDir::toNativeSeparators(QString("%1/Channel_%2.json").arg(mkPath.path()).arg(this->channel_number));

    /* 加载配置 */
    if(!loadParameter()){
        if(writeParameterSlot()){
            loadParameter();
            parameterToUi();
        }
    }
    else {/* 外部更改配置,回写配置到UI */
        parameterToUi();
    }
}

bool Channel_Setting_Form::loadParameter()
{
    configurationFolder.setFileName(fileRoot);
    if(!configurationFolder.open(QIODevice::ReadOnly)){
        qWarning().noquote()<<QString("Failed to load the Channel_%1 parameter, create the default parameter error<errorCode=%2>").arg(channel_number).arg(configurationFolder.OpenError);
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
            if(obj.contains(QString("Channel"))){
                QJsonValue value=obj.value(QString("Channel"));

                /* 读取子目录 */
                if(value.isObject()){

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
                    p_ChannelParameter->LocalAddr= getJsonValue("Camer","LocalAddr",value.toObject()).toString();

                    /*****************************
                    * @brief:other
                    ******************************/
                    p_ChannelParameter->Alias= getJsonValue("Other","Alias",value.toObject()).toString();
                    p_ChannelParameter->Channel_number=getJsonValue("Other","Channel_Number",value.toObject()).toInt();
                    p_ChannelParameter->A1ReleasrCap=getJsonValue("Other","A1ReleasrCap",value.toObject()).toDouble();
                    p_ChannelParameter->PlatePageState=getJsonValue("Other","PlatePageState",value.toObject()).toBool();
                    p_ChannelParameter->ProspectsPageState=getJsonValue("Other","ProspectsPageState",value.toObject()).toBool();
                    p_ChannelParameter->ForegroundPageState=getJsonValue("Other","ForegroundPageState",value.toObject()).toBool();
                    p_ChannelParameter->TopPageState=getJsonValue("Other","TopPageState",value.toObject()).toBool();

                    qDebug()<<p_ChannelParameter->A1ReleasrCap;

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

                    configurationFolder.close();
                    return  true;
                    }
                }
            }
        }
    else {
        configurationFolder.remove();
        qWarning().noquote()<<QString("load Channel_%2.json error<errorCode=%1>").arg(jsonError.errorString()).arg(channel_number);
    }
    configurationFolder.close();

    return false;
}

bool Channel_Setting_Form::writeParameterSlot()
{
    configurationFolder.setFileName(fileRoot);

    if(!configurationFolder.open(QIODevice::WriteOnly)){
        qWarning().noquote()<<QString("open Channel_%1.json error<errorCode=%2>").arg(channel_number).arg(configurationFolder.OpenError);
        return false;
    }

    QJsonDocument jsonDoc;
    QJsonObject  jsonChild, jsonObjRoot;

    /*****************************
    * @brief:camera
    ******************************/
    QJsonObject jsonObj;
    jsonObj.insert(QString("FrontCamer"),ui->Camera_Front->text());
    jsonObj.insert(QString("AfterCamer"),ui->Camera_After->text());
    jsonObj.insert(QString("LeftCamer"),ui->Camera_Left->text());
    jsonObj.insert(QString("RgihtCamer"),ui->Camera_Right->text());
    jsonObj.insert(QString("TopCamer"),ui->Camera_Top->text());
    jsonObj.insert(QString("PlateCamer"),ui->Camera_Plate->text());
    jsonObj.insert(QString("UserCamer"),ui->Camera_User->text());
    jsonObj.insert(QString("PasswordCamer"),ui->Camera_Password->text());
    jsonObj.insert(QString("ForgroundCamer"),ui->Camera_Forground->text());
    jsonObj.insert(QString("ProspectsCamer"),ui->Camera_Prospects->text());
    jsonObj.insert(QString("LocalAddr"),ui->LocalAddr->text());

    jsonChild.insert("Camer",QJsonValue(jsonObj));

    /*****************************
    * @brief:serialPort
    ******************************/
    QJsonObject jsonObj2;
    jsonObj2.insert(QString("ControllerSignalMode"),ui->ControllerSignalMode->currentIndex());
    jsonObj2.insert(QString("SerialPortOne"),ui->SerialPort_One->value());
    jsonObj2.insert(QString("SerialPortTow"),ui->SerialPort_Tow->value());
    jsonObj2.insert(QString("SerialAddrOne"),ui->SerialAddr_One->text());
    jsonObj2.insert(QString("SerialAddrTow"),ui->SerialAddr_Tow->text());
    jsonObj2.insert(QString("PortOne"),ui->Port_One->value());
    jsonObj2.insert(QString("PortTow"),ui->Port_Tow->value());   
    jsonObj2.insert(QString("controllerPort"),ui->controllerPort_spinBox->value());
    jsonObj2.insert(QString("controllerAddr"),ui->controllerAddr_linedit->text());
    jsonObj2.insert(QString("D1out"),ui->D1out_comboBox->currentIndex());
    jsonObj2.insert(QString("D2out"),ui->D2out_comboBox->currentIndex());
    jsonObj2.insert(QString("D3out"),ui->D3out_comboBox->currentIndex());
    jsonObj2.insert(QString("D4out"),ui->D4out_comboBox->currentIndex());
    jsonObj2.insert(QString("interfaceModel"),ui->interfaceModel_comboBox->currentIndex());
    jsonObj2.insert(QString("lifthingType"),ui->lifthingType_comboBox->currentIndex());

    if(ui->SerialPortOpenState->isChecked()){
        jsonObj2.insert(QString("infraredStatus"),0);
    }
    if(ui->SerialPortCloseState->isChecked()){
        jsonObj2.insert(QString("infraredStatus"),1);
    }
    jsonChild.insert("SerialPort",QJsonValue(jsonObj2));

    /*****************************
    * @brief:other
    ******************************/
    QJsonObject jsonObj3;
    jsonObj3.insert(QString("Alias"),ui->Alias->text());
    jsonObj3.insert(QString("A1ReleasrCap"),ui->A1ReleasrCap_doubleSpinBox->value());
    jsonObj3.insert(QString("PlatePageState"),ui->PlatePageState->isChecked());
    jsonObj3.insert(QString("ProspectsPageState"),ui->ProspectsPageState->isChecked());
    jsonObj3.insert(QString("ForegroundPageState"),ui->ForegroundPageState->isChecked());
    jsonObj3.insert(QString("TopPageState"),ui->TopPageState->isChecked());
    jsonObj3.insert(QString("Channel_Number"),ui->Channel_Number->value());
    if(0==ui->Channel_Number->value()){
        jsonObj3.insert(QString("Channel_Number"),channel_number);
    }
    jsonChild.insert("Other",QJsonValue(jsonObj3));



    jsonObjRoot.insert(QString("Channel"),QJsonValue(jsonChild));
    jsonDoc.setObject(jsonObjRoot);

    QByteArray arr=jsonDoc.toJson();
    configurationFolder.write(arr);
    configurationFolder.waitForBytesWritten(1000);
    configurationFolder.close();

    return true;
}

void Channel_Setting_Form::parameterToUi()
{
    /*****************************
    * @brief:camera
    ******************************/
    ui->Camera_Front->setText(p_ChannelParameter->FrontCamer);
    ui->Camera_After->setText(p_ChannelParameter->AfterCamer);
    ui->Camera_Left->setText(p_ChannelParameter->LeftCamer);
    ui->Camera_Right->setText(p_ChannelParameter->RgihtCamer);
    ui->Camera_Top->setText(p_ChannelParameter->TopCamer);
    ui->Camera_Plate->setText(p_ChannelParameter->PlateCamer);
    ui->Camera_User->setText(p_ChannelParameter->UserCamer);
    ui->Camera_Password->setText(p_ChannelParameter->PasswordCamer);
    ui->Camera_Forground->setText(p_ChannelParameter->ForgroundCamer);
    ui->Camera_Prospects->setText(p_ChannelParameter->ProspectsCamer);
    ui->LocalAddr->setText(p_ChannelParameter->LocalAddr);

    /*****************************
    * @brief:serialport
    ******************************/
    ui->ControllerSignalMode->setCurrentIndex(p_ChannelParameter->ControllerSignalMode);
    ui->SerialPort_One->setValue(p_ChannelParameter->SerialPortOne);
    ui->SerialPort_Tow->setValue(p_ChannelParameter->SerialPortTow);
    ui->SerialAddr_One->setText(p_ChannelParameter->SerialAddrOne);
    ui->SerialAddr_Tow->setText(p_ChannelParameter->SerialAddrTow);
    ui->Port_One->setValue(p_ChannelParameter->PortOne);
    ui->Port_Tow->setValue(p_ChannelParameter->PortTow);    
    ui->controllerPort_spinBox->setValue(p_ChannelParameter->controllerPort);
    ui->controllerAddr_linedit->setText(p_ChannelParameter->controllerAddr);
    ui->D1out_comboBox->setCurrentIndex(p_ChannelParameter->D1out);
    ui->D2out_comboBox->setCurrentIndex(p_ChannelParameter->D2out);
    ui->D3out_comboBox->setCurrentIndex(p_ChannelParameter->D3out);
    ui->D4out_comboBox->setCurrentIndex(p_ChannelParameter->D4out);
    ui->interfaceModel_comboBox->setCurrentIndex(p_ChannelParameter->interfaceModel);
    ui->lifthingType_comboBox->setCurrentIndex(p_ChannelParameter->lifthingType);

    if(!p_ChannelParameter->infraredStatus){
        /* 常开 */
        ui->SerialPortOpenState->setChecked(true);
    }
    else {
        /* 常闭 */
        ui->SerialPortCloseState->setChecked(true);
    }

    /*****************************
    * @brief:other
    ******************************/
    ui->Alias->setText(p_ChannelParameter->Alias);
    ui->Channel_Number->setValue(p_ChannelParameter->Channel_number);
    ui->A1ReleasrCap_doubleSpinBox->setValue(p_ChannelParameter->A1ReleasrCap);
    ui->PlatePageState->setChecked(p_ChannelParameter->PlatePageState);
    ui->ProspectsPageState->setChecked(p_ChannelParameter->ProspectsPageState);
    ui->ForegroundPageState->setChecked(p_ChannelParameter->ForegroundPageState);
    ui->TopPageState->setChecked(p_ChannelParameter->TopPageState);
}

QVariant Channel_Setting_Form::getJsonValue(const QString &child, const QString &key, QJsonObject obj)
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
    else {
        qDebug().noquote()<<QString("load Channel_%3.json value error:%1-%2").arg(child).arg(key).arg(this->channel_number);
    }
    return  QString("");
}
