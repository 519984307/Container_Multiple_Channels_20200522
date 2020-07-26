#include "setting_form.h"
#include "ui_setting_form.h"

Setting_Form::Setting_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Setting_Form)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose,true);

    this->setParent(parent);
    this->setHidden(true);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    ui->listWidget->setVisible(false);

    initializingObject();
}

Setting_Form::~Setting_Form()
{
    qDeleteAll(From_Map);

    From_Map.clear();

    delete ui;
}

void Setting_Form::showEvent(QShowEvent *event)
{
    if(event->type()==QEvent::Show){
        ui->system_pushButton->setFocus();
        emit on_system_pushButton_clicked();
    }
}

void Setting_Form::initializingObject()
{
    channelSelect=0;

    p_System_Setting_From=nullptr;
    p_Channel_Setting_From=nullptr;

    From_Map.append(p_System_Setting_From);
    From_Map.append(p_Channel_Setting_From);
}

void Setting_Form::removeTheWindow()
{
    if(p_System_Setting_From!=nullptr){
        delete p_System_Setting_From;
        p_System_Setting_From=nullptr;
    }
    if(p_Channel_Setting_From!=nullptr){
        delete p_Channel_Setting_From;
        p_Channel_Setting_From=nullptr;
    }
}

void Setting_Form::initializesTheDeviceListSlot(int count, QStringList rowLabels)
{
    channelSelect=0;

    ui->listWidget->addItems(rowLabels);

    for (int var = 1; var <= count; ++var) {
        ui->listWidget->item(var-1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    }
}

void Setting_Form::on_channel_pushButton_clicked()
{
    ui->listWidget->setVisible(true);
    ui->listWidget->setFocus();
    ui->listWidget->setCurrentRow(0);
    channelSelect=0;
}

void Setting_Form::on_system_pushButton_clicked()
{  
    if(p_System_Setting_From==nullptr){

        removeTheWindow();
        ui->listWidget->setVisible(false);

        p_System_Setting_From=new System_Setting_Form (this);
        ui->gridLayout->addWidget(p_System_Setting_From);
        p_System_Setting_From->setVisible(true);

        channelSelect=0;
    }
    else {
        qDebug()<<p_System_Setting_From;
    }
}

void Setting_Form::on_listWidget_currentRowChanged(int currentRow)
{
    /*****************************
    * 列表选中项发生改变,才触发信号
    ******************************/
    if(channelSelect!=currentRow+1){
        removeTheWindow();

        if(p_Channel_Setting_From==nullptr){

            p_Channel_Setting_From=new Channel_Setting_Form (this);
            ui->gridLayout->addWidget(p_Channel_Setting_From);
            p_Channel_Setting_From->setVisible(true);

            channelSelect=currentRow+1;
        }
    }
    else {
        qDebug()<<p_Channel_Setting_From;
    }
}
