#include "MainWindow/mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QPointer>

#include "Setting/main_dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //Main_Dialog* main_Dlg=new Main_Dialog (nullptr);
    QPointer<Main_Dialog> main_Dlg(new Main_Dialog(nullptr));
    if(main_Dlg->exec()!=10){
        return 0;
    }

    MainWindow w;
    w.show();

    return a.exec();
}
