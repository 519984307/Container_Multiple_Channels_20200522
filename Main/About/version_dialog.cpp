#include "version_dialog.h"
#include "ui_version_dialog.h"

Version_Dialog::Version_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Version_Dialog)
{
    ui->setupUi(this);

    ui->plainTextEdit->appendPlainText(QString("version:%1---[%2]").arg("1.1.1.12_2105301250","修复模拟发送bug"));
    ui->plainTextEdit->appendPlainText(QString("version:%1---[%2]").arg("1.1.1.13_2107121930","优化车辆和车牌输出结果关系"));
    ui->plainTextEdit->appendPlainText(QString("version:%1---[%2]").arg("1.1.1.14_2107200930","添加ZS车牌相机支持"));
    ui->plainTextEdit->appendPlainText(QString("version:%1---[%2]").arg("1.1.7.4_2108310114","添加隐式调用海康SDK"));
    ui->plainTextEdit->appendPlainText(QString("version:%1---[%2]").arg("1.1.7.5_2109011034","修复抓拍逻辑"));
    ui->plainTextEdit->appendPlainText(QString("version:%1---[%2]").arg("1.1.7.6_2110111959","修复红外逻辑配置"));
    ui->plainTextEdit->appendPlainText(QString("version:%1---[%2]").arg("1.1.7.7_2110120924","修复车牌和箱号逻辑问题"));
    ui->plainTextEdit->appendPlainText(QString("version:%1---[%2]").arg("1.1.7.9_2110151350","修复车牌写入数据库空白"));
}

Version_Dialog::~Version_Dialog()
{
    delete ui;
}
