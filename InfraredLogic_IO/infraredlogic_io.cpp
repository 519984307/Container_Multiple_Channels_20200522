#include "infraredlogic_io.h"

InfraredLogic_IO::InfraredLogic_IO(QObject *parent)
{
    this->setParent(parent);

    isHeartBeat=false;
    isConnected=false;
    pTcpServer=nullptr;
    pTcpClient=nullptr;
    pTimerAutoLink=nullptr;
    pCloseLEDTimer=nullptr;

    start=true;
    comming=false;
    isLong=false;
    isDouble=false;
    isCar=false;
    carInChannel=false;
    reversing=false;

    memset(status,0,sizeof (status));
    memset(tmpStatus,0,sizeof (tmpStatus));

#ifdef Q_OS_LINUX
    eol = "\n";
#endif
#ifdef Q_OS_WIN
    eol = "\r\n";
#endif
}

InfraredLogic_IO::~InfraredLogic_IO()
{
}

QString InfraredLogic_IO::InterfaceType()
{
    return QString("Protector_IO");
}

void InfraredLogic_IO::serialLogicSlot(int *sta)
{
    bool run=false;
    for(int ind=0;ind<4;ind++){
        if(status[ind]!=sta[ind]){
            run=true;
        }
    }
    if(!run){
        return;
    }

    memcpy(status,sta,sizeof (status));

    /*
    * 红外逻辑(一定要判断状态),1)如果A2无信号,过车释放A1,会导致后3张图偏移.(处理完成)
    * 常开[false|0,0,0,0,0,0,0,0]|常闭[true|1,1,1,1,1,1,1,1]
    * 0:南京三宝
    * 1:标准逻辑
    */
    if(0 == logicType){
        /*****************************
        * @brief:车辆倒车：车辆已进入抓拍完成，退出挡住（A2），B1,B2，A1释放
        ******************************/
        if(!reversing && carInChannel && status[0]==valueTwo && status[1]==valueOne && status[2]==valueOne){
            emit logicPutImageSignal(5);
            carInChannel=false;
            reversing=true;

            qDebug().noquote()<<QString("Vehicle reversing[-1]");
        }

        /*****************************
        * @brief:车辆倒车，【只挡住A1，退出倒车状态】
        * 2021-10-22-修改【if(reversing && status[0]==valueTwo && status[1]==valueTwo && status[2]==valueTwo && status[3]==valueTwo){】
        ******************************/
        if(reversing && status[0]==valueOne && status[1]==valueTwo && status[2]==valueTwo && status[3]==valueTwo){
            reversing=false;
        }

        /*****************************
        * @brief:车辆进入，如果是高车头同时挡住2组红外
        * 2021/09/01 挡住A1,A2释放B1,B2【防止倒车触发当前逻辑】
        ******************************/
        if(!reversing && status[0]==valueOne && status[1]==valueOne && status[2]==valueTwo && status[3]==valueTwo){
            comming=true;
            isLong=false;
            isDouble=false;
            isCar=false;

            carInChannel=false;

            emit logicPutImageSignal(-1);
            qDebug().noquote()<<QString("Vehicles entering[1]");
        }

        if(comming &&!isDouble && status[0]==valueOne && status[1]==valueOne && status[2]==valueOne && status[3]==valueOne){
            isLong=true;
        }

        /*****************************
        * 2021/02/07 16：13
        * @brief:长箱,短箱，双箱 都是A1 A2 B1抓3张
        ******************************/
        if(comming && !isLong && !isDouble && status[0]==valueOne && status[1]==valueOne && status[2]==valueOne){
            emit logicPutImageSignal(0);

            qDebug().noquote()<<QString("Grab (front, left, right)[3]");

            return;
        }

        if(comming && status[0]==valueTwo && status[1]==valueTwo && status[2]==valueOne && status[3]==valueOne){
            if(isDouble){
                emit logicPutImageSignal(4);/* 双箱 */
                qDebug().noquote()<<QString("Grab (Long Box) (Back, Left, Right)[4-4]");
            }
            else if(isLong){
                emit logicPutImageSignal(1);/* 长箱 */
                qDebug().noquote()<<QString("Grab (Long Box) (Back, Left, Right)[4-1]");
            }
            else {
                emit logicPutImageSignal(6);/* 短箱 */
                qDebug().noquote()<<QString("Grab (Long Box) (Back, Left, Right)[4-5]");
            }

            comming=false;
            isLong=false;
            isDouble=false;
            isCar=false;

            reversing=false;
            carInChannel=true;

            return;
        }

        /*****************************
        * @brief:A1释放多少秒后，抓牌后3张图片，防止通道距离不够完成不了抓拍
        ******************************/
        if(comming && status[0]==valueTwo && status[1]==valueOne && status[2]==valueOne && status[3]==valueOne && A1ReleasrCap>0){
            QTimer::singleShot(A1ReleasrCap*1000,this,SLOT(A1ReleasrCapSlot()));

            comming=false;
            isCar=false;

            reversing=false;
            carInChannel=true;

            return;
        }

        /*****************************
        * @brief:遮挡住2组红外，然后释放掉，证明是高车头                  2
        ******************************/
        if(comming && status[0]==valueTwo && status[1]==valueTwo && status[2]==valueTwo && status[3]==valueTwo){
            comming=false;
            isCar=true;/* 判断是高车头 */
            qDebug().noquote()<<QString("High truck head[2]");
        }

        /*****************************
        * @brief: 双箱                                              8
        ******************************/
    //    if(comming && !isCar  && isLong && status[0]==valueTwo && status[1]==valueOne && status[2]==valueOne){
    //        /* 双箱 A1 */
    //        isDouble=true;
    //        isLong=false;

    //        qDebug()<<"Double box state(A2)[8-0]";
    //    }
        if(comming && !isCar  && isLong && status[0]==valueOne && status[1]==valueTwo && status[2]==valueOne && status[3]==valueOne){
            /* 双箱 A2 */
            isDouble=true;
            //isLong=false;

            qDebug().noquote()<<QString("Double box state(A2)[8-1]");
        }
        if(comming && !isCar  && isLong && status[0]==valueOne && status[1]==valueOne && status[2]==valueTwo && status[3]==valueOne){
            /* 双箱 B1 */
            isDouble=true;
            //isLong=false;

            qDebug().noquote()<<QString("Double box state(B1)[8-2]");
        }
        if(comming && !isCar  && isLong && status[0]==valueOne && status[1]==valueOne && status[2]==valueOne && status[3]==valueTwo){
            /* 双箱 B2 */
            isDouble=false;
            isLong=false;

            qDebug().noquote()<<QString("Double box state(B2)[8-3]");
        }
    }
    if(1 == logicType){
        /*****************************
        * @brief:车辆倒车：车辆已进入抓拍完成，退出挡住（A2），B1,B2，A1释放
        ******************************/
        if(!reversing && carInChannel && status[0]==valueTwo && status[1]==valueOne && status[2]==valueOne){
            emit logicPutImageSignal(5);
            carInChannel=false;
            reversing=true;

            qDebug().noquote()<<QString("Vehicle reversing[-1]");
        }

        /*****************************
        * @brief:车辆倒车，【只挡住A1，退出倒车状态】
        * 2021-10-22-修改【if(reversing && status[0]==valueTwo && status[1]==valueTwo && status[2]==valueTwo && status[3]==valueTwo){】
        ******************************/
        if(reversing && status[0]==valueOne && status[1]==valueTwo && status[2]==valueTwo && status[3]==valueTwo){
            reversing=false;
        }

        /*****************************
        * @brief:车辆进入，如果是高车头同时挡住2组红外
        * 2021/09/01 挡住A1,A2释放B1,B2【防止倒车触发当前逻辑】
        ******************************/
        if(!reversing && status[0]==valueOne && status[1]==valueOne && status[2]==valueTwo && status[3]==valueTwo){
            comming=true;
            isLong=false;
            isDouble=false;
            isCar=false;

            carInChannel=false;

            emit logicPutImageSignal(-1);
            qDebug().noquote()<<QString("Vehicles entering[1]");
        }

        /*****************************
        * @brief:遮挡住2组红外，然后释放掉，证明是高车头                  2
        ******************************/
        if(comming && status[0]==valueTwo && status[1]==valueTwo && status[2]==valueTwo && status[3]==valueTwo){
            comming=false;
            isCar=true;/* 判断是高车头 */
            qDebug().noquote()<<QString("High truck head[2]");
        }

        /*****************************
        * @brief:不是双箱，不是车头，判断为长箱。抓拍前3张                3
        ******************************/
        if(comming && !isDouble && !isCar && status[0]==valueOne && status[1]==valueOne && status[2]==valueOne && status[3]==valueOne){
            /* 长箱或者双向(双箱加高车头抓两次) */
            isLong=true;

            emit logicPutImageSignal(0);

            qDebug().noquote()<<QString("Grab (front, left, right)[3]");

            return;
        }

        /*****************************
        * @brief:释放A1,A2。抓拍后3张。逻辑完成                        4
        ******************************/
        if(comming && isLong && status[0]==valueTwo && status[1]==valueTwo && status[2]==valueOne && status[3]==valueOne){
            if(isDouble){
                /* 如果是双箱就触发双箱标志 */
                emit logicPutImageSignal(4);
                qDebug().noquote()<<QString("Grab (double box) (back, left, right)[4-4}]");
            }
            else {
                /* 如果是长箱就触发长箱标志 */
                logicPutImageSignal(1);
                qDebug().noquote()<<QString("Grab (Long Box) (Back, Left, Right)[4-1]");
            }
            carInChannel=true;
            reversing=false;

            comming=false;
            isLong=false;
            isDouble=false;
            isCar=false;

            return;
        }

        /*****************************
        * @brief:A1释放多少秒后，抓牌后3张图片，防止通道距离不够完成不了抓拍
        ******************************/
        if(comming && isLong && status[0]==valueTwo && status[1]==valueOne && status[2]==valueOne && status[3]==valueOne && A1ReleasrCap>0){
            QTimer::singleShot(A1ReleasrCap*1000,this,SLOT(A1ReleasrCapSlot()));

            comming=false;
            isCar=false;

            reversing=false;
            carInChannel=true;

            return;
        }

        /*****************************
        * @brief:不是车头，不是长箱，就触发小箱逻辑。抓4张              5
        ******************************/
        if(comming && !isLong && !isCar && status[0]==valueTwo && status[1]==valueTwo && status[2]==valueOne && status[3]==valueOne){
            /* 小箱，抓4张(小箱放长托架后面,标准小箱) */
            emit logicPutImageSignal(2);
            carInChannel=true;

            comming=false;
            isLong=false;
            isDouble=false;
            isCar=false;
            reversing=false;

            qDebug().noquote()<<QString("Grasp (small box) (front , back, left, right)[5]");

            return;
        }



        /*****************************
        * @brief:                                               8
        ******************************/
        if(comming && !isCar  && isLong && status[0]==valueOne && status[1]==valueTwo && status[2]==valueOne && status[3]==valueOne){
            /* 双箱 A2 */
            isDouble=true;

            qDebug().noquote()<<QString("Double box state(A2)[8-1]");
        }
        if(comming && !isCar  && isLong && status[0]==valueOne && status[1]==valueOne && status[2]==valueTwo && status[3]==valueOne){
            /* 双箱 B1 */
            isDouble=true;

            qDebug().noquote()<<QString("Double box state(B1)[8-2]");
        }
        if(comming && !isCar  && isLong && status[0]==valueOne && status[1]==valueOne && status[2]==valueOne && status[3]==valueTwo){
            /* 双箱 B2 */
            isDouble=false;
            isLong=false;

            qDebug().noquote()<<QString("Double box state(B2)[8-3]");
        }
    }
}

