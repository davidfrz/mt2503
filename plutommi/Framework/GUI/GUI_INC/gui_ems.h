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
 *   gui_ems.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   EMS editor - UI component
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/**********************************************************************************
   Filename:      gui_ems.h
   Author:        manju
   Date Created:  March-25-2003
   Contains:      EMS input box
**********************************************************************************/

#ifndef __GUI_EMS_H__
#define __GUI_EMS_H__

//#include "gui.h"
#include "gui_scrollbars.h"
#include "gui_inputs.h"
/* MTK Leo add,20040318, for new simulator */
#include "gui_theme_struct.h"
/* MTK Leo end */

#include "Gsm7BitNationalLang.h"

    #include "gui_config.h"
    #include "MMIDataType.h"
    #include "CustThemesRes.h"
    #include "gui_data_types.h"
    #include "kal_general_types.h"
    #include "mmi_frm_input_gprot.h"
    #include "MMI_features.h"

#ifdef UI_EMS_SUPPORT

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    /* EMS UI element structures and functions   */

#define UI_EMS_INPUT_BOX_STATE_NORMAL              0x00000000
#define UI_EMS_INPUT_BOX_STATE_DISABLED               0x00000001
#define UI_EMS_INPUT_BOX_STATE_SELECTED               0x00000002
#define UI_EMS_INPUT_BOX_STATE_MULTITAP               0x00000004
#define UI_EMS_INPUT_BOX_DISABLE_BACKGROUND           0x00000008
#define UI_EMS_INPUT_BOX_DISABLE_SCROLLBAR            0x00000010
#define UI_EMS_INPUT_BOX_DISABLE_DRAW              0x00000020
#define UI_EMS_INPUT_BOX_DISABLE_CURSOR_DRAW       0x00000040
#define UI_EMS_INPUT_BOX_OVERWRITE_MODE               0x00000080
#define UI_EMS_INPUT_BOX_CURRENT_ALIGN_LEFT           0x00000100
#define UI_EMS_INPUT_BOX_CURRENT_ALIGN_RIGHT       0x00000200
#define UI_EMS_INPUT_BOX_CURRENT_ALIGN_CENTER         0x00000400
#define UI_EMS_INPUT_BOX_NEWLINE_DRAW              0x00000800
#define UI_EMS_INPUT_BOX_PREVIOUS_LINE             0x00001000
#define UI_EMS_INPUT_BOX_NEXT_LINE                 0x00002000
#define UI_EMS_INPUT_BOX_AUTO_DISABLE_SCROLLBAR       0x00004000
#define UI_EMS_INPUT_BOX_VIEW_MODE                 0x00008000
#define UI_EMS_INPUT_BOX_WORD_HIGHLIGHT               0x00010000
#define UI_EMS_INPUT_BOX_DISPLAY_HEADER               0x00020000
#define UI_EMS_INPUT_BOX_DISABLE_TONE              0x00040000
#define UI_EMS_INPUT_BOX_PREVIOUS_OBJECT           0x00080000
#define UI_EMS_INPUT_BOX_NEXT_OBJECT               0x00100000
#define UI_EMS_INPUT_BOX_CHECK_GSM_EXTENDED           0x00200000
#define  UI_EMS_INPUT_BOX_INCLUDE_INFO_AREA           0x00800000        /* Pixtel - Gurinder - 3/14/2004 - Editor With BG Image */
#define UI_EMS_INPUT_BOX_TRANSPARENT_BACKGROUND    0x01000000   /* 070405 Calvin added */
    /* START PMT NEERAJ 20050916 */
#define UI_EMS_INPUT_BOX_ALL_LINE_DRAW             0x02000000
    /* END PMT NEERAJ 20050916 */
#define UI_EMS_INPUT_BOX_INPUT_METHOD_MODE             0x04000000
#define UI_EMS_INPUT_BOX_AUTO_DISPLAY_REMAINING_COUNTER   0x08000000  

    extern UI_EMS_input_box_theme *current_EMS_input_box_theme;

#define EMS_EURO_SYMBOL_ORINGINAL_CHARACTER        0x20AC
#define EMS_EURO_SYMBOL_GSM_CHARACTER              0xA2
//#if(!UI_DISABLE_EMS_INPUT_BOX)

#define EMS_BYTE_ORDER_BIG_ENDIAN      0
#define EMS_USE_DCS                 1

    /* Include files for Pluto libraries      */
    /* MTK added for compile issue */
