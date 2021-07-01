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
 * BtcmSrvLEInterface.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for BT CM external API and internal API declaration
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *Log.
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __BT_4_0_BLE__
/***************************************************************************** 
* Included files
*****************************************************************************/
#include "BtcmSrvGprot.h"
#include "BtcmSrvProt.h"
#include "bluetooth_bm_struct.h"

#include "conversions.h"

// RHR: add
#include "MMIDataType.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "string.h"
#include "mmiapi_dm_struct.h"
#include "wgui_categories_list.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "app_ltlcom.h"
#include "stack_config.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "nvram_common_defs.h"
#include "kal_general_types.h"

#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "bluetooth_struct.h"
// RHR: add
#include "mmi_rp_srv_btcm_def.h"
#include "SimCtrlSrvGprot.h"

/*Extern part*/

#ifndef MMI_BT_LE_LINK_MAX_NUM
#define MMI_BT_LE_LINK_MAX_NUM (1)
#endif
typedef struct
{
	S32 le_link_num;
	srv_bt_cm_bt_addr le_addr[MMI_BT_LE_LINK_MAX_NUM];
}srv_bt_cm_le_linked_struct;

static srv_bt_cm_le_linked_struct g_srv_bt_cm_le_link_cntx;

/* Internal API*/
#define _LE_CM_INTERNAL_
static srv_bt_cm_get_le_link_num(void)
{
	return g_srv_bt_cm_le_link_cntx.le_link_num;
}

static srv_bt_cm_bt_addr* srv_bt_cm_get_le_addr(S32 index)
{
	return &g_srv_bt_cm_le_link_cntx.le_addr[index];
}

static void srv_bt_cm_inc_le_link_num(void)
{
	++g_srv_bt_cm_le_link_cntx.le_link_num;
}

static S32 srv_bt_cm_dec_le_link_num(void)
{
	--g_srv_bt_cm_le_link_cntx.le_link_num;
}

static S32 srv_bt_cm_set_le_link_num(S32 link_num)
{
	g_srv_bt_cm_le_link_cntx.le_link_num = link_num;
}

static MMI_BOOL srv_bt_cm_dev_is_in_link_table(srv_bt_cm_bt_addr* dev_addr)
{
	S32 index = 0;
	for (; index < MMI_BT_LE_LINK_MAX_NUM; ++index)
	{
		if (srv_bt_cm_is_dev_addr_equal(&g_srv_bt_cm_le_link_cntx.le_addr[index], dev_addr))
		{
			return MMI_TRUE;
		}
		++index;
	}

	return MMI_FALSE;
}

static MMI_BOOL srv_bt_cm_dev_le_linked(srv_bt_cm_bt_addr* dev_addr)
{
	MMI_BOOL le_linked = MMI_FALSE;

	if (!g_srv_bt_cm_le_link_cntx.le_link_num)
		return le_linked;

	le_linked = srv_bt_cm_dev_is_in_link_table(dev_addr);

	return le_linked;
}

/* external API*/
#define _LE_CM_EXTERNAL_
void srv_bt_cm_set_link_type(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_link_type_enum link_type, U8 result)
{
	S32 le_link_num = srv_bt_cm_get_le_link_num();
	srv_bt_cm_bt_addr* le_addr = srv_bt_cm_get_le_addr(le_link_num);
	srv_bt_cm_link_type_enum bt_cm_link = SRV_BT_CM_LINK_TYPE_NONE;
	kal_prompt_trace(MOD_MMI_CONN_APP, "[BTSRV] srv_bt_cm_set_link_type, link_type(%d), result(%d)", link_type, result);
	if (link_type != SRV_BT_CM_LINK_TYPE_LE)
		return;

	if (result == 0)
	{
		srv_bt_cm_copy_addr(le_addr, dev_addr);
		srv_bt_cm_inc_le_link_num();
	}
	else
	{
		--le_addr;
		memset(le_addr, 0, sizeof(srv_bt_cm_bt_addr));
		if (srv_bt_cm_dec_le_link_num() < 0)
		{
			srv_bt_cm_set_le_link_num(0);
		}
	}
	kal_prompt_trace(MOD_MMI_CONN_APP, "[BTSRV] srv_bt_cm_set_link_type, link_type(%d), link_num(%d)", link_type, srv_bt_cm_get_link_num(link_type));
}

S32 srv_bt_cm_get_link_type(void)
{
	S32 linked_type = SRV_BT_CM_LINK_TYPE_NONE;
	S32 edr_link = srv_bt_cm_get_existed_conn_num();
	if (edr_link)
	{
		linked_type |= SRV_BT_CM_LINK_TYPE_EDR;
	}

	if (srv_bt_cm_get_le_link_num())
	{
		linked_type |= SRV_BT_CM_LINK_TYPE_LE;
	}

	kal_prompt_trace(MOD_MMI_CONN_APP, "[BTSRV] srv_bt_cm_get_link_type, link_type(%d)", linked_type);
	return linked_type;
}

/* only for Android device*/
S32 srv_bt_cm_get_dev_link_type(srv_bt_cm_bt_addr* dev_addr)
{
	S32 linked_type = SRV_BT_CM_LINK_TYPE_NONE;
	S32 edr_link = srv_bt_cm_get_existed_conn_num_by_addr(dev_addr);
	if (edr_link)
	{
		linked_type |= SRV_BT_CM_LINK_TYPE_EDR;
	}

	if (srv_bt_cm_dev_le_linked(dev_addr))
	{
		linked_type |= SRV_BT_CM_LINK_TYPE_LE;
	}

	return linked_type;
}

S32 srv_bt_cm_get_link_num(srv_bt_cm_link_type_enum link_type)
{
	S32 link_num = 0;

	if (link_type & SRV_BT_CM_LINK_TYPE_EDR)
	{
	#ifdef __MMI_BT_DIALER_SUPPORT__
		link_num += srv_bt_cm_get_linked_dev_list_idx();
	#else
		link_num += (srv_bt_cm_get_existed_conn_num()>0? 1 : 0);
	#endif
	}
	if (link_type & SRV_BT_CM_LINK_TYPE_LE)
	{
		 link_num += srv_bt_cm_get_le_link_num();
	}

	return link_num;
}

#endif