void InfraredLogic_IO::timerCloseLEDSlot()
{
    /*****************************
    * @brief:车辆离开关灯
    ******************************/
    for(int ind=0;ind<dOutType.size();ind++){
        if(0 == model && pTcpClient!=nullptr && dOutType.at(ind)==2){
            QString cmd=QString("AT+STACH%1=0%2").arg(QString::number(ind+1),eol);
            pTcpClient->write(cmd.toLatin1());

            qDebug().noquote()<<QString("[%1] %2:After recognition, turn off the fill light").arg(this->metaObject()->className(),QString::number(channelNum));
        }
        if(1 == model && pTcpServer!=nullptr && dOutType.at(ind)==2){
            QString cmd=QString("AT+STACH%1=0%2").arg(QString::number(ind+1),eol);
            emit signal_toSendData(channelNum,cmd);

            qDebug().noquote()<<QString("[%1] %2:After recognition, turn off the fill light").arg(this->metaObject()->className(),QString::number(channelNum));
        }
    }
}

void InfraredLogic_IO::A1ReleasrCapSlot()
{
    if(0 == logicType){
        if(isDouble){
            emit logicPutImageSignal(4);/* 双箱 */
            qDebug().noquote()<<QString("Grab (double box) (back, left, right)[4-4}]");
        }
        else if(isLong){
            emit logicPutImageSignal(1);/* 长箱 */
            qDebug().noquote()<<QString("Grab (Long Box) (Back, Left, Right)[4-1]");
        }
        else {
            emit logicPutImageSignal(6);/* 短箱 */
            qDebug().noquote()<<QString("Grab (Long Box) (Back, Left, Right)[4-5]");
        }
    }
    if(1 == logicType){
        if(isDouble){
            /* 如果是双箱就触发双箱标志 */
            emit logicPutImageSignal(4);
            qDebug().noquote()<<QString("Grab (double box) (back, left, right)[4-4}]");
        }
        else {
            /* 如果是长箱就触发长箱标志 */
            logicPutImageSignal(1);
            qDebug().noquote()<<QString("Grab (Long Box) (Back, Left, Right)[4-1]");
        }
    }

    isLong=false;
    isDouble=false;
}

