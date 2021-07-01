/* ---------------------------------------------------------------------------
* include
* ------------------------------------------------------------------------ */
#include "MMI_features.h"
#include "Stdlib.h"
#include "MMIDataType.h"
#include "bt_demo_mode_switch.h"
#include "kal_public_api.h"
#include "mmi_rp_srv_gatt_app_def.h"
#include "BtcmSrvGprot.h"
#include "mmi_rp_srv_prof_def.h"
#include "app_frm_command_gprot.h"
#include "ProfilesSrvGprot.h"
#include "GpioSrvGprot.h"

/* ---------------------------------------------------------------------------
* define
* ------------------------------------------------------------------------ */
#define MODE_SWITCH_KEEP_ALIVE_DURATION 120
#define MODE_SWITCH_CHECK_CONN_DURATION 10*1000
#define MODE_SWITCH_DELAY_START_SERVER_TIME 200

typedef enum
{
    BT_COMMAND_ON,
    BT_COMMAND_OFF,
    BT_COMMAND_SET_NAME,
    BT_COMMAND_REACTIVE,
    BT_COMMAND_SWITCH_MODE,
    BT_COMMAND_POWER_SAVE_CONFIG,
    BT_COMMAND_SET_INQUIRY_SCAN,
    BT_COMMAND_SET_PAGE_SCAN,
    BT_COMMAND_SET_ADVERTISING,
    BT_COMMAND_DEREGISTER_ALL,
    BT_COMMAND_SENT_DATA_TO_TOY,
    BT_COMMAND_MAX
} bt_app_command_enum;

static mode_switch_cntx_struct mode_switch_cntx;
static S32 timer_started;
static char* bt_command[BT_COMMAND_MAX] = 
{
    "BTON",
    "BTOFF",
    "SETNAME",
    "REACTIVE",
    "SWITCHMODE",
    "SETPSC",
    "SETIS",
    "SETPS",
    "SETAD",
    "SETSER",
    "SEND"
};

/* ---------------------------------------------------------------------------
* local function
* ------------------------------------------------------------------------ */
static void mode_switch_change_mode(mode_switch_cntx_struct* cntx, mode_enum curr_mode);
static void mode_switch_change_to_peripheral(mode_switch_cntx_struct* cntx);
static void mode_switch_change_to_central(mode_switch_cntx_struct* cntx);
static void mode_switch_start_common_server(mode_switch_cntx_struct* cntx);
static void mode_switch_stop_common_server(mode_switch_cntx_struct* cntx);
static void bt_switch_mode_event_notify(U32 event, void* para);
static S32 power_save_start(void);
static S32 power_save_reactive(void);
static S32 power_save_stop(void);
static void power_save_power_off_cb(void);
static void power_save_check_conn_cb(void);
static void bt_switch_mode_psc_update(void);
static void bt_switch_mode_power_on_handle();
static void bt_switch_mode_power_off_handle();
static void bt_switch_mode_setname_handle(char* name);
static void bt_switch_mode_config(bt_power_save_enum power_save, S32 keep_alive_time);
static mode_enum mode_switch_get_curr_mode();
static mode_enum mode_switch_get_last_mode();
static void mode_switch_change_to_last_mode(mode_switch_cntx_struct* cntx);
static void bt_switch_mode_register(char* param);
static void mode_switch_change_mode_timeout_cb(void);
static void mode_switch_start_server(mode_switch_cntx_struct* cntx, mode_enum mode);
static void mode_switch_stop_server(mode_switch_cntx_struct* cntx, mode_enum mode);
static void mode_switch_set_status_cb(void);

/* ---------------------------------------------------------------------------
* global variables
* ------------------------------------------------------------------------ */


/* ---------------------------------------------------------------------------
* function
* ------------------------------------------------------------------------ */
void bt_switch_mode_power_on_handle()
{
    srv_bt_cm_power_status_enum ret;

    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] bt_switch_mode_power_on_handle");
    ret = srv_bt_cm_get_power_status();
    if (ret == SRV_BT_CM_POWER_OFF)
    {
        srv_bt_cm_switch_on();
    }
}

