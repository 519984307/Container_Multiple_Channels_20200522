/****************************************************************************
** Meta object code from reading C++ file 'infraredlogicinterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Container_Multiple_Channels_20200522/InfraredLogic/infraredlogicinterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
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
    QByteArrayData data[21];
    char stringdata0[242];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InfraredlogicInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InfraredlogicInterface_t qt_meta_stringdata_InfraredlogicInterface = {
    {
QT_MOC_LITERAL(0, 0, 22), // "InfraredlogicInterface"
QT_MOC_LITERAL(1, 23, 13), // "messageSignal"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 4), // "type"
QT_MOC_LITERAL(4, 43, 3), // "msg"
QT_MOC_LITERAL(5, 47, 17), // "logicStatusSignal"
QT_MOC_LITERAL(6, 65, 4), // "int*"
QT_MOC_LITERAL(7, 70, 6), // "status"
QT_MOC_LITERAL(8, 77, 19), // "logicPutImageSignal"
QT_MOC_LITERAL(9, 97, 9), // "putCommnd"
QT_MOC_LITERAL(10, 107, 21), // "serialPortStateSignal"
QT_MOC_LITERAL(11, 129, 4), // "com1"
QT_MOC_LITERAL(12, 134, 4), // "com2"
QT_MOC_LITERAL(13, 139, 14), // "startSlaveSlot"
QT_MOC_LITERAL(14, 154, 9), // "portName1"
QT_MOC_LITERAL(15, 164, 9), // "portName2"
QT_MOC_LITERAL(16, 174, 10), // "channelNum"
QT_MOC_LITERAL(17, 185, 19), // "simulateTriggerSlot"
QT_MOC_LITERAL(18, 205, 16), // "setAlarmModeSlot"
QT_MOC_LITERAL(19, 222, 5), // "model"
QT_MOC_LITERAL(20, 228, 13) // "exitWhileSlot"

    },
    "InfraredlogicInterface\0messageSignal\0"
    "\0type\0msg\0logicStatusSignal\0int*\0"
    "status\0logicPutImageSignal\0putCommnd\0"
    "serialPortStateSignal\0com1\0com2\0"
    "startSlaveSlot\0portName1\0portName2\0"
    "channelNum\0simulateTriggerSlot\0"
    "setAlarmModeSlot\0model\0exitWhileSlot"
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
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       5,    1,   59,    2, 0x06 /* Public */,
       8,    1,   62,    2, 0x06 /* Public */,
      10,    2,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    3,   70,    2, 0x0a /* Public */,
      17,    1,   77,    2, 0x0a /* Public */,
      18,    1,   80,    2, 0x0a /* Public */,
      20,    0,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   11,   12,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,   14,   15,   16,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void,

       0        // eod
};

void InfraredlogicInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InfraredlogicInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->messageSignal((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->logicStatusSignal((*reinterpret_cast< int*(*)>(_a[1]))); break;
        case 2: _t->logicPutImageSignal((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: _t->serialPortStateSignal((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->startSlaveSlot((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 5: _t->simulateTriggerSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setAlarmModeSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->exitWhileSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (InfraredlogicInterface::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InfraredlogicInterface::messageSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (InfraredlogicInterface::*)(int * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InfraredlogicInterface::logicStatusSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (InfraredlogicInterface::*)(const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InfraredlogicInterface::logicPutImageSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (InfraredlogicInterface::*)(bool , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InfraredlogicInterface::serialPortStateSignal)) {
                *result = 3;
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void InfraredlogicInterface::messageSignal(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void InfraredlogicInterface::logicStatusSignal(int * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void InfraredlogicInterface::logicPutImageSignal(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void InfraredlogicInterface::serialPortStateSignal(bool _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
