#ifndef LICENSEPLATETCP_GLOBAL_H
#define LICENSEPLATETCP_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QTimer>
#include <QDateTime>
#include <QDebug>

#if defined(LICENSEPLATETCP_LIBRARY)
#  define LICENSEPLATETCP_EXPORT Q_DECL_EXPORT
#else
#  define LICENSEPLATETCP_EXPORT Q_DECL_IMPORT
#endif

#endif // LICENSEPLATETCP_GLOBAL_H
