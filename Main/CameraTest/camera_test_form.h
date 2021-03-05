#ifndef CAMERA_TEST_FORM_H
#define CAMERA_TEST_FORM_H

#include <QWidget>
#include <QSharedPointer>

namespace Ui {
class Camera_Test_Form;
}

class Camera_Test_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Camera_Test_Form(QWidget *parent = nullptr);
    ~Camera_Test_Form();

private slots:
    void on_capture_pushButton_clicked();

    void on_play_pushButton_clicked();

    void on_identify_pushButton_clicked();

private:
    Ui::Camera_Test_Form *ui;
    QSharedPointer<QPixmap> pixStream;

public slots:

    ///
    /// \brief slot_pictureStream 图片流信号
    /// \param jpgStream 图片流
    /// \param imgNumber 图片编号
    /// \param imgTime 图片时间戳
    ///
    void slot_pictureStream(const QByteArray &jpgStream,const int &imgNumber,const QString &imgTime="");

    ///
    /// \brief slot_videoStream 视频流数据
    /// \param arr
    ///
    void slot_videoStream(const QByteArray &arr);

signals:
    ///
    /// \brief signal_capture 抓取图片
    ///
    void signal_capture();

    ///
    /// \brief signal_play 播放视频
    ///
    void signal_play(quint64 winID);
};

#endif // CAMERA_TEST_FORM_H
