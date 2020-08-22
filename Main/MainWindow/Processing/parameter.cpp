#include "parameter.h"

Parameter::Parameter(){

}

int Parameter::ChannelNumber= 1;
int Parameter::ImageFormat= 0;
int Parameter::ImageNamingRules= 0;
QString Parameter::ImagePath= QString("./");

/*****************************
* @brief:Upload
******************************/
int Parameter::Ftp=0;
QString Parameter::FtpAddress= QString("192.168.1.110");
QString Parameter::FtpLocalPath= QString("./");
QString Parameter::FtpPassword= QString("ABCabc123");
int Parameter::FtpPort= 21;
QString Parameter::FtpRemotePath= QString("./");
QString Parameter::FtpUser= QString("admin");
int Parameter::ReduceImage= 0;

/*****************************
* @brief:Other
******************************/
int Parameter::Language= 0;
int Parameter::Minimization= 0;
int Parameter::Automatic= 0;
int Parameter::InfoLog= 0;
int Parameter::DebugLog= 0;

/*****************************
* @brief:Recognizer
******************************/
int Parameter::ResultsTheCheck= 0;

/*****************************
* @brief:Service
******************************/
int Parameter::ServiceModel= 0;
int Parameter::Service_Type= 0;
QString Parameter::SingletonAddress= QString("") ;
QString Parameter::ManyCasesAddress= QString("");
int Parameter::Heartbeat= 0;
int Parameter::Resultting= 0;
