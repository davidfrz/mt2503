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
 *   ctrl_buff_pool.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*********************************************************************
   (C) _____ (year of first publication) Sasken communication
   Technologies Limited, All rights reserved.
*   This file provides a template for .c files. This space
*   should be used to describe the file contents
*   Component-specific prefix : xxxx
*********************************************************************/

#ifndef _KAL_USER_MEM_H
#define _KAL_USER_MEM_H

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "stack_buff_pool.h"

/**************************Customer config interface Begin********************/
/*Customer interface I:
 *
 * Discription:
 *
 * Customer can adjust system memory size here.
 * This value will be added into total size of system memory.
 * Define a negative value to shrink(not recommended), positive value to increase. 
 *
 * Tips:
 * Customer may increase it if runs out of system memory(E.g 
 * Third party application use heavily KAL API like evshed_create, kal_create_sem, 
 * kal_create_eventgroup that consume system memory more than predefined value).
 * Customer may also shrink this if want to save some RAM size. However, this 
 * is not recommended. 
 *
 * See also:
 * tools\sys_mem_gen.pl
 * 
 * 
 * Build command : 
 * make c,r custom
 *
 *Build command on Modis:
 * make clean_modis custom
 * && make remake_modis custom 
 */ 
#define CUSTOM_CFG_GLOBAL_MEM_SIZE_IN_BYTES 0

/*Customer interface II:
 *
 * Discription:
 * Customer can adjust event pool number for event scheduler
 * This value is the actual event pool number
 *
 * Tips:
 * It's rare for customer to adjust this value. However, in case
 * of runs out of event when using event scheduler, this is the 
 * place for customer to adjust the event number. It's not recommended
 * to shrink this value.
 * 
 * Build command: 
 * make sysgen && make c,r config custom
 *
 * Build command on Modis:
 * make sys_mem_gen_modis && make clean_modis config custom
 * && make remake_modis config custom
 * */ 

#if defined(__CS_SERVICE__) && defined(__PS_SERVICE__)
#if defined(__GADGET_SUPPORT__)
#define KAL_MIN_EVSHED_BUFF_NUM (80 + 500)
#elif defined(__SIP__)
#define KAL_MIN_EVSHED_BUFF_NUM 160
#else
#define KAL_MIN_EVSHED_BUFF_NUM 80
#endif
#elif defined(__CS_SERVICE__)
#if defined(__GADGET_SUPPORT__)
#define KAL_MIN_EVSHED_BUFF_NUM 540
#elif defined(__SIP__)
#define KAL_MIN_EVSHED_BUFF_NUM 160
#else
#define KAL_MIN_EVSHED_BUFF_NUM 40
#endif
#endif	/* defined(__CS_SERVICE__) && defined(__PS_SERVICE__) */

/*Customer interface III:
 *
 * Discription:
 * Customer can adjust control buffer size here.
 * This value will be added into total number of control buffer. 
 * Define a negative value to decrease (not recommended ), positive 
 * value to increase.
 * 
 * Tips:
 * The control buffer number is well-tuned. It's not recommended to 
 * shrink this value.
 *
 * Build command: 
 * make sysgen && make c,r config custom
 *
 * Build command on Modis:
 * make sys_mem_gen_modis && make clean_modis config custom
 * && make remake_modis config custom
 *
 * */ 
typedef enum {
   NUM_CUSTOM_CTRL_BUFF_POOL_SIZE32     = 0,
   NUM_CUSTOM_CTRL_BUFF_POOL_SIZE64     = 0,
   NUM_CUSTOM_CTRL_BUFF_POOL_SIZE128    = 0,
   NUM_CUSTOM_CTRL_BUFF_POOL_SIZE256    = 0,
   NUM_CUSTOM_CTRL_BUFF_POOL_SIZE512    = 0,
   NUM_CUSTOM_CTRL_BUFF_POOL_SIZE1024   = 0,
   NUM_CUSTOM_CTRL_BUFF_POOL_SIZE2048   = 0,
   NUM_CUSTOM_CTRL_BUFF_POOL_SIZE4096   = 0,
#ifdef  __UMTS_RAT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
} custom_ctrl_num_buff_pool_size;
/**************************Customer config interface END**********************/


/*
 * NOTICE: The following are pre-defined configration. Cutomer should not
 * modify here. 
 * 
 * */


/*************************KAL private memory config stuff*******************/
#ifdef  __UMTS_RAT__
/* under construction !*/
#else   /* __UMTS_RAT__ */
#define RPS_CREATED_CTRL_BUFF_POOLS       8
#endif  /* __UMTS_RAT__ */

