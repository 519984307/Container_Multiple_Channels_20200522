#ifndef PROCESSING_GLOBAL_H
#define PROCESSING_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PROCESSING_LIBRARY)
#  define PROCESSING_EXPORT Q_DECL_EXPORT
#else
#  define PROCESSING_EXPORT Q_DECL_IMPORT
#endif

#endif // PROCESSING_GLOBAL_H
