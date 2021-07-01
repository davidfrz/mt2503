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
     
/*RSSI threshold*/
#if (defined(MT6251FM))
kal_uint16 FMR_RSSI_THRESHOLD_LANT = 0x301;
kal_uint16 FMR_RSSI_THRESHOLD_SANT = 0x2E0;
kal_uint16 FMR_CQI_TH = 0xE9;
#elif (defined(MT6276FM))
kal_uint16 FMR_RSSI_THRESHOLD_LANT = 0x301;
kal_uint16 FMR_RSSI_THRESHOLD_SANT = 0x2E0;
kal_uint16 FMR_CQI_TH = 0xE9;
#elif (defined(MT6256FM)||defined(MT6255FM))
kal_uint16 FMR_RSSI_THRESHOLD_LANT = 0x301;
kal_uint16 FMR_RSSI_THRESHOLD_SANT = 0x2E0;
kal_uint16 FMR_CQI_TH = 0xE9;
#elif (defined(MT6626))
kal_uint16 FMR_RSSI_THRESHOLD_LANT = 0xFF01;
kal_uint16 FMR_RSSI_THRESHOLD_SANT = 0xFEE0;
kal_bool FMR_DEEMPHASIS_50us = KAL_FALSE;
kal_uint16 FMR_CQI_TH = 0xFFE9;
#elif (defined(MT6250FM))
typedef enum
{
	FMR_Audio_FalseAlarm = 0,
	FMR_Audio_Acceptable,
	FMR_Audio_Better,
	FMR_Audio_MBetter,
	FMR_Audio_Best,	
	FMR_Audio_End
}FMR_Audio_Level_e;
FMR_Audio_Level_e FMR_AUDIO_LEVEL = FMR_Audio_Acceptable;

kal_int32 FMR_RSSI_THRESHOLD = -4;	//range: -4dBuV ~ 70dBuV
kal_uint16 FMR_DESENSE_LEVEL = 1; 	//range: 0 ~ 6	(0:5dBuV, 1 : 10dBuV, 2 : 15dBuV, 3 : 20dBuV, 4 : 25dBuV, 5 : 30dBuV, 6 : 35dBuV)
#elif (defined(MT6260FM) || defined(MT6261FM))
typedef enum
{
	FMR_Audio_FalseAlarm = 0,
	FMR_Audio_Acceptable,
	FMR_Audio_Better,
	FMR_Audio_MBetter,
	FMR_Audio_Best,	
	FMR_Audio_End
}FMR_Audio_Level_e;
FMR_Audio_Level_e FMR_AUDIO_LEVEL = FMR_Audio_Acceptable;

kal_int32 FMR_RSSI_THRESHOLD = -4;	//range: -4dBuV ~ 70dBuV
kal_uint16 FMR_DESENSE_LEVEL = 1; 	//range: 0 ~ 6	(0:5dBuV, 1 : 10dBuV, 2 : 15dBuV, 3 : 20dBuV, 4 : 25dBuV, 5 : 30dBuV, 6 : 35dBuV)

#endif

kal_uint16 FMR_SCAN_BAND_UP = 1080; //108MHz
kal_uint16 FMR_SCAN_BAND_DN = 875; //87.5MHz
     
#endif
