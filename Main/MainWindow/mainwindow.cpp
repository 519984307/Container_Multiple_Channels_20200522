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
        p_Channel_Data_Form->close();
        delete p_Channel_Data_Form;
        p_Channel_Data_Form=nullptr;
    }
    if(p_Setting_Form!=nullptr){        
        p_Setting_Form->close();
        delete p_Setting_Form;
        p_Setting_Form=nullptr;
    }
    if(p_Equipment_State_Form!=nullptr){
        p_Equipment_State_Form->close();
        delete p_Equipment_State_Form;
        p_Equipment_State_Form=nullptr;
    }
    if(p_Camera_List_Form!=nullptr){
        p_Camera_List_Form->close();
        delete p_Camera_List_Form;
        p_Camera_List_Form=nullptr;
    }
    if(p_DataBase_Form!=nullptr){
        p_DataBase_Form->close();
        delete p_DataBase_Form;
        p_DataBase_Form=nullptr;
    }
    if(p_Data_Log_Form!=nullptr){
        p_Data_Log_Form->close();
        delete p_Data_Log_Form;
        p_Data_Log_Form=nullptr;
    }
    if(p_Info_Log_Form!=nullptr){
        p_Info_Log_Form->close();
        delete  p_Info_Log_Form;
        p_Info_Log_Form=nullptr;
    }
}

void MainWindow::initializingObject()
{                
    /*****************************
    * @brief: 参数处理
    ******************************/
    Pointer_Processing=QSharedPointer<Processing> (new Processing (this));

    /*****************************
    * @brief: 加载通道参数
    ******************************/
    Pointer_Processing->loadChannelParameter(Parameter::ChannelNumber);

    permanentWidget=nullptr;

    p_Channel_Data_Form=nullptr;
    p_Equipment_State_Form=nullptr;
    p_Setting_Form=nullptr;
    p_Camera_List_Form=nullptr;
    p_DataBase_Form=nullptr;
    p_Data_Log_Form=nullptr;
    p_Info_Log_Form=nullptr;

    Form_Map.append(p_Channel_Data_Form);
    Form_Map.append(p_Equipment_State_Form);
    Form_Map.append(p_Setting_Form);
    Form_Map.append(p_Camera_List_Form);
    Form_Map.append(p_DataBase_Form);
    Form_Map.append(p_Data_Log_Form);
    Form_Map.append(p_Info_Log_Form);
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
        /*****************************
        * @brief: 显示主页面
        ******************************/
        connect(p_Setting_Form,SIGNAL(showMainWindowSignal()),this,SLOT(showMainWindowSlot()));
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
    channelCount=Parameter::ChannelNumber;

    /*****************************
    * @brief: 通道配置文件个数
    ******************************/
    pointerCount=Pointer_Processing->ParmeterList.count();

    int key=0x30;
    for (int channel=1;channel<=channelCount;channel++) {

        QString name=tr("%1 # Channel").arg(channel,2,10,QChar('0'));

        /*****************************
        * @brief: 读取通道参数别名
        ******************************/
        if(pointerCount>=channel && Pointer_Processing->ParmeterList[channel-1]->Alias!=QString("")){
            name=Pointer_Processing->ParmeterList[channel-1]->Alias;
        }

        QAction *pAction=new QAction (name,this);
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

        /*****************************
        * @brief: 读取通道参数别名
        ******************************/

        int channel_number=it.value();
        if(pointerCount>=it.value() && Pointer_Processing->ParmeterList[it.value()-1]->Channel_number!=0){
            channel_number=Pointer_Processing->ParmeterList[it.value()-1]->Channel_number;
        }

        p_Channel_Data_Form=new Channel_Data_Form (it.key()->text(),channel_number,this);
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

void MainWindow::on_actionData_log_triggered()
{
    if(p_Data_Log_Form==nullptr){

        removeTheWindow();

        p_Data_Log_Form=new Data_Log_Form (nullptr);
        ui->gridLayout_2->addWidget(p_Data_Log_Form);
        p_Data_Log_Form->setVisible(true);

        /*****************************
        * 初始化通道
        ******************************/
        formConnet();

        setStatusBar(tr("TCP network data exchange"));
    }
    else {
        qDebug()<<p_Data_Log_Form;
    }
}

void MainWindow::on_actionInfo_log_triggered()
{
    if(p_Info_Log_Form==nullptr){

        removeTheWindow();

        p_Info_Log_Form=new Info_Log_Form (nullptr);
        ui->gridLayout_2->addWidget(p_Info_Log_Form);
        p_Info_Log_Form->setVisible(true);

        /*****************************
        * 初始化通道
        ******************************/
        formConnet();

        setStatusBar(tr("System operation information"));
    }
    else {
        qDebug()<<p_Info_Log_Form;
    }
}

void MainWindow::showMainWindowSlot()
{
    on_actionMainWindow_triggered();
}
