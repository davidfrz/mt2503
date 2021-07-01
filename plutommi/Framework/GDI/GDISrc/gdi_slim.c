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
 * gdc_main.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is entry point of GDI Command Executor
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/* KAL - RTOS Abstraction Layer */
#include "MMI_features.h"
#include "kal_release.h"

/* Task Message Communication */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* local/peer struct */
#include "stack_ltlcom.h"

#include "stack_config.h"
#include "task_main_func.h"
#include "syscomp_config.h"

#include "gdi_internal.h"
#include "gdc_include.h"

#include "mmi_frm_gprot.h"

#ifdef __MMI_TVOUT__
#include "mdi_datatype.h"
#include "mdi_tv.h"
#endif

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "fs_type.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "mmi_frm_events_gprot.h"
#include "MMIDataType.h"
#include "FileMgrSrvGProt.h"

#include "gdi_include.h"
#include "gdi_datatype.h"
#include "gdi_const.h"
#include "gdi_ipp.h"
#include "gdi_features.h"
#include "gdi_mutex.h"
#include "gdi_primitive.h"
#include "gdi_animate.h"
#include "gdi_imgdec.h"
#include "gd_include.h"

#if defined(__MMI_UI_DISPLAY_LEVEL_NONE__)
#define GDI_MUTEX_GUARD_PATTERN 0x87654321

#if defined(GDI_USE_RGB565_TO_SHOW_BW)
#define GD_FUNC_1(NAME)         (NAME##_func) NAME##_1 //gd_null_pointer_function
#else
#define GD_FUNC_1(NAME)         (NAME##_func) gd_null_pointer_function
#endif
#define GD_FUNC_8(NAME)         (NAME##_func) NAME##_8
#define GD_FUNC_16(NAME)        (NAME##_func) NAME##_16
#define GD_FUNC_24(NAME)        (NAME##_func) NAME##_24
#define GD_FUNC_32(NAME)        (NAME##_func) NAME##_32
#define GD_FUNC_32PARGB(NAME)   (NAME##_func) NAME##_32PARGB
#define GD_FUNC_UYVY422(NAME)   (NAME##_func) gd_null_pointer_function
#define GD_FUNC_A8(NAME)        (NAME##_func) NAME##_8


gdi_layer_struct GDI_LAYERS[GDI_LAYER_TOTAL_LAYER_COUNT];
gd_color_to_rgb_func gdi_act_color_to_rgb;
gdi_layer_struct *gdi_act_layer;
gdi_lcd_layer_struct *gdi_act_layer_info;
kal_eventgrpid gdi_event_group;
gdi_lcd_layer_struct gdi_layer_info[GDI_LAYER_TOTAL_LAYER_COUNT]; 
gdi_mutex_struct gdi_mutex = {GDI_MUTEX_GUARD_PATTERN,0,NULL,0,GDI_MUTEX_GUARD_PATTERN};
gdi_lcd_cntx_struct *GDI_LCD;
gd_color_from_rgb_func gdi_act_color_from_rgb;
gd_put_pixel_func gdi_act_put_pixel;
gd_get_pixel_func gdi_act_get_pixel;
void gd_color_to_rgb_main(U32 *A, U32 *R, U32 *G, U32 *B, gdi_color c);
void gd_color_to_rgb_sub(U32 *A, U32 *R, U32 *G, U32 *B, gdi_color c);

const gd_color_to_rgb_func gd_color_to_rgb[] = 
{
    GD_FUNC_1       (gd_color_to_rgb),          /* 1 */
    GD_FUNC_8       (gd_color_to_rgb),          /* 8 */
    GD_FUNC_16      (gd_color_to_rgb),          /* 16 */
    GD_FUNC_24      (gd_color_to_rgb),          /* 24 */
    GD_FUNC_32      (gd_color_to_rgb),          /* 32 */
    GD_FUNC_32PARGB (gd_color_to_rgb),          /* 32PARGB */
    GD_FUNC_UYVY422 (gd_color_to_rgb),          /* UYVY422 */
    GD_FUNC_A8      (gd_color_to_rgb),
#if defined(__MMI_LAUNCHER_APP_LIST__) || defined(__MMI_VUI_ENGINE__)
    GD_FUNC_PARGB6666(gd_color_to_rgb),
#endif
    (gd_color_to_rgb_func)gd_color_to_rgb_main, /* main */
    (gd_color_to_rgb_func)gd_color_to_rgb_sub   /* sub */
};

