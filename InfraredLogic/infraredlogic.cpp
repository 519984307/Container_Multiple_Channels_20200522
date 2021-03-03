#include "infraredlogic.h"

InfraredLogic::InfraredLogic(QObject *parent)
{
    this-> setParent(parent);

    pSerial1=new QSerialPort(this);
    pSerial2=new QSerialPort(this);

    pDetectionTimer=new QTimer  (this);
    connect(pDetectionTimer,SIGNAL(timeout()),this,SLOT(detectionLogicSlot()));

    pRealySerialportTimer = new QTimer(this);
    connect(pRealySerialportTimer,SIGNAL(timeout()),this,SLOT(realyTheSerialport()));

    pTimerFront=new QTimer (this) ;
    pTimerFront->setSingleShot(true);/* 单次定时器 */
    connect(pTimerFront,SIGNAL(timeout()),this,SLOT(delayFrontCaptureSlot()));

    pTimerAfter=new QTimer (this);
    pTimerAfter->setSingleShot(true);/* 单次定时器 */
    connect(pTimerAfter,SIGNAL(timeout()),this,SLOT(delayAfterCaptureSlot()));

    memset(status,0,sizeof (status));
    memset(tmpStatus,0,sizeof (tmpStatus));

    type=0;
    com1=false;
    com2=false;
    exit=false;
    doubleFrontPut=false;
    channelNum=-1;
    carInChannel=false;

    comming=false;isCar=false;isLong=false;isDouble=false;health1=true;health2=true;

    start=true;
}

InfraredLogic::~InfraredLogic()
{
}

QString InfraredLogic::InterfaceType()
{
    return "Protector";
}

void InfraredLogic::setAlarmModeSlot(bool model)
{
    valueOne=0;    valueTwo=1;
    /* 常开(false) |常闭(true) */
    if(!model) {
        valueOne=1;valueTwo=0;
    }
}

void InfraredLogic::exitWhileSlot()
{
    this->exit=true;

    pRealySerialportTimer->stop();
    pDetectionTimer->stop();
    pTimerFront->stop();
    pTimerAfter->stop();
    pSerial1->close();
    pSerial2->close();
}

bool InfraredLogic::compareStatus(int *before, int *after)
{
    for (int i=0;i<8;i++) {
        if(before[i]!=after[i]) {
            return true;
        }
    }
    return  false;
}

