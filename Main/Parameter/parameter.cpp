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
    int LogicType=1;
    int PlateType=0;
    int interfaceModel=0;
    int loadLibrary_HK=0;

    /*****************************
    * @brief:Upload
    ******************************/

    int Ftp=0;
    int FtpPort= 21;
    int ReduceImage= 0;
    QString FtpAddress= QString("192.168.1.110");
    int FtpTimeDIC= 1;
    QString FtpPassword= QString("ABCabc123");    
    QString FtpRemotePath= QString("./");
    QString FtpUser= QString("admin");
    int DatabaseType =0 ;
    QString databaseAddr = QString("127.0.0.1");
    QString databaseUser = QString("Admin");
    QString databasePass = QString("ABCabc123");
    QString upload_images =  QString("1,2,3,4,5,6");


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
    int picture_size=0;

    /*****************************
    * @brief:Service
    ******************************/

    int Service_Model= 0;
    int Service_Type= 0;
    int Identify_Protocol= 0;
    int Heartbeat= 0;
    int Resultting= 0;
    int ShortLink= 0;
    int newline=0;
    int DataChaneType=0;
    int DataChange_Format=0;
    int plate_timeout=10;
    int container_timeout=15;
    int not_plate_color=0;
    int same_plate_out=10;
    int dont_false_plate=0;
    QString false_plate=QString("1");
    QString SingletonAddress= QString("");
    QString ManyCasesAddress= QString("");
    QString SingletonAddressMQ= QString("");
    QString ManyCasesAddressMQ= QString("");
}
