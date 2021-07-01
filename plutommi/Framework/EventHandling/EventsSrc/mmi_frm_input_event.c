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
 *  mmi_frm_input_event.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  input event implementation
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
 *
 *
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "MMI_features.h"
#include "GlobalConstants.h"
#include "DebugInitDef_Int.h"

#include "gui.h"

//gpio, sound
#include "gpiosrvgprot.h"
#include "ProfilesSrvGprot.h"
#include "mmi_rp_all_defs.h"


#include "mmi_frm_input_event.h"

#include "BootupSrvGprot.h"
#include "nvram_common_defs.h"
#include "nvram_input_event_const.h"



//#if defined(__MMI_FRM_INPUT_EVT__)

#ifndef __INPUT_EVT_LED_UT__
//#define __INPUT_EVT_LED_UT__
#endif//0

/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

/*****************************************************************************              
 * Extern APIs                                                                    
 *****************************************************************************/



/*****************************************************************************              
 * Local Variable                                                                    
 *****************************************************************************/

//read cfg info from nvram, and cache it to static array
static mmi_input_event_led_notify g_input_event_notify_led_info_tbl[INPUT_EVENT_LED_ID_END];
static mmi_input_event_vib_notify g_input_event_notify_vib_info_tbl[INPUT_EVENT_VIB_IND_END];
static mmi_input_event_aud_notify g_input_event_notify_aud_info_tbl[INPUT_EVENT_MAX_AUD];
static mmi_input_event_notify_info g_mmi_input_event_notify_tbl[NVRAM_EF_NOTIFY_INFO_TOTAL];
static mmi_input_event_evt_info g_input_event_evt_info_tbl[NVRAM_EF_INPUT_EVENT_INFO_TOTAL];
static mmi_input_event_local_app_info g_input_event_local_app_info_tbl[NVRAM_EF_LOCAL_APP_INFO_TOTAL];

static U8 g_mmi_input_event_notify_volume;
//read cfg info
static void mmi_frm_input_event_led_info_initialization(void);
static void mmi_frm_input_event_vib_info_initialization(void);
static void mmi_frm_input_event_aud_info_initialization(void);
static void mmi_frm_input_event_notify_info_initialization(void);
static void mmi_frm_input_event_evt_info_initialization(void);
static void mmi_frm_input_event_local_app_info_initialization(void);
static void mmi_frm_input_event_cfg_info_initialization(void);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (INPUT_EVENT_MAX_LED_NUM == 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif (INPUT_EVENT_MAX_LED_NUM == 1)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0


static U16 g_current_app_indx = 0;

/*
notify
*/
//static U16 g_current_led_id;
//static U16 g_current_led_on_times[INPUT_EVENT_MAX_LED_NUM];
static MMI_BOOL g_input_event_notify_enabled = MMI_TRUE; 


/*led queue*/
__align(32) static U32 g_input_event_led_queue_buffer[INPUT_EVENT_LED_QUEUE_BUFFER_SIZE/4];
static KAL_ADM_ID g_input_event_led_queue_pool_id;



static mmi_input_event_led_queue *g_led_queue;
//log the notify ids of current high proirity leds
static U16 g_top_notify_array[INPUT_EVENT_MAX_LED_NUM];

//log the current led ids in show
static U16 g_current_led_array[INPUT_EVENT_MAX_LED_NUM];

//led0..2 callback array
#if (INPUT_EVENT_MAX_LED_NUM == 1)
static void mmi_frm_input_event_notify_led0_callback(void);
#elif(INPUT_EVENT_MAX_LED_NUM == 2)
static void mmi_frm_input_event_notify_led0_callback(void);
static void mmi_frm_input_event_notify_led1_callback(void);
#elif(INPUT_EVENT_MAX_LED_NUM == 3)
static void mmi_frm_input_event_notify_led0_callback(void);
static void mmi_frm_input_event_notify_led1_callback(void);
static void mmi_frm_input_event_notify_led2_callback(void);
#endif//


static FuncPtr g_input_event_notify_led_callback[INPUT_EVENT_MAX_LED_NUM] =
{
#if (INPUT_EVENT_MAX_LED_NUM == 1)
	mmi_frm_input_event_notify_led0_callback,
#elif(INPUT_EVENT_MAX_LED_NUM == 2)
	mmi_frm_input_event_notify_led0_callback,
	mmi_frm_input_event_notify_led1_callback,
#elif(INPUT_EVENT_MAX_LED_NUM == 3)
	mmi_frm_input_event_notify_led0_callback,
	mmi_frm_input_event_notify_led1_callback,
	mmi_frm_input_event_notify_led2_callback,
#endif
};

//aud
srv_prof_play_tone_callback g_input_event_tone_cb = NULL; 
MMI_BOOL g_input_event_block_aud_cb_execute = MMI_FALSE;

//long press event
static MMI_BOOL g_long_press_input_event = MMI_FALSE;

//input event module init or not
static MMI_BOOL g_input_event_initialized = MMI_FALSE;


#ifdef __INPUT_EVT_UT__
void input_event_test_case5(void);
void input_event_test_case6(void);
void input_event_test_case8(void);
void input_event_test_case9(void);
void input_event_test_case10(void);
void input_event_test_case11(void);

#endif//



/*****************************************************************************              
 * Local Function                                                                    
 *****************************************************************************/
static void mmi_frm_input_event_led_info_initialization(void)
{
	U32 i;
	S16 pError = 0;
	for(i=0; i<INPUT_EVENT_LED_ID_END; i++)
	{
		ReadRecord(
			NVRAM_EF_LED_INFO_LID,
			i+1,
			(void*)&g_input_event_notify_led_info_tbl[i],
			sizeof(mmi_input_event_led_notify),//NVRAM_EF_LED_INFO_SIZE,
			&pError);
		if(pError != NVRAM_READ_SUCCESS)
		{
			//TRC_MMI_FRM_INPUT_EVT_INFO_INIT
			
			MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_INFO_INIT, "LED", i+1, pError);
			MMI_ASSERT(0);
		}
		///TODO: add trace here, pError should be NVRAM_READ_SUCCESS
	}
}
static void mmi_frm_input_event_vib_info_initialization(void)
{
	U32 i;
	S16 pError = 0;
	for(i=0; i<INPUT_EVENT_VIB_IND_END; i++)
	{
		ReadRecord(
			NVRAM_EF_VIB_INFO_LID,
			i+1,
			(void*)&g_input_event_notify_vib_info_tbl[i],
			sizeof(mmi_input_event_vib_notify),//NVRAM_EF_VIB_INFO_SIZE,
			&pError);

		if(pError != NVRAM_READ_SUCCESS)
		{
			//TRC_MMI_FRM_INPUT_EVT_INFO_INIT
			
			MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_INFO_INIT, "VIB", i+1, pError);
			MMI_ASSERT(0);
		}
		///TODO: add trace here, pError should be NVRAM_READ_SUCCESS
	}

}

static void mmi_frm_input_event_aud_info_initialization(void)
{
	U32 i;
	S16 pError = 0;
	for(i=0; i<NVRAM_EF_AUD_INFO_TOTAL; i++)
	{
		ReadRecord(
			NVRAM_EF_AUD_INFO_LID,
			i+1,
			(void*)&g_input_event_notify_aud_info_tbl[i],
			sizeof(mmi_input_event_aud_notify),//NVRAM_EF_VIB_INFO_SIZE,
			&pError);

		if(pError != NVRAM_READ_SUCCESS)
		{
			//TRC_MMI_FRM_INPUT_EVT_INFO_INIT		
			MMI_ASSERT(0);
		}
		///TODO: add trace here, pError should be NVRAM_READ_SUCCESS
	}

}


static void mmi_frm_input_event_notify_info_initialization(void)
{
	U32 i;
	S16 pError = 0;
	for(i=0; i<NVRAM_EF_NOTIFY_INFO_TOTAL; i++)
	{
		ReadRecord(
			NVRAM_EF_NOTIFY_INFO_LID,
			i+1,
			(void*)&g_mmi_input_event_notify_tbl[i],
			sizeof(mmi_input_event_notify_info),//NVRAM_EF_NOTIFY_INFO_SIZE,
			&pError);

		if(pError != NVRAM_READ_SUCCESS)
		{
			//TRC_MMI_FRM_INPUT_EVT_INFO_INIT
			
			MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_INFO_INIT, "NOTIFY", i+1, pError);
			MMI_ASSERT(0);
		}
		///TODO: add trace here, pError should be NVRAM_READ_SUCCESS
	}

}

static void mmi_frm_input_event_evt_info_initialization(void)
{
	U32 i;
	S16 pError = 0;
	for(i=0; i<NVRAM_EF_INPUT_EVENT_INFO_TOTAL; i++)
	{
		ReadRecord(
			NVRAM_EF_INPUT_EVENT_INFO_LID,
			i+1,
			(void*)&g_input_event_evt_info_tbl[i],
			sizeof(mmi_input_event_evt_info),//NVRAM_EF_INPUT_EVENT_INFO_SIZE,
			&pError);

		if(pError != NVRAM_READ_SUCCESS)
		{
			//TRC_MMI_FRM_INPUT_EVT_INFO_INIT
			
			MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_INFO_INIT, "EVT", i+1, pError);
			MMI_ASSERT(0);
		}
		///TODO: add trace here, pError should be NVRAM_READ_SUCCESS
	}

}

static void mmi_frm_input_event_local_app_info_initialization(void)
{
	U32 i;
	S16 pError = 0;
	for(i=0; i<NVRAM_EF_LOCAL_APP_INFO_TOTAL; i++)
	{
		ReadRecord(
			NVRAM_EF_LOCAL_APP_INFO_LID,
			i+1,
			(void*)&g_input_event_local_app_info_tbl[i],
			sizeof(mmi_input_event_local_app_info),//NVRAM_EF_LOCAL_APP_INFO_SIZE,
			&pError);

		if(pError != NVRAM_READ_SUCCESS)
		{
			//TRC_MMI_FRM_INPUT_EVT_INFO_INIT
			
			MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_INFO_INIT, "LOCAL APP", i+1, pError);
			MMI_ASSERT(0);
		}
		kal_prompt_trace(MOD_MMI, "[hugo]local app, index=%d, pError=%d", i+1, pError);
		///TODO: add trace here, pError should be NVRAM_READ_SUCCESS
	}

}

static void mmi_frm_input_event_cfg_info_initialization(void)
{
	S16 error;
	
	mmi_frm_input_event_led_info_initialization();
	mmi_frm_input_event_vib_info_initialization();
	mmi_frm_input_event_aud_info_initialization();
	mmi_frm_input_event_notify_info_initialization();
	mmi_frm_input_event_evt_info_initialization();
	mmi_frm_input_event_local_app_info_initialization();

	//NVRAM_INPUT_EVT_NOTIFY_VOLUME
	ReadValue(NVRAM_INPUT_EVT_NOTIFY_VOLUME, &g_mmi_input_event_notify_volume, DS_BYTE, &error);

	if(g_mmi_input_event_notify_volume>INPUT_EVENT_NOTIFY_VOLUME_MAX)
	{
		g_mmi_input_event_notify_volume=INPUT_EVENT_NOTIFY_VOLUME_MAX;
	}

}

static MMI_BOOL mmi_frm_input_event_is_app_local(U16 app_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	S32 app_num, i;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	app_num = sizeof(g_input_event_local_app_info_tbl)/sizeof(mmi_input_event_local_app_info);

	for(i=0; i< app_num; i++)
	{
		if(g_input_event_local_app_info_tbl[i].app_id == app_id)
			return MMI_TRUE;
	}
	return MMI_FALSE;
}


static MMI_BOOL mmi_frm_input_event_is_curr_app_local(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	S32 app_num, i;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0
	return mmi_frm_input_event_is_app_local(mmi_frm_group_get_active_id());
}


static void mmi_frm_input_event_jump_to_next_app(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	g_current_app_indx = (g_current_app_indx + 1)%INPUT_EVENT_APP_INDX_LOCAL_END;
}

static U16 mmi_frm_input_event_get_current_app_evt(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S32 app_num, i;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	app_num = sizeof(g_input_event_local_app_info_tbl)/sizeof(mmi_input_event_local_app_info);

	for(i = 0; i < app_num; i++)
	{
		if(g_input_event_local_app_info_tbl[i].app_indx == g_current_app_indx)
			return g_input_event_local_app_info_tbl[i].launch_evt_id;
	}

	MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_LAUNCH_EVT_MISSED, g_current_app_indx);

	MMI_ASSERT(0);
	return 0;
}

