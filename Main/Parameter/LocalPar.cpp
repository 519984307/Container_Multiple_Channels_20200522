#if _MSC_VER >=1600    // MSVC2015>1899,对于MSVC2010以上版本都可以使用
#pragma execution_character_set("utf-8")
#endif

#include "LocalPar.h"

namespace LocalPar {
    QString App="ZBYCS";
    QString version=QString("%1_%2").arg(APP_VERSION,APP_CHANNEL);
    QString copyright="ZBYCS";
    QString msg="集装箱号码识别系统";
    QString proName=QString(APP_PROJECT);
    int Channels = 2;
    QString DogID=QString(DOG_ID);
    /*****************************
    * @brief:箱号相机：前，后，左，右，顶，车头，车尾,车牌
    ******************************/
    QStringList CamerNameList={"Front","Before","Left","Right","Top","Prospects","Foreground","Plate"};
    int CamerNumber=7;/* 不包含车牌 */
    QStringList DeviceStateList={"Front","Before","Left","Right","Top","Prospects","Foreground","Plate","Serial1","Serial2","IO","A1","A2","B1","B2","D1","D2","D3","D4","Con1","Con2","Plate","Msg"};

    equipmentEnum equipment=equipmentEnum::Front;

    #ifdef Q_OS_LINUX
    #endif
    #ifdef Q_OS_WIN
    #endif
}
