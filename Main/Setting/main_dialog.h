#ifndef MAIN_DIALOG_H
#define MAIN_DIALOG_H

#include <QDialog>

namespace Ui {
class Main_Dialog;
}

class Main_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Main_Dialog(QWidget *parent = nullptr);
    ~Main_Dialog();

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

private:
    Ui::Main_Dialog *ui;
};

#endif // MAIN_DIALOG_H
