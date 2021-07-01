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
 * CommBridge.h
 *
 * Project:
 * --------
 *   IOT
 *
 * Description:
 * ------------
 *   Bridge Interface
 *   As type increase, should increase pipe type and add specific type info
 *
 * Author:
 * -------
 * 
 * 
 *==============================================================================*/

#ifdef __LOW_LEVEL_BRIDGE_SUPPORT__

#ifndef _IOT_BRIDGE_INTERFACE_H
#define _IOT_BRIDGE_INTERFACE_H

typedef enum
{
    SOCKET_PIPE_TYPE = 0x01,
    UART_PIPE_TYPE,
    USB_PIPE_TYPE,
    UNDEFINED_TYPE
}PIPE_TYPE;


typedef struct SocketInfo
{
    int socket_accpet_fd;
}SocketInfo;

           
typedef struct UartInfo
{
    unsigned int uart_band;
    unsigned char uart_port;
    unsigned char flowControl;
}UartInfo;


typedef struct UsbInfo
{
    unsigned char usb_port;
}UsbInfo;
           

#define BRIDGE_PEER_INFO_HEADER   \
    int type;    \


typedef struct BridgePeerInfo
{
    BRIDGE_PEER_INFO_HEADER
    union TypeInfo
        {
            struct SocketInfo socketInfo;
            struct UartInfo uartInfo; 
            struct UsbInfo usbInfo;
        }TypeInfo;
}BridgePeerInfo;


/*****************************************************************************
 * FUNCTION
 *	createBridge
 * DESCRIPTION
 *	create bridge and connect firPeer and secPeer
 * PARAMETERS
 *	BridgePeerInfo *firPeer, BridgePeerInfo *secPeer
 * RETURNS
 *	if create success, return true, else return false
 *
 * Sample Code
 *   //accept sockect fd should obtain when socket accpet() return
 *   BridgePeerInfo firBridgeInfo,  secBridgeInfo;
 *   int ret;
 *
 *   firBridgeInfo.type = SOCKET_PIPE_TYPE;
 *   firBridgeInfo.TypeInfo.socketInfo.socket_accpet_fd = socket_id_accept;
 *
 *   secBridgeInfo.type = UART_PIPE_TYPE;
 *   secBridgeInfo.TypeInfo.uartInfo.uart_port = uart_port1;
 *   secBridgeInfo.TypeInfo.uartInfo.uart_band = UART_BAUD_9600;
 *   secBridgeInfo.TypeInfo.uartInfo.flowControl = fc_none;
 *
 *   ret = createBridge(&firBridgeInfo, &secBridgeInfo);
 *
 *  if(KAL_FALSE == ret)
 *  {
 *      //log create bridge failure
 *  }   
 *****************************************************************************/
extern int createBridge(BridgePeerInfo *firPeer, BridgePeerInfo *secPeer);

extern int closeBridgeEx(BridgePeerInfo *firstPeerInfo, BridgePeerInfo *secondPeerInfo);

#endif /*_IOT_BRIDGE_INTERFACE_H*/

#endif /* #ifdef __LOW_LEVEL_BRIDGE_SUPPORT__ */
