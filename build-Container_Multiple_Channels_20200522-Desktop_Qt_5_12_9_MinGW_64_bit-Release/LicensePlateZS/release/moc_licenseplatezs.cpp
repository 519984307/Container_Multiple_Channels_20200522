/****************************************************************************
** Meta object code from reading C++ file 'licenseplatezs.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Container_Multiple_Channels_20200522/LicensePlateZS/licenseplatezs.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'licenseplatezs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LicensePlateZS_t {
    QByteArrayData data[13];
    char stringdata0[188];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LicensePlateZS_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LicensePlateZS_t qt_meta_stringdata_LicensePlateZS = {
    {
QT_MOC_LITERAL(0, 0, 14), // "LicensePlateZS"
QT_MOC_LITERAL(1, 15, 13), // "startLinkSlot"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 13), // "heartbeatSlot"
QT_MOC_LITERAL(4, 44, 13), // "connectedSlot"
QT_MOC_LITERAL(5, 58, 15), // "receiveDataSlot"
QT_MOC_LITERAL(6, 74, 16), // "disconnectedSlot"
QT_MOC_LITERAL(7, 91, 16), // "displayErrorSlot"
QT_MOC_LITERAL(8, 108, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(9, 137, 11), // "socketError"
QT_MOC_LITERAL(10, 149, 22), // "processPlateResultSlot"
QT_MOC_LITERAL(11, 172, 4), // "data"
QT_MOC_LITERAL(12, 177, 10) // "packetSize"

    },
    "LicensePlateZS\0startLinkSlot\0\0"
    "heartbeatSlot\0connectedSlot\0receiveDataSlot\0"
    "disconnectedSlot\0displayErrorSlot\0"
    "QAbstractSocket::SocketError\0socketError\0"
    "processPlateResultSlot\0data\0packetSize"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LicensePlateZS[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    1,   54,    2, 0x08 /* Private */,
      10,    2,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,   11,   12,

       0        // eod
};

void LicensePlateZS::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LicensePlateZS *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startLinkSlot(); break;
        case 1: _t->heartbeatSlot(); break;
        case 2: _t->connectedSlot(); break;
        case 3: _t->receiveDataSlot(); break;
        case 4: _t->disconnectedSlot(); break;
        case 5: _t->displayErrorSlot((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 6: _t->processPlateResultSlot((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LicensePlateZS::staticMetaObject = { {
    &LicensePlateInterface::staticMetaObject,
    qt_meta_stringdata_LicensePlateZS.data,
    qt_meta_data_LicensePlateZS,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LicensePlateZS::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LicensePlateZS::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LicensePlateZS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ZBY.ContainerServer.LicensePlateInterface/2.2.2.4"))
        return static_cast< LicensePlateInterface*>(this);
    return LicensePlateInterface::qt_metacast(_clname);
}

int LicensePlateZS::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LicensePlateInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
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
    '.',  '2',  '.',  '4', 
    // "className"
    0x03,  0x6e,  'L',  'i',  'c',  'e',  'n',  's', 
    'e',  'P',  'l',  'a',  't',  'e',  'Z',  'S', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(LicensePlateZS, LicensePlateZS)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
