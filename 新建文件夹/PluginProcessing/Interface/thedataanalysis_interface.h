#ifndef THEDATAANALYSIS_INTERFACE_H
#define THEDATAANALYSIS_INTERFACE_H

#define ZBY_LOG(type)  tr("[%1][%2][%3]").arg(type).arg(Q_FUNC_INFO).arg(__LINE__)

#include <QObject>
#include <QMap>

class TheDataAnalysis_Interface : public QObject
{
    Q_OBJECT

public:
    virtual ~ TheDataAnalysis_Interface(){}

signals:

    ///
    /// \brief messageSignal 日志信息
    /// \param type 日志类型
    /// \param msg 信息体
    ///
    void messageSignal(const QString &type,const QString &msg);

    ///
    /// \brief containerSignal 箱号分析结果
    /// \param result1 前箱
    /// \param resultCheck1 校验
    /// \param iso1 箱型
    /// \param result2 后箱
    /// \param resultCheck2 校验
    /// \param iso2 箱型
    ///
    void containerSignal(const int& type,const QString &result1,const int& resultCheck1,const QString &iso1,const QString &result2="",const int& resultCheck2=0,const QString &iso2="");

    ///
    /// \brief updateDataBaseSignal 更新箱号数据
    /// \param data 数据字典
    ///
    void updateDataBaseSignal(QMap<QString, QString> data);

    ///
    /// \brief resultsAnalysisStateSignal 识别结果写入日志
    /// \param msg 信息体
    ///
    void resultsAnalysisStateSignal(const int& channel, const QString& msg);

    ///
    /// \brief sendResultSignal 发送识别结果
    /// \param channel 通道号
    /// \param result 识别结果
    ///
    void sendResultSignal(int channel,const QString& result);

public slots:

    ///
    /// \brief InitializationParameterSlot 初始化参数
    ///
    virtual void InitializationParameterSlot()=0;

    ///
    /// \brief resultsOfAnalysisSlot 分析箱号
    /// \param resultList 识别结果集
    /// \param type 逻辑类型
    /// \param imgList 图片名
    ///
    virtual void resultsOfAnalysisSlot(QStringList resultList, int type,QStringList imgList)=0;

    ///
    /// \brief setCheckTheResultsSlot 是否校验识别结果
    /// \param correct 校验标志
    ///
    virtual void setCheckTheResultsSlot(bool correct=false)=0;

    ///
    /// \brief setChannelSlot 设定通道号
    ///
    virtual void setChannelSlot(int channel)=0;

    ///
    /// \brief sendMidResultSlot 是否发中间结果集,FLASE发送
    /// \param state
    ///
    virtual void sendMidResultSlot(bool state)=0;
};

#define TheDataAnalysis_InterfaceIID "ZBY.ContainerServer.TheDataAnalysis_Interface/1.0"
Q_DECLARE_INTERFACE(TheDataAnalysis_Interface,TheDataAnalysis_InterfaceIID);

#endif // THEDATAANALYSISINTERFACE_H
