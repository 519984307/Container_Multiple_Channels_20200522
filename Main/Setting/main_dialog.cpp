#include "main_dialog.h"
#include "ui_main_dialog.h"

#include "Parameter/parameter.h"
#include "Parameter/processing.h"

#include <QPointer>

Main_Dialog::Main_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Main_Dialog)
{
    ui->setupUi(this);   

    this->setParent(parent);
    this->setHidden(true);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_DeleteOnClose,true);

    /*****************************
    * @brief: 加载系统配置参数,【优先加载】
    ******************************/
    loadParameter();

    /*****************************
    * @brief: 设置系统模式
    ******************************/
    setSystemModel();

    /*****************************
    * @brief:倒计时启动系统
    ******************************/
    startTheTimer();
}

Main_Dialog::~Main_Dialog()
{
    delete ui;
}

void Main_Dialog::loadParameter()
{
    QPointer<Processing> Pointer(new Processing(this));
    if(Pointer->loadParameter()){
        ui->ChannelNumber->setValue(Parameter::ChannelNumber);
    }
    else {
        ui->ChannelNumber->setValue(1);
    }
}

void Main_Dialog::setSystemModel()
{
    switch (ui->ChannelNumber->value()) {
    case 1:ui->comboBox->setCurrentIndex(0);
        break;
    default:
        ui->comboBox->setCurrentIndex(1);
    }
}

void Main_Dialog::startTheTimer()
{
    cot=0;
    QPointer<QTimer> pPTimer=new QTimer (this);
    connect(pPTimer,SIGNAL(timeout()),this,SLOT(theCountdown()));
    pPTimer->start(1000);
}

void Main_Dialog::on_pushButton_clicked()
{
    Parameter::ChannelNumber=ui->ChannelNumber->value();
    this->done(10);
}

void Main_Dialog::on_comboBox_currentIndexChanged(int index)
{
    if(0==index){
        ui->ChannelNumber->setValue(1);
    }
}

void Main_Dialog::on_ChannelNumber_valueChanged(int arg1)
{
    if(1==arg1){
        ui->comboBox->setCurrentIndex(0);
    }
    else {
        ui->comboBox->setCurrentIndex(1);
    }
}

void Main_Dialog::theCountdown()
{
    cot++;

    ui->progressBar->setMaximum(Parameter::DelayStart);
    ui->progressBar->setValue(cot);

    if(cot==Parameter::DelayStart){
        Parameter::ChannelNumber=ui->ChannelNumber->value();
        this->done(10);
    }
}
