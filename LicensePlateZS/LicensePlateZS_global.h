#ifndef LICENSEPLATEZS_GLOBAL_H
#define LICENSEPLATEZS_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QTcpSocket>
#include <QTimer>
#include <QJsonObject>
#include <QJsonDocument>
#include <QtConcurrent>
#include <QDateTime>

#if defined(LICENSEPLATEZS_LIBRARY)
#  define LICENSEPLATEZS_EXPORT Q_DECL_EXPORT
#else
#  define LICENSEPLATEZS_EXPORT Q_DECL_IMPORT
#endif

#endif // LICENSEPLATEZS_GLOBAL_H
