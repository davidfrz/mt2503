/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * 
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * 
 *
 * Author:
 * -------
 * 
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef VIP_H_
#define VIP_H_

#include "vmswitch.h"

#ifdef __MRE_LIB_NETWORK_VIP__

 
#include "vmsys.h"
#include "vmhttp.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __MRE_LIB_NETWORK_VIP_VG__


#define SHELL_CONFIG_FILENAME           "shell_config.cfg"//shaw

#ifdef _VMDEBUG
#define  PHSH_VIP_DEBUG         //shaw
#endif
//#define  APPSTORE_SUPPORT_COFING
#define  VIP_SUPPORT_NEW_BILLING

//rencai.xiao 2010/04/19 VIP support to upload imsi
#define VIP_SUPPORT_UPLOAD_IMSI

#define VIP_CHECK_DOWNLOAD_READY
/**
 * @name VIPЭ��İ汾��
 * @brief ����Ҫѡ������е���һ����
 * @{
 */
//#define VIP12
//#define VIP13
#define VIP14  //add by shaw, 09/11/04
/** @} */

/* 
 * VIPͨѶ��������ַ 
 */
#ifdef OS_ANYKA
	#define PROVISION_URL "http://anyka.vspace.net.cn/vmac/servlet/provision"
#else
   //#define  PROVISION_URL "http://www.vspace.net.cn/vresps3/provision"
//#define  PROVISION_URL "http://172.26.59.60:8080/vresps/provision"//VIP14���Ժ�̨
    //#define  PROVISION_URL "http://www.vspace.net.cn/vresps/provision"//VIP14���Ժ�̨
	//#define PROVISION_URL "http://www.vspace.net.cn/vresps/provision"//�²��Ժ�̨
	#define PROVISION_URL "http://as.vspace.net.cn:9999/vresps/provision"//��ʽ��̨
    //#define PROVISION_URL "http://www.vspace.net.cn/vmacmtk/provision" 
	//#define PROVISION_URL "http://218.249.47.76/sps/provision"//������̨
	//#define PROVISION_URL "http://www.vspace.net.cn/shelldemo/provision"
	//#define PROVISION_URL "http://192.168.0.53:8080/sps/provision"
	//#define PROVISION_URL "http://www.vogins.com:9999/vmac/servlet/provision"
#endif


#ifndef VIP12
#define VIP_UPDATE_MRE_SYS_CONFIG_URL	"/update/config.txt"       /*ϵͳ������Ϣ*/
#define VIP_DSM_URL						"/shell/app_list.txt"      /*�����б�*/
#define VIP_MRE_EXECUTABLE_FILE_URL		"/shell/download_app.txt"  /*����Ӧ��*/

#define VIP_FEE_CHANNEL_RUL             "/update/feechannel.txt"   /*�Ʒ�ͨ��*/
#ifdef VIP14
#define VIP_DSM_DOWN_TOP_URL            "/shell/down_top.txt"      /*��������*/
#define VIP_DSM_NEW_TOP_URL             "/shell/new_top.txt"       /*�����ϼ�*/
#define VIP_DSM_RECOMMEDN_URL           "/shell/recommend.txt"     /*��Ʒ�Ƽ�*/
#define VIP_DOWNLOAD_ICON_URL           "/shell/download_icon.txt" /*iconͼ��*/
#define VIP_RANK_APP_URL                "/shell/rank_app.txt"      /*����*/
#define VIP_MSG_LIST_URL                "/shell/msg_list.txt"      /*վ����Ϣ*/
#define VIP_APP_DETAIL_URL              "/shell/app_detail.txt"    /*��Ʒ��ϸ��Ϣ*/
#define VIP_WAP_LIST_URL                "/shell/wap_list.txt"      /*�ֻ���վ*/

#ifdef VIP_SUPPORT_NEW_BILLING
#define VIP_SYNC_FEEINFO_URL            "/upload/sync_feeinfo.txt"  /*�Ʒ���Ϣͬ��*/
#define VIP_SYNC_SMSINFO_URL            "/upload/sync_smsinfo.txt"  /*������Ϣͬ��*/
#define VIP_PROMOTION_UPDATE_URL        "/update/promotion_update.txt" /*����������*/
#endif
#endif
#endif



/**
 * @struct user_info_t
 * @brief VIPЭ��õ��û����ݵĽṹ.
 */
typedef struct user_info_t {
	int userid;
	char nickname[50];
	char password[50];
} user_info_t;

/**
 * @struct session_pool_item_t
 * @brief HTTP ���ӵĹ���ṹ.
 */
