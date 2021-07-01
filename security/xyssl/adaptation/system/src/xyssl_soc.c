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
 * xyssl_soc.c
 *
 * Project:
 * --------
 *   OpenSSL
 *
 * Description:
 * ------------
 *   This is file is used to adapt the memory related APIs in OpenSSL
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "stdlib.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "kal_public_api.h"
/* for socket */
#include "xyssl_soc.h"
#include "xyssl_log.h"


static int xyssl_soc_event = 0;
int xyssl_socket_retcode(kal_int32 ret);

#define XYSSL_SOCKET_EVENT_RECV           4
#define XYSSL_SOCKET_EVENT_SEND           5


/*****************************************************************************
 * FUNCTION
 *   xyssl_soc_read
 *
 * DESCRIPTION
 *   read data from established TLS connection
 *
 * PARAMETERS
 *   sock_id         socket id associate with the connection ctx to read data
 *   buf             buffer to store received data
 *   len             number of bytes to be read from the connection
 *
 * RETURN
 *   >0                        bytes of successful read data
 *   XYSSL_ERR_INVALID_SOCK_ID   given an invalid socket id
 *   XYSSL_ERR_NO_CONN_CTX       no associated connection context
 *   XYSSL_ERR_WOULDBLOCK        the lower-layer returns WOULDBLOCK
 *   XYSSL_ERR_IO_ERROR          lower-layer socket IO error
 *   XYSSL_ERR_CONN_CLOSED       connection closed by peer
 *   XYSSL_ERR_OP_DENIED         operation denied for incorrect connection state
 *****************************************************************************/
int xyssl_soc_read(void *connect_handle, unsigned char *buf, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 read;
	kal_int8 sock_id = *((kal_uint8*)connect_handle);
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	kal_wap_trace(MOD_WPS, TRACE_STATE, "xyssl_soc_read buf_len: %d", len);
	xyssl_soc_event = XYSSL_SOCKET_EVENT_RECV;
    read = soc_recv(sock_id, (kal_uint8*) buf, len, 0);
	
#ifdef XYSSL_ENABLE_DEBUG
#ifdef OBIGO_Q03C_BROWSER
	XYSSL_LOG_ERROR_SOC_RECV(read);			
#endif
#endif

	if(read == 0) read = SOC_WOULDBLOCK;

    return xyssl_socket_retcode(read);
 }

/*****************************************************************************
 * FUNCTION
 *   xyssl_soc_write
 *
 * DESCRIPTION
 *   write data to established TLS connection
 *
 * PARAMETERS
 *   sock_id         socket id associate with the connection ctx to write data
 *   buf             buffer storing the outgoing data
 *   len             number of bytes to be write to the connection
 *
 * RETURN
 *   >0                        bytes of successful written data
 *   XYSSL_ERR_INVALID_SOCK_ID   given an invalid socket id
 *   XYSSL_ERR_NO_CONN_CTX       no associated connection context
 *   XYSSL_ERR_WOULDBLOCK        the lower-layer returns WOULDBLOCK
 *   XYSSL_ERR_IO_ERROR          lower-layer socket IO error
 *   XYSSL_ERR_OP_DENIED         operation denied for incorrect connection state
 *****************************************************************************/
int xyssl_soc_write(void *connect_handle, unsigned char *buf, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 write;
	kal_int8 sock_id = *((kal_uint8*)connect_handle);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	xyssl_soc_event = XYSSL_SOCKET_EVENT_SEND;

	kal_wap_trace(MOD_WPS, TRACE_STATE, "xyssl_soc_write buf_len: %d", len);	
    write = soc_send((kal_int8) sock_id, (kal_uint8*) buf, len, 0);
	
#ifdef XYSSL_ENABLE_DEBUG
#ifdef OBIGO_Q03C_BROWSER
	XYSSL_LOG_ERROR_SOC_SEND(write);
#endif
#endif

	if(write == 0) write = SOC_WOULDBLOCK;
	
    return xyssl_socket_retcode(write);	
}

/*****************************************************************************
 * FUNCTION
 *  xyssl_socket_retcode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int xyssl_socket_retcode(kal_int32 ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(ret == SOC_SUCCESS || ret > 0)
	{
		return ret;
	}
    switch (ret)
    {
        case SOC_INVALID_SOCKET:
			return XYSSL_ERR_INVALID_SOCK_ID;
			
        case SOC_LIMIT_RESOURCE:		
        case SOC_INVAL:		
        case SOC_MSGSIZE:		
			return XYSSL_ERR_IO_ERROR;
			
        case SOC_WOULDBLOCK:
            return XYSSL_ERR_WOULDBLOCK;
			//return XYSSL_ERR_NET_TRY_AGAIN;
        default:
            return XYSSL_ERR_SOC_INTERNAL;
    }
}



int xyssl_soc_get_wait_event(void)
{
	return xyssl_soc_event;
}