void InfraredLogic_IO::delayAfterCaptureSlot()
{
    emit logicPutImageSignal(1);
    if(type==5){
        pTimerFront->start(10000);
    }
}

void InfraredLogic_IO::delayFrontCaptureSlot()
{
    emit logicPutImageSignal(-1);
    emit logicPutImageSignal(0);

    if(pTimerAfter->isActive()){/* 延时抓拍后面图片 */
        pTimerAfter->stop();
    }
    pTimerAfter->start(5000);
}

void InfraredLogic_IO::logicStateslot(int *state)
{
    lock.lockForWrite();
    logFile.open( QIODevice::Append | QIODevice::Text | QIODevice::Unbuffered );
    logFile.write(QString("%9: A1[%1] A2[%2] B1[%3] B2[%4] -  D1[%5] D2[%6] D3[%7] D4[%8]").arg(state[0]).arg(state[1]).arg(state[2]).arg(state[3]).arg(state[4]).arg(state[5]).arg(state[6]).arg(state[7]).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss zzz::")).toUtf8() );
    logFile.write( eol.toUtf8() );
    logFile.close();

    lock.unlock();
}

void InfraredLogic_IO::startSlaveSlot(const QString &portName1, const QString &portName2, const QString &address, int port,int model, int channelNum)
{
    Q_UNUSED(portName1)
    Q_UNUSED(portName2)

    if(address.isEmpty() || "..." == address || -1 == port){
        qCritical().noquote()<<QString("[%1] %2:The network relay address or port is incorrect").arg(this->metaObject()->className(),QString::number(channelNum));
        return;
    }

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
        start=false;
    }

    this->address=address;
    this->port=port;
    this->model=model;
    this->channelNum=channelNum;

    pCloseLEDTimer=new QTimer(this);
    /*****************************
    * @brief:延时关闭补光灯
    ******************************/
    connect(pCloseLEDTimer,&QTimer::timeout,this,&InfraredLogic_IO::timerCloseLEDSlot);

    if(1 == model){/* 服务器模式 */
        pTcpServer=new TcpServer (this);

        /* 绑定客户端数量 */
        connect(pTcpServer,&TcpServer::connectCountSignal,this,&InfraredLogic_IO::connectCountSlot);
        /* 红外状态 */
        connect(pTcpServer,&TcpServer::logicStatusSignal,this,&InfraredLogic_IO::logicStatusSignal);
        /* 红外状态写入日志 */
        connect(pTcpServer,&TcpServer::logicStatusSignal,this,&InfraredLogic_IO::logicStateslot);
        /* 逻辑判断 */
        connect(pTcpServer,&TcpServer::logicStatusSignal,this,&InfraredLogic_IO::serialLogicSlot);
        /* 服务端发送数据 */
        connect(this,&InfraredLogic_IO::signal_toSendData,pTcpServer,&TcpServer::toSendDataSlot);
        /* 释放资源 */
        connect(this,&InfraredLogic_IO::signal_releaseResources,pTcpServer,&TcpServer::releaseResourcesSlot);

        startListenSlot();
    }
    else if(0 == model){/* 客户端模式 */
        pTcpClient=new QTcpSocket();
        pTimerAutoLink=new QTimer(this);
        pTimerAutoLink->setSingleShot(true);

        connect(pTcpClient,&QIODevice::readyRead,this,&InfraredLogic_IO::receiveDataSlot);
        connect(pTcpClient,&QAbstractSocket::connected,this,&InfraredLogic_IO::connectedSlot);
        connect(pTcpClient,&QAbstractSocket::disconnected,this,&InfraredLogic_IO::disconnectedSlot);
        connect(pTcpClient,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this,&InfraredLogic_IO::displayErrorSlot);
        connect(pTimerAutoLink,&QTimer::timeout,this,&InfraredLogic_IO::startLinkSlot);

        /* 红外状态写入日志 */
        connect(this,&InfraredLogic_IO::logicStatusSignal,this,&InfraredLogic_IO::logicStateslot);
        /* 逻辑判断 */
        connect(this,&InfraredLogic_IO::logicStatusSignal,this,&InfraredLogic_IO::serialLogicSlot);

        startLinkSlot();
    }
    else{
        qCritical().noquote()<<QString("[%1] %2:%3  The network controller initialization mode is abnormal").arg(this->metaObject()->className(),address,QString::number(port));
    }
}

