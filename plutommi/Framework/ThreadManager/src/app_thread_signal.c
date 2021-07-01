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
 *  app_thread_signal.c
 *
 * Project:
 * -------- 
 *  IOT
 *
 * Description:
 * ------------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



/*************************************************************************
 * Include Statements
 *************************************************************************/
#include "kal_release.h"
#include "stack_types.h"
#include "mmi_frm_gprot.h"
#include "mmi_frm_prot.h"
#include "app_thread_mutex_gprot.h"
#include "app_frm_thread_gprot.h"
#include "app_thread_mgr.h"



/***************************************************************************** 
 * Define
 *****************************************************************************/
#define APP_FRM_SIGNAL_MAX             128
#define APP_FRM_EG_MAX                 ((APP_FRM_SIGNAL_MAX >> 4) + 1)
#define APP_FRM_FREE_MASK_LEN          ((APP_FRM_SIGNAL_MAX >> 5) + 1)
#define SIGNAL_ACCESS_LOCK           app_frm_mutex_lock(&signal_mutex)
#define SIGNAL_ACCESS_UNLOCK         app_frm_mutex_unlock(&signal_mutex);


typedef struct
{
    U32                   busy_mask;
    kal_eventgrpid        event_id;
} APP_GE_INFO_STRUCT;

typedef struct
{
	msg_type  msg_id;
    SIGNAL_ID s_id;
} app_frm_msg_signal_struct;

typedef struct
{
    SIGNAL_ID s_id;
	kal_taskid create_task;
	
} app_frm_signal_info_struct;


/***************************************************************************** 
 * Global variable
 *****************************************************************************/
static app_frm_mutex_struct      signal_mutex;
static U32                       signal_free_map[APP_FRM_FREE_MASK_LEN];
static kal_eventgrpid            signal_eg_array[APP_FRM_EG_MAX];
static kal_taskid                signal_create_task[APP_FRM_SIGNAL_MAX];

/***************************************************************************** 
 * Function
 *****************************************************************************/
static S32 app_frm_signal_valide_int(SIGNAL_ID s_id);
static void app_frm_signal_cancel_int(SIGNAL_ID s_id);


extern void app_frm_signal_bootup_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	app_frm_mutex_create(&signal_mutex);
	//initial ge array.
	for (i = 0; i < APP_FRM_EG_MAX; i++)
	{
		signal_eg_array[i] = kal_create_event_group("APP_FRM_SIGNAL");
	}
	return;
}
extern SIGNAL_ID app_frm_signal_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32               i;
	U32               var;
	kal_taskid        t_id;
	SIGNAL_ID         s_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SIGNAL_ACCESS_LOCK;
	for(i = 0; i < APP_FRM_FREE_MASK_LEN; i++)
	{
		if (signal_free_map[i] == 0xFFFFFFFF)
		{
			continue;
		}
		else
		{	
			break;
		}
	}

	if (i == APP_FRM_FREE_MASK_LEN)
	{
		// no free signal to use.
		SIGNAL_ACCESS_UNLOCK;
		return 0;
	}
	
	for (var = 0; var < 32; var++)
	{
		if (signal_free_map[i] & (0x1<< var))
		{
			continue;
		}
		else
		{
			signal_free_map[i] |= (0x1<< var);
			break;
		}
	}
	SIGNAL_ACCESS_UNLOCK;
	var |= (i << 4);
	t_id = kal_get_current_task();
	signal_create_task[var] = t_id;
	s_id = (SIGNAL_ID)((((U32)t_id)<<16) | var);
	return s_id;
}

extern void app_frm_signal_clean(SIGNAL_ID s_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32                   var1, var2;
	kal_eventgrpid        event_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SIGNAL_ACCESS_LOCK;
	ASSERT(app_frm_signal_valide_int(s_id));
	var1 = ((U32) s_id) & 0x0FFFF;
	event_id = signal_eg_array[var1>>4];
	var2 = ~(0x3<<((var1 & 0x0F) << 1));
	kal_set_eg_events(event_id, var2, KAL_AND);
	SIGNAL_ACCESS_UNLOCK;
	return;
}

