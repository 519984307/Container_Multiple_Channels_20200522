/****************************************************************************
** Meta object code from reading C++ file 'databaseinsert.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Container_Multiple_Channels_20200522/DatabaseInsert/databaseinsert.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'databaseinsert.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataBaseInsert_t {
    QByteArrayData data[1];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataBaseInsert_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataBaseInsert_t qt_meta_stringdata_DataBaseInsert = {
    {
QT_MOC_LITERAL(0, 0, 14) // "DataBaseInsert"

    },
    "DataBaseInsert"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataBaseInsert[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void DataBaseInsert::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DataBaseInsert::staticMetaObject = { {
    &DataBaseInsertInterface::staticMetaObject,
    qt_meta_stringdata_DataBaseInsert.data,
    qt_meta_data_DataBaseInsert,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DataBaseInsert::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataBaseInsert::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataBaseInsert.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ZBY.ContainerServer.DataBaseInsertInterface/1.3.2"))
        return static_cast< DataBaseInsertInterface*>(this);
    return DataBaseInsertInterface::qt_metacast(_clname);
}

int DataBaseInsert::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataBaseInsertInterface::qt_metacall(_c, _id, _a);
    return _id;
}

QT_PLUGIN_METADATA_SECTION
static constexpr unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x31,  'Z',  'B',  'Y',  '.',  'C', 
    'o',  'n',  't',  'a',  'i',  'n',  'e',  'r', 
    'S',  'e',  'r',  'v',  'e',  'r',  '.',  'D', 
    'a',  't',  'a',  'B',  'a',  's',  'e',  'I', 
    'n',  's',  'e',  'r',  't',  'I',  'n',  't', 
    'e',  'r',  'f',  'a',  'c',  'e',  '/',  '1', 
    '.',  '3',  '.',  '2', 
    // "className"
    0x03,  0x6e,  'D',  'a',  't',  'a',  'B',  'a', 
    's',  'e',  'I',  'n',  's',  'e',  'r',  't', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(DataBaseInsert, DataBaseInsert)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
