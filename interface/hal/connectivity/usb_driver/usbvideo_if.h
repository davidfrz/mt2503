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
 *  usbvideo_if.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file intends for usbvideo interface definition
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef USBVIDEO_IF_H
#define USBVIDEO_IF_H

#include "usbvideo_custom.h"
#include "app_ltlcom.h"
//#include "kal_non_specific_general_types.h"

typedef struct 
{
	LOCAL_PARA_HDR
	USBVideo_Attr_Value  attr_value;
} usbvideo_attr_msg_struct; 

typedef struct 
{
	LOCAL_PARA_HDR
	kal_uint8* buffer_addr;
	kal_uint32 buffer_size;
}usbvideo_video_req_struct; 


typedef enum 
{
	CONFIG_FAIL = 0,
	CONFIG_OK,
	CANNOT_CONFIG
}USB_CNF_RESPONSE;



typedef struct 
{
	LOCAL_PARA_HDR
	USBVIDEO_VIDEO_SIZE_TYPE video_size_type;
	USBVIDEO_COMPRESSION_TYPE video_compression_type;
	USB_CNF_RESPONSE result;
}usbvideo_video_size_struct; 

typedef struct 
{
	LOCAL_PARA_HDR
	USBVIDEO_STILL_SIZE_TYPE still_size_type;
	USBVIDEO_COMPRESSION_TYPE still_compression_type;
} usbvideo_still_size_struct; 

typedef struct 
{
	LOCAL_PARA_HDR
	kal_bool result;
} usbvideo_result_struct;

typedef struct
{
	kal_uint16 width;
	kal_uint16 height;
	kal_uint8* start_addr;
	kal_uint32 size;
}usbvideo_default_JPEG_Info;

typedef struct 
{
	LOCAL_PARA_HDR
	usbvideo_default_JPEG_Info *jpeg_info;	
	kal_uint8 size;
} usbvideo_default_JPEG_struct;


#endif /* USBVIDEO_IF_H */

