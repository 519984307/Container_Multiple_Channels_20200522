/****************************************************************************
** Meta object code from reading C++ file 'infraredlogicinterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../infraredlogicinterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'infraredlogicinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InfraredlogicInterface_t {
    QByteArrayData data[28];
    char stringdata0[317];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InfraredlogicInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InfraredlogicInterface_t qt_meta_stringdata_InfraredlogicInterface = {
    {
QT_MOC_LITERAL(0, 0, 22), // "InfraredlogicInterface"
QT_MOC_LITERAL(1, 23, 17), // "logicStatusSignal"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 4), // "int*"
QT_MOC_LITERAL(4, 47, 6), // "status"
QT_MOC_LITERAL(5, 54, 19), // "logicPutImageSignal"
QT_MOC_LITERAL(6, 74, 9), // "putCommnd"
QT_MOC_LITERAL(7, 84, 21), // "serialPortStateSignal"
QT_MOC_LITERAL(8, 106, 4), // "com1"
QT_MOC_LITERAL(9, 111, 4), // "com2"
QT_MOC_LITERAL(10, 116, 11), // "socketState"
QT_MOC_LITERAL(11, 128, 14), // "startSlaveSlot"
QT_MOC_LITERAL(12, 143, 9), // "portName1"
QT_MOC_LITERAL(13, 153, 9), // "portName2"
QT_MOC_LITERAL(14, 163, 7), // "address"
QT_MOC_LITERAL(15, 171, 4), // "port"
QT_MOC_LITERAL(16, 176, 5), // "model"
QT_MOC_LITERAL(17, 182, 10), // "channelNum"
QT_MOC_LITERAL(18, 193, 19), // "simulateTriggerSlot"
QT_MOC_LITERAL(19, 213, 4), // "type"
QT_MOC_LITERAL(20, 218, 16), // "setAlarmModeSlot"
QT_MOC_LITERAL(21, 235, 9), // "logicType"
QT_MOC_LITERAL(22, 245, 12), // "A1ReleasrCap"
QT_MOC_LITERAL(23, 258, 12), // "DTypeOutSlot"
QT_MOC_LITERAL(24, 271, 10), // "QList<int>"
QT_MOC_LITERAL(25, 282, 5), // "dType"
QT_MOC_LITERAL(26, 288, 7), // "lifting"
QT_MOC_LITERAL(27, 296, 20) // "releaseResourcesSlot"

    },
    "InfraredlogicInterface\0logicStatusSignal\0"
    "\0int*\0status\0logicPutImageSignal\0"
    "putCommnd\0serialPortStateSignal\0com1\0"
    "com2\0socketState\0startSlaveSlot\0"
    "portName1\0portName2\0address\0port\0model\0"
    "channelNum\0simulateTriggerSlot\0type\0"
    "setAlarmModeSlot\0logicType\0A1ReleasrCap\0"
    "DTypeOutSlot\0QList<int>\0dType\0lifting\0"
    "releaseResourcesSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InfraredlogicInterface[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    1,   57,    2, 0x06 /* Public */,
       7,    3,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    6,   67,    2, 0x0a /* Public */,
      18,    1,   80,    2, 0x0a /* Public */,
      20,    3,   83,    2, 0x0a /* Public */,
      23,    2,   90,    2, 0x0a /* Public */,
      27,    0,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,    8,    9,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,   12,   13,   14,   15,   16,   17,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int, QMetaType::Double,   16,   21,   22,
    QMetaType::Void, 0x80000000 | 24, QMetaType::Int,   25,   26,
    QMetaType::Void,

       0        // eod
};

void InfraredlogicInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InfraredlogicInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->logicStatusSignal((*reinterpret_cast< int*(*)>(_a[1]))); break;
        case 1: _t->logicPutImageSignal((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->serialPortStateSignal((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 3: _t->startSlaveSlot((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 4: _t->simulateTriggerSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setAlarmModeSlot((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 6: _t->DTypeOutSlot((*reinterpret_cast< QList<int>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->releaseResourcesSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (InfraredlogicInterface::*)(int * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InfraredlogicInterface::logicStatusSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (InfraredlogicInterface::*)(const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InfraredlogicInterface::logicPutImageSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (InfraredlogicInterface::*)(bool , bool , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InfraredlogicInterface::serialPortStateSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject InfraredlogicInterface::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_InfraredlogicInterface.data,
    qt_meta_data_InfraredlogicInterface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *InfraredlogicInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InfraredlogicInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InfraredlogicInterface.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int InfraredlogicInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void InfraredlogicInterface::logicStatusSignal(int * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void InfraredlogicInterface::logicPutImageSignal(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void InfraredlogicInterface::serialPortStateSignal(bool _t1, bool _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
