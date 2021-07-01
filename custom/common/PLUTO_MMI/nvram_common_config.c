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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * nvram_common_config.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file is for MTK to config the NVRAM settings.
 *
 * Author:
 * -------
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
 * removed!
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
 * removed!
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef NVRAM_NOT_PRESENT
#ifdef NVRAM_AUTO_GEN
#include "nvram_auto_gen.h"
#endif

#include "kal_general_types.h"
#include "MMI_features.h"

#include "nvram_default_audio.h"
#include "custom_mmi_default_value.h"
#include "custom_data_account.h"
#include "drv_features.h"
//#include "camera_para.h"

#include "nvram_defs.h"
#include "nvram_enums.h"
#include "common_nvram_editor_data_item.h"
#include "nvram_common_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_config.h"        /* NVRAM_APP_RESERVED */
#if defined(__NVRAM_COMPRESS_SUPPORT__) && !defined(NVRAM_AUTO_GEN)
#include "nvram_default_value.h"
#endif

#include "custom_srv_prof_defs.h"           /* SRV_PROF_ALERT_TYPE_RING */
#include "cbm_consts.h"                     /* CBM_DEFAULT_ACCT_ID */
#include "custom_phb_config.h"
#include "custom_wap_config.h"

#include "nvram_editor_data_item.h"

#ifndef __OPTR_NONE__
#include "op_custom_wap_config.h"
#endif

#ifdef __CLOG_STORAGE_BY_MMI__
#include "custom_calllog.h"
#endif

#ifdef __MMI_VUI_SHELL_SHORTCUTS__
#include "custom_shell_shortcuts_cfg.h"
#endif

#if defined(__MMI_FRM_INPUT_EVT__)	
#include "nvram_input_event_cfg.h"
#endif/*#if defined(__MMI_FRM_INPUT_EVT__)	*/

//custpack work around solution
#ifndef __NVRAM_SUPPORT_CUSTPACK__
#ifndef __UPDATE_BINARY_FILE__
extern const kal_uint8 NVRAM_EF_MMI_CACHE_BYTE_DEFAULT[];
extern const kal_uint8 NVRAM_EF_MMI_CACHE_SHORT_DEFAULT[];
extern const kal_uint8 NVRAM_EF_MMI_CACHE_DOUBLE_DEFAULT[];
#endif

extern kal_uint8 COMMON_NVRAM_EF_PHB_SOS_DEFAULT[];

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    extern mmi_phb_vip_contact_struct COMMON_NVRAM_EF_PHB_VIP_CONTACT_DEFAULT[];
#endif

 
#if defined(__TCPIP_OVER_CSD__)
    extern kal_uint8 COMMON_NVRAM_EF_CSD_PROFILE_DEFAULT[];
#endif

#if defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_EM_INET_APP_SLIM__)
/* Internet Application */
    extern nvram_em_inet_custpack_struct COMMON_NVRAM_EF_INET_CUSTPACK_DEFAULT[];
#endif

#ifdef __WAP_PUSH_SUPPORT__

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    extern nvram_push_wl_addr_struct COMMON_NVRAM_EF_PUSH_WHITE_LIST_DEFAULT[];
#endif

#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    extern nvram_push_bl_addr_struct COMMON_NVRAM_EF_PUSH_BLACK_LIST_DEFAULT[];
#endif
#endif

#ifdef WAP_SUPPORT
#ifdef __MMI_BROWSER_2__
    extern nvram_wap_bookmark_list_struct COMMON_NVRAM_EF_WAP_BOOKMARK_LIST_DEFAULT[];
#endif

#endif /* WAP_SUPPORT */

#ifdef __MMI_TETHERING_WIFI__
    extern nvram_ef_srv_tethering_wifi_hs_settings_struct COMMON_NVRAM_EF_SRV_TETHERING_WIFI_HS_SETTINGS_DEFAULT[];
#endif



#endif
//_______________________________
/*******************************************************
 *  Add include statement above this line
 *******************************************************/
#ifndef __OPTR_NONE__
#include "op_nvram_common_config.h"
#endif

#if defined(PLUTO_MMI) || defined(VENUS_MMI)
#include "mmi_res_range_def.h"
#include "mmi_cache_table.h"

#if (defined(__UPDATE_BINARY_FILE__) && !defined(__NVRAM_SUPPORT_CUSTPACK__)) 

kal_uint8 NVRAM_EF_MMI_CACHE_DEFAULT[NVRAM_CACHE_SIZE] = 
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

kal_uint32 NVRAM_EF_MMI_CACHE_BYTE_KEY_DEFAULT_R[NVRAM_MMI_CACHE_BYTE_KEY_SIZE * NVRAM_MMI_CACHE_BYTE_KEY_TOTAL / sizeof(kal_uint32)] =
{
	0x00000000,
	0x00000000
};

kal_uint32 NVRAM_EF_MMI_CACHE_SHORT_KEY_DEFAULT_R[NVRAM_MMI_CACHE_SHORT_KEY_SIZE * NVRAM_MMI_CACHE_SHORT_KEY_TOTAL / sizeof(kal_uint32)] =
{
	0x00000000,
	0x00000000
};

kal_uint32 NVRAM_EF_MMI_CACHE_DOUBLE_KEY_DEFAULT_R[NVRAM_MMI_CACHE_DOUBLE_KEY_SIZE * NVRAM_MMI_CACHE_DOUBLE_KEY_TOTAL / sizeof(kal_uint32)] =
{
	0x00000000,
	0x00000000
};

kal_uint32 const NVRAM_EF_MMI_CACHE_INIT_DEFAULT_R[] =
{
	0x12345678
};

#endif
#endif

#ifdef MRE_VERSION
#include "vmswitch.h"

#ifdef __MRE_CORE_SAFETY__
kal_uint8 const  NVRAM_VER_PKEY_EXT_DEFAULT[NVRAM_EF_MRE_PKEY_LIST_EXT_SIZE * NVRAM_EF_MRE_PKEY_LIST_EXT_TOTAL] = 
{
	0x33,0xED,0x1C,0xA2,0x54,0xA2,0x5C,0xCC,0xCB,0xB8,0x88,0x35,0xFD,0x69,0x33,0x29,0xC7,0x29,0x91,0x77,0xFB,0xF1,0xF6,0xAB,0x60,0x68,0x92,0xCD,0x0A,0xD9,0x16,0xC2,0xA1,0x77,0x36,0x8D,0x41,0x80,0x7A,0x7A,0x5C,0x7E,0x85,0x3C,0xF6,0xAC,0x4A,0xF7,0x6C,0xCD,0xA4,0xC6,0x25,0x06,0xA6,0xC5,0xC3,0x31,0x84,0xCE,0xFB,0xFA,0x4B,0x7C,0x69,0x5F,0x63,0x87,0xFF,0x78,0x9B,0x16,0xF8,0xA6,0xA6,0xA4,0x64,0xCC,0x89,0x05,0x4C,0x10,0xA5,0x4B,0x0C,0x4C,0x81,0xA7,0xAE,0x46,0x7C,0x7A,0x64,0x36,0x51,0xB3,0x11,0xE4,0x36,0x4F,0x81,0x9C,0x78,0x9B,0x6F,0x4B,0x76,0xE0,0xAF,0x50,0x68,0x0A,0x83,0x01,0x81,0x51,0x5E,0x5D,0xEE,0xA5,0x09,0x59,0xEB,0xD1,0xF6,0x81,0x8F,0x00,0x93,0xAD,0x21,0x6E,0x6C,0x92,0x22,0xC5,0x25,0x60,0xB0,0x44,0x8C,0x55,0x25,0x44,0x26,0xC1,0x05,0x56,0x5C,0xD9,0x53,0x94,0x4C,0x77,0x92,0xC2,0xB0,0x22,0x89,0xB5,0xE6,0xC2,0xB3,0xF6,0xCB,0x43,0xD5,0x32,0xC7,0x1D,0x40,0x83,0xE1,0x58,0xCF,0xBA,0x9F,0xFA,0xC8,0xF1,0x02,0xB7,0x42,0xD0,0x77,0x25,0x43,0x05,0xEA,0x7D,0x87,0x86,0xC4,0xBA,0xA2,0x95,0xB5,0x18,0x0F,0x7B,0xB2,0x73,0x62,0xBB,0x2F,0x20,0x9B,0xA5,0xBC,0x82,0xC1,0x6A,0xA2,0x8F,0x0F,0x17,0xBD,0xCA,0x8C,0x20,0x12,0x49,0xFE,0xCB,0xBC,0xF4,0x45,0xA0,0x99,0x5F,0x87,0xC9,0xC7,0x81,0xB9,0x1D,0xE7,0x3A,0x74,0xF1,0x54,0x33,0x16,0x42,0xDB,0x1B,0x14,0x2A,0xBD,0xA3,0xE4,0xDE,0xD8,0x15,0x2E,0x26,0xBF,0x94,0x03,0xE9,0x2E,0x79,0x87,0x41,0xD9,0xD4,0xD7,0x00,0xFA,0xC5,0x0B,0x4F,0x37,0xFE,0x05,0xAC,0x05,0xBF,0xCE,0x5F,0x53,0x35,0x20,0xD1,0x5D,0x95,0x49,0xD6,0xEB,0x5A,0xC8,0x0C,0x86,0x7F,0xB2,0xEA,0x54,0x7D,0x7E,0x6D,0x86,0x0D,0xC9,0x2F,0xA6,0x90,0xB7,0xFD,0xBA,0x5D,0x9D,0x22,0x8C,0x67,0x72,0x30,0xEA,0x03,0x57,0xDE,0xE7,0x9C,0x03,0xA5,0x51,0xD9,0x84,0x60,0x54,0x5B,0x4E,0x88,0xBC,0x87,0x2A,0xBB,0x4B,0x4E,0x4B,0xAB,0xED,0xBD,0x18,0x92,0xBA,0x26,0x3E,0x72,0x15,0x7E,0xDC,0xF0,0xE9,0x2C,0xCC,0xF8,0x3A,0x76,0x21,0x49,0x49,0x2A,0x08,0x7C,0x02,0xE1,0x01,0x4E,0x7A,0xD4,0xFA,0x55,0x06,0x38,0x24,0x4F,0xDB,0xB9,0x60,0x9E,0x6E,0x76,0x0E,0xAC,0x19,0x65,0x6E,0xEA,0xE9,0x6F,0x40,0x36,0xC4,0x01,0x2B,0x52,0x33,0xF7,0x41,0xF1,0xDB,0x6C,0xA9,0x9C,0xFC,0xA2,0x00,0x28,0x6F,0x4B,0x41,0x91,0xA1,0xF0,0x5E,0x49,0x17,0x38,0x11,0xB6,0xC0,0xB0,0xA6,0x59,0x33,0xEA,0xD5,0x80,0xE6,0x3C,0x28,0x41,0x08,0xED,0xCE,0x52,0x34,0x57,0x37,0xEA,0x69,0xB6,0x3A,0x1F,0xDB,0x22,0x51,0x21,0x5E,0xB7,0x01,0x6A,0xEF,0x6C,0x6D,0x80,0x13,0x58,0xA7,0x4F,0xAC,0xA7,0x7B,0xA7,0x25,0x11,0x6D,0x31,0x8B,0x28,0x74,0x23,0xD5,0x87,0x69,0xAD,0x16,0xDD,0x9C,0x0D,0xCC,0x7D,0x3B,0x10,0x39,0xEA,0xBE,0xEB,0x71,0x5A,0x05,0x3E,0x2E,0xE5,0xFA,0x2F,0xFE,0x15,0xC7,0x62,0x46,0x4D,0x22,0xEA,0x8E,0x1C,0xDA,0x73,0x2A,0xD1,0xAD,0x87,0xFE,0x83,0x72,0xA1,0x74,0xE1,0x95,0x7F,0x10,0xF0,0xC9,0x32,0xC1,0x00,0xB5,0xC7,0x38,0xBB,0xE4,0x17,0x4B,0x0C,0x8C,0x12,0x50,0x2D,0x3C,0x70,0x10,0xA7,0x2F,0x93,0x23,0xA5,0xCF,0xDD,0x5A,0xC7,0x15,0xE3,0x24,0x08,0x0A,0x54,0x1D,0x38,0xAF,0x1D,0x19,0x78,0x42,0x66,0xCA,0x4A,0xBB,0x46,0x33,0x09,0x2F,0xB8,0xAA,0x40,0x5C,0x27,0x12,0xDC,0x52,0x1E,0xAA,0xEE,0x0E,0x38,0xE1,0x3D,0x31,0x58,0xD1,0x30,0x0B,0x16,0xFF,0xBC,0x7E,0x99,0x07,0x80,0xD9,0x2D,0xA9,0xA3,0xFD,0x0D,0x90,0x92,0x12,0x47,0x72,0xA4,0xBA,0xBF,0xC0,0xBC,0x1E,0x31,0x58,0x14,0x52,0x0E,0x5B,0xEE,0x74,0xB8,0x01,0x41,0x21,0xEE,0xA5,0x30,0x56,0xC4,0x26,0x2D,0x96,0x38,0xEC,0x3A,0x22,0x78,0xE7,0xC2,0x1D,0xAC,0x9E,0x8B,0xEE,0x61,0x55,0x68,0x7E,0xC8,0x65,0x0C,0xDB,0x5E,0x60,0xAF,0x17,0xD2,0x65,0x08,0x36,0xEB,0x82,0x06,0x82,0x91,0xA9,0x5C,0xD2,0x78,0xBC,0x63,0xC4,0xDE,0x2D,0x9C,0x6C,0x2D,0x8D,0x62,0x71,0x26,0xDD,0x5F,0x6D,0x1C,0xA6,0x1B,0xBC,0x62,0x1B,0x5B,0x63,0xC3,0xA5,0x83,0x86,0x3D,0xEA,0xBF,0x52,0xDB,0xE0,0x48,0xB9,0xB0,0x3C,0x5B,0x44,0xDA,0x8B,0x19,0x1F,0x4A,0xCF,0xAA,0x83,0xF2,0xB8,0x6F,0x42,0xAE,0xD7,0xAD,0x05,0x09,0x7A,0xF4,0x5B,0x69,0x4C,0x94,0x80,0x2A,0xE9,0x96,0xF6,0x43,0x50,0x9D,0x37,0xE2,0x04,0x59,0xB0,0x69,0x63,0x80,0x08,0x0B,0xFA,0x87,0xD0,0xA9,0x6E,0xA4,0x0B,0xBD,0xF1,0xF9,0x1B,0x60,0x4F,0x3F,0xD8,0xFF,0x81,0x52,0xF2,0xBB,0xA8,0xA5,0x26,0x9D,0x9C,0x5A,0xA8,0xA7,0xA7,0x58,0x74,0x80,0xE8,0xB6,0x76,0xF8,0x70,0x8A,0x98,0xCF,0x41,0x88,0x74,0x4F,0xF6,0x9E,0xA2,0x8E,0x08,0x4C,0x64,0x46,0x0C,0x47,0xE6,0xE1,0x6B,0x86,0xBB,0x9F,0x7D,0xF0,0x57,0xD7,0xA6,0x34,

  0x9A,0xD1,0x3F,0x26,0xF5,0x67,0x02,0x6D,0x3C,0x33,0x14,0xC6,0xEE,0x62,0x13,0xDC,0x71,0xFC,0xC0,0x04,0x01,0xDC,0xD1,0xD1,0x8C,0x2F,0x4E,0x46,0x4B,0xB6,0x50,0xB6,0x6D,0x32,0x50,0x2F,0x3C,0x82,0x4E,0xA7,0x6E,0xE1,0x1D,0xFD,0x5A,0xDD,0x08,0xE4,0xB1,0x83,0x2D,0x21,0x5C,0x35,0x8F,0x08,0x39,0x5B,0x94,0xA4,0x6B,0x20,0xE6,0xA6,0x1C,0x17,0x70,0xF5,0xDB,0xAE,0x4B,0xAC,0xAA,0xD7,0x68,0xE1,0xB4,0x17,0xBE,0x12,0xC9,0xE1,0xF3,0xF3,0xD8,0x19,0x09,0x49,0x43,0xBD,0x0C,0x12,0x6B,0x2B,0xE8,0x65,0x35,0xAA,0x63,0x74,0xBB,0x60,0xAC,0x46,0x46,0xF0,0x1D,0x87,0x06,0x57,0x9F,0x0C,0x10,0x8C,0x67,0x1D,0x66,0x84,0x67,0x06,0x00,0xCE,0xC8,0xEF,0x73,0x64,0xA8,0x04,0xE3,0xE6,0xF6,0x02,0xFA,0x6F,0x77,0xA7,0x01,0x2C,0xA7,0x12,0x2B,0x06,0x4E,0x66,0xCE,0x4E,0x2C,0x43,0xF1,0x14,0x62,0x72,0xBA,0xE2,0xFA,0xA5,0x9E,0x52,0x30,0xBC,0x0A,0x85,0x67,0x11,0x68,0x07,0xDE,0xFA,0x0E,0x15,0xEE,0x6E,0x62,0x78,0x81,0x72,0xD5,0xDE,0xB1,0x25,0x55,0xE4,0xD8,0xF7,0xAB,0x60,0xA6,0x9C,0x10,0x04,0xFD,0xC9,0xFD,0xD0,0xC4,0x7A,0x44,0x79,0xAF,0x61,0xC6,0x12,0x65,0x08,0xF0,0xBD,0x81,0x82,0x7E,0x56,0x99,0xFE,0x02,0xA9,0x1B,0x3E,0x85,0xB7,0xA7,0x96,0xEE,0x3C,0x13,0x41,0xA5,0xC2,0x6E,0xB6,0x54,0x10,0x05,0xD7,0xCC,0x79,0x1F,0x95,0xA4,0x7E,0xB5,0x94,0x3D,0xF2,0x5C,0x05,0x0D,0x35,0x95,0xD2,0xF8,0x99,0x37,0xDD,0x57,0x29,0x4F,0x0A,0x59,0x98,0x6A,0xE8,0xBF,0x57,0x9A,0x66,0x04,0x35,0x4A,0xB0,0xEA,0xEB,0x4D,0x6F,0x9E,0xB1,0x86,0xB7,0xDE,0x32,0x11,0x93,0xCD,0x99,0x9B,0xF5,0x2C,0x3F,0x57,0x8F,0x69,0x08,0x64,0xCA,0xE0,0xF6,0x4E,0x15,0xDA,0xA4,0xB8,0xBD,0x1C,0x43,0xA2,0x4A,0xAD,0x3B,0xE2,0x9B,0x52,0x02,0x9E,0x60,0x3E,0x44,0xC9,0xEA,0xC4,0x8E,0xEE,0xC5,0xA9,0xF4,0xE7,0xD2,0x29,0x00,0x1E,0xA5,0x11,0x15,0x70,0xBE,0x56,0xFA,0xBA,0x1B,0x53,0xB9,0xC2,0xD3,0xDF,0x22,0xBC,0xA2,0x41,0xAF,0x9E,0x6E,0x1C,0x01,0x91,0x97,0xFF,0x1F,0xE3,0x29,0xA3,0xD9,0x0F,0x4C,0xD0,0x40,0x83,0x54,0x90,0xB6,0x2F,0x03,0xE7,0x4B,0x68,0xF4,0x22,0x22,0xAE,0xB5,0x64,0x29,0x22,0xB1,0x7D,0xE6,0x24,0x35,0xCC,0xE3,0x78,0x8E,0xA3,0xDA,0x34,0x70,0xC9,0x61,0xDB,0x6A,0xC5,0xC1,0x5C,0xA5,0xE3,0x60,0x11,0xD2,0xD8,0xFA,0x89,0xE1,0x51,0x2C,0x52,0x4B,0x69,0x68,0x05,0xD4,0x05,0x9F,0xBC,0x96,0x50,0xFA,0x80,0xF9,0xA5,0xD1,0xB0,0x05,0x72,0xD2,0xA0,0x1D,0x6A,0x80,0xDF,0x8F,0x89,0xDD,0x99,0x3D,0x2D,0x79,0xE3,0xDA,0x63,0x0D,0xF0,0x83,0x62,0xD8,0x08,0x9C,0x60,0x53,0x15,0x42,0x05,0xC3,0xFD,0xB4,0x58,0xD6,0xB8,0x59,0xCB,0x35,0x2A,0xA6,0x57,0xC5,0x3F,0xBA,0xF3,0xD1,0x05,0xB3,0xBF,0x31,0x9D,0xFA,0x1D,0xFE,0x35,0xE5,0xE1,0xC1,0x08,0xA7,0xB5,0x6D,0x2C,0xDB,0x6B,0x50,0xE7,0xCA,0xC2,0x96,0x12,0xEA,0xDE,0xD9,0x21,0x20,0xB7,0x5D,0xE7,0x20,0x31,0x9B,0xCB,0x71,0xDF,0x3F,0x44,0xA1,0xD7,0x10,0x93,0xED,0xC4,0xB2,0x38,0xBF,0x7C,0xB0,0x5A,0xBA,0x58,0x02,0x08,0xBD,0x66,0x29,0x5D,0x91,0x29,0x33,0x38,0x4E,0x99,0x75,0x44,0xBB,0xB1,0xA4,0x3E,0xA7,0xD1,0x01,0xAD,0xD7,0x32,0x40,0x96,0xE5,0x09,0xFE,0x0F,0xAD,0x3D,0xB9,0x00,0x44,0x67,0xCE,0x69,0x66,0xB4,0x6D,0x14,0x53,0xC5,0xAB,0x75,0x62,0x2C,0x74,0xE4,0xE5,0x9A,0xAC,0x68,0x8D,0x2C,0x3D,0x73,0xA7,0x18,0xA6,0x17,0x99,0xF8,0xC0,0xC3,0x67,0xBB,0xBE,0x94,0x69,0x29,0x6C,0x01,0xDD,0x01,0xF3,0x1F,0xA1,0x6C,0xDB,0xA8,0xA5,0xAB,0xFD,0x7C,0x8E,0xBF,0x6F,0x8E,0x29,0x96,0xD9,0x15,0xD9,0xAD,0xBB,0x5F,0x74,0xEC,0x5C,0x38,0xDB,0xE1,0x30,0xE2,0xEC,0xEF,0x19,0xF4,0xD5,0x46,0x87,0x31,0xBA,0x7B,0x87,0xF2,0x51,0xA7,0x7D,0x61,0x27,0x38,0x1E,0xB8,0x43,0x0F,0x6B,0x7F,0xA2,0x69,0xF1,0x45,0x55,0x13,0xA1,0x29,0x6C,0xB6,0xF2,0xC2,0x44,0x08,0x83,0x2C,0xEB,0x5E,0xA1,0x30,0x31,0xC2,0x22,0x1F,0x17,0x2E,0x34,0x79,0x1E,0x0E,0x4F,0x31,0xC3,0xD8,0x60,0x37,0xC1,0x7A,0x95,0x3E,0xFE,0xB3,0xF9,0x3B,0xB6,0xC7,0x9C,0x72,0x82,0x8C,0xCF,0x48,0xC2,0x6F,0xF1,0x5F,0xF5,0x6D,0x96,0x16,0x5C,0xFC,0x22,0x4E,0x16,0x05,0x79,0x08,0x05,0x90,0xA2,0xB9,0x9F,0x8C,0x56,0xB7,0x27,0x63,0x16,0xD3,0x08,0xC0,0x05,0x8F,0x43,0xFC,0x01,0xC8,0x53,0x02,0xDF,0x63,0xCD,0x1C,0x94,0x0E,0xDB,0x6F,0x0C,0x22,0xE3,0xF7,0x55,0x0D,0x3F,0xF6,0x09,0xC3,0x37,0xF3,0xF6,0xD1,0x76,0x03,0x28,0xB2,0x34,0xA2,0xC0,0x63,0x37,0x98,0x40,0xCB,0xAA,0xA2,0x1C,0x47,0xA8,0x8E,0xD3,0xC2,0xA5,0x8F,0x2A,0xE5,0x84,0x02,0xDD,0x3F,0x78,0x0C,0x8E,0x3A,0x6F,0xF8,0xEF,0x7A,0x00,0x5C,0x68,0x12,0x20,0x76,0xF1,0x98,0x0E,0x8C,0x41,

      0xA6,0xD1,0xA4,0x12,0xF9,0xC9,0x65,0xA6,0x18,0x3B,0x60,0xBD,0x5F,0x7A,0x3E,0x67,0xC5,0x5B,0xAE,0xA9,0x67,0x0C,0x9B,0xB2,0x0F,0xDC,0x0C,0x6F,0x72,0x90,0xBE,0xDF,0x8E,0x81,0xFB,0x52,0x0E,0xB3,0xD6,0x9B,0xB7,0x8D,0x13,0xD7,0x4C,0xAA,0x9E,0xDC,0x3D,0xF3,0xA0,0x84,0x0F,0x0B,0xB8,0xE8,0x17,0xCA,0x62,0xB7,0x66,0xD2,0xD2,0x1E,0x00,0x05,0x5C,0x9F,0xA8,0xF5,0x71,0x12,0xB6,0xB9,0x11,0xA4,0x9C,0x6F,0x9C,0xFB,0x20,0x04,0xCE,0xB4,0x15,0x0F,0x74,0x98,0xF8,0x45,0x7A,0x6D,0x8A,0xA8,0x6F,0x93,0x97,0x37,0x4D,0x1E,0x7E,0x2D,0x20,0xA3,0xB7,0x3C,0x78,0x06,0xFC,0x3F,0x48,0xE3,0xEC,0x29,0xF9,0x6D,0x53,0x93,0xCB,0x6D,0x23,0x7C,0x8A,0x1B,0xD5,0xE5,0x43,0x65,0xAD,0x4D,0xA8,0xB8,0xE8,0x2E,0xF3,0x8B,0x15,0xE2,0xFC,0x5B,0x86,0x74,0xC4,0x7A,0x3D,0xB0,0xFC,0x07,0xD5,0xE2,0x4D,0x11,0xB7,0x05,0xA5,0xF5,0x9D,0x65,0x6A,0x9B,0xA6,0xB4,0x30,0xDB,0x81,0x46,0x11,0xAF,0x5A,0xC7,0x70,0x2F,0x9D,0x8E,0x3C,0xC2,0x8A,0x16,0x5E,0xA5,0x0B,0xD9,0x9C,0x0F,0xA4,0x4D,0x83,0x95,0x24,0x11,0x64,0xDE,0x02,0x80,0xA2,0xA7,

	0xBA,0x54,0x58,0x14,0x99,0x95,0x91,0xFD,0xBA,0xEF,0xF8,0xE6,0x17,0x38,0xEF,0x0D,0x52,0x35,0xFD,0xE0,0xE9,0x0C,0x15,0xA9,0x9C,0x29,0xF2,0x48,0x5D,0xF9,0x17,0x09,0x4D,0x37,0x28,0x46,0x59,0xCF,0xDB,0xAB,0x23,0xAF,0x12,0x49,0x75,0x84,0x4A,0xFD,0xF4,0x80,0x2D,0xD8,0xFB,0xDF,0xEC,0x69,0x2C,0x0E,0x9A,0x4A,0xA8,0x29,0x31,0xF8,0xB1,0x62,0xFE,0xDE,0x7A,0x36,0x8C,0x1E,0x57,0xB2,0x4C,0x08,0x30,0x9C,0x4F,0xA7,0x3D,0xAB,0x1C,0x73,0x47,0xB9,0x66,0xC9,0x6A,0x7A,0x3C,0x1C,0x9F,0x06,0x81,0xE5,0xC6,0x0F,0xF1,0xCF,0xFD,0xF2,0xF5,0xB1,0x9E,0x4D,0x31,0xDA,0x0D,0x8B,0xDF,0xF0,0x5A,0x8C,0x6F,0xB7,0x86,0xC8,0x17,0x7C,0xA7,0x7F,0x81,0x99,0xE5,0xA1,0x3D,0x70,0x8F,0x9D,0x51,0xE7,0x40,0x4F,0x6A,0xD1,0x7F,0xEA,0xA1,0x5F,0x0D,0xC7,0xBF,0x3A,0x0C,0x85,0xC8,0xC0,0xB1,0xF4,0x88,0xCD,0x31,0xB5,0x56,0x92,0x78,0x96,0x6A,0x57,0x68,0x64,0xA0,0x9A,0x09,0x62,0x9F,0x15,0x32,0xB7,0xEC,0x4A,0xEB,0x45,0xF5,0x1C,0x4E,0x06,0x42,0x73,0x11,0xA2,0x96,0x5D,0x25,0x81,0xBC,0xAE,0x72,0x21,0xFF,0x7C,0xB3,0x83,0x28,0x38,0x7A,0x6E,0x3F,0x65,0xE4,0x8B,0xD1,0x12,0x9D,0xC9,0x73,0xAE,0x62,0xA2,0x9B,0xD7,0xDF,0xBB,0x45,0x45,0x38,0x61,0x56,0x03,0x72,0xAA,0xB3,0xC0,0x7F,0xC4,0xBA,0xAD,0xBF,0xC5,0xE4,0xF3,0x4C,0xFC,0x85,0xF3,0xEE,0xE6,0xDF,0x61,0x49,0xCE,0x4A,0xB7,0xCE,0xB5,0xC5,0x37,0x24,0xBD,0x03,0x1A,0x09,0xF8,0x85,0x35,0x43,0xF7,0xEB,0x7B,0x7F,0x26,0xE7,0xAC,0xCC,0x51,0xEB,0xF4,0x70,0x9B,0x8E,0x05,0xE9,0x70,0xCF,0xBD,0x81,0xE4,0x02,0xC5,0x9B,0xE1,0x46,0x83,0xA2,0xBE,0x6C,0x18,0x14,0xF2,0x20,0x47,0xC1,0x44,0x63,0xCC,0xF8,0xEB,0x46,0xB1,0x87,0x47,0xF1,0xD3,0xC1,0x6D,0x58,0x50,0xEA,0xA0,0x09,0xFD,0x78,0x70,0xDF,0x57,0xF8,0x89,0x78,0xC7,0x69,0x5B,0x10,0x53,0x45,0xE9,0xB6,0xB3,0x01,0x83,0xD3,0x27,0xC8,0xDA,0x13,0x75,0xE8,0xB7,0xB3,0x9B,0xB9,0x14,0x63,0xBB,0xC2,0x4A,0x71,0xFD,0xF2,0x0B,0x15,0x07,0x53,0x91,0x68,0xB0,0xD9,0xB0,0xFC,0xCC,0x91,0x15,0x83,0x1F,0x81,0xC4,0x4F,0xCD,0xFF,0x2A,0xF0,0x58,0x54,0xF7,0x76,0x5B,0x50,0x50,0x38,0x7E,0x78,0x70,0x68,0x3E,0x30,0x76,0xF0,0x77,0x09,0xE1,0xAA,0xC2,0xF4,0x2A,0xF4,0xEC,0x43,0x0A,0x98,0xAD,0xCF,0x30,0x7A,0xF5,0xDE,0x18,0x12,0xE7,0x99,0xFA,0xB2,0x58,0xA6,0xEF,0x6D,0x01,0xBB,0x26,0xDC,0x12,0x19,0x59,0x76,0xCF,0x88,0x08,0xCC,0x6F,0x24,0x1E,0xA3,0xDD,0x9D,0xCA,0xB5,0x4E,0xC5,0xAC,0xE7,0xD9,0x31,0xC8,0x6A,0x76,0xF2,0x10,0xF2,0xC3,0x95,0xEF,0x45,0x3E,0x99,0xC8,0x75,0xE8,0xCA,0x62,0x85,0x35,0x3A,0xA4,0x73,0x44,0x2E,0xD7,0xCB,0x81,0x03,0x2C,0x90,0x64,0xCB,0x81,0x51,0x4E,0x6B,0xA9,0xD8,0x45,0x55,0x5A,0x8C,0x32,0x24,0x36,0x00,0xA2,0x37,0x6B,0x80,0xFB,0xFC,0xDB,0xAD,0xC0,0x5E,0x04,0x58,0xCE,0x2C,0x8A,0xB6,0x04,0x31,0xF6,0x4F,0x84,0xA9,0xED,0xCF,0x12,0x1D,0x99,0x4A,0x16,0x4F,0x44,0x1A,0xEF,0x9E,0x22,0x2C,0x1C,0xF2,0xB1,0xF4,0x64,0x3F,0xA5,0x39,0x28,0x16,0x7F,0x3C,0x11,0xAE,0x84,0x95,0x7D,0xDB,0x14,0x1D,0xF5,0x65,0xCC,0x9B,0x71,0x48,0x27,0x42,0x96,0x95,0xBC,0xC5,0x68,0xC3,0x7B,0x1D,0x85,0x64,0xA0,0x5D,0xE3,0xC8,0x57,0xF8,0x86,0xDE,0x3E,0x00,0x6F,0x27,0xF3,0x46,0xE9,0xBD,0xBA,0x9A,0x33,0x68,0x11,0x34,0x21,0xEE,0xCC,0x22,0x0F,0x19,0xCA,0x33,0x4F,0xDE,0xF1,0x8F,0x09,0x96,0xDF,0x25,0x7F,0x9F,0x8F,0x21,0xF0,0xAE,0xCF,0x39,0xDA,0x24,0xAC,0xBF,0xD6,0x5F,0xFC,0x42,0xFE,0x8F,0xAA,0x9F,0x07,0x61,0x7A,0xCE,0x33,0x7C,0xF2,0x71,0x58,0x29,0x64,0x72,0x42,0x8E,0x17,0x59,0x73,0xB9,0x1B,0xD2,0xC4,0x08,0xC9,0x4D,0x28,0xD5,0x84,0x41,0x73,0x8B,0x9D,0x2D,0x58,0x34,0x78,0xE0,0x99,0x56,0x25,0x29,0x33,0x67,0x48,0xC4,0x4D,0xA8,0x5B,0xDB,0xD0,0xA1,0xA2,0xA2,0x18,0xCD,0x28,0x69,0xD5,0x78,0x7A,0x51,0x14,0x51,0x76,0x3D,0x28,0x54,0x80,0x7E,0x8A,0x9A,0xD6,0xA5,0xD5,0x35,0x84,0x6E,0xA4,0x0A,0xCC,0xF4,0xD9,0x80,0x15,0x05,0xE9,0xAA,0x12,0xB2,0x4A,0x85,0xDF,0x9E,0x9E,0x89,0x2B,0x8A,0x7C,0x40,0x97,0xE8,0xAE,0x0D,0x4E,0x40,0x23,0xFA,0x0D,0x02,0x95,0x4A,0xF0,0xF9,0x83,0xA9,0xE3,0x8C,0x19,0x21,0xE6,0x13,0xC2,0xFB,0x6E,0x61,0x7D,0x5F,0x0F,0x20,0xC1,0x43,0x17,0x57,0x6E,0x74,0xD9,0x27,0x59,0x0A,0x5C,0x9B,0x2B,0x7A,0x64,0x69,0x09,0x6F,0x10,0x98,0xF4,0x11,0x17,0x66,0xB8,0x44,0x1B,0x8E,0xB2,0x58,0x3B,0xF0,0x3A,0xF1,0x66,0x0F,0x4F,0xD8,0x48,0x34,0x80,0x0C,0xD7,0xFF,0xEA,0x7D,0x67,0xEC,0x82,0x70,0x72,0xD3,0x5A,0x22,0xD7,0x30,0x64,0x98,0x83,0x37,0x8C,0xD9,0x96,0xC9,0xD7,0xD2,0x9F,0x3B,0x2D,0x83,0x3E,

  0x5B,0x1E,0x5D,0x63,0x59,0xD2,0xD6,0x12,0x61,0x72,0xEE,0xA1,0x0B,0x74,0x89,0x07,0x52,0xEF,0x0C,0xE3,0xFA,0xE3,0xAA,0x05,0x85,0xD3,0x2B,0x65,0xDF,0xC0,0x0E,0x69,0x50,0xE9,0x04,0xFA,0x20,0x2A,0x79,0x53,0x3C,0x29,0x20,0x81,0x35,0x6A,0x3A,0x86,0xB6,0x36,0xEF,0xE9,0x81,0x3D,0xB4,0x9C,0xF5,0xBA,0x3E,0x20,0x4E,0x99,0x93,0x2C,0x61,0x99,0x1E,0x0B,0xC7,0xE8,0x4A,0xC1,0x95,0x10,0x5B,0x00,0x87,0xB6,0xF8,0x00,0x66,0x8E,0x5A,0x6F,0xBF,0xA1,0x88,0x2A,0x12,0x46,0x6D,0x24,0xD2,0x56,0x5D,0x18,0x53,0x03,0x9D,0x83,0xFD,0x82,0x14,0xB4,0xF2,0x92,0x41,0x6A,0xE1,0xEF,0x62,0x8B,0x8C,0x8F,0x3B,0x53,0x3C,0xB4,0x74,0x21,0xBD,0x1B,0x3D,0x19,0xE5,0xC6,0x6F,0xCF,0x16,0x1C,0x47,0x91,0x32,0xFE,0xB3,0xC8,0x00,0xE5,0x63,0x22,0xBA,0xD4,0x9F,0x5F,0x3C,0x91,0x5B,0x5C,0x3E,0x1F,0x16,0x36,0x87,0x0B,0x58,0xBD,0xF8,0x2A,0x80,0xB4,0x3D,0xE5,0x41,0xAD,0x6F,0xCB,0xBE,0xF6,0x2B,0x87,0xCA,0x02,0x06,0x66,0x6C,0xCC,0x3E,0x2A,0x4C,0xA7,0x53,0x9D,0xF6,0xB3,0x10,0xA0,0x61,0xB5,0xCA,0xFE,0x02,0xE6,0x11,0x68,0x3B,0xAF,0x8F,0x7E,0x08,0xF8,0x37,0xCD,0x58,0x18,0xEA,0xE5,0x86,0x96,0xD5,0xD4,0x95,0xAA,0xC8,0x84,0x21,0x2B,0xC4,0x57,0xE7,0x53,0x6E,0x71,0xAA,0x45,0xCE,0xAF,0xFA,0x9E,0x00,0xF6,0x7B,0xB6,0x95,0xD0,0xA5,0x16,0x08,0x54,0x78,0x6A,0x6D,0x0E,0x5D,0xCB,0x64,0xC4,0x3D,0x52,0x40,0x16,0x33,0x1D,0x9F,0x0B,0xC6,0x30,0xBE,0x37,0xBD,0xCF,0xF1,0xFD,0xE2,0x7A,0x9D,0x9B,0xA1,0x67,0x67,0x27,0x24,0xE9,0x87,0xDD,0x25,0x6E,0x78,0xD7,0x39,0x21,0xF8,0xAE,0x9B,0x6C,0x55,0x00,0x44,0x23,0x5C,0x07,0x96,0x51,0x72,0x4A,0x89,0x14,0x19,0x34,0x02,0xCF,0xAC,0x9C,0x13,0xB7,0x4A,0x47,0x80,0x49,0xB4,0x65,0x3B,0x79,0x8D,0x38,0xF0,0x10,0xF1,0x8A,0x22,0x8C,0x2B,0x73,0x35,0x1B,0xB7,0xCC,0x9B,0x7A,0x34,0x0A,0x44,0xEA,0xBC,0xF6,0x65,0x27,0x91,0xFE,0xD1,0xF7,0xA3,0xB4,0x3A,0x33,0xB4,0x28,0x57,0x08,0xF8,0xC2,0x21,0x3C,0x14,0xB9,0xD0,0xBB,0x5D,0x09,0x33,0xFB,0xE0,0x6C,0x1E,0x48,0x3C,0x66,0xB9,0x01,0xCB,0xB5,0xA4,0x03,0xD7,0x0A,0xB5,0x4D,0x88,0xF5,0x0E,0xAF,0x6B,0x04,0xF8,0x22,0xD8,0xE8,0xF1,0x42,0xC0,0x4E,0x9B,0x88,0xEA,0xF7,0xD7,0x8E,0xBB,0x6B,0x9C,0xB2,0x3D,0xC3,0x3C,0x7E,0x3C,0xA2,0x6D,0xCB,0x25,0x54,0xF1,0x01,0x61,0xA6,0xCC,0x42,0x01,0x15,0x21,0x57,0xE5,0xB0,0xDB,0xE6,0xFF,0x43,0x1A,0xFB,0x0B,0x73,0x9F,0x91,0x36,0x8E,0x71,0x03,0x81,0x53,0x69,0xD9,0x14,0x33,0x92,0xCC,0x80,0x49,0x3D,0xE5,0xD1,0xAF,0xFE,0xF1,0x2A,0x7A,0xA5,0x6D,0xBE,0x2E,0xDC,0x58,0x56,0x27,0xBA,0x60,0x28,0xF9,0x61,0x81,0x5B,0x9F,0xB6,0xAC,0x79,0x32,0x67,0x82,0xDB,0xC1,0x9F,0x9A,0x36,0xE7,0x1E,0xBE,0x66,0x9B,0x5C,0x6D,0x18,0x19,0x26,0xDA,0x85,0x51,0xF9,0x82,0xF0,0xA5,0x78,0xE6,0x16,0xE5,0x1B,0x5D,0xF3,0x77,0xB9,0x2C,0x32,0x6A,0xB2,0x80,0xDF,0x7C,0xAB,0xCA,0xF7,0x3B,0xA4,0x22,0x59,0x42,0x41,0xBA,0xA8,0x0B,0xFA,0xB7,0x62,0x03,0xC5,0xFC,0x4B,0xD6,0x61,0x04,0x2C,0x9B,0xDB,0x3B,0x78,0x86,0x88,0xEF,0xBF,0x26,0x19,0x15,0x62,0x44,0x98,0x1D,0xEC,0x38,0x62,0xA9,0xB9,0xC2,0xFB,0x26,0xD3,0x0E,0x6E,0x22,0x08,0xFF,0xDA,0xC7,0x7A,0xD6,0x6F,0xDB,0xB1,0x7D,0x48,0xEC,0x60,0xCA,0x12,0x13,0x7F,0x03,0xFB,0x80,0x43,0x59,0x2A,0xAF,0xF1,0xDF,0xF2,0x6D,0x77,0xDE,0xD4,0x48,0xDA,0x46,0x4A,0x22,0x9B,0x1A,0xB4,0x2F,0x95,0xE4,0x4E,0x44,0x7F,0x87,0xAF,0xD4,0xA5,0xDE,0x4E,0xB2,0x30,0x04,0x47,0x27,0xA9,0x5B,0xFF,0xE2,0x35,0xF7,0x05,0x87,0x66,0x06,0x4E,0xA4,0xDD,0x5B,0x53,0x7A,0x6E,0x5A,0x65,0xD5,0xA7,0x73,0x8D,0xDB,0x77,0x6A,0xB5,0x06,0x19,0x90,0x2B,0xF0,0x4B,0xC5,0x1D,0x84,0x90,0x34,0xC9,0x22,0xE2,0x38,0x8E,0x99,0xFB,0x25,0x2C,0x1E,0x78,0x6E,0xAC,0x81,0x42,0xC5,0x33,0x2C,0x5F,0xBB,0x6B,0x6B,0x89,0x41,0xEE,0x6B,0x85,0x2A,0x9D,0x2F,0x2E,0x24,0xE9,0x30,0x23,0xE3,0xDA,0x95,0x08,0xB2,0x67,0x3A,0xA5,0x6C,0x5B,0xAE,0xBA,0xB6,0xBE,0xF6,0x27,0x54,0x52,0xDD,0x01,0x3E,0x18,0x8B,0xC5,0x8F,0x1F,0x89,0x53,0x06,0x03,0x4F,0x41,0xD9,0x31,0xA6,0x00,0x83,0x0D,0xAE,0xF5,0x7F,0xE4,0x0D,0xE5,0x5A,0x79,0x2C,0xFF,0x73,0x2F,0xB4,0x01,0xEB,0x1D,0x62,0x6E,0x41,0x26,0x97,0x5F,0x1B,0xF6,0x71,0xD7,0x70,0xA0,0xF7,0x5C,0x7E,0xEA,0x18,0x0C,0x05,0x98,0x9B,0x66,0x06,0xC9,0xE4,0xBF,0xF4,0xE5,0xC2,0x9A,0x2A,0x20,0xBA,0xC5,0x93,0x38,0xF7,0x6E,0xF6,0x10,0x61,0xBA,0x67,0x72,0x46,0x00,0x94,0x48,0x0B,0xFF,0x13,0xF5,0x00,0x98,0x06,0xDB,0x17,0x70,0x74,0x28,0x94,0xE5,0x93,0xB7,0xF5,0x7D,0x1D,0x65,0x91,0x07,0xFE,

      0x02,0x0E,0x5C,0x17,0xA8,0x19,0x88,0xC8,0xAA,0x8B,0x1C,0x6C,0x10,0x15,0x9E,0xDF,0x04,0x9F,0x89,0xE4,0x7E,0x7A,0x1A,0x43,0xBF,0xA4,0xE5,0x72,0xC2,0x8C,0x26,0xA8,0x5E,0x57,0xCB,0xF2,0x7F,0xA1,0x17,0x2A,0x7F,0x61,0x16,0x36,0x85,0xC1,0x78,0xEB,0xAD,0x63,0xFF,0xDB,0x37,0x79,0xF1,0xCC,0x76,0x32,0xF3,0xC1,0x74,0xF2,0x58,0xF1,0x37,0x09,0xC2,0xF4,0x97,0x19,0x97,0x3C,0xD9,0x0E,0x5F,0x9E,0xD2,0x87,0x50,0x6F,0xDA,0xC7,0x77,0x51,0x9D,0xAE,0x75,0xDA,0x85,0xA6,0xDC,0x29,0xB1,0x33,0xFE,0x82,0x2E,0xFD,0x4C,0x5E,0x32,0xAC,0x99,0xEA,0xC7,0x6B,0xB5,0x7E,0x8B,0x97,0x7D,0x0F,0x6C,0x82,0xCA,0xD7,0x20,0x14,0x27,0x3A,0x16,0x0B,0xC5,0x29,0x8A,0xD4,0x46,0x3F,0x91,0x3E,0xA7,0x15,0x5A,0x29,0x02,0xBD,0xF6,0x96,0x04,0x04,0xF1,0xCA,0xE7,0x79,0x3D,0xB2,0x8B,0x2C,0xC5,0x63,0x1C,0x4D,0xCA,0x4A,0x71,0x5B,0xE7,0x60,0x42,0x60,0xFF,0x42,0x79,0x5A,0xB0,0xCB,0x5F,0x31,0x3F,0x6A,0x1B,0x3D,0x98,0xAE,0x03,0xCE,0xE1,0x9A,0x04,0x88,0xA7,0x3D,0xA8,0x50,0x8B,0x9D,0x62,0xDA,0x3C,0x8D,0xEC,0xD5,0x41,0xEF,0xC2,0xFA
};

