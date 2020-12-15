#if _MSC_VER >=1600    // MSVC2015>1899,对于MSVC2010以上版本都可以使用
#pragma execution_character_set("utf-8")
#endif

#include "LocalPar.h"

namespace LocalPar {
    QString App="ContainerMultiple";
    QString version="1.0.0.2012091107_BUILD-SNAPSHOT";
    QString copyright="深圳众百源科技有限公司";
    QString msg="集装箱号码识别系统";
    int Channels =10;
    /*****************************
    * @brief:箱号相机：前，后，左，右，顶，车牌，车头，车尾
    ******************************/
    QStringList CamerNameList={"Front","Before","Left","Right","Top","Prospects","Foreground","Plate"};
    int CamerNumber=7;/* 不包含车牌 */

    #ifdef Q_OS_LINUX
    #endif
    #ifdef Q_OS_WIN
    #endif
}
