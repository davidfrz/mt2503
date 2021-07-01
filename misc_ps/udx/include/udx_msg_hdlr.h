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
 *  udx_msg_hdlr.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intended for UDX message handler.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef UDX_MSG_HDLR_H
#define UDX_MSG_HDLR_H

#include "kal_general_types.h"
#include "mmi2udx_struct.h"

#ifdef __UDX_SUPPORT__

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
/* Write your global variable here */

extern kal_bool g_udx_abort_op;

/***************************************************************************** 
 * Global Function 
 *****************************************************************************/

extern void udx_build_header_req(mmi_udx_build_header_req_struct *b_req);
extern void udx_build_data_req(mmi_udx_build_data_req_struct *d_req);
extern void udx_build_end_req(void);
extern void udx_build_abort_req(void);
extern void udx_parse_header_req(mmi_udx_parse_header_req_struct *h_req);
extern void udx_parse_body_req(mmi_udx_parse_body_req_struct *b_req);
extern void udx_parse_data_req(mmi_udx_parse_data_req_struct *data_req);
extern void udx_parse_data_rsp(kal_uint8 type, kal_uint16 seq);
extern void udx_parse_finish_ind(kal_bool is_full);
extern void udx_parse_abort_req(void);
extern void udx_enter_usb_mode(void);

#endif /* __UDX_SUPPORT__ */

#ifdef __MULTI_VCARD_SUPPORT__

/***************************************************************************** 
 * Global Function 
 *****************************************************************************/

extern void udx_build_vcard_req(kal_int32 src_id, mmi_udx_build_vcard_req_struct *build_req);
extern void udx_parse_vcard_req(kal_int32 src_id, mmi_udx_parse_vcard_req_struct *parse_req);
extern void udx_read_vcard_req(kal_int32 src_id, mmi_udx_read_vcard_req_struct *read_req);

#endif /* __MULTI_VCARD_SUPPORT__ */

#endif /* UDX_MSG_HDLR_H */

