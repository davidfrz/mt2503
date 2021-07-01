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
 * RESOURCE_AUDIO.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for audio resource database.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/*
**   Includes
*/
//#include "kal_release.h"

#ifndef __L1_STANDALONE__

#ifdef WIN32
#define __align(X)
#endif

//#include "device.h"
#include "resource_audio.h"
//#include "MMI_features.h"

static const device_tones_struct dtmf0[]           =  {  { 941, 1336, 0,  0,   0 }   };
static const device_tones_struct dtmf1[]           =  {  { 697, 1209, 0,  0,   0 }   };
static const device_tones_struct dtmf2[]           =  {  { 697, 1336, 0,  0,   0 }   };
static const device_tones_struct dtmf3[]           =  {  { 697, 1477, 0,  0,   0 }   };
static const device_tones_struct dtmf4[]           =  {  { 770, 1209, 0,  0,   0 }   };
static const device_tones_struct dtmf5[]           =  {  { 770, 1336, 0,  0,   0 }   };
static const device_tones_struct dtmf6[]           =  {  { 770, 1477, 0,  0,   0 }   };
static const device_tones_struct dtmf7[]           =  {  { 852, 1209, 0,  0,   0 }   };
static const device_tones_struct dtmf8[]           =  {  { 852, 1336, 0,  0,   0 }   };
static const device_tones_struct dtmf9[]           =  {  { 852, 1477, 0,  0,   0 }   };
static const device_tones_struct dtmfstar[]        =  {  { 941, 1209, 0,  0,   0 }   };
static const device_tones_struct dtmfhash[]        =  {  { 941, 1477, 0,  0,   0 }   };
static const device_tones_struct dtmfnormal[]        =  {  { 1200,  0, 100,  0,   0 }   };
/* ref ETSI: 02.40 */
static const device_tones_struct tone_dial_call_gsm[]       =  {  { 425,   0,   0,   0,   0 }   };
static const device_tones_struct tone_dial_call_pcs[]       =  {  { 350, 440,   0,   0,   0 }   };
static const device_tones_struct tone_busy_call_gsm[]       =  {  { 425,   0, 500, 500,   0 }   };
static const device_tones_struct tone_busy_call_pcs[]       =  {  { 480, 620, 500, 500,   0 }   };
static const device_tones_struct tone_congestion_gsm[]       =  {  { 425,   0, 200, 200,   0 }   };
static const device_tones_struct tone_congestion_pcs[]       =  {  { 480, 620, 200, 200,   0 }   };
static const device_tones_struct tone_radio_path[]           =  {  { 425,   0, 200,   0,   0 }   };
static const device_tones_struct tone_radio_na[]           =  {  { 425,   0, 200, 200,   1 },
                                                                  { 425,   0, 200, 200,   2 },
                                                                  { 425,   0, 200,   0,   0 }   };
static const device_tones_struct tone_error_info[]          =  {  { 950,   0, 330,1000,   0 }   };
static const device_tones_struct tone_num_unobtain[]          =  {  {1400,   0, 330, 0,   0 }   };
static const device_tones_struct tone_auth_error[]          =  {  { 950,   0, 330,1000,   0 }   };

#ifndef __REPEAT_CALL_WAITING_TONE__ /* GSM */
static const device_tones_struct tone_call_waiting[]           =  {  { 425,   0, 200, 600,   1 },
                                                                     { 425,   0, 200,3000,   2 },
                                                                     { 425,   0, 200, 600,   3 },
                                                                     { 425,   0, 200,   0,   0 }   };
#else /* __REPEAT_CALL_WAITING_TONE__ */
static const device_tones_struct tone_call_waiting[]           =  {  { 440,   0, 200, 100,   1 },
                                                                     { 440,   0, 200,3500,   0 }   };
#endif /* __REPEAT_CALL_WAITING_TONE__ */
                                                                        
static const device_tones_struct tone_ring_tone_gsm[]           =  {  { 425,   0, 2000, 1000,   0 }   };
static const device_tones_struct tone_ring_tone_pcs[]           =  {  { 425,   0, 2000, 4000,   0 }   };

/* for SAT by brian */
static const device_tones_struct tone_positive_ack[]           =  {  { 600,   0, 200, 100,   1 },
                                                                     { 800,   0, 200, 100,   2 },
                                                                     { 1000,   0, 200,   0,   0 }   };
static const device_tones_struct tone_negative_ack[]           =  {  { 600,   0, 300, 100,   1 },
                                                                     { 300,   0, 700,   0,   0 }   };

static const device_tones_struct tone_mt_sms_in_call[]           =  {  { 852, 1209, 200,  0,   0 }   };

