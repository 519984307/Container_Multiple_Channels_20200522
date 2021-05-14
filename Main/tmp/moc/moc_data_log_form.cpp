/****************************************************************************
** Meta object code from reading C++ file 'data_log_form.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Log/data_log_form.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'data_log_form.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Data_Log_Form_t {
    QByteArrayData data[16];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Data_Log_Form_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Data_Log_Form_t qt_meta_stringdata_Data_Log_Form = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Data_Log_Form"
QT_MOC_LITERAL(1, 14, 15), // "slot_newLogText"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 9), // "QtMsgType"
QT_MOC_LITERAL(4, 41, 4), // "type"
QT_MOC_LITERAL(5, 46, 4), // "time"
QT_MOC_LITERAL(6, 51, 5), // "value"
QT_MOC_LITERAL(7, 57, 16), // "slot_sendLogToUi"
QT_MOC_LITERAL(8, 74, 14), // "channel_number"
QT_MOC_LITERAL(9, 89, 3), // "msg"
QT_MOC_LITERAL(10, 93, 14), // "slot_linkState"
QT_MOC_LITERAL(11, 108, 7), // "address"
QT_MOC_LITERAL(12, 116, 4), // "port"
QT_MOC_LITERAL(13, 121, 5), // "state"
QT_MOC_LITERAL(14, 127, 17), // "slot_connectCount"
QT_MOC_LITERAL(15, 145, 5) // "count"

    },
    "Data_Log_Form\0slot_newLogText\0\0QtMsgType\0"
    "type\0time\0value\0slot_sendLogToUi\0"
    "channel_number\0msg\0slot_linkState\0"
    "address\0port\0state\0slot_connectCount\0"
    "count"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Data_Log_Form[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   34,    2, 0x0a /* Public */,
       7,    2,   41,    2, 0x0a /* Public */,
      10,    3,   46,    2, 0x0a /* Public */,
      14,    1,   53,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QDateTime, QMetaType::QString,    4,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort, QMetaType::Bool,   11,   12,   13,
    QMetaType::Void, QMetaType::Int,   15,

       0        // eod
};

void Data_Log_Form::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Data_Log_Form *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_newLogText((*reinterpret_cast< QtMsgType(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->slot_sendLogToUi((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->slot_linkState((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 3: _t->slot_connectCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Data_Log_Form::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Data_Log_Form.data,
    qt_meta_data_Data_Log_Form,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Data_Log_Form::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Data_Log_Form::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Data_Log_Form.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Data_Log_Form::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