void InfraredLogic::serialLogic(int *status)
{
    /*
    * 红外逻辑(一定要判断状态),1)如果A2无信号,过车释放A1,会导致后3张图偏移.(处理完成)
    * 常开[false|0,0,0,0,0,0,0,0]|常闭[true|1,1,1,1,1,1,1,1]
    */

    /*****************************
    * @brief:车辆倒车：车辆已进入，退出挡住A1，其他释放
    ******************************/
    if(carInChannel && status[0]==valueOne && status[1]==valueTwo && status[2]==valueTwo && status[3]==valueTwo){
        emit logicPutImageSignal(5);
        carInChannel=false;
    }

    /*****************************
    * @brief:车辆进入，如果是高车头同时挡住2组红外                    1
    ******************************/
    if(status[0]==valueOne && status[1]==valueOne && status[2]==valueTwo && status[3]==valueTwo){
        comming=true;
        isLong=false;
        isDouble=false;
        isCar=false;

        carInChannel=false;

        emit logicPutImageSignal(-1);
        qDebug()<<"Vehicles entering[1]";
    }

    /*****************************
    * @brief:遮挡住2组红外，然后释放掉，证明是高车头                  2
    ******************************/
    if(comming && status[0]==valueTwo && status[1]==valueTwo && status[2]==valueTwo && status[3]==valueTwo){
        comming=false;
        isCar=true;/* 判断是高车头 */
        qDebug()<<"High truck head[2]";
    }

    /*****************************
    * @brief:不是双箱，不是车头，判断为长箱。抓拍前3张                3
    ******************************/
    if(comming && !isDouble && !isCar && status[0]==valueOne && status[1]==valueOne && status[2]==valueOne && status[3]==valueOne){
        /* 长箱或者双向(双箱加高车头抓两次) */
        isLong=true;

        if(health2){
            emit logicPutImageSignal(0);
        }
        qDebug()<<"Grab (front, left, right)[3]";

        return;
    }

    /*****************************
    * @brief:释放A1,A2。抓拍后3张。逻辑完成                        4
    ******************************/
    if(comming && isLong && status[0]==valueTwo && status[1]==valueTwo && status[2]==valueOne && status[3]==valueOne){
        if(health1){
            if(isDouble){
                /* 如果是双箱就触发双箱标志 */
                emit logicPutImageSignal(4);
                qDebug()<<"Grab (double box) (back, left, right)[4-4}]";
            }
            else {
                /* 如果是长箱就触发长箱标志 */
                logicPutImageSignal(1);
                qDebug()<<"Grab (Long Box) (Back, Left, Right)[4-1]";
            }
            carInChannel=true;
        }

        comming=false;
        isLong=false;
        isDouble=false;
        isCar=false;
        health2=true;
        health1=true;



        return;
    }

    /*****************************
    * @brief:不是车头，不是长箱，就触发小箱逻辑。抓4张              5
    ******************************/
    if(comming && !isLong && !isCar && status[0]==valueTwo && status[1]==valueTwo && status[2]==valueOne && status[3]==valueOne){
        /* 小箱，抓4张(小箱放长托架后面,标准小箱) */
        if(health1){
            emit logicPutImageSignal(2);
            carInChannel=true;
        }

        comming=false;
        isLong=false;
        isDouble=false;
        isCar=false;
        health2=true;
        health1=true;

        qDebug()<<"Grasp (small box) (front , back, left, right)[5]";

        return;
    }

    /*****************************
    * @brief:                                               8
    ******************************/
    if(comming && !isCar  && isLong && status[0]==valueOne && status[1]==valueTwo && status[2]==valueOne && status[3]==valueOne){
        /* 双箱 A2 */
        isDouble=true;

        qDebug()<<"Double box state(A2)[8-1]";
    }
    if(comming && !isCar  && isLong && status[0]==valueOne && status[1]==valueOne && status[2]==valueTwo && status[3]==valueOne){
        /* 双箱 B1 */
        isDouble=true;

        qDebug()<<"Double box state(B1)[8-2]";
    }
    if(comming && !isCar  && isLong && status[0]==valueOne && status[1]==valueOne && status[2]==valueOne && status[3]==valueTwo){
        /* 双箱 B2 */
        isDouble=false;
        isLong=false;

        qDebug()<<"Double box state(B2)[8-3]";
    }
}