void gd_color_to_rgb_main(U32 *A, U32 *R, U32 *G, U32 *B, gdi_color c)
{

}

void gd_color_to_rgb_sub(U32 *A, U32 *R, U32 *G, U32 *B, gdi_color c)
{

}

void gd_null_pointer_function(void)
{
    
}

kal_bool gdc_create(comptask_handler_struct **handle)
{
	return KAL_TRUE;
}

kal_bool gdd_create(comptask_handler_struct **handle)
{
	return KAL_TRUE;
}

void gdi_layer_govl_nb_callback_ind_handler(void)
{

}

GDI_RESULT gdi_layer_set_hw_update_layer(gdi_handle layer_handle, kal_bool is_hw_layer)
{
	return 0;
}

gdi_color gdi_layer_get_background(void)
{
	return 0;
}

GDI_RESULT gdi_layer_set_rotate_nb_concurrent(gdi_handle layer_handle, U8 rotate_value)
{
	return 0;
}


void gdi_init(void)
{

}

GDI_RESULT gdi_layer_blt_ext(
            gdi_handle handle0, 
            gdi_handle handle1, 
            gdi_handle handle2, 
            gdi_handle handle3,
        #ifdef GDI_6_LAYERS
            gdi_handle handle4,
            gdi_handle handle5,
        #endif
            S32 x1, 
            S32 y1, 
            S32 x2, 
            S32 y2)
{
	return 0;
}            

void gdi_fast_mutex_lock(void)
{

}

void gdi_fast_mutex_unlock(void)
{

}

GDI_RESULT gdi_image_encode_layer_to_jpeg(gdi_handle layer_handle, PS8 file_name)
{
	return 0;
}

GDI_RESULT gdi_layer_create_cf_using_outside_memory(
            gdi_color_format cf,
            S32 offset_x,
            S32 offset_y,
            S32 width,
            S32 height,
            gdi_handle *handle_ptr,
            U8 *outside_memory,
            S32 outside_memory_size)
{
	return 0;
}            

gdi_screen_shot_info_struct* gdi_screen_shot_capture(
                				gdi_handle lcd_handle,
                				U32 flag)
{
	return NULL;
}                				

GDI_RESULT gdi_anim_stop_all(void)
{
	return 0;
}

GDI_RESULT gdi_image_draw_id(S32 offset_x, S32 offset_y, U16 image_id)
{
	return 0;
}

GDI_RESULT gdi_image_get_dimension_id(U16 image_id, S32 *width, S32 *height)
{
	return 0;
}

GDI_RESULT gdi_image_jpeg_draw_internal(
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
            BOOL retry_thumbnail,
            U8 *dest_buf,
            S32 dest_buf_size,
            S32 *decoded_image_width,
            gdi_color_format dest_buf_cf)
{
	return 0;
}            

GDI_RESULT gdi_image_jpeg_get_dimension(U8 *jpeg_src, U32 size, S32 *width, S32 *height)
{
	return 0;
}

GDI_RESULT gdi_image_jpeg_get_dimension_file(S8 *image_name, S32 *width, S32 *height)
{
	return 0;
}

void gdi_image_util_fit_bbox(
        S32 bbox_width,
        S32 bbox_height,
        S32 src_width,
        S32 src_height,
        S32 *offset_x,
        S32 *offset_y,
        S32 *dest_width,
        S32 *dest_height)
{

}        