kal_uint8 const NVRAM_MER_PKEY_MTK_DEFAULT[NVRAM_EF_MRE_PKEY_LIST_MTK_SIZE * NVRAM_EF_MRE_PKEY_LIST_MTK_TOTAL] = 
{
0xfb, 0x64, 0x04, 0x2e, 0x50, 0x1e, 0x6a, 0xb9, 0xb5, 0x67, 0xc7, 0x1e, 0x95, 0xd2, 0x78, 0x82, 
0xb0, 0x3e, 0xc1, 0x43, 0x50, 0x98, 0x7c, 0xc7, 0x53, 0x53, 0xab, 0x9c, 0x2e, 0x24, 0xee, 0x4b, 
0x42, 0xef, 0x57, 0x6b, 0x61, 0x85, 0x6d, 0x1b, 0x91, 0x9a, 0xf2, 0xac, 0xea, 0xc4, 0xec, 0x35, 
0x2f, 0x0b, 0x91, 0x81, 0xa1, 0x66, 0x13, 0x7a, 0x2a, 0xf2, 0x72, 0x78, 0xd2, 0x3f, 0xfb, 0x91, 
0x32, 0xc1, 0x12, 0xc6, 0x64, 0x4e, 0x4a, 0x53, 0x3d, 0x18, 0xd2, 0x6c, 0x5c, 0x7c, 0x8f, 0x2c, 
0x4c, 0x7e, 0xcf, 0x4c, 0x67, 0x63, 0x73, 0x74, 0x09, 0x1c, 0x62, 0x54, 0x26, 0x14, 0xa6, 0x67, 
0x8c, 0x22, 0x2c, 0x76, 0xa3, 0x2b, 0x59, 0xd8, 0x9d, 0x9a, 0xe1, 0x2d, 0x1a, 0x8e, 0xbc, 0x5f, 
0x20, 0x66, 0x48, 0xa0, 0xf3, 0x03, 0x87, 0x3b, 0x87, 0x0b, 0x66, 0x0e, 0x9a, 0x51, 0xa2, 0x94, 
0xf3, 0xc0, 0x1f, 0x02, 0x96, 0x9d, 0x4b, 0x8f, 0x86, 0x78, 0xf0, 0x2a, 0xa6, 0x5e, 0xc5, 0x1a, 
0xc1, 0xdd, 0x41, 0x23, 0x1d, 0x44, 0xcb, 0xdf, 0xcb, 0x66, 0x93, 0x5e, 0x5d, 0x1a, 0x1b, 0xd6, 
0xce, 0x24, 0xbd, 0xd9, 0x75, 0x91, 0xd9, 0x82, 0xdf, 0x95, 0x4f, 0x41, 0xcb, 0x1a, 0x15, 0x18, 
0xf4, 0xca, 0x25, 0x3c, 0x30, 0xcb, 0x35, 0x55, 0x7c, 0xc9, 0xaa, 0x71, 0x1d, 0x6a, 0xc0, 0x08, 
0x7f, 0x45, 0x3e, 0xc4, 0xbc, 0x0c, 0xd8, 0xef, 0x39, 0x6a, 0xfd, 0xa9, 0x0d, 0xda, 0xa7, 0x11, 
0xd2, 0x55, 0xbd, 0xfb, 0x40, 0x30, 0x90, 0x16, 0xe7, 0x6c, 0xdb, 0x38, 0xb3, 0xe0, 0x31, 0xac, 
0x4e, 0xf4, 0x1f, 0x57, 0xbe, 0x01, 0xa1, 0x33, 0x66, 0xb6, 0xbc, 0xfc, 0x0c, 0x0b, 0x5c, 0xeb, 
0x7a, 0xfb, 0x0f, 0x11, 0xee, 0x4c, 0x1e, 0x14, 0x8c, 0xb1, 0x95, 0x90, 0xdd, 0xfa, 0xfd, 0x18, 
0xef, 0xbb, 0xba, 0xd7, 0x1e, 0x79, 0x92, 0xae, 0x6f, 0x36, 0xed, 0x10, 0xe1, 0x60, 0x5b, 0xc1, 
0xc0, 0xdd, 0x2f, 0xa6, 0x94, 0x91, 0x17, 0xba, 0xce, 0x8e, 0x34, 0x8f, 0x6a, 0xc2, 0xa8, 0x99, 
0x0d, 0xda, 0x31, 0xd5, 0x95, 0x0e, 0xd6, 0xe2, 0x55, 0x0f, 0x1f, 0x7d, 0x6a, 0x37, 0x92, 0xdb, 
0x58, 0xaf, 0x6e, 0xff, 0x79, 0xec, 0x21, 0xa4, 0x85, 0x30, 0xd4, 0x99, 0x72, 0x60, 0x4e, 0xac, 
0x2d, 0x7d, 0x4c, 0x78, 0x7e, 0x66, 0x6c, 0x8d, 0x9e, 0x09, 0x55, 0xac, 0x8a, 0xb3, 0xa9, 0x83, 
0xe1, 0x90, 0x78, 0xb3, 0x31, 0x3b, 0x1a, 0x6b, 0xbf, 0xf2, 0xb5, 0x1c, 0xce, 0xff, 0x4c, 0x41, 
0xd6, 0x3f, 0x2a, 0x96, 0xef, 0x2e, 0x4d, 0xcb, 0xdb, 0xd6, 0x07, 0xf7, 0x3c, 0x80, 0x17, 0xc7, 
0x74, 0xb8, 0x88, 0xa1, 0xa7, 0x1a, 0xa5, 0xcf, 0x82, 0x9d, 0x32, 0xfa, 0xa5, 0x49, 0xbd, 0x3e, 
0xf5, 0xf2, 0xf7, 0xc6, 0xfc, 0x12, 0x6c, 0xe9, 0x06, 0x27, 0xac, 0x23, 0x5d, 0xc6, 0xab, 0x3c, 
0xb2, 0x4a, 0xaa, 0xcd, 0xbf, 0xad, 0x17, 0xe8, 0x18, 0xea, 0x1f, 0x9e, 0xea, 0x79, 0xc3, 0x2f, 
0x41, 0x51, 0xa5, 0xa8, 0xa2, 0xf1, 0xcf, 0x7c, 0xcb, 0x65, 0x4f, 0x17, 0x6b, 0x70, 0xf5, 0x3c, 
0x1c, 0x1a, 0xa1, 0x51, 0x59, 0xa3, 0xfb, 0x5d, 0x27, 0x79, 0x2c, 0x96, 0xb0, 0x11, 0x04, 0x22, 
0x2a, 0x92, 0x22, 0x12, 0xcb, 0x99, 0x54, 0xbe, 0x50, 0x64, 0xac, 0x7b, 0x69, 0xbf, 0xef, 0xe3, 
0xb2, 0x4b, 0x9a, 0xa7, 0x8a, 0xc9, 0x87, 0x55, 0xcd, 0xf2, 0x52, 0x0b, 0x5e, 0xaa, 0xe3, 0xfb, 
0x36, 0x07, 0x30, 0x7f, 0xf1, 0x50, 0xf7, 0x3e, 0xd3, 0x5e, 0x2b, 0xa0, 0x43, 0x28, 0x85, 0xe6, 
0x76, 0xb2, 0x07, 0x97, 0x36, 0x99, 0xf1, 0x7b, 0xd0, 0xcc, 0x93, 0xa0, 0x3b, 0xfb, 0x43, 0x93, 
0xce, 0x59, 0x49, 0xa2, 0xa5, 0x0e, 0xb6, 0xc9, 0xd1, 0x95, 0x6d, 0x8a, 0xee, 0x9e, 0xc7, 0xce, 
0x94, 0x91, 0xa8, 0x61, 0xf4, 0x6f, 0x82, 0x49, 0x46, 0xf7, 0xbb, 0xfe, 0x51, 0xed, 0x61, 0xc8, 
0xc0, 0x70, 0x06, 0x68, 0x0a, 0x9d, 0xc7, 0x73, 0x27, 0x1a, 0x1f, 0x54, 0x50, 0xd7, 0xe8, 0xd9, 
0xcd, 0x53, 0x54, 0x42, 0xe1, 0x25, 0xb6, 0x8d, 0xd5, 0x02, 0x74, 0x0e, 0x49, 0x1d, 0xfa, 0xf7, 
0x0e, 0xa8, 0xdd, 0x23, 0xa6, 0x59, 0xd1, 0x2c, 0x17, 0xdc, 0x86, 0x0c, 0x5b, 0x51, 0xba, 0xf8, 
0xd5, 0xde, 0x43, 0x97, 0x8c, 0x39, 0xd3, 0xe2, 0x04, 0x90, 0x45, 0xa5, 0x61, 0x7d, 0x67, 0xe3, 
0xff, 0x5c, 0x86, 0xef, 0x8f, 0x59, 0x22, 0xdb, 0xf5, 0x77, 0x0a, 0x46, 0x68, 0xcc, 0x39, 0x34, 
0xeb, 0x3d, 0x18, 0xfe, 0x31, 0xa3, 0x7a, 0x6b, 0x82, 0xca, 0xe8, 0xba, 0x26, 0x86, 0x35, 0x2b, 
0x17, 0x11, 0xb7, 0xa4, 0x1f, 0x03, 0x19, 0xfb, 0x90, 0x7a, 0x33, 0x7f, 0xf0, 0x22, 0xa3, 0x37, 
0x2e, 0x12, 0xc4, 0x00, 0x2c, 0x8f, 0xa8, 0x45, 0xbe, 0xe9, 0x2e, 0x18, 0x16, 0xd5, 0x09, 0xb5, 
0x02, 0x27, 0x43, 0x51, 0x85, 0x1a, 0xdb, 0xfc, 0x9c, 0x5c, 0x16, 0x68, 0xb8, 0xc9, 0x62, 0x5e, 
0x25, 0x3a, 0xcf, 0xd6, 0x77, 0xac, 0xf0, 0x2c, 0x58, 0xa0, 0x77, 0x98, 0x37, 0x22, 0xe3, 0x6e, 
0xa6, 0x57, 0x56, 0x88, 0x60, 0x17, 0x9d, 0xdf, 0xae, 0x0e, 0x58, 0x7c, 0x4e, 0x3e, 0xdb, 0xd9, 
0x8f, 0x6c, 0xaa, 0x9a, 0xdb, 0x06, 0x19, 0x5a, 0x86, 0x9b, 0x09, 0x70, 0xb6, 0x0d, 0x76, 0x5e, 
0x70, 0xe1, 0x43, 0xee, 0x87, 0xc6, 0x7f, 0x12, 0x1f, 0xe0, 0x0e, 0x74, 0xcf, 0xa0, 0x9a, 0xf0, 
0x25, 0xf3, 0x62, 0xd8, 0x92, 0x71, 0x7c, 0x80, 0x33, 0x30, 0x78, 0xe0, 0xd7, 0xea, 0x0e, 0x8a, 
0x2b, 0xd6, 0xf0, 0x8a, 0x04, 0xe6, 0x43, 0x32, 0x0c, 0xd9, 0xa6, 0x42, 0xc2, 0xe0, 0xe4, 0xf7, 
0x23, 0x89, 0x06, 0x90, 0xf1, 0x8e, 0xeb, 0x8c, 0xd4, 0x23, 0x30, 0xda, 0x40, 0x30, 0x79, 0x96, 
0x8c, 0x30, 0x75, 0x87, 0x3c, 0x39, 0x2a, 0x00, 0xdd, 0x07, 0x27, 0xd7, 0x51, 0x6c, 0x47, 0x07, 
0x35, 0x38, 0x51, 0xda, 0x28, 0xd3, 0xe0, 0xba, 0xe6, 0x89, 0x49, 0xb4, 0xeb, 0x83, 0xe2, 0x09, 
0xf8, 0xa5, 0x79, 0xe0, 0x3f, 0xa1, 0xf8, 0xc4, 0x83, 0xb4, 0x34, 0xff, 0xbf, 0xa7, 0x98, 0x42, 
0x5d, 0x2b, 0x11, 0x77, 0xba, 0x40, 0x1a, 0xbd, 0xe3, 0x77, 0xcc, 0x06, 0x3d, 0x06, 0x22, 0xf6, 
0xb2, 0xb0, 0xce, 0xab, 0x76, 0xd3, 0x91, 0xfe, 0x04, 0x37, 0x6c, 0x69, 0xfb, 0xd6, 0xb6, 0x4a, 
0x2b, 0xee, 0xd6, 0xff, 0x6c, 0xe6, 0x3b, 0x48, 0xd0, 0x38, 0x5c, 0xba, 0xfc, 0x7d, 0x0f, 0xc1, 
0x33, 0xb6, 0xf2, 0x2b, 0x90, 0x7f, 0x66, 0x0f, 0x0a, 0xe7, 0x89, 0xd6, 0x94, 0x38, 0x36, 0xec, 
0xee, 0xe3, 0xb4, 0x5d, 0x86, 0x0a, 0x81, 0xfa, 0xb2, 0xe1, 0x2e, 0xca, 0x9b, 0xb2, 0x66, 0x89, 
0x14, 0xb4, 0xa8, 0x15, 0x4e, 0xab, 0x9b, 0xc7, 0xae, 0x93, 0x44, 0x95, 0x3b, 0xb6, 0xed, 0x96, 
0x2e, 0xe3, 0x8f, 0x06, 0x2c, 0x16, 0xc5, 0x79, 0x1f, 0xa6, 0xbf, 0x2e, 0x1f, 0x8b, 0x7a, 0x14, 
0x92, 0x9f, 0x47, 0x4b, 0xb9, 0x94, 0x1f, 0x9b, 0xbd, 0xc1, 0x96, 0x7a, 0xa8, 0x52, 0x78, 0xd5, 
0x74, 0xa6, 0xd2, 0x23, 0x64, 0x39, 0x44, 0x97, 0xe6, 0xdb, 0x75, 0x32, 0x40, 0x06, 0xc5, 0x04, 
0x6d, 0x0c, 0xf4, 0xfe, 0xa5, 0x59, 0xf5, 0x70, 0x0c, 0x61, 0xa9, 0xf3, 0x65, 0xcd, 0x9f, 0x80, 
0x9f, 0x9b, 0x29, 0x34, 0x8b, 0x93, 0x46, 0x15, 0xe9, 0x8d, 0xe5, 0xba, 0x43, 0x6c, 0x9d, 0x7f, 
0x70, 0x84, 0xd4, 0x18, 0x5b, 0x94, 0x64, 0x94, 0x92, 0x1b, 0x4d, 0xfc, 0x64, 0xe4, 0x9f, 0x83, 
0x6f, 0xc8, 0xec, 0xea, 0xa3, 0x64, 0x3d, 0x2e, 0xd4, 0x2b, 0x82, 0xff, 0x9b, 0x0d, 0x90, 0xe8, 
0xf5, 0xfe, 0x69, 0x02, 0xf2, 0xec, 0x8e, 0x68, 0xcb, 0x4c, 0xfc, 0x69, 0xb8, 0xad, 0x53, 0x96, 
0x0a, 0x99, 0x68, 0x23, 0x8c, 0x23, 0x48, 0x76, 0x42, 0x1d, 0xbb, 0x6b, 0x4c, 0xf4, 0xd9, 0x67, 
0x6b, 0x2c, 0x41, 0x9c, 0x08, 0x2f, 0xcf, 0xf8, 0xb5, 0x81, 0x82, 0x08, 0xa1, 0x73, 0xe9, 0x65, 
0xda, 0xae, 0x23, 0x7c, 0x5a, 0x61, 0xda, 0x12, 0x60, 0xa6, 0xb5, 0xbc, 0x8f, 0xf2, 0x0e, 0x33, 
0xc9, 0x9f, 0x27, 0x0b, 0xbc, 0x04, 0x58, 0x9b, 0xf2, 0xca, 0xf5, 0xd1, 0x36, 0xda, 0xb3, 0x8a, 
0xbf, 0xfd, 0xd5, 0x24, 0xa5, 0x92, 0x69, 0xd4, 0x4f, 0x94, 0xb4, 0x29, 0xd0, 0x9c, 0x4b, 0x54, 
0xbe, 0x47, 0x35, 0x0e, 0x36, 0x4d, 0x20, 0x09, 0x3a, 0x8c, 0xe8, 0xa7, 0xbf, 0xbb, 0x7c, 0x66, 
0x56, 0xde, 0x01, 0xd9, 0x8c, 0x36, 0xa7, 0x22, 0xe0, 0xd2, 0x6e, 0x5a, 0x28, 0x03, 0x92, 0x15, 
0x30, 0xfd, 0x6e, 0x23, 0xbe, 0x2a, 0xa8, 0x6d, 0x27, 0x7d, 0x1b, 0x2b, 0x56, 0xd4, 0x50, 0x1b, 
0x80, 0x95, 0xa5, 0x57, 0x85, 0xda, 0xb4, 0xf9, 0x3d, 0xe8, 0xf9, 0x9a, 0xa0, 0x88, 0x50, 0x9d, 
0xc7, 0xb0, 0x58, 0xea, 0x9b, 0xbb, 0xc7, 0xec, 0x59, 0x84, 0x88, 0x57, 0x38, 0xaf, 0x55, 0xfa, 
0x92, 0x01, 0xf7, 0x80, 0xfb, 0xd4, 0x6e, 0x65, 0x2c, 0xd1, 0xe0, 0xbf, 0x55, 0xb7, 0x26, 0x36, 
0xe4, 0x99, 0xfc, 0x92, 0x0c, 0xd5, 0x6d, 0x98, 0x46, 0x6b, 0x1f, 0xd6, 0xd1, 0xef, 0xa8, 0x3c, 
0x84, 0xc3, 0x72, 0xca, 0x7d, 0x3a, 0x76, 0xf0, 0x28, 0xef, 0xad, 0xbc, 0xa2, 0xfc, 0x65, 0xcc, 
0x46, 0xed, 0x55, 0xa7, 0x98, 0xeb, 0x83, 0x8d, 0xc0, 0xfc, 0xd2, 0x39, 0xbb, 0x85, 0x81, 0xcb, 
0x50, 0x4a, 0x6d, 0x02, 0x28, 0xbe, 0x59, 0x05, 0xd6, 0x2a, 0xcd, 0xc8, 0x23, 0xe2, 0xbb, 0xbb, 
0xa7, 0xd6, 0xb1, 0x65, 0xd2, 0x56, 0x59, 0xd0, 0x79, 0x74, 0x3a, 0x59, 0x5b, 0x0e, 0x27, 0x4b, 
0xbf, 0x7c, 0x47, 0xf6, 0xba, 0x36, 0x7e, 0x93, 0xbe, 0x5f, 0x64, 0xa4, 0x69, 0xd4, 0x62, 0x96, 
0x0d, 0x2e, 0x5a, 0x54, 0x2b, 0x7c, 0x4e, 0x92, 0xf3, 0xec, 0x62, 0x77, 0xb9, 0xea, 0x6c, 0xb1, 
0xde, 0xc5, 0x56, 0xaf, 0xde, 0xd8, 0xa9, 0xed, 0x86, 0x64, 0x2f, 0xc0, 0xdc, 0xbb, 0xab, 0x79, 
0x96, 0xc1, 0x28, 0xf8, 0x52, 0x55, 0x1b, 0x28, 0x3c, 0x42, 0x88, 0xb4, 0xd2, 0xb0, 0x47, 0x30, 
0x40, 0x3e, 0xa5, 0xf7, 0xd2, 0x5b, 0xa2, 0x9c, 0x82, 0x1f, 0x32, 0x4c, 0x32, 0x46, 0x88, 0x35, 
0x21, 0x89, 0x3e, 0x80, 0xb8, 0xe0, 0x04, 0x32, 0xb0, 0x3d, 0x29, 0x7e, 0x4d, 0x9d, 0x1b, 0x6f, 
0xb5, 0x8e, 0xd0, 0x6d, 0xf0, 0x15, 0x42, 0x5e, 0x99, 0x3c, 0xee, 0x21, 0xf3, 0x10, 0x23, 0xaf, 
0x8a, 0x41, 0x44, 0x7c, 0x7b, 0x56, 0xdc, 0x0e, 0x7d, 0x66, 0x27, 0x8d, 0x5a, 0x16, 0x76, 0xfc, 
0x78, 0xc6, 0xe0, 0x97, 0x94, 0x0c, 0x2f, 0xc7, 0xc1, 0xe4, 0x98, 0xb3, 0xb5, 0x6c, 0xa3, 0xea, 
0x39, 0x00, 0x5b, 0x7f, 0x1f, 0x10, 0x2c, 0x8e, 0x59, 0xc6, 0x1e, 0xff, 0xf6, 0xd2, 0xe5, 0xf2, 
0xe9, 0xe3, 0x76, 0x6b, 0xdf, 0xb2, 0xaa, 0x75, 0x5e, 0x7a, 0x8b, 0xd0, 0x68, 0x06, 0x39, 0xab, 
0x99, 0x1e, 0xc0, 0x53, 0x66, 0x57, 0x28, 0xf4, 0x43, 0x93, 0x71, 0x6d, 0x2d, 0x96, 0xdf, 0xde, 
0x31, 0x94, 0x82, 0xa1, 0x82, 0xff, 0x02, 0xb8, 0x20, 0xf9, 0xb1, 0x7a, 0xb0, 0x20, 0x09, 0x76, 
0xe2, 0x4c, 0xfa, 0xbf, 0xef, 0x1e, 0xe5, 0x82, 0x30, 0xde, 0x5a, 0xbd, 0xb0, 0x26, 0x49, 0x58, 
0x58, 0xef, 0xd5, 0x22, 0x73, 0x36, 0x41, 0x2e, 0x46, 0xab, 0x5c, 0x81, 0x02, 0xed, 0x4b, 0x14, 
0xa3, 0x31, 0xaf, 0x98, 0x11, 0xc0, 0xe7, 0xc7, 0x43, 0x7c, 0x06, 0xcd, 0xcb, 0x94, 0xaa, 0xf0, 
0xf6, 0x82, 0x7c, 0xe3, 0xa5, 0x82, 0x88, 0xc9, 0x4c, 0xdc, 0xa6, 0x57, 0x95, 0x15, 0x63, 0x47, 
0xfd, 0x03, 0xeb, 0x8c, 0x21, 0xc2, 0x4c, 0xd8, 0x94, 0xed, 0x9c, 0xdc, 0x97, 0xf0, 0xc8, 0x5d, 
0x23, 0x87, 0x82, 0x4b, 0x51, 0xab, 0x2d, 0xad, 0x6a, 0xd8, 0x83, 0xcd, 0xb8, 0x6b, 0xb9, 0x9b, 
0x28, 0x31, 0x59, 0x1e, 0x8b, 0x63, 0x2a, 0x65, 0xbf, 0x65, 0x00, 0x6e, 0xf8, 0x98, 0x49, 0x76, 
0x83, 0xf8, 0x33, 0xf1, 0x8c, 0xa0, 0x57, 0x4a, 0x07, 0x00, 0xde, 0xca, 0xcb, 0x4e, 0xb5, 0x9e, 
0x04, 0xb5, 0xa8, 0x5d, 0x88, 0x1a, 0x25, 0xf5, 0xc0, 0xe8, 0xea, 0x3b, 0xac, 0x40, 0xd9, 0x1e, 
0x92, 0xd7, 0x01, 0x27, 0xa2, 0x8e, 0x72, 0x95, 0x25, 0xa9, 0xcf, 0xfc, 0x18, 0xec, 0x0d, 0x26, 
0x3a, 0x36, 0x16, 0x28, 0x13, 0xb0, 0x74, 0x24, 0xc3, 0x5a, 0xb3, 0x4f, 0x5f, 0x05, 0xd2, 0x03, 
0x04, 0xd3, 0x0b, 0xb9, 0x97, 0xe8, 0x67, 0xca, 0x04, 0x85, 0xce, 0xad, 0xbe, 0xba, 0xe3, 0x77, 
0x55, 0x0d, 0x4e, 0x8e, 0xcb, 0xba, 0x7a, 0x1a, 0x75, 0x1a, 0x3b, 0xf8, 0x6f, 0x7e, 0xf2, 0x05, 
0x0e, 0x95, 0xcd, 0x82, 0xa8, 0x44, 0xb6, 0xf5, 0xbc, 0x8e, 0x28, 0x3f, 0x58, 0xca, 0x08, 0x7c, 
0x4f, 0x4b, 0xc1, 0x64, 0xd4, 0x68, 0x73, 0x9f, 0x98, 0x35, 0x36, 0x7a, 0xa4, 0x01, 0x68, 0x1b, 
0x3c, 0xb9, 0xdf, 0x9f, 0xb8, 0xdf, 0xef, 0x37, 0xe1, 0x34, 0xd7, 0x04, 0xda, 0x69, 0xe1, 0xa2, 
0x80, 0x9f, 0x08, 0x78, 0xac, 0xb6, 0xc5, 0x2a, 0xa4, 0x07, 0x1f, 0xa2, 0x30, 0xa2, 0x22, 0xfa, 
0xef, 0x06, 0x50, 0xd3, 0xf5, 0x82, 0xba, 0x60, 0x67, 0xdb, 0x1d, 0x87, 0x0b, 0xf7, 0x53, 0x34, 
0x4e, 0xe7, 0x84, 0x5b, 0xc0, 0x3f, 0xb9, 0x9d
};

