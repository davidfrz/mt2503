/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * vmwdt.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   mre watch dog
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
 *
 * removed!
 * removed!
 * removed!
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "vmswitch.h"

#ifdef __MRE_SAL_WDT__
#include "kal_public_api.h"
#include "vmsys.h"
#include "vmwdt.h"
#include "vmlog.h"

#define VM_WDT_COUNT 10

typedef struct
{
    VMUINT8 unused;
}*vm_timerid;

typedef struct
{
	char    name[8];
	VMINT   id;
	vm_timerid timerid;
	VMUINT  used;
	VMUINT  millisec;
}vm_wdt_list_struct;

vm_wdt_list_struct vm_wdt_list[VM_WDT_COUNT] = {
		{"vmwdt0", 0, NULL, 0, 0}, 
		{"vmwdt1", 0, NULL, 0, 0},
		{"vmwdt2", 0, NULL, 0, 0},
		{"vmwdt3", 0, NULL, 0, 0},
		{"vmwdt4", 0, NULL, 0, 0},
		{"vmwdt5", 0, NULL, 0, 0},
		{"vmwdt6", 0, NULL, 0, 0},
		{"vmwdt7", 0, NULL, 0, 0},
		{"vmwdt8", 0, NULL, 0, 0},
		{"vmwdt9", 0, NULL, 0, 0}
};

static void vm_wdt_timerproc(void *param)
{
	MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_WDT_TIME_OUT);
#ifdef __LINKIT_DEV_KIT__
	srv_reboot_normal_start();
#endif
  ASSERT(0);
}

VMINT vm_wdt_start(VMUINT millisec)
{
	int i;
		
	for(i=0; i<VM_WDT_COUNT; i++)
	{

		if(vm_wdt_list[i].used == 0)
			break;
	}

	if(i>=VM_WDT_COUNT)
	{
		MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_WDT_MAX_SIZE);
		return -1;
	}
		
	vm_wdt_list[i].timerid = (vm_timerid)kal_create_timer(vm_wdt_list[i].name);
	vm_wdt_list[i].id = i;
	vm_wdt_list[i].used = 1;
	vm_wdt_list[i].millisec = millisec;
	kal_set_timer((kal_timerid)vm_wdt_list[i].timerid,(kal_timer_func_ptr)vm_wdt_timerproc,(void*)NULL,millisec,0);
	return i;
}

void vm_wdt_feed(VMINT handle)
{
	if(handle >= VM_WDT_COUNT || handle < 0)
	{
		MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_WDT_FEED_ERROR);
		return ;
	}
	
	kal_cancel_timer((kal_timerid)vm_wdt_list[handle].timerid);

	vm_wdt_list[handle].timerid = (vm_timerid)kal_create_timer(vm_wdt_list[handle].name);
	vm_wdt_list[handle].used = 1;

	kal_set_timer((kal_timerid)vm_wdt_list[handle].timerid,(kal_timer_func_ptr)vm_wdt_timerproc,(void*)NULL,vm_wdt_list[handle].millisec,0);
}

void vm_wdt_stop(VMINT handle)
{
	if(handle >= VM_WDT_COUNT || handle < 0)
	{
		MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_WDT_STOP_ERROR);
		return ;
	}
	
	kal_cancel_timer((kal_timerid)vm_wdt_list[handle].timerid);
	vm_wdt_list[handle].timerid = NULL;
	vm_wdt_list[handle].id = 0;
	vm_wdt_list[handle].used = 0;
	vm_wdt_list[handle].millisec = 0;
}

#endif





