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
*  LAWS PRINCIPLES.	ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  ABMLoader.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  ABM encoder external interface
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *			   HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __ABMLOADER_H__
#define __ABMLOADER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMIDataType.h"

#include "WriteResUtil.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
 /* 1 MB input bitmap file size limit */
#define ABMENC_BMP_FILE_BUFFER_SIZE     (8 * 1024 * 2048)

#define ABM_ENC_MAX_FILE_SIZE           0xffffffff

/* abm encoder option flags, encoder will return smallest selected format */
/* Original file format */
#define ABM_ENC_OPTION_FLAG_ORIGINAL    (1 << 0)
/* ABM file format */
#define ABM_ENC_OPTION_FLAG_ABM         (1 << 1)
/* ABM file format */    
#define ABM_ENC_OPTION_FLAG_AB2         (1 << 2)
/* 24-bit format */    
#define ABM_ENC_OPTION_FLAG_24BIT       (1 << 3)
/* All file format enable */
#define ABM_ENC_OPTION_FLAG_ALL         (ABM_ENC_OPTION_FLAG_ORIGINAL | ABM_ENC_OPTION_FLAG_ABM | ABM_ENC_OPTION_FLAG_AB2)


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
/* abm encoder return code */
typedef enum
{
    ABMENC_UNIT_TEST_FAILED = -1,       /* unit test failed */
    ABMENC_UNIT_TEST_SUCCESSFUL = 0,    /* unit test successful */

    ABM_ENC_INPUT_BITMAP_ERROR = -2,    /* input bitmap error */
    ABMENC_COLOR_NOT_FOUND = -1,        /* color not found in the color table */
    
    ABM_ENC_RETURN_KEEP_ORIGINAL = 0,   /* do not use ABM */
    ABM_ENC_RETURN_USE_ABM,             /* use ABM */
    ABM_ENC_RETURN_USE_AB2,             /* use ABMv2 */
    
    ABM_ENC_OK                          /* ABM internal use successful code */
} abm_enc_return_value;

typedef U32 abm_enc_option_flag_type;


/***************************************************************************** 
 * Global Function
 *****************************************************************************/
extern S32 ABM_load(
        U8  *in_bmp_filename,
        S32 dev_bmp_bpp,
        U8  image_type,
        abm_enc_option_flag_type option,
        U8  *data,
        S32 *size,
        S32 *width,
        S32 *height,
        MMI_BOOL is9slice,
        SetImageProcessData * processData);

extern S32 ABMLoader(U8 *in_filename, U8 *out_filename, S32 encode_option, MMI_BOOL is9slice, U8* _9slice_filename, SetImageProcessData * processData);
extern S32 is16BitBMP(U8  *in_bmp_filename);
#endif /* __ABMLOADER_H__ */
