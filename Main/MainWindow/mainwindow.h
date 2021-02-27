#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGlobal>
#include <QDesktopWidget>
#include <QMap>
#include <QAction>
#include <QPointer>
#include <QLabel>
#include <QScreen>
#include <QSharedPointer>
#include <QSystemTrayIcon>
#include <QIcon>
#include <QAction>
#include <QMenu>
#include <QCloseEvent>
#include <QCoreApplication>
#include <QDir>
#include <QProgressBar>
#include <QDateTime>
#include <QThread>
#include <QMessageBox>

#include <QtConcurrent>
#include <QFuture>
#include <QFutureWatcher>

/*****************************
* UI
******************************/
#include "ChannelData/channel_data_form.h"
#include "ChannelData/equipment_state_from.h"
#include "Setting/setting_form.h"
#include "CameraTest/camera_list_form.h"
#include "DataBase/database_form.h"
#include "Log/data_log_form.h"
#include "About/aboutdialog.h"

/*****************************
* @brief:Parameter
******************************/
#include "Parameter/loadparameter.h"
#include "Parameter/parameter.h"
#include "Parameter/LocalPar.h"

//#include "touploaddata.h"
#include "logcontroller.h"
#include "Processing/loadinglibaray.h"
#include "DataProcessing/dataprocessing.h"
#include "alarmform.h"
#include "errorform.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow()Q_DECL_OVERRIDE;

protected:
    void closeEvent(QCloseEvent *event)Q_DECL_OVERRIDE;
    void changeEvent(QEvent* event)Q_DECL_OVERRIDE;

private:

    /*****************************
    * func
    ******************************/

    ///
    /// \brief initializing 加载参数对象
    ///
    void initializing();

    ///
    /// \brief initializingObject 初始化对象
    ///
    void initializingObject();

    ///
    /// \brief initializationParameter 初始化参数
    ///
    void initializationParameter();

    ///
    /// \brief clearnMap 清除容器
    ///
    void clearnContainer();

    ///
    /// \brief setStatusBar 设置状态栏信息
    ///
    void setStatusBar(const QString &msg);

    ///
    /// \brief connectProcess 主窗口信号与槽
    ///
    void connectProcess();

    ///
    /// \brief getScreenInfo 获取和设置系统屏幕大小
    ///
    void getScreenInfo();

    ///
    /// \brief bindingPlugin 绑定插件
    ///
    void bindingPlugin();

    ///
    /// \brief loadStyleSheet 加载样式表
    /// \param fileName 文件名
    ///
    void loadStyleSheet(const QString &fileName);

private:

    /*****************************
    * container
    ******************************/

    ///
    /// \brief From_Action_Map 数据窗口工具栏字典集
    ///
    QMap<QAction*,int> From_Action_Map;

    ///
    /// \brief Channel_Data_From_Map 数据窗口字典集
    ///
    QMap<int,Channel_Data_Form *> Channel_Data_From_Map;

    ///
    /// \brief Form_Map 窗口类对象合集
    ///
    QList<QObject*> Form_Map;

    ///
    /// \brief tdList 子线程集
    ///
    QList<QThread*> tdList;

    /*****************************
    * attribute
    ******************************/

    ///
    /// \brief channelSelect 数据界面组中,当前预览的通道号
    ///
    int channelSelect;

    ///
    /// \brief channelCount 通道数
    ///
    int channelCount;

    ///
    /// \brief channelLabels 通道名称列表
    ///
    QStringList channelLabels;

    ///
    /// \brief channelParCount 通道配置文件个数
    ///
    int channelParCount;

    ///
    /// \brief isExit 退出系统
    ///
    bool isExit;

    ///
    /// \brief alarmNum 警报数量
    ///
    int alarmNum;

    /*****************************
    * object
    ******************************/

    Ui::MainWindow *ui;       

    ///
    /// \brief pLoadinglibaray 加载插件
    ///
    QSharedPointer<LoadingLibaray> pLoadinglibaray;

    ///
    /// \brief DataProcessingList 数据综合处理类
    ///
    QList<QSharedPointer<DataProcessing>>  DataProcessingList;

    ///
    /// \brief pErrorForm 错误弹幕
    ///
    QPointer<ErrorForm> pErrorForm;

    ///
    /// \brief pAlarmForm 错误状态指示
    ///
    QPointer<AlarmForm> pAlarmForm;

//    ///
//    /// \brief watcher 监视异步加载插件完成状态
//    ///
//    QFutureWatcher<void> *watcher;

//    ///
//    /// \brief pUpload 上传文件
//    ///
//    QPointer<ToUploadData> pUpload;

    ///
    /// \brief pLog 日志
    ///
    QPointer<LogController> pLog;

    ///
    /// \brief actionShow 任务栏显示主页面
    ///
    QPointer<QAction> actionShow;

    ///
    /// \brief actionExit 任务栏退出
    ///
    QPointer<QAction> actionExit;

    ///
    /// \brief Pointer_Parameter 参数加载
    ///
    QPointer<LoadParameter> Pointer_Parameter;

    ///
    /// \brief SystemTray 任务栏
    ///
    QPointer<QSystemTrayIcon> SystemTray;

    ///
    /// \brief systemTrayMen 任务栏菜单
    ///
    QPointer<QMenu> systemTrayMen;

    ///
    /// \brief pAction 工具栏按钮
    ///
    QPointer<QAction> pAction;
    /*****************************
    * @brief:UI
    ******************************/

    ///
    /// \brief p_Data_Log_Form 运行日志窗口
    ///
    QSharedPointer<Data_Log_Form> p_Data_Log_Form;

    ///
    /// \brief p_Equipment_State_Form 设备列表窗口
    ///
    Equipment_State_From *p_Equipment_State_Form;

    ///
    /// \brief permanentLabel 状态栏永久信息
    ///
    QLabel *permanentLabel;

    ///
    /// \brief runTimeLabel 系统运行时长
    ///
    QLabel *runTimeLabel;

    ///
    /// \brief throughTheNumberLabel 通过数量
    ///
    QLabel *throughTheNumberLabel;

    ///
    /// \brief hardDriveCapacityLabel 硬盘容量
    ///
    QLabel *hardDriveCapacityLabel;

    ///
    /// \brief socketLinkCountLabel tcp链接数量
    ///
    QLabel *socketLinkCountLabel;

    ///
    /// \brief statusProgressBar 状态栏进度条
    ///
    QProgressBar *statusProgressBar;

