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

#ifndef __VM_DCC_H__
#define __VM_DCC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#define	VM_DCC_FAIL                   -2

#define VM_DCC_POWER_ON_SUCCESS				1
#define VM_DCC_POWER_ON_FAIL				-1
#define VM_DCC_POWER_ON_NOTIFY_LATER		2

#define VM_DCC_POWER_OFF_SUCCESS			10
#define VM_DCC_POWER_OFF_FAIL				-10
#define VM_DCC_POWER_OFF_NOTIFY_LATER		20

#define VM_DCC_SLEEP_SUCCESS				100
#define VM_DCC_SLEEP_FAIL					-100
#define VM_DCC_SLEEP_NOTIFY_LATER			200

#define VM_DCC_WAKEUP_SUCCESS				1000
#define VM_DCC_WAKEUP_FAIL					-1000
#define VM_DCC_WAKEUP_NOTIFY_LATER			2000

/***************************************************************************** 
* Typedef 
*****************************************************************************/
/* device type */
typedef enum
{
    VM_DCC_MODEM = 0,
    VM_DCC_WIFI,
    VM_DCC_GPS,
    VM_DCC_SENSOR_1,
    VM_DCC_SENSOR_2,
    VM_DCC_SENSOR_3,
    VM_DCC_SENSOR_4,
    VM_DCC_SENSOR_5,
    VM_DCC_MAX_DEVICE
} vm_dcc_device_type;

typedef enum
{
	VM_DCC_FUNC_NOTIFY_NONE = 0,
	VM_DCC_FUNC_NOTIFY_POWER_ON,
	VM_DCC_FUNC_NOTIFY_CB,
	VM_DCC_FUNC_NOTIFY_POWER_OFF,
	VM_DCC_FUNC_NOTIFY_SLEEP,
	VM_DCC_FUNC_NOTIFY_WAKEUP,
	VM_DCC_FUNC_NOTIFY_RESULT_MAX
} vm_dcc_func_notify_type;


typedef struct
{
	vm_dcc_func_notify_type noti_type;
	void* noti_info;
} vm_dcc_func_notify_info_struct;


/***************************************************************************** 
* Function
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *    VM_DCC_POWER_FUNC
 * DESCRIPTION
 *  	the prototype of the power on,power off,sleep,wakeup function.
 * PARAMETERS
 *  	op_code: 			[IN] 	 operation code set by user
 *	device_param:   		[IN]  device parameter used by function
 * RETURNS
 *  	the result of function 
 * RETURN VALUES 
 *	VM_DCC_DEVICE_POWER_ON_SUCCESS			device power on success
 *	VM_DCC_DEVICE_POWER_ON_FAIL				device power on fail
 *	VM_DCC_DEVICE_POWER_ON_NOTIFY_LATER		async power on func, will notify power on result later
 *	VM_DCC_DEVICE_POWER_OFF_SUCCESS			device power off success
 *	VM_DCC_DEVICE_POWER_OFF_FAIL				device power off fail
 *	VM_DCC_DEVICE_POWER_OFF_NOTIFY_LATER		async power off func, will notify power off result later
 *	VM_DCC_DEVICE_SLEEP_SUCCESS				device sleep success
 *	VM_DCC_DEVICE_SLEEP_FAIL					device sleep fail
 *	VM_DCC_DEVICE_SLEEP_NOTIFY_LATER			async sleep func, will notify sleep result later
 *	VM_DCC_DEVICE_WAKEUP_SUCCESS			device wakeup success
 *	VM_DCC_DEVICE_WAKEUP_FAIL				device wakeup fail
 *	VM_DCC_DEVICE_WAKEUP_NOTIFY_LATER		async wakeup func, will notify wakeup result later
 *    VM_DCC_FAIL                                                  mre fail
 *****************************************************************************/
typedef VMINT (*VM_DCC_POWER_FUNC)(void* op_code, void* device_param);


/*****************************************************************************
 * FUNCTION
 *    VM_DCC_CB_FUNC
 * DESCRIPTION
 *  	the prototype of the device callback function.
 * PARAMETERS
 *  	op_code: 			[IN] 	operation code set by user
 *	device_param:   		[IN]  device parameter used by function
 * RETURNS
 * 	The return value is void. 
 *****************************************************************************/
