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
                               Before=1,             /* 后相机 */
                               Left=2,             /* 左相机 */
                               Right=3,             /* 右相机 */
                               Top=4,             /* 顶相机 */
                               Prospects=5,            /* 前景相机 */
                               Foreground=6,            /* 后景相机 */
                               Plate=7,             /* 车牌相机 */
                               Serial1=8,            /* 串口1 */
                               Serial2=9,            /* 串口2 */
                               A1=10,             /* 红外A1 */
                               A2=11,             /* 红外A2 */
                               B1=12,             /* 红外B1 */
                               B2=13,             /* 红外B2 */
                               D1=14,             /* 红外D1 */
                               D2=15,             /* 红外D2 */
                               D3=16,             /* 红外D3 */
                               D4=17,             /* 红外D4 */
                               Con1=18,            /* 前箱号 */
                               Con2=19,            /* 后箱号 */
                               Plate1=20,          /* 车牌 */
                               Msg=21             /* 日志信息 */
                           };

    extern equipmentEnum equipment;
}

#endif // LOCALPAR_H
