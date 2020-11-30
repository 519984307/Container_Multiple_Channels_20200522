#include "database_form.h"
#include "ui_database_form.h"

DataBase_Form::DataBase_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataBase_Form)
{
    ui->setupUi(this);
\
    this->setParent(parent);
    this->setAttribute(Qt::WA_DeleteOnClose,true);

    this->setFixedSize(this->size());
    InitializationWindow();
}

DataBase_Form::~DataBase_Form()
{
    delete p_Image_Dialog;
    p_Image_Dialog=nullptr;

    delete ui;
}

void DataBase_Form::InitializationWindow()
{
    p_Image_Dialog=new Image_Dialog (this);
    connect(this,SIGNAL(set_image_dialog_pixmap_signal(QPixmap)),p_Image_Dialog,SLOT(set_image_dialog_pixmap_slot(QPixmap)));

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
                pix->load("C:\\Users\\cc\\Pictures\\Camera Roll\\WIN_20200722_10_17_51_Pro.jpg");
                QPixmap map= pix->scaled(pLabel->size().width()-2,pLabel->size().height()-2,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
                pLabel->setPixmap(map);

                delete pix;
                pix=nullptr;

                if(pLabel->pixmap()!=nullptr && p_Image_Dialog!=nullptr){
                    p_Image_Dialog->show();

                    QPixmap pix("C:\\Users\\cc\\Pictures\\Camera Roll\\WIN_20200722_10_17_51_Pro.jpg");
                    emit set_image_dialog_pixmap_signal(pix);
                }
            }
        }
    }
    return  QWidget::eventFilter(obj,event);
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
