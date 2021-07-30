#ifndef NETWORKCONTROLLER_GLOBAL_H
#define NETWORKCONTROLLER_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QNetworkInterface>
#include <QtNetwork/QNetworkDatagram>
#include <QtConcurrent>
#include <QTimer>
#include <QDebug>

#if defined(NETWORKCONTROLLER_LIBRARY)
#  define NETWORKCONTROLLER_EXPORT Q_DECL_EXPORT
#else
#  define NETWORKCONTROLLER_EXPORT Q_DECL_IMPORT
#endif

#endif // NETWORKCONTROLLER_GLOBAL_H
