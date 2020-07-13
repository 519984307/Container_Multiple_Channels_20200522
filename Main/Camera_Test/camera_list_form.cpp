#include "camera_list_form.h"
#include "ui_camera_list_form.h"

Camera_List_Form::Camera_List_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Camera_List_Form)
{
    ui->setupUi(this);
}

Camera_List_Form::~Camera_List_Form()
{
    delete ui;
}