kal_uint8 const NVRAM_MER_PKEY_1024BIT_DEFAULT[192] = 
{
	0xE8, 0x03, 0x00, 0x00, 0xE8, 0x03, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
	0xA8, 0xCC, 0xF1, 0xE1, 0xE5, 0x6C, 0xDA, 0x05, 0xC1, 0xD1, 0x57, 0xAB, 0x03, 0xAE, 0xCD, 0x46,
	0xB2, 0x67, 0x70, 0x56, 0x11, 0x74, 0xEE, 0x3B, 0x04, 0x73, 0xB9, 0x7F, 0xF8, 0x5B, 0x9E, 0x87,
	0x7C, 0xD5, 0x34, 0x3A, 0xFD, 0x25, 0xAF, 0xC4, 0x2B, 0x3B, 0x96, 0xB5, 0xC5, 0x5C, 0xD3, 0x5F,
	0x93, 0xF7, 0x53, 0xEE, 0x4B, 0x66, 0xFA, 0xEA, 0x88, 0x54, 0x41, 0xE2, 0xA7, 0xF4, 0xDB, 0xC6,
	0x70, 0x19, 0x20, 0x58, 0x5C, 0x06, 0xF9, 0xA1, 0xFE, 0xC5, 0xB0, 0x1A, 0xB7, 0xC4, 0x68, 0x97,
	0xC9, 0xBE, 0x5B, 0xCF, 0x3D, 0xA3, 0x04, 0x55, 0x6B, 0xDF, 0xFC, 0xD5, 0x0E, 0xBF, 0x12, 0x4B,
	0x37, 0xD2, 0xA1, 0xB1, 0xDC, 0x92, 0xA1, 0x79, 0xA1, 0xF1, 0xFF, 0x29, 0xB5, 0x08, 0x27, 0xF1,
	0x16, 0x96, 0x4D, 0x40, 0x69, 0x68, 0x25, 0xA0, 0x77, 0x03, 0xC5, 0x4B, 0x3B, 0xCF, 0xD6, 0x99,
	0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xee, 0x07, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 
	0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#endif

#ifdef __MRE_CORE_SANDBOX__
kal_uint8 const  NVRAM_VER_SYM_ENTRY_EXT_DEFAULT[NVRAM_EF_MRE_SYM_ENTRY_LIST_EXT_SIZE] = 
{
	0x1d, 0x85, 0xcb, 0x59, 0x8c, 0x5e, 0xae, 0xff, 0x49, 0x72, 0xac, 0xbc, 0xe1, 0x23, 0x48, 0x14, 
	0x61, 0x33, 0xd2, 0x26, 0x1c, 0xa2, 0x43, 0xb1, 0x0e, 0xf1, 0x19, 0x4e, 0xef, 0xcb, 0x9c, 0x56, 
	0x57, 0xa1, 0x2b, 0x0a, 0x17, 0xfd, 0xb6, 0x5d, 0x50, 0xf7, 0x47, 0x67, 0xdd, 0x91, 0x66, 0x53, 
	0x6a, 0xb2, 0x97, 0x01, 0x97, 0xe6, 0xe9, 0xc8, 0x50, 0x0c, 0x4a, 0xff, 0xd9, 0xee, 0x86, 0xdb, 
	0x63, 0x94, 0x36, 0x89, 0xd6, 0xd5, 0x84, 0x26, 0x7d, 0x4f, 0x60, 0xe2, 0x21, 0x90, 0x07, 0x7f, 
	0x2a, 0x4b, 0x7f, 0xbe, 0xee, 0xa6, 0x08, 0xdd, 0xdf, 0x1b, 0xd9, 0x5f, 0x2c, 0xf4, 0x03, 0x32, 
	0x3f, 0x47, 0xa0, 0xd1, 0xaa, 0x6b, 0x96, 0x68, 0x8c, 0x2a, 0x23, 0x6c, 0x81, 0xf8, 0x67, 0xdb, 
	0x02, 0xbe, 0xc5, 0xd9, 0xcd, 0x01, 0x01, 0xf9, 0x0d, 0x3f, 0x5e, 0x41, 0xa2, 0x4d, 0x41, 0x5e, 
	0x2e, 0xf2, 0x52, 0x16, 0x02, 0x69, 0xaf, 0x8e, 0x41, 0x11, 0xac, 0xba, 0xe9, 0x12, 0x98, 0xa9, 
	0x58, 0x10, 0x92, 0x4a, 0x73, 0xaa, 0x64, 0x52, 0xee, 0x0c, 0x2d, 0x38, 0x39, 0x98, 0xbc, 0x2c, 
	0xab, 0x46, 0xce, 0x93, 0x63, 0xd4, 0x5b, 0xa8, 0x35, 0x11, 0xf9, 0x61, 0x9c, 0x7a, 0xf9, 0xcf, 
	0x0c, 0xf0, 0x5d, 0x08, 0x2c, 0x9a, 0x03, 0x40, 0x2e, 0x41, 0x51, 0x94, 0x47, 0x93, 0x13, 0x27, 
	0x4e, 0xd5, 0xad, 0xaf, 0x9c, 0x86, 0xd7, 0x1c, 0x16, 0xcc, 0x0e, 0x6d, 0xbc, 0xa1, 0x73, 0x83, 
	0x95, 0xd5, 0x16, 0xd4, 0x7d, 0xc2, 0x81, 0xbe, 0xec, 0xa4, 0x8a, 0x30, 0x60, 0x61, 0xb8, 0x08, 
	0x95, 0xa0, 0x98, 0x1c, 0xfc, 0xf5, 0x77, 0x8e, 0xf4, 0xb8, 0x5e, 0xe2, 0x30, 0x5c, 0x59, 0xa3, 
	0x63, 0xea, 0xcb, 0x0c, 0x34, 0xa3, 0x04, 0x53, 0x3f, 0xd9, 0x27, 0x74, 0x3e, 0xd6, 0x33, 0x49, 
	0x27, 0xd8, 0xc5, 0x80, 0x55, 0x50, 0x8b, 0x06, 0x77, 0x71, 0xc2, 0xb1, 0x7d, 0xec, 0x0c, 0x03, 
	0x50, 0xb4, 0xba, 0x56, 0xc0, 0x2f, 0xf5, 0x2a, 0x74, 0x53, 0x39, 0xa4, 0x3d, 0x64, 0x6a, 0x7b, 
	0x8e, 0x65, 0xec, 0x4c, 0x3f, 0x99, 0xd4, 0x07, 0x5e, 0x0e, 0x61, 0x9a, 0x9b, 0xcf, 0x45, 0x3e, 
	0xe3, 0xa0, 0xb2, 0xce, 0x53, 0x6d, 0x81, 0xb2, 0x46, 0x6b, 0x37, 0x2a, 0x14, 0x17, 0x75, 0xd4, 
	0x7f, 0xc5, 0x24, 0xf5, 0x35, 0xac, 0xe3, 0x5c, 0x7f, 0x79, 0xa6, 0x91, 0x64, 0xa9, 0xb7, 0xff, 
	0xf9, 0x04, 0x8b, 0xa3, 0x61, 0xf9, 0x52, 0x1d, 0x2e, 0x0d, 0xe5, 0xcf, 0x7a, 0xa3, 0xa2, 0x75, 
	0x76, 0x30, 0x04, 0x8e, 0x23, 0xb9, 0xad, 0x3f, 0x61, 0x0b, 0x39, 0x65, 0xf0, 0x2d, 0x98, 0x32, 
	0xe4, 0x1c, 0x9d, 0x20, 0x9b, 0x06, 0xb9, 0x2e, 0xc3, 0x64, 0x84, 0x62, 0xd4, 0x40, 0xd8, 0x2a, 
	0xf8, 0xff, 0xdb, 0x72, 0xe3, 0xe2, 0x4d, 0x85, 0xd9, 0x39, 0xed, 0x66, 0x20, 0x22, 0x01, 0xa8, 
	0x56, 0x31, 0x44, 0xb2, 0x87, 0x58, 0x70, 0xbd, 0xf4, 0xbc, 0xc2, 0xd1, 0x36, 0xbf, 0xa9, 0x52, 
	0x99, 0x87, 0xae, 0x9f, 0x5d, 0x86, 0xe7, 0x31, 0x4e, 0x52, 0x5d, 0x19, 0xa0, 0xdf, 0xb4, 0x01, 
	0xe0, 0xd0, 0x57, 0xf3, 0x5f, 0xaf, 0x15, 0xd4, 0xd4, 0x93, 0xab, 0x4f, 0x60, 0xe6, 0x28, 0x48, 
	0xa2, 0xbf, 0x97, 0x25, 0x43, 0x67, 0xa4, 0x5a, 0xde, 0x4f, 0x26, 0xd8, 0x48, 0x72, 0x70, 0x5e, 
	0xf2, 0x79, 0x99, 0xcf, 0xa4, 0x4b, 0xf9, 0x27, 0x2d, 0xb2, 0x9b, 0x7b, 0x7d, 0x18, 0xdd, 0x97, 
	0x65, 0xca, 0x19, 0x45, 0x65, 0xef, 0xa7, 0xe4, 0x78, 0x16, 0xac, 0xb7, 0x05, 0xed, 0x08, 0xdd, 
	0x1a, 0x69, 0xe0, 0x23, 0x83, 0x04, 0xcd, 0x3e, 0xfb, 0xd6, 0x91, 0x52, 0xfd, 0x9f, 0x50, 0x13, 
	0xe6, 0xa2, 0x0c, 0x68, 0xf5, 0x17, 0x7c, 0x91, 0xbc, 0x9f, 0x8c, 0x89, 0x59, 0x90, 0x60, 0x4e, 
	0x9e, 0xfd, 0xd9, 0xe8, 0x82, 0x7b, 0x03, 0x01, 0x9e, 0x38, 0xa9, 0xfd, 0x3f, 0x98, 0x0e, 0x57, 
	0x45, 0x56, 0x8a, 0x13, 0xd0, 0x90, 0x49, 0xb5, 0xa7, 0xb6, 0xce, 0x66, 0x64, 0x55, 0x0a, 0x8f, 
	0x74, 0x4d, 0xa4, 0x9b, 0x27, 0x37, 0xa3, 0xd3, 0xd9, 0xd1, 0x53, 0xc8, 0x5d, 0xd9, 0xba, 0xf7, 
	0x2c, 0xed, 0x51, 0xba, 0xb5, 0xe0, 0xcd, 0x15, 0x37, 0x43, 0x82, 0xc2, 0x88, 0x7e, 0xa3, 0x1c, 
	0x8c, 0x90, 0x0a, 0x1b, 0x91, 0xca, 0x37, 0x03, 0x04, 0x0f, 0x2d, 0x2d, 0x30, 0xc1, 0x8f, 0x10, 
	0xb0, 0x5d, 0x48, 0xa6, 0x8d, 0xd3, 0xf1, 0x18, 0x48, 0xcb, 0x63, 0xd2, 0x2a, 0xca, 0x41, 0x45, 
	0x99, 0x03, 0x6e, 0x74, 0x0c, 0x14, 0x66, 0xa0, 0xdf, 0x30, 0xc3, 0x0b, 0x3e, 0x41, 0x11, 0xf5, 
	0x2d, 0x93, 0xb9, 0x18, 0xdf, 0xc1, 0x09, 0x95, 0x47, 0xe6, 0x7a, 0x4c, 0xea, 0x85, 0x44, 0xca, 
	0x0b, 0x70, 0xf0, 0x58, 0xe9, 0xc4, 0x48, 0xd5, 0x5b, 0xf6, 0xd1, 0x47, 0x1e, 0xa9, 0xce, 0x23, 
	0x37, 0xc0, 0xda, 0xb6, 0x0f, 0xaa, 0x54, 0x6b, 0x61, 0xbd, 0x28, 0xeb, 0x46, 0xab, 0xb7, 0x56, 
	0x54, 0x97, 0xb3, 0xbb, 0xc7, 0x37, 0x90, 0x1a, 0xcc, 0xf7, 0x75, 0x59, 0xe0, 0xb9, 0x64, 0x5d, 
	0x7e, 0xc4, 0xa7, 0x02, 0x92, 0xf2, 0xd5, 0xb8, 0xe0, 0x8b, 0x70, 0x25, 0xc7, 0x1f, 0x71, 0x60, 
	0xfa, 0x9c, 0xfe, 0x01, 0xa3, 0x81, 0xcf, 0x72, 0x69, 0x70, 0x08, 0x21, 0x0a, 0x01, 0xfa, 0xf5, 
	0x31, 0x92, 0x9b, 0x95, 0x60, 0xb8, 0x15, 0x9a, 0x21, 0x23, 0x36, 0xfd, 0xed, 0xe9, 0xaa, 0xd7, 
	0x59, 0xce, 0xe1, 0x07, 0xf2, 0x7b, 0xd3, 0xf1, 0x56, 0x9e, 0x24, 0x15, 0x1c, 0x72, 0x3f, 0xa1, 
	0x09, 0x0f, 0x71, 0x43, 0x57, 0xc0, 0x6b, 0x94, 0xbd, 0xbf, 0xdc, 0x8c, 0xbb, 0xf2, 0x4d, 0x8e, 
	0x30, 0x57, 0xec, 0x0f, 0x9e, 0xa1, 0x4f, 0xed, 0x11, 0xb4, 0x63, 0xfa, 0x02, 0x99, 0x2a, 0x88, 
	0x6a, 0xa3, 0x87, 0xfe, 0x47, 0x70, 0xef, 0x3a, 0xa1, 0x43, 0x19, 0x47, 0xd5, 0xcb, 0x01, 0xdd, 
	0x4f, 0xea, 0xbf, 0xab, 0xef, 0x33, 0x3b, 0x19, 0x09, 0xa8, 0x72, 0x92, 0x5e, 0x6c, 0xfd, 0x14, 
	0x21, 0x50, 0x38, 0x91, 0x7d, 0x09, 0xa5, 0x0b, 0x37, 0x49, 0xea, 0x3d, 0x0a, 0xa9, 0x6d, 0x67, 
	0x01, 0x60, 0x1e, 0x6a, 0x4c, 0xfa, 0x4c, 0x0c, 0xba, 0x87, 0x44, 0x4c, 0x54, 0x1b, 0x24, 0x4d, 
	0x8c, 0xfa, 0x06, 0x36, 0x6b, 0x7a, 0xea, 0x4a, 0x9a, 0x19, 0xf3, 0xce, 0x49, 0x83, 0x27, 0x2f, 
	0xee, 0x78, 0x82, 0xdd, 0x12, 0xae, 0xb1, 0xb1, 0x71, 0x5b, 0x67, 0xac, 0x74, 0x54, 0xa7, 0x69, 
	0x9f, 0xea, 0x2c, 0x7f, 0x0c, 0xaf, 0xdc, 0xc9, 0x69, 0x9a, 0x9f, 0x24, 0x35, 0x5c, 0x3c, 0xa8, 
	0x78, 0xda, 0x6c, 0x5e, 0x18, 0x67, 0x84, 0x5d, 0x2b, 0x7b, 0x9d, 0x26, 0x06, 0x16, 0x36, 0xb5, 
	0x12, 0x55, 0xe1, 0x01, 0x36, 0x03, 0x7c, 0xfd, 0xd5, 0x81, 0x4a, 0x46, 0x16, 0xfc, 0xfd, 0xab, 
	0x46, 0x27, 0xf4, 0xf5, 0x2e, 0xa4, 0x51, 0xef, 0x64, 0xe7, 0x80, 0x5a, 0xab, 0x57, 0x6b, 0xc0, 
	0xe8, 0x1e, 0xb8, 0x05, 0x05, 0xc3, 0x12, 0x22, 0x37, 0x91, 0x4a, 0x36, 0xc6, 0xe3, 0x4a, 0xa6, 
	0x69, 0x23, 0x6c, 0xe5, 0xfe, 0x5d, 0x80, 0xae, 0xc0, 0x17, 0xbc, 0xe8, 0x19, 0x6c, 0xdf, 0xe2, 
	0x86, 0x0e, 0xef, 0x48, 0x12, 0xdc, 0xc3, 0x0b, 0x8c, 0xa1, 0x29, 0x6c, 0x19, 0x29, 0x31, 0x45, 
	0x7c, 0x1b, 0x4d, 0x02, 0xca, 0x55, 0x6a, 0x0e, 0xf3, 0x77, 0xc6, 0x79, 0x09, 0xdc, 0x91, 0x2d, 
	0x7a, 0xb0, 0x98, 0x44, 0x02, 0xaf, 0xc5, 0xe3, 0x8a, 0x17, 0xaa, 0xb4, 0xf2, 0x08, 0x6d, 0x5b, 
	0xed, 0xd5, 0xbb, 0x0a, 0x0e, 0x81, 0x4d, 0x4c, 0xb6, 0xc1, 0xc8, 0x21, 0x93, 0x6b, 0xd8, 0xfe, 
	0x39, 0x5a, 0x68, 0xc0, 0xb5, 0x49, 0x7f, 0xa7, 0xc5, 0x97, 0x98, 0xe0, 0xbc, 0xb4, 0xdf, 0xd2, 
	0x1b, 0x80, 0xbf, 0x49, 0x94, 0xb8, 0x92, 0xf7, 0xb8, 0xc6, 0xfc, 0xe5, 0xfc, 0xaf, 0x9f, 0xf6, 
	0x4f, 0x98, 0xc9, 0xc3, 0xf6, 0x77, 0x5f, 0x35, 0xf4, 0xa0, 0x1d, 0xd4, 0x60, 0xf8, 0xb0, 0x3e, 
	0x31, 0xd9, 0xa3, 0x18, 0xb4, 0x14, 0x25, 0x91, 0xce, 0x3d, 0xae, 0x64, 0x53, 0xe7, 0x17, 0xe6, 
	0x40, 0x3f, 0x84, 0x2a, 0x00, 0x21, 0x56, 0x68, 0x8a, 0xe9, 0x12, 0x7c, 0xd9, 0x1a, 0x4e, 0x16, 
	0x50, 0x7b, 0x64, 0x15, 0x30, 0x5f, 0x42, 0x85, 0xfa, 0x44, 0x96, 0x83, 0x84, 0xe0, 0xf5, 0x4b, 
	0xae, 0x40, 0x77, 0x86, 0xde, 0x6f, 0x01, 0xbd, 0x32, 0x46, 0x22, 0x97, 0x28, 0x86, 0xb0, 0x7b, 
	0x10, 0x19, 0x18, 0x96, 0x24, 0xdf, 0xcd, 0xc8, 0x43, 0x1f, 0x3d, 0x0f, 0x2d, 0xf2, 0x0b, 0xec, 
	0xd7, 0xbe, 0xd4, 0xe3, 0xd6, 0x66, 0x45, 0x0a, 0x5a, 0x52, 0x43, 0xed, 0xe2, 0x61, 0x88, 0x3b, 
	0x97, 0xa3, 0x03, 0xa5, 0x5b, 0x48, 0xb4, 0x72, 0xda, 0xa1, 0xfe, 0xac, 0xbc, 0x65, 0x5a, 0x1a, 
	0x41, 0xa3, 0x55, 0xe5, 0xd1, 0x7e, 0x54, 0x3f, 0x2a, 0xde, 0xa3, 0xf3, 0x3d, 0xdb, 0x65, 0xc3, 
	0xf2, 0x26, 0xd4, 0xab, 0x30, 0x01, 0x19, 0xa9, 0x50, 0xe5, 0xd5, 0xde, 0x39, 0x1e, 0x39, 0x6b, 
	0xff, 0x0d, 0xff, 0x77, 0x8a, 0x3f, 0x7b, 0x7b, 0xed, 0x6b, 0x40, 0xf2, 0xd6, 0xf2, 0xab, 0x79, 
	0xe7, 0x9e, 0x74, 0x32, 0x90, 0x6f, 0x03, 0xdb, 0x3f, 0xd7, 0x0e, 0x04, 0x8b, 0x95, 0xbb, 0xa5, 
	0xbf, 0x42, 0xb4, 0x39, 0x63, 0x67, 0x3d, 0xcc, 0x29, 0xfc, 0x35, 0x18, 0xcf, 0xc1, 0x7a, 0xa8, 
	0x23, 0x62, 0x83, 0x09, 0x2b, 0x30, 0x4d, 0x04, 0xcb, 0xfa, 0xad, 0x3a, 0x06, 0xcc, 0x5a, 0x24, 
	0x37, 0x8e, 0xb7, 0x3f, 0x22, 0x9b, 0xef, 0x25, 0x38, 0x39, 0xf0, 0xba, 0xc6, 0xdc, 0xfc, 0x14, 
	0xb1, 0x03, 0x84, 0x84, 0x97, 0xf0, 0xd4, 0x70, 0x08, 0x32, 0x3a, 0xfe, 0x2f, 0x87, 0x9e, 0x17, 
	0x8e, 0x2e, 0x92, 0x7d, 0xfc, 0xc0, 0xfc, 0xb8, 0xff, 0x62, 0x91, 0xf8, 0xae, 0x24, 0xef, 0x2a, 
	0x53, 0x1d, 0x90, 0x0d, 0xc2, 0xf7, 0x3f, 0x1f, 0x5c, 0xde, 0x98, 0xfc, 0x0f, 0x0a, 0xf3, 0x4e, 
	0x7d, 0x96, 0x58, 0xdb, 0xaa, 0xcb, 0x8f, 0x11, 0x36, 0x27, 0x0b, 0x26, 0x1d, 0x7a, 0xe2, 0x4c, 
	0x38, 0x68, 0x13, 0xca, 0x2f, 0x32, 0xd1, 0x8b, 0x67, 0x2e, 0x6a, 0x7b, 0xc7, 0x42, 0x19, 0xae, 
	0x0f, 0x26, 0x36, 0x61, 0x71, 0x3d, 0x56, 0x45, 0xd4, 0x3c, 0x2f, 0xc5, 0x94, 0xc9, 0xed, 0xeb, 
	0xf2, 0x98, 0x67, 0xda, 0xe6, 0x9f, 0x51, 0x36, 0x72, 0x68, 0x43, 0x72, 0x00, 0xf0, 0xf6, 0x77, 
	0x21, 0x27, 0xbf, 0x2a, 0x41, 0x47, 0xa8, 0x8a, 0x90, 0xe0, 0xbe, 0x5b, 0x47, 0x25, 0x84, 0x3c, 
	0x7d, 0x08, 0xa8, 0xff, 0x38, 0xd5, 0xa4, 0x2c, 0xb9, 0x6e, 0x83, 0xe3, 0x45, 0x5c, 0xe5, 0x69, 
	0x4e, 0x15, 0xdf, 0x0f, 0x4c, 0x8a, 0x08, 0x7d, 0x6b, 0xa9, 0x1b, 0xb1, 0xe8, 0x3f, 0x83, 0xb7, 
	0x43, 0x03, 0xb5, 0x14, 0xab, 0x58, 0x72, 0x7e, 0x7e, 0xff, 0x3b, 0xba, 0x72, 0xa0, 0x5e, 0xbc, 
	0x3e, 0xc9, 0x06, 0xae, 0xb3, 0xe5, 0x1b, 0x34, 0x77, 0xeb, 0x0d, 0x61, 0x5a, 0xa0, 0x68, 0xf3, 
	0xf8, 0x7f, 0xbd, 0x26, 0xd4, 0xae, 0xac, 0xc9, 0x84, 0xfe, 0x61, 0x80, 0x53, 0xad, 0xf2, 0x69, 
	0x96, 0x16, 0x96, 0x9f, 0xca, 0x63, 0x20, 0x1e, 0xc2, 0xef, 0x48, 0x1d, 0x64, 0x0b, 0xce, 0xcc, 
	0x77, 0x90, 0xf5, 0xdf, 0xda, 0x20, 0xfb, 0x03, 0x1d, 0xac, 0x43, 0xa8, 0xc3, 0x10, 0x6e, 0x87, 
	0xfd, 0x78, 0xf4, 0x45, 0xfe, 0xb5, 0x98, 0xfb, 0x5c, 0x36, 0x0b, 0x07, 0x4d, 0x1f, 0x56, 0x48, 
	0x57, 0x24, 0xf7, 0x9b, 0xbb, 0x3e, 0xf1, 0xf8, 0x06, 0x51, 0x4b, 0x53, 0x17, 0xcc, 0xc8, 0x3f, 
	0x19, 0x24, 0x74, 0x4e, 0x20, 0xe3, 0xf3, 0xe0
};
#endif

#endif
#ifdef __CMCC_0202_SEGC_TECH__
#ifdef __MMI_CUSTOMER_SERVICE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__MMI_CUSTOMER_SERVICE__*/
#else /*__CMCC_0202_SEGC_TECH__*/
#ifdef __MMI_CUSTOMER_SERVICE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__MMI_CUSTOMER_SERVICE__*/
#endif /*__CMCC_0202_SEGC_TECH__*/


#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
#endif


#ifdef __MMI_FM_RADIO_SCHEDULER__
static char NVRAM_FMRDO_SCHEDULER_DEFAULT[NVRAM_EF_FMRDO_SCHEDULER_SIZE] =
{
    0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
	0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
    0, 0xff
};
#endif /* __MMI_FM_RADIO_SCHEDULER__ */

#ifdef __MMI_THEMES_APPLICATION__
#ifdef __MMI_THEMES_V2_SUPPORT__
static kal_uint8 const NVRAM_THEMES_VALUES_DEFAULT [NVRAM_THEMES_VALUES_SIZE] =
{
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00
};
#else /* __MMI_THEMES_V2_SUPPORT__*/
static kal_uint8 const NVRAM_THEMES_VALUES_DEFAULT [NVRAM_THEMES_VALUES_SIZE] =
{
   0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00
};
#endif /* __MMI_THEMES_V2_SUPPORT__*/
#endif /* __MMI_THEMES_APPLICATION__*/

/*
// move to mcu\nvram\src\nvram_data_items.c
static kal_int32 const NVRAM_EF_ADC_DEFAULT[] = {
#if defined(DRV_ADC_MAX_CH_1)
   5369,
   60428
#elif defined(DRV_ADC_MAX_CH_5)
   5369,  5369, 5369, 5369, 5369,
   60428, 60428, 60428, 60428, 60428
#elif defined(DRV_ADC_MAX_CH_6)
   5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_7)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_8)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_9)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_10)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_11)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_12)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_13)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_14)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_15)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_16)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_17)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_18)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_19)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_20)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#endif // #if defined(DRV_ADC_MAX_CH_5)

};
*/

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
static kal_uint8 const NVRAM_EF_AUTOTEST_DEFAULT[NVRAM_EF_AUTOTEST_SIZE] =
{
       /* [count, test0, test1, test2 ....... test229] */
	15,  0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   10,  11,  12,  13,  14, /* 16 */
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

#endif
#endif



static kal_uint8 const NVRAM_EF_QUICKTEST_DEFAULT[NVRAM_EF_QUICKTEST_SIZE] =
{
       /* [count, test0, test1, test2 ....... test229] */
	15,  0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   10,  11,  12,  13,  14, /* 16 */
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

#ifdef MOTION_SENSOR_SUPPORT

static kal_uint8 const NVRAM_EF_MOTION_SENSOR_SWITCH_DEFAULT[NVRAM_EF_MOTION_SENSOR_SWITCH_SIZE] =
{
    0x01
};

#endif /*MOTION_SENSOR_SUPPORT*/

#ifdef __MMI_EBOOK_READER__
static kal_uint8 const NVRAM_EF_EBOOK_DEFAULT_VALUE [NVRAM_EF_EBOOK_SETTING_SIZE] =
{
   0x01,0x00,0x01,0x00,0x01
};
#endif /* __MMI_EBOOK_READER__ */

#ifdef __MMI_ECOMPASS__
static kal_int32 const NVRAM_EF_ECOMPASS_DEFAULT[NVRAM_EF_ECOMPASS_SIZE * NVRAM_EF_ECOMPASS_TOTAL] =
{
	#include "ec_def_dec_ang.h"
};
#endif /* __MMI_ECOMPASS__ */

#ifdef __SYNCML_SUPPORT__

#ifdef CUSTOM_SYNCML_ACCOUNT_DEFAULT
nvram_ef_syncml_account_struct const NVRAM_EF_SYNCML_ACCOUNT_DEFAULT[NVRAM_EF_SYNCML_ACCOUNT_TOTAL] =
{
    CUSTOM_SYNCML_ACCOUNT_DEFAULT
};
#endif /* CUSTOM_SYNCML_ACCOUNT_DEFAULT */

#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
nvram_ef_syncml_account_struct const NVRAM_EF_SYNCML_ACCOUNT_DEFAULT_FOR_PC_SYNC[NVRAM_EF_SYNCML_ACCOUNT_TOTAL] =
{
	{                               /* default profile 1 */
     0x01,                          /* Account ID */
     "",                            /* Account Name */
     "http://",                     /* Server Address */
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* Contact Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* Calendar Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* Task Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* Note Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* bookmark Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* email Address */
     "",                            /* User Name */
     "",                            /* Password */
     0x8000,                        /* Validation:valid data account*/
     {
     #if (MMI_MAX_SIM_NUM>3)
     	CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
     #endif

	 #if (MMI_MAX_SIM_NUM>2)		
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	 #endif

	 #if (MMI_MAX_SIM_NUM>1)
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	 #endif
		
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID	
	},        /* Network ID */
     "",                            /* Proxy hash*/
     "",                            /* Provurl hash*/
     0,                             /* Type */
     0,                             /* Read only*/
     0,                             /* Connection Type -- HTTP 0, WAP 1, BT 2 */
     0,                             /* App to sync */
     0,                             /* sync type - two-way sync*/
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
#else
     0,
#endif
     0,                             /* regular sync - 0:none */
     0,                             /* regular sync notify */
     0,                             /* sync report 0:off 1:on */
     0,                             /* last_phb_anchor */
     0,                             /* last_cal_anchor */
     0,                             /* last_task_anchor */
     0,                             /* last_note_anchor */
     0,                             /* last_email_anchor */
     0,                             /* last_bkm_anchor */
     },
    {                               /* operator default Account 2 */
     0x02,                             /* Account ID */
     "",                            /* Account Name */
     "http://",                     /* Server Address */
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
     "",                            /* User Name */
     "",                            /* Password */
     "./",                            /* Contact Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                            /* Calendar Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                            /* Task Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                            /* Note Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* bookmark Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* email Address */
     "",                            /* User Name */
     "",                            /* Password */
     0x8000,                        /* Validation:valid data account*/     
	{
	#if (MMI_MAX_SIM_NUM>3)
		 CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	#endif

	#if (MMI_MAX_SIM_NUM>2)		 
		 CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	#endif
		 
	#if (MMI_MAX_SIM_NUM>1)
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	#endif

		CUSTOM_DEFAULT_SYNCML_DTCNT_ID  
	}, 	   /* Network ID */
     "",                            /* Proxy */
     "",                            /* Provurl*/
     0,                             /* Type */
     0,                             /* Read only*/
     0,                             /* Connection Type -- HTTP 0, WAP 1, BT 2 */
     0,                             /* App to sync */
     0,                             /* sync type - two-way sync*/
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
#else
     0,
#endif
     0,                             /* regular sync - 0:none */
     0,                             /* regular sync notify */
     0,                             /* sync report 0:off 1:on */
     0,                             /* last_phb_anchor */
     0,                             /* last_cal_anchor */
     0,                             /* last_task_anchor */
     0,                             /* last_note_anchor */
     0,                             /* last_email_anchor */
     0,                             /* last_bkm_anchor */
     },
    {                               /* operator default profile 3 */
     0x03,                             /* Account ID */
     {'M', 0x00,'T', 0x00,'K', 0x00,' ', 0x00,'P', 0x00, 'C', 0x00, ' ', 0x00, 'S', 0x00, 'Y', 0x00, 'N', 0x00, 'C', 0x00, 0x00, 0x00},  /* bt Account Name */
     "MTK SYNC TOOL",                /* Server Address */
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
     "",                            /* User Name */
     "",                            /* Password */
     "./Contacts",                          /* Contact Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./Calendar",                          /* Calendar Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./Tasks",                          /* Task Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./Notes",                          /* Note Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* bookmark Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* email Address */
     "",                            /* User Name */
     "",                            /* Password */
     0x0001 | 0x0002 | 0x0004 | 0x0008 | 0x0010 | 0x0020 | 0x8000,   /* Validation */
     {
     #if (MMI_MAX_SIM_NUM>3)
     	CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
     #endif

	 #if (MMI_MAX_SIM_NUM>2)		
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	 #endif

	 #if (MMI_MAX_SIM_NUM>1)
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	 #endif
		
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID	
	},        /* Network ID */                 /* Network ID */
     "",                            /* Proxy hash */
     "",                            /* Provurl hash */
     0,                             /* Profile Type */
     0,                             /* Read only */
     1,                             /* Connection Type -- internet 0, BT 1 */
     0x01,                          /* App to sync only phonebook*/
     0,                             /* sync type - two-way sync*/
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
#else
     0,
#endif
     0,                             /* regular sync - 0:none */
     0,                             /* regular sync notify */
     1,                             /* sync report 0:off 1:on */
     0,                             /* last_phb_anchor */
     0,                             /* last_cal_anchor */
     0,                             /* last_task_anchor */
     0,                             /* last_note_anchor */
     0,                             /* last_email_anchor */
     0,                             /* last_bkm_anchor */
     },
};

#else
nvram_ef_syncml_account_struct const NVRAM_EF_SYNCML_ACCOUNT_DEFAULT_FOR_NONE_PC_SYNC[NVRAM_EF_SYNCML_ACCOUNT_TOTAL] =
{
	{                               /* default profile 1 */
     0x01,                          /* Account ID */
     "",                            /* Account Name */
     "http://",                     /* Server Address */
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* Contact Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* Calendar Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* Task Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* Note Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* bookmark Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* email Address */
     "",                            /* User Name */
     "",                            /* Password */
     0x8000,                        /* Validation:valid data account*/
     {
     #if (MMI_MAX_SIM_NUM>3)
     	CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
     #endif

	 #if (MMI_MAX_SIM_NUM>2)		
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	 #endif

	 #if (MMI_MAX_SIM_NUM>1)
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	 #endif
		
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID	
	},        /* Network ID */
     "",                            /* Proxy hash*/
     "",                            /* Provurl hash*/
     0,                             /* Type */
     0,                             /* Read only*/
     0,                             /* Connection Type -- HTTP 0, WAP 1, BT 2 */
     0,                             /* App to sync */
     0,                             /* sync type - two-way sync*/
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
#else
     0,
#endif
     0,                             /* regular sync - 0:none */
     0,                             /* regular sync notify */
     0,                             /* sync report 0:off 1:on */
     0,                             /* last_phb_anchor */
     0,                             /* last_cal_anchor */
     0,                             /* last_task_anchor */
     0,                             /* last_note_anchor */
     0,                             /* last_email_anchor */
     0,                             /* last_bkm_anchor */
     },
    {                               /* operator default Account 2 */
     0x02,                             /* Account ID */
     "",                            /* Account Name */
     "http://",                     /* Server Address */
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
     "",                            /* User Name */
     "",                            /* Password */
     "./",                            /* Contact Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                            /* Calendar Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                            /* Task Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                            /* Note Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* bookmark Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* email Address */
     "",                            /* User Name */
     "",                            /* Password */
     0x8000,                        /* Validation:valid data account*/     
	{
	#if (MMI_MAX_SIM_NUM>3)
		 CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	#endif

	#if (MMI_MAX_SIM_NUM>2)		 
		 CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	#endif
		 
	#if (MMI_MAX_SIM_NUM>1)
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	#endif

		CUSTOM_DEFAULT_SYNCML_DTCNT_ID  
	}, 	   /* Network ID */
     "",                            /* Proxy */
     "",                            /* Provurl*/
     0,                             /* Type */
     0,                             /* Read only*/
     0,                             /* Connection Type -- HTTP 0, WAP 1, BT 2 */
     0,                             /* App to sync */
     0,                             /* sync type - two-way sync*/
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
#else
     0,
#endif
     0,                             /* regular sync - 0:none */
     0,                             /* regular sync notify */
     0,                             /* sync report 0:off 1:on */
     0,                             /* last_phb_anchor */
     0,                             /* last_cal_anchor */
     0,                             /* last_task_anchor */
     0,                             /* last_note_anchor */
     0,                             /* last_email_anchor */
     0,                             /* last_bkm_anchor */
     },
    {                               /* operator default profile 3 */
	 0x03,						   /* Account ID */
	 "", 						   /* Account Name */
	 "http://",					   /* Server Address */
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
     "",                            /* User Name */
     "",                            /* Password */
     "./",                            /* Contact Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                            /* Calendar Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                            /* Task Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                            /* Note Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* bookmark Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* email Address */
     "",                            /* User Name */
     "",                            /* Password */
     0x8000,                        /* Validation:valid data account*/    
     {
     #if (MMI_MAX_SIM_NUM>3)
     	CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
     #endif

	 #if (MMI_MAX_SIM_NUM>2)		
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	 #endif

	 #if (MMI_MAX_SIM_NUM>1)
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	 #endif
		
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID	
	},        /* Network ID */                 /* Network ID */
     "",                            /* Proxy hash */
     "",                            /* Provurl hash */
     0,                             /* Profile Type */
     0,                             /* Read only */
     0,                             /* Connection Type -- internet 0, BT 1 */
     0,                          /* App to sync only phonebook*/
     0,                             /* sync type - two-way sync*/
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
#else
     0,
#endif
     0,                             /* regular sync - 0:none */
     0,                             /* regular sync notify */
     0,                             /* sync report 0:off 1:on */
     0,                             /* last_phb_anchor */
     0,                             /* last_cal_anchor */
     0,                             /* last_task_anchor */
     0,                             /* last_note_anchor */
     0,                             /* last_email_anchor */
     0,                             /* last_bkm_anchor */
     },
};
#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */
#endif /* __SYNCML_SUPPORT__ */

#if defined(__MMI_FWU_VIA_TFTP__)
static nvram_ef_dm_fwu_tftp_setting_struct const NVRAM_EF_DM_FWU_TFTP_SETTING_DEFAULT[]=
{
    {"172.22.216.28", 0,
    {'S', 0, 'U', 0, 'P', 0, 'E', 0, 'R', 0, 'M', 0, 'A', 0, 'N', 0, '2', 0, '9', 0, '_', 0, 'M', 0, 'A', 0, 'U', 0, 'I', 0, '_', 0, 'W', 0, '0', 0, '6', 0, '_', 0, '4', 0, '4', 0, '.', 0, 'c', 0, 'p', 0, 'r', 0}, 0,},
};
#endif /* #if defined(__MMI_FWU_VIA_TFTP__) */


#if defined(__MMI_FWU_VIA_HTTP__)
static nvram_ef_dm_fwu_http_setting_struct const NVRAM_EF_DM_FWU_HTTP_SETTING_DEFAULT[]=
{
	{"http://wap1.mtk.com.tw/",0},
};
#endif  /* #if defined(__MMI_FWU_VIA_HTTP__) */

/*Rahul*/
#if defined(OBIGO_Q03C_MMS_V01)
nvram_mmsv01_compose_settings_struct const NVRAM_EF_MMSV01_COMPOSE_SETTING_CONTENT_DEFAULT[]=
{
/*#ifdef CUSTOM_MMS_COMPOSE_SETTING_CONTENT_DEFAULT
    CUSTOM_MMS_COMPOSE_SETTING_CONTENT_DEFAULT
#else CUSTOM_MMS_COMPOSE_SETTING_CONTENT_DEFAULT*/
  {
      0,1,0,0,""
   },

};

nvram_mmsv01_sending_settings_struct const NVRAM_EF_MMSV01_SENDING_SETTING_CONTENT_DEFAULT[]=
{
/*#ifdef CUSTOM_MMS_SENDING_SETTING_CONTENT_DEFAULT
    CUSTOM_MMS_SENDING_SETTING_CONTENT_DEFAULT
#else CUSTOM_MMS_SENDING_SETTING_CONTENT_DEFAULT*/
  {
      5,0,0,1,0,0,5
   },
};
#endif

#ifdef __MMI_MMS_2__

nvram_umms_compose_settings_struct const NVRAM_EF_MMS_COMPOSE_SETTING_CONTENT_DEFAULT[]=
{

    #ifdef __MMI_SLIM_MMS_2__ 
        {
   	      0,0,255,1,20,0,0,"",5
       },
   #else

#ifdef CUSTOM_MMS_COMPOSE_SETTING_CONTENT_DEFAULT
    CUSTOM_MMS_COMPOSE_SETTING_CONTENT_DEFAULT
#else /*CUSTOM_MMS_COMPOSE_SETTING_CONTENT_DEFAULT*/
  {

      0,0,255,1,20,0,0,"","","","",5
   },
   #endif

#endif
};

nvram_umms_sending_settings_struct const NVRAM_EF_MMS_SENDING_SETTING_CONTENT_DEFAULT[]=
{
#ifdef CUSTOM_MMS_SENDING_SETTING_CONTENT_DEFAULT
    CUSTOM_MMS_SENDING_SETTING_CONTENT_DEFAULT
#else /*CUSTOM_MMS_SENDING_SETTING_CONTENT_DEFAULT*/
	#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
		{
		  0,1,0,1,0,0,0,0,255,0,1
	   },
	#else
  {
      0,0,0,1,0,0,0,0,255,0,1
   },
#endif
#endif
};

#ifndef WAP_SUPPORT
nvram_profile_content_struct const  NVRAM_EF_WAP_PROFILE_CONTENT_DEFAULT[NVRAM_PROFILE_MAX]=
{
#ifdef CUSTOM_WAP_PROFILE_CONTENT_DEFAULT
    CUSTOM_WAP_PROFILE_CONTENT_DEFAULT
#else
   { /* wap profile 1 - FET */
      1,0,80,"http://mobile.fetnet.net",10,-1,1,210,241,199,199,"",""
		  ,0
   },
   { /* wap profile 2 - CHT */
      1,0,8080,"http://wap.emome.net",11,-1,1,10,1,1,1,"",""
		  ,0
   },
   { /* wap profile 3 - Taiwan mobile */
      2,0,80,"http://ewap",12,-1,1,10,1,1,1,"",""
		  ,0
   },
   { /* wap profile 4 - CHINA MOBILE */
      1,0,80,"http://wap.monternet.com",14,-1,1,10,0,0,172,"",""
		  ,0
   },
   { /* wap profile 5 - Unicom */
      2,0,80,"http://wap.uni-info.com.cn",15,-1,1,10,0,0,172,"",""
		  ,0
   },
   { /* wap profile 6 - AIRTEL INDIA */
      1,0,8080,"http://www.google.com",17,-1,1,202,56,231,117,"",""
		  ,0
   },
	{ /* wap profile 7 - HUTCH INDIA */
      1,0,9401,"http://www.hutchworld.co.in",19,-1,1,10,10,1,100,"",""
		  ,0
   },
   { /* wap profile 8 - KGT */
      1,0,0,"",0,0,1,0,0,0,0,"",""
		  ,0
   },
   { /* wap profile 9 - Mobitai */
      1,0,0,"",0,0,1,0,0,0,0,"",""
		  ,0
   },
   { /* wap profile 10 - Empty */
      1,0,0,"",0,0,1,0,0,0,0,"",""
		  ,0
   }
#endif /*CUSTOM_WAP_PROFILE_CONTENT_DEFAULT*/
};

nvram_profile_content_struct const NVRAM_EF_MMS_PROFILE_CONTENT_DEFAULT[NVRAM_PROFILE_MAX] =
{
#ifdef CUSTOM_MMS_PROFILE_CONTENT_DEFAULT
    CUSTOM_MMS_PROFILE_CONTENT_DEFAULT
#else /*CUSTOM_MMS_PROFILE_CONTENT_DEFAULT*/
  { /* mms profile 1 - FET */
      1,0,80,"http://mms",10,-1,1,210,241,199,199,"",""
		  ,0
   },
   { /* mms profile 2 - CHT */
      1,0,8080,"http://mms.emome.net:8002",11,-1,1,10,1,1,1,"",""
		  ,0
   },
   { /* mms profile 3 - Taiwan mobile */
      1,0,80,"http://mms",12,-1,1,10,1,1,1,"",""
		  ,0
   },
   { /* mms profile 4 - CHINA MOBILE */
      1,0,80,"http://mmsc.monternet.com",14,-1,1,10,0,0,172,"",""
		  ,0
   },
   { /* mms profile 5 - Unicom */
      2,0,80,"http://mmsc.myuni.com.cn",15,-1,1,10,0,0,172,"",""
		  ,0
   },
   { /* mms profile 6 - AIRTEL INDIA */
      1,0,8080,"http://100.1.201.171:10021/mmsc",18,-1,1,100,1,201,172,"",""
		  ,0
   },
   { /* mms profile 7 - HUTCH INDIA */
      1,0,9401,"http://mms1.hutchworld.co.in/mms/",19,-1,1,10,10,1,100,"",""
		  ,0
   },
	{ /* mms profile 8 - KGT */
      1,0,0,"",0,0,1,0,0,0,0,"",""
		  ,0
   },
   { /* mms profile 9 - Mobitai */
      1,0,0,"",0,0,1,0,0,0,0,"",""
		  ,0
   },
   { /* mms profile 10 - Empty */
      1,0,0,"",0,0,1,0,0,0,0,"",""
		  ,0
   }
#endif /*CUSTOM_MMS_PROFILE_CONTENT_DEFAULT*/
 };

nvram_profile_name_array_struct const NVRAM_EF_WAP_PROFILE_NAMES_DEFAULT[NVRAM_PROFILE_MAX]=
{
#ifdef CUSTOM_WAP_PROFILE_NAMES_DEFAULT
    CUSTOM_WAP_PROFILE_NAMES_DEFAULT
#else
	2,0x00,1,0,{"FET"},
	2,0x00,1,1,{"CHT"},
	2,0x00,2,2,{"Taiwan Mobile"},
	2,0x00,1,3,{"China Mobile"},
	2,0x00,2,4,{"China Unicom"},
	2,0x00,1,5,{"Airtel"},
	2,0x00,1,6,{"Hutch"},
	2,0x00,2,0,{""},
	2,0x00,2,0,{""},
	2,0x00,2,0,{""}
#endif /*CUSTOM_WAP_PROFILE_NAMES_DEFAULT*/
};

nvram_profile_name_array_struct const NVRAM_EF_MMS_PROFILE_NAMES_DEFAULT[NVRAM_PROFILE_MAX]=
{
#ifdef CUSTOM_MMS_PROFILE_NAMES_DEFAULT
    CUSTOM_MMS_PROFILE_NAMES_DEFAULT
#else /*CUSTOM_MMS_PROFILE_NAMES_DEFAULT*/
	2,0x00,1,0,{"FET MMS"},
	2,0x00,1,1,{"CHT MMS"},
	2,0x00,1,2,{"Taiwan Mobile MMS"},
	2,0x00,1,3,{"China Mobile MMS"},
	2,0x00,2,4,{"China Unicom MMS"},
	2,0x00,1,5,{"Airtel MMS"},
	2,0x00,1,6,{"Hutch MMS"},
	2,0x00,2,0,{""},
	2,0x00,2,0,{""},
	2,0x00,2,0,{""}
#endif /*CUSTOM_MMS_PROFILE_NAMES_DEFAULT*/
};

#endif /* WAP_SUPPORT */
#endif /* __MMI_MMS_2__ */

#ifdef __WAP_PUSH_SUPPORT__
nvram_push_general_setting_struct const NVRAM_EF_PUSH_GEN_SETTING_DEFAULT[]=
{
#ifdef CUSTOM_WAP_PUSH_GEN_SET
	CUSTOM_WAP_PUSH_GEN_SET
#else
	2,0

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    ,1
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */

#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    ,1
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
#endif /* CUSTOM_WAP_PUSH_GEN_SET */
};
#endif /* __WAP_PUSH_SUPPORT__ */

#ifdef __MMI_BROWSER_2__
#ifdef __MMI_OP12_BRW_SEARCH_MENU__
kal_uint8 const WAP_CUSTOM_CFG_SEARCH_WEB_URL[] = {'h', 't', 't', 'p', ':', '/', '/',
'l', 'i', 'v', 'e', '.', 'v', 'o', 'd', 'a', 'f', 'o', 'n','e', '.', 'c', 'o', 'm', '\0'};
#endif /* __MMI_OP12_BRW_SEARCH_MENU__ */
#endif /* __MMI_BROWSER_2__ */

#if defined(__MMI_VIDEO_STREAM__)
/* 5 predefined URL */
/* "URL", "SERVER NAME" - in unicode */
static nvram_ef_video_predefined_url_struct const NVRAM_EF_VIDEO_PREDEFINED_URL_DEFAULT[NVRAM_EF_VIDEO_PREDEFINED_URL_COUNT]=
{
	{
        {'h', 0, 't', 0, 't', 0, 'p', 0, ':', 0, '/', 0, '/', 0, 'm', 0, '.', 0, 'y', 0, 'o', 0,
         'u', 0, 't', 0, 'u', 0, 'b', 0, 'e', 0, '.', 0, 'c', 0, 'o', 0, 'm', 0, '/', 0}, /* url 1 */
        {'Y', 0, 'o', 0, 'u', 0, 'T', 0, 'u', 0, 'b', 0, 'e', 0}   /* name 1 */
    }
#ifdef DEMO_PROJECT
    /* MTK internal test server */
	,{
	    {'h', 0, 't', 0, 't', 0, 'p', 0, ':', 0, '/', 0, '/', 0, 'w', 0, 'a', 0, 'p', 0, '1', 0,
         '.', 0, 'm', 0, 't', 0, 'k', 0, '.', 0, 'c', 0, 'o', 0, 'm', 0, '.', 0, 't', 0, 'w', 0,
         '/', 0}, /* url 2 */
        {'M', 0, 'T', 0, 'K', 0}   /* name 2 */
    }
#endif /* DEMO_PROJECT */
};

static nvram_ef_video_network_profile_struct const NVRAM_EF_VIDEO_NETWORK_PROFILE_DEFAULT[NVRAM_EF_VIDEO_NETWORK_PROFILE_TOTAL] =
{
    /* profile 1 */
    {
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {'P', 0, 'r', 0, 'o', 0, 'f', 0, 'i', 0, 'l', 0, 'e', 0, '1', 0}, /* profile_name */
        {
        #if (MMI_MAX_SIM_NUM > 3)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 2)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 1)
            CBM_DEFAULT_ACCT_ID,
        #endif
            CBM_DEFAULT_ACCT_ID
        },        /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    },

    /* profile 2 */
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {'P', 0, 'r', 0, 'o', 0, 'f', 0, 'i', 0, 'l', 0, 'e', 0, '2', 0}, /* profile_name */
        {
        #if (MMI_MAX_SIM_NUM > 3)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 2)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 1)
            CBM_DEFAULT_ACCT_ID,
        #endif
            CBM_DEFAULT_ACCT_ID
        },        /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    },

    /* profile 3 */
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {'P', 0, 'r', 0, 'o', 0, 'f', 0, 'i', 0, 'l', 0, 'e', 0, '3', 0}, /* profile_name */
        {
        #if (MMI_MAX_SIM_NUM > 3)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 2)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 1)
            CBM_DEFAULT_ACCT_ID,
        #endif
            CBM_DEFAULT_ACCT_ID
        },        /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    },

    /* profile 4 */
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {'P', 0, 'r', 0, 'o', 0, 'f', 0, 'i', 0, 'l', 0, 'e', 0, '4', 0}, /* profile_name */
        {
        #if (MMI_MAX_SIM_NUM > 3)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 2)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 1)
            CBM_DEFAULT_ACCT_ID,
        #endif
            CBM_DEFAULT_ACCT_ID
        },        /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    },

    /* profile 5 */
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {'P', 0, 'r', 0, 'o', 0, 'f', 0, 'i', 0, 'l', 0, 'e', 0, '5', 0}, /* profile_name */
        {
        #if (MMI_MAX_SIM_NUM > 3)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 2)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 1)
            CBM_DEFAULT_ACCT_ID,
        #endif
            CBM_DEFAULT_ACCT_ID
        },        /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    }
};

