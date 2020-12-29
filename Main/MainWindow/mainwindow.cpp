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
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(isExit){
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

void MainWindow::clearnContainer()
{
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

    Channel_Data_From_Map.clear();
    From_Action_Map.clear();
    Form_Map.clear();   
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
    qRegisterMetaType<QtMsgType>("QtMsgType");
    qRegisterMetaType<QMap<QString,QString>>("QMap<QString,QString>");
    pLog=QPointer<LogController>(new LogController(LocalPar::App,this));

    pErrorForm=QPointer<ErrorForm>(new ErrorForm(this));

    p_Data_Log_Form=QSharedPointer<Data_Log_Form>(new Data_Log_Form (nullptr));
    p_Data_Log_Form.data()->setWindowModality(Qt::ApplicationModal);

    connect(pLog.data(),SIGNAL(signal_newLogText(QtMsgType,QDateTime,QString)),p_Data_Log_Form.data(),SLOT(slot_newLogText(QtMsgType,QDateTime,QString)));


    statusProgressBar=new QProgressBar (this);
    statusProgressBar->setFixedWidth(400);
    statusProgressBar->setStyleSheet("color: rgb(0, 0, 0);");
    statusProgressBar->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);

    permanentLabel=new QLabel (tr("System ready"),this);;
    runTimeLabel=new QLabel("0 H 0 M 0 S",this);;
    throughTheNumberLabel=new QLabel("0 Car",this);;
    hardDriveCapacityLabel=new QLabel("0 Mb",this);;
    socketLinkCountLabel=new QLabel("0 Machines [Server]",this);;

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
        p_Channel_Data_Form->loadParamter(channel,Pointer_Parameter->ParmeterMap.value(channel,nullptr));

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
        QString styleSheet=this->styleSheet();
        styleSheet+=QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);
    }
}

