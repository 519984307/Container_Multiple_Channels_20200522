#ifndef _WTY_H
#define _WTY_H

#if !defined(WIN32) && !defined(__stdcall)
#define __stdcall
#endif

#ifndef WIN32
typedef void *HWND;
typedef unsigned int UINT;
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32
typedef   __int64  unsigned_long_long;
#include <windows.h>
#else     
typedef  unsigned long long unsigned_long_long;
#endif
#define BIG_PICSTREAM_SIZE     200000-312///		//����ϴ�ȫ��ͼռ���ڴ������С
#define SMALL_PICSTREAM_SIZE   10000////			//����ϴ����ƽ�ͼռ���ڴ������С
#define BIG_PICSTREAM_SIZE_EX   1*800*1024-312		//����ϴ�ȫ��ͼռ���ڴ������С
#define SMALL_PICSTREAM_SIZE_EX   10000			//����ϴ����ƽ�ͼռ���ڴ������С

/* ���ʱ�� */
typedef struct 
{
	int Year;			/* �� 	*/
	int Month;			/* �� 	*/
	int Day;			/* �� 	*/
	int Hour;			/* ʱ 	*/
	int Minute;			/* �� 	*/
	int Second;			/* �� 	*/
	int Millisecond;	/* ΢�� */
}camera_time;

/* ʶ�������� */
typedef struct 
{
	int 	Left;	/* �� */
	int 	Top;	/* �� */
	int 	Right;	/* �� */
	int 	Bottom;	/* �� */
}plate_location;

/* ʶ���� */
typedef struct 
{	
	char		chWTYIP[16];						/* ���IP 				*/
	int			nFullLen;							/* ȫ��ͼ�����ݴ�С 	*/
	int			nPlateLen;							/* ����ͼ�����ݴ�С 	*/
	char		chFullImage[BIG_PICSTREAM_SIZE];	/* ȫ��ͼ������ 		*/
	char		chPlateImage[SMALL_PICSTREAM_SIZE];	/* ����ͼ������ 		*/
	char		chColor[8];							/* ������ɫ 			*/
	char		chLicense[16];						/* ���ƺ��� 			*/
	plate_location 	pcLocation;						/* ������ͼ���е����� 	*/
	camera_time		shootTime;						/* ʶ������Ƶ�ʱ�� 	*/
	int			nConfidence;						/* ���ƿ��Ŷ�			*/
	int			nTime;								/* ʶ���ʱ				*/
	int			nDirection;							/* ���Ʒ���				*/
	int			nCarLogo;							/* ��������(�ο�CAR_LOGO)*/
	int			nCarModel;							/* ��������(�ο�CAR_MODEL)*/
	char		reserved[256-12-4-4];
}plate_result;

/* ͼ����Ϣ*/
typedef struct
{
	int				nWidth;							/* ����					*/
	int				nHeight;						/* �߶�					*/
	int				nPitch;							/* ͼ����ȵ�һ��������ռ�ڴ��ֽ���*/
	int				nLen;							/* ͼ��ĳ���			*/
	char			reserved[16];					/* Ԥ��     			*/
	unsigned char	*pBuffer;						/* ͼ���ڴ���׵�ַ		*/
}LPRC_IMAGE_INFO;


/* ʶ���� */
typedef struct 
{	
	char				chWTYIP[16];						/* ���IP 				*/
	char				chColor[8];							/* ������ɫ 			*/
	char				chLicense[16];						/* ���ƺ��� 			*/
	plate_location 		pcLocation;							/* ������ͼ���е����� 	*/
	camera_time			shootTime;							/* ʶ������Ƶ�ʱ�� 	*/
	int					nConfidence;						/* ���ƿ��Ŷ�			*/
	int					nTime;								/* ʶ���ʱ				*/
	int					nDirection;							/* ���Ʒ���		    	*/
	int					nCarLogo;							/* ��������(�ο�CAR_LOGO)*/
	int					nCarModel;							/* ��������(�ο�CAR_MODEL)*/
	char				reserved[256-4-4];					/* Ԥ��     			*/
	LPRC_IMAGE_INFO		pFullImage;							/* ȫ��ͼ������(ע�⣺��������䣬�˴�ָ��Ϊ��) */
	LPRC_IMAGE_INFO		pPlateImage;						/* ����ͼ������(ע�⣺��������䣬�˴�ָ��Ϊ��) */
}plate_result_ex;

