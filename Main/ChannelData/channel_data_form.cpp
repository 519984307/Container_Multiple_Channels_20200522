#include "channel_data_form.h"
#include "ui_channel_data_form.h"

#include "imagedialog.h"
#include "simulationdialog.h"

#include <QPointer>
#include <QDebug>
#include <QDateTime>

Channel_Data_Form::Channel_Data_Form(QString alias, int channelNumber, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Channel_Data_Form)
{
    /*****************************
    * @brief:channelNumber有可能重复，后续添加逻辑判断
    ******************************/
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose,true);
    this->setParent(parent);
    this->setVisible(false);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    ui->image_label_1->installEventFilter(this);
    ui->image_label_2->installEventFilter(this);
    ui->image_label_3->installEventFilter(this);
    ui->image_label_4->installEventFilter(this);
    ui->image_label_5->installEventFilter(this);
    ui->image_label_6->installEventFilter(this);
    ui->image_label_7->installEventFilter(this);
    ui->image_label_8->installEventFilter(this);
    ui->image_label_9->installEventFilter(this);
    ui->image_label_10->installEventFilter(this);
    ui->image_label_11->installEventFilter(this);
    ui->image_label_12->installEventFilter(this);

    ui->image_label_7->setVisible(false);
    ui->image_label_8->setVisible(false);
    ui->image_label_9->setVisible(false);
    ui->image_label_10->setVisible(false);
    ui->image_label_11->setVisible(false);
    ui->image_label_12->setVisible(false);

    ui->alias_lineEdit->setText(alias);
    ui->channel_lineEdit->setText(QString::number(channelNumber));
    ui->toolBox->setCurrentIndex(0);

    /*****************************
    * @brief:绑定自定义红外信号触发槽
    ******************************/
    connect(ui->checkBox_1,&QCheckBox::clicked,this,&Channel_Data_Form::logicCheckBoxSlot);
    connect(ui->checkBox_2,&QCheckBox::clicked,this,&Channel_Data_Form::logicCheckBoxSlot);
    connect(ui->checkBox_3,&QCheckBox::clicked,this,&Channel_Data_Form::logicCheckBoxSlot);
    connect(ui->checkBox_4,&QCheckBox::clicked,this,&Channel_Data_Form::logicCheckBoxSlot);

    /*****************************
    * @brief:红外状态检测，1秒运行一次
    ******************************/
    logicStateTimer=new QTimer(this);
    connect(logicStateTimer,SIGNAL(timeout()),this,SLOT(logicStateSlot()));

    /*****************************
    * @brief:超时发送数据只运行一次
    ******************************/
    sendDataOutTimer=new QTimer(this);
    sendDataOutTimer->setSingleShot(true);
    connect(sendDataOutTimer,SIGNAL(timeout()),this,SLOT(timeOutSendData()));

    foreach (QCheckBox* obj, ui->toolBox->findChildren<QCheckBox*>(QString(),Qt::FindChildrenRecursively)) {
        /*****************************
        * @brief:ChcekBox禁止手动勾选
        ******************************/
        obj->setAttribute(Qt::WA_TransparentForMouseEvents);
        obj->setFocusPolicy(Qt::NoFocus);
        obj->setStyleSheet("color: rgb(211, 0, 0);");
    }

    connect(this,&Channel_Data_Form::signal_pictureStream,this,&Channel_Data_Form::slot_pictureStream);

    this->channelNumber=channelNumber;

    isConCar=false;
    isCar=false;
    isWaitCon=false;
    isCapSucess=false;

    simulationConStatus=false;
    simulationPlateStatus=false;
    simulationdialog=false;

    logicStatus=false;
    fron_45G1=false;
    front_22G1=false;
    fron_22G1_22G1=false;

    QVector<QString> picture_size;
    picture_size<<"1280*720"<<"1920*1080"<<"768*576";
    QStringList picture_size_tmp=picture_size.at(Parameter::picture_size).split("*");
    picture_w = picture_size_tmp.at(0).toUInt();
    picture_h = picture_size_tmp.at(1).toInt();
}

Channel_Data_Form::~Channel_Data_Form()
{
    if(logicStateTimer!=nullptr){
        logicStateTimer->stop();
    }

    if(sendDataOutTimer!=nullptr){
         sendDataOutTimer->stop();
    }

    watcher->waitForFinished();

    //LogicStateTmpList.clear();
    streamMap.clear();
    signatureList.clear();
    imgNameMap.clear();

    plateStream.clear();

    delete ui;
}

void Channel_Data_Form::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}

bool Channel_Data_Form::eventFilter(QObject *target, QEvent *event)
{
    /*****************************
    * @brief:双击放大图片
    ******************************/
    int key=0;
    if(target==ui->image_label_1){
        key=1;
    }
    else if (target==ui->image_label_2) {
        key=2;
    }
    else if (target==ui->image_label_3) {
        key=3;
    }
    else if (target==ui->image_label_4) {
        key=4;
    }
    else if (target==ui->image_label_5) {
        key=5;
    }
    else if (target==ui->image_label_6) {
        key=6;
    }
    else if (target==ui->image_label_7) {
        key=7;
    }
    else if (target==ui->image_label_8) {
        key=8;
    }
    else if (target==ui->image_label_9) {
        key=9;
    }
    else if (target==ui->image_label_10) {
        key=10;
    }
    else if (target==ui->image_label_11) {
        key=11;
    }
    else if (target==ui->image_label_12) {
        /*****************************
        * @brief:处理其他信息
        ******************************/
    }
    if(event->type()==QEvent::MouseButtonDblClick){
        if(nullptr != streamMap.value(key,nullptr)){
            QPointer<ImageDialog> Dlg=new ImageDialog(this);
            connect(this,SIGNAL(signal_enlargeImages(QByteArray)),Dlg,SLOT(slot_enlargeImages(QByteArray)));
            emit signal_enlargeImages(streamMap.value(key,nullptr));
            Dlg->exec();
        }
        else if(nullptr != plateStream.value(key,nullptr)){
            QPointer<ImageDialog> Dlg=new ImageDialog(this);
            connect(this,SIGNAL(signal_enlargeImages(QByteArray)),Dlg,SLOT(slot_enlargeImages(QByteArray)));
            emit signal_enlargeImages(plateStream.value(key,nullptr));
            Dlg->exec();
        }
    }
    if(event->type()==QEvent::Resize){
        if(nullptr != streamMap.value(key,nullptr)){
            slot_pictureStream(streamMap.value(key,nullptr),key,imgTimer);
        }
        else if(nullptr !=plateStream.value(key,nullptr)){
            slot_pictureStream(plateStream.value(key,nullptr),key,imgTimer);
        }
    }
    return  QWidget::eventFilter(target,event);
}

