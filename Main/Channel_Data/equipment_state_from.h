#ifndef EQUIPMENT_STATE_FROM_H
#define EQUIPMENT_STATE_FROM_H

#include <QWidget>

namespace Ui {
class Equipment_State_From;
}

class Equipment_State_From : public QWidget
{
    Q_OBJECT

public:
    explicit Equipment_State_From(QWidget *parent = nullptr);
    ~Equipment_State_From();

private:
    Ui::Equipment_State_From *ui;
};

#endif // EQUIPMENT_STATE_FROM_H
