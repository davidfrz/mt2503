extern "C"
{
#include "vmswitch.h"
#include "vmsettings.h"
#include "vmpromng.h"
#include "ProfilesSrvGprot.h"
#include "vmresmng.h"
#include "vmmod.h"
#include "vmsys.h"
#include "CommSettings.h"
#include "vmmem.h"
#ifndef __COSMOS_MMI_PACKAGE__
#include "ViewSettingCommonProt.h"
#endif
#include "mmi_phnset_dispchar.h"
#include "GeneralSettingSrvGprot.h"
}

#ifdef __MRE_SAL_SETTINGS__

#ifndef __COSMOS_MMI_PACKAGE__

typedef struct
{
    VM_P_HANDLE                         pHandle;
    vm_settings_set_wallpaper_callback  callback;
    void*                               user_data;
}vm_settings_set_wallpaper_data;

#else //__COSMOS_MMI_PACKAGE__

#include "vapp_wallpaper_setting_method_gprot.h" 

class vmWallpaperCB : public VfxObject
{
public:
    VM_P_HANDLE                         m_pHandle;
    vm_settings_set_wallpaper_callback  m_callback;
    void*                               m_userdata;
    void*                               m_buffer;
    void callback(VfxU8 param);
};

#endif

static const srv_prof_settings_enum type_map[]={
    SRV_PROF_SETTINGS_POWER_ON_TONE,            
    SRV_PROF_SETTINGS_POWER_OFF_TONE,           
    SRV_PROF_SETTINGS_POWER_ON_OFF_TONE,        
    SRV_PROF_SETTINGS_COVER_OPEN_TONE,          
    SRV_PROF_SETTINGS_COVER_CLOSE_TONE,         
    SRV_PROF_SETTINGS_SMS_TONE,
    SRV_PROF_SETTINGS_SMS_CARD2_TONE,     
    SRV_PROF_SETTINGS_SMS_CARD3_TONE,       
    SRV_PROF_SETTINGS_SMS_CARD4_TONE, 
    SRV_PROF_SETTINGS_MMS_TONE,                 
    SRV_PROF_SETTINGS_MMS_CARD2_TONE,           
    SRV_PROF_SETTINGS_MMS_CARD3_TONE,           
    SRV_PROF_SETTINGS_MMS_CARD4_TONE,           
    SRV_PROF_SETTINGS_EMAIL_TONE,               
    SRV_PROF_SETTINGS_EMAIL_CARD2_TONE,         
    SRV_PROF_SETTINGS_EMAIL_CARD3_TONE,         
    SRV_PROF_SETTINGS_EMAIL_CARD4_TONE,         
    SRV_PROF_SETTINGS_VOICE_TONE,               
    SRV_PROF_SETTINGS_VOICE_CARD2_TONE,         
    SRV_PROF_SETTINGS_VOICE_CARD3_TONE,         
    SRV_PROF_SETTINGS_VOICE_CARD4_TONE,         
    SRV_PROF_SETTINGS_MT_CALL_TONE,             
    SRV_PROF_SETTINGS_MT_CALL_CARD2_TONE,       
    SRV_PROF_SETTINGS_MT_CALL_CARD3_TONE,       
    SRV_PROF_SETTINGS_MT_CALL_CARD4_TONE,       
    SRV_PROF_SETTINGS_VT_CALL_TONE,             
    SRV_PROF_SETTINGS_VT_CALL_CARD2_TONE,       
    SRV_PROF_SETTINGS_VT_CALL_CARD3_TONE,       
    SRV_PROF_SETTINGS_VT_CALL_CARD4_TONE,
};


