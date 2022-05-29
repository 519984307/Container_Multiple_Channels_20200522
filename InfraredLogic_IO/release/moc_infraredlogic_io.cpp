/****************************************************************************
** Meta object code from reading C++ file 'infraredlogic_io.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../infraredlogic_io.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'infraredlogic_io.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InfraredLogic_IO_t {
    QByteArrayData data[26];
    char stringdata0[386];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InfraredLogic_IO_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InfraredLogic_IO_t qt_meta_stringdata_InfraredLogic_IO = {
    {
QT_MOC_LITERAL(0, 0, 16), // "InfraredLogic_IO"
QT_MOC_LITERAL(1, 17, 23), // "signal_releaseResources"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 17), // "signal_toSendData"
QT_MOC_LITERAL(4, 60, 14), // "channel_number"
QT_MOC_LITERAL(5, 75, 6), // "result"
QT_MOC_LITERAL(6, 82, 20), // "rebootSerialportSlot"
QT_MOC_LITERAL(7, 103, 21), // "delayAfterCaptureSlot"
QT_MOC_LITERAL(8, 125, 21), // "delayFrontCaptureSlot"
QT_MOC_LITERAL(9, 147, 14), // "logicStateslot"
QT_MOC_LITERAL(10, 162, 4), // "int*"
QT_MOC_LITERAL(11, 167, 5), // "state"
QT_MOC_LITERAL(12, 173, 15), // "serialLogicSlot"
QT_MOC_LITERAL(13, 189, 3), // "sta"
QT_MOC_LITERAL(14, 193, 17), // "timerCloseLEDSlot"
QT_MOC_LITERAL(15, 211, 16), // "A1ReleasrCapSlot"
QT_MOC_LITERAL(16, 228, 13), // "startLinkSlot"
QT_MOC_LITERAL(17, 242, 15), // "startListenSlot"
QT_MOC_LITERAL(18, 258, 13), // "connectedSlot"
QT_MOC_LITERAL(19, 272, 15), // "receiveDataSlot"
QT_MOC_LITERAL(20, 288, 16), // "disconnectedSlot"
QT_MOC_LITERAL(21, 305, 16), // "displayErrorSlot"
QT_MOC_LITERAL(22, 322, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(23, 351, 11), // "socketError"
QT_MOC_LITERAL(24, 363, 16), // "connectCountSlot"
QT_MOC_LITERAL(25, 380, 5) // "count"

    },
    "InfraredLogic_IO\0signal_releaseResources\0"
    "\0signal_toSendData\0channel_number\0"
    "result\0rebootSerialportSlot\0"
    "delayAfterCaptureSlot\0delayFrontCaptureSlot\0"
    "logicStateslot\0int*\0state\0serialLogicSlot\0"
    "sta\0timerCloseLEDSlot\0A1ReleasrCapSlot\0"
    "startLinkSlot\0startListenSlot\0"
    "connectedSlot\0receiveDataSlot\0"
    "disconnectedSlot\0displayErrorSlot\0"
    "QAbstractSocket::SocketError\0socketError\0"
    "connectCountSlot\0count"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InfraredLogic_IO[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    2,   95,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,  100,    2, 0x08 /* Private */,
       7,    0,  101,    2, 0x08 /* Private */,
       8,    0,  102,    2, 0x08 /* Private */,
       9,    1,  103,    2, 0x08 /* Private */,
      12,    1,  106,    2, 0x08 /* Private */,
      14,    0,  109,    2, 0x08 /* Private */,
      15,    0,  110,    2, 0x08 /* Private */,
      16,    0,  111,    2, 0x08 /* Private */,
      17,    0,  112,    2, 0x08 /* Private */,
      18,    0,  113,    2, 0x08 /* Private */,
      19,    0,  114,    2, 0x08 /* Private */,
      20,    0,  115,    2, 0x08 /* Private */,
      21,    1,  116,    2, 0x08 /* Private */,
      24,    1,  119,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, QMetaType::Int,   25,

       0        // eod
};

void InfraredLogic_IO::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InfraredLogic_IO *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_releaseResources(); break;
        case 1: _t->signal_toSendData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->rebootSerialportSlot(); break;
        case 3: _t->delayAfterCaptureSlot(); break;
        case 4: _t->delayFrontCaptureSlot(); break;
        case 5: _t->logicStateslot((*reinterpret_cast< int*(*)>(_a[1]))); break;
        case 6: _t->serialLogicSlot((*reinterpret_cast< int*(*)>(_a[1]))); break;
        case 7: _t->timerCloseLEDSlot(); break;
        case 8: _t->A1ReleasrCapSlot(); break;
        case 9: _t->startLinkSlot(); break;
        case 10: _t->startListenSlot(); break;
        case 11: _t->connectedSlot(); break;
        case 12: _t->receiveDataSlot(); break;
        case 13: _t->disconnectedSlot(); break;
        case 14: _t->displayErrorSlot((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 15: _t->connectCountSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (InfraredLogic_IO::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InfraredLogic_IO::signal_releaseResources)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (InfraredLogic_IO::*)(int , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InfraredLogic_IO::signal_toSendData)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject InfraredLogic_IO::staticMetaObject = { {
    &InfraredlogicInterface::staticMetaObject,
    qt_meta_stringdata_InfraredLogic_IO.data,
    qt_meta_data_InfraredLogic_IO,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *InfraredLogic_IO::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InfraredLogic_IO::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InfraredLogic_IO.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ZBY.ContainerServer.InfraredlogicInterface/1.5.0.4"))
        return static_cast< InfraredlogicInterface*>(this);
    return InfraredlogicInterface::qt_metacast(_clname);
}

int InfraredLogic_IO::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = InfraredlogicInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void InfraredLogic_IO::signal_releaseResources()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void InfraredLogic_IO::signal_toSendData(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
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
    '5',  '.',  '0',  '.',  '4', 
    // "className"
    0x03,  0x70,  'I',  'n',  'f',  'r',  'a',  'r', 
    'e',  'd',  'L',  'o',  'g',  'i',  'c',  '_', 
    'I',  'O', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(InfraredLogic_IO, InfraredLogic_IO)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
