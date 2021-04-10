#ifndef DATAINTERRABBITMQ_GLOBAL_H
#define DATAINTERRABBITMQ_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QSharedPointer>
#include <QScopedPointer>
#include <QPointer>

#if defined(DATAINTERRABBITMQ_LIBRARY)
#  define DATAINTERRABBITMQ_EXPORT Q_DECL_EXPORT
#else
#  define DATAINTERRABBITMQ_EXPORT Q_DECL_IMPORT
#endif

#endif // DATAINTERRABBITMQ_GLOBAL_H