void Channel_Data_Form::loadParamter(int channelID,ChannelParameter *para)
{
    this->channelID=channelID;
    this->para=para;

    ui->plateCheckBox->setChecked(para->PlatePageState);
    ui->prospectsCheckBox->setChecked(para->ProspectsPageState);
    ui->foregroundCheckBox->setChecked(para->ForegroundPageState);
    ui->topCheckBox->setChecked(para->TopPageState);

    watcher=new QFutureWatcher<void>(this);
    /*****************************
    * @brief:初始化数据库
    ******************************/
    emit signal_initDataBase(QString::number(channelID),Parameter::databaseUser,Parameter::databasePass,Parameter::databaseAddr,Parameter::DatabaseType);
}

void Channel_Data_Form::clearnPixmap(int type)
{
    QPalette palette;

    switch (type) {
    /*****************************
    * @brief:车牌清除箱号
    ******************************/
    case -1:
    {
        streamMap.clear();
        imgTimerAf.clear();

        /*****************************
        * @brief:清除车牌
        ******************************/
        if(localPlateTime.isEmpty()){
            plateStream.clear();
            ui->image_label_7->setPalette(palette);

            emit signal_clean_plate_con_test(channelID,1);
        }
        emit signal_clean_plate_con_test(channelID,0);

        ui->image_label_1->setPalette(palette);
        ui->image_label_2->setPalette(palette);
        ui->image_label_3->setPalette(palette);
        ui->image_label_4->setPalette(palette);
        ui->image_label_5->setPalette(palette);
        ui->image_label_6->setPalette(palette);
        ui->image_label_8->setPalette(palette);
        ui->image_label_9->setPalette(palette);
        ui->image_label_10->setPalette(palette);
        ui->image_label_11->setPalette(palette);
        ui->image_label_12->setPalette(palette);
    }
        break;
    /*****************************
    * @brief:箱号清除车牌
    ******************************/
    case 0:
    {
        plateStream.clear();
        localPlate.clear();
        localPlateTime.clear();
        localPlateColor.clear();

        ui->image_label_7->setPalette(palette);

        emit signal_clean_plate_con_test(channelID,1);
    }
        break;
    }

    if(1 != type){
        foreach (QLineEdit* obj, ui->toolBox->findChildren<QLineEdit*>(QString(),Qt::FindChildrenRecursively)) {
            if(obj==ui->alias_lineEdit || obj==ui->channel_lineEdit){
                /*****************************
                * @brief:车牌和固定信息不清除
                ******************************/
                continue;
            }
            /*****************************
            * @brief:车牌清除箱号
            ******************************/
            if(-1==type && (obj==ui->plate_lineEdit || obj==ui->plate_color_lineEdit || obj==ui->plate_time_lineEdit)){
                continue;
            }
            /*****************************
            * @brief:箱号清除车牌
            ******************************/
            if(0==type && (obj==ui->time_lineEdit || obj==ui->con_after_lineEdit || obj==ui->con_brfore_lineEdit || obj==ui->iso_after_lineEdit || obj==ui->iso_before_lineEdit || obj==ui->box_type_lineEdit)){
                continue;
            }
            obj->setText("");
            obj->clear();
            obj->setStyleSheet("background-color: rgb(255, 255, 255);color: rgb(0, 0, 0);");
        }
    }
}

void Channel_Data_Form::on_SimulationPushButton_clicked()
{
    if(simulationdialog){
        return;
    }

    QPointer<SimulationDialog> Dlg=new SimulationDialog(channelNumber,this);
    Dlg->setWindowTitle(QString("SimulationDialog[%1]").arg(QString::number(channelNumber)));
    connect(Dlg,&SimulationDialog::signal_logicPutImage,this,&Channel_Data_Form::slot_logicPutImage);
    connect(Dlg,&SimulationDialog::sendResultSignal,this,&Channel_Data_Form::sendResultSignal);
    connect(this,&Channel_Data_Form::signal_container,Dlg,&SimulationDialog::slot_container);

    connect(this,&Channel_Data_Form::signal_plate,Dlg,&SimulationDialog::slot_plate);
    connect(Dlg,&SimulationDialog::signal_simulationCapture,this,&Channel_Data_Form::signal_simulationCapture);
    connect(Dlg,&SimulationDialog::signal_liftingElectronicRailing,this,&Channel_Data_Form::signal_liftingElectronicRailing);
    connect(Dlg,&SimulationDialog::signal_transparentTransmission485,this,&Channel_Data_Form::signal_transparentTransmission485);
    connect(Dlg,&SimulationDialog::signal_plateResult,this,&Channel_Data_Form::signal_plateResult);

    connect(Dlg,&SimulationDialog::signal_dialogCloseState,this,&Channel_Data_Form::slot_simulationCloseState);

    connect(Dlg,&SimulationDialog::signal_setSimulationStatus,this,&Channel_Data_Form::slot_setSimulationStatus);

    Dlg->show();

    simulationdialog=true;
}