/* Jpeg���ص�����ÿһ֡jpeg���ݽṹ�� */
typedef struct 
{
	char			chIp[16];				/*���IP												*/
	char			*pchBuf;				/*ÿһ֡jpeg���ݻ�����									*/
	unsigned int	nLen;					/*��ǰjpeg֡�����ݳ���									*/
	int				nStatus;				/* ��ǰjpeg֡����״̬�� 0-����, ��0-������ 				*/
	char			reserved[128];			/* ����		  											*/
}DevData_info;
/*���մ������ݵĽṹ��*/
typedef struct
{
	unsigned char *pData;//[1024];////��������ָ��
	int nsize;///�������ݴ�С
	char reserved[128];			/* ����	*/
}DevSerial_data;

/* �����豸֮�󱣴��豸��Ϣ�Ľṹ�壬ע:Ҫ���޸�ip��Ϣ�뱣֤������Ϣ�����ı�*/
typedef struct 
{
	char 			chDevName[256];			/* �豸��		*/
	char			chSoftVer[20];			/* �����汾��	*/
	char 			chHardVer[20];			/* Ӳ���汾��	*/
	char 			chSysVer[20];			/* ϵͳ�汾	*/
	int				nSdkPort;				/* sdk�˿ں�			*/
	char 			chIp[16];				/* ip��ַ		*/
	char 			chGateway[16];			/* ����	*/
	char 			chNetmask[16];			/* ��������	*/
	char 			chMac[18];				/* Mac��ַ		*/
	char            chRoomID[20];				/*RooMID            */
	char            chSN[20];					/*SN*/
	char			reserved[256];			/* ����		  */
}WTY_DeviceInfo;
/*�°汾Rs485͸�����ݽṹ��*/   
typedef struct{
	short           TimeDelay;				/*��ʱ��Χ:10~200����֮��
												 ע:1�����õ��Ǳ������ݺ���һ������֮�����ʱʱ��
													2�����һ�����ݲ���Ҫ������ʱ
											*/		
    unsigned char   *data;					/*�洢�������ݵĻ�����ָ�룬��Ҫ�ͻ��Լ����뻺����*/
	short           datalen;				/*��������󳤶�2*1024*/
	char            reserved[10];			/*����*/
 } WTY_RS485_Data_t;

/*�°汾485͸���ṹ��*/
typedef struct{
	WTY_RS485_Data_t  rS485_data[5];  /*ʵ�ʷ������ݵĽṹ��*/
	int               datanum;		  /*ÿ�η������֧�ַ���5������*/
} WTY_RS485_Transparent_t;

/*GPIO �����״̬ �ṹ�� */
typedef struct{ 	
	unsigned  char gpio_in0;//GPIO IN0 0�͵�ƽ 1 �ߵ�ƽ 	
	unsigned  char gpio_in1;//GPIO IN1 0�͵�ƽ 1 �ߵ�ƽ
	unsigned  char gpio_in2;//GPIO IN2 0�͵�ƽ 1 �ߵ�ƽ
	unsigned  char gpio_in3;//GPIO IN3 0�͵�ƽ 1 �ߵ�ƽ 
}WTY_GPIO_In_Statue;


/************************************************************************/
/* WTY_InitSDK: �������												*/
/*		Parameters:														*/
/*			nPort[in]:		��������Ķ˿ڣ���Ĭ��Ϊ8080				*/
/*			hWndHandle[in]:	������Ϣ�Ĵ���������ΪNULLʱ����ʾ�޴���  */
/*			uMsg[in]:		�û��Զ�����Ϣ����hWndHandle��ΪNULLʱ��	*/
/*							��⵽���µĳ���ʶ������׼���õ�ǰ����	*/
/*							��������Ϣ����::PostMessage ������		*/
/*							hWndHandle����uMsg��Ϣ������WPARAM����Ϊ0��	*/
/*							LPARAM����Ϊ0								*/
/*			chServerIP[in]:	�����IP��ַ								*/
/*		Return Value:   int												*/
/*							0	������ӳɹ�							*/
/*							1	�������ʧ��							*/
/*		Notice:   														*/
/*				������ûص��ķ�ʽ��ȡ����ʱ��hWndHandle���ΪNULL��	*/
/*				uMsgΪ0������ע��ص�������֪ͨ���µ����ݣ�				*/
/*				��֮�����������յ���Ϣʱ������WTY_GetVehicleInfo��ȡ	*/
/*				���ݡ�													*/
/************************************************************************/
int __stdcall WTY_InitSDK(UINT nPort,HWND hWndHandle,UINT uMsg,char *chServerIP);


/************************************************************************/
/* 	����: ����IP��ַ���Ͽ�ָ���豸����									*/
/*		Parameters:														*/
/*			pCameraIP[in]:			���IP��ַ							*/
/*		Return Value:   int												*/
/*							0	��ȡ�ɹ�								*/
/*							1	��ȡʧ��								*/
/************************************************************************/
int __stdcall WTY_QuitDevice(char *pCameraIP);


