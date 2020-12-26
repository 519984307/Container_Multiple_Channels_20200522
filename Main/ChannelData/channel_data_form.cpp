#include "channel_data_form.h"
#include "ui_channel_data_form.h"

#include "imagedialog.h"
#include "simulationdialog.h"

#include <QPointer>
#include <QDebug>

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

    ui->lineEdit_10->setText(alias);
    ui->lineEdit_5->setText(QString::number(channelNumber));
    ui->toolBox->setCurrentIndex(0);

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
    streamMap.clear();
    qDebug()<<"~Channel_Data_Form";
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
}

void Channel_Data_Form::on_SimulationPushButton_clicked()
{
    QPointer<SimulationDialog> Dlg=new SimulationDialog(this);
    Dlg->exec();
}

void Channel_Data_Form::slot_pictureStream(const QByteArray &jpgStream, const int &imgNumber, const QString &imgTime)
{
    if(imgTime!=this->imgTimer){
        streamMap.clear();
    }
    this->imgTimer=imgTime;
    streamMap.insert(imgNumber,jpgStream);

    QSharedPointer<QPixmap> pix(new QPixmap());
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
    }
    if (camerIP==para->AfterCamer) {
        ui->beforeCheckBox->setChecked(state);
        if(state){
            ui->beforeCheckBox->setStyleSheet("color: rgb(0, 211, 0);");
        }
        else {
            ui->beforeCheckBox->setStyleSheet("color: rgb(211, 0, 0);");
        }
    }
    if (camerIP==para->LeftCamer) {
        ui->leftCheckBox->setChecked(state);
        if(state){
            ui->leftCheckBox->setStyleSheet("color: rgb(0, 211, 0);");
        }
        else {
            ui->leftCheckBox->setStyleSheet("color: rgb(211, 0, 0);");
        }
    }
    if (camerIP==para->RgihtCamer) {
        ui->rightCheckBox->setChecked(state);
        if(state){
            ui->rightCheckBox->setStyleSheet("color: rgb(0, 211, 0);");
        }
        else {
            ui->rightCheckBox->setStyleSheet("color: rgb(211, 0, 0);");
        }
    }
    if (camerIP==para->PlateCamer) {
        ui->platestateCheckBox->setChecked(state);
        if(state){
            ui->platestateCheckBox->setStyleSheet("color: rgb(0, 211, 0);");
        }
        else {
            ui->platestateCheckBox->setStyleSheet("color: rgb(211, 0, 0);");
        }
    }
    if (camerIP==para->TopCamer) {
        ui->topstateCheckBox->setChecked(state);
        if(state){
            ui->topstateCheckBox->setStyleSheet("color: rgb(0, 211, 0);");
        }
        else {
            ui->topstateCheckBox->setStyleSheet("color: rgb(211, 0, 0);");
        }
    }
    if (camerIP==para->ForgroundCamer) {
        ui->forgroundstateCheckBox->setChecked(state);
        if(state){
            ui->forgroundstateCheckBox->setStyleSheet("color: rgb(0, 211, 0);");
        }
        else {
            ui->forgroundstateCheckBox->setStyleSheet("color: rgb(211, 0, 0);");
        }
    }
    if (camerIP==para->ProspectsCamer) {
        ui->prospectsstateCheckBox->setChecked(state);
        if(state){
            ui->prospectsstateCheckBox->setStyleSheet("color: rgb(0, 211, 0);");
        }
        else {
            ui->prospectsstateCheckBox->setStyleSheet("color: rgb(211, 0, 0);");
        }
    }
}

void Channel_Data_Form::slot_initEquipment()
{
    if(nullptr==this->para){
        return;
    }

    signatureList=LocalPar::CamerNameList;

    emit signal_initCamer_front(para->FrontCamer,8000,para->UserCamer,para->PasswordCamer,signatureList.at(0));
    emit signal_initCamer_before(para->AfterCamer,8000,para->UserCamer,para->PasswordCamer,signatureList.at(1));
    emit signal_initCamer_left(para->LeftCamer,8000,para->UserCamer,para->PasswordCamer,signatureList.at(2));
    emit signal_initCamer_right(para->RgihtCamer,8000,para->UserCamer,para->PasswordCamer,signatureList.at(3));
    emit signal_initCamer_top(para->TopCamer,8000,para->UserCamer,para->PasswordCamer,signatureList.at(4));
    emit signal_initCamer_prospects(para->ProspectsCamer,8000,para->UserCamer,para->PasswordCamer,signatureList.at(5));
    emit signal_initCamer_foreground(para->ForgroundCamer,8000,para->UserCamer,para->PasswordCamer,signatureList.at(6));

    emit signal_setAlarmMode(para->infraredStatus);
    emit signal_startSlave(QString("COM%1").arg(para->SerialPortOne),QString("COM%1").arg(para->SerialPortTow),channelID);
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
    /* A1.A2.D1.B1.B2.D2.D3.D4 */
    ui->a1checkBox->setChecked(status[0]);
    ui->a2checkBox->setChecked(status[1]);
    ui->b1checkBox->setChecked(status[3]);
    ui->b2checkBox->setChecked(status[4]);
    ui->d1checkBox->setChecked(status[2]);
    ui->d2checkBox->setChecked(status[5]);
    ui->d3checkBox->setChecked(status[6]);
    ui->d4checkBox->setChecked(status[7]);
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
        break;
    case 0:
    {
        imgTimer=QDateTime::currentDateTime().toString("yyyyMMddhhmmss");/* 来车时间 */
        emit signal_putCommand(1,imgTimer,signatureList.at(0));
        emit signal_putCommand(2,imgTimer,signatureList.at(2));
        emit signal_putCommand(3,imgTimer,signatureList.at(3));
    }
        break;
    case 1:
    {
        emit signal_putCommand(4,imgTimer,signatureList.at(2));
        emit signal_putCommand(5,imgTimer,signatureList.at(3));
        emit signal_putCommand(6,imgTimer,signatureList.at(1));
    }
        break;
    case 2:
    {
        imgTimer=QDateTime::currentDateTime().toString("yyyyMMddhhmmss");/* 来车时间 */
        emit signal_putCommand(1,imgTimer,signatureList.at(0));
        emit signal_putCommand(2,imgTimer,signatureList.at(2));
        emit signal_putCommand(3,imgTimer,signatureList.at(3));
        emit signal_putCommand(6,imgTimer,signatureList.at(1));
    }
        break;
    case 4:
    {
        emit signal_putCommand(4,imgTimer,signatureList.at(2));
        emit signal_putCommand(5,imgTimer,signatureList.at(3));
        emit signal_putCommand(6,imgTimer,signatureList.at(1));
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
}