void Channel_Data_Form::saveImages(QMap<int, QByteArray> stream, QString datetime, QString type)
{
    QMutexLocker locket(&mutex);
    if(Parameter::ImagePath.isEmpty()){
        Parameter::ImagePath=QString("C:\\images");
    }

    /*****************************
    * @brief:本地FTP服务端创建文件夹，远端需另行处理
    ******************************/
//    if(Parameter::Ftp){
//        QDir dir(Parameter::FtpLocalPath);
//        dir.mkpath(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
//    }

    QString suffixPath;

    switch (Parameter::ImageFormat) {
    case 0:
        suffixPath=QDir::toNativeSeparators(QString("%1/%2").arg(channelNumber).arg(QDateTime::currentDateTime().toString("yyyy/MM/dd")));
        break;
    case 1:
        suffixPath=QDir::toNativeSeparators(QString("%1/%2").arg(channelNumber).arg(QDateTime::currentDateTime().toString("yyyy/MM")));
        break;
    case 2:
        suffixPath=QDir::toNativeSeparators(QString("%1/%2").arg(channelNumber).arg(QDateTime::currentDateTime().toString("yyyy")));
        break;
    case 3:
        suffixPath=QDir::toNativeSeparators(QString("%1").arg(channelNumber));
        break;
    case 4:
        suffixPath=QDir::toNativeSeparators(QString("%1").arg(QDateTime::currentDateTime().toString("yyyy/MM/dd")));
        break;
    case 5:
        suffixPath=QDir::toNativeSeparators(QString("%1").arg(QDateTime::currentDateTime().toString("yyyy/MM")));
        break;
    case 6:
        suffixPath=QDir::toNativeSeparators(QString("%1").arg(QDateTime::currentDateTime().toString("yyyy")));
        break;
    case 7:
        suffixPath=QDir::toNativeSeparators(QString("./"));
        break;
    }

    QDir dir(Parameter::ImagePath);
    dir.mkpath(suffixPath);
    dir.cd(suffixPath);

    ///
    /// \brief databaseMap 插入数据库
    ///
    QMap<QString, QString> databaseMap;

    ///
    /// \brief imgMap 图片集，送入识别器
    ///
    QMap<int , QString> imgMap;

    foreach (auto key, stream.keys()) {
        QString imgName="";
        switch (Parameter::ImageNamingRules) {
        case 0:
            imgName=QString("%1%2%3.jpg").arg(datetime).arg(channelNumber,Parameter::channel_id_placeholder,10,QLatin1Char('0')).arg(key,Parameter::camera_id_placeholder,10,QLatin1Char('0'));
            break;
        case 1:
            imgName=QString("%1%2%3.jpg").arg(datetime).arg(key,Parameter::camera_id_placeholder,10,QLatin1Char('0')).arg(channelNumber,Parameter::channel_id_placeholder,10,QLatin1Char('0'));
            break;
        }
        QString imgPath=QDir::toNativeSeparators(QString("%1/%2").arg(dir.path()).arg(imgName));

        if(nullptr == stream.value(key,nullptr) && 7 != key){
            slot_recognitionResult("RESULT: ||0|0",imgPath,key);
            continue;
        }

        QScopedPointer<QPixmap> pix(new QPixmap());
        pix.data()->loadFromData(stream.value(key));

        if(false == pix.data()->scaled(picture_w,picture_h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation).save(imgPath)){
            if(7 != key){
                slot_recognitionResult("RESULT: ||0|0",imgPath,key);
            }
            continue;
        }
        else {
            if(7 != key){
                //emit signal_identifyImages(imgPath,key);
                imgMap.insert(key,imgPath);
            }
            if(Parameter::Ftp){
                /*****************************
                * @brief:上传图片
                ******************************/
                if(Parameter::upload_images.indexOf(QString::number(key))!=-1){
                    emit signal_uploadData(imgPath);
                }
            }
        }

        /*****************************
        * @brief:图片写入数据库
        ******************************/

        switch (key) {
        case 1:
            databaseMap.insert("ImgFront",imgName);
            break;
        case 2:
            databaseMap.insert("ImgLeftFront",imgName);
            break;
        case 3:
            databaseMap.insert("ImgRightFront",imgName);
            break;
        case 4:
            databaseMap.insert("ImgLeftAfter",imgName);
            break;
        case 5:
            databaseMap.insert("ImgRightAfter",imgName);
            break;
        case 6:
            databaseMap.insert("ImgAfter",imgName);
            break;
        case 7:
            databaseMap.insert("PlateImg",imgName);
            break;
        case 8:
            databaseMap.insert("ImgProspects",imgName);
            break;
        case 9:
            databaseMap.insert("ImgForeground",imgName);
            break;
        }
    }

    /*****************************
    * @brief:送入识别器
    ******************************/
//    if(imgMap.size()>0){
//        emit signal_identifyImages(imgMap);
//    }
//    imgMap.clear();
    emit signal_identifyImages(imgMap);

    /*****************************
    * @brief:先箱号后车牌，需要更新车牌数据，要使用箱号时间戳和通道号
    ******************************/
    if(stream.size()>=2 || type=="U"){
        /*****************************
        * @brief:插入箱号数据库到数据库
        ******************************/
        databaseMap.insert("Timer",QDateTime::fromString(datetime,"yyyyMMddhhmmss").toString("yyyy/MM/dd hh:mm:ss"));        
    }
    else {
        /*****************************
        * @brief:插入车牌数据到数据库
        *
        ******************************/
        /*****************************
        * @brief:修改-cc
        * 20211021 - databaseMap.insert("Timer",QString("%1").arg(QDateTime::fromString(localPlateTime,"yyyyMMddhhmmss").toString("yyyy/MM/dd hh:mm:ss")));
        ******************************/
        databaseMap.insert("Timer",QString("%1").arg(QDateTime::fromString(datetime,"yyyyMMddhhmmss").toString("yyyy/MM/dd hh:mm:ss")));
        databaseMap.insert("Type",QString::number(-1));
    }

    if(!localPlateTime.isEmpty()){
        databaseMap.insert("PlateTimer",QString("%1").arg(QDateTime::fromString(localPlateTime,"yyyyMMddhhmmss").toString("yyyy/MM/dd hh:mm:ss")));
        databaseMap.insert("Plate",localPlate);
        databaseMap.insert("plateColor",localPlateColor);
    }

    databaseMap.insert("Channel",QString::number(channelNumber));

    if(type=="I"){
         emit signal_insertDataBase(databaseMap);
    }
    else if (type=="U") {
        emit signal_updateDataBase(databaseMap);
    }

    if(!sendDataOutTimer->isActive() && !isWaitCon){
        localPlateTime.clear();
        localPlate.clear();
        localPlateColor.clear();
    }
}

void Channel_Data_Form::slot_pictureStream(const QByteArray &jpgStream, const int &imgNumber, const QString &imgTime)
{
    if(imgNumber==0){
        return;
    }   

    if(imgTime!=this->imgTimerAf){
         streamMap.clear();
         imgNameMap.clear();
    }

    this->imgTimerAf=imgTime;

    if(imgNumber!=7){
        streamMap.insert(imgNumber,jpgStream);
    }

    /*****************************
    * @brief:图片数量
    ******************************/
    int imgCount=putCount;

    if(-1!=putCount && streamMap.size()>=imgCount && watcher->isFinished()){

        QFuture<void> future  =QtConcurrent::run(this,&Channel_Data_Form::saveImages,streamMap,imgTime,QString("I"));
        watcher->setFuture(future);
        putCount=-1;
    }

    QScopedPointer<QPixmap> pix(new QPixmap());
    if(jpgStream!=nullptr){
        pix->loadFromData(jpgStream);
    }
    else {
        return;
    }

    QPalette palette;

    switch (imgNumber) {
    case 1:
    {
        palette.setBrush(QPalette::Background, QBrush(pix.data()->scaled(ui->image_label_1->size(), Qt::IgnoreAspectRatio)));
        ui->image_label_1->setPalette(palette);
    }
        break;
    case 2:
    {
        palette.setBrush(QPalette::Background, QBrush(pix.data()->scaled(ui->image_label_2->size(), Qt::IgnoreAspectRatio)));
        ui->image_label_2->setPalette(palette);
    }
        break;
    case 3:
    {
        palette.setBrush(QPalette::Background, QBrush(pix.data()->scaled(ui->image_label_3->size(), Qt::IgnoreAspectRatio)));
        ui->image_label_3->setPalette(palette);
    }
        break;
    case 4:
    {
        palette.setBrush(QPalette::Background, QBrush(pix.data()->scaled(ui->image_label_4->size(), Qt::IgnoreAspectRatio)));
        ui->image_label_4->setPalette(palette);
    }
        break;
    case 5:
    {
        palette.setBrush(QPalette::Background, QBrush(pix.data()->scaled(ui->image_label_5->size(), Qt::IgnoreAspectRatio)));
        ui->image_label_5->setPalette(palette);
    }
        break;
    case 6:
    {
        palette.setBrush(QPalette::Background, QBrush(pix.data()->scaled(ui->image_label_6->size(), Qt::IgnoreAspectRatio)));
        ui->image_label_6->setPalette(palette);
    }
        break;
    case 7:
    {
        palette.setBrush(QPalette::Background, QBrush(pix.data()->scaled(ui->image_label_7->size(), Qt::IgnoreAspectRatio)));
        ui->image_label_7->setPalette(palette);
    }
        break;
    case 8:
    {
        palette.setBrush(QPalette::Background, QBrush(pix.data()->scaled(ui->image_label_8->size(), Qt::IgnoreAspectRatio)));
        ui->image_label_8->setPalette(palette);
    }
        break;
    case 9:
    {
        palette.setBrush(QPalette::Background, QBrush(pix.data()->scaled(ui->image_label_9->size(), Qt::IgnoreAspectRatio)));
        ui->image_label_9->setPalette(palette);
    }
        break;
    case 10:
    {
        palette.setBrush(QPalette::Background, QBrush(pix.data()->scaled(ui->image_label_10->size(), Qt::IgnoreAspectRatio)));
        ui->image_label_10->setPalette(palette);
    }
        break;
    case 11:
    {
        palette.setBrush(QPalette::Background, QBrush(pix.data()->scaled(ui->image_label_11->size(), Qt::IgnoreAspectRatio)));
        ui->image_label_11->setPalette(palette);
    }
        break;
    case 12:
    {
        palette.setBrush(QPalette::Background, QBrush(pix.data()->scaled(ui->image_label_12->size(), Qt::IgnoreAspectRatio)));
        ui->image_label_12->setPalette(palette);
    }
        break;
    }
}

