/***********************************************************************
*   This software/firmware and related documentation ("MediaTek Software") 
*   are protected under relevant copyright laws. The information contained 
*   herein is confidential and proprietary to MediaTek Inc. and/or its licensors.
*
*   Without the prior written permission of MediaTek Inc. and/or its licensors, 
*   any reproduction, modification, use or disclosure of MediaTek Software, and 
*   information contained herein, in whole or in part, shall be strictly prohibited.
*
*   MediaTek Inc. (C) [2007]. All rights reserved.
*
*************************************************************************/ 
/*******************************************************************************
 * Filename:
 * ---------
 *  gps_main.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GPS task
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/***************************************************************************** 
 * Include
 *****************************************************************************/ 
#include "kal_trace.h"
#include "stack_msgs.h"         /* enum for message IDs */
#include "app_ltlcom.h"         /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "dcl.h"
#include "gps_main.h"
#include "gps_init.h"
#include "gps_sm.h"
#include "gps_trc.h"
#include "stack_ltlcom.h"
#include "stack_config.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
#ifdef UNIT_TEST
#include "gps_uart_hdlr.h"
#endif
        
#include "gps_agps_process.h"

#ifdef __GPS_EPO_DOWNLOAD__
#include "wepodownload.h"
#else
#include "epodownload.h"
#endif

#ifdef __GPS_SUPPORT__
extern void gps_tst_inject_string_handler( ilm_struct *ilm_ptr );
#endif
extern void gps_uart_state_reset(void);
#if defined(__AGPS_SUPPORT__)
extern void gps_agps_init(void);
extern void gps_agps_reset(void);
#endif
extern kal_bool gps_msg_hdlr(ilm_struct *ilm_ptr);
extern kal_uint8 gps_uart_port;

gps_context_struct gps_context;
gps_context_struct *gps_context_p = &gps_context;
gps_timer_table_struct gps_timer_table[MAX_NUM_OF_GPS_TIMER];

#ifdef __IOT_CUSTOMIZE__
kal_mutexid g_agps_supl_mutex;
static kal_bool gps_get_supl_ref_location(double *latitude, double *longitude);
#endif

#ifdef UNIT_TEST
/* Klockwork issue fix 20120712
 * align buffer length used (256 bytes) in gps_uart_ready_to_read_ind() instead of GPS_UART_RAW_BUF_SIZE (30 bytes),
 * and avoid memory corruption in case long sentence received by tst_inject
 */
kal_uint8  gps_command_buffer[GPS_NMEA_BUFFER_SIZE+1];
kal_uint16 gps_command_bsize;
#endif

static void gps_timer_expiry(ilm_struct *ilm_ptr);
static void gps_timer_expiry_callback(void *arg);
extern void gps_uart_state_init(void);

kal_bool GPS_TASK_INIT_OK = KAL_FALSE;
/*****************************************************************************
 * FUNCTION
 *  gps_main
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  ilm_ptr     [IN]     message data
 * RETURNS
 *  void
 *****************************************************************************/
void gps_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifdef __IOT_CUSTOMIZE__
    double      temp_long,temp_lati;
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MSG_ID_TIMER_EXPIRY == ilm_ptr->msg_id)
    {
        gps_timer_expiry(ilm_ptr);
    }
#ifdef __GPS_SUPPORT__
    else if (MSG_ID_TST_INJECT_STRING == ilm_ptr->msg_id)
    {
        gps_tst_inject_string_handler( ilm_ptr );
    }
    else if (MSG_ID_RTC_GPS_TIME_CHANGE_IND == ilm_ptr->msg_id)
    {
        GPS_Adjust_RTC_Diff( ilm_ptr );
    }
    else if (MSG_ID_NVRAM_WRITE_CNF == ilm_ptr->msg_id)
    {
        gps_nvram_write_cnf_handler( ilm_ptr );
    }
    else if (MSG_ID_GPS_HOST_WAKE_UP_IND == ilm_ptr->msg_id)
    {
        gps_host_wake_up_ind_handler();
    }
#endif /*__GPS_SUPPORT__*/
#ifdef UNIT_TEST
    else if (MSG_ID_GPS_UT_SET_EVENT_IND == ilm_ptr->msg_id)
    {
        /* Viola 20110712
         * This message is used to verified "set-event" and "ret value" in UT
         */
        return;
    }
