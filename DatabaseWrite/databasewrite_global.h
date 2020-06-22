#ifndef DATABASEWRITE_GLOBAL_H
#define DATABASEWRITE_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QReadWriteLock>
#include <QMap>
#include <QDir>
#include <QCoreApplication>

#if defined(DATABASEWRITE_LIBRARY)
#  define DATABASEWRITESHARED_EXPORT Q_DECL_EXPORT
#else
#  define DATABASEWRITESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // DATABASEWRITE_GLOBAL_H
