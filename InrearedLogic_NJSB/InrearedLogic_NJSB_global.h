#ifndef INREAREDLOGIC_NJSB_GLOBAL_H
#define INREAREDLOGIC_NJSB_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QTimer>
#include <QThread>
#include <QtSerialPort/QSerialPort>
#include <QCoreApplication>
#include <QtConcurrent>
#include <QDebug>

#if defined(INREAREDLOGIC_NJSB_LIBRARY)
#  define INREAREDLOGIC_NJSB_EXPORT Q_DECL_EXPORT
#else
#  define INREAREDLOGIC_NJSB_EXPORT Q_DECL_IMPORT
#endif

#endif // INREAREDLOGIC_NJSB_GLOBAL_H
