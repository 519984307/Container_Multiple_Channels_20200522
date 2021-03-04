/****************************************************************************
** Meta object code from reading C++ file 'resultsanalysis.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Container_Multiple_Channels_20200522/ResultsAnalysis/resultsanalysis.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'resultsanalysis.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ResultsAnalysis_t {
    QByteArrayData data[1];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ResultsAnalysis_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ResultsAnalysis_t qt_meta_stringdata_ResultsAnalysis = {
    {
QT_MOC_LITERAL(0, 0, 15) // "ResultsAnalysis"

    },
    "ResultsAnalysis"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ResultsAnalysis[] = {

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

void ResultsAnalysis::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ResultsAnalysis::staticMetaObject = { {
    &ResultsAnalysisInterface::staticMetaObject,
    qt_meta_stringdata_ResultsAnalysis.data,
    qt_meta_data_ResultsAnalysis,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ResultsAnalysis::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ResultsAnalysis::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ResultsAnalysis.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ZBY.ContainerServer.ResultsAnalysisInterface/2.6.4.5"))
        return static_cast< ResultsAnalysisInterface*>(this);
    return ResultsAnalysisInterface::qt_metacast(_clname);
}

int ResultsAnalysis::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ResultsAnalysisInterface::qt_metacall(_c, _id, _a);
    return _id;
}

QT_PLUGIN_METADATA_SECTION
static constexpr unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x34,  'Z',  'B',  'Y',  '.',  'C', 
    'o',  'n',  't',  'a',  'i',  'n',  'e',  'r', 
    'S',  'e',  'r',  'v',  'e',  'r',  '.',  'R', 
    'e',  's',  'u',  'l',  't',  's',  'A',  'n', 
    'a',  'l',  'y',  's',  'i',  's',  'I',  'n', 
    't',  'e',  'r',  'f',  'a',  'c',  'e',  '/', 
    '2',  '.',  '6',  '.',  '4',  '.',  '5', 
    // "className"
    0x03,  0x6f,  'R',  'e',  's',  'u',  'l',  't', 
    's',  'A',  'n',  'a',  'l',  'y',  's',  'i', 
    's', 
    // "MetaData"
    0x04,  0xa2,  0x65,  'c',  'l',  'a',  's',  's', 
    0x6f,  'R',  'e',  's',  'u',  'l',  't',  's', 
    'A',  'n',  'a',  'l',  'y',  's',  'i',  's', 
    0x63,  'v',  'e',  'r',  0x65,  '2',  '.',  '3', 
    '.',  '2', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(ResultsAnalysis, ResultsAnalysis)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
