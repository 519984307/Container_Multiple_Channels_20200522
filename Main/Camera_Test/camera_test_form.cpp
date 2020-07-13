#include "camera_test_form.h"
#include "ui_camera_test_form.h"

Camera_Test_Form::Camera_Test_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Camera_Test_Form)
{
    ui->setupUi(this);
}

Camera_Test_Form::~Camera_Test_Form()
{
    delete ui;
}
