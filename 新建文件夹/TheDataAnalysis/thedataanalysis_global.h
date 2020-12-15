#ifndef THEDATAANALYSIS_GLOBAL_H
#define THEDATAANALYSIS_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QMap>
#include <QDir>
#include <QDateTime>
#include <QDebug>
#include <QCoreApplication>
#include <QFile>

#if defined(THEDATAANALYSIS_LIBRARY)
#  define THEDATAANALYSISSHARED_EXPORT Q_DECL_EXPORT
#else
#  define THEDATAANALYSISSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // THEDATAANALYSIS_GLOBAL_H
