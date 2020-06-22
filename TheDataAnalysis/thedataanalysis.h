#ifndef THEDATAANALYSIS_H
#define THEDATAANALYSIS_H

#include "thedataanalysis_global.h"
#include "thedataanalysisinterface.h"

class THEDATAANALYSISSHARED_EXPORT TheDataAnalysis:public TheDataAnalysisInterface
{
    Q_OBJECT
    Q_INTERFACES(TheDataAnalysisInterface)
    Q_PLUGIN_METADATA(IID TheDataAnalysisInterfaceIID)

public:
    TheDataAnalysis(QObject *parent=nullptr);
    ~TheDataAnalysis()Q_DECL_OVERRIDE;

    ///
    /// \brief InitializationParameterSlot 初始化参数
    ///
    void InitializationParameterSlot()Q_DECL_OVERRIDE;

    ///
    /// \brief resultsOfAnalysisSlot 分析箱号
    /// \param resultList 识别结果集
    /// \param type 逻辑类型
    /// \param imgList 图片名
    ///
    void resultsOfAnalysisSlot(QStringList resultList, int type, QStringList imgList)Q_DECL_OVERRIDE;

    ///
    /// \brief setCheckTheResultsSlot 是否校验识别结果
    /// \param correct 校验标示
    ///
    void setCheckTheResultsSlot(bool correct)Q_DECL_OVERRIDE;

    ///
    /// \brief setChannelSlot 设定通道号
    ///
    void setChannelSlot(int channel)Q_DECL_OVERRIDE;

    ///
    /// \brief sendMidResultSlot 是否发中间结果集
    /// \param state
    ///
    void sendMidResultSlot(bool state)Q_DECL_OVERRIDE;

private:

    ///
    /// \brief updateDataBase 更新数据库
    /// \param type 逻辑箱型
    /// \param Cindex1 箱号下标1
    /// \param Iindex1 箱型下标
    /// \param Cindex2 箱号下标2
    /// \param Iindex2 箱型下标
    ///
    void updateDataBase(int type,int Cindex1, int Iindex1,int Cindex2,int Iindex2,QStringList imgList);

    ///
    /// \brief initCheckMap 初始化校验列表
    ///
    void initCheckMap();

    ///
    /// \brief initScreeningMap 初始化识别结果筛选列表
    ///
    void initScreeningMap();

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
    /// \brief isoToReplace 箱型替换
    /// \param notISO 状态
    /// \param type 箱型类型
    ///
    void isoToReplace(bool notISO,int type);

private:

    ///
    /// \brief ISOContains 箱型包含
    ///
    QByteArray ISOContains;

    ///
    /// \brief ISOReplaceMap 箱型替换
    ///
    QMap<QString,QString> ISOReplaceMap;

    ///
    /// \brief checkMap 校验列表
    ///
    QMap<QChar,int> checkMap;

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
};

#endif // THEDATAANALYSIS_H
