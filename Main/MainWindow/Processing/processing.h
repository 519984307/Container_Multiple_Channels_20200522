#ifndef PROCESSING_H
#define PROCESSING_H

#include <QObject>

#include "logcontroller.h"

class Processing : public QObject
{
    Q_OBJECT
public:
    explicit Processing(QObject *parent = nullptr);

    LogController *p_LogController;

signals:

};

#endif // PROCESSING_H
