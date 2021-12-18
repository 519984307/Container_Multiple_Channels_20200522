#include "database_form.h"
#include "ui_database_form.h"

#include <QDebug>

DataBase_Form::DataBase_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataBase_Form)
{
    ui->setupUi(this);
\
    this->setParent(parent);
    this->setAttribute(Qt::WA_DeleteOnClose,true);
    //this->setFixedSize(this->size());

    InitializationWindow();
}

DataBase_Form::~DataBase_Form()
{
    imgMap.clear();
    delete ui;
}

void DataBase_Form::InitializationWindow()
{
    /*****************************
     * 默认显示第一页
     ******************************/
    ui->database_stackedWidget->setCurrentIndex(0);

    /*****************************
     * 注册控件事件
     ******************************/
    ui->image_label_1->installEventFilter(this);
    ui->image_label_2->installEventFilter(this);
    ui->image_label_3->installEventFilter(this);
    ui->image_label_4->installEventFilter(this);
    ui->image_label_5->installEventFilter(this);
    ui->image_label_6->installEventFilter(this);
    ui->image_label_7->installEventFilter(this);
    ui->image_label_8->installEventFilter(this);
    ui->image_label_9->installEventFilter(this);
    ui->image_label_10->installEventFilter(this);
    ui->image_label_11->installEventFilter(this);
    ui->image_label_12->installEventFilter(this);


    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    /*****************************
    * @brief:初始化数据库,主页面已初始化。
    ******************************/
    //emit signal_initDataBaseR();
}