static const device_tones_struct tone_warning1[]           =  {  { 852, 0, 200,  0,   0 }   };
static const device_tones_struct tone_warning2[]           =  {  { 852, 0, 200,  0,   0 }   };
static const device_tones_struct tone_error1[]           =  {  { 1209, 0, 200,  0,   0 }   };
static const device_tones_struct tone_error2[]           =  {  { 1209, 0, 200,  0,   0 }   };
static const device_tones_struct tone_general_beep[]           =  {  { 700, 0, 200,  0,   0 }   };

static const device_tones_struct tone_key_click[]           =  {  { 1500, 0, 200,  0,   0 }   };
static const device_tones_struct tone_call_connect[]           =  {  { 700, 0, 200,  0,   0 }   };
static const device_tones_struct tone_battery_low[]           =  {  { 1100,   0, 300, 100,   1 },
                                                                     { 900,   0, 300,   0,   0 }   };
static const device_tones_struct tone_battery_warning[]       =  {  { 1400,   0, 300, 100,   1 },
                                                                     { 1400,   0, 300, 100,   2 },
                                                                     { 1400,   0, 300,   0,   0 }   };
static const device_tones_struct tone_aux_ind[]                =  {  { 700, 0, 200,  0,   0 }   };
static const device_tones_struct tone_data_call[]           =  {  { 425,   0, 2000, 1000,   0 }   };
static const device_tones_struct tone_call_time_reminder[]     =  {  { 852, 0, 200,  0,   0 }   };
#ifdef __OP01_FWPBW__
static const device_tones_struct tone_continue_sound[]       =  {  { 400, 0, 0,  0,   0 }   };
#endif

const device_tones_struct *mtk_resource_tones[]=
{
   dtmf0, /* TONE_DTMF_0 */            	/* 0 */
   dtmf1,                           	/* 1 */
   dtmf2,                           	/* 2 */
   dtmf3,                           	/* 3 */
   dtmf4,                           	/* 4 */
   dtmf5,                           	/* 5 */
   dtmf6,                           	/* 6 */
   dtmf7,                            	/* 7 */
   dtmf8,                           	/* 8 */
   dtmf9, /* TONE_DTMF_9 */            	/* 9 */
   dtmfstar, /* TONE_KEY_STAR */        /* 10 */
   dtmfhash, /* TONE_KEY_HASH */       /* 11 */
   dtmfnormal, /* TONE_KEY_NORMAL */   /* 12 */
   tone_key_click,       				/* 13 */

   tone_call_connect,                  /* 14 */
   tone_mt_sms_in_call,				/* 15 */
   tone_call_time_reminder,			/* 16 */
   
   tone_dial_call_gsm,				/* 17 */
   tone_dial_call_pcs, 				/* 18 */
   tone_busy_call_gsm, 				/* 19 */
   tone_busy_call_pcs,				/* 20 */
   tone_congestion_gsm,				/* 21 */
   tone_congestion_pcs, 			/* 22 */
   tone_radio_path,					/* 23 */
   tone_radio_na,					/* 24 */
   tone_error_info, 				/* 25 */
   tone_num_unobtain, 				/* 26 */
   tone_auth_error,					/* 27 */
   tone_call_waiting, 				/* 28 */
   tone_ring_tone_gsm, 				/* 29 */
   tone_ring_tone_pcs,				/* 30 */
   tone_positive_ack, 				/* 31 */
   tone_negative_ack,				/* 32 */

   tone_dial_call_gsm,				/* 33 */
   tone_dial_call_pcs,				/* 34 */
   tone_busy_call_gsm,				/* 35 */
   tone_busy_call_pcs,				/* 36 */
   tone_congestion_gsm,				/* 37 */
   tone_congestion_pcs,				/* 38 */
   tone_radio_path,					/* 39 */
   tone_radio_na,					/* 40 */
   tone_error_info,	    			/* 41 */
   tone_num_unobtain,				/* 42 */
   tone_auth_error,					/* 43 */
   tone_call_waiting,				/* 44 */
   tone_ring_tone_gsm,				/* 45 */
   tone_ring_tone_pcs,				/* 46 */
   tone_positive_ack,				/* 47 */
   tone_negative_ack,				/* 48 */

   tone_warning1,					/* 49 */
   tone_warning2,					/* 50 */
   tone_error1,						/* 51 */
   tone_error2,						/* 52 */
   tone_general_beep, 				/* 53 */
   tone_battery_low,    			/* 54 */
   tone_battery_warning,			/* 55 */
   tone_aux_ind,					/* 56 */
   tone_data_call					/* 57 */
#ifdef __OP01_FWPBW__
   ,tone_continue_sound              /* 58 */
#endif
};
#endif /* !__L1_STANDALONE__ */