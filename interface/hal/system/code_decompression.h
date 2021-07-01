/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   cache_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the functionality of code and data cache.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef CODE_DECOMPRESSION_H
#define CODE_DECOMPRESSION_H

#if defined(__ZIMAGE_SUPPORT__)

#include "kal_general_types.h"

typedef void (*ZImageNotifyFunction)(kal_uint32, kal_uint32);

kal_int32 ZImageDecompressHal(kal_uint32 notifyLength, ZImageNotifyFunction notifyFunction);
#else

typedef void (*ZImageNotifyFunction)(kal_uint32, kal_uint32);

#endif /* __ZIMAGE_SUPPORT__ */

#endif /* CODE_DECOMPRESSION_H */