void DataBase_Form::showImgaes(const QModelIndex &index)
{
    imgMap.clear();

    if(Parameter::ImagePath.isEmpty()){
        Parameter::ImagePath= QString("C:\\images");
    }
    QDir dir(Parameter::ImagePath);
    QString suffixPath="";
    bool isRoot=false;/* 如果是保存在根目录就不用CD */
    QStringList date=index.sibling(index.row(),Timer).data().toString().split(" ");
    int land=index.sibling(index.row(),Channel).data().toInt();

    if(date.count()==2){
        QStringList tmpList=date[0].split("/");
        switch (Parameter::ImageFormat) {
        case 0:
            suffixPath=QDir::toNativeSeparators(QString("%1/%2").arg(QString::number(land)).arg(tmpList.join("/")));
            break;
        case 1:
            suffixPath=QDir::toNativeSeparators(QString("%1/%2").arg(QString::number(land)).arg(tmpList[0].append("/").append(tmpList[1])));
            break;
        case 2:
            suffixPath=QDir::toNativeSeparators(QString("%1/%2").arg(QString::number(land)).arg(tmpList[0]));
            break;
        case 3:
            suffixPath=QDir::toNativeSeparators(QString("%1").arg(land));
            break;
        case 4:
            suffixPath=QDir::toNativeSeparators(QString("%1").arg(tmpList.join("/")));
            break;
        case 5:
            suffixPath=QDir::toNativeSeparators(QString("%1").arg(tmpList[0].append("/").append(tmpList[1])));
            break;
        case 6:
            suffixPath=QDir::toNativeSeparators(QString("%1").arg(tmpList[0]));
            break;
        case 7:
            isRoot=true;
            break;
        }
    }
    if(!isRoot){
        dir.cd(suffixPath);
    }

    QScopedPointer<QPixmap> labelPix(new QPixmap());
    QPalette palette;

    QString imgTmp=index.sibling(index.row(),ImgFront).data().toString();
    if(imgTmp!=""){
        imgMap.insert(1,QDir::toNativeSeparators(QString("%1/%2").arg(dir.path()).arg(imgTmp)));
        if(labelPix->load(QDir::toNativeSeparators(QString("%1/%2").arg(dir.path()).arg(imgTmp)))){
            palette.setBrush(QPalette::Background, QBrush(labelPix.data()->scaled(ui->image_label_1->size(), Qt::IgnoreAspectRatio)));
            ui->image_label_1->setPalette(palette);
        }
    }
    imgTmp=index.sibling(index.row(),ImgLeftFront).data().toString();
    if(imgTmp!=""){
        imgMap.insert(2,QDir::toNativeSeparators(QString("%1/%2").arg(dir.path()).arg(imgTmp)));
        if(labelPix->load(QDir::toNativeSeparators(QString("%1/%2").arg(dir.path()).arg(imgTmp)))){
            palette.setBrush(QPalette::Background, QBrush(labelPix.data()->scaled(ui->image_label_2->size(), Qt::IgnoreAspectRatio)));
            ui->image_label_2->setPalette(palette);
        }
    }
    imgTmp=index.sibling(index.row(),ImgRightFront).data().toString();
    if(imgTmp!=""){
        imgMap.insert(3,QDir::toNativeSeparators(QString("%1/%2").arg(dir.path()).arg(imgTmp)));
        if(labelPix->load(QDir::toNativeSeparators(QString("%1/%2").arg(dir.path()).arg(imgTmp)))){
            palette.setBrush(QPalette::Background, QBrush(labelPix.data()->scaled(ui->image_label_3->size(), Qt::IgnoreAspectRatio)));
            ui->image_label_3->setPalette(palette);
        }
    }
    imgTmp=index.sibling(index.row(),ImgLeftAfter).data().toString();
    if(imgTmp!=""){
        imgMap.insert(4,QDir::toNativeSeparators(QString("%1/%2").arg(dir.path()).arg(imgTmp)));
        if(labelPix->load(QDir::toNativeSeparators(QString("%1/%2").arg(dir.path()).arg(imgTmp)))){
            palette.setBrush(QPalette::Background, QBrush(labelPix.data()->scaled(ui->image_label_4->size(), Qt::IgnoreAspectRatio)));
            ui->image_label_4->setPalette(palette);
        }
    }
    imgTmp=index.sibling(index.row(),ImgRightAfter).data().toString();
    if(imgTmp!=""){
        imgMap.insert(5,QDir::toNativeSeparators(QString("%1/%2").arg(dir.path()).arg(imgTmp)));
        if(labelPix->load(QDir::toNativeSeparators(QString("%1/%2").arg(dir.path()).arg(imgTmp)))){
            palette.setBrush(QPalette::Background, QBrush(labelPix.data()->scaled(ui->image_label_5->size(), Qt::IgnoreAspectRatio)));
            ui->image_label_5->setPalette(palette);
        }
    }
    imgTmp=index.sibling(index.row(),ImgAfter).data().toString();
    if(imgTmp!=""){
        imgMap.insert(6,QDir::toNativeSeparators(QString("%1/%2").arg(dir.path()).arg(imgTmp)));
        if(labelPix->load(QDir::toNativeSeparators(QString("%1/%2").arg(dir.path()).arg(imgTmp)))){
            palette.setBrush(QPalette::Background, QBrush(labelPix.data()->scaled(ui->image_label_6->size(), Qt::IgnoreAspectRatio)));
            ui->image_label_6->setPalette(palette);
        }
    }
    imgTmp=index.sibling(index.row(),PlateImg).data().toString();
    if(imgTmp!=""){
        imgMap.insert(7,QDir::toNativeSeparators(QString("%1/%2").arg(dir.path()).arg(imgTmp)));
        if(labelPix->load(QDir::toNativeSeparators(QString("%1/%2").arg(dir.path()).arg(imgTmp)))){
            palette.setBrush(QPalette::Background, QBrush(labelPix.data()->scaled(ui->image_label_7->size(), Qt::IgnoreAspectRatio)));
            ui->image_label_7->setPalette(palette);
        }
    }

    /*****************************
    * @brief:202112181747
    ******************************/
    imgTmp=index.sibling(index.row(),ImgProspects).data().toString();
    if(imgTmp!=""){
        imgMap.insert(8,QDir::toNativeSeparators(QString("%1/%2").arg(dir.path()).arg(imgTmp)));
        if(labelPix->load(QDir::toNativeSeparators(QString("%1/%2").arg(dir.path()).arg(imgTmp)))){
            palette.setBrush(QPalette::Background, QBrush(labelPix.data()->scaled(ui->image_label_8->size(), Qt::IgnoreAspectRatio)));
            ui->image_label_8->setPalette(palette);
        }
    }
    imgTmp=index.sibling(index.row(),ImgForeground).data().toString();
    if(imgTmp!=""){
        imgMap.insert(9,QDir::toNativeSeparators(QString("%1/%2").arg(dir.path()).arg(imgTmp)));
        if(labelPix->load(QDir::toNativeSeparators(QString("%1/%2").arg(dir.path()).arg(imgTmp)))){
            palette.setBrush(QPalette::Background, QBrush(labelPix.data()->scaled(ui->image_label_9->size(), Qt::IgnoreAspectRatio)));
            ui->image_label_9->setPalette(palette);
        }
    }
}

void DataBase_Form::slot_filterData(QString data)
{
    emit signal_setDataBaseFilter(data);
}

