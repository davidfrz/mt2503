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
 * phb_defs.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file contains common definitions for PHB module.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef _PHB_DEFS_H
#define _PHB_DEFS_H

#include "kal_release.h"
#include "stack_config.h"
#include "kal_general_types.h"

#include "sim_public_api.h"


#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    /* Header files should be include before this one */


/*----------------------------------------------------------------------------*/
/* CallLog                                                                    */
/*----------------------------------------------------------------------------*/

/*---------------------- CallLog Number Check --------------------------------*/

#if !defined(__PHB_NO_CALL_LOG__)


#if (MAX_PHB_LN_ENTRY > 10) && (MAX_PHB_LN_ENTRY != 20) && \
   (MAX_PHB_LN_ENTRY != 30) && (MAX_PHB_LN_ENTRY != 40) && \
   (MAX_PHB_LN_ENTRY != 50) && (MAX_PHB_LN_ENTRY != 60) && \
   (MAX_PHB_LN_ENTRY != 70) && (MAX_PHB_LN_ENTRY != 80) && \
   (MAX_PHB_LN_ENTRY != 90) && (MAX_PHB_LN_ENTRY != 100)
#error PHB_LN_ENTRY should be set to 20, 30, 40, 50, 60, 70, 80, 90, 100 or less and equal than 10
#endif 


/*---------------------- Internal Compile option ----------------------------*/

#if (MAX_PHB_LN_ENTRY > 20)

#ifndef __PHB_RECORD_LN_TYPE_SEQ__
#define __PHB_RECORD_LN_TYPE_SEQ__
#endif 

#ifndef __PHB_LN_SINGLE_COUNT__
#define __PHB_LN_SINGLE_COUNT__
#endif 

#else /* (MAX_PHB_LN_ENTRY > 20) */

/* Support Consecutive merge style */
#ifndef __PHB_LN_CONSECUTIVE_MERGE__
//#define __PHB_LN_CONSECUTIVE_MERGE__
#endif

#endif /* (MAX_PHB_LN_ENTRY > 20) */ 






#endif /* !defined(__PHB_NO_CALL_LOG__) */




/*----------------------------------------------------------------------------*/
/* CallLog End                                                                */
/*----------------------------------------------------------------------------*/


#define PHB_INVALID_VALUE              ~0
#define PHB_NULL_VALUE                 0

#define BYTE_SIZE                      8
#define BYTE_SIZE_SHIFT_ARITHMETIC     3


/*----------------------------------------------------------------------------*/
/* CallLog                                                                    */
/*----------------------------------------------------------------------------*/

/* Number of LN entries in one NVRAM LID */
#if (MAX_PHB_LN_ENTRY >= 10)
#define PHB_MAX_LN_ENTRIES             10
#else 
#define PHB_MAX_LN_ENTRIES              MAX_PHB_LN_ENTRY
#endif /* MAX_PHB_LN_ENTRY >= 10 */

#ifdef __L4_MAX_NAME_60__
#define PHB_MAX_LND_ENTRIES            15
#define PHB_MAX_LNM_ENTRIES            15
#define PHB_MAX_LNR_ENTRIES            15
#else /* __L4_MAX_NAME_60__ */ 
#define PHB_MAX_LND_ENTRIES            MAX_PHB_LN_ENTRY
#define PHB_MAX_LNM_ENTRIES            MAX_PHB_LN_ENTRY
#define PHB_MAX_LNR_ENTRIES            MAX_PHB_LN_ENTRY
#endif /* __L4_MAX_NAME_60__ */ 

#if !defined(__PHB_NO_CALL_LOG__)
#ifdef __PHB_RECORD_LN_TYPE_SEQ__
#define PHB_TOTAL_LN_ENTRIES           (PHB_MAX_LND_ENTRIES+PHB_MAX_LNM_ENTRIES+PHB_MAX_LNR_ENTRIES)
#endif 

#define PHB_TOT_LND_LIDS      ((PHB_MAX_LND_ENTRIES+PHB_MAX_LN_ENTRIES-1)/PHB_MAX_LN_ENTRIES)
#define PHB_TOT_LNM_LIDS      ((PHB_MAX_LNM_ENTRIES+PHB_MAX_LN_ENTRIES-1)/PHB_MAX_LN_ENTRIES)
#define PHB_TOT_LNR_LIDS      ((PHB_MAX_LNR_ENTRIES+PHB_MAX_LN_ENTRIES-1)/PHB_MAX_LN_ENTRIES)

#define PHB_LND_LID_START     1
#define PHB_LNM_LID_START     (PHB_TOT_LND_LIDS + PHB_LND_LID_START)
#define PHB_LNR_LID_START     (PHB_TOT_LNM_LIDS + PHB_LNM_LID_START)
#define PHB_TOTAL_LN_LID      (PHB_TOT_LND_LIDS+PHB_TOT_LNM_LIDS+PHB_TOT_LNR_LIDS)
#endif /* !defined(__PHB_NO_CALL_LOG__) */


/*----------------------------------------------------------------------------*/
/* CallLog End                                                                */
/*----------------------------------------------------------------------------*/



#ifdef __PHB_USIM_SUPPORT__
#define PHB_TYPE2_FILE_FLAG          (0x80)
#endif

