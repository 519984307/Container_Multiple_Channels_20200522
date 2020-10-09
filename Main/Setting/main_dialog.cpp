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

    this->setAttribute(Qt::WA_DeleteOnClose,true);

    this->setParent(parent);
    this->setHidden(true);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    /*****************************
    * @brief: 加载系统配置参数
    ******************************/
    QPointer<Processing> Pointer(new Processing(this));
    if(Pointer->loadParameter()){
        ui->ChannelNumber->setValue(Parameter::ChannelNumber);
    }
    else {
        ui->ChannelNumber->setValue(1);
    }

    /*****************************
    * @brief: 设置系统模式
    ******************************/
    switch (ui->ChannelNumber->value()) {
    case 1:ui->comboBox->setCurrentIndex(0);
        break;
    default:
        ui->comboBox->setCurrentIndex(1);
    }
}

Main_Dialog::~Main_Dialog()
{
    delete ui;
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
