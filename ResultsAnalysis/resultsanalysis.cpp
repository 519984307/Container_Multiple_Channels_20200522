﻿#include "resultsanalysis.h"

ResultsAnalysis::ResultsAnalysis(QObject *parent)
{
    this->setParent(parent);
}

ResultsAnalysis::~ResultsAnalysis()
{
    ISOContains.clear();
    ISOReplaceMap.clear();
    checkMap.clear();
}

QString ResultsAnalysis::InterfaceType()
{
    return  QString("ResultsAnalysis");
}

void ResultsAnalysis::initParameter(const int &channel,const int &ImageNamingRules , bool check, bool sendMid,int correctTheox)
{
    /*****************************
    * @brief:暂时未处理
    ******************************/
    this->correctTheox=correctTheox;
    this->ImageNamingRules=ImageNamingRules;
    this->correct=check;
    this->channel=channel;
    this->sendMid=sendMid;

    QDateTime dateTime = QDateTime::currentDateTime();
    QString stringDateTime = dateTime.toString( "yyyy_MM_dd_hh_mm_ss" );
    QString path = QStandardPaths::writableLocation( QStandardPaths::AppConfigLocation );

    QString logFolderName =QDir::toNativeSeparators(path + "/" + "identify_log"+"/"+QString::number(channel));
    if( !QDir( logFolderName ).exists() )
    {
        QDir().mkpath( logFolderName );
    }

    logFile.setFileName( QDir::toNativeSeparators(logFolderName+ "/" + stringDateTime + ".log" ));

    // If more 30 files, remove the last.
    QDir dir( logFolderName );
    dir.setFilter( QDir::Files );
    dir.setSorting( QDir::Name );
    QList<QFileInfo> list = dir.entryInfoList();
    if ( list.count() > 30 )
    {
        QFile file( list.at(0).absoluteFilePath() );
        file.remove();
    }

    /*****************************
    * @brief:识别结果写入日志
    ******************************/
    connect(this,&ResultsAnalysis::resultsAnalysisStateSignal,this,&ResultsAnalysis::resultsAnalysisStateslot);

    QFile file(QCoreApplication::applicationDirPath()+"/ISO.txt");
    if(file.open( QIODevice::ReadOnly ) )
    {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString iso=in.readLine().trimmed();
            if(!iso.isEmpty()){
                ISOContains.append(iso);
            }
        }
    }
    file.close();

    initCheckMap();
}

void ResultsAnalysis::initCheckMap()
{
    char ch = 'A';
    for (int i = 10; i <= 38; i++)
    {
        if ((i == 11) || (i == 22) || (i == 33))
        {
            i++;
        }
        checkMap.insert(ch,i);
        ch++;
    }
}

int ResultsAnalysis::computeQuadraticPower(int variable)
{
    int result;
    if (variable == 0)
    {
        return 1;
    }
    result = 2 * computeQuadraticPower(variable - 1);
    return result;
}

bool ResultsAnalysis::numberCheck(QString number)
{
    correctNUmber=number;

    if(number.length()<10)/* 最后一位可以计算出来 */
    {
        return false;
    }

    /*****************************
    * @brief:计算前4位为英文，后面位阿拉伯数字
    * 202202221941
    ******************************/
    if(number.size()>=10){
        for(int i=0;i<4;i++){
            if(number.at(i)<'A'){
                return false;
            }
        }
        for(int i=4;i<number.size();i++){
            if(number.at(i)>'9'){
                return false;
            }
        }
    }

    int sum=0;
    int i = 1;
    foreach (QChar ch , number)
    {/* 计算校验总值 */
        if (i == 11)
        {
            break;
        }
        if (i > 4)
        {
            sum += (ch.toLatin1()-'0') * (computeQuadraticPower(i-1));
        }
        else
        {
            if (checkMap.value(ch)!=0)
            {
                sum += checkMap.value(ch) * computeQuadraticPower(i - 1);
            }
            else
            {/* 箱号前4位必须是英文,否则箱号格式错误 */
                return false;
            }
        }
        i++;
    }

    int die=sum % 11;
    if(die==10){
        die=0;
    }
    //qDebug()<<"die"<<die;

    if(number.count()==10){
        if(correct){
            number=number.append(QString::number(die));
            correctNUmber=number;
            return true;
        }
        return false;
    }
    if (number.count()==11 && die!=number[10].toLatin1()-'0')
    {
        if(0<=die && die <=9 && correct)
        {
            number[10]=die+'0';/* 矫正结果 */
            correctNUmber=number;
            return true;
        }
        return false;
    }
    return true;
}

