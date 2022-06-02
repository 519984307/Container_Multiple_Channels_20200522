#include "system_setting_form.h"
#include "ui_system_setting_form.h"
/*****************************
* @brief:全局参数
******************************/
#include "Parameter/LocalPar.h"

System_Setting_Form::System_Setting_Form(int channelNumber, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::System_Setting_Form)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose,true);

    this->setParent(parent);
    this->setHidden(true);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    InitializationParameter(channelNumber);
}

System_Setting_Form::~System_Setting_Form()
{
    delete ui;
}

void System_Setting_Form::showEvent(QShowEvent *event)
{
    Q_UNUSED(event)

    /*****************************
    * @brief:主页面显示tab文本
    ******************************/
    QStringList systemTabs;
    for (int var = 0; var < ui->tabWidget->count(); ++var) {
        systemTabs<<ui->tabWidget->tabText(var);
    }
    emit initializesTheDeviceTemporaryTableSignal(0,systemTabs);
}

void System_Setting_Form::InitializationParameter(int channelNumber)
{
    /*****************************
    * @brief:默认保存日志30次
    ******************************/
    ui->groupBox_11->setHidden(true);

    ///
    /// \brief loadAdapterMAC 加载本机网卡
    ///
    loadAdapterMAC();

    /*****************************
    * @brief:启动禁止设置按钮
    ******************************/
    ui->setParameter_pushButton->setEnabled(false);

    ui->equiment_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tabWidget->setCurrentIndex(0);

    if (Parameter::DataChaneType==0){
        if(Parameter::Service_Type==0){
            ui->Service_Type_stackedWidget->setCurrentIndex(0);
        }
        else if (Parameter::Service_Type==1) {
            ui->Service_Type_stackedWidget->setCurrentIndex(1);
        }
    }
    else if(Parameter::DataChaneType==1){
        if(Parameter::Service_Type==0){
            ui->Service_Type_stackedWidget->setCurrentIndex(2);
        }
        else if (Parameter::Service_Type==1) {
            ui->Service_Type_stackedWidget->setCurrentIndex(3);
        }
    }

    /*****************************
    * @brief:创建配置文件夹
    ******************************/
    QDir mkPath(QCoreApplication::applicationDirPath());
    mkPath.mkdir("Json");
    mkPath.cd("Json");

    fileRoot=QDir::toNativeSeparators(QString("%1/%2").arg(mkPath.path()).arg("System.json"));

    connect(ui->Contains_pushButton,SIGNAL(clicked()),this,SLOT(conditionsOfButton_clicked()));
    connect(ui->Eliminate_pushButton,SIGNAL(clicked()),this,SLOT(conditionsOfButton_clicked()));

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

    /*****************************
    * @brief: 写入临时通道数
    ******************************/
    int CS=channelNumber;
    if(CS>LocalPar::Channels){
        CS=LocalPar::Channels;
    }
    ui->ChannelNumber->setValue(CS);
    ui->ChannelNumber->setMaximum(LocalPar::Channels);

    foreach (QTabBar* obj, ui->tabWidget->findChildren<QTabBar*>()) {
        /*****************************
        * @brief:ChcekBox禁止手动勾选
        ******************************/
        obj->hide();
    }
}

void System_Setting_Form::loadAdapterMAC()
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
                if(address.ip().protocol()==QAbstractSocket::IPv4Protocol){
                    ui->adapter_comboBox->addItem(QString("[%1][%2]:%3").arg(address.ip().toString(),adapter.hardwareAddress(),adapter.humanReadableName()));
                }
            }
        }
    }
}