GDI_RESULT gdi_layer_blt_previous(S32 x1, S32 y1, S32 x2, S32 y2)
{
	return 0;
}

GDI_RESULT gdi_layer_clear(gdi_color bg_color)
{
	return 0;
}

GDI_RESULT gdi_layer_create(
             S32 offset_x,
             S32 offset_y,
             S32 width,
             S32 height,
             gdi_handle *handle_ptr)
{
	return 0;
}             

GDI_RESULT gdi_layer_flatten_to_base(
             gdi_handle src_handle0, 
             gdi_handle src_handle1, 
             gdi_handle src_handle2,
             gdi_handle src_handle3)
{
	return 0;
}             

GDI_RESULT gdi_layer_free(gdi_handle handle)
{
	return 0;
}

GDI_RESULT gdi_layer_get_base_handle(gdi_handle *handle_ptr)
{
	return 0;
}

GDI_RESULT gdi_layer_get_buffer_ptr(U8 **buf_ptr)
{
	return 0;
}

U8 gdi_layer_get_rotate(void)
{
	return 0;
}

void gdi_layer_lock_frame_buffer(void)
{

}

GDI_RESULT gdi_layer_multi_layer_disable(void)
{
	return 0;
}

GDI_RESULT gdi_layer_multi_layer_enable(void)
{
	return 0;
}

void gdi_layer_pop_and_restore_active(void)
{
	
}

void gdi_layer_push_and_set_active(gdi_handle handle)
{
	
}

void gdi_layer_reset_clip(void)
{
	
}

void gdi_layer_resize(S32 width, S32 height)
{

}

void gdi_layer_set_active(gdi_handle handle)
{
	
}

BOOL gdi_layer_set_background(gdi_color color)
{
	return FALSE;
}

GDI_RESULT gdi_layer_set_blt_layer(
             gdi_handle handle0, 
             gdi_handle handle1, 
             gdi_handle handle2,
             gdi_handle handle3)
{
	return 0;
}             

void gdi_layer_set_clip(S32 x1, S32 y1, S32 x2, S32 y2)
{

}

GDI_RESULT gdi_layer_set_position(S32 offset_x, S32 offset_y)
{
	return 0;
}

void gdi_layer_set_rotate(U8 rotate_value)
{
}

GDI_RESULT gdi_layer_set_source_key(BOOL source_key_enable, gdi_color source_key_value)
{
	return 0;
}

GDI_RESULT gdi_layer_toggle_double(void)
{
	return 0;
}

void gdi_layer_unlock_frame_buffer(void)
{

}

GDI_RESULT gdi_lcd_blt(gdi_handle handle0, gdi_handle handle1, gdi_handle handle2, gdi_handle handle3)
{
	return 0;
}

void gdi_lcd_set_rotate_by_layer(BOOL rotate_by_layer)
{

}

kal_bool gdi_lcd_set_te_ctrl(kal_bool te_ctrl)
{
	return FALSE;
}

gdi_handle gdi_set_alpha_blending_source_layer(gdi_handle src_layer_handle)
{
	return NULL;
}

void gdi_util_fit_box(
        S32 mode,
        S32 bbox_width,
        S32 bbox_height,
        S32 src_width,
        S32 src_height,
        S32 *offset_x,
        S32 *offset_y,
        S32 *dest_width,
        S32 *dest_height)
{

}        

GDI_RESULT gdi_anim_stop(gdi_handle serial_handle)
{
	return 0;
}

GDI_RESULT gdi_image_draw_resized_id(
                    S32 x,
                    S32 y,
                    S32 w,
                    S32 h,
                    U16 image_id)
{
	return 0;
}                    

GDI_RESULT gdi_layer_flatten_previous_to_base(void)
{
	return 0;
}

int gdi_layer_get_bit_per_pixel(void)
{
	return 0;
}

GDI_RESULT gdi_layer_get_dimension(S32 *width, S32 *height)
{
	return 0;
}

