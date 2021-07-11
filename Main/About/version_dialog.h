#ifndef VERSION_DIALOG_H
#define VERSION_DIALOG_H

#include <QDialog>

namespace Ui {
class Version_Dialog;
}

class Version_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Version_Dialog(QWidget *parent = nullptr);
    ~Version_Dialog();

private:
    Ui::Version_Dialog *ui;
};

#endif // VERSION_DIALOG_H
