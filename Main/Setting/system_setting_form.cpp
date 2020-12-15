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

void System_Setting_Form::InitializationParameter(int channelNumber)
{
    ui->tabWidget->setCurrentIndex(0);
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
}

bool System_Setting_Form::loadParameter()
{
    configurationFolder.setFileName(fileRoot);

    if(!configurationFolder.open(QIODevice::ReadOnly)){
        QByteArray msg=tr("Failed to load the parameter,create the default parameter error<errorCode=%1>").arg(configurationFolder.OpenError).toLocal8Bit();
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
                    Parameter::FullScreen= getJsonValue("Other","FullScreen",value.toObject()).toInt();
                    Parameter::Automatic=getJsonValue("Other","Automatic",value.toObject()).toInt();
                    Parameter::InfoLog= getJsonValue("Other","InfoLog",value.toObject()).toInt();
                    Parameter::DebugLog= getJsonValue("Other","DebugLog",value.toObject()).toInt();
                    Parameter::DelayStart= getJsonValue("Other","DelayStart",value.toObject()).toInt();

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

bool System_Setting_Form::writeParameterSlot()
{
    configurationFolder.setFileName(fileRoot);

    if(!configurationFolder.open(QIODevice::WriteOnly)){
        const char* msg=tr("Failed to load the parameter,create the default parameter error<errorCode=%1>").arg(configurationFolder.OpenError).toLocal8Bit();
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
    obj3.insert("FtpLocalPath",ui->FtpLocal->text());
    obj3.insert("ReduceImage",(int)ui->ReduceImage->isChecked());
    jsonChild.insert("Upload",QJsonValue(obj3));

    /*****************************
    * @brief:Service
    ******************************/
    QJsonObject obj4;

    if(ui->ClientModel->isChecked()){
        obj4.insert("ServiceModel",0);
    }
    if(ui->ServerModel->isChecked()){

        obj4.insert("ServiceModel",1);
    }

    obj4.insert("Service_Type",ui->Service_Type_comboBox->currentIndex());
    obj4.insert("SingletonAddress",ui->Address_Singleton_lineEdit->text());
    obj4.insert("ManyCasesAddress",ui->Address_Many_textEdit->toPlainText());
    obj4.insert("Heartbeat",int(ui->Hearbeat_checkBox->isChecked()));
    obj4.insert("Resultting",int(ui->Resulting_checkBox->isChecked()));
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

    /*****************************
    * @brief:Recognizer
    ******************************/
    if(!Parameter::ResultsTheCheck){/* 颜色显示 */
        ui->ColorDisplay->setChecked(1);
    }
    else {/* 自动校验 */
        ui->AutomaticCorrection->setChecked(1);
    }

    /*****************************
    * @brief:Service
    ******************************/
    if(!Parameter::ServiceModel){/* 客户端模式 */
        ui->ClientModel->setChecked(1);
    }
    else {/* 服务器模式 */
        ui->ServerModel->setChecked(1);
    }
    ui->Service_Type_comboBox->setCurrentIndex(Parameter::Service_Type);
    ui->Address_Singleton_lineEdit->setText(Parameter::SingletonAddress);
    ui->Address_Many_textEdit->setText(Parameter::ManyCasesAddress);
    ui->Hearbeat_checkBox->setChecked(Parameter::Heartbeat);
    ui->Resulting_checkBox->setChecked(Parameter::Resultting);

    /*****************************
    * @brief:Upload
    ******************************/
    ui->Ftp->setChecked(Parameter::Ftp);
    ui->FtpAddress->setText(Parameter::FtpAddress);
    ui->FtpPort->setText(QString::number(Parameter::FtpPort));
    ui->FtpUser->setText(Parameter::FtpUser);
    ui->FtpPassword->setText(Parameter::FtpPassword);
    ui->FtpLocal->setText(Parameter::FtpLocalPath);
    ui->FtpRemote->setText(Parameter::FtpRemotePath);

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
    QByteArray msg=tr("load SYSTEM.json value error:%1-%2").arg(child).arg(key).toLocal8Bit();
    qWarning("%s", msg.data());
    return  QString("");
}

void System_Setting_Form::on_Service_Type_comboBox_currentIndexChanged(int index)
{
    if(index==0){
        ui->ClientModel->setEnabled(false);
        ui->ServerModel->setChecked(true);
    }
    else if (index==1) {
        ui->ClientModel->setEnabled(true);
        ui->ClientModel->setEnabled(true);
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
                QMessageBox::StandardButton bt= QMessageBox::warning(this,check,tr("Whether to delete the record=%1").arg(check),QMessageBox::Yes|QMessageBox::No);
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
                QMessageBox::StandardButton bt= QMessageBox::warning(this,check,tr("Whether to add the record=%1").arg(check),QMessageBox::Yes|QMessageBox::No);
                if(bt==QMessageBox::Yes){
                    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
                        strList.append(tr("%1").arg(check));
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
        rowLabels.append(tr("%1 # Channel").arg(i,2,10,QChar('0')));
    }
    emit initializesTheDeviceTemporaryTableSignal(arg1,rowLabels);
}
