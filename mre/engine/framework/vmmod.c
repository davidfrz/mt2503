#include "vmswitch.h"
#ifdef __MRE_CORE_BASE__
#include "string.h"
//#include "stdlib.h"

#include "vmsys.h"
#include "vmmod.h"
#include "vmlog.h"

#define MRE_MAX_MODULE_NUM					(50)
#define MRE_SUPPORT_MAX_MODULE_NAME			(20)

/*
  * MRE��ģ�鶨�塣
  */
typedef struct mre_module_t {
	/**
	 * ģ�����ơ�
	 */
	char name[MRE_SUPPORT_MAX_MODULE_NAME + 1];

	/*
	  * ģ������������¼��Ĵ�������
	  */
	MOD_EVT_PROCESS liefcircle_process;
} mre_module_t;

/*
  * �洢����ģ�����ƺ�cleanup function ��setup function
  * ���������ݽṹ��
  */
typedef struct mre_modules_t {
	unsigned int curr_use_num;
	mre_module_t modues[MRE_MAX_MODULE_NUM];
} mre_modules_t;

/*
 * ��Ÿ���ģ���������ͳ�ʼ�������ı�����
 */
static mre_modules_t mre_modules;

/**
 * ���MRE״̬�ı�����
 */
MRE_MOD_STATUS mre_mod_status = MOD_STATUS_SHUTDOWN;

VMINT _vm_reg_module(VMSTR name, MOD_EVT_PROCESS process)
{
	unsigned int i = 0;

	if (!name || name[0] == 0)
	{
		return MRE_MODULE_NAME_NOT_EXISTS_ERROR;
	}

	for (i = 0; i < mre_modules.curr_use_num; i++)
	{
		if (strncmp(name, mre_modules.modues[i].name, 
			MRE_SUPPORT_MAX_MODULE_NAME) == 0)
		{
			return MRE_MODULE_NAME_CONFLICT_ERROR;
		}
	}

	if (mre_modules.curr_use_num < MRE_MAX_MODULE_NUM)
	{
		memset(mre_modules.modues[mre_modules.curr_use_num].name, 0x00, 
			sizeof(mre_modules.modues[mre_modules.curr_use_num].name));
		
		strncpy(mre_modules.modues[mre_modules.curr_use_num].name, 
			name, MRE_SUPPORT_MAX_MODULE_NAME);
		mre_modules.modues[mre_modules.curr_use_num].liefcircle_process = process;
		mre_modules.curr_use_num++;
	}
	else
	{
    MMI_ASSERT(0);
		return OVERFLOW_MAX_MODULE_NUM_ERROR;
	}

	return REG_MRE_MODULE_SUCCESS;
}

MRE_MOD_STATUS _vm_get_status(void)
{
	return mre_mod_status;
}

VMINT _vm_notify_modules(MRE_MOD_LIFECIRCLE_EVT event)
{
	int i = 0;

	switch (event)
	{
	case EVT_MOD_INIT:
	case EVT_MOD_ACTIVE:
		for (i = 0; i < (int)mre_modules.curr_use_num; i++)
		{
			vm_log_info("[%s] module will be notified [%d] event.", 
				mre_modules.modues[i].name, event);
			
			if (mre_modules.modues[i].liefcircle_process(event) != 0)
			{
				vm_log_error("%s module is failed to process %d event.", mre_modules.modues[i].name, event);
				if (event == EVT_MOD_INIT)
				{
					int j = i;
					
					while (j >= 0 && j < MRE_MAX_MODULE_NUM)
					{
						mre_modules.modues[j].liefcircle_process(EVT_MOD_RELEASE);
						j--;
					}
					return -1;
				}
			}
		}

		mre_mod_status = MOD_STATUS_RUNNING;
		break;
	case EVT_MOD_INACTIVE:
		for (i = (int)(mre_modules.curr_use_num - 1); i >= 0; i--)
		{
			vm_log_info("[%s] module will be notified [%d] event.", 
				mre_modules.modues[i].name, event);
			
			mre_modules.modues[i].liefcircle_process(event);
		}
		
		mre_mod_status = MOD_STATUS_PAUSE;
		
		break;
	case EVT_MOD_RELEASE:
		for (i = (int)(mre_modules.curr_use_num - 1); i >= 0; i--)
		{
			vm_log_info("[%s] module will be notified [%d] event.", 
				mre_modules.modues[i].name, event);
			
			mre_modules.modues[i].liefcircle_process(event);
		}
		
		mre_mod_status = MOD_STATUS_SHUTDOWN;
		
		break;
	default:
		vm_log_error("{MODULE MANAGER}Unkown module lifecircle event[%d]", event);
	}
			
	return 0;
}
	extern VMINT _vm_reg_timer_module(void);
	extern VMINT _vm_reg_io_module(void);
	extern VMINT _vm_reg_graphic_modual(void);
#ifdef __MRE_SAL_SOCKET__	    
	extern VMINT _vm_reg_tcp_module(void);
	extern VMINT _vm_reg_wifi_loc_module(void);
        extern VMINT _vm_reg_preload_module(void);
