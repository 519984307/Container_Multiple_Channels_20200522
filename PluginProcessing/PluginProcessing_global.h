#ifndef PLUGINPROCESSING_GLOBAL_H
#define PLUGINPROCESSING_GLOBAL_H

#include <QtCore/qglobal.h>

#include <QDir>
#include <QPluginLoader>
#include <QCoreApplication>
#include <QMessageLogger>
#include <QPointer>

#if defined(PLUGINPROCESSING_LIBRARY)
#  define PLUGINPROCESSING_EXPORT Q_DECL_EXPORT
#else
#  define PLUGINPROCESSING_EXPORT Q_DECL_IMPORT
#endif

#endif // PLUGINPROCESSING_GLOBAL_H
