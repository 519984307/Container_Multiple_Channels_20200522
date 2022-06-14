#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initializingObject();
    initializationParameter();
    connectProcess();
    getScreenInfo();
    loadStyleSheet(":/qss/style.qss");
}

MainWindow::~MainWindow()
{
    //delete pLoadinglibaray;
    if(getDiskFreeTimer!=nullptr){
        getDiskFreeTimer->stop();
    }

    if(systemRunTime!=nullptr){
        systemRunTime->stop();
    }

    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(isExit){
        SystemTray->showMessage(LocalPar::copyright,tr("系统正在释放内部资源，请稍后"),QSystemTrayIcon::Information,60000);

        this->hide();

        clearnContainer();
        event->accept();
        QWidget::closeEvent(event);
        //exit(0);
    }
    else {
        event->ignore();
        hide();
        SystemTray->showMessage(LocalPar::copyright,tr("The program is running in the background, if you want to exit, please exit from the taskbar!"),QSystemTrayIcon::Information,3000);
    }
}

void MainWindow::changeEvent(QEvent *event)
{
    if(event->type()==QEvent::WindowStateChange && this->windowState()==Qt::WindowMinimized){
        hide();
    }
    QWidget::changeEvent(event);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);

    if(pErrorForm!=nullptr){
        int w=this->geometry().width();
        pErrorForm->setGeometry(0,30,w,50);
    }
}

void MainWindow::initializing()
{
    /*****************************
    * @brief:设置海康相机抓拍模式
    ******************************/
    emit signal_setCameraCaptureType(Parameter::HCNET_Capture_Type+1,0);

    /*****************************
    * @brief:初始化海康动态库
    ******************************/
    emit signal_initializationParameter();

    /*****************************
    * @brief:设置海康车牌抓拍模式（车牌抓拍默认3，回调函数默认1）
    ******************************/
    emit signal_setPlateCaptureType(3,1);

    /*****************************
    * @brief:登录相机
    ******************************/
    emit signal_initEquipment();

    QStringList tcpAddr;
    if(Parameter::DataChaneType==0){
        if(Parameter::Service_Type){
            tcpAddr.append(Parameter::SingletonAddress);
        }
        else {
            tcpAddr.append(Parameter::ManyCasesAddress.split(","));
        }
    }
    else if (Parameter::DataChaneType==1) {
        if(Parameter::Service_Type){
            tcpAddr.append(Parameter::SingletonAddressMQ);
        }
        else {
            tcpAddr.append(Parameter::ManyCasesAddressMQ.split(","));
        }
    }

    if(Parameter::Interface_Model==1){
        for (int i=0;i<Parameter::ChannelNumber;i++) {
            DataProcessingList.at(i).data()->signal_InitializationParameter(Parameter::HttpAddr,-1,Parameter::Service_Type,Parameter::Heartbeat,Parameter::Service_Model,Parameter::ShortLink,Parameter::newline);
        }
    }
    else {
        for (int var = 0; var < tcpAddr.size(); ++var) {
            if(var<DataProcessingList.size()){
                QStringList addrTmp=tcpAddr.at(var).split(":");
                if(addrTmp.size()>=2){
                    DataProcessingList.at(var).data()->signal_InitializationParameter(addrTmp[0],static_cast<quint16>(addrTmp[1].toUInt()),Parameter::Service_Type,Parameter::Heartbeat,Parameter::Service_Model,Parameter::ShortLink,Parameter::newline);
                }
                else {
                    qCritical().noquote()<<"Error setting network service address or port";
                }
            }
        }
    }

    /*****************************
    * @brief:初始化FTP
    ******************************/
    emit signal_InitializationFTPParameter(Parameter::FtpUser,Parameter::FtpPassword,Parameter::FtpRemotePath,Parameter::FtpTimeDIC,Parameter::FtpAddress,Parameter::FtpPort);

    /*****************************
    * @brief:初始化加密,默认单通道，不比对加密狗
    ******************************/
    emit signal_initEncryption(LocalPar::Channels,"");

    /*****************************
    * @brief:初始化数据库
    ******************************/
    emit signal_initDataBaseR(QString::number(0),Parameter::databaseUser,Parameter::databasePass,Parameter::databaseAddr,Parameter::DatabaseType);

    linkCount=0;

    /*****************************
    * @brief:获取硬盘空间
    ******************************/
    getDiskFreeTimer = new QTimer(this);
    getDiskFreeTimer->setSingleShot(false);
    connect(getDiskFreeTimer,SIGNAL(timeout()),this,SLOT(slot_getDiskFreeSpace()));
    QTimer::singleShot(3000,this,SLOT(slot_getDiskFreeSpace()));
    getDiskFreeTimer->start(600000);


    runTime=QDateTime::currentDateTime();
    /*****************************
    * @brief:系统运行时长
    ******************************/
    systemRunTime=new QTimer(this);
    systemRunTime->setSingleShot(false);
    connect(systemRunTime,SIGNAL(timeout()),this,SLOT(slot_systemRunTimer()));
    QTimer::singleShot(3000,this,SLOT(slot_getDiskFreeSpace()));
    systemRunTime->start(5000);

    /*****************************
    * @brief:数据接口统计
    ******************************/
    slot_connectCount(0);

    /*****************************
    * @brief:流量统计
    ******************************/
//    QString start=QString("%1 %2").arg(QDate::currentDate().toString("yyyy/MM/dd")).arg(QTime(0,0,0).toString("HH:mm:ss"));
//    QString end=QString("%1 %2").arg(QDate::currentDate().toString("yyyy/MM/dd")).arg(QTime(23,59,59).toString("HH:mm:ss"));

//    QString filterTimer=QString("((Timer>='%1' AND Timer<='%2'))").arg(start,end);
//    QString filterType=QString("Type!='%1'").arg(-1);
//    QStringList filterList;
//    filterList.append(filterTimer);
//    filterList.append(filterType);
//    emit signal_setDataBaseFilter(filterList.join(" AND "));
    slot_statisticalData(0,0,0,0);

    /*****************************
    * @brief:接口插件设置图片路径，用于Http上传图片
    * 202206132311-程玉良
    ******************************/
    emit signal_SetImagePath(Parameter::ImagePath,Parameter::ImageFormat,Parameter::ImageNamingRules,Parameter::channel_id_placeholder,Parameter::camera_id_placeholder);
}

void MainWindow::clearnContainer()
{
//    delete  pUpload;
//    pUpload=nullptr;

    emit signal_releaseResources();
    emit signal_destructorThread();

    foreach (auto thread, tdList) {
        thread->quit();
        thread->wait();
    }

    //watcher->cancel();
    //p_Data_Log_Form.data()->close();

    /*****************************
    * 删除所有窗口对象
    ******************************/
//    qDeleteAll (Form_Map);
//    qDeleteAll (From_Action_Map.keys());
//    qDeleteAll (Channel_Data_From_Map.values());

    if(p_Data_Log_Form!=nullptr){
         p_Data_Log_Form->close();
    }


    Channel_Data_From_Map.clear();
    From_Action_Map.clear();
    Form_Map.clear();   
    DataProcessingList.clear();
}

