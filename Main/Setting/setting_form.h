#ifndef SETTING_FORM_H
#define SETTING_FORM_H

#include <QWidget>
#include <QMap>
#include <QShowEvent>
#include <QMessageLogger>

#include "channel_setting_form.h"
#include "system_setting_form.h"

namespace Ui {
class Setting_Form;
}

class Setting_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Setting_Form(QWidget *parent = nullptr);
    ~Setting_Form();

    void showEvent(QShowEvent *event);

private:

    /*****************************
     * func
     ******************************/

    ///
    /// \brief hideTheWindow 隐藏窗口
    ///
    void hideTheWindow();

private:

    /*****************************
    * The container
    ******************************/

    ///
    /// \brief Setting_Map 窗口类对象
    ///
    QMap<int,QObject*> Setting_Map;

    //QScopedArrayPointer<Channel_Setting_Form> pForm;

private slots:

    /*****************************
     *  slot
     ******************************/

    ///
    /// \brief initializesTheDeviceListSlot 初始化设备列表
    /// \param count 通道数
    /// \param rowLabels 通道名称
    ///
    void initializesTheDeviceListSlot(int count, QStringList rowLabels);

    ///
    /// \brief on_channel_pushButton_clicked 通道设定
    ///
    void on_channel_pushButton_clicked();

    ///
    /// \brief on_system_pushButton_clicked 系统设定
    ///
    void on_system_pushButton_clicked();

    ///
    /// \brief on_listWidget_currentRowChanged 通道切换
    /// \param currentRow
    ///
    void on_listWidget_currentRowChanged(int currentRow);

    ///
    /// \brief on_buttonBox_clicked 保存日志
    /// \param button
    ///
    void on_buttonBox_clicked(QAbstractButton *button);

signals:

    ///
    /// \brief writeParameterSignal 保存设置参数
    /// \return 保存状态
    ///
    bool writeParameterSignal();

    ///
    /// \brief InitializationParameterSignal 初始化通道设置参数
    /// \param number 通道号
    ///
    void InitializationParameterSignal(int number);

    ///
    /// \brief InitializationParameterSignal 初始化系统设置参数
    /// \param number 通道号
    ///
    void InitializationParameterSignal();

private:

    /*****************************
     * object
     ******************************/

    Ui::Setting_Form *ui;


    /*****************************
    * attribute
    ******************************/

    ///
    /// \brief channelSelect 设置界面组中,当前预览的通道号
    ///
    int channelSelect;
};

#endif // SETTING_FORM_H
