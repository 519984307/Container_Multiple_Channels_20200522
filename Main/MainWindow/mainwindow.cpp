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

void MainWindow::getScreenInfo()
{
    QRect rect=QGuiApplication::screens().at(0)->geometry();
    this->resize(QSize(rect.width(),rect.height()));
}

void MainWindow::clearnContainer()
{
    /*****************************
    * 删除所有窗口对象
    ******************************/
    qDeleteAll (Form_Map);
    qDeleteAll(Channel_Data_Action_Map.keys());

    Channel_Data_Action_Map.clear();
    Form_Map.clear();
}

void MainWindow::removeTheWindow()
{
    if(p_Channel_Data_Form!=nullptr){
        delete p_Channel_Data_Form;
        p_Channel_Data_Form=nullptr;
    }
    if(p_Setting_Form!=nullptr){
        delete p_Setting_Form;
        p_Setting_Form=nullptr;
    }
    if(p_Equipment_State_Form!=nullptr){
        delete p_Equipment_State_Form;
        p_Equipment_State_Form=nullptr;
    }
    if(p_Camera_List_Form!=nullptr){
        delete p_Camera_List_Form;
        p_Camera_List_Form=nullptr;
    }
    if(p_DataBase_Form!=nullptr){
        delete p_DataBase_Form;
        p_DataBase_Form=nullptr;
    }
    if(p_Communication_Logs_Form!=nullptr){
        delete p_Communication_Logs_Form;
        p_Communication_Logs_Form=nullptr;
    }
    if(p_Operational_Log_Form!=nullptr){
        delete p_Operational_Log_Form;
        p_Operational_Log_Form=nullptr;
    }
    if(p_Identify_The_Log_Form!=nullptr){
        delete p_Identify_The_Log_Form;
        p_Identify_The_Log_Form=nullptr;
    }
}

void MainWindow::initializingObject()
{    
    permanentWidget=nullptr;

    p_Channel_Data_Form=nullptr;
    p_Equipment_State_Form=nullptr;
    p_Setting_Form=nullptr;
    p_Camera_List_Form=nullptr;
    p_DataBase_Form=nullptr;
    p_Communication_Logs_Form=nullptr;
    p_Identify_The_Log_Form=nullptr;
    p_Operational_Log_Form=nullptr;

    Form_Map.append(p_Channel_Data_Form);
    Form_Map.append(p_Equipment_State_Form);
    Form_Map.append(p_Setting_Form);
    Form_Map.append(p_Camera_List_Form);
    Form_Map.append(p_DataBase_Form);
    Form_Map.append(p_Communication_Logs_Form);
    Form_Map.append(p_Identify_The_Log_Form);
    Form_Map.append(p_Operational_Log_Form);
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

void MainWindow::formConnet()
{
    if(p_Equipment_State_Form!=nullptr){

        /*****************************
        * 初始化通道状态
        ******************************/
        connect(this,SIGNAL(initializesTheDeviceStateListSignal(int,QStringList)),p_Equipment_State_Form,SLOT(initializesTheDeviceStateListSlot(int,QStringList)));

        /*****************************
        * 设置通道设备状态
        ******************************/
        connect(this,SIGNAL(setDeviceStatusSignal(int,int,bool)),p_Equipment_State_Form,SLOT(setDeviceStatusSlot(int,int,bool)));
    }

    if(p_Setting_Form!=nullptr){
        /*****************************
        * 初始化设置窗口通道设备列表
        ******************************/
        connect(this,SIGNAL(initializesTheDeviceStateListSignal(int,QStringList)),p_Setting_Form,SLOT(initializesTheDeviceListSlot(int,QStringList)));
    }

    if(p_Camera_List_Form!=nullptr){
        /*****************************
       * 初始化通道列表
       ******************************/
        connect(this,SIGNAL(initializesTheDeviceStateListSignal(int,QStringList)),p_Camera_List_Form,SLOT(initializesTheDeviceListSlot(int,QStringList)));
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

        /*****************************
       * 通道组
       ******************************/
        channelLabels.append(pAction->text());
    }
}

void MainWindow::setStatusBar(const QString &msg)
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
    if(p_Equipment_State_Form==nullptr){

        removeTheWindow();

        p_Equipment_State_Form=new Equipment_State_From (this);
        ui->gridLayout_2->addWidget(p_Equipment_State_Form);
        p_Equipment_State_Form->setVisible(true);

        /*****************************
        * 初始化设备
        ******************************/
        formConnet();
        emit initializesTheDeviceStateListSignal(channelCount,channelLabels);

        channelSelect=0;

        setStatusBar(tr("The system is ready"));
    }
    else {
        qDebug()<<p_Equipment_State_Form;
    }
}