void MainWindow::getScreenInfo()
{
    actionShow=new QAction(tr("Display window"),this);
    connect(actionShow,SIGNAL(triggered()),this,SLOT(systemTrayAction()));

    actionExit=new QAction(tr("Exit the program"),this);
    connect(actionExit,SIGNAL(triggered()),this,SLOT(systemTrayAction()));

    systemTrayMen=QPointer<QMenu>(new QMenu(this));
    systemTrayMen->addAction(actionShow);
    systemTrayMen->addAction(actionExit);

    SystemTray=QPointer<QSystemTrayIcon>(new QSystemTrayIcon(this));
    SystemTray->setContextMenu(systemTrayMen.data());
    SystemTray->setIcon(QIcon(":/UI_ICO/ICO/ICO.ico"));
    SystemTray->setToolTip(LocalPar::copyright);
    SystemTray->show();

    connect(SystemTray.data(),SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(systemTrayTriggered(QSystemTrayIcon::ActivationReason)));

    if(Parameter::Minimization){
        this->hide();
        SystemTray->showMessage(LocalPar::copyright,LocalPar::msg,QSystemTrayIcon::Information,3000);

    }else {
        if(Parameter::FullScreen){
            this->showFullScreen();
        }
        else {
            this->show();
            this->hide();
            this->setWindowState(Qt::WindowMaximized);
            this->show();
        }
    }
}

void MainWindow::initializingObject()
{    
    qRegisterMetaType<QList<int>>("QList<int>");
    qRegisterMetaType<QtMsgType>("QtMsgType");
    qRegisterMetaType<QMap<QString,QString>>("QMap<QString,QString>");
    qRegisterMetaType<QMap<QString,QString>>("QMap<QString,QMap<QString,QString>>");
    qRegisterMetaType<QMap<int,QString>>("QMap<int,QString>");
    pLog=QPointer<LogController>(new LogController(LocalPar::App,this));

    pErrorForm=QPointer<ErrorForm>(new ErrorForm(this));

    p_Data_Log_Form=QSharedPointer<Data_Log_Form>(new Data_Log_Form (nullptr));
    //p_Data_Log_Form->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    p_Data_Log_Form.data()->setWindowModality(Qt::NonModal  );

    connect(pLog.data(),SIGNAL(signal_newLogText(QtMsgType,QDateTime,QString)),p_Data_Log_Form.data(),SLOT(slot_newLogText(QtMsgType,QDateTime,QString)));

    statusProgressBar=new QProgressBar (this);
    statusProgressBar->setFixedWidth(400);
    statusProgressBar->setStyleSheet("color: rgb(0, 0, 0);");
    statusProgressBar->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);

    permanentLabel=new QLabel (tr("System ready"),this);
    runTimeLabel=new QLabel("0 H 0 M 0 S",this);
    throughTheNumberLabel=new QLabel("0 Car",this);
    hardDriveCapacityLabel=new QLabel("0 Mb",this);
    socketLinkCountLabel=new QLabel("0 Machines [Server]",this);

    permanentLabel->setStyleSheet("background-color: rgb(0, 85, 0);");

    ui->statusBar->insertPermanentWidget(0,statusProgressBar);
    ui->statusBar->insertPermanentWidget(1,permanentLabel);
    ui->statusBar->insertPermanentWidget(2,socketLinkCountLabel);
    ui->statusBar->insertPermanentWidget(3,hardDriveCapacityLabel);
    ui->statusBar->insertPermanentWidget(4,throughTheNumberLabel);
    ui->statusBar->insertPermanentWidget(5,runTimeLabel);

    p_Equipment_State_Form=nullptr;
    Form_Map.append(p_Equipment_State_Form);

//    watcher=new QFutureWatcher<void>(this);
//    connect(watcher, SIGNAL(finished()), this, SLOT(slot_handleFinished()));
//    connect(watcher,SIGNAL(progressRangeChanged(int , int )),this,SLOT(slot_progressRangeChanged(int , int )));
//    connect(watcher,SIGNAL(progressTextChanged(const QString)),this,SLOT(slot_progressTextChanged(const QString )));
//    connect(watcher,SIGNAL(progressValueChanged(int)),this,SLOT(slot_progressValueChanged(int )));
//    QFuture<void> future =QtConcurrent::run(this,&MainWindow::loadingLibaray,Parameter::ChannelNumber);
//    watcher->setFuture(future);

    /*****************************
    * @brief:数据处理类
    ******************************/
    for (int var = 0; var < Parameter::ChannelNumber; ++var) {
        DataProcessingList.append(QSharedPointer<DataProcessing>(new DataProcessing(nullptr,Parameter::bluePlate)));
    }

    pLoadinglibaray=QSharedPointer<LoadingLibaray>(new LoadingLibaray(Parameter::ChannelNumber));
    connect(pLoadinglibaray.data(),SIGNAL(signal_handleFinished()), this, SLOT(slot_handleFinished()));
    connect(pLoadinglibaray.data(),SIGNAL(signal_progressRangeChanged(int , int )),this,SLOT(slot_progressRangeChanged(int , int )));
    connect(pLoadinglibaray.data(),SIGNAL(signal_progressTextChanged(const QString)),this,SLOT(slot_progressTextChanged(const QString )));
    connect(pLoadinglibaray.data(),SIGNAL(signal_progressValueChanged(int)),this,SLOT(slot_progressValueChanged(int )));
    connect(pLoadinglibaray.data(),SIGNAL(signal_loadPluginError(QString)),this,SLOT(slot_Error(QString)));
    connect(this,SIGNAL(signal_destructorThread()),pLoadinglibaray.data(),SLOT(slot_destructorThread()),Qt::BlockingQueuedConnection);
    connect(this,SIGNAL(signal_createLibaray()),pLoadinglibaray.data(),SLOT(slot_createLibaray()));

    QThread *th=new QThread(this);
    tdList.append(th);
    pLoadinglibaray->moveToThread(th);
    th->start();
    signal_createLibaray();    
}

void MainWindow::initializationParameter()
{
    alarmNum=0;

    isExit=false;

    /*****************************
    * @brief: 参数处理
    ******************************/
    Pointer_Parameter=QPointer<LoadParameter> (new LoadParameter (this));

    /*****************************
    * @brief:加载系统参数
    ******************************/
    Pointer_Parameter->loadSysParameter();

    /*****************************
    * @brief: 加载通道参数
    ******************************/
    Pointer_Parameter->loadChannelParameter(Parameter::ChannelNumber);

    int key=0x30;
    channelSelect=0;
    channelCount=Parameter::ChannelNumber;
    /*****************************
    * @brief: 通道配置文件个数
    ******************************/
    channelParCount=Pointer_Parameter->ParmeterMap.count();

    if(channelCount>1){
        /*****************************
        * @brief:多通道显示主页面，工具栏编号(0)
        ******************************/
        QAction *pAction=new QAction (tr("Main"),this);
        pAction->setIcon(QIcon(":/UI_ICO/ICO/main-fill.svg"));
        pAction->setShortcut(QKeySequence(Qt::CTRL+static_cast<uint16_t>(key+'A')));
        pAction->setToolTip(tr("Channel switching (CTRL+%1)").arg("A"));

        From_Action_Map.insert(pAction,0);
        p_Equipment_State_Form=new Equipment_State_From(this);

        ui->gridLayout_2->addWidget(p_Equipment_State_Form);
        p_Equipment_State_Form->setVisible(true);
        setStatusBar(0,tr("System ready"));
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
        if(channelParCount>=channel && !Pointer_Parameter->ParmeterMap.value(channel)->Alias.isEmpty()){
            name=Pointer_Parameter->ParmeterMap.value(channel)->Alias;
        }

        QAction *pAction=new QAction (name,this);
        pAction->setIcon(QIcon(":/UI_ICO/ICO/container.svg"));
        pAction->setShortcut(QKeySequence(Qt::CTRL+static_cast<uint16_t>(key+channel)));
        pAction->setToolTip(tr("Channel switching (CTRL+%1)").arg(channel));

        From_Action_Map.insert(pAction,channel);

        /*****************************
        * @brief:数据窗口
        ******************************/
        if(channelParCount>=channel && 0!=Pointer_Parameter->ParmeterMap.value(channel)->Channel_number){
            channel_number=Pointer_Parameter->ParmeterMap.value(channel)->Channel_number;
        }
        Channel_Data_Form *p_Channel_Data_Form=new Channel_Data_Form(name,channel_number,this);
        Channel_Data_From_Map.insert(channel,p_Channel_Data_Form);
        ui->gridLayout_2->addWidget(p_Channel_Data_Form);

        /*****************************
        * @brief:加载通道参数
        ******************************/
        p_Channel_Data_Form->loadParamter(channel,Pointer_Parameter->ParmeterMap.value(channel,nullptr).data());

        if(nullptr==p_Equipment_State_Form && 1==channel){
            p_Channel_Data_Form->setVisible(true);
            setStatusBar(0,tr("The preview page %1").arg(name));
            channelSelect=1;
        }

        /*****************************
        * 通道名数组
        ******************************/
        channelLabels.append(pAction->text());
    }
}