void Channel_Data_Form::logicStateSlot()
{
//    isConCar=false;

//    /*****************************
//    * @brief:第一次没有检测道红外状态，默认初始化一次,下次循环再判断。
//    ******************************/
//    if(LogicStateTmpList.size()==0){
//        LogicStateTmpList<<ui->a1checkBox->checkState()<<ui->a2checkBox->checkState()<<ui->b1checkBox->checkState()<<ui->b2checkBox->checkState();
//        return;
//    }

//    /*****************************
//    * @brief:记录红外状态,判断是否为集装箱车辆
//    ******************************/
//    QVector<int> tmpStatusList;
//    tmpStatusList<<ui->a1checkBox->checkState()<<ui->a2checkBox->checkState()<<ui->b1checkBox->checkState()<<ui->b2checkBox->checkState();
//    for (int var = 0; var < tmpStatusList.count(); ++var) {
//        if(LogicStateTmpList[var]!=tmpStatusList[var]){
//            isConCar=true;
//        }
//    }

//    tmpStatusList.clear();

    /*****************************
    * @brief:20220602 16:37
    * 2，3组红外状态（2，3组红外间距），判断是否带箱
    ******************************/

    if(para->infraredStatus){
        /*****************************
        * @brief:红外常闭模式
        ******************************/
        if(ui->a2checkBox->checkState()==Qt::Unchecked && ui->b1checkBox->checkState()==Qt::Unchecked){
            isConCar=true;
        }
    }
    else {
        /*****************************
        * @brief:红外常开模式
        ******************************/
        if(ui->a2checkBox->checkState()==Qt::Checked && ui->b1checkBox->checkState()==Qt::Checked){
            isConCar=true;
        }
    }

    if(isConCar || simulationConStatus){
        isWaitCon=true;
        isCar=false;

        logicStateTimer->stop();
        /*****************************
        * @brief:检测到箱体，不再超时，永久等待箱号
        ******************************/
        sendDataOutTimer->stop();
        //LogicStateTmpList.clear();
    }
}

void Channel_Data_Form::timeOutSendData()
{
    logicStateTimer->stop();
    //LogicStateTmpList.clear();

    emit signal_waitSendData();
    qDebug().noquote()<<"Logical data receive timeout, send data-+";
}

void Channel_Data_Form::logicCheckBoxSlot()
{
    /* putCommnd
     * -1:来车
     *0:45G1前面
     *1:45G1后面
     *2:22G1
     *3:双22G1前面
     *4:双22G1后面
    */

    /*****************************
    * @brief:前置条件
    ******************************/
    if(ui->checkBox_1->isChecked() && ui->checkBox_2->isChecked() && ui->checkBox_3->isChecked() && ui->checkBox_4->isChecked()){
        logicStatus=true;

        front_22G1=false;
        fron_45G1=false;
        fron_22G1_22G1=false;
    }
    if(logicStatus){
        /*****************************
        * @brief:45前
        ******************************/
        if(!fron_22G1_22G1 && ui->checkBox_1->checkState()==Qt::Unchecked && ui->checkBox_2->checkState()==Qt::Unchecked && ui->checkBox_3->checkState()==Qt::Unchecked && ui->checkBox_4->checkState()==Qt::Unchecked){
            slot_logicPutImage(-1);
            slot_logicPutImage(0);
            fron_45G1=true;
            front_22G1=false;
        }
        /*****************************
        * @brief:45后
        ******************************/
        if(fron_45G1 && ui->checkBox_1->checkState()==Qt::Checked && ui->checkBox_2->checkState()==Qt::Checked && ui->checkBox_3->checkState()==Qt::Unchecked && ui->checkBox_4->checkState()==Qt::Unchecked){
            slot_logicPutImage(1);
            fron_45G1=false;
            logicStatus=false;
        }
        /*****************************
        * @brief:22前
        ******************************/
        if(ui->checkBox_1->checkState()==Qt::Unchecked && ui->checkBox_2->checkState()==Qt::Unchecked && ui->checkBox_3->checkState()==Qt::Unchecked && ui->checkBox_4->checkState()==Qt::Checked){
            slot_logicPutImage(-1);
            front_22G1=true;
        }
        /*****************************
        * @brief:22后
        ******************************/
        if(front_22G1 && ui->checkBox_1->checkState()==Qt::Checked && ui->checkBox_2->checkState()==Qt::Checked && ui->checkBox_3->checkState()==Qt::Unchecked && ui->checkBox_4->checkState()==Qt::Unchecked){
            slot_logicPutImage(2);
            front_22G1=false;
            logicStatus=false;
        }
        /*****************************
        * @brief:双22前置条件
        ******************************/
        if(fron_45G1 && ui->checkBox_1->checkState()==Qt::Unchecked && ui->checkBox_2->checkState()==Qt::Unchecked && ui->checkBox_3->checkState()==Qt::Checked && ui->checkBox_4->checkState()==Qt::Unchecked){
            fron_45G1=false;
            fron_22G1_22G1=true;
        }
        /*****************************
        * @brief:双22前置条件
        ******************************/
        if(fron_45G1 && ui->checkBox_1->checkState()==Qt::Unchecked && ui->checkBox_2->checkState()==Qt::Checked && ui->checkBox_3->checkState()==Qt::Unchecked && ui->checkBox_4->checkState()==Qt::Unchecked){
            fron_45G1=false;
            fron_22G1_22G1=true;
        }
        /*****************************
        * @brief:双22前
        ******************************/
        if(fron_22G1_22G1 && ui->checkBox_1->checkState()==Qt::Unchecked && ui->checkBox_2->checkState()==Qt::Unchecked && ui->checkBox_3->checkState()==Qt::Unchecked && ui->checkBox_4->checkState()==Qt::Unchecked){
            slot_logicPutImage(-1);
            slot_logicPutImage(0);
        }
        /*****************************
        * @brief:双22后
        ******************************/
        if(fron_22G1_22G1 && ui->checkBox_1->checkState()==Qt::Checked && ui->checkBox_2->checkState()==Qt::Checked && ui->checkBox_3->checkState()==Qt::Unchecked && ui->checkBox_4->checkState()==Qt::Unchecked){
            slot_logicPutImage(4);
            fron_22G1_22G1=false;
            logicStatus=false;
        }
    }
}

