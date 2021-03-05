/****************************************************************************
** Meta object code from reading C++ file 'loadinglibaray.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Container_Multiple_Channels_20200522/Main/Processing/loadinglibaray.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loadinglibaray.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LoadingLibaray_t {
    QByteArrayData data[14];
    char stringdata0[239];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LoadingLibaray_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LoadingLibaray_t qt_meta_stringdata_LoadingLibaray = {
    {
QT_MOC_LITERAL(0, 0, 14), // "LoadingLibaray"
QT_MOC_LITERAL(1, 15, 21), // "signal_handleFinished"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 27), // "signal_progressRangeChanged"
QT_MOC_LITERAL(4, 66, 7), // "minimum"
QT_MOC_LITERAL(5, 74, 7), // "maximum"
QT_MOC_LITERAL(6, 82, 26), // "signal_progressTextChanged"
QT_MOC_LITERAL(7, 109, 12), // "progressText"
QT_MOC_LITERAL(8, 122, 27), // "signal_progressValueChanged"
QT_MOC_LITERAL(9, 150, 13), // "progressValue"
QT_MOC_LITERAL(10, 164, 22), // "signal_loadPluginError"
QT_MOC_LITERAL(11, 187, 10), // "pluginName"
QT_MOC_LITERAL(12, 198, 18), // "slot_createLibaray"
QT_MOC_LITERAL(13, 217, 21) // "slot_destructorThread"

    },
    "LoadingLibaray\0signal_handleFinished\0"
    "\0signal_progressRangeChanged\0minimum\0"
    "maximum\0signal_progressTextChanged\0"
    "progressText\0signal_progressValueChanged\0"
    "progressValue\0signal_loadPluginError\0"
    "pluginName\0slot_createLibaray\0"
    "slot_destructorThread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoadingLibaray[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    2,   50,    2, 0x06 /* Public */,
       6,    1,   55,    2, 0x06 /* Public */,
       8,    1,   58,    2, 0x06 /* Public */,
      10,    1,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   64,    2, 0x0a /* Public */,
      13,    0,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::QString,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LoadingLibaray::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LoadingLibaray *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_handleFinished(); break;
        case 1: _t->signal_progressRangeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->signal_progressTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->signal_progressValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->signal_loadPluginError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->slot_createLibaray(); break;
        case 6: _t->slot_destructorThread(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LoadingLibaray::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoadingLibaray::signal_handleFinished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LoadingLibaray::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoadingLibaray::signal_progressRangeChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LoadingLibaray::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoadingLibaray::signal_progressTextChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (LoadingLibaray::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoadingLibaray::signal_progressValueChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (LoadingLibaray::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoadingLibaray::signal_loadPluginError)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LoadingLibaray::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_LoadingLibaray.data,
    qt_meta_data_LoadingLibaray,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LoadingLibaray::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoadingLibaray::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LoadingLibaray.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int LoadingLibaray::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void LoadingLibaray::signal_handleFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LoadingLibaray::signal_progressRangeChanged(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LoadingLibaray::signal_progressTextChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void LoadingLibaray::signal_progressValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void LoadingLibaray::signal_loadPluginError(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
