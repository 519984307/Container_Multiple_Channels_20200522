#include "camera_test_form.h"
#include "ui_camera_test_form.h"

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