void InfraredLogic_IO::simulateTriggerSlot(int type)
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

void InfraredLogic_IO::setAlarmModeSlot(bool model,int logicType,double A1ReleasrCap)
{
    this->logicType=logicType;
    this->A1ReleasrCap=A1ReleasrCap;

    valueOne=0;    valueTwo=1;
    /* 常开(false) |常闭(true) */
    if(!model) {
        valueOne=1;valueTwo=0;
    }
}

void InfraredLogic_IO::DTypeOutSlot(QList<int> dType, int lifting)
{
    dOutType=dType;

    /*****************************
    * @brief:收到抬杆信号
    ******************************/
    if(lifting>0){
        for(int ind=0;ind<dOutType.size();ind++){
            if(0 == model && pTcpClient!=nullptr && dOutType.at(ind)==1){
                QString cmd=QString("AT+STACH%1=3,1%2").arg(QString::number(ind+1),eol);
                pTcpClient->write(cmd.toLatin1());

                qDebug().noquote()<<QString("[%1] %2:I got the lift signal. Lift is successful").arg(this->metaObject()->className(),QString::number(channelNum));
            }
            if(1 == model && pTcpServer!=nullptr && dOutType.at(ind)==1){
                QString cmd=QString("AT+STACH%1=3,1%2").arg(QString::number(ind+1),eol);
                emit signal_toSendData(channelNum,cmd);

                qDebug().noquote()<<QString("[%1] %2:I got the lift signal. Lift is successful").arg(this->metaObject()->className(),QString::number(channelNum));
            }
        }
    }
}

