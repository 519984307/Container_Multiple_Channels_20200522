#ifndef THELICENSEPLATE_HCNET_GLOBAL_H
#define THELICENSEPLATE_HCNET_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(THELICENSEPLATE_HCNET_LIBRARY)
#  define THELICENSEPLATE_HCNETSHARED_EXPORT Q_DECL_EXPORT
#else
#  define THELICENSEPLATE_HCNETSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // THELICENSEPLATE_HCNET_GLOBAL_H