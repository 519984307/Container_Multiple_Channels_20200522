/****************************************************************************
** Meta object code from reading C++ file 'touploaddatainterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Container_Multiple_Channels_20200522/ToUploadData/touploaddatainterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'touploaddatainterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ToUploadDataInterface_t {
    QByteArrayData data[17];
    char stringdata0[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ToUploadDataInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ToUploadDataInterface_t qt_meta_stringdata_ToUploadDataInterface = {
    {
QT_MOC_LITERAL(0, 0, 21), // "ToUploadDataInterface"
QT_MOC_LITERAL(1, 22, 19), // "theProgressOfSignal"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 9), // "bytesSent"
QT_MOC_LITERAL(4, 53, 10), // "bytesTotal"
QT_MOC_LITERAL(5, 64, 13), // "messageSignal"
QT_MOC_LITERAL(6, 78, 4), // "type"
QT_MOC_LITERAL(7, 83, 3), // "msg"
QT_MOC_LITERAL(8, 87, 27), // "InitializationParameterSlot"
QT_MOC_LITERAL(9, 115, 4), // "user"
QT_MOC_LITERAL(10, 120, 4), // "pass"
QT_MOC_LITERAL(11, 125, 4), // "path"
QT_MOC_LITERAL(12, 130, 4), // "host"
QT_MOC_LITERAL(13, 135, 4), // "port"
QT_MOC_LITERAL(14, 140, 14), // "uploadDataSlot"
QT_MOC_LITERAL(15, 155, 4), // "data"
QT_MOC_LITERAL(16, 160, 20) // "releaseResourcesSlot"

    },
    "ToUploadDataInterface\0theProgressOfSignal\0"
    "\0bytesSent\0bytesTotal\0messageSignal\0"
    "type\0msg\0InitializationParameterSlot\0"
    "user\0pass\0path\0host\0port\0uploadDataSlot\0"
    "data\0releaseResourcesSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ToUploadDataInterface[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       5,    2,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    5,   54,    2, 0x0a /* Public */,
       8,    4,   65,    2, 0x2a /* Public | MethodCloned */,
      14,    1,   74,    2, 0x0a /* Public */,
      16,    0,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,    9,   10,   11,   12,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,   10,   11,   12,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,

       0        // eod
};

void ToUploadDataInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ToUploadDataInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->theProgressOfSignal((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 1: _t->messageSignal((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->InitializationParameterSlot((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const int(*)>(_a[5]))); break;
        case 3: _t->InitializationParameterSlot((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 4: _t->uploadDataSlot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->releaseResourcesSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ToUploadDataInterface::*)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ToUploadDataInterface::theProgressOfSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ToUploadDataInterface::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ToUploadDataInterface::messageSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ToUploadDataInterface::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ToUploadDataInterface.data,
    qt_meta_data_ToUploadDataInterface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ToUploadDataInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ToUploadDataInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ToUploadDataInterface.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ToUploadDataInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void ToUploadDataInterface::theProgressOfSignal(qint64 _t1, qint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ToUploadDataInterface::messageSignal(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
