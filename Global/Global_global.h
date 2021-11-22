#ifndef GLOBAL_GLOBAL_H
#define GLOBAL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(GLOBAL_LIBRARY)
#  define GLOBAL_EXPORT Q_DECL_EXPORT
#else
#  define GLOBAL_EXPORT Q_DECL_IMPORT
#endif

#endif // GLOBAL_GLOBAL_H
