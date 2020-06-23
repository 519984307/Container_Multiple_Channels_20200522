#ifndef CHANNEL_DATA_FORM_H
#define CHANNEL_DATA_FORM_H

#include <QWidget>

namespace Ui {
class Channel_Data_Form;
}

class Channel_Data_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Channel_Data_Form(QWidget *parent = nullptr);
    ~Channel_Data_Form();

private:
    Ui::Channel_Data_Form *ui;
};

#endif // CHANNEL_DATA_FORM_H