#endif  /* defined(__MMI_VIDEO_STREAM__) */

#if defined(__MMI_MEDIA_PLAYER_STREAM__) || defined(__MMI_KURO_SUPPORT__)
static nvram_ef_medply_settings_profile_struct const NVRAM_EF_MEDPLY_NETWORK_PROFILE_DEFAULT[NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_TOTAL] =
{
    /* profile 1 */
    {
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0}, /* profile_name */
        {
        #if (MMI_MAX_SIM_NUM > 3)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 2)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 1)
            CBM_DEFAULT_ACCT_ID,
        #endif
            CBM_DEFAULT_ACCT_ID
        },        /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    },

    /* profile 2 */
    {
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0}, /* profile_name */
        {
        #if (MMI_MAX_SIM_NUM > 3)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 2)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 1)
            CBM_DEFAULT_ACCT_ID,
        #endif
            CBM_DEFAULT_ACCT_ID
        },        /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    },

    /* profile 3 */
    {
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0}, /* profile_name */
        {
        #if (MMI_MAX_SIM_NUM > 3)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 2)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 1)
            CBM_DEFAULT_ACCT_ID,
        #endif
            CBM_DEFAULT_ACCT_ID
        },        /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    },

    /* profile 4 */
    {
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0}, /* profile_name */
        {
        #if (MMI_MAX_SIM_NUM > 3)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 2)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 1)
            CBM_DEFAULT_ACCT_ID,
        #endif
            CBM_DEFAULT_ACCT_ID
        },        /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    },

    /* profile 5 */
    {
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0}, /* profile_name */
        {
        #if (MMI_MAX_SIM_NUM > 3)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 2)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 1)
            CBM_DEFAULT_ACCT_ID,
        #endif
            CBM_DEFAULT_ACCT_ID
        },        /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    }
};
#endif /* __MMI_MEDIA_PLAYER_STREAM__ __MMI_KURO_SUPPORT__*/

#ifdef __MMI_MEDIA_PLAYER_STREAM__
static nvram_ef_medply_video_predefined_url_struct const NVRAM_EF_MEDPLY_VIDEO_PREDEFINED_URL_DEFAULT[NVRAM_EF_MEDPLY_VIDEO_PREDEFINED_URL_COUNT]=
{
	{
        {'h', 0, 't', 0, 't', 0, 'p', 0, ':', 0, '/', 0, '/', 0, 'm', 0, '.', 0, 'y', 0, 'o', 0,
         'u', 0, 't', 0, 'u', 0, 'b', 0, 'e', 0, '.', 0, 'c', 0, 'o', 0, 'm', 0, '/', 0}, /* url 1 */
        {'Y', 0, 'o', 0, 'u', 0, 'T', 0, 'u', 0, 'b', 0, 'e', 0}   /* name 1 */
    }
#ifdef DEMO_PROJECT
    /* MTK internal test server */
	,{
	    {'h', 0, 't', 0, 't', 0, 'p', 0, ':', 0, '/', 0, '/', 0, 'w', 0, 'a', 0, 'p', 0, '1', 0,
         '.', 0, 'm', 0, 't', 0, 'k', 0, '.', 0, 'c', 0, 'o', 0, 'm', 0, '.', 0, 't', 0, 'w', 0,
         '/', 0}, /* url 2 */
        {'M', 0, 'T', 0, 'K', 0}   /* name 2 */
    }
#endif /* DEMO_PROJECT */
};
#endif

#ifdef __IOT__
nvram_ef_wifiap_mode_config_struct const COMMON_NVRAM_EF_WIFIAP_MODE_CONFIG_DEFAULT[NVRAM_EF_WIFIAP_MODE_CONFIG_TOTAL] =
{
    {1, "", "12345678"}
};
#endif /* __IOT__ */

#ifdef __MMI_DM_SELF_REGISTER_SUPPORT__
static kal_uint8 const NVRAM_EF_DM_SR_NUMBER_DEFAULT[NVRAM_EF_DM_SR_NUMBER_SIZE] =
{
    #if defined(__OP01__)
	'1', '0', '6', '5', '4', '0', '4', '0', '\0'
    #elif defined(__OP02__)
	'1', '0', '6', '5', '5', '4', '5', '9', '\0'
    #else
	'0', '0', '0', '0', '0', '0', '0', '0', '\0' 
    #endif
};
#endif /* __MMI_DM_SELF_REGISTER_SUPPORT__ */


#ifdef __BIP_PULL_SUPPORT__
static kal_uint8 const NVRAM_EF_BT_BIP_SETTING_DEFAULT[NVRAM_EF_BT_BIP_SETTING_SIZE] =
{
	0, 0, 0, 0, 0, 0
};
#endif /* __MMI_BIP_SUPPORT__ */

#ifdef __MMI_IPSEC__
nvram_ef_ipsec_policy_struct const NVRAM_EF_IPSEC_POLICY_DEFAULT[] =
{
    0, {0, 0, 0, 0}, 0, {0, 0, 0, 0}, 1, 0, {0, 0, 0, 0}, 0, 2, 2
};
nvram_ef_ipsec_ike_struct const NVRAM_EF_IPSEC_IKE_DEFAULT[] =
{
    "", 0, 0, 0
};
#endif /* __MMI_IPSEC__ */

#if (defined __MMI_OP01_DCD__)
static kal_uint8 const NVRAM_EF_DCD_SETTING_DATA_DEFAULT[NVRAM_EF_DCD_SETTING_DATA_SIZE] = 
{
    0x01, 0x00, 0x00, 0x00, 0xFF, 0x01 
};
#elif (defined __MMI_OP01_DCD_V30__)
static kal_uint8 const NVRAM_EF_DCD_SETTING_DATA_DEFAULT[NVRAM_EF_DCD_SETTING_DATA_SIZE] = 
{
    0x01, 0x00, 0x01, 0x00, 0x01
};
#endif

#ifdef __MMI_EM_MISC_DCD__
#if (defined __DCD_V20__)
static kal_uint8 const NVRAM_EF_DCD_EM_PARAM_DATA_DEFAULT[NVRAM_EF_DCD_EM_PARAM_DATA_SIZE] = 
{
     'c',  'm',  'w',  'a',  'p', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* APN: 12B */
     'C',  'h',  'i',  'n',  'a',  ' ',  'M',  'o',  'b',  'i',  'l',  'e', /* APN name: 24B */
	 ' ',  'G',  'P',  'R',  'S', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	 '0',  '1',  '0',  '.',  '0',  '0',  '0',  '.',  '0',  '0',  '0',  '.', /* gate way: 20B*/
	 '1',  '7',  '2', 0x00, 0x00, 0x00, 0x00, 0x00,
	 '8',  '0', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,                        /* port: 8B */

	 'h',  't',  't',  'p',  ':',  '/',  '/',  'd',  'c',  'd',  '.',  'm',  'o',  'n',  't', 'e', /* add channel: 64B */
     'r',  'n',  'e',  't',  '.',  'c',  'o',  'm',  '/',  's',  'e',  'r',  'v',  'i',  'c', 'e',
     '/',  'a',  'd',  'd',  'c',  'h',  'a',  'n',  'n',  'e',  'l', 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	 'h',  't',  't',  'p',  ':',  '/',  '/',  'd',  'c',  'd',  '.',  'm',  'o',  'n',  't',  'e', /* delete channel: 64B */
     'r',  'n',  'e',  't',  '.',  'c',  'o',  'm',  '/',  's',  'e',  'r',  'v',  'i',  'c',  'e',
     '/',  'd',  'e',  'l',  'e',  't',  'e',  'c',  'h',  'a',  'n',  'n',  'e',  'l', 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

	 'h',  't',  't',  'p',  ':',  '/',  '/',  'd',  'c',  'd',  '.',  'm',  'o',  'n',  't',  'e',/* refresh: 64B */
     'r',  'n',  'e',  't',  '.',  'c',  'o',  'm',  '/',  'c',  'o',  'n',  't',  'e',  'n',  't',
     '/',  'r',  'e',  'f',  'r',  'e',  's',  'h', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

	 'h',  't',  't',  'p',  ':',  '/',  '/',  'd',  'c',  'd',  '.',  'm',  'o',  'n',  't', 'e',/* help: 64B */
     'r',  'n',  'e',  't',  '.',  'c',  'o',  'm',  '/',  's',  'e',  'r',  'v',  'i',  'c', 'e',
     '/',  'h',  'e',  'l',  'p', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00    /* storage switch */
};
#elif (defined __DCD_V30__)
static kal_uint8 const NVRAM_EF_DCD_EM_PARAM_DATA_DEFAULT[NVRAM_EF_DCD_EM_PARAM_DATA_SIZE] = 
{
     'c',  'm',  'w',  'a',  'p', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* APN: 12B */
     'C',  'h',  'i',  'n',  'a',  ' ',  'M',  'o',  'b',  'i',  'l',  'e', /* APN name: 24B */
	 ' ',  'G',  'P',  'R',  'S', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	 '0',  '1',  '0',  '.',  '0',  '0',  '0',  '.',  '0',  '0',  '0',  '.', /* gate way: 20B*/
	 '1',  '7',  '2', 0x00, 0x00, 0x00, 0x00, 0x00,
	 '8',  '0', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,                        /* port: 8B */

    /* for cmcc test platform */
     'h',  't',  't',  'p',  ':',  '/',  '/',  '2',  '1',  '8',  '.',  '2',  '0',  '6',  '.', '1', /* add channel: 64B */
     '7',  '6',  '.',  '2',  '4',  '8',  ':',  '1',  '0',  '0',  '8',  '1',  '/',  's',  'e', 'r',
     'v',  'i',  'c',  'e',  '/',  'a',  'd',  'd',  'c',  'h',  'a',  'n',  'n',  'e',  'l', 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

     'h',  't',  't',  'p',  ':',  '/',  '/',  '2',  '1',  '8',  '.',  '2',  '0',  '6',  '.', '1', /* delete channel: 64B */
     '7',  '6',  '.',  '2',  '4',  '8',  ':',  '1',  '0',  '0',  '8',  '1',  '/',  's',  'e', 'r',
     'v',  'i',  'c',  'e',  '/',  'd',  'e',  'l',  'e',  't',  'e',  'c',  'h',  'a',  'n', 'n', 
     'e',  'l', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

     'h',  't',  't',  'p',  ':',  '/',  '/',  '2',  '1',  '8',  '.',  '2',  '0',  '6',  '.', '1', /* refresh: 64B */
     '7',  '6',  '.',  '2',  '4',  '8',  ':',  '1',  '0',  '0',  '8',  '0', 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

     // http://218.206.176.248:10081/service/help
     'h',  't',  't',  'p',  ':',  '/',  '/',  '2',  '1',  '8',  '.',  '2',  '0',  '6',  '.', '1', /* help: 64B */
     '7',  '6',  '.',  '2',  '4',  '8',  ':',  '1',  '0',  '0',  '8',  '1',  '/',  's',  'e', 'r',
     'v',  'i',  'c',  'e',  '/',  'h',  'e',  'l',  'p', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00    /* storage switch */
};
#endif
#endif /* __MMI_EM_MISC_DCD__ */



