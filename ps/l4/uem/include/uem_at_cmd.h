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
 * uem_at_cmd.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for AT command test function.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _UEM_AT_CMD_H
#define _UEM_AT_CMD_H

#include "kal_general_types.h"

typedef enum
{
    L4CUEM_EF_PORT_NULL = 0,
    L4CUEM_EF_PORT_COM_SWITCH,
    L4CUEM_EF_PORT_MS,
    L4CUEM_EF_PORT_SD_LOGGING,
    L4CUEM_EF_PORT_CDROM_CONFIG,
    L4CUEM_EF_PORT_MAX_ITEM
} l4cuem_at_ef_port_mode_enum;

/***************************************************************************** 
* External Function
*****************************************************************************/
//extern kal_bool l4cuem_test_alarm_setting(kal_uint8 const **buffer);

//extern kal_bool l4cuem_test_alarm_delete(kal_uint8 const **buffer);

//extern kal_bool l4cuem_test_clock_setting(kal_uint8 const **buffer);

//extern kal_bool l4cuem_test_date_format(kal_uint8 const **buffer);

extern kal_bool l4cuem_test_time_format(kal_uint8 const **buffer);

//extern kal_bool l4cuem_test_battery_level(kal_uint8 const **buffer);

//extern kal_bool l4cuem_test_language(kal_uint8 const **buffer);

extern kal_bool l4cuem_test_volume_level(kal_uint8 const **buffer);

extern kal_bool l4cuem_test_ring_volume_level(kal_uint8 const **buffer);

extern kal_bool l4cuem_test_mute_mode(kal_uint8 const **buffer);

extern kal_bool l4cuem_test_silent_mode(kal_uint8 const **buffer);

extern kal_bool l4cuem_test_vibrator_mode(kal_uint8 const **buffer);

extern kal_bool l4cuem_test_greeting_text(kal_uint8 const **buffer);

extern kal_bool l4cuem_at_query_is_charging(void);

extern kal_bool l4cuem_at_query_is_clam_open(void);

extern kal_bool l4cuem_at_ef_port_setting(l4cuem_at_ef_port_mode_enum mode, void *param);
extern l4cuem_at_ef_port_mode_enum l4cuem_at_get_ef_port_setting_mode(void);
extern void l4cuem_at_ef_port_setting_read_cnf_hdlr(void *data);
extern void l4cuem_at_ef_port_setting_write_cnf_hdlr(void *data);

#endif /* _UEM_AT_CMD_H */ /* uem_at_cmd.h */

