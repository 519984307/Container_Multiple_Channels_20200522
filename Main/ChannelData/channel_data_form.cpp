#include "channel_data_form.h"
#include "ui_channel_data_form.h"

#include "imagedialog.h"
#include "simulationdialog.h"

#include <QPointer>

Channel_Data_Form::Channel_Data_Form(QString alias, int channelNumber, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Channel_Data_Form)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose,true);

    this->setParent(parent);
    this->setVisible(false);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    ui->image_label_1->installEventFilter(this);
    ui->image_label_2->installEventFilter(this);
    ui->image_label_3->installEventFilter(this);
    ui->image_label_4->installEventFilter(this);
    ui->image_label_5->installEventFilter(this);
    ui->image_label_6->installEventFilter(this);
    ui->image_label_7->installEventFilter(this);
    ui->image_label_8->installEventFilter(this);
    ui->image_label_9->installEventFilter(this);
    ui->image_label_10->installEventFilter(this);
    ui->image_label_11->installEventFilter(this);
    //ui->image_label_12->installEventFilter(this);

    ui->image_label_7->setVisible(false);
    ui->image_label_8->setVisible(false);
    ui->image_label_9->setVisible(false);
    ui->image_label_10->setVisible(false);
    ui->image_label_11->setVisible(false);
    ui->image_label_12->setVisible(false);

    ui->lineEdit_10->setText(alias);
    ui->lineEdit_2->setText(QString::number(channelNumber));

    ui->image_label_1->repaint();
    QPixmap pix("C:\\Users\\cc\\Pictures\\Camera Roll\\WIN_20200722_10_17_51_Pro.jpg");
    QPixmap pp= pix.scaled(QSize(ui->image_label_1->size()),Qt::IgnoreAspectRatio);


    QPalette palette(ui->image_label_1->palette());
    palette.setBrush(QPalette::Background, QBrush(pp));
    ui->image_label_1->setPalette(palette);
}

Channel_Data_Form::~Channel_Data_Form()
{
    delete ui;
}

void Channel_Data_Form::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}

bool Channel_Data_Form::eventFilter(QObject *target, QEvent *event)
{
    if(target==ui->image_label_1||target==ui->image_label_2||target==ui->image_label_3||target==ui->image_label_4
            ||target==ui->image_label_5||target==ui->image_label_6||target==ui->image_label_7||target==ui->image_label_8
            ||target==ui->image_label_9||target==ui->image_label_10||target==ui->image_label_11){

        if(event->type()==QEvent::MouseButtonDblClick){
            QPointer<ImageDialog> Dlg=new ImageDialog(this);
            connect(this,SIGNAL(signal_enlargeImages(QByteArray)),Dlg,SLOT(slot_enlargeImages(QByteArray)));
            Dlg->exec();
        }
        if(event->type()==QEvent::Resize){
            ui->image_label_1->repaint();
            QPixmap pix("C:\\Users\\cc\\Pictures\\Camera Roll\\WIN_20200722_10_17_51_Pro.jpg");
            QPixmap pp= pix.scaled(QSize(ui->image_label_1->size()),Qt::IgnoreAspectRatio);


            QPalette palette(ui->image_label_1->palette());
            palette.setBrush(QPalette::Background, QBrush(pp));
            ui->image_label_1->setPalette(palette);
        }
    }

    return  QWidget::eventFilter(target,event);
}

void Channel_Data_Form::on_SimulationPushButton_clicked()
{
    QPointer<SimulationDialog> Dlg=new SimulationDialog(this);
    Dlg->exec();
}
