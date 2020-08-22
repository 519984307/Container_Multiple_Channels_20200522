#ifndef PARAMETER_H
#define PARAMETER_H

#include <QObject>

class Parameter
{
public:
    Parameter();

    /*****************************
    * @brief:Channel
    ******************************/

    ///
    /// \brief ImageNamingRules 图片命名
    ///
    static int ImageNamingRules;

    ///
    /// \brief ChannelNumber 通道数量
    ///
    static int ChannelNumber;

    ///
    /// \brief ImageFormat 保存图片格式1
    ///
    static int ImageFormat;

    ///
    /// \brief ImagePath 图片路径1
    ///
    static QString ImagePath;


    /*****************************
    * @brief:Upload
    ******************************/

    ///
    /// \brief FTP 是否启动上传图片
    ///
    static int Ftp;

    ///
    /// \brief FtpAddress FTP地址
    ///
    static QString FtpAddress;

    ///
    /// \brief FtpLocalPath FTP本地图片路径
    ///
    static QString FtpLocalPath;

    ///
    /// \brief FtpPassword FTP密码
    ///
    static QString FtpPassword;

    ///
    /// \brief FtpPort FTP端口
    ///
    static int FtpPort;

    ///
    /// \brief FtpRemotePath FTP远端图片地址
    ///
    static QString FtpRemotePath;

    ///
    /// \brief FtpUser FTP用户名
    ///
    static QString FtpUser;

    ///
    /// \brief ReduceImage 缩小图片
    ///
    static int ReduceImage;



    /*****************************
    * @brief:Other
    ******************************/

    ///
    /// \brief Language 语言版本
    ///
    static int Language;

    ///
    /// \brief Minimization 启动最小化状态
    ///
    static int Minimization;

    ///
    /// \brief Automatic 开机自动启动
    ///
    static int Automatic;

    ///
    /// \brief InfoLog 运行日志
    ///
    static int InfoLog;

    ///
    /// \brief DebugLog 警告日志
    ///
    static int DebugLog;



    /*****************************
    * @brief:Recognizer
    ******************************/

    ///
    /// \brief CheckResult 结果校验
    ///
    static int ResultsTheCheck;



    /*****************************
    * @brief:Service
    ******************************/

    ///
    /// \brief ServiceModel 服务模式
    ///
    static int ServiceModel;

    ///
    /// \brief SingletonAddress 单例地址
    ///
    static QString SingletonAddress;

    ///
    /// \brief ManyCasesAddress 多例地址
    ///
    static QString ManyCasesAddress;

    ///
    /// \brief Service_Type 服务类型
    ///
    static int Service_Type;

    ///
    /// \brief Heartbeat 心跳包
    ///
    static int Heartbeat;

    ///
    /// \brief Resultting 回应结果
    ///
    static int Resultting;
};

#endif // PARAMETER_H
