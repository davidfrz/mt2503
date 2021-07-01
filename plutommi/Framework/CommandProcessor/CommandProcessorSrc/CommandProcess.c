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
 * CommandProcess.C
 *
 * Project:
 * --------
 *  
 *
 * Description:
 * ------------
 * IOT  
 *
 * Author:
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __COMMAND_PORT_SUPPORT__
/*****************************************************************************
* Include
*****************************************************************************/
#include "kal_general_types.h"
#include "string.h"
#include "mmi_frm_queue_gprot.h"
#include "mmi_msg_struct.h"
#include "app_frm_command_gprot.h"
#include "App_mem_med.h"
#include "MMI_fw_trc.h"
#include "MMI_trc_Int.h"
#include "med_struct.h"

//extern void Test_app_cb(app_command_struct *param, void *user_data);
#ifdef __INET_HTTPD__
extern void inet_httpd_AT_callback(app_command_struct *param, void *user_data);
#endif

#ifdef  __MED_AT_DEBUG__
extern void ipcam_med_vid_AT_callback(app_command_struct *param, void *user_data);
#endif

#ifdef __INET_RTSPD__
extern void inet_rtspd_AT_callback(app_command_struct *param, void *user_data);
#endif

#ifdef __INET_DNSD__
 extern void inet_dnsd_AT_callback(app_command_struct *param, void *user_data);
#endif
#ifdef __INET_FTPD__
 extern void inet_ftpd_AT_callback(app_command_struct *param, void *user_data);
#endif

#if defined(__IOT__) && defined(__BT_GATTS_PROFILE__)
 extern void conn_bt_AT_callback(app_command_struct *param, void *user_data);
#endif

#if defined(__GPS_MT3333__)
 extern void conn_gps_AT_callback(app_command_struct *param, void *user_data);
#endif

#if defined(__GPS_MT3333__)
 extern void conn_gps_AT_callback(app_command_struct *param, void *user_data);
#endif

#if defined(__GPS_MT3333__)
extern void gps_fota_AT_callback(app_command_struct *param, void *user_data);
#endif

/*****************************************************************************
* Typedef Internal
*****************************************************************************/

/*****************************************************************************
* Define
*****************************************************************************/
#define APP_PORT_TOTAL 30 //the max number that can be opened simultaneously
#define PORT_LENGTH 5
#define SYMBOL_CR 13
#define SYMBOL_LF 10

/*****************************************************************************
* Global Variable
*****************************************************************************/
//static registration table for internal app use, which need not to call API to register.
//ex: {1, Test_app_cb, NULL}
//The port can choose any number between 1 and 100, but should not conflict with other.
const static app_frm_command_port_info_struct g_app_frm_cmd_port_info_static_tbl[] = 
{
    {0, NULL, NULL}
#ifdef __INET_HTTPD__
    ,{1, inet_httpd_AT_callback, NULL}
#endif

#ifdef __MED_AT_DEBUG__
		,{2,ipcam_med_vid_AT_callback,NULL}
#endif

#ifdef __INET_RTSPD__
    ,{3, inet_rtspd_AT_callback, NULL}
#endif  

#ifdef __INET_DNSD__
	,{4, inet_dnsd_AT_callback, NULL}
#endif    
#ifdef __INET_FTPD__
	,{5, inet_ftpd_AT_callback, NULL}
#endif 
#if defined(__IOT__) && defined(__BT_GATTS_PROFILE__)
    ,{6, conn_bt_AT_callback, NULL}
#endif

#if defined(__GPS_MT3333__)
    ,{7, conn_gps_AT_callback, NULL}
#endif
#if defined(__GPS_MT3333__)
    ,{8, gps_fota_AT_callback, NULL}
#endif
    /*Please put your call back register bellow this*/
};

//dynamic registration table for app use, which need to call API to register and unregister.
static app_frm_command_port_info_struct g_app_frm_cmd_port_info_dynamic_tbl[APP_PORT_TOTAL];

/***************************************************************************** 
* Function
*****************************************************************************/