bool System_Setting_Form::loadParameter()
{
    configurationFolder.setFileName(fileRoot);

    if(!configurationFolder.open(QIODevice::ReadOnly)){
        QByteArray msg=QString("Failed to load the parameter,create the default parameter error<errorCode=%1>").arg(configurationFolder.OpenError).toLocal8Bit();
        qWarning("%s", msg.data());

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
                    if(Parameter::ChannelNumber>ui->ChannelNumber->maximum()){
                        /*****************************
                        * @brief: 防止后台篡改通道数量
                        ******************************/
                        Parameter::ChannelNumber=ui->ChannelNumber->maximum();
                    }
                    else if (Parameter::ChannelNumber==0) {
                        /*****************************
                        * @brief: 登录页面已做处理
                        ******************************/
                        Parameter::ChannelNumber= getJsonValue("Channel","ChannelNumber",value.toObject()).toInt();
                    }
                    else {
                        //Parameter::ChannelNumber= getJsonValue("Channel","ChannelNumber",value.toObject()).toInt();
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
                    Parameter::databaseAddr= getJsonValue("Upload","databaseAddr",value.toObject()).toString();
                    Parameter::databaseUser= getJsonValue("Upload","databaseUser",value.toObject()).toString();
                    Parameter::databasePass= getJsonValue("Upload","databasePass",value.toObject()).toString();
                    Parameter::DatabaseType=getJsonValue("Upload","DatabaseType",value.toObject()).toInt();
                    Parameter::upload_images=getJsonValue("Upload","upload_images",value.toObject()).toString();

                    /*****************************
                    * @brief:Other
                    ******************************/
                    Parameter::Language= getJsonValue("Other","Language",value.toObject()).toInt();
                    Parameter::Minimization= getJsonValue("Other","Minimization",value.toObject()).toInt();
                    Parameter::FullScreen= getJsonValue("Other","FullScreen",value.toObject()).toInt();
                    Parameter::Automatic=getJsonValue("Other","Automatic",value.toObject()).toInt();
                    Parameter::InfoLog= getJsonValue("Other","InfoLog",value.toObject()).toInt();
                    Parameter::DebugLog= getJsonValue("Other","DebugLog",value.toObject()).toInt();
                    Parameter::DelayStart= getJsonValue("Other","DelayStart",value.toObject()).toInt();

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
                    Parameter::Identify_Protocol=getJsonValue("Service","Identify_Protocol",value.toObject()).toInt();
                    Parameter::Heartbeat=getJsonValue("Service","Heartbeat",value.toObject()).toInt();
                    Parameter::Resultting=getJsonValue("Service","Resultting",value.toObject()).toInt();
                    Parameter::ShortLink=getJsonValue("Service","ShortLink",value.toObject()).toInt();
                    Parameter::newline=getJsonValue("Service","newline",value.toObject()).toInt();
                    Parameter::DataChaneType=getJsonValue("Service","DataChaneType",value.toObject()).toInt();                                      
                    Parameter::SingletonAddressMQ=getJsonValue("Service","SingletonAddressMQ",value.toObject()).toString();
                    Parameter::ManyCasesAddressMQ=getJsonValue("Service","ManyCasesAddressMQ",value.toObject()).toString();
                    Parameter::DataChange_Format=getJsonValue("Service","DataChange_Format",value.toObject()).toInt();
                    Parameter::plate_timeout=getJsonValue("Service","plate_timeout",value.toObject()).toInt();
                    Parameter::container_timeout=getJsonValue("Service","container_timeout",value.toObject()).toInt();
                    Parameter::not_plate_color=getJsonValue("Service","not_plate_color",value.toObject()).toInt();
                    Parameter::same_plate_out=getJsonValue("Service","same_plate_out",value.toObject()).toInt();
                    Parameter::dont_false_plate=getJsonValue("Service","dont_false_plate",value.toObject()).toInt();
                    Parameter::false_plate=getJsonValue("Service","false_plate",value.toObject()).toString();
                    Parameter::bluePlate=getJsonValue("Service","bluePlate",value.toObject()).toInt();


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

bool System_Setting_Form::writeParameterSlot()
{
    configurationFolder.setFileName(fileRoot);

    if(!configurationFolder.open(QIODevice::WriteOnly)){
        const char* msg=QString("Failed to load the parameter,create the default parameter error<errorCode=%1>").arg(configurationFolder.OpenError).toLocal8Bit();
        qWarning("%s", msg);
        return false;
    }

    QJsonDocument jsonDoc;
    QJsonObject jsonChild,jsonRoot;

    /*****************************
    * @brief:Channel
    ******************************/
    QJsonObject obj1;
    obj1.insert("ChannelNumber",ui->ChannelNumber->value());
    obj1.insert("ImageFormat",ui->ImageFormat->currentIndex());
    obj1.insert("ImagePath",ui->ImgPathlineEdit->text());
    obj1.insert("ImageNamingRules",(int)ui->ImageNamingRules->currentIndex());
    obj1.insert("camera_id_placeholder",ui->camera_id_lineEdit->text());
    obj1.insert("channel_id_placeholder",ui->channel_id_lineEdit->text());
    jsonChild.insert("Channel",QJsonValue(obj1)); 

    /*****************************
    * @brief:Recognizer
    ******************************/
    QJsonObject obj2;

    if(ui->ColorDisplay->isChecked()){
        obj2.insert("ResultsTheCheck",0);       
    }
    else if (ui->AutomaticCorrection->isChecked()) {
        obj2.insert("ResultsTheCheck",1);
    }
    obj2.insert("picture_size",ui->picture_size_comboBox->currentIndex());
    jsonChild.insert("Recognizer",QJsonValue(obj2));

    /*****************************
    * @brief:Upload
    ******************************/
    QJsonObject obj3;
    obj3.insert("Ftp",(int)ui->Ftp->isChecked());
    obj3.insert("FtpUser",ui->FtpUser->text());
    obj3.insert("FtpPassword",ui->FtpPassword->text());
    obj3.insert("FtpAddress",ui->FtpAddress->text());
    obj3.insert("FtpPort", ui->FtpPort->text().toInt());
    obj3.insert("FtpRemotePath",ui->FtpRemote->text());
    obj3.insert("FtpTimeDIC",(int)ui->time_Dic_checkBox->isChecked());
    obj3.insert("ReduceImage",(int)ui->ReduceImage->isChecked());
    obj3.insert("DatabaseType",ui->database_Type_comboBox->currentIndex());
    obj3.insert("databaseAddr",ui->database_Addr_lineEdit->text());
    obj3.insert("databaseUser",ui->database_User_lineEdit->text());
    obj3.insert("databasePass",ui->database_Pass_lineEdit->text());
    obj3.insert("upload_images",ui->upload_images_lineEdit->text());
    jsonChild.insert("Upload",QJsonValue(obj3));

    /*****************************
    * @brief:Service
    ******************************/
    QJsonObject obj4;

    if(ui->ClientModel->isChecked()){
        obj4.insert("Service_Model",0);
    }
    if(ui->ServerModel->isChecked()){
        obj4.insert("Service_Model",1);
    }   

    obj4.insert("DataChange_Format",ui->DataChange_Format_comboBox->currentIndex());
    obj4.insert("SingletonAddressMQ",ui->Address_Singleton_MQ_lineEdit->text());
    obj4.insert("ManyCasesAddressMQ",ui->Address_Many_MQ_textEdit->toPlainText());
    obj4.insert("Service_Type",ui->Service_Type_comboBox->currentIndex());
    obj4.insert("SingletonAddress",ui->Address_Singleton_lineEdit->text());
    obj4.insert("ManyCasesAddress",ui->Address_Many_textEdit->toPlainText());
    obj4.insert("Heartbeat",int(ui->Hearbeat_checkBox->isChecked()));
    obj4.insert("Resultting",int(ui->Resulting_checkBox->isChecked()));
    obj4.insert("ShortLink",int(ui->ShortLink_checkBox->isChecked()));
    obj4.insert("DataChaneType",ui->DataChaneType_combox->currentIndex());
    obj4.insert("newline",int(ui->newline_checkBox->isChecked()));
    obj4.insert("Identify_Protocol",int(ui->Identify_Protocol_comboBox_2->currentIndex()));    
    obj4.insert("plate_timeout",int(ui->plate_timeout_spinBox->value()));
    obj4.insert("container_timeout",int(ui->container_timeout_spinBox->value()));
    obj4.insert("not_plate_color",int(ui->plate_color_checkBox->isChecked()));
    obj4.insert("same_plate_out",int(ui->same_plate_out_spinBox->value()));
    obj4.insert("false_plate",ui->false_plate_lineEdit->text());
    obj4.insert("dont_false_plate",int(ui->false_plate_checkBox->isChecked()));
    obj4.insert("bluePlate",int(ui->bluePlate_checkBox->isChecked()));


    jsonChild.insert("Service",QJsonValue(obj4));

    /*****************************
    * @brief:Other
    ******************************/
    QJsonObject obj5;
    obj5.insert("InfoLog",int(ui->InfoLog->isChecked()));
    obj5.insert("DebugLog",int(ui->DebugLog->isChecked()));
    obj5.insert("Minimization",int(ui->StartupMinimization->isChecked()));
    obj5.insert("FullScreen",int(ui->FullScreen->isChecked()));
    obj5.insert("Language", ui->Language->currentIndex());
    obj5.insert("Automatic",int(ui->AutomaticStart->isChecked()));
    obj5.insert("DelayStart",ui->DelayStart->value());
    jsonChild.insert("Other",QJsonValue(obj5));

    /*****************************
    * @brief:Model
    ******************************/
    QJsonObject obj6;
    obj6.insert("HCNET_Capture_Type",ui->HCNET_Capture_Type_comboBox->currentIndex());
    obj6.insert("Camera_Load_Plugin",ui->Camera_Load_Plugin_comboBox->currentIndex());
    /*****************************
    * @brief:红外模式【0:南京三宝，1:标准】
    ******************************/
    if(ui->logicType_standard_radioButton->isChecked()){
        obj6.insert("LogicType",1);
    }
    if(ui->logicType_njsb_radioButton->isChecked()){
        obj6.insert("LogicType",0);
    }
    obj6.insert("PlateType",ui->PlateType_comboBox->currentIndex());
    obj6.insert("interfaceModel",ui->interfaceModel_comboBox->currentIndex());
    obj6.insert("loadLibrary_HK",int(ui->loadLibrary_HK_checkBox->isChecked()));
    obj6.insert("Display_mode",ui->Display_mode_comboBox->currentIndex());

    jsonChild.insert("Model",QJsonValue(obj6));

    jsonRoot.insert("Main",QJsonValue(jsonChild));
    jsonDoc.setObject(jsonRoot);

    /*****************************
    * @brief:写入配置文件
    ******************************/
    QByteArray arr=jsonDoc.toJson();
    int len=configurationFolder.write(arr);
    configurationFolder.waitForBytesWritten(1000);
    configurationFolder.close();

    /*****************************
    * @brief:开机启动参数设置
    ******************************/
    emit automaticStateSingal(ui->AutomaticStart->checkState());

    if(len==-1){
        return false;
    }
    return true;
}

void System_Setting_Form::sendEquipmentParSlot(QMap<QString, QMap<QString, QString>> par)
{
    parMap=par;

    QList<QString> keyList=par.keys().toSet().toList();

    foreach (QString key, keyList) {
        int row = ui->equiment_tableWidget->rowCount();
        ui->equiment_tableWidget->insertRow(row);
        ui->equiment_tableWidget->setItem(row,2,new QTableWidgetItem(key));

        //QList<QMap<QString,QString>> varList=  par.values(key);
        foreach (auto var, par.values(key)) {
            if(!var.value("NAME","").isEmpty()){
                ui->equiment_tableWidget->setItem(row,0,new QTableWidgetItem(var.value("NAME")));
            }
            if(!var.value("IP","").isEmpty()){
                ui->equiment_tableWidget->setItem(row,1,new QTableWidgetItem(var.value("IP")));
            }
        }
    }
    keyList.clear();

    if(ui->equiment_tableWidget->rowCount()>0){
        ui->setParameter_pushButton->setEnabled(true);
    }
}

void System_Setting_Form::setParSucessSlot()
{
    QMessageBox::information(this,"ZBY Setting",QString("%1:%2").arg(ui->mac_lineEdit->text(),"Parameter setting succeeded"),QMessageBox::Ok);

    QString key=ui->mac_lineEdit->text();
    parMap.remove(key);

    QMap<QString,QString> tmpPar;
    tmpPar.insert("IP",ui->address_lineEdit->text());
    tmpPar.insert("GATEWAY",ui->gateway_lineEdit->text());
    tmpPar.insert("MASK",ui->mask_lineEdit->text());
    tmpPar.insert("PORT",ui->port_lineEdit->text());
    tmpPar.insert("MODEL",QString::number(ui->model_comboBox->currentIndex()));
    tmpPar.insert("DIP",ui->local_address_lineEdit->text());
    tmpPar.insert("DPORT",ui->local_port_lineEdit->text());
    tmpPar.insert("WID",ui->id_lineEdit->text());
    tmpPar.insert("NAME",ui->name_lineEdit->text());
    parMap.insertMulti(key,tmpPar);
}

void System_Setting_Form::systemCurrentRowChangedSlot(int currentRow)
{
    ui->tabWidget->setCurrentIndex(currentRow);
}

void System_Setting_Form::parameterToUi()
{
    /*****************************
    * @brief:Channel
    ******************************/
    if(Parameter::ChannelNumber>ui->ChannelNumber->maximum()){/* 防止后台篡改通道数量 */
        Parameter::ChannelNumber=ui->ChannelNumber->maximum();
    }
    ui->ChannelNumber->setValue(Parameter::ChannelNumber);
    ui->ImageNamingRules->setCurrentIndex(Parameter::ImageNamingRules);
    ui->ImageFormat->setCurrentIndex(Parameter::ImageFormat);
    ui->ImgPathlineEdit->setText(Parameter::ImagePath);
    ui->camera_id_lineEdit->setText(QString::number(Parameter::camera_id_placeholder));
    ui->channel_id_lineEdit->setText(QString::number(Parameter::channel_id_placeholder));

    /*****************************
    * @brief:Model
    ******************************/
    ui->HCNET_Capture_Type_comboBox->setCurrentIndex(Parameter::HCNET_Capture_Type);
    ui->Camera_Load_Plugin_comboBox->setCurrentIndex(Parameter::Camera_Load_Plugin);

    if(1 == Parameter::LogicType){
        ui->logicType_standard_radioButton->setChecked(true);
    }
    if(0 == Parameter::LogicType){
        ui->logicType_njsb_radioButton->setChecked(true);
    }

    ui->PlateType_comboBox->setCurrentIndex(Parameter::PlateType);
    ui->interfaceModel_comboBox->setCurrentIndex(Parameter::interfaceModel);
    ui->loadLibrary_HK_checkBox->setChecked(Parameter::loadLibrary_HK);
    ui->Display_mode_comboBox->setCurrentIndex(Parameter::Display_mode);


    /*****************************
    * @brief:Recognizer
    ******************************/
    if(!Parameter::ResultsTheCheck){/* 颜色显示 */
        ui->ColorDisplay->setChecked(1);
    }
    else {/* 自动校验 */
        ui->AutomaticCorrection->setChecked(1);
    }
    ui->picture_size_comboBox->setCurrentIndex(Parameter::picture_size);

    /*****************************
    * @brief:Service
    ******************************/
    if(!Parameter::Service_Model){/* 客户端模式 */
        ui->ClientModel->setChecked(1);
    }
    else {/* 服务器模式 */
        ui->ServerModel->setChecked(1);
    }   
    ui->DataChange_Format_comboBox->setCurrentIndex(Parameter::DataChange_Format);
    ui->Address_Singleton_MQ_lineEdit->setText(Parameter::SingletonAddressMQ);
    ui->Address_Many_MQ_textEdit->setText(Parameter::ManyCasesAddressMQ);
    ui->Service_Type_comboBox->setCurrentIndex(Parameter::Service_Type);
    ui->Address_Singleton_lineEdit->setText(Parameter::SingletonAddress);
    ui->Address_Many_textEdit->setText(Parameter::ManyCasesAddress);
    ui->Hearbeat_checkBox->setChecked(Parameter::Heartbeat);
    ui->Resulting_checkBox->setChecked(Parameter::Resultting);
    ui->ShortLink_checkBox->setChecked(Parameter::ShortLink);
    ui->newline_checkBox->setChecked(Parameter::newline);
    ui->DataChaneType_combox->setCurrentIndex(Parameter::DataChaneType);
    ui->Identify_Protocol_comboBox_2->setCurrentIndex(Parameter::Identify_Protocol);    
    ui->plate_timeout_spinBox->setValue(Parameter::plate_timeout);
    ui->container_timeout_spinBox->setValue(Parameter::container_timeout);
    ui->plate_color_checkBox->setChecked(Parameter::not_plate_color);
    ui->same_plate_out_spinBox->setValue(Parameter::same_plate_out);
    ui->false_plate_lineEdit->setText(Parameter::false_plate);
    ui->false_plate_checkBox->setChecked(Parameter::dont_false_plate);
    ui->bluePlate_checkBox->setChecked(Parameter::bluePlate);


    /*****************************
    * @brief:Upload
    ******************************/
    ui->Ftp->setChecked(Parameter::Ftp);
    ui->FtpAddress->setText(Parameter::FtpAddress);
    ui->FtpPort->setText(QString::number(Parameter::FtpPort));
    ui->FtpUser->setText(Parameter::FtpUser);
    ui->FtpPassword->setText(Parameter::FtpPassword);
    ui->time_Dic_checkBox->setChecked(Parameter::FtpTimeDIC);
    ui->FtpRemote->setText(Parameter::FtpRemotePath);   
    ui->database_Type_comboBox->setCurrentIndex(Parameter::DatabaseType);
    ui->database_Addr_lineEdit->setText(Parameter::databaseAddr);
    ui->database_User_lineEdit->setText(Parameter::databaseUser);
    ui->database_Pass_lineEdit->setText(Parameter::databasePass);
    ui->upload_images_lineEdit->setText(Parameter::upload_images);

    /*****************************
    * @brief:Other
    ******************************/
    ui->StartupMinimization->setChecked(Parameter::Minimization);
    ui->FullScreen->setChecked(Parameter::FullScreen);
    ui->Language->setCurrentIndex(Parameter::Language);
    ui->AutomaticStart->setChecked(Parameter::Automatic);
    ui->InfoLog->setChecked(Parameter::InfoLog);
    ui->DebugLog->setChecked(Parameter::DebugLog);
    ui->DelayStart->setValue(Parameter::DelayStart);
}

QVariant System_Setting_Form::getJsonValue(const QString &child, const QString &key, QJsonObject obj)
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
    QByteArray msg=QString("load SYSTEM.json value error:%1-%2").arg(child).arg(key).toLocal8Bit();
    qWarning("%s", msg.data());
    return  QString("");
}

void System_Setting_Form::on_Service_Type_comboBox_currentIndexChanged(int index)
{
    if(ui->DataChaneType_combox->currentIndex()==1){
        if(index==0){
            ui->Service_Type_stackedWidget->setCurrentIndex(2);
        }
        else if (index==1) {
            ui->Service_Type_stackedWidget->setCurrentIndex(3);
        }
    }
    else if (ui->DataChaneType_combox->currentIndex()==0) {
        if(index==0){
            ui->ClientModel->setEnabled(true);
        }
        else if (index==1) {
            ui->ClientModel->setEnabled(false);
            ui->ServerModel->setChecked(true);
        }
    }
}

void System_Setting_Form::on_CheckPathPushButton_clicked()
{
    QString path=QFileDialog::getExistingDirectory(this);
    if(path.trimmed()==""){
        ui->ImgPathlineEdit->setText("");
    }
    ui->ImgPathlineEdit->setText(QString("%1").arg(path).toLocal8Bit());
}

void System_Setting_Form::conditionsOfButton_clicked()
{
    QString fileName="";
    QString check="";

    QPushButton* pPb=qobject_cast<QPushButton*>(sender());
    if(pPb==ui->Contains_pushButton){
        fileName="XXXX.dat";
        check=ui->Contains_lineEdit->text().trimmed().toUpper();
    }
    else if (pPb==ui->Eliminate_pushButton) {
        fileName="ZZZZ.dat";
        check=ui->Eliminate_lineEdit->text().trimmed().toUpper();
    }

    int index=-1;
    QFile file(QDir::toNativeSeparators(QString("%1/%2/%3").arg(QCoreApplication::applicationDirPath()).arg("QRecognition").arg(fileName)));

    if(check!=""){
        if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream stream(&file);
            QStringList strList=stream.readAll().split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
            for (int var = 0; var < strList.count(); ++var) {
                if(strList.at(var)==check){
                    index=var;
                    break;
                }
            }
            file.close();

            if(index!=-1){/* 添加项 */
                QMessageBox::StandardButton bt= QMessageBox::warning(this,check,QString("Whether to delete the record=%1").arg(check),QMessageBox::Yes|QMessageBox::No);
                if(bt==QMessageBox::Yes){
                    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
                        strList.removeAt(index);
                        #ifdef Q_OS_LINUX
                            stream<<strList.join("\n");
                        #endif
                        #ifdef Q_OS_WIN
                            stream<<strList.join("\r\n");
                        #endif
                        file.close();
                    }
                }
            }
            else {/* 删除项 */
                QMessageBox::StandardButton bt= QMessageBox::warning(this,check,QString("Whether to add the record=%1").arg(check),QMessageBox::Yes|QMessageBox::No);
                if(bt==QMessageBox::Yes){
                    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
                        strList.append(QString("%1").arg(check));
                        #ifdef Q_OS_LINUX
                            stream<<strList.join("\n");
                        #endif
                        #ifdef Q_OS_WIN
                            stream<<strList.join("\r\n");
                        #endif
                        file.close();
                    }
                }
            }
        }
    }
}