#endif
#ifdef GPS_EPO_DOWNLOAD
    else if (MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND == ilm_ptr->msg_id ||
        MSG_ID_APP_SOC_NOTIFY_IND == ilm_ptr->msg_id)
    {
        epo_connectivty_message_handler(ilm_ptr);
    }
    else if (MSG_ID_EPO_BT_DOWNLOAD_REQ == ilm_ptr->msg_id ||
        MSG_ID_EPODOWNLOAD_BT_CONNECT_IND == ilm_ptr->msg_id ||
        MSG_ID_BT_EPO_DOWNLOAD_FINISH == ilm_ptr->msg_id ||
        MSG_ID_EPODOWNLOAD_BT_DISCONNECT_IND == ilm_ptr->msg_id)
    {
        epo_bt_download_message_handler(ilm_ptr);
    }
#endif
    else if (KAL_TRUE == gps_msg_hdlr(ilm_ptr))
    {
        #ifdef __IOT_CUSTOMIZE__
        /* If use the code of below block, it can be used to get reference location*/
        /*
        if (ilm_ptr->msg_id == MSG_ID_GPS_LCSP_ASSIST_DATA_REQ)
        {
            if(gps_get_supl_ref_location(&temp_lati, &temp_long))
            {
                // got valid supl reference location
            }
        }
        */
        #endif
        return;
    }

}


/*****************************************************************************
 * FUNCTION
 *  gps_task_main
 * DESCRIPTION
 *  GPS task main
 * PARAMETERS
 *  task_entry_ptr      [IN]        task struct pointer 
 * RETURNS
 *  void
 *****************************************************************************/