typedef struct session_pool_item_t {
	int used;
	http_session_t session;
} session_pool_item_t;

#ifndef VIP12
/**
 * @struct vm_http_item_t
 * @brief http���������������.
 */
typedef struct vm_vip_item_t {
	VMINT user_id;							/**<MRE�û����.								*/
	VMINT mobile_phone_id;					/**<���ͺ���VIP13���Ժ�İ汾���ɷ����������.	*/
	VMINT http_handle;						/**<HTTP���Ӿ��. 								*/
	VMSHORT used;							/**<�Ƿ����ڷ��͵ı�־λ.						*/
	VMUINT8 des_key[8];						/**<DES��Կ.									*/
	VMSHORT encrypt;						/**<�ô������Ƿ񱻼���,0Ϊ����,��0Ϊ
												�Ѿ�������.									*/
	vm_vip_callback callback;				/**<�ͻ�����ע�������Ļص�����.					*/
	VMCHAR vip_session[255];				/**<��VIPͨѶ�ڼ�����ĻỰ��.					*/
	VMUINT8* repeat_content;				/**<���·��͵����ݡ�							*/
	VMINT repeat_content_size;				/**<�ط����ݵĳ��ȡ�							*/
	VMINT allow_repeat;						/**<�Ƿ��������·���VIP����					*/
	vm_vip_progress_callback progress_hook;	/**<VIPЭ����ȵĻص�������						*/
} vm_vip_item_t;
#endif


/**
 * @name ʹ��ģʽ.
 */
#define USAGE_MODE_PER_TIME		(1)
#define USAGE_MODE_PERIOD		(2)

/**
 * @name ���ѷ�ʽ.
 */
#define PAY_METHOD_BY_WAP		(1)
#define PAY_METHOD_BY_SMS		(2)

//add by shaw, 09/11/06


#ifdef LINK_RICH
/* ���żƷѷ�ʽ */
typedef struct sms_charge_t {
	char access_number[21];
	char order[100];
	int sms_count;
} sms_charge_t;
/* WAP�Ʒѷ�ʽ */
typedef struct wap_charge_t {
	char reverse_subscribe_url[181];	// ���򶩹���ַ��
} wap_charge_t;
/* �Ʒѷ�ʽ */
typedef union charge_info_t {
	sms_charge_t sms_info;
	wap_charge_t wap_info;
} charge_info_t;
/* �Ʒ���Ϣ */
typedef struct price_t {
	BYTE usage_mode;					// �Ʒ�ģʽ
	int param;							// �Ʒ����������
	int price;							// �����۸�
	BYTE pay_method;					// �Ʒ��÷�ʽ
	char download_song_url[181];		// �������ص�ַ
	charge_info_t charge_info;			// �Ʒ���Ϣ
} price_t;
#else
typedef struct price_t {
	int usage_mode;
	int param;
	int price;
	int pay_method;
	char access_number[21];
	char order_cmd[100];
	int sms_count;
} price_t;
#endif

/**
 * @struct res_content_t
 * @brief ��Դ�����Ӧ����Ӧ.
 */
typedef struct res_content_t {
	int len;					/**<��Դ��Ӧ���ֽڳ��ȡ�	*/
	BYTE* buf;					/**<��Դ��ͷָ�롣			*/
} res_content_t;



/**
 *��ȡHTTP������ַ
 *
 * @return     0��ʾ��ȡ�ɹ��������ȡʧ��
 */
VMINT vip_get_shell_config_value(VMCHAR * key_value, VMCHAR * pro_url);


void vip_vg_set_update(VMINT is_updating);


#endif /* __MRE_LIB_NETWORK_VIP_VG__ */



/**
 * @name ����
 */
#define  VIP_APP_HANDLE         (0)      //����Ӧ�õ�����
#define  VIP_OTHER_HANDLE       (1)      //�����������ݵ�����


/**
 * @name VIP�����������.
 * @{
 */
#define REQ_CONNECT_CMD				1
#define REQ_WAP_PROXY_RESULT		2
#define REQ_ASK_FOR_PRICE_CMD		3
#define REQ_PAY_BY_WAP				4
#define REQ_GET_USER_INFO			6
#define REQ_ENCRYPT_CMD				7
#define REQ_READRES_CMD				10
#define REQ_POST_DATA_CMD           11
/** @} */

/**
 * @name VIP��Ӧ��������.
 * @{
 */
#define RES_WAP_PAYMENT_COMPLETE	1
#define RES_PROCESS_WAP_PROXY		2
#define RES_PRICE_INFO_CMD			3
#define RES_ERROR_CMD				5   /*����ʧ���������*/
#define RES_ENCRYPT_CMD				7
#define RES_USER_INFO				6
#define RES_ENCRYPT_CMD				7
#define RES_RESCONTENT_CMD			10  /*���سɹ�*/