typedef void (*VM_DCC_CB_FUNC)(void* op_code, void* device_param);

/*****************************************************************************
 * FUNCTION
 *    VM_DCC_ACESS_DEVICE_CB
 * DESCRIPTION
 *  	the prototype of the callback to receive device data
 * PARAMETERS
 *	dev_type:			[IN]	device type
 *  	op_code: 			[IN] 	operation code set by user
 *	result:				[IN]	device info struct pointer
 *	user_data:    			[IN]  user data used by function
 * RETURNS
 * 	The return value is void.
 *****************************************************************************/
typedef void (*VM_DCC_ACESS_DEVICE_CB)(vm_dcc_device_type dev_type, void* op_code, vm_dcc_func_notify_info_struct* result, void* user_data);

/***************************************************************************** 
* Function
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *    vm_dcc_register_power_on_func
 * DESCRIPTION
 *  	register device power on func
 * PARAMETERS
 * 	dev_type:    			[IN]  device type
 * 	power_on_func:  		[IN]  power on function
 * 	device_param:		[IN]	 device param
 * RETURNS
 *  	The return value is void. 
 * EXAMPLE
 * <code>
 *   void add_one_device(vm_dcc_device_type new_dev)
 *   {
 *		vm_dcc_register_power_on_func(new_dev, device_power_on, power_on_param);
 *		vm_dcc_register_power_off_func(new_dev, device_power_off, power_off_param)
 *		vm_dcc_register_callback_func(new_dev, device_cb, cb_param);
 * 		vm_dcc_register_sleep_func(new_dev, device_sleep, sleep_param);
 *		vm_dcc_register_wakeup_func(new_dev, device_wakeup, wakeup_param);
 *   }
 *
 *   VM_DCC_FUNC_RET device_power_on(void* op_code, void* power_on_param)
 *   {
 *		//if power on func is sync func, return fail or success; 
 *           //if power on func is async, return notify later
 *		VM_DCC_FUNC_RET power_on_result;
 *		power_on_result = power_on_device();
 *		return power_on_result;
 *   }
 * </code>
 *****************************************************************************/
extern void vm_dcc_register_power_on_func(vm_dcc_device_type dev_type, VM_DCC_POWER_FUNC power_on_func, void* device_param);

/*****************************************************************************
 * FUNCTION
 *    vm_dcc_register_power_off_func
 * DESCRIPTION
 *	register device power off func
 * PARAMETERS
 *	dev_type:    			[IN]  device type
 *	power_off_func:     	[IN]  power off function
 * RETURNS
 *  	The return value is void. 
 * EXAMPLE
 * <code>
 *   void add_one_device(vm_dcc_device_type new_dev)
 *   {
 *		vm_dcc_register_power_on_func(new_dev, device_power_on, power_on_param);
 *		vm_dcc_register_power_off_func(new_dev, device_power_off, power_off_param)
 *		vm_dcc_register_callback_func(new_dev, device_cb, cb_param);
 * 		vm_dcc_register_sleep_func(new_dev, device_sleep, sleep_param);
 *		vm_dcc_register_wakeup_func(new_dev, device_wakeup, wakeup_param);
 *   }
 *
 *   VM_DCC_FUNC_RET device_power_off(void* op_code, void* power_off_param)
 *   {
 *		//if power off func is sync func, return fail or success;
 *           //if power off func is async, return notify later
 *		VM_DCC_FUNC_RET power_off_result;
 *		power_off_result = power_off_device();
 *		return power_off_result;
 *   }
 * </code>
 *****************************************************************************/
extern void vm_dcc_register_power_off_func(vm_dcc_device_type dev_type, VM_DCC_POWER_FUNC power_off_func, void* device_param);

