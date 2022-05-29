#ifndef IDENTIFYIMAGES_GLOBAL_H
#define IDENTIFYIMAGES_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QThreadPool>
#include <QThread>
#include <QDebug>
#include <QSharedPointer>
#include <QMap>
#include <QTimer>

#if defined(IDENTIFYIMAGES_LIBRARY)
#  define IDENTIFYIMAGESSHARED_EXPORT Q_DECL_EXPORT
#else
#  define IDENTIFYIMAGESSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // IDENTIFYIMAGES_GLOBAL_H
