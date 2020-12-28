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
    int FtpPort= 21;
    int ReduceImage= 0;
    QString FtpAddress= QString("192.168.1.110");
    QString FtpLocalPath= QString("./");
    QString FtpPassword= QString("ABCabc123");    
    QString FtpRemotePath= QString("./");
    QString FtpUser= QString("admin");
    int DatabaseType =0 ;
    QString databaseAddr = QString("127.0.0.1");
    QString databaseUser = QString("Admin");
    QString databasePass = QString("ABCabc123");


    /*****************************
    * @brief:Other
    ******************************/
    int Language= 0;
    int Minimization= 0;
    int FullScreen= 0;
    int Automatic= 0;
    int InfoLog= 0;
    int DebugLog= 0;
    int DelayStart=10;

    /*****************************
    * @brief:Recognizer
    ******************************/
    int ResultsTheCheck= 0;

    /*****************************
    * @brief:Service
    ******************************/
    int ServiceModel= 0;
    int Service_Type= 0;
    int Heartbeat= 0;
    int Resultting= 0;
    QString SingletonAddress= QString("");
    QString ManyCasesAddress= QString("");

}