/************************************************************************/
/* WTY_QuitSDK: �Ͽ������Ѿ������豸���ͷ���Դ							*/
/*		Parameters:														*/
/*		Return Value:   void											*/
/************************************************************************/
void  __stdcall WTY_QuitSDK();


/***********************************************************************************/
/* �ص�����:ѭ����Ⲣ֪ͨ����豸ͨѶ״̬�Ļص�����						       */
/*		Parameters:														           */
/*			chWTYIP[out]:		�����豸IP								           */
/*			nStatus[out]:		�豸״̬��0��ʾ�����쳣���豸�쳣��			       */
/*										  1��ʾ�����������豸������		    	   */
/*										  2��ʾ�����������豸�����ӣ������������  */
/*		Return Value:   void											           */
/***********************************************************************************/
typedef void (*WTYConnectCallback)(char *chWTYIP,UINT nStatus);


/************************************************************************/
/* WTY_RegWTYConnEvent: ע�����ͨѶ״̬�Ļص�����						*/
/*		Parameters:														*/
/*			WTYConnect[in]:		ConnectCallback���ͻص�����				*/
/*		Return Value:   void											*/
/************************************************************************/
void __stdcall WTY_RegWTYConnEvent (WTYConnectCallback WTYConnect);


/************************************************************************/
/* WTY_CheckStatus: �����������豸��ͨѶ״̬							*/
/*		Parameters:														*/
/*			chWTYIP[in]:		Ҫ���������IP						*/
/*		Return Value:   int												*/
/*							0	����									*/
/*							1	���粻ͨ								*/
/************************************************************************/
int __stdcall WTY_CheckStatus (char *chWTYIP);


/************************************************************************/
/* �ص�����: ע�����ʶ�����ݻص�����									*/
/*		Parameters:														*/
/*			recResult[out]:		ʶ��������							*/
/*		Return Value:   void											*/
/*	Note:																*/
/*		����չ�Ļص������������û����������Ƚϸ߻�ֱ��ʽϸߵ�JPEGͼ��	*/
/************************************************************************/
typedef void (*WTYDataEx2Callback)(plate_result_ex *recResultEx);


/************************************************************************/
/* WTY_RegDataEx2Event: ע���ȡʶ�����Ļص�����						*/
/*		Parameters:														*/
/*			WTYData[in]:		����ʶ�����Ļص�������ָ��			*/
/*		Return Value:   void											*/
/*	Note:																*/
/*		���������Ƚϸߣ���ֱ��ʽϸߵ�JPEGͼ��							*/
/************************************************************************/
void __stdcall WTY_RegDataEx2Event(WTYDataEx2Callback WTYDataEx2);


/************************************************************************/
/* �ص�����:��ȡ���485���͵�����										*/
/*		Parameters:														*/
/*			chWTYIP[out]:		�����豸IP								*/
/*          serialData[out]          �������ݵ�ַ						*/
/*			nlen[out]				�������ݴ�С						*/
/*		Return Value:   void											*/
/************************************************************************/
typedef void (*WTYSerialDataCallback)(char *chWTYIP,DevSerial_data *pSerialData);


/************************************************************************/
/* WTY_RegSerialDataEvent: ע���ȡ�������ݵĻص�����					*/
/*		Parameters:														*/
/*			WTYSerialData[in]:		�������մ������ݵĻص�������ָ��	*/
/*		Return Value:   void											*/
/************************************************************************/
void __stdcall WTY_RegSerialDataEvent(WTYSerialDataCallback WTYSerialData);


/************************************************************************/
/* �ص�����:��ȡ���GPIO״̬											*/
/*		Parameters:														*/
/*			chWTYIP[out]:		�����豸IP								*/
/*          pGpioState[out]          �������ݵ�ַ						*/
/*		Return Value:   void											*/
/************************************************************************/
typedef void (*WTYGetGpioStateCallback)(char *chWTYIP,WTY_GPIO_In_Statue *pGpioState);


/************************************************************************/
/* WTY_RegWTYGetGpioState: ע���ȡ���GPIO״̬�Ļص�����				*/
/*		Parameters:														*/
/*			WTYGpioState[in]:		WTYGetGpioStateCallback���ͻص�����	*/
/*		Return Value:   void											*/
/************************************************************************/
void __stdcall WTY_RegWTYGetGpioState (WTYGetGpioStateCallback WTYGpioState);