bool DataBase_Form::eventFilter(QObject *target, QEvent *event)
{
    int key=0;
    if(target==ui->image_label_1){
        key=1;
    }
    else if (target==ui->image_label_2) {
        key=2;
    }
    else if (target==ui->image_label_3) {
        key=3;
    }
    else if (target==ui->image_label_4) {
        key=4;
    }
    else if (target==ui->image_label_5) {
        key=5;
    }
    else if (target==ui->image_label_6) {
        key=6;
    }
    else if (target==ui->image_label_7) {
        key=7;
    }
    else if (target==ui->image_label_8) {
        key=8;
    }
    else if (target==ui->image_label_9) {
        key=9;
    }
    else if (target==ui->image_label_10) {
        key=10;
    }
    else if (target==ui->image_label_11) {
        key=11;
    }
    else if (target==ui->image_label_12) {
        /*****************************
        * @brief:处理其他信息
        ******************************/
    }
    if(event->type()==QEvent::MouseButtonDblClick){
        if(nullptr != imgMap.value(key,nullptr)){
            QPointer<Image_Dialog> Dlg=new Image_Dialog(this);
            connect(this,SIGNAL(set_image_dialog_pixmap_signal(QString)),Dlg,SLOT(set_image_dialog_pixmap_slot(QString)));
            emit set_image_dialog_pixmap_signal(imgMap.value(key,nullptr));
            Dlg->exec();
        }
    }
    if(event->type()==QEvent::Resize){
        showImgaes(ui->tableView->currentIndex());
    }
    return  QWidget::eventFilter(target,event);
}