void System_Setting_Form::on_AutomaticStart_stateChanged(int arg1)
{
    bool status=false;
    if(arg1==Qt::CheckState::Checked){
        status=true;
    }
    emit automaticStateSingal(status);
}

void System_Setting_Form::on_ChannelNumber_valueChanged(int arg1)
{
    QStringList rowLabels;
    for(int i=1;i<=arg1;i++){
        rowLabels.append(QString("%1 # Channel").arg(i,2,10,QChar('0')));
    }
    emit initializesTheDeviceTemporaryTableSignal(arg1,rowLabels);
}

void System_Setting_Form::on_HCNET_Capture_Type_comboBox_currentIndexChanged(int index)
{
    if(3==index){
        ui->Camera_Load_Plugin_comboBox->setCurrentIndex(1);
    }
    if(2==index){
        ui->Camera_Load_Plugin_comboBox->setCurrentIndex(0);
    }
    if(4==index){
        ui->Camera_Load_Plugin_comboBox->setCurrentIndex(1);
    }
}

void System_Setting_Form::on_Camera_Load_Plugin_comboBox_currentIndexChanged(int index)
{
    Q_UNUSED(index);

    if(3==ui->HCNET_Capture_Type_comboBox->currentIndex()){
        ui->Camera_Load_Plugin_comboBox->setCurrentIndex(1);
    }
    if(2==ui->HCNET_Capture_Type_comboBox->currentIndex()){
        ui->Camera_Load_Plugin_comboBox->setCurrentIndex(0);
    }
    if(4==ui->HCNET_Capture_Type_comboBox->currentIndex()){
        ui->Camera_Load_Plugin_comboBox->setCurrentIndex(1);
    }
}

