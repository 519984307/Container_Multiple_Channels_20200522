#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPointer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initializingObject();
    initializationParameter();
    mainConnect();
    createSystemTrayMenu();
    getScreenInfo();

    isExit=false;
}

MainWindow::~MainWindow()
{    
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(isExit){
        clearnContainer();
        event->accept();
    }
    else {
        event->ignore();
        hide();
        SystemTray->showMessage(LocalPar::name,tr("The program is running in the background, if you want to exit, please exit from the taskbar!"),QSystemTrayIcon::Information,3000);
    }
}

void MainWindow::changeEvent(QEvent *event)
{
    if (this->windowState()==Qt::WindowMinimized) {
        this->hide();
    }

    QWidget::changeEvent(event);
}

void MainWindow::clearnContainer()
{
    /*****************************
    * 删除所有窗口对象
    ******************************/
    qDeleteAll (Form_Map);
    qDeleteAll (Channel_Data_Action_Map.keys());

    Channel_Data_Action_Map.clear();
    Form_Map.clear();
}

void MainWindow::getScreenInfo()
{
    setWindowState(Qt::WindowMaximized);

    QPointer<QMenu> systemTrayMen(new QMenu(this));
    systemTrayMen->addAction(actionShow);
    systemTrayMen->addAction(actionExit);

    SystemTray=QPointer<QSystemTrayIcon>  (new QSystemTrayIcon(this));
    SystemTray->setContextMenu(systemTrayMen);
    SystemTray->setIcon(QIcon(":/UI_ICO/ICO/ICO.ico"));
    SystemTray->setToolTip(LocalPar::name);
    SystemTray->show();

    connect(SystemTray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(systemTrayTriggered(QSystemTrayIcon::ActivationReason)));

    if(Parameter::Minimization){
        this->hide();

        SystemTray->showMessage(LocalPar::name,LocalPar::msg,QSystemTrayIcon::Information,3000);

    }else {
        if(Parameter::FullScreen){
            this->showFullScreen();
        }
        else {
            this->show();
            setWindowState(Qt::WindowMaximized);
        }
    }

}

void MainWindow::createSystemTrayMenu()
{
    actionShow=new QAction(tr("Display window"),this);
    connect(actionShow,SIGNAL(triggered()),this,SLOT(systemTrayAction()));

    actionExit=new QAction(tr("Exit the program"),this);
    connect(actionExit,SIGNAL(triggered()),this,SLOT(systemTrayAction()));
}

void MainWindow::initializingObject()
{                
    permanentLabel=nullptr;
    runTimeLabel=nullptr;
    throughTheNumberLabel=nullptr;
    hardDriveCapacityLabel=nullptr;
    socketLinkCountLabel=nullptr;

    p_Equipment_State_Form=nullptr;
    p_Data_Log_Form=new Data_Log_Form (nullptr);

    Form_Map.append(p_Equipment_State_Form);
    Form_Map.append(p_Data_Log_Form);        
}

void MainWindow::mainConnect()
{
    QList<int> actList=Channel_Data_Action_Map.values();
    std::sort(actList.begin(),actList.end());
    foreach (auto ind, actList) {
        /*****************************
        * 绑定工具栏按钮事件
        ******************************/
        connect(Channel_Data_Action_Map.key(ind),SIGNAL(triggered()),this,SLOT(actionTiggeredSlot()));

        /*****************************
        * 添加通道到菜单栏
        ******************************/
        ui->menuChannel_To_View->addAction(Channel_Data_Action_Map.key(ind));

        /*****************************
        * 添加通道到工具栏
        ******************************/
        ui->mainToolBar->addAction(Channel_Data_Action_Map.key(ind));
    }

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

    /*****************************
    * 初始化设备
    ******************************/
    emit initializesTheDeviceStateListSignal(channelCount,channelLabels);
}