/*****************************************************************************
 * FUNCTION
 *    vm_dcc_register_callback_func
 * DESCRIPTION
 *  	register device callback func
 * PARAMETERS
 * 	dev_type:    			[IN]  device type
 * 	cb_func:   		[IN]  callback function
 * 	device_param:		[IN]	device param
 * RETURNS
 *  	The return value is void. 
 * EXAMPLE
 * <code>
 *   void add_one_device(vm_dcc_device_type new_dev)
 *   {
 *		vm_dcc_register_power_on_func(new_dev, device_power_on, power_on_param);
 *		vm_dcc_register_power_off_func(new_dev, device_power_off, power_off_param)
 *		vm_dcc_register_callback_func(new_dev, device_cb, cb_param);
 * 		vm_dcc_register_sleep_func(new_dev, device_sleep, sleep_param);
 *		vm_dcc_register_wakeup_func(new_dev, device_wakeup, wakeup_param);
 *   }
 *
 *   void device_cb(void* op_code, void* cb_param)
 *   {
 *		//no matter callback func is async or sync, callback func has no return value
 *		//all callback func use api vm_dcc_notify_callback to notify finish
 *
 *		do_something(&result);
 *		
 *           //if callback is async, notify directly
 *		vm_dcc_notify_callback(new_dev, op_code, result);
 *   }
 * </code>
 *****************************************************************************/
extern void vm_dcc_register_callback_func(vm_dcc_device_type dev_type, VM_DCC_CB_FUNC cb_func, void* device_param);

/*****************************************************************************
 * FUNCTION
 *    vm_dcc_register_sleep_func
 * DESCRIPTION
 *  	register device sleep func
 * PARAMETERS
 * 	dev_type:    			[IN]  device type
 * 	cb_func:   			[IN]  sleep function
 * 	device_param:		[IN]	device param
 * RETURNS
 *  	The return value is void. 
 * EXAMPLE
 * <code>
 *   void add_one_device(vm_dcc_device_type new_dev)
 *   {
 *		vm_dcc_register_power_on_func(new_dev, device_power_on, power_on_param);
 *		vm_dcc_register_power_off_func(new_dev, device_power_off, power_off_param)
 *		vm_dcc_register_callback_func(new_dev, device_cb, cb_param);
 * 		vm_dcc_register_sleep_func(new_dev, device_sleep, sleep_param);
 *		vm_dcc_register_wakeup_func(new_dev, device_wakeup, wakeup_param);
 *   }
 *
 *   VM_DCC_FUNC_RET device_sleep(void* op_code, void* sleep_param)
 *   {
 *		//if sleep func is sync func, return fail or success; 
 *           //if sleep func is async, return notify later
 *		VM_DCC_FUNC_RET sleep_result;
 *		sleep_result = sleep_device();
 *		return sleep_result;
 *   }
 * </code>
 *****************************************************************************/
extern void vm_dcc_register_sleep_func(vm_dcc_device_type dev_type, VM_DCC_POWER_FUNC sleep_func, void* device_param);

/*****************************************************************************
 * FUNCTION
 *    vm_dcc_register_wakeup_func
 * DESCRIPTION
 *  	register device wakeup func
 * PARAMETERS
 * 	dev_type:    			[IN]  device type
 * 	cb_func:   			[IN]  wakeup function
 * 	device_param:		[IN]	device param
 * RETURNS
 *  	The return value is void. 
 * EXAMPLE
 * <code>
 *   void add_one_device(vm_dcc_device_type new_dev)
 *   {
 *		vm_dcc_register_power_on_func(new_dev, device_power_on, power_on_param);
 *		vm_dcc_register_power_off_func(new_dev, device_power_off, power_off_param)
 *		vm_dcc_register_callback_func(new_dev, device_cb, cb_param);
 * 		vm_dcc_register_sleep_func(new_dev, device_sleep, sleep_param);
 *		vm_dcc_register_wakeup_func(new_dev, device_wakeup, wakeup_param);
 *   }
 *
 *   VM_DCC_FUNC_RET device_wakeup(void* op_code, void* wakeup_param)
 *   {
 *		//if wakeup func is sync func, return fail or success; 
 *           //if wakeup func is async, return notify later
 *		VM_DCC_FUNC_RET wakeup_result;
 *		wakeup_result = wakeup_device();
 *		return wakeup_result;
 *   }
 * </code>
 *****************************************************************************/
extern void vm_dcc_register_wakeup_func(vm_dcc_device_type dev_type, VM_DCC_POWER_FUNC wakeup_func, void* device_param);