GDI_RESULT gdi_layer_get_position(S32 *offset_x, S32 *offset_y)
{
	return 0;
}

void gdi_layer_pop_clip(void)
{

}

void gdi_layer_push_and_set_clip(S32 x1, S32 y1, S32 x2, S32 y2)
{

}

GDI_RESULT gdi_layer_set_color_format(gdi_color_format cf)
{
	return 0;
}

BOOL gdi_lcd_get_rotate_by_layer(void)
{
	return FALSE;
}

void gdi_lcd_set_rotate(U8 rotate_value)
{

}

void gdi_pop_and_restore_alpha_blending_source_layer(void)
{

}

void gdi_push_and_set_alpha_blending_source_layer(gdi_handle handle)
{

}

void gdi_draw_solid_circle(S32 x, S32 y, S32 r, gdi_color circle_color)
{

}

GDI_RESULT gdi_layer_create_cf_double_using_outside_memory(
            gdi_color_format cf,
            S32 offset_x,
            S32 offset_y,
            S32 width,
            S32 height,
            gdi_handle *handle_ptr,
            U8 *outside_memory1,
            S32 outside_memory_size_1,
            U8 *outside_memory2,
            S32 outside_memory_size_2)
{
	return 0;
}            

BOOL gdi_layer_is_double(gdi_handle layer)
{
	return FALSE;
}

void gdi_draw_frame_rect(	S32 x1, S32 y1, S32 x2, S32 y2, gdi_color	rect_color, gdi_color	frame_color, S32			frame_width)
{

}

GDI_RESULT gdi_image_cache_bmp_draw(S32 offset_x, S32 offset_y, gdi_image_cache_bmp_struct *bmp_ptr)
{
	return 0;
}

GDI_RESULT gdi_image_cache_bmp_get(S32 x1, S32 y1, S32 x2, S32 y2, gdi_image_cache_bmp_struct *bmp_ptr)
{
	return 0;
}

GDI_RESULT gdi_image_draw(
             S32 x,
             S32 y,
             U8 *img_src)
{
	return 0;
}             

GDI_RESULT gdi_image_draw_resized(
                    S32 x,
                    S32 y,
                    S32 w,
                    S32 h,
                    U8 *img_src)
{
	return 0;
}                    

GDI_RESULT gdi_image_get_dimension(U8 *image_ptr, S32 *width, S32 *height)
{
	return 0;
}

void gdi_layer_get_active(gdi_handle *handle_ptr)
{
	
}

GDI_RESULT gdi_image_get_dimension_file(S8 *image_name, S32 *width, S32 *height)
{
	return 0;
}

U16 gdi_image_get_type_from_file(S8 *file_name)
{
	return 0;
}

void gdc_imgdec_callback_dispatch(void *data, U8 scr_mod)
{

}

void gdc_msg_dispatch(void *data, U8 scr_mod)
{

}

void gdi_anim_mmi_init(void)
{

}

S32 gdi_bits_per_pixel(gdi_color_format cf)
{
	return 0;
}

void gdi_draw_line(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color line_color)
{

}

gdi_color_format gdi_get_color_format(S32 bits)
{
	return 0;
}

void gdi_layer_get_clip(S32 *x1, S32 *y1, S32 *x2, S32 *y2)
{
}

void gdi_mutex_init(gdi_mutex_struct *m)
{

}

GDI_RESULT gdi_layer_flatten(
             gdi_handle handle0, 
             gdi_handle handle1, 
             gdi_handle handle2, 
             gdi_handle handle3)
{
	return 0;
}             

GDI_RESULT gdi_layer_set_opacity(BOOL opacity_enable, U8 opacity_value)
{
	return 0;
}

void gdi_lcd_freeze(BOOL is_freeze)
{

}

void gdi_color_engine_custom_off(void)
{

}

void gdi_color_engine_custom_on(void)
{

}

GDI_RESULT gdi_lcd_repaint_all(void)
{
	return 0;
}

