/****************************************************************************
** Meta object code from reading C++ file 'ICaptureImages.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Processing/INTERFACE/ICaptureImages.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ICaptureImages.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ICaptureImages_t {
    QByteArrayData data[51];
    char stringdata0[670];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ICaptureImages_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ICaptureImages_t qt_meta_stringdata_ICaptureImages = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ICaptureImages"
QT_MOC_LITERAL(1, 15, 16), // "camerStateSingal"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 7), // "camerIP"
QT_MOC_LITERAL(4, 41, 5), // "state"
QT_MOC_LITERAL(5, 47, 19), // "pictureStreamSignal"
QT_MOC_LITERAL(6, 67, 9), // "jpgStream"
QT_MOC_LITERAL(7, 77, 9), // "imgNumber"
QT_MOC_LITERAL(8, 87, 7), // "imgTime"
QT_MOC_LITERAL(9, 95, 17), // "videoStreamSignal"
QT_MOC_LITERAL(10, 113, 13), // "messageSignal"
QT_MOC_LITERAL(11, 127, 4), // "type"
QT_MOC_LITERAL(12, 132, 3), // "msg"
QT_MOC_LITERAL(13, 136, 17), // "signal_initCamera"
QT_MOC_LITERAL(14, 154, 9), // "localAddr"
QT_MOC_LITERAL(15, 164, 4), // "addr"
QT_MOC_LITERAL(16, 169, 4), // "port"
QT_MOC_LITERAL(17, 174, 4), // "user"
QT_MOC_LITERAL(18, 179, 3), // "pow"
QT_MOC_LITERAL(19, 183, 19), // "signal_openTheVideo"
QT_MOC_LITERAL(20, 203, 2), // "ID"
QT_MOC_LITERAL(21, 206, 4), // "play"
QT_MOC_LITERAL(22, 211, 5), // "winID"
QT_MOC_LITERAL(23, 217, 24), // "signal_simulationCapture"
QT_MOC_LITERAL(24, 242, 31), // "signal_liftingElectronicRailing"
QT_MOC_LITERAL(25, 274, 4), // "gate"
QT_MOC_LITERAL(26, 279, 33), // "signal_transparentTransmissio..."
QT_MOC_LITERAL(27, 313, 22), // "signal_bindingCameraID"
QT_MOC_LITERAL(28, 336, 10), // "cameraAddr"
QT_MOC_LITERAL(29, 347, 13), // "initCamerSlot"
QT_MOC_LITERAL(30, 361, 9), // "camerPort"
QT_MOC_LITERAL(31, 371, 9), // "CamerUser"
QT_MOC_LITERAL(32, 381, 8), // "CamerPow"
QT_MOC_LITERAL(33, 390, 9), // "signature"
QT_MOC_LITERAL(34, 400, 14), // "putCommandSlot"
QT_MOC_LITERAL(35, 415, 14), // "playStreamSlot"
QT_MOC_LITERAL(36, 430, 28), // "liftingElectronicRailingSlot"
QT_MOC_LITERAL(37, 459, 30), // "transparentTransmission485Slot"
QT_MOC_LITERAL(38, 490, 15), // "resizeEventSlot"
QT_MOC_LITERAL(39, 506, 20), // "releaseResourcesSlot"
QT_MOC_LITERAL(40, 527, 18), // "InitializationSlot"
QT_MOC_LITERAL(41, 546, 18), // "slot_pictureStream"
QT_MOC_LITERAL(42, 565, 6), // "arrJpg"
QT_MOC_LITERAL(43, 572, 16), // "slot_setCameraID"
QT_MOC_LITERAL(44, 589, 8), // "cameraIP"
QT_MOC_LITERAL(45, 598, 27), // "slot_resultsTheLicensePlate"
QT_MOC_LITERAL(46, 626, 5), // "plate"
QT_MOC_LITERAL(47, 632, 5), // "color"
QT_MOC_LITERAL(48, 638, 4), // "time"
QT_MOC_LITERAL(49, 643, 6), // "arrImg"
QT_MOC_LITERAL(50, 650, 19) // "slot_equipmentState"

    },
    "ICaptureImages\0camerStateSingal\0\0"
    "camerIP\0state\0pictureStreamSignal\0"
    "jpgStream\0imgNumber\0imgTime\0"
    "videoStreamSignal\0messageSignal\0type\0"
    "msg\0signal_initCamera\0localAddr\0addr\0"
    "port\0user\0pow\0signal_openTheVideo\0ID\0"
    "play\0winID\0signal_simulationCapture\0"
    "signal_liftingElectronicRailing\0gate\0"
    "signal_transparentTransmission485\0"
    "signal_bindingCameraID\0cameraAddr\0"
    "initCamerSlot\0camerPort\0CamerUser\0"
    "CamerPow\0signature\0putCommandSlot\0"
    "playStreamSlot\0liftingElectronicRailingSlot\0"
    "transparentTransmission485Slot\0"
    "resizeEventSlot\0releaseResourcesSlot\0"
    "InitializationSlot\0slot_pictureStream\0"
    "arrJpg\0slot_setCameraID\0cameraIP\0"
    "slot_resultsTheLicensePlate\0plate\0"
    "color\0time\0arrImg\0slot_equipmentState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ICaptureImages[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  144,    2, 0x06 /* Public */,
       5,    3,  149,    2, 0x06 /* Public */,
       5,    2,  156,    2, 0x26 /* Public | MethodCloned */,
       9,    1,  161,    2, 0x06 /* Public */,
      10,    2,  164,    2, 0x06 /* Public */,
      13,    5,  169,    2, 0x06 /* Public */,
      19,    3,  180,    2, 0x06 /* Public */,
      23,    1,  187,    2, 0x06 /* Public */,
      24,    1,  190,    2, 0x06 /* Public */,
      26,    1,  193,    2, 0x06 /* Public */,
      27,    2,  196,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      29,    6,  201,    2, 0x0a /* Public */,
      29,    5,  214,    2, 0x2a /* Public | MethodCloned */,
      34,    3,  225,    2, 0x0a /* Public */,
      34,    2,  232,    2, 0x2a /* Public | MethodCloned */,
      35,    3,  237,    2, 0x0a /* Public */,
      35,    2,  244,    2, 0x2a /* Public | MethodCloned */,
      36,    1,  249,    2, 0x0a /* Public */,
      37,    1,  252,    2, 0x0a /* Public */,
      38,    0,  255,    2, 0x0a /* Public */,
      39,    0,  256,    2, 0x0a /* Public */,
      40,    0,  257,    2, 0x0a /* Public */,
      41,    2,  258,    2, 0x0a /* Public */,
      43,    2,  263,    2, 0x0a /* Public */,
      45,    5,  268,    2, 0x0a /* Public */,
      50,    2,  279,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    3,    4,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int, QMetaType::QString,    6,    7,    8,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,   14,   15,   16,   17,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::ULongLong,   20,   21,   22,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   28,   20,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,   14,    3,   30,   31,   32,   33,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,   14,    3,   30,   31,   32,
    QMetaType::Bool, QMetaType::Int, QMetaType::QString, QMetaType::QString,    7,    8,   33,
    QMetaType::Bool, QMetaType::Int, QMetaType::QString,    7,    8,
    QMetaType::Void, QMetaType::ULongLong, QMetaType::Bool, QMetaType::QString,   22,   21,   33,
    QMetaType::Void, QMetaType::ULongLong, QMetaType::Bool,   22,   21,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray,   20,   42,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   20,   44,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QByteArray,   20,   46,   47,   48,   49,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   20,    4,

       0        // eod
};

