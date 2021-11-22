#include "tcpclient.h"

TcpClient::TcpClient(QObject *parent):QTcpSocket(parent)
{
    this->setParent(parent);

    memset(tmpStatus,0,sizeof (tmpStatus));

#ifdef Q_OS_LINUX
    eol = "\n";
#endif
#ifdef Q_OS_WIN
    eol = "\r\n";
#endif
}

void TcpClient::receiveDataSlot()
{
    QByteArray buf=readAll();

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
                this->write(QString("AT+OCCH0=?%1").arg(eol).toLatin1());
            }
            if(arr.trimmed()=="[H]"){
                /*****************************
                * @brief:心跳包
                ******************************/
                this->write(QString("AT+ACK%1").arg(eol).toLatin1());
            }
            if(arr.startsWith("OCCH_ALL:")){
                int pos=arr.indexOf(":")+1;
                if(-1 != pos){
                    tmpStatus[0]=arr.at(pos)-'0';
                    tmpStatus[1]=arr.at(pos+2)-'0';
                    tmpStatus[2]=arr.at(pos+4)-'0';
                    tmpStatus[3]=arr.at(pos+6)-'0';

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
