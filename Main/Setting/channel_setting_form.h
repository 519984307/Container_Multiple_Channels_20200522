#ifndef CHANNEL_SETTING_FORM_H
#define CHANNEL_SETTING_FORM_H

#include <QWidget>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>

#include "MainWindow/Processing/channelparameter.h"

namespace Ui {
class Channel_Setting_Form;
}

class Channel_Setting_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Channel_Setting_Form(int number,QWidget *parent = nullptr);
    ~Channel_Setting_Form();

private:
    Ui::Channel_Setting_Form *ui;

    ///
    /// \brief channel_number 通道号
    ///
    int channel_number;

    ///
    /// \brief p_ChannelParameter 配置参数表
    ///
    ChannelParameter *p_ChannelParameter;

    ///
    /// \brief configurationFolder 配置文件夹
    ///
    QFile configurationFolder;

    ///
    /// \brief fileRoot 配置文件根目录
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
    /// \brief getJsonValue 获取配置项
    /// \param child 配置项子名称
    /// \param key 配置项值
    /// \param obj JSON对象
    /// \return
    ///
    QVariant  getJsonValue(const QString &child,const QString &key,QJsonObject obj);

    ///
    /// \brief InitializationParameter 初始化参数
    /// \param number 通道号
    ///
    void InitializationParameter(int number);

public slots:


    ///
    /// \brief writeParameterSlot 写入参数
    ///
    bool writeParameterSlot();
};

#endif // CHANNEL_SETTING_FORM_H