QStringList ResultsAnalysis::queueContainerNumber(QStringList list)
{
    QStringList resultList;
    QMap<int,int> conCountMap;/* 下标和出现次数 */
    QSet<QString> set=list.toSet();/* 去掉重复项 */
    set.remove("");
    QList<QString> tmpList=set.toList();
    if(tmpList.count()==0){
        return resultList;
    }

    if(tmpList.count()>=1){
        for(int i=0;i<tmpList.count();i++){
            int j=0;
            foreach (auto var, list) {
                if(var==tmpList[i]){
                    j+=1;
                    conCountMap.insert(i,j);
                }
            }
        }
    }

    QList<int> tmp=conCountMap.values();
    std::sort(tmp.begin(), tmp.end());


    if(!tmp.isEmpty() && tmp.last()>1){
        QList<int> indList= conCountMap.keys(tmp.last());
        foreach (auto var, indList) {
            resultList.append(tmpList.value(var));
        }
    }

    tmp.clear();
    tmpList.clear();
    set.clear();
    conCountMap.clear();

    return  resultList;
}

void ResultsAnalysis::resultsOfAnalysisSlot(QMap<int,QString> resultMap, int type,QMap<int,QString> imgNameMap)
{   
    /* 外发协议,集装箱类别:
     * -1 – 未知
     * 0 – 一个 20 集装箱
     * 1 – 一个 40 吋/45 吋集装箱
     * 2 – 两个 20 吋集装箱
     */

    int conType=type;  /* 逻辑类型 */

    for(auto ind:resultMap.keys()){
        if(resultMap.value(ind).startsWith("RESULT")){
            QStringList tmp=resultMap.value(ind).split(":")[1].split("|");
            if(tmp.count()==4){
                //qDebug()<<ind<<":"<<resultMap.value(ind);

                /*****************************
                 * 20220220
                * @brief:第8张图为前箱图片，第9张为后箱图片，默认追加
                ******************************/
                if(ind==8 && resultMap.keys().size()==8){

                    bool check= numberCheck(tmp[0].trimmed());
                    conTemp.insert(3,correctNUmber);/* 箱号 */
                    if(correctNUmber!=tmp[0].trimmed()){
                        checkConList.insert(3,1);/* 校验结果 */
                    }
                    else {
                        checkConList.insert(3,check);/* 校验结果 */
                    }

                    isoTemp.insert(3,tmp[1]);/* 箱型 */                    
                    conProbabilityTemp.insert(3,tmp[2].toUInt());/* 箱号置信度 */
                    isoProbabilityTemp.insert(3,tmp[3].toUInt()/*-1!=ISOContains.indexOf(tmp[1])?tmp[3].toUInt():0*/);/* 箱型置信度 */
                }
                else {

                    bool check= numberCheck(tmp[0].trimmed());
                    conTemp.append(correctNUmber);/* 箱号 */
                    if(correctNUmber!=tmp[0].trimmed()){
                        checkConList.append(1);/* 校验结果 */
                    }
                    else {
                        checkConList.append(check);/* 校验结果 */
                    }

                    isoTemp.append(tmp[1]);/* 箱型 */
                    conProbabilityTemp.append(tmp[2].toUInt());/* 箱号置信度 */
                    isoProbabilityTemp.append(tmp[3].toUInt()/*-1!=ISOContains.indexOf(tmp[1])?tmp[3].toUInt():0*/);/* 箱型置信度 */
                }
                //qDebug()<<correctNUmber;
                correctNUmber.clear();
            }
        }
    }

    //qDebug()<<"conTemp.length():"<<conTemp.length();
    /* 没有识别到箱型代码就默认指定一个 */
    bool notISO=true;
    foreach (auto var, isoTemp) {
        if(!var.isEmpty() /*&& -1!=ISOContains.indexOf(var)*/){
            notISO=false;
            break;
        }
    }

    /* 防止双箱,未检测到箱型。默认为长箱，南京三宝小箱为6张图，后续系统判断修改 */
    if(isoTemp.count()==8){
        foreach (auto iso, isoTemp) {
            if(iso.startsWith("2")){
                conType=2;
                break;
            }
        }
    }

    if(notISO){
        switch (conType) {
        case 0:
            isoTemp[0]="22G1";
            break;
        case 1:
            isoTemp[0]="45G1";
            break;
        case 2:
            isoTemp[0]="22G1";
            isoTemp[4]="22G1";
            break;
        }
    }


    /* 双箱，分前3个结果和后3个结果独立处理,前箱下标,前箱型下标,后箱下标,后箱型下标,箱号置信度下表,箱型置信度下标 */
    int Cindex1=0;    int Iindex1=0;    int Cindex2=0;    int Iindex2=0;

    if(/*conType==2 && */conProbabilityTemp.count()==8){
        QList<int> checkResult1,checkResult2;

        checkResult1=checkContainerNumber(0,4);
        if(checkResult1.size()==2){
            Cindex1=checkResult1.at(0);
            Iindex1=checkResult1.at(1);
        }
        checkResult2=checkContainerNumber(4,8);
        if(checkResult2.size()==2){
            Cindex2=checkResult2.at(0);
            Iindex2=checkResult2.at(1);
        }

        /*****************************
        * @brief:系统逻辑判断检测为双箱,
        ******************************/
        if(2==type && conTemp[Cindex1]!=conTemp[Cindex2]){
            emit containerSignal(conType,conTemp[Cindex1], checkConList[Cindex1],isoTemp[Iindex1],conTemp[Cindex2],checkConList[Cindex2],isoTemp[Iindex2]);
        }
        else {
            bool isOne=false;
            if(conTemp[Cindex1]==conTemp[Cindex2] && !conTemp[Cindex1].isEmpty()){/* 前后相同修正长箱 */
                isOne=true;
            }
            else if(conTemp[Cindex1]!=conTemp[Cindex2] && !conTemp[Cindex1].isEmpty() && !conTemp[Cindex2].isEmpty()){/* 前后相同修正长箱 */
                if(ConsecutiveLCS(conTemp[Cindex1],conTemp[Cindex2])<=1){/* 两个箱号相似度小于2,判定为一个集装箱 */
                    isOne=true;
                }
                if(ConsecutiveLCS(conTemp[Cindex1].mid(4,conTemp[Cindex1].size()),conTemp[Cindex2].mid(4,conTemp[Cindex2].size()
                                                                                                       ))<=1){/* 两个箱号相似度小于2,判定为一个集装箱 */
                    isOne=true;
                }
                if(conTemp[Cindex1].indexOf(conTemp[Cindex2])!=-1 || conTemp[Cindex2].indexOf(conTemp[Cindex1])!=-1){/* 一个箱号是另外一个箱号子集 */
                    isOne=true;
                }
                /*****************************
                * @brief:通过22判断小箱，如果一个为错，也判断成单箱
                ******************************/
//                if(checkConList[Cindex1] != checkConList[Cindex2]){
//                    isOne=true;
//                }

            }
            else if(conTemp[Cindex2].isEmpty() || conTemp[Cindex1].isEmpty()){/* 前后有空修装小箱 */
                if(type!=2){
                    isOne=true;
                }
            }

            if(isOne){
                //conType=1;

                QList<int> checkResult;/* 判断为一个箱，重新合在一起校验 */
                checkResult=checkContainerNumber(0,conTemp.size());
                if(checkResult.size()==2){
                    Cindex1=checkResult.at(0);
                    Iindex1=checkResult.at(1);
                }

//                if (isoTemp[Iindex1].startsWith("2") || isoTemp[Iindex2].startsWith("2")) {
//                    //isoTemp[Iindex1]="22G1";
//                    conType=0;
//                }
//                if((isoTemp[Iindex1].isEmpty() && isoTemp[Iindex2].isEmpty()) || (!isoTemp[Iindex1].startsWith("2") && !isoTemp[Iindex2].startsWith("2"))){
//                    //isoTemp[Iindex1]="45G1";
//                    conType=type;
//                }
                if (isoTemp[Iindex1].startsWith("2") || isoTemp[Iindex2].startsWith("2")) {
                    //isoTemp[Iindex1]="22G1";
                    conType=0;
                    if(isoTemp[Iindex1].isEmpty() && isoTemp[Iindex2].isEmpty()){
                        isoTemp[Iindex1]="22G1";
                    }
                }
                else {
                    conType=1;
                    if(isoTemp[Iindex1].isEmpty() && isoTemp[Iindex2].isEmpty()){
                        isoTemp[Iindex1]="45G1";
                    }
                }

                emit containerSignal(conType,conTemp[Cindex1],checkConList[Cindex1],isoTemp[Iindex1]);
            }
            else {
                conType=2;
            }

            if(conType==2){
                if(isoTemp[Iindex1].isEmpty() /*|| -1==ISOContains.indexOf(isoTemp[Iindex1])*/){
                    isoTemp[Iindex1]="22G1";
                }
                if(isoTemp[Iindex2].isEmpty() /*|| -1==ISOContains.indexOf(isoTemp[Iindex2])*/){
                    isoTemp[Iindex2]="22G1";
                }
                emit containerSignal(conType,conTemp[Cindex1], checkConList[Cindex1],isoTemp[Iindex1],conTemp[Cindex2],checkConList[Cindex2],isoTemp[Iindex2]);
            }
        }
    }
    else {        
//        QList<int> checkResult;
//        checkResult=checkContainerNumber(0,conTemp.size());
//        if(checkResult.size()==2){
//            Cindex1=checkResult.at(0);
//            Iindex1=checkResult.at(1);
//        }
//        if(isoTemp[Iindex1].isEmpty()){
//            isoTemp[Iindex1]=conType?"45G1":"22G1";
//        }
//        else {
//            conType = isoTemp[Iindex1].startsWith("2")?0:1;
////            if(-1==ISOContains.indexOf(isoTemp[Iindex1])){
////                isoTemp[Iindex1]=conType?"45G1":"22G1";
////            }
//        }
        QList<int> checkResult;
        checkResult=checkContainerNumber(0,conTemp.size());
        if(checkResult.size()==2){
            Cindex1=checkResult.at(0);
            Iindex1=checkResult.at(1);
        }

        conType=0;
        if(isoTemp[Iindex1].isEmpty()){
            isoTemp[Iindex1]="22G1";
        }

        emit containerSignal(conType,conTemp[Cindex1],checkConList[Cindex1],isoTemp[Iindex1]);
    }

    //    /*****************************
    //     * 20220220
    //    * @brief:方便数据写入数据库
    //    ******************************/
    //    conTemp.clear();
    //    isoTemp.clear();
    //    checkConList.clear();
    //    conProbabilityTemp.clear();
    //    isoProbabilityTemp.clear();

    //    for(auto var:resultMap.values()){
    //        if(var.startsWith("RESULT")){
    //            QStringList tmp=var.split(":")[1].split("|");
    //            if(tmp.count()==4){
    //                conTemp.append(tmp[0].trimmed());/* 箱号 */
    //                isoTemp.append(tmp[1]);/* 箱型 */
    //                checkConList.append(numberCheck(tmp[0].trimmed()));/* 校验结果 */
    //                conProbabilityTemp.append(tmp[2].toUInt());/* 箱号置信度 */
    //                isoProbabilityTemp.append(tmp[3].toUInt()/*-1!=ISOContains.indexOf(tmp[1])?tmp[3].toUInt():0*/);/* 箱型置信度 */
    //            }
    //        }
    //    }

    //    /*****************************
    //    * @brief:conTemp结果集在处理时经过排序，这里需要恢复下标
    //    ******************************/
    //    if(conTemp.size()==8){
    //        Cindex1=Cindex1==3?6:Cindex1;
    //        Iindex1=Iindex1==3?6:Iindex1;
    //    }

    updateDataBase(conType,Cindex1,Iindex1,Cindex2,Iindex2,imgNameMap);

    conTemp.clear();
    isoTemp.clear();
    checkConList.clear();
    conProbabilityTemp.clear();
    isoProbabilityTemp.clear();
    resultMap.clear();
    correctNUmber.clear();
}