void bt_switch_mode_power_off_handle()
{
    srv_bt_cm_power_status_enum power_status;
    srv_bt_cm_result_codes_enum conn_status;

    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] bt_switch_mode_power_off_handle");
    power_status = srv_bt_cm_get_power_status();
    if (power_status == SRV_BT_CM_POWER_ON)
    {
        conn_status = srv_bt_cm_release_all_conn();
        if (conn_status == SRV_BT_CM_RESULT_NO_CONNECTION)
        {
            srv_bt_cm_switch_off();
        }
    }
}

void bt_switch_mode_setname_handle(char* name)
{
    srv_bt_cm_power_status_enum ret;

    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] bt_switch_mode_setname_handle, name:%s", name);
    name += strspn(name, " \t");
    ret = srv_bt_cm_get_power_status();
    if (ret == SRV_BT_CM_POWER_ON)
    {
        srv_bt_cm_set_host_dev_name(name);
    }
}

void bt_switch_mode_power_save_config_handle(char* param)
{
    S32 alive_time = -1, power_strategy = -1;
    param += strspn(param, " \t");
    power_strategy = atoi(param);
    param = strpbrk(param, " \t,");
    if (param)
    {
        param += strspn(param, " \t,");
        if (*param)
        {
            alive_time = atoi(param);
        }
    }
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] power_save_config_handle, power_strategy:%d, alive_time:%d", power_strategy, alive_time);

    if ((power_strategy == BT_POWER_NORMAL) || (power_strategy == BT_POWER_SAVE && alive_time > 0))
    {
        bt_switch_mode_config(power_strategy, alive_time);
    }
}

void bt_switch_mode_switch_mode()
{
    srv_bt_cm_power_status_enum power_status;
    mode_switch_cntx_struct* cntx = &mode_switch_cntx;
    mode_enum curr_mode;
        
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] bt_switch_mode_switch_mode");
    
    power_status = srv_bt_cm_get_power_status();
    if (power_status == SRV_BT_CM_POWER_ON)
    {
        if (!cntx->is_mode_switching)
        {
            curr_mode = mode_switch_get_curr_mode();
            if (curr_mode == BT_MODE_PERIPHERAL)
            {
                mode_switch_change_to_central(cntx); 
            }
            else if (curr_mode == BT_MODE_CENTRAL)
            {
                mode_switch_change_to_peripheral(cntx);    
            }
            else
            {
                //something wrong, should be not happen.
            }
            
            //tricky, reset power saving timer if need
            if (cntx->power_strategy)
            {
                power_save_reactive();
            }
        }
    }
    else if (power_status == SRV_BT_CM_POWER_OFF)
    {
        if (!cntx->is_mode_switching)
        {
            curr_mode = mode_switch_get_last_mode();
            if (curr_mode == BT_MODE_CENTRAL)
            {
                cntx->last_mode = BT_MODE_PERIPHERAL; 
            }
            else if (curr_mode == BT_MODE_PERIPHERAL)
            {
                cntx->last_mode = BT_MODE_CENTRAL;    
            }
            else
            {
                //something wrong, should be not happen.
            }
        }
        srv_bt_cm_switch_on();
    }
    
}

void bt_switch_mode_config(bt_power_save_enum power_save, S32 keep_alive_time)
{
    mode_switch_cntx_struct* cntx = &mode_switch_cntx;

    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] bt_switch_mode_config, power_save:%d, keep_alive_time:%d", power_save, keep_alive_time);

    cntx->power_strategy_update = power_save;
    if (power_save)
    {
        if (keep_alive_time >= 120 && keep_alive_time <= 300)
        {
            cntx->alive_time_update = keep_alive_time * 1000;
        }
        else
        {
            cntx->alive_time_update = MODE_SWITCH_KEEP_ALIVE_DURATION * 1000;
        }
    }

    if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_OFF)
    {
        bt_switch_mode_psc_update();
    }
}

