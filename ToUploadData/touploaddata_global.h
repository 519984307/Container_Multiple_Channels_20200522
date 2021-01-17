#ifndef TOUPLOADDATA_GLOBAL_H
#define TOUPLOADDATA_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QFile>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDebug>
#include <QRegExp>
#include <QMutexLocker>
#include <QMutex>
#include <QDir>
#include <QPointer>
#include <QTimer>

#if defined(TOUPLOADDATA_LIBRARY)
#  define TOUPLOADDATASHARED_EXPORT Q_DECL_EXPORT
#else
#  define TOUPLOADDATASHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // TOUPLOADDATA_GLOBAL_H
