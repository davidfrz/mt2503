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
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   sndcp.sap
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   SNDCP related message identity definition
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/


    /*------------------------SND_MSG_CODE_BEGIN ---------------*/
    /*Not verify yet.*/
    MSG_ID_SN_DATA_REQ = MSG_ID_SND_CODE_BEGIN,
    MSG_ID_SN_UNITDATA_REQ,
    MSG_ID_SN_XID_REQ,

    /* Robert comment start  */
    /* Don't modify following message sequence. */
    /* SNDCP checks sapi in snd_main() function. */
    MSG_ID_LLSND_UNITDATA_IND,
    MSG_ID_LLSND_XID_IND,
    MSG_ID_LLSND_XID_CNF,
    MSG_ID_LLSND_DATA_IND,
    MSG_ID_LLSND_DATA_CNF,
    MSG_ID_LLSND_ESTABLISH_IND,
    MSG_ID_LLSND_ESTABLISH_CNF,
    MSG_ID_LLSND_RELEASE_IND,
    MSG_ID_LLSND_RELEASE_CNF,
    MSG_ID_LLSND_STATUS_IND,
    /* Robert comment end  */

    MSG_ID_LLSND_RESET_IND,
    MSG_ID_LLSND_T100_RESET_IND, /* Eric Hsieh: for PSHO */
    MSG_ID_LLSND_FLUSH_CNF,

    MSG_ID_SNSM_ACTIVATE_IND,
    MSG_ID_SNSM_DEACTIVATE_IND,
    MSG_ID_SNSM_MODIFY_IND,
    MSG_ID_SNSM_SEQUENCE_IND,
    MSG_ID_SNSM_CELL_INFO_UPDATE_IND, /* erica 20051229: for egprs */

    MSG_ID_SND_FLC_SUSPEND_RESUME,
    MSG_ID_SND_ACTIVATE_IND,
    MSG_ID_SND_ACTIVATE_RSP,
    MSG_ID_SND_DEACTIVATE_IND,
    MSG_ID_SND_DEACTIVATE_RSP,
    MSG_ID_SND_MODIFY_EST,
    MSG_ID_SND_MODIFY_EST_RSP,
    MSG_ID_SND_MODIFY_REL,
    MSG_ID_SND_MODIFY_REL_RSP,
    MSG_ID_SND_UNITDATA_IND,
    MSG_ID_SND_UNITDATA_TX_REQ,
    MSG_ID_SND_DATA_IND,
    MSG_ID_SND_DATA_TX_REQ,
    MSG_ID_SND_RESET_IND,
    MSG_ID_SND_DATA_ERROR,
    MSG_ID_SND_COMPRESS_RSP,
    MSG_ID_SND_DECOMPRESS_RSP,
    MSG_ID_SND_FLC_DATA_RESUME_PPP,

    /* Jeff Wu 2007-03-03: RATDM -> SNDCP */
    MSG_ID_RATDM_SNDCP_ACTIVATE_REQ,
    MSG_ID_RATDM_SNDCP_DATA_REQ,
    MSG_ID_RATDM_SNDCP_MODIFY_REQ,
    MSG_ID_RATDM_SNDCP_DEACTIVATE_REQ,
    MSG_ID_RATDM_SNDCP_SEQUENCE_REQ,

    MSG_ID_SOC_SND_DL_SRPDU_RESUME,
    MSG_ID_SND_NPDU_INQUEUE_IND, //erica 20060320
    MSG_ID_SND_CODE_END = MSG_ID_SND_NPDU_INQUEUE_IND,
/*------------------------SND_MSG_CODE_END -----------------*/

