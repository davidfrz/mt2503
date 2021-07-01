
#ifndef _VM_RES_MNG_
#define	_VM_RES_MNG_
#include "vmswitch.h"
#ifdef __MRE_CORE_RESOURCE_MANAGE__

#include "vmsys.h"
#include "vmpromng.h"

typedef void (*vm_res_release_callback_t)(VM_P_HANDLE process_handle, VMINT sys_state);

typedef struct vm_res_node_t {
VM_P_HANDLE   phandle;	/*��Դ�����Ľ��̾��*/
VMINT    res_id;			/*��Դ���*/
void*     res_callback;		/*��Դ�Ļص�����ָ��*/
VMINT    mtk_res_id;		/*����Դ��Ӧ��mtk��Դ���*/
void*    data_content;		/*��Դ������ݿ��׵�ַָ��*/
VMINT  data_size;		/*��Դ������ݿ��С*/
VMINT  state;				/*��Դ�йص�һЩ״̬��*/
						/*(��״̬������Դռ�������ֻ�Ƿ����û��Լ���¼��Դ��һЩʹ����������û��Լ�����ʹ�á�)*/
}  vm_res_node_t ;

/**
 * ������Դ��Ϊ2��ģʽ��һ���Ƕ�ռ��Դ����һ��Ϊ�Ƕ�ռ��Դ��
 * ÿһ�ֶ�ռ��Դ�İ���1��handle���Ƕ�ռʽ��handle��������ϵͳ����
 * ÿһ����Դ��handle��3�����ԣ�״̬���������̼����õ���Դ��
 */
typedef enum{	
		VM_RES_TYPE_START = 0,
		VM_RES_TYPE_FILE ,
		VM_RES_TYPE_FILE_FIND,
		VM_RES_TYPE_TIMER,
		VM_RES_TYPE_TIMER_EX,
		VM_RES_TYPE_SMS_HANDLE,
		VM_RES_TYPE_MMS_HANDLE,
		VM_RES_TYPE_MMS_INTERRUPT,
		VM_RES_TYPE_CAMERA,
		VM_RES_TYPE_CALLOUT,
		VM_RES_TYPE_IVR,
		VM_RES_TYPE_PHONE_BOOK,
		VM_RES_TYPE_INPUT_SYS,
		VM_RES_TYPE_INPUT_KEY,
		VM_RES_TYPE_INPUT_PEN,
		VM_RES_TYPE_IME,
		VM_RES_TYPE_TCP_HANDLE,
		VM_RES_TYPE_HTTP_HANDLE,
		VM_RES_TYPE_WPS_HANDLE,		
		VM_RES_TYPE_PROCESS_PARAM,
		VM_RES_TYPE_VIDEO_HANDLE,
		VM_RES_TYPE_AUDIO_HANDLE,
		VM_RES_TYPE_AUDIO_BIT_HANDLE,
		VM_RES_TYPE_MIDI_HANDLE,
		VM_RES_TYPE_RECORD_HANDLE,
		VM_RES_TYPE_GPS,
		VM_RES_TYPE_CELL,
		VM_RES_TYPE_LAYER_HANDLE,
		VM_RES_TYPE_GRAPHIC_CXT,
		VM_RES_TYPE_STATUS_BAR,
		VM_RES_TYPE_PAYMENT,
		VM_RES_TYPE_MD5,
		VM_RES_TYPE_SHA1,
		VM_RES_TYPE_SENSOR,
        VM_RES_TYPE_EBOOK,
		VM_RES_TYPE_SMS_INTERRUPT,
		VM_RES_TYPE_SMS_INTERRUPT_EX,
		VM_RES_TYPE_DAEMON,
		VM_RES_TYPE_DLA,
        VM_RES_TYPE_VRT,
        VM_RES_TYPE_FONT,
        VM_RES_TYPE_VENUS_IME,
		VM_RES_TYPE_VFX,
		VM_RES_TYPE_SELECTOR,
		VM_RES_TYPE_WLAN_LOC,
		VM_RES_TYPE_BTCM,
		VM_RES_TYPE_BTSPP,
		VM_RES_TYPE_PRELOAD,
		VM_RES_TYPE_UDP_HANDLE,
		VM_RES_TYPE_MULTI_TOUCH,
		VM_RES_TYPE_FS_ASYNC,
		VM_RES_TYPE_APPMGR,
		VM_RES_TYPE_DA,
		VM_RES_TYPE_GET_SERVICE,
		VM_RES_TYPE_ALARM,
		VM_RES_TYPE_AUDIO_INTERRUPT,
		VM_RES_TYPE_FOLDER_BROWSER,
        VM_RES_TYPE_TLS,
		VM_RES_TYPE_COMMON_UI,
		VM_RES_TYPE_FOLDER_SELECTOR,     
		VM_RES_TYPE_SSL,
		VM_RES_TYPE_NOTIFY,
		VM_RES_TYPE_DCL,
		VM_RES_TYPE_SETTING_SRV,
		VM_RES_TYPE_ATCMD,
		VM_RES_TYPE_VAD,
		VM_RES_TYPE_SOC_SERVER,
		VM_RES_TYPE_NAT,
    VM_RES_TYPE_MAGIC,
		VM_RES_TYPE_BEARER, 
		VM_RES_TYPE_BTGATT, 
		VM_RES_TYPE_DCC,
		VM_RES_TYPE_TEL,
    VM_RES_TYPE_BTPDMS,
    VM_RES_TYPE_BLOCK_PRECISE_TIMER,
    VM_RES_TYPE_BTHFP_HF,
		VM_RES_TYPE_TOTAL
} vm_res_type_enum;

