#include "setting_form.h"
#include "ui_setting_form.h"

Setting_Form::Setting_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Setting_Form)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose,true);

    this->setParent(parent);
    this->setHidden(true);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    ui->listWidget->setVisible(false);
}

Setting_Form::~Setting_Form()
{
    foreach (auto obj, Setting_Map.values()) {
        if(System_Setting_Form *Obj=qobject_cast<System_Setting_Form*>(obj)){
            Q_UNUSED(Obj);
        }
        else if(Channel_Setting_Form *Obj=qobject_cast<Channel_Setting_Form*>(obj)){
            Q_UNUSED(Obj);
        }
        else {
            continue;
        }

        delete obj;
        obj=nullptr;
    }

    Setting_Map.clear();
    delete ui;
}

void Setting_Form::showEvent(QShowEvent *event)
{
    if(event->type()==QEvent::Show){
        ui->system_pushButton->setFocus();
        emit on_system_pushButton_clicked();
    }
}

void Setting_Form::hideTheWindow()
{
    foreach (auto obj, Setting_Map.values()) {
        if(System_Setting_Form *Obj=qobject_cast<System_Setting_Form*>(obj)){
            Obj->setVisible(false);
        }
        if(Channel_Setting_Form *Obj=qobject_cast<Channel_Setting_Form*>(obj)){
            Obj->setVisible(false);
        }
    }
}

void Setting_Form::automaticStartup(bool start)
{
    /*****************************
    * @brief:window 开机启动注册表
    ******************************/
    /*
    HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run
    HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Run
    */

    QSettings reg(QDir::toNativeSeparators("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"),QSettings::NativeFormat);
    QString app=QCoreApplication::applicationName();
    QString path=QDir::toNativeSeparators(QCoreApplication::applicationFilePath());

    if(start){
        reg.setValue(app,path);

    }
    else {
        reg.remove(app);
    }
}

void Setting_Form::initializesTheDeviceListSlot(int count, QStringList rowLabels)
{
    automatic=false;
    channelSelect=0;

    ui->listWidget->addItems(rowLabels);

    for (int var = 0; var < count; ++var) {
        ui->listWidget->item(var)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        /*****************************
        * @brief: 添加通道设置窗口到容器
        ******************************/
        Channel_Setting_Form *p_Channel_Setting_Form=new Channel_Setting_Form (var+1,this);

        /*****************************
        * @brief: 保存参数
        ******************************/
        connect(this,SIGNAL(writeParameterSignal()),p_Channel_Setting_Form,SLOT(writeParameterSlot()));

        Setting_Map.insert(var+1,p_Channel_Setting_Form);
        ui->gridLayout->addWidget(p_Channel_Setting_Form);
    }

    /*****************************
    * @brief: 添加系统设置到容器
    ******************************/
    System_Setting_Form *p_System_Setting_Form=new System_Setting_Form (count,this);

    /*****************************
    * @brief: 保存参数
    ******************************/
    connect(this,SIGNAL(writeParameterSignal()),p_System_Setting_Form,SLOT(writeParameterSlot()));

    /*****************************
    * @brief:获取开机启动设置状态
    ******************************/
    connect(p_System_Setting_Form,SIGNAL(automaticStateSingal(bool)),this,SLOT(automaticStateSlot(bool)));

    /*****************************
    * @brief: 初始化参数
    ******************************/
    //connect(this,SIGNAL(InitializationParameterSignal()),p_System_Setting_Form,SLOT(InitializationParameterSlot()));
    //emit InitializationParameterSignal();

    Setting_Map.insert(0,p_System_Setting_Form);
    ui->gridLayout->addWidget(p_System_Setting_Form);
    p_System_Setting_Form->setVisible(true);
}

void Setting_Form::on_channel_pushButton_clicked()
{
    channelSelect=0;

    ui->listWidget->setCurrentRow(-1);
    ui->listWidget->setVisible(true);
    ui->listWidget->setFocus();
    ui->listWidget->setCurrentRow(0);
}

void Setting_Form::on_system_pushButton_clicked()
{
    if(System_Setting_Form *Obj=qobject_cast<System_Setting_Form*>(Setting_Map.value(0))){
        if(Obj->isVisible()){
            return;
        }
        hideTheWindow();

        ui->listWidget->setVisible(false);

        Obj->setVisible(true);
        channelSelect=0;
    }
}

void Setting_Form::on_listWidget_currentRowChanged(int currentRow)
{
    /*****************************
    * 列表选中项发生改变,才触发信号
    ******************************/
    if(channelSelect!=currentRow+1){

        if(Channel_Setting_Form *Obj=qobject_cast<Channel_Setting_Form*>(Setting_Map.value(currentRow+1))){
            if(Obj->isVisible()){
                return;
            }
            hideTheWindow();

            Obj->setVisible(true);

            channelSelect=currentRow+1;
        }
    }
}

void Setting_Form::on_buttonBox_clicked(QAbstractButton *button)
{
    if(button==ui->buttonBox->button(QDialogButtonBox::Save)){
        QByteArray msg=tr("Save System Json Sucess").toLocal8Bit();
        qInfo("%s", msg.data());
        QMessageBox::warning(this,tr("Save System Settings"),tr("Parameter saved successfully, software restart takes effect"));

        if(!writeParameterSignal()){
            /*****************************
            * @brief: 参数保存失败,做提示
            ******************************/
            qWarning("Save System Json error");
            QMessageBox::warning(this,"Save System Settings","Save System Json error");
        }
        else {
            /*****************************
            * @brief:开机自动启动
            ******************************/
            automaticStartup(automatic);
        }

    }
    if(button==ui->buttonBox->button(QDialogButtonBox::Ignore)){
        /*****************************
        * @brief: 参数未保存做提示
        ******************************/
        QByteArray msg=tr("Not Save System Json").toLocal8Bit();
        qWarning("%s", msg.data());
        QMessageBox::warning(this,"Save System Settings","Not Save System Json");
    }

    /*****************************
    * @brief:返回主页面
    ******************************/
    emit showMainWindowSignal();

}

void Setting_Form::automaticStateSlot(bool status)
{
    automatic=status;
}