/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_update_curr_app_index
* DESCRIPTION
*  update current app index.
* PARAMETERS
*  notify_id
*  led_id
*  aud_id
*  vib_id
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_input_event_update_curr_app_index(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    S32 app_num, i;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	
	app_num = sizeof(g_input_event_local_app_info_tbl)/sizeof(mmi_input_event_local_app_info);

	for(i = 0; i < app_num; i++)
	{
		if(g_input_event_local_app_info_tbl[i].app_id == mmi_frm_group_get_active_id())
		{
			g_current_app_indx = g_input_event_local_app_info_tbl[i].app_indx;
			break;
		}
	}		
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_query_notify_info
* DESCRIPTION
*  query the detail info of the notify.
* PARAMETERS
*  notify_id
*  led_id
*  aud_id
*  vib_id
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_input_event_query_notify_info(
				U16 notify_id, 
				U16 *led_id, 
				U16 *aud_id, 
				U16 *vib_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    S32 i, sz;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if(notify_id == 0)
	{
		*led_id = 0;
		*aud_id = 0;
		*vib_id = 0;	
		return;
	}

    sz = sizeof(g_mmi_input_event_notify_tbl)/sizeof(mmi_input_event_notify_info);
		
	for(i = 0; i < sz; i++)
	{
		if(g_mmi_input_event_notify_tbl[i].notify_id == notify_id)
		{
			*led_id = g_mmi_input_event_notify_tbl[i].led_indx;
			*aud_id = g_mmi_input_event_notify_tbl[i].voi_id;
			*vib_id = g_mmi_input_event_notify_tbl[i].vib_indx;
			return;
		}
	}
	MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_NOTIFY_ID_UNDEFINED, notify_id);

	MMI_ASSERT(0);//invalid notify id
	
}

//led queue
/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_led_queue_initr
* DESCRIPTION
*  init led queue
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_input_event_led_queue_init(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	g_input_event_led_queue_pool_id = kal_adm_create(
										(void*)g_input_event_led_queue_buffer,
										(kal_uint32) INPUT_EVENT_LED_QUEUE_BUFFER_SIZE,
										NULL,
										KAL_FALSE);
	if(g_input_event_led_queue_pool_id == NULL)
	{
		MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_NOTIFY_LED_QUEUE_INIT_FAIL);
		ASSERT(g_input_event_led_queue_pool_id != NULL);
	}
	
	
	//g_led_queue = (mmi_input_event_led_queue*)mmi_frm_scrmem_alloc_framebuffer(sizeof(mmi_input_event_led_queue));

	g_led_queue =  (mmi_input_event_led_queue*)(U8*) kal_adm_alloc(
														g_input_event_led_queue_pool_id,
														sizeof(mmi_input_event_led_queue));
	memset(g_led_queue, 0, sizeof(g_led_queue));
	g_led_queue->next = NULL;
}

/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_led_queue_add
* DESCRIPTION
*  init led queue
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_input_event_led_queue_add(U16 notify_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	mmi_input_event_led_queue *tmp;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	
    //tmp = (mmi_input_event_led_queue*)mmi_frm_scrmem_alloc_framebuffer(sizeof(mmi_input_event_led_queue));
	tmp = (mmi_input_event_led_queue*)(U8*) kal_adm_alloc(
												g_input_event_led_queue_pool_id,
												sizeof(mmi_input_event_led_queue));

/*queue not bigger enough or too many flagments, please
*  try to enlarge INPUT_EVENT_LED_QUEUE_BUFFER_SIZE 
*/
	if(tmp == NULL)
		MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_NOTIFY_LED_QUEUE_NOT_ENOUGH);

	MMI_ASSERT(tmp != NULL);	
	
	memset(tmp, 0, sizeof(tmp));
	tmp->notify_id = notify_id;
	tmp->next = NULL;

	//insert from the header
	tmp->next = g_led_queue->next;
	g_led_queue->next = tmp;

}

/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_led_queue_remove
* DESCRIPTION
*  init led queue
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_input_event_led_queue_remove(U16 notify_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	mmi_input_event_led_queue *head, *tmp;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	head = g_led_queue;
	
	while(g_led_queue->next != NULL)
	{
		if(g_led_queue->next->notify_id == notify_id)
		{
			//remove
			tmp = g_led_queue->next;
			g_led_queue->next = g_led_queue->next->next;

			//mmi_frm_scrmem_free(tmp);
			kal_adm_free(
				g_input_event_led_queue_pool_id, 
				tmp);
			
			g_led_queue = head;

			return;
		}
		else
		{
			g_led_queue = g_led_queue->next;
		}
	}

	g_led_queue = head;
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_led_queue_empty
* DESCRIPTION
*  init led queue
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL mmi_frm_input_event_is_led_queue_empty(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	if(g_led_queue->next == NULL)
	{
		return MMI_TRUE;
	}
	else
	{
		return MMI_FALSE;
	}

}

/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_pop_highest_led_in_queue
* DESCRIPTION
*  pop led queue
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static U16 mmi_frm_input_event_pop_highest_led_in_queue(U16 led_indx)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	mmi_input_event_led_queue *head;//, *tmp;
	U16 notify_id, led_id, led_id_next, aud_id, vib_id;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	head = g_led_queue;

	if(g_led_queue->next != NULL)
	{
		notify_id = g_led_queue->next->notify_id;
		g_led_queue = g_led_queue->next;
	}
	else
	{
		///TODO:
		return 0;
	}
	
	while(g_led_queue->next != NULL)
	{
			//get notify detail info
		mmi_frm_input_event_query_notify_info(
			notify_id, 
			&led_id,
			&aud_id,
			&vib_id);	
		mmi_frm_input_event_query_notify_info(
			g_led_queue->next->notify_id, 
			&led_id_next,
			&aud_id,
			&vib_id);
		
		if(g_input_event_notify_led_info_tbl[led_id].items[led_indx].color == INPUT_EVENT_DIM_LED)
		{
			notify_id = g_led_queue->next->notify_id;
		}
		else if(g_input_event_notify_led_info_tbl[led_id_next].items[led_indx].color != INPUT_EVENT_DIM_LED &&
			(g_input_event_notify_led_info_tbl[led_id].priority <
			g_input_event_notify_led_info_tbl[led_id_next].priority))
		{
			notify_id = g_led_queue->next->notify_id;
		}
		
		g_led_queue = g_led_queue->next;
	}

	g_led_queue = head;
	
	//fix when led3 shows none			
	mmi_frm_input_event_query_notify_info(
		notify_id, 
		&led_id,
		&aud_id,
		&vib_id);	
	if(g_input_event_notify_led_info_tbl[led_id].items[led_indx].color == INPUT_EVENT_DIM_LED)
		return 0;
		
	mmi_frm_input_event_led_queue_remove(notify_id);
	return notify_id;
}

/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_notify_in_queue
* DESCRIPTION
*  check notify whether in queue
* PARAMETERS
*  notify id
* RETURNS
*  MMI_BOOL
*****************************************************************************/
static MMI_BOOL mmi_frm_input_event_notify_in_queue(U16 notify_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	mmi_input_event_led_queue*head;//, *tmp;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	head = g_led_queue;
	
	while(g_led_queue->next != NULL)
	{
		if(g_led_queue->next->notify_id == notify_id)
		{			
			g_led_queue = head;
			return MMI_TRUE;
		}
		else
		{
			g_led_queue = g_led_queue->next;
		}
	}

	g_led_queue = head;

	return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_get_highest_in_top
* DESCRIPTION
*  get next highest notify id after removed highest notify id
* PARAMETERS
*  notify led index
* RETURNS
*  notify id
*****************************************************************************/
static U16 mmi_frm_input_event_get_highest_in_top(U16 led_index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U32 i;
	U16 notify_id_to_removed;
	U16 highest_notify_id = 0;
	U16 led_id, led_highest, aud_id, vib_id;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	notify_id_to_removed = g_top_notify_array[led_index];
	
	for(i = 0; i < INPUT_EVENT_MAX_LED_NUM; i++)
	{
		U16 notify_id = g_top_notify_array[i];
		
		if(notify_id != notify_id_to_removed)
		{
			mmi_frm_input_event_query_notify_info(
				highest_notify_id, 
				&led_highest,
				&aud_id,
				&vib_id);
			
			mmi_frm_input_event_query_notify_info(
				notify_id, 
				&led_id,
				&aud_id,
				&vib_id);
			
			if(g_input_event_notify_led_info_tbl[led_id].items[led_index].color != INPUT_EVENT_DIM_LED &&
				g_input_event_notify_led_info_tbl[led_id].priority > g_input_event_notify_led_info_tbl[led_highest].priority)		
			{
				highest_notify_id = notify_id;
			}

		}
	}

	return highest_notify_id;
}



//end queue

/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_notify_led_callback_helper
* DESCRIPTION
*  led callback helper
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_input_event_notify_led_callback_helper(U32 led_indx)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U16 led_id;
	mmi_input_event_led_item item;
	U8 led_color = 255;//invalid
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
 	led_id = g_current_led_array[led_indx];
	item = g_input_event_notify_led_info_tbl[led_id].items[led_indx];

///TODO: need switch to led index, not SUPPORT now!!!
	if(led_indx > 0)
	{
		return;
	}
	
#if defined(__MTK_TARGET__)

//every led group has three led pins, one shows red, one shows green, and the other shows blue
//need to close all led when show a color

	srv_gpio_control_led(
		ALL_LED, 
		LED_CMD_DIMMING,
		0,
		0);

	if(item.color == INPUT_EVENT_DIM_LED)
	{
		//do nothing
	}
	else
	{
		if(item.color == INPUT_EVENT_RED_LED)
		{
			led_color = RED_LED;
		}
		else if(item.color == INPUT_EVENT_GREEN_LED)
		{
			led_color = GREEN_LED;
		}
		else if(item.color == INPUT_EVENT_BLUE_LED)
		{
			led_color = BLUE_LED;
		}
		else if(item.color == INPUT_EVENT_YELLOW_LED)
		{
			led_color = YELLOW_LED;
		}
		else if(item.color == INPUT_EVENT_PURPLE_LED)
		{
			led_color = PURPLE_LED;
		}
		else if(item.color == INPUT_EVENT_AZURE_LED)
		{
			led_color = AZURE_LED;
		}

		if(led_color != 255)
		{
			srv_gpio_control_led(
				led_color, 
				((item.off_time == 0)?LED_CMD_BRIGHTING:LED_CMD_FLICKER),
				item.on_time * INPUT_EVENT_LED_UNITS,
				item.off_time* INPUT_EVENT_LED_UNITS);
		}
		else
		{
			MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_NOTIFY_LED_COLOR_INVALID, led_id);
		
			MMI_ASSERT(0);
		}
		
	}

#endif/*#if defined(__MTK_TARGET__)*/	
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_notify_led0_callback
* DESCRIPTION
*  led0 callback
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_input_event_notify_led0_callback(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mmi_frm_input_event_notify_led_callback_helper(0);

}

#if (INPUT_EVENT_MAX_LED_NUM > 1)
/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_notify_led1_callback
* DESCRIPTION
*  led1 callback
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_input_event_notify_led1_callback(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
 	//g_current_led_array[1]
	mmi_frm_input_event_notify_led_callback_helper(1);
}
#endif

#if (INPUT_EVENT_MAX_LED_NUM > 2)
/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_notify_led2_callback
* DESCRIPTION
*  led2 callback
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_input_event_notify_led2_callback(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
 	//g_current_led_array[2]
 	mmi_frm_input_event_notify_led_callback_helper(2);
	
}
#endif//


/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_close_led_item
* DESCRIPTION
*  close led led_indx
* PARAMETERS
*
*  led_indx, index in all leds
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_input_event_close_led_item(
				U16 led_id,
				U32 led_indx)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	//reset current show led ids
	g_current_led_array[led_indx] = 0;

///TODO: add trace here..
	///TODO:  switch led control to led_indx
#if defined(__MTK_TARGET__)

	srv_gpio_control_led(
			ALL_LED, 
			LED_CMD_DIMMING,
			0,
			0);
#endif/*#if defined(__MTK_TARGET__)*/	
}



