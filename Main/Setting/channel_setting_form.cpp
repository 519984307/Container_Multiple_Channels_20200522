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

void Channel_Setting_Form::InitializationParameter()
{

}

bool Channel_Setting_Form::loadParameter()
{

}

bool Channel_Setting_Form::writeParameter()
{

}

void Channel_Setting_Form::parameterToUi()
{

}

QVariant Channel_Setting_Form::getJsonValue(const QString &child, const QString &key, QJsonObject obj)
{

}