/*****************************************************************************
* FUNCTION
*	app_frm_write_uart()
* DESCRIPTION
*	This function is send message to write uart
* PARAMETERS
*	buffer	- the data to be written
*	length	- the length of data to be written
* RETURNS
*	none
*****************************************************************************/
static void app_frm_write_uart(kal_uint8* buffer, U32 buf_size)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												          */
	/*----------------------------------------------------------------*/
	mmi_write_to_uart_req_struct *res_msg;

	/*----------------------------------------------------------------*/
	/* Code Body													          */
	/*----------------------------------------------------------------*/
	res_msg =
		(mmi_write_to_uart_req_struct*) OslConstructDataPtr(sizeof(mmi_write_to_uart_req_struct));
	
	res_msg->data = (kal_uint8 *)applib_asm_alloc_anonymous(buf_size);
    if (res_msg->data == NULL)
    {
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, APP_FRM_CMD_PROCESSOR_ALLOC_MEM_FAILED, buf_size);
        return;
    }
	strncpy(res_msg->data, buffer, buf_size);
	res_msg->data_size= buf_size;

	mmi_frm_send_ilm(MOD_ATCI, MSG_ID_MMI_WRITE_DATA_TO_UART_REQ, (oslParaType*)res_msg, NULL);
    
	return;
}

void app_frm_command_reply(char* reply_buf, U32 buf_size, U32 reply_type)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												          */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body												                */
	/*----------------------------------------------------------------*/
	MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, APP_FRM_CMD_PROCESSOR_REPLY_START);
	if (buf_size == 0)
    {        
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, APP_FRM_CMD_PROCESSOR_REPLY_NO_DATA);
		return;
    }
	
	switch (reply_type)
	{
		case APP_FRM_UART_TYPE:
		{            
            MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, APP_FRM_CMD_PROCESSOR_WRITE_UART);
			app_frm_write_uart(reply_buf, buf_size);
			break;
		}
		default:
        {
            ASSERT(0);
            break;
        }
	}
	MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, APP_FRM_CMD_PROCESSOR_REPLY_END);

	return;
}

U16 app_frm_open_command_port(U16 port, app_command_callback call_back, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
	kal_uint8 i;
	kal_int16 iInsertPosition = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, APP_FRM_CMD_PROCESSOR_OPEN_PORT_START);
	ASSERT(port != 0 && call_back != NULL);

    for (i = 0; i < sizeof(g_app_frm_cmd_port_info_static_tbl) / sizeof(app_frm_command_port_info_struct); i++)
    {
        if (g_app_frm_cmd_port_info_static_tbl[i].port == port)
		{
            MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, APP_FRM_CMD_PROCESSOR_PORT_OPENED_IN_STATIC_TBL, port);
			return 0;
		}
    }
    
	for (i = 0; i < APP_PORT_TOTAL; i++)
	{
		if (g_app_frm_cmd_port_info_dynamic_tbl[i].port == port)
		{
            MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, APP_FRM_CMD_PROCESSOR_PORT_OPENED_IN_DYNAMIC_TBL, port);
			return 0;
		}
		else if ((g_app_frm_cmd_port_info_dynamic_tbl[i].port == 0) && (iInsertPosition == -1))
		{
			iInsertPosition = i;
		}
	}

	if (iInsertPosition != -1)
	{
		g_app_frm_cmd_port_info_dynamic_tbl[iInsertPosition].port = port;
		g_app_frm_cmd_port_info_dynamic_tbl[iInsertPosition].call_back = call_back;
		g_app_frm_cmd_port_info_dynamic_tbl[iInsertPosition].user_data = user_data;
	}
	else
	{
		MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, APP_FRM_CMD_PROCESSOR_NO_ENOUGH_SPACE_FOR_PORT, port);
	}
	MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, APP_FRM_CMD_PROCESSOR_OPEN_PORT_END);

	return port;
}

