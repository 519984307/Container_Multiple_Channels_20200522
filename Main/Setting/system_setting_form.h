#ifndef SYSTEM_SETTING_FORM_H
#define SYSTEM_SETTING_FORM_H

#include <QWidget>

namespace Ui {
class System_Setting_Form;
}

class System_Setting_Form : public QWidget
{
    Q_OBJECT

public:
    explicit System_Setting_Form(QWidget *parent = nullptr);
    ~System_Setting_Form();

private:
    Ui::System_Setting_Form *ui;
};

#endif // SYSTEM_SETTING_FORM_H
