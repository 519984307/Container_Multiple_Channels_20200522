#ifndef DECODINGTHEVIDEO_H
#define DECODINGTHEVIDEO_H

#include "DecodingTheVideo_global.h"

//必须加以下内容,否则编译不能通过,为了兼容C和C99标准
#ifndef INT64_C
#define INT64_C
#define UINT64_C
#endif

//引入ffmpeg头文件
extern "C" {
#include "libavutil/opt.h"
#include "libavutil/time.h"
#include "libavutil/frame.h"
#include "libavutil/pixdesc.h"
#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/ffversion.h"
#include "libavcodec/avcodec.h"
#include "libswscale/swscale.h"
#include "libswresample/swresample.h"
#include "libavformat/avformat.h"
#include "libavfilter/avfilter.h"

#ifdef ffmpegdevice
#include "libavdevice/avdevice.h"
#endif

#ifndef gcc45
#include "libavutil/hwcontext.h"
#include "libavutil/hwcontext_qsv.h"
#endif
}

class DECODINGTHEVIDEO_EXPORT DecodingTheVideo
{
public:
    DecodingTheVideo();

    AVCodecContext *pAVCodecCtx_decoder;
    AVCodec *pAVCodec_decoder;
    AVPacket mAVPacket_decoder;
    AVFrame *pAVFrame_decoder;
    SwsContext* pImageConvertCtx_decoder;
    AVFrame *pFrameYUV_decoder;

    /**
     视频流解码器初始化
     @param ctx 解码参数结构体AVCodecParameters
     @see FFmpeg_H264DecoderInit，此为解码H264视频流
     @return 初始化成功返回0，否则<0
     */
    int FFmpeg_VideoDecoderInit(AVCodecParameters *codecParameters);

    /**
     H264视频流解码器初始化
     @return 初始化成功返回0，否则<0
     */
    int FFmpeg_H264DecoderInit(void);

    /**
     释放解码器
     @return 初始化成功返回0，否则<0
     */
    int FFmpeg_VideoDecoderRelease(void);

    //return 0:暂未收到解码数据，-1：解码失败，1：解码成功

    /**
     解码视频流数据
     @param inbuf 视频裸流数据
     @param inbufSize 视频裸流数据大小
     @param framePara 接收帧参数数组：{width,height,linesize1,linesiz2,linesize3}
     @param outRGBBuf 输出RGB数据(若已申请内存)
     @param outYUVBuf 输出YUV数据(若已申请内存)
     @return 成功返回解码数据帧大小，否则<=0
     */
    int FFmpeg_H264Decode(unsigned char * inbuf, int inbufSize, int *framePara, unsigned char *outRGBBuf, unsigned char **outYUVBuf);
};

#endif // DECODINGTHEVIDEO_H
