#include "version_dialog.h"
#include "ui_version_dialog.h"

Version_Dialog::Version_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Version_Dialog)
{
    ui->setupUi(this);

    ui->plainTextEdit->appendPlainText(QString("version:%1---[%2]").arg("1.1.1.12_2105301250_1","修复模拟发送bug"));
    ui->plainTextEdit->appendPlainText(QString("version:%1---[%2]").arg("1.1.1.13_2107121930_1","优化车辆和车牌输出结果关系"));
}

Version_Dialog::~Version_Dialog()
{
    delete ui;
}