#ifdef __MMI_VUI_MAINMENU__
static kal_uint8 const NVRAM_EF_VENUS_MM_DEFAULT [NVRAM_EF_VENUS_MM_SIZE] =
{
   0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B
};
#endif /*__MMI_VUI_MAINMENU__*/
#ifdef __MMI_VUI_3D_MAINMENU__
static kal_uint8 const NVRAM_EF_VENUS_3D_MM_DEFAULT[NVRAM_EF_VENUS_3D_MM_SIZE] =
{
    0x00, 0x00
};
#endif
#ifdef __MMI_AZAAN_ALARM__
static mmi_hijri_azaan_nvram_struct const NVRAM_EF_AZAAN_ALARM_DEFAULT[NVRAM_AZAAN_ALARM_SIZE] =
{
    /* For Fajr */
    {
    0x05, 0X21, 0x00, 0x00,
    0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  },

    /* For Zuhr */
    {
    0x0C, 0x23, 0x00, 0x00,
    0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  },
    /* For Asr */
    {
    0x10, 0x2D, 0x00, 0x00,
    0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  },
    /* For Magrib */
    {
    0x12, 0x19, 0x00, 0x00,
    0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  },
    /* For Isha */
    {
    0x13, 0x24, 0x00, 0x00,
    0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  }
};
#endif /* __MMI_AZAAN_ALARM__ */

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
static kal_uint8 const NVRAM_EF_SRV_SMS_PDU_DEFAULT[] = {
                        /* status, 1 byte, unused flag */
                        0x00,
                        /* Reminder, 175 byte */
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00,
                        /* timestamp, 4 byte */
                        0x00, 0x00, 0x00, 0x00
                    #ifdef __SRV_SMS_MULTI_SIM__
                        /* sim_id, 2 byte */
                        , 0x01, 0x01
                    #endif
                    #ifdef __SRV_SMS_MULTI_ADDR__
                        /* addr_num, 2 byte */
                        , 0x00, 0x00
                        /* start_addr_id, 2 byte, invalid address ID */
                        , 0xFF, 0xFF
                    #endif
                    #ifdef __SRV_SMS_RESEND_COUNT__
                        /* resend_count, 1 byte */
                        , 0x00
                    #endif
                    #ifdef __SRV_SMS_DELIVERY_STATUS__
                        /* tp_st, 1 byte, invalid delivery status */
                        , 0xFF
                    #endif
                  };
#endif


