#ifndef RESULTSANALYSIS_GLOBAL_H
#define RESULTSANALYSIS_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QMap>
#include <QDir>
#include <QDateTime>
#include <QDebug>
#include <QCoreApplication>
#include <QFile>

#if defined(RESULTSANALYSIS_LIBRARY)
#  define RESULTSANALYSISSHARED_EXPORT Q_DECL_EXPORT
#else
#  define RESULTSANALYSISSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // RESULTSANALYSIS_GLOBAL_H
