#ifndef IDENTIFY_THE_LOG_FORM_H
#define IDENTIFY_THE_LOG_FORM_H

#include <QWidget>

namespace Ui {
class Identify_The_Log_Form;
}

class Identify_The_Log_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Identify_The_Log_Form(QWidget *parent = nullptr);
    ~Identify_The_Log_Form();

private:
    Ui::Identify_The_Log_Form *ui;
};

#endif // IDENTIFY_THE_LOG_FORM_H
