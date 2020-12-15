#include "camera_list_form.h"
#include "ui_camera_list_form.h"

#include <QDebug>

Camera_List_Form::Camera_List_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Camera_List_Form)
{
    ui->setupUi(this);

    this->setParent(parent);
    this->setAttribute(Qt::WA_DeleteOnClose,true);

    initializingObject();
}

Camera_List_Form::~Camera_List_Form()
{
    delete takeItem;
    takeItem=nullptr;

    qDebug()<<"~Camera_List_Form()";
    delete ui;
}

void Camera_List_Form::initializingObject()
{
    p_Camera_Test_Form=new Camera_Test_Form (this);
    ui->gridLayout->addWidget(p_Camera_Test_Form);

    takeItem=nullptr;
    CamerNameList=LocalPar::CamerNameList;
}

void Camera_List_Form::initializesTheDeviceListSlot(int count, QStringList rowLabels)
{
    for(int i=0;i<count;i++){
        auto childItem=new QTreeWidgetItem (QStringList(rowLabels.at(i)));
        /*  添加子项    */
        ui->CameraList->addTopLevelItem(childItem);
        for(auto name:CamerNameList){
            auto sunItem=new QTreeWidgetItem (childItem,QStringList(name));
            childItem->addChild(sunItem);
        }
    }

    /*****************************
     * 初始化显示第一项
     ******************************/
//    QTreeWidgetItemIterator it(ui->CameraList);
//    while(*it){
//        if((*it)->childCount()==0){
//            ui->CameraList->setCurrentItem(*it);
//            emit on_CameraList_itemActivated(*it);
//            break;
//        }
//        it++;
//    }
}

void Camera_List_Form::on_CameraList_itemActivated(QTreeWidgetItem *item)
{
    if(takeItem!=item && item->childCount()==0){
        takeItem=item;
    }
}
