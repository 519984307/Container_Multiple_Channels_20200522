/****************************************************************************
** Meta object code from reading C++ file 'camera_test_form.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Container_Multiple_Channels_20200522/Main/CameraTest/camera_test_form.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camera_test_form.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Camera_Test_Form_t {
    QByteArrayData data[12];
    char stringdata0[186];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Camera_Test_Form_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Camera_Test_Form_t qt_meta_stringdata_Camera_Test_Form = {
    {
QT_MOC_LITERAL(0, 0, 16), // "Camera_Test_Form"
QT_MOC_LITERAL(1, 17, 14), // "signal_capture"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 11), // "signal_play"
QT_MOC_LITERAL(4, 45, 5), // "winID"
QT_MOC_LITERAL(5, 51, 29), // "on_capture_pushButton_clicked"
QT_MOC_LITERAL(6, 81, 26), // "on_play_pushButton_clicked"
QT_MOC_LITERAL(7, 108, 30), // "on_identify_pushButton_clicked"
QT_MOC_LITERAL(8, 139, 18), // "slot_pictureStream"
QT_MOC_LITERAL(9, 158, 9), // "jpgStream"
QT_MOC_LITERAL(10, 168, 9), // "imgNumber"
QT_MOC_LITERAL(11, 178, 7) // "imgTime"

    },
    "Camera_Test_Form\0signal_capture\0\0"
    "signal_play\0winID\0on_capture_pushButton_clicked\0"
    "on_play_pushButton_clicked\0"
    "on_identify_pushButton_clicked\0"
    "slot_pictureStream\0jpgStream\0imgNumber\0"
    "imgTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Camera_Test_Form[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   53,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    3,   56,    2, 0x0a /* Public */,
       8,    2,   63,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::ULongLong,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int, QMetaType::QString,    9,   10,   11,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,    9,   10,

       0        // eod
};

void Camera_Test_Form::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Camera_Test_Form *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_capture(); break;
        case 1: _t->signal_play((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 2: _t->on_capture_pushButton_clicked(); break;
        case 3: _t->on_play_pushButton_clicked(); break;
        case 4: _t->on_identify_pushButton_clicked(); break;
        case 5: _t->slot_pictureStream((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 6: _t->slot_pictureStream((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Camera_Test_Form::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Camera_Test_Form::signal_capture)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Camera_Test_Form::*)(quint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Camera_Test_Form::signal_play)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Camera_Test_Form::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Camera_Test_Form.data,
    qt_meta_data_Camera_Test_Form,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Camera_Test_Form::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Camera_Test_Form::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Camera_Test_Form.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Camera_Test_Form::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void Camera_Test_Form::signal_capture()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Camera_Test_Form::signal_play(quint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
