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
#include "Parameter/parameter.h"
#include "MainWindow/mainwindow.h"

#include "crashstack.h"

int main(int argc, char *argv[])
{
#ifdef Q_OS_WIN
        crashstack dump;
#endif

    QTextCodec *codec = QTextCodec::codecForName("gbk");
    QTextCodec::setCodecForLocale(codec);

    QApplication::addLibraryPath(QDir::toNativeSeparators("./Plugins"));

    QApplication a(argc, argv);

    int language=0;
    QPointer<LoadParameter> Pointer(new LoadParameter(nullptr));
    if(Pointer->loadSysParameter()){
        language=Parameter::Language;
    }

    QTranslator translator;
    translator.load("zh_hans.qm", QDir::toNativeSeparators("./translations"));
    if(1==language){
        a.installTranslator(&translator);
    }


    //连接LocalServer
    QString serverName = "localserver";
    QLocalSocket socket;
    socket.connectToServer(serverName);
    if(socket.waitForConnected(1000)){
        QMessageBox::critical(nullptr,"ZBY","Startup error, the program is already running.");
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

    /*****************************
    * @brief:根据软件状态显示
    ******************************/
    MainWindow w;
    //w.show();

    return a.exec();
}
