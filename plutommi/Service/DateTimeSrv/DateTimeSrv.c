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
 * DateTimeSrv.c
 *
 * Project:
 * --------
 *   IOT
 *
 * Description:
 * ------------
 * This file implements date/time related API for IOT date and time settings
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifndef __MMI_DATE_TIME_SRV_C__
#define __MMI_DATE_TIME_SRV_C__
#include "DateTimeGprot.h"

#include "DateTimeSrvGprot.h"
#include "app_datetime.h"
#include "mmi_msg_struct.h"
#include "ps_public_struct.h"
#include "ProtocolEvents.h"
#include "custom_mmi_default_value.h"   /* for extern MYTIME MyTime;*/
#include "mmi_frm_queue_gprot.h"
#include "mmi_rp_srv_datetime_setting_def.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "MMI_common_app_trc.h"
#include "commSettings.h"
#include "Nvram_data_items.h"
#include "nvram_interface.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "Mmi_rp_app_phonesetting_new_def.h"

#if defined(__GPS_ADAPTOR_SUPPORT__)
#include "GPS_sap.h"
#include "GPS_struct.h"
#endif
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef struct {
	srv_dt_set_time_res_funcptr res_callback;
	applib_time_struct set_time;
	void* usr_data;
	srv_datetime_sync_level level;
	MMI_BOOL enable_sync;
}srv_dt_cntx;
	
static FLOAT g_srv_dt_time_zone;
/***************************************************************************** 
 * Variables
 *****************************************************************************/
static srv_dt_cntx g_srv_dt_cntx;

#ifndef __MTK_TARGET__
extern applib_time_struct MyTime;
#endif
extern rtc_format_struct gclockData;
#if defined(__GPS_ADAPTOR_SUPPORT__)
static MMI_BOOL g_srv_dt_current_time_mode;
#endif
/***************************************************************************** 
 * Function declaration
 *****************************************************************************/
static void srv_dt_conv_rtc2_mytime(applib_time_struct *out_time, const rtc_format_struct *in_time);
static void srv_dt_set_rtc_dt_rsp(void* param);
static void srv_dt_change_notify(const applib_time_struct *old_time, const applib_time_struct *new_time);
#if defined(__GPS_ADAPTOR_SUPPORT__)
static void srv_dt_set_gps_sync_mode_init(void);
static void srv_dt_set_gps_time_sync_hdlr(void* msg);
#endif
#ifdef __NTPD_SUPPORT__
extern void srv_ntp_auto_sync_timer_reset(void);
#endif


/***************************************************************************** 
 * Function define
 *****************************************************************************/
static void srv_dt_conv_rtc2_mytime(applib_time_struct *out_time, const rtc_format_struct *in_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[DateTimeSrv.c]srv_dt_conv_rtc2_mytime.");
	MMI_ASSERT(out_time != NULL && in_time != NULL);
	
	out_time->DayIndex = in_time->rtc_wday;
	out_time->nYear = in_time->rtc_year;
	out_time->nMonth = in_time->rtc_mon;
	out_time->nDay = in_time->rtc_day;
	out_time->nHour = in_time->rtc_hour;
	out_time->nMin = in_time->rtc_min;
	out_time->nSec = in_time->rtc_sec;
}

void srv_dt_set_init(void)
{
	U8 time_zone_from_nvrm;
#if defined(__GPS_ADAPTOR_SUPPORT__)
	srv_dt_set_gps_sync_mode_init();
	SetProtocolEventHandler(srv_dt_set_gps_time_sync_hdlr, MSG_ID_GPS_TIME_SYNC_TO_LOCAL);
#endif
	memset(&g_srv_dt_cntx, 0, sizeof(srv_dt_cntx));
	#if defined(__MMI_UI_DISPLAY_LEVEL_NONE__)
	    g_srv_dt_cntx.enable_sync = MMI_TRUE;
	#endif
	
	ReadValueSlim(SRV_DT_TIME_ZONE, &time_zone_from_nvrm, DS_BYTE);
	g_srv_dt_time_zone = time_zone_from_nvrm / 4.0f;
	g_srv_dt_time_zone -= 12.0f;
}