#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
static nvram_ef_op11_hs32_hist_struct const NVRAM_EF_OP11_HS32_HIST_DEFAULT[NVRAM_EF_OP11_HS32_HIST_TOTAL] =
{
	{
		{0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* sidebar items */
		{
			{0x00, 0x01, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Call  0*/
			{0x00, 0x02, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Contacts (PHB) 1*/
#ifdef __MMI_UNIFIED_COMPOSER__
			{0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Message  2*/
#else
			{0x00, 0x01, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Message  2*/
#endif
			{0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Email  3*/
			{0x00, 0x01, 0x02, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Orange Messenger  4*/
			{0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0xff, 0xff, 0xff, 0xff}, /* Orange World (WAP)  5*/
			{0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Profile  6*/
			{0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Alarms  7*/
			{0x00, 0x01, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Calendar  8*/
			{0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Music  9*/
			{0x00, 0x01, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Photography  10*/
#if defined(__MMI_BT_SUPPORT__) && defined(__MMI_WLAN_FEATURES__)
			{0x00, 0x01, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Connections (WIFI, BT, Flight Mode)  11*/
#elif defined(__MMI_WLAN_FEATURES__)
			{0x00, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Connections (WIFI, Flight Mode)  11*/
#elif defined(__MMI_BT_SUPPORT__)
			{0x01, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Connections (BT, Flight Mode)  11*/
#else
			{0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Connections (Flight Mode)  11*/
#endif
			{0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Device Status  12*/
			{0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* SIM Toolkit  13*/
			{0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Take Photo 14 */
			{0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* VIP Contacts 15 */
			{0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* AP reserved (PHB for example) 16 */
			{0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff} /* */
		},
            {0xff, 0xff, 0xff, 0xff} /* wall paper panel */
	}
};
#endif /*defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)*/

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
#ifdef __SRV_CBS_SUPPORT__
static nvram_ef_srv_cbs_page_struct const NVRAM_EF_SRV_CBS_PAGE_DEFAULT[] =
                                                {
                                                    0xFFFF,
                                                    {0}
                                                };
static nvram_ef_srv_cbs_msg_node_struct const NVRAM_EF_SRV_CBS_MSG_NODE_DEFAULT[] =
                                                {
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0xFFFF,
                                                    0
                                                };

static nvram_ef_srv_cbs_chnl_name_struct const NVRAM_EF_SRV_CBS_CHNL_NAME_DEFAULT[] =
                                                {
                                                    0xFFFF,
                                                    {0}
                                                };
#endif
#endif /* !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) */

#ifdef __BT_SUPPORT__
#if defined(PLUTO_MMI) && defined(__LOW_COST_SUPPORT_COMMON__) // SLIM:memory reduction
static kal_uint8 const NVRAM_EF_SRV_BT_CM_DEFAULT[] = {
0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xFF, 0xFF, 0xFF, 0xFF, 'M',  'T',  'K',  'B',
'T',  'D',  'E',  'V',  'I',  'C',  'E',  0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
#else
static kal_uint8 const NVRAM_EF_SRV_BT_CM_DEFAULT[] = {
0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xFF, 0xFF, 0xFF, 0xFF, 'M',  'T',  'K',  'B',
'T',  'D',  'E',  'V',  'I',  'C',  'E',  0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00
};
#endif  // SLIM:memory reduction


static kal_uint8 const NVRAM_EF_SRV_BT_CM_SYS_DEFAULT[] = {
#ifdef __BT_LE_ONLY__
	  0xd0, 0x00, 0x00, 0x00,
#else
    0xf0, 0x00, 0x00, 0x00,
#endif
#ifdef __MMI_BTBOX_NOLCD__
    'B',  'T',  'B',  'O',
    'X',  'N',  'o',  'L',
    'C',  'D',  0x00, 0x00,
#else /* __MMI_BTBOX_NOLCD__ */
    'M',  'T',  'K',  'B',
    'T',  'D',  'E',  'V',
    'I',  'C',  'E',  0x00,
#endif /* __MMI_BTBOX_NOLCD__ */
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};
#endif  /* __BT_SUPPORT__ */

#ifdef __BT_AUTO_DETECT_SUPPORT__
static kal_uint8 const NVRAM_EF_BT_AUTO_DETECT_SETTING_DEFAULT[NVRAM_EF_BT_AUTO_DETECT_SETTING_SIZE] =
{
	0x1,		/* show_bt_menu */
	0x1		/* auto_detect_bt_chip */
};
#endif /* __BT_AUTO_DETECT_SUPPORT__ */

#ifdef __MMI_PUSH_TURN_ON_OFF_SWITCH__
static kal_uint8 const NVRAM_EF_PUSH_SWITCH_SETTING_DEFAULT[NVRAM_EF_PUSH_SWITCH_SETTING_SIZE] = 
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
#endif
    0x01
};
#endif /* __MMI_PUSH_TURN_ON_OFF_SWITCH__ */

#ifdef __MMI_BROWSER_2__
#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
    #ifdef __GOOGLE_SEARCH_SUPPORT__
        const kal_uint8 COMMON_NVRAM_EF_WAP_HOMEPAGE_DEFAULT[] = {"http://www.google.com/m/search?client=ms-mtk"};
    #else
        #ifdef __MMI_SEARCH_WEB_BAIDU__ 
            const kal_uint8 COMMON_NVRAM_EF_WAP_HOMEPAGE_DEFAULT[] = {"http://www.google.com/m/search?client=ms-mtk-free"};
        #else
            const kal_uint8 COMMON_NVRAM_EF_WAP_HOMEPAGE_DEFAULT[] = {"http://www.google.com/m/search?client=ms-mtk"};
        #endif
    #endif
#endif
#endif /* __MMI_BROWSER_2__ */

#ifdef __MMI_VUI_LAUNCHER__
static kal_uint8 const NVRAM_EF_VAPP_DRAWER_ORDER_DATA_DEFAULT[NVRAM_EF_VAPP_DRAWER_ORDER_DATA_SIZE] = {0};
#endif /* __MMI_VUI_LAUNCHER__ */
#ifdef __MMI_VUI_LAUNCHER_KEY__
static kal_uint8 const NVRAM_EF_VAPP_KMM_ORDER_DATA_DEFAULT[NVRAM_EF_VAPP_KMM_ORDER_DATA_SIZE] = {0};
#endif

#ifdef __WIFI_SUPPORT__
static const kal_uint8 NVRAM_EF_WLAN_SETTING_DEFAULT[NVRAM_MAX_WLAN_SETTING_SIZE] = 
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00};
#endif /* __WIFI_SUPPORT__ */

#ifdef __MMI_VUI_LAUNCHER_KEY__
static const kal_uint8 NVRAM_EF_PHNSET_SHCUT_APP_LIST_DEFAULT[] = 
{
	'n','a','t','i','v','e','.','m','t','k','.','d','i','a','l','e','r', 0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0, 	
	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,  0, 
	'n','a','t','i','v','e','.','m','t','k','.','m','e','s','s','a','g','i','n','g', 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,
	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,	 0,  0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	
	'n','a','t','i','v','e','.','m','t','k','.','p','h','o','n','e','b','o','o','k', 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,
	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,	 0,  0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	
#ifdef __MMI_GB_WINGUO__
	'n','a','t','i','v','e','.','g','u','o','b','i','.','w','i','n','g','u','o','_','n','e','t', 0,  0,  0,  0,  0,  0,  0, 
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
#endif	 
#ifdef __MMI_MEDIA_PLAYER__
	'n','a','t','i','v','e','.','m','t','k','.','m','e','d','i','a','p','l','a','y','e','r', 0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
#else /* __MMI_MEDIA_PLAYER__ */
	'n','a','t','i','v','e','.','m','t','k','.','a','u','d','i','o','p','l','a','y','e','r', 0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
#endif /* __MMI_MEDIA_PLAYER__ */ 
#ifdef __MMI_MAINLCD_320X240__ /* 4 default shortcuts */ 
#if defined(__MMI_CAMCORDER__)
	'n','a','t','i','v','e','.','m','t','k','.','c','a','m','c','o','r','d','e','r', 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
#elif defined(__MMI_CAMERA__)
	'n','a','t','i','v','e','.','m','t','k','.','c','a','m','c','e','r','a', 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
#else
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
#endif
#endif
};
#endif /* __MMI_VUI_LAUNCHER_KEY__ */

#ifdef __MMI_NSS_SUPPORT__
#ifdef __COSMOS_MMI_PACKAGE__
    #ifdef __LOW_COST_SUPPORT_COMMON__
        static nvram_ef_srv_nss_struct  NVRAM_EF_SRV_NSS_PROFILE_DEFAULT[] = 
        {
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}
        };
    #else
        static nvram_ef_srv_nss_struct  NVRAM_EF_SRV_NSS_PROFILE_DEFAULT[] = 
        {
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0}
        };
    #endif/*__LOW_COST_SUPPORT_COMMON__*/
#else
    static nvram_ef_srv_nss_struct  NVRAM_EF_SRV_NSS_PROFILE_DEFAULT[] = 
        {
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}
        };
#endif 
#endif

#ifdef __MMI_MRE_MSPACE__
extern kal_int8 const  NVRAM_MSPACE_URL[]; 
#endif

#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
static const kal_uint8  NVRAM_EF_SYS_LANGUAGE_SSC_DEFAULT[NVRAM_EF_SYS_LANGUAGE_SSC_SIZE] =
{'*', '#', '0', '0', '4', '4', '#', 0x00, 0x00, 0x00};
#endif /*__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__*/

#if defined(__WIFI_SUPPORT__) && defined(__IOT__)
static nvram_ef_srv_dtcnt_wlan_scan_setting_struct NVRAM_EF_WLAN_SCAN_SETTING_DEFAULT[] = 
{
    {
        0x3C, 0x01, 0x00, 
        {
            {
                0x00, 
                {
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00
                }
            }, 
            {
                0x00, 
                {
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00
                }
            },
            {
                0x00, 
                {
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00
                }
            },
            {
                0x00, 
                {
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00
                }
            },
            {
                0x00, 
                {
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00
                }
            },
            {
                0x00, 
                {
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00
                }
            },
            {
                0x00, 
                {
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00
                }
            }
            
         }
    }
};
#endif


#ifndef __MMI_TELEPHONY_SUPPORT__
static nvram_ef_phone_lock_struct NVRAM_EF_PHONE_LOCK_DEFAULT=
{	
	{"1122"},
	0		
};
#endif /* __MMI_TELEPHONY_SUPPORT__ */

#if defined(__FUDIFFNET_ENABLE__)
//for lite DM
static nvram_ef_diff_fota_info_struct NVRAM_EF_DIFF_FOTA_INFO_DEFAULT=
{
    {"MTK"},         //brand
    {"MTK_liteDM"}, //model
    {"MTKRelease"},  //domain
    {"192251"}      //pin-code
};
//for SWM client
static nvram_ef_diff_fota_info_swmc_struct NVRAM_EF_DIFF_FOTA_INFO_SWMC_DEFAULT=
{
    {"MTK"},         //brand
    {"MTK_Release"}, //model
    {"MTKRelease"}, //domain
    {"192251"}      //pin-code
};
#endif

#if defined(__FUNET_ENABLE__)
static nvram_ef_ubin_fota_info_struct NVRAM_EF_UBIN_FOTA_INFO_DEFAULT=
{
    {"https://iotlab.mediatek.com/fota/general/1.1/files/download"},//domain
    {"RD_ANDROID"},                                           //model
    {"99f7f7712cded91b48b13c82d913dfed"}                            //dl key
};
#endif

#if defined(__MMI_USB_FIRMWARE_UPDATE__)
static nvram_ef_usb_fota_info_struct NVRAM_EF_USB_FOTA_INFO_DEFAULT=
{
    {"https://iotlab.mediatek.com/fota/general/1.1/files/download"},//domain
    {"RD_ANDROID"},                                                 //model
    {"99f7f7712cded91b48b13c82d913dfed"}                            //dl key
};
#endif

#if defined(__ROCK_FOTA_SUPPORT__)
static nvram_ef_rock_fota_info_struct NVRAM_EF_ROCK_FOTA_INFO_DEFAULT=
{
    {"MTK"},         //brand
    {"Wearable"}, //model
};
#endif

#ifdef __MMI_BLOOD_PRESSURE_SUPPORT__
static nvram_ef_bp_info_struct NVRAM_EF_BP_INFO_DEFAULT=
{
	173,
	65,
	1,
	35,
	80,
    {"default"}
};

#endif

/**
 * Steps of defining logical data item:
 * 1> Define LID of new logical data item into `nvram_LID_cust_enum' in
 *    nvram_user_defs.h
 * 2> Define two constants: SIZE and TOTAL, in nvram_user_defs.h
 * 3> Define default value of that new logical data item in nvram_user_config.c
 * 4> Define attributes of that new logical data item into
 *    `logical_data_item_table_cust'
 * 5> Bypass.
 * 6> Change version number CODED_DATA_VERSION in nvram_user_config.c
 */
/**
 * The logical data item table.
 * Note:
 * Each logical data item must be:
 * 1> Size must be EVEN
 * 2> Size of default value must be equal to the logical data item's size.
 */
 /**
 * The rule for data item changes:
 * 1. To add a new data item, its name must be the next of the current last LID, for example,
 *     the last LID in the CT reign now is CT20, the new one must be CT21.
 * 2. Version must be increased if
 *    (a) Size is changed, or
 *    (b) Number of sections is changed, or
 *    (c) Attribute is changed, or
 *    (d) data structure is changed.
 */
ltable_entry_struct logical_data_item_table_common_app[] =
{
#ifdef __PHB_STORAGE_BY_MMI__
    #ifdef __MMI_TELEPHONY_SUPPORT__

    {
        NVRAM_EF_PHB_LID,
        NVRAM_EF_PHB_TOTAL,
        NVRAM_EF_PHB_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MP0C",
        VER(NVRAM_EF_PHB_LID)
    },
    #endif
#endif    

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    {
        NVRAM_EF_AUTOTEST_LID,
        NVRAM_EF_AUTOTEST_TOTAL,
        NVRAM_EF_AUTOTEST_SIZE ,
        NVRAM_NORMAL(NVRAM_EF_AUTOTEST_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP07",
        VER(NVRAM_EF_AUTOTEST_LID)
    },
#endif

#if defined(PLUTO_MMI) || defined(VENUS_MMI)
#if (defined(__UPDATE_BINARY_FILE__) && !defined(__NVRAM_SUPPORT_CUSTPACK__)) 

    {
        NVRAM_EF_CACHE_BYTE_LID,
        NVRAM_CACHE_TOTAL,
        NVRAM_CACHE_SIZE,
        NVRAM_CUSTPACK(NVRAM_EF_MMI_CACHE_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE,
        "MM00",
        VER(NVRAM_EF_CACHE_BYTE_LID)
    },
    
    {
        NVRAM_EF_CACHE_SHORT_LID,
        NVRAM_CACHE_TOTAL,
        NVRAM_CACHE_SIZE,
        NVRAM_CUSTPACK(NVRAM_EF_MMI_CACHE_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE,
        "MM01",
        VER(NVRAM_EF_CACHE_SHORT_LID)
    },
    
    {
        NVRAM_EF_CACHE_DOUBLE_LID,
        NVRAM_CACHE_TOTAL,
        NVRAM_CACHE_SIZE,
        NVRAM_CUSTPACK(NVRAM_EF_MMI_CACHE_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE,
        "MM02",
        VER(NVRAM_EF_CACHE_DOUBLE_LID)
    },
    
    {
        NVRAM_EF_MMI_CACHE_BYTE_KEY_LID,
        NVRAM_MMI_CACHE_BYTE_KEY_TOTAL,
        NVRAM_MMI_CACHE_BYTE_KEY_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_MMI_CACHE_BYTE_KEY_DEFAULT_R),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_NOT_ZIP_DEFAULT | NVRAM_ATTR_MULTI_DEFAULT,
        "MM03",
        VER(NVRAM_EF_MMI_CACHE_BYTE_KEY_LID)
    },
    
    {
        NVRAM_EF_MMI_CACHE_SHORT_KEY_LID,
        NVRAM_MMI_CACHE_SHORT_KEY_TOTAL,
        NVRAM_MMI_CACHE_SHORT_KEY_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_MMI_CACHE_SHORT_KEY_DEFAULT_R),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_NOT_ZIP_DEFAULT | NVRAM_ATTR_MULTI_DEFAULT,
        "MM04",
        VER(NVRAM_EF_MMI_CACHE_SHORT_KEY_LID)
    },
    
    {
        NVRAM_EF_MMI_CACHE_DOUBLE_KEY_LID,
        NVRAM_MMI_CACHE_DOUBLE_KEY_TOTAL,
        NVRAM_MMI_CACHE_DOUBLE_KEY_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_MMI_CACHE_DOUBLE_KEY_DEFAULT_R),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_NOT_ZIP_DEFAULT | NVRAM_ATTR_MULTI_DEFAULT,
        "MM05",
        VER(NVRAM_EF_MMI_CACHE_DOUBLE_KEY_LID)
    },
#else
    {
        NVRAM_EF_CACHE_BYTE_LID,
        NVRAM_CACHE_TOTAL,
        NVRAM_CACHE_SIZE,
        NVRAM_CUSTPACK(NVRAM_EF_MMI_CACHE_BYTE_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE,
        "MM00",
        VER(NVRAM_EF_CACHE_BYTE_LID)
    },
    
    {
        NVRAM_EF_CACHE_SHORT_LID,
        NVRAM_CACHE_TOTAL,
        NVRAM_CACHE_SIZE,
        NVRAM_CUSTPACK(NVRAM_EF_MMI_CACHE_SHORT_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE,
        "MM01",
        VER(NVRAM_EF_CACHE_SHORT_LID)
    },
    
    {
        NVRAM_EF_CACHE_DOUBLE_LID,
        NVRAM_CACHE_TOTAL,
        NVRAM_CACHE_SIZE,
        NVRAM_CUSTPACK(NVRAM_EF_MMI_CACHE_DOUBLE_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE,
        "MM02",
        VER(NVRAM_EF_CACHE_DOUBLE_LID)
    },
    
    {
        NVRAM_EF_MMI_CACHE_BYTE_KEY_LID,
        NVRAM_MMI_CACHE_BYTE_KEY_TOTAL,
        NVRAM_MMI_CACHE_BYTE_KEY_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_MMI_CACHE_BYTE_KEY_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_NOT_ZIP_DEFAULT | NVRAM_ATTR_MULTI_DEFAULT,
        "MM03",
        VER(NVRAM_EF_MMI_CACHE_BYTE_KEY_LID)
    },
    
    {
        NVRAM_EF_MMI_CACHE_SHORT_KEY_LID,
        NVRAM_MMI_CACHE_SHORT_KEY_TOTAL,
        NVRAM_MMI_CACHE_SHORT_KEY_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_MMI_CACHE_SHORT_KEY_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_NOT_ZIP_DEFAULT | NVRAM_ATTR_MULTI_DEFAULT,
        "MM04",
        VER(NVRAM_EF_MMI_CACHE_SHORT_KEY_LID)
    },
    
    {
        NVRAM_EF_MMI_CACHE_DOUBLE_KEY_LID,
        NVRAM_MMI_CACHE_DOUBLE_KEY_TOTAL,
        NVRAM_MMI_CACHE_DOUBLE_KEY_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_MMI_CACHE_DOUBLE_KEY_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_NOT_ZIP_DEFAULT | NVRAM_ATTR_MULTI_DEFAULT,
        "MM05",
        VER(NVRAM_EF_MMI_CACHE_DOUBLE_KEY_LID)
    },

#endif    
#endif

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    {
        NVRAM_EF_PHB_SOS_LID,
        NVRAM_EF_PHB_SOS_TOTAL,
        NVRAM_EF_PHB_SOS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP0E",
        VER(NVRAM_EF_PHB_SOS_LID)
    },

#if defined(__MMI_PHB_SPEED_DIAL__)
    {
        NVRAM_EF_PHB_SPEEDDIAL_LID,
        NVRAM_EF_PHB_SPEEDDIAL_TOTAL,
        NVRAM_EF_PHB_SPEEDDIAL_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP0F",
        VER(NVRAM_EF_PHB_SPEEDDIAL_LID)
    },
#endif /* defined(__MMI_PHB_SPEED_DIAL__) */
    #ifdef __MMI_TELEPHONY_SUPPORT__

    {
        NVRAM_EF_PHB_FIELDS_LID,
        NVRAM_EF_PHB_FIELDS_TOTAL,
        NVRAM_EF_PHB_FIELDS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ,
        "MP0H",
        VER(NVRAM_EF_PHB_FIELDS_LID)
    },
    #endif
    {
        NVRAM_EF_PHB_FIELDS_MASK_LID,
        NVRAM_EF_PHB_FIELDS_MASK_TOTAL,
        NVRAM_EF_PHB_FIELDS_MASK_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIPLE,
        "MP0I",
        VER(NVRAM_EF_PHB_FIELDS_MASK_LID)
    },

#ifdef __MMI_PHB_CALLER_GROUP__
    {
        NVRAM_EF_PHB_GROUP_INFO_LID,
        NVRAM_EF_PHB_GROUP_INFO_TOTAL,
        NVRAM_EF_PHB_GROUP_INFO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP0J",
        VER(NVRAM_EF_PHB_GROUP_INFO_LID)
    },
#endif /* __MMI_PHB_CALLER_GROUP__ */

    {
        NVRAM_EF_PHB_MY_NUMBER_LID,
        NVRAM_EF_PHB_MY_NUMBER_TOTAL,
        NVRAM_EF_PHB_MY_NUMBER_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP0K",
        VER(NVRAM_EF_PHB_MY_NUMBER_LID)
    },

#ifdef __MMI_PHB_CALLER_GROUP__
    {
        NVRAM_EF_PHB_GROUP_FIELD_LID,
        NVRAM_EF_PHB_GROUP_FIELD_TOTAL,
        NVRAM_EF_PHB_GROUP_FIELD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP0M",
        VER(NVRAM_EF_PHB_GROUP_FIELD_LID)
    },
#endif /* __MMI_PHB_CALLER_GROUP__ */

    {
        NVRAM_EF_PHB_INFO_LID,
        NVRAM_EF_PHB_INFO_TOTAL,
        NVRAM_EF_PHB_INFO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP0Q",
        VER(NVRAM_EF_PHB_INFO_LID)
    },
#endif /* !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) */

#ifdef __MMI_MESSAGES_PREDEFINED_TEMPLATE__
    {
        NVRAM_EF_SMS_LID,
        NVRAM_SMS_RECORD_TOTAL,
        NVRAM_SMS_TEMPL_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP0V",
        VER(NVRAM_EF_SMS_LID)
    },
#endif/*__MMI_MESSAGES_PREDEFINED_TEMPLATE__*/

#ifdef __DOWNLOAD__
    {
        NVRAM_EF_EMS_MY_PICTURE_NAME_LID,
        NVRAM_EMS_MY_PICTURE_NAME_RECORD_TOTAL,
        NVRAM_EMS_MY_PICTURE_NAME_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP0Z",
        VER(NVRAM_EF_EMS_MY_PICTURE_NAME_LID)
    },
    
    {
        NVRAM_EF_EMS_MY_ANIMATION_NAME_LID,
        NVRAM_EMS_MY_ANIMATION_NAME_RECORD_TOTAL,
        NVRAM_EMS_MY_ANIMATION_NAME_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP10",
        VER(NVRAM_EF_EMS_MY_ANIMATION_NAME_LID)
    },

    #ifdef __MMI_IMELODY_SUPPORT__
    {
        NVRAM_EF_EMS_MY_MELODY_NAME_LID,
        NVRAM_EMS_MY_MELODY_NAME_RECORD_TOTAL,
        NVRAM_EMS_MY_MELODY_NAME_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP11",
        VER(NVRAM_EF_EMS_MY_MELODY_NAME_LID)
    },
    #endif

#endif/*__DOWNLOAD__*/

#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
    {
        NVRAM_EF_CAMERA_SETTING_LID,
        NVRAM_EF_CAMERA_SETTING_TOTAL,
        NVRAM_EF_CAMERA_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP1B",
        VER(NVRAM_EF_CAMERA_SETTING_LID)
    },
#endif/* defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__) */

#if defined (__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)
    {
        NVRAM_EF_VIDEO_SETTING_LID,
        NVRAM_EF_VIDEO_SETTING_TOTAL,
        NVRAM_EF_VIDEO_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP1C",
        VER(NVRAM_EF_VIDEO_SETTING_LID)
    },
#endif/* defined (__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__) */

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    #ifdef __IP_NUMBER__
    {
        NVRAM_EF_IP_NUMBER_LID,
        NVRAM_IP_NUMBER_TOTAL,
        NVRAM_IP_NUMBER_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP1H",
        VER(NVRAM_EF_IP_NUMBER_LID)
    },
    #endif/*__IP_NUMBER__*/
#endif


#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
  #ifdef __no_remove__
    {
        NVRAM_EF_ALM_QUEUE_LID,
        NVRAM_ALM_QUEUE_TOTAL,
        NVRAM_ALM_QUEUE_SIZE ,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER ,
        NVRAM_ATTR_SW_VERNO_RESET,
        "MP1L",
        VER(NVRAM_EF_ALM_QUEUE_LID)
    },
  #endif
    
    {
        NVRAM_EF_ALM_SPOF_DATA_LID,
        NVRAM_ALM_SPOF_DATA_TOTAL,
        NVRAM_ALM_SPOF_DATA_SIZE ,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_SW_VERNO_RESET,
        "MP1M",
        VER(NVRAM_EF_ALM_SPOF_DATA_LID)
    },
    
    {
        NVRAM_EF_ALM_ALARM_DATA_LID,
        NVRAM_ALM_ALARM_DATA_TOTAL,
        NVRAM_ALM_ALARM_DATA_SIZE ,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_SW_VERNO_RESET,
        "MP1N",
        VER(NVRAM_EF_ALM_ALARM_DATA_LID)
    },
#endif /* #if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) */

#ifdef __MMI_TODOLIST__
    {
        NVRAM_EF_TODO_LIST_LID,
        NVRAM_TODO_LIST_RECORD_TOTAL,
        NVRAM_TODO_LIST_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MP1O",
        VER(NVRAM_EF_TODO_LIST_LID)
    },
#endif/* __MMI_TODOLIST__ */

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
#if 0 /* Phased out greeting text */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
#endif /* #if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) */

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    {
        NVRAM_EF_GROUPLIST_LID,
        NVRAM_MAX_GROUP_NAME_TOTAL,
        NVRAM_MAX_GROUP_NAME_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP1R",
        VER(NVRAM_EF_GROUPLIST_LID)
    },
#endif

#ifdef __MMI_FILE_MANAGER__
    {
        NVRAM_EF_WALLPAPER_FILENAME_LID,
        NVRAM_EF_WALLPAPER_FILENAME_TOTAL,
        NVRAM_EF_DISP_CACHE_SET_FILENAME_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP1S",
        VER(NVRAM_EF_WALLPAPER_FILENAME_LID)
    },
#endif /* __MMI_FILE_MANAGER__ */

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    {
        NVRAM_EF_SHORTCUTS_LID,
        NVRAM_SHORTCUTS_TOTAL,
        NVRAM_SHORTCUTS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_SW_VERNO_RESET | NVRAM_ATTR_FACTORY_RESET,
        "MP1T",
        VER(NVRAM_EF_SHORTCUTS_LID)
    },
#endif


#ifdef __MMI_STOPWATCH__
    {
        NVRAM_EF_STOPWATCH_LID,
        NVRAM_EF_STOPWATCH_RECORD_TOTAL,
        NVRAM_EF_STOPWATCH_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP1W",
        VER(NVRAM_EF_STOPWATCH_LID)
    },
#endif/*__MMI_STOPWATCH__*/

#ifdef __MMI_PICTURE_EDITOR_SUPPORT__
    {
        NVRAM_PICTURE_EDITOR_LID,
        NVRAM_PICTURE_EDITOR_TOTAL,
        NVRAM_PICTURE_EDITOR_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP1X",
        VER(NVRAM_PICTURE_EDITOR_LID)
    },
#endif/*__MMI_PICTURE_EDITOR_SUPPORT__*/

#ifdef __MMI_FM_RADIO__
    {
        NVRAM_EF_FM_RADIO_LID,
        NVRAM_EF_FM_RADIO_TOTAL,
        NVRAM_EF_FM_RADIO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
    #ifdef __MMI_FM_RADIO_SCHEDULER__
        NVRAM_CATEGORY_USER,
    #else
        NVRAM_CATEGORY_USER,
    #endif
        NVRAM_ATTR_AVERAGE,
        "MP1Z",
        VER(NVRAM_EF_FM_RADIO_LID)
    },
#endif/*__MMI_FM_RADIO__*/

#ifdef __MMI_FM_RADIO_SCHEDULE_REC__
    {
        NVRAM_EF_FMSR_SETTING_LID,
        NVRAM_EF_FMSR_SETTING_TOTAL,
        NVRAM_EF_FMSR_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP20",
        VER(NVRAM_EF_FMSR_SETTING_LID)
    },
#endif/*__MMI_FM_RADIO_SCHEDULE_REC__*/

#ifdef __MMI_VRSD__
    {
        NVRAM_EF_VRSD_TAG_LID,
        NVRAM_EF_VRSD_TAG_TOTAL,
        NVRAM_EF_VRSD_TAG_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_CONFIDENTIAL,
        "MP21",
        VER(NVRAM_EF_VRSD_TAG_LID)
    },
#endif/*__MMI_VRSD__*/

#ifdef __MMI_VRSI__
    {
        NVRAM_EF_VRSI_TAG_LID,
        NVRAM_EF_VRSI_TAG_TOTAL,
        NVRAM_EF_VRSI_TAG_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_CONFIDENTIAL,
        "MP22",
        VER(NVRAM_EF_VRSI_TAG_LID)
    },
#endif /* __MMI_VRSI__*/

#if NVRAM_EF_FMGR_FILEPATH_COUNT  /* not 0 */
    {
        NVRAM_EF_FMGR_FILEPATH_POOL_HEAD_LID,
        NVRAM_EF_FMGR_FILEPATH_POOL_HEAD_TOTAL,
        NVRAM_EF_FMGR_FILEPATH_POOL_HEAD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP23",
        VER(NVRAM_EF_FMGR_FILEPATH_POOL_HEAD_LID)
    },

    {
        NVRAM_EF_FMGR_FILEPATH_POOL_TAIL_LID,
        NVRAM_EF_FMGR_FILEPATH_POOL_TAIL_TOTAL,
        NVRAM_EF_FMGR_FILEPATH_POOL_TAIL_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP24",
        VER(NVRAM_EF_FMGR_FILEPATH_POOL_TAIL_LID)
    },
#endif /* NVRAM_EF_FILEPATH_COUNT */

#ifdef __BT_SUPPORT__
    {
        NVRAM_EF_BT_INFO_LID,
        NVRAM_EF_BT_INFO_TOTAL,
        NVRAM_EF_BT_INFO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_SRV_BT_CM_DEFAULT), //NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP25",
        VER(NVRAM_EF_BT_INFO_LID)
    },

    {
        NVRAM_EF_BT_DEV_LIST_LID,
        NVRAM_EF_BT_DEV_LIST_TOTAL,
        NVRAM_EF_BT_DEV_LIST_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP26",
        VER(NVRAM_EF_BT_DEV_LIST_LID)
    },

    {
        NVRAM_EF_BT_DEV_LIST_INDEX_LID,
        NVRAM_EF_BT_DEV_LIST_INDEX_TOTAL,
        NVRAM_EF_BT_DEV_LIST_INDEX_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP27",
        VER(NVRAM_EF_BT_DEV_LIST_INDEX_LID)
    },

    {
        NVRAM_EF_BT_SYS_INFO_LID,
        NVRAM_EF_BT_INFO_TOTAL,
        NVRAM_EF_BT_SYS_INFO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_SRV_BT_CM_SYS_DEFAULT), //NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP29",
        VER(NVRAM_EF_BT_SYS_INFO_LID)
    },

#endif/*__BT_SUPPORT__*/

#ifdef __MMI_CM_BLACK_LIST__
    {
        NVRAM_EF_BLACK_LIST_LID,
        NVRAM_EF_BLACK_LIST_TOTAL,
        NVRAM_EF_BLACK_LIST_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP2A",
        VER(NVRAM_EF_BLACK_LIST_LID)
    },
#endif/*__MMI_CM_BLACK_LIST__*/

#if defined(__MMI_IMPS__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif/* __MMI_IMPS__ */

#ifdef __MMI_AUDIO_EQUALIZER__
    {
        NVRAM_EF_AUDIO_EQUALIZER_LID,
        NVRAM_EF_AUDIO_EQUALIZER_TOTAL,
        NVRAM_EF_AUDIO_EQUALIZER_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_AUDIO_EQUALIZER_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_FACTORY_RESET | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MP2C",
        VER(NVRAM_EF_AUDIO_EQUALIZER_LID)
    },
#endif/*__MMI_AUDIO_EQUALIZER__*/

#ifdef __MMI_THEMES_APPLICATION__
    {
        NVRAM_EF_THEMES_VALUES,
        NVRAM_THEMES_VALUES_RECORDS,
        NVRAM_THEMES_VALUES_SIZE,
        NVRAM_NORMAL(NVRAM_THEMES_VALUES_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_FACTORY_RESET,
        "MP2G",
        VER(NVRAM_EF_THEMES_VALUES)
    },
#endif/*__MMI_THEMES_APPLICATION__*/

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    {
        NVRAM_EF_THEME_MANAGER_LID,
        NVRAM_EF_THEME_MANAGER_RECORD_TOTAL,
        NVRAM_EF_THEME_MANAGER_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP2H",
        VER(NVRAM_EF_THEME_MANAGER_LID)
    },

    {
        NVRAM_EF_THEME_DOWNLOAD_LIST_LID,
        NVRAM_THEMES_DOWNLOAD_RECORDS,
        NVRAM_THEMES_DOWNLOAD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP2I",
        VER(NVRAM_EF_THEME_DOWNLOAD_LIST_LID)
    },
#endif/* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */

#ifdef __MMI_MOTION_APP__
    {
        NVRAM_EF_MOTION_DICE_LID,
        NVRAM_EF_MOTION_DICE_TOTAL,
        NVRAM_EF_MOTION_DICE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP2J",
        VER(NVRAM_EF_MOTION_DICE_LID)
    },

    {
        NVRAM_EF_MOTION_DJ_LID,
        NVRAM_EF_MOTION_DJ_TOTAL,
        NVRAM_EF_MOTION_DJ_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP2K",
        VER(NVRAM_EF_MOTION_DJ_LID)
    },
#endif/* __MMI_MOTION_APP__ */

#ifdef __MMI_BG_SOUND_EFFECT__
    {
        NVRAM_EF_BGSND_SETTING_LID,
        NVRAM_EF_BGSND_SETTING_TOTAL,
        NVRAM_EF_BGSND_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP2M",
        VER(NVRAM_EF_BGSND_SETTING_LID)
    },

    {
        NVRAM_EF_BGSND_FILEPATH_LID,
        NVRAM_EF_BGSND_FILEPATH_TOTAL,
        NVRAM_EF_BGSND_FILEPATH_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP2N",
        VER(NVRAM_EF_BGSND_FILEPATH_LID)
    },
#endif/* __MMI_BG_SOUND_EFFECT__ */

#ifdef __MMI_EBOOK_READER__
    {
        NVRAM_EF_EBOOK_SETTINGS_LID,
        NVRAM_EF_EBOOK_SETTING_TOTAL,
        NVRAM_EF_EBOOK_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_EBOOK_DEFAULT_VALUE),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_FACTORY_RESET,
        "MP30",
        VER(NVRAM_EF_EBOOK_SETTINGS_LID)
    },
#endif /* __MMI_EBOOK_READER__ */

#ifdef __MMI_BARCODEREADER__
    {
        NVRAM_EF_BARCODEREADER_SETTING_LID,
        NVRAM_EF_BARCODEREADER_SETTING_TOTAL,
        NVRAM_EF_BARCODEREADER_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP32",
        VER(NVRAM_EF_BARCODEREADER_SETTING_LID)
    },
#endif /* __MMI_BARCODEREADER__ */

#if defined(__MMI_A2DP_SUPPORT__)
    {
        NVRAM_EF_A2DP_SETTINGS_LID,
        1,
        sizeof(nvram_ef_a2dp_settings_struct),
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP36",
        VER(NVRAM_EF_A2DP_SETTINGS_LID)
    },
#endif /* __MMI_A2DP_SUPPORT__*/

#ifdef __MMI_VOIP__
    {
        NVRAM_EF_VOIP_PROF_LID,
        NVRAM_EF_VOIP_PROF_TOTAL,
        NVRAM_EF_VOIP_PROF_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP37",
        VER(NVRAM_EF_VOIP_PROF_LID)
    },

    {
        NVRAM_EF_VOIP_SETTING_LID,
        NVRAM_EF_VOIP_SETTING_TOTAL,
        NVRAM_EF_VOIP_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP38",
        VER(NVRAM_EF_VOIP_SETTING_LID)
    },
#endif /* __MMI_VOIP__*/

#ifdef __WIFI_SUPPORT__
    {
        NVRAM_EF_WLAN_SETTING_LID,
        NVRAM_MAX_WLAN_SETTING_TOTAL,
        NVRAM_MAX_WLAN_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_WLAN_SETTING_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP39",
        VER(NVRAM_EF_WLAN_SETTING_LID)
    },

    {
        NVRAM_EF_WLAN_PROFILE_LID,
        NVRAM_MAX_WLAN_PROFILE_TOTAL,
        NVRAM_MAX_WLAN_PROFILE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP40",
        VER(NVRAM_EF_WLAN_PROFILE_LID)
    },
#endif /* __WIFI_SUPPORT__*/

#if defined(__EM_MODE__) && defined(__MMI_ENGINEER_MODE__)
    {
        NVRAM_EF_EM_NW_EVENT_RINGS_LID,
        NVRAM_EF_EM_NW_EVENT_RINGS_TOTAL,
        NVRAM_EF_EM_NW_EVENT_RINGS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT36",
        VER(NVRAM_EF_EM_NW_EVENT_RINGS_LID)
    },
#endif /* defined(__EM_MODE__) && defined(__MMI_ENGINEER_MODE__) */

#ifdef __MMI_NITZ__

    {
        NVRAM_EF_NITZ_NW_NAME_LID,
        NVRAM_NITZ_NW_NAME_TOTAL,
        NVRAM_NITZ_NW_NAME_SIZE ,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_SW_VERNO_RESET | NVRAM_ATTR_FACTORY_RESET,
        "MP42",
        VER(NVRAM_EF_NITZ_NW_NAME_LID)
    },
#endif /* __MMI_NITZ__ */

#if defined(__MMI_FWU_VIA_TFTP__)
    {
        NVRAM_EF_DM_FWU_TFTP_SETTING_LID,
        NVRAM_EF_DM_FWU_TFTP_SETTING_TOTAL,
        NVRAM_EF_DM_FWU_TFTP_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_DM_FWU_TFTP_SETTING_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP43",
        VER(NVRAM_EF_DM_FWU_TFTP_SETTING_LID)
    },
#endif /* __MMI_FWU_VIA_TFTP__ */

#if defined(__MMI_FWU_VIA_HTTP__)
    {
        NVRAM_EF_DM_FWU_HTTP_SETTING_LID,
        NVRAM_EF_DM_FWU_HTTP_SETTING_TOTAL,
        NVRAM_EF_DM_FWU_HTTP_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_DM_FWU_HTTP_SETTING_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP44",
        VER(NVRAM_EF_DM_FWU_HTTP_SETTING_LID)
    },
#endif /* #if defined(__MMI_FWU_VIA_HTTP__) */

#ifdef __MMI_AVATAR__
    {
        NVRAM_EF_AVATAR_SETTING_LID,
        NVRAM_EF_AVATAR_SETTING_TOTAL,
        NVRAM_EF_AVATAR_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP47",
        VER(NVRAM_EF_AVATAR_SETTING_LID)
    },
#endif /* __MMI_AVATAR__ */

#ifdef __MMI_BROWSER_2__
#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__

    {
        NVRAM_EF_BRW_ADDRESS_HISTORY_TITLE_LID,
        NVRAM_EF_BRW_ADDRESS_HISTORY_TITLE_RECORDS,
        NVRAM_EF_BRW_ADDRESS_HISTORY_RECORD_TITLE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP48",
        VER(NVRAM_EF_BRW_ADDRESS_HISTORY_TITLE_LID)
    },

    {
        NVRAM_EF_BRW_ADDRESS_HISTORY_URL_LID,
        NVRAM_EF_BRW_ADDRESS_HISTORY_URL_RECORDS,
        NVRAM_EF_BRW_ADDRESS_HISTORY_RECORD_URL_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP49",
        VER(NVRAM_EF_BRW_ADDRESS_HISTORY_URL_LID)
    },
#endif /* #ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__ */
#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
    {
        NVRAM_EF_BRW_SEARCH_ITEM_LID,
        NVRAM_EF_BRW_SEARCH_ITEMS_RECORDS,
        NVRAM_EF_BRW_SEARCH_ITEM_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP41", 
        VER(NVRAM_EF_BRW_SEARCH_ITEM_LID)
    },
#endif /* __MMI_BRW_SEARCH_HISTORY_SUPPORT__ */
    #ifdef __MMI_BRW_ADVANCED_APP_FEATURES__
    {
        NVRAM_EF_BRW_LAST_WEB_ADDR_LID,
        NVRAM_EF_BRW_LAST_WEB_ADDR_RECORDS,
        NVRAM_EF_BRW_LAST_WEB_ADDR_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP4A",
        VER(NVRAM_EF_BRW_LAST_WEB_ADDR_LID)
    },
    #endif /* __MMI_BRW_ADVANCED_APP_FEATURES__  */

#ifdef __MMI_BROWSER_2__
#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
    {
        NVRAM_EF_BRW_USER_DEFINED_HOMEPAGE_LID,
        NVRAM_EF_BRW_USER_DEFINED_HOMEPAGE_RECORDS,
        NVRAM_EF_BRW_USER_DEFINED_HOMEPAGE_SIZE,
        NVRAM_NORMAL(COMMON_NVRAM_EF_WAP_HOMEPAGE_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP4B",
        VER(NVRAM_EF_BRW_USER_DEFINED_HOMEPAGE_LID)
    },
#endif
#endif
#ifdef __MMI_Q05A_LAUNCH_SCREEN__
    {
        NVRAM_EF_BRW_SHORTCUTS_LIST_LID,
        NVRAM_EF_BRW_SHORTCUTS_LIST_RECORDS,
        NVRAM_EF_BRW_SHORTCUTS_LIST_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP51", 
        VER(NVRAM_EF_BRW_SHORTCUTS_LIST_LID)
    },
#endif /* __MMI_BRW_SEARCH_HISTORY_SUPPORT__ */
    #ifndef WAP_SUPPORT
    {
        NVRAM_EF_WAP_PROFILE_CONTENT_LID,
        NVRAM_EF_WAP_PROFILE_CONTENT_TOTAL,
        NVRAM_EF_WAP_PROFILE_CONTENT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_WAP_PROFILE_CONTENT_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_FACTORY_RESET | NVRAM_ATTR_MULTI_DEFAULT,
        "MP4D",
        VER(NVRAM_EF_WAP_PROFILE_CONTENT_LID)
    },

    {
        NVRAM_EF_WAP_PROFILE_NAMES_LID,
        NVRAM_EF_WAP_PROFILE_NAMES_TOTAL,
        NVRAM_EF_WAP_PROFILE_NAMES_SIZE,
        NVRAM_NORMAL(NVRAM_EF_WAP_PROFILE_NAMES_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP4E",
        VER(NVRAM_EF_WAP_PROFILE_NAMES_LID)
    },

    {
        NVRAM_EF_MMS_PROFILE_CONTENT_LID,
        NVRAM_EF_MMS_PROFILE_CONTENT_TOTAL,
        NVRAM_EF_MMS_PROFILE_CONTENT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_MMS_PROFILE_CONTENT_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_FACTORY_RESET | NVRAM_ATTR_MULTI_DEFAULT,
        "MP4F",
        VER(NVRAM_EF_MMS_PROFILE_CONTENT_LID)
    },

    {
        NVRAM_EF_MMS_PROFILE_NAMES_LID,
        NVRAM_EF_MMS_PROFILE_NAMES_TOTAL,
        NVRAM_EF_MMS_PROFILE_NAMES_SIZE,
        NVRAM_NORMAL(NVRAM_EF_MMS_PROFILE_NAMES_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP4G",
        VER(NVRAM_EF_MMS_PROFILE_NAMES_LID)
    },
    #endif /* WAP_SUPPORT */
#endif /* __MMI_BROWSER_2__ */

#ifdef __MMI_CSB_BROWSER__
    {
        NVRAM_EF_CSB_SETTINGS_LID,
        NVRAM_CSB_SETTINGS_TOTAL,
        NVRAM_CSB_SETTINGS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP4H",
        VER(NVRAM_EF_CSB_SETTINGS_LID),
    },
#endif /* __MMI_CSB_BROWSER__ */

#ifdef __MMI_VIDEO_STREAM__
    {
        NVRAM_EF_VIDEO_PREDEFINED_URL_LID,
        NVRAM_EF_VIDEO_PREDEFINED_URL_TOTAL,
        NVRAM_EF_VIDEO_PREDEFINED_URL_SIZE,
        NVRAM_NORMAL(NVRAM_EF_VIDEO_PREDEFINED_URL_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP4I",
        VER(NVRAM_EF_VIDEO_PREDEFINED_URL_LID)
    },
#endif/*__MMI_VIDEO_STREAM__*/

#ifdef __MMI_VIDEO_STREAM__
    {
        NVRAM_EF_VIDEO_HISTORY_URL_LID,
        NVRAM_EF_VIDEO_HISTORY_URL_TOTAL,
        NVRAM_EF_VIDEO_HISTORY_URL_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP4J",
        VER(NVRAM_EF_VIDEO_HISTORY_URL_LID)
    },
#endif/*__MMI_VIDEO_STREAM__*/

#ifdef __MMI_DM_SELF_REGISTER_SUPPORT__
    {
        NVRAM_EF_DM_SR_NUMBER_LID,
        NVRAM_EF_DM_SR_NUMBER_TOTAL,
        NVRAM_EF_DM_SR_NUMBER_SIZE,
        NVRAM_NORMAL(NVRAM_EF_DM_SR_NUMBER_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP4K",
        VER(NVRAM_EF_DM_SR_NUMBER_LID)
    },
#endif /* __MMI_DM_SELF_REGISTER_SUPPORT__ */

#ifdef __MMI_CUSTOMER_SERVICE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_CUSTOMER_SERVICE__ */

#if defined (__MMI_MMS_2__)
    {
        NVRAM_EF_UMMS_COMPOSE_SETTINGS_LID,
        NVRAM_UMMS_COMPOSE_SETTINGS_RECORDS,
        NVRAM_UMMS_COMPOSE_SETTINGS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_MMS_COMPOSE_SETTING_CONTENT_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_FACTORY_RESET,
        "MP4N",
        VER(NVRAM_EF_UMMS_COMPOSE_SETTINGS_LID)
    },

    {
        NVRAM_EF_UMMS_SENDING_SETTINGS_LID,
        NVRAM_UMMS_SENDING_SETTINGS_RECORDS,
        NVRAM_UMMS_SENDING_SETTINGS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_MMS_SENDING_SETTING_CONTENT_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP4O",
        VER(NVRAM_EF_UMMS_SENDING_SETTINGS_LID)
    },
#endif

#if defined (OBIGO_Q03C_MMS_V01)
    {
        NVRAM_EF_MMSV01_COMPOSE_SETTINGS_LID,
        NVRAM_MMSV01_COMPOSE_SETTINGS_RECORDS,
        NVRAM_MMSV01_COMPOSE_SETTINGS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_MMSV01_COMPOSE_SETTING_CONTENT_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP4N",
        VER(NVRAM_EF_MMSV01_COMPOSE_SETTINGS_LID)
    },

    {
        NVRAM_EF_MMSV01_SENDING_SETTINGS_LID,
        NVRAM_MMSV01_SENDING_SETTINGS_RECORDS,
        NVRAM_MMSV01_SENDING_SETTINGS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_MMSV01_SENDING_SETTING_CONTENT_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP4O",
        VER(NVRAM_EF_MMSV01_SENDING_SETTINGS_LID)
    },
#endif

#ifdef __MMI_EMAIL_TEMPLATE__
    {
        NVRAM_EF_EMAIL_TEMPLATE_LID,
        NVRAM_EMAIL_RECORD_TOTAL,
        NVRAM_EMAIL_TEMPL_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP4P",
        VER(NVRAM_EF_EMAIL_TEMPLATE_LID)
    },
#endif/*__MMI_EMAIL_TEMPLATE__*/

#ifdef __MMI_LAUNCHER_APP_LIST__
    {
        NVRAM_EF_APPLIST_DATA_LID,
        NVRAM_EF_APPLIST_DATA_TOTAL,
        NVRAM_EF_APPLIST_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP4R",
        VER(NVRAM_EF_APPLIST_DATA_LID)
    },
#endif /* __MMI_LAUNCHER_APP_LIST__ */

#ifdef __MMI_ATV_SUPPORT__
    {
        NVRAM_EF_MOBILE_TV_PLAYER_SETTING_LID,
        NVRAM_EF_MOBILE_TV_PLAYER_SETTING_TOTAL,
        NVRAM_EF_MOBILE_TV_PLAYER_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP4S",
        VER(NVRAM_EF_MOBILE_TV_PLAYER_SETTING_LID)
    },
#endif /* __MMI_ATV_SUPPORT__ */

#ifdef __MMI_MOBILE_TV_CMMB_SUPPORT__
    {
        NVRAM_EF_DTV_PLAYER_SETTING_LID,
        NVRAM_EF_DTV_PLAYER_SETTING_TOTAL,
        NVRAM_EF_DTV_PLAYER_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP4T",
        VER(NVRAM_EF_DTV_PLAYER_SETTING_LID)
    },
#endif /* __MMI_MOBILE_TV_CMMB_SUPPORT__ */

#ifdef __MMI_SLIDESHOW__
    {
        NVRAM_EF_SLIDE_SHOW_SETTING_LID,
        NVRAM_EF_SLIDE_SHOW_SETTING_TOTAL,
        NVRAM_EF_SLIDE_SHOW_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP4U",
        VER(NVRAM_EF_SLIDE_SHOW_SETTING_LID)
    },
#endif/*__MMI_SLIDESHOW__*/

#ifdef __MMI_VIDEO_TELEPHONY__
    {
        NVRAM_EF_VT_SETTING_LID,
        NVRAM_EF_VT_SETTING_TOTAL,
        NVRAM_EF_VT_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP4V",
        VER(NVRAM_EF_VT_SETTING_LID)
    },
#endif /* __MMI_VIDEO_TELEPHONY__ */

#ifdef __BIP_PULL_SUPPORT__
    {
        NVRAM_EF_BT_BIP_SETTING_LID,
        NVRAM_EF_BT_BIP_SETTING_TOTAL,
        NVRAM_EF_BT_BIP_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_BT_BIP_SETTING_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP4X",
        VER(NVRAM_EF_BT_BIP_SETTING_LID)
    },
#endif /* __MMI_BIP_SUPPORT__ */


#ifdef __MMI_BARCODEREADER__
    #if defined(__MMI_OP11_BARCODEREADER__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
#endif

#ifdef __MMI_VIDEO_STREAM__
    {
        NVRAM_EF_VIDEO_NETWORK_PROFILE_LID,
        NVRAM_EF_VIDEO_NETWORK_PROFILE_TOTAL,
        NVRAM_EF_VIDEO_NETWORK_PROFILE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_VIDEO_NETWORK_PROFILE_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTI_DEFAULT,
        "MP55",
        VER(NVRAM_EF_VIDEO_NETWORK_PROFILE_LID)
    },
#endif/*__MMI_VIDEO_STREAM__*/

#if ((defined __MMI_OP01_DCD__) || (defined __MMI_OP01_DCD_V30__))
    {
        NVRAM_EF_DCD_SETTING_DATA_LID,
        NVRAM_EF_DCD_SETTING_DATA_TOTAL,
        NVRAM_EF_DCD_SETTING_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_DCD_SETTING_DATA_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP56",
        VER(NVRAM_EF_DCD_SETTING_DATA_LID)
    },
#endif

#ifdef __MMI_CAMCORDER__
    {
        NVRAM_EF_CAMCO_MAIN_SETTING_LID,
        NVRAM_EF_CAMCO_MAIN_SETTING_TOTAL,
        NVRAM_EF_CAMCO_MAIN_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP5D",
        VER(NVRAM_EF_CAMCO_MAIN_SETTING_LID)
    },

    {
        NVRAM_EF_CAMCO_MAIN_SETTING_SCENE_SEL_LID,
        NVRAM_EF_CAMCO_MAIN_SETTING_SCENE_SEL_TOTAL,
        NVRAM_EF_CAMCO_MAIN_SETTING_SCENE_SEL_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP5E",
        VER(NVRAM_EF_CAMCO_MAIN_SETTING_SCENE_SEL_LID)
    },
#endif /* __MMI_CAMCORDER__ */


#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
    {
        NVRAM_EF_AUDPLY_LAST_PLAYLIST_PATH_LID,
        NVRAM_EF_AUDPLY_LIST_PLAYLIST_PATH_TOTAL,
        NVRAM_EF_AUDPLY_LIST_PLAYLIST_PATH_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP5K",
        VER(NVRAM_EF_AUDPLY_LAST_PLAYLIST_PATH_LID)
    },
#endif  /* __MMI_AUDPLY_MULTIPLE_LIST__ */

    /* phonebook vip contact */
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__) || defined (__MMI_VUI_WIDGET_KEY_VIP_CONTACT__)
    {
        NVRAM_EF_PHB_VIP_CONTACT_LID,
        NVRAM_EF_PHB_VIP_CONTACT_TOTAL,
        NVRAM_EF_PHB_VIP_CONTACT_SIZE,                
    #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_PHB_VIP_CONTACT_DEFAULT),
    #else
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
    #endif

    #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
    #else
        NVRAM_CATEGORY_USER /* | NVRAM_CATEGORY_FACTORY */,
    #endif
        NVRAM_ATTR_AVERAGE,
        "MP5L",
        VER(NVRAM_EF_PHB_VIP_CONTACT_LID)
    },
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__) */
    /* phonebook vip contact */

#ifdef __MMI_MESSAGES_SMS_EMAIL__
    {
        NVRAM_EF_SMS_EMAIL_LID,
        NVRAM_SMS_EMAIL_RECORD_TOTAL,
        NVRAM_SMS_EMAIL_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP5M",
        VER(NVRAM_EF_SMS_EMAIL_LID)
    },
#endif/*__MMI_MESSAGES_SMS_EMAIL__*/

#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */

#if defined(__MMI_BT_DEF_SEND_DEVICE__)
    {
        NVRAM_EF_BT_DEFDEVICE_LID,
        NVRAM_EF_BT_DEFDEVICE_TOTAL,
        NVRAM_EF_BT_DEFDEVICE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP5S",
        VER(NVRAM_EF_BT_DEFDEVICE_LID)
    },
#endif/*__MMI_BT_DEF_SEND_DEVICE__*/

#if defined(__MMI_TODOLIST__) && defined(__MMI_BIRTHDAY_REMINDER__)
    {
        NVRAM_EF_TDL_BR_LID,
        NVRAM_EF_TDL_BR_TOTAL,
        NVRAM_EF_TDL_BR_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MP5T",
        VER(NVRAM_EF_TDL_BR_LID)
    },
#endif

#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_OP12_TOOLBAR__)
    {
        NVRAM_EF_SMS_VOICEMAIL_TIME_LID,
        NVRAM_EF_SMS_VOICEMAIL_TIME_TOTAL,
        NVRAM_EF_SMS_VOICEMAIL_TIME_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP5V",
        VER(NVRAM_EF_SMS_VOICEMAIL_TIME_LID)
    },
#endif /* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_OP12_TOOLBAR__) */

#if defined (__FLAVOR_VENDOR_SDK__) || defined(__MAUI_SDK_TEST__)
    {
        NVRAM_EF_VS_SETTING_LID,
        NVRAM_EF_VS_SETTING_TOTAL,
        NVRAM_EF_VS_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP5Z",
        VER(NVRAM_EF_VS_SETTING_LID)
    },
#endif

#ifdef __MMI_IPSEC__
    {
       NVRAM_EF_IPSEC_POLICY_LID,
       NVRAM_EF_IPSEC_POLICY_TOTAL,
       NVRAM_EF_IPSEC_POLICY_SIZE,
       NVRAM_NORMAL(NVRAM_EF_IPSEC_POLICY_DEFAULT),
       NVRAM_CATEGORY_USER,
       NVRAM_ATTR_AVERAGE,
       "MP60",
       VER(NVRAM_EF_IPSEC_POLICY_LID)
    },

    {
       NVRAM_EF_IPSEC_IKE_LID,
       NVRAM_EF_IPSEC_IKE_TOTAL,
       NVRAM_EF_IPSEC_IKE_SIZE,
       NVRAM_NORMAL(NVRAM_EF_IPSEC_IKE_DEFAULT),
       NVRAM_CATEGORY_USER,
       NVRAM_ATTR_AVERAGE,
       "MP61",
       VER(NVRAM_EF_IPSEC_IKE_LID)
    },
#endif /* __MMI_IPSEC__ */

#ifdef __OP11__ /*__MMI_PHB_ICE_CONTACT__ */
    {
        NVRAM_EF_PHB_ICE_CONTACT_LID,
        NVRAM_EF_PHB_ICE_CONTACT_TOTAL,
        NVRAM_EF_PHB_ICE_CONTACT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP63",
        VER(NVRAM_EF_PHB_ICE_CONTACT_LID)
    },
#endif /* __OP11__ */

#ifdef __MMI_MESSAGES_USERDEFINED_TEMPLATE__
    {
        NVRAM_EF_SMS_UD_TMEP_LID,
        NVRAM_SMS_UD_RECORD_TOTAL,
        NVRAM_SMS_UD_TEMPL_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP68",
        VER(NVRAM_EF_SMS_UD_TMEP_LID)
    },
#endif/*__MMI_MESSAGES_USERDEFINED_TEMPLATE__*/

#if defined(__SYNCML_SUPPORT__) 
    {
        NVRAM_EF_SYNCML_VIEW_LOG_LID,
        NVRAM_EF_SYNCML_VIEW_LOG_TOTAL,
        NVRAM_EF_SYNCML_VIEW_LOG_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
    #ifdef __MMI_SYNCML_RESTORE_FACTORY_DEFAULT__
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
    #else
        NVRAM_ATTR_AVERAGE,
    #endif /* __MMI_SYNCML_RESTORE_FACTORY_DEFAULT__ */
        "MP69",
        VER(NVRAM_EF_SYNCML_VIEW_LOG_LID)
    },
#endif 

#ifdef __MMI_BCR__
    {
       NVRAM_EF_BCR_SETTING_LID,
       NVRAM_EF_BCR_SETTING_TOTAL,
       NVRAM_EF_BCR_SETTING_SIZE,
       NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
       NVRAM_CATEGORY_USER,
       NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
       "MP6A",
       VER(NVRAM_EF_BCR_SETTING_LID)
    },
#endif /* __MMI_BCR__ */

#ifdef __MMI_AUTO_ANSWER_MACHINE__
    {
        NVRAM_EF_ANSWER_MACHINE_SETTING_LID,
        NVRAM_EF_ANSWER_MACHINE_SETTING_TOTAL,
        NVRAM_EF_ANSWER_MACHINE_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP6B",
        VER(NVRAM_EF_ANSWER_MACHINE_SETTING_LID)
    },
#endif/*__MMI_AUTO_ANSWER_MACHINE__*/

#ifdef __MMI_OP12_TOOLBAR__
    {
        NVRAM_EF_TOOLBAR_CNTX_LID,
        NVRAM_EF_TOOLBAR_CNTX_TOTAL,
        NVRAM_EF_TOOLBAR_CNTX_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP6C",
        VER(NVRAM_EF_TOOLBAR_CNTX_LID)
    },
#endif /* __MMI_OP12_TOOLBAR__ */

#ifdef __MMI_MEDIA_PLAYER__
    {
      NVRAM_EF_MEDPLY_SETTINGS_LID,
      NVRAM_EF_MEDPLY_SETTINGS_TOTAL,
      NVRAM_EF_MEDPLY_SETTINGS_SIZE,
      NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
      NVRAM_CATEGORY_USER,
      NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
      "MP6D",
      VER(NVRAM_EF_MEDPLY_SETTINGS_LID)
    },
    
    #if defined(__MMI_MEDIA_PLAYER_STREAM__) || defined(__MMI_KURO_SUPPORT__)
    {
      NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_LID,
      NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_TOTAL,
      NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_SIZE,
      NVRAM_NORMAL(NVRAM_EF_MEDPLY_NETWORK_PROFILE_DEFAULT),
      NVRAM_CATEGORY_USER,
      NVRAM_ATTR_MULTI_DEFAULT,
      "MP6E",
      VER(NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_LID)
    },
    #endif /* (__MMI_MEDIA_PLAYER_STREAM__) || defined(__MMI_KURO_SUPPORT__)*/

    #if defined(__MMI_MEDIA_PLAYER_STREAM__)
        #ifdef __MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__
            {
                  NVRAM_EF_MEDPLY_HISTORY_URL_LID,
                  NVRAM_EF_MEDPLY_HISTORY_URL_TOTAL,
                  NVRAM_EF_MEDPLY_HISTORY_URL_SIZE,
                  NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
                  NVRAM_CATEGORY_USER,
                  NVRAM_ATTR_AVERAGE,
                  "MP6F",
                  VER(NVRAM_EF_MEDPLY_HISTORY_URL_LID)
            },
        #endif  /* __MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__ */
    #endif
    {
       NVRAM_EF_MEDPLY_LAST_PLAYLIST_PATH_LID,
       NVRAM_EF_MEDPLY_LIST_PLAYLIST_PATH_TOTAL,
       NVRAM_EF_MEDPLY_LIST_PLAYLIST_PATH_SIZE,
       NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
       NVRAM_CATEGORY_USER,
       NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
       "MP6G",
       VER(NVRAM_EF_MEDPLY_LAST_PLAYLIST_PATH_LID)
    },
#endif

#ifdef __WAP_PUSH_SUPPORT__
    {
        NVRAM_EF_PUSH_GEN_SETTING_LID,
        NVRAM_EF_PUSH_GEN_SETTING_TOTAL,
        NVRAM_EF_PUSH_GEN_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_PUSH_GEN_SETTING_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP6I",
        VER(NVRAM_EF_PUSH_GEN_SETTING_LID)
    },

    #ifdef __MMI_WAP_PUSH_BLACK_LIST__
    {
        NVRAM_EF_PUSH_BLACK_LIST_LID,
        NVRAM_EF_PUSH_BLACK_LIST_TOTAL,
        NVRAM_EF_PUSH_BLACK_LIST_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_PUSH_BLACK_LIST_DEFAULT),
        NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT,
        "MP6J",
        VER(NVRAM_EF_PUSH_BLACK_LIST_LID)
    },
    #endif /* __MMI_WAP_PUSH_BLACK_LIST__ */

    #ifdef __MMI_WAP_PUSH_WHITE_LIST__
    {
        NVRAM_EF_PUSH_WHITE_LIST_LID,
        NVRAM_EF_PUSH_WHITE_LIST_TOTAL,
        NVRAM_EF_PUSH_WHITE_LIST_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_PUSH_WHITE_LIST_DEFAULT),
        NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT,
        "MP6K",
        VER(NVRAM_EF_PUSH_WHITE_LIST_LID)
    },
    #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
#endif /* __WAP_PUSH_SUPPORT__ */

#if !defined(__MMI_EM_INET_APP_SLIM__) && defined(__MMI_ENGINEER_MODE__)
    /* Internet Application */
    {
        NVRAM_EF_INET_CUSTPACK_LID,
        NVRAM_EF_INET_CUSTPACK_TOTAL,
        NVRAM_EF_INET_CUSTPACK_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_INET_CUSTPACK_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE,
        "MP6L",
        VER(NVRAM_EF_INET_CUSTPACK_LID)
    },
#endif

#ifdef __MMI_IPSEC__
    {
       NVRAM_EF_IPSEC_PROFILE_NAME_LID,
       NVRAM_EF_IPSEC_PROFILE_NAME_TOTAL,
       NVRAM_EF_IPSEC_PROFILE_NAME_SIZE,
       NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
       NVRAM_CATEGORY_USER,
       NVRAM_ATTR_AVERAGE,
       "MP6M",
       VER(NVRAM_EF_IPSEC_PROFILE_NAME_LID)
    },
#endif /* __MMI_IPSEC__ */

#if defined(__MMI_PICT_BRIDGE_SUPPORT__)
    {
        NVRAM_EF_PICTBRIDGE_LID,
        NVRAM_EF_PICTBRIDGE_TOTAL,
        NVRAM_EF_PICTBRIDGE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP6N",
        VER(NVRAM_EF_PICTBRIDGE_LID)
    },
#endif/* __MMI_PICT_BRIDGE_SUPPORT__*/

#ifdef __MMI_SYNCML_DEVICE_SYNC__
    {
        NVRAM_EF_SYNCML_DEV_SETTING_LID,
        NVRAM_EF_SYNCML_DEV_SETTING_TOTAL,
        NVRAM_EF_SYNCML_DEV_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP6O",
        VER(NVRAM_EF_SYNCML_DEV_SETTING_LID)
    },

    {
        NVRAM_EF_SYNCML_DEV_ACCOUNT_LID,
        NVRAM_EF_SYNCML_DEV_ACCOUNT_TOTAL,
        NVRAM_EF_SYNCML_DEV_ACCOUNT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP6P",
        VER(NVRAM_EF_SYNCML_DEV_ACCOUNT_LID)
    },

    {
        NVRAM_EF_SYNCML_DEV_SYNC_LOG_LID,
        NVRAM_EF_SYNCML_DEV_SYNC_LOG_TOTAL,
        NVRAM_EF_SYNCML_DEV_SYNC_LOG_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP6Q",
        VER(NVRAM_EF_SYNCML_DEV_SYNC_LOG_LID)
    },
#endif/* __MMI_SYNCML_DEVICE_SYNC__ */

#ifdef __MMI_BROWSER_2__
    {
        NVRAM_EF_WAP_BOOKMARK_LIST_LID,
        NVRAM_EF_WAP_BOOKMARK_LIST_TOTAL_RECORDS,
        NVRAM_EF_WAP_BOOKMARK_LIST_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_WAP_BOOKMARK_LIST_DEFAULT),
        NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_MULTI_DEFAULT,
        "MP6R",
        VER(NVRAM_EF_WAP_BOOKMARK_LIST_LID)
    },
#endif /* __MMI_BROWSER_2__ */

#ifdef __MMI_CM_WHITE_LIST__
    {
        NVRAM_EF_WHITE_LIST_LID,
        NVRAM_EF_WHITE_LIST_TOTAL,
        NVRAM_EF_WHITE_LIST_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP6S",
        VER(NVRAM_EF_WHITE_LIST_LID)
    },
#endif/*__MMI_CM_WHITE_LIST__*/

#ifdef __MMI_FM_RADIO_SCHEDULER__
    {
        NVRAM_EF_FMRDO_SCHEDULER_LID,
        NVRAM_EF_FMRDO_SCHEDULER_TOTAL,
        NVRAM_EF_FMRDO_SCHEDULER_SIZE,
        NVRAM_NORMAL(NVRAM_FMRDO_SCHEDULER_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP6U",
        VER(NVRAM_EF_FMRDO_SCHEDULER_LID)
    },
#endif /* __MMI_FM_RADIO_SCHEDULER__ */

#ifdef __MMI_BCR__
    {
       NVRAM_EF_BCR_FIELD_SET_LID,
       NVRAM_EF_BCR_FIELD_SET_TOTAL,
       NVRAM_EF_BCR_FIELD_SET_SIZE,
       NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
       NVRAM_CATEGORY_USER,
       NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
       "MP6V",
       VER(NVRAM_EF_BCR_FIELD_SET_LID)
    },
#endif /* __MMI_BCR__ */

#ifdef __BIP_PULL_SUPPORT__
    {
        NVRAM_EF_BT_BIP_SET_FOLDER_LID,
        NVRAM_EF_BT_BIP_SETTING_TOTAL,
        NVRAM_EF_BT_BIP_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_BT_BIP_SETTING_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP6W",
        VER(NVRAM_EF_BT_BIP_SET_FOLDER_LID)
    },
#endif /* __MMI_BIP_SUPPORT__ */

#ifdef __MMI_MEDIA_PLAYER_STREAM__
    {
        NVRAM_EF_MEDPLY_PREDEFINED_URL_LID,
        NVRAM_EF_MEDPLY_VIDEO_PREDEFINED_URL_TOTAL,
        NVRAM_EF_MEDPLY_VIDEO_PREDEFINED_URL_SIZE,
        NVRAM_NORMAL(NVRAM_EF_MEDPLY_VIDEO_PREDEFINED_URL_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP6Y",
        VER(NVRAM_EF_MEDPLY_PREDEFINED_URL_LID)
    },
#endif

#ifdef __MMI_CAMCORDER__
    {
        NVRAM_EF_CAMCO_APP_INFO_LID,
        NVRAM_EF_CAMCO_APP_INFO_TOTAL,
        NVRAM_EF_CAMCO_APP_INFO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP7P",
        VER(NVRAM_EF_CAMCO_APP_INFO_LID)
    },

    #ifdef DUAL_CAMERA_SUPPORT
    {
        NVRAM_EF_CAMCO_SUB_SETTING_LID,
        NVRAM_EF_CAMCO_SUB_SETTING_TOTAL,
        NVRAM_EF_CAMCO_SUB_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP7Q",
        VER(NVRAM_EF_CAMCO_SUB_SETTING_LID)
    },

    {
        NVRAM_EF_CAMCO_SUB_SETTING_SCENE_SEL_LID,
        NVRAM_EF_CAMCO_SUB_SETTING_SCENE_SEL_TOTAL,
        NVRAM_EF_CAMCO_SUB_SETTING_SCENE_SEL_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP7R",
        VER(NVRAM_EF_CAMCO_SUB_SETTING_SCENE_SEL_LID)
    },
    #endif /* DUAL_CAMERA_SUPPORT */
#endif /* __MMI_CAMCORDER__ */

#ifdef __EMAIL__
    /* Email Data Account */
    {
        NVRAM_EF_EMAIL_DATA_ACCOUNT_LID,
        NVRAM_EF_EMAIL_DATA_ACCOUNT_TOTAL,
        NVRAM_EF_EMAIL_DATA_ACCOUNT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ,
        "MP7S",
        VER(NVRAM_EF_EMAIL_DATA_ACCOUNT_LID)
    },
#endif/* defined(ISP_SUPPORT) && defined(DRV_ISP_6235_SERIES) && defined(BACKUP_SENSOR_SUPPORT) */

#ifdef __SYNCML_SUPPORT__
    {
        NVRAM_EF_SYNCML_ACCOUNT_LID,
        NVRAM_EF_SYNCML_ACCOUNT_TOTAL,
        NVRAM_EF_SYNCML_ACCOUNT_SIZE,
    #ifdef CUSTOM_SYNCML_ACCOUNT_DEFAULT
        NVRAM_NORMAL(NVRAM_EF_SYNCML_ACCOUNT_DEFAULT),       
    #else /* CUSTOM_SYNCML_ACCOUNT_DEFAULT */
        #ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
            NVRAM_NORMAL(NVRAM_EF_SYNCML_ACCOUNT_DEFAULT_FOR_PC_SYNC),
        #else /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */
            NVRAM_NORMAL(NVRAM_EF_SYNCML_ACCOUNT_DEFAULT_FOR_NONE_PC_SYNC),
        #endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */
    #endif /* CUSTOM_SYNCML_ACCOUNT_DEFAULT */

    NVRAM_CATEGORY_USER,
    
    #ifdef CUSTOM_SYNCML_ACCOUNT_DEFAULT
        #ifndef __MMI_SYNCML_RESTORE_FACTORY_DEFAULT__
            NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_FACTORY_RESET,
        #else
            NVRAM_ATTR_MULTI_DEFAULT,
        #endif /* __MMI_SYNCML_RESTORE_FACTORY_DEFAULT__ */

    #else /* CUSTOM_SYNCML_ACCOUNT_DEFAULT */
            NVRAM_ATTR_MULTI_DEFAULT,
    #endif /* CUSTOM_SYNCML_ACCOUNT_DEFAULT */
        "MP7V",
        VER(NVRAM_EF_SYNCML_ACCOUNT_LID)
    },
#endif /* __SYNCML_SUPPORT__ */


     #ifdef __MMI_ECOMPASS__
    {
       NVRAM_EF_ECOMPASS_LID,
       NVRAM_EF_ECOMPASS_TOTAL,
       NVRAM_EF_ECOMPASS_SIZE,
       NVRAM_NORMAL(NVRAM_EF_ECOMPASS_DEFAULT),
       NVRAM_CATEGORY_USER,
       NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_MULTI_DEFAULT,
       "MP83",
       VER(NVRAM_EF_ECOMPASS_LID)
    },
   #endif /* __MMI_ECOMPASS__ */

#ifdef __MMI_NOTE_APP__
    {
        NVRAM_EF_NOTE_APP_LID,
        NVRAM_EF_NOTE_LIST_TOTAL,
        NVRAM_EF_NOTE_NODE_STRUCT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP84",
        VER(NVRAM_EF_NOTE_APP_LID)
    },
#endif /* __MMI_NOTE_APP__ */

#ifdef __MMI_SEARCH_WEB__
    {
        NVRAM_EF_SEARCH_WEB_HISTORY_LID,
        NVRAM_EF_SEARCH_WEB_HISTORY_TOTAL,
        NVRAM_EF_SEARCH_WEB_HISTORY_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP85",
        VER(NVRAM_EF_SEARCH_WEB_HISTORY_LID)
    },
#endif /* __MMI_SEARCH_WEB__ */

#ifdef __MMI_SEARCH_WEB_BAIDU__
    {
        NVRAM_EF_SEARCH_WEB_BAIDU_UID_LID,
        NVRAM_EF_SEARCH_WEB_BAIDU_UID_TOTAL,
        NVRAM_EF_SEARCH_WEB_BAIDU_UID_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER, 
        NVRAM_ATTR_AVERAGE,
        "MP86",
        VER(NVRAM_EF_SEARCH_WEB_BAIDU_UID_LID)
    },
#endif /* __MMI_SEARCH_WEB__ */

#ifdef __MMI_VUI_HOMESCREEN__
    {
        NVRAM_EF_VENUS_HS_WIDGET_MGR_LID,
        NVRAM_EF_VENUS_HS_WIDGET_MGR_TOTAL,
        NVRAM_EF_VENUS_HS_WIDGET_MGR_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP87",
        VER(NVRAM_EF_VENUS_HS_WIDGET_MGR_LID)
    },
#endif /* __MMI_VUI_HOMESCREEN__ */

#ifdef __MMI_VUI_HOMESCREEN_MEMO__
    {
        NVRAM_EF_VENUS_HS_WIDGET_MEMO_CNTX_LID,
        NVRAM_EF_VENUS_HS_WIDGET_MEMO_CNTX_TOTAL,
        NVRAM_EF_VENUS_HS_WIDGET_MEMO_CNTX_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP88",
        VER(NVRAM_EF_VENUS_HS_WIDGET_MEMO_CNTX_LID)
    },
#endif /* __MMI_VUI_HOMESCREEN_MEMO__ */

#ifdef __MMI_VUI_MAINMENU__
    {
        NVRAM_EF_VENUS_MM_LID,
        NVRAM_EF_VENUS_MM_TOTAL,
        NVRAM_EF_VENUS_MM_SIZE,
        NVRAM_NORMAL(NVRAM_EF_VENUS_MM_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP89",
        VER(NVRAM_EF_VENUS_MM_LID)
    },
#endif /* __MMI_VUI_MAINMENU__*/

#ifdef __MMI_VUI_HOMESCREEN_PHOTO__
    {
        NVRAM_EF_VENUS_PHOTO_FILEPATH_LID,
        NVRAM_EF_VENUS_PHOTO_FILEPATH_TOTAL,
        NVRAM_EF_VENUS_PHOTO_FILEPATH_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP8A",
        VER(NVRAM_EF_VENUS_PHOTO_FILEPATH_LID)
    },
#endif /* __MMI_VUI_HOMESCREEN_PHOTO__*/

#ifdef __MMI_ZAKAT_CALCULATOR__
    {
        NVRAM_EF_ZAKAT_CALCULATOR_LID,
        NVRAM_EF_ZAKAT_CALCULATOR_TOTAL,
        NVRAM_EF_ZAKAT_CALCULATOR_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP8B",
        VER(NVRAM_EF_ZAKAT_CALCULATOR_LID)
    },
#endif /* __MMI_ZAKAT_CALCULATOR__*/

#ifdef __TCPIP__
#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    {
		NVRAM_EF_CNMGR_CONNECT_DATA_LID,
		NVRAM_EF_CNMGR_CONNECT_DATA_LAST_TOTAL,
		NVRAM_EF_CNMGR_CONNECT_DATA_LAST_TOTAL_SIZE,
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"MP90",
		VER(NVRAM_EF_CNMGR_CONNECT_DATA_LID)
	},
#endif /* !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) */
#endif /* __TCPIP__ */

#ifdef __MMI_EM_MISC_DCD__
    {
        NVRAM_EF_DCD_EM_PARAM_DATA_LID,
        NVRAM_EF_DCD_EM_PARAM_DATA_TOTAL,
        NVRAM_EF_DCD_EM_PARAM_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_DCD_EM_PARAM_DATA_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP91",
        VER(NVRAM_EF_DCD_EM_PARAM_DATA_LID)
    },
#endif /* __MMI_EM_MISC_DCD__ */

#ifdef __MMI_AZAAN_ALARM__
    {
        NVRAM_EF_AZAAN_ALARM_LID,
        NVRAM_AZAAN_ALARM_TOTAL,
        NVRAM_AZAAN_ALARM_SIZE,
        NVRAM_NORMAL(NVRAM_EF_AZAAN_ALARM_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_FACTORY_RESET,
        "MP94",
        VER(NVRAM_EF_AZAAN_ALARM_LID)
    },
#endif /* __MMI_AZAAN_ALARM__ */


#ifdef __MMI_IMAGE_VIEWER_EX__
    {
        NVRAM_EF_IVEX_SETTINGS_LID,
        NVRAM_EF_IVEX_SETTINGS_TOTAL,
        NVRAM_EF_IVEX_SETTINGS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP9D",
        VER(NVRAM_EF_IVEX_SETTINGS_LID)
    },
#endif/* __MMI_IMAGE_VIEWER_EX__ */

//#ifdef __MMI_SRV_TODOLIST__
#ifdef __MMI_CALENDAR_EVENT__
    {
        NVRAM_EF_TDL_EVENT_LID,
        NVRAM_EF_TDL_EVENT_TOTAL,
        NVRAM_EF_TDL_EVENT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MP9F",
        VER(NVRAM_EF_TDL_EVENT_LID)
    },
#endif

#ifdef __MMI_TODOLIST__
    {
        NVRAM_EF_TDL_TASK_LID,
        NVRAM_EF_TDL_TASK_TOTAL,
        NVRAM_EF_TDL_TASK_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MPA0",
        VER(NVRAM_EF_TDL_TASK_LID)
    },
#endif    
//#endif /* __MMI_SRV_TODOLIST__ */

#ifdef __DM_SCOMO_SUPPORT__
    {
        NVRAM_EF_DM_APP_SCOMO_REPORT_INFO_LID,
        NVRAM_EF_DM_APP_SCOMO_REPORT_INFO_TOTAL,
        NVRAM_EF_DM_APP_SCOMO_REPORT_INFO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPA1",
        VER(NVRAM_EF_DM_APP_SCOMO_REPORT_INFO_LID)
    },
#endif /* __DM_SCOMO_SUPPORT__ */

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    {
        NVRAM_EF_SRV_SMS_PDU_LID,
        NVRAM_EF_SRV_SMS_PDU_TOTAL,
        NVRAM_EF_SRV_SMS_PDU_SIZE,
        NVRAM_NORMAL(NVRAM_EF_SRV_SMS_PDU_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MPA3",
        VER(NVRAM_EF_SRV_SMS_PDU_LID)
    },

    #ifdef __SRV_SMS_RECENT_EVENT__
    {
        NVRAM_EF_SRV_SMS_RECENT_EVENT_BITMAP_LID,
        NVRAM_EF_SRV_SMS_RECENT_EVENT_BITMAP_TOTAL,
        NVRAM_EF_SRV_SMS_RECENT_EVENT_BITMAP_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPA4",
        VER(NVRAM_EF_SRV_SMS_RECENT_EVENT_BITMAP_LID)
    },
    #endif /* __SRV_SMS_RECENT_EVENT__ */
#endif

#ifdef __OCSP_SUPPORT__
    {
        NVRAM_EF_CERTMAN_OCSP_URL_LID,
        NVRAM_EF_CERTMAN_OCSP_URL_TOTAL,
        NVRAM_EF_CERTMAN_OCSP_URL_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPA5",
        VER(NVRAM_EF_CERTMAN_OCSP_URL_LID)
    },
#endif /*__OCSP_SUPPORT__*/


#if (defined(MRE_VERSION) && defined(__MRE_CORE_SANDBOX__))
    {
        NVRAM_EF_MRE_APP_BAN_LIST_EXT_LID,
        NVRAM_EF_MRE_APP_BAN_LIST_EXT_TOTAL,
        NVRAM_EF_MRE_APP_BAN_LIST_EXT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPA9",
        VER(NVRAM_EF_MRE_APP_BAN_LIST_EXT_LID)
    },

    {
        NVRAM_EF_MRE_SYM_ENTRY_LIST_EXT_LID,
        NVRAM_EF_MRE_SYM_ENTRY_LIST_EXT_TOTAL,
        NVRAM_EF_MRE_SYM_ENTRY_LIST_EXT_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_VER_SYM_ENTRY_EXT_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MPAB",
        VER(NVRAM_EF_MRE_SYM_ENTRY_LIST_EXT_LID)
    },
#endif

#if (defined(MRE_VERSION) && defined(__MRE_CORE_SAFETY__))
    {
        NVRAM_EF_MRE_PKEY_LIST_EXT_LID,
        NVRAM_EF_MRE_PKEY_LIST_EXT_TOTAL,
        NVRAM_EF_MRE_PKEY_LIST_EXT_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_VER_PKEY_EXT_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MPAA",
        VER(NVRAM_EF_MRE_PKEY_LIST_EXT_LID)
    },

    {
        NVRAM_EF_MRE_SYM_CONF_LIST_EXT_LID,
        NVRAM_EF_MRE_SYM_CONF_LIST_EXT_TOTAL,
        NVRAM_EF_MRE_SYM_CONF_LIST_EXT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPAC", 
        VER(NVRAM_EF_MRE_SYM_CONF_LIST_EXT_LID)
    },
#endif
    {
        NVRAM_EF_MRE_FIRST_RUNNING_LID,
        NVRAM_EF_MRE_FIRST_RUNNING_TOTAL,
        NVRAM_EF_MRE_FIRST_RUNNING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPB4",
        VER(NVRAM_EF_MRE_FIRST_RUNNING_LID)
    },
#ifdef __MRE_AM__
    {
        NVRAM_EF_AM_HS_SHORTCUT_LIST_LID,
        NVRAM_EF_AM_HS_SHORTCUT_LIST_TOTAL,
        NVRAM_EF_AM_HS_SHORTCUT_LIST_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPB5",
        VER(NVRAM_EF_AM_HS_SHORTCUT_LIST_LID)
    },
#endif

#ifdef __MMI_VUI_HOMESCREEN_CLOCK__
    {
        NVRAM_EF_VENUS_HS_WIDGET_CLOCK_CNTX_LID,
        NVRAM_EF_VENUS_HS_WIDGET_CLOCK_CNTX_TOTAL,
        NVRAM_EF_VENUS_HS_WIDGET_CLOCK_CNTX_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPB6",
        VER(NVRAM_EF_VENUS_HS_WIDGET_CLOCK_CNTX_LID)
    },
#endif /* __MMI_VUI_HOMESCREEN_CLOCK__ */

#ifdef __MMI_VUI_3D_CUBE_APP__
    {
        NVRAM_EF_CUBE_VIP_CONTS_LID,
        NVRAM_EF_CUBE_VIP_CONTS_TOTAL,
        NVRAM_EF_CUBE_VIP_CONTS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPB7",
        VER(NVRAM_EF_CUBE_VIP_CONTS_LID)
    },
#endif

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    {
		NVRAM_EF_OP11_HS32_HIST_LID,
        NVRAM_EF_OP11_HS32_HIST_TOTAL,
        NVRAM_EF_OP11_HS32_HIST_SIZE,
        NVRAM_NORMAL(NVRAM_EF_OP11_HS32_HIST_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPB8",
        VER(NVRAM_EF_OP11_HS32_HIST_LID)
    },
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */

#ifdef __MMI_VUI_HOMESCREEN__
    {
        NVRAM_EF_VENUS_HS_SHORTCUT_MGR_LID,
        NVRAM_EF_VENUS_HS_SHORTCUT_MGR_TOTAL,
        NVRAM_EF_VENUS_HS_SHORTCUT_MGR_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPB9",
        VER(NVRAM_EF_VENUS_HS_SHORTCUT_MGR_LID)
    },
#endif /* __MMI_VUI_HOMESCREEN__ */

#if (!defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) && defined(__SRV_SMS_SIM_CUST_DATA__))
    {
        NVRAM_EF_SRV_SMS_SIM_CUST_DATA_LID,
        NVRAM_EF_SRV_SMS_SIM_CUST_DATA_TOTAL,
        NVRAM_EF_SRV_SMS_SIM_CUST_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPBA",
        VER(NVRAM_EF_SRV_SMS_SIM_CUST_DATA_LID)
    },
#endif /* (!defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) && defined(__SRV_SMS_SIM_CUST_DATA__)) */

#ifdef __MMI_GADGET_SUPPORT__
    {
        NVRAM_EF_WGTMGR_DATA_LID,
        NVRAM_EF_WGTMGR_DATA_TOTAL,
        NVRAM_EF_WGTMGR_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPBB",
        VER(NVRAM_EF_WGTMGR_DATA_LID)
    },
#endif

#ifdef __MMI_SLIDESHOW__
    {
        NVRAM_EF_SLIDE_SHOW_PATH_LID,
        NVRAM_EF_SLIDE_SHOW_PATH_TOTAL,
        NVRAM_EF_SLIDE_SHOW_PATH_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPC1",
        VER(NVRAM_EF_SLIDE_SHOW_PATH_LID)
    },
#endif/*__MMI_SLIDESHOW__*/

#ifdef __MMI_SLIDESHOW__
    {
        NVRAM_EF_SLIDE_SHOW_AUDIO_LID,
        NVRAM_EF_SLIDE_SHOW_AUDIO_TOTAL,
        NVRAM_EF_SLIDE_SHOW_AUDIO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPC2",
        VER(NVRAM_EF_SLIDE_SHOW_AUDIO_LID)
    },
#endif/*__MMI_SLIDESHOW__*/

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
#ifdef __SRV_CBS_SUPPORT__

    {
        NVRAM_EF_SRV_CBS_PAGE_LID,
        NVRAM_EF_SRV_CBS_PAGE_TOTAL,
        NVRAM_EF_SRV_CBS_PAGE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_SRV_CBS_PAGE_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MPC3",
        VER(NVRAM_EF_SRV_CBS_PAGE_LID)
    },

    {
        NVRAM_EF_SRV_CBS_MSG_NODE_LID,
        NVRAM_EF_SRV_CBS_MSG_NODE_TOTAL,
        NVRAM_EF_SRV_CBS_MSG_NODE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_SRV_CBS_MSG_NODE_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MPC4",
        VER(NVRAM_EF_SRV_CBS_MSG_NODE_LID)
    },

    {
        NVRAM_EF_SRV_CBS_CHNL_NAME_LID,
        NVRAM_EF_SRV_CBS_CHNL_NAME_TOTAL,
        NVRAM_EF_SRV_CBS_CHNL_NAME_SIZE,
        NVRAM_NORMAL(NVRAM_EF_SRV_CBS_CHNL_NAME_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MPC5",
        VER(NVRAM_EF_SRV_CBS_CHNL_NAME_LID)
    },
#endif
#if defined(__DA_SMART_SELECTION_SUPPORT__)
    {
        NVRAM_EF_DTCNT_SIM_ID_LID,
        NVRAM_MAX_DTCNT_SIM_ID_TOTAL,
        NVRAM_MAX_DTCNT_SIM_ID_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPC6",
        VER(NVRAM_EF_DTCNT_SIM_ID_LID)
    },
#endif
#endif /* !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) */

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    {
        NVRAM_EF_GROUPLIST_SIM2_LID,
        NVRAM_MAX_GROUP_NAME_TOTAL,
        NVRAM_MAX_GROUP_NAME_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPC8",
        VER(NVRAM_EF_GROUPLIST_SIM2_LID)
    },
#endif

#ifdef OPERA_BROWSER
    {
        NVRAM_EF_OPERA_ADP_PROF_SETTING_LID,
        NVRAM_EF_OPERA_ADP_PROF_SETTING_TOTAL,
        NVRAM_EF_OPERA_ADP_PROF_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPC9",
        VER(NVRAM_EF_OPERA_ADP_PROF_SETTING_LID)
    },
#endif /* OPERA_BROWSER */

#ifdef __BT_HFG_PROFILE__
    {
        NVRAM_EF_BTHF_CONFIG_LID,
        NVRAM_EF_BTHF_CONFIG_TOTAL,
        NVRAM_EF_BTHF_CONFIG_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPCA",
        VER(NVRAM_EF_BTHF_CONFIG_LID)
    },
#endif/* __BT_HFG_PROFILE__ */

#ifdef __MMI_FILE_MANAGER__
#ifdef __MMI_SCREEN_SAVER__
    {
        NVRAM_EF_SCREENSAVER_FILENAME_LID,
        NVRAM_EF_SCREENSAVER_FILENAME_TOTAL,
        NVRAM_EF_SCREENSAVER_FILENAME_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPCB",
        VER(NVRAM_EF_SCREENSAVER_FILENAME_LID)
    },
#endif /* __MMI_SCREEN_SAVER__ */
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    {
        NVRAM_EF_POWER_ON_OFF_DISP_FILENAME_LID,
        NVRAM_EF_POWER_ON_OFF_DISP_FILENAME_TOTAL,
        NVRAM_EF_POWER_ON_OFF_DISP_FILENAME_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPCC",
        VER(NVRAM_EF_POWER_ON_OFF_DISP_FILENAME_LID)
    },
#endif
#endif /* __MMI_FILE_MANAGER__ */

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
#if !defined(__MMI_BASIC_UI_STYLE__) && !defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
    {
        NVRAM_EF_MMI_PROF_SETTING_LID,
        NVRAM_MMI_PROF_RECORD_TOTAL,
        NVRAM_MMI_PROF_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPCD",
        VER(NVRAM_EF_MMI_PROF_SETTING_LID)
    },
#endif
#endif /* !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) */

#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
    {
        NVRAM_EF_SRV_SMS_STATUS_REPORT_LID,
        NVRAM_EF_SRV_SMS_STATUS_REPORT_TOTAL,
        NVRAM_EF_SRV_SMS_STATUS_REPORT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MPCF",
        VER(NVRAM_EF_SRV_SMS_STATUS_REPORT_LID)
    },
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */

#ifdef __MMI_VUI_SHELL_APP__
    {
        NVRAM_EF_VENUS_SHELL_PAGE_ORDER_LID,
        NVRAM_EF_VENUS_SHELL_PAGE_ORDER_TOTAL,
        NVRAM_EF_VENUS_SHELL_PAGE_ORDER_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPCG",
        VER(NVRAM_EF_VENUS_SHELL_PAGE_ORDER_LID)
    },
#endif /* __MMI_VUI_SHELL_APP__ */

#if defined(__CLOG_STORAGE_BY_MMI__)
  #ifdef __MMI_TELEPHONY_SUPPORT__
    {
        NVRAM_EF_CLOG_LOG_LID,
        NVRAM_EF_CLOG_LOG_TOTAL,
        NVRAM_EF_CLOG_LOG_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MPD1",
        VER(NVRAM_EF_CLOG_LOG_LID)
    },

   {
        NVRAM_EF_CLOG_CALL_TIME_LID,
        NVRAM_EF_CLOG_CALL_TIME_TOTAL,
        NVRAM_EF_CLOG_CALL_TIME_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MPD2",
        VER(NVRAM_EF_CLOG_CALL_TIME_LID)
    },
  #endif /* __MMI_TELEPHONY_SUPPORT__ */
#endif /* __CLOG_STORAGE_BY_MMI__ */

#ifdef __MMI_VUI_SHELL_SHORTCUTS__
    {
        NVRAM_EF_SHELL_SHORTCUTS_LID,
        NVRAM_EF_SHELL_SHORTCUTS_TOTAL,
        NVRAM_EF_SHELL_SHORTCUTS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPD3",
        VER(NVRAM_EF_SHELL_SHORTCUTS_LID)
    },
#endif /* __MMI_VUI_SHELL_SHORTCUTS__ */

#ifdef __MMI_VUI_SHELL_FAV_CONTACT__
    {
        NVRAM_EF_SHELL_FC_LID,
        NVRAM_EF_SHELL_FC_TOTAL,
        NVRAM_EF_SHELL_FC_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPD4",
        VER(NVRAM_EF_SHELL_FC_LID)
    },
#endif

#ifdef __MMI_VUI_3D_MAINMENU__
    {   // hongxi add
        NVRAM_EF_VENUS_3D_MM_LID,
        NVRAM_EF_VENUS_3D_MM_TOTAL,
        NVRAM_EF_VENUS_3D_MM_SIZE,
        NVRAM_NORMAL(NVRAM_EF_VENUS_3D_MM_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPDB",
        VER(NVRAM_EF_VENUS_3D_MM_LID)
    },
#endif

#ifdef __MMI_WLAN_FEATURES__
    {
        NVRAM_EF_CMCC_WIFI_SETTING_LID,
        NVRAM_MAX_CMCC_WIFI_SETTING_TOTAL,
        NVRAM_MAX_CMCC_WIFI_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPDO",
        VER(NVRAM_EF_CMCC_WIFI_SETTING_LID),
    },
#endif

#ifdef __BT_AUTO_DETECT_SUPPORT__
    {
        NVRAM_EF_BT_AUTO_DETECT_SETTING_LID,
        NVRAM_EF_BT_AUTO_DETECT_SETTING_TOTAL,
        NVRAM_EF_BT_AUTO_DETECT_SETTING_SIZE,
        NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_BT_AUTO_DETECT_SETTING_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPC6",
        VER(NVRAM_EF_BT_AUTO_DETECT_SETTING_LID)
    },
#endif

    {
        NVRAM_EF_SRV_REMINDER_Q_LID,
        NVRAM_EF_SRV_REMINDER_Q_TOTAL,
        NVRAM_EF_SRV_REMINDER_Q_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_SW_VERNO_RESET,
        "MPDC",
        VER(NVRAM_EF_SRV_REMINDER_Q_LID)
    },


#ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
    {
        NVRAM_EF_PHB_FIELD_LABEL_LID,
        NVRAM_EF_PHB_FIELD_LABEL_TOTAL,
        NVRAM_EF_PHB_FIELD_LABEL_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ,
        "MPDF",
        VER(NVRAM_EF_PHB_FIELD_LABEL_LID)
    },
#endif


#ifdef __SRV_SMS_MULTI_ADDR__
    {
        NVRAM_EF_SRV_SMS_ADDR_LID,
        NVRAM_EF_SRV_SMS_ADDR_TOTAL,
        NVRAM_EF_SRV_SMS_ADDR_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MPDH",
        VER(NVRAM_EF_SRV_SMS_ADDR_LID)
    },
#endif /* __SRV_SMS_MULTI_ADDR__ */

#ifdef __DM_LAWMO_SUPPORT__
    {
        NVRAM_EF_DM_APP_LAWMO_INFO_LID,
        NVRAM_EF_DM_APP_LAWMO_INFO_TOTAL,
        NVRAM_EF_DM_APP_LAWMO_INFO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPDI",
        VER(NVRAM_EF_DM_APP_LAWMO_INFO_LID)
    },
#endif /* __DM_LAWMO_SUPPORT__ */

#if (MMI_MAX_SIM_NUM>=3)
    #if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    {
        NVRAM_EF_GROUPLIST_SIM3_LID,
        NVRAM_MAX_GROUP_NAME_TOTAL,
        NVRAM_MAX_GROUP_NAME_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPDJ",
        VER(NVRAM_EF_GROUPLIST_SIM3_LID)
    },
    #endif
#endif

#if (MMI_MAX_SIM_NUM>=4)
    #if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    {
        NVRAM_EF_GROUPLIST_SIM4_LID,
        NVRAM_MAX_GROUP_NAME_TOTAL,
        NVRAM_MAX_GROUP_NAME_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPDK",
        VER(NVRAM_EF_GROUPLIST_SIM4_LID)
    },
    #endif
#endif

#ifdef __MMI_139_PUSH_MAIL__
    {
        NVRAM_EF_PUSHMAIL_INFO_LID,
        NVRAM_EF_PUSHMAIL_INFO_TOTAL,
        NVRAM_EF_PUSHMAIL_INFO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPDL",
        VER(NVRAM_EF_PUSHMAIL_INFO_LID)
    },
#endif

#ifdef __MMI_TETHERING__
    {
        NVRAM_EF_SRV_TETHERING_DTCNT_LID,
        NVRAM_EF_SRV_TETHERING_DTCNT_TOTAL,
        NVRAM_EF_SRV_TETHERING_DTCNT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPDM",
        VER(NVRAM_EF_SRV_TETHERING_DTCNT_LID)
    },
#ifdef __MMI_TETHERING_WIFI__
    {
        NVRAM_EF_SRV_TETHERING_WIFI_HS_SETTINGS_LID,
        NVRAM_EF_SRV_TETHERING_WIFI_HS_SETTINGS_TOTAL,
        NVRAM_EF_SRV_TETHERING_WIFI_HS_SETTINGS_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_SRV_TETHERING_WIFI_HS_SETTINGS_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPDN",
        VER(NVRAM_EF_SRV_TETHERING_WIFI_HS_SETTINGS_LID)
    },
#endif /* __MMI_TETHERING_WIFI__ */
#endif /* __MMI_TETHERING__ */

#ifdef __MMI_OP01_WIFI__
    {
        NVRAM_EF_CMCC_WIFI_BLACK_LIST_LID,
        NVRAM_MAX_CMCC_WIFI_BLACK_LIST_TOTAL,
        NVRAM_MAX_CMCC_WIFI_BLACK_LIST_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPDP",
        VER(NVRAM_EF_CMCC_WIFI_BLACK_LIST_LID)
    },
#endif

#ifdef __MMI_CM_BLACK_LIST_EXT__
    #ifdef __MMI_VIDEO_TELEPHONY__
    {
        NVRAM_EF_BLACK_LIST_VIDEO_LID,
        NVRAM_EF_BLACK_LIST_TOTAL,
        NVRAM_EF_BLACK_LIST_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPDQ",
        VER(NVRAM_EF_BLACK_LIST_LID)
    },
    #endif /* __MMI_VIDEO_TELEPHONY__ */
#endif/* __MMI_CM_BLACK_LIST_EXT__ */

#ifdef __MMI_CM_WHITE_LIST_EXT__
    #ifdef __MMI_VIDEO_TELEPHONY__
    {
        NVRAM_EF_WHITE_LIST_VIDEO_LID,
        NVRAM_EF_WHITE_LIST_TOTAL,
        NVRAM_EF_WHITE_LIST_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPDR",
        VER(NVRAM_EF_WHITE_LIST_LID)
    },
    #endif /* __MMI_VIDEO_TELEPHONY__ */
#endif/* __MMI_CM_WHITE_LIST_EXT__ */

#ifdef __MMI_PUSH_TURN_ON_OFF_SWITCH__
    {
        NVRAM_EF_PUSH_SWITCH_SETTING_LID,
        NVRAM_EF_PUSH_SWITCH_SETTING_TOTAL,
        NVRAM_EF_PUSH_SWITCH_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_PUSH_SWITCH_SETTING_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPDS",
        VER(NVRAM_EF_PUSH_SWITCH_SETTING_LID)
    },
#endif /* __MMI_PUSH_TURN_ON_OFF_SWITCH__ */

#ifdef __MMI_OP01_WIFI__
    {
        NVRAM_EF_WLAN_PROXY_EXCLUSIVE_IP_ADDR_LID,
        NVRAM_EF_WLAN_PROXY_EXCLUSIVE_IP_ADDR_TOTAL,
        NVRAM_EF_WLAN_PROXY_EXCLUSIVE_IP_ADDR_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPE1",
        VER(NVRAM_EF_WLAN_PROXY_EXCLUSIVE_IP_ADDR_LID)
    },
#endif

#if defined(__MMI_VIDEO_TELEPHONY__) && defined(__OP01__)
    {
        NVRAM_EF_VT_SETTING_REMOTE_PIC_LID,
        NVRAM_EF_VT_SETTING_TOTAL,
        NVRAM_EF_VT_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPE2",
        VER(NVRAM_EF_VT_SETTING_REMOTE_PIC_LID)
    },
#endif /* defined(__MMI_VIDEO_TELEPHONY__) && defined(__OP01__) */

#if defined(__MMI_VUI_SHELL_OP01_HOMESCREEN__)||defined(__MMI_VUI_LAUNCHER_KEY__)
    {
        NVRAM_EF_OP01_HS_SETTING_LID,
        NVRAM_EF_OP01_HS_SETTING_TOTAL,
        NVRAM_EF_OP01_HS_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPE3",
        VER(NVRAM_EF_OP01_HS_SETTING_LID)
    },
#endif /* defined(__MMI_VUI_SHELL_OP01_HOMESCREEN__)||defined(__MMI_VUI_LAUNCHER_KEY__) */

#ifdef SYNCML_DM_SUPPORT
{
    NVRAM_EF_DM_SRV_ACC_LID,
    NVRAM_EF_DM_SRV_ACC_TOTAL,
    NVRAM_EF_DM_SRV_ACC_SIZE,
    NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
    NVRAM_CATEGORY_USER,
    NVRAM_ATTR_AVERAGE,
    "MPE4",
    VER(NVRAM_EF_DM_SRV_ACC_LID)
},
#endif /* SYNCML_DM_SUPPORT */

#ifdef __OP01_FWPBW__
    {
        NVRAM_EF_DIALER_DIRECT_DIAL_LID,
        NVRAM_EF_PHB_SPEEDDIAL_TOTAL,
        NVRAM_EF_PHB_SPEEDDIAL_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPE5",
        VER(NVRAM_EF_DIALER_DIRECT_DIAL_LID)
    },
#endif
#ifdef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
    {
        NVRAM_EF_MMI_PROF_NEW_NAME_LID,
        NVRAM_MMI_PROF_NEW_RECORD_TOTAL,
        NVRAM_MMI_PROF_NEW_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPE6",
        VER(NVRAM_EF_MMI_PROF_NEW_NAME_LID),
    },

    {
        NVRAM_EF_MMI_PROF_NEW_FLAG_LID,
        NVRAM_MMI_PROF_FLAG_RECORD_TOTAL,
        NVRAM_MMI_PROF_FLAG_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPE7",
        VER(NVRAM_EF_MMI_PROF_NEW_FLAG_LID),
    },
#endif
#if (defined(MRE_VERSION) && defined(__MRE_CORE_SAFETY__))
    {
    	NVRAM_EF_MRE_PKEY_LIST_MTK_LID,
    	NVRAM_EF_MRE_PKEY_LIST_MTK_TOTAL,
    	NVRAM_EF_MRE_PKEY_LIST_MTK_SIZE,
    	NVRAM_NORMAL_NOT_GEN(NVRAM_MER_PKEY_MTK_DEFAULT),
      NVRAM_CATEGORY_USER,
      NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MPE8",
        VER(NVRAM_EF_MRE_PKEY_LIST_MTK_LID)
    },
#endif

#ifdef __MMI_EM_GPRS_CNMGR_SCRI_SUPPORT__
    {
        NVRAM_EF_CNMGR_SCRI_CHECK_TIME_LID,
		NVRAM_EF_CNMGR_SCRI_CHECK_TIME_TOTAL,
		NVRAM_EF_CNMGR_SCRI_CHECK_TIME_SIZE,
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"MPE9",
		VER(NVRAM_EF_CNMGR_SCRI_CHECK_TIME_LID)
    },
#endif /* __MMI_EM_GPRS_CNMGR_SCRI_SUPPORT__ */

#ifdef __MMI_VUI_LAUNCHER__
    {
        NVRAM_EF_VAPP_DRAWER_ORDER_DATA_LID,
        NVRAM_EF_VAPP_DRAWER_ORDER_DATA_TOTAL,
        NVRAM_EF_VAPP_DRAWER_ORDER_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_VAPP_DRAWER_ORDER_DATA_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPEA",
        VER(NVRAM_EF_VAPP_DRAWER_ORDER_DATA_LID)
    },
    {
        NVRAM_EF_VENUS_LAUNCHER_DESKTOP_LID,
        NVRAM_EF_VENUS_LAUNCHER_DESKTOP_TOTAL,
        NVRAM_EF_VENUS_LAUNCHER_DESKTOP_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPEB",
        VER(NVRAM_EF_VENUS_LAUNCHER_DESKTOP_LID)
    },
#endif
#ifdef __MMI_DM_SELF_REGISTER_SUPPORT__
    {
        NVRAM_EF_DMSR_SIM_IMSI_LID,
        NVRAM_EF_DM_SR_IMSI_TOTAL,
        NVRAM_EF_DM_SR_IMSI_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
    	NVRAM_ATTR_AVERAGE,
        "MPEC",
        VER(NVRAM_EF_DMSR_SIM_IMSI_LID)
    },
#endif/*__MMI_DM_SELF_REGISTER_SUPPORT__*/
#ifdef __MMI_VUI_LAUNCHER_KEY__
    {
        NVRAM_EF_VAPP_KMM_ORDER_DATA_LID,
        NVRAM_EF_VAPP_KMM_ORDER_DATA_TOTAL,
        NVRAM_EF_VAPP_KMM_ORDER_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_VAPP_KMM_ORDER_DATA_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPEE",
        VER(NVRAM_EF_VAPP_KMM_ORDER_DATA_LID)
    },
#endif /* __MMI_VUI_LAUNCHER__ */

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    {
        NVRAM_EF_QUICKTEST_LID,
        NVRAM_EF_QUICKTEST_TOTAL,
        NVRAM_EF_QUICKTEST_SIZE ,
        NVRAM_NORMAL(NVRAM_EF_QUICKTEST_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPG0",
        VER(NVRAM_EF_QUICKTEST_LID)
    },
#endif  /* !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) */

#ifdef __NFC_SUPPORT__
	{
		NVRAM_EF_NFC_STATUS_LID,
		NVRAM_EF_NFC_STATUS_TOTAL,
		NVRAM_EF_NFC_STATUS_SIZE,
		NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
		"MPED",
		VER(NVRAM_EF_NFC_STATUS_LID)
		
	},
#endif /* __NFC_SUPPORT__ */

#ifdef __SOCIAL_NETWORK_SUPPORT__
    {
        NVRAM_EF_SRV_SNS_ACCOUNT_LID,
        NVRAM_EF_SRV_SNS_ACCOUNT_TOTAL,
        NVRAM_EF_SRV_SNS_ACCOUNT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPEO",
        VER(NVRAM_EF_SRV_SNS_ACCOUNT_LID)
    },
#endif /* __SOCIAL_NETWORK_SUPPORT__ */

#ifdef __MMI_SSO__
    {
        NVRAM_EF_SRV_SSO_ACCOUNT_LID,
        NVRAM_EF_SRV_SSO_ACCOUNT_TOTAL,
        NVRAM_EF_SRV_SSO_ACCOUNT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPSO",
        VER(NVRAM_EF_SRV_SSO_ACCOUNT_LID)
    },
#endif /* __MMI_SSO__ */

#ifdef __MMI_VUI_LAUNCHER_KEY__
	{
		NVRAM_EF_PHNSET_WIDGET_MGR_SYS_LIST_LID,
		NVRAM_EF_PHNSET_WIDGET_MGR_SYS_LIST_TOTAL,
		NVRAM_EF_PHNSET_WIDGET_MGR_SYS_LIST_SIZE,
		NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
		"MPEP",
		VER(NVRAM_EF_PHNSET_WIDGET_MGR_SYS_LIST_LID)	
	},
#endif

#ifdef __MMI_VUI_LAUNCHER_KEY__
		{
		NVRAM_EF_PHNSET_SHCUT_APP_LIST_LID,
		NVRAM_EF_PHNSET_SHCUT_APP_LIST_TOTAL,
		NVRAM_EF_PHNSET_SHCUT_APP_LIST_SIZE,
		NVRAM_NORMAL(NVRAM_EF_PHNSET_SHCUT_APP_LIST_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
		"MPEF",
		VER(NVRAM_EF_PHNSET_SHCUT_APP_LIST_LID)	
	},
#endif

#ifdef MOTION_SENSOR_SUPPORT
	{		
		NVRAM_EF_MOTION_SENSOR_SWITCH_LID,
		NVRAM_EF_MOTION_SENSOR_SWITCH_TOTAL,
		NVRAM_EF_MOTION_SENSOR_SWITCH_SIZE,
		NVRAM_NORMAL(NVRAM_EF_MOTION_SENSOR_SWITCH_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE| NVRAM_ATTR_FACTORY_RESET,
		"MPEG",
		VER(NVRAM_EF_MOTION_SENSOR_SWITCH_LID)
	},
#endif

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
	{
		NVRAM_EF_NETSET_SIM_NAME_LID,
		NVRAM_EF_NETSET_SIM_NAME_TOTAL,
		NVRAM_EF_NETSET_SIM_NAME_SIZE,
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
		"MPEH",
		VER(NVRAM_EF_NETSET_SIM_NAME_LID)
	},  
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */

#ifdef __MMI_VUI_SCREEN_LOCK_KEY__
    {
		NVRAM_EF_SCREEN_LOCK_KEY_IMG_SETTING_LID,
		NVRAM_EF_SCREEN_LOCK_KEY_IMG_SETTING_TOTAL,
		NVRAM_EF_SCREEN_LOCK_KEY_IMG_SETTING_SIZE,
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"MPEI",
		VER(NVRAM_EF_SCREEN_LOCK_KEY_IMG_SETTING_LID)	
	},
#endif
#ifdef __MMI_NSS_SUPPORT__
    {
        NVRAM_EF_SRV_NSS_PROFILE_LID,
        NVRAM_EF_SRV_NSS_PROFILE_TOTAL,
        NVRAM_EF_SRV_NSS_PROFILE_SIZE,
        NVRAM_CUSTPACK(NVRAM_EF_SRV_NSS_PROFILE_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT,
        "MPNS",
        VER(NVRAM_EF_SRV_NSS_PROFILE_LID)
    },
#endif    

#ifdef __MMI_MRE_MSPACE__
    {
            NVRAM_EF_SRV_MSPACE_LID,
            NVRAM_EF_SRV_MSPACE_TOTAL,
            NVRAM_EF_SRV_MSPACE_SIZE,
            NVRAM_NORMAL_NOT_GEN(NVRAM_MSPACE_URL),
            NVRAM_CATEGORY_USER,
            NVRAM_ATTR_AVERAGE,
            "MPNT",
            VER(NVRAM_EF_SRV_MSPACE_LID)   
    },
#endif

/* ADD-S 20120417 FOR CMMBCAS2GPP*/
#ifdef CMMB_CAS_2GPP_V10
    {
        NVRAM_EF_CMMB_CAS_2GPP_LID,
        NVRAM_EF_CMMB_CAS_2GPP_TOTAL,
        NVRAM_EF_CMMB_CAS_2GPP_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_CONFIDENTIAL,
        "MPNU",
        VER(NVRAM_EF_CMMB_CAS_2GPP_LID)
    },
#endif /* __MMI_MOBILE_TV_PLAYER__ */
/* ADD-E 20120417 FOR CMMBCAS2GPP*/
#ifdef __CLOUD_SUPPORT__
#ifdef __SMS_CLOUD_SUPPORT__
    {
        NVRAM_EF_SMS_USED_NUM_LID,
        NVRAM_MAX_SMS_USED_NUM_TOTAL,
        NVRAM_MAX_SMS_USED_NUM_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP71",
        VER(NVRAM_EF_SMS_USED_NUM_LID)
    },
    {
        NVRAM_EF_SMS_UID_COUNT_LID,
        NVRAM_MAX_SMS_UID_COUNT_TOTAL,
        NVRAM_MAX_SMS_UID_COUNT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP73",
        VER(NVRAM_EF_SMS_UID_COUNT_LID)
    }, 
    {
        NVRAM_EF_CLOUD_SMS_ITEM_LID,
        NVRAM_MAX_CLOUD_SMS_ITEM_TOTAL,
        NVRAM_MAX_CLOUD_SMS_ITEM_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP74",
        VER(NVRAM_EF_CLOUD_SMS_ITEM_LID)
    },    
#endif
#ifdef __VCARD_CLOUD_SUPPORT__
    {
        NVRAM_EF_VCRD_USED_NUM_LID,
        NVRAM_MAX_VCRD_USED_NUM_TOTAL,
        NVRAM_MAX_VCRD_USED_NUM_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP75",
        VER(NVRAM_EF_VCRD_USED_NUM_LID)
    },
    {
        NVRAM_EF_VCRD_UID_COUNT_LID,
        NVRAM_MAX_VCRD_UID_COUNT_TOTAL,
        NVRAM_MAX_VCRD_UID_COUNT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP77",
        VER(NVRAM_EF_VCRD_UID_COUNT_LID)
    },    
    {
        NVRAM_EF_CLOUD_VCRD_ITEM_LID,
        NVRAM_MAX_CLOUD_VCRD_ITEM_TOTAL,
        NVRAM_MAX_CLOUD_VCRD_ITEM_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP78",
        VER(NVRAM_EF_CLOUD_VCRD_ITEM_LID)
    },
    {
        NVRAM_EF_VCRD_UID_LIST_URL_LID,
        NVRAM_MAX_VCRD_UID_LIST_URL_TOTAL,
        NVRAM_MAX_VCRD_UID_LIST_URL_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP79",
        VER(NVRAM_EF_VCRD_UID_LIST_URL_LID)
    },    
    {
        NVRAM_EF_VCRD_IS_CHANGE_LID,
        NVRAM_MAX_VCRD_IS_CHANGE_TOTAL,
        NVRAM_MAX_VCRD_IS_CHANGE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP7A",
        VER(NVRAM_EF_VCRD_IS_CHANGE_LID)            
    },
#endif
#endif

#if (defined(MRE_VERSION) && defined(__MRE_CORE_SAFETY__))
    {
    	NVRAM_EF_MRE_PKEY_EX_LID,
    	NVRAM_EF_MRE_PKEY_EX_TOTAL,
    	NVRAM_EF_MRE_PKEY_EX_SIZE,
    	NVRAM_NORMAL_NOT_GEN(NVRAM_MER_PKEY_1024BIT_DEFAULT),
        NVRAM_CATEGORY_USER,
    	NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MP7B",
        VER(NVRAM_EF_MRE_PKEY_EX_LID)
    },
#endif

#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
    {
    	NVRAM_EF_SYS_LANGUAGE_SSC_LID,
    	NVRAM_EF_SYS_LANGUAGE_SSC_TOTAL,
    	NVRAM_EF_SYS_LANGUAGE_SSC_SIZE,
    	NVRAM_NORMAL_NOT_GEN(NVRAM_EF_SYS_LANGUAGE_SSC_DEFAULT),
        NVRAM_CATEGORY_USER,
    	NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP7C",
        VER(NVRAM_EF_SYS_LANGUAGE_SSC_LID)
    },
#endif

#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__
    {
		NVRAM_EF_DLT_APPICON_LID,
		NVRAM_EF_DLT_APPICON_TOTAL,
		NVRAM_EF_DLT_APPICON_SIZE,
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"MP7D",
		VER(NVRAM_EF_DLT_APPICON_LID)
	},
#endif	

#ifdef __MMI_APPLIST_BARREL_SUPPORT__
    {
        NVRAM_EF_APPLIST_BARREL_EFFECT_LID,
        NVRAM_EF_APPLIST_BARREL_EFFECT_TOTAL,
        NVRAM_EF_APPLIST_BARREL_EFFECT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP7E",
        VER(NVRAM_EF_APPLIST_BARREL_EFFECT_LID)
    },
#endif

#if defined(__MMI_BT_DIALER_SUPPORT__) && !defined(__MMI_BT_BTBOX_NOLCD__)
    {
        NVRAM_BYTE_BT_DIALER_CONNSTR,
        NVRAM_BYTE_BT_DIALER_CONNSTR_TOTAL,
        NVRAM_BYTE_BT_DIALER_CONNSTR_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_SW_VERNO_RESET,
        "MP80",
        VER(NVRAM_BYTE_BT_DIALER_CONNSTR)
    },
    {
        NVRAM_BYTE_BT_DIALER_AUTO_CONN,
        NVRAM_BYTE_BT_DIALER_AUTO_CONN_TOTAL,
        NVRAM_BYTE_BT_DIALER_AUTO_CONN_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP81",
        VER(NVRAM_BYTE_BT_DIALER_AUTO_CONN)
    },
#endif
    
#ifdef __MMI_AUDPLY_WALK_PLAY__
    {
        NVRAM_EF_AUDPLY_WALK_LID,
        NVRAM_EF_AUDPLY_WALK_TOTAL,
        NVRAM_EF_AUDPLY_WALK_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP82",
        VER(NVRAM_EF_AUDPLY_WALK_LID)
    },
#endif  /* __MMI_AUDPLY_WALK_PLAY__ */

#if defined(__IOT__) 
    {
        NVRAM_EF_WIFIAP_MODE_CONFIG_LID,
        NVRAM_EF_WIFIAP_MODE_CONFIG_TOTAL,
        NVRAM_EF_WIFIAP_MODE_CONFIG_SIZE,
        NVRAM_NORMAL(COMMON_NVRAM_EF_WIFIAP_MODE_CONFIG_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP83",
        VER(NVRAM_EF_WIFIAP_MODE_CONFIG_LID)
    },
#endif /* defined(__IOT__) */

#if defined(__WIFI_SUPPORT__) && defined(__IOT__)
    {
        NVRAM_EF_WLAN_SCAN_SETTING_LID,
        NVRAM_MAX_WLAN_SCAN_SETTING_TOTAL,
        NVRAM_MAX_WLAN_SCAN_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_WLAN_SCAN_SETTING_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP84",
        VER(NVRAM_EF_WLAN_SCAN_SETTING_LID)
    },
#endif
#if defined(__CERTMAN_SUPPORT__)  
    {
        NVRAM_EF_CERTMAN_CERT_LID,
        NVRAM_EF_FM_CERTMAN_TOTAL,
        NVRAM_EF_FM_CERTMAN_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT6C",
        VER(NVRAM_EF_CERTMAN_CERT_LID)
    },
#endif/*__CERTMAN_SUPPORT__*/
	//huking
#if defined(__MMI_FRM_INPUT_EVT__)	
	//led	
	{
        NVRAM_EF_LED_INFO_LID,
        NVRAM_EF_LED_INFO_TOTAL,
        NVRAM_EF_LED_INFO_SIZE,
        NVRAM_NORMAL(nv_input_event_notify_led_info_tbl),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET| NVRAM_ATTR_MULTI_DEFAULT,
        "MP86",
        VER(NVRAM_EF_LED_INFO_LID)
    },
    //vib
	{
        NVRAM_EF_VIB_INFO_LID,
        NVRAM_EF_VIB_INFO_TOTAL,
        NVRAM_EF_VIB_INFO_SIZE,
        NVRAM_NORMAL(nv_input_event_notify_vib_info_tbl),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET| NVRAM_ATTR_MULTI_DEFAULT,
        "MP87",
        VER(NVRAM_EF_VIB_INFO_LID)
    },
    //aud
	{
        NVRAM_EF_AUD_INFO_LID,
        NVRAM_EF_AUD_INFO_TOTAL,
        NVRAM_EF_AUD_INFO_SIZE,
        NVRAM_NORMAL(nv_input_event_notify_aud_info_tbl),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET| NVRAM_ATTR_MULTI_DEFAULT,
        "MP88",
        VER(NVRAM_EF_AUD_INFO_LID)
    },    
	//notify
	{
        NVRAM_EF_NOTIFY_INFO_LID,
        NVRAM_EF_NOTIFY_INFO_TOTAL,
        NVRAM_EF_NOTIFY_INFO_SIZE,
        NVRAM_NORMAL(nv_input_event_notify_tbl),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET | NVRAM_ATTR_MULTI_DEFAULT,
        "MP89",
        VER(NVRAM_EF_NOTIFY_INFO_LID)
    },
    //input event
	{
        NVRAM_EF_INPUT_EVENT_INFO_LID,
        NVRAM_EF_INPUT_EVENT_INFO_TOTAL,
        NVRAM_EF_INPUT_EVENT_INFO_SIZE,
        NVRAM_NORMAL(nv_input_event_evt_info_tbl),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET| NVRAM_ATTR_MULTI_DEFAULT,
        "MP8A",
        VER(NVRAM_EF_INPUT_EVENT_INFO_LID)
    },
	//local		
	{
        NVRAM_EF_LOCAL_APP_INFO_LID,
        NVRAM_EF_LOCAL_APP_INFO_TOTAL,
        NVRAM_EF_LOCAL_APP_INFO_SIZE,
        NVRAM_NORMAL(nv_input_event_local_app_info_tbl),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET| NVRAM_ATTR_MULTI_DEFAULT,
        "MP8B",
        VER(NVRAM_EF_LOCAL_APP_INFO_LID)
    },
#endif/*#if defined(__MMI_FRM_INPUT_EVT__)*/    

#ifndef __MMI_TELEPHONY_SUPPORT__
    {
        NVRAM_EF_PHONE_LOCK_LID,
        NVRAM_EF_PHONE_LOCK_TOTAL,
        NVRAM_EF_PHONE_LOCK_SIZE,
        NVRAM_NORMAL(&NVRAM_EF_PHONE_LOCK_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP8C",
        VER(NVRAM_EF_PHONE_LOCK_LID)
    },
#endif  /* __MMI_TELEPHONY_SUPPORT__ */
// local
#ifdef __MMI_BT_APK_SMART_INSTALL_SUPPORT__
	{
		NVRAM_EF_BT_APK_SMART_INS_RECORD_LID,
		NVRAM_EF_BT_APK_SMART_INS_RECORD_TOTAL,
		NVRAM_EF_BT_APK_SMART_INS_RECORD_SIZE,
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
		"MP8E",
		VER(NVRAM_EF_BT_APK_SMART_INS_RECORD_LID)
	},
#endif

#if (defined(__UPDATE_BINARY_FILE__) && !defined(__NVRAM_SUPPORT_CUSTPACK__))

{
	NVRAM_EF_CACHE_INIT_LID,
	NVRAM_MMI_CACHE_INIT_TOTAL,
	NVRAM_MMI_CACHE_INIT_SIZE,
	NVRAM_NORMAL(NVRAM_EF_MMI_CACHE_INIT_DEFAULT_R),
	NVRAM_CATEGORY_USER,
	NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
	"MP8F",
	VER(NVRAM_EF_CACHE_INIT_LID)
},
#endif

#if defined(__FUDIFFNET_ENABLE__)
    {
        NVRAM_EF_DIFF_FOTA_INFO_LID,
        NVRAM_EF_DIFF_FOTA_INFO_TOTAL,
        NVRAM_EF_DIFF_FOTA_INFO_SIZE,
        NVRAM_NORMAL(&NVRAM_EF_DIFF_FOTA_INFO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP8G",
        VER(NVRAM_EF_DIFF_FOTA_INFO_LID)
    },

    {
        NVRAM_EF_DIFF_FOTA_INFO_SWMC_LID,
        NVRAM_EF_DIFF_FOTA_INFO_SWMC_TOTAL,
        NVRAM_EF_DIFF_FOTA_INFO_SWMC_SIZE,
        NVRAM_NORMAL(&NVRAM_EF_DIFF_FOTA_INFO_SWMC_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP8H",
        VER(NVRAM_EF_DIFF_FOTA_INFO_SWMC_LID)
    },

    {
        NVRAM_EF_DIFF_FOTA_DM_TYPE_LID,
        NVRAM_EF_DIFF_FOTA_DM_TYPE_TOTAL,
        NVRAM_EF_DIFF_FOTA_DM_TYPE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP8I",
        VER(NVRAM_EF_DIFF_FOTA_DM_TYPE_LID)
    },
#endif

#if defined(__FUNET_ENABLE__)
    {
        NVRAM_EF_UBIN_FOTA_INFO_LID,
        NVRAM_EF_UBIN_FOTA_INFO_TOTAL,
        NVRAM_EF_UBIN_FOTA_INFO_SIZE,
        NVRAM_NORMAL(&NVRAM_EF_UBIN_FOTA_INFO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP8J",
        VER(NVRAM_EF_UBIN_FOTA_INFO_LID)
    },
#endif


#if defined(__MMI_USB_FIRMWARE_UPDATE__)
    {
        NVRAM_EF_USB_FOTA_INFO_LID,
        NVRAM_EF_USB_FOTA_INFO_TOTAL,
        NVRAM_EF_USB_FOTA_INFO_SIZE,
        NVRAM_NORMAL(&NVRAM_EF_USB_FOTA_INFO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP8K",
        VER(NVRAM_EF_USB_FOTA_INFO_LID)
    },
#endif

#if defined(__ROCK_FOTA_SUPPORT__)
    {
        NVRAM_EF_ROCK_FOTA_INFO_LID,
        NVRAM_EF_ROCK_FOTA_INFO_TOTAL,
        NVRAM_EF_ROCK_FOTA_INFO_SIZE,
        NVRAM_NORMAL(&NVRAM_EF_ROCK_FOTA_INFO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP8L",
        VER(NVRAM_EF_ROCK_FOTA_INFO_LID)
    },
#endif

#ifdef __MMI_ONE_KEY_SOS_SUPPORT__
    {
        NVRAM_EF_OKSOS_INFO_LID,
        NVRAM_EF_OKSOS_INFO_TOTAL,
        NVRAM_EF_OKSOS_INFO_SIZE,
        NVRAM_NORMAL(&NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP8M",
        VER(NVRAM_EF_OKSOS_INFO_LID)
    },
#endif /* __MMI_ONE_KEY_SOS_SUPPORT__ */

#ifdef __MMI_BLOOD_PRESSURE_SUPPORT__
	{
		NVRAM_EF_BP_INFO_LID,
		NVRAM_EF_BP_INFO_TOTAL,
		NVRAM_EF_BP_INFO_SIZE,
		NVRAM_NORMAL(&NVRAM_EF_ZERO_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
		"MP8N",
		VER(NVRAM_EF_BP_INFO_LID)
	},

#endif /*__MMI_BLOOD_PRESSURE_SUPPORT__*/
};

nvram_ltable_tbl_struct nvram_ltable_comm_app = 
    {logical_data_item_table_common_app,     sizeof(logical_data_item_table_common_app)/sizeof(nvram_ltable_entry_struct)};

#endif /*!NVRAM_NOT_PRESENT*/


