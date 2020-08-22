#ifndef LOG_GLOBAL_H
#define LOG_GLOBAL_H

#include <QtCore/qglobal.h>

#include <QObject>
#include <QDebug>
#include <QTime>
#include <QFile>
#include <QDir>
#include <QPointer>
#include <QScopedPointer>
#include <QStandardPaths>
#include <QMessageLogger>

#if defined(LOG_LIBRARY)
#  define LOG_EXPORT Q_DECL_EXPORT
#else
#  define LOG_EXPORT Q_DECL_IMPORT
#endif

#endif // LOG_GLOBAL_H