/************************************************************************/
/* 	����: ��Ϣ��ʽ��ȡָ��IP�����ʶ������							*/
/*		  ��WTY_initSDK�����������˴���������Ϣʱ��					*/
/*		  ��Ҫ����Ϣ���������е��ô˺�����������ȡʶ������			*/
/*		Parameters:														*/
/*			chWTYIP[in]:		������Ϣ����ȡָ��IP�豸ʶ������		*/
/*			chPlate[in]:		���ƺ���								*/
/*			chColor[in]:		������ɫ								*/
/*			chFullImage[in]:	ȫ��ͼ����								*/
/*			nFullLen[in]:		ȫ��ͼ���ݳ���							*/
/*			chPlateImage[in]:	����ͼ����								*/
/*			nPlateLen[in]:		����ͼ���ݳ���							*/
/*			chTwoImage[in]:		��ֵ������								*/
/*			nTwoLen[in]:		��ֵ�����ݳ���							*/
/*		Return Value:   int												*/
/*							0	��ȡ�ɹ�								*/
/*							1	��ȡʧ��								*/
/*		Notice:   														*/
/*			�������˴������ݲ���ʱ�����Զ�Ӧ������ΪNULL������Ϊ-1��	*/
/*			��û���γ�����ʱ�����Զ�Ӧ����ΪNULL������Ϊ0				*/
/************************************************************************/
int __stdcall WTY_GetVehicleInfoEx(char *chWTYIP,
								 char *chPlate,	
								 char *chColor,
								 void *chFullImage ,
								 int *nFullLen,
								 void *chPlateImage,
								 int *nPlateLen,
								 void *chTwoImage,
								 int *nTwoLen);


/************************************************************************/
/* WTY_SetSavePath: ����û���Ҫ��̬���Զ�����ͼƬ������ͨ���ú������ñ�*/
/*					��ͼƬ��·����										*/
/*		Parameters:														*/
/*			chSavePath[in]:	�ļ��洢·������"\\"�������磺"D:\\Image\\"	*/
/*		Return Value:   void											*/
/*																		*/
/*		Notice:   														*/
/*			ȫ��ͼ��ָ��Ŀ¼\\�豸IP\\�����գ�YYYYMMDD��\\FullImage\\	*/
/*									ʱ����-����__��ɫ_���ƺ���__.jpg	*/
/*			����ͼ��ָ��Ŀ¼\\�豸IP\\�����գ�YYYYMMDD��\\PlatelImage\\	*/
/*									ʱ����-����__��ɫ_���ƺ���__.jpg	*/
/************************************************************************/
void __stdcall WTY_SetSavePath (char *chSavePath);


/************************************************************************/
/* WTY_SetTrigger: ����ʶ��												*/
/*		Parameters:														*/
/*			pCameraIP[in]:			Ҫ����������豸��IP				*/
/*			nCameraPort[in]:		�˿�,Ĭ��8080						*/
/*		Return Value:													*/
/*					0	�����ɹ�����									*/
/*				  ��0	ʧ��											*/
/************************************************************************/	
int __stdcall WTY_SetTrigger(char *pCameraIP, int nCameraPort);


/************************************************************************/
/* ����˵��: ���Ƽ̵����ıպ�											*/
/*		Parameters:														*/
/*			pCameraIP[in]:			���IP								*/
/*			nCameraPort[in]:		�˿�,Ĭ��8080						*/
/*		Return Value:   int												*/
/*							0	���óɹ�								*/
/*						  ��0	ʧ��									*/
/*		Notice:   														*/
/*				ͨ���˹��ܣ�������PC��ͨ��һ����豸�������Ƶ�բ��̧��	*/
/*				�豸�̵�������ź�Ϊ���������źš�						*/
/************************************************************************/
int __stdcall WTY_SetRelayClose(char *pCameraIP, int nCameraPort);


/************************************************************************/
/* ����˵��: ���Ƶ�բ����											*/
/*		Parameters:														*/
/*			pCameraIP[in]:			���IP								*/
/*			nCameraPort[in]:		�˿�,Ĭ��8080						*/
/*		Return Value:   int												*/
/*							0	���óɹ�								*/
/*						  ��0	ʧ��									*/
/*		Notice:   														*/
/*				ͨ���˹��ܣ�������PC��ͨ��һ����豸�������Ƶ�բ������	*/
/*				�豸����ź�Ϊ�������ź�						*/
/************************************************************************/
int __stdcall WTY_DropRod(char *pCameraIP, int nCameraPort);


/************************************************************************/
/* WTY_RS485Send: RS485͸������											*/
/*		Parameters:														*/
/*			pCameraIP[in]				����豸IP��ַ					*/
/*			nPort[in]					�˿�,Ĭ��9110					*/
/*			chData[in]					��Ҫ��������ݿ���׵�ַ		*/
/*			nSendLen[in]				��Ҫ��������ݿ���ֽ���		*/
/*		Return Value:   int												*/
/*							0	�ɹ�									*/
/*						  ��0	ʧ��									*/
/*		notice��														*/
/*				1���û�ͨ���˽ӿڣ�������������ݣ�����豸��ԭ��������	*/
/*				ͨ��RS485�ӿ�ת����ȥ�����ͻ����ӵ��ⲿ�豸�ϡ�			*/
/*				2��ʹ�ô˹���ǰ����Ҫ����ʾDEMO�����ý����ϣ���������� */
/*				�ܴ���ʶ����(Ĭ��S485����ʶ����)��					*/
/************************************************************************/
int __stdcall WTY_RS485Send(char *pCameraIP, int nCameraPort, char *chData, int nSendLen);