QList<int> ResultsAnalysis::checkContainerNumber(int start, int end)
{
    /* 双箱，分前3个结果和后3个结果独立处理,前箱下标,前箱型下标,后箱下标,后箱型下标,箱号置信度下表,箱型置信度下标 */
    int Cindex=0;    int Iindex=0;      uint32_t Cprobability=0;    uint32_t Iprobability=0;
    bool check=false;
    QList<int> checkResult;

    QStringList numberList=queueContainerNumber(conTemp.mid(start,end));

    if(numberList.size()==1 && numberList.at(0).size()>4){
        QString number=numberList.at(0);
        for(int i=0;i<4;i++){
            if(number.at(i)<'A'){
                numberList.clear();
            }
        }
        for(int i=4;i<number.size();i++){
            //qDebug()<<number.at(i);
            if(number.at(i)>'9'){
                numberList.clear();
            }
        }
    }

    if(numberList.count()==1 && numberList.at(0).size()==11){/* 有多组相同箱号，分析置信度和校验*/
        for (int var = start; var < end; ++var) {
            if(numberList[0]==conTemp[var]){
                check=true;
                Cindex=var;
            }
        }
    }

    if(!check) {

        /*****************************
        * @brief:多次出现箱号字头
        ******************************/
        QString startTmp= queueContainerStart(conTemp.mid(start,end));
        for(int i=0;i<startTmp.size();i++){
            if(startTmp.at(i)<'A' || startTmp.at(i)>'Z'){
                startTmp.clear();
                break;
            }
        }

        /*****************************
        * @brief:校验正确的个数
        ******************************/
        int i=0;

        for (int var = start; var < end; ++var) {
            if(!startTmp.isEmpty()){
                if(conProbabilityTemp[var]>Cprobability && conTemp[var].mid(0,4)==startTmp && checkConList[var]){
                    Cindex=var;
                    Cprobability=conProbabilityTemp[var];
                    ++i;
                }
            }
            else {
                if(checkConList[var] && conProbabilityTemp[var]>Cprobability){/* 没有相同字头，对比置信度和校验 */
                    Cindex=var;
                    Cprobability=conProbabilityTemp[var];
                    ++i;
                }
            }
        }

        if(i==0/* && startTmp.isEmpty()*/){/* 没有正确箱号，直接对比置信度 */
            for (int var = start; var < end; ++var) {
                if(conProbabilityTemp[var]>Cprobability){
                    Cindex=var;
                    Cprobability=conProbabilityTemp[var];
                }
            }
        }
    }


    /*****************************
    * @brief:帅选箱型重复项
    * 202202201807
    ******************************/
    numberList=queueContainerNumber(isoTemp.mid(start,end));
    if(numberList.count()==1){/* 有多组相同箱型，直接返回*/
        for (int var = start; var < end; ++var) {
            if(numberList[0]==isoTemp[var]){
                Iindex=var;
            }
        }
    }
    else {
        for (int var = start; var < end; ++var) {/* 箱型校验 */
            if(isoProbabilityTemp[var]>Iprobability){
                Iprobability=isoProbabilityTemp[var];/* 比对箱型置信度 */
                Iindex=var;
            }
        }
    }

    return checkResult<<Cindex<<Iindex;
}

