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
 *  mmi_dcc.h
 *
 * Project:
 * -------- 
 *  Wearable_Device
 *
 * Description:
 * ------------
 * The header file for device control center
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
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MMI_DCC_H_
#define _MMI_DCC_H_


/***************************************************************************** 
* Include
*****************************************************************************/
//#include "vmsys.h"
#include "MMIDataType.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#define MMI_DCC_DEVICE_POWER_ON_SUCCESS				1
#define MMI_DCC_DEVICE_POWER_ON_FAIL				-1
#define MMI_DCC_DEVICE_POWER_ON_NOTIFY_LATER		2

#define MMI_DCC_DEVICE_POWER_OFF_SUCCESS			10
#define MMI_DCC_DEVICE_POWER_OFF_FAIL				-10
#define MMI_DCC_DEVICE_POWER_OFF_NOTIFY_LATER		20

#define MMI_DCC_DEVICE_SLEEP_SUCCESS				100
#define MMI_DCC_DEVICE_SLEEP_FAIL					-100
#define MMI_DCC_DEVICE_SLEEP_NOTIFY_LATER			200

#define MMI_DCC_DEVICE_WAKEUP_SUCCESS				1000
#define MMI_DCC_DEVICE_WAKEUP_FAIL					-1000
#define MMI_DCC_DEVICE_WAKEUP_NOTIFY_LATER			2000
/***************************************************************************** 
* Typedef 
*****************************************************************************/
/* device type */
typedef enum
{
    MMI_DCC_DEVICE_MODEM = 0,
    MMI_DCC_DEVICE_WIFI,
    MMI_DCC_DEVICE_GPS,
    MMI_DCC_DEVICE_SENSOR_1,
    MMI_DCC_DEVICE_SENSOR_2,
    MMI_DCC_DEVICE_SENSOR_3,
    MMI_DCC_DEVICE_SENSOR_4,
    MMI_DCC_DEVICE_SENSOR_5,
    MMI_DCC_MAX_DEVICE
} mmi_dcc_device_type;

typedef enum
{
	MMI_DCC_FUNC_NOTIFY_NONE = 0,
	MMI_DCC_FUNC_NOTIFY_POWER_ON,
	MMI_DCC_FUNC_NOTIFY_CB,
	MMI_DCC_FUNC_NOTIFY_POWER_OFF,
	MMI_DCC_FUNC_NOTIFY_SLEEP,
	MMI_DCC_FUNC_NOTIFY_WAKEUP,
	MMI_DCC_FUNC_NOTIFY_RESULT_MAX
} mmi_dcc_func_notify_type;


typedef struct
{
	mmi_dcc_func_notify_type noti_type;
	void* noti_info;
}mmi_dcc_func_notify_info_struct;

typedef S32 MMI_DCC_FUNC_RET;

/***************************************************************************** 
* Function
*****************************************************************************/

/*****************************************************************************
 * DESCRIPTION
 *  the prototype of the power on / power off /sleep /wakeup function.
 * PARAMETERS
 *  op_code: 				[IN] 	operation code set by user
 *	device_param:   [IN]  device parameter used by function
 * RETURNS
 *  the result of power on/off,sleep, wakeup function 
 *****************************************************************************/
typedef MMI_DCC_FUNC_RET (*MMI_DCC_POWER_FUNC)(void* op_code, void* device_param);


/*****************************************************************************
 * DESCRIPTION
 *  the prototype of the callback  function.
 * PARAMETERS
 *  op_code: 				[IN] 	operation code set by user
 *	device_param:   [IN]  device parameter used by function
 * RETURNS
 * 	The return value is void. 
 *****************************************************************************/
typedef void (*MMI_DCC_CB_FUNC)(void* op_code, void* device_param);

/*****************************************************************************
 * DESCRIPTION
 *  the prototype of the callback to receive device data
 * PARAMETERS
 *	dev_type:				[IN]	device type
 *  op_code: 				[IN] 	operation code set by user
 *	result:					[IN]	device info struct pointer
 *	user_data:    	[IN]  user data used by function
 * RETURNS
 * 	The return value is void.
 *****************************************************************************/
typedef void (*MMI_DCC_ACESS_DEVICE_CB)(mmi_dcc_device_type dev_type, void* op_code, mmi_dcc_func_notify_info_struct* result, void* user_data);

/***************************************************************************** 
* Function
*****************************************************************************/

/*****************************************************************************
 * DESCRIPTION
 *  register device power on func
 * PARAMETERS
 * 	dev_type:    		[IN]  device type
 * 	power_on_func:  [IN]  power on function
 * 	device_param:		[IN]	device param
 * RETURNS
 *  The return value is void. 
 *****************************************************************************/
extern void mmi_dcc_register_power_on_func(mmi_dcc_device_type dev_type, MMI_DCC_POWER_FUNC power_on_func, void* device_param);

/*****************************************************************************
 * DESCRIPTION
 *	register device power off func
 * PARAMETERS
 *	dev_type:    		[IN]  device type
 *	power_off_func:     [IN]  power off function
 * RETURNS
 *  The return value is void. 
 *****************************************************************************/
extern void mmi_dcc_register_power_off_func(mmi_dcc_device_type dev_type, MMI_DCC_POWER_FUNC power_off_func, void* device_param);

/*****************************************************************************
 * DESCRIPTION
 *  register device power off func
 * PARAMETERS
 * 	dev_type:    			[IN]  device type
 * 	power_off_func:   [IN]  power off function
 * 	device_param:			[IN]	device param
 * RETURNS
 *  The return value is void. 
 *****************************************************************************/