/************************************************************************/
/* WTY_RS485SendEx: �°汾RS485͸������									*/
/*		Parameters:														*/
/*			pCameraIP[in]				����豸IP��ַ					*/
/*			nPort[in]					�˿�,Ĭ��9110					*/
/*			nRs485[in]	����485���ݵĽṹ��								*/
/*		Return Value:   int												*/
/*							0	�ɹ�									*/
/*						  ��0	ʧ��									*/
/*		notice��														*/
/*				1���û�ͨ���˽ӿڣ�������������ݣ�����豸��ԭ��������	*/
/*				ͨ��RS485�ӿ�ת����ȥ�����ͻ����ӵ��ⲿ�豸�ϡ�			*/
/*				2��ʹ�ô˹���ǰ����Ҫ����ʾDEMO�����ý����ϣ���������� */
/*				�ܴ���ʶ����(Ĭ��S485����ʶ����)��					*/
/*				3:�°汾����һ���Ը�����������5�����ݣ���������ÿ������*/
/*				͸����ʱ������									      */
/************************************************************************/
int __stdcall WTY_RS485SendEx(char *pCameraIP, int nCameraPort, WTY_RS485_Transparent_t nRs485);


/************************************************************************/
/* WTY_SearchDeviceList:    �����豸IP�б�							    */
/*		Parameters:														*/
/*		pBuf[out]			�洢������������б���Ϣ�ṹ������		    */
/*		Return Value:   	int											*/
/*							����0	�ɹ����������豸��					*/
/*						  	-1	ʧ��									*/
/************************************************************************/
int __stdcall WTY_SearchDeviceList(WTY_DeviceInfo *pBuf);


/************************************************************************/
/* WTY_AlterDeviceInfo:    �޸�ָ�����豸���豸��Ϣ					    */
/*		Parameters:														*/
/*		pCameraIP[in]		��Ҫ�޸ĵ�����豸��ip��ַ				    */
/*		pBuf[out]			�洢��Ҫ�޸ĵ��豸��Ϣ�ṹ��		        */
/*		Return Value:   	int											*/
/*							==0	�ɹ�									*/
/*						  	��0	ʧ��									*/
/************************************************************************/
int __stdcall WTY_AlterDeviceInfo(char *pCameraIP,WTY_DeviceInfo pBuf);


/************************************************************************/
/* WTY_SetDevTimeParam:    �޸��豸ϵͳʱ��							    */
/*		Parameters:														*/
/*		pCameraIP[in]		��Ҫ�޸ĵ�����豸��ip��ַ				    */
/*		sysTime[in]			����ʱ��ṹ��		                        */
/*		Return Value:   	int											*/
/*							==0	�ɹ�									*/
/*						  	��0	ʧ��									*/
/************************************************************************/
int __stdcall WTY_SetDevTimeParam(char *pCameraIP, camera_time*sysTime);


/************************************************************************/
/* WTY_SetEncryptKey:    	���ü���оƬ����							*/
/*		Parameters:														*/
/*		pCameraIP[in]		��Ҫ�޸ĵ�����豸��ip��ַ				    */
/*		nKey[in]			����оƬ���룬8���ֽڴ�С	                */
/*		Return Value:   	int											*/
/*							==0	�ɹ�									*/
/*						  	��0	ʧ��									*/
/************************************************************************/
int __stdcall WTY_SetEncryptKey(char *pCameraIP, unsigned_long_long nKey);


/************************************************************************/
/* WTY_ReSetEncryptKey:    	���ü���оƬ���룬����ָ�Ϊ123456			*/
/*                          �����û����ݻָ�Ϊ��                        */
/*		Parameters:														*/
/*		pCameraIP[in]		��Ҫ�޸ĵ�����豸��ip��ַ				    */
/*		Return Value:   	int											*/
/*							==0	�ɹ�									*/
/*						  	��0	ʧ��									*/
/************************************************************************/
int __stdcall WTY_ReSetEncryptKey(char *pCameraIP);