/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_show_led_item
* DESCRIPTION
*  led callback helper
* PARAMETERS
*  led_id,    identify of led info
*  led_indx, index in all leds
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_input_event_show_led_item(
				U16 led_id,
				U32 led_indx)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if(led_indx >= INPUT_EVENT_MAX_LED_NUM)
	{
		MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_NOTIFY_LED_INDEX_INVALID, led_indx);
		MMI_ASSERT(led_indx >= 0 && led_indx < INPUT_EVENT_MAX_LED_NUM);
	}	
//backup current show led ids
	g_current_led_array[led_indx] = led_id;
//delay
	StartTimer(
		INPUT_EVENT_LED0_TIMER + led_indx,
		g_input_event_notify_led_info_tbl[led_id].items[led_indx].delay * INPUT_EVENT_LED_UNITS,
		g_input_event_notify_led_callback[led_indx]);

}

/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_stop_all_led_flashing
* DESCRIPTION
*  stop all led timer
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_input_event_stop_all_led_flash(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S32 i;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	for(i = 0; i < INPUT_EVENT_MAX_LED_NUM; i++)
	{
		StopTimer(INPUT_EVENT_LED0_TIMER + i);
	}

	StopTimer(INPUT_EVENT_LED_TIMER);
	
}

/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_proc_current_led_cntx
* DESCRIPTION
*  proc the led in top arrary
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_input_event_proc_current_led_cntx(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S32 i;
	U16 led_id, aud_id, vib_id;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	mmi_frm_input_event_stop_all_led_flash();

	//proc led in top array one by one
	
	for(i = 0; i < INPUT_EVENT_MAX_LED_NUM; i++)
	{
	
		if(g_top_notify_array[i] == 0)//dummy
		{
			mmi_frm_input_event_close_led_item(0, i);

			continue;
		}
		
		//get notify detail info
		mmi_frm_input_event_query_notify_info(
					g_top_notify_array[i], 
					&led_id,
					&aud_id,
					&vib_id);

		MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_NOTIFY_LED_LONG, g_top_notify_array[i]);
		
		mmi_frm_input_event_show_led_item(
			led_id,
			i);	
	}
	   
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_get_flash_led_duration
* DESCRIPTION
*  get the duration of led_id
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static U32 mmi_frm_input_event_get_flash_led_duration(U16 led_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S32 i;
	U32 max_duration = 0;
	U32 item_duration = 0;
	mmi_input_event_led_item item;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
   	for(i = 0; i < INPUT_EVENT_MAX_LED_NUM; i++)
   	{
   		item = g_input_event_notify_led_info_tbl[led_id].items[i];
		item_duration = item.delay + 
						(item.on_time + item.off_time)*item.repeat_times;

		if(item_duration > max_duration)
		{
			max_duration = item_duration;
		}
	}

	return max_duration * INPUT_EVENT_LED_UNITS;
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_get_flash_led_duration
* DESCRIPTION
*  get the duration of led_id
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_input_event_flash_led_hdlr_completed(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U32 i;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	for(i = 0; i < INPUT_EVENT_MAX_LED_NUM; i++)
	{	
		mmi_frm_input_event_close_led_item(0, i);
	}
	
   mmi_frm_input_event_proc_current_led_cntx();
}



/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_notify_exits
* DESCRIPTION
*  check notify whether exists(in queue or in top array)
* PARAMETERS
*  notify id
* RETURNS
*  MMI_BOOL
*****************************************************************************/
static MMI_BOOL mmi_frm_input_event_notify_existed(U16 notify_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S32 i;
	MMI_BOOL existed;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	existed = mmi_frm_input_event_notify_in_queue(notify_id);

	for(i = 0; i < INPUT_EVENT_MAX_LED_NUM; i++)
   	{
  		if(g_top_notify_array[i] == notify_id)
			existed = MMI_TRUE;
	}

	return existed;
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_led_notify_hdlr
* DESCRIPTION
*  led notify hdlr.
* PARAMETERS
*  led_id
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_input_event_led_notify_hdlr(U16 notify_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 led_id, top_led_id, top_aud_id, top_vib_id;
#ifndef __HUGO__
    mmi_input_event_led_queue *head, *tmp;
#endif /* __HUGO__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // LED Queue Dump
#ifndef __HUGO__
    i = 0;
    mmi_frm_input_event_query_notify_info(
        notify_id, 
        &led_id,
        &top_aud_id,
        &top_vib_id);
    kal_prompt_trace(MOD_MMI, "HUGO New LED,notify_id=%d,led_id=%d,priority=%d", 
        notify_id, led_id, g_input_event_notify_led_info_tbl[led_id].priority);
    
    head = g_led_queue;
    while(g_led_queue->next != NULL)
    {
        mmi_frm_input_event_query_notify_info(
            g_led_queue->next->notify_id,
            &led_id,
            &top_aud_id,
            &top_vib_id);

        kal_prompt_trace(MOD_MMI, "HUGO LED Queue %d,notify_id=%d,led_id=%d,priority=%d", 
            i,
            g_led_queue->next->notify_id,
            top_led_id,
            g_input_event_notify_led_info_tbl[top_led_id].priority);
        
        i++;
        g_led_queue = g_led_queue->next;
    }
    g_led_queue = head;

    for(i = 0; i < INPUT_EVENT_MAX_LED_NUM; i++)
    {
        mmi_frm_input_event_query_notify_info(
            g_top_notify_array[i], 
            &top_led_id,
            &top_aud_id,
            &top_vib_id);

        kal_prompt_trace(MOD_MMI, "HUGO Notify Queue %d,notify_id=%d,led_id=%d,priority=%d", 
            i,
            g_top_notify_array[i],
            top_led_id,
            g_input_event_notify_led_info_tbl[top_led_id].priority);
    }                
#endif /* __HUGO__ */

#ifdef __INPUT_EVT_LED_UT__
	return;
#endif/*__INPUT_EVT_LED_UT__*/

    //get notify detail info
    mmi_frm_input_event_query_notify_info(notify_id, &led_id, &top_aud_id, &top_vib_id);

    //check whether led is dummy
    if(led_id == INPUT_EVENT_LED_ID_DUMMY)
        return;
    
    if(g_input_event_notify_led_info_tbl[led_id].priority == INPUT_EVENT_LED_SHORT_FLASH)
    {
        ///
        MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_NOTIFY_LED_FLASH, notify_id);

        //flash
        for(i = 0; i < INPUT_EVENT_MAX_LED_NUM; i++)
        {
            //led0, led1, led2
            if(g_input_event_notify_led_info_tbl[led_id].items[i].color == INPUT_EVENT_DIM_LED)
            {//not show this led in flash
                // play top[i] in top array
                mmi_frm_input_event_query_notify_info(
                    g_top_notify_array[i], 
                    &top_led_id,
                    &top_aud_id,
                    &top_vib_id);
                mmi_frm_input_event_show_led_item(top_led_id, i); 
            }
            else
            {
                //play g_input_event_notify_led_info_tbl[led_id].items[i]
                mmi_frm_input_event_show_led_item(led_id, i); 
            }
        }

        //get the total length of flash, start timer to resume

        //timeout resume, play current led
        StartTimer(
            INPUT_EVENT_LED_TIMER,
            mmi_frm_input_event_get_flash_led_duration(led_id),
            mmi_frm_input_event_flash_led_hdlr_completed);
    }
    else if(mmi_frm_input_event_notify_existed(notify_id))
    {//always on and exist in queue, don't add to queue
        MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_NOTIFY_LED_EXISTED, notify_id);
        mmi_frm_input_event_proc_current_led_cntx();
    }
    else//always on
    {
        MMI_BOOL need_add_incoming_notify_to_queue = MMI_TRUE;

        //find
        for(i = 0; i < INPUT_EVENT_MAX_LED_NUM; i++)
        {
            //led0..2
            if(g_input_event_notify_led_info_tbl[led_id].items[i].color != INPUT_EVENT_DIM_LED)
            {
                MMI_BOOL need_add_top_to_queue = MMI_TRUE;

                //get notify detail info
                mmi_frm_input_event_query_notify_info(
                    g_top_notify_array[i], 
                    &top_led_id,
                    &top_aud_id,
                    &top_vib_id);

                //play g_input_event_notify_led_info_tbl[led_id].items[i]
                if(g_input_event_notify_led_info_tbl[led_id].priority >=
                    g_input_event_notify_led_info_tbl[top_led_id].priority)
                {
                    //
                    S32 j;
                    for(j = 1; j < INPUT_EVENT_MAX_LED_NUM; j++)
                    {
                        if(g_top_notify_array[i] == 
                            g_top_notify_array[(i + j)%INPUT_EVENT_MAX_LED_NUM])
                        {
                            need_add_top_to_queue = MMI_FALSE;
                        }
                    }
                    if(need_add_top_to_queue && 
                       (g_top_notify_array[i] != INPUT_EVENT_LED_ID_DUMMY))
                    {
                        MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_NOTIFY_LED_TOP_TO_Q, notify_id);
                        //add
                        mmi_frm_input_event_led_queue_add(g_top_notify_array[i]);
                    }
                    g_top_notify_array[i] = notify_id;
                    need_add_incoming_notify_to_queue = MMI_FALSE;
                }
            }
        }

        if(need_add_incoming_notify_to_queue)
        {
            MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_NOTIFY_LED_ADD_TO_Q, notify_id);
            mmi_frm_input_event_led_queue_add(notify_id);
        }

        //play current led
        mmi_frm_input_event_proc_current_led_cntx();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_aud_notify_hdlr_cb
