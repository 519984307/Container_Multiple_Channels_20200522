#ifndef MAIN_SETTING_FORM_H
#define MAIN_SETTING_FORM_H

#include <QWidget>

namespace Ui {
class Main_Setting_Form;
}

class Main_Setting_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Main_Setting_Form(QWidget *parent = nullptr);
    ~Main_Setting_Form();

private:
    Ui::Main_Setting_Form *ui;
};

#endif // MAIN_SETTING_FORM_H
