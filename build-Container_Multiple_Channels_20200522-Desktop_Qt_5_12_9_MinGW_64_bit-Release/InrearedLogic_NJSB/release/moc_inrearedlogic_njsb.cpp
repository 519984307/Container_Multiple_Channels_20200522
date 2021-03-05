/****************************************************************************
** Meta object code from reading C++ file 'inrearedlogic_njsb.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Container_Multiple_Channels_20200522/InrearedLogic_NJSB/inrearedlogic_njsb.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'inrearedlogic_njsb.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InrearedLogic_NJSB_t {
    QByteArrayData data[10];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InrearedLogic_NJSB_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InrearedLogic_NJSB_t qt_meta_stringdata_InrearedLogic_NJSB = {
    {
QT_MOC_LITERAL(0, 0, 18), // "InrearedLogic_NJSB"
QT_MOC_LITERAL(1, 19, 16), // "logicStatesignal"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 4), // "int*"
QT_MOC_LITERAL(4, 42, 5), // "state"
QT_MOC_LITERAL(5, 48, 21), // "delayAfterCaptureSlot"
QT_MOC_LITERAL(6, 70, 21), // "delayFrontCaptureSlot"
QT_MOC_LITERAL(7, 92, 18), // "detectionLogicSlot"
QT_MOC_LITERAL(8, 111, 18), // "realyTheSerialport"
QT_MOC_LITERAL(9, 130, 14) // "logicStateslot"

    },
    "InrearedLogic_NJSB\0logicStatesignal\0"
    "\0int*\0state\0delayAfterCaptureSlot\0"
    "delayFrontCaptureSlot\0detectionLogicSlot\0"
    "realyTheSerialport\0logicStateslot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InrearedLogic_NJSB[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,
       8,    0,   50,    2, 0x08 /* Private */,
       9,    1,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void InrearedLogic_NJSB::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InrearedLogic_NJSB *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->logicStatesignal((*reinterpret_cast< int*(*)>(_a[1]))); break;
        case 1: _t->delayAfterCaptureSlot(); break;
        case 2: _t->delayFrontCaptureSlot(); break;
        case 3: _t->detectionLogicSlot(); break;
        case 4: _t->realyTheSerialport(); break;
        case 5: _t->logicStateslot((*reinterpret_cast< int*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (InrearedLogic_NJSB::*)(int * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InrearedLogic_NJSB::logicStatesignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject InrearedLogic_NJSB::staticMetaObject = { {
    &InfraredlogicInterface::staticMetaObject,
    qt_meta_stringdata_InrearedLogic_NJSB.data,
    qt_meta_data_InrearedLogic_NJSB,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *InrearedLogic_NJSB::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InrearedLogic_NJSB::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InrearedLogic_NJSB.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ZBY.ContainerServer.InfraredlogicInterface/1.4.5.2"))
        return static_cast< InfraredlogicInterface*>(this);
    return InfraredlogicInterface::qt_metacast(_clname);
}

int InrearedLogic_NJSB::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = InfraredlogicInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void InrearedLogic_NJSB::logicStatesignal(int * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

QT_PLUGIN_METADATA_SECTION
static constexpr unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x32,  'Z',  'B',  'Y',  '.',  'C', 
    'o',  'n',  't',  'a',  'i',  'n',  'e',  'r', 
    'S',  'e',  'r',  'v',  'e',  'r',  '.',  'I', 
    'n',  'f',  'r',  'a',  'r',  'e',  'd',  'l', 
    'o',  'g',  'i',  'c',  'I',  'n',  't',  'e', 
    'r',  'f',  'a',  'c',  'e',  '/',  '1',  '.', 
    '4',  '.',  '5',  '.',  '2', 
    // "className"
    0x03,  0x72,  'I',  'n',  'r',  'e',  'a',  'r', 
    'e',  'd',  'L',  'o',  'g',  'i',  'c',  '_', 
    'N',  'J',  'S',  'B', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(InrearedLogic_NJSB, InrearedLogic_NJSB)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