void Channel_Data_Form::slot_camerState(const QString &camerIP, bool state)
{
    if(nullptr==this->para){
        return;
    }

    if(camerIP==para->FrontCamer){
        ui->frontCheckBox->setChecked(state);
        if(state){
            ui->frontCheckBox->setStyleSheet("color: rgb(0, 211, 0);");
        }
        else {
            ui->frontCheckBox->setStyleSheet("color: rgb(211, 0, 0);");
        }
        emit signal_setDeviceStatus(channelID,LocalPar::Front,state);
    }
    if (camerIP==para->AfterCamer) {
        ui->beforeCheckBox->setChecked(state);
        if(state){
            ui->beforeCheckBox->setStyleSheet("color: rgb(0, 211, 0);");
        }
        else {
            ui->beforeCheckBox->setStyleSheet("color: rgb(211, 0, 0);");
        }
        emit signal_setDeviceStatus(channelID,LocalPar::Before,state);
    }
    if (camerIP==para->LeftCamer) {
        ui->leftCheckBox->setChecked(state);
        if(state){
            ui->leftCheckBox->setStyleSheet("color: rgb(0, 211, 0);");
        }
        else {
            ui->leftCheckBox->setStyleSheet("color: rgb(211, 0, 0);");
        }
        emit signal_setDeviceStatus(channelID,LocalPar::Left,state);
    }
    if (camerIP==para->RgihtCamer) {
        ui->rightCheckBox->setChecked(state);
        if(state){
            ui->rightCheckBox->setStyleSheet("color: rgb(0, 211, 0);");
        }
        else {
            ui->rightCheckBox->setStyleSheet("color: rgb(211, 0, 0);");
        }
        emit signal_setDeviceStatus(channelID,LocalPar::Right,state);
    }
    if (camerIP==para->PlateCamer) {
        ui->platestateCheckBox->setChecked(state);
        if(state){
            ui->platestateCheckBox->setStyleSheet("color: rgb(0, 211, 0);");
        }
        else {
            ui->platestateCheckBox->setStyleSheet("color: rgb(211, 0, 0);");
        }
        emit signal_setDeviceStatus(channelID,LocalPar::Plate,state);
    }
    if (camerIP==para->TopCamer) {
        ui->topstateCheckBox->setChecked(state);
        if(state){
            ui->topstateCheckBox->setStyleSheet("color: rgb(0, 211, 0);");
        }
        else {
            ui->topstateCheckBox->setStyleSheet("color: rgb(211, 0, 0);");
        }
        emit signal_setDeviceStatus(channelID,LocalPar::Top,state);
    }
    if (camerIP==para->ForgroundCamer) {
        ui->forgroundstateCheckBox->setChecked(state);
        if(state){
            ui->forgroundstateCheckBox->setStyleSheet("color: rgb(0, 211, 0);");
        }
        else {
            ui->forgroundstateCheckBox->setStyleSheet("color: rgb(211, 0, 0);");
        }
        emit signal_setDeviceStatus(channelID,LocalPar::Foreground,state);
    }
    if (camerIP==para->ProspectsCamer) {
        ui->prospectsstateCheckBox->setChecked(state);
        if(state){
            ui->prospectsstateCheckBox->setStyleSheet("color: rgb(0, 211, 0);");
        }
        else {
            ui->prospectsstateCheckBox->setStyleSheet("color: rgb(211, 0, 0);");
        }
        emit signal_setDeviceStatus(channelID,LocalPar::Prospects,state);
    }
}

void Channel_Data_Form::slot_initEquipment()
{
    if(nullptr==this->para){
        return;
    }

    signatureList=LocalPar::CamerNameList;
    if(signatureList.size()>=7){
        /*****************************
        * @brief:相机
        ******************************/
        emit signal_initCamer_front(para->LocalAddr,para->FrontCamer,8000,para->UserCamer,para->PasswordCamer,signatureList.at(0));
        emit signal_initCamer_before(para->LocalAddr,para->AfterCamer,8000,para->UserCamer,para->PasswordCamer,signatureList.at(1));
        emit signal_initCamer_left(para->LocalAddr,para->LeftCamer,8000,para->UserCamer,para->PasswordCamer,signatureList.at(2));
        emit signal_initCamer_right(para->LocalAddr,para->RgihtCamer,8000,para->UserCamer,para->PasswordCamer,signatureList.at(3));
        emit signal_initCamer_top(para->LocalAddr,para->TopCamer,8000,para->UserCamer,para->PasswordCamer,signatureList.at(4));
        emit signal_initCamer_prospects(para->LocalAddr,para->ProspectsCamer,8000,para->UserCamer,para->PasswordCamer,signatureList.at(5));
        emit signal_initCamer_foreground(para->LocalAddr,para->ForgroundCamer,8000,para->UserCamer,para->PasswordCamer,signatureList.at(6));

        int port=0;
        if(Parameter::PlateType==0){
            port=8000;
        }
        else if (Parameter::PlateType==1) {
            port=8080;
        }
        else if (Parameter::PlateType==2) {
            port=8131;
        }
        emit signal_initCamer_plate(para->LocalAddr,para->PlateCamer,port,para->UserCamer,para->PasswordCamer,signatureList.at(7));
    }    

    /*****************************
    * @brief:红外(常开|常闭,标准|南京三宝，A1释放多久抓拍)
    ******************************/
    emit signal_setAlarmMode(para->infraredStatus,Parameter::LogicType,para->A1ReleasrCap);

    /*****************************
    * @brief:初始化网络控制器输出参数
    ******************************/
    Dout<<para->D1out<<para->D2out<<para->D3out<<para->D4out;
    emit signal_DTypeOut(Dout,-1);

    /*****************************
    * @brief:红外信号
    ******************************/
    switch (para->ControllerSignalMode) {
    case 0:
        /*****************************
        * @brief:串口模式
        ******************************/
        emit signal_startSlave(QString("COM%1").arg(para->SerialPortOne),QString("COM%1").arg(para->SerialPortTow),QString(""),-1,para->interfaceModel,para->Channel_number);
        break;
    case 1:
        /*****************************
        * @brief:moxa socket 客户端模式需要开启两个服务，分别接收两个串口数据
        ******************************/
        //emit signal_startSlave(QString(""),QString(""),QString(""),-1,-1,para->Channel_number);
        break;
    case 2:
        /*****************************
        * @brief:网络控制器
        ******************************/
        emit signal_startSlave(QString(""),QString(""),para->controllerAddr,para->controllerPort,para->interfaceModel,para->Channel_number);
        break;
    }

    /*****************************
    * @brief:数据库插入
    ******************************/
    emit signal_initDataBase(QString::number(channelID),Parameter::databaseUser,Parameter::databasePass,Parameter::databaseAddr,Parameter::DatabaseType);

    /*****************************
    * @brief:结果分析
    ******************************/
    emit signal_initReAnaParameter(channelNumber,Parameter::ImageNamingRules,Parameter::ResultsTheCheck,Parameter::Resultting,Parameter::Identify_Protocol);
}

