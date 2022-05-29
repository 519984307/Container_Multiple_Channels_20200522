#ifndef TOUPLOADDATA2_GLOBAL_H
#define TOUPLOADDATA2_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QMutexLocker>
#include <QMutex>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QTimer>

#if defined(TOUPLOADDATA2_LIBRARY)
#  define TOUPLOADDATA2_EXPORT Q_DECL_EXPORT
#else
#  define TOUPLOADDATA2_EXPORT Q_DECL_IMPORT
#endif

#endif // TOUPLOADDATA2_GLOBAL_H
