#ifndef CHANNEL_DATA_FORM_H
#define CHANNEL_DATA_FORM_H

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QResizeEvent>

namespace Ui {
class Channel_Data_Form;
}

class Channel_Data_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Channel_Data_Form(QString alias,int channelNumber,QWidget *parent = nullptr);
    ~Channel_Data_Form();

    void paintEvent(QPaintEvent *event)override;
    bool eventFilter(QObject *target,QEvent *event) override;

private slots:

    void on_SimulationPushButton_clicked();


private:
    Ui::Channel_Data_Form *ui;    

signals:

    ///
    /// \brief signal_enlargeImages 放大图片
    /// \param arry
    ///
    void signal_enlargeImages(QByteArray arry);
};

#endif // CHANNEL_DATA_FORM_H
