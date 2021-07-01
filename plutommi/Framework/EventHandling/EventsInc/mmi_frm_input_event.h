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
 * mmi_frm_input_event.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for input event.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef MMI_FRM_INPUT_EVENT_H
#define MMI_FRM_INPUT_EVENT_H

#include "MMI_features.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "ProfilesSrvGprot.h"

#include "mmi_frm_input_gprot.h"




#if defined(__MMI_FRM_INPUT_EVT__)
/***************************************************************************** 
* Define
*****************************************************************************/
/*
common app id
*/
#define INPUT_EVENT_APP_ID_COMMON (0)

/*invalid evt id*/
#define INPUT_EVENT_EVT_ID_INVALID (-1)

/*
MAX LED NUMBER
*/
#define INPUT_EVENT_MAX_LED_NUM 1

//led item color
//#define INPUT_EVENT_DIM_LED    (0)//not show led
//#define INPUT_EVENT_RED_LED    (1)
//#define INPUT_EVENT_BLUE_LED   (2)
//#define INPUT_EVENT_ORANGE_LED (3)
typedef enum
{
	INPUT_EVENT_DIM_LED,
	INPUT_EVENT_RED_LED,
	INPUT_EVENT_GREEN_LED,
	INPUT_EVENT_BLUE_LED,
	INPUT_EVENT_YELLOW_LED,
	INPUT_EVENT_ORANGE_LED,
	INPUT_EVENT_PURPLE_LED = INPUT_EVENT_ORANGE_LED,	
	INPUT_EVENT_AZURE_LED,

	INPUT_EVENT_MAX_LED,
}mmi_input_event_led_color;


#define INPUT_EVENT_LED_QUEUE_BUFFER_SIZE (512)

//flash, means flash in a short time
#define INPUT_EVENT_LED_SHORT_FLASH (0)

//led duration units
#define INPUT_EVENT_LED_UNITS (100)//100ms

//vib duration units
#define INPUT_EVENT_VIB_UNITS (100)//100ms

//notify volume
#define INPUT_EVENT_NOTIFY_VOLUME_MAX (16)
#define INPUT_EVENT_NOTIFY_VOLUME_MIN (0)

/***************************************************************************** 
* Typedef 
*****************************************************************************/

#if 1//move to mmi_frm_btbox_nolcd_cfg.h
/*
this information can help to find the next app when switch to next local app
*/

typedef struct
{
	U16 app_indx;
	U16 app_id;//app group id
	U16 launch_evt_id;//
}mmi_input_event_local_app_info;




/*
evt structure

rule: in one app, one{key_code, key_type} only map one evt id
but can map serveral evt id among different apps.
and this will be checked when bootup
*/
typedef struct
{
	U16 app_id;//
	U16 evt_id;
	S16 key_code;
	S16 key_type;

}mmi_input_event_evt_info;


typedef struct
{
	S16 key_code;
	S16 key_type;
	void* data;//reserved
}mmi_input_event_key_data;



/*
notify: nolcd box app use notify to output, like led, voice, vibrate.
app only tell framework the notify id, framework will help to
find the led id(led show pattern), void id, vibrate id(vibrate).
and output these information.
*/
typedef struct
{
	U16 notify_id;//will be generated by resgen flow
	U16 led_indx;
	U16 voi_id;
	U16 vib_indx;//
}mmi_input_event_notify_info;

#endif//0


/*
led item structure:
the information of every led
*/
typedef struct
{
//red,1, blue, 2, orange,3..
  U8 color;//led color, like red, blue, orange. 0, show led in queue
  
  U8 delay;//wait delay ms to turn on this led
  U8 on_time;//on duration(ms)
  U8 off_time;// off duration(ms)
  U8 repeat_times;//on times
}mmi_input_event_led_item;

/*
led id structure

*/
typedef struct
{
	U16 led_id;
	U16 priority;//0, flash, others always on
	mmi_input_event_led_item items[INPUT_EVENT_MAX_LED_NUM];
}mmi_input_event_led_notify;

/*
notify_id queue
*/
typedef struct input_event_led_queue
{
	U16 notify_id;
	struct input_event_led_queue *next;
}mmi_input_event_led_queue;

/*
information aud file
*/
#define MMI_AUD_PATH_MAX_LEN (20)

typedef struct
{
	U16 aud_id;
	U8 path[MMI_AUD_PATH_MAX_LEN];//vibrate number, now  max number is 2
	U8 desc[MMI_AUD_PATH_MAX_LEN];//vibrate
}mmi_input_event_aud_notify;

/*
notify: vibrate
*/

/*
information vibrate
*/
typedef struct
{
	U16 vib_id;
	U8 num;//vibrate number, now  max number is 2
	U8 type;//vibrate
	U16 duration;//vibrate duration
}mmi_input_event_vib_notify;

/*

*/
typedef struct
{
	srv_prof_play_tone_callback aud_cb;//aud callback
		
}mmi_input_event_notify_param;

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/


/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

/*
  *  Framework internal interface
*/
extern void mmi_frm_input_event_goto_first_local_app(void);

extern void mmi_frm_input_event_handle_input(
			S16 key_code,
			S16 key_type);

/*
*the interface below are for application.
*/
extern void mmi_frm_input_event_check_info_tbl(void);

extern MMI_BOOL mmi_frm_input_event_is_app_switch_to(U16 app_id);

extern void mmi_frm_input_event_switch_to_next_app(void);
/*
notify 
*/
extern void mmi_frm_input_event_notify(U16 notify_id, void* param);

extern void mmi_frm_input_event_notify_remove(U16 notify_id);

/*
disable notify
*/
extern void mmi_frm_input_event_disable_notify(void);

/*
enable notify
*/
extern void mmi_frm_input_event_enable_notify(void);


#endif/*#if defined(__MMI_FRM_INPUT_EVT__)*/
#endif/*MMI_FRM_INPUT_EVENT_H*/
