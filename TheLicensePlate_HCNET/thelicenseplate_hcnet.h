#ifndef THELICENSEPLATE_HCNET_H
#define THELICENSEPLATE_HCNET_H

#include "thelicenseplate_hcnet_global.h"
#include "thelicenseplate_hcnet_interface.h"
#include "HCNetSDK.h"

class THELICENSEPLATE_HCNETSHARED_EXPORT TheLicensePlate_HCNET:public TheLicensePlate_HCNET_Interface
{
    Q_OBJECT
    Q_INTERFACES(TheLicensePlate_HCNET_Interface)
    Q_PLUGIN_METADATA(IID TheLicensePlate_HCNET_InterfaceIID)

public:
    TheLicensePlate_HCNET(QObject *parent=nullptr);
    ~TheLicensePlate_HCNET();
};

#endif // THELICENSEPLATE_HCNET_H
