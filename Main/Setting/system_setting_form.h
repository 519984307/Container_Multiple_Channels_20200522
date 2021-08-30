#ifndef SYSTEM_SETTING_FORM_H
#define SYSTEM_SETTING_FORM_H

#include <QWidget>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QMessageLogger>
#include <QtNetwork/QNetworkInterface>
#include <QTableWidgetItem>
#include <QShowEvent>

#include "Parameter/parameter.h"

namespace Ui {
class System_Setting_Form;
}

class System_Setting_Form : public QWidget
{
    Q_OBJECT

public:
    explicit System_Setting_Form(int channelNumber,QWidget *parent = nullptr);
    ~System_Setting_Form();    

    void showEvent(QShowEvent *event)Q_DECL_OVERRIDE;

private slots:

    ///
    /// \brief on_Service_Type_comboBox_currentIndexChanged 设置通讯模式
    /// \param index
    ///
    void on_Service_Type_comboBox_currentIndexChanged(int index);

    ///
    /// \brief on_CheckPathPushButton_clicked 设置图片保存路径
    ///
    void on_CheckPathPushButton_clicked();

    ///
    /// \brief conditionsOfButton_clicked 字头条件按钮
    ///
    void conditionsOfButton_clicked();

    ///
    /// \brief on_AutomaticStart_stateChanged 开机启动框状态
    /// \param arg1
    ///
    void on_AutomaticStart_stateChanged(int arg1);

    ///
    /// \brief on_ChannelNumber_valueChanged 设置通道数量
    /// \param arg1
    ///
    void on_ChannelNumber_valueChanged(int arg1);

    ///
    /// \brief on_HCNET_Capture_Type_comboBox_currentIndexChanged 海康相机抓拍模式
    /// \param index
    ///
    void on_HCNET_Capture_Type_comboBox_currentIndexChanged(int index);

    ///
    /// \brief on_Camera_Load_Plugin_comboBox_currentIndexChanged 海康相机插件加载模式
    /// \param index
    ///
    void on_Camera_Load_Plugin_comboBox_currentIndexChanged(int index);

    ///
    /// \brief on_DataChaneType_combox_currentIndexChanged 数据接口模式
    /// \param index
    ///
    void on_DataChaneType_combox_currentIndexChanged(int index);

    ///
    /// \brief on_searchEquipment_pushButton_clicked 搜索网络控制器
    ///
    void on_searchEquipment_pushButton_clicked();

    ///
    /// \brief on_equiment_tableWidget_itemClicked 读取搜索到设备参数
    /// \param item
    ///
    void on_equiment_tableWidget_itemClicked(QTableWidgetItem *item);

    ///
    /// \brief on_setParameter_pushButton_clicked 设置网络控制器参数
    ///
    void on_setParameter_pushButton_clicked();

    ///
    void on_loadLibrary_HK_checkBox_stateChanged(int arg1);

    /// \brief on_searchInternet_pushButton_clicked 查找网卡
    ///
    void on_searchInternet_pushButton_clicked();

signals:

    ///
    /// \brief initializesTheDeviceTemporaryTableSignal 初始化设备列表
    /// \param count 通道数
    /// \param rowLabels 通道名称
    ///
    void initializesTheDeviceTemporaryTableSignal(int count, QStringList rowLabels);

    ///
    /// \brief messageSignal 日志信息
    /// \param type 日志类型
    /// \param msg 信息体
    ///
    void messageSignal(const QString &type,const QString &msg);

    ///
    /// \brief setSaveImgFormatSignal 设置图片保存路径1
    /// \param path 图片路径
    /// \param format 保存协议
    ///
    void setSaveImgFormatSignal(const QString &path,int format);

    ///
    /// \brief setAutomaticStateSingal 设置开机自动启动状态
    /// \param status 状态
    ///
    void automaticStateSingal(bool status);

    ///
    /// \brief searchEquipmentSignal 搜索网络控制器设备
    /// \param address 地址
    /// \param port 端口
    ///
    void searchEquipmentSignal(QString address,int port);

    ///
    /// \brief setEquipmentParSignal 设置网络控制器参数
    /// \param par
    ///
    void setEquipmentParSignal(QMap<QString,QMap<QString,QString>> par);

private:
    Ui::System_Setting_Form *ui;

    ///
    /// \brief configurationFolder 配置文件夹
    ///
    QFile configurationFolder;

    ///
    /// \brief fileRoot 参数保存路径根目录
    ///
    QString fileRoot;

    ///
    /// \brief parMap 读取的网络控制器参数
    ///
    QMap<QString, QMap<QString, QString>> parMap;

private:

    ///
    /// \brief loadParameter 读取参数
    ///
    bool loadParameter();

    ///
    /// \brief parameterToUi 回写参数到界面
    ///
    void parameterToUi();

    ///
    /// \brief getJsonValue 获取参数值
    ///
    QVariant getJsonValue(const QString &child, const QString &key, QJsonObject obj);    

    ///
    /// \brief InitializationParameter 初始化参数
    ///
    void InitializationParameter(int channelNumber);

    ///
    /// \brief loadAdapterMAC 获取网卡MAC地址
    ///
    void loadAdapterMAC();

public slots:

    ///
    /// \brief writeParameterSlot 写入参数
    ///
    bool writeParameterSlot();

    ///
    /// \brief sendEquipmentParSlot 接收搜索到网络控制器参数
    /// \param par
    ///
    void sendEquipmentParSlot(QMap<QString,QMap<QString,QString>> par);

    ///
    /// \brief setParSucessSlot 网络控制器参数设置成功
    ///
    void setParSucessSlot();

    ///
    /// \brief systemCurrentRowChangedSignal 系统设置页面
    /// \param currentRow
    ///
    void systemCurrentRowChangedSlot(int currentRow);
};

#endif // SYSTEM_SETTING_FORM_H