#define VM_RES_TYPE_MEMORY  200
#define VM_RES_TYPE_APP_NAME    2010

#define VM_RES_APP_ID_TOTAL 2011

#define VM_RES_VALUE_NOT_AVAILABLE  -1

#define VM_RES_MONITOR_LOG_INTERVAL 50

typedef struct vm_res_monitor_init_struct
{
    VM_P_HANDLE p_handle; //process handle needed to init in resource monitor
    VMINT res_type; //next resource type;
    struct vm_res_monitor_init_struct * next_app; //next process node
}vm_res_monitor_init_struct;

typedef enum{
		VM_RES_ATTRIBUTE_CONCURRENT = 0,
		VM_RES_ATTRIBUTE_EXCLUSIVE,
		VM_RES_ATTRIBUTE_TOTAL
} vm_res_attribute_enum;


typedef enum{
		VM_RES_STATE_USED = 0,
		VM_RES_STATE_IDLE,
		VM_RES_STATE_TOTAL
} vm_res_state_enum;

typedef enum{
		//vm_res_find
		VM_RES_NOT_FIND = -9,
		
		//vm_res_init
		VM_RES_INIT_FAIL,
		
		//vm_res_save_data & vm_res_get_data
		VM_RES_INVALID_TYPE,
		VM_RES_INVALID_DATA,
		VM_RES_OUT_OF_RESOURCE,
		VM_RES_INVALID_BUFFER,
		VM_RES_INSUFFICIENT_BUFFER,
		VM_RES_INVALID_HANDLE,
		
		VM_RES_INTERNAL_ERROR,
		VM_RES_OK
} vm_res_retcode_enum;


/**
 * ��ʼ���ں���Դ����ģ�顣
 *
 * @param 
 *
 * @return	���֤��ϵͳ��ʼ���ɹ�������ֵΪ0��ʧ�ܷ��ش����롣
 */
VMINT vm_res_initialize( void );


/**
 * �����ں���Դ����ģ�顣
 *
 * @param 
 *
 * @return
 */
void vm_res_finialize( void );


/**
 * ������Դ��
 *
 * @param data_type		��Դ���͡�
 * @param data_content	����Դ���Ͷ�Ӧ����Դ���ݡ�
 * @param process_handle	��������ID��VM_PMNG_CUR_HANDLE ��ʾ��ǰ����ID����
 *
 * @return				�洢��Դ�ľ�����Ǹ�ֵ���������Դ�洢ʧ�ܣ����ش����롣
 */
VMINT vm_res_save_data( VMINT data_type, void * data_content, VMINT data_size, void* callback, VM_P_HANDLE process_handle );


/**
 * ����Դ�б�ע��mtk��Դ������γ�mre��Դ�����mtk��Դ���ӳ���ϵ��
 * �������Դû��mtk��Դ������ɲ�ʹ�á�
 *
 * @param data_type		��Դ���͡�
 * @param data_handle		��Դ�Ĵ洢�����
 * @param reshandle		mtk��Դ�����
 *
 * @return				��ȡ��Դ�ɹ�����0�����򷵻ظ����Ĵ����롣
 */
VMINT vm_res_set_mtk_reshandle(VMINT data_type, VMINT data_handle, VMINT mtk_res_handle);

/**
 * ��ȡ��Ӧ��mtk��Դ�����
 *
 * @param data_type		��Դ���͡�
 * @param data_handle		��Դ�Ĵ洢�����
 * @param reshandle		mtk��Դ�����
 *
 * @return				��ȡ��Դ�ɹ�����0�����򷵻ظ����Ĵ����롣
 */
