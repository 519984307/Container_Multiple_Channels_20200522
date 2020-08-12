#ifndef COMMUNICATION_LOGS_FORM_H
#define COMMUNICATION_LOGS_FORM_H

#include <QWidget>

namespace Ui {
class Communication_Logs_Form;
}

class Communication_Logs_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Communication_Logs_Form(QWidget *parent = nullptr);
    ~Communication_Logs_Form();

private:
    Ui::Communication_Logs_Form *ui;
};

#endif // COMMUNICATION_LOGS_FORM_H
