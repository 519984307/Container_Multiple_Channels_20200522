﻿#ifndef MIDDLEWARECLINET_GLOBAL_H
#define MIDDLEWARECLINET_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QDebug>

#if defined(MIDDLEWARECLINET_LIBRARY)
#  define MIDDLEWARECLINET_EXPORT Q_DECL_EXPORT
#else
#  define MIDDLEWARECLINET_EXPORT Q_DECL_IMPORT
#endif

#endif // MIDDLEWARECLINET_GLOBAL_H