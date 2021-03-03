/****************************************************************************
** Meta object code from reading C++ file 'resultsanalysisinterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Container_Multiple_Channels_20200522/Main/Processing/interface/resultsanalysisinterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'resultsanalysisinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ResultsAnalysisInterface_t {
    QByteArrayData data[34];
    char stringdata0[418];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ResultsAnalysisInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ResultsAnalysisInterface_t qt_meta_stringdata_ResultsAnalysisInterface = {
    {
QT_MOC_LITERAL(0, 0, 24), // "ResultsAnalysisInterface"
QT_MOC_LITERAL(1, 25, 13), // "messageSignal"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 4), // "type"
QT_MOC_LITERAL(4, 45, 3), // "msg"
QT_MOC_LITERAL(5, 49, 15), // "containerSignal"
QT_MOC_LITERAL(6, 65, 7), // "result1"
QT_MOC_LITERAL(7, 73, 12), // "resultCheck1"
QT_MOC_LITERAL(8, 86, 4), // "iso1"
QT_MOC_LITERAL(9, 91, 7), // "result2"
QT_MOC_LITERAL(10, 99, 12), // "resultCheck2"
QT_MOC_LITERAL(11, 112, 4), // "iso2"
QT_MOC_LITERAL(12, 117, 20), // "updateDataBaseSignal"
QT_MOC_LITERAL(13, 138, 21), // "QMap<QString,QString>"
QT_MOC_LITERAL(14, 160, 4), // "data"
QT_MOC_LITERAL(15, 165, 26), // "resultsAnalysisStateSignal"
QT_MOC_LITERAL(16, 192, 7), // "channel"
QT_MOC_LITERAL(17, 200, 16), // "sendResultSignal"
QT_MOC_LITERAL(18, 217, 6), // "result"
QT_MOC_LITERAL(19, 224, 13), // "initParameter"
QT_MOC_LITERAL(20, 238, 16), // "ImageNamingRules"
QT_MOC_LITERAL(21, 255, 5), // "check"
QT_MOC_LITERAL(22, 261, 7), // "sendMid"
QT_MOC_LITERAL(23, 269, 21), // "resultsOfAnalysisSlot"
QT_MOC_LITERAL(24, 291, 17), // "QMap<int,QString>"
QT_MOC_LITERAL(25, 309, 9), // "resultMap"
QT_MOC_LITERAL(26, 319, 10), // "imgNameMap"
QT_MOC_LITERAL(27, 330, 24), // "resultsAnalysisStateslot"
QT_MOC_LITERAL(28, 355, 18), // "slot_plateSendData"
QT_MOC_LITERAL(29, 374, 17), // "Identify_Protocol"
QT_MOC_LITERAL(30, 392, 8), // "isConCar"
QT_MOC_LITERAL(31, 401, 5), // "plate"
QT_MOC_LITERAL(32, 407, 5), // "color"
QT_MOC_LITERAL(33, 413, 4) // "time"

    },
    "ResultsAnalysisInterface\0messageSignal\0"
    "\0type\0msg\0containerSignal\0result1\0"
    "resultCheck1\0iso1\0result2\0resultCheck2\0"
    "iso2\0updateDataBaseSignal\0"
    "QMap<QString,QString>\0data\0"
    "resultsAnalysisStateSignal\0channel\0"
    "sendResultSignal\0result\0initParameter\0"
    "ImageNamingRules\0check\0sendMid\0"
    "resultsOfAnalysisSlot\0QMap<int,QString>\0"
    "resultMap\0imgNameMap\0resultsAnalysisStateslot\0"
    "slot_plateSendData\0Identify_Protocol\0"
    "isConCar\0plate\0color\0time"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ResultsAnalysisInterface[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,
       5,    7,   79,    2, 0x06 /* Public */,
       5,    6,   94,    2, 0x26 /* Public | MethodCloned */,
       5,    5,  107,    2, 0x26 /* Public | MethodCloned */,
       5,    4,  118,    2, 0x26 /* Public | MethodCloned */,
      12,    1,  127,    2, 0x06 /* Public */,
      15,    2,  130,    2, 0x06 /* Public */,
      17,    2,  135,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    4,  140,    2, 0x0a /* Public */,
      23,    3,  149,    2, 0x0a /* Public */,
      27,    2,  156,    2, 0x0a /* Public */,
      28,    5,  161,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString,    3,    6,    7,    8,    9,   10,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int,    3,    6,    7,    8,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,    3,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString,    3,    6,    7,    8,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   16,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   16,   18,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Bool, QMetaType::Bool,   16,   20,   21,   22,
    QMetaType::Void, 0x80000000 | 24, QMetaType::Int, 0x80000000 | 24,   25,    3,   26,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   16,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString,   29,   30,   31,   32,   33,

       0        // eod
};

void ResultsAnalysisInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ResultsAnalysisInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->messageSignal((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->containerSignal((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const int(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7]))); break;
        case 2: _t->containerSignal((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const int(*)>(_a[6]))); break;
        case 3: _t->containerSignal((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        case 4: _t->containerSignal((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 5: _t->updateDataBaseSignal((*reinterpret_cast< QMap<QString,QString>(*)>(_a[1]))); break;
        case 6: _t->resultsAnalysisStateSignal((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 7: _t->sendResultSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 8: _t->initParameter((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 9: _t->resultsOfAnalysisSlot((*reinterpret_cast< QMap<int,QString>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QMap<int,QString>(*)>(_a[3]))); break;
        case 10: _t->resultsAnalysisStateslot((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 11: _t->slot_plateSendData((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ResultsAnalysisInterface::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ResultsAnalysisInterface::messageSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ResultsAnalysisInterface::*)(const int & , const QString & , const int & , const QString & , const QString & , const int & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ResultsAnalysisInterface::containerSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ResultsAnalysisInterface::*)(QMap<QString,QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ResultsAnalysisInterface::updateDataBaseSignal)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ResultsAnalysisInterface::*)(const int & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ResultsAnalysisInterface::resultsAnalysisStateSignal)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ResultsAnalysisInterface::*)(int , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ResultsAnalysisInterface::sendResultSignal)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ResultsAnalysisInterface::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ResultsAnalysisInterface.data,
    qt_meta_data_ResultsAnalysisInterface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ResultsAnalysisInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ResultsAnalysisInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ResultsAnalysisInterface.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ResultsAnalysisInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void ResultsAnalysisInterface::messageSignal(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ResultsAnalysisInterface::containerSignal(const int & _t1, const QString & _t2, const int & _t3, const QString & _t4, const QString & _t5, const int & _t6, const QString & _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 5
void ResultsAnalysisInterface::updateDataBaseSignal(QMap<QString,QString> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ResultsAnalysisInterface::resultsAnalysisStateSignal(const int & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ResultsAnalysisInterface::sendResultSignal(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
