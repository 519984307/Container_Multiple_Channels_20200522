#include "camera_list_form.h"
#include "ui_camera_list_form.h"

Camera_List_Form::Camera_List_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Camera_List_Form)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose,true);

    this->setParent(parent);
    this->setHidden(true);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    initializingObject();
}

Camera_List_Form::~Camera_List_Form()
{
    delete ui;
}

void Camera_List_Form::initializingObject()
{
    p_Camera_Test_Form=nullptr;

    channelSelect=0;
    CamerNameList<<"Front"<<"Before"<<"Left"<<"Right"<<"Top"<<"Plate";
}

void Camera_List_Form::removeTheWindow()
{
    if(p_Camera_Test_Form!=nullptr){
        delete p_Camera_Test_Form;
        p_Camera_Test_Form=nullptr;
    }
}

void Camera_List_Form::initializesTheDeviceListSlot(int count, QStringList rowLabels)
{
    for(int i=0;i<count;i++){
        auto childItem=new QTreeWidgetItem (QStringList(rowLabels[i]));
        /*  添加子项    */
        ui->CameraList->addTopLevelItem(childItem);
        for(auto name:CamerNameList){
            auto sunItem=new QTreeWidgetItem (childItem,QStringList(name));
            childItem->addChild(sunItem);
        }
    }
}

void Camera_List_Form::on_CameraList_clicked(const QModelIndex &index)
{
    if(channelSelect!=index.row()+1){
        if(p_Camera_Test_Form==nullptr){

            removeTheWindow();

            p_Camera_Test_Form=new Camera_Test_Form (this);
            ui->gridLayout->addWidget(p_Camera_Test_Form);
            p_Camera_Test_Form->setVisible(true);

            channelSelect=index.row()+1;
        }
    }
    else {
        qDebug()<<p_Camera_Test_Form;
    }
}
