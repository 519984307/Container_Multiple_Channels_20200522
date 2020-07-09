#include "channel_data_form.h"
#include "ui_channel_data_form.h"

Channel_Data_Form::Channel_Data_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Channel_Data_Form)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose,true);

    this->setParent(parent);
    this->setHidden(true);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
}

Channel_Data_Form::~Channel_Data_Form()
{
    delete ui;
}
