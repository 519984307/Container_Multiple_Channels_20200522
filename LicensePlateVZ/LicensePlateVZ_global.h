#ifndef LICENSEPLATEVZ_GLOBAL_H
#define LICENSEPLATEVZ_GLOBAL_H

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

#if defined(LICENSEPLATEVZ_LIBRARY)
#  define LICENSEPLATEVZ_EXPORT Q_DECL_EXPORT
#else
#  define LICENSEPLATEVZ_EXPORT Q_DECL_IMPORT
#endif

#endif // LICENSEPLATEVZ_GLOBAL_H