/** @} */

typedef unsigned char BYTE;
/**
 * @struct error_t
 * @brief ������Ӧ.
 */
typedef struct error_t {
	int code;					/**<�����롣				*/
	char message[255];			/**<��������ص�����˵����	*/
} error_t;









/**
 * VIPЭ�����ע��ص����������͡�
 */
#ifdef VIP12
typedef void (* vm_vip_callback) (VMINT vip_response_type, const void* vip_response);
#else
typedef void (* vm_vip_progress_callback)(VMINT percent);
typedef void (* vm_vip_callback) (VMINT uid, VMINT mpi, VMINT vip_response_type, 
	const void* vip_response, VMUINT response_size);
#endif


/**
 * ��vip�����߼���ע��ص��������ú���Ӧ���ڷ����κ�vip
 * �������á�
 * 
 * @param[in]	pf ע�ᵽvipͨѶ�Ļص�������
 * @return		0 ��ʾע��ɹ�������Ϊ�����룬������Ҳ������vip_init�������ú�
 *				�����á�
 */
VMINT register_vip_callback(vm_vip_callback pf);


/**
 * ��vip�����߼���ע��ص��������ú���Ӧ���ڷ����κ�vip
 * �������á�
 * 
 * @param[in]	pf ע�ᵽvipͨѶ�Ļص�������
 * @return		0 ��ʾע��ɹ�������Ϊ�����룬������Ҳ������vip_init�������ú�
 *				�����á�
 */
VMINT register_vip_callback_for_app(vm_vip_callback pf);


/**
 * ��ʼ��VIPЭ��ջ��������������ڵ����κ�VIP����֮ǰִ�С�
 * 
 * @param[in]			phondid	�ֻ��ͺű�š�
 * @param[in]			userid �û���š�
 * @return				0��ʾ��ʼ���ɹ�������Ϊʧ�ܡ�
 */
VMINT vip_init(VMINT phoneid, VMINT userid);


/**
 * ��ʼ��VIPЭ��ջ��������������ڵ����κ�VIP����֮ǰִ�С�
 * 
 * @param[in]			phondid	�ֻ��ͺű�š�
 * @param[in]			userid �û���š�
 * @param[in]           nHandle ��ʼ����VIP_APP_HANDLEΪ����Ӧ�õľ����VIP_OTHER_HANDLE�����������ݵľ��
 * @return				0��ʾ��ʼ���ɹ�������Ϊʧ�ܡ�
 */
VMINT vip_init_ext(VMINT phoneid, VMINT userid, VMINT nHandle);


/**
 * ��VIPЭ��ջע��һ����ʾ���ȵĻص�������������ֻ����VIP13Э�����ű�ʵ�֡�
 * 
 * @param[in]			progress_hook �ش�����VIP��Ӧ�Ľ��ȡ�
 * @return				0��ʾ�ɹ�������Ϊʧ�ܣ�������Ҳ������
*/

VMINT register_vip_progress_callback(vm_vip_progress_callback progress_hook);


//add by shaw, 09/11/05  ����ע������App�ص��Ľӿ�
VMINT register_vip_progress_callback_for_app(vm_vip_progress_callback progress_hook);


/**
 * ����Դ�����Ǹ��첽���������ú��������أ����ͨ��VM_VIP_RESCONTENT��Ϣ������Ӧ�ó���
 *
 * @param[in]			respath ��Դ·����
 */
VMINT vip_read_resource(VMCHAR* respath);


/**
 * ȡ��vip���󣬶���VIP13Э�鼰���ϰ汾����Ч��ͬ
 * vip_cancel_request_and_finalize������ͬ��
 */
void cancel_all_vip_request(void);


/**
 * ȡ��vip���󣬲����ͷŵ����е���Դ����������vip_init��Ӧ�����������vip_init
 * �����������ñ��������ͷ���Դ��
 */
void vip_cancel_request_and_finalize(void);


/**
 * ȡ��ָ�����������
 *
 * @nHandle ָ���ľ����VIP_APP_HANDLEΪ����Ӧ�õľ����VIP_OTHER_HANDLEΪ�����������ݵľ��
 */
void vip_cancel_request_handle(VMINT nHandle);


/**
 * �ͷų�ʼ��ʱ����Ŀռ�
 */
void vip_finalize(void);




#ifdef __cplusplus
}
#endif

#endif /* __MRE_LIB_NETWORK_VIP__ */

#endif /* VIP_H_ */