VMINT vm_res_get_mtk_reshandle(VMINT data_type, VMINT data_handle, VMINT * mtk_res_handle);

/**
 * ������Դ���ݡ�
 *
 * @param data_type		��Դ���͡�
 * @param data_handle		��Դ�Ĵ洢�����
 * @param data_buffer		������Դ���ݵĻ��档 
 * @param data_size		��Դ�������ݵĴ�С��
 *
 * @return				��ȡ��Դ�ɹ�����0�����򷵻ظ����Ĵ����롣
 */
VMINT vm_res_set_data( VMINT data_type, VMINT	data_handle, void * data_buffer, VMINT buffer_size );

/**
 * ��ȡ��Դ���ݡ�
 *
 * @param data_type		��Դ���͡�
 * @param data_handle		��Դ�Ĵ洢�����
 * @param data_buffer		������Դ���ݵĻ��档 
 * @param data_size		��Դ�������ݵĴ�С()��
 *
 * @return				��ȡ��Դ�ɹ�����0�����򷵻ظ����Ĵ����롣
 */
VMINT vm_res_get_data( VMINT data_type, VMINT	data_handle, void ** data_buffer, VMINT * buffer_size );

/**
 * ���ûص���
 *
 * @param data_type		��Դ���͡�
 * @param data_handle		��Դ�Ĵ洢�����
 * @param callback		��Դ�ص�����(����Դ�ص�Ϊapp����ĳ�ӿ���ע��Ļص�)����Ϊ�ա�
 *
 * @return				��ȡ��Դ�ɹ�����0�����򷵻ظ����Ĵ����롣
 */
VMINT vm_res_set_callback( VMINT data_type, VMINT	data_handle, void* callback );

/**
 * ��ȡ�ص���
 *
 * @param data_type		��Դ���͡�
 * @param data_handle		��Դ�Ĵ洢�����
 * @param callback		��Դ�ص�����(����Դ�ص�Ϊapp����ĳ�ӿ���ע��Ļص�)����Ϊ�ա�
 *
 * @return				��ȡ��Դ�ɹ�����0�����򷵻ظ����Ĵ����롣
 */
VMINT vm_res_get_callback( VMINT data_type, VMINT	data_handle, void** callback );


/**
 * ��ȡ��Դ��Ӧ�Ľ��̾����
 *
 * @param data_type		��Դ���͡�
 * @param data_handle		��Դ��Դ�����
 *
 * @return				�ɹ����ؽ��̾�������򷵻ظ�����
 */
VM_P_HANDLE vm_res_get_process_handle( VMINT data_type, VMINT data_handle );



/**
 * �ͷ���Դ��
 *
 * @param data_type		��Դ���͡�
 * @param data_handle		��Դ�Ĵ洢�����
 *
 * @return				�ͷ���Դʱ��ͬʱ�ͷ���Դhandle
 */
VMINT vm_res_release_data( VMINT data_type, VMINT	data_handle );


/**
 * ��ѯ��Դ���͵����ԡ�
 *
 * @param data_type			��Դ���͡�
 *
 * @return					��ȡ��Դ���͵����ԣ���ռʽ��Ƕ�ռʽ��
 */
VMINT	vm_res_type_attribute( VMINT data_type );


/**
 * ��ѯ��Դ���͵�������
 *
 * @param data_type			��Դ���͡�
 *
 * @return					��ȡ��Դ���͵�������
 */
VMINT vm_res_type_max_handle( VMINT data_type );


/**
 * ע��֪ͨ�ر���Դ�ص�����ָ�롣
 * 
 * 
 * @param data_type			��Դ���͡�
 * @param release_function_ptr	�ر���Դ�ص�����ָ�롣
 *
 *  @return					�ɹ�����0�����򷵻ظ����Ĵ����롣
 *
 */
VMINT vm_res_type_set_notify_callback(VMINT data_type, vm_res_release_callback_t notify_function_ptr);


/**
 * ��ȡ�ر���Դ�ص�����ָ��
 * 
 * @param data_type			��Դ���͡�
 *
 *  @return					�ɹ�������Դ�ص�����ָ�룬���򷵻�NULL��
 */
vm_res_release_callback_t vm_res_type_get_notify_callback(VMINT data_type);

/**
 * ��ѯ��Դ���͵Ŀ�����������δʹ�ã���
 *
 * @param data_type			��Դ���͡�
 *
 * @return							��ȡ��Դ���͵Ŀ�����������δʹ�ã���
 */
VMINT vm_res_type_avaliable_handle( VMINT data_type, VM_P_HANDLE process_handle);


