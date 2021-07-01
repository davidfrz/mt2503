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
 *  gdi_datatype.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI header file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _GDI_DATATYPE_H_
#define _GDI_DATATYPE_H_

#include "MMIDataType.h"

typedef U32 gdi_color;
typedef U8 gdi_color_format;
typedef U32 gdi_handle;
typedef S32 gdi_result;

typedef U8 gdi_image_type;

typedef struct
{
    S32 x;
    S32 y;
    S32 z;
} gdi_point3D_stuct;

/* clip region structure */
typedef struct
{
    S32 x1;
    S32 y1;
    S32 x2;
    S32 y2;
} gdi_rect_struct;

typedef struct
{
    S16 x;
    S16 y;
} gdi_point2D_struct;

typedef struct
{
    S32 x;
    S32 y;
} gdi_point_S32_struct;

 typedef struct _gdi_polygon_edge_struct
{
    S32 Ymin;       /* min Y */
    S32 Ymax;       /* max Y */
    S32 Xint;       /* the round up value of real current x */
    S32 Xfra;       /* the nuerator of fraction part of x, if Xfra==slope_y, actually that meas Xfra==0. */
    S32 slope_x;    /* numerator of slope */
    S32 slope_y;    /* denominator of slope */
    struct _gdi_polygon_edge_struct *next;
}gdi_polygon_edge_struct;

typedef struct
{
    U32 header_size;
    U32 buf_width;
    U32 buf_height;
    U8  color_format;
    U8* buf_ptr;
    U32 buf_size;
} gdi_screen_shot_info_struct;

typedef struct
{
    void (*callback_func)(void *user_data);
    void *user_data;
} gdi_callback_struct;

typedef struct
{
    gdi_image_type type;
    kal_int32 width;
    kal_int32 height;
} gdi_image_info_struct;


typedef gdi_color(*gd_color_from_rgb_func) (U32 A, U32 R, U32 G, U32 B);
typedef void (*gd_color_to_rgb_func) (U32 *A, U32 *R, U32 *G, U32 *B, gdi_color c);

typedef gdi_color(*gd_get_pixel_func) (int x, int y);
typedef void (*gd_put_pixel_func) (int x, int y, gdi_color c);
typedef void (*gd_put_pixel_to_layer_func) (gdi_handle layer_handle, int x, int y, gdi_color c);
typedef gdi_color(*gd_get_buf_pixel_func) (U8 *buf_ptr, U32 buf_width, int x, int y);
typedef void (*gd_put_buf_pixel_func) (U8 *buf_ptr, U32 buf_width, int x, int y, gdi_color c);
typedef void (*gd_replace_src_key_func) (U8 *dest_ptr, S32 dest_pitch, S32 dest_offset_x, S32 dest_offset_y,
                                         S32 clipx1, S32 clipy1, S32 clipx2, S32 clipy2, gdi_color src_key, S32 width,
                                         S32 height);
typedef void (*gd_bitblt_func) (U8 *dest, S32 dw, S32 dh, S32 dx1, S32 dy1, S32 dx2, S32 dy2, U8 *src, S32 sw, S32 sh,
                                S32 sx1, S32 sy1, S32 sx2, S32 sy2, S32 clipx1, S32 clipy1, S32 clipx2, S32 clipy2,
                                gdi_color src_key, gdi_color layer_key);
typedef void (*gd_memset_func) (U8 *dest, U32 value, U32 len);
typedef void (*gd_fill_dot_rect_func)(U8 *dest,S32 dw,S32 dh,S32 dx1,S32 dy1,S32 dx2,S32 dy2,S32 clipx1,S32 clipy1,S32 clipx2,S32 clipy2,gdi_color c);
typedef void (*gd_image_bits_draw_func)(U8 *dest,S32 dw, S32 dh, S32 dx1, S32 dy1, S32 dx2, S32 dy2, U8 *src, S32 sw,S32 sh,S32 sx1,S32 sy1, S32 sx2, S32 sy2, S32 src_size,S32 bits_per_pixel,gdi_color palette[],S32 clipx1, S32 clipy1, S32 clipx2, S32 clipy2);


typedef enum
{
    GDI_MEM_TYPE_CACHEABLE,
    GDI_MEM_TYPE_FRAMEBUFFER,

    GDI_MEM_TYPE_END_OF_ENUM
} gdi_mem_type_enum;

typedef void* (*gdi_mem_allocate_func)(kal_uint32 size, gdi_mem_type_enum type, kal_uint32 alignment);
typedef kal_bool (*gdi_mem_free_func)(void *mem);


#endif /* _GDI_DATATYPE_H_ */ 


