#include "system_setting_form.h"
#include "ui_system_setting_form.h"

System_Setting_Form::System_Setting_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::System_Setting_Form)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose,true);

    this->setParent(parent);
    this->setHidden(true);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    InitializationParameter();
}

System_Setting_Form::~System_Setting_Form()
{
    p_Parameter=nullptr;

    delete p_Parameter;
    delete ui;
}

void System_Setting_Form::InitializationParameter()
{
    p_Parameter=new Parameter ();

    /*****************************
    * @brief:创建配置文件夹
    ******************************/
    QDir mkPath(QCoreApplication::applicationDirPath());
    mkPath.mkdir("Json");
    mkPath.cd("Json");

    configurationFolder.setFileName(QDir::toNativeSeparators(QString("%1/%2").arg(mkPath.path()).arg("System.json")));

    connect(ui->Contains_pushButton,SIGNAL(clicked()),this,SLOT(conditionsOfButton_clicked()));
    connect(ui->Eliminate_pushButton,SIGNAL(clicked()),this,SLOT(conditionsOfButton_clicked()));

    /* 加载配置 */
    if(!loadParameter()){
        if(writeParameter()){
            loadParameter();
        }
    }
    else {/* 外部更改配置,回写配置到UI */
        parameterToUi();
    }
}

bool System_Setting_Form::loadParameter()
{
    if(!configurationFolder.open(QIODevice::ReadOnly)){
        emit messageSignal(ZBY_LOG("ERROR"),tr("Failed to load the parameter,create the default parameter error<errorCode=%1>").arg(configurationFolder.OpenError));
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
            if(obj.contains(tr("Main"))){
                QJsonValue value=obj.value(tr("Main"));

                /* 读取子目录 */
                if(value.isObject()){

                    /*****************************
                    * @brief:Channel
                    ******************************/
                    p_Parameter->ChannelNumber= getJsonValue("Channel","ChannelNumber",value.toObject()).toInt();
                    if(p_Parameter->ChannelNumber>ui->ChannelNumber->maximum()){/* 防止后台篡改通道数量 */
                        p_Parameter->ChannelNumber=ui->ChannelNumber->maximum();
                    }
                    p_Parameter->ImageFormat= getJsonValue("Channel","ImageFormat",value.toObject()).toInt();
                    p_Parameter->ImageNamingRules= getJsonValue("Channel","ImageNamingRules",value.toObject()).toInt();
                    p_Parameter->ImagePath= getJsonValue("Channel","ImagePath",value.toObject()).toString();

                    /*****************************
                    * @brief:Upload
                    ******************************/
                    p_Parameter->Ftp=getJsonValue("Upload","Ftp",value.toObject()).toInt();
                    p_Parameter->FtpAddress= getJsonValue("Upload","FtpAddress",value.toObject()).toString();
                    p_Parameter->FtpLocalPath= getJsonValue("Upload","FtpLocalPath",value.toObject()).toString();
                    p_Parameter->FtpPassword= getJsonValue("Upload","FtpPassword",value.toObject()).toString();
                    p_Parameter->FtpPort= getJsonValue("Upload","FtpPort",value.toObject()).toString();
                    p_Parameter->FtpRemotePath= getJsonValue("Upload","FtpRemotePath",value.toObject()).toString();
                    p_Parameter->FtpUser= getJsonValue("Upload","FtpUser",value.toObject()).toString();
                    p_Parameter->ReduceImage=getJsonValue("Upload","ReduceImage",value.toObject()).toInt();

                    /*****************************
                    * @brief:Other
                    ******************************/
                    p_Parameter->Language= getJsonValue("Other","Language",value.toObject()).toInt();
                    p_Parameter->Minimization= getJsonValue("Other","Minimization",value.toObject()).toInt();
                    p_Parameter->Automatic=getJsonValue("Other","Automatic",value.toObject()).toInt();
                    p_Parameter->InfoLog= getJsonValue("Other","InfoLog",value.toObject()).toInt();
                    p_Parameter->DebugLog= getJsonValue("Other","DebugLog",value.toObject()).toInt();

                    /*****************************
                    * @brief:Recognizer
                    ******************************/
                    p_Parameter->ResultsTheCheck=getJsonValue("Recognizer","ResultsTheCheck",value.toObject()).toInt();

                    /*****************************
                    * @brief:Service
                    ******************************/
                    p_Parameter->ServiceModel=getJsonValue("Service","ServiceModel",value.toObject()).toInt();
                    p_Parameter->Service_Type=getJsonValue("Service","Service_Type",value.toObject()).toInt();
                    p_Parameter->SingletonAddress=getJsonValue("Service","SingletonAddress",value.toObject()).toString();
                    p_Parameter->ManyCasesAddress=getJsonValue("Service","ManyCasesAddress",value.toObject()).toString();
                    p_Parameter->Heartbeat=getJsonValue("Service","Heartbeat",value.toObject()).toInt();
                    p_Parameter->Resultting=getJsonValue("Service","Resultting",value.toObject()).toInt();

                    return true;
                }
            }
        }
    }
    else {
        emit messageSignal(ZBY_LOG("ERROR"),tr("Load System.json error<errorCode=%1>").arg(jsonError.errorString()));
    }
    return false;
}

