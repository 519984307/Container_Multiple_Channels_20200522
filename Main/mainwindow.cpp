#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initializingAttribute();
    initStatusBar();
    initializesTheDataWindow();
    initializationParameter();
    mainWindowConnect();
}

MainWindow::~MainWindow()
{
    clearnMap();

    delete ui;
}

void MainWindow::clearnMap()
{
    qDeleteAll(WindowsVector);

    WindowsVector.clear();
    Channel_Data_From_Map.clear();
    Channel_Data_Action_Map.clear();
}

void MainWindow::hideTheWindow()
{
    foreach (auto window, WindowsVector) {
        if(Channel_Data_Form *pFrom=qobject_cast<Channel_Data_Form*>(window)){
            pFrom->setVisible(false);
        }
        else if (Equipment_State_From *pFrom=qobject_cast<Equipment_State_From*>(window)) {
            pFrom->setVisible(false);
        }
        else if (Setting_Form *pFrom=qobject_cast<Setting_Form*>(window)) {
            pFrom->setVisible(false);
        }
    }
}

void MainWindow::mainWindowConnect()
{
    if(p_Equipment_State_From!=nullptr){
        p_Equipment_State_From->setVisible(true);

        connect(this,SIGNAL(initializesTheDeviceStateListSignal(int,QStringList)),p_Equipment_State_From,SLOT(initializesTheDeviceStateListSlot(int,QStringList)));
        connect(this,SIGNAL(setDeviceStatusSignal(int,int,bool)),p_Equipment_State_From,SLOT(setDeviceStatusSlot(int,int,bool)));
    }
    if(p_Setting_From!=nullptr){
        connect(this,SIGNAL(initializesTheDeviceStateListSignal(int,QStringList)),p_Setting_From,SLOT(initializesTheDeviceStateListSlot(int,QStringList)));
    }

    emit initializesTheDeviceStateListSignal(channelCount,channelLabels);
}

void MainWindow::initializingAttribute()
{
    channelCount=20;

    permanentWidget = new QLabel (tr("The system is ready"),this);
    p_Equipment_State_From=new Equipment_State_From (this);
    p_Setting_From=new Setting_Form(this);

    ui->gridLayout_2->addWidget(p_Setting_From);
    ui->gridLayout_2->addWidget(p_Equipment_State_From);

    WindowsVector.append(p_Setting_From);
    WindowsVector.append(permanentWidget);
    WindowsVector.append(p_Equipment_State_From);
}

void MainWindow::initializationParameter()
{
    foreach (auto action, Channel_Data_Action_Map.keys()) {
        /* 绑定工具栏事件 */
        connect(action,SIGNAL(triggered()),this,SLOT(actionTiggeredSlot()));
    }
}

void MainWindow::initializesTheDataWindow()
{
    for (int channel=1;channel<=channelCount;channel++) {
        Channel_Data_Form *pFrom=new Channel_Data_Form (this);

        ui->gridLayout_2->addWidget(pFrom);

        QAction *pAction=new QAction (tr("%1 # Channel").arg(channel,2,10,QChar('0')),this);

        Channel_Data_From_Map.insert(channel,pFrom);
        Channel_Data_Action_Map.insert(pAction,pFrom);

        WindowsVector.append(pFrom);        
        channelLabels.append(pAction->text());

        ui->menuChannel_To_View->addAction(pAction);
        ui->mainToolBar->addAction(pAction);
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

void MainWindow::actionTiggeredSlot()
{
    QAction* pAction=qobject_cast<QAction*> (sender());

    QMap<QAction*,QObject*>::const_iterator it =Channel_Data_Action_Map.find(pAction);
    if(it!=Channel_Data_Action_Map.end()){
        if(Channel_Data_Form *pFrom=qobject_cast<Channel_Data_Form*>(it.value()))
        {
            hideTheWindow();
            pFrom->setVisible(true);
            setStatusBar(pAction->text());
        }
    }
}

void MainWindow::setStatusBar(QString msg)
{
    if(permanentWidget!=nullptr){
        permanentWidget->setText(msg);
    }
}

void MainWindow::on_actionMainWindow_triggered()
{
    if(p_Equipment_State_From!=nullptr){
        hideTheWindow();
        p_Equipment_State_From->setVisible(true);
        setStatusBar("The system is ready");
    }
}

void MainWindow::on_actionSystem_Settings_triggered()
{
    if(p_Setting_From!=nullptr){
        hideTheWindow();
        p_Setting_From->setVisible(true);
        setStatusBar("Setting system parameters");
    }
}

void MainWindow::on_actiontest_triggered()
{
    emit setDeviceStatusSignal(3,8,true);
}