void gps_task_main(task_entry_struct *task_entry_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;
    kal_uint32 my_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_my_task_index(&my_index);
    
#if defined(__SMART_PHONE_MODEM__)||defined(__FEATURE_PHONE_MODEM__)
    gps_uart_state_init();
#endif

#if defined(__SMART_PHONE_MODEM__)//smart phone used for CCCI,but FP don't need.because gps init will open uart by gps or mnl.
	{	
		DCL_HANDLE handle;
		UART_CTRL_OPEN_T data;	
		
	    data.u4OwenrId = MOD_GPS;
		handle = DclSerialPort_Open(gps_uart_port, 0);
		DclSerialPort_Control(handle, SIO_CMD_OPEN, (DCL_CTRL_DATA_T*)&data); 	
	}
#endif

#ifdef __IOT_CUSTOMIZE__
    g_agps_supl_mutex = kal_create_mutex("supl_ref_location");
#endif
#ifdef GPS_EPO_DOWNLOAD
    epo_init(EPO_MAX_CHUNK, NULL, NULL);
#endif

    while (1)
    {
        receive_msg_ext_q_for_stack(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
        stack_set_active_module_id(my_index, current_ilm.dest_mod_id);

        gps_main((void*)&current_ilm);

        free_ilm(&current_ilm);
    }

}


/*****************************************************************************
 * FUNCTION
 *  gps_task_init
 * DESCRIPTION
 *  Init GPS task
 * PARAMETERS
 *  task_indx       [IN]    task index             
 * RETURNS
 *  KAL_BOOL
 *****************************************************************************/
kal_bool gps_task_init(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gps_context_p->gps_state = GPS_POWEROFF_STATE; 
    
    gps_context_p->event_scheduler_ptr = evshed_create("GPS base timer", MOD_GPS, 0, 0 );

    GPS_TASK_INIT_OK = KAL_TRUE;

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  gps_task_reset
 * DESCRIPTION
 *  Reset GPS task
 * PARAMETERS
 *  task_indx       [IN]    task index             
 * RETURNS
 *  KAL_BOOL
 *****************************************************************************/
kal_bool gps_task_reset(task_indx_type task_indx)
{
    int j;
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gps_context_p->gps_state = GPS_POWEROFF_STATE; 
    
    GPS_TASK_INIT_OK = KAL_TRUE;

    evshed_delete_all_events(gps_context_p->event_scheduler_ptr);

    for(j = 0; j < MAX_NUM_OF_GPS_TIMER; j++)
    {
       gps_timer_table[j].event_id = NULL;
    }
    
    gps_uart_state_reset();
#if defined(__AGPS_SUPPORT__)
    gps_agps_reset();
#endif

#ifdef UNIT_TEST
    gps_command_bsize = 0;
#endif
    
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  gps_task_init_ok
 * DESCRIPTION
 *  Init GPS task
 * PARAMETERS
 *  none            
 * RETURNS
 *  KAL_BOOL
 *****************************************************************************/
kal_bool gps_task_init_ok(void)
{
    return GPS_TASK_INIT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  gps_create
 * DESCRIPTION
 *  Create GPS task
 * PARAMETERS
 *  handle      [IN]     handle
 * RETURNS
 *  KAL_BOOL
 *****************************************************************************/
kal_bool gps_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct gps_handler_info = 
    {
        gps_task_main,  /* task entry function */
        gps_task_init,  /* task initialization function */
        NULL,           /* task configuration function */
        gps_task_reset, /* task reset handler */
        NULL,           /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*)&gps_handler_info;

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gps_timer_expiry
 * DESCRIPTION
 * 
 * PARAMETERS
 *  ilm_ptr                
 * RETURNS
 *  void
 *****************************************************************************/
static void gps_timer_expiry(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    evshed_timer_handler(gps_context_p->event_scheduler_ptr);

}
/*****************************************************************************
 * FUNCTION
 *  gps_timer_expiry_callback
 * DESCRIPTION
 *  timer exiry callback
 * PARAMETERS
 *  arg     [IN]   callback function parameter   
 * RETURNS
 *  void
 *****************************************************************************/
static void gps_timer_expiry_callback(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *timer_id = (kal_uint8*) arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((kal_uint32) timer_id < (kal_uint32) MAX_NUM_OF_GPS_TIMER)
    {
        GPS_TRACE((TRACE_GROUP_4, GPS_TIMER_TRC_TIMEOUT_ID, timer_id));    
        gps_timer_table[(kal_uint32) (timer_id)].event_id = NULL;
        (gps_timer_table[(kal_uint32) (timer_id)].callback_func) (gps_timer_table[(kal_uint32) (timer_id)].arg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gps_start_timer
 * DESCRIPTION
 *  start timer
 * PARAMETERS
 *  timer_id            [IN]      timer id  
 *  period              [IN]       period 
 *  timer_expiry        [IN]    delay time in ticks    
 *  arg                 [IN]      callback function parameter      
 * RETURNS
 *  void
 *****************************************************************************/
void gps_start_timer(kal_uint8 timer_id, kal_uint32 period, kal_timer_func_ptr timer_expiry, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 temp = period * 13 / 60 + 1;    /* ~= x 1/4.615 */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gps_timer_table[timer_id].callback_func = timer_expiry;
    gps_timer_table[timer_id].arg = arg;
    gps_timer_table[timer_id].event_id = evshed_set_event(
                                            gps_context_p->event_scheduler_ptr,
                                            (kal_timer_func_ptr) gps_timer_expiry_callback,
                                            (void*)timer_id,
                                            temp /** KAL_TICKS_10_MSEC */ );
}


/*****************************************************************************
 * FUNCTION
 *  gps_stop_timer
 * DESCRIPTION
 *  stop timer
 * PARAMETERS
 *  timer_id        [IN]    timer id    
 * RETURNS
 *  void
 *****************************************************************************/
void gps_stop_timer(kal_uint8 timer_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gps_timer_table[timer_id].event_id != NULL)
    {
        evshed_cancel_event(gps_context_p->event_scheduler_ptr, &(gps_timer_table[timer_id].event_id));
        gps_timer_table[timer_id].event_id = NULL;
    }
}

#ifdef __IOT_CUSTOMIZE__
/*****************************************************************************
 * FUNCTION
 *  gps_get_supl_ref_location
 * DESCRIPTION
 *  Get SUPL ref. location data
 * PARAMETERS
 *  latitude        [OUT]    referenced latitude in degrees (-90~90)   
 *  longitude       [OUT]    referenced longitude in degrees (-180~180)
 * RETURNS
 *  kal_bool        KAL_TRUE: Valid, KAL_FALSE: Invalid
 *****************************************************************************/
kal_bool gps_get_supl_ref_location(double *latitude, double *longitude)
{
    *longitude = g_supl_ref_location.longitude;
    *latitude = g_supl_ref_location.latitude;
    if(g_supl_ref_location.longitude && g_supl_ref_location.latitude)
        return KAL_TRUE;
    else
        return KAL_FALSE;
}
#endif


void agps_assist_ref_location_finished_callback()
{
	kal_prompt_trace(MOD_GPS, "assist ref loaction finish callback");
}

void agps_assist_ref_time_finished_callback()
{
	kal_prompt_trace(MOD_GPS, "assist ref time finish callback");
}
void agps_assist_epo_finished_callback()
{
	kal_prompt_trace(MOD_GPS, "assist EPO finish callback");
}
