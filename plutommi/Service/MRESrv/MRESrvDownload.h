#ifndef __SRV_MRE_DOWNLOAD_H__
#define __SRV_MRE_DOWNLOAD_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "mmi_features.h"
#include "vmswitch.h"
#include "MRESrvDownloadGprot.h"

#ifdef __MRE_LIB_NETWORK__
#define MRE_DOWNLOAD_SRV
#endif

#if defined(MRE_DOWNLOAD_SRV)

//#define SRV_MRE_DL_LOG_ON
#define SRV_MRE_DL_TRACE_ON


#if defined(SRV_MRE_DL_LOG_ON)

#define SRV_MRE_DL_LOG vm_log_fatal

#else /* defined(SRV_MRE_DL_LOG_ON) */

#ifdef WIN32
#define SRV_MRE_DL_LOG  1 ? (void)0 : vm_log_fatal
#else
#define SRV_MRE_DL_LOG(...)
#endif 

#endif /* defined(SRV_MRE_DL_LOG_ON) */


#if defined(SRV_MRE_DL_TRACE_ON)

#define SRV_MRE_DL_TRACE MMI_TRACE

#else /* defined(SRV_MRE_DL_LOG_ON) */

#ifdef WIN32
#define SRV_MRE_DL_TRACE  1 ? (void)0 : MMI_TRACE
#else
#define SRV_MRE_DL_TRACE(...)
#endif 

#endif /* defined(SRV_MRE_DL_LOG_ON) */




#define SRV_MRE_DL_TRACELINE          SRV_MRE_DL_TRACE(MMI_MRE_TRC_G2_SERVICE_DL, TRC_MRE_SERVICE_DL_TRACELINE, __LINE__);


    /**************************** VIP ���ش���************************************/
#define  MAX_LEN_APP_VERSIONID              (22)
#define  MAX_LEN_APP_NAME                   (24)
#define  MAX_LEN_TIME                       (10)
#define  SAFE_FREE(p)                       if(p){ vm_free(p); (p) = NULL; }
#define  VAM_DOWNLOAD_DEFAULT_SIZE          (25 * 1024)


#define  VAM_ADD_APP                        0   //VAM��ӵ�Ӧ��
#define  VAM_ADD_VAS                        4   //VAM��ӵ�VAS
#define  APPSTORE_ID                        "appstore"

#define  VAM_MAX_APP_NUM                    10 //VAM֧�ֵ�Ӧ�ø���
/**
* ������һ��������һ���ʱ����,��λ:����
*/
#define VAM_DOWNLOAD_INTERVAL               (10)      

/**
* �����ļ��Ŀ��С
*/
#define  VAM_DOWNLOAD_DEFAULT_SIZE          (25 * 1024)

/**
* ��ʱ�ļ���׺
*/
#define  VAM_TASK_TEMP_SUFFIX               "tmp"     /*��ʱ�ļ���׺*/

//copy ���С
#define DM_COPY_SIZE                          (5 * 1024)





//�Ƿ�֧��uftת��
#define AM_SUPPORT_UTF_CHSET
/**
* ������Դ���
*/
#define VAM_DOWNLOAD_RETRY_MAX_COUNT                           3




typedef struct mre_vip_func
{
    VMINT(*register_vip_callback)(vm_vip_callback pf);
    VMINT(*register_vip_callback_for_app)(vm_vip_callback pf);
    VMINT(*vip_init)(VMINT phoneid, VMINT userid);
    VMINT(*vip_init_ext)(VMINT phoneid, VMINT userid, VMINT nHandle);
    VMINT(*register_vip_progress_callback)(vm_vip_progress_callback progress_hook);
    VMINT(*register_vip_progress_callback_for_app)(vm_vip_progress_callback progress_hook);
    VMINT(*vip_read_resource)(VMCHAR* respath);
    void(*cancel_all_vip_request)(void);
    void(*vip_cancel_request_and_finalize)(void);
    void(*vip_cancel_request_handle)(VMINT nHandle);  

}MRE_VIP_FUNC;

extern VMINT srv_mre_dl_load_vip_func(MRE_VIP_FUNC *func);


#endif /* MRE_DOWNLOAD_SRV */


#ifdef __cplusplus
}
#endif

#endif /* __SRV_MRE_DOWNLOAD_H__ */