//#include "mmi_platform.h"
//#include "smsal_l4c_enum.h"
    /* MTK end */
//#include "kal_non_specific_general_types.h"
//#include "l4c_common_enum.h"
//#include "mcd_l4_common.h"
//#include "l4c_aux_struct.h"
//#include "l4c2smsal_struct.h"
#include "ems.h"
#include "Customer_ps_inc.h"

#ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
#define __UI_EMS_HIGHLIGHT_LIST_SUPPORT__
#endif

#if defined(__MMI_TOUCH_SCREEN__) // || defined(__MMI_HANDWRITING_PAD__)
//#include "kal_non_specific_general_types.h"
//#include "mmi_frm_gprot.h"

    typedef enum
    {
        GUI_EMS_INPUT_BOX_PEN_NONE,
        GUI_EMS_INPUT_BOX_PEN_TEXT_DOWN,
        GUI_EMS_INPUT_BOX_PEN_TEXT_UP,
        GUI_EMS_INPUT_BOX_PEN_SCROLL_BAR,
        GUI_EMS_INPUT_BOX_PEN_CONTROL_AREA,
        GUI_EMS_INPUT_BOX_PEN_MAX
    } gui_EMS_input_box_pen_enum;

    typedef struct
    {
        U8 pen_inside;
        U8 pen_on_scroll_bar;
    } gui_EMS_input_box_pen_state_struct;
#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 

#define  MAX_EMS_EDITOR_LINES       MMI_SMS_MAX_MSG_SEG * 153

#ifdef __UI_EMS_HIGHLIGHT_LIST_SUPPORT__
    typedef enum
    {
        EMS_HILITE_NONE,
        EMS_HILITE_URL,
        EMS_HILITE_EMAIL_ADDR,
        EMS_HILITE_USSD,
        EMS_HILITE_NUMBER,
        EMS_HILITE_OBJECT,
        EMS_HILITE_END
	} EMS_HILITE_TYPE;

    typedef struct
    {
        EMS_HILITE_TYPE hilite_type;
        EMSObject *object;
        U16   offset_to_text;
        U16   hilite_length;
	} EMS_HILITE;
