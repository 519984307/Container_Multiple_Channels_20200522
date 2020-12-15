#ifndef THELICENSEPLATEHCNET_H
#define THELICENSEPLATEHCNET_H

#include "TheLicensePlateHCNET_global.h"
#include "ITheLicensePlateHCNET.h"
#include "HCNetSDK.h"

class THELICENSEPLATEHCNET_EXPORT TheLicensePlateHCNET:public ITheLicensePlateHCNET
{
    Q_OBJECT
    Q_INTERFACES(ITheLicensePlateHCNET)
    Q_PLUGIN_METADATA(IID ITheLicensePlateHCNET_IID)

public:
    TheLicensePlateHCNET(QObject *parent=nullptr);
    ~TheLicensePlateHCNET()Q_DECL_OVERRIDE;
};

#endif // THELICENSEPLATEHCNET_H
