﻿#ifndef CAPTUREUNDERLYING_GLOBAL_H
#define CAPTUREUNDERLYING_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QThread>
#include <QTimer>
#include <QtNetwork/QSctpSocket>
#include <QDebug>

#if defined(CAPTUREUNDERLYING_LIBRARY)
#  define CAPTUREUNDERLYINGSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CAPTUREUNDERLYINGSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CAPTUREUNDERLYING_GLOBAL_H