void app_frm_close_command_port(U16 port)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
	kal_uint8 i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, APP_FRM_CMD_PROCESSOR_CLOSE_PORT_START);
	ASSERT(port != 0);
	for (i = 0; i < APP_PORT_TOTAL; i++)
	{
		if (g_app_frm_cmd_port_info_dynamic_tbl[i].port == port)
		{
			memset(&g_app_frm_cmd_port_info_dynamic_tbl[i], 0, sizeof(app_frm_command_port_info_struct));
			
            MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, APP_FRM_CMD_PROCESSOR_CLOSE_PORT_END);
			return;
		}	
	}
    
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, APP_FRM_CMD_PROCESSOR_CLOSE_WRONG_PORT, port);
	return;
}
/*****************************************************************************
 * FUNCTION
 *  app_frm_convert_string_to_port
 * DESCRIPTION
 *  Converts port string to integer. 
 * PARAMETERS
 *  port_string           [IN]    port string to convert    
 * RETURNS
 *  return kal_uint16 value of the string
 *****************************************************************************/
static kal_uint16 app_frm_str2int(kal_uint8 *port_string)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_uint8 *c;                 /* current char */
	kal_uint16 total = 0;         /* current total */

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* skip whitespace */
	ASSERT(port_string != NULL);
	c = port_string;
	while ( *c == ' ' )
	{
		c++;
	}
	
	while ((*c >= '0') && (*c <= '9')) 
	{
		total = 10 * total + (*c - '0');     /* accumulate digit */
		c++;                               /* get next char */
	}

	return total;
}
/*****************************************************************************
 * FUNCTION
 *  app_frm_check_mmi_cmd_format
 * DESCRIPTION
 *  Check the command is the MMI command.
 *  If yes, get the virtual port and real command string.
 * PARAMETERS
 *  cmd_string           [IN]    command string
 *  port                    [OUT]  virtual port
 *  real_cmd_index     [OUT]   real command string index
 * RETURNS
 *  KAL_TRUE    is the APP command
 *  KAL_FALSE   no such command 
 *****************************************************************************/
static kal_bool app_frm_check_mmi_cmd_format(kal_uint8 *cmd_string, kal_uint16 *port, kal_int16 *real_cmd_index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    kal_uint8 port_string[PORT_LENGTH + 1];
    kal_uint8 port_len;
	kal_uint8 *pHead = NULL;
	kal_uint8 *pTail = NULL;
	kal_uint16 cmd_len;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, APP_FRM_CMD_PROCESSOR_CHECK_FORMAT_START, cmd_string);
    
	if ((pHead = strstr((const kal_char *)cmd_string,"AT+[")) != NULL || 
        (pHead = strstr((const kal_char *)cmd_string,"at+[")) != NULL)
	{
	    //skip "AT+["
	    pHead = pHead + 4;
	}
    else
    {
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, APP_FRM_CMD_PROCESSOR_CHECK_NO_PREFIX);
		return KAL_FALSE;
    }
	if ((pTail = strstr((const kal_char *)pHead,"]")) == NULL)
	{
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, APP_FRM_CMD_PROCESSOR_CHECK_NO_POSTFIX);
		return KAL_FALSE;
	}
    
    //get the virtal port number
    port_len = pTail - pHead;
    if (port_len <= PORT_LENGTH)
    {
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, APP_FRM_CMD_PROCESSOR_CHECK_PORT_LENGTH, port_len);
        strncpy((kal_char *)port_string, (kal_char *)pHead, port_len);
        port_string[port_len] = '\0';
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, APP_FRM_CMD_PROCESSOR_CHECK_PORT_LENGTH_INVALID);
        return KAL_FALSE;
    }
	
	*port = app_frm_str2int(port_string);
	if (*port == 0)
	{
		return KAL_FALSE;
	}

    pTail++;    //skip "]"
    //get the real command string start index
    *real_cmd_index = pTail - cmd_string;

	return KAL_TRUE;	
}