void System_Setting_Form::on_DataChaneType_combox_currentIndexChanged(int index)
{
    if(index==0){
        if(ui->Service_Type_comboBox->currentIndex()==0){
            ui->Service_Type_stackedWidget->setCurrentIndex(0);
        }
        else if (ui->Service_Type_comboBox->currentIndex()==1) {
            ui->Service_Type_stackedWidget->setCurrentIndex(1);
        }
    }
    if(index==1){
        if(ui->Service_Type_comboBox->currentIndex()==0){
            ui->Service_Type_stackedWidget->setCurrentIndex(2);
        }
        else if (ui->Service_Type_comboBox->currentIndex()==1) {
            ui->Service_Type_stackedWidget->setCurrentIndex(3);
        }
    }
}

void System_Setting_Form::on_searchEquipment_pushButton_clicked()
{
    parMap.clear();

    ui->setParameter_pushButton->setEnabled(false);

    int row=ui->equiment_tableWidget->rowCount();
    for (int ind=0;ind<row;ind++) {
        ui->equiment_tableWidget->removeRow(0);
    }

    foreach (QLineEdit* obj, ui->groupBox_3->findChildren<QLineEdit*>(QString(),Qt::FindChildrenRecursively)) {
        obj->setText("");
        obj->clear();
    }

    ui->model_comboBox->setCurrentIndex(ui->model_comboBox->count()-1);

    emit searchEquipmentSignal(ui->adapter_comboBox->currentText(),5000);
}

