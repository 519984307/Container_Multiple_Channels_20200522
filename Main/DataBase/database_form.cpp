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
    this->setFixedSize(this->size());

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
            suffixPath=QDir::toNativeSeparators(tr("%1/%2").arg(QString::number(land)).arg(tmpList.join("/")));
            break;
        case 1:
            suffixPath=QDir::toNativeSeparators(tr("%1/%2").arg(QString::number(land)).arg(tmpList[0].append("/").append(tmpList[1])));
            break;
        case 2:
            suffixPath=QDir::toNativeSeparators(tr("%1/%2").arg(QString::number(land)).arg(tmpList[0]));
            break;
        case 3:
            suffixPath=QDir::toNativeSeparators(tr("%1").arg(land));
            break;
        case 4:
            suffixPath=QDir::toNativeSeparators(tr("%1").arg(tmpList.join("/")));
            break;
        case 5:
            suffixPath=QDir::toNativeSeparators(tr("%1").arg(tmpList[0].append("/").append(tmpList[1])));
            break;
        case 6:
            suffixPath=QDir::toNativeSeparators(tr("%1").arg(tmpList[0]));
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
        imgMap.insert(1,QDir::toNativeSeparators(tr("%1/%2").arg(dir.path()).arg(imgTmp)));
        if(labelPix->load(QDir::toNativeSeparators(tr("%1/%2").arg(dir.path()).arg(imgTmp)))){
            palette.setBrush(QPalette::Background, QBrush(labelPix.data()->scaled(ui->image_label_1->size(), Qt::IgnoreAspectRatio)));
            ui->image_label_1->setPalette(palette);
        }
    }
    imgTmp=index.sibling(index.row(),ImgLeftFront).data().toString();
    if(imgTmp!=""){
        imgMap.insert(2,QDir::toNativeSeparators(tr("%1/%2").arg(dir.path()).arg(imgTmp)));
        if(labelPix->load(QDir::toNativeSeparators(tr("%1/%2").arg(dir.path()).arg(imgTmp)))){
            palette.setBrush(QPalette::Background, QBrush(labelPix.data()->scaled(ui->image_label_2->size(), Qt::IgnoreAspectRatio)));
            ui->image_label_2->setPalette(palette);
        }
    }
    imgTmp=index.sibling(index.row(),ImgRightFront).data().toString();
    if(imgTmp!=""){
        imgMap.insert(3,QDir::toNativeSeparators(tr("%1/%2").arg(dir.path()).arg(imgTmp)));
        if(labelPix->load(QDir::toNativeSeparators(tr("%1/%2").arg(dir.path()).arg(imgTmp)))){
            palette.setBrush(QPalette::Background, QBrush(labelPix.data()->scaled(ui->image_label_3->size(), Qt::IgnoreAspectRatio)));
            ui->image_label_3->setPalette(palette);
        }
    }
    imgTmp=index.sibling(index.row(),ImgLeftAfter).data().toString();
    if(imgTmp!=""){
        imgMap.insert(4,QDir::toNativeSeparators(tr("%1/%2").arg(dir.path()).arg(imgTmp)));
        if(labelPix->load(QDir::toNativeSeparators(tr("%1/%2").arg(dir.path()).arg(imgTmp)))){
            palette.setBrush(QPalette::Background, QBrush(labelPix.data()->scaled(ui->image_label_4->size(), Qt::IgnoreAspectRatio)));
            ui->image_label_4->setPalette(palette);
        }
    }
    imgTmp=index.sibling(index.row(),ImgRightAfter).data().toString();
    if(imgTmp!=""){
        imgMap.insert(5,QDir::toNativeSeparators(tr("%1/%2").arg(dir.path()).arg(imgTmp)));
        if(labelPix->load(QDir::toNativeSeparators(tr("%1/%2").arg(dir.path()).arg(imgTmp)))){
            palette.setBrush(QPalette::Background, QBrush(labelPix.data()->scaled(ui->image_label_5->size(), Qt::IgnoreAspectRatio)));
            ui->image_label_5->setPalette(palette);
        }
    }
    imgTmp=index.sibling(index.row(),ImgAfter).data().toString();
    if(imgTmp!=""){
        imgMap.insert(6,QDir::toNativeSeparators(tr("%1/%2").arg(dir.path()).arg(imgTmp)));
        if(labelPix->load(QDir::toNativeSeparators(tr("%1/%2").arg(dir.path()).arg(imgTmp)))){
            palette.setBrush(QPalette::Background, QBrush(labelPix.data()->scaled(ui->image_label_6->size(), Qt::IgnoreAspectRatio)));
            ui->image_label_6->setPalette(palette);
        }
    }
    imgTmp=index.sibling(index.row(),PlateImg).data().toString();
    if(imgTmp!=""){
        imgMap.insert(7,QDir::toNativeSeparators(tr("%1/%2").arg(dir.path()).arg(imgTmp)));
        if(labelPix->load(QDir::toNativeSeparators(tr("%1/%2").arg(dir.path()).arg(imgTmp)))){
            palette.setBrush(QPalette::Background, QBrush(labelPix.data()->scaled(ui->image_label_7->size(), Qt::IgnoreAspectRatio)));
            ui->image_label_7->setPalette(palette);
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

    QString filepath = QFileDialog::getSaveFileName(this, tr("Save as..."),
                                                  QString(), tr("EXCEL files (*.xls);;HTML-Files (*.txt);;"));

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
            ts.setCodec("GB2312");//这个地方大家自己判断是否用“utf-8”
            ts << textEdit.document()->toPlainText();
            file.close();
            QMessageBox::information(this,"excel data","Data export successful");
        }else{
            QMessageBox::warning(this,"excel data","Data export failed");
        }
    }

}