* DESCRIPTION
*  aud notify hdlr callback.
* PARAMETERS
*  aud_id
* RETURNS
*  void
*****************************************************************************/
static srv_prof_ret mmi_frm_input_event_aud_notify_hdlr_cb(srv_prof_ret ret)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0	
	mdi_audio_resume_background_play();

	return 0;
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_aud_notify_hdlr_cb
* DESCRIPTION
*  aud notify hdlr callback.
* PARAMETERS
*  aud_id
* RETURNS
*  void
*****************************************************************************/
static U8* mmi_frm_input_event_get_aud_path(U16 aud_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    U32 i;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	for(i = 0; i < NVRAM_EF_AUD_INFO_TOTAL; i++)
	{
		if(g_input_event_notify_aud_info_tbl[i].aud_id == aud_id)
			return g_input_event_notify_aud_info_tbl[i].path;
	}
	
	return NULL;
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_aud_notify_hdlr
* DESCRIPTION
*  aud notify hdlr.
* PARAMETERS
*  aud_id
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_input_event_aud_notify_hdlr(U16 aud_id, void *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_prof_ret  ret;
	mmi_input_event_notify_param *pa = (mmi_input_event_notify_param*)param;
	U8 *temp_file = NULL;
	U16 filepath[MMI_AUD_PATH_MAX_LEN];
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//
	if(pa&&pa->aud_cb)
	{
		g_input_event_tone_cb = pa->aud_cb;
	}	
	else
	{
		g_input_event_tone_cb = mmi_frm_input_event_aud_notify_hdlr_cb;
	}
	
	temp_file = mmi_frm_input_event_get_aud_path(aud_id);

		//
	mmi_asc_n_to_ucs2(
		(CHAR*)filepath, 
		(CHAR*)temp_file,
		MMI_AUD_PATH_MAX_LEN);
	if(aud_id == AUD_ID_INPUT_EVT_DUMMY)
	{
		//won't play empty audio
		ret = SRV_PROF_RET_NOT_PLAY;
	}
	else if(filepath && (FS_GetAttributes((PU16)filepath) >= 0))
	{	
		ret = mdi_audio_play_file(
                filepath,
                DEVICE_AUDIO_PLAY_ONCE,
                NULL,
                g_input_event_tone_cb,
                NULL);
		//mdi_
		mdi_audio_set_volume(MDI_VOLUME_MEDIA, (U8)(MDI_AUD_VOL_EX_MUTE(g_mmi_input_event_notify_volume)));
	}	
	else	
	{
		ret = srv_prof_play_tone_with_id(
				SRV_PROF_TONE_INCOMING_CALL,
				aud_id,
				SRV_PROF_RING_TYPE_ONCE,
				g_input_event_tone_cb);//mmi_frm_input_event_aud_notify_hdlr_cb
		//mdi_
		mdi_audio_set_volume(MDI_VOLUME_MEDIA, (U8)(MDI_AUD_VOL_EX_MUTE(g_mmi_input_event_notify_volume)));		
	}
	
	MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_NOTIFY_AUD, aud_id, g_input_event_tone_cb, ret);

	/*
	TO execute callback registered for AUDIO in APP when audio play failed
	*/
	if(ret != SRV_PROF_RET_SUCCESS && g_input_event_tone_cb)
	{
		srv_prof_ret result = -1;
		result = (*g_input_event_tone_cb)(ret);
	}
	
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_vib_notify_hdlr
* DESCRIPTION
*  vibrate notify hdlr.
* PARAMETERS
*  vib_id
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_input_event_vib_notify_callback(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    //S32 i, sz;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	srv_vibrator_off();//just for test
	
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_vib_notify_hdlr
* DESCRIPTION
*  vibrate notify hdlr.
* PARAMETERS
*  vib_id
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_input_event_vib_notify_hdlr(U16 vib_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
   // S32 i, sz;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	StartTimer(
		INPUT_EVENT_VIB_TIMER,
		g_input_event_notify_vib_info_tbl[vib_id].duration * INPUT_EVENT_VIB_UNITS, 
		mmi_frm_input_event_vib_notify_callback);

	srv_vibrator_on();
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_notify_valid
* DESCRIPTION
*  check notify id valid or not.
* PARAMETERS
*  notify_id
* RETURNS
*  MMI_BOOL
*****************************************************************************/
static MMI_BOOL mmi_frm_input_event_notify_valid(U16 notify_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    S32 i, sz;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	sz = sizeof(g_mmi_input_event_notify_tbl)/sizeof(mmi_input_event_notify_info);

	for(i = 0; i < sz; i++)
	{
		if(g_mmi_input_event_notify_tbl[i].notify_id == notify_id)
		{
			return MMI_TRUE;
		}	
	}

///TODO: add trace here..
	return MMI_FALSE;
}



/*****************************************************************************              
 * Export Function                                                                    
 *****************************************************************************/
/*
Internal interface for framework
*/

/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_init
* DESCRIPTION
*  init when device bootup
* PARAMETERS
*  void   
* RETURNS
*  void
*****************************************************************************/
void mmi_frm_input_event_init(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
    S32 i;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if(g_input_event_initialized)
		return;
	mmi_frm_input_event_cfg_info_initialization();

#if defined(__MTK_TARGET__)	
//led(led should be init when brigting)
	for(i = 0; i < INPUT_EVENT_MAX_LED_NUM; i++)
	{
///TODO: switch to led0..2	
		srv_gpio_control_led(
			ALL_LED, 
			LED_CMD_INIT,
			0,
			0);
	}
#endif/*#if defined(__MTK_TARGET__)*/
	mmi_frm_input_event_led_queue_init();

	g_input_event_initialized = MMI_TRUE;
	
}

/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_notify_stop
* DESCRIPTION
*  init when device bootup
* PARAMETERS
*  void   
* RETURNS
*  void
*****************************************************************************/
void mmi_frm_input_event_notify_stop(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
    //S32 i, sz;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_NOTIFY_STOP);
/*
aud
*/
	
//	mdi_audio_stop_all();

/*
vibrate
*/
	srv_vibrator_off();
}

/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_is_common_evt
* DESCRIPTION
*  check the event is common or not
* PARAMETERS
*  evt_id  
* RETURNS
*  MMI_BOOL
*****************************************************************************/
static MMI_BOOL mmi_frm_input_event_is_common_evt(U16 evt_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if(evt_id < EVT_ID_SCENARIO_MAX && evt_id > GLOBAL_BASE)
	{
		return MMI_TRUE;
	}	
	else
	{
		return MMI_FALSE;
	}	
}

/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_is_local_evt
* DESCRIPTION
*  check the event is for local or not
* PARAMETERS
*  evt_id  
* RETURNS
*  MMI_BOOL
*****************************************************************************/
static MMI_BOOL mmi_frm_input_event_is_local_evt(U16 evt_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if(evt_id < EVT_ID_INPUT_EVENT_LOCAL_END && evt_id > EVT_ID_INPUT_EVENT_LOCAL_START)
	{
		return MMI_TRUE;
	}	
	else
	{
		return MMI_FALSE;
	}	
}

/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_is_bt_evt
* DESCRIPTION
*  check the event is for bt only or not
* PARAMETERS
*  evt_id  
* RETURNS
*  MMI_BOOL
*****************************************************************************/
static MMI_BOOL mmi_frm_input_event_is_bt_only_evt(U16 evt_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if(evt_id < EVT_ID_BTB_END && evt_id > EVT_ID_BTB_START)
	{
		return MMI_TRUE;
	}	
	else
	{
		return MMI_FALSE;
	}	
}

/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_is_evt_for_all
* DESCRIPTION
*  check the event is for bt only or not
* PARAMETERS
*  evt_id  
* RETURNS
*  MMI_BOOL
*****************************************************************************/
static MMI_BOOL mmi_frm_input_event_is_evt_for_all(U16 evt_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if(evt_id < EVT_ID_INPUT_EVENT_COMMON_END && evt_id > EVT_ID_INPUT_EVENT_COMMON_START)
	{
		return MMI_TRUE;
	}	
	else
	{
		return MMI_FALSE;
	}	
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_chk_evt_info_tbl
* DESCRIPTION
*  check the evt info,.
* PARAMETERS
*  void  
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_input_event_chk_evt_info_tbl(mmi_input_event_evt_info *info_tbl, U32 sz)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U32 i, j;
	//U32 sz;

	S16 key_code, key_type;
    U16 appid; 
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	//sz = sizeof(info_tbl)/sizeof(mmi_input_event_evt_info);

	/*rule: 
	1. (key_code, key_type) used for common evt, should not be used for any app
       2. (key_code, key_type) should not be used for two evts in the same app
	*/
    for(i = 0; i < sz; i++)
    {
    
    	key_code = info_tbl[i].key_code;
		key_type = info_tbl[i].key_type;
		appid    = info_tbl[i].app_id;
		//skip invalid 
		if(key_code == -1 || key_type == -1) 
		{
			continue;
		}
///TODO: add trace here
		
		for(j = i + 1; j < sz; j++)
		{
			if(key_code == info_tbl[j].key_code &&
				key_type == info_tbl[j].key_type)
			{
			/*
			evt config invalid!!!!
			*/
							
				if(mmi_frm_input_event_is_common_evt(info_tbl[i].evt_id)||
					mmi_frm_input_event_is_common_evt(info_tbl[j].evt_id))
				{//common event config times
//            			tst_sysfatal_trace((kal_uint8*)err_info_str);
					/*
						common local event can't be configure in any local app
					*/
					if(mmi_frm_input_event_is_local_evt(info_tbl[i].evt_id) && mmi_frm_input_event_is_app_local(info_tbl[j].app_id) ||
						mmi_frm_input_event_is_local_evt(info_tbl[j].evt_id) && mmi_frm_input_event_is_app_local(info_tbl[i].app_id))
					{
						MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_CONFLICT_WITH_COM_EVENT, key_code, key_type);
						MMI_ASSERT(0);	
					}
					//common event for bt only should not be configured in bt app
					else if(mmi_frm_input_event_is_bt_only_evt(info_tbl[i].evt_id)&& !mmi_frm_input_event_is_app_local(info_tbl[j].app_id) ||
						mmi_frm_input_event_is_bt_only_evt(info_tbl[j].evt_id)&& !mmi_frm_input_event_is_app_local(info_tbl[i].app_id))
					{
						MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_CONFLICT_WITH_COM_EVENT, key_code, key_type);
						MMI_ASSERT(0);
					}
					//event for all should be unique
					else if(mmi_frm_input_event_is_evt_for_all(info_tbl[i].evt_id)||
						mmi_frm_input_event_is_evt_for_all(info_tbl[j].evt_id))
					{
						MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_CONFLICT_WITH_COM_EVENT, key_code, key_type);
						MMI_ASSERT(0);
					}
						
				}
				else if(appid == info_tbl[j].app_id)
				{//in one app config twice
					
					MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_CONFLICT_IN_ONE_APP, appid, key_code, key_type);
					
					MMI_ASSERT(0);
				}

			}
		}
	}

}

/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_chk_app_info_tbl
* DESCRIPTION
*  check the evt info,.
* PARAMETERS
*  void  
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_input_event_chk_app_info_tbl(mmi_input_event_local_app_info *info_tbl, U32 sz)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U32 i, j;
	//U32 sz;
	MMI_BOOL find = MMI_TRUE;
	MMI_BOOL chk_evt_completed = MMI_FALSE;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	for(i = 0; i < INPUT_EVENT_APP_INDX_LOCAL_END; i++)
	{
		find = MMI_FALSE;
		
		for(j = 0; j < sz; j++)
		{
		/*
		rule:
		1. every local app index in mmi_input_event_app_indx_enum should
		    have one item info in local app cfg table
		 the range of local app launch evt should be in (GLOBAL_BASE, EVT_ID_SCENARIO_MAX)
		 evt_id<EVT_ID_SCENARIO_MAX && evt_id>GLOBAL_BASE
		*/
			if(!chk_evt_completed)
			{	
				if(!mmi_frm_input_event_is_common_evt(info_tbl[j].launch_evt_id))
			
				{
					MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_LAUNCH_EVT_CONFIG_INVALID, info_tbl[j].app_id);
						
					MMI_ASSERT(0);
				}

			}

			if(info_tbl[j].app_indx == i)
			{
				find = MMI_TRUE;
				break;
			}

		}

		chk_evt_completed = MMI_TRUE;
		
		if(!find)
		{
			MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_APP_INFO_MISSED, i);
/*
please MAKE SURE that every item in mmi_input_event_app_indx_enum
should have one item in g_input_event_local_app_info_tbl
*/		
			MMI_ASSERT(0);
		}

	}

}


/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_check_led_info_tbl
* DESCRIPTION
*  check the led info,.
* PARAMETERS
*  void  
* RETURNS
*  void
*****************************************************************************/
void mmi_frm_input_event_check_led_info_tbl(mmi_input_event_led_notify *info_tbl, U32 led_num)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	//U32 led_num;
	U32 i;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	/*
	please CHECK the enum table mmi_input_event_led_enum and the led info table
	the size of info tbl SHOULD be INPUT_EVENT_LED_ID_END
	*/	
	if(led_num != INPUT_EVENT_LED_ID_END)
	{
		MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_NOTIFY_LED_SIZE_INVALID, INPUT_EVENT_LED_ID_END);
		MMI_ASSERT(led_num == INPUT_EVENT_LED_ID_END);
	}

	
	for(i = 0; i < led_num; i++)
	{
	///TODO: add trace here

	/*
	NOTICE: the led in info table SHOULD be from 0 to INPUT_EVENT_LED_ID_END-1
	*/	if(info_tbl[i].led_id != i)
		{
			MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_NOTIFY_LED_TBL_OUT_OF_ORDER, info_tbl[i].led_id, i);
	
			MMI_ASSERT(info_tbl[i].led_id == i);
		}	
	}
		
}

/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_check_vib_info_tbl
* DESCRIPTION
*  check the vib info,.
* PARAMETERS
*  void  
* RETURNS
*  void
*****************************************************************************/
void mmi_frm_input_event_check_vib_info_tbl(mmi_input_event_vib_notify *info_tbl, U32 vib_num)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	//U32 vib_num;
	U32 i;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	/*
	please CHECK the enum table mmi_input_event_led_enum and the led info table
	the size of info tbl SHOULD be INPUT_EVENT_VIB_IND_END
	*/
	if(vib_num != INPUT_EVENT_VIB_IND_END)
	{
		MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_NOTIFY_VIB_SIZE_INVALID, INPUT_EVENT_VIB_IND_END);	
		MMI_ASSERT(vib_num == INPUT_EVENT_VIB_IND_END);
	}

	
	for(i = 0; i < vib_num; i++)
	{
	/*
	NOTICE: the vib in info table SHOULD be from 0 to INPUT_EVENT_VIB_IND_END-1
	*/	if(info_tbl[i].vib_id != i)
		{
			MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_NOTIFY_VIB_TBL_OUT_OF_ORDER, info_tbl[i].vib_id, i);
	
			MMI_ASSERT(info_tbl[i].vib_id == i);
		}
	}
	
}