int ResultsAnalysis::ConsecutiveLCS(QString rs1, QString rs2)
{
    int cot=0;
    int len=0;

    if(rs1.indexOf(rs2)!=-1){
        return 0;
    }

    if(rs2.indexOf(rs1)!=-1){
        return 0;
    }


    if(rs1.size()==11 && rs2.size()==11){
        if(rs1.indexOf(rs2.mid(4,rs2.size()-4))!=-1){
            return 0;
        }

        if(rs2.indexOf(rs1.mid(4,rs1.size()-4))!=-1){
            return 0;
        }

        for(int i=0;i<4;i++){
            if(rs1.at(i)!=rs2.at(i)){
                cot++;
            }
        }

        for(int i=4;i<11;i++){
            if(rs1.at(i)!=rs2.at(i)){
                cot++;
            }
        }
        if(cot<=2){
            return cot;
        }
        else {
            cot=0;
        }
    }

    if(rs1.size()==7 && rs2.size()==7){
        for(int i=0;i<7;i++){
            if(rs1.at(i)!=rs2.at(i)){
                cot++;
            }
        }
        if(cot<=1){
            return cot;
        }
        else {
            cot=0;
        }
    }


    if(rs1.size()-rs2.size()<0){
        len=rs1.size();
    }
    else {
        len=rs2.size();
    }

    for(int i=0;i<len;i++){
        if(rs1.at(i)!=rs2.at(i)){
            cot++;
        }
    }
    return cot;
}

