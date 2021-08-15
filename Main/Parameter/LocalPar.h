#ifndef LOCALPAR_H
#define LOCALPAR_H

#include <QString>
#include <QStringList>

namespace LocalPar {
    extern QString App;
    extern QString version;
    extern QString copyright;
    extern QString msg;
    extern int Channels;
    extern int CamerNumber;
    extern QStringList CamerNameList;
    extern QStringList DeviceStateList;
    extern QString DogID;
    extern QString proName;

    enum equipmentEnum{        Front=0,             /* 前相机 */
                               Before,             /* 后相机 */
                               Left,             /* 左相机 */
                               Right,             /* 右相机 */
                               Top,             /* 顶相机 */
                               Prospects,            /* 前景相机 */
                               Foreground,            /* 后景相机 */
                               Plate,             /* 车牌相机 */
                               Serial1,            /* 串口1 */
                               Serial2,            /* 串口2 */
                               IO,               /* 网络控制器 */
                               A1,             /* 红外A1 */
                               A2,             /* 红外A2 */
                               B1,             /* 红外B1 */
                               B2,             /* 红外B2 */
                               D1,             /* 红外D1 */
                               D2,             /* 红外D2 */
                               D3,             /* 红外D3 */
                               D4,             /* 红外D4 */
                               Con1,            /* 前箱号 */
                               Con2,            /* 后箱号 */
                               Plate1,          /* 车牌 */
                               Msg             /* 日志信息 */
                           };

    extern equipmentEnum equipment;
}

#endif // LOCALPAR_H
