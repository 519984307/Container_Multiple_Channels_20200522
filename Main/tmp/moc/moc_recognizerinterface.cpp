/****************************************************************************
** Meta object code from reading C++ file 'recognizerinterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Processing/interface/recognizerinterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recognizerinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RecognizerInterface_t {
    QByteArrayData data[17];
    char stringdata0[216];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RecognizerInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RecognizerInterface_t qt_meta_stringdata_RecognizerInterface = {
    {
QT_MOC_LITERAL(0, 0, 19), // "RecognizerInterface"
QT_MOC_LITERAL(1, 20, 13), // "messageSignal"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 4), // "type"
QT_MOC_LITERAL(4, 40, 3), // "msg"
QT_MOC_LITERAL(5, 44, 23), // "recognitionResultSignal"
QT_MOC_LITERAL(6, 68, 6), // "result"
QT_MOC_LITERAL(7, 75, 7), // "imgName"
QT_MOC_LITERAL(8, 83, 9), // "imgNumber"
QT_MOC_LITERAL(9, 93, 18), // "identifyStreamSlot"
QT_MOC_LITERAL(10, 112, 9), // "jpgStream"
QT_MOC_LITERAL(11, 122, 18), // "identifyImagesSlot"
QT_MOC_LITERAL(12, 141, 17), // "QMap<int,QString>"
QT_MOC_LITERAL(13, 159, 6), // "imgMap"
QT_MOC_LITERAL(14, 166, 21), // "identifyDogStatusSlot"
QT_MOC_LITERAL(15, 188, 6), // "status"
QT_MOC_LITERAL(16, 195, 20) // "releaseResourcesSlot"

    },
    "RecognizerInterface\0messageSignal\0\0"
    "type\0msg\0recognitionResultSignal\0"
    "result\0imgName\0imgNumber\0identifyStreamSlot\0"
    "jpgStream\0identifyImagesSlot\0"
    "QMap<int,QString>\0imgMap\0identifyDogStatusSlot\0"
    "status\0releaseResourcesSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RecognizerInterface[] = {

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
       5,    3,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    2,   56,    2, 0x0a /* Public */,
      11,    1,   61,    2, 0x0a /* Public */,
      14,    1,   64,    2, 0x0a /* Public */,
      16,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    6,    7,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,   10,    8,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void,

       0        // eod
};

void RecognizerInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RecognizerInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->messageSignal((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->recognitionResultSignal((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3]))); break;
        case 2: _t->identifyStreamSlot((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 3: _t->identifyImagesSlot((*reinterpret_cast< QMap<int,QString>(*)>(_a[1]))); break;
        case 4: _t->identifyDogStatusSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->releaseResourcesSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RecognizerInterface::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RecognizerInterface::messageSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RecognizerInterface::*)(const QString & , const QString & , const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RecognizerInterface::recognitionResultSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RecognizerInterface::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_RecognizerInterface.data,
    qt_meta_data_RecognizerInterface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RecognizerInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RecognizerInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RecognizerInterface.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RecognizerInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void RecognizerInterface::messageSignal(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RecognizerInterface::recognitionResultSignal(const QString & _t1, const QString & _t2, const int & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