/*****************************************************************************
 * FUNCTION
 *    vm_dcc_notify_power_on
 * DESCRIPTION
 *  	notify when powe on func finished
 * PARAMETERS
 *	dev_type:      			[IN] device type
 *  	op_code: 			[IN] operation code set by user
 *	result:				[IN] power on result: success, fail or notify later
 * RETURNS
 *  	The return value is void. 
 * EXAMPLE
 * <code>
 *	void some_function_of_new_dev()  
 *	{
 *		//if power on function of new dev is async, flow will finish finally in some function
 *		do_something(&result);
 *		vm_dcc_notify_power_on(dev_type, op_code, result);
 *	}
 * </code>
 *****************************************************************************/
extern void vm_dcc_notify_power_on(vm_dcc_device_type dev_type, void* op_code, VMINT result);

/*****************************************************************************
 * FUNCTION
 *    vm_dcc_notify_power_off
 * DESCRIPTION
 *  	notify when powe off finished
 * PARAMETERS
 *	dev_type:      			[IN] device type
 *  	op_code: 			[IN] operation code set by user
 *	result:				[IN] power off result: success, fail or notify later
 * RETURNS
 *  	The return value is void.  
 * EXAMPLE
 * <code>
 *	void some_function_of_new_dev()
 *	{
 *		//if power off function of new dev is async, flow will finish finally in some function
 *		do_something(&result);
 *		vm_dcc_notify_power_off(dev_type, op_code, result);
 *	}
 * </code>
 *****************************************************************************/
extern void vm_dcc_notify_power_off(vm_dcc_device_type dev_type, void* op_code, VMINT result);

/*****************************************************************************
 * FUNCTION
 *    vm_dcc_notify_callback
 * DESCRIPTION
 *	notify when callback func finished
 * PARAMETERS
 *	dev_type:      			[IN]  device type
 *	op_code:				[IN]	operation code set by user
 *	result:					[IN]	callback info returned by device
 * RETURNS
 *	The return value is void. 
 * EXAMPLE
 * <code>
 *	void some_function_of_new_dev()
 *	{
 *		//if callback function of new dev is async, flow will finish finally in some function
 *		do_something(&result);
 *		vm_dcc_notify_callback(dev_type, op_code, result);
 *	}
 * </code>
 *****************************************************************************/
extern void vm_dcc_notify_callback(vm_dcc_device_type dev_type, void* op_code, void* result);

/*****************************************************************************
 * FUNCTION
 *    vm_dcc_notify_sleep
 * DESCRIPTION
 *  	notify when sleep finished
 * PARAMETERS
 *	dev_type:      			[IN] device type
 *  	op_code: 			[IN] operation code set by user
 *	result:				[IN] sleep result: success, fail or notify later
 * RETURNS
 *  	The return value is void. 
 * EXAMPLE
 * <code>
 *	void some_function_of_new_dev()
 *	{
 *		//if sleep function of new dev is async, flow will finish finally in some function
 *		do_something(&result);
 *		vm_dcc_notify_sleep(dev_type, op_code, result);
 *	}
 * </code>
 *****************************************************************************/
extern void vm_dcc_notify_sleep(vm_dcc_device_type dev_type, void* op_code, VMINT result);

/*****************************************************************************
 * FUNCTION
 *    vm_dcc_notify_wakeup
 * DESCRIPTION
 *  	notify when wakeup finished
 * PARAMETERS
 *	dev_type:      			[IN] device type
 *  	op_code: 			[IN] operation code set by user
 *	result:				[IN] wakeup result: success, fail or notify later
 * RETURNS
 *  	The return value is void. 
 * EXAMPLE
 * <code>
 *	void some_function_of_new_dev()
 *	{
 *		//if wakeup function of new dev is async, flow will finish finally in some function
 *		do_something(&result);
 *		vm_dcc_notify_wakeup(dev_type, op_code, result);
 *	}
 * </code>
 *****************************************************************************/
extern void vm_dcc_notify_wakeup(vm_dcc_device_type dev_type, void* op_code, VMINT result);

