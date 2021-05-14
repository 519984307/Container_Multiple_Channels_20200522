/****************************************************************************
** Meta object code from reading C++ file 'licenseplatehcnet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../licenseplatehcnet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'licenseplatehcnet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LicensePlateHCNET_t {
    QByteArrayData data[4];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LicensePlateHCNET_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LicensePlateHCNET_t qt_meta_stringdata_LicensePlateHCNET = {
    {
QT_MOC_LITERAL(0, 0, 17), // "LicensePlateHCNET"
QT_MOC_LITERAL(1, 18, 19), // "getDeviceStatusSlot"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 18) // "slot_imgGetTimeOut"

    },
    "LicensePlateHCNET\0getDeviceStatusSlot\0"
    "\0slot_imgGetTimeOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LicensePlateHCNET[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x08 /* Private */,
       3,    0,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LicensePlateHCNET::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LicensePlateHCNET *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getDeviceStatusSlot(); break;
        case 1: _t->slot_imgGetTimeOut(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject LicensePlateHCNET::staticMetaObject = { {
    &LicensePlateInterface::staticMetaObject,
    qt_meta_stringdata_LicensePlateHCNET.data,
    qt_meta_data_LicensePlateHCNET,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LicensePlateHCNET::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LicensePlateHCNET::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LicensePlateHCNET.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ZBY.ContainerServer.LicensePlateInterface/2.2.2.3"))
        return static_cast< LicensePlateInterface*>(this);
    return LicensePlateInterface::qt_metacast(_clname);
}

int LicensePlateHCNET::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LicensePlateInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

QT_PLUGIN_METADATA_SECTION
static constexpr unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x31,  'Z',  'B',  'Y',  '.',  'C', 
    'o',  'n',  't',  'a',  'i',  'n',  'e',  'r', 
    'S',  'e',  'r',  'v',  'e',  'r',  '.',  'L', 
    'i',  'c',  'e',  'n',  's',  'e',  'P',  'l', 
    'a',  't',  'e',  'I',  'n',  't',  'e',  'r', 
    'f',  'a',  'c',  'e',  '/',  '2',  '.',  '2', 
    '.',  '2',  '.',  '3', 
    // "className"
    0x03,  0x71,  'L',  'i',  'c',  'e',  'n',  's', 
    'e',  'P',  'l',  'a',  't',  'e',  'H',  'C', 
    'N',  'E',  'T', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(LicensePlateHCNET, LicensePlateHCNET)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
