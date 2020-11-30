#ifndef SIMULATIONDIALOG_H
#define SIMULATIONDIALOG_H

#include <QDialog>

namespace Ui {
class SimulationDialog;
}

class SimulationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SimulationDialog(QWidget *parent = nullptr);
    ~SimulationDialog();

private slots:
    void on_capturePushButton_clicked();

    void on_plateCapPushButton_clicked();

    void on_liftingLeverPushButton_clicked();

    void on_fallRodPushButton_clicked();

private:
    Ui::SimulationDialog *ui;
};

#endif // SIMULATIONDIALOG_H
