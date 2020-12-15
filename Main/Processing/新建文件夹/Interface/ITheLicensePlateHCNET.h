#ifndef ITHELICENSEPLATEHCNET_H
#define ITHELICENSEPLATEHCNET_H

#include <QObject>

class ITheLicensePlateHCNET : public QObject
{
    Q_OBJECT

public:
    virtual ~ ITheLicensePlateHCNET(){}

signals:

public slots:
};

#define ITheLicensePlateHCNET_IID "ZBY.ContainerServer.ITheLicensePlateHCNET/1.1"
Q_DECLARE_INTERFACE(ITheLicensePlateHCNET,ITheLicensePlateHCNET_IID);


#endif // ITHELICENSEPLATEHCNET_H
