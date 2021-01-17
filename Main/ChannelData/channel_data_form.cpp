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

    this->channelNumber=channelNumber;

    foreach (QCheckBox* obj, ui->toolBox->findChildren<QCheckBox*>(QString(),Qt::FindChildrenRecursively)) {
        /*****************************
        * @brief:ChcekBox禁止手动勾选
        ******************************/
        obj->setAttribute(Qt::WA_TransparentForMouseEvents);
        obj->setFocusPolicy(Qt::NoFocus);
        obj->setStyleSheet("color: rgb(211, 0, 0);");
    }

    connect(this,&Channel_Data_Form::signal_pictureStream,this,&Channel_Data_Form::slot_pictureStream);
}

Channel_Data_Form::~Channel_Data_Form()
{
    qDebug()<<"~Channel_Data_Form";

    streamMap.clear();
    signatureList.clear();
    imgNameMap.clear();

    delete ui;
}

void Channel_Data_Form::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}

bool Channel_Data_Form::eventFilter(QObject *target, QEvent *event)
{
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
    }
    if(event->type()==QEvent::Resize){
        if(nullptr != streamMap.value(key,nullptr)){
            slot_pictureStream(streamMap.value(key,nullptr),key,imgTimer);
        }
    }
    return  QWidget::eventFilter(target,event);
}

void Channel_Data_Form::loadParamter(int channelID,ChannelParameter *para)
{
    this->channelID=channelID;
    this->para=para;

    watcher=new QFutureWatcher<void>(this);
    /*****************************
    * @brief:初始化数据库
    ******************************/
    emit signal_initDataBase(QString::number(channelID),Parameter::databaseUser,Parameter::databasePass,Parameter::databaseAddr,Parameter::DatabaseType);
}

void Channel_Data_Form::clearnPixmap()
{
    QPalette palette;
    ui->image_label_1->setPalette(palette);
    ui->image_label_2->setPalette(palette);
    ui->image_label_3->setPalette(palette);
    ui->image_label_4->setPalette(palette);
    ui->image_label_5->setPalette(palette);
    ui->image_label_6->setPalette(palette);
    //ui->image_label_7->setPalette(palette);
    ui->image_label_8->setPalette(palette);
    ui->image_label_9->setPalette(palette);
    ui->image_label_10->setPalette(palette);
    ui->image_label_11->setPalette(palette);
    //ui->image_label_12->setPalette(palette);

//    foreach (QLabel* obj, ui->gridLayout->findChildren<QLabel*>(QString(),Qt::FindChildrenRecursively)) {
//        if(obj==ui->image_label_7 || obj==ui->image_label_12){
//            break;
//        }
//        obj->setPalette(palette);
//    }

    foreach (QLineEdit* obj, ui->toolBox->findChildren<QLineEdit*>(QString(),Qt::FindChildrenRecursively)) {
        obj->setText("");
        obj->clear();
    }

//    ui->con_brfore_lineEdit->clear();
//    ui->iso_before_lineEdit->clear();
//    ui->con_after_lineEdit->clear();
//    ui->iso_after_lineEdit->clear();
//    ui->box_type_lineEdit->clear();
//    ui->time_lineEdit->clear();
}

void Channel_Data_Form::on_SimulationPushButton_clicked()
{
    QPointer<SimulationDialog> Dlg=new SimulationDialog(this);
    connect(Dlg,&SimulationDialog::signal_logicPutImage,this,&Channel_Data_Form::slot_logicPutImage);
    connect(this,&Channel_Data_Form::signal_container,Dlg,&SimulationDialog::slot_container);
    Dlg->exec();
}