#if defined(__IOT__)        
        extern VMINT _vm_reg_soc_svr_module(void);
#endif        
#endif
#if ( defined(__MRE_SAL_GPS__)) 
	extern VMINT _vm_reg_gps_modual(void);
#endif
	extern VMINT _vm_reg_cell_modual(void);
#ifdef __MRE_SAL_SMS__	
	extern VMINT _vm_reg_sms_module(void);
#endif	
#ifdef __MRE_SAL_MMS__
	extern VMINT _vm_reg_mms_modual(void);
#endif	
#ifdef __MRE_SAL_TELE__
	extern VMINT _vm_reg_callout_module(void);
    extern VMINT _vm_reg_call_module(void);
#endif
#ifdef __MRE_SAL_AUDIO__
	extern VMINT _vm_reg_audio_module(void);
#endif
#if ( defined(__MRE_SAL_BITSTREAM__)) 
	extern VMINT _vm_reg_bitsteam_audio_module(void);
#endif
#if ( defined(__MRE_SAL_VIDEO__)) 
	extern VMINT _vm_reg_video_modual(void);
#endif
#ifdef __MRE_LIB_IME__
	extern VMINT _vm_reg_ime_module(void);
#endif
#if ( defined(__MRE_SAL_CAMERA__)) 
	extern VMINT _vm_reg_cam_module(void);
#endif
#ifdef __MRE_LIB_HTTP__       
	extern VMINT _vm_reg_http_module(void);
#endif

#ifdef __MRE_SAL_WPS__       
	extern VMINT _vm_reg_wps_module(void);
#endif
#ifdef __MRE_SAL_STATUS__
	extern VMINT _vm_reg_statusbar_module(void);
#endif
#ifdef __MRE_SAL_PHONEBOOK__	
	extern VMINT _vm_reg_phb_module(void);
#endif	
#ifdef __MRE_SAL_CHE_SHA1__	
	extern VMINT _vm_reg_sha1_modual(void);
#endif
#ifdef __MRE_SAL_CHE_MD5__	
	extern VMINT _vm_reg_md5_modual(void);
#endif
#if ( defined(__MRE_SAL_SENSOR__)) 
	extern VMINT _vm_reg_sensor_module(void);
#endif
#ifdef __MRE_LIB_NETWORK_VIP__    
#ifdef __MRE_LIB_NETWORK_VIP_VG__
	extern VMINT _vm_reg_vip_module(void);
#endif /* __MRE_LIB_NETWORK_VIP_VG__ */
#endif /* __MRE_LIB_NETWORK_VIP__ */
#ifdef __MRE_SAL_BTCM__
    extern VMINT _vm_reg_btcm_module(void);
#endif

#ifdef __MRE_SAL_BTSPP__
    extern VMINT _vm_reg_btspp_module(void);
#endif
#ifdef __MRE_SAL_BTNOTIFY__
    extern VMINT _vm_reg_btnotify_module(void);
#endif
    extern VMINT _vm_reg_multi_touch_module(void);
    extern VMINT _vm_reg_fs_async_module(void);

#ifdef __MRE_SAL_DA__
    extern VMINT _vm_reg_da_module(void);
#endif
	extern VMINT _vm_reg_alarm_module(void);

	extern VMINT _vm_reg_selector_module(void);
	extern VMINT _vm_reg_folder_browser_module(void);
	extern VMINT _vm_reg_common_ui_module(void);
#ifdef __MRE_SAL_TLS__
extern VMINT _vm_reg_tls_module(void);
#endif
	extern VMINT _vm_reg_folder_selector_module(void);

#ifdef __MRE_CORE_DCL__
extern VMINT _vm_reg_dcl_module(void);
#endif

#ifdef __MRE_SAL_XYSSL__
    extern VMINT _vm_reg_ssl_module(void);
#endif
#ifdef __MRE_SAL_SETTINGS__
    extern VMINT _vm_reg_setting_srv_module(void);
#endif

#ifdef __MRE_CORE_ATCMD__
	extern VMINT _vm_reg_atcmd_module(void);
#endif

#ifdef __MRE_SAL_VAD__
extern VMINT _vm_reg_vad_module(void);
#endif

#ifdef __MRE_SAL_NAT__
extern VMINT _vm_reg_nat_module(void);
#endif

#ifdef __MRE_SAL_BTGATT__
extern VMINT _vm_reg_btgatt_module(void);
#endif

#ifdef __MRE_SAL_DCC__
extern VMINT _vm_reg_dcc_module(void);
#endif

#if defined(__MRE_BT_PDMS__)
extern VMINT _vm_reg_btpdms_module(void);
#endif

