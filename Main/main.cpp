#include <QApplication>
#include <QPointer>

#include "Setting/main_dialog.h"
#include "MainWindow/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //a.setQuitOnLastWindowClosed(false);

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
