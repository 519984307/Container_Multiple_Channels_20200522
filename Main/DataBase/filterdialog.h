#ifndef FILTERDIALOG_H
#define FILTERDIALOG_H

#include <QDialog>
#include <QAbstractButton>
#include <QPushButton>

namespace Ui {
class FilterDialog;
}

class FilterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FilterDialog(QWidget *parent = nullptr);
    ~FilterDialog();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::FilterDialog *ui;

signals:

    ///
    /// \brief signal_filterData 数据库筛选条件
    /// \param data
    ///
    void signal_filterData(QString data);
};

#endif // FILTERDIALOG_H