void Channel_Data_Form::saveImages(QMap<int, QByteArray> stream,QString datetime)
{
    QMutexLocker locket(&mutex);
    if(Parameter::ImagePath.isEmpty()){
        Parameter::ImagePath="C:\\images";
    }

    QString suffixPath;

    switch (Parameter::ImageFormat) {
    case 0:
        suffixPath=QDir::toNativeSeparators(tr("%1/%2").arg(channelNumber).arg(QDateTime::currentDateTime().toString("yyyy/MM/dd")));
        break;
    case 1:
        suffixPath=QDir::toNativeSeparators(tr("%1/%2").arg(channelNumber).arg(QDateTime::currentDateTime().toString("yyyy/MM")));
        break;
    case 2:
        suffixPath=QDir::toNativeSeparators(tr("%1/%2").arg(channelNumber).arg(QDateTime::currentDateTime().toString("yyyy")));
        break;
    case 3:
        suffixPath=QDir::toNativeSeparators(tr("%1").arg(channelNumber));
        break;
    case 4:
        suffixPath=QDir::toNativeSeparators(tr("%1").arg(QDateTime::currentDateTime().toString("yyyy/MM/dd")));
        break;
    case 5:
        suffixPath=QDir::toNativeSeparators(tr("%1").arg(QDateTime::currentDateTime().toString("yyyy/MM")));
        break;
    case 6:
        suffixPath=QDir::toNativeSeparators(tr("%1").arg(QDateTime::currentDateTime().toString("yyyy")));
        break;
    case 7:
        suffixPath=QDir::toNativeSeparators("./");
        break;
    }

    QDir dir(Parameter::ImagePath);
    dir.mkpath(suffixPath);
    dir.cd(suffixPath);

    ///
    /// \brief databaseMap 插入数据库
    ///
    QMap<QString, QString> databaseMap;

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
        QString imgPath=QDir::toNativeSeparators(tr("%1/%2").arg(dir.path()).arg(imgName));

        if(nullptr == stream.value(key,nullptr)){
            slot_recognitionResult("RESULT: ||0|0",imgPath,key);
            continue;
        }
        QScopedPointer<QPixmap> pix(new QPixmap());
        pix.data()->loadFromData(stream.value(key));
        if(false == pix.data()->scaled(1280,720, Qt::IgnoreAspectRatio, Qt::SmoothTransformation).save(imgPath)){
            slot_recognitionResult("RESULT: ||0|0",imgPath,key);
            continue;
        }
        else {
            emit signal_identifyImages(imgPath,key);
            if(Parameter::Ftp){
                /*****************************
                * @brief:上传图片
                ******************************/
                emit signal_uploadData(imgPath);
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
        }
    }
    /*****************************
    * @brief:插入数据库
    ******************************/
    databaseMap.insert("Timer",QDateTime::fromString(datetime,"yyyyMMddhhmmss").toString("yyyy/MM/dd hh:mm:ss"));
    databaseMap.insert("Channel",QString::number(channelNumber));
    databaseMap.insert("Type",QString::number(this->putComType));

    emit signal_insertDataBase(databaseMap);
}

