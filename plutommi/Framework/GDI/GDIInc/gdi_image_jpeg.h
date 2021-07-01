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
 *  gdi_image_jpeg.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Image Jpeg header file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _GDI_IMAGE_JPEG_H_
#define _GDI_IMAGE_JPEG_H_

#include "MMIDataType.h"
#include "gdi_const.h"
#include "gdi_datatype.h"

#if defined(GDI_USING_HW_JPEG_V2)
#define GDI_JPEG_LOCK_MUTEX      gdi_jpeg_lock_mutex()
#define GDI_JPEG_UNLOCK_MUTEX    gdi_jpeg_unlock_mutex()

extern void gdi_jpeg_lock_mutex(void);
extern void gdi_jpeg_unlock_mutex(void);
#endif

extern GDI_RESULT gdi_image_is_jpeg_file(U8 *file_name);
extern GDI_RESULT gdi_image_jpeg_draw_handler(
                    U32 flag,
                    U32 frame_pos,
                    S32 x,
                    S32 y,
                    S32 w,
                    S32 h,
                    U8 *data_ptr,
                    U32 img_size);
extern GDI_RESULT gdi_image_jpeg_get_dimension_handler(
                    U32 flag,
                    U8 *data_ptr,
                    U32 img_size,
                    S32 *width,
                    S32 *height);
extern GDI_RESULT gdi_image_hwjpeg_draw_internal(
                            gdi_handle output_layer_handle,
                            S32 ox,
                            S32 oy,
                            S32 resized_width,
                            S32 resized_height,
                            S32 output_clipx1,
                            S32 output_clipy1,
                            S32 output_clipx2,
                            S32 output_clipy2,
                            U8 *src,
                            U32 size,
                            BOOL is_file,
                            BOOL is_resized,
                            U8 *dest_buf,
                            S32 dest_buf_size,
                            S32 *ret_decoded_image_width,
                            gdi_color_format dest_buf_cf,
                            BOOL *is_aborted,
                            U32 flag);

#if defined(GDI_USING_HW_JPEG_V2)
extern GDI_RESULT gdi_image_hwjpeg_v2_draw_internal(
                            gdi_handle output_layer_handle,
                            S32 ox,
                            S32 oy,
                            S32 resized_width,
                            S32 resized_height,
                            U8 *src,
                            U32 size,
                            BOOL is_file,
                            BOOL is_resized,
                            S32 *decoded_image_width,
                            BOOL source_key_enable,
                            gdi_color source_key_value,
                            BOOL *is_aborted,
                            U32 flag,
                            S32 aspect_flag,
                            BOOL need_rotate);
extern void gdi_image_jpeg_v2_init(void);
extern GDI_RESULT gdi_jpeg_get_dimension_internal(U8 *src, U32 size, S32 *width, S32 *height, BOOL need_rotate);
#endif

extern GDI_RESULT gdi_imgdec_jpeg_get_dimension(U8 *src, U32 size, S32 *width, S32 *height);

#endif /* _GDI_IMAGE_JPEG_H_ */ 


