#ifndef CAPTUREIMAGES_GLOBAL_H
#define CAPTUREIMAGES_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QCoreApplication>
#include <QObject>
#include <QTimer>
#include <QDebug>

#if defined(CAPTUREIMAGES_LIBRARY)
#  define CAPTUREIMAGESSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CAPTUREIMAGESSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CAPTUREIMAGES_GLOBAL_H