bool System_Setting_Form::writeParameter()
{
    if(!configurationFolder.open(QIODevice::WriteOnly)){
        emit messageSignal(ZBY_LOG("ERROR"),tr("Failed to load the parameter,create the default parameter error<errorCode=%1>").arg(configurationFolder.OpenError));
        return false;
    }

    QJsonDocument jsonDoc;
    QJsonObject jsonChild,jsonRoot;

    /*****************************
    * @brief:Channel
    ******************************/
    QJsonObject obj1;
    obj1.insert("channelNumber?",tr("?Set the software to control the number of channels"));
    obj1.insert("channelNumber",ui->ChannelNumber->value());
    obj1.insert("ImageFormat?",tr("?Format the image save path"));
    obj1.insert("ImageFormat",ui->ImageFormat->currentIndex());
    obj1.insert("ImagePath?",tr("?Set the image to save the root directory"));
    obj1.insert("ImagePath",ui->ImgPathlineEdit->text());
    obj1.insert("ImageNamingRules?",tr("?Save image naming conventions"));
    obj1.insert("ImageNamingRules",(int)ui->ImageNamingRules->currentIndex());
    jsonChild.insert("Channel",QJsonValue(obj1));

    /*****************************
    * @brief:Recognizer
    ******************************/
    QJsonObject obj2;
    if(ui->ColorDisplay->isChecked()){
        obj2.insert("ResultsTheCheck?",tr("?Identify validation rules for results"));
        obj2.insert("ResultsTheCheck",0);       
    }
    else if (ui->AutomaticCorrection->isChecked()) {
        obj2.insert("ResultsTheCheck?",tr("?Identify validation rules for results"));
        obj2.insert("ResultsTheCheck",1);
    }
    jsonChild.insert("Recognizer",QJsonValue(obj2));

    /*****************************
    * @brief:Upload
    ******************************/
    QJsonObject obj3;
    obj3.insert("Ftp?",tr("?Whether to upload pictures or not"));
    obj3.insert("Ftp",(int)ui->Ftp->isChecked());
    obj3.insert("FtpUser?",tr("?Upload image username"));
    obj3.insert("FtpUser",ui->FtpUser->text());
    obj3.insert("FtpPassword?",tr("?Upload image user password"));
    obj3.insert("FtpPassword",ui->FtpPassword->text());
    obj3.insert("FtpAddress?",tr("?Upload picture address"));
    obj3.insert("FtpAddress",ui->FtpAddress->text());
    obj3.insert("FtpPort?",tr("?Upload image port"));
    obj3.insert("FtpPort",ui->FtpPort->text());
    obj3.insert("FtpRemotePath?",tr("?Upload picture server directory"));
    obj3.insert("FtpRemotePath",ui->FtpRemote->text());
    obj3.insert("FtpLocalPath?",tr("?Upload picture native directory"));
    obj3.insert("FtpLocalPath",ui->FtpLocal->text());
    obj3.insert("ReduceImage?",tr("?Whether to zoom out the uploaded image"));
    obj3.insert("ReduceImage",(int)ui->ReduceImage->isChecked());
    jsonChild.insert("Upload",QJsonValue(obj3));

    /*****************************
    * @brief:Service
    ******************************/
    QJsonObject obj4;
    if(ui->ClientModel->isChecked()){
        obj4.insert("ServiceModel?",tr("?TCP data transfer mode"));
        obj4.insert("ServiceModel",0);
    }
    if(ui->ServerModel->isChecked()){
        obj4.insert("ServiceModel?",tr("?TCP data transfer mode"));
        obj4.insert("ServiceModel",1);
    }
    obj4.insert("Service_Type?",tr("?TCP data transfer type"));
    obj4.insert("Service_Type",ui->Service_Type_comboBox->currentIndex());
    obj4.insert("SingletonAddress?",tr("?Single TCP mode address"));
    obj4.insert("SingletonAddress",ui->Address_Singleton_lineEdit->text());
    obj4.insert("ManyCasesAddress?",tr("?Multitcp mode address group"));
    obj4.insert("ManyCasesAddress",ui->Address_Many_textEdit->toPlainText());
    obj4.insert("Heartbeat?",tr("?Whether to send heartbeat packets"));
    obj4.insert("Heartbeat",int(ui->Hearbeat_checkBox->isChecked()));
    obj4.insert("Resultting?",tr("?Whether to send only result sets"));
    obj4.insert("Resultting",int(ui->Resulting_checkBox->isChecked()));
    jsonChild.insert("Service",QJsonValue(obj4));

    /*****************************
    * @brief:Other
    ******************************/
    QJsonObject obj5;
    obj5.insert("InfoLog?",tr("?Whether to keep running logs"));
    obj5.insert("InfoLog",int(ui->InfoLog->isChecked()));
    obj5.insert("DebugLog?",tr("?Whether to maintain operation and maintenance log"));
    obj5.insert("DebugLog",int(ui->DebugLog->isChecked()));
    obj5.insert("Minimization?",tr("?Startup minimization"));
    obj5.insert("Minimization",int(ui->StartupMinimization->isChecked()));
    obj5.insert("Language?", tr("?Language version"));
    obj5.insert("Language", ui->Language->currentIndex());
    obj5.insert("Automatic?",tr("?Automatic start"));
    obj5.insert("Automatic",int(ui->AutomaticStart->isChecked()));
    jsonChild.insert("Other",QJsonValue(obj5));

    jsonRoot.insert("Main",QJsonValue(jsonChild));
    jsonDoc.setObject(jsonRoot);

    /*****************************
    * @brief:写入日志
    ******************************/
    QByteArray arr=jsonDoc.toJson();
    int len=configurationFolder.write(arr);
    configurationFolder.waitForBytesWritten(1000);
    configurationFolder.close();

    if(len==-1){
        return false;
    }
    return true;
}