/* delete all turbo */
#define __PHB_DELETE_ALL_TURBO__ 
    /* Concurrency degree is the number of control blocks. */
#if defined(__PHB_ACCESS_SIM_LN__) && defined(__CLOG_STORAGE_BY_MMI__) 
#define PHB_CONCURRENCY_DEGREE         3
#else
#define PHB_CONCURRENCY_DEGREE         2
#endif

    /* In byte(s). Must not exceeds the capacity defined by l4_common_struct.h. */
    /* 20040802 Wilson, If LMMI providing sorting mechanism, it does not need to sort in L4 */
#if defined(__MMI_FMI__)
#define PHB_ALPHA_ID_DEPTH             1
#else 
#define PHB_ALPHA_ID_DEPTH             10
#endif 

    /* Number of bytes after ALPHA_ID field */
#define PHB_LENGTH_AFTER_ALPHA_ID      14

    /* Byte size of TON/NPI allocated in NVRAM/SIM */
#define TON_NPI_SIZE 1

/**
 * Maximum bytes of TON/NPI and DIALLING_NUMBER/SSC_STRING 
 * fields allocated for ADN-like EF's
 */
#define PHB_EF_MAX_TON_NPI_TEL_NUMBER_LEN       11

/**
 * Maximum bytes of DIALLING_NUMBER/SSC_STRING field allocated
 * for EXT-like EF's.
 */
#define PHB_EF_EXT_MAX_TEL_NUMBER_LEN      10

#define PHB_EMAIL_MAX_LEN 60

    /* TON and NPI constants */
#define NPI_UNKNOWN                    0
#define NPI_ISDN                       1
/** 
 * Most significant bit is always 1 for TON. ie, 1???. 
 * Hence, 
 * TON_UNKNOW is 1000, TON_NATIONAL is 1010, and 
 * TON_INTERNATIONAL is 1001
 */
#define TON_EXT                        0x08
#define TON_UNKNOWN                    0x00
#define TON_INTERNATIONAL              0x01
#define TON_NATIONAL                   0x02
#define TON_NETWORK_SPECIFIC           0x03
#define TON_DEDICATED                  0x04

    /* Default TON/NPI */
#define TON_NPI_DEFAULT    (((TON_EXT | TON_UNKNOWN) << 4) | NPI_ISDN)

#define FETCH_TON(x)       ((x >> 4) & 0x07)

    /* This is reserved for possible revision of l4_addr_bcd_struct */
#define L4_ADDR_BCD_TON_NPI_OFFSET     0
#define L4_ADDR_BCD_TON_NPI_SIZE       1
#define L4_ADDR_BCD_TEL_NUM_OFFSET     1

    /* Valid digits are 0x00 ~ 0x0C; ie, before p; ranges from 0 ~ *, #. */
#define DN_VALID_DIGIT_LIMIT           0x0C

#if defined(GEMINI_PLUS) && (GEMINI_PLUS >= 4)
extern module_type phb_current_mod;
#define PHB_SIM_NUM 4
#elif defined(GEMINI_PLUS) && (GEMINI_PLUS >= 3)
extern module_type phb_current_mod;
#define PHB_SIM_NUM 3
#elif defined(__GEMINI__)
/* under construction !*/
/* under construction !*/
#else
#define PHB_SIM_NUM 1
#endif

#ifdef __REL5__
#define MAX_NETWORK_ECC_NUM 16
#endif /* __REL5__ */


#if defined(__GEMINI__) || defined(GEMINI_PLUS)
#define PHB_WHICH_SIM phb_which_sim_ex()
#define PHB_SIM_SERVICE_TABLE_QUERY(x) (sim_service_table_query(x, PHB_WHICH_SIM) == SERVICE_SUPPORT ? KAL_TRUE : KAL_FALSE)
#else /* __GEMINI__ */
#define PHB_WHICH_SIM
#define PHB_SIM_SERVICE_TABLE_QUERY(x) (sim_service_table_query(x) == SERVICE_SUPPORT ? KAL_TRUE : KAL_FALSE)
#endif /* __GEMINI__ */


    typedef enum
    {
        IO_NONE,
    #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
        IO_READ_IAP,
        IO_WRITE_IAP,
    #endif
        IO_WAIT,
        IO_SEGMENTATION,
        IO_COMPLETE,
    } IO_state_enum;

    typedef enum
    {
        OP_READ,
        OP_WRITE,
        OP_DELETE
    } op_enum;

    typedef struct
    {
        kal_uint8 length;
        kal_uint8 charset;
        kal_uint8 data[PHB_ALPHA_ID_DEPTH];
    } alpha_id_type;

#define EF_TEL_NUMBER_SIZE 10
    /* Stored phone book entries structure */
    typedef struct
    {
        kal_uint8 len;
        kal_uint8 ton_npi;
        kal_uint8 tel_number[EF_TEL_NUMBER_SIZE];
        kal_uint8 cap_cnf_id;
        kal_uint8 ext_id;   /* Should not be used for nvram_access. */
        /* Note that BDN has 1 byte more: comparison method ID */
    } phb_ef_mandatory_struct;

    typedef struct
    {
        kal_uint8 *alpha_id;
        phb_ef_mandatory_struct *mandatory;
    } phb_ef_struct;

#ifdef __cplusplus
}
#endif 

#endif /* _PHB_DEFS_H */ 