void Channel_Data_Form::slot_pollsForCarStatus(int type)
{
    switch (type) {
    case -1:
    {
        /*****************************
        * @brief:清除数据逻辑定时器
        ******************************/
        logicStateTimer->stop();
        sendDataOutTimer->stop();

        /*****************************
        * @brief:不是集装箱车辆，车牌写入数据库
        ******************************/
        if(!isConCar){
            /*****************************
            * @brief:非集装箱车辆，清除前一辆箱号图片和信息。
            ******************************/
            clearnPixmap(-1);

            QFuture<void> future  =QtConcurrent::run(this,&Channel_Data_Form::saveImages,plateStream,localPlateTime,QString("I"));
            watcher->setFuture(future);
        }
        else {
            isConCar=false;
            isWaitCon=false;
            QFuture<void> future  =QtConcurrent::run(this,&Channel_Data_Form::saveImages,plateStream,imgTimer,QString("U"));
            watcher->setFuture(future);
        }

        isCar=false;
        isConCar=false;
        isWaitCon=false;                

        /*****************************
        * @brief:抓拍逻辑完成，倒车复位使用
        ******************************/
        isCapSucess=false;
    }
        break;
    case 0:
    {
        /*****************************
        * @brief:清除前一辆车牌图片和信息
        ******************************/
        clearnPixmap(0);

        /*****************************
        * @brief:收到箱号后，如果没有车牌信息就检查车牌相机状态。
        ******************************/
        isConCar=true;

        /*****************************
        * @brief:判断车牌，高车头，无集装箱检测使用
        ******************************/
        isCar=false;

        /*****************************
        * @brief:判断车牌相机是否登录成功
        ******************************/
        if(ui->platestateCheckBox->isChecked() || simulationPlateStatus){
            sendDataOutTimer->start(Parameter::plate_timeout*1000);
        }
        else {
            emit signal_waitSendData();
        }
    }
        break;
    case 1:
    {
        /*****************************
        * @brief:清除前一辆箱号图片和信息
        ******************************/
        if(!isConCar){
            clearnPixmap(-1);

            /*****************************
            * @brief:超时检测红外状态
            ******************************/
            logicStateTimer->start(1000);

            /*****************************
            * @brief:判断车牌，高车头，无集装箱检测使用
            ******************************/
            isCar=true;
        }
        else {
            isCar=false;
            isWaitCon=true;
        }

        /*****************************
        * @brief:超时发送数据。已完成部分抓拍，不超时处理
        ******************************/
        if(!isConCar){
            sendDataOutTimer->start(Parameter::container_timeout*1000);
            qDebug().noquote()<<QString("No container is detected, and the waiting time for the container expires. Procedure");
        }

        /*****************************
        * @brief:如果车牌装的靠前，箱号晚出，黄车车头
        ******************************/
        //sendDataOutTimer->start(Parameter::container_timeout*1000);
    }
        break;
    }
}

void Channel_Data_Form::slot_setSimulationStatus(bool con, bool plate)
{
    simulationConStatus=con;
    simulationPlateStatus=plate;
}

void Channel_Data_Form::slot_lifting()
{
    if(para->lifthingType==2){
        emit signal_DTypeOut(Dout,2);
    }
}

void Channel_Data_Form::slot_transparentTransmission485(const QString &msg)
{
    /*****************************
    * @brief:485传输临时信息：前缀，箱号和车牌，后缀
    ******************************/
    QString data=QString("%1,%2,%3").arg(this->para->Display_temp_prefix,msg,this->para->Display_temp_suffix);
    emit signal_transparentTransmission485(data);
}

void Channel_Data_Form::slot_bindingCameraID(QString cameraAddr, int ID)
{
    Q_UNUSED(cameraAddr);
    qDebug()<<para->Channel_number<<":"<<ID;
}

void Channel_Data_Form::slot_captureTest(int channelID, int cameraID)
{
    if(this->channelID==channelID){
        if("Plate"==signatureList.at(cameraID-1)){
            emit signal_simulationCapture();
        }
        else {
            emit signal_putCommand(0,"",signatureList.at(cameraID-1));
        }
    }
}

void Channel_Data_Form::slot_playStream(quint64 winID, bool play, int channelID, int cameraID)
{
    if(this->channelID==channelID){
        if("Plate"==signatureList.at(cameraID-1)){
            emit signal_openTheVideo(play,winID);
        }
        else {
            emit signal_playStream(winID,play,signatureList.at(cameraID-1));
        }
    }
}

void Channel_Data_Form::slot_logicStatus(int *status)
{
    /* A1.A2.B1.B2.D1.D2.D3.D4 */
    ui->a1checkBox->setChecked(status[0]);
    ui->a2checkBox->setChecked(status[1]);
    ui->b1checkBox->setChecked(status[2]);
    ui->b2checkBox->setChecked(status[3]);
    ui->d1checkBox->setChecked(status[4]);
    ui->d2checkBox->setChecked(status[5]);
    ui->d3checkBox->setChecked(status[6]);
    ui->d4checkBox->setChecked(status[7]);

    LocalPar::equipment=LocalPar::A1;
    for (int var = 0; var < 8; ++var) {
        emit signal_setDeviceStatus(channelID,LocalPar::equipment+var,status[var]);
    }

    /*****************************
    * @brief:行车中途退出，复位
    ******************************/
    if(isConCar && !isCapSucess){
        bool liife=false;
        if(para->infraredStatus==0 && !status[0] && !status[1] && !status[2] && !status[3]){
            liife=true;
        }
        if(para->infraredStatus==1 && status[0] && status[1] && status[2] && status[3]){
            liife=true;
        }

//        if( ui->checkBox_1->isChecked() && !ui->checkBox_2->isChecked() && !ui->checkBox_3->isChecked() && !ui->checkBox_4->isChecked()){
//            liife=true;
//        }

        if(liife){
            isCar=false;
            isConCar=false;
            isWaitCon=false;

            localPlateTime.clear();
            localPlate.clear();
            localPlateColor.clear();

            qDebug().noquote()<<QString("[%1] The vehicle leaves and the data is reset.").arg(this->metaObject()->className());
        }
    }
}

