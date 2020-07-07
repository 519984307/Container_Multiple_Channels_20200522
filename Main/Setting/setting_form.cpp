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
    qDeleteAll(WindowsVector);
    WindowsVector.clear();

    delete ui;
}

void Setting_Form::showEvent(QShowEvent *event)
{
    if(event->type()==QEvent::Show){
        ui->system_pushButton->setFocus();
        emit on_system_pushButton_clicked();
    }
}

void Setting_Form::hideEvent(QHideEvent *event)
{
//    if(event->type()==QEvent::Hide){
//        this->close();
//    }
}

void Setting_Form::hideWindows()
{
    foreach (auto window, WindowsVector) {
        if(Channel_Setting_Form *pFrom=qobject_cast<Channel_Setting_Form*>(window)){
            pFrom->setVisible(false);
        }
        else if (System_Setting_Form *pFrom=qobject_cast<System_Setting_Form*>(window)) {
            pFrom->setVisible(false);
        }
    }
}

void Setting_Form::initializesTheDeviceListSlot(int count, QStringList rowLabels)
{
    ui->listWidget->addItems(rowLabels);

    for (int var = 1; var <= count; ++var) {
        Channel_Setting_Form *p_Channel_From=new Channel_Setting_Form (this);
        ui->gridLayout->addWidget(p_Channel_From);

        channel_setting_from_map.insert(var,p_Channel_From);
        WindowsVector.append(p_Channel_From);

        ui->listWidget->item(var-1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    }

    p_System_Setting_From=new System_Setting_Form (this);

    ui->gridLayout->addWidget(p_System_Setting_From);
    WindowsVector.append(p_System_Setting_From);
}

void Setting_Form::on_channel_pushButton_clicked()
{
    if(Channel_Setting_Form *pFrom=qobject_cast<Channel_Setting_Form*>(channel_setting_from_map.value(1))){
        hideWindows();
        ui->listWidget->setVisible(true);
        pFrom->setVisible(true);
    }

}

void Setting_Form::on_system_pushButton_clicked()
{  
    if(p_System_Setting_From!=nullptr){
        hideWindows();
        ui->listWidget->setVisible(false);
        p_System_Setting_From->setVisible(true);
    }
}

void Setting_Form::on_listWidget_currentRowChanged(int currentRow)
{
    if(Channel_Setting_Form *pFrom=qobject_cast<Channel_Setting_Form*>(channel_setting_from_map.value(currentRow+1))){
        hideWindows();
        pFrom->setVisible(true);
    }
}
