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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VM_ENV__
#define __VM_ENV__

#ifdef __cplusplus
extern "C" {
#endif

#include "vmswitch.h"

#include "vmsys.h"
#include "vmdl.h"
#include "vmpromng.h"
#include "vmloader.h"

typedef enum {
	MRE_EVT_START_SUCCESS = 0,	/** succeed to start application async **/		    
    MRE_EVT_START_ASM_READY,    /**<ASM�ڴ����ɹ���MRE�����ɹ���                              */         
	MRE_EVT_START_INTERNEL_ERROR,		/**<ϵͳ�������������ڲ�ʧ�ܡ�									*/
	MRE_EVT_QUIT							/**<MRE �����˳�����Ϣ�� 												*/
} VAM_START_MRE_EVT;

typedef void (*vm_mre_evt_cb_t)(VAM_START_MRE_EVT evt);
typedef void (*vm_mre_app_evt_cb_t)(VMUWSTR fileName, VAM_START_MRE_EVT evt);

#define VM_VLC_START_SUCCESS					(0)
#define VM_VLC_ASYN_ALLOC_ASM					(1)
#define VM_VLC_MASS_STORAGE					(-1)
#define VM_VLC_MEDIA_BUFFER_ALLOC_ERROR		(-2)
#define VM_VLC_INTERNEL_ERROR					(-3)
#define VM_VLC_NOT_ENOUGH_MEMORY            (-4)


#define VM_START_APP_NORMAL              0
#define VM_START_APP_EXIT_PARENT         1
#define VM_START_APP_RESTART_PARENT      2
#define VM_START_APP_NO_SELECT_POPUP     4
#define VM_START_APP_INSTALL             8
#define VM_FLAG_DIS_WLAN_PERFER (0X80000000)

/**
 * ����MRE ���������ǲ���ע��Pen, Keyboard����Ϣ����Ҳ����
 * ����MRE ��SCREEN��������SCREEN��һ�����⣬��MREʹ��ASM
 * �ڴ沢���ڴ�û�з��䵽��ʱ��ASM Framework���ܻ����Լ�
 * ��Popup Screen�����MRE�����Ѿ���������ñ������������κ�
 * �Ĵ������ҷ��������ɹ���
 * 
 * @param[in]					state ��ǰû���õ���Ĭ��Ϊ0��
 * @return					����MRE�Ƿ�ɹ��ķ���ֵ��
 * @retval					VM_VLC_START_SUCCESS �����ɹ���
 * @retval					VM_VLC_ASYN_ALLOC_ASM ASMû�з��䵽
 *							ϵͳ���첽�ͷŵ�����ռ��ASM��Ӧ�á�
 * @retval					VM_VLC_MASS_STOREAGE �ֻ����ڴ洢ģʽ��MRE����ʧ�ܡ�
 * @retval					VM_VLC_MEDIA_BUFFER_ALLOC_ERROR MRE����media bufferʧ�ܡ�
 * @retval					VM_VLC_INTERNEL_ERROR MRE�ڲ�����
 */
VMINT vm_vam_load_core(vm_mre_evt_cb_t vam_cb);

/**
 * @name vm_execute�����ķ���ֵ
 * @{
 */
/**
 * �ɹ�������ָ��Ӧ�á�
 */
#define VM_EXECUTE_APP_SUCCESS					(0)

/**
 * ָ��Ӧ��Ϊ�Ƿ���Ӧ�ó���
 */
#define VM_EXECUTE_APP_ILLEGAL					(-1)

/**
 * û���㹻���ڴ�����Ӧ�á�
 */
#define VM_EXECUTE_APP_NOT_ENOUGH_MEMORY		(-2)

/**
 * ����ջ������
 */
#define VM_EXECUTE_APP_CALL_STACK_FULL			(-3)

/**
 * �����ں��ڲ����󣬰���IO��ȡ����ȡ�
 */
#define VM_EXECUTE_INTERNAL_ERROR				(-4)

/**
 * Ӧ�ó������в�����ƽ̨������ƥ�䡣
 */
#define VM_EXECUTE_PLATFORM_PARAM_DISMATCH		(-5)

/**
 * Ӧ�ó��򳬹���Ч�ڡ�
 */
#define VM_EXECUTE_TIMESTAMP_ERROR				(-6)

/**
 * �Ǻ�������Ӧ�ò���������
 */
#define VM_EXECUTE_BANNED_APP					(-7)

/**
 * Ӧ�ó����IMSI����ƽ̨��IMSI��ƥ�䣬����ʧ�ܡ�
 */
#define VM_EXECUTE_IMSI_DISMATCH					(-8)

/**
 * Ӧ�ó���ʹ�õ�֤����ڡ�
 */
#define VM_EXECUTE_CERT_OVERDUE					(-9)

/**
 * ��MREĿ¼���ļ�����5000���򷵻ظô����롣
 */
#define VM_EXECUTE_EXCEED_FILE_IN_MRE_DIRECTORY (-10)

/**
 * ϵͳû���㹻���ڴ�������Ӧ�á�����˳����е�Ӧ��Ҳ����������
 * Ӧ�á�
 */
#define VM_EXECUTE_SYS_NOT_ENOUGH_MEMORY		(-11)

/* */
#define VM_EXECUTE_SYS_ASYN_ASM     (-12)

#define VM_EXECUTE_SYS_NOT_SUPPORT_VP   (-13)

#define VM_EXECUTE_ONLY_ONE_FOREGROUND   (-14)

#define VM_EXECUTE_MAX_APP_NUM_REACHED   (-15)

#define VM_EXECUTE_VERSION_NOT_MATCH    (-16)
/**@} */

/**
 * ����Ӧ�ó������Ӧ�������ɹ���MRE �ᴴ��MRE ��SCREEN��
 * ʧ���򲻻ᴴ����������ļ��Ѿ�����������MRE��ֱ�Ӱ�
 * ��Ӧ�õ��ȵ�ǰ̨��
 * 
 * @param[in]				filename ��Ҫ�������ļ����ƣ���Ҫ������·����
 * @return				�Ƿ�ɹ�������Ӧ�ó���ķ���ֵ��
 * @retval				VM_EXECUTE_APP_SUCCESS ����Ӧ�ó���ɹ���
 * @retval				VM_EXECUTE_APP_ILLEGAL �Ƿ���Ӧ�ó���
 * @retval				VM_EXECUTE_APP_NOT_ENOUGH_MEMORY û���㹻���ڴ�����Ӧ�ó���
 * @retval				VM_EXECUTE_APP_CALL_STACK_FULL ���ö�ջ������
 * @retval				VM_EXECUTE_INTERNAL_ERROR �����ں��ڲ�����
 * @retval				VM_EXECUTE_PLATFORM_PARAM_DISMATCH ƽ̨������ƥ�䡣
 * @retval				VM_EXECUTE_TIMESTAMP_ERROR Ӧ�ó��򳬹���Ч�ڡ�
 * @retval				VM_EXECUTE_BANNED_APP �Ǻ�������Ӧ�ò���������
 * @retval				VM_EXECUTE_IMSI_DISMATCH Ӧ�ó����IMSI����ƽ̨��IMSI��ƥ�䣬����ʧ�ܡ�
 * @retval				VM_EXECUTE_CERT_OVERDUE Ӧ�ó���ʹ�õ�֤����ڡ�
 * @retval				VM_EXECUTE_EXCEED_FILE_IN_MRE_DIRECTORY MREĿ¼���ļ�����5000�����ظô����롣
 */
VMINT vm_execute(VMWSTR filename, vm_mre_app_evt_cb_t vam_cb);

/**
 * ����Ԥ���ص�Ӧ�ó������Ӧ�������ɹ���MRE �ᴴ��MRE ��SCREEN��
 * ʧ���򲻻ᴴ����������ļ��Ѿ�����������MRE��ֱ�Ӱ�
 * ��Ӧ�õ��ȵ�ǰ̨��
 * 
 * @param[in]				filename ��Ҫ�������ļ����ƣ���Ҫ������·����
 * @return				�Ƿ�ɹ�������Ӧ�ó���ķ���ֵ��
 * @retval				VM_EXECUTE_APP_SUCCESS ����Ӧ�ó���ɹ���
 * @retval				VM_EXECUTE_APP_ILLEGAL �Ƿ���Ӧ�ó���
 * @retval				VM_EXECUTE_APP_NOT_ENOUGH_MEMORY û���㹻���ڴ�����Ӧ�ó���
 * @retval				VM_EXECUTE_APP_CALL_STACK_FULL ���ö�ջ������
 * @retval				VM_EXECUTE_INTERNAL_ERROR �����ں��ڲ�����
 * @retval				VM_EXECUTE_PLATFORM_PARAM_DISMATCH ƽ̨������ƥ�䡣
 * @retval				VM_EXECUTE_TIMESTAMP_ERROR Ӧ�ó��򳬹���Ч�ڡ�
 * @retval				VM_EXECUTE_BANNED_APP �Ǻ�������Ӧ�ò���������
 * @retval				VM_EXECUTE_IMSI_DISMATCH Ӧ�ó����IMSI����ƽ̨��IMSI��ƥ�䣬����ʧ�ܡ�
 * @retval				VM_EXECUTE_CERT_OVERDUE Ӧ�ó���ʹ�õ�֤����ڡ�
 * @retval				VM_EXECUTE_EXCEED_FILE_IN_MRE_DIRECTORY MREĿ¼���ļ�����5000�����ظô����롣
 */
VMINT vm_execute_preload_app(vm_preload_app_info_t *preload_info, vm_mre_app_evt_cb_t vam_cb);

/**
 * �Ѿ����е�Ӧ�ó�����Ϣ��
 */
typedef struct vm_running_app_info_t
{
	VMWCHAR app_filename[MAX_APP_NAME_LEN + 1];		/**< ��ǰ�Ѿ����е�Ӧ�ó�������ơ�*/
	VMINT app_id;										/**< Ӧ�ó����š�							*/
	VMUINT alloc_mem;									/**< �ڴ�ռ��������λΪKB�� 				*/
}vm_running_app_info_t;

/**
 * ����Ӧ�ó����������VM_EXECUTE_APP_NOT_ENOUGH_MEMORY�������bg_app_infos��
 * app_info_numָ���λ��д�뵱ǰ���ں�̨���еĽ����б�������
 * �ڲ�ʹ��bg_app_infos��ָ���ڴ�ʱ���������vm_release_app_running_infos�ͷ�
 * exist_app_infos��ָ��Ķ���
 *
 * @code 
 * VMINT ret = VM_EXECUTE_APP_SUCCESS;
 * VMUINT infos_num = 0;
 * vm_running_app_info_t* infos = NULL;
 * 
 * ret = vm_execute_app((VMWSTR)L"c:\\mre\\game.vxp", &infos, &infos_num);
 * switch (ret)
 * {
 * case VM_EXECUTE_APP_NOT_ENOUGH_MEMORY:
 *     // ��ʾ�û��˳�Ӧ�ÿ���������Ӧ�á�
 *     if (infos != NULL)
 *     {
 *         vm_release_app_running_infos(infos);
 *     }
 *     break;
 * case VM_EXECUTE_SYS_NOT_ENOUGH_MEMORY:
 *     // ��ʾӦ���޷����У��ڴ��������
 *     break;
 * case VM_EXECUTE_TIMESTAMP_ERROR:
 *     ......
 * }
 * @endcode
 * 
 * @param[in]				filename ��Ҫ�������ļ����ơ�
 * @param[out]			bg_app_infos ���ں�̨���е�Ӧ�ó������Ϣ��
 * @param[out]			app_info_num ���ں�̨���е�Ӧ�ó�����Ϣ������
 * @param[in]				filename ��Ҫ�������ļ����ƣ���Ҫ������·����
 * 
 * @return				�Ƿ�ɹ�������Ӧ�ó���ķ���ֵ��
 * @retval				VM_EXECUTE_APP_SUCCESS ����Ӧ�ó���ɹ���
 * @retval				VM_EXECUTE_APP_ILLEGAL �Ƿ���Ӧ�ó���
 * @retval				VM_EXECUTE_APP_NOT_ENOUGH_MEMORY û���㹻���ڴ�����Ӧ�ó���
 * @retval				VM_EXECUTE_APP_CALL_STACK_FULL ���ö�ջ������
 * @retval				VM_EXECUTE_INTERNAL_ERROR �����ں��ڲ�����
 * @retval				VM_EXECUTE_PLATFORM_PARAM_DISMATCH ƽ̨������ƥ�䡣
 * @retval				VM_EXECUTE_TIMESTAMP_ERROR Ӧ�ó��򳬹���Ч�ڡ�
 * @retval				VM_EXECUTE_BANNED_APP �Ǻ�������Ӧ�ò���������
 * @retval				VM_EXECUTE_IMSI_DISMATCH Ӧ�ó����IMSI����ƽ̨��IMSI��ƥ�䣬����ʧ�ܡ�
 * @retval				VM_EXECUTE_CERT_OVERDUE Ӧ�ó���ʹ�õ�֤����ڡ�
 * @retval				VM_EXECUTE_EXCEED_FILE_IN_MRE_DIRECTORY MREĿ¼���ļ�����5000�����ظô����롣
 * @retval				VM_EXECUTE_SYS_NOT_ENOUGH_MEMORY Ӧ������Ҫ�ڴ����ϵͳ�޷���������
 * 
 * @see					vm_release_app_running_infos
 */
VMINT vm_execute_app(VMWSTR filename, vm_running_app_info_t** bg_app_infos, VMUINT* app_info_num);

/**
 * �ͷ��ɵ���vm_execute_ext�����������������е�Ӧ�ó�����Ϣ��
 *
 * @param[in]				app_infos Ӧ�ó�����Ϣ��
 * @see					vm_execute_ext
 */
void vm_release_app_running_infos(vm_running_app_info_t* app_infos);

/**
 * ��ֹӦ�ó���ɹ���
 */
#define VM_TERMINATE_SUCCESS					(0)

/**
 * ��������
 */
#define VM_TERMINATE_ERROR_PARAM				(-1)

/**
 * ��Ҫ��ֹ��Ӧ�ó��򲻴��ڡ�
 */
#define VM_TERMINATE_NOT_EXISTS				(-2)

/**
 * ֹͣ��ǰ̨���еĽ��̡�
 */
#define VM_TERMINATE_ERROR_STATUS			(-3)

/**
 * ��ֹ��̨���е�Ӧ�ó���
 * 
 * @code
 * vm_terminate_bg_app((VMWSTR)L"c:\\mre\\game.vxp");
 * @endocde
 * @param[in]					filename ��Ҫ��ֹ��Ӧ�ó�������ƣ��Ǿ���·����
 * @return					�Ƿ�ɹ���ֹӦ�ó���ı�־��
 * @retval					VM_TERMINATE_SUCCESS �ɹ���ֹӦ�ó���
 * @retval					VM_TERMINATE_ERROR_PARAM ��������
 * @retval					VM_TERMINATE_NOT_EXISTS ָ����Ӧ�ó��򲻴��ڡ�
 * @retval					VM_TERMINATE_ERROR_STATUS ֹͣ��Ӧ�ó�������ǰ̨���У���ֹӦ��
 *							����ʧ�ܡ�
 */
VMINT vm_terminate_bg_app(VMWSTR filename);

/**
 * ���MRE����Ӧ���������У����ñ�������û������;
 * ���MREû�����е��ñ�����Ҳû���κ�����;
 * ���MREû��Ӧ������������MRE���������ɹ���
 * ���ñ������ὫMRE�����˳���
 */
void vm_vam_unload_core(void);

void vm_vam_unload_core_by_asm(void);

#define		VAM_IN_USE					1
#define		VAM_OUT_OF_USE			0

/*
 * ֪ͨ�ں�VAM��״̬
 *  
 * @param[in] 			VAM_IN_USE ��ʾVAM�������У�VAM_OUT_OF_USE ��ʾVAM�Ѿ��˳���
*/
void vm_vam_set_vam_state(VMINT state);

/**
 * VAM ��MRE�����ڴ档
 * 
 * @param[in]				size ��Ҫ������ڴ�����
 * @return				NULL ����ʧ�ܣ�����Ϊ�ڴ���׵�ַ��
 */
void* vm_vam_malloc(VMINT size);

/**
 * VAM �ͷ��ڴ�ʱ���á�
 * 
 * @param[in]				p ��Ҫ�ͷŵ��ڴ��׵�ַ��  
 */
void vm_vam_free(void* p);


/*
 * �ж�Ӧ�ó����Ƿ������С�
 *
 * @param[in]				vxp_filename	Ӧ�õ��ļ�����������ȫ·����
 * @return				���Ӧ�ó����������У�����1�����򷵻�0��
 */
VMINT vm_vam_app_is_running(VMWSTR vxp_filename);

#define		LOAD_VAM_RES_PARAM_ERROR				(-1)
#define		LOAD_VAM_RES_FAIL							(-2)
#define		LOAD_VAM_RES_INSUFFICIENT_BUF			(-3)

/*
 * ���ļ���װ��ָ������Դ
 *  
 * @param[in]					filename �ļ������ơ�
 * @param[in] 				res_name ��Դ���ơ�
 * @param[out]				res_size ������Դ���ȵ�ָ�롣
 * @param[in]					cache_buf �ⲿ���� ��
 * @param[in] 				cache_size �ⲿ����ĳ��ȡ�
 * @return					������Դ�ɹ�����0, ���򷵻ظ����Ĵ����롣
*/
int vm_vam_load_resource_from_file( short * filename, char * res_name, int * res_size, char * cache_buf, int cache_size );

/**
 * �������͡�
 */
typedef enum LANGUAGE_TYPE{
	ENG = 0,		/**<Ӣ�			*/
	CHS,		/**<�������ġ� 	*/
	CHT			/**<�������ġ� 	*/
}LANGUAGE_TYPE;

/**
* �������ļ��л�ȡGIF�������ڴ档���unpackGIFZM.h��unpackGIFZM3.c
* 
* @param[in] 					gifzm ����Դ��
* @param[out] 				data_buf �������ݵĻ��档
* @param[out] 				data_len ����GIF���ݳ��ȡ�
* @return					�ɹ�ʱ����0�����򷵻ظ����Ĵ����롣
*							��data_bufΪ��ʱ���ýӿڲ�ѯ����Ҫ��ȡ�����ݵĴ�С����data_len���ء�
*							��data_buf��Ϊ��ʱ��data_len�ĳ�ʼֵΪdata_buf�Ĵ�С, 
*							�ӿ�ִ���꣬data_len�������ݵ�ʵ�ʴ�С��
*/
VMINT vm_vam_get_gif_data(VMUINT8 *gifzm, VMUINT8 ** data_buf, VMINT *data_len);

/**
* �������ļ��л�ȡ�ַ����������ڴ档���unpackGIFZM.h��unpackGIFZM3.c
* 
* @param[in]					gifzm ����Դ��
* @param[out]				data_buf �������ݵĻ��档
* @param[in]					lan �������͡�
* @param[out]				data_len ����string���ݳ��ȡ�
* @param[out]				font �����ַ��������С��
* @param[out]               data_size ��ģsize
* @return					�ɹ�ʱ����0�����򷵻ظ����Ĵ����롣
*							��data_bufΪ��ʱ���ýӿڲ�ѯ����Ҫ��ȡ�����ݵĴ�С����data_len���ء�
*							��data_buf��Ϊ��ʱ��data_len�ĳ�ʼֵΪdata_buf�Ĵ�С, 
*							�ӿ�ִ���꣬data_len�������ݵ�ʵ�ʴ�С��
*/
VMINT vm_vam_get_string_data(VMUINT8* gifzm, VMUINT8** data_buf, LANGUAGE_TYPE lan, VMINT* data_len, VMINT* font, VMINT *data_size);


/**
 * ��ȡ���ؿ��
 * @param[in] zimo_buf ָ����ģ���ݵ�ָ�� 
 * @param[in] str_len �ַ����� 
 *
 * @return  ��ģ�����ؿ�� 
 */
VMINT vm_vam_measure_zimo_string(VMUINT8 *zimo_buf, VMINT str_len);

/**
 * �����ʱ�ļ��Ƿ�Ϸ������ؽ��ȡ�
 * 
 * @param[in]					filename ��ʱ�ļ������ơ�
 * @param[out]				progress	���ܽ������ݵ�ָ�롣 
 * @return					�����ʱ�ļ��Ϸ�����0, ���򷵻ظ����Ĵ����롣
 *							����0ʱ, progressָ������ݴ�����ȣ�0 - 100����
*/
VMINT vm_vam_check_tempfile(VMSHORT * filename, VMINT* progress);

/**
 * ȡ�����ء�
 */
void vm_vam_cancel_download(void);

/**
 * ����SIM����
 *
 * @param[in]					choose_index ѡ�е�SIM����ţ�1ΪSIM��һ��2ΪSIM������
 * @return                                	���óɹ�����0�����򷵻�-1
 */
VMINT vm_vam_set_sim_card(VMINT choose_index);

/**
 * �����������͡�
 *
 * @param[in]					net_type �������ͣ�1ΪGPRS��2ΪWIFI��
 * @return                             	���óɹ�����0�����򷵻�-1
 */
VMINT vm_vam_set_net_type(VMINT net_type);

/**
 * �õ���ǰ�Ѿ����õĿ���������
 * 
 * @param[out]				�õ���������ָ�롣
 * @return					�Ƿ�ɹ��õ�SIM�������ı�־��
 * @retval					TRUE(1) �ɹ��õ�SIM��������
 * @retval					FALSE(0) ʧ�ܣ�û�еõ�SIM��������
 */
VMINT vm_vam_get_sim_card(VMINT* sim_index);

/**
 * �õ���ǰ�������͡�
 * 
 * @param[out]				�õ��������͵�ָ�롣
 * @return					�Ƿ�ɹ��õ��������͵ı�־��
 * @retval					TRUE(1) �ɹ��õ��������͡�
 * @retval					FALSE(0) ʧ�ܣ�û�еõ��������͡�
 */
VMINT vm_vam_get_net_type(VMINT* net_type);

/**
 * �����������ӵ㡣
 * 
 * @param[in] 				point_type ���ӵ����ͣ�1ΪCMWAP��2ΪCMNET��
 * @return                             	���óɹ�����0�����򷵻�-1
 */
//VMINT vm_vam_set_connection_point(VMINT point_type);

/**
 * ��֤Ӧ�ó����Ƿ���Ч
 * 
 * @param[in]					vxp_filename VXP�ļ����ļ�������ȫ·��
 * @return					Ӧ�ó�����֤ͨ��,����0, ���򷵻ظ����Ĵ����롣�ο�vmcerter.h
 */
VMINT vm_vam_app_is_valid(VMWSTR vxp_filename);

#define  VAM_DL_DONE             	1  //����VXP�������
#define  VAM_DL_OK               		0  //�ɹ�
#define  VAM_DL_ERR              		-1 //ʧ��
#define  VAM_DL_NET_ERR         	-2 //�������         
#define  VAM_DL_SAVE_ERR         	-3 //�������
#define  VAM_DL_APP_NOT_EXIST  -4 //Ӧ�ò�����
#define  VAM_DL_SPACE_FULL       	-5 //�ռ䲻��
#define  VAM_DL_OTHER_ERR        	-6 //��������
#define  VAM_DL_FILE_NOT_EXIST -7 //�ļ�������
#define  VAM_DL_IO_ERROR        -8 //I/O ��������


/**
 * ����Ӧ������* @param download_app_cb     ����Ӧ�ûص�
 *                             @param nResult  ���ؽ��:VAM_DL_OK = �ɹ�����������߳ɹ�������һ��
 *                                                      VAM_DL_DONE = ȫ���������
 *                                                      VAM_DL_ERR�ȴ�����
                                                        VAM_DL_IO_ERROR �ļ���������
														VAM_DL_SPACE_FULL �ռ䲻��
 *                             @param nPercent nResult��ΪVAM_DL_DONEʱ��ʾ���ؽ���,�����ʾ�洢�̷�
 *
 * @param[in] 			    download_app_cb     ����Ӧ�ûص���
 * @param[out] 				nResult  ���ؽ��:VAM_DL_OK = �ɹ�����������߳ɹ�������һ��
 *                                            VAM_DL_DONE = ȫ���������
 *                                            VAM_DL_ERR�ȴ�����
 * @paramp[out] 			nPercent nResult��ΪVAM_DL_DONEʱ��ʾ���ؽ���,�����ʾ�洢�̷�
 * @param[in] 				pszVersionID Ӧ�ð汾��ID��
 * @param[in]				pszFileName �ļ�����
 * @param[in] 				nBlockSize ���ؿ��С��
 * @return                  �ɹ������������󷵻�VAM_DL_OK, ���򷵻ش�����(VAM_DL_ERR, VAM_DL_IO_ERROR, VAM_DL_SPACE_FULL)��
 */
VMINT vm_vam_download_app(void(*download_app_cb)(VMINT nResult, VMINT nPercent), 
	VMUINT32 nAppID/*VMWSTR pszVersionID*/, VMWSTR pszFileName, VMINT nBlockSize);


#define			VMM_RET_NO_SYSC_CDR								(0)
#define			VAM_RET_NVRAM_NEED_FOR_SYNC_CDR				(1)
#define			VAM_RET_TIME_NEED_FOR_SYNC_CDR					(2)

/**
 * �Ƿ���Ҫͬ���Ʒѡ�
 * 
 * @return					�Ƿ���Ҫ���µı�־��
 * @retval					VMM_RET_NO_SYSC_CDR ��ʾ����Ҫ���¡�
 * @retval					VAM_RET_NVRAM_NEED_FOR_SYNC_CDR NVRAM����Ҫ���¡�
 * @retval					VAM_RET_TIME_NEED_FOR_SYNC_CDR ʱ�䵽��Ҫ���¡�
 */
VMINT vm_vam_is_sync_cdr(void);

/**
 * �������ͬ���Ʒ�����
 * 
 * @param[in/out]				sync_cb �ɹ���ʧ�ܵĻص�������nResultΪ0��ʾ�ɹ�����Ϊʧ�ܡ�
 * @return					�ɹ�����ͬ������VAM_DL_OK, ���򷵻ش�����(VAM_DL_ERR, VAM_DL_IO_ERROR)��
 */
VMINT vm_vam_sync_cdr(void (*sync_cb)(VMINT nResult));

/**
 * �õ��û�����
 * 
 * @param[out]				user_balance �û���
 * @return					0 ��ʾ�Ѿ��õ�������Ϊʧ�ܡ�
 */
VMINT vm_vam_get_user_balance(VMUINT* user_balance);

/**
  * ȡ���ƷѸ���
  */
void vm_vam_cancel_sync_cdr(void);
/**
 * ע�������ͷſռ亯��
 *
 * @param mem_calloc_cb   ����ռ�ӿ�
 * @param mem_free_cb     �ͷſռ�ӿ�
 */
void vm_am_pre_download_app(void *(* mem_calloc_cb)(int size), void (* mem_free_cb)(void *ptr));


/**
 * ��ȡӦ�ð汾��
 *
 * @param[in] �ļ���
 * @param[out] �õ��İ汾��
 *
 * @return ��ȡ�ɹ�����VAM_DL_OK�����򷵻�VAM_DL_ERR
 */
VMINT vm_get_app_version(VMWSTR filename, VMINT * version);

/*
 * ������޸��µ�����
 *
 * @return  �����Ӧ�ó���ĸ������󣬷��ظ��������version id,���򷵻�null��
 */
VMWSTR vm_vam_need_update(void);

/*
 * ������£���vam��ȡ���������version id��Ӧ��֪ͨmre������µ�version id��
 */
void vm_vam_clean_update(void);

/**
 * �˳����н��̣��˳�MRE���������MREû����������ñ�����
 * ���������κ����á�
 */
void vm_exit(void);
void vm_exit_ex(VMINT param);

/**
 * ASM �����ڴ�Ĳ�����callback������
 */
void vm_exit_by_asm(void);

/**
 * ������ó����׵�ַ�б�
 * 
 * @param[out]			app_array_ptr ���ó����׵�ַ�б��ָ�롣
 * @param[out]			app_array_len_ptr ���ó��������
 */
void vm_get_buildin_app_array(VMINT** app_array_ptr, VMINT* app_array_len_ptr);


/*****************************************************************************
 * FUNCTION
 *  vm_vam_get_core_asm_size
 * DESCRIPTION
 *  Get the ASM size of MRE core by byte.
 * RETURNS
 *  ASM size of MRE core by byte.
 *****************************************************************************/
VMUINT vm_vam_get_core_asm_size(void);


extern VMBOOL vm_start_app(const VMWCHAR* filepath, VMINT parent_app_handle, VMINT flag);
extern void vm_start_app_with_para(const VMWCHAR* filepath, VMINT parent_app_handle, VMINT is_parent_exit,void* parameter,VMINT parameter_size);


/**
 * �����ַ����ֽ�˳��
 *
 * @param 				pwDesData ��������ִ�
 * @param 				pwSrcData Դ����
 */
extern void vm_vam_string_byte_switch(VMWCHAR * pwDesData, VMWCHAR * pwSrcData);

extern VMINT vm_vam_get_app_version(VMWSTR filename, VMCHAR * appversion);

extern VMINT vm_vam_parse_time_data(vm_time_t *timestamp, char* str_time);

extern VMINT vm_vam_get_today_from_2000(void);

#ifdef __cplusplus
}
#endif
#endif
