#include "info_log_form.h"
#include "ui_info_log_form.h"

Info_Log_Form::Info_Log_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Info_Log_Form)
{
    ui->setupUi(this);
}

Info_Log_Form::~Info_Log_Form()
{
    delete ui;
}
