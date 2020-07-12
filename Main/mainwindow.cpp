#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    getScreenInfo();

    initializingObject();
    initStatusBar();
    initializationParameter();
    mainConnect();

    on_actionMainWindow_triggered();
}

MainWindow::~MainWindow()
{
    clearnContainer();

    delete ui;
}

void MainWindow::clearnContainer()
{
    /*****************************
    * 删除所有窗口对象
    ******************************/

    Channel_Data_Action_Map.clear();
}

void MainWindow::getScreenInfo()
{
    QDesktopWidget* desktop=QApplication::desktop();
    QRect rect=desktop->screenGeometry();
    this->resize(QSize(rect.width(),rect.height()));
}

void MainWindow::removeTheWindow()
{
    if(p_Channel_Data_Form!=nullptr){
        delete p_Channel_Data_Form;
        p_Channel_Data_Form=nullptr;
    }
    if(p_Setting_From!=nullptr){
        delete p_Setting_From;
        p_Setting_From=nullptr;
    }
    if(p_Equipment_State_From!=nullptr){
        delete p_Equipment_State_From;
        p_Equipment_State_From=nullptr;
    }
}

void MainWindow::initStatusBar()
{
    if(permanentWidget==nullptr){
        permanentWidget = new QLabel (tr("The system is ready"),this);
    }
    permanentWidget->setStyleSheet("color: rgb(0, 85, 255);");
    ui->statusBar->addPermanentWidget(permanentWidget);
}

void MainWindow::initializingObject()
{
    p_Channel_Data_Form=nullptr;
    p_Equipment_State_From=nullptr;
    p_Setting_From=nullptr;
    permanentWidget=nullptr;
}

void MainWindow::mainConnect()
{
    foreach (auto action, Channel_Data_Action_Map.keys()) {
        /*****************************
        * 绑定工具栏按钮事件
        ******************************/
        connect(action,SIGNAL(triggered()),this,SLOT(actionTiggeredSlot()));
    }
}

void MainWindow::fromConnet()
{
    if(p_Equipment_State_From!=nullptr){

        /*****************************
        * 初始化通道状态
        ******************************/
        connect(this,SIGNAL(initializesTheDeviceStateListSignal(int,QStringList)),p_Equipment_State_From,SLOT(initializesTheDeviceStateListSlot(int,QStringList)));

        /*****************************
        * 设置通道设备状态
        ******************************/
        connect(this,SIGNAL(setDeviceStatusSignal(int,int,bool)),p_Equipment_State_From,SLOT(setDeviceStatusSlot(int,int,bool)));
    }

    if(p_Setting_From!=nullptr){
        /*****************************
        * 初始化设置窗口通道设备列表
        ******************************/
        connect(this,SIGNAL(initializesTheDeviceStateListSignal(int,QStringList)),p_Setting_From,SLOT(initializesTheDeviceListSlot(int,QStringList)));
    }
}

void MainWindow::initializationParameter()
{
    channelSelect=0;
    channelCount=10;

    int key=0x30;
    for (int channel=1;channel<=channelCount;channel++) {
        QAction *pAction=new QAction (tr("%1 # Channel").arg(channel,2,10,QChar('0')),this);
        pAction->setIcon(QIcon(":/UI_ICO/ICO/container.svg"));
        pAction->setShortcut(QKeySequence(Qt::CTRL+static_cast<uint16_t>(key+channel)));
        pAction->setToolTip(tr("Channel switching (CTRL+%1)").arg(channel));

        Channel_Data_Action_Map.insert(pAction,channel);

        /*****************************
        * 添加通道切换到菜单栏
        ******************************/
        ui->menuChannel_To_View->addAction(pAction);

        /*****************************
        * 添加通道切换到工具栏
        ******************************/
        ui->mainToolBar->addAction(pAction);

        channelLabels.append(pAction->text());
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

    /*****************************
    * 预览通道没有切换,就不做处理(channelSelect)
    ******************************/
    if(it!=Channel_Data_Action_Map.end() && it.value()!=channelSelect){

        removeTheWindow();

        channelSelect=it.value();

        p_Channel_Data_Form=new Channel_Data_Form (this);
        ui->gridLayout_2->addWidget(p_Channel_Data_Form);
        p_Channel_Data_Form->setVisible(true);

        setStatusBar(tr("The preview page %1").arg( it.key()->text()));
    }
    else {
        qDebug()<<p_Channel_Data_Form;
    }
}

void MainWindow::on_actionMainWindow_triggered()
{
    if(p_Equipment_State_From==nullptr){

        removeTheWindow();

        p_Equipment_State_From=new Equipment_State_From (this);
        ui->gridLayout_2->addWidget(p_Equipment_State_From);
        p_Equipment_State_From->setVisible(true);

        /*****************************
        * 初始化设备
        ******************************/
        fromConnet();
        emit initializesTheDeviceStateListSignal(channelCount,channelLabels);

        channelSelect=0;

        setStatusBar("The system is ready");
    }
    else {
        qDebug()<<p_Equipment_State_From;
    }
}

void MainWindow::on_actionSystem_Settings_triggered()
{
    if(p_Setting_From==nullptr){

        removeTheWindow();

        p_Setting_From=new Setting_Form (this);
        ui->gridLayout_2->addWidget(p_Setting_From);
        p_Setting_From->setVisible(true);

        /*****************************
        * 初始化通道
        ******************************/
        fromConnet();
        emit initializesTheDeviceStateListSignal(channelCount,channelLabels);

        setStatusBar("Setting system parameters");
    }
    else {
        qDebug()<<p_Setting_From;
    }
}

void MainWindow::on_actiontest_triggered()
{
    emit setDeviceStatusSignal(3,8,true);
}