/*****************************************************************************
 * FUNCTION
 *    vm_dcc_set_power_mode_param
 * DESCRIPTION
 *  	notify when powe off finished
 * PARAMETERS
 *	dev_type:      			[IN] device type
 *  	Istrarup: 				[IN] average startup current(mA)
 *	Isleep:				[IN] average sleep current(mA)
 *  	Tstartup: 			[IN] average time of startup(ms)
 *	Tworking:			[IN] average time of working(ms)
 * RETURNS
 *  	The return value is void.  
 * EXAMPLE
 * <code>
 *  void set_new_device_param(void)
 *  {
 *		//the four parameter is used to control the on, off ,sleep status of device intelligently to lower the power consumption
 *		// the four paramete should be measured carefully
 *		vm_dcc_set_power_mode_param(new_dev, 0.352, 0.178, 0.634, 0.887);
 *  }
 * </code>
 *****************************************************************************/
extern void vm_dcc_set_power_mode_param(vm_dcc_device_type dev_type, VMFLOAT Istrarup, VMFLOAT Isleep, VMFLOAT Tstartup, VMFLOAT Tworking);

/*****************************************************************************
 * FUNCTION
 *    vm_dcc_set_next_working_peroid
 * DESCRIPTION
 *  	set device next working period
 * PARAMETERS
 *	dev_type:      			[IN] device type
 *  	time: 				[IN] next working period of device
 * RETURNS
 *  	The return value is void.
 * EXAMPLE
 * <code>
 *  void set_new_device_period(void)
 *  {
 *		//the working period is used to decide the beharior of device
 *		vm_dcc_set_next_working_peroid(new_dev, 50);
 *  }
 * </code>
 *****************************************************************************/
extern void vm_dcc_set_next_working_peroid(vm_dcc_device_type dev_type, VMINT time);

/*****************************************************************************
 * FUNCTION
 *    vm_dcc_get_next_working_peroid
 * DESCRIPTION
 *  	get device next working peroid
 * PARAMETERS
 * 	dev_type:      	[IN]  device type
 * RETURNS
 *  	The working peroid of specified device 
 * EXAMPLE
 * <code>
 *  void get_new_device_period(void)
 *  {
 *		S32 current_period;
 *		current_period = vm_dcc_get_next_working_peroid(new_dev);
 *  }
 * </code>
 *****************************************************************************/
extern VMINT vm_dcc_get_next_working_peroid(vm_dcc_device_type dev_type);


/*****************************************************************************
 * FUNCTION
 *    vm_dcc_access_device
 * DESCRIPTION
 *	access device info
 * PARAMETERS
 *	dev_type:      	[IN]  device type
 *  	op_code: 				[IN] 	operation code set by user
 *	access_cb:			[IN]  callback to receive device info
 *	user_data:			[IN]	user data
 * RETURNS
 *  	The return value is void. 
 * EXAMPLE
 * <code>
 *  void access_new_device(void)
 *  {
 *		//this api is used when we want to get the infomation of some device
 *		//op_code here refers to the specified access action user want to do: read, write, reset...
 *		//when this op_code been passed to the device, the spedified action will be trigger
 *		vm_dcc_access_device(new_dev, op_code, access_new_device_cb, user_data);
 *  }
 *  void access_new_device_cb(vm_dcc_device_type dev_type, void* op_code, vm_dcc_func_notify_info_struct* result, void* user_data)
 *  {
 *		//when info is ready, this callback will be triggered
 *		//parameter "result" contains the info user intrested
 *  }
 * </code>
 *****************************************************************************/
extern void vm_dcc_access_device(vm_dcc_device_type dev_type, void* op_code, VM_DCC_ACESS_DEVICE_CB access_cb, void* user_data);


/*****************************************************************************
 * FUNCTION
 *    vm_dcc_device_init
 * DESCRIPTION
 *	init device table
 * PARAMETERS
 *	void
 * RETURNS
 *	void
  * EXAMPLE
 * <code>
 *  void app_init(void)
 *  {
 *		some_init_ation();
 *
 *		//this api is used to init the default device provided by our company
 *		vm_dcc_device_init();
 *
 *    		other_init_action();
 *  }
 * </code>
 *****************************************************************************/
extern void vm_dcc_device_init(void);


#ifdef __cplusplus
}
#endif

#endif  /* __VM_DCC_H__ */

