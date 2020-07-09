#include "channel_setting_form.h"
#include "ui_channel_setting_form.h"

Channel_Setting_Form::Channel_Setting_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Channel_Setting_Form)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose,true);
    this->setParent(parent);
    this->setHidden(true);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
}

Channel_Setting_Form::~Channel_Setting_Form()
{
    delete ui;
}