void MainWindow::setStatusBar(/*int type */const QString &msg)
{
//    switch (type) {
//    case 0:
//        permanentLabel->setText(msg);
//        break;
//    case 1:
//        runTimeLabel->setText(msg);
//        break;
//    case 2:
//        throughTheNumberLabel->setText(msg);
//        break;
//    case 3:
//        hardDriveCapacityLabel->setText(msg);
//        break;
//    case 4:
//        socketLinkCountLabel->setText(msg);
//        break;
//    }

    permanentLabel->setText(msg);
    ui->statusBar->showMessage("Technical support telephone:18565659070",100000);
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
        setWindowState(Qt::WindowMaximized);
        this->show();
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
                setStatusBar(tr("System ready"));
            }
        }

        if(nullptr!= Channel_Data_From_Map.value(channelSelect,nullptr)){
            Channel_Data_From_Map.value(channelSelect)->setVisible(true);
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
    * @brief:绑定测试抓拍,相机状态
    ******************************/
    foreach (auto p_Channel_Data_Form, Channel_Data_From_Map.values()) {
        connect(p_Camera_List_Form,SIGNAL(signal_captureTest(int,int)),p_Channel_Data_Form,SLOT(slot_captureTest(int,int)));
        connect(p_Channel_Data_Form,SIGNAL(signal_getCameraState(int,int)),p_Camera_List_Form,SLOT(slot_getCameraState(int,int)));
        connect(p_Channel_Data_Form,SIGNAL(signal_pictureStream(QByteArray, int, QString)),p_Camera_List_Form,SIGNAL(signal_pictureStream(QByteArray,int,QString)));
        connect(p_Camera_List_Form,SIGNAL(signal_playStream(quint64,bool,int,int)),p_Channel_Data_Form,SLOT(slot_playStream(quint64,bool,int,int)));
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
    qInfo()<<"Successfully loading plug-in";
    ui->statusBar->showMessage(tr("Successfully loading plug-in"),3000);
    statusProgressBar->setVisible(false);             

    bindingPlugin();

    /*****************************
    * @brief:初始化数据库
    ******************************/
    emit signal_initDataBaseR(QString::number(0),Parameter::databaseUser,Parameter::databasePass,Parameter::databaseAddr,Parameter::DatabaseType);

    /*****************************
    * @brief:登录相机
    ******************************/
    emit signal_initEquipment();
}

void MainWindow::slot_Error(QString pluginName)
{
    QString text = tr("Error loading system plug-in:%1, duplicate plug-in exists. Please check the plugins directory to avoid system interference!").arg(pluginName);

    emit signal_setAlarmMsg(++alarmNum,text);

    int w=this->size().width();
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

void MainWindow::bindingPlugin()
{
    if(pLoadinglibaray->ICaptureImagesLit.size()>1){
        int i=0;
        for (int ind = 1; ind <= Channel_Data_From_Map.count(); ++ind) {
            int j=i;
            for (; j < LocalPar::CamerNumber+i; ++j) {
                connect(pLoadinglibaray->ICaptureImagesLit.at(j).data(),SIGNAL(camerStateSingal(const QString,bool)),Channel_Data_From_Map.value(ind),SLOT(slot_camerState(const QString,bool)));                    
                //connect(pLoadinglibaray->ICaptureImagesLit.at(j).data(),SIGNAL(signal_bindingCameraID(QString,int)),Channel_Data_From_Map.value(ind),SIGNAL(slot_bindingCameraID( QString, int)));
                connect(this,&MainWindow::signal_releaseResources,pLoadinglibaray->ICaptureImagesLit.at(j).data(),&ICaptureImages::releaseResourcesSlot,Qt::BlockingQueuedConnection);
            }
            for (int var = 0; var < LocalPar::CamerNumber; ++var) {
                connect(Channel_Data_From_Map.value(ind),SIGNAL(signal_putCommand(int, QString, QString)),pLoadinglibaray->ICaptureImagesLit.at(i+var).data(),SLOT(putCommandSlot(int, QString, QString)));
                connect(pLoadinglibaray->ICaptureImagesLit.at(i+var).data(),SIGNAL(pictureStreamSignal(QByteArray, int, QString)),Channel_Data_From_Map.value(ind),SIGNAL(signal_pictureStream(QByteArray, int, QString)));
                connect(Channel_Data_From_Map.value(ind),SIGNAL(signal_playStream(quint64,bool,const QString)),pLoadinglibaray->ICaptureImagesLit.at(i+var).data(),SLOT(playStreamSlot(quint64,bool,const QString)));
            }
            connect(Channel_Data_From_Map.value(ind),SIGNAL(signal_initCamer_front( QString, int, QString, QString,QString)),pLoadinglibaray->ICaptureImagesLit.at(i++).data(),SLOT(initCamerSlot( QString, int, QString, QString,QString)));
            connect(Channel_Data_From_Map.value(ind),SIGNAL(signal_initCamer_before( QString, int, QString, QString,QString)),pLoadinglibaray->ICaptureImagesLit.at(i++).data(),SLOT(initCamerSlot( QString, int, QString, QString,QString)));
            connect(Channel_Data_From_Map.value(ind),SIGNAL(signal_initCamer_left( QString, int, QString, QString,QString)),pLoadinglibaray->ICaptureImagesLit.at(i++).data(),SLOT(initCamerSlot( QString, int, QString, QString,QString)));
            connect(Channel_Data_From_Map.value(ind),SIGNAL(signal_initCamer_right( QString, int, QString, QString,QString)),pLoadinglibaray->ICaptureImagesLit.at(i++).data(),SLOT(initCamerSlot( QString, int, QString, QString,QString)));
            if(7==LocalPar::CamerNumber){
                connect(Channel_Data_From_Map.value(ind),SIGNAL(signal_initCamer_top( QString, int, QString, QString,QString)),pLoadinglibaray->ICaptureImagesLit.at(i++).data(),SLOT(initCamerSlot( QString, int, QString, QString,QString)));
                connect(Channel_Data_From_Map.value(ind),SIGNAL(signal_initCamer_prospects( QString, int, QString, QString,QString)),pLoadinglibaray->ICaptureImagesLit.at(i++).data(),SLOT(initCamerSlot( QString, int, QString, QString,QString)));
                connect(Channel_Data_From_Map.value(ind),SIGNAL(signal_initCamer_foreground( QString, int, QString, QString,QString)),pLoadinglibaray->ICaptureImagesLit.at(i++).data(),SLOT(initCamerSlot( QString, int, QString, QString,QString)));
            }
        }
    }

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
        connect(this,&MainWindow::signal_releaseResources,pLoadinglibaray->IMiddlewareLit.at(0).data(),&IMiddleware::releaseResourcesSlot,Qt::BlockingQueuedConnection);
    }

    if(pLoadinglibaray->InfraredlogicLit.size()>=1){
        for (int var = 0; var < pLoadinglibaray->InfraredlogicLit.size(); ++var) {
            connect(pLoadinglibaray->InfraredlogicLit.at(var).data(),&InfraredlogicInterface::logicStatusSignal,Channel_Data_From_Map.value(var+1),&Channel_Data_Form::slot_logicStatus);
            connect(pLoadinglibaray->InfraredlogicLit.at(var).data(),&InfraredlogicInterface::logicPutImageSignal,Channel_Data_From_Map.value(var+1),&Channel_Data_Form::slot_logicPutImage);
            connect(pLoadinglibaray->InfraredlogicLit.at(var).data(),&InfraredlogicInterface::serialPortStateSignal,Channel_Data_From_Map.value(var+1),&Channel_Data_Form::slot_serialPortState);
            connect(Channel_Data_From_Map.value(var+1),&Channel_Data_Form::signal_simulateTrigger,pLoadinglibaray->InfraredlogicLit.at(var).data(),&InfraredlogicInterface::simulateTriggerSlot);
            connect(Channel_Data_From_Map.value(var+1),&Channel_Data_Form::signal_setAlarmMode,pLoadinglibaray->InfraredlogicLit.at(var).data(),&InfraredlogicInterface::setAlarmModeSlot);
            connect(Channel_Data_From_Map.value(var+1),&Channel_Data_Form::signal_startSlave,pLoadinglibaray->InfraredlogicLit.at(var).data(),&InfraredlogicInterface::startSlaveSlot);
            connect(this,&MainWindow::signal_releaseResources,pLoadinglibaray->InfraredlogicLit.at(var).data(),&InfraredlogicInterface::exitWhileSlot,Qt::BlockingQueuedConnection);
        }
    }

    if(pLoadinglibaray->IDataBaseInsertList.size()>=1){
        for (int var = 0; var < pLoadinglibaray->IDataBaseInsertList.size(); ++var) {
            connect(Channel_Data_From_Map.value(var+1),&Channel_Data_Form::signal_initDataBase,pLoadinglibaray->IDataBaseInsertList.at(var).data(),&DataBaseInsertInterface::initDataBaseSlot);
            connect(Channel_Data_From_Map.value(var+1),&Channel_Data_Form::signal_insertDataBase,pLoadinglibaray->IDataBaseInsertList.at(var).data(),&DataBaseInsertInterface::insertDataBaseSlot);
            connect(Channel_Data_From_Map.value(var+1),&Channel_Data_Form::signal_updateDataBase,pLoadinglibaray->IDataBaseInsertList.at(var).data(),&DataBaseInsertInterface::updateDataBaseSlot);
        }
    }

    if(pLoadinglibaray->IDataBaseReadList.size()>=1){
        connect(this,&MainWindow::signal_initDataBaseR,pLoadinglibaray->IDataBaseReadList.at(0).data(),&DataBaseReadInterface::initDataBaseSlot);
    }
}
