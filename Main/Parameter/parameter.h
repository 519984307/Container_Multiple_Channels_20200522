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
    /// \brief camera_id_placeholder 相机编号占用位数
    ///
    extern int camera_id_placeholder;

    ///
    /// \brief channel_id_placeholder 通道编号占用位数
    ///
    extern int channel_id_placeholder;

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
    * @brief:Model
    ******************************/

    ///
    /// \brief loadLibrary_HK 隐式加载海康动态库
    ///
    extern int loadLibrary_HK;

    ///
    /// \brief HCNET_Type 海康相机抓拍类型
    ///
    extern int HCNET_Capture_Type;

    ///
    /// \brief Camera_Load_Plugin 相机插件加载类型
    ///
    extern int Camera_Load_Plugin;

    ///
    /// \brief LogicType 红外逻辑类型
    ///
    extern int LogicType;

    ///
    /// \brief PlateType 车牌相机类型
    ///
    extern int PlateType;

    ///
    /// \brief interfaceModel 信号接口模式
    ///
    extern int interfaceModel;

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

    ///
    /// \brief picture_size 识别图片大小
    ///
    extern int picture_size;

    /*****************************
    * @brief:Service
    ******************************/

    ///
    /// \brief Service_Model 服务模式
    ///
    extern int Service_Model;

    ///
    /// \brief SingletonAddress 单例地址
    ///
    extern QString SingletonAddress;

    ///
    /// \brief ManyCasesAddress 多例地址
    ///
    extern QString ManyCasesAddress;

    ///
    /// \brief SingletonAddressMQ 单例地址
    ///
    extern QString SingletonAddressMQ;

    ///
    /// \brief ManyCasesAddressMQ 多例地址
    ///
    extern QString ManyCasesAddressMQ;

    ///
    /// \brief Service_Type 服务类型
    ///
    extern int Service_Type;

    ///
    /// \brief Identify_Protocol 接口协议
    ///
    extern int Identify_Protocol;

    ///
    /// \brief Heartbeat 心跳包
    ///
    extern int Heartbeat;

    ///
    /// \brief Resultting 回应结果
    ///
    extern int Resultting;

    ///
    /// \brief ShortLink 短链接,主动断开
    ///
    extern int ShortLink;

    ///
    /// \brief newline 信息添加换行符
    ///
    extern int newline;

    ///
    /// \brief DataChaneType 数据接口模式
    ///
    extern int DataChaneType;

    ///
    /// \brief DataChange_Format 数据接口格式
    ///
    extern int DataChange_Format;

    ///
    /// \brief plate_timeout 车牌结果超时
    ///
    extern int plate_timeout;

    ///
    /// \brief container_timeout 集装箱结果超时时间
    ///
    extern int container_timeout;

    ///
    /// \brief not_plate_color 接口协议不需要车牌颜色
    ///
    extern int not_plate_color;

    /*****************************
    * @brief:storage
    ******************************/

    ///
    /// \brief storage_monitoring 硬盘监测状态
    ///
    extern int storage_monitoring;

    ///
    /// \brief storage_value 硬盘监测值
    ///
    extern int storage_value;
}

#endif // PARAMETER_H
