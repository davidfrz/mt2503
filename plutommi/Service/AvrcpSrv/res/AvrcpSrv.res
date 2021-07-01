/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   AvrcpSrv.res
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  AVRCP Service resource file
 *
 * Author:
 * -------
 *   Kinse Lin (mtk01393)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision: $
 * $Modtime: $
 * $Log: $
 *
 * 03 18 2014 yun.yi
 * [MAUI_03488091] [BTDv3] check-in to 11C
 * .
 *
 * 02 19 2014 yun.yi
 * [MAUI_03466018] [BT Dialer v3.0] IT check-in to 11CW1352_BTDV3_DEV
 * .
 *
 * 09 11 2013 yun.yi
 * [MAUI_03459269] [BT Dialer 2.x] check-in to BT BOX
 * .
 *
 * 06 03 2013 amitpratap.singh
 * [MAUI_03421566] [BT dialer 2.0] check-in
 * .
 *
 * 04 20 2012 kinse.lin
 * [MAUI_03172471] [Res] move timer id to res file
 * .
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

//ktimer

#include "mmi_features.h"

#ifdef __MMI_AVRCP_SUPPORT__

<?xml version="1.0" encoding="UTF-8"?>

<APP id="SRV_AVRCP">


<!----------------------------------------------------------------------------------------
******** Timer section  
------------------------------------------------------------------------------------------>

    <TIMER id="BT_AVRCP_AUTO_RELEASE_TIMER"/>
    <TIMER id="BT_AVRCP_TEST_TIMER"/>
<!-----------------Service Events begin for BT Music--------------------------------------------------->
  <EVENT id="EVT_ID_BT_MUSIC_AVRCP_CONNECTED_EVENT_ID" type="SENDER"/>
<EVENT id="EVT_ID_BT_MUSIC_AVRCP_DISCONNECTED_EVENT_ID" type="SENDER"/>

</APP>

#endif /* __MMI_AVRCP_SUPPORT__ */