#endif /* __UI_EMS_HIGHLIGHT_LIST_SUPPORT__ */

    typedef struct _UI_EMS_input_box
    {
        S32 x, y;
        S32 width, height;
        UI_filled_area *normal_filler;
        UI_filled_area *disabled_filler;
        UI_filled_area *selected_filler;
        color normal_text_color;
        color selected_text_color;
        color selection_color;
        color cursor_color;
        color boundary_color;               /* Pixtel - Gurinder - 3/14/2004 - Editor With BG Image */
        U32 flags;
        gui_input_box_state_enum state;
        vertical_scrollbar vbar;
        EMSData *data;
        UI_string_type default_text;
        EMSTextFormat text_format;          /* For editing */
        EMSPosition start_position;         /* Temporary   */
        EMSPosition end_position;           /* Temporary   */
        EMSPosition previous_line_position; /* Temporary   */
        /* slim_2_2 */ //EMSPosition next_line_position;     /* Temporary   */
        EMSPosition input_mode_position;    /* Temporary   */
        /* This variable is required as we need information from which
           position the input started for multitap. This change was implemented while
           imlpementing multigraph support for editor */
        EMSPosition input_start_position;
        /* slim_2_2 */ //S32 previous_line_object_count;     /* Temporary   */
        /* slim_2_2 */ ///S32 next_line_object_count;         /* Temporary   */
        S32 cursor_ax, cursor_ay;
        S32 cursor_line_height;
        S32 display_y;
        S32 display_height;
        S32 last_display_height;
        /* slim_2_2 */ //S32 cursor_line_position;
        S32 UCS2_count;
        S32 GSM_ext_count;
        S32 object_count;
        S32 available_length;
        /* Highlight coordinate */
        S16 hilite_s_x, hilite_s_y, hilite_e_x, hilite_e_y;
        void (*overflow_callback) (void);
        void (*change_callback) (void);
        EMSPosition highlight_start_position;
        EMSPosition highlight_end_position;
        void (*display_header) (S32 x1, S32 y1, S32 x2, S32 y2);
          S32(*measure_header) (void);
        MMI_BOOL (*pen_control_area_callback)(gui_input_box_area_enum area_type, mmi_pen_event_type_enum pen_event, S32 x, S32 y);
        S32 header_height;
        S32 n_lines;
        S32 current_line;
        S32 first_displayed_line;
        S32 last_displayed_line;
        S32 saved_cursor_ax;
        color underline_color;
        color strikethrough_color;
        color paragraph_color;
    #if defined(__MMI_TOUCH_SCREEN__) //|| defined(__MMI_HANDWRITING_PAD__)
        S16 pen_scroll_delay_time;
        S16 pen_scroll_after_delay;
        gui_EMS_input_box_pen_state_struct pen_state;
    #endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 
        
    #ifdef GUI_INPUT_BOX_CACHE_SUPPORT
        S32 (*cache_begin_callback)(struct _UI_EMS_input_box *b, void* param);
        S32 (*cache_line_ready_callback)(struct _UI_EMS_input_box *b, void* param);
        S32 cache_update_type;
    #endif

        U32 locate_cursor_flag;
        U32 show_action_flag;
        S32 line_before_visible_start_height, line_after_visible_start_height;
#ifdef __UI_EMS_HIGHLIGHT_LIST_SUPPORT__
        EMS_HILITE *hilite_list;               	/* Highlight list */
        U16	hilite_str_number               	/* Highlight list number */;
        S32	current_hilite_idx;              	/* Current highlight index in the highlight list */
        void (*hilite_cb)(S32 idx);             /* Highlight callback */
#ifdef __MMI_TOUCH_SCREEN__
        void (*hilite_click_cb)(S32 idx);    /* Pen click callback */
#endif /* __MMI_TOUCH_SCREEN__ */
#endif /* __UI_EMS_HIGHLIGHT_LIST_SUPPORT__ */
#ifdef __SMS_R8_NATION_LANGUAGE__
        mmi_7bit_auto_detection_struct ems_auto_dection;     
#endif        

       /* cursor offset of last change */
       S32  last_cursor_offset;

        U16 line_positions_text_offset[MAX_EMS_EDITOR_LINES];
        #ifdef __MMI_MESSAGES_EMS__
        U8  line_positions_object_index[MAX_EMS_EDITOR_LINES];
        #endif
        U8 scrollbar_state;
    } UI_EMS_input_box;

    
    /* msz00065_20051010 peng hua add for multitap thai begin */
#ifdef __MMI_MULTITAP_THAI__
    extern U8 gui_EMS_check_input_test_overflow(UI_EMS_input_box *b, UI_character_type c);
#endif 
    /* msz00065_20051010 peng hua add for multitap thai end */
    extern void gui_ems_cursor_info_update(UI_EMS_input_box *b);
    extern void gui_intialize_EMS(void);
    extern void gui_set_EMS_input_box_theme(UI_EMS_input_box *b, UI_EMS_input_box_theme *t);
    extern void gui_set_EMS_input_box_current_theme(UI_EMS_input_box *b);
    extern void gui_create_EMS_input_box(UI_EMS_input_box *b, S32 x, S32 y, S32 width, S32 height);
    extern void gui_set_EMS_input_box_data(UI_EMS_input_box *b, EMSData *d);
    extern U8 gui_EMS_input_box_forward_cursor(UI_EMS_input_box *b);
    extern void gui_EMS_input_box_locate_cursor(UI_EMS_input_box *b);
    extern EMSTATUS gui_EMS_input_box_add_string(UI_EMS_input_box *b, U8 *s, EMSTextFormat *text_format);
    extern EMSTATUS gui_EMS_input_box_add_whole_string(UI_EMS_input_box *b, U8 *s, EMSTextFormat *text_format);
    extern EMSTATUS gui_EMS_inputbox_add_object(
                        UI_EMS_input_box *b,
                        U8 type,
                        EMSObjData *objData,
                        U8 predefined_object_number);
    extern U8 gui_EMS_input_box_insert_multitap_string_no_draw(UI_EMS_input_box *b, UI_character_type* string);
    extern void gui_EMS_input_box_backspace(UI_EMS_input_box *b);
    extern U8 gui_EMS_input_box_insert_character(UI_EMS_input_box *b, UI_character_type c);
    extern U8 gui_EMS_input_box_insert_multitap_character(UI_EMS_input_box *b, UI_character_type c);
    extern void gui_EMS_input_box_confirm_multitap_character(UI_EMS_input_box *b);
    extern void gui_EMS_input_box_delete(UI_EMS_input_box *b);
    extern void gui_EMS_input_box_delete_all(UI_EMS_input_box *b);
    extern void gui_EMS_input_box_toggle_insert_mode(UI_EMS_input_box *b);
    extern void gui_show_EMS_input_box(UI_EMS_input_box *b);
    extern void gui_move_EMS_input_box(UI_EMS_input_box *b, S32 x, S32 y);
    extern void gui_resize_EMS_input_box(UI_EMS_input_box *b, S32 width, S32 height);
    extern U8 gui_EMS_input_box_insert_new_line(UI_EMS_input_box *b);
    extern void gui_EMS_input_box_previous(UI_EMS_input_box *b);
    extern void gui_EMS_input_box_next(UI_EMS_input_box *b);
    extern void gui_EMS_input_box_previous_line(UI_EMS_input_box *b);
    extern void gui_EMS_input_box_next_line(UI_EMS_input_box *b);
    extern void gui_ems_input_box_start_input(UI_EMS_input_box *b);
    extern void gui_ems_input_box_stop_input(UI_EMS_input_box *b);
    extern U8 gui_EMS_input_box_get_next_object(
                EMSData *data,
                EMSPosition *current_position,
                UI_character_type *c,
                EMSObject **o);
    extern U8 gui_EMS_input_box_get_previous_object(
                EMSData *data,
                EMSPosition *current_position,
                UI_character_type *c,
                EMSObject **o);
