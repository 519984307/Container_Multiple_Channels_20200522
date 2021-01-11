#ifndef PARAMETER_GLOBAL_H
#define PARAMETER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PARAMETER_LIBRARY)
#  define PARAMETER_EXPORT Q_DECL_EXPORT
#else
#  define PARAMETER_EXPORT Q_DECL_IMPORT
#endif

#endif // PARAMETER_GLOBAL_H
