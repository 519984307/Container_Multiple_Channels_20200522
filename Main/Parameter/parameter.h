#ifndef PARAMETER_H
#define PARAMETER_H

#include <QString>

namespace Parameter {
    /*****************************
    * @brief:Channel
    ******************************/

    ///
    /// \brief ImageNamingRules 图片命名
    ///
    extern int ImageNamingRules;

    ///
    /// \brief ChannelNumber 通道数量
    ///
    extern int ChannelNumber;

    ///
    /// \brief ImageFormat 保存图片格式1
    ///
    extern int ImageFormat;

    ///
    /// \brief ImagePath 图片路径1
    ///
    extern QString ImagePath;


    /*****************************
    * @brief:Upload
    ******************************/

    ///
    /// \brief FTP 是否启动上传图片
    ///
    extern int Ftp;

    ///
    /// \brief FtpAddress FTP地址
    ///
    extern QString FtpAddress;

    ///
    /// \brief FtpLocalPath FTP本地图片路径
    ///
    extern QString FtpLocalPath;

    ///
    /// \brief FtpPassword FTP密码
    ///
    extern QString FtpPassword;

    ///
    /// \brief FtpPort FTP端口
    ///
    extern int FtpPort;

    ///
    /// \brief FtpRemotePath FTP远端图片地址
    ///
    extern QString FtpRemotePath;

    ///
    /// \brief FtpUser FTP用户名
    ///
    extern QString FtpUser;

    ///
    /// \brief ReduceImage 缩小图片
    ///
    extern int ReduceImage;

    ///
    /// \brief DatabaseType 数据库类型
    ///
    extern int DatabaseType;

    ///
    /// \brief databaseAddr 数据库地址
    ///
    extern QString databaseAddr;

    ///
    /// \brief databaseUser 数据库用户名
    ///
    extern QString databaseUser;

    ///
    /// \brief databasePass 数据库密码
    ///
    extern QString databasePass;

    /*****************************
    * @brief:Other
    ******************************/

    ///
    /// \brief Language 语言版本
    ///
    extern int Language;

    ///
    /// \brief Minimization 启动最小化状态
    ///
    extern int Minimization;

    ///
    /// \brief FullScreen 全屏显示
    ///
    extern int FullScreen;

    ///
    /// \brief Automatic 开机自动启动
    ///
    extern int Automatic;

    ///
    /// \brief DelayStart 延时启动
    ///
    extern int DelayStart;

    ///
    /// \brief InfoLog 运行日志
    ///
    extern int InfoLog;

    ///
    /// \brief DebugLog 警告日志
    ///
    extern int DebugLog;



    /*****************************
    * @brief:Recognizer
    ******************************/

    ///
    /// \brief CheckResult 结果校验
    ///
    extern int ResultsTheCheck;



    /*****************************
    * @brief:Service
    ******************************/

    ///
    /// \brief ServiceModel 服务模式
    ///
    extern int ServiceModel;

    ///
    /// \brief SingletonAddress 单例地址
    ///
    extern QString SingletonAddress;

    ///
    /// \brief ManyCasesAddress 多例地址
    ///
    extern QString ManyCasesAddress;

    ///
    /// \brief Service_Type 服务类型
    ///
    extern int Service_Type;

    ///
    /// \brief Heartbeat 心跳包
    ///
    extern int Heartbeat;

    ///
    /// \brief Resultting 回应结果
    ///
    extern int Resultting;
}

#endif // PARAMETER_H
