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
 *  app_frm_relay_signal.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



/*************************************************************************
 * Include Statements
 *************************************************************************/
#include "app_thread_mutex_gprot.h"
#include "app_frm_thread_gprot.h"
#include "app_thread_mgr.h"



/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MSG_SIGNAL_ACCESS_LOCK           app_frm_mutex_lock(&msg_signal_mutex)
#define MSG_SIGNAL_ACCESS_UNLOCK         app_frm_mutex_unlock(&msg_signal_mutex);
#define MSG_SIGNAL_MAX 32
typedef struct
{
	msg_type msg_id;
	SIGNAL_ID s_id;
	ilm_struct *ilm;
} MSG_SIGNAL_STRUCT;

/***************************************************************************** 
 * Global variable
 *****************************************************************************/
static app_frm_mutex_struct      msg_signal_mutex;
static MSG_SIGNAL_STRUCT         msg_signal_array[MSG_SIGNAL_MAX];
/***************************************************************************** 
 * Function
 *****************************************************************************/
static S32 app_frm_find_signal_msg(msg_type msg_id);
extern void app_frm_relay_msg_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	app_frm_mutex_create(&msg_signal_mutex);
	return;
}

extern void app_frm_wait_msg(msg_type msg_id, ilm_struct *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	SIGNAL_ID msg_signal;
	S32       index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	msg_signal = app_frm_signal_init();
	MSG_SIGNAL_ACCESS_LOCK;
	index = app_frm_find_signal_msg(MSG_ID_INVALID_TYPE);
	ASSERT(index >= 0);
	msg_signal_array[index].ilm = ilm;
	msg_signal_array[index].s_id = msg_signal;
	msg_signal_array[index].msg_id = msg_id;
	MSG_SIGNAL_ACCESS_UNLOCK;
	msg_send(ilm);
	app_frm_signal_wait(msg_signal);
	app_frm_signal_deinit(msg_signal);
}

extern U32 app_frm_msg_signal_handler(ilm_struct *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	SIGNAL_ID msg_signal;
	S32       index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	index = app_frm_find_signal_msg(ilm->msg_id);
	if (index >= 0)
	{
		memcpy(msg_signal_array[index].ilm, ilm, sizeof(ilm_struct));
		msg_signal_array[index].ilm->dest_mod_id = (module_type)0;
		msg_signal = msg_signal_array[index].s_id;
		memset(&msg_signal_array[index], 0x00, sizeof(MSG_SIGNAL_STRUCT));
		app_frm_signal_post(msg_signal);
		return 1;
	}
	else
	{
		return 0;
	}
}


static S32 app_frm_find_signal_msg(msg_type msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = MSG_SIGNAL_MAX - 1; i >= 0 && msg_signal_array[i].msg_id == msg_id; i--);
	return i;
}