extern "C" VMINT vm_settings_set_tone(vm_settings_tone_enum type, VMWCHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_ret ret = VM_SETTINGS_RET_FAIL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__IOT__)
    if (type <0 || type >= VM_SETTINGS_TONE_END)
    {
        return VM_SETTINGS_RET_PARAM_ERR;
    }
    
    ret =  srv_prof_set_current_profile_tone_with_file_path(type_map[(VMINT)type],(WCHAR*)path);

    switch (ret)
    {
    case SRV_PROF_RET_SUCCESS:
        ret = VM_SETTINGS_RET_OK;
        break;
    case SRV_PROF_RET_FAIL:
        ret = VM_SETTINGS_RET_FAIL;
        break;
    case SRV_PROF_RET_SETTING_NOT_SUPPORTED:
        ret = VM_SETTINGS_RET_NOT_SUPPORT;
        break;
    default:
        if ( ret >= 0)
        {
            ret = VM_SETTINGS_RET_OK;
        }
        else
        {
            ret = VM_SETTINGS_RET_FAIL;
        }
        break;
    }
#endif
    return ret;
}


#ifndef __COSMOS_MMI_PACKAGE__ //PLUTO
static mmi_ret _vm_settings_set_wallpaper_cb(mmi_event_struct *param)
{
    vm_settings_set_wallpaper_data* data = (vm_settings_set_wallpaper_data*)param;
    if (data && data->callback && VM_PMNG_UNLOAD != vm_pmng_state(data->pHandle))
    {
        vm_pmng_set_ctx(data->pHandle);
        data->callback(data->user_data);
        vm_free(data);
        vm_pmng_reset_ctx();
    }
    
    return 0;
}
#else
void vmWallpaperCB::callback(VfxU8 param)
{
    if (this->m_callback && VM_PMNG_UNLOAD != vm_pmng_state(this->m_pHandle))
    {
        vm_pmng_set_ctx(this->m_pHandle);
        this->m_callback(this->m_userdata);        
        vm_free(this->m_buffer);
        vm_pmng_reset_ctx();
    }    
}

#endif

extern "C" VMINT vm_settings_set_wallpaper(vm_setttings_wallpaper_enum type, 
                                            VMWCHAR* path,vm_settings_set_wallpaper_callback callback, void* user_data)
{
#ifndef __COSMOS_MMI_PACKAGE__ //PLUTO

    vm_settings_set_wallpaper_data* data = NULL;

    if (type != VM_SETTINGS_HOME_PAPER)
    {
        return VM_SETTINGS_RET_NOT_SUPPORT;
    }
    
    if (callback)
    {
        data = (vm_settings_set_wallpaper_data*)vm_malloc(sizeof(vm_settings_set_wallpaper_data));
        if (data == NULL)
        {
            return VM_SETTINGS_RET_NO_MEM;
        }
        
        data->pHandle = vm_pmng_get_current_handle();
        data->callback = callback;
        data->user_data = user_data;
    }

    
#if !defined(__IOT__)
    mmi_phnset_view_setting_set_by_file(MMI_PHNSET_TYPE_WP,(const WCHAR* )path,(mmi_proc_func)_vm_settings_set_wallpaper_cb,(void*)data);
#endif

    return VM_SETTINGS_RET_OK;
#else //__COSMOS_MMI_PACKAGE__

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    return VM_SETTINGS_RET_OK;
    
#endif //__COSMOS_MMI_PACKAGE__
    
}