extern void mmi_dcc_register_callback_func(mmi_dcc_device_type dev_type, MMI_DCC_CB_FUNC cb_func, void* device_param);

/*****************************************************************************
 * DESCRIPTION
 *  register device sleep func
 * PARAMETERS
 * 	dev_type:    			[IN]  device type
 * 	cb_func:   				[IN]  sleep function
 * 	device_param:			[IN]	device param
 * RETURNS
 *  The return value is void. 
 *****************************************************************************/
extern void mmi_dcc_register_sleep_func(mmi_dcc_device_type dev_type, MMI_DCC_POWER_FUNC cb_func, void* device_param);

/*****************************************************************************
 * DESCRIPTION
 *  register device wakeup func
 * PARAMETERS
 * 	dev_type:    			[IN]  device type
 * 	cb_func:   				[IN]  wakeup function
 * 	device_param:			[IN]	device param
 * RETURNS
 *  The return value is void. 
 *****************************************************************************/
extern void mmi_dcc_register_wakeup_func(mmi_dcc_device_type dev_type, MMI_DCC_POWER_FUNC cb_func, void* device_param);

/*****************************************************************************
 * DESCRIPTION
 *  notify when powe on func finished
 * PARAMETERS
 *	dev_type:      	[IN] device type
 *  op_code: 				[IN] operation code set by user
 *	result:					[IN] power on result: success, fail or notify later
 * RETURNS
 *  The return value is void. 
 *****************************************************************************/
extern void mmi_dcc_notify_power_on(mmi_dcc_device_type dev_type, void* op_code, S32 result);

/*****************************************************************************
 * DESCRIPTION
 *  notify when powe off finished
 * PARAMETERS
 *	dev_type:      	[IN] device type
 *  op_code: 				[IN] operation code set by user
 *	result:					[IN] power off result: success, fail or notify later
 * RETURNS
 *  The return value is void.  
 *****************************************************************************/
extern void mmi_dcc_notify_power_off(mmi_dcc_device_type dev_type, void* op_code, S32 result);

/*****************************************************************************
 * DESCRIPTION
 *	notify when callback func finished
 * PARAMETERS
 *	dev_type:      	[IN]  device type
 *	op_code:				[IN]	operation code set by user
 *	info:						[IN]	callback info returned by device
 * RETURNS
 *	The return value is void. 
 *****************************************************************************/
extern void mmi_dcc_notify_callback(mmi_dcc_device_type dev_type, void* op_code, void* result);

/*****************************************************************************
 * DESCRIPTION
 *  notify when sleep finished
 * PARAMETERS
 *	dev_type:      	[IN] device type
 *  op_code: 				[IN] operation code set by user
 *	result:					[IN] sleep result: success, fail or notify later
 * RETURNS
 *  The return value is void. 
 *****************************************************************************/
extern void mmi_dcc_notify_sleep(mmi_dcc_device_type dev_type, void* op_code, S32 result);

/*****************************************************************************
 * DESCRIPTION
 *  notify when wakeup finished
 * PARAMETERS
 *	dev_type:      	[IN] device type
 *  op_code: 				[IN] operation code set by user
 *	result:					[IN] wakeup result: success, fail or notify later
 * RETURNS
 *  The return value is void. 
 *****************************************************************************/
extern void mmi_dcc_notify_wakeup(mmi_dcc_device_type dev_type, void* op_code, S32 result);

/*****************************************************************************
 * DESCRIPTION
 *  notify when powe off finished
 * PARAMETERS
 *	dev_type:      	[IN] device type
 *  Istrarup: 			[IN] average startup current
 *	Isleep:					[IN] average sleep current
 *  Tstartup: 			[IN] average time of startup
 *	Tworking:				[IN] average time of working
 * RETURNS
 *  The return value is void.  
 *****************************************************************************/
extern void mmi_dcc_set_power_mode_param(mmi_dcc_device_type dev_type, FLOAT Istrarup, FLOAT Isleep, FLOAT Tstartup, FLOAT Tworking);

/*****************************************************************************
 * DESCRIPTION
 *  set device next working period
 * PARAMETERS
 *	dev_type:      	[IN] device type
 *  time: 					[IN] operation code set by user
 * RETURNS
 *  The return value is void.
 *****************************************************************************/
extern void mmi_dcc_set_next_working_peroid(mmi_dcc_device_type dev_type, S32 time);

/*****************************************************************************
 * DESCRIPTION
 *  get device next working peroid
 * PARAMETERS
 * 	dev_type:      	[IN]  device type
 * RETURNS
 *  The working peroid of specified device 
 *****************************************************************************/
extern S32 mmi_dcc_get_next_working_peroid(mmi_dcc_device_type dev_type);


/*****************************************************************************
 * DESCRIPTION
 *	access device info
 * PARAMETERS
 *	dev_type:      	[IN]  device type
 *  op_code: 				[IN] 	operation code set by user
 *	access_cb:			[IN]  callback to receive device info
 *	user_data:			[IN]	user data
 * RETURNS
 *  The return value is void. 
 *****************************************************************************/
extern void mmi_dcc_access_device(mmi_dcc_device_type dev_type, void* op_code, MMI_DCC_ACESS_DEVICE_CB access_cb, void* user_data);


//device init action
/*****************************************************************************
 * DESCRIPTION
 *	init device table
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
extern void mmi_dcc_device_init();

#endif

