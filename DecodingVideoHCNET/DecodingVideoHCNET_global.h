#ifndef DECODINGVIDEOHCNET_GLOBAL_H
#define DECODINGVIDEOHCNET_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QObject>
#include <QtConcurrent>
#include <QImage>
#include <QBuffer>

#if defined(DECODINGVIDEOHCNET_LIBRARY)
#  define DECODINGVIDEOHCNET_EXPORT Q_DECL_EXPORT
#else
#  define DECODINGVIDEOHCNET_EXPORT Q_DECL_IMPORT
#endif

#endif // DECODINGVIDEOHCNET_GLOBAL_H
