/****************************************************************************
** Meta object code from reading C++ file 'encryption.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Container_Multiple_Channels_20200522/Encryption/encryption.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'encryption.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Encryption_t {
    QByteArrayData data[4];
    char stringdata0[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Encryption_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Encryption_t qt_meta_stringdata_Encryption = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Encryption"
QT_MOC_LITERAL(1, 11, 20), // "SmartXCheckExistSlot"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 15) // "checkTheKeyFunc"

    },
    "Encryption\0SmartXCheckExistSlot\0\0"
    "checkTheKeyFunc"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Encryption[] = {

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

void Encryption::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Encryption *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SmartXCheckExistSlot(); break;
        case 1: _t->checkTheKeyFunc(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Encryption::staticMetaObject = { {
    &EncryptionInterface::staticMetaObject,
    qt_meta_stringdata_Encryption.data,
    qt_meta_data_Encryption,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Encryption::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Encryption::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Encryption.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ZBY.ContainerServer.EncryptionInterface/430c4bdbd03296d3f0b2080eceadbe83"))
        return static_cast< EncryptionInterface*>(this);
    return EncryptionInterface::qt_metacast(_clname);
}

int Encryption::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = EncryptionInterface::qt_metacall(_c, _id, _a);
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
    0x02,  0x78,  0x48,  'Z',  'B',  'Y',  '.',  'C', 
    'o',  'n',  't',  'a',  'i',  'n',  'e',  'r', 
    'S',  'e',  'r',  'v',  'e',  'r',  '.',  'E', 
    'n',  'c',  'r',  'y',  'p',  't',  'i',  'o', 
    'n',  'I',  'n',  't',  'e',  'r',  'f',  'a', 
    'c',  'e',  '/',  '4',  '3',  '0',  'c',  '4', 
    'b',  'd',  'b',  'd',  '0',  '3',  '2',  '9', 
    '6',  'd',  '3',  'f',  '0',  'b',  '2',  '0', 
    '8',  '0',  'e',  'c',  'e',  'a',  'd',  'b', 
    'e',  '8',  '3', 
    // "className"
    0x03,  0x6a,  'E',  'n',  'c',  'r',  'y',  'p', 
    't',  'i',  'o',  'n', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(Encryption, Encryption)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
