#include <QApplication>
#include <QPointer>

#include "Setting/main_dialog.h"
#include "MainWindow/mainwindow.h"
#include "logcontroller.h"

int main(int argc, char *argv[])
{
    LogController log;
    Q_UNUSED(log);


    QApplication a(argc, argv);

    QPointer<Main_Dialog> main_Dlg(new Main_Dialog(nullptr));
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