/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_check_info_tbl
* DESCRIPTION
*  check the cfg info,.
* PARAMETERS
*  void  
* RETURNS
*  void
*****************************************************************************/
void mmi_frm_input_event_check_info_tbl(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	//check evt info tbl
	mmi_frm_input_event_chk_evt_info_tbl(
		g_input_event_evt_info_tbl,
		sizeof(g_input_event_evt_info_tbl)/sizeof(mmi_input_event_evt_info));

	//local app info
	mmi_frm_input_event_chk_app_info_tbl(
		g_input_event_local_app_info_tbl, 
		sizeof(g_input_event_local_app_info_tbl)/sizeof(mmi_input_event_local_app_info));

	//check led info tbl
	mmi_frm_input_event_check_led_info_tbl(
		g_input_event_notify_led_info_tbl,
		sizeof(g_input_event_notify_led_info_tbl)/sizeof(mmi_input_event_led_notify));

	//check vib info tbl
	mmi_frm_input_event_check_vib_info_tbl(
		g_input_event_notify_vib_info_tbl,
		sizeof(g_input_event_notify_vib_info_tbl)/sizeof(mmi_input_event_vib_notify));
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_keyinput_convert_evt_int
* DESCRIPTION
*  convert keyinput to evt id,.
* PARAMETERS
*  void*  
* RETURNS
*  S32
*****************************************************************************/
S32 mmi_frm_input_event_keyinput_convert_evt_int(
			S32 key_code,
			S32 key_type)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U32 i, sz;
	U16 appid;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	
	//treat key repeat as the same as key long press
/*	if(key_type == KEY_REPEAT)
	{
		key_type = KEY_LONG_PRESS;
	}
*/
	//get current app id
	appid = mmi_frm_group_get_active_id();
	
	//get the size of tbl
	sz = sizeof(g_input_event_evt_info_tbl)/sizeof(mmi_input_event_evt_info);
    for(i = 0; i < sz; i++)
    {
		if(g_input_event_evt_info_tbl[i].key_code == key_code &&
			g_input_event_evt_info_tbl[i].key_type == key_type)
		{
			//common evt 
			if(mmi_frm_input_event_is_common_evt(g_input_event_evt_info_tbl[i].evt_id)||
				g_input_event_evt_info_tbl[i].app_id == appid)//app evt
			{
				return g_input_event_evt_info_tbl[i].evt_id;	
			}			
		}			
	}

	return INPUT_EVENT_EVT_ID_INVALID;
}

/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_handle_input
* DESCRIPTION
*  handle key input,.
* PARAMETERS
*  void  
* RETURNS
*  void
*****************************************************************************/
void mmi_frm_input_event_handle_input(
			S16 key_code,
			S16 key_type)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S32 evt_id;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	/*handle power key, if this supports ending call, it maybe need 
	* to consider IS_IN_CALL
	*/
	if(key_code == KEY_POWER && key_type == KEY_EVENT_DOWN)
	{
		srv_shutdown_normal_start(0);
		return;
	}

#if defined(__MMI_BTBOX_NOLCD__)
//	  kal_prompt_trace(MOD_MMI,"[charger]booting mode=%d",srv_bootup_get_booting_mode());
	if((srv_bootup_get_booting_mode()==SRV_BOOTUP_MODE_USB) ||(srv_bootup_get_booting_mode()==SRV_BOOTUP_MODE_CHARGE))
	{	
		return;
	}	
#endif

	
	//only handle key up and long press event
	//short press: key down->key up
	//long press:  key down->long press->key up
	//             key down->long press->repeat->...->key up
	if(key_type == KEY_EVENT_DOWN)
		return;
	if(key_type == KEY_EVENT_UP && g_long_press_input_event)
	{
		g_long_press_input_event = MMI_FALSE;
		return;	
	}
	if(key_type == KEY_LONG_PRESS)
		g_long_press_input_event = MMI_TRUE;


	//get evt id
	evt_id = mmi_frm_input_event_keyinput_convert_evt_int(
				key_code,
				key_type);

	//handle case by case: common evt and app evt
	if(mmi_frm_input_event_is_common_evt(evt_id))//(evt_id<EVT_ID_SCENARIO_MAX && evt_id>GLOBAL_BASE)
	{
		//send out
        mmi_event_struct evt;
		mmi_ret cb_ret;

		//add for BT
		if(!mmi_frm_input_event_is_local_evt(evt_id))//(evt_id >EVT_ID_BTB_START && evt_id<EVT_ID_BTB_END)
		{
			MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_SEND, evt_id, key_code, key_type);
		
	        MMI_FRM_INIT_EVENT(&evt, 0);
	 		evt.evt_id = evt_id;
	        cb_ret = MMI_FRM_CB_EMIT_EVENT(&evt);
			return;
		}

		//no need to send these events when in  interrupt app
		if(!mmi_frm_input_event_is_curr_app_local())
			return;
		
		//switch
		if(evt_id == EVT_ID_INPUT_EVENT_APP_SWITCH)
		{
			mmi_frm_input_event_switch_to_next_app();
		}

		MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_SEND, evt_id, key_code, key_type);
		
        MMI_FRM_INIT_EVENT(&evt, 0);
 		evt.evt_id = evt_id;
        cb_ret = MMI_FRM_CB_EMIT_EVENT(&evt);
	
		//switch
		if(evt_id == EVT_ID_INPUT_EVENT_APP_SWITCH)
		{
			while(cb_ret == MMI_RET_OK)//none handle this evt
			{
				MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_SWITCH_NEXT_APP);
			
			///TODO: if always return ok, how to handle
				mmi_frm_input_event_jump_to_next_app();
				cb_ret = MMI_FRM_CB_EMIT_EVENT(&evt);
			}
		}
		else//launch event
		{
			if(cb_ret == MMI_RET_LOCAL_APP_UNLAUNCHED)
			{
				MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_LAUNCH_APP_FAILED);
			}
			///TODO: need add launched log
		}
		
		//update current 
		mmi_frm_input_event_update_curr_app_index();		
		MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_SEND_END, evt_id);	
	}
	else//app evt
	{
	//	MMI_ID group_id;
    	mmi_group_node_struct node_info;

		mmi_event_struct evt;
		mmi_input_event_key_data key_data;

		//key data
		memset(&key_data, 0, sizeof(mmi_input_event_key_data));
		key_data.key_code = key_code;
		key_data.key_type = key_type;
		
        MMI_FRM_INIT_EVENT(&evt, 0);
 		evt.evt_id = evt_id;
        evt.user_data = (void*)&key_data;

	
		MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_PROC, mmi_frm_group_get_active_id(), evt_id, key_code, key_type);
    	// get group info of current screen group
    	mmi_frm_group_get_info(mmi_frm_group_get_active_id(),&node_info);
		if(node_info.proc == NULL)
		{
			MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_APP_PROC_MISSED, mmi_frm_group_get_active_id());	
			MMI_ASSERT(node_info.proc);//every group 
		}	
		node_info.proc((mmi_event_struct *)&evt);
	}
			
}


//end internal interface for framework



#ifdef __INPUT_EVT_LED_UT__
//test for led
#define TEST_LED_TIMER 10000
#define TEST_LED_LENGTH 1*6*1000
static void mmi_frm_test_red_led_long(void)
{
	kal_prompt_trace(MOD_MMI, "[LED UT] mmi_frm_test_red_led_long");

	srv_gpio_control_led(
		RED_LED, 
		LED_CMD_BRIGHTING,
		1 * INPUT_EVENT_LED_UNITS,
		10 * INPUT_EVENT_LED_UNITS);	
#if 0	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0
	return;
}

static void mmi_frm_test_blue_led_long(void)
{
	kal_prompt_trace(MOD_MMI, "[LED UT] mmi_frm_test_blue_led_long");

	srv_gpio_control_led(
		BLUE_LED, 
		LED_CMD_BRIGHTING,
		1 * INPUT_EVENT_LED_UNITS,
		8* INPUT_EVENT_LED_UNITS);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0
	return;

}

static void mmi_frm_test_purple_led_long(void)
{
	kal_prompt_trace(MOD_MMI, "[LED UT] mmi_frm_test_purple_led_long");

	srv_gpio_control_led(
		PURPLE_LED, 
		LED_CMD_BRIGHTING,
		1 * INPUT_EVENT_LED_UNITS,
		6* INPUT_EVENT_LED_UNITS);
#if 0
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0
	return;	

}

static void mmi_frm_test_green_led_long(void)
{
	kal_prompt_trace(MOD_MMI, "[LED UT] mmi_frm_test_green_led_long");

	srv_gpio_control_led(
		GREEN_LED, 
		LED_CMD_BRIGHTING,
		10 * INPUT_EVENT_LED_UNITS,
		0* INPUT_EVENT_LED_UNITS);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	return;

}

static void mmi_frm_test_yellow_led_long(void)
{
	kal_prompt_trace(MOD_MMI, "[LED UT] mmi_frm_test_yellow_led_long");

	srv_gpio_control_led(
		YELLOW_LED, 
		LED_CMD_BRIGHTING,
		10 * INPUT_EVENT_LED_UNITS,
		0* INPUT_EVENT_LED_UNITS);
	return;

}

static void mmi_frm_test_azure_led_long(void)
{
	kal_prompt_trace(MOD_MMI, "[LED UT] mmi_frm_test_azure_led_long");

	srv_gpio_control_led(
		AZURE_LED, 
		LED_CMD_BRIGHTING,
		10 * INPUT_EVENT_LED_UNITS,
		0* INPUT_EVENT_LED_UNITS);
	return;

}

static void mmi_frm_test_red_led_long_flash(void)
{
	kal_prompt_trace(MOD_MMI, "[LED UT] mmi_frm_test_red_led_long_flash");

	srv_gpio_control_led(
		RED_LED, 
		LED_CMD_FLICKER,
		1 * INPUT_EVENT_LED_UNITS,
		10 * INPUT_EVENT_LED_UNITS);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0
	return;

}

static void mmi_frm_test_blue_led_long_flash(void)
{
	kal_prompt_trace(MOD_MMI, "[LED UT] mmi_frm_test_blue_led_long_flash");

	srv_gpio_control_led(
		BLUE_LED, 
		LED_CMD_FLICKER,
		1 * INPUT_EVENT_LED_UNITS,
		10 * INPUT_EVENT_LED_UNITS);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0
	return;

}

static void mmi_frm_test_purple_led_long_flash(void)
{
	kal_prompt_trace(MOD_MMI, "[LED UT] mmi_frm_test_purple_led_long_flash");

	srv_gpio_control_led(
		PURPLE_LED, 
		LED_CMD_FLICKER,
		1 * INPUT_EVENT_LED_UNITS,
		10 * INPUT_EVENT_LED_UNITS);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0
	return;
}


static void mmi_frm_test_green_led_long_flash(void)
{
	kal_prompt_trace(MOD_MMI, "[LED UT] mmi_frm_test_green_led_long_flash");

	srv_gpio_control_led(
		GREEN_LED, 
		LED_CMD_FLICKER,
		1 * INPUT_EVENT_LED_UNITS,
		10 * INPUT_EVENT_LED_UNITS);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0
	return;
}

static void mmi_frm_test_yellow_led_long_flash(void)
{
	kal_prompt_trace(MOD_MMI, "[LED UT] mmi_frm_test_yellow_led_long_flash");

	srv_gpio_control_led(
		YELLOW_LED, 
		LED_CMD_FLICKER,
		1 * INPUT_EVENT_LED_UNITS,
		10 * INPUT_EVENT_LED_UNITS);

	return;
}

static void mmi_frm_test_azure_led_long_flash(void)
{
	kal_prompt_trace(MOD_MMI, "[LED UT] mmi_frm_test_azure_led_long_flash");

	srv_gpio_control_led(
		AZURE_LED, 
		LED_CMD_FLICKER,
		1 * INPUT_EVENT_LED_UNITS,
		10 * INPUT_EVENT_LED_UNITS);

	return;
}


static U32 test_case_id = 0;
#define TEST_CASE_NUM 12
static void mmi_frm_test_led(void)
{
	srv_gpio_control_led(
			ALL_LED, 
			LED_CMD_DIMMING,
			0,
			0);

	switch(test_case_id)
	{
		case 0:
			mmi_frm_test_red_led_long();
			break;
		case 1:
			mmi_frm_test_green_led_long();	
			break;
		case 2:
			mmi_frm_test_blue_led_long();
			break;
		case 3:
			mmi_frm_test_yellow_led_long();
			break;
		case 4:
			mmi_frm_test_purple_led_long();
			break;
		case 5:
			mmi_frm_test_azure_led_long();
			break;
		case 6:
			mmi_frm_test_red_led_long_flash();
			break;
		case 7:
			mmi_frm_test_green_led_long_flash();
			break;
		case 8:
			mmi_frm_test_blue_led_long_flash();
			break;
		case 9:
			mmi_frm_test_yellow_led_long_flash();
			break;
		case 10:
			mmi_frm_test_purple_led_long_flash();
			break;
		case 11:
			mmi_frm_test_azure_led_long_flash();
			break;
			
		default:
			break;
	}

	kal_prompt_trace(MOD_MMI, "[hugo][led]test case =%d", test_case_id);
	test_case_id = (test_case_id + 1)%TEST_CASE_NUM;
	//timer
	StartTimer(
		TEST_LED_TIMER,
		TEST_LED_LENGTH,
		mmi_frm_test_led);

}