void Channel_Data_Form::slot_pictureStream(const QByteArray &jpgStream, const int &imgNumber, const QString &imgTime)
{
    if(imgNumber==0){
        return;
    }
    if(imgTime!=this->imgTimerAf){
        QMutableMapIterator<int, QByteArray> i(streamMap);
         while (i.hasNext()) {
             i.next();
             i.remove();
         }
         streamMap.clear();
         imgNameMap.clear();
    }

    this->imgTimerAf=imgTime;
    streamMap.insert(imgNumber,jpgStream);

    if(-1!=putCount && streamMap.size()==putCount && watcher->isFinished()){
        QFuture<void> future  =QtConcurrent::run(this,&Channel_Data_Form::saveImages,streamMap,imgTime);
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

    /*****************************
    * @brief:相机
    ******************************/
    emit signal_initCamer_front(para->FrontCamer,8000,para->UserCamer,para->PasswordCamer,signatureList.at(0));
    emit signal_initCamer_before(para->AfterCamer,8000,para->UserCamer,para->PasswordCamer,signatureList.at(1));
    emit signal_initCamer_left(para->LeftCamer,8000,para->UserCamer,para->PasswordCamer,signatureList.at(2));
    emit signal_initCamer_right(para->RgihtCamer,8000,para->UserCamer,para->PasswordCamer,signatureList.at(3));
    emit signal_initCamer_top(para->TopCamer,8000,para->UserCamer,para->PasswordCamer,signatureList.at(4));
    emit signal_initCamer_prospects(para->ProspectsCamer,8000,para->UserCamer,para->PasswordCamer,signatureList.at(5));
    emit signal_initCamer_foreground(para->ForgroundCamer,8000,para->UserCamer,para->PasswordCamer,signatureList.at(6));

    /*****************************
    * @brief:红外
    ******************************/
    emit signal_setAlarmMode(para->infraredStatus);
    emit signal_startSlave(QString("COM%1").arg(para->SerialPortOne),QString("COM%1").arg(para->SerialPortTow),channelID);

    /*****************************
    * @brief:数据库插入
    ******************************/
    emit signal_initDataBase(QString::number(channelID),Parameter::databaseUser,Parameter::databasePass,Parameter::databaseAddr,Parameter::DatabaseType);

    /*****************************
    * @brief:结果分析
    ******************************/
    emit signal_initReAnaParameter(channelNumber,Parameter::ImageNamingRules,Parameter::ResultsTheCheck,Parameter::Resultting);
}

void Channel_Data_Form::slot_bindingCameraID(QString cameraAddr, int ID)
{
    Q_UNUSED(cameraAddr);
    qDebug()<<para->Channel_number<<":"<<ID;
}

void Channel_Data_Form::slot_captureTest(int channelID, int cameraID)
{
    if(this->channelID==channelID){
        emit signal_putCommand(0,"",signatureList.at(cameraID-1));
    }
}

void Channel_Data_Form::slot_playStream(quint64 winID, bool play, int channelID, int cameraID)
{
    if(this->channelID==channelID){
        emit signal_playStream(winID,play,signatureList.at(cameraID-1));
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
        emit clearnPixmap();/* 通知来车,清除数据界面图片 */
        this->putCount=-1;
        this->putComType=-1;
        break;
    case 0:
    {
        imgTimer=QDateTime::currentDateTime().toString("yyyyMMddhhmmss");/* 来车时间 */
        emit signal_putCommand(1,imgTimer,signatureList.at(0));
        emit signal_putCommand(2,imgTimer,signatureList.at(2));
        emit signal_putCommand(3,imgTimer,signatureList.at(3));
        this->putCount=-1;
        this->putComType=-1;
    }
        break;
    case 1:
    {
        emit signal_putCommand(4,imgTimer,signatureList.at(2));
        emit signal_putCommand(5,imgTimer,signatureList.at(3));
        emit signal_putCommand(6,imgTimer,signatureList.at(1));
        this->putCount=6;
        this->putComType=1;
    }
        break;
    case 2:
    {
        imgTimer=QDateTime::currentDateTime().toString("yyyyMMddhhmmss");/* 来车时间 */
        emit signal_putCommand(1,imgTimer,signatureList.at(0));
        emit signal_putCommand(2,imgTimer,signatureList.at(2));
        emit signal_putCommand(3,imgTimer,signatureList.at(3));
        emit signal_putCommand(6,imgTimer,signatureList.at(1));
        this->putCount=4;
        this->putComType=0;
    }
        break;
    case 4:
    {
        emit signal_putCommand(4,imgTimer,signatureList.at(2));
        emit signal_putCommand(5,imgTimer,signatureList.at(3));
        emit signal_putCommand(6,imgTimer,signatureList.at(1));
        this->putCount=6;
        this->putComType=2;
    }
        break;
    }
}

void Channel_Data_Form::slot_serialPortState(bool com1, bool com2)
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
    ui->serial1checkBox->setChecked(com1);
    ui->serial2checkBox->setChecked(com2);

    emit signal_setDeviceStatus(channelID,LocalPar::Serial1,com1);
    emit signal_setDeviceStatus(channelID,LocalPar::Serial2,com2);
}

void Channel_Data_Form::slot_recognitionResult(const QString &result, const QString &imgName, const int &imgNumber)
{
    recogMap.insert(imgNumber,result);
    imgNameMap.insert(imgNumber,imgName);
    if(recogMap.size()==streamMap.size()){
        emit signal_resultsOfAnalysis(recogMap,putComType,imgNameMap);
        recogMap.clear();
        imgNameMap.clear();
    }
}

void Channel_Data_Form::slot_container(const int &type, const QString &result1, const int &resultCheck1, const QString &iso1, const QString &result2, const int &resultCheck2, const QString &iso2)
{
    emit signal_container(type, result1, resultCheck1, iso1, result2, resultCheck2, iso2);
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
}
