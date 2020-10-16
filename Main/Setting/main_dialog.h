#ifndef MAIN_DIALOG_H
#define MAIN_DIALOG_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class Main_Dialog;
}

class Main_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Main_Dialog(QWidget *parent = nullptr);
    ~Main_Dialog();

private:

    ///
    /// \brief loadParameter 加载系统配置参数,【优先加载】
    ///
    void loadParameter();

    ///
    /// \brief setSystemModel 设置系统模式
    ///
    void setSystemModel();

    ///
    /// \brief startTheTimer 倒计时启动系统
    ///
    void startTheTimer();

private slots:
    void on_pushButton_clicked();

    ///
    /// \brief on_comboBox_currentIndexChanged 设置软件模式，更改UI
    /// \param index
    ///
    void on_comboBox_currentIndexChanged(int index);

    ///
    /// \brief on_ChannelNumber_valueChanged 设置通道数量，更改UI
    /// \param arg1
    ///
    void on_ChannelNumber_valueChanged(int arg1);

    ///
    /// \brief theCountdown 程序启动倒计时
    ///
    void theCountdown();

private:

    Ui::Main_Dialog *ui;

    ///
    /// \brief cot 倒计时
    ///
    int cot;
};

#endif // MAIN_DIALOG_H