/************************************************************************/
/* WTY_SetEncryptUserData:  ���ü���оƬ�û����ݣ��������ƥ��ſ��Գɹ�*/
/*		Parameters:														*/
/*		pCameraIP[in]		��Ҫ�޸ĵ�����豸��ip��ַ				    */
/*		nKey[in]			����оƬ���룬8���ֽڴ�С	                */
/*      pUserData[in]       ����оƬ�û�����ָ�룬��С24���ֽ�          */
/*		Return Value:   	int											*/
/*							==0	�ɹ�									*/
/*						  	��0	ʧ��									*/
/************************************************************************/
int __stdcall WTY_SetEncryptUserData(char *pCameraIP, unsigned_long_long nKey,char *pUserData);


/************************************************************************/
/* WTY_GetEncryptUserData:  ���ü���оƬ�û����ݣ��������ƥ��ſ��Գɹ�*/
/*		Parameters:														*/
/*		pCameraIP[in]		��Ҫ�޸ĵ�����豸��ip��ַ				    */
/*		nKey[in]			����оƬ���룬8���ֽڴ�С	                */
/*      pUserData[out]      �洢��ȡ�����û�����                        */
/*		Return Value:   	int											*/
/*							==0	�ɹ�									*/
/*						  	��0	ʧ��									*/
/************************************************************************/
int __stdcall WTY_GetEncryptUserData(char *pCameraIP, unsigned_long_long nKey,char *pUserData);




/*************************************************************************************************************/
/****************************���½ӿ����ڽ���汾��V5������ܲ��ٻ��ṩ֧��***********************************/
/**********************************��ͻ��ҽ�ʱ�򣬾���ʹ�����Ͻӿ�*******************************************/
/*************************************************************************************************************/


/************************************************************************/
/* 	����: ��Ϣ��ʽ��ȡָ��IP���ʶ������								*/
/*		  ��WTY_initSDK�����������˴���������Ϣʱ��					*/
/*		  ��Ҫ����Ϣ���������е��ô˺�����������ȡʶ������			*/
/*		Parameters:														*/
/*			chWTYIP[in]:		������Ϣ����ȡָ��IP�豸ʶ������		*/
/*			chPlate[in]:		���ƺ���								*/
/*			chColor[in]:		������ɫ								*/
/*			chFullImage[in]:	ȫ��ͼ����								*/
/*			nFullLen[in]:		ȫ��ͼ���ݳ���							*/
/*			chPlateImage[in]:	����ͼ����								*/
/*			nPlateLen[in]:		����ͼ���ݳ���							*/
/*		Return Value:   int												*/
/*							0	��ȡ�ɹ�								*/
/*							1	��ȡʧ��								*/
/*		Notice:   														*/
/*			�������˴������ݲ���ʱ�����Զ�Ӧ������ΪNULL������Ϊ-1��	*/
/*			��û���γ�����ʱ�����Զ�Ӧ����ΪNULL������Ϊ0				*/
/************************************************************************/
int __stdcall WTY_GetVehicleInfo(char *chWTYIP,
								 char *chPlate,	
								 char *chColor,
								 void *chFullImage ,	
								 int *nFullLen, 
								 void *chPlateImage,
								 int *nPlateLen);


/************************************************************************/
/* �ص�����: ע�����ʶ�����ݻص�����									*/
/*		Parameters:														*/
/*			recResult[out]:		ʶ��������							*/
/*		Return Value:   void											*/
/************************************************************************/
typedef void (*WTYDataExCallback)(plate_result *recResult);


/************************************************************************/
/* WTY_RegDataExEvent: ע���ȡʶ�����Ļص�����						*/
/*		Parameters:														*/
/*			WTYData[in]:		����ʶ�����Ļص�������ָ��			*/
/*		Return Value:   void											*/
/*	Note:																*/
/*		���������Ƚϵͣ���ֱ��ʽϵ͵�JPEGͼ��							*/
/************************************************************************/
void __stdcall WTY_RegDataExEvent(WTYDataExCallback WTYDataEx);





/************************************************************************/
/* �ص�����: ��ȡʶ�����Ļص�����										*/
/*		Parameters:														*/
/*			chWTYIP[out]:		����ʶ�������豸IP					*/
/*			chPlate[out]:		���ƺ���								*/
/*			chColor[out]:		������ɫ								*/
/*			chFullImage[out]:	ȫ��ͼ����								*/
/*			nFullLen[out]:		ȫ��ͼ���ݳ���							*/
/*			chPlateImage[out]:	����ͼ����								*/
/*			nPlateLen[out]:		����ͼ���ݳ���							*/
/*		Return Value:   void											*/
/************************************************************************/
typedef void (*WTYDataCallback)(char *chWTYIP, 
								char *chPlate,
								char *chColor,
								char *chFullImage,
								int nFullLen, 
								char *chPlateImage,
								int nPlateLen);


