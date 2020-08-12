#ifndef OPERATIONAL_LOG_FORM_H
#define OPERATIONAL_LOG_FORM_H

#include <QWidget>

namespace Ui {
class Operational_Log_Form;
}

class Operational_Log_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Operational_Log_Form(QWidget *parent = nullptr);
    ~Operational_Log_Form();

private:
    Ui::Operational_Log_Form *ui;
};

#endif // OPERATIONAL_LOG_FORM_H
