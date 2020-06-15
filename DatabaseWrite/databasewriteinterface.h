#ifndef DATABASEWRITEINTERFACE_H
#define DATABASEWRITEINTERFACE_H

#include <QObject>

class DatabaseWriteInterface : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseWriteInterface(QObject *parent = nullptr);

signals:

public slots:
};

#endif // DATABASEWRITEINTERFACE_H