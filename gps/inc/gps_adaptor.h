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
*  gps_agps_process.h
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  AGPS related structure define in GPS task
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
*******************************************************************************/
#ifndef __GPS_ADAPTOR_H__
#define __GPS_ADAPTOR_H__
#ifdef __GPS_ADAPTOR_SUPPORT__

#include "stack_config.h"
#include "gps2lcsp_enum.h"
#include "gps2lcsp_struct.h"
#include "agps_struct.h"
#include "gps_main.h"
#include "gps_uart_hdlr.h"
#include "app_ltlcom.h"

#include "kal_general_types.h"
#include "kal_public_defs.h"

#include "gps_trc.h"

#define GPS_ADAPTOR_DEBUG_LEVEL 0//0 :kal_trace;    1: kal_prompt_trace
#if (GPS_ADAPTOR_DEBUG_LEVEL==0)
#define GPSADAPTOR_TRACE(args)     kal_trace args
#else
#define GPSADAPTOR_TRACE(args)     kal_prompt_trace args
#endif

#if defined(__AGPS_SUPPORT__)
#include "uagps_cp_gps_struct.h"
#define GPS_CP_AREA_EVENTS_NUM    (3)
#endif /*__AGPS_SUPPORT__*/


typedef struct{
	kal_uint32 user_data; 
	module_type src_mod;
	gps_start_mode_enum start_mode;
	kal_uint32 result;
}gps_timer_data_struct;

typedef enum
{
    GPS_ADAPTOR_TIMER = 0,
#ifndef __GPS_EPO_DOWNLOAD__
    GPS_EPO_TIMER,
#endif
    GPS_AGPS_SWITCH_MODE_TIMER,
    MAX_NUM_OF_GPS_ADAPTOR_TIMER
} gps_adaptor_timer_enum;

void gps_adaptor_start_timer(kal_uint8 timer_id, kal_uint32 period, kal_timer_func_ptr timer_expiry, void *arg);

void gps_adaptor_stop_timer(kal_uint8 timer_id);




//define timeID   time_interval

void send_msg_to_gps_task(module_type src_mod,module_type dst_mod,msg_type msg_id,void *local_param_ptr, kal_uint32 para_size);

#endif
#endif /*__GPS_ADAPTOR_H__*/