extern "C"
{
/*****************************************************************************
 * FUNCTION
 *  vm_setting_get_time_format
 * DESCRIPTION
 *  Get system time format 
 * PARAMETERS
 *  void
 * RETURNS
 *  vm_setting_time_format_enum
 *****************************************************************************/
VMINT vm_setting_get_time_format(void)
{
    srv_setting_time_format_enum format;

    format = srv_setting_get_time_format();
    switch(format)
    {
        case SETTING_TIME_FORMAT_12_HOURS:
            return VM_SETTING_TIME_FORMAT_12_HOURS;

        case SETTING_TIME_FORMAT_24_HOURS:
            return VM_SETTING_TIME_FORMAT_24_HOURS;
    }
    return -2;
}


/*****************************************************************************
 * FUNCTION
 *  vm_setting_get_date_format
 * DESCRIPTION
 *  Get system date format 
 * PARAMETERS
 *  void
 * RETURNS
 *  vm_setting_date_format_enum
 *****************************************************************************/
VMINT vm_setting_get_date_format(void)
{
    srv_setting_date_format_enum format;

    format = srv_setting_get_date_format();
    switch(format)
    {
        case SETTING_DATE_FORMAT_DD_MM_YYYY:
            return VM_SETTING_DATE_FORMAT_DD_MM_YYYY;

        case SETTING_DATE_FORMAT_MM_DD_YYYY:
            return VM_SETTING_DATE_FORMAT_MM_DD_YYYY;

        case SETTING_DATE_FORMAT_YYYY_MM_DD:
            return VM_SETTING_DATE_FORMAT_YYYY_MM_DD;
    }
    return -2;    
}


/*****************************************************************************
 * FUNCTION
 *  vm_setting_get_date_seperator
 * DESCRIPTION
 *  Get system date seperator 
 * PARAMETERS
 *  void
 * RETURNS
 *  vm_setting_date_seperator_enum
 *****************************************************************************/
VMINT vm_setting_get_date_seperator(void)
{
    srv_setting_date_seperator_enum seperator;

    seperator = srv_setting_get_date_seperator();
    switch(seperator)
    {
        case SETTING_DATE_SEPERATOR_DOT:
            return VM_SETTING_DATE_SEPERATOR_DOT;

        case SETTING_DATE_SEPERATOR_COLON:
            return VM_SETTING_DATE_SEPERATOR_COLON;

        case SETTING_DATE_SEPERATOR_SLOPE:
            return VM_SETTING_DATE_SEPERATOR_SLOPE;

        case SETTING_DATE_SEPERATOR_LINE:
            return VM_SETTING_DATE_SEPERATOR_LINE;
    }
    return -2;      
}

extern VMINT mre_running;

typedef struct
{
    VM_P_HANDLE m_pHandle;
    vm_setting_srv_result_callback m_pAppSetSrvCB;
    VMINT m_nResid;
} vm_setting_srv_struct;

static VMINT vm_setting_srv_cancel(VMINT setting_id)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_SETTING_SRV, TRC_MRE_VMSETTINGSRV_113);
    VMINT res_node_size = 0;
    vm_setting_srv_struct *res_p = NULL;
    VM_P_HANDLE phandle = -1;
    VM_P_HANDLE curr_phandle = vm_pmng_get_app_handle();
    MMI_BOOL ret;

    if ((phandle = vm_res_get_process_handle(VM_RES_TYPE_SETTING_SRV, setting_id)) < 0)
    {
    	MMI_TRACE(MMI_MRE_TRC_MOD_SETTING_SRV, TRC_MRE_VMSETTINGSRV_114);
        return VM_SETTING_SRV_ERROR_INVALID_ID;
    }
	
    if (curr_phandle > 0)   /* app, not engine */
    {
        if (phandle != curr_phandle)    /* application A can not cancel alarm belongs to application B */
        {
        	MMI_TRACE(MMI_MRE_TRC_MOD_SETTING_SRV, TRC_MRE_VMSETTINGSRV_115);
            return VM_SETTING_SRV_ERROR_OF_PROCESS;
        }
    }

    if (vm_res_get_data(VM_RES_TYPE_SETTING_SRV, setting_id, (void **)&res_p, &res_node_size) < VM_RES_OK)
    {
    	MMI_TRACE(MMI_MRE_TRC_MOD_SETTING_SRV, TRC_MRE_VMSETTINGSRV_116);
        return VM_SETTING_SRV_ERROR_OF_RES;
    }
    _vm_kernel_free(res_p);

    if (vm_res_release_data(VM_RES_TYPE_SETTING_SRV, setting_id) < VM_RES_OK)
    { 
        MMI_TRACE(MMI_MRE_TRC_MOD_SETTING_SRV, TRC_MRE_VMSETTINGSRV_117);
        return VM_SETTING_SRV_ERROR_OF_RES;
    }	

    return VM_SETTING_SRV_NO_ERROR;
}

