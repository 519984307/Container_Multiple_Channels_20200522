
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
    this->setVisible(false);
    this->setWindowState(Qt::WindowMaximized);

    initializingObject();
}

Camera_List_Form::~Camera_List_Form()
{
    ItemMap.clear();
    delete ui;

    qDebug()<<"~Camera_List_Form()";
}

void Camera_List_Form::closeEvent(QCloseEvent *event)
{
    if(ui->CameraList->selectedItems().size()>0){
        emit signal_playStream(winID,false,ItemMap.value(tmpItem->parent()),ui->CameraList->currentIndex().row()+1);
    }

    foreach (auto obj, ItemMap.keys()) {
        delete obj;
        obj=nullptr;
    }
    QWidget::closeEvent(event);
}

void Camera_List_Form::initializingObject()
{
    p_Camera_Test_Form=QPointer<Camera_Test_Form>(new Camera_Test_Form (this));
    connect(this,SIGNAL(signal_pictureStream(QByteArray,int,QString)),p_Camera_Test_Form,SLOT(slot_pictureStream(QByteArray,int,QString)));
    connect(this,SIGNAL(signal_videoStream(QByteArray)),p_Camera_Test_Form,SLOT(slot_videoStream(QByteArray)));
    connect(p_Camera_Test_Form,SIGNAL(signal_capture()),this,SLOT(slot_capture()));
    connect(p_Camera_Test_Form,SIGNAL(signal_play(quint64)),this,SLOT(slot_play(quint64)));

    ui->gridLayout->addWidget(p_Camera_Test_Form);

    CamerNameList=LocalPar::CamerNameList;
    tmpItem=nullptr;

    play=false;
    winID=0;
}

void Camera_List_Form::initializesTheDeviceListSlot(int count, QStringList rowLabels)
{
    for(int i=0;i<count;i++){
        auto childItem=new QTreeWidgetItem (QStringList(rowLabels.at(i)));       
        ItemMap.insert(childItem,i+1);
        /*  添加子项    */
        ui->CameraList->addTopLevelItem(childItem);
        for(auto name:CamerNameList){
            auto sunItem=new QTreeWidgetItem (childItem,QStringList(name));
            childItem->addChild(sunItem);
        }
    }
}

void Camera_List_Form::slot_getCameraState(int channelID, int cameraID)
{
    Q_UNUSED(channelID);
    Q_UNUSED(cameraID);
}

void Camera_List_Form::on_CameraList_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    Q_UNUSED(column);

    if(item->childCount()==0){
        emit signal_captureTest(ItemMap.value(item->parent()),ui->CameraList->currentIndex().row()+1);
    }
}

void Camera_List_Form::on_CameraList_itemClicked(QTreeWidgetItem *item, int column)
{
    Q_UNUSED(column);
    if(item->childCount()==0){
        if(item!=tmpItem && play){
            play=false;
            emit signal_playStream(winID,play,ItemMap.value(tmpItem->parent()),index);
        }
        tmpItem=item;        
    }
}

void Camera_List_Form::slot_capture()
{
    if(nullptr== tmpItem){
        QMessageBox::warning(this,"Warning",QString("Please select the camera you want to capture"));
    }
    else {
        on_CameraList_itemDoubleClicked(tmpItem,0);
    }
}

void Camera_List_Form::slot_play(quint64 winID)
{
    if(nullptr== tmpItem){
        QMessageBox::warning(this,"Warning",QString("Please select the camera you want to play"));
    }
    else {
        if(0==this->winID){
            this->winID=winID;
        }
        if(!play){
            play=true;
            emit signal_playStream(winID,play,ItemMap.value(tmpItem->parent()),ui->CameraList->currentIndex().row()+1);
        }
        else {
            play=false;
            emit signal_playStream(winID,play,ItemMap.value(tmpItem->parent()),ui->CameraList->currentIndex().row()+1);
        }
    }

    index=ui->CameraList->currentIndex().row()+1;
}
