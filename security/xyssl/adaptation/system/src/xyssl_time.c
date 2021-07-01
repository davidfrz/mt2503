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
 * xyssl_time.c
 *
 * Project:
 * --------
 *   OpenSSL
 *
 * Description:
 * ------------
 *   This is file is used to adapt the time related APIs in OpenSSL
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

#include "kal_general_types.h"
#include "kal_public_api.h"
#include <time.h>           /* time structure for kal_time.h */
#include "app_datetime.h"   /* app_gettime */
#include "kal_public_api.h"

extern void srand(kal_uint32 seed);
extern int rand(void);
#if defined (__UPDATE_BINARY_FILE__)
kal_uint32 (*xyssl_app_getcurrtime)(void);
kal_uint32 (*xyssl_app_gettime)(kal_uint32 *t_loc);
#endif
/*****************************************************************************
 * FUNCTION
 *  xyssl_adp_gmtime_r
 * DESCRIPTION
 *  This function is to adapt the OPENSSL_gmtime() to kal system
 * PARAMETERS
 *  *timer        [IN]        pointer to store time
 *  *result       [IN/OUT]    pointer to a structure of type tm (the result will be stored in it)
 * RETURNS
 *  pointer to a structure of type tm (it is equal to INPUT result) 
 *****************************************************************************/
kal_uint32 xyssl_adp_get_curr_time(void)
{
   #if defined (__UPDATE_BINARY_FILE__)
    return xyssl_app_getcurrtime();
   #else
    return app_getcurrtime();
   #endif
}

/*****************************************************************************
 * FUNCTION
 *  xyssl_adp_gmtime_r
 * DESCRIPTION
 *  This function is to adapt the OPENSSL_gmtime() to kal system
 * PARAMETERS
 *  *timer        [IN]        pointer to store time
 *  *result       [IN/OUT]    pointer to a structure of type tm (the result will be stored in it)
 * RETURNS
 *  pointer to a structure of type tm (it is equal to INPUT result) 
 *****************************************************************************/
struct tm *xyssl_adp_gmtime_r(const time_t *timer, struct tm *result)
{
    return gmtime_r(timer, result);
}


/*****************************************************************************
 * FUNCTION
 *  xyssl_adp_time
 * DESCRIPTION
 *  This function is to adapt the OPENSSL_time() to kal system.
 * PARAMETERS
 *  *t        [IN/OUT] return value is also stored in *t, if t is non-null
 * RETURNS
 *  the time since the Epoch (00:00:00 UTC, January 1, 1970),measured in seconds.
 *****************************************************************************/
time_t xyssl_adp_time(time_t *t)
{
     #if defined (__UPDATE_BINARY_FILE__)
     return (time_t)xyssl_app_gettime((kal_uint32 *)t);
	 #else
    return (time_t)app_gettime((kal_uint32 *)t);
	 #endif
}

/*****************************************************************************
 * FUNCTION
 *  xyssl_adp_RAND_seed
 * DESCRIPTION
 *  This function is to adapt the RAND_seed in OpenSSL RAND Lib.
 * PARAMETERS
 *  N/A
 * RETURNS
 *  void
 *****************************************************************************/
void xyssl_adp_RAND_seed(void)
{
    time_t      now_time = 0;
    /* get current time for random seed */
    xyssl_adp_time(&now_time);
	srand(now_time);
}

/*****************************************************************************
 * FUNCTION
 *  xyssl_adp_RAND
 * DESCRIPTION
 *  This function is to adapt the RAND_seed in OpenSSL RAND Lib.
 * PARAMETERS
 *  N/A
 * RETURNS
 *  void
 *****************************************************************************/
int xyssl_adp_RAND( void *p_rng )
{
	return rand()<<16 | rand();
}