void System_Setting_Form::parameterToUi()
{
    if(p_Parameter->ChannelNumber>ui->ChannelNumber->maximum()){/* 防止后台篡改通道数量 */
        p_Parameter->ChannelNumber=ui->ChannelNumber->maximum();
    }
    ui->ChannelNumber->setValue(p_Parameter->ChannelNumber);
    ui->ImageNamingRules->setCurrentIndex(p_Parameter->ImageNamingRules);
    ui->ImageFormat->setCurrentIndex(p_Parameter->ImageFormat);
    ui->ImgPathlineEdit->setText(p_Parameter->ImagePath);


    if(!p_Parameter->ResultsTheCheck){/* 颜色显示 */
        ui->ColorDisplay->setChecked(1);
    }
    else {/* 自动校验 */
        ui->AutomaticCorrection->setChecked(1);
    }


    if(!p_Parameter->ServiceModel){/* 客户端模式 */
        ui->ClientModel->setChecked(1);
    }
    else {/* 服务器模式 */
        ui->ServerModel->setChecked(1);
    }
    ui->Service_Type_comboBox->setCurrentIndex(p_Parameter->Service_Type);
    ui->Address_Singleton_lineEdit->setText(p_Parameter->SingletonAddress);
    ui->Address_Many_textEdit->setText(p_Parameter->ManyCasesAddress);
    ui->Hearbeat_checkBox->setChecked(p_Parameter->Heartbeat);
    ui->Resulting_checkBox->setChecked(p_Parameter->Resultting);



    ui->Ftp->setChecked(p_Parameter->Ftp);
    ui->FtpAddress->setText(p_Parameter->FtpAddress);
    ui->FtpPort->setText(p_Parameter->FtpPort);
    ui->FtpUser->setText(p_Parameter->FtpUser);
    ui->FtpPassword->setText(p_Parameter->FtpPassword);
    ui->FtpLocal->setText(p_Parameter->FtpLocalPath);
    ui->FtpRemote->setText(p_Parameter->FtpRemotePath);

    ui->StartupMinimization->setChecked(p_Parameter->Minimization);
    ui->Language->setCurrentIndex(p_Parameter->Language);
    ui->AutomaticStart->setChecked(p_Parameter->Automatic);
    ui->InfoLog->setChecked(p_Parameter->InfoLog);
    ui->DebugLog->setChecked(p_Parameter->DebugLog);
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
    emit messageSignal(ZBY_LOG("ERROR"),tr("load SYSTEM.json value error:%1-%2").arg(child).arg(key));
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
                if(strList[var]==check){
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
                        stream<<strList.join("\n");
                        file.close();
                    }
                }
            }
            else {/* 删除项 */
                QMessageBox::StandardButton bt= QMessageBox::warning(this,check,tr("Whether to add the record=%1").arg(check),QMessageBox::Yes|QMessageBox::No);
                if(bt==QMessageBox::Yes){
                    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
                        strList.append(tr("%1").arg(check));
                        stream<<strList.join("\n");
                        file.close();
                    }
                }
            }
        }
    }
}