/* PMT START FOR_7.17INDIC */
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
	extern void gui_EMS_post_template_addition_adjustment(UI_EMS_input_box *b);
#endif /*__MMI_INDIC_ALG__*/
/*PMT IRE END*/
/* PMT END FOR_7.17INDIC */
#ifdef __MMI_MESSAGES_EMS__

    extern PU8 EMS_editor_sound_icon;
    extern PU8 EMS_editor_melody_icon;

    extern void gui_EMS_input_box_measure_object(EMSObject *o, S32 *width, S32 *height);
    extern void gui_EMS_input_box_set_text_format_object(UI_EMS_input_box *b, EMSTextFormat *f);
    extern void gui_EMS_input_box_display_object(S32 x, S32 y, EMSObject *o, U8 display_cursor);
    extern void EMS_cancel_object_focus(void);
    extern void gui_EMS_playback_object(EMSObject *o);
    extern void EMS_cancel_object_focus(void);
#endif /* __MMI_MESSAGES_EMS__ */ 
    extern void gui_EMS_input_box_reset_cursor_position(UI_EMS_input_box *b);
    extern void gui_EMS_input_box_set_cursor_position(UI_EMS_input_box *b, EMSPosition *p);
    extern U8 gui_EMS_inputbox_empty(UI_EMS_input_box *b);
    extern U8 gui_EMS_inputbox_empty(UI_EMS_input_box *b);
    extern S32 gui_EMS_input_box_highlight_cursor_end(UI_EMS_input_box *b);
    extern S32 gui_EMS_input_box_highlight_cursor_start(UI_EMS_input_box *b);
    extern void EMS_map_position(EMSData *data, EMSPosition *src, EMSPosition *dst);
    extern EMSObject *GetTextFormatObjectAtPosition(EMSData *data, EMSPosition *p);
    extern EMSObject *gui_ems_get_current_text_format_for_position(EMSData *data, EMSPosition *p);
    extern EMSObject *gui_ems_get_current_text_format_for_position_ex(EMSData *data, EMSPosition *p);
    /* MTK Joy added for text format insert, 0112 */
    extern EMSTATUS gui_EMS_input_box_insert_text_alignment(UI_EMS_input_box *b, EMSTextFormat *t);
    extern EMSTATUS gui_EMS_input_box_insert_new_paragraph(UI_EMS_input_box *b, EMSTextFormat *t);
    /* MTK end */
    extern U8 gui_EMS_input_box_test_paragraph_start(UI_EMS_input_box *b, EMSPosition *p);
    extern void gui_EMS_input_box_set_paragraph_text_alignment(UI_EMS_input_box *b, EMSPosition *p, U8 alignment);
    extern void gui_EMS_input_box_view_previous_object(UI_EMS_input_box *b);
    extern void gui_EMS_input_box_view_next_object(UI_EMS_input_box *b);
    extern S32 EMS_get_remaining_length(EMSData *data);