void srv_dt_set_time_sync_switch(MMI_BOOL enable_sync)
{
    g_srv_dt_cntx.enable_sync = enable_sync;

    if(enable_sync)
    {
        g_srv_dt_cntx.level = SRV_UTC_DT_SYNC_LEVEL_UNDEF;
    }
}

static MMI_BOOL srv_dt_set_check_update_level(srv_datetime_sync_level level)
{
	MMI_BOOL check_pass = MMI_TRUE;
	
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[DateTimeSrv.c]srv_dt_set_check_update_level() BEGIN, old_level=%d, new_level=%d", g_srv_dt_cntx.level, level);
	MMI_ASSERT(level>SRV_UTC_DT_SYNC_LEVEL_UNDEF && level<SRV_UTC_DT_SYNC_LEVEL_END);
    do
    {
        if ((g_srv_dt_cntx.enable_sync == MMI_FALSE && level != SRV_UTC_DT_SYNC_LEVEL1)
            || (g_srv_dt_cntx.enable_sync == MMI_TRUE && level == SRV_UTC_DT_SYNC_LEVEL1))
        {
            check_pass = MMI_FALSE;
            break;
}

        if (g_srv_dt_cntx.level > SRV_UTC_DT_SYNC_LEVEL_UNDEF && g_srv_dt_cntx.level < level)
        {
            check_pass = MMI_FALSE;
        }
		else
        {
            g_srv_dt_cntx.level = level;
        }
    }while(0);
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[DateTimeSrv.c]srv_dt_set_check_update_level() END, check_pass=%d, cur_level=%d", check_pass, g_srv_dt_cntx.level);

    return check_pass;
}

#if defined(__GPS_ADAPTOR_SUPPORT__)
void srv_dt_set_gps_sync_mode_init(void)
{
	g_srv_dt_current_time_mode = MMI_FALSE;
	ReadValueSlim(GPS_TIME_SYNC_MODE, &g_srv_dt_current_time_mode, DS_BYTE);
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[DateTimeSrv.c]srv_dt_set_gps_sync_mode_init, time_sync_mode(%d).", g_srv_dt_current_time_mode);
}

MMI_BOOL srv_dt_set_get_gps_time_sync_mode(void)
{
	return (MMI_BOOL)g_srv_dt_current_time_mode;
}

void srv_dt_set_set_gps_sync_time_mode(MMI_BOOL mode)
{
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[DateTimeSrv.c]srv_dt_set_set_gps_sync_time_mode, original_sync_mode(%d), new_sync_mode(%d).", g_srv_dt_current_time_mode, mode);
	g_srv_dt_current_time_mode = mode;
	WriteValueSlim(GPS_TIME_SYNC_MODE, &g_srv_dt_current_time_mode, DS_BYTE);
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[DateTimeSrv.c]srv_dt_set_set_gps_sync_time_mode, set success");	
}

void srv_dt_set_gps_time_sync_hdlr(void* msg)
{
	gps_time_sync_to_local_struct* gps_msg = (gps_time_sync_to_local_struct*)msg;
	applib_time_struct utc_time;
	srv_datetime_sync_level level = SRV_UTC_DT_SYNC_LEVEL2;
	U8 update_datetime_mode;

	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[DateTimeSrv.c]srv_dt_set_gps_time_sync_hdlr, time_sync_mode(%d).", g_srv_dt_current_time_mode);
	if (!g_srv_dt_current_time_mode)
		return;

	memset(&utc_time, 0, sizeof(utc_time));	
	utc_time.nYear = gps_msg->utc_date.year;
	utc_time.nMonth = gps_msg->utc_date.month;
	utc_time.nDay = gps_msg->utc_date.day;
	utc_time.nHour = gps_msg->utc_time.hour;
	utc_time.nMin = gps_msg->utc_time.minute;
	utc_time.nSec = gps_msg->utc_time.second;

	srv_dt_set_dt(level, &utc_time, NULL, NULL);
	update_datetime_mode = MMI_UPDATE_DATETIME_GPS;
	WriteValueSlim(NVRAM_UPDATE_DATETIME_MODE, &update_datetime_mode, DS_BYTE);
#ifdef __NTPD_SUPPORT__
	srv_ntp_auto_sync_timer_reset();
#endif
}
#endif

