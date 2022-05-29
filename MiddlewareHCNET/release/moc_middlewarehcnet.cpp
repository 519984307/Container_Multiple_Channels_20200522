/****************************************************************************
** Meta object code from reading C++ file 'middlewarehcnet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../middlewarehcnet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'middlewarehcnet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MiddlewareHCNET_t {
    QByteArrayData data[10];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MiddlewareHCNET_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MiddlewareHCNET_t qt_meta_stringdata_MiddlewareHCNET = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MiddlewareHCNET"
QT_MOC_LITERAL(1, 16, 23), // "signal_getPictureStream"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 5), // "putID"
QT_MOC_LITERAL(4, 47, 11), // "lReadHandle"
QT_MOC_LITERAL(5, 59, 23), // "signal_releaseResources"
QT_MOC_LITERAL(6, 83, 2), // "ID"
QT_MOC_LITERAL(7, 86, 19), // "getDeviceStatusSlot"
QT_MOC_LITERAL(8, 106, 19), // "slot_handleFinished"
QT_MOC_LITERAL(9, 126, 15) // "resizeEventSlot"

    },
    "MiddlewareHCNET\0signal_getPictureStream\0"
    "\0putID\0lReadHandle\0signal_releaseResources\0"
    "ID\0getDeviceStatusSlot\0slot_handleFinished\0"
    "resizeEventSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MiddlewareHCNET[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       5,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   47,    2, 0x08 /* Private */,
       8,    0,   48,    2, 0x08 /* Private */,
       9,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Long,    3,    4,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MiddlewareHCNET::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MiddlewareHCNET *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_getPictureStream((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< long(*)>(_a[2]))); break;
        case 1: _t->signal_releaseResources((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->getDeviceStatusSlot(); break;
        case 3: _t->slot_handleFinished(); break;
        case 4: _t->resizeEventSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MiddlewareHCNET::*)(int , long );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MiddlewareHCNET::signal_getPictureStream)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MiddlewareHCNET::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MiddlewareHCNET::signal_releaseResources)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MiddlewareHCNET::staticMetaObject = { {
    &IMiddleware::staticMetaObject,
    qt_meta_stringdata_MiddlewareHCNET.data,
    qt_meta_data_MiddlewareHCNET,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MiddlewareHCNET::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MiddlewareHCNET::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MiddlewareHCNET.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ZBY.ContainerServer.IMiddleware/2.4.3.4"))
        return static_cast< IMiddleware*>(this);
    return IMiddleware::qt_metacast(_clname);
}

int MiddlewareHCNET::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IMiddleware::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void MiddlewareHCNET::signal_getPictureStream(int _t1, long _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MiddlewareHCNET::signal_releaseResources(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

QT_PLUGIN_METADATA_SECTION
static constexpr unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x27,  'Z',  'B',  'Y',  '.',  'C', 
    'o',  'n',  't',  'a',  'i',  'n',  'e',  'r', 
    'S',  'e',  'r',  'v',  'e',  'r',  '.',  'I', 
    'M',  'i',  'd',  'd',  'l',  'e',  'w',  'a', 
    'r',  'e',  '/',  '2',  '.',  '4',  '.',  '3', 
    '.',  '4', 
    // "className"
    0x03,  0x6f,  'M',  'i',  'd',  'd',  'l',  'e', 
    'w',  'a',  'r',  'e',  'H',  'C',  'N',  'E', 
    'T', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(MiddlewareHCNET, MiddlewareHCNET)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
