#ifndef CHANNEL_DATA_FORM_H
#define CHANNEL_DATA_FORM_H

#include <QWidget>
#include <QResizeEvent>
#include <QPaintEvent>

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

private slots:
    void on_plateCheckBox_stateChanged(int arg1);

    void on_topCheckBox_stateChanged(int arg1);

    void on_prospectsCheckBox_stateChanged(int arg1);

    void on_foregroundCheckBox_stateChanged(int arg1);

private:
    Ui::Channel_Data_Form *ui;    

    bool plateC;
    bool topC;
    bool prospectsC;
    bool foregroundC;
};

#endif // CHANNEL_DATA_FORM_H
