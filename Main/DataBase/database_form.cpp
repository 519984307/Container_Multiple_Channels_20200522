#include "database_form.h"
#include "ui_database_form.h"

DataBase_Form::DataBase_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataBase_Form)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose,true);

    this->setParent(parent);
    this->setHidden(true);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    InitializationWindow();
}

DataBase_Form::~DataBase_Form()
{
    delete ui;
}

void DataBase_Form::InitializationWindow()
{
    p_Image_Dialog=nullptr;

    /*****************************
     * 默认显示第一页
     ******************************/
    ui->database_stackedWidget->setCurrentIndex(0);

    /*****************************
     * 注册控件事件
     ******************************/
    ui->front_image_label->installEventFilter(this);
    ui->front_left_image_label->installEventFilter(this);
    ui->front_right_image_label->installEventFilter(this);
    ui->after_image_label->installEventFilter(this);
    ui->after_left_image_label->installEventFilter(this);
    ui->after_right_image_label->installEventFilter(this);
}

bool DataBase_Form::eventFilter(QObject *obj, QEvent *event)
{
    if(QLabel* pLabel=qobject_cast<QLabel*>(obj)){
        if(event->type()==QEvent::MouseButtonPress){
            QMouseEvent *pMouseEvent = static_cast<QMouseEvent*>(event);
            if(pMouseEvent->button()==Qt::LeftButton){

                QPixmap *pix=new QPixmap();
                pix->load("/home/cc/文档/trian/img_1.jpg");
                QPixmap map= pix->scaled(pLabel->size().width()-2,pLabel->size().height()-2,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
                pLabel->setPixmap(map);

                delete pix;
                pix=nullptr;

                if(pLabel->pixmap()!=nullptr){
                    if(p_Image_Dialog==nullptr){
                        p_Image_Dialog = new Image_Dialog (this);
                        p_Image_Dialog->show();
                    }

                    connect(p_Image_Dialog,SIGNAL(image_dialog_close_signal()),this,SLOT(image_dialog_close_slot()));
                    connect(this,SIGNAL(set_image_dialog_pixmap_signal(QPixmap)),p_Image_Dialog,SLOT(set_image_dialog_pixmap_slot(QPixmap)));

                    emit set_image_dialog_pixmap_signal(*pLabel->pixmap());
                }

                return true;
            }
        }
    }
    return  QWidget::eventFilter(obj,event);
}

void DataBase_Form::resizeEvent(QResizeEvent *event)
{
    if(event->oldSize().height()!=-1){
        int W= ui->database_stackedWidget->size().width()/3-4-4;
        int H=ui->database_stackedWidget->size().height()/2-ui->after_left_result_lineEdit_2->size().height()-6;
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

void DataBase_Form::on_database_imageOrData_pushButton_clicked()
{
    switch (ui->database_stackedWidget->currentIndex()) {
    case 0:ui->database_stackedWidget->setCurrentIndex(1);
        break;
    case 1:ui->database_stackedWidget->setCurrentIndex(0);
        break;
    }
}

void DataBase_Form::on_database_stackedWidget_currentChanged(int arg1)
{
    switch (arg1) {
    case 0:ui->database_imageOrData_pushButton->setText(tr("Image"));
        break;
    case 1:ui->database_imageOrData_pushButton->setText(tr("Data"));
        break;
    }
}

void DataBase_Form::image_dialog_close_slot()
{
    delete p_Image_Dialog;
    p_Image_Dialog=nullptr;
}
