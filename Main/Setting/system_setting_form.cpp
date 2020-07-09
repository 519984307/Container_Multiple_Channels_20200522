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
}

System_Setting_Form::~System_Setting_Form()
{
    delete ui;
}
