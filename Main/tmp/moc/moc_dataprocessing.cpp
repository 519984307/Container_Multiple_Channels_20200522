/****************************************************************************
** Meta object code from reading C++ file 'dataprocessing.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DataProcessing/dataprocessing.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dataprocessing.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataProcessing_t {
    QByteArrayData data[30];
    char stringdata0[364];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataProcessing_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataProcessing_t qt_meta_stringdata_DataProcessing = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DataProcessing"
QT_MOC_LITERAL(1, 15, 30), // "signal_InitializationParameter"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 7), // "address"
QT_MOC_LITERAL(4, 55, 4), // "port"
QT_MOC_LITERAL(5, 60, 11), // "serviceType"
QT_MOC_LITERAL(6, 72, 9), // "heartBeat"
QT_MOC_LITERAL(7, 82, 11), // "serviceMode"
QT_MOC_LITERAL(8, 94, 9), // "shortLink"
QT_MOC_LITERAL(9, 104, 7), // "newline"
QT_MOC_LITERAL(10, 112, 17), // "signal_toSendData"
QT_MOC_LITERAL(11, 130, 14), // "channel_number"
QT_MOC_LITERAL(12, 145, 4), // "data"
QT_MOC_LITERAL(13, 150, 24), // "signal_trafficStatistics"
QT_MOC_LITERAL(14, 175, 5), // "state"
QT_MOC_LITERAL(15, 181, 24), // "signal_pollsForCarStatus"
QT_MOC_LITERAL(16, 206, 4), // "type"
QT_MOC_LITERAL(17, 211, 20), // "signal_sendToDisplay"
QT_MOC_LITERAL(18, 232, 3), // "msg"
QT_MOC_LITERAL(19, 236, 20), // "slot_containerResult"
QT_MOC_LITERAL(20, 257, 7), // "channel"
QT_MOC_LITERAL(21, 265, 6), // "result"
QT_MOC_LITERAL(22, 272, 16), // "slot_plateResult"
QT_MOC_LITERAL(23, 289, 8), // "isConCar"
QT_MOC_LITERAL(24, 298, 5), // "plate"
QT_MOC_LITERAL(25, 304, 5), // "color"
QT_MOC_LITERAL(26, 310, 9), // "plateTime"
QT_MOC_LITERAL(27, 320, 17), // "slot_waitSendData"
QT_MOC_LITERAL(28, 338, 18), // "slot_readCarStatus"
QT_MOC_LITERAL(29, 357, 6) // "status"

    },
    "DataProcessing\0signal_InitializationParameter\0"
    "\0address\0port\0serviceType\0heartBeat\0"
    "serviceMode\0shortLink\0newline\0"
    "signal_toSendData\0channel_number\0data\0"
    "signal_trafficStatistics\0state\0"
    "signal_pollsForCarStatus\0type\0"
    "signal_sendToDisplay\0msg\0slot_containerResult\0"
    "channel\0result\0slot_plateResult\0"
    "isConCar\0plate\0color\0plateTime\0"
    "slot_waitSendData\0slot_readCarStatus\0"
    "status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataProcessing[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    7,   59,    2, 0x06 /* Public */,
      10,    2,   74,    2, 0x06 /* Public */,
      13,    1,   79,    2, 0x06 /* Public */,
      15,    1,   82,    2, 0x06 /* Public */,
      17,    1,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    2,   88,    2, 0x0a /* Public */,
      22,    5,   93,    2, 0x0a /* Public */,
      27,    0,  104,    2, 0x0a /* Public */,
      28,    1,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UShort, QMetaType::Int, QMetaType::Bool, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   11,   12,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::QString,   18,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   20,   21,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString,   20,   23,   24,   25,   26,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   29,

       0        // eod
};

void DataProcessing::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DataProcessing *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_InitializationParameter((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< const int(*)>(_a[5])),(*reinterpret_cast< const int(*)>(_a[6])),(*reinterpret_cast< const int(*)>(_a[7]))); break;
        case 1: _t->signal_toSendData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->signal_trafficStatistics((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->signal_pollsForCarStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->signal_sendToDisplay((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->slot_containerResult((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->slot_plateResult((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        case 7: _t->slot_waitSendData(); break;
        case 8: _t->slot_readCarStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DataProcessing::*)(const QString & , const quint16 & , const int & , bool , const int & , const int & , const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataProcessing::signal_InitializationParameter)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DataProcessing::*)(int , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataProcessing::signal_toSendData)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DataProcessing::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataProcessing::signal_trafficStatistics)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DataProcessing::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataProcessing::signal_pollsForCarStatus)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DataProcessing::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataProcessing::signal_sendToDisplay)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DataProcessing::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_DataProcessing.data,
    qt_meta_data_DataProcessing,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DataProcessing::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataProcessing::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataProcessing.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataProcessing::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void DataProcessing::signal_InitializationParameter(const QString & _t1, const quint16 & _t2, const int & _t3, bool _t4, const int & _t5, const int & _t6, const int & _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DataProcessing::signal_toSendData(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DataProcessing::signal_trafficStatistics(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DataProcessing::signal_pollsForCarStatus(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DataProcessing::signal_sendToDisplay(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
