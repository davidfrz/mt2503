/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   dcl_gpt.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer) for GPT.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef DCL_DEFINITION_STRUCT
#ifndef __DCL_GPT_H_STRUCT__
#define __DCL_GPT_H_STRUCT__
#include "kal_non_specific_general_types.h"
#include "kal_release.h"

// GPT Interrupt Interval. [write to hardware register.]
// put this macro in here, becasue it will be used in alerter.c
#define gptimer_interval   10
/*******************************************************************************
 * DCL_OPTIONS for GPT
 *******************************************************************************/
#define GPT_OPTIONS

/*******************************************************************************
 * DCL_CONFIGURE_T for GPT
 *******************************************************************************/


/*******************************************************************************
 * DCL_EVENT
 *******************************************************************************/
#define GPT_EVENTS   \
   EVENT_HGPT_TIMEOUT = 0x1,

/*******************************************************************************
 * DCL_CTRL_CMD
 *******************************************************************************/
 #ifdef __BUILD_DOM__
/*
* The GPIO Command values in DCL_CTRL_CMD_T Enum of dcl.h 
* DCL_CTRL_DATA_T Define the Control data structure for each module's command 
*/
typedef enum
{
	 SGPT_CMD_START,  //GPT Start command. <DCL_GPT_CB>
	 SGPT_CMD_MINI_SECOND_START,
   SGPT_CMD_STOP,   //GPT Stop  command. <DCL_GPT_CB>
   SGPT_CMD_BUSYWAIT, //GPT Busywait command, that's only support to DCL_GPT_BusyWait.
   FGPT_CMD_START, //Free run GPT start command <DCL_GPT_FreeRUN3 & DCL_GPT_FreeRUN4>
   FGPT_CMD_STOP,  //Free run GPT Stop command <DCL_GPT_FreeRUN3 & DCL_GPT_FreeRUN4>
   FGPT_CMD_RETURN_COUNT,	//Free run GPT return current count value. <DCL_GPT_FreeRUN3 & DCL_GPT_FreeRUN4>
}DCL_CTRL_CMD_T;
#else
#define GPT_CMDS  \
   SGPT_CMD_START,  \
   SGPT_CMD_MINI_SECOND_START, \
   SGPT_CMD_STOP, \
   SGPT_CMD_BUSYWAIT, \
   FGPT_CMD_START, \
   FGPT_CMD_STOP, \
   FGPT_CMD_RETURN_COUNT,
#endif

/* For SGPT_CMD_START command. */
typedef struct
{
   DCL_UINT16   u2Tick;//The time Ticks(a tick is 10ms) that register callback function delay to wake up. 
   void     (*pfCallback)(void *); //register callback function
   void     *vPara; //parameter of register callback function 
} SGPT_CTRL_START_T;

/* For FGPT_CMD_RETURN_COUNT command. */
typedef DCL_UINT16 FGPT_CTRL_RETURN_COUNT_T;
/*For SGPT_CMD_BUSYWAIT command*/
typedef DCL_UINT16 GPT_BUSYWAIT_COUNT;

#ifdef __BUILD_DOM__
/*The GPIO command prarmeter data structure for each command. that's enum in in DCL_CTRL_DATA_T*/
typedef enum
	{
		 SGPT_CTRL_START_T             rSGPTStart, /* For SGPT_CMD_START command. */
	   FGPT_CTRL_RETURN_COUNT_T      u2RetCount, /* For FGPT_CMD_RETURN_COUNT command. */
	   GPT_BUSYWAIT_COUNT			   uBusyWaitcount, /*For SGPT_CMD_BUSYWAIT command*/
	}DCL_CTRL_DATA_T;
#else
#define GPT_CTRLS \
   SGPT_CTRL_START_T             rSGPTStart; \
   FGPT_CTRL_RETURN_COUNT_T      u2RetCount; \
   GPT_BUSYWAIT_COUNT			 uBusyWaitcount;
#endif // __BUILD_DOM__
 
#endif // #ifndef __DCL_GPT_H_STRUCT__
#endif // #ifdef DCL_DEFINITION_STRUCT   
#ifndef DCL_GPT_H_
#define DCL_GPT_H_
#define MAX_GPT_ITEMS		32
//static kal_bool fgGPT1Init = KAL_FALSE;

typedef struct 
{
	void (*gpt1_func)(void);
	void (*gpt2_func)(void); 
}gpt_func;

typedef struct 
{
	kal_uint16   tick;
	void     	 (*gptimer_func)(void *parameter);
	void    	 *parameter;
}gptimer_item;

