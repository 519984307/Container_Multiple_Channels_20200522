#include "pluginprocessing.h"

PluginProcessing::PluginProcessing(int ChannelNumber, QObject *parent)
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

            if(ICaptureImagesHCNET *pICaptureImagesHCNET=static_cast<ICaptureImagesHCNET*>(plugin)){
                /*****************************
                * @brief:箱号相机：前，后，左，右，顶，车头，车尾
                ******************************/
                pluginsNum=ChannelNumber*7;

                delete pICaptureImagesHCNET;
                pICaptureImagesHCNET=nullptr;
            }
            else if (ICaptureImagesTCP *pICaptureImagesTCP=qobject_cast<ICaptureImagesTCP*>(plugin)) {
                pluginsNum=ChannelNumber*7;

                delete pICaptureImagesTCP;
                pICaptureImagesTCP=nullptr;
            }
            else if (InfraredLogic_Interface *pInfraredLogic_Interface=qobject_cast<InfraredLogic_Interface*>(plugin)) {
                pluginsNum=ChannelNumber;

                delete pInfraredLogic_Interface;
                pInfraredLogic_Interface=nullptr;
            }
            else {
                delete plugin;
                plugin=nullptr;
            }

            for(int i=1;i<=pluginsNum;i++){
                  QFile::copy(QDir::toNativeSeparators(QString("%1/%2").arg(path).arg(fileName)),QDir::toNativeSeparators(QString("%1/%2_%3").arg(pluginsDir.absolutePath()).arg(i).arg(fileName)));
            }

            processingPlugins(pluginsDir);

            pluginsDir.cdUp();
        }
        pluginLoader.unload();
    }
}

PluginProcessing::~PluginProcessing()
{

}

void PluginProcessing::processingPlugins(QDir pluginPath)
{
    const QStringList entryList=pluginPath.entryList(QDir::Files);
    for(QString pluginName:entryList){
        QPluginLoader  pluginLoader(pluginPath.absoluteFilePath(pluginName));
        QObject* plugin = pluginLoader.instance();

        if(plugin){
            if(ICaptureImagesHCNET* pICaptureImagesHCNET=qobject_cast<ICaptureImagesHCNET*>(plugin)){

            }
        }else{
            delete plugin;
            plugin=nullptr;
        }
    }/*
    QMap<QString, QPluginLoader*>::iterator iter = plugin_map.find(plugin_guid);
    if (iter == plugin_map.end()) {
        return false;
    }

    iter.value()->unload();
    plugin_map.erase(iter);

    return true;
    */
}

void PluginProcessing::setConCameraProtocolModeSlot(QMultiMap<int, QMap<int, int> > protocol)
{

}