/* Buffer thresholds expressed in percentage */
#define FLC_CTRL_BUFF_UPPER_THRSHLD1 ( 90 )
#define FLC_CTRL_BUFF_UPPER_THRSHLD2 ( 95 )

/*************************************************************************
 * Type Definitions
 *************************************************************************/
/* For performance reason, general buffer pool is allocated for 2^n size */
typedef enum {
   CTRL_BUFF_POOL_SIZE32      = 32,
   CTRL_BUFF_POOL_SIZE64      = 64,
   CTRL_BUFF_POOL_SIZE128     = 128,
   CTRL_BUFF_POOL_SIZE256     = 256,
   CTRL_BUFF_POOL_SIZE512     = 512,
   CTRL_BUFF_POOL_SIZE1024    = 1024,
   CTRL_BUFF_POOL_SIZE2048    = 2048,
   CTRL_BUFF_POOL_SIZE4096    = 4096,
#ifdef  __UMTS_RAT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else   /* __UMTS_RAT__ */
   CTRL_BUFF_POOL_MAX_BUFF_SIZE = CTRL_BUFF_POOL_SIZE4096
#endif  /* __UMTS_RAT__ */
} ctrl_buff_pool_size;


#if defined(_SIMULATION)
typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32     = 20,
   NUM_CTRL_BUFF_POOL_SIZE64     = 10,
   NUM_CTRL_BUFF_POOL_SIZE128    = 10,
   NUM_CTRL_BUFF_POOL_SIZE256    = 10,
   NUM_CTRL_BUFF_POOL_SIZE512    = 10,
   NUM_CTRL_BUFF_POOL_SIZE1024   = 10,
   NUM_CTRL_BUFF_POOL_SIZE2048   = 8,
   NUM_CTRL_BUFF_POOL_SIZE4096   = 0,
   NUM_CTRL_BUFF_POOL_SIZE8192   = 0,
   NUM_CTRL_BUFF_POOL_SIZE16384  = 0,
   NUM_CTRL_BUFF_POOL_SIZE32768  = 0,
   NUM_CTRL_BUFF_POOL_SIZE65536  = 0,
   NUM_CTRL_BUFF_POOL_SIZE100000 = 0
} ctrl_num_buff_pool_size;
#elif defined(__UMTS_RAT__)
/* under construction !*/
   #if defined(__UMTS_TDD128_MODE__)
      #if defined(__UMTS_R5__) /* __UMTS_R5__ */
         #if defined(__GEMINI__)
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
		          #if defined(__MTK_TARGET__)   
/* under construction !*/
		          #else
/* under construction !*/
		          #endif
/* under construction !*/
	      #else 
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
	            #if defined(__MTK_TARGET__)   
/* under construction !*/
	            #else
/* under construction !*/
	            #endif
/* under construction !*/
	      #endif
      #endif  /* __UMTS_R5__ */
   #else  /* __UMTS_TDD128_MODE__ */
      #if defined(__UMTS_R5__)  /* __UMTS_R5__ */
         #if defined(__GEMINI_MONITOR_PAGE_DURING_TRANSFER__)  /* __GEMINI_MONITOR_PAGE_DURING_TRANSFER__ */
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
               #if defined(__MTK_TARGET__)   
/* under construction !*/
               #else
/* under construction !*/
               #endif
/* under construction !*/
         #else  /* __GEMINI_MONITOR_PAGE_DURING_TRANSFER__ */
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
               #if defined(__MTK_TARGET__)   
/* under construction !*/
               #else
/* under construction !*/
               #endif
/* under construction !*/
         #endif  /* __GEMINI_MONITOR_PAGE_DURING_TRANSFER__ */   
      #else  /* __UMTS_R5__ */
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
            #if defined(__MTK_TARGET__)   
/* under construction !*/
            #else
/* under construction !*/
            #endif
/* under construction !*/
      #endif  /* __UMTS_R5__ */
   #endif /* __UMTS_TDD128_MODE__ */
/* under construction !*/
#elif defined(__CS_SERVICE__) && defined(__PS_SERVICE__)    /* __UMTS_RAT__ */