extern void app_frm_signal_post(SIGNAL_ID s_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32                   var1, var2;
	kal_eventgrpid        event_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SIGNAL_ACCESS_LOCK;
	ASSERT(app_frm_signal_valide_int(s_id));
	var1 = ((U32) s_id) & 0x0FFFF;
	event_id = signal_eg_array[var1>>4];
	var2 = 0x1<<((var1 & 0x0F) << 1);
	kal_set_eg_events(event_id, var2, KAL_OR);
	SIGNAL_ACCESS_UNLOCK;
	return;

}

extern S32 app_frm_signal_wait(SIGNAL_ID s_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32                   var1, event_bit, event_bit_cancel;
	kal_eventgrpid        event_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SIGNAL_ACCESS_LOCK;
	ASSERT(app_frm_signal_valide_int(s_id));
	var1 = ((U32) s_id) & 0x0FFFF;
	event_id = signal_eg_array[var1>>4];
	SIGNAL_ACCESS_UNLOCK;
	event_bit = 0x1<<((var1 & 0x0F) << 1);
	event_bit_cancel = 0x2<<((var1 & 0x0F) << 1);	
	kal_retrieve_eg_events(
						event_id, 
						event_bit | event_bit_cancel, 
						KAL_OR_CONSUME,
						&var1,
						KAL_SUSPEND
						);
	if (var1 & event_bit)
	{
		return SIGNAL_RESULT_SUCCESS;
	}
	else
	{
		return SIGNAL_RESULT_CANCEL;
	}
}


extern S32 app_frm_signal_timedwait(SIGNAL_ID s_id, U32 time_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32                   var1, event_bit, event_bit_cancel;
	kal_eventgrpid        event_id;
	kal_status            status;
	kal_uint32            ticks;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SIGNAL_ACCESS_LOCK;
	ASSERT(app_frm_signal_valide_int(s_id));
	var1 = ((U32) s_id) & 0x0FFFF;
	event_id = signal_eg_array[var1>>4];
	SIGNAL_ACCESS_UNLOCK;
	ticks = kal_milli_secs_to_ticks(time_count);
	event_bit = 0x1<<((var1 & 0x0F) << 1);
	event_bit_cancel = 0x2<<((var1 & 0x0F) << 1);	
	status = kal_retrieve_eg_events_timeout(
		                event_id, 
		                event_bit | event_bit_cancel,
		                KAL_OR_CONSUME,
                        &var1, 
                        ticks
                        );
	if (status == KAL_NOT_PRESENT)
	{
		return SIGNAL_RESULT_TIMEOUT;
	}
	else if (var1 & event_bit)
	{
		return SIGNAL_RESULT_SUCCESS;
	}
	else
	{
		return SIGNAL_RESULT_CANCEL;
	}	
}

extern void app_frm_signal_deinit(SIGNAL_ID s_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32                   var, current_mask;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SIGNAL_ACCESS_LOCK;
	ASSERT(app_frm_signal_valide_int(s_id));
	app_frm_signal_cancel_int(s_id);	
	app_frm_signal_clean(s_id);
	//clean mask.
	var = ((U32) s_id) & 0x0FFFF;
	signal_free_map[var>>5] &= ~(0x1 << (var & 0x1F));
	signal_create_task[var] = NULL;
	SIGNAL_ACCESS_UNLOCK;

}


static void app_frm_signal_cancel_int(SIGNAL_ID s_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32                   var1, var2;
	kal_eventgrpid        event_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ASSERT(app_frm_signal_valide_int(s_id));
	var1 = ((U32) s_id) & 0x0FFFF;
	event_id = signal_eg_array[var1>>4];
	var2 = 0x2<<((var1 & 0x0F) << 1);
	kal_set_eg_events(event_id, var2, KAL_OR);
	return;	
}

static S32 app_frm_signal_valide_int(SIGNAL_ID s_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32                   var1, var2;
	kal_taskid            t_id;
	kal_eventgrpid        event_id;
	U32                   current_mask;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	do
	{
		var1 = ((U32) s_id) & 0x0FFFF;
		if (var1 >= APP_FRM_SIGNAL_MAX)
			break;
		current_mask = signal_free_map[var1>>5];
		if ((current_mask & (0x1 << (var1 & 0x1F))) == 0)
			break;
		t_id = signal_create_task[var1];
		event_id = signal_eg_array[var1>>4];
		var2 = ((U32) s_id)>>16;
		if ((((U32)t_id)& 0x0FFFF) != var2)
		    break;
		return 1;
	} while(0);
	return 0;
}