#if !defined(DRV_GPT_NEW_ARCHI)
typedef struct
{
   kal_uint32     status;  /*1,activated ,0:de-activated*/
   kal_bool       GPTSTOP;
   kal_uint32     Hgpt_handle;
   kal_uint16     GPT_TICK;
   kal_uint8      MAX_GPTIMER_ITEMS;  // Indicate the current registered GPT users
   kal_uint8      GPTUsed[32];  /* 0: Not registered by user, 1: Registerd by used*/
                                /* Reset to 0 when user release GPT handle*/
   gptimer_item   GPTItems[32];  /*support at most 32 gptimer*/
   gpt_func       GPT_FUNC;
   kal_hisrid     hisr;
} GPTStruct; 

#else

typedef struct
{
   kal_uint8      GPTUsed[32];  /* 0: Not registered by user, 1: Registerd by used*/
   kal_hisrid     hisr;
} GPTStruct; 
typedef struct GPTNodeStruct
{
	kal_bool 	 Is_Iddle;//record this user is free or busy
	kal_uint32	 gpt_start_tick; //32K start tick
	kal_uint32   gpt_arrive_tick; //32K arrive tick
	void     	 (*gptimer_func)(void *parameter);// call back function
	void    	 *parameter;  // call back funtion parameter
}GPTNodeStruct;

#endif
#endif
#if defined(DCL_DEFINITION_PROTOTYPE)
#ifndef __DCL_GPT_H_PROTOTYPE__
#define __DCL_GPT_H_PROTOTYPE__


/*************************************************************************
* FUNCTION
*  DclSGPT_Initialize
*
* DESCRIPTION
*  This function is to initialize SW GPT module. 
*
* PARAMETERS
*	DCL_STATUS_OK
*
* RETURNS
*  none
*
*************************************************************************/
extern DCL_STATUS DclSGPT_Initialize(void);

/*************************************************************************
* FUNCTION
*  DclSGPT_Open
*
* DESCRIPTION
*  This function is to open the SW GPT module and get a handle. 
*  Note that for DCL_GPT_CB, multiple opens are allowed.For DCL_GPT_BusyWait, Multiple opens are not support.
*
* PARAMETERS
*	eDev: only valid for DCL_GPT_CB DCL_GPT_BusyWait
*	flags: no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURN VALUES
*	DCL_HANDLE_INVALID: Open failed.
*  other value: Open success, return a a valid handle
*
*************************************************************************/
extern DCL_HANDLE DclSGPT_Open(DCL_DEV dev, DCL_FLAGS flags);

/*************************************************************************
* FUNCTION
*  DclSGPT_ReadData
*
* DESCRIPTION
*  This function is not supported for the SW GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURN VALUES
*	STATUS_UNSUPPORTED: 
*
*************************************************************************/
extern DCL_STATUS DclSGPT_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options);

/*************************************************************************
* FUNCTION
*  DclSGPT_WriteData
*
* DESCRIPTION
*  This function is not supported for the SW GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURN VALUES
*	STATUS_UNSUPPORTED: 
*
*************************************************************************/
extern DCL_STATUS DclSGPT_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options);

/*************************************************************************
* FUNCTION
*  DclSGPT_Configure
*
* DESCRIPTION
*  This function is not supported for the SW GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURN VALUES
*	STATUS_UNSUPPORTED: 
*
*************************************************************************/
extern DCL_STATUS DclSGPT_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);

/*************************************************************************
* FUNCTION
*  DclSGPT_RegisterCallback
*
* DESCRIPTION
*  This function is not supported for the SW GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURN VALUES
*	STATUS_UNSUPPORTED: 
*
*************************************************************************/
extern DCL_STATUS DclSGPT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);

/*************************************************************************
* FUNCTION
*  DclSGPT_Control
*
* DESCRIPTION
*  This function is to send command to control the SW GPT module.
*
* Now, we support two kind of GPT function.
* For DCL_GPT_CB timer, you can register a callback function with some tick waiting to run.(a tick is 10ms)
* when timeout ,the callback function will be run in DRV_HISR.
*
* For DCL_GPT_BusyWait, You can call DclSGPT_Control with SGPT_CMD_BUSYWAIT command, the programm will be loop in this
* function until timeout. (a busywait tick is 1ms).
*
* PARAMETERS
*	handle: a valid handle return by DclSGPT_Open()
*  cmd: a control command for GPT module
*          1. SGPT_CMD_START - to start a GPT timer
*          2. SGPT_CMD_STOP- to stop a GPT timer
*          3. SGPT_CMD_BUSYWAIT - to start GPT Busywait function.
*  data:  data structure for control command.
*             1. SGPT_CMD_START- pointer to a SGPT_CTRL_START_T structure
*             2. SGPT_CMD_STOP- a NULL pointer
*							3. SGPT_CMD_BUSYWAIT - a pointer to GPT_BUSYWAIT_COUNT;
*
* RETURN VALUES
*	STATUS_OK: command is executed successfully.
*	STATUS_FAIL:  command is failed.
* DCL_HANDLE_INVALID:  It's a invaild handle.
* STATUS_INVALID_CMD: It's a invalid command.
*
*************************************************************************/
extern DCL_STATUS DclSGPT_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);