QString ResultsAnalysis::queueContainerStart(QStringList conList)
{
    QStringList conStart;
    foreach (QString var, conList) {
        conStart.append(var.mid(0,4));
    }
    QStringList tmpStart= queueContainerNumber(conStart);

    if(tmpStart.size()==1){
        return tmpStart[0];
    }
    return QString("");
}

void ResultsAnalysis::resultsAnalysisStateslot(const int &channel, const QString &msg)
{
    Q_UNUSED(channel);

    lock.lockForWrite();

#ifdef Q_OS_LINUX
    QString eol = "\n";
#endif
#ifdef Q_OS_WIN
    QString eol = "\r\n";
#endif
    logFile.open( QIODevice::Append | QIODevice::Text | QIODevice::Unbuffered );
    logFile.write( msg.toUtf8() );
    logFile.write( eol.toUtf8() );
    logFile.close();

    lock.unlock();
}

void ResultsAnalysis::updateDataBase(int type, int Cindex1,int Iindex1, int Cindex2, int Iindex2,QMap<int,QString> imgMap)
{
    /* Tupe,集装箱类别:
     * -1 – 未知
     * 0 – 一个 20 集装箱
     * 1 – 一个 40 吋/45 吋集装箱
     * 2 – 两个 20 吋集装箱
     */

    QString time=QDateTime::currentDateTime().toString("yyyyMMddhhmmss");

    if(imgMap.size()>=1){
        QStringList tmp=imgMap.values().at(0).split(QDir::toNativeSeparators("/"));
        time=tmp.at(tmp.size()-1).mid(0,14);
    }

    QString dateTime=QDateTime::fromString(time,"yyyyMMddhhmmss").toString("yyyy/MM/dd hh:mm:ss");

    emit resultsAnalysisStateSignal(channel,QString("%1 start").arg(dateTime));/* 日志起始 */

    /*****************************
     * 202202201511
    * @brief:识别结果集编号1，2，3，8，4，5，6，9
    * 图片编号1，2，3，4，5，6，8，9
    ******************************/
    for (int var = 0; var < conTemp.count(); ++var) {
        /* 识别结果写入日志,[标志|时间戳|通道号(2位)|相机号(2位)|箱号|校验|箱型] */
        QString result="";
        /*****************************
        * @brief:双箱和长箱第8张图是前箱
        * 202202201946
        ******************************/
        if(imgMap.keys().size()==8){
            if(var==3){
                result=QString("[%1|%2|%3|%4|%5|%6|%7]").arg("I").arg(time).arg(channel,2,10,QLatin1Char('0')).arg(8,2,10,QLatin1Char('0')).arg(conTemp[var]).arg(checkConList[var]?"Y":"N").arg(isoTemp[var]);
            }
            else if (var==7) {
                result=QString("[%1|%2|%3|%4|%5|%6|%7]").arg("I").arg(time).arg(channel,2,10,QLatin1Char('0')).arg(9,2,10,QLatin1Char('0')).arg(conTemp[var]).arg(checkConList[var]?"Y":"N").arg(isoTemp[var]);
            }
            else if(var<3){
                result=QString("[%1|%2|%3|%4|%5|%6|%7]").arg("I").arg(time).arg(channel,2,10,QLatin1Char('0')).arg(var+1,2,10,QLatin1Char('0')).arg(conTemp[var]).arg(checkConList[var]?"Y":"N").arg(isoTemp[var]);
            }
            else {
                result=QString("[%1|%2|%3|%4|%5|%6|%7]").arg("I").arg(time).arg(channel,2,10,QLatin1Char('0')).arg(var,2,10,QLatin1Char('0')).arg(conTemp[var]).arg(checkConList[var]?"Y":"N").arg(isoTemp[var]);
            }
        }
        else {
            if(var==3){
                result=QString("[%1|%2|%3|%4|%5|%6|%7]").arg("I").arg(time).arg(channel,2,10,QLatin1Char('0')).arg(6,2,10,QLatin1Char('0')).arg(conTemp[var]).arg(checkConList[var]?"Y":"N").arg(isoTemp[var]);
            }
            else if (var==4) {
                result=QString("[%1|%2|%3|%4|%5|%6|%7]").arg("I").arg(time).arg(channel,2,10,QLatin1Char('0')).arg(8,2,10,QLatin1Char('0')).arg(conTemp[var]).arg(checkConList[var]?"Y":"N").arg(isoTemp[var]);
            }
            else if(var==5){
                result=QString("[%1|%2|%3|%4|%5|%6|%7]").arg("I").arg(time).arg(channel,2,10,QLatin1Char('0')).arg(9,2,10,QLatin1Char('0')).arg(conTemp[var]).arg(checkConList[var]?"Y":"N").arg(isoTemp[var]);
            }
            else {
                result=QString("[%1|%2|%3|%4|%5|%6|%7]").arg("I").arg(time).arg(channel,2,10,QLatin1Char('0')).arg(var+1,2,10,QLatin1Char('0')).arg(conTemp[var]).arg(checkConList[var]?"Y":"N").arg(isoTemp[var]);
            }
        }

        emit resultsAnalysisStateSignal(channel,result);
        if(sendMid){
            emit sendResultSignal(channel,result);
        }
    }

    if(type==2){
        /* 识别结果写入日志,[标志|时间戳|通道号(2位)|逻辑|箱号|校验|箱号|校验|箱型|箱型] */
        QString result=QString("[%1|%2|%3|%4|%5|%6|%7|%8|%9|%10]").arg("C").arg(time).arg(channel,2,10,QLatin1Char('0')).arg(type).arg(conTemp[Cindex1]).arg(checkConList[Cindex1]?"Y":"N").arg(conTemp[Cindex2]).arg(checkConList[Cindex2]?"Y":"N").arg(isoTemp[Iindex1]).arg(isoTemp[Iindex2]);
        emit resultsAnalysisStateSignal(channel,result);
        emit sendResultSignal(channel,result);
    }
    else {
        QString result=QString("[%1|%2|%3|%4|%5|%6|%7]").arg("C").arg(time).arg(channel,2,10,QLatin1Char('0')).arg(type).arg(conTemp[Cindex1]).arg(checkConList[Cindex1]?"Y":"N").arg(isoTemp[Iindex1]);
        emit resultsAnalysisStateSignal(channel,result);
        emit sendResultSignal(channel,result);
    }

    QMap<QString,QString> data;
    data["Timer"]=dateTime;
    data["Channel"]=QString::number(channel);
    data["Type"]=QString::number(type);
    data["ContainerFront"]=conTemp[Cindex1];
    data["ISOFront"]=isoTemp[Iindex1];
    data["CheckFront"]=QString::number(checkConList[Cindex1]);

    if(type==2){
        data["ContainerAfter"]=conTemp[Cindex2];
        data["ISOAfter"]=isoTemp[Iindex2];
        data["CheckAfter"]=QString::number(checkConList[Cindex2]);
    }

    if(conTemp.count()==6){
        data["ImgFrontNumber"]=conTemp[0];
        data["ImgFrontISO"]=isoTemp[0];
        data["ImgFrontCheck"]=QString::number(checkConList[0]);
        data["ImgLeftFrontNumber"]=conTemp[1];
        data["ImgLeftFrontISO"]=isoTemp[1];
        data["ImgLeftFrontCheck"]=QString::number(checkConList[1]);
        data["ImgRightFrontNumber"]=conTemp[2];
        data["ImgRightFrontISO"]=isoTemp[2];
        data["ImgRightFrontCheck"]=QString::number(checkConList[2]);
        data["ImgAfterNumber"]=conTemp[3];
        data["ImgAfterISO"]=isoTemp[3];
        data["ImgAfterCheck"]=QString::number(checkConList[3]);

        /*****************************
        * @brief:202112181739
        ******************************/
        data["ImgProspectsNumber"]=conTemp[4];
        data["ImgProspectsISO"]=isoTemp[4];
        data["ImgProspectsCheck"]=QString::number(checkConList[4]);
        data["ImgForegroundNumber"]=conTemp[5];
        data["ImgForegroundISO"]=isoTemp[5];
        data["ImgForegroundCheck"]=QString::number(checkConList[5]);
    }
    else if (conTemp.count()==8) {
        data["ImgFrontNumber"]=conTemp[0];
        data["ImgFrontISO"]=isoTemp[0];
        data["ImgFrontCheck"]=QString::number(checkConList[0]);
        data["ImgLeftFrontNumber"]=conTemp[1];
        data["ImgLeftFrontISO"]=isoTemp[1];
        data["ImgLeftFrontCheck"]=QString::number(checkConList[1]);
        data["ImgRightFrontNumber"]=conTemp[2];
        data["ImgRightFrontISO"]=isoTemp[2];
        data["ImgRightFrontCheck"]=QString::number(checkConList[2]);

        data["ImgLeftAfterNumber"]=conTemp[4];
        data["ImgLeftAfterISO"]=isoTemp[4];
        data["ImgLeftAfterCheck"]=QString::number(checkConList[4]);
        data["ImgRightAfterNumber"]=conTemp[5];
        data["ImgRightAfterISO"]=isoTemp[5];
        data["ImgRightAfterCheck"]=QString::number(checkConList[5]);
        data["ImgAfterNumber"]=conTemp[6];
        data["ImgAfterISO"]=isoTemp[6];
        data["ImgAfterCheck"]=QString::number(checkConList[6]);

        /*****************************
        * @brief:202112181739
        ******************************/
        data["ImgProspectsNumber"]=conTemp[3];
        data["ImgProspectsISO"]=isoTemp[3];
        data["ImgProspectsCheck"]=QString::number(checkConList[3]);
        data["ImgForegroundNumber"]=conTemp[7];
        data["ImgForegroundISO"]=isoTemp[7];
        data["ImgForegroundCheck"]=QString::number(checkConList[7]);
    }

    emit updateDataBaseSignal(data);
    data.clear();
    imgMap.clear();
}
