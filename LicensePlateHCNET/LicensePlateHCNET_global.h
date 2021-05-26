#ifndef LICENSEPLATEHCNET_GLOBAL_H
#define LICENSEPLATEHCNET_GLOBAL_H

#include <QtCore/qglobal.h>
//#include <QTimer>
#include <QDebug>

#if defined(LICENSEPLATEHCNET_LIBRARY)
#  define LICENSEPLATEHCNET_EXPORT Q_DECL_EXPORT
#else
#  define LICENSEPLATEHCNET_EXPORT Q_DECL_IMPORT
#endif

#endif // LICENSEPLATEHCNET_GLOBAL_H
