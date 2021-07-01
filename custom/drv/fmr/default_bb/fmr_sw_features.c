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
 *
 * Filename:
 * ---------
 *  fmr_config_customize.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file contains fm radio customized configuration.
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#if defined(FM_RADIO_ENABLE)
#include "kal_general_types.h"
     
/*SW sort*/
kal_bool Scan_Sort_on = KAL_TRUE;
#if (defined(MT6276FM))
kal_bool FMR_SWEliminate_on = KAL_TRUE;
const kal_uint8 FMR_EmptyChannelNum = 0;
const kal_uint8 FMR_EmptyRSSI[] = 
{
	0
};//dBuVemf
const kal_uint16 g_EmptyChannel[] =
{
	0
};
#elif (defined(MT6626))
kal_bool FMR_SWEliminate_on = KAL_TRUE;
const kal_uint8 FMR_EmptyChannelNum = 0;
const kal_uint16 g_EmptyChannel[] =
{
	0
};
const kal_uint8 FMR_EmptyRSSI[] = 
{
	0
};//dBuVemf
#elif (defined(MT6250FM))
const kal_uint8 FMR_EmptyChannelNum = 0;
const kal_uint16 g_EmptyChannel[] =
{
	0
};
#else
kal_bool FMR_SWEliminate_on = KAL_FALSE;
const kal_uint8 FMR_EmptyChannelNum = 0;
const kal_uint16 g_EmptyChannel[] =
{
	0
};
const kal_uint8 FMR_EmptyRSSI[] = 
{
	0
};//dBuVemf
#endif
     
#endif