/**
 * ��ѯ��Դ��״̬����״̬���û��Լ������ʹ�á�����Դ����ռ������޹ء�
 * 
 *
 * @param data_type		��Դ���͡�
 * @param data_handle		��Դ�����
 *
 * @return				��Դ��״̬��
 */
VMINT vm_res_get_handle_state( VMINT data_type, VMINT data_handle );


/**
 * ������Դ��״̬����״̬���û��Լ������ʹ�á�����Դ����ռ������޹ء�
 *
 * @param data_type		��Դ���͡�
 * @param data_handle		��Դ�����
 * @param data_state		��Դ��״̬��
 *
 * @return							���óɹ�����0��ʧ�ܷ��ظ����Ĵ����롣
 */
VMINT vm_res_set_handle_state( VMINT data_type, VMINT data_handle, VMINT data_state );

/**
 * ��ȡ�����Ѿ�ռ����Դ��������
 *
 * @param process_handle	���̾����
 * @param data_type		��Դ���͡�����˵�������vm_res_type_enum��
 *						�����Ҫ��ȡ����������Դ��������VM_RES_TYPE_TOTAL��
 *
 * @return				�����Ѿ�ռ����Դ������
 */
VMINT vm_res_get_data_list_count_by_proecss(VM_P_HANDLE process_handle, VMINT data_type);


/**
 * ��ȡ�����Ѿ�ռ����Դ�б�
 *
 * @param process_handle	���̾����
 * @param data_type		��Դ���͡�����˵�������vm_res_type_enum��
 *						�����Ҫ��ȡ����������Դ��������VM_RES_TYPE_TOTAL��
 * @param data_list		��Դ�б������׵�ַ��(���б�ռ����û�����)
 * @param data_list_count	��Դ�б�����ĳ��ȡ�
 *
 * @return				�����Ѿ�ռ����Դ������ 
 */
VMINT vm_res_get_data_list_by_proecss(VM_P_HANDLE process_handle, VMINT data_type, vm_res_node_t* data_list, VMINT data_list_count);

/**
 * ��ȡָ����Դ�����Ѿ�ռ����Դ��������
 *
 * @param data_type		��Դ���͡�����˵�������vm_res_type_enum��
 *						ȡֵ��ΧС��VM_RES_TYPE_TOTAL��
 *
 * @return				�����Ѿ�ռ����Դ������
 */
VMINT vm_res_get_data_list_count_by_type(VMINT data_type);

/**
 * ��ȡָ����Դ�����Ѿ�ռ����Դ�б�
 *
 * @param data_type		��Դ���͡�����˵�������vm_res_type_enum��
 *						ȡֵ��ΧС��VM_RES_TYPE_TOTAL��
 * @param data_list		��Դ�б������׵�ַ��(���б�ռ����û�����)
 * @param data_list_count	��Դ�б�����ĳ��ȡ�
 *
 * @return				�����Ѿ�ռ����Դ������ 
 */
VMINT vm_res_get_data_list_by_type(VMINT data_type, vm_res_node_t* data_list, VMINT data_list_count);
	

/**
 * ϵͳ֪ͨ��Դ�������˳�����
 */
VMINT vm_res_notify_data_by_process(VM_P_HANDLE process_handle, VMINT process_state);

/**
  *	vm_res_findfirst, vm_res_findnext, vm_res_close���������ṩһ����Դ���ҵķ�����
  *	@param process_handle	�����͸ý�����ص���Դ(���Ϊ-1,˵����������������Դ)��
  *	@param data_type			��Դ���͡�
  *
  *	@return		�����ɹ�������Դ�ľ����ʧ�ܷ���VM_RES_NOT_FIND��
  *
  *	ע�������Դ�����仯����������ɾ����������findfirst��
  *
  *	vm_res_findfirstʹ������
  *	VMINT i;
  *	i = vm_res_findfirst(phandle, VM_RES_TYPE_TIMER);
  *	vm_log_debug("vm_timer_proc : vm_res_findfirst timerid=%d", i);
  *	while ( i != VM_RES_NOT_FIND)
  *	{
  *		i = vm_res_findnext(phandle, VM_RES_TYPE_TIMER);
  *		vm_log_debug("vm_timer_proc : vm_res_findnext timerid=%d", i);
  *	}
  *	vm_res_findclose(VM_RES_TYPE_TIMER);
  *
  */
VMINT vm_res_findfirst(VM_P_HANDLE process_handle, VMINT data_type);
VMINT vm_res_findnext(VM_P_HANDLE process_handle, VMINT data_type);
void vm_res_findclose(VMINT data_type);

void vm_print_res_table(VMINT type);
void vm_res_print_monitor_log(VM_P_HANDLE p, VMINT res_type);
#endif
#endif