/* Mude Lin(MBJ06016) Add For SMS Remaining Count Display In EMS Editor*/
#ifdef __MMI_MESSAGES_EMS_REMAINING_COUNTER__
	extern S32 EMS_get_required_segment(UI_EMS_input_box *input_data);
	extern S32 EMS_get_last_segment_remaining_char(UI_EMS_input_box *input_data);
#endif /* __MMI_MESSAGES_EMS_REMAINING_COUNTER__ */

/*End Mude Lin(MBJ06016) Add*/	

    extern void gui_EMS_input_box_set_text_format_cursor_position(UI_EMS_input_box *b);

    extern void EMS_enable_audio_playback(void);
    extern void EMS_disable_audio_playback(void);

//#endif /* (!UI_DISABLE_EMS_INPUT_BOX) */ 
#if defined(__MMI_TOUCH_SCREEN__)// || defined(__MMI_HANDWRITING_PAD__)
    extern BOOL gui_EMS_input_box_translate_pen_event(
                    UI_EMS_input_box *b,
                    mmi_pen_event_type_enum pen_event,
                    S16 x,
                    S16 y,
                    gui_EMS_input_box_pen_enum *EMS_input_box_event);
#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 
    extern void gui_show_EMS_input_box_ext(UI_EMS_input_box *b, S32 move_to_x, S32 move_to_y);
    extern U8 gui_EMS_input_box_get_previous_character(UI_EMS_input_box *b, UI_character_type *c);
	extern U8 gui_EMS_input_box_get_next_character(UI_EMS_input_box *b, UI_character_type *c);
    extern void gui_ems_adjust_cursor_position(UI_EMS_input_box *b, U8 b_forward);

#if defined(__MMI_ARSHAPING_ENGINE__) && defined(__MMI_BIDI_ALG__)
    extern void gui_ems_input_box_translate_shaping_data(UI_EMS_input_box *b);
#endif

    extern kal_uint16 gui_ems_ucs2_to_nl_callback(EMSNationalLanguage lang, kal_uint8 *src, kal_uint8 *dest, kal_uint16 len, kal_uint8 seg_num);
    extern kal_uint16 gui_ems_nl_to_ucs2_callback(EMSNationalLanguage lang, kal_uint8 *src, kal_uint8 *dest, kal_uint16 len, kal_uint8 seg_num);

    extern U8 TestLastPosition(EMSData *data, EMSPosition *p);
	extern U8 TestFirstPosition(EMSData *data, EMSPosition *p);

    extern void gui_EMS_input_box_disalbe_show(MMI_BOOL b_disable);
    extern void gui_EMS_input_box_disable_sound(MMI_BOOL b_disable);
    extern void gui_emsc_all_line_update(void);

    extern EMSObject* gui_ems_get_object_by_index(UI_EMS_input_box *b, U8 index);
    extern U8 gui_ems_get_object_index(UI_EMS_input_box *b, EMSObject *object);

#ifdef __UI_EMS_HIGHLIGHT_LIST_SUPPORT__
    extern void gui_EMS_input_box_go_to_hilite(UI_EMS_input_box *b, U16 idx);
    extern void gui_EMS_input_box_next_line_with_hilite_list(UI_EMS_input_box *b);
    extern void gui_EMS_input_box_previous_line_with_hilite_list(UI_EMS_input_box *b);
    extern MMI_BOOL gui_EMS_input_box_is_pen_down_in_hilite(UI_EMS_input_box *b);
#endif /* __UI_EMS_HIGHLIGHT_LIST_SUPPORT__ */

    extern EMSTATUS gui_EMS_input_box_set_dcs(UI_EMS_input_box *b, kal_uint8 dcs);

    extern S32 gui_EMS_input_box_get_unit_count(UI_EMS_input_box *b, EMSPosition start, EMSPosition end);
    
    extern MMI_BOOL gui_ems_test_UCS2_character(UI_character_type c);
    
    extern void gui_EMS_input_box_set_default_text(UI_EMS_input_box *b, UI_string_type default_text);

#ifdef __cplusplus
}
#endif 

#endif /* __GUI_EMS_H__ */ 

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

#ifdef __EMS_NON_STD_7BIT_CHAR__
    extern U8 convert_non_standard_gsm(U16 c);
#endif

#ifdef __cplusplus
}
#endif 

#endif /* UI_EMS_SUPPORT */


