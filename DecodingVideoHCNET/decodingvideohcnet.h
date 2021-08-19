#ifndef DECODINGVIDEOHCNET_H
#define DECODINGVIDEOHCNET_H

#define IMG_BYTE 1920*1080+1

#include "DecodingVideoHCNET_global.h"

#include "IDecodingVideo.h"
#include "plaympeg4.h"
#include "HCNetSDK.h"

class DECODINGVIDEOHCNET_EXPORT DecodingVideoHCNET:public IDecodingVideo
{
    Q_OBJECT
    Q_INTERFACES(IDecodingVideo)
    Q_PLUGIN_METADATA(IID IDecodingVideoIID)

public:
    DecodingVideoHCNET();
    ~DecodingVideoHCNET()Q_DECL_OVERRIDE;

    QString InterfaceType()Q_DECL_OVERRIDE;

    void *getCallBack()Q_DECL_OVERRIDE;
    long getReadHanlde()Q_DECL_OVERRIDE;
    void setReadHanlde(long handle)Q_DECL_OVERRIDE;


    ///
    /// \brief imgBuff 图片流内存(主动申请和释放)
    ///
    char* imgBuff;


    static DecodingVideoHCNET *pThis;
    static long lPort;
    int putID;
    long handle;


    ///
    /// \brief g_RealDataCallBack_V30 预览回调函数
    /// \param lRealHandle 当前的预览句柄，NET_DVR_RealPlay_V40的返回值
    /// \param dwDataType 数据类型 宏定义 宏定义值 含义
    /// \param pBuffer 存放数据的缓冲区指针
    /// \param dwBufSize 缓冲区大小
    /// \param dwUser 用户数据
    ///
    static void CALLBACK g_RealDataCallBack_V30(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize,void* dwUser);

    ///
    /// \brief DecCallBack 解码流回调函数
    /// \param nPort
    /// \param pBuf
    /// \param nSize
    /// \param pFrameInfo
    /// \param luser
    /// \param nReserved2
    ///
    static void CALLBACK DecCallBack(long nPort, char *pBuf, long nSize, FRAME_INFO *pFrameInfo, long luser, long nReserved2);

    ///
    /// \brief yv12ToRGB888 yv12转RGB888
    /// \param yv12
    /// \param rgb888
    /// \param width
    /// \param height
    /// \return
    ///
    void yv12ToRGB888(int ID, int width, int height, unsigned char *yv12, long nPort);

    ///
    /// \brief slot_getPictureStream 抓取图片
    /// \param putID
    ///
    void slot_getPictureStream(int ID,long lReadHandle)Q_DECL_OVERRIDE;

    ///
    /// \brief releaseResourcesSlot 释放动态库资源
    ///
    void releaseResourcesSlot(int ID)Q_DECL_OVERRIDE;
};

#endif // DECODINGVIDEOHCNET_H