/************************************************************************/
/* WTY_RegDataEvent: ע���ȡʶ�����Ļص�����							*/
/*		Parameters:														*/
/*			WTYData[in]:		����ʶ�����Ļص�������ָ��			*/
/*		Return Value:   void											*/
/************************************************************************/
void __stdcall WTY_RegDataEvent(WTYDataCallback WTYData);


/************************************************************************/
/* WTY_SetTransContent: ��������豸�ϴ�����					        */
/*		Parameters:														*/
/*			pCameraIP[in]:		Ҫ���õ��豸IP							*/
/*			nCameraPort[in]:	�˿�,Ĭ��8080							*/
/*			nFullImg[in]:		ȫ��ͼ��0��ʾ������1��ʾ��				*/
/*			nPlateImg[in]:		����ͼ��0��ʾ������1��ʾ��				*/
/*		Return Value:   int												*/
/*							0	�ɹ�									*/
/*						  ��0	ʧ��									*/
/************************************************************************/
int __stdcall WTY_SetTransContent (char *pCameraIP, int nCameraPort, int nFullImg, int nPlateImg);


/************************************************************************/
/* �ص�����: ��ȡJpeg���Ļص�����										*/
/*		Parameters:														*/
/*			JpegInfo[out]:		JPEG��������Ϣ							*/
/*		Return Value:   void											*/
/*																		*/
/*		Notice:															*/
/*			1:һ̨PC���Ӷ�̨�豸ʱ���˺�������ʵ��һ�Ρ������ֲ�ͬ		*/
/*			�豸��JPEG��ʱ������ͨ�����������DevData_info�е�chIp��	*/
/*			����.														*/
/*			2:�˹���Ŀǰ������V5.5.3.0��V6.0.0.0�����ϰ汾,				*/
/*			  V5.2.1.0��V5.2.2.0��V5.2.6.0�Ȱ汾����ʹ�ô˹���			*/
/************************************************************************/
typedef void (*WTYJpegCallback)(DevData_info *JpegInfo);


/************************************************************************/
/* WTY_RegJpegEvent: ע���ȡJpeg���Ļص�����							*/
/*		Parameters:														*/
/*			JpegInfo[in]:		WTYJpegCallback���ͻص�����				*/
/*		Return Value:   void											*/
/*																		*/
/*		Notice:															*/
/*			1:һ̨PC���Ӷ�̨�豸ʱ���˺�������ʵ��һ�Ρ������ֲ�ͬ		*/
/*			�豸��JPEG��ʱ������ͨ�����������DevData_info�е�chIp��	*/
/*			����.														*/
/*			2:�˹���Ŀǰ������V5.5.3.0��V6.0.0.0�����ϰ汾,				*/
/*			  V5.2.1.0��V5.2.2.0��V5.2.6.0�Ȱ汾����ʹ�ô˹���			*/
/************************************************************************/
void __stdcall WTY_RegJpegEvent(WTYJpegCallback JpegInfo);


/************************************************************************/
/* ����: Jpeg����Ϣ������ʼ��											*/
/*		Parameters:														*/
/*			hWndHandle[in]:	������Ϣ�Ĵ�����							*/
/*			uMsg[in]:		�û��Զ�����Ϣ								*/
/*							��⵽�����ݲ�׼���û��������ݺ�			*/
/*							��::PostMessage ������hWndHandle����uMsg	*/
/*							��Ϣ������WPARAM����Ϊ0��LPARAM����Ϊ0		*/
/*			chIp[in]:		���IP��ַ								*/
/*		Return Value:   int												*/
/*							0	��ȡ�ɹ�								*/
/*							1	��ȡʧ��								*/
/************************************************************************/
int __stdcall WTY_JpegMessageInit(HWND hWndHandle,UINT uMsg,char *chIp);


/************************************************************************/
/* 	����: ��Ϣ��ʽ��ȡָ��IP�������Jpeg������							*/
/*		Parameters:														*/
/*			chIp[in]:			���IP��ַ								*/
/*			chJpegBuf[in]:		�洢JPEG��buffer						*/
/*			nJpegBufLen[in]:	��ȡ����JPEG���ݳ���					*/
/*		Return Value:   int												*/
/*							0	��ȡ�ɹ�								*/
/*							1	��ȡʧ��								*/
/*		Notice:   														*/
/*			ʹ�ô˺���ǰ���ȵ���WTY_JpegMessageInit���������Զ�����Ϣ	*/
/************************************************************************/
int __stdcall WTY_GetJpegStream(char *chIp, char *chJpegBuf, char *nJpegBufLen);


