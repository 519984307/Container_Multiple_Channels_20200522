#include "camera_test_form.h"
#include "ui_camera_test_form.h"

#include <QDebug>

Camera_Test_Form::Camera_Test_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Camera_Test_Form)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose,true);
    this->setParent(parent);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
}

Camera_Test_Form::~Camera_Test_Form()
{
    delete ui;
}

void Camera_Test_Form::on_capture_pushButton_clicked()
{
    emit signal_capture();
}

void Camera_Test_Form::on_play_pushButton_clicked()
{
    emit signal_play(ui->label->winId());
}

void Camera_Test_Form::on_identify_pushButton_clicked()
{

}

void Camera_Test_Form::slot_pictureStream(const QByteArray &jpgStream, const int &imgNumber, const QString &imgTime)
{
    Q_UNUSED(imgTime);

    if(imgNumber==0){
        if(jpgStream!=nullptr){
            QSharedPointer<QPixmap> pix(new QPixmap());
            pix->loadFromData(jpgStream);
            ui->label->setPixmap(pix.data()->scaled(ui->label->size(), Qt::IgnoreAspectRatio));
        }
        else {
            ui->label->clear();
            qCritical()<<"Capture image data is empty";
        }
    }
}
