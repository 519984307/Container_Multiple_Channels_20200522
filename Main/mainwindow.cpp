#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    channelCount=10;
    initializesTheDataWindow();
    initializationParameter();
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

void MainWindow::resizeEvent(QResizeEvent *size)
{
    foreach (auto window, WindowsVector) {
        if(Channel_Data_Form *pFrom=qobject_cast<Channel_Data_Form*>(window)){
            pFrom->resize(size->size().width(),size->size().height()-90);
        }
    }
}

void MainWindow::hideTheWindow()
{
    foreach (auto window, WindowsVector) {
        if(Channel_Data_Form *pFrom=qobject_cast<Channel_Data_Form*>(window)){
            pFrom->setVisible(false);
        }
    }
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
    for (uint channel=1;channel<=channelCount;channel++) {
        Channel_Data_Form *pFrom=new Channel_Data_Form (this);
        QAction *pAction=new QAction (tr("%1 # Channel").arg(channel),this);

        Channel_Data_From_Map.insert(channel,pFrom);
        Channel_Data_Action_Map.insert(pAction,pFrom);
        WindowsVector.append(pFrom);

        ui->mainToolBar->addAction(pAction);
    }
}

void MainWindow::actionTiggeredSlot()
{
    hideTheWindow();

    QAction* pAction=qobject_cast<QAction*> (sender());

    QMap<QAction*,QObject*>::const_iterator it =Channel_Data_Action_Map.find(pAction);
    if(it!=Channel_Data_Action_Map.end()){
        if(Channel_Data_Form *pFrom=qobject_cast<Channel_Data_Form*>(it.value()))
        {
            pFrom->move(0,65);
            pFrom->setVisible(true);
        }
    }
}
