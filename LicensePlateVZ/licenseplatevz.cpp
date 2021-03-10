#include "licenseplatevz.h"

LicensePlateVZ::LicensePlateVZ(QObject *parent)
{

}

LicensePlateVZ::~LicensePlateVZ()
{

}

QString LicensePlateVZ::InterfaceType()
{

}

void LicensePlateVZ::simulationCaptureSlot()
{

}

void LicensePlateVZ::liftingElectronicRailingSlot(bool gate)
{

}

void LicensePlateVZ::transparentTransmission485Slot(const QString &msg)
{

}

void LicensePlateVZ::openTheVideoSlot(bool play, quint64 winID)
{

}

void LicensePlateVZ::releaseResourcesSlot()
{

}

void LicensePlateVZ::initCamerSlot(const QString &localAddr, const QString &camerIP, const int &camerPort, const QString &CamerUser, const QString &CamerPow, const QString &signature)
{

}

bool LicensePlateVZ::initializationParameter()
{

}

int LicensePlateVZ::PLATE_INFO_CALLBACK(VzLPRClientHandle handle, void *pUserData, const TH_PlateResult *pResult, unsigned uNumPlates, VZ_LPRC_RESULT_TYPE eResultType, const VZ_LPRC_IMAGE_INFO *pImgFull, const VZ_LPRC_IMAGE_INFO *pImgPlateClip)
{

}

void LicensePlateVZ::SERIAL_RECV_DATA_CALLBACK(int nSerialHandle, const unsigned char *pRecvData, unsigned uRecvSize, void *pUserData)
{

}

void LicensePlateVZ::COMMON_NOTIFY_CALLBACK(VzLPRClientHandle handle, void *pUserData, VZ_LPRC_COMMON_NOTIFY eNotify, const char *pStrDetail)
{

}

void LicensePlateVZ::autoLinkCamer()
{

}

void LicensePlateVZ::slot_pictureStream(int ID, QByteArray arrJpg)
{

}

void LicensePlateVZ::slot_setCameraID(int ID, QString cameraIP)
{

}

void LicensePlateVZ::slot_resultsTheLicensePlate(int ID, const QString &plate, const QString &color, const QString &time, const QByteArray &arrImg)
{

}

void LicensePlateVZ::slot_equipmentState(int ID, bool state)
{

}
