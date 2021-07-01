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

/*******************************************************************************
 * Filename:
 * ---------
 * DateTimeSrvGprot.h
 *
 * Project:
 * --------
 * IOT
 *
 * Description:
 * ------------
 * This file defines function prototypes for date/time service realted utilities.
 *
 * Author:
 * -------
 * -------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ***************************************************************/

#ifndef _MMI_DATETIME_SRV_GPROT_H
#define _MMI_DATETIME_SRV_GPROT_H

#include "MMIDataType.h"
#include "app_datetime.h"
//#include "custom_mmi_default_value.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef struct
{
    MMI_EVT_PARAM_HEADER    
    U32 change;
	applib_time_struct old_time;
	applib_time_struct new_time;
} srv_datetime_evt_struct;

typedef enum
{
    SRV_UTC_DT_SYNC_LEVEL_UNDEF,
    SRV_UTC_DT_SYNC_LEVEL1,
    SRV_UTC_DT_SYNC_LEVEL2,
    SRV_UTC_DT_SYNC_LEVEL3,
    SRV_UTC_DT_SYNC_LEVEL4,

    SRV_UTC_DT_SYNC_LEVEL_END
}srv_datetime_sync_level;

typedef void (*srv_dt_set_time_res_funcptr) (kal_bool result, void* usr_data);

/***************************************************************************** 
 * Variables
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
extern void srv_dt_set_rtc_dt(const applib_time_struct *t);
extern S32 srv_dt_set_dt(srv_datetime_sync_level level, const applib_time_struct *time, srv_dt_set_time_res_funcptr callback, void* usr_data);
extern void srv_dt_set_time_zone(S16 time_zone);
extern void srv_dt_set_init(void);
extern void srv_dt_set_time_sync_switch(MMI_BOOL enable_sync);

#if defined(__GPS_ADAPTOR_SUPPORT__)
extern MMI_BOOL srv_dt_set_get_gps_time_sync_mode(void);
extern void srv_dt_set_set_gps_sync_time_mode(MMI_BOOL mode);
#endif

#endif /* _MMI_DATETIME_SRV_GPROT_H */ 

