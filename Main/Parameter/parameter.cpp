#include "parameter.h"

namespace Parameter {

    /*****************************
    * @brief:channel
    ******************************/

    int ChannelNumber= 0;
    int ImageFormat= 0;
    int ImageNamingRules= 0;
    QString ImagePath= QString("C:\\images");
    int camera_id_placeholder=2;
    int channel_id_placeholder=2;

    /*****************************
    * @brief:Model
    ******************************/

    int HCNET_Capture_Type=0;
    int Camera_Load_Plugin=0;
    int LogicType=0;
    int PlateType=0;

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

    int Service_Model= 0;
    int Service_Type= 0;
    int Heartbeat= 0;
    int Resultting= 0;
    int ShortLink=0;
    QString SingletonAddress= QString("");
    QString ManyCasesAddress= QString("");
}
