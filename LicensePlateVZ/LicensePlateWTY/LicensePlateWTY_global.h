#ifndef LICENSEPLATEWTY_GLOBAL_H
#define LICENSEPLATEWTY_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QLibrary>
#include <QDir>
#include <QDateTime>
#include <QMutexLocker>
#include <QMutex>
#include <QDebug>
#include <QCoreApplication>
#include <QThread>
#include <QTimer>

#if defined(LICENSEPLATEWTY_LIBRARY)
#  define LICENSEPLATEWTY_EXPORT Q_DECL_EXPORT
#else
#  define LICENSEPLATEWTY_EXPORT Q_DECL_IMPORT
#endif

#endif // LICENSEPLATEWTY_GLOBAL_H