/*************************************************************************
* FUNCTION
*  DclSGPT_Close
*
* DESCRIPTION
*  This function is to close the SW GPT module.
*
* PARAMETERS
*	handle:   hanlde previous got from DclSGPT_Open()
*
* RETURN VALUES
*	DCL_STATUS_OK: successfully close the SW GPT module.
*	DCL_STATUS_fail: fails to close the SW GPT module.
* STATUS_INVALID_HANDLE: invalid handle.
*************************************************************************/
extern DCL_STATUS DclSGPT_Close(DCL_HANDLE *handle);

/*************************************************************************
* FUNCTION
*  DclFGPT_Initialize
*
* DESCRIPTION
*  This function is to initialize the free run GPT module.
*
* PARAMETERS
*	None
*
* RETURN VALUES
*	DCL_STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclFGPT_Initialize(void);

/*************************************************************************
* FUNCTION
*  DclFGPT_Open
*
* DESCRIPTION
*  This function is to open a free run GPT module if it exists. Note 
* that it supports multiple opens and no need to close it.
*
* PARAMETERS
*	eDev: only valid for  <DCL_GPT_FreeRUN3 & DCL_GPT_FreeRUN4>
*	flags: no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURN VALUES
*	DCL_HANDLE_INVALID: Open failed. It means no free run GPT exists or 
*                       open a wrong device.
*  other value: a valid handle
*
*************************************************************************/
extern DCL_HANDLE DclFGPT_Open(DCL_DEV dev, DCL_FLAGS flags);

/*************************************************************************
* FUNCTION
*  DclFGPT_ReadData
*
* DESCRIPTION
*  This function is not supported for the free run GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclFGPT_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options);

/*************************************************************************
* FUNCTION
*  DclFGPT_WriteData
*
* DESCRIPTION
*  This function is not supported for the free run GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclFGPT_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options);

/*************************************************************************
* FUNCTION
*  DclFGPT_Configure
*
* DESCRIPTION
*  This function is not supported for the free run GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclFGPT_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);

/*************************************************************************
* FUNCTION
*  DclFGPT_RegisterCallback
*
* DESCRIPTION
*  This function is not supported for the free run GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclFGPT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);

/*************************************************************************
* FUNCTION
*  DclFGPT_Control
*
* DESCRIPTION
*  This function is to send command to control the free run GPT module.
*
* PARAMETERS
*	handle: a valid handle return by DclFGPT_Open()
*  cmd:  a control command for free ryb GPT module
*					1. FGPT_CMD_START - to start free run gpt timer
*					2. FGPT_CMD_STOP - to stop free run gpt timer
*         3.  FGPT_CMD_RETURN_COUNT - to get the timer count
*  data:  
*	 1. FGPT_CMD_RETURN_COUNT- pointer to a FGPT_CTRL_RETURN_COUNT_T type
*  2. FGPT_CMD_START - pointer to null
*  3. FGPT_CMD_STOP -pointer to null
*
* RETURN VALUES
*	STATUS_OK:  command is executed successfully.
*	STATUS_FAIL:  command is failed. No free run GPT is supported.
*  STATUS_INVALID_CMD:  The command is invalid.
*  STATUS_INVALID_HANDLE: The handle is invalid.
*
*************************************************************************/
extern DCL_STATUS DclFGPT_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);

/*************************************************************************
* FUNCTION
*  DclFGPT_Close
*
* DESCRIPTION
*   This function is to close the SW GPT module.
*
* PARAMETERS
*	handle:   hanlde previous got from DclSGPT_Open()
*
* RETURN VALUES
*	DCL_STATUS_OK: successfully close the SW GPT module.
*	DCL_STATUS_fail: fails to close the SW GPT module.
* STATUS_INVALID_HANDLE: invalid handle.
*
*************************************************************************/
extern DCL_STATUS DclFGPT_Close(DCL_HANDLE handle);

#endif // #ifndef __DCL_GPT_H_PROTOTYPE__
#endif // #ifdef DCL_DEFINITION_PROTOTYPE