static U32 g_test_notify_indx = 0;
void mmi_frm_test_notify_led(void)
{
	
	kal_prompt_trace(MOD_MMI, "[hugo][notify]led =%Mmmi_input_event_led_enum", g_mmi_input_event_notify_tbl[g_test_notify_indx].led_indx);
	
	mmi_frm_input_event_notify(
		g_mmi_input_event_notify_tbl[g_test_notify_indx].notify_id,
		NULL);
	g_test_notify_indx = (g_test_notify_indx + 1)%INPUT_EVENT_MAX_NOTIFY;

	StartTimer(
		TEST_LED_TIMER,
		TEST_LED_LENGTH,
		mmi_frm_test_notify_led);
}

//end test for led
#endif/*__INPUT_EVT_LED_UT__*/
/*
external interface for application

*/


/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_goto_first_local_app
* DESCRIPTION
*  goto the first local app after target bootup,.
* PARAMETERS
*  void  
* RETURNS
*  void
*****************************************************************************/
void mmi_frm_input_event_goto_first_local_app(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
  //  U16 evt_id;
	mmi_event_struct evt;
	mmi_ret cb_ret;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    g_current_app_indx = 0;
#ifdef __INPUT_EVT_UT__
	input_event_test_case5();
	input_event_test_case6();
#endif//

#ifdef __INPUT_EVT_LED_UT__
	mmi_frm_test_led();
//	mmi_frm_test_notify_led();
	return;
#endif/*__INPUT_EVT_LED_UT__*/
	do
	{	
		MMI_FRM_INIT_EVENT(&evt, 0);
		evt.evt_id = mmi_frm_input_event_get_current_app_evt();
	    cb_ret = MMI_FRM_CB_EMIT_EVENT(&evt);

		if(cb_ret != MMI_RET_LOCAL_APP_LAUNCHED)
		{	
		///TODO: launching failed
			MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_FIRST_APP_LAUNCHING, evt.evt_id, g_current_app_indx);
			mmi_frm_input_event_jump_to_next_app();
		}
	}while(cb_ret != MMI_RET_LOCAL_APP_LAUNCHED);
	MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_FIRST_APP_LAUNCHED, evt.evt_id, g_current_app_indx);

#ifdef __INPUT_EVT_UT__
	input_event_test_case8();
//test led queue
	input_event_test_case11();

//test aud
	input_event_test_case9();
#endif//  
}

/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_is_app_switch_to
* DESCRIPTION
*  check the app is the dst app that switch to,.
* PARAMETERS
*  U16 app_id 
* RETURNS
*  MMI_BOOL
*****************************************************************************/
MMI_BOOL mmi_frm_input_event_is_app_switch_to(U16 app_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
  //  U16 app_indx;
	S32 i, app_num;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	app_num = sizeof(g_input_event_local_app_info_tbl)/sizeof(mmi_input_event_local_app_info);

	for(i=0; i<app_num; i++)
	{
		if(g_input_event_local_app_info_tbl[i].app_id == app_id &&
			g_input_event_local_app_info_tbl[i].app_indx == g_current_app_indx)
		{

			MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_SWITCH_APP, app_id, g_current_app_indx);
			return MMI_TRUE;			
		}	
	}

	//MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_SWITCH_APP_FAILED, app_id, g_current_app_indx);

    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_switch_to_next
* DESCRIPTION
*  check the app is the dst app that switch to,.
* PARAMETERS
*  void 
* RETURNS
*  void
*****************************************************************************/
void mmi_frm_input_event_switch_to_next_app(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	///TODO: add trace here
	mmi_frm_input_event_jump_to_next_app();
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_notify
* DESCRIPTION
*  play the notity(led, voice, vibrate) separetly,.
* PARAMETERS
*  notify_id   
*  param
* RETURNS
*  void
*****************************************************************************/
void mmi_frm_input_event_notify(
				U16 notify_id, 
				void* param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U16 led_id, aud_id, vib_id;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/	

	if(!g_input_event_initialized)
	{
		mmi_frm_input_event_init();
	}

//if the notify id is invalid, just skip it!!!!
	if(!mmi_frm_input_event_notify_valid(notify_id))
		return;
		
//stop current notify
	mmi_frm_input_event_notify_stop();

//get notify detail info
	mmi_frm_input_event_query_notify_info(
		notify_id, 
		&led_id,
		&aud_id,
		&vib_id);
	MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_NOTIFY, notify_id, led_id, aud_id, vib_id);

//led, log notify_id in led queue
	mmi_frm_input_event_led_notify_hdlr(notify_id);

//aud
	if(g_input_event_notify_enabled)
	{
		if(aud_id != 0)
		{
			mmi_frm_input_event_aud_notify_hdlr(aud_id, param);
		}
	}
	else
	{
		MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_NOTIFY_DISABLED);
	}	

//vibrate
	if(vib_id != 0)
	{
		mmi_frm_input_event_vib_notify_hdlr(vib_id);
	}
	
}

/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_notify_remove
* DESCRIPTION
*  remove notify.
* PARAMETERS
* void
* RETURNS
*  void
*****************************************************************************/
void mmi_frm_input_event_notify_remove(U16 notify_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S32 i, j;
	U16 highest_led_in_queue;
	MMI_BOOL find_in_top = MMI_FALSE;
	U16 led_id, aud_id, vib_id;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	//find notify_id in top

	for(i=0; i<INPUT_EVENT_MAX_LED_NUM; i++)
	{
		if(g_top_notify_array[i] == notify_id)
		{
			//get highest priority led in top first
			highest_led_in_queue = mmi_frm_input_event_get_highest_in_top(i);
		
			//get highest priority leds in queue
			if(highest_led_in_queue == 0)
				highest_led_in_queue = mmi_frm_input_event_pop_highest_led_in_queue(i);
			
			g_top_notify_array[i] = highest_led_in_queue;

			find_in_top = MMI_TRUE;
						
			if(highest_led_in_queue == 0)
				continue;
			
			//update others
			mmi_frm_input_event_query_notify_info(
				highest_led_in_queue, 
				&led_id,
				&aud_id,
				&vib_id);
			
			for(j=i+1; j<INPUT_EVENT_MAX_LED_NUM; j++)
			{
				if(g_top_notify_array[j]== notify_id && 
					g_input_event_notify_led_info_tbl[led_id].items[j].color != INPUT_EVENT_DIM_LED)
				{
					g_top_notify_array[j] = highest_led_in_queue;
				}
			}
			
		}
	}

	//play current led
	mmi_frm_input_event_proc_current_led_cntx();
		
	if(find_in_top)
	{
		MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_NOTIFY_REMOVE_TOP, notify_id);
	
		return;
	}

	//find in queue and remove
	MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_NOTIFY_REMOVE, notify_id);
	
	mmi_frm_input_event_led_queue_remove(notify_id);
	
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_disable_notify
* DESCRIPTION
*  disable notify.
* PARAMETERS
* void
* RETURNS
*  void
*****************************************************************************/
void mmi_frm_input_event_disable_notify(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	
	MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_NOTIFY_DISABLE);
	g_input_event_notify_enabled = MMI_FALSE;	
}

/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_enable_notify
* DESCRIPTION
*  disable notify.
* PARAMETERS
* void
* RETURNS
*  void
*****************************************************************************/
void mmi_frm_input_event_enable_notify(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/	
	
	MMI_TRACE(MMI_FW_TRC_INPUT_EVT, TRC_MMI_FRM_INPUT_EVT_NOTIFY_ENABLE);
	g_input_event_notify_enabled = MMI_TRUE;	
}



/*
BELOW this is just for unit testing
*/
//#define __INPUT_EVT_UT__

#ifdef __INPUT_EVT_UT__

/*
*NOTICE:
*
*	before you do the following UT test case, 
*	please complete the following FIVE steps.
*/
//first, replace the content of mmi_frm_input_event_cfg.h with the following
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0


//second, replace the content of mmi_frm_input_event_cfg.c with the following
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0
//third, replace the content of g_input_event_notify_led_info_tbl with the following
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0

//Fourth, register EVT to callback mgr: mmi_rp_callback_mgr_config.h
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

//Fifth, #define __INPUT_EVT_UT__ in mmi_features.h and make c,r

/*
*	END NOTICE
*/


/*the (key code, key type) of  SWITCH EVENT is the same with LAUNCH EVT*/
mmi_input_event_evt_info g_input_event_evt_info_tbl_ab1[] = 
{
  {INPUT_EVENT_APP_ID_COMMON, EVT_ID_INPUT_EVENT_APP_SWITCH, KEY_CSK, KEY_LONG_PRESS},
  {GRP_ID_AUDPLY_MAIN, EVT_ID_INPUT_EVENT_AUDPLY_PLAY, KEY_LSK, KEY_EVENT_UP},
  {GRP_ID_AUDPLY_MAIN, EVT_ID_INPUT_EVENT_AUDPLY_PAUSE, KEY_RSK, KEY_EVENT_UP},
  {GRP_ID_AUDPLY_MAIN, EVT_ID_INPUT_EVENT_AUDPLY_RECORD, KEY_CSK, KEY_EVENT_UP},
  {GRP_ID_AUDPLY_MAIN, EVT_ID_INPUT_EVENT_LAUNCH_AUDPLY, KEY_CSK, KEY_LONG_PRESS},
};

/*the (key code, key type) of  SWITCH EVENT is the same with APP EVT*/
mmi_input_event_evt_info g_input_event_evt_info_tbl_ab2[] = 
{
  {INPUT_EVENT_APP_ID_COMMON, EVT_ID_INPUT_EVENT_APP_SWITCH, KEY_0, KEY_LONG_PRESS},
  {GRP_ID_AUDPLY_MAIN, EVT_ID_INPUT_EVENT_AUDPLY_PLAY, KEY_0, KEY_LONG_PRESS},
  {GRP_ID_AUDPLY_MAIN, EVT_ID_INPUT_EVENT_AUDPLY_PAUSE, KEY_RSK, KEY_EVENT_UP},
  {GRP_ID_AUDPLY_MAIN, EVT_ID_INPUT_EVENT_AUDPLY_RECORD, KEY_CSK, KEY_EVENT_UP},
  {GRP_ID_AUDPLY_MAIN, EVT_ID_INPUT_EVENT_LAUNCH_AUDPLY, KEY_CSK, KEY_LONG_PRESS},
};

/*the (key code, key type) of  LAUNCH EVENT is the same with APP EVT*/
mmi_input_event_evt_info g_input_event_evt_info_tbl_ab3[] = 
{
  {INPUT_EVENT_APP_ID_COMMON, EVT_ID_INPUT_EVENT_APP_SWITCH, KEY_0, KEY_LONG_PRESS},
  {GRP_ID_AUDPLY_MAIN, EVT_ID_INPUT_EVENT_AUDPLY_PLAY, KEY_LSK, KEY_EVENT_UP},
  {GRP_ID_AUDPLY_MAIN, EVT_ID_INPUT_EVENT_AUDPLY_PAUSE, KEY_RSK, KEY_EVENT_UP},
  {GRP_ID_AUDPLY_MAIN, EVT_ID_INPUT_EVENT_AUDPLY_RECORD, KEY_CSK, KEY_LONG_PRESS},
  {GRP_ID_AUDPLY_MAIN, EVT_ID_INPUT_EVENT_LAUNCH_AUDPLY, KEY_CSK, KEY_LONG_PRESS},
};

