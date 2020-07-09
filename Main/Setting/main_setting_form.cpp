#include "main_setting_form.h"
#include "ui_main_setting_form.h"

Main_Setting_Form::Main_Setting_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Main_Setting_Form)
{
    ui->setupUi(this);
}

Main_Setting_Form::~Main_Setting_Form()
{
    delete ui;
}
