/****************************************************************************
** Meta object code from reading C++ file 'ICaptureUnderlying.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ICaptureUnderlying.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ICaptureUnderlying.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ICaptureUnderlying_t {
    QByteArrayData data[20];
    char stringdata0[226];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ICaptureUnderlying_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ICaptureUnderlying_t qt_meta_stringdata_ICaptureUnderlying = {
    {
QT_MOC_LITERAL(0, 0, 18), // "ICaptureUnderlying"
QT_MOC_LITERAL(1, 19, 16), // "camerStateSingal"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 7), // "camerIP"
QT_MOC_LITERAL(4, 45, 5), // "state"
QT_MOC_LITERAL(5, 51, 5), // "alias"
QT_MOC_LITERAL(6, 57, 19), // "pictureStreamSignal"
QT_MOC_LITERAL(7, 77, 9), // "jpgStream"
QT_MOC_LITERAL(8, 87, 9), // "imgNumber"
QT_MOC_LITERAL(9, 97, 7), // "imgTime"
QT_MOC_LITERAL(10, 105, 13), // "messageSignal"
QT_MOC_LITERAL(11, 119, 4), // "type"
QT_MOC_LITERAL(12, 124, 3), // "msg"
QT_MOC_LITERAL(13, 128, 13), // "initCamerSlot"
QT_MOC_LITERAL(14, 142, 9), // "camerPort"
QT_MOC_LITERAL(15, 152, 9), // "CamerUser"
QT_MOC_LITERAL(16, 162, 8), // "CamerPow"
QT_MOC_LITERAL(17, 171, 14), // "putCommandSlot"
QT_MOC_LITERAL(18, 186, 20), // "releaseResourcesSlot"
QT_MOC_LITERAL(19, 207, 18) // "InitializationSlot"

    },
    "ICaptureUnderlying\0camerStateSingal\0"
    "\0camerIP\0state\0alias\0pictureStreamSignal\0"
    "jpgStream\0imgNumber\0imgTime\0messageSignal\0"
    "type\0msg\0initCamerSlot\0camerPort\0"
    "CamerUser\0CamerPow\0putCommandSlot\0"
    "releaseResourcesSlot\0InitializationSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ICaptureUnderlying[] = {

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
       1,    3,   59,    2, 0x06 /* Public */,
       6,    3,   66,    2, 0x06 /* Public */,
       6,    2,   73,    2, 0x26 /* Public | MethodCloned */,
       6,    1,   78,    2, 0x26 /* Public | MethodCloned */,
      10,    2,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    5,   86,    2, 0x0a /* Public */,
      17,    2,   97,    2, 0x0a /* Public */,
      18,    0,  102,    2, 0x0a /* Public */,
      19,    0,  103,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int, QMetaType::QString,    7,    8,    9,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::QByteArray,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,   12,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,   14,   15,   16,    5,
    QMetaType::Bool, QMetaType::Int, QMetaType::QString,    8,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ICaptureUnderlying::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ICaptureUnderlying *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->camerStateSingal((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 1: _t->pictureStreamSignal((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 2: _t->pictureStreamSignal((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 3: _t->pictureStreamSignal((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 4: _t->messageSignal((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->initCamerSlot((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        case 6: { bool _r = _t->putCommandSlot((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->releaseResourcesSlot(); break;
        case 8: _t->InitializationSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ICaptureUnderlying::*)(const QString & , bool , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICaptureUnderlying::camerStateSingal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ICaptureUnderlying::*)(const QByteArray & , const int & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICaptureUnderlying::pictureStreamSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ICaptureUnderlying::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICaptureUnderlying::messageSignal)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ICaptureUnderlying::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ICaptureUnderlying.data,
    qt_meta_data_ICaptureUnderlying,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ICaptureUnderlying::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ICaptureUnderlying::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ICaptureUnderlying.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ICaptureUnderlying::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ICaptureUnderlying::camerStateSingal(const QString & _t1, bool _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ICaptureUnderlying::pictureStreamSignal(const QByteArray & _t1, const int & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 4
void ICaptureUnderlying::messageSignal(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
