/****************************************************************************
** Meta object code from reading C++ file 'putcommand.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../putcommand.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'putcommand.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PutCommand_t {
    QByteArrayData data[9];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PutCommand_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PutCommand_t qt_meta_stringdata_PutCommand = {
    {
QT_MOC_LITERAL(0, 0, 10), // "PutCommand"
QT_MOC_LITERAL(1, 11, 13), // "messageSignal"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "type"
QT_MOC_LITERAL(4, 31, 3), // "msg"
QT_MOC_LITERAL(5, 35, 16), // "linktoServerSlot"
QT_MOC_LITERAL(6, 52, 4), // "addr"
QT_MOC_LITERAL(7, 57, 4), // "port"
QT_MOC_LITERAL(8, 62, 14) // "putCommandSlot"

    },
    "PutCommand\0messageSignal\0\0type\0msg\0"
    "linktoServerSlot\0addr\0port\0putCommandSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PutCommand[] = {

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
       8,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    6,    7,
    QMetaType::Bool,

       0        // eod
};

void PutCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PutCommand *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->messageSignal((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->linktoServerSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 2: { bool _r = _t->putCommandSlot();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PutCommand::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PutCommand::messageSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PutCommand::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_PutCommand.data,
    qt_meta_data_PutCommand,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PutCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PutCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PutCommand.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PutCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void PutCommand::messageSignal(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
