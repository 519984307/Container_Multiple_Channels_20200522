#include "channel_data_form.h"
#include "ui_channel_data_form.h"

Channel_Data_Form::Channel_Data_Form(QString alias, int channelNumber, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Channel_Data_Form)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose,true);

    this->setParent(parent);
    this->setVisible(false);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    ui->lineEdit_10->setText(alias);
    ui->lineEdit_2->setText(QString::number(channelNumber));
}

Channel_Data_Form::~Channel_Data_Form()
{
    delete ui;
}

void Channel_Data_Form::resizeEvent(QResizeEvent *event)
{
    if(event->oldSize().height()!=-1){
        int W=(event->size().width()-150)/3-6;
        //int W= ui->groupBox_2->size().width()/3-4-4;
        int H=event->size().height()/2-ui->label_2->size().height()-6;
        //int H=ui->groupBox_2->size().height()/2-ui->label_2->size().height()-6;
        if(W>0 && H>0){
            ui->front_image_label->setFixedSize(QSize(W,H));
            ui->front_image_label->size().scale(QSize(W,H),Qt::IgnoreAspectRatio);
            ui->front_left_image_label->setFixedSize(QSize(W,H));
            ui->front_left_image_label->size().scale(QSize(W,H),Qt::IgnoreAspectRatio);
            ui->front_right_image_label->setFixedSize(QSize(W,H));
            ui->front_right_image_label->size().scale(QSize(W,H),Qt::IgnoreAspectRatio);
            ui->after_image_label->setFixedSize(QSize(W,H));
            ui->after_image_label->size().scale(QSize(W,H),Qt::IgnoreAspectRatio);
            ui->after_left_image_label->setFixedSize(QSize(W,H));
            ui->after_left_image_label->size().scale(QSize(W,H),Qt::IgnoreAspectRatio);
            ui->after_right_image_label->setFixedSize(QSize(W,H));
            ui->after_right_image_label->size().scale(QSize(W,H),Qt::IgnoreAspectRatio);
        }
    }
    return QWidget::resizeEvent(event);
}
