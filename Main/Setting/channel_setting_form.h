#ifndef CHANNEL_SETTING_FORM_H
#define CHANNEL_SETTING_FORM_H

#define ZBY_LOG(type)  tr("[%1][%2][%3]").arg(type).arg(Q_FUNC_INFO).arg(__LINE__)

#include <QWidget>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QScopedPointer>

#include "MainWindow/Processing/channelparameter.h"

namespace Ui {
class Channel_Setting_Form;
}

class Channel_Setting_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Channel_Setting_Form(QWidget *parent = nullptr);
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

private:

    ///
    /// \brief loadParameter 读取参数
    ///
    bool loadParameter();

    ///
    /// \brief writeParameter 写入参数
    ///
    bool writeParameter();

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

signals:

    ///
    /// \brief messageSignal 日志信号
    /// ]param type 信息类型
    /// \param msg 信息体
    ///
    void messageSignal(QtMsgType type,const QString &msg);

public slots:

    ///
    /// \brief InitializationParameterSlot 初始化参数
    /// \param number 通道号
    ///
    void InitializationParameterSlot(int number);
};

#endif // CHANNEL_SETTING_FORM_H