static void vm_setting_srv_notify_callback(VM_P_HANDLE process_handle, VMINT sys_state)
{
    VMINT i;
    switch(sys_state)
    {
    	MMI_TRACE(MMI_MRE_TRC_MOD_SETTING_SRV, TRC_MRE_VMSETTINGSRV_112, sys_state);
        case VM_PMNG_UNLOAD:
        if (vm_pmng_get_app_handle() == process_handle)
        {			
            while ((i = vm_res_findfirst(process_handle, VM_RES_TYPE_SETTING_SRV)) != VM_RES_NOT_FIND)
            {
                vm_setting_srv_cancel(i);
                vm_res_findclose(VM_RES_TYPE_SETTING_SRV);
            }				
        }
     		break;
     		
		    default:
        return;
    }
}

static void vm_setting_srv_initial(void)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_SETTING_SRV, TRC_MRE_VMSETTINGSRV_110);
    vm_res_type_set_notify_callback(VM_RES_TYPE_SETTING_SRV, vm_setting_srv_notify_callback);
}

static void vm_setting_srv_finialize(void)
{
    VMINT i = VM_RES_NOT_FIND;
    MMI_TRACE(MMI_MRE_TRC_MOD_SETTING_SRV, TRC_MRE_VMSETTINGSRV_111);
    while ((i = vm_res_findfirst(-1, VM_RES_TYPE_SETTING_SRV)) != VM_RES_NOT_FIND)
    {
        vm_setting_srv_cancel(i);
        vm_res_findclose(VM_RES_TYPE_SETTING_SRV);
    }
    vm_res_type_set_notify_callback(VM_RES_TYPE_SETTING_SRV, NULL);
}

static VMINT vm_setting_srv_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event)
    {
        case EVT_MOD_INIT:
            vm_setting_srv_initial();
            break;
        case EVT_MOD_RELEASE:
            vm_setting_srv_finialize();
            break;
    }
    return 0;
}

