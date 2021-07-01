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
*  TimeSrvGprot.h
*
* Project:
* -------- 
*  MAUI
*
* Description:
* ------------
*  Time sync extension
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef __TIME_SRV_GPROT_H__
#define __TIME_SRV_GPROT_H__

/****************************************************************************
 * Include
 ****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "btostypes.h"
#include "bt_types.h"
#include "GattcSrv.h"
#include "kal_trace.h"
#include "MMI_conn_app_trc.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_events_gprot.h"


#define __TIME_SYNC_EXT__


/* time handle */
typedef void *SRV_TIME_HANDLE;

/* time evt enum */
typedef enum
{
    SRV_TIME_EVT_CONNECT        = 0,
    SRV_TIME_EVT_DISCONNECT,
    SRV_TIME_EVT_TF_NOTI,
    SRV_TIME_EVT_TF_RCB,
    SRV_TIME_EVT_TF_SEARCH,

    SRV_TIME_EVT_TOTAL
} srv_time_evt_enum;

/* time callback struct */
typedef struct
{
    U8 evt;
    void *ud;   /* user data */
    void *para;
} srv_time_evt_struct;

typedef void (*srv_time_evt_cb)(srv_time_evt_struct *evt);

/* register  req struct */
typedef struct
{
    U8 type;
    void *ud;   /* user data */
    BD_ADDR bd_addr;
    void *func_cb;
} srv_time_reg_struct;

/* tf struct */
typedef struct
{
    U8 tf;
} srv_time_tf_struct;

/* evt struct */
typedef struct
{
    MMI_EVT_PARAM_HEADER
} srv_tip_update_time_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
} srv_tip_connect_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
} srv_time_update_tf_struct;

/*****************************************************************************
* FUNCTION
*  srv_time_register
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
extern SRV_TIME_HANDLE srv_time_register(srv_time_reg_struct *reg);


/*****************************************************************************
* FUNCTION
*  srv_time_deregister
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
extern S32 srv_time_deregister(SRV_TIME_HANDLE handle);


/*****************************************************************************
* FUNCTION
*  srv_time_read_tf
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
extern S32 srv_time_read_tf(SRV_TIME_HANDLE handle);

#endif /* __TIME_SRV_GPROT_H__ */