void InfraredLogic_IO::releaseResourcesSlot()
{
    isConnected=false;

    if(pTcpServer!=nullptr && pTcpServer->isListening()){
        emit signal_releaseResources();
        pTcpServer->close();
    }

    if(pTcpClient != nullptr && pTcpClient->isOpen()){
        pTcpClient->disconnected();
        pTcpClient->close();
        pTcpClient->abort();
    }

//    if(pTimerFront!=nullptr){
//        pTimerFront->stop();
//    }

//    if(pTimerAfter!=nullptr){
//        pTimerAfter->stop();
//    }

    if(pCloseLEDTimer!=nullptr){
        pCloseLEDTimer->stop();
    }

    if(pTimerAutoLink!=nullptr){
        pTimerAutoLink->stop();
    }

    qDebug().noquote()<<QString("[%1] releaseResourcesSlot").arg(this->metaObject()->className());
}

void InfraredLogic_IO::connectCountSlot(int count)
{
    if(count>0){
        emit serialPortStateSignal(false,false,true);
    }
    else {
        emit serialPortStateSignal(false,false,false);
    }
}

/* socket */

void InfraredLogic_IO::startLinkSlot()
{
    if(!isConnected){
        pTcpClient->close();
        pTcpClient->abort();
        pTcpClient->connectToHost(address,port);
    }
}

void InfraredLogic_IO::startListenSlot()
{
    if(!pTcpServer->listen(QHostAddress(address),port)){/* 服务器使用本机地址 */
        qWarning().noquote()<<QString("[%1] %2:%3 listen error<errocCode=%4>").arg(this->metaObject()->className(),address,QString::number(port),pTcpServer->errorString());
    }
    else {
        qDebug().noquote()<<QString("[%1] %2:%3 Start listen.").arg(this->metaObject()->className(),address,QString::number(port));
    }
}