void gdi_lcd_set_high_priority_freeze(BOOL is_freeze)
{

}

gdi_cabc_mode_enum gdi_cabc_get_mode(void)
{
	return 0;
}


void gdi_cabc_set_mode(gdi_cabc_mode_enum mode)
{
}

U16 gdi_image_get_type_from_mem(PS8 ptr)
{
	return 0;
}

gdi_result gdi_layer_get_actual_rotate_value(gdi_handle layer_handle, kal_uint8 *layer_actual_rotate_value)
{
	return 0;
}

gdi_result gdi_layer_get_blt_layer_flag(U32 *blt_layer_flag)
{
	return 0;
}

GDI_RESULT gdi_layer_get_color_format(gdi_color_format *cf)
{
	return 0;
}

GDI_RESULT gdi_layer_get_layer_element(U32 blt_layer_index, kal_uint32 *layer_element, kal_uint32 *blt_ctx, kal_uint32 *blt_dev)
{
	return 0;
}

GDI_RESULT gdi_layer_set_blt_layer_previous(void)
{
	return 0;
}

GDI_RESULT gdi_layer_set_hw_update_layer_ext(gdi_handle layer_handle, kal_bool is_hw_layer, char* file_p, long line_p)
{
	return 0;
}

void gdi_lcd_get_dimension(S32 *width, S32 *height)
{

}

void gdi_lcd_lock_mutex(void)
{

}

void gdi_lcd_set_active(gdi_handle lcd_handle)
{

}

GDI_RESULT gdi_lcd_set_hw_update(kal_bool hw_update)
{
	return 0;
}

void gdi_lcd_unlock_mutex(void)
{

}

void gdi_waiting_blt_finish(void)
{

}

GDI_RESULT gdi_layer_create_cf(
            gdi_color_format cf,
            S32 offset_x,
            S32 offset_y,
            S32 width,
            S32 height,
            gdi_handle *handle_ptr)
{
	return 0;
}            

void gdi_lcd_get_active(gdi_handle *lcd_handle_ptr)
{

}

U8 gdi_lcd_get_rotate(void)
{
	return 0;
}

GDI_RESULT gdi_util_rotator(
            GDI_ROTATOR_ENUM rotator_type,
            U8 rotate_angle,
            U8* src_ptr,
            U8  src_cf,
            U32 src_pitch,
            U32 src_height,
            S32 src_x,
            S32 src_y,
            U32 src_w,
            U32 src_h,
            U8* dst_ptr,
            U8  dst_cf, 
            U32 dst_pitch,
            U32 dst_height,
            S32 dst_x,
            S32 dst_y,
            U32 dst_w,
            U32 dst_h)
{
	return 0;
}            

GDI_RESULT gdi_layer_is_hw_update_layer(gdi_handle layer_handle, kal_bool *is_hw_layer)
{
	return 0;
}

GDI_RESULT gdi_image_bmp_get_dimension_handler(U32 flag, U8 *data_ptr, U32 img_size, S32 *width, S32 *height)
{
	return 0;
}

MMI_BOOL gdi_image_check_image_file_valid(S8 *filepath)
{
	return MMI_FALSE;
}

GDI_RESULT gdi_image_codec_draw(
            gdi_image_src_enum src_type,
            U8 *img_src,
            U8 img_type,
            S32 img_size,
            S32 x,
            S32 y,
            S32 w,
            S32 h,
            U32 flag,
            U32 frame_pos)
{
	return 0;
}            

S32 gdi_image_get_buf_len(U8* res_src)
{
	return 0;
}

U16 gdi_image_get_buf_type(U8 * image_ptr)
{
	return 0;
}

GDI_RESULT gdi_image_gif_get_dimension(U8 *GIF_src, S32 *width, S32 *height)
{
	return 0;
}

GDI_RESULT gdi_image_gif_get_frame_count(U8 *GIF_src, U32 size, S32 *frame_count)
{
	return 0;
}

