#ifndef LOADINGLIBARAY_H
#define LOADINGLIBARAY_H

#include <QObject>
#include <QDir>
#include <QPluginLoader>
#include <QCoreApplication>
#include <QMessageLogger>
#include <QPointer>



class LoadingLibaray : public QObject
{
    Q_OBJECT

public:

    ///
    /// \brief LoadingLibaray 创建插件
    /// \param ChannelNumber 通道数量
    /// \param parent
    ///
    explicit LoadingLibaray(int ChannelNumber,QObject *parent = nullptr);

private:

    ///
    /// \brief processingPlugins 加载插件到内存
    /// \param pluginPath 插件路径
    ///
    void processingPlugins(QDir pluginPath);

signals:

};

#endif // LOADINGLIBARAY_H
