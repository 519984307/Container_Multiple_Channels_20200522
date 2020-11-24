#ifndef ERRCODEFORM_H
#define ERRCODEFORM_H

#include <QWidget>
#include <QFile>
#include <QCloseEvent>

namespace Ui {
class ErrCodeForm;
}

class ErrCodeForm : public QWidget
{
    Q_OBJECT

public:
    explicit ErrCodeForm(QWidget *parent = nullptr);
    ~ErrCodeForm();

    void closeEvent(QCloseEvent *event) override;

private:
    Ui::ErrCodeForm *ui;


public slots:

    ///
    /// \brief readErrCode 加载错误码
    /// \param path 错误码路径
    /// \return
    ///
    bool slot_readErrCode(QString path);

signals:

    void signal_theFormExit(QString cls);
};

#endif // ERRCODEFORM_H
