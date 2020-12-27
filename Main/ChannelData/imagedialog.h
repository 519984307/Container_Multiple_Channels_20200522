#ifndef IMAGEDIALOG_H
#define IMAGEDIALOG_H

#include <QDialog>

namespace Ui {
class ImageDialog;
}

class ImageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ImageDialog(QWidget *parent = nullptr);
    ~ImageDialog();

    bool eventFilter(QObject *target, QEvent *event)override;

private:
    Ui::ImageDialog *ui;

    QByteArray imgArr;

public slots:

    ///
    /// \brief enlargeImages 放大图片
    /// \param arry
    ///
    void slot_enlargeImages(QByteArray arry);

private slots:
    void on_savePushButton_clicked();
};

#endif // IMAGEDIALOG_H
