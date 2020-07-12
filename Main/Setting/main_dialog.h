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

private:
    Ui::Main_Dialog *ui;
};

#endif // MAIN_DIALOG_H
