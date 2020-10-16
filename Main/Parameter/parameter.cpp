#include "parameter.h"

namespace Parameter {

    int ChannelNumber= 0;
    int ImageFormat= 0;
    int ImageNamingRules= 0;
    QString ImagePath= QString("./");

    /*****************************
    * @brief:Upload
    ******************************/
    int Ftp=0;
    QString FtpAddress= QString("192.168.1.110");
    QString FtpLocalPath= QString("./");
    QString FtpPassword= QString("ABCabc123");
    int FtpPort= 21;
    QString FtpRemotePath= QString("./");
    QString FtpUser= QString("admin");
    int ReduceImage= 0;

    /*****************************
    * @brief:Other
    ******************************/
    int Language= 0;
    int Minimization= 0;
    int Automatic= 0;
    int InfoLog= 0;
    int DebugLog= 0;
    int DelayStart=0;

    /*****************************
    * @brief:Recognizer
    ******************************/
    int ResultsTheCheck= 0;

    /*****************************
    * @brief:Service
    ******************************/
    int ServiceModel= 0;
    int Service_Type= 0;
    QString SingletonAddress= QString("") ;
    QString ManyCasesAddress= QString("");
    int Heartbeat= 0;
    int Resultting= 0;

}