void System_Setting_Form::on_equiment_tableWidget_itemClicked(QTableWidgetItem *item)
{
    Q_UNUSED(item);

    QList<QTableWidgetItem*> items=ui->equiment_tableWidget->selectedItems();
    if(parMap.keys().size()>0){
        QList<QString> keyList=parMap.keys().toSet().toList();

        foreach (QString key, keyList) {
            if(items.at(2)->text()==key){
                ui->mac_lineEdit->setText(key);
                //QList<QMap<QString,QString>> varList=  parMap.values(key);
                foreach (auto var, parMap.values(key)) {
                    if(!var.value("IP","").isEmpty()){
                        ui->address_lineEdit->setText(var.value("IP"));
                    }
                    if(!var.value("GATEWAY","").isEmpty()){
                        ui->gateway_lineEdit->setText(var.value("GATEWAY"));
                    }
                    if(!var.value("MASK","").isEmpty()){
                        ui->mask_lineEdit->setText(var.value("MASK"));
                    }
                    if(!var.value("PORT","").isEmpty()){
                        ui->port_lineEdit->setText(var.value("PORT"));
                    }
                    if(!var.value("MODEL","").isEmpty()){
                        ui->model_comboBox->setCurrentIndex(var.value("MODEL").toInt());
                    }
                    if(!var.value("DIP","").isEmpty()){
                        ui->local_address_lineEdit->setText(var.value("DIP"));
                    }
                    if(!var.value("DPORT","").isEmpty()){
                        ui->local_port_lineEdit->setText(var.value("DPORT"));
                    }
                    if(!var.value("WID","").isEmpty()){
                        ui->id_lineEdit->setText(var.value("WID"));
                    }
                    if(!var.value("NAME","").isEmpty()){
                        ui->name_lineEdit->setText(var.value("NAME"));
                    }
                }
            }
        }
        keyList.clear();
    }
}

