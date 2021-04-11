#ifndef DATA_LOG_FORM_H
#define DATA_LOG_FORM_H

#include <QWidget>
#include <QDateTime>
#include <QTableWidgetItem>

namespace Ui {
class Data_Log_Form;
}

class Data_Log_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Data_Log_Form(QWidget *parent = nullptr);
    ~Data_Log_Form();

public slots:
    void slot_newLogText(QtMsgType type,QDateTime time,QString value);

    ///
    /// \brief slot_sendLogToUi 发送的数据写入log页面
    /// \param msg
    ///
    void slot_sendLogToUi(int channel_number, QString msg);

    ///
    /// \brief slot_linkState TCP链接状态
    /// \param address 地址
    /// \param state 状态
    ///
    void slot_linkState(const QString &address,quint16 port,bool state);

    ///
    /// \brief slot_connectCount 链接数量
    /// \param count
    ///
    void slot_connectCount(int count);

private:
    Ui::Data_Log_Form *ui;

    int textCount;
    int ServiceCount;
};

#endif // DATA_LOG_FORM_H
