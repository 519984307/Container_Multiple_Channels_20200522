﻿#include "channel_data_form.h"
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

    foreach (QCheckBox* obj, ui->toolBox->findChildren<QCheckBox*>(QString(),Qt::FindChildrenRecursively)) {
        /*****************************
        * @brief:ChcekBox禁止手动勾选
        ******************************/
        obj->setAttribute(Qt::WA_TransparentForMouseEvents);
        obj->setFocusPolicy(Qt::NoFocus);
        obj->setStyleSheet("color: rgb(211, 0, 0);");
    }

    ui->toolBox->setCurrentIndex(0);

//    ui->image_label_1->repaint();
//    QPixmap pix("C:\\Users\\cc\\Pictures\\Camera Roll\\WIN_20200722_10_17_51_Pro.jpg");
//    QPixmap pp= pix.scaled(QSize(ui->image_label_1->size()),Qt::IgnoreAspectRatio);


//    QPalette palette(ui->image_label_1->palette());
//    palette.setBrush(QPalette::Background, QBrush(pp));
//    ui->image_label_1->setPalette(palette);
}

Channel_Data_Form::~Channel_Data_Form()
{
    qDebug()<<"~Channel_Data_Form";
    delete ui;
}

void Channel_Data_Form::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}

bool Channel_Data_Form::eventFilter(QObject *target, QEvent *event)
{
    if(target==ui->image_label_1||target==ui->image_label_2||target==ui->image_label_3||target==ui->image_label_4
            ||target==ui->image_label_5||target==ui->image_label_6||target==ui->image_label_7||target==ui->image_label_8
            ||target==ui->image_label_9||target==ui->image_label_10||target==ui->image_label_11){

        if(event->type()==QEvent::MouseButtonDblClick){
            QPointer<ImageDialog> Dlg=new ImageDialog(this);
            connect(this,SIGNAL(signal_enlargeImages(QByteArray)),Dlg,SLOT(slot_enlargeImages(QByteArray)));
            Dlg->exec();
        }
//        if(event->type()==QEvent::Resize){
//            ui->image_label_1->repaint();
//            QPixmap pix("C:\\Users\\cc\\Pictures\\Camera Roll\\WIN_20200722_10_17_51_Pro.jpg");
//            QPixmap pp= pix.scaled(QSize(ui->image_label_1->size()),Qt::IgnoreAspectRatio);


//            QPalette palette(ui->image_label_1->palette());
//            palette.setBrush(QPalette::Background, QBrush(pp));
//            ui->image_label_1->setPalette(palette);
//        }
    }
    else if (target==ui->image_label_12) {
        /*****************************
        * @brief:处理其他信息
        ******************************/
        ;
    }
    return  QWidget::eventFilter(target,event);
}

void Channel_Data_Form::loadParamter(int channelID,ChannelParameter *para)
{
    this->channelID=channelID;
    this->para=para;
}

void Channel_Data_Form::on_SimulationPushButton_clicked()
{
    QPointer<SimulationDialog> Dlg=new SimulationDialog(this);
    Dlg->exec();
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

void Channel_Data_Form::slot_initCamera()
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