/*the (key code, key type) of  APP EVT is the same with another APP EVT in one app*/
mmi_input_event_evt_info g_input_event_evt_info_tbl_ab4[] = 
{
  {INPUT_EVENT_APP_ID_COMMON, EVT_ID_INPUT_EVENT_APP_SWITCH, KEY_0, KEY_LONG_PRESS},
  {GRP_ID_AUDPLY_MAIN, EVT_ID_INPUT_EVENT_AUDPLY_PLAY, KEY_LSK, KEY_EVENT_UP},
  {GRP_ID_AUDPLY_MAIN, EVT_ID_INPUT_EVENT_AUDPLY_PAUSE, KEY_CSK, KEY_EVENT_UP},
  {GRP_ID_AUDPLY_MAIN, EVT_ID_INPUT_EVENT_AUDPLY_RECORD, KEY_CSK, KEY_EVENT_UP},
  {GRP_ID_AUDPLY_MAIN, EVT_ID_INPUT_EVENT_LAUNCH_AUDPLY, KEY_CSK, KEY_LONG_PRESS},
};


/*
input evt cfg info validation
*/
void input_event_test_case1(void)
{
//normal
	mmi_frm_input_event_chk_evt_info_tbl(
		g_input_event_evt_info_tbl,
		sizeof(g_input_event_evt_info_tbl)/sizeof(mmi_input_event_evt_info));
//abnormal 1	
	mmi_frm_input_event_chk_evt_info_tbl(
		g_input_event_evt_info_tbl_ab1,
		sizeof(g_input_event_evt_info_tbl_ab1)/sizeof(mmi_input_event_evt_info));

//abnormal 2
	mmi_frm_input_event_chk_evt_info_tbl(
		g_input_event_evt_info_tbl_ab2,
		sizeof(g_input_event_evt_info_tbl_ab2)/sizeof(mmi_input_event_evt_info));

//abnormal 3
	mmi_frm_input_event_chk_evt_info_tbl(
		g_input_event_evt_info_tbl_ab3,
		sizeof(g_input_event_evt_info_tbl_ab3)/sizeof(mmi_input_event_evt_info));

//abnormal 4
	mmi_frm_input_event_chk_evt_info_tbl(
		g_input_event_evt_info_tbl_ab4,
		sizeof(g_input_event_evt_info_tbl_ab4)/sizeof(mmi_input_event_evt_info));



}


/*app launch event should be in global event*/
mmi_input_event_local_app_info g_input_event_local_app_info_tbl_ab1[] = 
{
  {0, 100, 35000},
};


/*
app cfg info validation
*/
void input_event_test_case2(void)
{
	mmi_frm_input_event_chk_app_info_tbl(
		g_input_event_local_app_info_tbl_ab1,
		sizeof(g_input_event_local_app_info_tbl_ab1)/sizeof(mmi_input_event_local_app_info));
}

/*all led id should have cfg info*/
mmi_input_event_led_notify g_input_event_notify_led_info_tbl_ab1[] =
{
	{INPUT_EVENT_LED_ID_DUMMY,0, {0, 0, 0}},
	{INPUT_EVENT_LED_ID_0,0, {0, 0, 0}},
	{INPUT_EVENT_LED_ID_1,0, {0, 0, 0}},
	{INPUT_EVENT_LED_ID_2,0, {0, 0, 0}},
	{INPUT_EVENT_LED_ID_3,0, {0, 0, 0}},	
	{INPUT_EVENT_LED_ID_4,0, {0, 0, 0}},
	{INPUT_EVENT_LED_ID_CUSTOM_0,0, {0, 0, 0}},
	{INPUT_EVENT_LED_ID_CUSTOM_1,0, {0, 0, 0}},
	{INPUT_EVENT_LED_ID_CUSTOM_2,0, {0, 0, 0}},
	{INPUT_EVENT_LED_ID_CUSTOM_3,0, {0, 0, 0}},
//	{INPUT_EVENT_LED_ID_CUSTOM_4,0, {0, 0, 0}},	
};

/*the cfg info should from 0-INPUT_EVENT_LED_ID_END*/
mmi_input_event_led_notify g_input_event_notify_led_info_tbl_ab2[] =
{
	{INPUT_EVENT_LED_ID_DUMMY,0, {0, 0, 0}},
	{INPUT_EVENT_LED_ID_1,0, {0, 0, 0}},
	{INPUT_EVENT_LED_ID_0,0, {0, 0, 0}},
	{INPUT_EVENT_LED_ID_2,0, {0, 0, 0}},
	{INPUT_EVENT_LED_ID_3,0, {0, 0, 0}},	
	{INPUT_EVENT_LED_ID_4,0, {0, 0, 0}},
	{INPUT_EVENT_LED_ID_CUSTOM_0,0, {0, 0, 0}},
	{INPUT_EVENT_LED_ID_CUSTOM_1,0, {0, 0, 0}},
	{INPUT_EVENT_LED_ID_CUSTOM_2,0, {0, 0, 0}},
	{INPUT_EVENT_LED_ID_CUSTOM_3,0, {0, 0, 0}},
	{INPUT_EVENT_LED_ID_CUSTOM_4,0, {0, 0, 0}},	
};

/*the cfg info should from 0-INPUT_EVENT_LED_ID_END*/
mmi_input_event_led_notify g_input_event_notify_led_info_tbl_ab3[] =
{
	{INPUT_EVENT_LED_ID_DUMMY,0, {0, 0, 0}},
	{INPUT_EVENT_LED_ID_0,0, {0, 0, 0}},
	{INPUT_EVENT_LED_ID_0,0, {0, 0, 0}},
	{INPUT_EVENT_LED_ID_2,0, {0, 0, 0}},
	{INPUT_EVENT_LED_ID_3,0, {0, 0, 0}},	
	{INPUT_EVENT_LED_ID_4,0, {0, 0, 0}},
	{INPUT_EVENT_LED_ID_CUSTOM_0,0, {0, 0, 0}},
	{INPUT_EVENT_LED_ID_CUSTOM_1,0, {0, 0, 0}},
	{INPUT_EVENT_LED_ID_CUSTOM_2,0, {0, 0, 0}},
	{INPUT_EVENT_LED_ID_CUSTOM_3,0, {0, 0, 0}},
	{INPUT_EVENT_LED_ID_CUSTOM_4,0, {0, 0, 0}},	
};


/*
led cfg info validation
*/
void input_event_test_case3(void)
{
//
	mmi_frm_input_event_check_led_info_tbl(
		g_input_event_notify_led_info_tbl_ab1,
		sizeof(g_input_event_notify_led_info_tbl_ab1)/sizeof(mmi_input_event_led_notify));
//
	mmi_frm_input_event_check_led_info_tbl(
		g_input_event_notify_led_info_tbl_ab2,
		sizeof(g_input_event_notify_led_info_tbl_ab2)/sizeof(mmi_input_event_led_notify));
//
	mmi_frm_input_event_check_led_info_tbl(
		g_input_event_notify_led_info_tbl_ab3,
		sizeof(g_input_event_notify_led_info_tbl_ab3)/sizeof(mmi_input_event_led_notify));

}

/*all vib id should have cfg info*/
mmi_input_event_vib_notify g_input_event_notify_vib_info_tbl_ab1[]=
{
	{INPUT_EVENT_VIB_INDX_DUMMY, 0, 0,100},
	{INPUT_EVENT_VIB_INDX_0, 1, 1,100},	
	{INPUT_EVENT_VIB_INDX_1, 1, 0,100},
	{INPUT_EVENT_VIB_INDX_2, 0, 1,100},
	{INPUT_EVENT_VIB_INDX_3, 1, 2,100},
	{INPUT_EVENT_VIB_INDX_4, 0, 2,100},
	{INPUT_EVENT_VIB_INDX_CUSTOM_0, 0, 0,100},
	{INPUT_EVENT_VIB_INDX_CUSTOM_1, 0, 0,100},
	{INPUT_EVENT_VIB_INDX_CUSTOM_2, 0, 0,100},
	{INPUT_EVENT_VIB_INDX_CUSTOM_3, 0, 0,100},
//	{INPUT_EVENT_VIB_INDX_CUSTOM_4, 0, 0,100},
};
/*the vib id in cfg info table should be from 0-INPUT_EVENT_VIB_ID_END*/
mmi_input_event_vib_notify g_input_event_notify_vib_info_tbl_ab2[]=
{
	{INPUT_EVENT_VIB_INDX_DUMMY, 0, 0,100},
	{INPUT_EVENT_VIB_INDX_1, 1, 1,100},	
	{INPUT_EVENT_VIB_INDX_0, 1, 0,100},
	{INPUT_EVENT_VIB_INDX_2, 0, 1,100},
	{INPUT_EVENT_VIB_INDX_3, 1, 2,100},
	{INPUT_EVENT_VIB_INDX_4, 0, 2,100},
	{INPUT_EVENT_VIB_INDX_CUSTOM_0, 0, 0,100},
	{INPUT_EVENT_VIB_INDX_CUSTOM_1, 0, 0,100},
	{INPUT_EVENT_VIB_INDX_CUSTOM_2, 0, 0,100},
	{INPUT_EVENT_VIB_INDX_CUSTOM_3, 0, 0,100},
	{INPUT_EVENT_VIB_INDX_CUSTOM_4, 0, 0,100},
};

/*the vib id in cfg info table should be from 0-INPUT_EVENT_VIB_ID_END*/
mmi_input_event_vib_notify g_input_event_notify_vib_info_tbl_ab3[]=
{
	{INPUT_EVENT_VIB_INDX_DUMMY, 0, 0,100},
	{INPUT_EVENT_VIB_INDX_0, 1, 1,100},	
	{INPUT_EVENT_VIB_INDX_0, 1, 0,100},
	{INPUT_EVENT_VIB_INDX_2, 0, 1,100},
	{INPUT_EVENT_VIB_INDX_3, 1, 2,100},
	{INPUT_EVENT_VIB_INDX_4, 0, 2,100},
	{INPUT_EVENT_VIB_INDX_CUSTOM_0, 0, 0,100},
	{INPUT_EVENT_VIB_INDX_CUSTOM_1, 0, 0,100},
	{INPUT_EVENT_VIB_INDX_CUSTOM_2, 0, 0,100},
	{INPUT_EVENT_VIB_INDX_CUSTOM_3, 0, 0,100},
	{INPUT_EVENT_VIB_INDX_CUSTOM_4, 0, 0,100},
};


/*
vib cfg info validation
*/
void input_event_test_case4(void)
{
//
	mmi_frm_input_event_check_vib_info_tbl(
		g_input_event_notify_vib_info_tbl_ab1,
		sizeof(g_input_event_notify_vib_info_tbl_ab1)/sizeof(mmi_input_event_vib_notify));
//
	mmi_frm_input_event_check_vib_info_tbl(
		g_input_event_notify_vib_info_tbl_ab2,
		sizeof(g_input_event_notify_vib_info_tbl_ab2)/sizeof(mmi_input_event_vib_notify));
//
	mmi_frm_input_event_check_vib_info_tbl(
		g_input_event_notify_vib_info_tbl_ab3,
		sizeof(g_input_event_notify_vib_info_tbl_ab3)/sizeof(mmi_input_event_vib_notify));

}

//app proc
static mmi_ret app_proc_A(mmi_event_struct *evt)
{
	switch(evt->evt_id)
	{

	default:
		break;
	}

	return MMI_RET_OK;
}

static mmi_ret app_proc_B(mmi_event_struct *evt)
{
	switch(evt->evt_id)
	{

	default:
		break;
	}

	return MMI_RET_OK;
}

static mmi_ret app_proc_C(mmi_event_struct *evt)
{
	switch(evt->evt_id)
	{

	default:
		break;
	}

	return MMI_RET_OK;
}

static mmi_ret app_proc_D(mmi_event_struct *evt)
{
	switch(evt->evt_id)
	{

	default:
		break;
	}

	return MMI_RET_OK;
}

//app launch
static mmi_ret launch_app_A(mmi_event_struct *evt)
{
	switch(evt->evt_id)
	{
		case EVT_ID_INPUT_EVENT_LAUNCH_A:
		{
/*			
			MMI_ID pre_app_id = mmi_frm_group_get_active_id();
			mmi_frm_group_create(
				GRP_ID_ROOT,
				100,
				app_proc_A,
				NULL);
			mmi_frm_group_enter(
				100,
				0);

			mmi_frm_group_close(pre_app_id);

			
			return MMI_RET_LOCAL_APP_LAUNCHED;
*/			//
			return MMI_RET_LOCAL_APP_UNLAUNCHED;
		}
		break;

		default:
			break;
	}

	return MMI_RET_OK;
}


