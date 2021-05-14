/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MainWindow/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[66];
    char stringdata0[1080];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 35), // "initializesTheDeviceStateList..."
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 5), // "count"
QT_MOC_LITERAL(4, 54, 9), // "rowLabels"
QT_MOC_LITERAL(5, 64, 21), // "setDeviceStatusSignal"
QT_MOC_LITERAL(6, 86, 7), // "channel"
QT_MOC_LITERAL(7, 94, 9), // "equipment"
QT_MOC_LITERAL(8, 104, 5), // "state"
QT_MOC_LITERAL(9, 110, 20), // "signal_createLibaray"
QT_MOC_LITERAL(10, 131, 18), // "signal_setAlarmMsg"
QT_MOC_LITERAL(11, 150, 3), // "num"
QT_MOC_LITERAL(12, 154, 3), // "msg"
QT_MOC_LITERAL(13, 158, 20), // "signal_initEquipment"
QT_MOC_LITERAL(14, 179, 23), // "signal_destructorThread"
QT_MOC_LITERAL(15, 203, 23), // "signal_releaseResources"
QT_MOC_LITERAL(16, 227, 20), // "signal_initDataBaseR"
QT_MOC_LITERAL(17, 248, 11), // "connectName"
QT_MOC_LITERAL(18, 260, 4), // "user"
QT_MOC_LITERAL(19, 265, 4), // "pass"
QT_MOC_LITERAL(20, 270, 2), // "ip"
QT_MOC_LITERAL(21, 273, 12), // "dataBaseType"
QT_MOC_LITERAL(22, 286, 33), // "signal_InitializationFTPParam..."
QT_MOC_LITERAL(23, 320, 4), // "path"
QT_MOC_LITERAL(24, 325, 4), // "host"
QT_MOC_LITERAL(25, 330, 4), // "port"
QT_MOC_LITERAL(26, 335, 27), // "signal_setCameraCaptureType"
QT_MOC_LITERAL(27, 363, 7), // "capType"
QT_MOC_LITERAL(28, 371, 14), // "msgCallBackInd"
QT_MOC_LITERAL(29, 386, 26), // "signal_setPlateCaptureType"
QT_MOC_LITERAL(30, 413, 24), // "signal_setDataBaseFilter"
QT_MOC_LITERAL(31, 438, 6), // "filter"
QT_MOC_LITERAL(32, 445, 16), // "systemTrayAction"
QT_MOC_LITERAL(33, 462, 19), // "systemTrayTriggered"
QT_MOC_LITERAL(34, 482, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(35, 516, 6), // "reason"
QT_MOC_LITERAL(36, 523, 18), // "actionTiggeredSlot"
QT_MOC_LITERAL(37, 542, 37), // "on_actionParameter_Settings_t..."
QT_MOC_LITERAL(38, 580, 30), // "on_actionCamera_Test_triggered"
QT_MOC_LITERAL(39, 611, 33), // "on_actionHistory_Sqlite_trigg..."
QT_MOC_LITERAL(40, 645, 27), // "on_actionData_log_triggered"
QT_MOC_LITERAL(41, 673, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(42, 697, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(43, 722, 19), // "slot_handleFinished"
QT_MOC_LITERAL(44, 742, 25), // "slot_progressRangeChanged"
QT_MOC_LITERAL(45, 768, 7), // "minimum"
QT_MOC_LITERAL(46, 776, 7), // "maximum"
QT_MOC_LITERAL(47, 784, 24), // "slot_progressTextChanged"
QT_MOC_LITERAL(48, 809, 12), // "progressText"
QT_MOC_LITERAL(49, 822, 25), // "slot_progressValueChanged"
QT_MOC_LITERAL(50, 848, 13), // "progressValue"
QT_MOC_LITERAL(51, 862, 10), // "slot_Error"
QT_MOC_LITERAL(52, 873, 10), // "pluginName"
QT_MOC_LITERAL(53, 884, 18), // "slot_hideErrorForm"
QT_MOC_LITERAL(54, 903, 19), // "slot_theFtpProgress"
QT_MOC_LITERAL(55, 923, 9), // "bytesSent"
QT_MOC_LITERAL(56, 933, 10), // "bytesTotal"
QT_MOC_LITERAL(57, 944, 21), // "slot_getDiskFreeSpace"
QT_MOC_LITERAL(58, 966, 17), // "slot_connectCount"
QT_MOC_LITERAL(59, 984, 20), // "slot_statisticalData"
QT_MOC_LITERAL(60, 1005, 5), // "total"
QT_MOC_LITERAL(61, 1011, 7), // "correct"
QT_MOC_LITERAL(62, 1019, 5), // "error"
QT_MOC_LITERAL(63, 1025, 11), // "statistical"
QT_MOC_LITERAL(64, 1037, 22), // "slot_trafficStatistics"
QT_MOC_LITERAL(65, 1060, 19) // "slot_systemRunTimer"

    },
    "MainWindow\0initializesTheDeviceStateListSignal\0"
    "\0count\0rowLabels\0setDeviceStatusSignal\0"
    "channel\0equipment\0state\0signal_createLibaray\0"
    "signal_setAlarmMsg\0num\0msg\0"
    "signal_initEquipment\0signal_destructorThread\0"
    "signal_releaseResources\0signal_initDataBaseR\0"
    "connectName\0user\0pass\0ip\0dataBaseType\0"
    "signal_InitializationFTPParameter\0"
    "path\0host\0port\0signal_setCameraCaptureType\0"
    "capType\0msgCallBackInd\0"
    "signal_setPlateCaptureType\0"
    "signal_setDataBaseFilter\0filter\0"
    "systemTrayAction\0systemTrayTriggered\0"
    "QSystemTrayIcon::ActivationReason\0"
    "reason\0actionTiggeredSlot\0"
    "on_actionParameter_Settings_triggered\0"
    "on_actionCamera_Test_triggered\0"
    "on_actionHistory_Sqlite_triggered\0"
    "on_actionData_log_triggered\0"
    "on_actionExit_triggered\0"
    "on_actionAbout_triggered\0slot_handleFinished\0"
    "slot_progressRangeChanged\0minimum\0"
    "maximum\0slot_progressTextChanged\0"
    "progressText\0slot_progressValueChanged\0"
    "progressValue\0slot_Error\0pluginName\0"
    "slot_hideErrorForm\0slot_theFtpProgress\0"
    "bytesSent\0bytesTotal\0slot_getDiskFreeSpace\0"
    "slot_connectCount\0slot_statisticalData\0"
    "total\0correct\0error\0statistical\0"
    "slot_trafficStatistics\0slot_systemRunTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      34,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  184,    2, 0x06 /* Public */,
       5,    3,  189,    2, 0x06 /* Public */,
       9,    0,  196,    2, 0x06 /* Public */,
      10,    2,  197,    2, 0x06 /* Public */,
      13,    0,  202,    2, 0x06 /* Public */,
      14,    0,  203,    2, 0x06 /* Public */,
      15,    0,  204,    2, 0x06 /* Public */,
      16,    5,  205,    2, 0x06 /* Public */,
      22,    5,  216,    2, 0x06 /* Public */,
      22,    4,  227,    2, 0x26 /* Public | MethodCloned */,
      26,    2,  236,    2, 0x06 /* Public */,
      29,    2,  241,    2, 0x06 /* Public */,
      30,    1,  246,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      32,    0,  249,    2, 0x08 /* Private */,
      33,    1,  250,    2, 0x08 /* Private */,
      36,    0,  253,    2, 0x08 /* Private */,
      37,    0,  254,    2, 0x08 /* Private */,
      38,    0,  255,    2, 0x08 /* Private */,
      39,    0,  256,    2, 0x08 /* Private */,
      40,    0,  257,    2, 0x08 /* Private */,
      41,    0,  258,    2, 0x08 /* Private */,
      42,    0,  259,    2, 0x08 /* Private */,
      43,    0,  260,    2, 0x08 /* Private */,
      44,    2,  261,    2, 0x08 /* Private */,
      47,    1,  266,    2, 0x08 /* Private */,
      49,    1,  269,    2, 0x08 /* Private */,
      51,    1,  272,    2, 0x08 /* Private */,
      53,    0,  275,    2, 0x08 /* Private */,
      54,    2,  276,    2, 0x08 /* Private */,
      57,    0,  281,    2, 0x08 /* Private */,
      58,    1,  282,    2, 0x08 /* Private */,
      59,    4,  285,    2, 0x08 /* Private */,
      64,    1,  294,    2, 0x08 /* Private */,
      65,    0,  297,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QStringList,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    6,    7,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,   17,   18,   19,   20,   21,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,   18,   19,   23,   24,   25,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   18,   19,   23,   24,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   27,   28,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   27,   28,
    QMetaType::Void, QMetaType::QString,   31,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 34,   35,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   45,   46,
    QMetaType::Void, QMetaType::QString,   48,
    QMetaType::Void, QMetaType::Int,   50,
    QMetaType::Void, QMetaType::QString,   52,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   55,   56,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double,   60,   61,   62,   63,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initializesTheDeviceStateListSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 1: _t->setDeviceStatusSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 2: _t->signal_createLibaray(); break;
        case 3: _t->signal_setAlarmMsg((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->signal_initEquipment(); break;
        case 5: _t->signal_destructorThread(); break;
        case 6: _t->signal_releaseResources(); break;
        case 7: _t->signal_initDataBaseR((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const int(*)>(_a[5]))); break;
        case 8: _t->signal_InitializationFTPParameter((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const int(*)>(_a[5]))); break;
        case 9: _t->signal_InitializationFTPParameter((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 10: _t->signal_setCameraCaptureType((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 11: _t->signal_setPlateCaptureType((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 12: _t->signal_setDataBaseFilter((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->systemTrayAction(); break;
        case 14: _t->systemTrayTriggered((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 15: _t->actionTiggeredSlot(); break;
        case 16: _t->on_actionParameter_Settings_triggered(); break;
        case 17: _t->on_actionCamera_Test_triggered(); break;
        case 18: _t->on_actionHistory_Sqlite_triggered(); break;
        case 19: _t->on_actionData_log_triggered(); break;
        case 20: _t->on_actionExit_triggered(); break;
        case 21: _t->on_actionAbout_triggered(); break;
        case 22: _t->slot_handleFinished(); break;
        case 23: _t->slot_progressRangeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 24: _t->slot_progressTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 25: _t->slot_progressValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->slot_Error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 27: _t->slot_hideErrorForm(); break;
        case 28: _t->slot_theFtpProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 29: _t->slot_getDiskFreeSpace(); break;
        case 30: _t->slot_connectCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->slot_statisticalData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 32: _t->slot_trafficStatistics((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->slot_systemRunTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(int , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::initializesTheDeviceStateListSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int , int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::setDeviceStatusSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signal_createLibaray)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signal_setAlarmMsg)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signal_initEquipment)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signal_destructorThread)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signal_releaseResources)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & , const QString & , const QString & , const QString & , const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signal_initDataBaseR)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & , const QString & , const QString & , const QString & , const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signal_InitializationFTPParameter)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const int & , const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signal_setCameraCaptureType)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const int & , const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signal_setPlateCaptureType)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signal_setDataBaseFilter)) {
                *result = 12;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 34)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 34;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 34)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 34;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::initializesTheDeviceStateListSignal(int _t1, QStringList _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::setDeviceStatusSignal(int _t1, int _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::signal_createLibaray()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::signal_setAlarmMsg(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::signal_initEquipment()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MainWindow::signal_destructorThread()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void MainWindow::signal_releaseResources()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void MainWindow::signal_initDataBaseR(const QString & _t1, const QString & _t2, const QString & _t3, const QString & _t4, const int & _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainWindow::signal_InitializationFTPParameter(const QString & _t1, const QString & _t2, const QString & _t3, const QString & _t4, const int & _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 10
void MainWindow::signal_setCameraCaptureType(const int & _t1, const int & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void MainWindow::signal_setPlateCaptureType(const int & _t1, const int & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void MainWindow::signal_setDataBaseFilter(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
