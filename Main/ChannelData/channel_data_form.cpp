#include "channel_data_form.h"
#include "ui_channel_data_form.h"

#include <QDebug>

Channel_Data_Form::Channel_Data_Form(QString alias, int channelNumber, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Channel_Data_Form)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose,true);

    this->setParent(parent);
    this->setVisible(false);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    ui->image_label_7->setVisible(false);
    ui->image_label_8->setVisible(false);
    ui->image_label_9->setVisible(false);
    ui->image_label_10->setVisible(false);
    ui->image_label_11->setVisible(false);
    ui->image_label_12->setVisible(false);

    ui->lineEdit_10->setText(alias);
    ui->lineEdit_2->setText(QString::number(channelNumber));

    topC=false;
    prospectsC=false;
    foregroundC=false;
    plateC=false;

}

Channel_Data_Form::~Channel_Data_Form()
{
    delete ui;
}

void Channel_Data_Form::paintEvent(QPaintEvent *event)
{

    if(ui->image_label_2->sizeHint()!=ui->image_label_2->size()){
            ui->image_label_2->repaint();
            QPixmap pix("C:\\Users\\cc\\Pictures\\Camera Roll\\WIN_20200722_10_17_51_Pro.jpg");
            QPixmap pp= pix.scaled(QSize(ui->image_label_2->size()),Qt::IgnoreAspectRatio);


            QPalette palette(ui->image_label_2->palette());
            palette.setBrush(QPalette::Background, QBrush(pp));
            ui->image_label_2->setPalette(palette);
    }
    //ui->image_label_1->update();
    QWidget::paintEvent(event);
}

void Channel_Data_Form::on_plateCheckBox_stateChanged(int arg1)
{
    plateC=false;
    if(arg1==Qt::CheckState::Checked){
        plateC=true;
        //this->resize(this->size());
    }
}

void Channel_Data_Form::on_topCheckBox_stateChanged(int arg1)
{
    topC=false;
    if(arg1==Qt::CheckState::Checked){
        topC=true;
        //this->resize(this->size());
    }
}

void Channel_Data_Form::on_prospectsCheckBox_stateChanged(int arg1)
{
    prospectsC=false;
    if(arg1==Qt::CheckState::Checked){
        prospectsC=true;
        //this->resize(this->size());
    }
}

void Channel_Data_Form::on_foregroundCheckBox_stateChanged(int arg1)
{
    foregroundC=false;
    if(arg1==Qt::CheckState::Checked){
        foregroundC=true;
        //this->resize(this->size());
        ui->image_label_2->repaint();
        QPixmap pix("C:\\Users\\cc\\Pictures\\Camera Roll\\WIN_20200722_10_17_51_Pro.jpg");
        QPixmap pp= pix.scaled(QSize(ui->image_label_2->size()),Qt::IgnoreAspectRatio);


        QPalette palette(ui->image_label_2->palette());
        palette.setBrush(QPalette::Background, QBrush(pp));
        ui->image_label_2->setPalette(palette);


    }
}
