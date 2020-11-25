#include "mainwindow_original.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //initializationParameter();
    //initStatusBar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    /*****************************
    * 删除所有窗口对象
    ******************************/
    qDeleteAll(Channel_Data_Action_Map.keys());
    qDeleteAll(Channel_Data_From_Map.values());

    Channel_Data_From_Map.clear();
    Channel_Data_Action_Map.clear();

    event->ignore();
}

void MainWindow::initializationParameter()
{
    /*****************************
    * @brief: 参数处理
    ******************************/
    pointer_Processing=QSharedPointer<Processing> (new Processing (this));

    /*****************************
    * @brief:加载系统参数
    ******************************/
    pointer_Processing->loadParameter();

    /*****************************
    * @brief: 加载通道参数
    ******************************/
    pointer_Processing->loadChannelParameter(Parameter::ChannelNumber);

    int key=0x30;
    channelSelect=0;
    channelCount=Parameter::ChannelNumber;
    channelParCount=pointer_Processing->ParmeterMap.count();

    if(channelCount>1){
        /*****************************
        * @brief:大于一条道，才显示主页面
        ******************************/
        QAction *pAction=new QAction (tr("Main"),this);
        pAction->setIcon(QIcon(":/UI_ICO/ICO/main-fill.svg"));
        pAction->setShortcut(QKeySequence(Qt::CTRL+static_cast<uint16_t>(key+'A')));
        pAction->setToolTip(tr("Channel switching (CTRL+%1)").arg("A"));

        Channel_Data_Action_Map.insert(pAction,0);
        Equipment_State_From* p_Equipment_State_From=new Equipment_State_From (this);

        /*****************************
        * @brief:工具栏信号
        ******************************/
        connect(pAction,SIGNAL(triggered()),this,SLOT(actionTiggeredSlot()));
        /*****************************
        * 初始化通道状态
        ******************************/
        connect(this,SIGNAL(initializesTheDeviceStateListSignal(int,QStringList)),p_Equipment_State_From,SLOT(initializesTheDeviceStateListSlot(int,QStringList)));
        /*****************************
        * 设置通道设备状态
        ******************************/
        connect(this,SIGNAL(setDeviceStatusSignal(int,int,bool)),p_Equipment_State_From,SLOT(setDeviceStatusSlot(int,int,bool)));

        Channel_Data_From_Map.insert(0,p_Equipment_State_From);

        ui->gridLayout_2->addWidget(p_Equipment_State_From);
        p_Equipment_State_From->setVisible(true);
    }

    for (int channel=1;channel<=channelCount;channel++) {

        QString name=tr("%1 # Channel").arg(channel,2,10,QChar('0'));

        /*****************************
        * @brief: 读取通道参数别名
        ******************************/
        if(channelParCount>=channel && !pointer_Processing->ParmeterMap[channel]->Alias.isEmpty()){
            name=pointer_Processing->ParmeterMap[channel]->Alias;
        }

        QAction *pAction=new QAction (name,this);
        pAction->setIcon(QIcon(":/UI_ICO/ICO/container.svg"));
        pAction->setShortcut(QKeySequence(Qt::CTRL+static_cast<uint16_t>(key+channel)));
        pAction->setToolTip(tr("Channel switching (CTRL+%1)").arg(channel));

        /*****************************
        * 绑定工具栏按钮事件
        ******************************/
        connect(pAction,SIGNAL(triggered()),this,SLOT(actionTiggeredSlot()));
        Channel_Data_Action_Map.insert(pAction,channel);

        /*****************************
        * @brief:数据窗口
        ******************************/
        Channel_Data_Form *p_Channel_Data_Form=new Channel_Data_Form(name,pointer_Processing->ParmeterMap[channel]->Channel_number,this);
        Channel_Data_From_Map.insert(channel,p_Channel_Data_Form);

        if(channelCount==1){
            p_Channel_Data_Form->setVisible(true);
            ui->gridLayout_2->addWidget(p_Channel_Data_Form);
        }
        /*****************************
        * 添加通道切换到菜单栏
        ******************************/
        ui->menuChannel_To_View->addAction(pAction);

        /*****************************
        * 添加通道切换到工具栏
        ******************************/
        ui->mainToolBar->addAction(pAction);

        /*****************************
       * 通道组
       ******************************/
        channelLabels.append(pAction->text());
    }
    /*****************************
    * 初始化设备
    ******************************/
    emit initializesTheDeviceStateListSignal(channelCount,channelLabels);
}

void MainWindow::hideTheWindow()
{
    foreach (auto window, Channel_Data_From_Map.values()) {
        if(Channel_Data_Form *pFrom=qobject_cast<Channel_Data_Form*>(window)){
            /*****************************
            * 通道数据窗口
            ******************************/
            pFrom->setVisible(false);
        }
        else if (Equipment_State_From *pFrom=qobject_cast<Equipment_State_From*>(window)) {
            /*****************************
            * 通道状态窗口
            ******************************/
            pFrom->setVisible(false);
        }
    }
}

void MainWindow::initStatusBar()
{
    if(permanentWidget!=nullptr){
        permanentWidget->setText(tr("The system is ready"));
        permanentWidget->setStyleSheet("color: rgb(0, 85, 255);");
        ui->statusBar->addPermanentWidget(permanentWidget);
    }
}

void MainWindow::setStatusBar(QString msg)
{
    if(permanentWidget!=nullptr){
        permanentWidget->setText(msg);
    }
}

void MainWindow::actionTiggeredSlot()
{
    QAction* pAction=qobject_cast<QAction*> (sender());

    QMap<QAction*,int>::const_iterator it =Channel_Data_Action_Map.find(pAction);
    if(it!=Channel_Data_Action_Map.end()){

        int number=it.value();
        if(channelSelect!=number)
        {
            channelSelect=number;
            hideTheWindow();

            if(Channel_Data_Form *pFrom=qobject_cast<Channel_Data_Form*>(Channel_Data_From_Map.value(number)))
            {
                setStatusBar(pAction->text());
                pFrom->setVisible(true);
            }
            else if(Equipment_State_From *pFrom=qobject_cast<Equipment_State_From*>(Channel_Data_From_Map.value(number)))
            {
                setStatusBar(pAction->text());
                pFrom->setVisible(true);
            }
        }
    }
}

void MainWindow::on_actionMainWindow_triggered()
{

//    if(pFrom!=nullptr){////
//        delete  pFrom;////
//        pFrom=nullptr;////////
//    }
//    if(p_Equipment_State_From!=nullptr){////
//        delete p_Equipment_State_From;///
//        p_Equipment_State_From=nullptr;////
//    }

//    p_Equipment_State_From=new Equipment_State_From (this);/////////////////
//    ui->gridLayout_2->addWidget(p_Equipment_State_From);////////////////

//    if(p_Equipment_State_From!=nullptr){

//        hideTheWindow();
//        setStatusBar("The system is ready");

//        p_Equipment_State_From->setVisible(true);
//    }
}

void MainWindow::on_actionSystem_Settings_triggered()
{
//    if(p_Setting_From!=nullptr){

//        hideTheWindow();
//        setStatusBar("Setting system parameters");

//        p_Setting_From->setVisible(true);
//        p_Setting_From->setAttribute(Qt::WA_DeleteOnClose);
//    }
}

void MainWindow::on_actiontest_triggered()
{
    emit setDeviceStatusSignal(3,8,true);
}
