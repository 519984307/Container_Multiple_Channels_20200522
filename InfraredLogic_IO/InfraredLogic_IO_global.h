#ifndef INFRAREDLOGIC_IO_GLOBAL_H
#define INFRAREDLOGIC_IO_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QTimer>
#include <QThread>
#include <QCoreApplication>
#include <QtConcurrent>
#include <QReadWriteLock>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QFile>
#include <QDebug>

#if defined(INFRAREDLOGIC_IO_LIBRARY)
#  define INFRAREDLOGIC_IO_EXPORT Q_DECL_EXPORT
#else
#  define INFRAREDLOGIC_IO_EXPORT Q_DECL_IMPORT
#endif

#endif // INFRAREDLOGIC_IO_GLOBAL_H