void bt_switch_mode_psc_update(void)
{
    mode_switch_cntx_struct* cntx = &mode_switch_cntx;

    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] bt_switch_mode_psc_update");
    if (cntx->power_strategy != cntx->power_strategy_update)
    {
        if (cntx->power_strategy_update == BT_POWER_SAVE)
        {
            mode_switch_register_app(BT_MODE_COMMON_SERVER, power_save_start, power_save_stop, power_save_reactive);
        }
        else
        {
            mode_switch_deregister_app(BT_MODE_COMMON_SERVER, power_save_start, power_save_stop, power_save_reactive);
        }
    }
    cntx->power_strategy = cntx->power_strategy_update;
    cntx->alive_time = cntx->alive_time_update;
}

void bt_switch_mode_app_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 event_mask;
    mode_switch_cntx_struct* cntx = &mode_switch_cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] bt_switch_mode_app_init");
    cntx->last_mode = BT_MODE_PERIPHERAL;
    cntx->mode = BT_MODE_MAX;
    cntx->is_init = 1;
    #ifndef __LINKIT_DEV_KIT__
    bt_switch_mode_config(BT_POWER_SAVE, MODE_SWITCH_KEEP_ALIVE_DURATION);
    mode_switch_register_app(BT_MODE_COMMON_SERVER, power_save_start, power_save_stop, power_save_reactive);
    #endif
    
    event_mask = SRV_BT_CM_EVENT_ACTIVATE |
                 SRV_BT_CM_EVENT_BEGIN_DEACTIVATE |
                 SRV_BT_CM_EVENT_RELEASE_ALL_CONN;
    srv_bt_cm_set_notify((srv_bt_cm_notifier)bt_switch_mode_event_notify, event_mask, NULL);
#ifdef __MMI_BLE_DOGP_SUPPORT__ 	
    mode_switch_register_app(BT_MODE_PERIPHERAL, srv_sogps_adp_init, srv_sogps_adp_deinit, NULL);
#endif
#ifdef __MMI_BLE_PXP_SUPPORT__
    mode_switch_register_app(BT_MODE_PERIPHERAL, pxp_srv_app_power_on_to_init, pxp_srv_power_on_to_deinit,NULL);
#endif
#ifdef __BT_GATTC_PROFILE__ 
    mode_switch_register_app(BT_MODE_CENTRAL, gatt_client_start, gatt_client_stop, gatt_client_reactive_handler);
#endif
    return; 
}

