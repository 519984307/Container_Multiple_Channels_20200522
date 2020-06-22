#ifndef THELICENSEPLATE_HCNET_INTERFACE_H
#define THELICENSEPLATE_HCNET_INTERFACE_H

#define ZBY_LOG(type)  tr("[%1][%2][%3]").arg(type).arg(Q_FUNC_INFO).arg(__LINE__)

#include <QObject>

class TheLicensePlate_HCNET_Interface : public QObject
{
    Q_OBJECT

public:
    virtual ~ TheLicensePlate_HCNET_Interface(){}

signals:

public slots:
};

#define TheLicensePlate_HCNET_InterfaceIID "ZBY.ContainerServer.TheLicensePlate_HCNET_Interface/1.0"
Q_DECLARE_INTERFACE(TheLicensePlate_HCNET_Interface,TheLicensePlate_HCNET_InterfaceIID);

#endif // THELICENSEPLATE_HCNET_INTERFACE_H