/************************************************************************/
/* WTY_SetNetworkCardBind: �ֶ���ָ������IP							*/
/*		Parameters:														*/
/*			pCameraIP[in]		Ҫ�󶨵�����IP��ַ						*/
/*		Return Value:   int												*/
/*							0	�ɹ�									*/
/*						  ��0	ʧ��									*/
/*		notice:��PC�����ڶ����������ʱ���ֲ������Ϊ������ʱ����ͨ����	*/
/*				�����������ͨѶ������IP								*/
/************************************************************************/
int __stdcall WTY_SetNetworkCardBind(char *pCameraIP);


/************************************************************************/
/* �ص�����: ��ȡ������Ϣ�Ļص�����										*/
/*		Parameters:														*/
/*			alarmInfo[out]:		������Ϣ								*/
/*		Return Value:   void											*/
/*																		*/
/*		Notice:															*/
/*			һ̨PC���Ӷ�̨�豸ʱ���˺�������ʵ��һ�Ρ������ֲ�ͬ�豸	*/
/*			��Alarmʱ������ͨ�����������DevData_info�е�chIp������		*/
/*																		*/
/*		Notice:															*/
/*			1:һ̨PC���Ӷ�̨�豸ʱ���˺�������ʵ��һ�Ρ������ֲ�ͬ		*/
/*			�豸��JPEG��ʱ������ͨ�����������DevData_info�е�chIp��	*/
/*			����.														*/
/*			2:�˹���Ŀǰ������V5.5.3.0��V6.0.0.0�����ϰ汾,				*/
/*			  V5.2.1.0��V5.2.2.0��V5.2.6.0�Ȱ汾����ʹ�ô˹���			*/
/************************************************************************/
typedef void (*WTYAlarmCallback)(DevData_info *alarmInfo);


/************************************************************************/
/* WTY_RegAlarmEvent: ע���ȡ������Ϣ�Ļص�����						*/
/*		Parameters:														*/
/*			AlarmInfo[in]:		WTYAlarmCallback���ͻص�����			*/
/*		Return Value:   void											*/
/*																		*/
/*		Notice:															*/
/*			1:һ̨PC���Ӷ�̨�豸ʱ���˺�������ʵ��һ�Ρ������ֲ�ͬ		*/
/*			�豸��JPEG��ʱ������ͨ�����������DevData_info�е�chIp��	*/
/*			����.														*/
/*			2:�˹���Ŀǰ������V5.5.3.0��V6.0.0.0�����ϰ汾,				*/
/*			  V5.2.1.0��V5.2.2.0��V5.2.6.0�Ȱ汾����ʹ�ô˹���			*/
/************************************************************************/

void __stdcall WTY_RegAlarmEvent(WTYAlarmCallback AlarmInfo);


/************************************************************************/
/*WTY_SnapJpegFrame ����ץ��һ֡�����ֱ��淽ʽ��ֱ�ӱ��浽�̶�Ŀ¼����	*/
/*					���浽�ض��ڴ�,Ҫ�Ǳ����ض��ڴ�ģʽ��Ҫ�����ڴ�		*/
/*					���ֵ,���ַ�ʽ��ѡ									*/		
/*		Parameters:														*/
/*			chIp[in]		   �����IP��ַ								*/
/*			pSaveFileName[in]  ·���ʹ�JPEG��׺�����ļ��������ڰѵ�ǰ	*/
/*							   ץ�ĵ���֡����Ϊ�ض��ļ�  Ĭ����ƥ��		*/
/*							   �ļ���									*/
/*          pSaveBuf[in]       ���ڱ��浱ǰ֡���ض��ڴ��,������Ҫ����	*/
/*							   �ڴ�ɴ洢�����ֵ�����ļ���Ϊ�յ�ʱ��	*/
/*							   ����Ż���Ч��							*/  
/*          Maxlen[in]         ���浱ǰ֡�ض��ڴ�����ֵ				*/
/*		Return Value:   int												*/
/*						   0	���浽�ض�Ŀ¼�ɹ�						*/
/*                         >0   ���浽�ض��ڴ�����ݵ�ʵ�ʴ�С          */
/*						  -1	ʧ��									*/
/************************************************************************/
int __stdcall WTY_SnapJpegFrame(char *chIp,char *pSaveFileName,unsigned char *pSaveBuf,int Maxlen);


/********************************************************************************/
/* WTY_SetJpegStreamPlayOrStop: ����jpeg���Ŀ���							    */
/*		Parameters:														        */
/*		pCameraIP[in]		��Ҫ���õ�����豸��ip��ַ				            */
/*		onoff[in]			jpeg�������0��ʾ�ر�����1��ʾ���� 2��H264    */
/*		Return Value:   	int											        */
/*							0	�ɹ�									        */
/*						  	��0	ʧ��									        */
/********************************************************************************/
int __stdcall WTY_SetJpegStreamPlayOrStop(char *pCameraIP,int onoff);

#ifdef __cplusplus
}
#endif

#endif