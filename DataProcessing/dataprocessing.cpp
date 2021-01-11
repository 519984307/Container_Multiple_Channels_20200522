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

void DataProcessing::slot_sendDataToLog(int channel_number, const QString &result)
{

}

void DataProcessing::slot_containerResult(int channel, const QString &result)
{
    emit signal_toSendData(channel,result);
}
