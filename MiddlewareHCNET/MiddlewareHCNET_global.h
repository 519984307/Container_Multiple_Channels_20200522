#ifndef MIDDLEWAREHCNET_GLOBAL_H
#define MIDDLEWAREHCNET_GLOBAL_H

#include <QtCore/qglobal.h>

#include <QCoreApplication>
#include <QLibrary>
#include <QSysInfo>
#include <QDir>
#include <QTimer>
#include <QDebug>
#include <QCoreApplication>
#include <QThread>
#include <QDateTime>
#include <QMutexLocker>
#include <QMutex>
#include <QImage>
#include <QBuffer>
#include <QScopedPointer>
#include <QtConcurrent>
#include <QFutureWatcher>

#if defined(MIDDLEWAREHCNET_LIBRARY)
#  define MIDDLEWAREHCNET_EXPORT Q_DECL_EXPORT
#else
#  define MIDDLEWAREHCNET_EXPORT Q_DECL_IMPORT
#endif

#endif // MIDDLEWAREHCNET_GLOBAL_H
