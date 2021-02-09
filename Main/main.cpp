#include <QApplication>
#include <QPointer>
#include <QLocalSocket>
#include <QLocalServer>
#include <QTranslator>
#include <QCoreApplication>
#include <QDir>
#include <QTextCodec>
#include <QMessageBox>

#include "Setting/main_dialog.h"
#include "MainWindow/mainwindow.h"

int main(int argc, char *argv[])
{
    QTextCodec *codec = QTextCodec::codecForName("gbk");
    QTextCodec::setCodecForLocale(codec);

    QApplication::addLibraryPath(QDir::toNativeSeparators("./Plugins"));
    QApplication::addLibraryPath(QDir::toNativeSeparators("./translations"));

    QApplication a(argc, argv);

    //连接LocalServer
    QString serverName = "localserver";
    QLocalSocket socket;
    socket.connectToServer(serverName);
    if(socket.waitForConnected(1000)){
        QMessageBox::critical(nullptr,"Container","Startup error, the program is already running.");
        return(-1);
    }

    //创建LocalServer
    QLocalServer server;
    if (server.listen(serverName)){
        if(server.serverError()== QAbstractSocket::AddressInUseError &&
                QFile::exists(server.serverName())){
            QFile::remove(server.serverName());
            server.listen(serverName);
        }
    }

    QPointer<Main_Dialog> main_Dlg(new Main_Dialog(nullptr));
    main_Dlg->setWindowFlag(Qt::WindowStaysOnTopHint);
    if(main_Dlg->exec()!=10){
        return 0;
    }

//    QTranslator translator;
//    translator.load("zh_hans.qm", QDir::toNativeSeparators("./translations"));
//    if(0==main_Dlg.data()->language){
//        //a.installTranslator(&translator);
//    }

    /*****************************
    * @brief:根据软件状态显示
    ******************************/
    MainWindow w;
    //w.show();

    return a.exec();
}
