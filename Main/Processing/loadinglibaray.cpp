#include "loadinglibaray.h"
#include <QtDebug>

LoadingLibaray::LoadingLibaray(int ChannelNumber, QObject *parent) : QObject(parent)
{
    channelCount=ChannelNumber;
}

void LoadingLibaray::slot_destructorThread()
{
    foreach (auto thread, tdList) {
        thread->quit();
        thread->wait();
    }
}

void LoadingLibaray::slot_createLibaray()
{
    QDir pluginsDir(QCoreApplication::applicationDirPath());

    /*  创建插件目录  */
    const QString pluginPath="Plugins";
    pluginsDir.mkdir(pluginPath);
    pluginsDir.cd(pluginPath);

    const QString path=pluginsDir.path();

    /*****************************
    * @brief: 插件数量
    ******************************/
    int pluginsNum=0;

    /*****************************
    * @brief:删除非插件类文件夹
    ******************************/
    for(const QString fileName :pluginsDir.entryList(QDir::Dirs|QDir::NoDotAndDotDot)){
        if("HCNetSDK"!=fileName && "OLD"!=fileName){
            QDir dir(QDir::toNativeSeparators(path+"/"+fileName));
            dir.removeRecursively();
        }
    }

    /*****************************
    * @brief:加载插件名称，判断同一接口是否重复加载
    ******************************/
    QVector<QString> loadVec;

    for(const QString fileName :pluginsDir.entryList(QDir::Files,QDir::Name)){
        QPluginLoader  pluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();

        if(plugin){

            const QString pluginName=fileName.split(".").at(0);
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
            pluginsNum=0;

            bool isErr=false;

            if(ICaptureImages *pICaptureImages=qobject_cast<ICaptureImages*>(plugin)){
                delete pICaptureImages;
                pICaptureImages=nullptr;
                pluginsNum=channelCount*LocalPar::CamerNumber;

                if(-1!=loadVec.indexOf("ICaptureImages")){
                    isErr=true;
                }
                else {
                    loadVec.append("ICaptureImages");
                }
            }
            else if(IMiddleware *pIMiddleware=qobject_cast<IMiddleware*>(plugin)) {
                delete pIMiddleware;
                pIMiddleware=nullptr;
                pluginsNum=1;

                if(-1!=loadVec.indexOf("IMiddleware")){
                    isErr=true;
                }
                else {
                    loadVec.append("IMiddleware");
                }
            }

            if(isErr){
                emit signal_loadPluginError(fileName);
            }

            for(int i=1;i<=pluginsNum;i++){
                  QFile::copy(QDir::toNativeSeparators(QString("%1/%2").arg(path).arg(fileName)),QDir::toNativeSeparators(QString("%1/%2_%3").arg(pluginsDir.absolutePath()).arg(i).arg(fileName)));
            }
            if(pluginsNum>0){
                processingPlugins(pluginsDir);
            }

            pluginsDir.cdUp();
            pluginLoader.unload();
        }       
    }

    emit signal_handleFinished();
}

void LoadingLibaray::processingPlugins(QDir pluginPath)
{
    emit signal_progressRangeChanged(0,pluginPath.entryList(QDir::Files).count());
    int val=1;

    const QStringList entryList=pluginPath.entryList(QDir::Files);
    for(QString pluginName:entryList){

        emit signal_progressValueChanged(val++);
        emit signal_progressTextChanged(pluginName);

        QPluginLoader  pluginLoader(pluginPath.absoluteFilePath(pluginName));
        QObject* plugin = pluginLoader.instance();

        if(plugin){
            if(ICaptureImages *pICaptureImages=qobject_cast<ICaptureImages*>(plugin)){
                QThread *th=new QThread(this);
                tdList.append(th);
                pICaptureImages->moveToThread(th);
                th->start();
                ICaptureImagesLit.append(QSharedPointer<ICaptureImages>(pICaptureImages));
            }
            else if(IMiddleware *pIMiddleware=qobject_cast<IMiddleware*>(plugin)) {

                QThread *th=new QThread(this);
                tdList.append(th);
                pIMiddleware->moveToThread(th);
                th->start();
                IMiddlewareLit.append(QSharedPointer<IMiddleware>(pIMiddleware));
            }
            else {
                pluginLoader.unload();
            }
        }
        else{
            pluginLoader.unload();
        }
    }
}
