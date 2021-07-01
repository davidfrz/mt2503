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
 *  vmtask.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



/*************************************************************************
* Include Statements
*************************************************************************/
#include "kal_release.h"
#include "kal_public_api.h"
#include "stack_types.h"
#include "syscomp_config.h"
#include "kal_general_types.h"
#include "MMI_mre_app_info_trc.h"
#include "mmi_rp_app_mre_def.h"
#include "vmsys.h"
#include "vmtimer.h"

#ifdef __LINKIT_HIGH_PRIORITY_TASK_SUPPORT__

/***************************************************************************** 
* Declear
*****************************************************************************/
kal_bool vm_task_Init(task_indx_type task_indx);
void vm_task_main(task_entry_struct *entry_param);

#define VM_TIMER_NUMBER 2
#define VM_SIMULTANEOUS_TIMER_NUM  (12)
#define VM_TIMER_INDEX (0x100)

/* ticks of 5 millisecond. because KAL did not define the value. define in floating falue to avoid early rouning */
#define VM_TICKS_5_MSEC  (KAL_TICKS_1_SEC/200.0)

typedef struct {
	kal_uint16 timer_type;
    kal_uint16 timer_id;     /* timer info. */
    eventid event_id;   /* event_id returned from evshed_set_event() */
    vm_timer_func_ptr callback_func;  /* timer_expiry_func */
    void* arg;
}vm_timer_type;


typedef struct vmtimertable
{
    vm_timer_type tm[VM_SIMULTANEOUS_TIMER_NUM];  /* timer items */
    struct vmtimertable *next;    /* point to the next TIMERTABLE data */
}VMTIMERTABLE;

static VMTIMERTABLE g_timer_table = {0};
static kal_uint16 g_timer_table_used = 0;
static event_scheduler *vm_event_scheduler_ptr[VM_TIMER_NUMBER];
static kal_mutexid vm_task_mutex;

static void vm_evshed_timer_init(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	kal_uint32 i;
	kal_uint8 max_delay[VM_TIMER_NUMBER] = {254, 0};
	kal_int8 *timer_name[VM_TIMER_NUMBER] = {"LINKIT_a", "LINKIT_na"};

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	for (i = 0; i<VM_TIMER_NUMBER; i++)
	{
		vm_event_scheduler_ptr[i] = evshed_create(timer_name[i], MOD_LINKIT, 0, max_delay[i]);
		evshed_set_index(vm_event_scheduler_ptr[i], (VM_TIMER_INDEX+i));
	}
}

static void vm_l4_callback_timer(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_timer_type *pTimer = (vm_timer_type *)p;
    kal_uint32 nTimerId = pTimer->timer_id;
    vm_timer_func_ptr pTimerExpiry = pTimer->callback_func;
    void * arg = pTimer->arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//kal_wap_trace(MOD_MRE_APP_LOG,TRACE_GROUP_2, "vm_l4_callback_timer");
	

    if(g_timer_table_used <= 0)
	{
		//kal_wap_trace(MOD_MRE_APP_LOG,TRACE_GROUP_2, "g_timer_table_used <= 0");
		return ;
    }
	
	kal_take_mutex(vm_task_mutex);
    g_timer_table_used--;
	kal_give_mutex(vm_task_mutex);

    memset( pTimer, 0, sizeof(vm_timer_type)); /* clear timer */

    if (pTimerExpiry)
    {
        pTimerExpiry((void *)arg);
    }
	
}

VMBOOL vm_timer_start_high_priority_timer(vm_timer_func_ptr callback,void *userdata,VMUINT32 millisec,VMUINT16 alignment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMTIMERTABLE *pTable = NULL;
    kal_uint16 i = 0;
    kal_uint32 temp = 0, sec = 0, milli_secs = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sec = millisec / 1000;
    milli_secs = millisec % 1000;
	
	//kal_wap_trace(MOD_MRE_APP_LOG,TRACE_GROUP_2, "vm_start_evshed_timer");

    if(sec > 0)
        temp = kal_secs_to_ticks(sec);
    if(milli_secs > 0)
        temp += kal_milli_secs_to_ticks(milli_secs);

    if (temp == 0)
    {
        /* Cause by by rounding. If expire immediately, MoDIS boot-up failure because MMI keeps running and block NVRAM task */
        temp = (kal_uint32)VM_TICKS_5_MSEC;
    }

	kal_take_mutex(vm_task_mutex);

    pTable = &g_timer_table;
    if (g_timer_table_used >= VM_SIMULTANEOUS_TIMER_NUM)
    {
    	// have no resource
		//kal_wap_trace(MOD_MRE_APP_LOG,TRACE_GROUP_2, "have no resource");
		return FALSE;
    }
    else
    {
        /* find the empty record in g_timer_table list */
        i = 0;
        do
        {
            if (pTable->tm[i].event_id == NULL)
            {   /* find the empty space */
				//kal_wap_trace(MOD_MRE_APP_LOG,TRACE_GROUP_2, "find the empty space");
                break;
            }
            i++;
            if (i >= VM_SIMULTANEOUS_TIMER_NUM)
            {
                pTable = pTable->next;
                i = 0;
            }
        } while (pTable != NULL);

        if (pTable == NULL)
        {
            /* Can't find the empty space in TIMERTABLE list, assert!!! */
            //MMI_ASSERT(0);
        }
    }   /* if (g_timer_table_used >= g_timer_table_size) */

	pTable->tm[i].timer_type = alignment;
    pTable->tm[i].timer_id = MRE_SYS_TIMER_99 - i;
    pTable->tm[i].event_id = evshed_set_event(
                                vm_event_scheduler_ptr[alignment],
                                (kal_timer_func_ptr)vm_l4_callback_timer,
                                (void*)&(pTable->tm[i]),
                                temp);
    pTable->tm[i].arg = userdata;
    pTable->tm[i].callback_func = callback;
    g_timer_table_used++;
	
	kal_give_mutex(vm_task_mutex);

	return TRUE;
	
}

kal_bool vm_task_create(comptask_handler_struct **handle)
{
    static comptask_handler_struct vm_handler_info = 
    {
        vm_task_main,     /* task entry function */
        vm_task_Init,     /* task initialization function */
        NULL, 
        NULL,              /* task reset handler */
        NULL,              /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/
    *handle = &vm_handler_info;
    return KAL_TRUE;
	
}

kal_bool vm_task_Init(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return KAL_TRUE;
}

void vm_task_main(task_entry_struct *entry_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	ilm_struct ilm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	vm_evshed_timer_init();

	vm_task_mutex = kal_create_mutex("LinkIt");
	
	while (1)
	{
		msg_receive_extq(&ilm);
		
		if (ilm.msg_id == MSG_ID_TIMER_EXPIRY)
		{
			kal_uint32 i;
			kal_uint16 timer_index = evshed_get_index((ilm_struct*)&ilm);
			
			for (i = 0; i<VM_TIMER_NUMBER; i++)
			{
				if (timer_index == (VM_TIMER_INDEX+i))
				{
					evshed_timer_handler(vm_event_scheduler_ptr[i]);
				}
			}
		}
		destroy_ilm(&ilm);
	}
}

#endif