extern VMINT _vm_reg_magic_module(void);
#if defined(__MRE_BT_HFP__)
extern VMINT _vm_reg_bthfp_module(void);
#endif
typedef VMINT (*vm_reg_module_fn)(void);
static vm_reg_module_fn reg_fn_array[]=
{
	_vm_reg_timer_module,
	 _vm_reg_io_module,
#ifdef __MRE_LIB_GRAPIC_IMAGE__
	_vm_reg_graphic_modual,
#endif
#ifdef __MRE_SAL_SOCKET__	    
	 _vm_reg_tcp_module,
	_vm_reg_wifi_loc_module,
	_vm_reg_preload_module,
#if defined(__IOT__)	
	_vm_reg_soc_svr_module,
#endif	
#endif
#if ( defined(__MRE_SAL_GPS__)) 
	_vm_reg_gps_modual,
#endif
	_vm_reg_cell_modual,
#ifdef __MRE_SAL_SMS__	
	_vm_reg_sms_module,
#endif	
#ifdef __MRE_SAL_MMS__
	_vm_reg_mms_modual,
#endif	
#ifdef __MRE_SAL_TELE__
	_vm_reg_callout_module,
	_vm_reg_call_module,
#endif
#ifdef __MRE_SAL_AUDIO__	
	_vm_reg_audio_module,
#endif
#if ( defined(__MRE_SAL_BITSTREAM__)) 
	_vm_reg_bitsteam_audio_module,
#endif
#if ( defined(__MRE_SAL_VIDEO__)) 
	_vm_reg_video_modual,
#endif
#ifdef __MRE_LIB_IME__
	_vm_reg_ime_module,
#endif
#if ( defined(__MRE_SAL_CAMERA__)) 
	_vm_reg_cam_module,
#endif
#ifdef __MRE_LIB_HTTP__       
	_vm_reg_http_module,
#endif
	
#ifdef __MRE_SAL_WPS__       
	_vm_reg_wps_module,
#endif
#ifdef __MRE_SAL_STATUS__
	_vm_reg_statusbar_module,
#endif
#ifdef __MRE_SAL_PHONEBOOK__	
	_vm_reg_phb_module,
#endif	
#ifdef __MRE_SAL_CHE_SHA1__	
	_vm_reg_sha1_modual,
#endif
#ifdef __MRE_SAL_CHE_MD5__	
	_vm_reg_md5_modual,
#endif
#if ( defined(__MRE_SAL_SENSOR__)) 
	_vm_reg_sensor_module,
#endif
#ifdef __MRE_LIB_NETWORK_VIP__    
#ifdef __MRE_LIB_NETWORK_VIP_VG__
	 _vm_reg_vip_module,
#endif /* __MRE_LIB_NETWORK_VIP_VG__ */
#endif /* __MRE_LIB_NETWORK_VIP__ */
#ifdef __MRE_SAL_BTCM__
	 _vm_reg_btcm_module,
#endif
	
#ifdef __MRE_SAL_BTSPP__
	_vm_reg_btspp_module,
#endif
#ifdef __MRE_SAL_BTNOTIFY__
    _vm_reg_btnotify_module,
#endif

	_vm_reg_multi_touch_module,
	_vm_reg_fs_async_module,
	
#ifdef __MRE_SAL_DA__
	 _vm_reg_da_module,
#endif
	_vm_reg_alarm_module,
	
	 _vm_reg_selector_module,
	 _vm_reg_folder_browser_module,
	_vm_reg_common_ui_module,
#ifdef __MRE_SAL_TLS__
	_vm_reg_tls_module,
#endif
	_vm_reg_folder_selector_module,

#ifdef __MRE_CORE_DCL__
	_vm_reg_dcl_module,
#endif

#ifdef __MRE_SAL_XYSSL__
        _vm_reg_ssl_module,
#endif
#ifdef __MRE_SAL_SETTINGS__
    _vm_reg_setting_srv_module,
#endif
#ifdef __MRE_CORE_ATCMD__
	_vm_reg_atcmd_module,
#endif

#ifdef __MRE_SAL_VAD__
		_vm_reg_vad_module,
#endif
#ifdef __MRE_SAL_NAT__
		_vm_reg_nat_module,
#endif
#ifdef __MRE_SAL_BTGATT__
        _vm_reg_btgatt_module,
#endif
#if defined(__MRE_BT_PDMS__)
    _vm_reg_btpdms_module,
#endif
#if defined(__MRE_BT_HFP__)
    _vm_reg_bthfp_module,
#endif
#ifdef __MRE_SAL_DCC__
        _vm_reg_dcc_module,
#endif
    _vm_reg_magic_module,
 
};
VMINT _vm_reg_modules(void)
{    
	int res = REG_MRE_MODULE_SUCCESS;
	int i;
	for(i=0;i<sizeof(reg_fn_array)/sizeof(vm_reg_module_fn);i++)
	{
		if((res = reg_fn_array[i]())!=REG_MRE_MODULE_SUCCESS)
			break;
	}
	return res;
}
void _vm_initizlize_module_manager(void)
{
	//mre_modules.curr_use_num = 0;
	//memset(mre_modules.modues, 0x00, MRE_MAX_MODULE_NUM * sizeof(mre_module_t));
	memset(&mre_modules,0,sizeof(mre_modules));
}

void _vm_destory_module_manager(void)
{
	//mre_modules.curr_use_num = 0;
	//memset(mre_modules.modues, 0x00, MRE_MAX_MODULE_NUM * sizeof(mre_module_t));
	_vm_initizlize_module_manager();
}
#endif