void InfraredLogic::startSlaveSlot(const QString &portName1, const QString &portName2,int channelNum)
{
    if(start){
        QDateTime dateTime = QDateTime::currentDateTime();
        QString stringDateTime = dateTime.toString( "yyyy_MM_dd_hh_mm_ss" );
        QString path = QStandardPaths::writableLocation( QStandardPaths::AppConfigLocation );

        QString logFolderName =QDir::toNativeSeparators(path + "/" + "logic_log"+"/"+QString::number(channelNum));
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

        connect(this,SIGNAL(logicStatesignal(int*)),this,SLOT(logicStateslot(int*)));
        start=false;
    }

    port1=portName1;
    port2=portName2;
    this->channelNum=channelNum;

    /*
     * COM1
    */
    if(!com1){
        pSerial1->close();
        pSerial1->setPortName(portName1);

        if(!pSerial1->open(QIODevice::ReadOnly)){
            qWarning().noquote()<<QString("Channel:%1 | portName1:%2 Open error<errorCode=%3>").arg(channelNum).arg(portName1).arg(pSerial1->error());
        }
        else{
            /*
             * 设置DTR电平高
            */
            if(pSerial1->setDataTerminalReady(true)){
                qDebug().noquote()<<QString("Channel:%1 | portName1:%2 Set DataTerminalReady successful").arg(channelNum).arg(portName1);
                com1=true;
            }
            else {
                qWarning().noquote()<<QString("Channel:%1 | portName1:%2 Set DataTerminalReady error<errorCode=%3>").arg(channelNum).arg(portName1).arg(pSerial1->error());
            }
            /*
             * 设置RTS电平高,可以不设置
            */
            if(pSerial1->setRequestToSend(true))
            {
                qDebug().noquote()<<QString("Channel:%1 | portName1:%2 Set RequestToSend successful").arg(channelNum).arg(portName1);
            }
            else{
                qWarning().noquote()<<QString("Channel:%1 | portName1:%2 Set RequestToSend error<errorCode=%3>").arg(channelNum).arg(portName1).arg(pSerial1->error());
            }
        }
    }

    /*
     * COM2
    */
    if(!com2)
    {
        pSerial2->close();
        pSerial2->setPortName(portName2);

        if(!pSerial2->open(QIODevice::ReadOnly)){
            qWarning().noquote()<<QString("Channel:%1 | portName2:%2 Open error<errorCode=%3>").arg(channelNum).arg(portName2).arg(pSerial2->error());
        }
        else{
            /*
             * 设置DTR电平高
            */
            if(pSerial2->setDataTerminalReady(true)){
                qDebug().noquote()<<QString("Channel:%1 | portName2:%2 Set DataTerminalReady successful").arg(channelNum).arg(portName2);
                com2=true;
            }
            else {
                qWarning().noquote()<<QString("Channel:%1 | portName2:%2 Set DataTerminalReady error<errorCode=%3>").arg(channelNum).arg(portName2).arg(pSerial2->error());
            }
            /*
             * 设置RTS电平高,可以不设置
            */
            if(pSerial2->setRequestToSend(true))
            {
                qDebug().noquote()<<QString("Channel:%1 | portName2:%2 Set RequestToSend successful").arg(channelNum).arg(portName2);
            }
            else{
                qWarning().noquote()<<QString("Channel:%1 | portName2:%2 Set RequestToSend error<errorCode=%3>").arg(channelNum).arg(portName2).arg(pSerial2->error());
            }
        }
    }

    emit serialPortStateSignal(com1,com2);

    if(!com1 && !com2){/* com1和com2都未打开,不做后续处理 */
        qWarning().noquote()<<QString("Channel:%1 serial port exception").arg(channelNum);
        QTimer::singleShot(15000,this,SLOT(realyTheSerialport()));

        return;
    }

    pDetectionTimer->start(10);

}

void InfraredLogic::simulateTriggerSlot(int type)
{
    this->type=type;

    switch (type) {
    case 0:/* 清除图片 */
        emit logicPutImageSignal(-1);
        break;
    case 1:/* 22G1 */
        emit logicPutImageSignal(-1);
        emit logicPutImageSignal(2);
        break;
    case 2:/* 45G1,后3张图片延时抓拍 */
        emit logicPutImageSignal(-1);
        emit logicPutImageSignal(0);
        QTimer::singleShot(3000,this,SLOT(delayAfterCaptureSlot()));
        break;
    case 3:/* Double 22G1 Front */
        emit logicPutImageSignal(-1);
        emit logicPutImageSignal(3);
        doubleFrontPut=true;
        break;
    case 4:/* Double 22G1 Front */
        if(doubleFrontPut){
            emit logicPutImageSignal(4);
        }
        doubleFrontPut=false;
        break;
    case 5:/* 循环抓拍45G1,后3张图片延时抓拍 */
        if(pTimerFront->isActive()){
            pTimerFront->stop();
        }
        else {
            if(!pTimerAfter->isActive()){
                pTimerFront->start(5000);
            }
        }
        if(pTimerAfter->isActive()){
            pTimerAfter->stop();
        }
        break;
    }
}