void Channel_Data_Form::slot_logicPutImage(const int &putCommnd)
{
    /* putCommnd
     * -1:来车
     *0:45G1前面
     *1:45G1后面
     *2:22G1
     *3:双22G1前面
     *4:双22G1后面
    */
    /*  Type,集装箱类别:
     * -1 – 未知
     * 0 – 一个 20 集装箱
     * 1 – 一个 40 吋/45 吋集装箱
     * 2 – 两个 20 吋集装箱
     */

    switch (putCommnd) {
    case -1:        
        clearnPixmap(-1);/* 通知来车,清除数据界面图片 */
        this->putCount=-1;
        this->putComType=-1;
        emit signal_channelState(channelID,1);

        isCapSucess=false;

        break;
    case 0:
    {
        imgTimer=QDateTime::currentDateTime().toString("yyyyMMddhhmmss");/* 来车时间 */
        emit signal_putCommand(1,imgTimer,signatureList.at(0));
        emit signal_putCommand(2,imgTimer,signatureList.at(2));
        emit signal_putCommand(3,imgTimer,signatureList.at(3));

        /*****************************
        * @brief:202112181611,6相机
        ******************************/
        QThread::msleep(100);
        emit signal_putCommand(8,imgTimer,signatureList.at(5));
        this->putCount=-1;
        this->putComType=-1;       
    }
        break;
    case 1:
    {
        emit signal_putCommand(4,imgTimer,signatureList.at(2));
        emit signal_putCommand(5,imgTimer,signatureList.at(3));
        emit signal_putCommand(6,imgTimer,signatureList.at(1));

        /*****************************
        * @brief:202112181611,6相机
        ******************************/
        QThread::msleep(100);
        emit signal_putCommand(9,imgTimer,signatureList.at(6));
        this->putCount=8;
        this->putComType=1;

        isCapSucess=true;
    }
        break;
    case 2:
    {
        imgTimer=QDateTime::currentDateTime().toString("yyyyMMddhhmmss");/* 来车时间 */
        emit signal_putCommand(1,imgTimer,signatureList.at(0));
        emit signal_putCommand(2,imgTimer,signatureList.at(2));
        emit signal_putCommand(3,imgTimer,signatureList.at(3));
        emit signal_putCommand(6,imgTimer,signatureList.at(1));

        /*****************************
        * @brief:202112181611,6相机
        ******************************/
        QThread::msleep(100);
        emit signal_putCommand(8,imgTimer,signatureList.at(5));
        emit signal_putCommand(9,imgTimer,signatureList.at(6));
        this->putCount=6;
        this->putComType=0;

        isCapSucess=true;
    }
        break;
    case 4:
    {
        emit signal_putCommand(4,imgTimer,signatureList.at(2));
        emit signal_putCommand(5,imgTimer,signatureList.at(3));
        emit signal_putCommand(6,imgTimer,signatureList.at(1));

        /*****************************
        * @brief:202112181611,6相机
        ******************************/
        QThread::msleep(100);
        emit signal_putCommand(9,imgTimer,signatureList.at(6));
        this->putCount=8;
        this->putComType=2;

        isCapSucess=true;
    }
        break;
    case 5:
        /*****************************
        * @brief:车辆倒车
        ******************************/
        emit signal_channelState(channelID,0);
        break;
    case 6:
        /*****************************
        * @brief:南京三宝短箱红外逻辑
        ******************************/
    {
        emit signal_putCommand(4,imgTimer,signatureList.at(2));
        emit signal_putCommand(5,imgTimer,signatureList.at(3));
        emit signal_putCommand(6,imgTimer,signatureList.at(1));

        /*****************************
        * @brief:202112181611,6相机
        ******************************/
        QThread::msleep(100);
        emit signal_putCommand(9,imgTimer,signatureList.at(6));
        this->putCount=8;
        this->putComType=0;

        isCapSucess=true;
    }
        break;
    }

    /*****************************
    * @brief:20220219
    * 触发到红外，判定为集装箱车辆。
    * 由于车辆抓拍部分图片，车牌会清除图片，导致不识别
    ******************************/
    if(putCommnd!=-1){
         isConCar=true;
         isCar=false;

        /*****************************
        * @brief:发送拖箱状态
        ******************************/
        emit signal_sendCarStatus(isConCar);

        qDebug().noquote()<<QString("Example Set the container flow status");
    }
}

void Channel_Data_Form::slot_serialPortState(bool com1, bool com2, bool socketState)
{
    if(com1){
        ui->serial1checkBox->setStyleSheet("color: rgb(0, 211, 0);");
    }
    else {
        ui->serial1checkBox->setStyleSheet("color: rgb(211, 0, 0);");
    }
    if(com2){
        ui->serial2checkBox->setStyleSheet("color: rgb(0, 211, 0);");
    }
    else {
        ui->serial2checkBox->setStyleSheet("color: rgb(211, 0, 0);");
    }
    if(socketState){
        ui->iocheckBox->setStyleSheet("color: rgb(0, 211, 0);");
    }
    else {
       ui->iocheckBox->setStyleSheet("color: rgb(211, 0, 0);");
    }

    ui->serial1checkBox->setChecked(com1);
    ui->serial2checkBox->setChecked(com2);
    ui->iocheckBox->setChecked(socketState);

    emit signal_setDeviceStatus(channelID,LocalPar::Serial1,com1);
    emit signal_setDeviceStatus(channelID,LocalPar::Serial2,com2);
    emit signal_setDeviceStatus(channelID,LocalPar::IO,socketState);
}

void Channel_Data_Form::slot_theVideoStream(const QByteArray &arrImg)
{
    emit signal_videoStream(arrImg);
}

void Channel_Data_Form::slot_imageFlow(const QByteArray &jpgStream)
{
    if(jpgStream!=nullptr){
        /*****************************
        * @brief:调试页面显示车牌你图片（主页面可以显示小车牌图片，后续需要再处理）
        ******************************/
        emit signal_pictureStream(jpgStream,0,"");
    }
}

void Channel_Data_Form::slot_simulationCloseState()
{
    simulationdialog=false;

    /*****************************
    * @brief:清除模拟抓拍页面的车牌和箱号状态
    ******************************/
    simulationPlateStatus=false;
    simulationConStatus=false;
}

