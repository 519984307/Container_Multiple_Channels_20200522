#ifndef RESULTSANALYSIS_H
#define RESULTSANALYSIS_H

#include "resultsanalysis_global.h"
#include "resultsanalysisinterface.h"

class RESULTSANALYSISSHARED_EXPORT ResultsAnalysis:public ResultsAnalysisInterface
{
    Q_OBJECT
    Q_INTERFACES(ResultsAnalysisInterface)
    Q_PLUGIN_METADATA(IID ResultsAnalysisInterfaceIID FILE "mymetadata.json")

public:
    ResultsAnalysis(QObject* parent=nullptr);
    ~ResultsAnalysis()Q_DECL_OVERRIDE;

    ///
    /// \brief InterfaceType 插件类型，多插件调用统一接口
    /// \return
    ///
    QString InterfaceType()Q_DECL_OVERRIDE;

private:

    ///
    /// \brief isConCar 是否为集装箱车辆
    ///
    bool isConCar;

    ///
    /// \brief plate 车牌
    ///
    QString plate;

    ///
    /// \brief plateColor 车牌颜色
    ///
    QString plateColor;

    ///
    /// \brief plateTime 车牌时间
    ///
    QString plateTime;

    ///
    /// \brief Identify_Protocol 数据协议类型
    ///
    int Identify_Protocol;

public:

    ///
    /// \brief initParameter 初始化参数
    /// \param channel
    /// \param check
    /// \param sendMid
    ///
    void initParameter(const int &channel,const int &ImageNamingRules ,bool check,bool sendMid)Q_DECL_OVERRIDE;

    ///
    /// \brief resultsOfAnalysisSlot 分析箱号
    /// \param resultMap 识别结果集
    /// \param type 逻辑类型
    /// \param imgNameMap 图片名
    ///
    void resultsOfAnalysisSlot(QMap<int,QString> resultMap, int type,QMap<int,QString> imgNameMap)Q_DECL_OVERRIDE;

    ///
    /// \brief resultsAnalysisStateSignal 识别结果写入日志
    /// \param msg 信息体
    ///
    void resultsAnalysisStateslot(const int& channel, const QString& msg)Q_DECL_OVERRIDE;

    ///
    /// \brief slot_plateSendData 发送车牌数据
    /// \param Identify_Protocol
    /// \param isConCar
    /// \param channelNumber
    /// \param plate
    /// \param color
    /// \param time
    ///
    void slot_plateSendData(const int &Identify_Protocol,const bool &isConCar,const QString &plate,const QString &color,const QString &time)Q_DECL_OVERRIDE;

private:

    ///
    /// \brief updateDataBase 更新数据库
    /// \param type 逻辑箱型
    /// \param Cindex1 箱号下标1
    /// \param Iindex1 箱型下标
    /// \param Cindex2 箱号下标2
    /// \param Iindex2 箱型下标
    ///
    void updateDataBase(int type, int Cindex1, int Iindex1, int Cindex2, int Iindex2, QMap<int, QString> imgMap);

    ///
    /// \brief initCheckMap 初始化校验列表
    ///
    void initCheckMap();

    ///
    /// \brief computeQuadraticPower 计算箱号位的二次方
    /// \param variable 箱号数位
    /// \return 计算结果
    ///
    int computeQuadraticPower(int variable);

    ///
    /// \brief numberCheck 集装箱号码校验
    /// \param number 集装箱号码
    /// \return  校验结果
    ///
    bool numberCheck(QString &number);

    ///
    /// \brief queueContainerNumber 统计箱号出现次数，分析箱号
    /// \param QStringList
    /// \return
    ///
    QStringList queueContainerNumber(QStringList list);

    ///
    /// \brief checkContainerNumber 校验箱号
    /// \param start 下标起始
    /// \param end 下标结束
    /// \return
    ///
    QList<int> checkContainerNumber(int start,int end);

    ///
    /// \brief ConsecutiveLCS 计算两个结果相似度
    /// \param rs1
    /// \param rs2
    /// \return
    ///
    int ConsecutiveLCS(QString rs1,QString rs2);

private:

    ///
    /// \brief ISOContains 箱型包含
    ///
    QStringList ISOContains;

    ///
    /// \brief ISOReplaceMap 箱型替换
    ///
    QMap<QString,QString> ISOReplaceMap;

    ///
    /// \brief checkMap 校验列表
    ///
    QMap<QChar,int> checkMap;

    ///
    /// \brief conProbabilityTemp 箱号置信度
    ///
    QList<uint32_t> conProbabilityTemp;

    ///
    /// \brief isoProbabilityTemp 箱型置信度
    ///
    QList<uint32_t> isoProbabilityTemp;

    ///
    /// \brief conTemp 箱号列表
    ///
    QStringList conTemp;

    ///
    /// \brief isoTemp 箱型列表
    ///
    QStringList isoTemp;

    ///
    /// \brief checkConList 箱号校验列表
    ///
    QList<int> checkConList;

    ///
    /// \brief correct 校验标志
    ///
    bool correct;

    ///
    /// \brief channel 通道号
    ///
    int channel;

    ///
    /// \brief sendMid 是否发送中间结果集
    ///
    bool sendMid;

    ///
    /// \brief ImageNamingRules 图片命名规则
    ///
    int ImageNamingRules;

    ///
    /// \brief logFile 日志文件
    ///
    QFile logFile;

    ///
    /// \brief lock 写入锁
    ///
    QReadWriteLock lock;
};

#endif // RESULTSANALYSIS_H
