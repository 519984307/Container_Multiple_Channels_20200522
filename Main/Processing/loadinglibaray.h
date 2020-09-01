#ifndef LOADINGLIBARAY_H
#define LOADINGLIBARAY_H

#include <QObject>
#include <QDir>
#include <QPluginLoader>
#include <QDebug>
#include <QCoreApplication>

class LoadingLibaray : public QObject
{
    Q_OBJECT
public:
    explicit LoadingLibaray(int ChannelNumber,QObject *parent = nullptr);

signals:

};

#endif // LOADINGLIBARAY_H
