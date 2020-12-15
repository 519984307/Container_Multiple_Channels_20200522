#ifndef PLUGINPROCESSING_H
#define PLUGINPROCESSING_H

#include "PluginProcessing_global.h"

#include "Interface/ICaptureImagesHCNET.h"
#include "Interface/ICaptureImagesTCP.h"
#include "Interface/ITheLicensePlateHCNET.h"
#include "Interface/ITheLicensePlateWTY.h"
#include "Interface/databaseread_interface.h"
#include "Interface/databasewrite_interface.h"
#include "Interface/datainterchange_interface.h"
#include "Interface/encryption_interface.h"
#include "Interface/infraredlogic_interface.h"
#include "Interface/recognizer_interface.h"
#include "Interface/thedataanalysis_interface.h"

#include <QObject>

class PLUGINPROCESSING_EXPORT PluginProcessing:public QObject
{
    Q_OBJECT

public:
    PluginProcessing(int ChannelNumber,QObject *parent = nullptr);

    ~PluginProcessing();

private:

    ///
    /// \brief processingPlugins 加载插件到内存
    /// \param pluginPath 插件路径
    ///
    void processingPlugins(QDir pluginPath);


public slots:

    ///
    /// \brief setConCameraProtocolModeSlot 设置相机协议模式
    /// \param protocol
    ///
    void setConCameraProtocolModeSlot(QMultiMap<int,QMap<int,int>> protocol);

private slots:

signals:

};

#endif // PLUGINPROCESSING_H