void MainWindow::initializationParameter()
{
    /*****************************
    * @brief: 参数处理
    ******************************/
    Pointer_Processing=QSharedPointer<Processing> (new Processing (this));

    /*****************************
    * @brief:加载系统参数
    ******************************/
    Pointer_Processing->loadParameter();

    /*****************************
    * @brief: 加载通道参数
    ******************************/
    Pointer_Processing->loadChannelParameter(Parameter::ChannelNumber);

    /*****************************
    * @brief: 加载插件
    ******************************/
    //pLoadingLibaray=new LoadingLibaray(Parameter::ChannelNumber,this);

    int key=0x30;
    channelSelect=0;
    channelCount=Parameter::ChannelNumber;
    /*****************************
    * @brief: 通道配置文件个数
    ******************************/
    channelParCount=Pointer_Processing->ParmeterMap.count();

    if(channelCount>1){
        /*****************************
        * @brief:多通道显示主页面，工具栏编号(0)
        ******************************/
        QAction *pAction=new QAction (tr("Main"),this);
        pAction->setIcon(QIcon(":/UI_ICO/ICO/main-fill.svg"));
        pAction->setShortcut(QKeySequence(Qt::CTRL+static_cast<uint16_t>(key+'A')));
        pAction->setToolTip(tr("Channel switching (CTRL+%1)").arg("A"));

        Channel_Data_Action_Map.insert(pAction,0);
        p_Equipment_State_Form=new Equipment_State_From(this);

        ui->gridLayout_2->addWidget(p_Equipment_State_Form);
        p_Equipment_State_Form->setVisible(true);
        setStatusBar(tr("System ready"));
    }

    for (int channel=1;channel<=channelCount;channel++) {
        /*****************************
        * @brief:默认通道别名
        ******************************/
        QString name=tr("%1 # Channel").arg(channel,2,10,QChar('0'));
        /*****************************
        * @brief:默认通道号
        ******************************/
        int channel_number=channel;
        /*****************************
        * @brief: 读取通道参数别名
        ******************************/
        if(channelParCount>=channel && !Pointer_Processing->ParmeterMap[channel]->Alias.isEmpty()){
            name=Pointer_Processing->ParmeterMap[channel]->Alias;
        }

        QAction *pAction=new QAction (name,this);
        pAction->setIcon(QIcon(":/UI_ICO/ICO/container.svg"));
        pAction->setShortcut(QKeySequence(Qt::CTRL+static_cast<uint16_t>(key+channel)));
        pAction->setToolTip(tr("Channel switching (CTRL+%1)").arg(channel));

        Channel_Data_Action_Map.insert(pAction,channel);

        /*****************************
        * @brief:数据窗口
        ******************************/
        if(channelParCount>=channel && 0!=Pointer_Processing->ParmeterMap[channel]->Channel_number){
            channel_number=Pointer_Processing->ParmeterMap[channel]->Channel_number;
        }
        Channel_Data_Form *p_Channel_Data_Form=new Channel_Data_Form(name,channel_number,this);
        Channel_Data_From_Map.insert(channel,p_Channel_Data_Form);
        ui->gridLayout_2->addWidget(p_Channel_Data_Form);

        if(nullptr==p_Equipment_State_Form && 1==channel){
            p_Channel_Data_Form->setVisible(true);
            setStatusBar(tr("The preview page %1").arg(name));
            channelSelect=1;
        }

        /*****************************
        * 通道名数组
        ******************************/
        channelLabels.append(pAction->text());
    }
}

void MainWindow::setStatusBar(const QString &msg)
{    
    if(runTimeLabel==nullptr){
        runTimeLabel=new QLabel("0 H 0 M 0 S",this);
        ui->statusBar->addPermanentWidget(runTimeLabel);
    }
    if(throughTheNumberLabel==nullptr){
        throughTheNumberLabel=new QLabel("0 Car",this);
        ui->statusBar->addPermanentWidget(throughTheNumberLabel);
    }
    if(hardDriveCapacityLabel==nullptr){
        hardDriveCapacityLabel=new QLabel("0 Mb",this);
        ui->statusBar->addPermanentWidget(hardDriveCapacityLabel);
    }
    if(socketLinkCountLabel==nullptr){
        socketLinkCountLabel=new QLabel("0 Machines",this);
        socketLinkCountLabel->setStyleSheet("color: rgb(255, 0, 0);background-color: rgb(226, 226, 226);");
        ui->statusBar->addPermanentWidget(socketLinkCountLabel);
    }
    if(permanentLabel==nullptr){
        permanentLabel = new QLabel (tr("System ready"),this);
        ui->statusBar->addPermanentWidget(permanentLabel);
    }

    permanentLabel->setText(msg);

}

