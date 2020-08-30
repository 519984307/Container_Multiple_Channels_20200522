#include "data_log_form.h"
#include "ui_data_log_form.h"

Data_Log_Form::Data_Log_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Data_Log_Form)
{
    ui->setupUi(this);
}

Data_Log_Form::~Data_Log_Form()
{
    delete ui;
}