void System_Setting_Form::on_setParameter_pushButton_clicked()
{
    if(!ui->mac_lineEdit->text().isEmpty()){
        QString key=ui->mac_lineEdit->text();
        QMap<QString,QMap<QString,QString>> parMMap;
        QMap<QString,QString> par;
        par.insert("IP",ui->address_lineEdit->text());
        par.insert("GATEWAY",ui->gateway_lineEdit->text());
        par.insert("MASK",ui->mask_lineEdit->text());
        par.insert("PORT",ui->port_lineEdit->text());
        par.insert("MODEL",QString::number(ui->model_comboBox->currentIndex()));
        par.insert("DIP",ui->local_address_lineEdit->text());
        par.insert("DPORT",ui->local_port_lineEdit->text());
        par.insert("WID",ui->id_lineEdit->text());
        par.insert("NAME",ui->name_lineEdit->text());

        parMMap.insertMulti(key,par);

        emit setEquipmentParSignal(parMMap);
        par.clear();
        parMMap.clear();
    }
}

void System_Setting_Form::on_searchInternet_pushButton_clicked()
{
    ui->adapter_comboBox->clear();
    loadAdapterMAC();
}

void System_Setting_Form::on_loadLibrary_HK_checkBox_stateChanged(int arg1)
{
    if(arg1==Qt::CheckState::Checked){
       ui->Camera_Load_Plugin_comboBox->setEnabled(false);
    }
    else {
        ui->Camera_Load_Plugin_comboBox->setEnabled(true);
    }
}
