#ifndef RESULTSANALYSISINTERFACE_H
#define RESULTSANALYSISINTERFACE_H

#define ZBY_LOG(type)  tr("[%1][%2][%3]").arg(type).arg(Q_FUNC_INFO).arg(__LINE__)
#include <QObject>
#include <QMap>

class ResultsAnalysisInterface : public QObject
{
    Q_OBJECT

public:
    virtual ~ResultsAnalysisInterface() {}

    ///
    /// \brief InterfaceType 插件类型，多插件调用统一接口
    /// \return
    ///
    virtual QString InterfaceType()=0;

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
    /// \brief initParameter 初始化参数
    /// \param channel
    /// \param check
    /// \param sendMid
    ///
    virtual void initParameter(const int &channel,const int &ImageNamingRules ,bool check,bool sendMid)=0;

    ///
    /// \brief resultsOfAnalysisSlot 分析箱号
    /// \param resultMap 识别结果集
    /// \param type 逻辑类型
    /// \param imgNameMap 图片名
    ///
    virtual void resultsOfAnalysisSlot(QMap<int,QString> resultMap, int type,QMap<int,QString> imgNameMap)=0;
};

#define ResultsAnalysisInterfaceIID "ZBY.ContainerServer.ResultsAnalysisInterface/2.3.2.3"
Q_DECLARE_INTERFACE(ResultsAnalysisInterface,ResultsAnalysisInterfaceIID);

#endif // RESULTSANALYSISINTERFACE_H

