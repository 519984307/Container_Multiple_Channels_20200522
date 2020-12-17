#ifndef ALARMFORM_H
#define ALARMFORM_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class AlarmForm;
}

class AlarmForm : public QWidget
{
    Q_OBJECT

public:
    explicit AlarmForm(QWidget *parent = nullptr);
    ~AlarmForm();

private:
    Ui::AlarmForm *ui;

    QList<QString> msgList;

public slots:

    ///
    /// \brief slot_setAlarmMsg 设置警报信息
    /// \param num 警报数量
    /// \param msg 信息
    ///
    void slot_setAlarmMsg(int num,QString msg);
private slots:
    void on_toolButton_clicked();
};

#endif // ALARMFORM_H
