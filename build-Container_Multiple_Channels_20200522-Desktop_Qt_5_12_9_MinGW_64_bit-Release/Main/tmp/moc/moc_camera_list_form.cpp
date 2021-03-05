/****************************************************************************
** Meta object code from reading C++ file 'camera_list_form.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Container_Multiple_Channels_20200522/Main/CameraTest/camera_list_form.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camera_list_form.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Camera_List_Form_t {
    QByteArrayData data[23];
    char stringdata0[309];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Camera_List_Form_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Camera_List_Form_t qt_meta_stringdata_Camera_List_Form = {
    {
QT_MOC_LITERAL(0, 0, 16), // "Camera_List_Form"
QT_MOC_LITERAL(1, 17, 18), // "signal_captureTest"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 9), // "channelID"
QT_MOC_LITERAL(4, 47, 8), // "cameraID"
QT_MOC_LITERAL(5, 56, 20), // "signal_pictureStream"
QT_MOC_LITERAL(6, 77, 9), // "jpgStream"
QT_MOC_LITERAL(7, 87, 9), // "imgNumber"
QT_MOC_LITERAL(8, 97, 7), // "imgTime"
QT_MOC_LITERAL(9, 105, 17), // "signal_playStream"
QT_MOC_LITERAL(10, 123, 5), // "winID"
QT_MOC_LITERAL(11, 129, 4), // "play"
QT_MOC_LITERAL(12, 134, 28), // "initializesTheDeviceListSlot"
QT_MOC_LITERAL(13, 163, 5), // "count"
QT_MOC_LITERAL(14, 169, 9), // "rowLabels"
QT_MOC_LITERAL(15, 179, 31), // "on_CameraList_itemDoubleClicked"
QT_MOC_LITERAL(16, 211, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(17, 228, 4), // "item"
QT_MOC_LITERAL(18, 233, 6), // "column"
QT_MOC_LITERAL(19, 240, 25), // "on_CameraList_itemClicked"
QT_MOC_LITERAL(20, 266, 12), // "slot_capture"
QT_MOC_LITERAL(21, 279, 9), // "slot_play"
QT_MOC_LITERAL(22, 289, 19) // "slot_getCameraState"

    },
    "Camera_List_Form\0signal_captureTest\0"
    "\0channelID\0cameraID\0signal_pictureStream\0"
    "jpgStream\0imgNumber\0imgTime\0"
    "signal_playStream\0winID\0play\0"
    "initializesTheDeviceListSlot\0count\0"
    "rowLabels\0on_CameraList_itemDoubleClicked\0"
    "QTreeWidgetItem*\0item\0column\0"
    "on_CameraList_itemClicked\0slot_capture\0"
    "slot_play\0slot_getCameraState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Camera_List_Form[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,
       5,    3,   69,    2, 0x06 /* Public */,
       5,    2,   76,    2, 0x26 /* Public | MethodCloned */,
       9,    4,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    2,   90,    2, 0x08 /* Private */,
      15,    2,   95,    2, 0x08 /* Private */,
      19,    2,  100,    2, 0x08 /* Private */,
      20,    0,  105,    2, 0x08 /* Private */,
      21,    1,  106,    2, 0x08 /* Private */,
      22,    2,  109,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int, QMetaType::QString,    6,    7,    8,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::ULongLong, QMetaType::Bool, QMetaType::Int, QMetaType::Int,   10,   11,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QStringList,   13,   14,
    QMetaType::Void, 0x80000000 | 16, QMetaType::Int,   17,   18,
    QMetaType::Void, 0x80000000 | 16, QMetaType::Int,   17,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::ULongLong,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,

       0        // eod
};

void Camera_List_Form::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Camera_List_Form *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_captureTest((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->signal_pictureStream((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 2: _t->signal_pictureStream((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 3: _t->signal_playStream((*reinterpret_cast< quint64(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 4: _t->initializesTheDeviceListSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 5: _t->on_CameraList_itemDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->on_CameraList_itemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->slot_capture(); break;
        case 8: _t->slot_play((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 9: _t->slot_getCameraState((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Camera_List_Form::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Camera_List_Form::signal_captureTest)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Camera_List_Form::*)(const QByteArray & , const int & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Camera_List_Form::signal_pictureStream)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Camera_List_Form::*)(quint64 , bool , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Camera_List_Form::signal_playStream)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Camera_List_Form::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Camera_List_Form.data,
    qt_meta_data_Camera_List_Form,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Camera_List_Form::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Camera_List_Form::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Camera_List_Form.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Camera_List_Form::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Camera_List_Form::signal_captureTest(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Camera_List_Form::signal_pictureStream(const QByteArray & _t1, const int & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 3
void Camera_List_Form::signal_playStream(quint64 _t1, bool _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