GDI_RESULT gdi_image_gif_get_frame_count_file(const S8 *filename, S32 *frame_count)
{
	return 0;
}

void gdi_image_gif_reset(void)
{

}

GDI_RESULT gdi_image_wbmp_get_dimension_handler(U32 flag, U8 *data_ptr, U32 img_size, S32 *width, S32 *height)
{
	return 0;
}

void gdi_image_cache_reset(void)
{

}

void gdi_draw_solid_rect(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color rect_color)
{

}

GDI_RESULT gdi_bitblt_resized(
                    gdi_handle src_layer_handle, 
                    S32 sx1,
                    S32 sy1,
                    S32 sx2,
                    S32 sy2,
                    S32 dx1,
                    S32 dy1,
                    S32 dx2,
                    S32 dy2)
{
	return 0;
}                    

void gdi_image_clear_work_buffer(void)
{

}

GDI_RESULT gdi_image_draw_file(
             S32 x,
             S32 y,
             S8 *img_name)
{
	return 0;
}             

GDI_RESULT gdi_image_gif_draw_file(S32 ox, S32 oy, const S8 *filename, U16 frame_number)
{
	return 0;
}

void gdi_layer_push_clip(void)
{

}

gdi_handle gdi_anim_nb_draw_resized_file(
                    S32 x,
                    S32 y,
                    S32 w,
                    S32 h,
                    U8 *img_name)
{
	return NULL;
}                    

GDI_RESULT gdi_anim_stop_all_by_layer(gdi_handle layer)
{
	return 0;
}

void gdi_color_engine_close()
{

}

void gdi_color_engine_disable()
{

}

void gdi_color_engine_enable()
{

}

void gdi_color_engine_open()
{

}

GDI_RESULT gdi_image_gif_check_animation_file(const S8 *filename, MMI_BOOL *is_anim)
{
	return 0;
}

gdi_handle gdi_image_nb_draw_internal(
                            gdi_image_src_enum src_type,
                            U8 *img_src,
                            U8 img_type,
                            S32 img_size,
                            S32 x,
                            S32 y,
                            S32 w,
                            S32 h,
                            U32 img_flag,
                            U32 frame_pos,
                            gdc_job_flag_enum job_flag)
{
	return NULL;
}                            

GDI_RESULT gdi_image_nb_stop(gdi_handle handle)
{
	return 0;
}

GDI_RESULT gdi_layer_blt_previous_nb_concurrent(S32 x1, S32 y1, S32 x2, S32 y2)
{
	return 0;
}

GDI_RESULT gdi_layer_clear_nb_concurrent(gdi_handle layer_handle, gdi_color bg_color)
{
	return 0;
}

GDI_RESULT gdi_layer_get_blt_layer_ext(
            gdi_handle *handle0, 
            gdi_handle *handle1, 
            gdi_handle *handle2,
            gdi_handle *handle3
        #ifdef GDI_6_LAYERS
            ,gdi_handle *handle4
            ,gdi_handle *handle5
        #endif
            )
{
	return 0;
}            

GDI_RESULT gdi_layer_get_dimension_nb_concurrent(gdi_handle layer_handle, S32 *width, S32 *height)
{
	return 0;
}

GDI_RESULT gdi_layer_resize_nb_concurrent(gdi_handle layer_handle, S32 width, S32 height)
{
	return 0;
}

GDI_RESULT gdi_layer_set_background_nb_concurrent(gdi_handle layer_handle, gdi_color color)
{
	return 0;
}

GDI_RESULT gdi_layer_set_blt_layer_nb_concurrent_ext(
            gdi_handle handle0, 
            gdi_handle handle1, 
            gdi_handle handle2, 
            gdi_handle handle3
        #ifdef GDI_6_LAYERS
            ,gdi_handle handle4
            ,gdi_handle handle5
        #endif
            )
{
	return 0;
}            

