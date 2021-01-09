#include "dataprocessing.h"

DataProcessing::DataProcessing(QObject *parent) : QObject(parent)
{

}

void DataProcessing::slot_linkState(const QString &address, bool state)
{

}

void DataProcessing::slot_connectCount(int count)
{

}

void DataProcessing::slot_toSendData(int channel_number, const QString &result)
{

}

void DataProcessing::slot_setHeartbeatPackState(bool state)
{

}

void DataProcessing::slot_sendResult(int channel, const QString &result)
{
    emit signal_toSendData(channel,result);
}
