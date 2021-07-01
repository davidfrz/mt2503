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
 *  app_frm_command_gprot.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef APP_FRM_COMMAND_GPROT_H
#define APP_FRM_COMMAND_GPROT_H
#ifdef __COMMAND_PORT_SUPPORT__
#ifdef __cplusplus
extern "C"
{
#endif

/***************************************************************************** 
* Include
*****************************************************************************/
#include "MMIDataType.h"

/***************************************************************************** 
* Define
*****************************************************************************/


/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{
	APP_CMD_AT = 0,
	APP_CMD_TYPE_TOTAL
} app_frm_command_type;

typedef enum
{
	APP_FRM_UART_TYPE = 0,
	APP_FRM_TRANSMITTER_TYPE_TOTAL
} app_frm_command_transmitter_type;

typedef struct
{
	U32      command_type;
	U32      command_buf_size;
	char*    command_buf;
} app_command_struct;

typedef void (*app_command_callback)(app_command_struct *param, void *user_data);

typedef struct
{
	U16 port;
	app_command_callback call_back;
	void *user_data;
} app_frm_command_port_info_struct;

/***************************************************************************** 
* Function
*****************************************************************************/
	
/*****************************************************************************
 * FUNCTION
 *  app_frm_open_command_port
 * DESCRIPTION
 *  after app open the port, all the command send to the port will transfer to the app.
 *  port (0~100) is reserved by framework, app should not use them.
 * PARAMETERS
 *  port                          [IN]       The port number.
 * RETURNS
 *  The opened port if sucess, or 0
 *
 * Example code:
 * #define MY_PORT 5000
 * S32 hello_world_proc(THREAD_HANDLE main_handler, APP_EVENT_STRUCT*evt)
 * {
 * 	switch (evt->message_id)
 * 	{
 * 		case APPLICATION_START:			
 * 			app_frm_open_command_port(MY_PORT, my_AT_CB, NULL);
 * 			break;
 * 		case APPLICATION_STOP:
 * 			app_frm_close_command_port(MY_PORT);
 * 			break;
 * 		}
 * 	}
 * 	return 0;
 * }
 *
 * void my_AT_CB(app_command_struct *param, void *user_data)
 * {
 *    int len;
 *    char ret_buf[50];
 * 	if (APP_CMD_AT == param->command_type)
 * 	{
 *          // use "AT+[5000]command1" to trigger it.
 * 		if (strncmp(command_buf, "command1", param->command_buf_size))
 * 		{	
 *                // handle the command and fill the result buffer.
 * 			hadle_command1(ret_buf, &len);
 *                app_frm_command_reply(ret_buf, len, APP_CMD_AT);
 * 		}
 * 	}
 * 	return;
 * }
 *****************************************************************************/
extern U16 app_frm_open_command_port(U16 port, app_command_callback call_back, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  app_frm_close_command_port
 * DESCRIPTION
 *  close the command port.
 * PARAMETERS
 *  port                          [IN]       The port number.
 * RETURNS
 *  None
 *****************************************************************************/
extern void app_frm_close_command_port(U16 port);

/*****************************************************************************
 * FUNCTION
 *  app_frm_command_reply
 * DESCRIPTION
 *  response the command resoult.
 * PARAMETERS
 *  reply_buf                 [IN]       command resoult string buffer.
 *  buf_size                  [IN]       the size of the buffer.
 *  reply_type               [IN]       default transfer 0 for AT command reply.
 * RETURNS
 *  None
 *****************************************************************************/
extern void app_frm_command_reply(char* reply_buf, U32 buf_size, U32 reply_type);

/*****************************************************************************
 * FUNCTION
 *	app_frm_at_command_process
 * DESCRIPTION
 *    Find the right app, and call the corresponding callback to process at command
 * PARAMETERS
 *	arg				  [IN]		 local buffer of message.
 * RETURNS
 *	None
 *****************************************************************************/
extern void app_frm_at_command_process(void* arg);

#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif //__COMMAND_PORT_SUPPORT__
#endif // APP_FRM_COMMAND_GPROT_H