GDI_RESULT gdi_layer_set_position_nb_concurrent(gdi_handle layer_handle, S32 offset_x, S32 offset_y)
{
	return 0;
}

GDI_RESULT gdi_layer_set_source_key_nb_concurrent(
            gdi_handle layer_handle, 
            BOOL source_key_enable, 
            gdi_color source_key_value)
{
	return 0;
}            

void gdi_nb_set_anim_after_each_frame_callback(void (*callback)(GDI_RESULT result))
{

}

void gdi_nb_set_anim_before_frame_callback(void (*callback)(GDI_RESULT result,gdi_handle handle))
{

}

void gdi_nb_set_anim_handle_query_callback(void (*callback)(gdi_handle anim_handle,gdi_handle job_handle))
{

}

void gdi_nb_set_anim_last_frame_callback(void (*callback)(GDI_RESULT result))
{

}

void gdi_nb_set_blt(BOOL is_blt,BOOL is_progress)
{

}

void gdi_nb_set_done_callback(void (*callback)(GDI_RESULT result,gdi_handle handle))
{

}

mmi_ret gdi_anim_on_protocol_handler_reset(mmi_event_struct *evt)
{
	return 0;
}

MMI_RET gdi_image_9slice_handle_scrn_enter_proc(mmi_event_struct *evt)
{
	return 0;
}

GDI_RESULT gdi_layer_get_source_key(BOOL *source_key_enable, gdi_color *source_key_value)
{
	return 0;
}

void gdi_draw_arc(S32 circle_x, S32 circle_y, S32 circle_r, int startAngle, int angleExtent, gdi_color color)
{

}

void gdi_draw_arc_ext(S32 circle_x, S32 circle_y, S32 circle_r, S32 width, int startAngle, int angleExtent, gdi_color color)
{

}

void gdi_draw_ring(S32 circle_x, S32 circle_y, S32 circle_r, S32 width, int startAngle, int angleExtent, gdi_color sColor, gdi_color mColor, gdi_color eColor)
{
}

void gdi_draw_font_by_abm(
                S32 x, 
                S32 y, 
                gdi_color color, 
                U8 *font_data, 
                S32 char_width, 
                S32 char_height)
{

}                

void gdi_draw_gradient_rect(
        S32 x1,
        S32 y1,
        S32 x2,
        S32 y2,
        gdi_color rect_color_start,
        gdi_color rect_color_end,
        gdi_color frame_color,
        S32 frame_width,
        gdi_gradient_rect_style_enum style)
{

}        

void gdi_draw_line_style(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color line_color, U8 cycle, const U8 *bitvalues)
{

}

void gdi_draw_point(S32 x, S32 y, gdi_color pixel_color)
{

}

void gdi_draw_polygon(gdi_point2D_struct point[], U32 point_num, gdi_color color)
{

}

void gdi_draw_rect(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color frame_color)
{

}

void gdi_draw_solid_arc(S32 circle_x, S32 circle_y, S32 circle_r, int startAngle, int angleExtent, gdi_color color)
{

}

GDI_RESULT gdi_draw_solid_polygon(
            gdi_point2D_struct point[], 
            U32 point_num, 
            gdi_color color)
{
	return 0;
}            

void gdi_get_alpha_blending_source_layer(gdi_handle *src_layer_handle)
{

}

GDI_RESULT gdi_image_draw_frames(
             S32 x,
             S32 y,
             U8 *img_src,
             U32 frame_pos)
{
	return 0;
}             

GDI_RESULT gdi_image_draw_mem(
             S32 x,
             S32 y,
             U8 *img_src,
             U8 img_type,
             S32 img_size)
{
	return 0;
}             

GDI_RESULT gdi_image_draw_resized_file(
             S32 x,
             S32 y,
             S32 w,
             S32 h,
             S8 *img_name)
{
	return 0;
}             

GDI_RESULT gdi_image_get_dimension_mem(U8 img_type,U8 *img_ptr,S32 img_size,S32 *width, S32 *height)
{
	return 0;
}