void DataBase_Form::closeEvent(QCloseEvent *event)
{
    if(1==ui->database_stackedWidget->currentIndex()){
        QMessageBox::StandardButton bt = QMessageBox::warning(this,"Exit","Confirm closing window: please click OK.\n Back to list of data: please click Cancel",QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
        if(QMessageBox::Yes==bt){
            this->close();
            event->accept();
            QWidget::closeEvent(event);
        }
        if(QMessageBox::No==bt){
            ui->database_stackedWidget->setCurrentIndex(0);
            event->ignore();
        }
    }
}

void DataBase_Form::on_database_imageOrData_pushButton_clicked()
{
    switch (ui->database_stackedWidget->currentIndex()) {
    case 0:ui->database_stackedWidget->setCurrentIndex(1);
        break;
    case 1:ui->database_stackedWidget->setCurrentIndex(0);
        break;
    }
}

void DataBase_Form::on_database_stackedWidget_currentChanged(int arg1)
{
    switch (arg1) {
    case 0:ui->database_imageOrData_pushButton->setText(tr("Image"));
        break;
    case 1:ui->database_imageOrData_pushButton->setText(tr("Data"));
        break;
    }
}

void DataBase_Form::slot_returnModel(QSqlTableModel *ml)
{
    ui->database_stackedWidget->setCurrentIndex(0);

    ui->tableView->setModel(ml);
    ui->tableView->setColumnHidden(ID,true);
    ui->tableView->setColumnHidden(ImgFront,true);
    ui->tableView->setColumnHidden(ImgFrontCheck,true);
    ui->tableView->setColumnHidden(ImgFrontNumber,true);
    ui->tableView->setColumnHidden(ImgLeftFront,true);
    ui->tableView->setColumnHidden(ImgLeftFrontCheck,true);
    ui->tableView->setColumnHidden(ImgLeftFrontNumber,true);
    ui->tableView->setColumnHidden(ImgRightFront,true);
    ui->tableView->setColumnHidden(ImgRightFrontCheck,true);
    ui->tableView->setColumnHidden(ImgRightFrontNumber,true);
    ui->tableView->setColumnHidden(ImgLeftAfter,true);
    ui->tableView->setColumnHidden(ImgLeftAfterCheck,true);
    ui->tableView->setColumnHidden(ImgLeftAfterNumber,true);
    ui->tableView->setColumnHidden(ImgRightAfter,true);
    ui->tableView->setColumnHidden(ImgRightAfterCheck,true);
    ui->tableView->setColumnHidden(ImgRightAfterNumber,true);
    ui->tableView->setColumnHidden(ImgAfter,true);
    ui->tableView->setColumnHidden(ImgAfterCheck,true);
    ui->tableView->setColumnHidden(ImgAfterNumber,true);
    ui->tableView->setColumnHidden(PlateImg,true);    
    ui->tableView->setColumnHidden(ImgFrontISO,true);
    ui->tableView->setColumnHidden(ImgLeftFrontISO,true);
    ui->tableView->setColumnHidden(ImgRightFrontISO,true);
    ui->tableView->setColumnHidden(ImgLeftAfterISO,true);
    ui->tableView->setColumnHidden(ImgRightAfterISO,true);
    ui->tableView->setColumnHidden(ImgAfterISO,true);
    ui->tableView->setColumnHidden(ImgProspects,true);
    ui->tableView->setColumnHidden(ImgProspectsCheck,true);
    ui->tableView->setColumnHidden(ImgProspectsNumber,true);
    ui->tableView->setColumnHidden(ImgForeground,true);
    ui->tableView->setColumnHidden(ImgForegroundCheck,true);
    ui->tableView->setColumnHidden(ImgForegroundNumber,true);
    ui->tableView->setColumnHidden(ImgTop1,true);
    ui->tableView->setColumnHidden(ImgFrontISO,true);
    ui->tableView->setColumnHidden(ImgTop2,true);
    ui->tableView->setColumnHidden(PlateColor,true);
}

void DataBase_Form::slot_statisticalData(int total, double correct, double error, double statistical)
{
    ui->label_13->setText(QString::number(total));
    ui->label_14->setText(QString::number(correct));
    ui->label_15->setText(QString::number(error));
    ui->label_16->setText(QString::number(statistical));
}

void DataBase_Form::on_pushButton_5_clicked()
{
    QPointer<FilterDialog> filter(new FilterDialog(this));
    connect(filter,&FilterDialog::signal_filterData,this,&DataBase_Form::slot_filterData);
    filter->exec();
}

void DataBase_Form::on_tableView_doubleClicked(const QModelIndex &index)
{
    QPalette palette;
    ui->image_label_1->setPalette(palette);
    ui->image_label_2->setPalette(palette);
    ui->image_label_3->setPalette(palette);
    ui->image_label_4->setPalette(palette);
    ui->image_label_5->setPalette(palette);
    ui->image_label_6->setPalette(palette);
    ui->image_label_7->setPalette(palette);
    ui->image_label_8->setPalette(palette);
    ui->image_label_9->setPalette(palette);
    ui->image_label_10->setPalette(palette);
    ui->image_label_11->setPalette(palette);
    ui->image_label_12->setPalette(palette);

    ui->database_stackedWidget->setCurrentIndex(1);
    on_tableView_clicked(index);
    showImgaes(index);
}

void DataBase_Form::on_pushButton_8_clicked()
{
    ui->tableView->selectRow(0);
    on_tableView_doubleClicked(ui->tableView->currentIndex());
}

void DataBase_Form::on_pushButton_9_clicked()
{
    ui->tableView->selectRow(ui->tableView->currentIndex().row()-1);
    on_tableView_doubleClicked(ui->tableView->currentIndex());
}

void DataBase_Form::on_pushButton_10_clicked()
{
    ui->tableView->selectRow(ui->tableView->currentIndex().row()+1);
    on_tableView_doubleClicked(ui->tableView->currentIndex());
}

void DataBase_Form::on_pushButton_11_clicked()
{
    if(ui->tableView->model()!=nullptr){
        ui->tableView->selectRow(ui->tableView->model()->rowCount()-1);
        on_tableView_doubleClicked(ui->tableView->currentIndex());
    }
}

void DataBase_Form::on_pushButton_7_clicked()
{

    QString filepath = QFileDialog::getSaveFileName(this, QString("Save as..."),
                                                  QString(), QString("EXCEL files (*.xls);;HTML-Files (*.txt);;"));

    if (filepath != "")
    {
        int row = ui->tableView->model()->rowCount();
        int col = ui->tableView->model()->columnCount();
        QList<QString> list;
        //添加列标题
        QString HeaderRow;
        for (int i = 0; i < col; i++)
        {
            HeaderRow.append(ui->tableView->model()->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\t");
        }
        list.push_back(HeaderRow);
        for (int i = 0; i < row; i++)
        {
            QString rowStr = "";
            for (int j = 0; j < col; j++){
                QModelIndex index = ui->tableView->model()->index(i, j);
                rowStr += ui->tableView->model()->data(index).toString() + "\t";
            }
            list.push_back(rowStr);
        }
        QTextEdit textEdit;
        for (int i = 0; i < list.size(); i++)
        {
            textEdit.append(list.at(i));
        }

        QFile file(filepath);
        if (file.open(QFile::WriteOnly | QIODevice::Text))
        {
            QTextStream ts(&file);
            ts.setCodec("GB2312");/* 这个地方大家自己判断是否用“utf-8” */
            ts << textEdit.document()->toPlainText();
            file.close();
            QMessageBox::information(this,"excel data","Data export successful");
        }else{
            QMessageBox::warning(this,"excel data","Data export failed");
        }
    }
}

void DataBase_Form::on_tableView_clicked(const QModelIndex &index)
{
    ui->result_lineEdit_front->setText(index.sibling(index.row(),ContainerFront).data().toString());/* 前箱 */
    ui->result_lineEdit_before->setText(index.sibling(index.row(),ContainerAfter).data().toString());/* 后箱 */
    ui->iso_lineEdit_front->setText(index.sibling(index.row(),ISOFront).data().toString());/* 前箱型 */
    ui->iso_lineEdit_before->setText(index.sibling(index.row(),ISOAfter).data().toString());/* 后箱型 */

    if("黄"==index.sibling(index.row(),PlateColor).data().toString()){
        ui->plate_lineEdit_front->setStyleSheet("background-color: rgb(255, 255, 0);color: rgb(0, 0, 0);");
    }
    if("蓝"==index.sibling(index.row(),PlateColor).data().toString()){
        ui->plate_lineEdit_front->setStyleSheet("background-color: rgb(0, 0, 255);color: rgb(255, 255, 255);");
    }
    if("无车牌"==index.sibling(index.row(),Plate).data().toString()){
        ui->plate_lineEdit_front->setStyleSheet("background-color: rgb(235, 235, 235);color: rgb(255, 0, 0);");
    }
    ui->plate_lineEdit_front->setText(index.sibling(index.row(),Plate).data().toString());/* 车牌 */

    ui->result_lineEdit_1->setText(index.sibling(index.row(),ImgFrontNumber).data().toString()+" | "+index.sibling(index.row(),ImgFrontISO).data().toString());
    if(index.sibling(index.row(),ImgFrontCheck).data().toBool()){
        ui->result_lineEdit_1->setStyleSheet("background-color: rgb(0, 170, 0);color: rgb(255, 255, 255);");
    }
    else {
        ui->result_lineEdit_1->setStyleSheet("background-color: rgb(255, 0, 0);color: rgb(255, 255, 255);");
    }

    ui->result_lineEdit_2->setText(index.sibling(index.row(),ImgLeftFrontNumber).data().toString()+" | "+index.sibling(index.row(),ImgLeftFrontISO).data().toString());
    if(index.sibling(index.row(),ImgLeftFrontCheck).data().toBool()){
        ui->result_lineEdit_2->setStyleSheet("background-color: rgb(0, 170, 0);color: rgb(255, 255, 255);");
    }
    else {
        ui->result_lineEdit_2->setStyleSheet("background-color: rgb(255, 0, 0);color: rgb(255, 255, 255);");
    }

    ui->result_lineEdit_3->setText(index.sibling(index.row(),ImgRightFrontNumber).data().toString()+" | "+index.sibling(index.row(),ImgRightFrontISO).data().toString());
    if(index.sibling(index.row(),ImgRightFrontCheck).data().toBool()){
        ui->result_lineEdit_3->setStyleSheet("background-color: rgb(0, 170, 0);color: rgb(255, 255, 255);");
    }
    else {
        ui->result_lineEdit_3->setStyleSheet("background-color: rgb(255, 0, 0);color: rgb(255, 255, 255);");
    }

    ui->result_lineEdit_4->setText(index.sibling(index.row(),ImgLeftAfterNumber).data().toString()+" | "+index.sibling(index.row(),ImgLeftAfterISO).data().toString());
    if(index.sibling(index.row(),ImgLeftAfterCheck).data().toBool()){
        ui->result_lineEdit_4->setStyleSheet("background-color: rgb(0, 170, 0);color: rgb(255, 255, 255);");
    }
    else {
        ui->result_lineEdit_4->setStyleSheet("background-color: rgb(255, 0, 0);color: rgb(255, 255, 255);");
    }

    ui->result_lineEdit_5->setText(index.sibling(index.row(),ImgRightAfterNumber).data().toString()+" | "+index.sibling(index.row(),ImgRightAfterISO).data().toString());
    if(index.sibling(index.row(),ImgRightAfterCheck).data().toBool()){
        ui->result_lineEdit_5->setStyleSheet("background-color: rgb(0, 170, 0);color: rgb(255, 255, 255);");
    }
    else {
        ui->result_lineEdit_5->setStyleSheet("background-color: rgb(255, 0, 0);color: rgb(255, 255, 255);");
    }

    ui->result_lineEdit_6->setText(index.sibling(index.row(),ImgAfterNumber).data().toString()+" | "+index.sibling(index.row(),ImgAfterISO).data().toString());
    if(index.sibling(index.row(),ImgAfterCheck).data().toBool()){
        ui->result_lineEdit_6->setStyleSheet("background-color: rgb(0, 170, 0);color: rgb(255, 255, 255);");
    }
    else {
        ui->result_lineEdit_6->setStyleSheet("background-color: rgb(255, 0, 0);color: rgb(255, 255, 255);");
    }

    /*****************************
    * @brief:20211218
    ******************************/
    ui->result_lineEdit_8->setText(index.sibling(index.row(),ImgProspectsNumber).data().toString()+" | "+index.sibling(index.row(),ImgProspectsISO).data().toString());
    if(index.sibling(index.row(),ImgProspectsCheck).data().toBool()){
        ui->result_lineEdit_8->setStyleSheet("background-color: rgb(0, 170, 0);color: rgb(255, 255, 255);");
    }
    else {
        ui->result_lineEdit_8->setStyleSheet("background-color: rgb(255, 0, 0);color: rgb(255, 255, 255);");
    }
    ui->result_lineEdit_9->setText(index.sibling(index.row(),ImgForegroundNumber).data().toString()+" | "+index.sibling(index.row(),ImgForegroundISO).data().toString());
    if(index.sibling(index.row(),ImgForegroundCheck).data().toBool()){
        ui->result_lineEdit_9->setStyleSheet("background-color: rgb(0, 170, 0);color: rgb(255, 255, 255);");
    }
    else {
        ui->result_lineEdit_9->setStyleSheet("background-color: rgb(255, 0, 0);color: rgb(255, 255, 255);");
    }


    /* Tupe,集装箱类别:
     * -1 – 未知
     * 0 – 一个 20 集装箱
     * 1 – 一个 40 吋/45 吋集装箱
     * 2 – 两个 20 吋集装箱
     */
    int type=index.sibling(index.row(),Type).data().toInt();
    if(type>=0){
        if(type==2){
            if(index.sibling(index.row(),CheckFront).data().toBool()){
                ui->result_lineEdit_front->setStyleSheet("background-color: rgb(0, 170, 0);color: rgb(255, 255, 255);");
            }
            else {
                ui->result_lineEdit_front->setStyleSheet("background-color: rgb(255, 0, 0);color: rgb(255, 255, 255);");
            }
            if(index.sibling(index.row(),CheckAfter).data().toBool()){
                ui->result_lineEdit_before->setStyleSheet("background-color: rgb(0, 170, 0);color: rgb(255, 255, 255);");
            }
            else {
                ui->result_lineEdit_before->setStyleSheet("background-color: rgb(255, 0, 0);color: rgb(255, 255, 255);");
            }
            ui->type_lineEdit->setText(tr("Two boxes"));
        }
        else if (type<2) {
            if(index.sibling(index.row(),CheckFront).data().toBool()){
                ui->result_lineEdit_front->setStyleSheet("background-color: rgb(0, 170, 0);color: rgb(255, 255, 255);");
            }
            else {
                ui->result_lineEdit_front->setStyleSheet("background-color: rgb(255, 0, 0);color: rgb(255, 255, 255);");
            }
            ui->result_lineEdit_before->setStyleSheet("background-color: rgb(255, 255, 255);color: rgb(0, 0, 0);");
            ui->type_lineEdit->setText(tr("A long box"));
            if(type==0){
//                ui->result_lineEdit_4->setStyleSheet("background-color: rgb(255, 255, 255);color: rgb(0, 0, 0);");
//                ui->result_lineEdit_5->setStyleSheet("background-color: rgb(255, 255, 255);color: rgb(0, 0, 0);");
                ui->type_lineEdit->setText(tr("A small box"));
            }
        }
    }
    else {
        ui->result_lineEdit_front->setStyleSheet("background-color: rgb(255, 255, 255);color: rgb(0, 0, 0);");
        ui->result_lineEdit_before->setStyleSheet("background-color: rgb(255, 255, 255);color: rgb(0, 0, 0);");
        ui->type_lineEdit->setText(tr("Unknown box"));
    }
}
