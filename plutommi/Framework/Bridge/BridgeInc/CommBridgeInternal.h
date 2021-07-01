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
 * CommonBridgeInternal.h
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

#include "Soc2tcpip_struct.h"
#include "Kal_general_types.h"
#include "MMI_fw_trc.h"
#include "MMI_trc_Int.h"

typedef struct DataManagement
{
    mbuf* headPtr;
    void* dataPtr;
    int sendDataLen;
    int totalDataLen;
    struct DataManagement *next;
}DataManagement;

typedef struct BridgeTableElement
{
    int peerIndex;
    
    kal_uint8 *firstPeerDataPtr;
    kal_uint8 *lastPeerDataPtr;
    kal_uint8 *bridgeDataHeadPtr;
    
    unsigned int reserved;
}BridgeTableElement;

typedef struct BridgeItem
{
    BridgeTableElement firstBridgeItem;
    BridgeTableElement secondBridgeItem;
}BridgeItem;


/* bridge struct */
typedef struct soc_bridge_node_struct
{
    kal_uint8    ref_count; /* reference count */
    kal_uint16   msg_len; /* message length */
    BridgeTableElement*  bridge_node_ptr;
} soc_bridge_node_struct;

#define bridge_node_struct BridgeTableElement
#define bridge_node_struct_ptr BridgeTableElement*

#define MOD_TRACE_FILTER MMI_FW_TRC_G3_CAT
#define BRIDGE_TRACE(...) MMI_TRACE(MOD_TRACE_FILTER, __VA_ARGS__);

#define BRIDGE_SEND_TRACE(...) MMI_TRACE(MMI_FW_TRC_G5_IME, __VA_ARGS__);
#define SOC_CLOSING_FLAG 0x00000001
#define SOC_TIMER_FLAG 0x00000002
#define SOC_BRIDGE_RECV_DATA_EMPTY_FLAG 0x00000004
#define SOC_BRIDGE_RECV_DATA_FULL_FLAG 0x00000008
#define SOC_BRIDGE_BLOCK_SEND_FLAG 0x00000010
#define SOC_BRIDGE_NEED_FORCE_RECV_FLAG 0x00000020
#define SOC_BRIDGE_VALIDATE_FLAG 0x00000040

#define _PIPE_ID(Type, DetailID) ((((unsigned int)(Type))<<24) + (DetailID))
#define set_soc_close_flag(flag) flag|=SOC_CLOSING_FLAG
#define get_soc_close_flag(flag) (((unsigned int)(flag))&(SOC_CLOSING_FLAG))
#define set_soc_timer_flag(flag) flag|=SOC_TIMER_FLAG
#define clear_soc_timer_flag(flag) flag&=(~SOC_TIMER_FLAG)
#define get_soc_timer_flag(flag) (((unsigned int)(flag))&(SOC_TIMER_FLAG))

#define set_soc_recv_empty_flag(flag) flag|=SOC_BRIDGE_RECV_DATA_EMPTY_FLAG
#define get_soc_recv_empty_flag(flag) (((unsigned int)(flag))&(SOC_BRIDGE_RECV_DATA_EMPTY_FLAG))
#define clear_soc_recv_empty_flag(flag) flag&=(~SOC_BRIDGE_RECV_DATA_EMPTY_FLAG)

#define set_soc_recv_full_flag(flag) flag|=SOC_BRIDGE_RECV_DATA_FULL_FLAG
#define get_soc_recv_full_flag(flag) (((unsigned int)(flag))&(SOC_BRIDGE_RECV_DATA_FULL_FLAG))
#define clear_soc_recv_full_flag(flag) flag&=(~SOC_BRIDGE_RECV_DATA_FULL_FLAG)

#define set_soc_block_send_flag(flag) flag|=SOC_BRIDGE_BLOCK_SEND_FLAG
#define get_soc_block_send_flag(flag) (((unsigned int)(flag))&(SOC_BRIDGE_BLOCK_SEND_FLAG))
#define clear_soc_block_send_flag(flag) flag&=(~SOC_BRIDGE_BLOCK_SEND_FLAG)

#define set_soc_need_force_recv_flag(flag) flag|=SOC_BRIDGE_NEED_FORCE_RECV_FLAG
#define get_soc_need_force_recv_flag(flag) (((unsigned int)(flag))&(SOC_BRIDGE_NEED_FORCE_RECV_FLAG))
#define clear_soc_need_force_recv_flag(flag) flag&=(~SOC_BRIDGE_NEED_FORCE_RECV_FLAG)

#define set_bridge_validate_flag(flag) flag|=SOC_BRIDGE_VALIDATE_FLAG
#define get_bridge_validate_flag(flag) (((unsigned int)(flag))&(SOC_BRIDGE_VALIDATE_FLAG))
#define clear_bridge_validate_flag(flag) flag&=(~SOC_BRIDGE_VALIDATE_FLAG)

extern bridge_node_struct_ptr searchPeerInBridge(int peerIndex);
extern bridge_node_struct_ptr searchSelfInBridge(int peerIndex);
extern void sendDataFromSocByBridge(bridge_node_struct_ptr bridge_node_ptr, mbuf *buf_data);
extern void sendLeftPortDataByBridge(kal_uint16 port);
extern void closeBridge(int peerIndex);
extern void iot_timer_send_soc_cb(bridge_node_struct_ptr bridge_node_ptr);
extern void initBridge();
extern void processPortDataHandler(kal_uint16 port);
extern void prepare_bridge_close(bridge_node_struct_ptr bridge_info_ptr);


extern kal_uint16 getUartRecvBytes(unsigned short port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid);


#endif /*__LOW_LEVEL_BRIDGE_SUPPORT__*/