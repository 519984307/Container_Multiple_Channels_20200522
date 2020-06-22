#ifndef THELICENSEPLATE_WTY_GLOBAL_H
#define THELICENSEPLATE_WTY_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QLibrary>
#include <QDir>
#include <QDateTime>
#include <QMutexLocker>
#include <QMutex>
#include <QPixmap>
#include <QCoreApplication>

#if defined(THELICENSEPLATE_WTY_LIBRARY)
#  define THELICENSEPLATE_WTYSHARED_EXPORT Q_DECL_EXPORT
#else
#  define THELICENSEPLATE_WTYSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // THELICENSEPLATE_WTY_GLOBAL_H