void MainWindow::connectProcess()
{
    QList<int> actList=From_Action_Map.values();
    std::sort(actList.begin(),actList.end());
    foreach (auto ind, actList) {
        /*****************************
        * 绑定工具栏按钮事件
        ******************************/
        connect(From_Action_Map.key(ind),SIGNAL(triggered()),this,SLOT(actionTiggeredSlot()));

        /*****************************
        * 添加通道到菜单栏
        ******************************/
        ui->menuChannel_To_View->addAction(From_Action_Map.key(ind));

        /*****************************
        * 添加通道到工具栏
        ******************************/
        ui->mainToolBar->addAction(From_Action_Map.key(ind));
    }
    if(p_Equipment_State_Form!=nullptr){

        /*****************************
        * 初始化通道状态
        ******************************/
        connect(this,SIGNAL(initializesTheDeviceStateListSignal(int,QStringList)),p_Equipment_State_Form,SLOT(initializesTheDeviceStateListSlot(int,QStringList)));

        /*****************************
        * @brief:展示设备状态
        ******************************/
        connect(this,SIGNAL(setDeviceStatusSignal(int,int,bool)),p_Equipment_State_Form,SLOT(setDeviceStatusSlot(int,int,bool)));
    }

    foreach (auto from, Channel_Data_From_Map.values()) {
        connect(this,SIGNAL(signal_initEquipment()),from,SLOT(slot_initEquipment()));
        connect(from,SIGNAL(signal_setDeviceStatus(int,int,bool)),this,SIGNAL(setDeviceStatusSignal(int,int,bool)));
        if(p_Equipment_State_Form!=nullptr){
            connect(from,&Channel_Data_Form::signal_container,p_Equipment_State_Form,&Equipment_State_From::slot_container);
            connect(from,&Channel_Data_Form::signal_plate,p_Equipment_State_Form,&Equipment_State_From::slot_plate);
            connect(from,&Channel_Data_Form::signal_channelState,p_Equipment_State_Form,&Equipment_State_From::slot_channelState);
            connect(from,&Channel_Data_Form::signal_clean_plate_con_test,p_Equipment_State_Form,&Equipment_State_From::slot_clean_plate_con_test);
        }
    }

    /*****************************
    * 初始化设备
    ******************************/
    emit initializesTheDeviceStateListSignal(channelCount,channelLabels);

    pAlarmForm=QPointer<AlarmForm>(new AlarmForm(this));
    connect(this,SIGNAL(signal_setAlarmMsg(int,QString)),pAlarmForm,SLOT(slot_setAlarmMsg(int,QString)));
    /*****************************
    * @brief:添加错误状态提示到工具栏
    ******************************/
    ui->mainToolBar->addWidget(pAlarmForm);
}


void MainWindow::loadStyleSheet(const QString &fileName)
{
    QFile file(fileName);
    file.open(QFile::ReadOnly);
    if(file.isOpen()){
        QString styleSheet=QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);
    }      
}

void MainWindow::setStatusBar(int type, const QString &msg)
{
    switch (type) {
    case 0:
        permanentLabel->setText(msg);
        break;
    case 1:
        runTimeLabel->setText(msg);
        break;
    case 2:
        throughTheNumberLabel->setText(msg);
        break;
    case 3:
        hardDriveCapacityLabel->setText(msg);
        break;
    case 4:
        socketLinkCountLabel->setText(msg);
        break;
    }
    //permanentLabel->setText(msg);
    ui->statusBar->showMessage(LocalPar::copyright+"-"+LocalPar::proName,100000);
}

void MainWindow::systemTrayAction()
{
    QPointer<QAction> pAction=qobject_cast<QAction*> (sender());
    if(pAction==actionShow){
        setWindowState(Qt::WindowMaximized);
        this->show();
    }
    if(pAction==actionExit){
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
    {
        setWindowState(Qt::WindowMaximized);
        this->show();
    }
        break;
    default:
        break;
    }
}

void MainWindow::actionTiggeredSlot()
{
    pAction=qobject_cast<QAction*> (sender());

    QMap<QAction*,int>::const_iterator it =From_Action_Map.find(pAction);

    /*****************************
    * 预览通道没有切换,就不做处理(channelSelect)
    ******************************/
    if(it!=From_Action_Map.end() && it.value()!=channelSelect){
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
                setStatusBar(0,tr("System ready"));
            }
        }

        if(nullptr!= Channel_Data_From_Map.value(channelSelect,nullptr)){
            Channel_Data_From_Map.value(channelSelect)->setVisible(true);
            setStatusBar(0,tr("The preview page %1").arg( it.key()->text()));
        }
    }
}

void MainWindow::on_actionParameter_Settings_triggered()
{
    QPointer<Setting_Form> p_Setting_Form=new Setting_Form (nullptr);

    QPointer<NetworkController> p_NetworkController=new NetworkController(nullptr);

    /*****************************
    * @brief:初始化设备状态
    ******************************/
    connect(this,SIGNAL(initializesTheDeviceStateListSignal(int,QStringList)),p_Setting_Form,SLOT(initializesTheDeviceListSlot(int,QStringList)));

    /*****************************
    * @brief:搜索网络控制器
    ******************************/
    connect(p_Setting_Form,&Setting_Form::searchEquipmentSignal,p_NetworkController,&NetworkController::searchEquipmentSlot);

    /*****************************
    * @brief:搜索到网络控制器参数
    ******************************/
    connect(p_NetworkController,&NetworkController::sendEquipmentParSignal,p_Setting_Form,&Setting_Form::sendEquipmentParSignal);

    /*****************************
    * @brief:设置网络控制器参数成功
    ******************************/
    connect(p_NetworkController,&NetworkController::setParSucessSignal,p_Setting_Form,&Setting_Form::setParSucessSignal);

    /*****************************
    * @brief:加载网络控制器参数
    ******************************/
    connect(p_Setting_Form,&Setting_Form::setEquipmentParSignal,p_NetworkController,&NetworkController::setEquipmentParSlot);

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
    * @brief:绑定测试抓拍,相机状态
    ******************************/
    foreach (auto p_Channel_Data_Form, Channel_Data_From_Map.values()) {
        connect(p_Camera_List_Form,SIGNAL(signal_captureTest(int,int)),p_Channel_Data_Form,SLOT(slot_captureTest(int,int)));
        connect(p_Channel_Data_Form,SIGNAL(signal_getCameraState(int,int)),p_Camera_List_Form,SLOT(slot_getCameraState(int,int)));
        connect(p_Channel_Data_Form,SIGNAL(signal_pictureStream(QByteArray, int, QString)),p_Camera_List_Form,SIGNAL(signal_pictureStream(QByteArray,int,QString)));
        connect(p_Camera_List_Form,SIGNAL(signal_playStream(quint64,bool,int,int)),p_Channel_Data_Form,SLOT(slot_playStream(quint64,bool,int,int)));
        connect(p_Channel_Data_Form,SIGNAL(signal_videoStream(QByteArray)),p_Camera_List_Form,SIGNAL(signal_videoStream(QByteArray)));
    }

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
    if(pLoadinglibaray->IDataBaseReadList.size()>=1){
        connect(p_DataBase_Form,&DataBase_Form::signal_initDataBaseR,pLoadinglibaray->IDataBaseReadList.at(0).data(),&DataBaseReadInterface::initDataBaseSlot);
        connect(p_DataBase_Form,&DataBase_Form::signal_setDataBaseFilter,pLoadinglibaray->IDataBaseReadList.at(0).data(),&DataBaseReadInterface::setDataBaseFilterSlot);
        connect(pLoadinglibaray->IDataBaseReadList.at(0).data(),&DataBaseReadInterface::returnModelSingal,p_DataBase_Form,&DataBase_Form::slot_returnModel);
        connect(pLoadinglibaray->IDataBaseReadList.at(0).data(),&DataBaseReadInterface::statisticalDataSignal,p_DataBase_Form,&DataBase_Form::slot_statisticalData);
    }

    p_DataBase_Form->setWindowModality(Qt::ApplicationModal);
    p_DataBase_Form->show();
}

