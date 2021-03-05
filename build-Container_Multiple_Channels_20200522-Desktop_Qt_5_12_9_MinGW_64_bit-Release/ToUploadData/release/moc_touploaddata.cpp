/****************************************************************************
** Meta object code from reading C++ file 'touploaddata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Container_Multiple_Channels_20200522/ToUploadData/touploaddata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'touploaddata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ToUploadData_t {
    QByteArrayData data[19];
    char stringdata0[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ToUploadData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ToUploadData_t qt_meta_stringdata_ToUploadData = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ToUploadData"
QT_MOC_LITERAL(1, 13, 19), // "theProgressOfSignal"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 9), // "bytesSent"
QT_MOC_LITERAL(4, 44, 10), // "bytesTotal"
QT_MOC_LITERAL(5, 55, 13), // "messageSignal"
QT_MOC_LITERAL(6, 69, 4), // "type"
QT_MOC_LITERAL(7, 74, 3), // "msg"
QT_MOC_LITERAL(8, 78, 17), // "replyFinishedSlot"
QT_MOC_LITERAL(9, 96, 14), // "QNetworkReply*"
QT_MOC_LITERAL(10, 111, 5), // "reply"
QT_MOC_LITERAL(11, 117, 14), // "slot_SslErrors"
QT_MOC_LITERAL(12, 132, 16), // "QList<QSslError>"
QT_MOC_LITERAL(13, 149, 6), // "sslErr"
QT_MOC_LITERAL(14, 156, 10), // "slot_Error"
QT_MOC_LITERAL(15, 167, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(16, 195, 3), // "err"
QT_MOC_LITERAL(17, 199, 13), // "slot_finished"
QT_MOC_LITERAL(18, 213, 19) // "slot_uploadProgress"

    },
    "ToUploadData\0theProgressOfSignal\0\0"
    "bytesSent\0bytesTotal\0messageSignal\0"
    "type\0msg\0replyFinishedSlot\0QNetworkReply*\0"
    "reply\0slot_SslErrors\0QList<QSslError>\0"
    "sslErr\0slot_Error\0QNetworkReply::NetworkError\0"
    "err\0slot_finished\0slot_uploadProgress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ToUploadData[] = {

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
       1,    2,   49,    2, 0x06 /* Public */,
       5,    2,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   59,    2, 0x08 /* Private */,
      11,    1,   62,    2, 0x08 /* Private */,
      14,    1,   65,    2, 0x08 /* Private */,
      17,    0,   68,    2, 0x08 /* Private */,
      18,    2,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    3,    4,

       0        // eod
};

void ToUploadData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ToUploadData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->theProgressOfSignal((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 1: _t->messageSignal((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->replyFinishedSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->slot_SslErrors((*reinterpret_cast< QList<QSslError>(*)>(_a[1]))); break;
        case 4: _t->slot_Error((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 5: _t->slot_finished(); break;
        case 6: _t->slot_uploadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSslError> >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ToUploadData::*)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ToUploadData::theProgressOfSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ToUploadData::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ToUploadData::messageSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ToUploadData::staticMetaObject = { {
    &ToUploadDataInterface::staticMetaObject,
    qt_meta_stringdata_ToUploadData.data,
    qt_meta_data_ToUploadData,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ToUploadData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ToUploadData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ToUploadData.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ZBY.ContainerServer.ToUploadDataInterface/1.3.3"))
        return static_cast< ToUploadDataInterface*>(this);
    return ToUploadDataInterface::qt_metacast(_clname);
}

int ToUploadData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ToUploadDataInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ToUploadData::theProgressOfSignal(qint64 _t1, qint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ToUploadData::messageSignal(const QString & _t1, const QString & _t2)
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
    0x02,  0x78,  0x2f,  'Z',  'B',  'Y',  '.',  'C', 
    'o',  'n',  't',  'a',  'i',  'n',  'e',  'r', 
    'S',  'e',  'r',  'v',  'e',  'r',  '.',  'T', 
    'o',  'U',  'p',  'l',  'o',  'a',  'd',  'D', 
    'a',  't',  'a',  'I',  'n',  't',  'e',  'r', 
    'f',  'a',  'c',  'e',  '/',  '1',  '.',  '3', 
    '.',  '3', 
    // "className"
    0x03,  0x6c,  'T',  'o',  'U',  'p',  'l',  'o', 
    'a',  'd',  'D',  'a',  't',  'a', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(ToUploadData, ToUploadData)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
