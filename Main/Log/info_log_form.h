#ifndef INFO_LOG_FORM_H
#define INFO_LOG_FORM_H

#include <QWidget>

namespace Ui {
class Info_Log_Form;
}

class Info_Log_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Info_Log_Form(QWidget *parent = nullptr);
    ~Info_Log_Form();

private:
    Ui::Info_Log_Form *ui;
};

#endif // INFO_LOG_FORM_H