private slots:

    /*****************************
    * triggerd
    ******************************/
    ///
    /// \brief systemTrayAction 任务栏菜单
    ///
    void systemTrayAction();

    ///
    /// \brief systemTrayTriggered 任务栏点击事件
    ///
    void systemTrayTriggered(QSystemTrayIcon::ActivationReason reason);

    ///
    /// \brief actionTiggeredSlot 工具栏按钮事件
    ///
    void actionTiggeredSlot();

    ///
    /// \brief on_actionParameter_Settings_triggered 系统参数设置
    ///
    void on_actionParameter_Settings_triggered();

    ///
    /// \brief on_actionCamera_Test_triggered 相机调试
    ///
    void on_actionCamera_Test_triggered();

    ///
    /// \brief on_actionHistory_Sqlite_triggered 查找历史记录
    ///
    void on_actionHistory_Sqlite_triggered();

    ///
    /// \brief on_actionData_log_triggered 系统日志
    ///
    void on_actionData_log_triggered();

    ///
    /// \brief on_actionExit_triggered 退出系统
    ///
    void on_actionExit_triggered();

    ///
    /// \brief on_actionAbout_triggered 关于对话框
    ///
    void on_actionAbout_triggered();

private slots:

    ///
    /// \brief slot_handleFinished 异步加载插件完成
    ///
    void slot_handleFinished();

    ///
    /// \brief slot_progressRangeChanged 异步加载插件设置进度条范围
    /// \param minimum
    /// \param maximum
    ///
    void slot_progressRangeChanged(int minimum, int maximum);

    ///
    /// \brief slot_progressTextChanged 异步加载插件设置进度条文本
    /// \param progressText
    ///
    void slot_progressTextChanged(const QString &progressText);

    ///
    /// \brief slot_progressValueChanged 异步加载插件设置进度条值
    /// \param progressValue
    ///
    void slot_progressValueChanged(int progressValue);

    ///
    /// \brief slot_Error 错误弹幕
    /// \param pluginName
    ///
    void slot_Error(QString pluginName);

    ///
    /// \brief slot_hideErrorForm 隐藏错误弹幕
    ///
    void slot_hideErrorForm();

    ///
    /// \brief slot_theFtpProgress FTP上传进度
    /// \param bytesSent 上传大小
    /// \param bytesTotal 上传总量
    ///
    void slot_theFtpProgress(qint64 bytesSent, qint64 bytesTotal);

signals:

    /*****************************
    * signal
    ******************************/

    ///
    /// \brief initializesTheDeviceStateListSignal 初始化设备状态列表
    /// \param count 通道数
    /// \param rowLabels 通道名称
    ///
    void initializesTheDeviceStateListSignal(int count,QStringList rowLabels);

    ///
    /// \brief setDeviceStatusSignal 设置设备表状态
    /// \param channel 通道
    /// \param equipment 设备
    /// \param state 状态
    ///
    void setDeviceStatusSignal(int channel, int equipment,bool state);

    ///
    /// \brief signal_createLibaray 加载插件
    ///
    void signal_createLibaray();

    ///
    /// \brief signal_setAlarmMsg 设置警报信息
    /// \param num 警报数量
    /// \param msg 信息
    ///
    void signal_setAlarmMsg(int num,QString msg);

    ///
    /// \brief signal_initEquipment 初始化设备
    ///
    void signal_initEquipment();

    ///
    /// \brief signal_destructorThread 析构插件线程
    ///
    void signal_destructorThread();

    ///
    /// \brief signal_releaseResources 释放插件资源
    ///
    void signal_releaseResources();    

    ///
    /// \brief signal_initDataBaseR 初始化数据库.如果不存在,就创建.
    /// \param connectName 链接名称
    /// \param user 用户名
    /// \param pass密码
    /// \param ip 地址
    /// \param dataBaseType 数据库类型
    ///
    void signal_initDataBaseR(const QString &connectName,const QString &user,const QString &pass,const QString &ip,const int &dataBaseType);

    ///
    /// \brief signal_InitializationFTPParameter 初始化FTP参数
    /// \param host 地址
    /// \param port 端口
    /// \param path 路径
    /// \param user 用户名
    /// \param pass 密码
    ///
    void signal_InitializationFTPParameter(const QString &user,const QString &pass,const QString &path,const QString &host,const int &port=21);

    ///
    /// \brief signal_setCameraCaptureType 设置相机抓拍模式
    /// \param capType
    /// \param msgCallBackInd
    ///
    void signal_setCameraCaptureType(const int &capType, const int &msgCallBackInd);

    ///
    /// \brief signal_setPlateCaptureType 设置车牌抓拍模式
    /// \param capType
    /// \param msgCallBackInd
    ///
    void signal_setPlateCaptureType(const int &capType, const int &msgCallBackInd);
};

#endif // MAINWINDOW_H