void ICaptureImages::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ICaptureImages *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->camerStateSingal((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->pictureStreamSignal((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 2: _t->pictureStreamSignal((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 3: _t->videoStreamSignal((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 4: _t->messageSignal((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->signal_initCamera((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        case 6: _t->signal_openTheVideo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< quint64(*)>(_a[3]))); break;
        case 7: _t->signal_simulationCapture((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->signal_liftingElectronicRailing((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->signal_transparentTransmission485((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->signal_bindingCameraID((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->initCamerSlot((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6]))); break;
        case 12: _t->initCamerSlot((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        case 13: { bool _r = _t->putCommandSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: { bool _r = _t->putCommandSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->playStreamSlot((*reinterpret_cast< quint64(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 16: _t->playStreamSlot((*reinterpret_cast< quint64(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 17: _t->liftingElectronicRailingSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->transparentTransmission485Slot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->resizeEventSlot(); break;
        case 20: _t->releaseResourcesSlot(); break;
        case 21: { bool _r = _t->InitializationSlot();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 22: _t->slot_pictureStream((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 23: _t->slot_setCameraID((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 24: _t->slot_resultsTheLicensePlate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QByteArray(*)>(_a[5]))); break;
        case 25: _t->slot_equipmentState((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ICaptureImages::*)(const QString & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICaptureImages::camerStateSingal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ICaptureImages::*)(const QByteArray & , const int & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICaptureImages::pictureStreamSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ICaptureImages::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICaptureImages::videoStreamSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ICaptureImages::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICaptureImages::messageSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ICaptureImages::*)(const QString & , const QString & , const int & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICaptureImages::signal_initCamera)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ICaptureImages::*)(int , bool , quint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICaptureImages::signal_openTheVideo)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ICaptureImages::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICaptureImages::signal_simulationCapture)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (ICaptureImages::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICaptureImages::signal_liftingElectronicRailing)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (ICaptureImages::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICaptureImages::signal_transparentTransmission485)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (ICaptureImages::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICaptureImages::signal_bindingCameraID)) {
                *result = 10;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ICaptureImages::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ICaptureImages.data,
    qt_meta_data_ICaptureImages,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ICaptureImages::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ICaptureImages::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ICaptureImages.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ICaptureImages::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void ICaptureImages::camerStateSingal(const QString & _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ICaptureImages::pictureStreamSignal(const QByteArray & _t1, const int & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 3
void ICaptureImages::videoStreamSignal(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ICaptureImages::messageSignal(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ICaptureImages::signal_initCamera(const QString & _t1, const QString & _t2, const int & _t3, const QString & _t4, const QString & _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ICaptureImages::signal_openTheVideo(int _t1, bool _t2, quint64 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ICaptureImages::signal_simulationCapture(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ICaptureImages::signal_liftingElectronicRailing(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void ICaptureImages::signal_transparentTransmission485(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void ICaptureImages::signal_bindingCameraID(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
