#ifndef CHANNEL_SETTING_FORM_H
#define CHANNEL_SETTING_FORM_H

#include <QWidget>

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
};

#endif // CHANNEL_SETTING_FORM_H
