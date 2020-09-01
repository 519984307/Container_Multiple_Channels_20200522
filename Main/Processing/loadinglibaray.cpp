#include "loadinglibaray.h"

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

LoadingLibaray::LoadingLibaray(int ChannelNumber, QObject *parent) : QObject(parent)
{
    this->setParent(parent);

    QDir pluginsDir(QCoreApplication::applicationDirPath());

    /*  创建插件目录  */
    const QString pluginPath="Plugins";
    pluginsDir.mkdir(pluginPath);
    pluginsDir.cd(pluginPath);

    const QString path=pluginsDir.path();

    for(const QString &fileName :pluginsDir.entryList(QDir::Files)){
        QPluginLoader  pluginLoader(pluginsDir.absoluteFilePath(fileName));       
        QObject *plugin = pluginLoader.instance();

        if(plugin){
            qDebug()<<fileName;
            const QString pluginName=fileName.split(".")[0];
            /*  创建子插件目录 */
            pluginsDir.mkdir(pluginName);
            pluginsDir.cd(pluginName);
            /*  删除旧插件   */
            for(QFileInfo file :pluginsDir.entryInfoList()){
                if(file.isFile()){
                    file.dir().remove(file.fileName());
                }
            }

            /*****************************
            * @brief: 插件数量
            ******************************/
            int pluginsNum=0;

            if(ICaptureImagesHCNET *pICaptureImagesHCNET=qobject_cast<ICaptureImagesHCNET*>(plugin)){
                pluginsNum=ChannelNumber*5;

                delete pICaptureImagesHCNET;
                pICaptureImagesHCNET=nullptr;
            }
            else if (InfraredLogic_Interface *pInfraredLogic_Interface=qobject_cast<InfraredLogic_Interface*>(plugin)) {
                pluginsNum=ChannelNumber;

                delete pICaptureImagesHCNET;
                pICaptureImagesHCNET=nullptr;
            }
            else if (ICaptureImagesTCP *pICaptureImagesTCP=qobject_cast<ICaptureImagesTCP*>(plugin)) {
                pluginsNum=ChannelNumber*5;

                delete pICaptureImagesHCNET;
                pICaptureImagesHCNET=nullptr;
            }
            else {
                delete plugin;
                plugin=nullptr;
            }

            for(int i=1;i<=pluginsNum;i++){
                  QFile::copy(QDir::toNativeSeparators(QString("%1/%2").arg(path).arg(fileName)),QDir::toNativeSeparators(QString("%1/%2_%3").arg(pluginsDir.absolutePath()).arg(i).arg(fileName)));
            }

            pluginsDir.cdUp();
            qDebug()<< pluginLoader.unload();
        }
    }
}