void app_frm_at_command_process(void* arg)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    kal_uint16 port = 0;
	kal_uint8 i;
	kal_uint16 cmd_len;
    kal_int16 real_cmd_index= -1;
    kal_uint16 static_table_size;
	app_command_struct *app_command = NULL;	
	l4c_pass_cmd_to_mmi_ind_struct *local_para= (l4c_pass_cmd_to_mmi_ind_struct *)arg;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/
    if (app_frm_check_mmi_cmd_format(local_para->cmd_string,&port,&real_cmd_index) == KAL_FALSE)
	{
	    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, APP_FRM_CMD_PROCESSOR_CHECK_NOT_APP_COMMAND);
		applib_asm_free_anonymous(local_para->cmd_string);
		mmi_frm_send_ilm(MOD_ATCI, MSG_ID_MMI_RESPONSE_ERROR_CODE_REQ, NULL, NULL);
		return;
	}
    
    //remove  'CR' and 'LF' symbol of command string.
    cmd_len = strlen(local_para->cmd_string);
    while (*(local_para->cmd_string + (cmd_len - 1)) == SYMBOL_CR || 
           *(local_para->cmd_string + (cmd_len - 1)) == SYMBOL_LF)
    {
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, APP_FRM_CMD_PROCESSOR_CHECK_CR_AND_LF, *(local_para->cmd_string + (cmd_len - 1)));
        cmd_len--;//remove 'CR' and ' LF '.
    }
	*(local_para->cmd_string + cmd_len) = '\0';
    
    //port: 1 ~ 100 is for internal use
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, APP_FRM_CMD_PROCESSOR_GET_PORT_NUMBER, port);
    //Find port in static table first, then dynamic table
    static_table_size = sizeof(g_app_frm_cmd_port_info_static_tbl) / sizeof(app_frm_command_port_info_struct);
    for (i = 0; i < static_table_size; i++)
    {
        if (g_app_frm_cmd_port_info_static_tbl[i].port == port)
		{
		    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, APP_FRM_CMD_PROCESSOR_FIND_IN_STATIC_TBL);
		    app_command = (app_command_struct *)get_ctrl_buffer(sizeof(app_command_struct));
            if (app_command == NULL)
            {
                MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, APP_FRM_CMD_PROCESSOR_CTRL_BUFFER_NOT_ENOUGH, sizeof(app_command_struct));
            }
            
			app_command->command_type = APP_CMD_AT;
			app_command->command_buf_size = strlen(local_para->cmd_string + real_cmd_index);
			app_command->command_buf = local_para->cmd_string + real_cmd_index;

			(*(g_app_frm_cmd_port_info_static_tbl[i].call_back))(app_command, 
				                    g_app_frm_cmd_port_info_static_tbl[i].user_data);
			applib_asm_free_anonymous(local_para->cmd_string);
			free_ctrl_buffer(app_command);
			
			return;
		}	
    }

	for (i = 0; i < APP_PORT_TOTAL; i++)
	{
    	if (g_app_frm_cmd_port_info_dynamic_tbl[i].port == port)
		{
		    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, APP_FRM_CMD_PROCESSOR_FIND_IN_DYNAMIC_TBL);
		    app_command = (app_command_struct *)get_ctrl_buffer(sizeof(app_command_struct));
            if (app_command == NULL)
            {
                MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, APP_FRM_CMD_PROCESSOR_CTRL_BUFFER_NOT_ENOUGH, sizeof(app_command_struct));
            }
            
			app_command->command_type = APP_CMD_AT;
			app_command->command_buf_size = strlen(local_para->cmd_string + real_cmd_index);
			app_command->command_buf = local_para->cmd_string + real_cmd_index;
			
    		(*(g_app_frm_cmd_port_info_dynamic_tbl[i].call_back))(app_command, 
    				                g_app_frm_cmd_port_info_dynamic_tbl[i].user_data);
			applib_asm_free_anonymous(local_para->cmd_string);
			free_ctrl_buffer(app_command);
			
			return;
		}	
	}

    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, APP_FRM_CMD_PROCESSOR_IDENTIFY_WRONG_PORT, port);    
    applib_asm_free_anonymous(local_para->cmd_string);
	mmi_frm_send_ilm(MOD_ATCI, MSG_ID_MMI_RESPONSE_ERROR_CODE_REQ, NULL, NULL);
    
	return;
}

#endif //__COMMAND_PORT_SUPPORT__
