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
 *   xyssl_debug.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This is module seclib trace map definition.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _XYSSL_DEBUG_H_
#define _XYSSL_DEBUG_H_

#include "wps_trc.h"

#define XYSSL_ENABLE_DEBUG

#ifdef XYSSL_ENABLE_DEBUG

#define XYSSL_LOG_MSG_ERROR(ret, state) {kal_trace(TRACE_GROUP_1, XYSSL_LOG_ERROR_CODE_WITH_STATE, ret, state);}
#define XYSSL_LOG_MSG_ERROR_STATE(state) {kal_trace(TRACE_GROUP_1, XYSSL_LOG_STATE, state);}
#define XYSSL_LOG_ERROR_MEM_ALLOC(size) {kal_trace(TRACE_GROUP_1, XYSSL_LOG_ERROR_MALLOC, size);}
#define XYSSL_LOG_ERROR_MEM_FREE(ptr) {kal_trace(TRACE_GROUP_1, XYSSL_LOG_ERROR_FREE, ptr);}
#define XYSSL_LOG_ERROR_SOC_RECV(read) {kal_trace(TRACE_GROUP_1, XYSSL_LOG_SOC_RECV, read);}
#define XYSSL_LOG_ERROR_SOC_SEND(write) {kal_trace(TRACE_GROUP_1, XYSSL_LOG_SOC_SEND, write);}
#define XYSSL_LOG_ERROR_GENERAL(str) {kal_trace(TRACE_GROUP_1, XYSSL_LOG_GENERAL, str);}
#define XYSSL_LOG(LOG_MSG_ID, ...) {kal_trace(TRACE_GROUP_1, LOG_MSG_ID, ...);}

#else

#define XYSSL_LOG_MSG_ERROR(ret, state)     do { } while( 0 )
#define XYSSL_LOG_MSG_ERROR_STATE(state)    do { } while( 0 )
#define XYSSL_LOG_ERROR_MEM_ALLOC(size)     do { } while( 0 )
#define XYSSL_LOG_ERROR_MEM_FREE(ptr)       do { } while( 0 )
#define XYSSL_LOG_ERROR_GENERAL(str)        do { } while( 0 )

#endif

extern void xyssl_adpssl_set_dbg_cb( void* param, int level, char *text);

#endif /* !_XYSSL_DEBUG_H_ */


