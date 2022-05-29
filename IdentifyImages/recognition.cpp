#include "recognition.h"
#include "identifyimages_global.h"

Recognition::Recognition(QObject *parent, const QString &imgName, const int &imgNumber) : QObject(parent)
{
    this->setAutoDelete(true);
    this->setParent(parent);    
    this->imgName=QDir::fromNativeSeparators(imgName).trimmed();
    this->imgNumber=imgNumber;
}

void Recognition::run()
{
    QProcess Process;
    QString program="QRecognition.exe";
    QString path=QDir::toNativeSeparators(QString("%1/%2/").arg(QCoreApplication::applicationDirPath()).arg(program.split(".")[0]));
    Process.setWorkingDirectory(path);
    Process.start(path.append(program),QStringList()<<imgName<<"QRecog.dll");
    if(!Process.waitForStarted(3000)){
        emit recognitionResultSignal("RESULT: ||0|0",imgName,imgNumber);
        qDebug().noquote()<<QString("Recognizer startup error<errorCode=%1>").arg(Process.errorString().toLocal8Bit().data());
    }
    else {
        /* 停止写入 */
        Process.closeWriteChannel();
        /* 等待识别结果 */
        if(Process.waitForFinished()){
            QByteArray result= Process.readAll();
            if(0 == result.size()){
                emit recognitionResultSignal("RESULT: ||0|0",imgName,imgNumber);
            }
            else {
                emit recognitionResultSignal(result.data(),imgName,imgNumber);
            }
            qDebug().noquote()<<QString("Identify the results<%1:%2>").arg(imgName,result.data());
        }
        else {
            emit recognitionResultSignal("RESULT: ||0|0",imgName,imgNumber);
            qWarning().noquote()<<QString("Identify the mistakes error<errorCode=%1>").arg(Process.errorString().toLocal8Bit().data());
        }
    }
}
