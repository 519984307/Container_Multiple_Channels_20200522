#ifndef CAPTUREIMAGES_SDK_HCNET_GLOBAL_H
#define CAPTUREIMAGES_SDK_HCNET_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QCoreApplication>
#include <QLibrary>
#include <QSysInfo>
#include <QObject>
#include <QDir>
#include <QTimer>
#include <QDebug>

#if defined(CAPTUREIMAGES_SDK_HCNET_LIBRARY)
#  define CAPTUREIMAGES_SDK_HCNETSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CAPTUREIMAGES_SDK_HCNETSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CAPTUREIMAGES_SDK_HCNET_GLOBAL_H