void MainWindow::systemTrayAction()
{
    QPointer<QAction> pAction=qobject_cast<QAction*> (sender());
    if(pAction==actionShow){
        setWindowState(Qt::WindowMaximized);
        this->show();
    }
    if(pAction==actionExit){
        //exit(0);
        isExit=true;
        this->close();
    }
}

void MainWindow::systemTrayTriggered(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
        break;
    case QSystemTrayIcon::DoubleClick:
        setWindowState(Qt::WindowMaximized);
        this->show();
        break;
    default:
        break;
    }
}

void MainWindow::actionTiggeredSlot()
{
    QPointer<QAction> pAction=qobject_cast<QAction*> (sender());

    QMap<QAction*,int>::const_iterator it =Channel_Data_Action_Map.find(pAction);

    /*****************************
    * 预览通道没有切换,就不做处理(channelSelect)
    ******************************/
    if(it!=Channel_Data_Action_Map.end() && it.value()!=channelSelect){

        channelSelect=it.value();

        foreach (Channel_Data_Form* form, Channel_Data_From_Map.values()) {
            form->setVisible(false);
        }
        if(nullptr!=p_Equipment_State_Form){
            p_Equipment_State_Form->setVisible(false);
        }

        if(0==channelSelect){
            if(nullptr!=p_Equipment_State_Form){
                p_Equipment_State_Form->setVisible(true);
                setStatusBar(tr("System ready"));
            }
        }

        if(nullptr!= Channel_Data_From_Map.value(channelSelect,nullptr)){
            Channel_Data_From_Map[channelSelect]->setVisible(true);
            setStatusBar(tr("The preview page %1").arg( it.key()->text()));
        }
    }    
}

void MainWindow::on_actionParameter_Settings_triggered()
{
    QPointer<Setting_Form> p_Setting_Form=new Setting_Form (nullptr);
    connect(this,SIGNAL(initializesTheDeviceStateListSignal(int,QStringList)),p_Setting_Form,SLOT(initializesTheDeviceListSlot(int,QStringList)));
    /*****************************
    * 初始化设备
    ******************************/
    emit initializesTheDeviceStateListSignal(channelCount,channelLabels);
    p_Setting_Form->setWindowModality(Qt::ApplicationModal);
    p_Setting_Form->show();
}

void MainWindow::on_actionCamera_Test_triggered()
{
    QPointer<Camera_List_Form> p_Camera_List_Form=new Camera_List_Form (nullptr);
    connect(this,SIGNAL(initializesTheDeviceStateListSignal(int,QStringList)),p_Camera_List_Form,SLOT(initializesTheDeviceListSlot(int,QStringList)));
    /*****************************
    * 初始化设备
    ******************************/
    emit initializesTheDeviceStateListSignal(channelCount,channelLabels);
    p_Camera_List_Form->setWindowModality(Qt::ApplicationModal);
    p_Camera_List_Form->show();
}

void MainWindow::on_actionHistory_Sqlite_triggered()
{
    QPointer<DataBase_Form> p_DataBase_Form=new DataBase_Form (nullptr);
    p_DataBase_Form->setWindowModality(Qt::ApplicationModal);
    p_DataBase_Form->show();
}

void MainWindow::on_actionData_log_triggered()
{
    if(p_Data_Log_Form!=nullptr){
        if(p_Data_Log_Form->isVisible()){
            p_Data_Log_Form->setVisible(false);
        }
        p_Data_Log_Form->setVisible(true);
    }
}

void MainWindow::on_actionExit_triggered()
{
    isExit=true;
    this->close();
}
