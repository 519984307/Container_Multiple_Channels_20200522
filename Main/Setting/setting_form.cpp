#include "setting_form.h"
#include "ui_setting_form.h"

Setting_Form::Setting_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Setting_Form)
{
    ui->setupUi(this);

    ui->listWidget->setVisible(false);

    this->setParent(parent);
    this->setHidden(true);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
}

Setting_Form::~Setting_Form()
{
    delete ui;
}

void Setting_Form::hideWindows()
{
    foreach (auto window, channel_setting_from_map.values()) {
        if(Channel_Setting_Form *pFrom=qobject_cast<Channel_Setting_Form*>(window)){
            pFrom->setVisible(false);
        }
    }
}

void Setting_Form::initializesTheDeviceStateListSlot(int count, QStringList rowLabels)
{
    for (int var = 1; var <= count; ++var) {
        Channel_Setting_Form *p_Channel_From=new Channel_Setting_Form (this);
        ui->gridLayout->addWidget(p_Channel_From);
        channel_setting_from_map.insert(var,p_Channel_From);
    }
    ui->listWidget->addItems(rowLabels);
}

void Setting_Form::on_channel_pushButton_clicked()
{
    ui->listWidget->setVisible(true);
}

void Setting_Form::on_system_pushButton_clicked()
{
    ui->listWidget->setVisible(false);
}

void Setting_Form::on_listWidget_currentRowChanged(int currentRow)
{
    if(Channel_Setting_Form *pFrom=qobject_cast<Channel_Setting_Form*>(channel_setting_from_map.value(currentRow+1))){
        hideWindows();
        pFrom->setVisible(true);
        qDebug()<<currentRow;
    }
}