VMINT _vm_reg_setting_srv_module(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int res = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((res = _vm_reg_module("SETT MODULE", (MOD_EVT_PROCESS) vm_setting_srv_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
    {
    	MMI_TRACE(MMI_MRE_TRC_MOD_SETTING_SRV, TRC_MRE_VMSETTINGSRV_109);
    }
    return res;
}

VMINT vm_setting_srv_register_callback(vm_setting_srv_result_callback cb)
{
    vm_setting_srv_struct *setting_srv_p;
    VMINT handle = 0;
    VM_P_HANDLE phandle;
    VMINT setting_srv_id;
    
    handle = vm_pmng_get_app_handle();
    if ((phandle = vm_pmng_get_app_handle()) == 0)
    {
    	MMI_TRACE(MMI_MRE_TRC_MOD_SETTING_SRV, TRC_MRE_VMSETTINGSRV_106);
        return VM_SETTING_SRV_ERR_OTHERS;  		
    }
    if((setting_srv_p = (vm_setting_srv_struct *)_vm_kernel_malloc(sizeof(vm_setting_srv_struct))) == NULL)
    {
    	MMI_TRACE(MMI_MRE_TRC_MOD_SETTING_SRV, TRC_MRE_VMSETTINGSRV_107);
        return VM_SETTING_SRV_GET_MEM_FAIL;
        
    }
    setting_srv_p->m_pHandle = phandle;
    setting_srv_p->m_pAppSetSrvCB = cb;
    
    if ((setting_srv_id = vm_res_save_data(VM_RES_TYPE_SETTING_SRV, (void *) setting_srv_p, sizeof(vm_setting_srv_struct), NULL, phandle)) < 0)
    {
    	MMI_TRACE(MMI_MRE_TRC_MOD_SETTING_SRV, TRC_MRE_VMSETTINGSRV_108);
        _vm_kernel_free(setting_srv_p);
        return VM_SETTING_SRV_ERROR_OF_RES;
    }
    setting_srv_p->m_nResid = setting_srv_id;
    return VM_SETTING_SRV_NO_ERROR;
}


static void vm_setting_srv_run_callback(VMINT32 result, void *user_data)
{
    VMINT p_handle;
    VMINT resid = -1;
    VMINT res_node_size = 0;
    vm_setting_srv_struct *res_p = NULL;
    if (mre_running == FALSE)
    {
        return;
    }
    p_handle = vm_pmng_get_app_handle();
    while ((resid = vm_res_findfirst(p_handle, VM_RES_TYPE_SETTING_SRV)) != VM_RES_NOT_FIND)
    {
    	MMI_TRACE(MMI_MRE_TRC_MOD_SETTING_SRV, TRC_MRE_VMSETTINGSRV_103, resid);
        if (vm_res_get_data(VM_RES_TYPE_SETTING_SRV, resid, (void **)&res_p, &res_node_size) < VM_RES_OK)
        {
        	MMI_TRACE(MMI_MRE_TRC_MOD_SETTING_SRV, TRC_MRE_VMSETTINGSRV_104);
            return;
        }
        if (vm_pmng_set_ctx(res_p->m_pHandle) == VM_PMNG_OP_OK)
        {
            if (res_p->m_pAppSetSrvCB)
            {
            	MMI_TRACE(MMI_MRE_TRC_MOD_SETTING_SRV, TRC_MRE_VMSETTINGSRV_105);
                res_p->m_pAppSetSrvCB(result, user_data);
            }
            vm_pmng_reset_ctx();
        }
        _vm_kernel_free(res_p);
        if (vm_res_release_data(VM_RES_TYPE_SETTING_SRV, resid) < VM_RES_OK)
        {
            return;
        }
    }
}


VMINT32 vm_setting_srv_command(VMUINT16 type, VMUINT16 operation, void *in, void *out, vm_setting_srv_result_callback cb, void *user_data)
{
    VMINT32 result = 0;
    if(cb == NULL)
    {
    	MMI_TRACE(MMI_MRE_TRC_MOD_SETTING_SRV, TRC_MRE_VMSETTINGSRV_101); 
        result = srv_settings_command(type, operation, (void *)in, (void *)out, NULL, (void *)user_data);
        
    }
    else
    {
    	MMI_TRACE(MMI_MRE_TRC_MOD_SETTING_SRV, TRC_MRE_VMSETTINGSRV_102);
    	vm_setting_srv_register_callback(cb);
        result = srv_settings_command(type, operation, (void *)in, (void *)out, (srv_setting_result_callback)vm_setting_srv_run_callback, (void *)user_data);
    }
    return result;
}


/****/
#include "SensorSrvGport.h"
vm_srv_sensor_hr_data_cb G_VM_SRV_SENSOR_HR_CB = NULL;
vm_srv_sensor_acc_data_cb G_VM_SENSOR_ACC_CB = NULL;
VM_P_HANDLE setting_curr_phandle;
static void vm_setting_global_srv_hr_result_callback(void *sensor_data)
{
    if (vm_pmng_set_ctx(setting_curr_phandle) == VM_PMNG_OP_OK)
	{
		if (G_VM_SRV_SENSOR_HR_CB != NULL)
		{
			G_VM_SRV_SENSOR_HR_CB(sensor_data);
		}
		vm_pmng_reset_ctx();
	}
}

static void vm_setting_global_srv_acc_result_callback(void *acc_x, void *acc_y, void *acc_z)
{
    if (vm_pmng_set_ctx(setting_curr_phandle) == VM_PMNG_OP_OK)
	{
		if (G_VM_SENSOR_ACC_CB != NULL)
		{
			G_VM_SENSOR_ACC_CB(acc_x, acc_y, acc_z);
		}
		vm_pmng_reset_ctx();
	}
}

#ifdef MOTION_SENSOR_SUPPORT
void vm_srv_sensor_acc_data_rigister_cb(vm_srv_sensor_acc_data_cb event_hdlr)
{
    if(event_hdlr == NULL)
    {
        srv_sensor_acc_data_rigister_cb(NULL);
    }
    else
    {
        G_VM_SENSOR_ACC_CB = event_hdlr;
		setting_curr_phandle = vm_pmng_get_current_handle();
        srv_sensor_acc_data_rigister_cb(vm_setting_global_srv_acc_result_callback);
    }
}
#else
void vm_srv_sensor_acc_data_rigister_cb(vm_srv_sensor_acc_data_cb event_hdlr)
{

}
#endif 

#ifdef __HEART_RATE_ENABLE__
void vm_srv_sensor_hr_data_rigister_cb(vm_srv_sensor_hr_data_cb event_hdlr)
{
    if(event_hdlr == NULL)
    {
        srv_sensor_hr_data_rigister_cb(NULL);
    }
    else
    {
        setting_curr_phandle = vm_pmng_get_current_handle();
        G_VM_SRV_SENSOR_HR_CB = event_hdlr;
        srv_sensor_hr_data_rigister_cb(vm_setting_global_srv_hr_result_callback);
    }
}
#else
void vm_srv_sensor_hr_data_rigister_cb(vm_srv_sensor_hr_data_cb event_hdlr)
{

}
#endif

/****/
#if defined(__MMI_WEARABLE_DEVICE__) && !defined(__IOT__)
#include "SwatchGprot.h"
#endif

vm_idle_swatch_pedometer_cb G_VM_IDLE_WATCH_PEDOMETER_HANDLE_CB = NULL;
VM_P_HANDLE idle_curr_phandle;

static void vm_idle_swatch_register_callback(void *data)
{
    if (vm_pmng_set_ctx(idle_curr_phandle) == VM_PMNG_OP_OK)
	{
		if (G_VM_IDLE_WATCH_PEDOMETER_HANDLE_CB != NULL)
		{
			G_VM_IDLE_WATCH_PEDOMETER_HANDLE_CB(data);
		}
		vm_pmng_reset_ctx();
	}
}
#if defined(__MMI_WEARABLE_DEVICE__) && !defined(__IOT__)
void vm_idle_swatch_pedometer_register_callback(vm_idle_swatch_pedometer_cb event_hdlr)
{
    if(event_hdlr == NULL)
    {
        mmi_idle_swatch_pedometer_resgiter_callback(NULL);
    }
    else
    {
        G_VM_IDLE_WATCH_PEDOMETER_HANDLE_CB = event_hdlr;
		idle_curr_phandle = vm_pmng_get_current_handle();
        mmi_idle_swatch_pedometer_resgiter_callback(vm_idle_swatch_register_callback);
    }    
}

VMBOOL g_vm_bt_call_disable;
void vm_switch_bt_call(VMBOOL on)
{
	if(on)
	{
		g_vm_bt_call_disable = VM_FALSE;
	}
	else
	{
		g_vm_bt_call_disable = VM_TRUE;
	}
}

VMBOOL vm_is_bt_call_allowed(void)
{
	return !g_vm_bt_call_disable;
}

#else
void vm_idle_swatch_pedometer_register_callback(vm_idle_swatch_pedometer_cb event_hdlr)
{
   
}

void vm_switch_bt_call(VMBOOL on)
{

}
VMBOOL vm_is_bt_call_allowed(void)
{
	return VM_TRUE;
}

#endif

} /* extern "C" */
#endif //__MRE_SAL_SETTINGS__