#ifndef DATA_LOG_FORM_H
#define DATA_LOG_FORM_H

#include <QWidget>

namespace Ui {
class Data_Log_Form;
}

class Data_Log_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Data_Log_Form(QWidget *parent = nullptr);
    ~Data_Log_Form();

private:
    Ui::Data_Log_Form *ui;
};

#endif // DATA_LOG_FORM_H