static mmi_ret launch_app_B(mmi_event_struct *evt)
{
	switch(evt->evt_id)
	{
		case EVT_ID_INPUT_EVENT_LAUNCH_B:
		{
			MMI_ID pre_app_id = mmi_frm_group_get_active_id();
			mmi_frm_group_create(
				GRP_ID_ROOT,
				200,
				app_proc_A,
				NULL);
			mmi_frm_group_enter(
				200,
				0);

			mmi_frm_group_close(pre_app_id);

			
			return MMI_RET_LOCAL_APP_LAUNCHED;
			//
			//return MMI_RET_LOCAL_APP_UNLAUNCHED;
		}
		break;

		default:
			break;
	}

	return MMI_RET_OK;
}

static mmi_ret launch_app_C(mmi_event_struct *evt)
{
	switch(evt->evt_id)
	{
		case EVT_ID_INPUT_EVENT_LAUNCH_C:
		{
			MMI_ID pre_app_id = mmi_frm_group_get_active_id();
			mmi_frm_group_create(
				GRP_ID_ROOT,
				300,
				app_proc_C,
				NULL);
			mmi_frm_group_enter(
				300,
				0);

			mmi_frm_group_close(pre_app_id);

			
			return MMI_RET_LOCAL_APP_LAUNCHED;
			//
			//return MMI_RET_LOCAL_APP_UNLAUNCHED;
		}
		break;

		default:
			break;
	}

	return MMI_RET_OK;
}

static mmi_ret launch_app_D(mmi_event_struct *evt)
{
	switch(evt->evt_id)
	{
		case EVT_ID_INPUT_EVENT_LAUNCH_D:
		{
			MMI_ID pre_app_id = mmi_frm_group_get_active_id();
			mmi_frm_group_create(
				GRP_ID_ROOT,
				400,
				app_proc_A,
				NULL);
			mmi_frm_group_enter(
				400,
				0);

			mmi_frm_group_close(pre_app_id);

			
			return MMI_RET_LOCAL_APP_LAUNCHED;
			//
			//return MMI_RET_LOCAL_APP_UNLAUNCHED;
		}
		break;

		default:
			break;
	}

	return MMI_RET_OK;
}

//switch callback
static mmi_ret switch_A(mmi_event_struct *evt)
{
	switch(evt->evt_id)
	{
		case EVT_ID_INPUT_EVENT_APP_SWITCH:
			if(mmi_frm_input_event_is_app_switch_to(100))
			{
				MMI_BOOL can_launched = MMI_TRUE;
				if(can_launched)
				{
					MMI_ID pre_app_id = mmi_frm_group_get_active_id();
					mmi_frm_group_create(
						GRP_ID_ROOT,
						100,
						app_proc_A,
						NULL);
					mmi_frm_group_enter(
						100,
						0);

					mmi_frm_group_close(pre_app_id);

					
					return MMI_RET_LOCAL_APP_LAUNCHED;
				}
				else
				{
				//		mmi_frm_input_event_switch_to_next_app();
				}

			}
			break;
		default:
			break;

	}


	return MMI_RET_OK;	
}

static mmi_ret switch_B(mmi_event_struct *evt)
{
	switch(evt->evt_id)
	{
		case EVT_ID_INPUT_EVENT_APP_SWITCH:
			if(mmi_frm_input_event_is_app_switch_to(200))
			{
				MMI_BOOL can_launched = MMI_TRUE;
				if(can_launched)
				{
					MMI_ID pre_app_id = mmi_frm_group_get_active_id();
					mmi_frm_group_create(
						GRP_ID_ROOT,
						200,
						app_proc_B,
						NULL);
					mmi_frm_group_enter(
						200,
						0);

					mmi_frm_group_close(pre_app_id);

					
					return MMI_RET_LOCAL_APP_LAUNCHED;
				}
				else
				{
				//		mmi_frm_input_event_switch_to_next_app();
				}

			}
			break;
		default:
			break;

	}

	return MMI_RET_OK;	
}

static mmi_ret switch_C(mmi_event_struct *evt)
{
	switch(evt->evt_id)
	{
		case EVT_ID_INPUT_EVENT_APP_SWITCH:
			if(mmi_frm_input_event_is_app_switch_to(300))
			{
				MMI_BOOL can_launched = MMI_FALSE;
				if(can_launched)
				{
					MMI_ID pre_app_id = mmi_frm_group_get_active_id();
					mmi_frm_group_create(
						GRP_ID_ROOT,
						300,
						app_proc_C,
						NULL);
					mmi_frm_group_enter(
						300,
						0);

					mmi_frm_group_close(pre_app_id);

					
					return MMI_RET_LOCAL_APP_LAUNCHED;
				}
				else
				{
				//		mmi_frm_input_event_switch_to_next_app();
				}

			}
			break;
		default:
			break;

	}
	

	return MMI_RET_OK;	
}

static mmi_ret switch_D(mmi_event_struct *evt)
{
	switch(evt->evt_id)
	{
		case EVT_ID_INPUT_EVENT_APP_SWITCH:
			if(mmi_frm_input_event_is_app_switch_to(400))
			{
				MMI_BOOL can_launched = MMI_TRUE;
				if(can_launched)
				{
					MMI_ID pre_app_id = mmi_frm_group_get_active_id();
					mmi_frm_group_create(
						GRP_ID_ROOT,
						400,
						app_proc_D,
						NULL);
					mmi_frm_group_enter(
						400,
						0);

					mmi_frm_group_close(pre_app_id);

					
					return MMI_RET_LOCAL_APP_LAUNCHED;
				}
				else
				{
				//		mmi_frm_input_event_switch_to_next_app();
				}

			}
			break;
		default:
			break;

	}
	


	return MMI_RET_OK;	
}


/*
goto first local app when bootup
*/
void input_event_test_case5(void)
{

	//reg event cb dynamic
	mmi_frm_cb_reg_event(
		EVT_ID_INPUT_EVENT_LAUNCH_A,
		launch_app_A,
		NULL);	
	mmi_frm_cb_reg_event(
		EVT_ID_INPUT_EVENT_LAUNCH_B,
		launch_app_B,
		NULL);
	mmi_frm_cb_reg_event(
		EVT_ID_INPUT_EVENT_LAUNCH_C,
		launch_app_C,
		NULL);
	mmi_frm_cb_reg_event(
		EVT_ID_INPUT_EVENT_LAUNCH_D,
		launch_app_D,
		NULL);	

		
}

/*
switch key function
*/
void input_event_test_case6(void)
{

//reg event cb dynamic
	mmi_frm_cb_reg_event(
		EVT_ID_INPUT_EVENT_APP_SWITCH,
		switch_A,
		NULL);

	mmi_frm_cb_reg_event(
		EVT_ID_INPUT_EVENT_APP_SWITCH,
		switch_B,
		NULL);

	mmi_frm_cb_reg_event(
		EVT_ID_INPUT_EVENT_APP_SWITCH,
		switch_C,
		NULL);

	mmi_frm_cb_reg_event(
		EVT_ID_INPUT_EVENT_APP_SWITCH,
		switch_D,
		NULL);
	
}

/*
input evt
*/
void input_event_test_case7(void)
{

}

static mmi_ret interrupt_app_proc_F(mmi_event_struct *evt)
{
	switch(evt->evt_id)
	{
	case 600:
		
		mmi_frm_group_close(mmi_frm_group_get_active_id());

	default:
		break;
	}

	return MMI_RET_OK;
}



static mmi_ret interrupt_app_proc_E(mmi_event_struct *evt)
{
	switch(evt->evt_id)
	{
	case 500:
		mmi_frm_group_close(mmi_frm_group_get_active_id());
		break;
	case 501:
		{
			mmi_frm_group_create(
				GRP_ID_ROOT,
				600,
				interrupt_app_proc_F,
				NULL);
			mmi_frm_group_enter(
				600,
				0);	
		}
		break;
	default:
		break;
	}

	return MMI_RET_OK;
}


/*
launch key
*/
void input_event_test_case8(void)
{
  //test launch key in interrup app
	mmi_frm_group_create(
		GRP_ID_ROOT,
		500,
		interrupt_app_proc_E,
		NULL);
	mmi_frm_group_enter(
		500,
		0);
}

/*
notify audio
*/
static void test_input_event_aud_cb1(srv_prof_ret ret)
{
	//
}

static void test_input_event_aud_cb2(srv_prof_ret ret)
{
	//
}

void input_event_test_case9(void)
{
//callback
	mmi_input_event_notify_param pa1, pa2;
 	pa1.aud_cb = test_input_event_aud_cb1;

	mmi_frm_input_event_notify(
		99,
		(void*)&pa1);
#if 1	
//whether callback can be interrupted
	pa2.aud_cb = test_input_event_aud_cb2;
	mmi_frm_input_event_notify(
		100,
		(void*)&pa2);	
	
//more notify in one time
//	mmi_frm_input_event_notify(
//		101,
//		NULL);
#endif//0

}

/*
notify vibrate
*/
void input_event_test_case10(void)
{
	//untested
}

/*
notify led queue
*/
void input_event_test_case11(void)
{
//add in sequence
	mmi_frm_input_event_notify(
		99,
		NULL);
	mmi_frm_input_event_notify(
		100,
		NULL);
	mmi_frm_input_event_notify(
		101,
		NULL);
	mmi_frm_input_event_notify(
		102,
		NULL);
	mmi_frm_input_event_notify(
		103,
		NULL);
	mmi_frm_input_event_notify(
		104,
		NULL);
	mmi_frm_input_event_notify(
		105,
		NULL);
	mmi_frm_input_event_notify(
		106,
		NULL);
	mmi_frm_input_event_notify(
		107,
		NULL);
	mmi_frm_input_event_notify(
		108,
		NULL);
	mmi_frm_input_event_notify(
		100,
		NULL);
	mmi_frm_input_event_notify(
		101,
		NULL);
//remove
	mmi_frm_input_event_notify_remove(99);
	mmi_frm_input_event_notify_remove(100);
	mmi_frm_input_event_notify_remove(101);
	
	mmi_frm_input_event_notify_remove(102);
	mmi_frm_input_event_notify_remove(103);
	mmi_frm_input_event_notify_remove(104);
	mmi_frm_input_event_notify_remove(105);
	mmi_frm_input_event_notify_remove(106);
	mmi_frm_input_event_notify_remove(107);
	mmi_frm_input_event_notify_remove(108);
	mmi_frm_input_event_notify_remove(100);
	mmi_frm_input_event_notify_remove(101);

//add
	mmi_frm_input_event_notify(
		99,
		NULL);
	mmi_frm_input_event_notify(
		100,
		NULL);
	//flash
	mmi_frm_input_event_notify(
		107,
		NULL);
	mmi_frm_input_event_notify(
		108,
		NULL);

	mmi_frm_input_event_notify(
		101,
		NULL);
	mmi_frm_input_event_notify(
		102,
		NULL);
//flash
	mmi_frm_input_event_notify(
		107,
		NULL);

	mmi_frm_input_event_notify(
		106,
		NULL);
	//flash
	mmi_frm_input_event_notify(
		107,
		NULL);
	mmi_frm_input_event_notify(
		108,
		NULL);

	mmi_frm_input_event_notify(
		103,
		NULL);
	mmi_frm_input_event_notify(
		104,
		NULL);
	mmi_frm_input_event_notify(
		105,
		NULL);
	mmi_frm_input_event_notify(
		106,
		NULL);
	mmi_frm_input_event_notify(
		107,
		NULL);
	mmi_frm_input_event_notify(
		108,
		NULL);
	mmi_frm_input_event_notify(
		100,
		NULL);
	mmi_frm_input_event_notify(
		101,
		NULL);


//remove
	mmi_frm_input_event_notify_remove(106);

	mmi_frm_input_event_notify_remove(99);
	mmi_frm_input_event_notify_remove(100);
	mmi_frm_input_event_notify_remove(104);
	mmi_frm_input_event_notify_remove(105);
	mmi_frm_input_event_notify_remove(101);
	
	mmi_frm_input_event_notify_remove(102);
	mmi_frm_input_event_notify_remove(103);
	mmi_frm_input_event_notify_remove(104);
	mmi_frm_input_event_notify_remove(105);
	mmi_frm_input_event_notify_remove(106);
	mmi_frm_input_event_notify_remove(107);
	mmi_frm_input_event_notify_remove(108);
	mmi_frm_input_event_notify_remove(100);
	mmi_frm_input_event_notify_remove(101);

//
	mmi_frm_input_event_notify(
		108,
		NULL);
	
}



#endif/*__INPUT_EVT_UT__*/

