/****************************************************************************
** Meta object code from reading C++ file 'IDecodingVideo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../IDecodingVideo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IDecodingVideo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IDecodingVideo_t {
    QByteArrayData data[9];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IDecodingVideo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IDecodingVideo_t qt_meta_stringdata_IDecodingVideo = {
    {
QT_MOC_LITERAL(0, 0, 14), // "IDecodingVideo"
QT_MOC_LITERAL(1, 15, 20), // "signal_pictureStream"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 2), // "ID"
QT_MOC_LITERAL(4, 40, 6), // "arrJpg"
QT_MOC_LITERAL(5, 47, 21), // "slot_getPictureStream"
QT_MOC_LITERAL(6, 69, 5), // "putID"
QT_MOC_LITERAL(7, 75, 11), // "lReadHandle"
QT_MOC_LITERAL(8, 87, 20) // "releaseResourcesSlot"

    },
    "IDecodingVideo\0signal_pictureStream\0"
    "\0ID\0arrJpg\0slot_getPictureStream\0putID\0"
    "lReadHandle\0releaseResourcesSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IDecodingVideo[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   34,    2, 0x0a /* Public */,
       8,    1,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Long,    6,    7,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void IDecodingVideo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IDecodingVideo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_pictureStream((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 1: _t->slot_getPictureStream((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< long(*)>(_a[2]))); break;
        case 2: _t->releaseResourcesSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (IDecodingVideo::*)(int , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IDecodingVideo::signal_pictureStream)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject IDecodingVideo::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_IDecodingVideo.data,
    qt_meta_data_IDecodingVideo,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IDecodingVideo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IDecodingVideo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IDecodingVideo.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int IDecodingVideo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void IDecodingVideo::signal_pictureStream(int _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
