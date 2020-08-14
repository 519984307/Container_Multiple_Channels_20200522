#ifndef PARAMETER_H
#define PARAMETER_H

#include <QObject>

class Parameter
{
public:
    Parameter(){};

    /*****************************
    * @brief:Channel
    ******************************/

    ///
    /// \brief ImageNamingRules 图片命名
    ///
    int ImageNamingRules;

    ///
    /// \brief ChannelNumber 通道数量
    ///
    int ChannelNumber;

    ///
    /// \brief ImageFormat 保存图片格式1
    ///
    int ImageFormat;

    ///
    /// \brief ImagePath 图片路径1
    ///
    QString ImagePath;


    /*****************************
    * @brief:Upload
    ******************************/

    ///
    /// \brief FTP 是否启动上传图片
    ///
    int Ftp;

    ///
    /// \brief FtpAddress FTP地址
    ///
    QString FtpAddress;

    ///
    /// \brief FtpLocalPath FTP本地图片路径
    ///
    QString FtpLocalPath;

    ///
    /// \brief FtpPassword FTP密码
    ///
    QString FtpPassword;

    ///
    /// \brief FtpPort FTP端口
    ///
    QString FtpPort;

    ///
    /// \brief FtpRemotePath FTP远端图片地址
    ///
    QString FtpRemotePath;

    ///
    /// \brief FtpUser FTP用户名
    ///
    QString FtpUser;

    ///
    /// \brief ReduceImage 缩小图片
    ///
    int ReduceImage;



    /*****************************
    * @brief:Other
    ******************************/

    ///
    /// \brief Language 语言版本
    ///
    int Language;

    ///
    /// \brief Minimization 启动最小化状态
    ///
    int Minimization;

    ///
    /// \brief Automatic 开机自动启动
    ///
    int Automatic;

    ///
    /// \brief InfoLog 运行日志
    ///
    int InfoLog;

    ///
    /// \brief DebugLog 警告日志
    ///
    int DebugLog;



    /*****************************
    * @brief:Recognizer
    ******************************/

    ///
    /// \brief CheckResult 结果校验
    ///
    int ResultsTheCheck;



    /*****************************
    * @brief:Service
    ******************************/

    ///
    /// \brief ServiceModel 服务模式
    ///
    int ServiceModel;

    ///
    /// \brief SingletonAddress 单例地址
    ///
    QString SingletonAddress;

    ///
    /// \brief ManyCasesAddress 多例地址
    ///
    QString ManyCasesAddress;

    ///
    /// \brief Service_Type 服务类型
    ///
    int Service_Type;

    ///
    /// \brief Heartbeat 心跳包
    ///
    int Heartbeat;

    ///
    /// \brief Resultting 回应结果
    ///
    int Resultting;
};

#endif // PARAMETER_H