void InfraredLogic_IO::connectedSlot()
{
    isConnected=true;

    emit serialPortStateSignal(false,false,true);

    qDebug().noquote()<<QString("[%1] %2:%3 link successful").arg(this->metaObject()->className(),address,QString::number(port));
}

void InfraredLogic_IO::receiveDataSlot()
{
    QByteArray buf=pTcpClient->readAll();

    /*****************************
    * @brief:数据流
    ******************************/
    if(buf.trimmed().startsWith('+')){
        /*****************************
        * @brief:红外信号
        ******************************/
        if(buf.startsWith("+OCCH_ALL:")){
            int pos=buf.indexOf(":")+1;
            tmpStatus[0]=buf.at(pos)-'0';
            tmpStatus[1]=buf.at(pos+2)-'0';
            tmpStatus[2]=buf.at(pos+4)-'0';
            tmpStatus[3]=buf.at(pos+6)-'0';

            //serialLogicSlot(status); /* 逻辑判断 */
            emit logicStatusSignal(tmpStatus);
        }
        else if(buf.startsWith("+OCCH")){
            QList<QByteArray> data= buf.split('+');
            foreach (QByteArray arr, data) {
                int pos=arr.indexOf(":");
                if(-1 != pos && arr.startsWith("OCCH")){
                    if(arr.at(pos-1)=='1'){
                        tmpStatus[0]=arr.at(pos+1)-'0';
                    }
                    if(arr.at(pos-1)=='2'){
                        tmpStatus[1]=arr.at(pos+1)-'0';
                    }
                    if(arr.at(pos-1)=='3'){
                        tmpStatus[2]=arr.at(pos+1)-'0';
                    }
                    if(arr.at(pos-1)=='4'){
                        tmpStatus[3]=arr.at(pos+1)-'0';

                        //serialLogicSlot(status); /* 逻辑判断 */
                        emit logicStatusSignal(tmpStatus);
                    }
                }
            }
        }
        else if(buf.startsWith("+STACH")){
            /*****************************
            * @brief:网络控制器输出信号
            ******************************/
            QList<QByteArray> data= buf.split('+');
            foreach (QByteArray arr, data) {
                int pos=arr.indexOf(":");
                if(-1 != pos && arr.startsWith("STACH")){
                    int ind=arr.at(pos-1)-'0';
                    tmpStatus[ind+3]=arr.at(pos+1)-'0';
                    emit logicStatusSignal(tmpStatus);
                }
            }
        }
    }
    else {
        QList<QByteArray> data= buf.split('+');

        foreach (QByteArray arr, data) {
            if(arr.trimmed()==QString("CC_ZBY")){
                /*****************************
                * @brief:初始化查询一次输入状态
                ******************************/
                pTcpClient->write(QString("AT+OCCH0=?%1").arg(eol).toLatin1());
            }
            if(arr.trimmed()=="[H]"){
                pTcpClient->write(QString("AT+ACK%1").arg(eol).toLatin1());
            }
            if(arr.startsWith("OCCH_ALL:")){
                int pos=arr.indexOf(":")+1;
                if(-1 != pos){
                    tmpStatus[0]=arr.at(pos)-'0';
                    tmpStatus[1]=arr.at(pos+2)-'0';
                    tmpStatus[2]=arr.at(pos+4)-'0';
                    tmpStatus[3]=arr.at(pos+6)-'0';

                    //serialLogicSlot(status); /* 逻辑判断 */
                    emit logicStatusSignal(tmpStatus);
                }
            }
            else if(buf.startsWith("STACH")){
                /*****************************
                * @brief:网络控制器输出信号
                ******************************/
                int pos=arr.indexOf(":");
                if(-1 != pos){
                    int ind=arr.at(pos-1)-'0';
                    tmpStatus[ind+3]=arr.at(pos+1)-'0';
                    emit logicStatusSignal(tmpStatus);
                }
            }
        }
    }

    buf.clear();
}

void InfraredLogic_IO::disconnectedSlot()
{
    isConnected=false;

    emit serialPortStateSignal(false,false,false);
}

void InfraredLogic_IO::displayErrorSlot(QAbstractSocket::SocketError socketError)
{
    isConnected=false;

    emit serialPortStateSignal(false,false,false);

    pTimerAutoLink->start(10000);

    qWarning().noquote()<<QString("[%1] %2:%3  link error<errorCode=%4>").arg(this->metaObject()->className(),address,QString::number(port),QString::number(socketError));
}