void srv_dt_set_time_zone(S16 time_zone)
{
    U8 time_zone_for_nvrm = (U8)(time_zone + 48);

    WriteValueSlim(SRV_DT_TIME_ZONE, &time_zone_for_nvrm, DS_BYTE);
    g_srv_dt_time_zone = time_zone / 4.0f;	
}

S32 srv_dt_set_dt(srv_datetime_sync_level level, const applib_time_struct *time, srv_dt_set_time_res_funcptr callback, void* usr_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct local_time;
	U64 utcSec = 0;
	U8 update_datetime_mode;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[DateTimeSrv.c]srv_dt_set_dt.");
    memcpy(&local_time, time, sizeof(applib_time_struct));
    if(srv_dt_set_check_update_level(level) ==	MMI_FALSE)
    {
        return SETTING_RESULT_FAIL;
    }
	g_srv_dt_cntx.res_callback = callback;
	g_srv_dt_cntx.usr_data = usr_data;

	ReadValueSlim(NVRAM_UPDATE_DATETIME_MODE, &update_datetime_mode, DS_BYTE);
	
    if (MMI_UPDATE_DATETIME_NITZ != update_datetime_mode && level > SRV_UTC_DT_SYNC_LEVEL1 && level < SRV_UTC_DT_SYNC_LEVEL4)
    {
        applib_dt_utc_to_rtc(g_srv_dt_time_zone, (applib_time_struct *)time, &local_time);
    }
    srv_dt_set_rtc_dt(&local_time);
	if (SRV_UTC_DT_SYNC_LEVEL1 == level || SRV_UTC_DT_SYNC_LEVEL2 == level)
		{
			utcSec = applib_dt_mytime_2_utc_sec(&local_time, MMI_FALSE);
			WriteValueSlim(NVRAM_RTC_TIME, &utcSec, DS_DOUBLE);
		}
    return SETTING_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_dt_set_rtc_dt
 * DESCRIPTION
 *  This function is to send set time request to L4
 *  Functionality:
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dt_set_rtc_dt(const applib_time_struct *t)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_rtc_time_req_struct *time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[DateTimeSrv.c]srv_dt_set_rtc_dt.");
	SetProtocolEventHandler(srv_dt_set_rtc_dt_rsp, HW_SET_TIME_REQ_SUCCESS);
	g_srv_dt_cntx.set_time = *t;
	
    time = OslAllocDataPtr(mmi_eq_set_rtc_time_req_struct);
	
    time->info.alarm_format = 0;
    time->info.alarm_index = 0;
    time->info.type = 0;
    time->info.text[0] = '\0';
    time->info.recurr = 0;
    time->info.data_time.rtc_sec = t->nSec;
    time->info.data_time.rtc_min = t->nMin;
    time->info.data_time.rtc_hour = t->nHour;

    time->rtc_type = RTC_TIME_CLOCK_IND;
    time->set_type = RTC_SETTING_TYPE_DATETIME;
    time->info.data_time.rtc_day = t->nDay;
    time->info.data_time.rtc_mon = t->nMonth;
    time->info.data_time.rtc_year = t->nYear - YEARFORMATE;
    time->info.data_time.rtc_wday = applib_dt_dow(t->nYear, t->nMonth, t->nDay);

	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[DateTimeSrv.c]set rtc: y=%d, m=%d, d=%d.", t->nYear, t->nMonth, t->nDay);
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[DateTimeSrv.c]set rtc: h=%d, m=%d, s=%d.", t->nHour, t->nMin, t->nSec);
	mmi_frm_send_ilm(MOD_L4C, HW_SET_TIME_REQ, (oslParaType *)time, NULL);
	
#else /* __MTK_TARGET__ */ 
	mmi_eq_set_rtc_time_rsp_struct rsp;
	SetProtocolEventHandler(srv_dt_set_rtc_dt_rsp, HW_SET_TIME_REQ_SUCCESS);

	g_srv_dt_cntx.set_time = *t;
    MyTime = *t;

	rsp.result = 1;
	srv_dt_set_rtc_dt_rsp(&rsp);

#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_dt_set_rtc_dt_rsp
 * DESCRIPTION
 *  Function to set date and time information to global variable of MMI
 * PARAMETERS
 *  t       [IN]        Struct variable that stores date and time information from PS
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_dt_set_rtc_dt_rsp(void* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_rtc_time_rsp_struct *res_ptr;
	applib_time_struct old_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[DateTimeSrv.c]srv_dt_set_rtc_dt_rsp.");
	MMI_ASSERT(param != NULL);
	res_ptr = (mmi_eq_set_rtc_time_rsp_struct*)(param);
	
	if (res_ptr->result == 1)
	{
    #ifdef __MTK_TARGET__
		srv_dt_conv_rtc2_mytime(&old_time, &gclockData);
	
        gclockData.rtc_year = g_srv_dt_cntx.set_time.nYear- YEARFORMATE;
        gclockData.rtc_mon = g_srv_dt_cntx.set_time.nMonth;
        gclockData.rtc_day = g_srv_dt_cntx.set_time.nDay;
        gclockData.rtc_hour = g_srv_dt_cntx.set_time.nHour;
        gclockData.rtc_min = g_srv_dt_cntx.set_time.nMin;
    #else /* __MTK_TARGET__ */
		old_time = MyTime;
		MyTime = g_srv_dt_cntx.set_time;
        DateTimerProc();
    #endif /* __MTK_TARGET__ */ 

		srv_dt_change_notify(&old_time, &g_srv_dt_cntx.set_time);
        srv_reminder_on_time_change_notify(NULL);
	}

	if (g_srv_dt_cntx.res_callback != NULL)
	{
		g_srv_dt_cntx.res_callback((MMI_BOOL)(res_ptr->result == 1), g_srv_dt_cntx.usr_data);
		g_srv_dt_cntx.res_callback = NULL;
		g_srv_dt_cntx.usr_data = NULL;
	}
}

/*****************************************************************************
 * FUNCTION
 *  srv_dt_change_notify
 * DESCRIPTION
 *  Notify system date and time changed.
 * PARAMETERS
 *  old_time	:[IN]	old time
 *  new_time	:[IN]	new time
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_dt_change_notify(const applib_time_struct *old_time, const applib_time_struct *new_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_datetime_evt_struct dt_evt;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[DateTimeSrv.c]srv_dt_set_rtc_dt_rsp.");
	MMI_FRM_INIT_EVENT(&dt_evt, EVT_ID_SRV_DATE_AND_TIME_CHANGE);
	
	memcpy(&dt_evt.old_time, old_time, sizeof(applib_time_struct));
	memcpy(&dt_evt.new_time, new_time, sizeof(applib_time_struct));

	/*
	if (old_time->nMin != new_time->nMin)
	{
		dt_evt.change |= SRV_DATETIME_CHANGE_FLAG_MIN;
	}
	if (old_time->nHour != new_time->nHour)
	{
		dt_evt.change |= SRV_DATETIME_CHANGE_FLAG_HOUR;
	}
	if (old_time->nDay != new_time->nDay)
	{
		dt_evt.change |= SRV_DATETIME_CHANGE_FLAG_DAY;
	}
	
	if (old_time->nMonth != new_time->nMonth)
	{
		dt_evt.change |= SRV_DATETIME_CHANGE_FLAG_MONTH;
	}
	*/
	
	MMI_FRM_CB_EMIT_EVENT(&dt_evt);
}

#endif /*__MMI_DATE_TIME_SRV_C__*/