/* GPRS Class B Solution */
#if ( GEMINI_PLUS > 2 )
typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32   = 280, /*286*/
   NUM_CTRL_BUFF_POOL_SIZE64   = 76,  /*78*/
   NUM_CTRL_BUFF_POOL_SIZE128  = 61,
   NUM_CTRL_BUFF_POOL_SIZE256  = 46,  /*50*/
   NUM_CTRL_BUFF_POOL_SIZE512  = 41,  /*42*/
   NUM_CTRL_BUFF_POOL_SIZE1024 = 16,
   NUM_CTRL_BUFF_POOL_SIZE2048 = 15,
   NUM_CTRL_BUFF_POOL_SIZE4096 = 0
} ctrl_num_buff_pool_size;
#elif defined(__GEMINI__)
#if (defined(__BT_MAX_LE_LINK_NUM__)) && (__BT_MAX_LE_LINK_NUM__ >= 1)
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
#else /* defined(__GEMINI__) */
#if (defined(__BT_MAX_LE_LINK_NUM__)) && (__BT_MAX_LE_LINK_NUM__ >= 1)
typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32   = 149,/*98*/
   NUM_CTRL_BUFF_POOL_SIZE64   = 120,/*20*/
   NUM_CTRL_BUFF_POOL_SIZE128  = 80,
   NUM_CTRL_BUFF_POOL_SIZE256  = 33,/*30*/
   NUM_CTRL_BUFF_POOL_SIZE512  = 20,
   NUM_CTRL_BUFF_POOL_SIZE1024 = 16,
   NUM_CTRL_BUFF_POOL_SIZE2048 = 8,
   NUM_CTRL_BUFF_POOL_SIZE4096 = 0
} ctrl_num_buff_pool_size;
#elif defined(__LINKIT_DEV_KIT__)
    typedef enum {
       NUM_CTRL_BUFF_POOL_SIZE32   = 149, /*155*/
       NUM_CTRL_BUFF_POOL_SIZE64   = 70,  /*74*/
       NUM_CTRL_BUFF_POOL_SIZE128  = 45,
       NUM_CTRL_BUFF_POOL_SIZE256  = 33,  /*48*/
       NUM_CTRL_BUFF_POOL_SIZE512  = 16,  /*22*/
       NUM_CTRL_BUFF_POOL_SIZE1024 = 16,
       NUM_CTRL_BUFF_POOL_SIZE2048 = 8,
       NUM_CTRL_BUFF_POOL_SIZE4096 = 0
    } ctrl_num_buff_pool_size;
#else
typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32   = 149, /*155*/
   NUM_CTRL_BUFF_POOL_SIZE64   = 28,  /*74*/
   NUM_CTRL_BUFF_POOL_SIZE128  = 45,
   NUM_CTRL_BUFF_POOL_SIZE256  = 33,  /*48*/
   NUM_CTRL_BUFF_POOL_SIZE512  = 16,  /*22*/
   NUM_CTRL_BUFF_POOL_SIZE1024 = 16,
#if defined(__GPS_ADAPTOR_SUPPORT__)    
   NUM_CTRL_BUFF_POOL_SIZE2048 = 11,
#else                    
   NUM_CTRL_BUFF_POOL_SIZE2048 = 8,
#endif
   NUM_CTRL_BUFF_POOL_SIZE4096 = 0
} ctrl_num_buff_pool_size;
#endif
#endif /* defined(__GEMINI__) */

#elif defined(__CS_SERVICE__)   /* __UMTS_RAT__ */

#if defined(IC_BURNIN_TEST)

/* Reduce the No. of buffer to reduce memory consumption. */

typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32   = 10,
   NUM_CTRL_BUFF_POOL_SIZE64   = 5,
   NUM_CTRL_BUFF_POOL_SIZE128  = 5,
   NUM_CTRL_BUFF_POOL_SIZE256  = 5,
   NUM_CTRL_BUFF_POOL_SIZE512  = 2,
   NUM_CTRL_BUFF_POOL_SIZE1024 = 5,
   NUM_CTRL_BUFF_POOL_SIZE2048 = 3,
   NUM_CTRL_BUFF_POOL_SIZE4096 = 1
} ctrl_num_buff_pool_size;

#elif defined(LOW_COST_SUPPORT) /* LOW_COST_SUPPORT */

#if defined(__LOW_COST_SUPPORT_ULC__) /* __LOW_COST_SUPPORT_ULC__ */

#if defined(__GEMINI__) /* __GEMINI__ */
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
#else /* __GEMINI__ */

typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32   = 57,/*63*/
   NUM_CTRL_BUFF_POOL_SIZE64   = 18,/*20*/
   NUM_CTRL_BUFF_POOL_SIZE128  = 30,
   NUM_CTRL_BUFF_POOL_SIZE256  = 15,/*17*/
   NUM_CTRL_BUFF_POOL_SIZE512  = 8,
   NUM_CTRL_BUFF_POOL_SIZE1024 = 8,
   NUM_CTRL_BUFF_POOL_SIZE2048 = 4,
   NUM_CTRL_BUFF_POOL_SIZE4096 = 0
} ctrl_num_buff_pool_size;

#endif /* __GEMINI__ */

#else /* __LOW_COST_SUPPORT_ULC__ */

#if ( GEMINI_PLUS > 3 )

typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32   = 92, /*98*/
   NUM_CTRL_BUFF_POOL_SIZE64   = 36, /*38*/
   NUM_CTRL_BUFF_POOL_SIZE128  = 40,
   NUM_CTRL_BUFF_POOL_SIZE256  = 30, /*32*/
   NUM_CTRL_BUFF_POOL_SIZE512  = 20,
   NUM_CTRL_BUFF_POOL_SIZE1024 = 12,
   NUM_CTRL_BUFF_POOL_SIZE2048 = 13,
   NUM_CTRL_BUFF_POOL_SIZE4096 = 0
} ctrl_num_buff_pool_size;

#elif ( GEMINI_PLUS > 2 )

typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32   = 92, /*98*/
   NUM_CTRL_BUFF_POOL_SIZE64   = 31, /*33*/
   NUM_CTRL_BUFF_POOL_SIZE128  = 40,
   NUM_CTRL_BUFF_POOL_SIZE256  = 29, /*31*/
   NUM_CTRL_BUFF_POOL_SIZE512  = 20,
   NUM_CTRL_BUFF_POOL_SIZE1024 = 10,
   NUM_CTRL_BUFF_POOL_SIZE2048 = 10,
   NUM_CTRL_BUFF_POOL_SIZE4096 = 0
} ctrl_num_buff_pool_size;

#elif defined(__GEMINI__) /* __GEMINI__ */
#if (defined(__BT_MAX_LE_LINK_NUM__)) && (__BT_MAX_LE_LINK_NUM__ >= 1)
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
#endif //(defined(__BT_MAX_LE_LINK_NUM__)) && (__BT_MAX_LE_LINK_NUM__ >= 1)
#else /* __GEMINI__ */

#if (defined(__BT_MAX_LE_LINK_NUM__)) && (__BT_MAX_LE_LINK_NUM__ >= 1)
typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32   = 142,/*98*/
   NUM_CTRL_BUFF_POOL_SIZE64   = 120,/*20*/
   NUM_CTRL_BUFF_POOL_SIZE128  = 80,
   NUM_CTRL_BUFF_POOL_SIZE256  = 28,/*30*/
   NUM_CTRL_BUFF_POOL_SIZE512  = 20,
   NUM_CTRL_BUFF_POOL_SIZE1024 = 9,
   NUM_CTRL_BUFF_POOL_SIZE2048 = 7,
   NUM_CTRL_BUFF_POOL_SIZE4096 = 0
} ctrl_num_buff_pool_size;
#else
typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32   = 92,/*98*/
   NUM_CTRL_BUFF_POOL_SIZE64   = 60,/*20*/
   NUM_CTRL_BUFF_POOL_SIZE128  = 40,
   NUM_CTRL_BUFF_POOL_SIZE256  = 28,/*30*/
   NUM_CTRL_BUFF_POOL_SIZE512  = 20,
   NUM_CTRL_BUFF_POOL_SIZE1024 = 9,
   NUM_CTRL_BUFF_POOL_SIZE2048 = 7,
   NUM_CTRL_BUFF_POOL_SIZE4096 = 0
} ctrl_num_buff_pool_size;
#endif //(defined(__BT_MAX_LE_LINK_NUM__)) && (__BT_MAX_LE_LINK_NUM__ >= 1)
#endif /* __GEMINI__ */

#endif /* __LOW_COST_SUPPORT_ULC__ */

#else  /* LOW_COST_SUPPORT (default configuration for BASIC, UDVT load) */

typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32   = 63,
   NUM_CTRL_BUFF_POOL_SIZE64   = 20,
   NUM_CTRL_BUFF_POOL_SIZE128  = 30,
   NUM_CTRL_BUFF_POOL_SIZE256  = 17,
   NUM_CTRL_BUFF_POOL_SIZE512  = 8,
   NUM_CTRL_BUFF_POOL_SIZE1024 = 8,
   NUM_CTRL_BUFF_POOL_SIZE2048 = 4,
   NUM_CTRL_BUFF_POOL_SIZE4096 = 0
} ctrl_num_buff_pool_size;

#endif  /* LOW_COST_SUPPORT */

#endif  /* __UMTS_RAT__ */

#define META_EXTRA_CTRL_BUFF_POOL_SIZE4096 CTRL_BUFF_POOL_SIZE4096

/*************************************************************************
 * Exported Global Variables
 *************************************************************************/
extern buff_pool_info_struct ctrl_buff_pool_info_g[ RPS_CREATED_CTRL_BUFF_POOLS];

/*************************************************************************
 * Exported Function Prototypes
 *************************************************************************/
extern void config_ctrl_buff_info( void );
#endif /*_KAL_USER_MEM_H*/