void MainWindow::on_actionData_log_triggered()
{
    if(nullptr!=p_Data_Log_Form){
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

void MainWindow::on_actionAbout_triggered()
{
    QSharedPointer<AboutDialog> dlg(new AboutDialog());
    dlg->exec();
}

void MainWindow::slot_handleFinished()
{
    qInfo()<<QString("[%1] Successfully loading plug-in").arg(this->metaObject()->className());
    ui->statusBar->showMessage(tr("Successfully loading plug-in"),3000);
    statusProgressBar->setVisible(false);

    bindingPlugin();
    initializing();
}

void MainWindow::slot_Error(QString pluginName)
{
    QString text = tr("Error loading system plug-in:%1").arg(pluginName);

    emit signal_setAlarmMsg(++alarmNum,text);

    int w=this->geometry().width();
    pErrorForm->setGeometry(0,30,w,50);
    pErrorForm->setTipInfo(text);
    QTimer::singleShot(10000,this,SLOT(slot_hideErrorForm()));
}

void MainWindow::slot_hideErrorForm()
{
    pErrorForm->setVisible(false);
}

void MainWindow::slot_progressRangeChanged(int minimum, int maximum)
{
    statusProgressBar->setRange(minimum,maximum);
}

void MainWindow::slot_progressTextChanged(const QString &progressText)
{
    statusProgressBar->setFormat(tr("Loading plug-in:%1").arg(progressText));
}

void MainWindow::slot_progressValueChanged(int progressValue)
{
    statusProgressBar->setValue(progressValue);
}

void MainWindow::slot_theFtpProgress(qint64 bytesSent, qint64 bytesTotal)
{
    statusProgressBar->setFormat(tr("Uploading a picture"));
    statusProgressBar->setRange(0,bytesTotal);
    statusProgressBar->setValue(bytesSent);
}

void MainWindow::slot_getDiskFreeSpace()
{
    QDir dir(Parameter::ImagePath);
    QString dirName = dir.absolutePath();
    LPCWSTR lpcwstrDriver = (LPCWSTR)dirName.utf16();
    ULARGE_INTEGER liFreeBytesAvailable, liTotalBytes, liTotalFreeBytes;

    if (GetDiskFreeSpaceEx(lpcwstrDriver, &liFreeBytesAvailable, &liTotalBytes, &liTotalFreeBytes)) {
        QString use = QString::number((double)(liTotalBytes.QuadPart - liTotalFreeBytes.QuadPart) / GB, 'f', 1);
        use += "G";
        QString free = QString::number((double) liTotalFreeBytes.QuadPart / GB, 'f', 1);
        free += "G";
        QString all = QString::number((double) liTotalBytes.QuadPart / GB, 'f', 1);
        all += "G";
        int percent = 100 - ((double)liTotalFreeBytes.QuadPart / liTotalBytes.QuadPart) * 100;
        setStatusBar(3,QString("Dir:%1  Use:%2  Free:%3  All:%4  Percent:%5%").arg(dirName.mid(0,3)).arg(use).arg(free).arg(all).arg(percent));
    }
}

void MainWindow::slot_connectCount(int count)
{
    if(linkCount<0){
        linkCount=0;
    }
    linkCount=linkCount+count;
    setStatusBar(4,QString("Service:%1  Format:%2  Count:%3").arg(Parameter::DataChaneType?"MQ":"TCP").arg(Parameter::DataChange_Format?"JSON":"TEXT").arg(linkCount));
}

void MainWindow::slot_statisticalData(int total, double correct, double error, double statistical)
{
    this->total=total;
    this->correct=correct;
    this->error=error;
    this->statistical=statistical;
    setStatusBar(2,QString("Total:%1  Correct:%2  Error:%3  Statistical:%4%").arg(total).arg(correct).arg(error).arg(statistical));
}

void MainWindow::slot_trafficStatistics(bool state)
{
    total+=1;
    if(state){
        correct+=1;
        statistical=correct/total*100;
    }
    else {
        error+=1;
        statistical=correct/total*100;
    }
    setStatusBar(2,QString("Total:%1  Correct:%2  Error:%3  Statistical:%4%").arg(total).arg(correct).arg(error).arg(statistical));
}

void MainWindow::slot_systemRunTimer()
{
    QTime m_time(0, 0, 0, 0);
    QDateTime now=QDateTime::currentDateTime();
    QString tt= m_time.addSecs(runTime.secsTo(now)).toString("hh:mm:ss");
    setStatusBar(1,QString("Start:%1  Run:%2(D) %3").arg(runTime.toString("yyyy-MM-dd HH:mm:ss")).arg(runTime.daysTo(now)).arg(tt));
}

void MainWindow::slot_exceptionCode(unsigned long dwType, long lUserID)
{
    emit signal_exceptionCode(dwType,lUserID);
}

void MainWindow::bindingPlugin()
{
    if(pLoadinglibaray->ICaptureImagesLit.size()>1){
        int i=0;
        for (int ind = 1; ind <= Channel_Data_From_Map.count(); ++ind) {
            int j=i;
            for (; j < LocalPar::CamerNumber+i; ++j) {
                connect(pLoadinglibaray->ICaptureImagesLit.at(j).data(),&ICaptureImages::camerStateSingal,Channel_Data_From_Map.value(ind),&Channel_Data_Form::slot_camerState);
                connect(this,&MainWindow::signal_releaseResources,pLoadinglibaray->ICaptureImagesLit.at(j).data(),&ICaptureImages::releaseResourcesSlot,Qt::BlockingQueuedConnection);
            }
            for (int var = 0; var < LocalPar::CamerNumber; ++var) {
                connect(Channel_Data_From_Map.value(ind),&Channel_Data_Form::signal_putCommand,pLoadinglibaray->ICaptureImagesLit.at(i+var).data(),&ICaptureImages::putCommandSlot);
                connect(pLoadinglibaray->ICaptureImagesLit.at(i+var).data(),&ICaptureImages::pictureStreamSignal,Channel_Data_From_Map.value(ind),&Channel_Data_Form::signal_pictureStream);
                connect(Channel_Data_From_Map.value(ind),&Channel_Data_Form::signal_playStream,pLoadinglibaray->ICaptureImagesLit.at(i+var).data(),&ICaptureImages::playStreamSlot);
            }
            connect(Channel_Data_From_Map.value(ind),&Channel_Data_Form::signal_initCamer_front,pLoadinglibaray->ICaptureImagesLit.at(i++).data(),&ICaptureImages::initCamerSlot);
            connect(Channel_Data_From_Map.value(ind),&Channel_Data_Form::signal_initCamer_before,pLoadinglibaray->ICaptureImagesLit.at(i++).data(),&ICaptureImages::initCamerSlot);
            connect(Channel_Data_From_Map.value(ind),&Channel_Data_Form::signal_initCamer_left,pLoadinglibaray->ICaptureImagesLit.at(i++).data(),&ICaptureImages::initCamerSlot);
            connect(Channel_Data_From_Map.value(ind),&Channel_Data_Form::signal_initCamer_right,pLoadinglibaray->ICaptureImagesLit.at(i++).data(),&ICaptureImages::initCamerSlot);
            if(7==LocalPar::CamerNumber){
                connect(Channel_Data_From_Map.value(ind),&Channel_Data_Form::signal_initCamer_top,pLoadinglibaray->ICaptureImagesLit.at(i++).data(),&ICaptureImages::initCamerSlot);
                connect(Channel_Data_From_Map.value(ind),&Channel_Data_Form::signal_initCamer_prospects,pLoadinglibaray->ICaptureImagesLit.at(i++).data(),&ICaptureImages::initCamerSlot);
                connect(Channel_Data_From_Map.value(ind),&Channel_Data_Form::signal_initCamer_foreground,pLoadinglibaray->ICaptureImagesLit.at(i++).data(),&ICaptureImages::initCamerSlot);
            }
        }
    }

    if(!Parameter::loadLibrary_HK){
        /* 显式加载SDK */
        if(pLoadinglibaray->IMiddlewareLit.size()>=1){
            int ind=0;
            int cout=pLoadinglibaray->IMiddlewareLit.size();
            /*****************************
            * @brief:海康车牌增加一个库
            ******************************/
            if(0==Parameter::PlateType){
                cout-=1;
            }

            for (int var = 0; var < pLoadinglibaray->ICaptureImagesLit.size(); ++var) {
                if(1==cout){
                    ind=0;
                }
                else {
                    ind=var;
                }
                connect(pLoadinglibaray->ICaptureImagesLit.at(var).data(),&ICaptureImages::signal_initCamera,pLoadinglibaray->IMiddlewareLit.at(ind).data(),&IMiddleware::initCameraSlot);
                connect(pLoadinglibaray->ICaptureImagesLit.at(var).data(),&ICaptureImages::signal_openTheVideo,pLoadinglibaray->IMiddlewareLit.at(ind).data(),&IMiddleware::openTheVideoSlot);
                connect(pLoadinglibaray->ICaptureImagesLit.at(var).data(),&ICaptureImages::signal_simulationCapture,pLoadinglibaray->IMiddlewareLit.at(ind).data(),&IMiddleware::simulationCaptureSlot);
                connect(pLoadinglibaray->ICaptureImagesLit.at(var).data(),&ICaptureImages::signal_liftingElectronicRailing,pLoadinglibaray->IMiddlewareLit.at(ind).data(),&IMiddleware::liftingElectronicRailingSlot);
                connect(pLoadinglibaray->ICaptureImagesLit.at(var).data(),&ICaptureImages::signal_transparentTransmission485,pLoadinglibaray->IMiddlewareLit.at(ind).data(),&IMiddleware::transparentTransmission485Slot);

                connect(pLoadinglibaray->IMiddlewareLit.at(ind).data(),&IMiddleware::signal_pictureStream,pLoadinglibaray->ICaptureImagesLit.at(var).data(),&ICaptureImages::slot_pictureStream);
                connect(pLoadinglibaray->IMiddlewareLit.at(ind).data(),&IMiddleware::signal_setCameraID,pLoadinglibaray->ICaptureImagesLit.at(var).data(),&ICaptureImages::slot_setCameraID);
                connect(pLoadinglibaray->IMiddlewareLit.at(ind).data(),&IMiddleware::equipmentStateSignal,pLoadinglibaray->ICaptureImagesLit.at(var).data(),&ICaptureImages::slot_equipmentState);
                connect(pLoadinglibaray->IMiddlewareLit.at(ind).data(),&IMiddleware::resultsTheLicensePlateSignal,pLoadinglibaray->ICaptureImagesLit.at(var).data(),&ICaptureImages::slot_resultsTheLicensePlate);

                /*****************************
                * @brief:海康全局回调多次设置，会覆盖之前设置。此功能设置统一回调
                ******************************/
                connect(pLoadinglibaray->IMiddlewareLit.at(ind).data(),&IMiddleware::signal_exceptionCode,this,&MainWindow::slot_exceptionCode);
                connect(this,&MainWindow::signal_exceptionCode,pLoadinglibaray->IMiddlewareLit.at(ind).data(),&IMiddleware::slot_exceptionCode);

                connect(this,&MainWindow::signal_setCameraCaptureType,pLoadinglibaray->IMiddlewareLit.at(ind).data(),&IMiddleware::setCaptureTypeSlot);
                connect(this,&MainWindow::signal_releaseResources,pLoadinglibaray->IMiddlewareLit.at(ind).data(),&IMiddleware::releaseResourcesSlot,Qt::BlockingQueuedConnection);
            }
        }
    }
    else {
       /* 隐式加载SDK */
        if(pLoadinglibaray->IMiddlewareLit.size()>=1){
            for (int var = 0; var < pLoadinglibaray->ICaptureImagesLit.size(); ++var) {
                connect(pLoadinglibaray->ICaptureImagesLit.at(var).data(),&ICaptureImages::signal_initCamera,pLoadinglibaray->IMiddlewareLit.at(0).data(),&IMiddleware::initCameraSlot);
                connect(pLoadinglibaray->ICaptureImagesLit.at(var).data(),&ICaptureImages::signal_openTheVideo,pLoadinglibaray->IMiddlewareLit.at(0).data(),&IMiddleware::openTheVideoSlot);
                connect(pLoadinglibaray->ICaptureImagesLit.at(var).data(),&ICaptureImages::signal_simulationCapture,pLoadinglibaray->IMiddlewareLit.at(0).data(),&IMiddleware::simulationCaptureSlot);
                connect(pLoadinglibaray->ICaptureImagesLit.at(var).data(),&ICaptureImages::signal_liftingElectronicRailing,pLoadinglibaray->IMiddlewareLit.at(0).data(),&IMiddleware::liftingElectronicRailingSlot);
                connect(pLoadinglibaray->ICaptureImagesLit.at(var).data(),&ICaptureImages::signal_transparentTransmission485,pLoadinglibaray->IMiddlewareLit.at(0).data(),&IMiddleware::transparentTransmission485Slot);

                connect(pLoadinglibaray->IMiddlewareLit.at(0).data(),&IMiddleware::signal_pictureStream,pLoadinglibaray->ICaptureImagesLit.at(var).data(),&ICaptureImages::slot_pictureStream);
                connect(pLoadinglibaray->IMiddlewareLit.at(0).data(),&IMiddleware::signal_setCameraID,pLoadinglibaray->ICaptureImagesLit.at(var).data(),&ICaptureImages::slot_setCameraID);
                connect(pLoadinglibaray->IMiddlewareLit.at(0).data(),&IMiddleware::equipmentStateSignal,pLoadinglibaray->ICaptureImagesLit.at(var).data(),&ICaptureImages::slot_equipmentState);
                connect(pLoadinglibaray->IMiddlewareLit.at(0).data(),&IMiddleware::resultsTheLicensePlateSignal,pLoadinglibaray->ICaptureImagesLit.at(var).data(),&ICaptureImages::slot_resultsTheLicensePlate);
            }
            connect(this,&MainWindow::signal_setCameraCaptureType,pLoadinglibaray->IMiddlewareLit.at(0).data(),&IMiddleware::setCaptureTypeSlot);
            connect(this,&MainWindow::signal_releaseResources,pLoadinglibaray->IMiddlewareLit.at(0).data(),&IMiddleware::releaseResourcesSlot,Qt::BlockingQueuedConnection);
            connect(this,&MainWindow::signal_initializationParameter,pLoadinglibaray->IMiddlewareLit.at(0).data(),&IMiddleware::slot_initializationParameter);
        }
    }

    if(pLoadinglibaray->InfraredlogicLit.size()>=1 && pLoadinglibaray->InfraredlogicLit.size()==Channel_Data_From_Map.size()){
        for (int var = 0; var < pLoadinglibaray->InfraredlogicLit.size(); ++var) {
            connect(pLoadinglibaray->InfraredlogicLit.at(var).data(),&InfraredlogicInterface::logicStatusSignal,Channel_Data_From_Map.value(var+1),&Channel_Data_Form::slot_logicStatus);
            connect(pLoadinglibaray->InfraredlogicLit.at(var).data(),&InfraredlogicInterface::logicPutImageSignal,Channel_Data_From_Map.value(var+1),&Channel_Data_Form::slot_logicPutImage);
            connect(pLoadinglibaray->InfraredlogicLit.at(var).data(),&InfraredlogicInterface::serialPortStateSignal,Channel_Data_From_Map.value(var+1),&Channel_Data_Form::slot_serialPortState);
            connect(Channel_Data_From_Map.value(var+1),&Channel_Data_Form::signal_simulateTrigger,pLoadinglibaray->InfraredlogicLit.at(var).data(),&InfraredlogicInterface::simulateTriggerSlot);
            connect(Channel_Data_From_Map.value(var+1),&Channel_Data_Form::signal_setAlarmMode,pLoadinglibaray->InfraredlogicLit.at(var).data(),&InfraredlogicInterface::setAlarmModeSlot);
            connect(Channel_Data_From_Map.value(var+1),&Channel_Data_Form::signal_DTypeOut,pLoadinglibaray->InfraredlogicLit.at(var).data(),&InfraredlogicInterface::DTypeOutSlot);
            connect(Channel_Data_From_Map.value(var+1),&Channel_Data_Form::signal_startSlave,pLoadinglibaray->InfraredlogicLit.at(var).data(),&InfraredlogicInterface::startSlaveSlot);
            connect(this,&MainWindow::signal_releaseResources,pLoadinglibaray->InfraredlogicLit.at(var).data(),&InfraredlogicInterface::releaseResourcesSlot,Qt::BlockingQueuedConnection);
        }
    }

    if(pLoadinglibaray->IDataBaseInsertList.size()>=1 && pLoadinglibaray->IDataBaseInsertList.size()==Channel_Data_From_Map.size()){
        for (int var = 0; var < pLoadinglibaray->IDataBaseInsertList.size(); ++var) {
            connect(Channel_Data_From_Map.value(var+1),&Channel_Data_Form::signal_initDataBase,pLoadinglibaray->IDataBaseInsertList.at(var).data(),&DataBaseInsertInterface::initDataBaseSlot);
            connect(Channel_Data_From_Map.value(var+1),&Channel_Data_Form::signal_insertDataBase,pLoadinglibaray->IDataBaseInsertList.at(var).data(),&DataBaseInsertInterface::insertDataBaseSlot);
            connect(Channel_Data_From_Map.value(var+1),&Channel_Data_Form::signal_updateDataBase,pLoadinglibaray->IDataBaseInsertList.at(var).data(),&DataBaseInsertInterface::updateDataBaseSlot);
        }
    }

    if(pLoadinglibaray->IDataBaseReadList.size()>=1){
        connect(this,&MainWindow::signal_initDataBaseR,pLoadinglibaray->IDataBaseReadList.at(0).data(),&DataBaseReadInterface::initDataBaseSlot);
        /*****************************
        * @brief:当日数据流量统计
        ******************************/
//        connect(this,&MainWindow::signal_setDataBaseFilter,pLoadinglibaray->IDataBaseReadList.at(0).data(),&DataBaseReadInterface::setDataBaseFilterSlot);
//        connect(pLoadinglibaray->IDataBaseReadList.at(0).data(),&DataBaseReadInterface::statisticalDataSignal,this,&MainWindow::slot_statisticalData);
    }

    if(pLoadinglibaray->IRecognizerList.size()>=1 && pLoadinglibaray->IRecognizerList.size()==Channel_Data_From_Map.size()){
        for (int var = 0; var < pLoadinglibaray->IRecognizerList.size(); ++var) {
            connect(Channel_Data_From_Map.value(var+1),&Channel_Data_Form::signal_identifyStream,pLoadinglibaray->IRecognizerList.at(var).data(),&RecognizerInterface::identifyStreamSlot);
            connect(Channel_Data_From_Map.value(var+1),&Channel_Data_Form::signal_identifyImages,pLoadinglibaray->IRecognizerList.at(var).data(),&RecognizerInterface::identifyImagesSlot);
            connect(pLoadinglibaray->IRecognizerList.at(var).data(),&RecognizerInterface::recognitionResultSignal,Channel_Data_From_Map.value(var+1),&Channel_Data_Form::slot_recognitionResult);
            connect(this,&MainWindow::signal_releaseResources,pLoadinglibaray->IRecognizerList.at(var).data(),&RecognizerInterface::releaseResourcesSlot,Qt::BlockingQueuedConnection);
        }
    }

    if(pLoadinglibaray->IResultsAnalysisList.size()>=1 && pLoadinglibaray->IResultsAnalysisList.size()==Channel_Data_From_Map.size() && pLoadinglibaray->IResultsAnalysisList.size()==pLoadinglibaray->IDataBaseInsertList.size()){
        for (int var = 0; var < pLoadinglibaray->IResultsAnalysisList.size(); ++var) {
            connect(Channel_Data_From_Map.value(var+1),&Channel_Data_Form::signal_initReAnaParameter,pLoadinglibaray->IResultsAnalysisList.at(var).data(),&ResultsAnalysisInterface::initParameter);
            connect(Channel_Data_From_Map.value(var+1),&Channel_Data_Form::signal_resultsOfAnalysis,pLoadinglibaray->IResultsAnalysisList.at(var).data(),&ResultsAnalysisInterface::resultsOfAnalysisSlot);
            connect(pLoadinglibaray->IResultsAnalysisList.at(var).data(),&ResultsAnalysisInterface::containerSignal,Channel_Data_From_Map.value(var+1),&Channel_Data_Form::slot_container);
            connect(pLoadinglibaray->IResultsAnalysisList.at(var).data(),&ResultsAnalysisInterface::updateDataBaseSignal,pLoadinglibaray->IDataBaseInsertList.at(var).data(),&DataBaseInsertInterface::updateDataBaseSlot);
        }
    }

    if(pLoadinglibaray->IDataInterchangeList.size()>=1 && DataProcessingList.size()>=1 && pLoadinglibaray->IResultsAnalysisList.size()==DataProcessingList.size()){
        int cot=pLoadinglibaray->IDataInterchangeList.size();
        for (int var = 0; var < DataProcessingList.size(); ++var) {
            if(Parameter::Service_Type || Parameter::DataChaneType==1){
                cot=0;
            }
            else {
                cot=var;
            }
            connect(pLoadinglibaray->IDataInterchangeList.at(cot).data(),&DataInterchangeInterface::linkStateSingal,p_Data_Log_Form.data(),&Data_Log_Form::slot_linkState);
            connect(pLoadinglibaray->IDataInterchangeList.at(cot).data(),&DataInterchangeInterface::connectCountSignal,p_Data_Log_Form.data(),&Data_Log_Form::slot_connectCount);
            connect(pLoadinglibaray->IDataInterchangeList.at(cot).data(),&DataInterchangeInterface::signal_sendDataSuccToLog,p_Data_Log_Form.data(),&Data_Log_Form::slot_sendLogToUi);

            connect(DataProcessingList.at(var).data(),&DataProcessing::signal_toSendData,pLoadinglibaray->IDataInterchangeList.at(cot).data(),&DataInterchangeInterface::toSendDataSignal);
            connect(DataProcessingList.at(var).data(),&DataProcessing::signal_InitializationParameter,pLoadinglibaray->IDataInterchangeList.at(cot).data(),&DataInterchangeInterface::InitializationParameterSlot);

            connect(pLoadinglibaray->IResultsAnalysisList.at(var).data(),&ResultsAnalysisInterface::sendResultSignal,DataProcessingList.at(var).data(),&DataProcessing::slot_containerResult);
            connect(this,&MainWindow::signal_releaseResources,pLoadinglibaray->IDataInterchangeList.at(cot).data(),&DataInterchangeInterface::releaseResourcesSlot,Qt::BlockingQueuedConnection);

            /*****************************
            * @brief:链接状态道状态页面
            ******************************/
            connect(pLoadinglibaray->IDataInterchangeList.at(cot).data(),&DataInterchangeInterface::connectCountSignal,this,&MainWindow::slot_connectCount);
            /*****************************
            * @brief:接收抬杆信号
            ******************************/
            connect(pLoadinglibaray->IDataInterchangeList.at(cot).data(),&DataInterchangeInterface::signal_lifting,Channel_Data_From_Map.value(var+1),&Channel_Data_Form::slot_lifting);
            /*****************************
            * @brief:模拟发送数据
            ******************************/
            connect(Channel_Data_From_Map.value(var+1),&Channel_Data_Form::sendResultSignal,DataProcessingList.at(var).data(),&DataProcessing::slot_containerResult);
            connect(Channel_Data_From_Map.value(var+1),&Channel_Data_Form::signal_plateResult,DataProcessingList.at(var).data(),&DataProcessing::slot_plateResult);
            /*****************************
            * @brief:发送箱号
            ******************************/
            connect(Channel_Data_From_Map.value(var+1),&Channel_Data_Form::signal_waitSendData,DataProcessingList.at(var).data(),&DataProcessing::slot_waitSendData);
            /*****************************
            * @brief:检测数据逻辑
            ******************************/
            connect(DataProcessingList.at(var).data(),&DataProcessing::signal_pollsForCarStatus,Channel_Data_From_Map.value(var+1),&Channel_Data_Form::slot_pollsForCarStatus);
            /*****************************
            * @brief:485透明传输
            ******************************/
            connect(DataProcessingList.at(var).data(),&DataProcessing::signal_sendToDisplay,Channel_Data_From_Map.value(var+1),&Channel_Data_Form::slot_transparentTransmission485);
            /*****************************
            * @brief:流量统计
            ******************************/
            connect(DataProcessingList.at(var).data(),&DataProcessing::signal_trafficStatistics,this,&MainWindow::slot_trafficStatistics);
            /*****************************
            * @brief:车牌结果
            ******************************/
            connect(Channel_Data_From_Map.value(var+1),&Channel_Data_Form::signal_plateSendData,DataProcessingList.at(var).data(),&DataProcessing::slot_plateResult);
            /*****************************
            * @brief:进车车辆拖箱状态
            ******************************/
            connect(Channel_Data_From_Map.value(var+1),&Channel_Data_Form::signal_sendCarStatus,DataProcessingList.at(var).data(),&DataProcessing::slot_readCarStatus);
            /*****************************
            * @brief:设置图片路径，用于HTTP上传图片
            ******************************/
            connect(this,&MainWindow::signal_SetImagePath,pLoadinglibaray->IDataInterchangeList.at(cot).data(),&DataInterchangeInterface::setImagePathSlot);
        }
    }

    if(pLoadinglibaray->IToUploadDataList.size()>=1){
        for (int var = 1; var <= Channel_Data_From_Map.size(); ++var) {
            connect(Channel_Data_From_Map.value(var),&Channel_Data_Form::signal_uploadData,pLoadinglibaray->IToUploadDataList.at(0).data(),&ToUploadDataInterface::uploadDataSlot);
        }
        connect(this,&MainWindow::signal_InitializationFTPParameter,pLoadinglibaray->IToUploadDataList.at(0).data(),&ToUploadDataInterface::InitializationParameterSlot);
        connect(pLoadinglibaray->IToUploadDataList.at(0).data(),&ToUploadDataInterface::theProgressOfSignal,this,&MainWindow::slot_theFtpProgress);
        connect(this,&MainWindow::signal_releaseResources,pLoadinglibaray->IToUploadDataList.at(0).data(),&ToUploadDataInterface::releaseResourcesSlot,Qt::BlockingQueuedConnection);
    }

    if(!Parameter::loadLibrary_HK){
        /* 显示加载SDK */
        if(pLoadinglibaray->ILicensePlateList.size()>=1 && Channel_Data_From_Map.size()==pLoadinglibaray->ILicensePlateList.size()){
            int var = pLoadinglibaray->IMiddlewareLit.size()-1;
            for (int ind = 1; ind <= Channel_Data_From_Map.count(); ++ind) {
                connect(Channel_Data_From_Map.value(ind),&Channel_Data_Form::signal_initCamer_plate,pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::initCamerSlot);
                connect(Channel_Data_From_Map.value(ind),&Channel_Data_Form::signal_simulationCapture,pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::simulationCaptureSlot);
                connect(Channel_Data_From_Map.value(ind),&Channel_Data_Form::signal_liftingElectronicRailing,pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::liftingElectronicRailingSlot);
                connect(Channel_Data_From_Map.value(ind),&Channel_Data_Form::signal_transparentTransmission485,pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::transparentTransmission485Slot);
                connect(Channel_Data_From_Map.value(ind),&Channel_Data_Form::signal_openTheVideo,pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::openTheVideoSlot);

                connect(pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::imageFlowSignal,Channel_Data_From_Map.value(ind),&Channel_Data_Form::slot_imageFlow);
                connect(pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::theVideoStreamSignal,Channel_Data_From_Map.value(ind),&Channel_Data_Form::slot_theVideoStream);
                connect(pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::resultsTheLicensePlateSignal,Channel_Data_From_Map.value(ind),&Channel_Data_Form::slot_resultsTheLicensePlate);
                connect(pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::equipmentStateSignal,Channel_Data_From_Map.value(ind),&Channel_Data_Form::slot_camerState);

                /*****************************
                * @brief:主动获取车牌最后一次结果
                ******************************/
                connect(Channel_Data_From_Map.value(ind),&Channel_Data_Form::signal_getLastPlate,pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::getLastPlateSlot);

                /*****************************
                * @brief:和海康插件对接
                ******************************/
                if(0==Parameter::PlateType && pLoadinglibaray->IMiddlewareLit.size()>=1){
                    connect(pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::signal_initCamera,pLoadinglibaray->IMiddlewareLit.at(var).data(),&IMiddleware::initCameraSlot);
                    connect(pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::signal_openTheVideo,pLoadinglibaray->IMiddlewareLit.at(var).data(),&IMiddleware::openTheVideoSlot);
                    connect(pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::signal_simulationCapture,pLoadinglibaray->IMiddlewareLit.at(var).data(),&IMiddleware::simulationCaptureSlot);
                    connect(pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::signal_liftingElectronicRailing,pLoadinglibaray->IMiddlewareLit.at(var).data(),&IMiddleware::liftingElectronicRailingSlot);
                    connect(pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::signal_transparentTransmission485,pLoadinglibaray->IMiddlewareLit.at(var).data(),&IMiddleware::transparentTransmission485Slot);

                    connect(pLoadinglibaray->IMiddlewareLit.at(var).data(),&IMiddleware::signal_pictureStream,pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::slot_pictureStream);
                    connect(pLoadinglibaray->IMiddlewareLit.at(var).data(),&IMiddleware::signal_setCameraID,pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::slot_setCameraID);
                    connect(pLoadinglibaray->IMiddlewareLit.at(var).data(),&IMiddleware::equipmentStateSignal,pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::slot_equipmentState);
                    connect(pLoadinglibaray->IMiddlewareLit.at(var).data(),&IMiddleware::resultsTheLicensePlateSignal,pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::slot_resultsTheLicensePlate);

                    /*****************************
                    * @brief:海康全局回调多次设置，会覆盖之前设置。此功能设置统一回调
                    ******************************/
                    connect(pLoadinglibaray->IMiddlewareLit.at(ind).data(),&IMiddleware::signal_exceptionCode,this,&MainWindow::slot_exceptionCode);
                    connect(this,&MainWindow::signal_exceptionCode,pLoadinglibaray->IMiddlewareLit.at(ind).data(),&IMiddleware::slot_exceptionCode);

                    /*****************************
                    * @brief:20211218
                    ******************************/
                    connect(this,&MainWindow::signal_setPlateCaptureType,pLoadinglibaray->IMiddlewareLit.at(var).data(),&IMiddleware::setCaptureTypeSlot);
                }
                connect(this,&MainWindow::signal_releaseResources,pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::releaseResourcesSlot,Qt::BlockingQueuedConnection);
            }
            connect(this,&MainWindow::signal_releaseResources,pLoadinglibaray->IMiddlewareLit.at(var).data(),&IMiddleware::releaseResourcesSlot,Qt::BlockingQueuedConnection);
            //connect(this,&MainWindow::signal_setPlateCaptureType,pLoadinglibaray->IMiddlewareLit.at(var).data(),&IMiddleware::setCaptureTypeSlot);
        }
    }
    else {
       /* 隐式加载SDK */
        if(pLoadinglibaray->ILicensePlateList.size()>=1 && Channel_Data_From_Map.size()==pLoadinglibaray->ILicensePlateList.size()){
            for (int ind = 1; ind <= Channel_Data_From_Map.count(); ++ind) {
                connect(Channel_Data_From_Map.value(ind),&Channel_Data_Form::signal_initCamer_plate,pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::initCamerSlot);
                connect(Channel_Data_From_Map.value(ind),&Channel_Data_Form::signal_simulationCapture,pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::simulationCaptureSlot);
                connect(Channel_Data_From_Map.value(ind),&Channel_Data_Form::signal_liftingElectronicRailing,pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::liftingElectronicRailingSlot);
                connect(Channel_Data_From_Map.value(ind),&Channel_Data_Form::signal_transparentTransmission485,pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::transparentTransmission485Slot);
                connect(Channel_Data_From_Map.value(ind),&Channel_Data_Form::signal_openTheVideo,pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::openTheVideoSlot);

                connect(pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::imageFlowSignal,Channel_Data_From_Map.value(ind),&Channel_Data_Form::slot_imageFlow);
                connect(pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::theVideoStreamSignal,Channel_Data_From_Map.value(ind),&Channel_Data_Form::slot_theVideoStream);
                connect(pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::resultsTheLicensePlateSignal,Channel_Data_From_Map.value(ind),&Channel_Data_Form::slot_resultsTheLicensePlate);
                connect(pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::equipmentStateSignal,Channel_Data_From_Map.value(ind),&Channel_Data_Form::slot_camerState);

                /*****************************
                * @brief:主动获取车牌最后一次结果
                ******************************/
                connect(Channel_Data_From_Map.value(ind),&Channel_Data_Form::signal_getLastPlate,pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::getLastPlateSlot);

                /*****************************
                * @brief:和海康插件对接
                ******************************/
                if(0==Parameter::PlateType && pLoadinglibaray->IMiddlewareLit.size()>=1){
                    connect(pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::signal_initCamera,pLoadinglibaray->IMiddlewareLit.at(0).data(),&IMiddleware::initCameraSlot);
                    connect(pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::signal_openTheVideo,pLoadinglibaray->IMiddlewareLit.at(0).data(),&IMiddleware::openTheVideoSlot);
                    connect(pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::signal_simulationCapture,pLoadinglibaray->IMiddlewareLit.at(0).data(),&IMiddleware::simulationCaptureSlot);
                    connect(pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::signal_liftingElectronicRailing,pLoadinglibaray->IMiddlewareLit.at(0).data(),&IMiddleware::liftingElectronicRailingSlot);
                    connect(pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::signal_transparentTransmission485,pLoadinglibaray->IMiddlewareLit.at(0).data(),&IMiddleware::transparentTransmission485Slot);

                    connect(pLoadinglibaray->IMiddlewareLit.at(0).data(),&IMiddleware::signal_pictureStream,pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::slot_pictureStream);
                    connect(pLoadinglibaray->IMiddlewareLit.at(0).data(),&IMiddleware::signal_setCameraID,pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::slot_setCameraID);
                    connect(pLoadinglibaray->IMiddlewareLit.at(0).data(),&IMiddleware::equipmentStateSignal,pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::slot_equipmentState);
                    connect(pLoadinglibaray->IMiddlewareLit.at(0).data(),&IMiddleware::resultsTheLicensePlateSignal,pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::slot_resultsTheLicensePlate);
                }
                connect(this,&MainWindow::signal_releaseResources,pLoadinglibaray->ILicensePlateList.at(ind-1).data(),&LicensePlateInterface::releaseResourcesSlot,Qt::BlockingQueuedConnection);
            }
            //connect(this,&MainWindow::signal_releaseResources,pLoadinglibaray->IMiddlewareLit.at(0).data(),&IMiddleware::releaseResourcesSlot,Qt::BlockingQueuedConnection);
            //connect(this,&MainWindow::signal_setPlateCaptureType,pLoadinglibaray->IMiddlewareLit.at(0).data(),&IMiddleware::setCaptureTypeSlot);
            //connect(this,&MainWindow::signal_initializationParameter,pLoadinglibaray->IMiddlewareLit.at(0).data(),&IMiddleware::slot_initializationParameter);
        }
    }

    if(pLoadinglibaray->IEncryptionList.size()==1 && pLoadinglibaray->IRecognizerList.size()>=1){
        for (int var = 0; var < pLoadinglibaray->IRecognizerList.size(); ++var) {
            connect(pLoadinglibaray->IEncryptionList.at(0).data(),&EncryptionInterface::GetTheEncryptedStateSignal,pLoadinglibaray->IRecognizerList.at(var).data(),&RecognizerInterface::identifyDogStatusSlot);
        }
        connect(this,&MainWindow::signal_initEncryption,pLoadinglibaray->IEncryptionList.at(0).data(),&EncryptionInterface::InitializationSlot);
        connect(this,&MainWindow::signal_releaseResources,pLoadinglibaray->IEncryptionList.at(0).data(),&EncryptionInterface::releaseResourcesSlot,Qt::BlockingQueuedConnection);
    }
}

void MainWindow::on_actionVersion_triggered()
{
    QSharedPointer<Version_Dialog> dlg(new Version_Dialog());
    dlg->exec();
}
