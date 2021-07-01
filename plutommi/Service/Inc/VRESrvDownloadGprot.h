#ifndef __SRV_VRE_DOWNLOADGPROT_H__
#define __SRV_VRE_DOWNLOADGPROT_H__

#define __SRV_VRE_DL__

#ifdef __cplusplus
extern "C" {
#endif

#include "MMIDataType.h"

/*************************************************** Download service Interfaces *****************************************************/

#define SRV_VRE_DL_DONE                1  //����VXP�������
#define SRV_VRE_DL_SUCCESS             0  //�ɹ�
#define SRV_VRE_DL_ERR                 -1 //ʧ��
#define SRV_VRE_DL_NET_ERR             -2 //�������         
#define SRV_VRE_DL_SAVE_ERR            -3 //�������
#define SRV_VRE_DL_APP_NOT_EXIST       -4 //Ӧ�ò�����
#define SRV_VRE_DL_SPACE_FULL          -5 //�ռ䲻��
#define SRV_VRE_DL_OTHER_ERR           -6 //��������
#define SRV_VRE_DL_FILE_NOT_EXIST      -7 //�ļ�������
#define SRV_VRE_DL_IO_ERROR            -8 //I/O ��������
#define SRV_VRE_DL_ERR_DOWNLOADING     -9 //Downloading a app, please stop it first.




#define  MAX_LEN_FILE_NAME                  (260)
#define  VAM_LEN_MD5                        (32)  


#define VRE_SRV_INT_SIZE                    sizeof(U32)


/*
*   Ӧ������״̬���Ͷ���
*/
typedef enum 
{
    APPDLSTATE_UNKNOWN = 0,         //δ֪״̬
    APPDLSTATE_DOWNLOADING,         //��������  
    APPDLSTATE_FAIL,                //����ʧ��
    APPDLSTATE_OK,                  //������
    APPDLSTATE_NOT,                 //δ����
    APPDLSTATE_PAUSE,               //��ͣ����
    APPDLSTATE_WAIT                 //�ȴ�����
}E_AppDlState_t;





typedef struct
{
    /* Need to fill in when start */
    U32       nAppid;                                    /*Ӧ��ID*/
    WCHAR     szFilename[MAX_LEN_FILE_NAME + 1];         /*�ļ���*/

    /*Internal paramter*/
    S32       nPercent;                                  /*�������*/
    S32       nFilehandle;                               /*��ʱ�ļ����*/
    S32       nRetryCount;                               /*���Դ���*/
    U32       nFilesize;                                 /*�ļ���С*/
    U32       nDownloadsize;                             /*�����ش�С*/
    WCHAR     szVXPDigest[VAM_LEN_MD5 + 1];              /*��vxp�ļ�����ժҪ*/
    E_AppDlState_t eState;                               /*����״̬*/
} VRE_DL_ITEM;


extern MMI_BOOL srv_vre_dl_is_running(void);

extern S32 srv_vre_dl_init(void);

extern S32 srv_vre_dl_deinit(void);

extern S32 srv_vre_dl_start(U32 appid, U16 *file_path, void(*download_app_cb)(S32 nResult, VRE_DL_ITEM *pDownload));

extern S32 srv_vre_dl_stop(S32 handle);

extern S32 srv_vre_dl_cancel(S32 handle);





/************************************************************** Get Info Interfaces *************************************************/

///////////////APP_VERSION
#define VM_APP_VERSION_APPNAME_LEN (40)
#define VM_APP_VERSION_FILENAME_LEN (20)

/*
* @sync_cb  �ص�������
*
* @	appid             Ϊ��Ҫ����Ӧ�ó�����.
* @	nResultΪ0 	  ��ʾ�ӷ�������ȡ��Ϣ�ɹ�.
* @	app_version 	  ��ʾ��ǰ�������ϵ�Ӧ�ð汾��,�뱾�صİ汾�űȽ����ж��Ƿ���Ҫ����.
* @  	app_name	  ��ʾappid ��Ӧ��app_name��Ϊucs2����
* @	app_file_name  	  ��ʾappid ��Ӧ��app_file_name��Ϊucs2����
* @	app_filesize      ��ʾ��ǰ�������϶�Ӧ�汾�ŵ�Ӧ�ó�����ļ���С,��λΪ�ֽ�.
*
*/
typedef void (*sync_cb)(U32 appid, S32 nResult, S32 app_version, U8 *app_name,U8 *app_file_name,S32 app_filesize);

/**
* ���Ӧ�ó���İ汾��,Ϊ�첽�ӿ�.
* 
* @appid	Ϊ��Ҫ����Ӧ�ó�����.
* @sync_cb  	�ص�������
*
* @ return 0 ��������ɹ�������Ϊʧ�ܡ�
*/
S32 srv_vre_dl_check_app_version (U32 appid, sync_cb sync_callback);


S32 srv_vre_dl_cancel_check_app_version (void);




/************************************************************** Update Interfaces *********************************************************/
#define AM_UPDATE_BILLING_INTERVAL      3

#define AM_NVRAM_READ_MAX_VALUE         16

#define VAM_RES_PATH_SIZE               (1024 * 4)

#define UPDATE_CONFIG_PATH "/update/config.txt?timezonzeid=China&permission=%s&cert=%s&appblalst=%s&channel=%s&appstore=%s"



#define VRE_SRV_CDR_NO_SYSC_CDR	                					(0)
#define VRE_SRV_CDR_NVRAM_NEED_FOR_SYNC_CDR				    (1)
#define VRE_SRV_CDR_TIME_NEED_FOR_SYNC_CDR					(2)




/*
*	ϵͳ������������
*/
typedef enum 
{
	VRE_SYSTEM_TIME = 1,  /*ϵͳʱ��*/
	VRE_PUBLIC_KEY,       /*public key*/
	VRE_PERMISSION_BLACK_LIST, /*ϵͳȨ��*/
	VRE_APPLICATION_BLACK_LIST,/*������*/
	VRE_PAYMENT_CHANNEL,/*�Ʒ�ͨ��*/
	VRE_APPSTORE_VERSION,/*AS�Ƿ���±�־*/
	VRE_SHOW_FEE_HINT /*�Ʒ���Ϣ��ʾ��־*/
}E_SysCfgCnt_t;


extern S32 srv_vre_update_sync_cdr(void (*sync_cb)(S32 nResult));

extern void srv_vre_update_cancel_sync_cdr(void);

extern S32 srv_vre_update_is_sync_cdr(void);






/*********************************************************** Data Account Interfaces *********************************************************/
typedef enum
{
    SRV_VRE_DA_SIM1,
    SRV_VRE_DA_SIM1_PX,
    SRV_VRE_DA_SIM2,
    SRV_VRE_DA_SIM2_PX,
    SRV_VRE_DA_WIFI_ONLY
}srv_vre_da_type;


/*****************************************************************************
 * FUNCTION
 *  srv_vre_da_init
 * DESCRIPTION
 *  VRE service, init VRE data account
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_vre_da_init(void);


/*****************************************************************************
 * FUNCTION
 *  srv_vre_da_deinit
 * DESCRIPTION
 *  VRE service, deinit VRE data account
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_vre_da_deinit(void);


/*****************************************************************************
 * FUNCTION
 *  srv_vre_da_get_app_id
 * DESCRIPTION
 *  VRE service, data account , to get a app ID
 * PARAMETERS
 *  void
 * RETURNS
 *  Application ID
 *****************************************************************************/
extern U8   srv_vre_da_get_app_id(void);


/*****************************************************************************
 * FUNCTION
 *  srv_vre_da_get_account_id
 * DESCRIPTION
 *  VRE service, data account , to get a data account ID from NVRAM, could use this interface
 * PARAMETERS
 *  da_type         [IN]        The type of VRE Data account want to get
 * RETURNS
 *  Data Account ID of needed type.
 *****************************************************************************/
extern U32  srv_vre_da_get_account_id(srv_vre_da_type da_type);


/*****************************************************************************
 * FUNCTION
 *  srv_vre_da_set_account_id
 * DESCRIPTION
 *  VRE service, data account , to Set a data account ID to NVRAM, could use this interface
 * PARAMETERS
 *  da_type         [IN]        The type of VRE Data account want to get
 *  da_id           [IN]        Data Account ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_vre_da_set_account_id(srv_vre_da_type da_type, U16 da_id);



#ifdef __cplusplus
}
#endif

#endif /* __SRV_VRE_DOWNLOAD_H__ */