void InfraredLogic::delayAfterCaptureSlot()
{
    emit logicPutImageSignal(1);
    if(type==5){
        pTimerFront->start(10000);
    }
}

void InfraredLogic::delayFrontCaptureSlot()
{
    emit logicPutImageSignal(-1);
    emit logicPutImageSignal(0);

    if(pTimerAfter->isActive()){/* 延时抓拍后面图片 */
        pTimerAfter->stop();
    }
    pTimerAfter->start(5000);
}

void InfraredLogic::detectionLogicSlot()
{
    detectionLogicStatus(com1,com2);
}

void InfraredLogic::realyTheSerialport()
{
    startSlaveSlot(port1,port2,channelNum);
}

void InfraredLogic::detectionLogicStatus(bool com1, bool com2)
{
    QCoreApplication::processEvents();
    if(com1 && pSerial1->pinoutSignals()!=QSerialPort::NoSignal){
        /*A1*/
        status[0]= (pSerial1->pinoutSignals()&QSerialPort::ClearToSendSignal)?1:0;
        //A2
        status[1]= (pSerial1->pinoutSignals()&QSerialPort::DataSetReadySignal)?1:0;
        /*D1*/
        status[4]= (pSerial1->pinoutSignals()&QSerialPort::DataCarrierDetectSignal)?1:0;
    }
    else {
        this->com1=false;
    }

    if(com2 && pSerial2->pinoutSignals()!=QSerialPort::NoSignal){
        /*B1*/
        status[2]= (pSerial2->pinoutSignals()&QSerialPort::ClearToSendSignal)?1:0;
        /*B2*/
        status[3]= (pSerial2->pinoutSignals()&QSerialPort::DataSetReadySignal)?1:0;
        /*D2*/
        status[5]= (pSerial2->pinoutSignals()&QSerialPort::DataCarrierDetectSignal)?1:0;
    }
    else {
        this->com2=false;
    }


    if(compareStatus(status,tmpStatus)){
        emit logicStatesignal(status);
    }

    if(com1&&com2){
        /* 比对红外状态有没有变化 有变化才做相应处理 */
        if(compareStatus(status,tmpStatus)){
            serialLogic(status); /* 逻辑判断 */
        }
        pRealySerialportTimer->stop();
    }
    else {
        if(!pRealySerialportTimer->isActive()){
            pRealySerialportTimer->start(15000);
        }
        if(!com1){
            /*A1*/
            status[0]= 0;
            //A2
            status[1]= 0;
            /*D1*/
            status[4]= 0;
        }
        if(!com2){
            /*B1*/
            status[2]= 0;
            /*B2*/
            status[3]= 0;
            /*D2*/
            status[5]= 0;
        }
    }

    if(!com1 && !com2){
        pDetectionTimer->stop();
        QTimer::singleShot(15000,this,SLOT(realyTheSerialport()));
        memset(status,0,sizeof (status));
    }
    emit logicStatusSignal(status);/* 传递状态 */
    memcpy(tmpStatus,status,sizeof (status));
}

void InfraredLogic::logicStateslot(int *state)
{
    lock.lockForWrite();

#ifdef Q_OS_LINUX
    QString eol = "\n";
#endif
#ifdef Q_OS_WIN
    QString eol = "\r\n";
#endif
    logFile.open( QIODevice::Append | QIODevice::Text | QIODevice::Unbuffered );
    logFile.write(QString("%9: A1[%1] A2[%2] B1[%3] B2[%4] -  D1[%5] D2[%6] D3[%7] D4[%8]").arg(state[0]).arg(state[1]).arg(state[2]).arg(state[3]).arg(state[4]).arg(state[5]).arg(state[6]).arg(state[7]).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss zzz::")).toUtf8() );
    logFile.write( eol.toUtf8() );
    logFile.close();

    lock.unlock();
}