void MainWindow::on_actionParameter_Settings_triggered()
{
    if(p_Setting_Form==nullptr){

        removeTheWindow();

        p_Setting_Form=new Setting_Form (this);
        ui->gridLayout_2->addWidget(p_Setting_Form);
        p_Setting_Form->setVisible(true);

        /*****************************
        * 初始化通道
        ******************************/
        formConnet();
        emit initializesTheDeviceStateListSignal(channelCount,channelLabels);

        setStatusBar(tr("Setting system parameters"));
    }
    else {
        qDebug()<<p_Setting_Form;
    }
}

void MainWindow::on_actionCamera_Test_triggered()
{
    if(p_Camera_List_Form==nullptr){

        removeTheWindow();

        p_Camera_List_Form=new Camera_List_Form (this);
        ui->gridLayout_2->addWidget(p_Camera_List_Form);
        p_Camera_List_Form->setVisible(true);

        /*****************************
        * 初始化设备
        ******************************/
        formConnet();
        emit initializesTheDeviceStateListSignal(channelCount,channelLabels);

        channelSelect=0;

        setStatusBar(tr("The camera debug"));
    }
    else {
        qDebug()<<p_Camera_List_Form;
    }
}

void MainWindow::on_actionHistory_Sqlite_triggered()
{
    if(p_DataBase_Form==nullptr){

        removeTheWindow();

        p_DataBase_Form=new DataBase_Form (this);
        ui->gridLayout_2->addWidget(p_DataBase_Form);
        p_DataBase_Form->setVisible(true);


        channelSelect=0;

        setStatusBar(tr("Data query interface"));
    }
    else {
        qDebug()<<p_DataBase_Form;
    }
}

void MainWindow::on_actionOperational_log_triggered()
{
    if(p_Operational_Log_Form==nullptr){

        removeTheWindow();

        p_Operational_Log_Form=new Operational_Log_Form (this);
        ui->gridLayout_2->addWidget(p_Operational_Log_Form);
        p_Operational_Log_Form->setVisible(true);


        channelSelect=0;

        setStatusBar(tr("System operation and maintenance log"));
    }
    else {
        qDebug()<<p_Operational_Log_Form;
    }
}

void MainWindow::on_actionIdentify_the_log_triggered()
{
    if(p_Identify_The_Log_Form==nullptr){

        removeTheWindow();

        p_Identify_The_Log_Form=new Identify_The_Log_Form (this);
        ui->gridLayout_2->addWidget(p_Identify_The_Log_Form);
        p_Identify_The_Log_Form->setVisible(true);


        channelSelect=0;

        setStatusBar(tr("Identification result log"));
    }
    else {
        qDebug()<<p_Identify_The_Log_Form;
    }
}

void MainWindow::on_actionCommunication_log_triggered()
{
    if(p_Communication_Logs_Form==nullptr){

        removeTheWindow();

        p_Communication_Logs_Form=new Communication_Logs_Form (this);
        ui->gridLayout_2->addWidget(p_Communication_Logs_Form);
        p_Communication_Logs_Form->setVisible(true);


        channelSelect=0;

        setStatusBar(tr("System communication log"));
    }
    else {
        qDebug()<<p_Communication_Logs_Form;
    }
}
