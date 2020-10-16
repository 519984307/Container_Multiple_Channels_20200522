#include "MainWindow/mainwindow.h"
#include "Setting/main_dialog.h"

#include <QApplication>
#include <QPointer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPointer<Main_Dialog> main_Dlg(new Main_Dialog(nullptr));
    if(main_Dlg->exec()!=10){
        return 0;
    }

    MainWindow w;

    /*****************************
    * @brief:根据软件状态显示
    ******************************/
    //w.show();

    return a.exec();
}