GDI_RESULT gdi_image_get_frame_count_mem(
            U8  image_type,
            U8  *image_ptr,
            S32 image_size,
            S32 *frame_count)
{
	return 0;
}            

GDI_RESULT gdi_layer_blt_with_flag(
            gdi_handle handle0, 
            gdi_handle handle1, 
            gdi_handle handle2, 
            gdi_handle handle3,
            kal_int32 x1, 
            kal_int32 y1, 
            kal_int32 x2, 
            kal_int32 y2,
            gdi_layer_blt_flag_bit_set flag,
            const gdi_callback_struct *nb_finish_callback)
{
	return 0;
}            

GDI_RESULT gdi_layer_flatten_ext(
            gdi_handle handle0, 
            gdi_handle handle1, 
            gdi_handle handle2, 
            gdi_handle handle3
        #ifdef GDI_6_LAYERS
            ,gdi_handle handle4
            ,gdi_handle handle5
        #endif
            )
{
	return 0;
}            

GDI_RESULT gdi_layer_flatten_with_clipping_ext(
            gdi_handle handle0, 
            gdi_handle handle1, 
            gdi_handle handle2,
            gdi_handle handle3
        #ifdef GDI_6_LAYERS
            ,gdi_handle handle4
            ,gdi_handle handle5
        #endif
            )
{
	return 0;
}            

GDI_RESULT gdi_layer_set_blt_layer_ext(
            gdi_handle handle0, 
            gdi_handle handle1, 
            gdi_handle handle2, 
            gdi_handle handle3
        #ifdef GDI_6_LAYERS
            ,gdi_handle handle4
            ,gdi_handle handle5
        #endif
            )
{
	return 0;
}            

S32 gdi_sizeof_pixels(gdi_color_format cf, S32 width, S32 height)
{
	return 0;
}

GDI_RESULT gdi_image_jpeg_is_progressive(S8 *filename, MMI_BOOL *is_progressive)
{
	return 0;
}

GDI_RESULT gdi_anim_get_min_delay_time(BOOL *enable_min_delay_time, U32 *min_delay_time)
{
	return 0;
}

GDI_RESULT gdi_anim_set_min_delay_time(BOOL enable_min_delay_time, U32 min_delay_time)
{
	return 0;
}

void gd_color_to_rgb_8(U32 *A, U32 *R, U32 *G, U32 *B, gdi_color c)
{

}

void gd_color_to_rgb_16(U32 *A, U32 *R, U32 *G, U32 *B, gdi_color c)
{

}

void gd_color_to_rgb_24(U32 *A, U32 *R, U32 *G, U32 *B, gdi_color c)
{

}

void gd_color_to_rgb_32(U32 *A, U32 *R, U32 *G, U32 *B, gdi_color c)
{

}

void gd_color_to_rgb_32PARGB(U32 *A, U32 *R, U32 *G, U32 *B, gdi_color c)
{

}

void gdi_2d_fill_rect_callback_ind_handler(void)
{

}

kal_bool gdi_2d_linear_transform_hw_support(void)
{
	return KAL_FALSE;
}

gdi_result gdi_2d_linear_transfrom(   
            float *matrix,
            gdi_handle src_layer_handle,
            kal_int32 src_rect_x,
            kal_int32 src_rect_y,
            kal_int32 src_rect_w,
            kal_int32 src_rect_h,
            kal_int32 dst_rect_x,
            kal_int32 dst_rect_y,
            kal_int32 dst_rect_w,
            kal_int32 dst_rect_h,
            GDI_LT_SRC_KEY_EDGE_FILTER_ENUM edge_filter_mode,
            kal_uint32 edge_filter_color,
            GDI_LT_SAMPLE_MODE_ENUM sample_mode,
            kal_uint32 flag)
{

	return -1;
}            

#endif/*#if defined(__MMI_UI_DISPLAY_LEVEL_NONE__)*/