/*****************************************************************************
 * FUNCTION
 *  bt_switch_mode_event_notify
 * DESCRIPTION
 *  This function is to received service event
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void bt_switch_mode_event_notify(U32 event, void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mode_switch_cntx_struct* cntx = &mode_switch_cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] bt_switch_mode_event_notify.event:%d", event);
    switch (event)
    {
        case SRV_BT_CM_EVENT_ACTIVATE:
            if (mode_switch_get_curr_mode() == BT_MODE_MAX)
            {
                mode_switch_change_to_last_mode(cntx);
                mode_switch_start_common_server(cntx);
            }
            break;

        case SRV_BT_CM_EVENT_BEGIN_DEACTIVATE:
            if (mode_switch_get_curr_mode() != BT_MODE_MAX)
            {
                mode_switch_change_mode(cntx, BT_MODE_MAX);
                mode_switch_stop_common_server(cntx);
                bt_switch_mode_psc_update();
            }
            break;

        case SRV_BT_CM_EVENT_RELEASE_ALL_CONN:
            srv_bt_cm_switch_off();
            break;
		default :
			break;
	}

}


S32 mode_switch_register_app(mode_enum mode, 
                                    app_start_f app_start_cb, 
                                    app_stop_f app_stop_cb, 
                                    app_reactive_f reactive_cb)
{
    S32 i;
    mode_switch_cntx_struct* cntx = &mode_switch_cntx;

    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] mode_switch_register_app.start_cb:0x%x, stop_cb:0x%x, reactive_cb:0x%x",
                    app_start_cb,
                    app_stop_cb,
                    reactive_cb);
    if ( app_start_cb == NULL && app_stop_cb == NULL)
    {
        return -1;
    }
    
    for (i = 0; i < MODE_SWITCH_MAX_APP_NUM; i++)
    {
        if (cntx->start_cb[i][mode] == app_start_cb 
            && cntx->stop_cb[i][mode] == app_stop_cb 
            && cntx->reactive_cb[i][mode] == reactive_cb)
        {
            return -1;
        }
    }

    for (i = 0; i < MODE_SWITCH_MAX_APP_NUM; i++)
    {
        if (cntx->start_cb[i][mode] == NULL && cntx->stop_cb[i][mode] == NULL)
        {
            cntx->start_cb[i][mode] = app_start_cb;
            cntx->stop_cb[i][mode] = app_stop_cb;
            cntx->reactive_cb[i][mode] = reactive_cb;
            return i;
        }
    }
    return 0;
}


S32 mode_switch_deregister_app(mode_enum mode, 
                                    app_start_f app_start_cb, 
                                    app_stop_f app_stop_cb, 
                                    app_reactive_f reactive_cb)
{
    S32 i;
    mode_switch_cntx_struct* cntx = &mode_switch_cntx;

    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] mode_switch_deregister_app.start_cb:0x%x, stop_cb:0x%x, reactive_cb:0x%x",
                    app_start_cb,
                    app_stop_cb,
                    reactive_cb);
    if ( app_start_cb == NULL && app_stop_cb == NULL)
    {
        return -1;
    }
    
    for (i = 0; i < MODE_SWITCH_MAX_APP_NUM; i++)
    {
        if (cntx->start_cb[i][mode] == app_start_cb 
            && cntx->stop_cb[i][mode] == app_stop_cb 
            && cntx->reactive_cb[i][mode] == reactive_cb)
        {
            cntx->start_cb[i][mode] = NULL;
            cntx->stop_cb[i][mode] = NULL;
            cntx->reactive_cb[i][mode] = NULL;
            return 0;
        }
    }
    return -1;
}


mode_enum mode_switch_get_curr_mode()
{
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] mode_switch_get_curr_mode.");
    return mode_switch_cntx.mode;
}

mode_enum mode_switch_get_last_mode()
{
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] mode_switch_get_last_mode.");
    return mode_switch_cntx.last_mode;
}

void mode_switch_change_to_peripheral(mode_switch_cntx_struct* cntx)
{
    mode_enum curr_mode = BT_MODE_PERIPHERAL;

    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] mode_switch_change_to_peripheral.");
    mode_switch_change_mode(cntx, curr_mode);
}


void mode_switch_change_to_central(mode_switch_cntx_struct* cntx)
{
    mode_enum curr_mode = BT_MODE_CENTRAL;
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] mode_switch_change_to_central.");
    mode_switch_change_mode(cntx, curr_mode);    
}

void mode_switch_change_to_last_mode(mode_switch_cntx_struct* cntx)
{
    mode_enum curr_mode = cntx->last_mode;
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] mode_switch_change_to_last_mode.");
    mode_switch_change_mode(cntx, curr_mode);    
}


void mode_switch_start_common_server(mode_switch_cntx_struct* cntx)
{
    S32 i;
    
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] mode_switch_start_common_server.");
    for (i = 0; i < MODE_SWITCH_MAX_APP_NUM; i++)
    {
        if (cntx->start_cb[i][BT_MODE_COMMON_SERVER] != NULL || cntx->stop_cb[i][BT_MODE_COMMON_SERVER] != NULL)
        {
            if(cntx->start_cb[i][BT_MODE_COMMON_SERVER])
            {
               cntx->start_cb[i][BT_MODE_COMMON_SERVER](); 
            }
        }
    }        
}

void mode_switch_stop_common_server(mode_switch_cntx_struct* cntx)
{
    S32 i;
    
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] mode_switch_stop_common_server.");
    for (i = 0; i < MODE_SWITCH_MAX_APP_NUM; i++)
    {
        if (cntx->start_cb[i][BT_MODE_COMMON_SERVER] != NULL || cntx->stop_cb[i][BT_MODE_COMMON_SERVER] != NULL)
        {
            if(cntx->stop_cb[i][BT_MODE_COMMON_SERVER])
            {
               cntx->stop_cb[i][BT_MODE_COMMON_SERVER](); 
            }
        }
    }        
}

void mode_switch_change_mode(mode_switch_cntx_struct* cntx, mode_enum curr_mode)
{
    S32 i;
    mode_enum prev_mode = cntx->mode;
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] mode_switch_change_mode, prev: %d, curr: %d.", prev_mode, curr_mode);

    if (cntx->is_mode_switching)
    {
        kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] error. can not switching, wait a moument");
        return;
    }
    else
    {
        cntx->is_mode_switching = KAL_TRUE;
    }
    if (prev_mode == curr_mode)
    {
        return;
    }
    if (curr_mode == BT_MODE_CENTRAL)
    {
        srv_bt_cm_write_scanenable_mode_req_hdler(BTBM_ADP_P_ON_I_ON_L_OFF);
    }
    mode_switch_stop_server(cntx, prev_mode);
    cntx->last_mode = prev_mode;
    cntx->mode = curr_mode;

    StartTimer(BT_MODE_SWITCH_DELAY_TIMER, MODE_SWITCH_DELAY_START_SERVER_TIME, mode_switch_change_mode_timeout_cb);
}


void mode_switch_change_mode_timeout_cb(void)
{
    mode_switch_cntx_struct* cntx = &mode_switch_cntx;

    if (srv_bt_cm_get_link_num(SRV_BT_CM_LINK_TYPE_LE) == 0)
    {
        //cntx->is_mode_switching = KAL_FALSE;
        mode_switch_start_server(cntx, cntx->mode);
        
        if (cntx->mode == BT_MODE_PERIPHERAL)
        {
            srv_bt_cm_write_scanenable_mode_req_hdler(BTBM_ADP_P_ON_I_ON);
        }
        StartTimer(BT_MODE_SWITCH_DELAY_TIMER, MODE_SWITCH_DELAY_START_SERVER_TIME, mode_switch_set_status_cb);
    }
    else
    {
        StartTimer(BT_MODE_SWITCH_DELAY_TIMER, MODE_SWITCH_DELAY_START_SERVER_TIME, mode_switch_change_mode_timeout_cb);
    }
}


void mode_switch_set_status_cb(void)
{
    mode_switch_cntx_struct* cntx = &mode_switch_cntx;
    cntx->is_mode_switching = KAL_FALSE;
}

void mode_switch_stop_server(mode_switch_cntx_struct* cntx, mode_enum mode)
{
    S32 i;
    if (mode < BT_MODE_MAX && mode >= BT_MODE_CENTRAL)
    {
        for (i = 0; i < MODE_SWITCH_MAX_APP_NUM; i++)
        {
            if (cntx->start_cb[i][mode] != NULL || cntx->stop_cb[i][mode] != NULL)
            {
                if(cntx->stop_cb[i][mode])
                {
                   cntx->stop_cb[i][mode](); 
                }
            }
        }
    }
}

void mode_switch_start_server(mode_switch_cntx_struct* cntx, mode_enum mode)
{
    S32 i;
    if (mode < BT_MODE_MAX && mode >= BT_MODE_CENTRAL)
    {
        for (i = 0; i < MODE_SWITCH_MAX_APP_NUM; i++)
        {
            if (cntx->start_cb[i][mode] != NULL || cntx->stop_cb[i][mode] != NULL)
            {
                if(cntx->start_cb[i][mode])
                {
                   cntx->start_cb[i][mode](); 
                }
            }
        }
    }
}


void mode_switch_reactivate_handle(void)
{
    S32 ret;
    S32 i,j;
    mode_switch_cntx_struct* cntx = &mode_switch_cntx;

    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] mode_switch_reactivate_handle.");
    if (!cntx->is_init)
    {
        return;
    }

    ret = srv_bt_cm_get_power_status();
    if (ret == SRV_BT_CM_POWER_OFF)
    {
        srv_bt_cm_switch_on();
    }
    else if (ret == SRV_BT_CM_POWER_ON)
    {
        for (i = 0; i < MODE_SWITCH_MAX_APP_NUM; i++)
        {
            if (cntx->reactive_cb[i][BT_MODE_COMMON_SERVER])
            {
                cntx->reactive_cb[i][BT_MODE_COMMON_SERVER]();
            }
            if (cntx->mode != BT_MODE_MAX && cntx->reactive_cb[i][cntx->mode])
            {
                cntx->reactive_cb[i][cntx->mode]();
            }
        }
    }
}


S32 power_save_start(void)
{
    mode_switch_cntx_struct* cntx = &mode_switch_cntx;

    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] power_save_start.");
    timer_started = 1;
    StartTimer(BT_MODE_SWITCH_KEEP_ALIVE_TIMER, cntx->alive_time, power_save_power_off_cb);
    StartTimer(BT_MODE_SWITCH_CONN_CHECK_TIMER, MODE_SWITCH_CHECK_CONN_DURATION, power_save_check_conn_cb);    
}

S32 power_save_reactive(void)
{
    power_save_start();
}

S32 power_save_stop(void)
{
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] power_save_stop.");
    timer_started = 0;
    StopTimer(BT_MODE_SWITCH_KEEP_ALIVE_TIMER);
    StopTimer(BT_MODE_SWITCH_CONN_CHECK_TIMER);
}

void power_save_power_off_cb(void)
{
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] power_save_power_off_cb.");
    if (srv_bt_cm_get_link_num(SRV_BT_CM_LINK_TYPE_DUAL) == 0)
    {
        srv_bt_cm_switch_off();
        power_save_stop();// tricky, because of start service triky when change mode
    }
}

void power_save_check_conn_cb(void)
{
    mode_switch_cntx_struct* cntx = &mode_switch_cntx;

    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] power_save_check_conn_cb.");
    if (srv_bt_cm_get_link_num(SRV_BT_CM_LINK_TYPE_DUAL) == 0 && srv_bt_cm_get_existed_conn_num() == 0)
    {
        if (!timer_started)
        {
            StartTimer(BT_MODE_SWITCH_KEEP_ALIVE_TIMER, cntx->alive_time, power_save_power_off_cb);
            timer_started = 1;
        }
    }
    else
    {
        if (timer_started)
        {
            StopTimer(BT_MODE_SWITCH_KEEP_ALIVE_TIMER);
            timer_started = 0;
        }
    }
    StartTimer(BT_MODE_SWITCH_CONN_CHECK_TIMER, MODE_SWITCH_CHECK_CONN_DURATION, power_save_check_conn_cb); 
}


void conn_bt_AT_callback(app_command_struct *param, void *user_data)
{
	char* command;
    S32 i;
    mode_switch_cntx_struct* cntx = &mode_switch_cntx;

    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] conn_bt_AT_callback.cmd:%s", param->command_buf);
    if (!cntx->is_init)
    {
        return;
    }

    command = param->command_buf;

    for (i = 0; i < BT_COMMAND_MAX; i++)
    {
        if (strstr(command, bt_command[i]) == command)
        {
            command += strlen(bt_command[i]);
            break;
        }
    }
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] parsed cmd:%d", i);

    switch(i)
    {
        case BT_COMMAND_ON:
            bt_switch_mode_power_on_handle();
            mode_switch_paly_tone(BT_MODE_SWITCH_POWERON);
            break;
        case BT_COMMAND_OFF:
            bt_switch_mode_power_off_handle();
            mode_switch_paly_tone(BT_MODE_SWITCH_POWEROFF);
            break;
        case BT_COMMAND_SET_NAME:
            bt_switch_mode_setname_handle(command);
            break;
        case BT_COMMAND_REACTIVE:
            mode_switch_reactivate_handle();
            mode_switch_paly_tone(BT_MODE_SWITCH_REACTIVE);
            break;
        case BT_COMMAND_SWITCH_MODE:
            bt_switch_mode_switch_mode();
            mode_switch_paly_tone(BT_MODE_SWITCH_CHANGE_MODE);
            break;
        case BT_COMMAND_POWER_SAVE_CONFIG:
            bt_switch_mode_power_save_config_handle(command);
            break;
        case BT_COMMAND_SET_INQUIRY_SCAN:
            break;
        case BT_COMMAND_SET_PAGE_SCAN:
            break;
        case BT_COMMAND_SET_ADVERTISING:
            break;
        case BT_COMMAND_DEREGISTER_ALL:
            bt_switch_mode_register(command);
            break;
        case BT_COMMAND_SENT_DATA_TO_TOY:
            gatt_client_send_data_to_toy(command);
            break;
    }
}

void bt_switch_mode_register(char* param)
{
    S32 operate = -1, service_set = 0;
    param += strspn(param, " \t");
    operate = atoi(param);
    param = strpbrk(param, " \t,");
    if (param)
    {
        param += strspn(param, " \t,");
        if (*param)
        {
            service_set = atoi(param);
        }
    }
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] bt_switch_mode_register, operater: %d, service_set:%d", operate, service_set);
    if (service_set > 0x0F || service_set <= 0)
    {
        return;
    }
    if (operate == 1)
    {
        if (service_set & 0x01)
        {
            mode_switch_register_app(BT_MODE_COMMON_SERVER, power_save_start, power_save_stop, power_save_reactive);
        }
        if (service_set & 0x02)
        {
#ifdef __MMI_BLE_DOGP_SUPPORT__ 	
            mode_switch_register_app(BT_MODE_PERIPHERAL, srv_sogps_adp_init, srv_sogps_adp_deinit, NULL);
#endif
        }
        if (service_set & 0x04)
        {
#ifdef __MMI_BLE_PXP_SUPPORT__
            mode_switch_register_app(BT_MODE_PERIPHERAL, pxp_srv_app_power_on_to_init, pxp_srv_power_on_to_deinit,NULL);
#endif
        }
        if (service_set & 0x08)
        {
            mode_switch_register_app(BT_MODE_CENTRAL, gatt_client_start, gatt_client_stop, gatt_client_reactive_handler);
        }
    }
    else if (operate == 0)
    {
        if (service_set & 0x01)
        {
            mode_switch_deregister_app(BT_MODE_COMMON_SERVER, power_save_start, power_save_stop, power_save_reactive);
        }
        if (service_set & 0x02)
        {
#ifdef __MMI_BLE_DOGP_SUPPORT__ 	
            mode_switch_deregister_app(BT_MODE_PERIPHERAL, srv_sogps_adp_init, srv_sogps_adp_deinit, NULL);
#endif
        }
        if (service_set & 0x04)
        {
#ifdef __MMI_BLE_PXP_SUPPORT__
            mode_switch_deregister_app(BT_MODE_PERIPHERAL, pxp_srv_app_power_on_to_init, pxp_srv_power_on_to_deinit,NULL);
#endif
        }
        if (service_set & 0x08)
        {
            mode_switch_deregister_app(BT_MODE_CENTRAL, gatt_client_start, gatt_client_stop, gatt_client_reactive_handler);
        }
    }
}

void mode_switch_paly_tone(mode_switch_tone_enum pattern)
{
    S32 tone_type[BT_MODE_TONE_MAX] = 
        {
            AUD_ID_PROF_RING1,
            AUD_ID_PROF_RING2,
            AUD_ID_PROF_RING3,
            AUD_ID_PROF_RING4,
            AUD_ID_PROF_RING5,
        };
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTMS] mode_switch_paly_tone, pattern: %d", pattern);
    if (pattern < 0 || pattern > BT_MODE_MAX)
    {
        return;
    }
	srv_prof_play_tone_with_id(SRV_PROF_TONE_ALARM, 
							tone_type[pattern], 
						    SRV_PROF_RING_TYPE_ONCE, 
							NULL);
	srv_vibrator_play_once();
}
