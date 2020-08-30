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

signals:

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

public slots:

    ///
    /// \brief InitializationParameterSlot 初始化参数
    ///
    void InitializationParameterSlot(int channelNumber);

    ///
    /// \brief writeParameterSlot 写入参数
    ///
    bool writeParameterSlot();
};

#endif // SYSTEM_SETTING_FORM_H
