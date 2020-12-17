#ifndef ERRORFORM_H
#define ERRORFORM_H

#include <QWidget>

namespace Ui {
class ErrorForm;
}

class ErrorForm : public QWidget
{
    Q_OBJECT

public:
    explicit ErrorForm(QWidget *parent = nullptr);
    ~ErrorForm();

    void setTipInfo(QString info);

private:
    Ui::ErrorForm *ui;

};

#endif // ERRORFORM_H