void Channel_Data_Form::slot_recognitionResult(const QString &result, const QString &imgName, const int &imgNumber)
{
    recogMap.insert(imgNumber,result);
    imgNameMap.insert(imgNumber,imgName);

    /*****************************
    * @brief:20210715 0121
    ******************************/
    bool complete=false;
    if(streamMap.value(7,nullptr)!=nullptr && recogMap.size()==(streamMap.size()-1) && recogMap.size()==imgNameMap.size()){
        complete=true;
    }
    if(streamMap.value(7,nullptr)==nullptr && recogMap.size()==streamMap.size() && recogMap.size()==imgNameMap.size()){
        complete=true;
    }

    if(complete){
        emit signal_resultsOfAnalysis(recogMap,putComType,imgNameMap);
        recogMap.clear();
        imgNameMap.clear();
    }
    complete=false;
}

void Channel_Data_Form::slot_container(const int &type, const QString &result1, const int &resultCheck1, const QString &iso1, const QString &result2, const int &resultCheck2, const QString &iso2)
{
    /*****************************
    * @brief:设定为集装箱车辆
    ******************************/
    isConCar=true;
    isCar=false;

    ui->time_lineEdit->setText(QDateTime::fromString(imgTimer,"yyyyMMddhhmmss").toString("yyyy/MM/dd hh:mm:ss"));
    ui->con_brfore_lineEdit->setText(result1);
    ui->iso_before_lineEdit->setText(iso1);
    ui->con_after_lineEdit->setText(result2);
    ui->iso_after_lineEdit->setText(iso2);

    if(resultCheck1){
        ui->con_brfore_lineEdit->setStyleSheet("background-color: rgb(0, 170, 0);color: rgb(255, 255, 255);");
    }
    else {
        ui->con_brfore_lineEdit->setStyleSheet("background-color: rgb(255, 0, 0);color: rgb(255, 255, 255);");
    }
    if(type==2){
        if(resultCheck2){
            ui->con_after_lineEdit->setStyleSheet("background-color: rgb(0, 170, 0);color: rgb(255, 255, 255);");
        }
        else {
            ui->con_after_lineEdit->setStyleSheet("background-color: rgb(255, 0, 0);color: rgb(255, 255, 255);");
        }
    }

    QString logic="";

    switch (type) {
    case -1:
        logic=tr("No container");
        break;
    case 0:
        logic=tr("A small container");
        break;
    case 1:
        logic=tr("A large container");
        break;
    case 2:
        logic=tr("Two containers");
        break;
    }
    ui->box_type_lineEdit->setText(logic);

    if(0 ==  para->lifthingType){
        emit signal_DTypeOut(Dout,1);
    }
    else if (1 == para->lifthingType) {
        if(2 == type && resultCheck1 && resultCheck2){
            emit signal_DTypeOut(Dout,1);
        }
        if(type <2 && resultCheck1){
            emit signal_DTypeOut(Dout,1);
        }
    }

    /*****************************
    * @brief:抓拍页面和多通道主页显示信息
    ******************************/
    emit signal_container(channelID, type, result1, resultCheck1, iso1, result2, resultCheck2, iso2);
}

void Channel_Data_Form::slot_resultsTheLicensePlate(const QString &plate, const QString &color, const QString &time,const QByteArray &arrImg)
{
    if(Parameter::dont_false_plate){
        if(Parameter::false_plate.size()!=1){
            if(plate.indexOf(Parameter::false_plate)!=-1){
                qCritical().noquote()<<QString("Not case：Filtering false license plates");
                return;
            }
        }
        else{
            int I=-1;
            int S= plate.indexOf(Parameter::false_plate);
            if(S!=-1){
                I= plate.indexOf(Parameter::false_plate,S+1);
            }
            int E= plate.lastIndexOf(Parameter::false_plate);
            if(S!=E && E!=I){
                qCritical().noquote()<<QString("Not case：Filtering false license plates");
                return;
            }
        }
    }

    if(!plate.isEmpty() && plate==historyPlate &&  QDateTime::fromString(historyPlateTime,"yyyy-M-d h:m:s").secsTo(QDateTime::fromString(time,"yyyy-M-d h:m:s"))<=Parameter::same_plate_out)
    {
        qCritical().noquote()<<QString("Not case：Filter the same license plate for a specified period of time");
        return;
    }

    /*****************************
    * @brief:跟车跳出不处理。
    ******************************/
    if(isWaitCon || !localPlateTime.isEmpty()){
        //emit signal_waitSendData();
        qCritical().noquote()<<QString("Not case：The process of the preceding vehicle has not been processed, and the information of the following vehicle is not processed.");
        return;
    }

//    if(!plate.isEmpty() && plate==localPlate && !localPlateTime.isEmpty() && QTime::fromString(time).msecsTo(QTime::fromString(localPlateTime))<60){
//        qCritical().noquote()<<QString("Repeated license plate recognition.");
//        return;
//    }

    /*****************************
    * @brief:非集装箱车辆清除历史图片
    ******************************/
    if(!isConCar){
        streamMap.clear();
        isCar=true;
    }
    else {
        isCar=false;
    }

    plateStream.clear();
    plateStream.insert(7,arrImg);

    localPlate=plate;
    localPlateColor=color;
    localPlateTime=QDateTime::fromString(time,"yyyy-M-d h:m:s").toString("yyyyMMddhhmmss");

    ui->plate_lineEdit->setText(plate);
    ui->plate_time_lineEdit->setText(time);
    ui->plate_color_lineEdit->setText(color);

    /*****************************
    * @brief:显示车牌图片
    ******************************/
    QScopedPointer<QPixmap> pix(new QPixmap());
    if(arrImg!=nullptr){
        pix->loadFromData(arrImg);
        QPalette palette;
        palette.setBrush(QPalette::Background, QBrush(pix.data()->scaled(ui->image_label_1->size(), Qt::IgnoreAspectRatio)));
        ui->image_label_7->setPalette(palette);
        //streamMap.insert(7,arrImg);
    }

    /*****************************
    * @brief:识别没有完成，写入数据库失败
    * 202002260923
    ******************************/
    if(sendDataOutTimer->isActive() && isConCar){
        /*****************************
        * @brief:关联车牌和箱号数据，更新车牌数据到数据库.
        ******************************/
        sendDataOutTimer->stop();
        QFuture<void> future  =QtConcurrent::run(this,&Channel_Data_Form::saveImages,plateStream,imgTimer,QString("U"));
        watcher->setFuture(future);
    }

    emit signal_plateSendData(channelNumber,isConCar,localPlate,localPlateColor,time);
    emit signal_plate(channelID,localPlate,localPlateColor,time,isConCar);

    /*****************************
    * @brief:保存上次识别车牌
    ******************************/
    historyPlate=plate;
    historyPlateTime=time;
}
