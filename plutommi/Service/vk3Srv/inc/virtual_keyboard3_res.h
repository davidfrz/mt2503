
#ifdef __MMI_IME_V3__

#ifndef __VIRTUAL_KEYBOARD3_DEFINE_H__
#define __VIRTUAL_KEYBOARD3_DEFINE_H__


#include "mmi_rp_srv_vk3_def.h"
#include "Lcd_sw_inc.h"
#include "mmi_rp_srv_input_method_def.h"

 
extern const wgui_virtual_keyboard_layout_struct        keyBoardTable[];
extern const gui_virtual_keyboard_togglekey_struct    toggleStructTable[];
extern const gui_virtual_keyboard_key_struct     toggleKeyTable[];
extern const gui_virtual_keyboard_key_struct*  toggleKeyPtrTable[];
#ifdef __IMEHW_DCM_SUPPORT__
#include "dcmgr.h"
#pragma arm section rodata = "DYNAMIC_CODE_VKLAYOUT_RODATA"
#endif





const gui_virtual_keyboard_key_struct  	keyTable[] = 
{

	{
		/* index 0 */
	 /* file_index: hwkb_halfscreen_en_0_1 */ 
		44,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L",",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		0,			/* pos_x */
		3,			/* pos_y */
		27,			/* height */
		41,			/* width */
		0,			/* popup_skb */
		toggleStructTable+0			/* toggle_index */
	},	

	{
		/* index 1 */
	 /* file_index: hwkb_halfscreen_en_0_2 */ 
		33,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"!",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		198,			/* pos_x */
		3,			/* pos_y */
		27,			/* height */
		41,			/* width */
		0,			/* popup_skb */
		toggleStructTable+1			/* toggle_index */
	},	

	{
		/* index 2 */
	 /* file_index: hwkb_halfscreen_en_1_1 */ 
		44,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L",",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		0,			/* pos_x */
		3,			/* pos_y */
		27,			/* height */
		41,			/* width */
		0,			/* popup_skb */
		toggleStructTable+2			/* toggle_index */
	},	

	{
		/* index 3 */
	 /* file_index: hwkb_halfscreen_en_1_2 */ 
		8230,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\x2026",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		198,			/* pos_x */
		3,			/* pos_y */
		27,			/* height */
		41,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 4 */
	 /* file_index: hwkb_halfscreen_en_2_1 */ 
		46,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L".",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		0,			/* pos_x */
		30,			/* pos_y */
		27,			/* height */
		41,			/* width */
		0,			/* popup_skb */
		toggleStructTable+3			/* toggle_index */
	},	

	{
		/* index 5 */
	 /* file_index: hwkb_halfscreen_en_2_2 */ 
		GUI_VKBD_PEN_V3_DELETE,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa454",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		198,			/* pos_x */
		30,			/* pos_y */
		27,			/* height */
		41,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 6 */
	 /* file_index: hwkb_halfscreen_en_3_1 */ 
		63,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\?",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		0,			/* pos_x */
		57,			/* pos_y */
		27,			/* height */
		41,			/* width */
		0,			/* popup_skb */
		toggleStructTable+4			/* toggle_index */
	},	

	{
		/* index 7 */
	 /* file_index: hwkb_halfscreen_en_3_2 */ 
		GUI_VKBD_PEN_V3_SPACE ,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa46b",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		198,			/* pos_x */
		57,			/* pos_y */
		27,			/* height */
		41,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 8 */
	 /* file_index: hwkb_halfscreen_en_4_1 */ 
		GUI_VKBD_PEN_V3_CHANGE_MODE,			/* code */
		3,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa45a",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		0,			/* pos_x */
		84,			/* pos_y */
		27,			/* height */
		41,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 9 */
	 /* file_index: hwkb_halfscreen_en_4_2 */ 
		GUI_VKBD_PEN_V3_SYMBPICKER,			/* code */
		3,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa46e",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		198,			/* pos_x */
		84,			/* pos_y */
		27,			/* height */
		41,			/* width */
		keyBoardTable+14,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 10 */
	 /* file_index: hwkb_halfscreen_en_5_1 */ 
		33,			/* code */
		3,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"!",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		0,			/* pos_x */
		84,			/* pos_y */
		27,			/* height */
		41,			/* width */
		0,			/* popup_skb */
		toggleStructTable+5			/* toggle_index */
	},	

	{
		/* index 11 */
	 /* file_index: hwkb_halfscreen_en_5_2 */ 
		GUI_VKBD_PEN_V3_SYMBPICKER,			/* code */
		3,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa46e",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		198,			/* pos_x */
		84,			/* pos_y */
		27,			/* height */
		41,			/* width */
		keyBoardTable+14,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 12 */
	 /* file_index: hwkb_halfscreen_en_6_1 */ 
		GUI_VKBD_PEN_V3_HIDE,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa451",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		0,			/* pos_x */
		111,			/* pos_y */
		27,			/* height */
		41,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 13 */
	 /* file_index: hwkb_halfscreen_en_6_2 */ 
		GUI_VKBD_PEN_V3_ENTER,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa456",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		198,			/* pos_x */
		111,			/* pos_y */
		27,			/* height */
		41,			/* width */
		0,			/* popup_skb */
		toggleStructTable+6			/* toggle_index */
	},	

	{
		/* index 14 */
	 /* file_index: skb_phn_en_0_1 */ 
		44,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa453",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		toggleStructTable+7			/* toggle_index */
	},	

	{
		/* index 15 */
	 /* file_index: skb_phn_en_0_2 */ 
		GUI_VKBD_PEN_ALPHANUMERIC_KEY_1,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"1",			/* label */
		L"\?!@",			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 16 */
	 /* file_index: skb_phn_en_0_3 */ 
		GUI_VKBD_PEN_ALPHANUMERIC_KEY_2,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"2",			/* label */
		L"abc",			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 17 */
	 /* file_index: skb_phn_en_0_4 */ 
		GUI_VKBD_PEN_ALPHANUMERIC_KEY_3,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"3",			/* label */
		L"def",			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 18 */
	 /* file_index: skb_phn_en_0_5 */ 
		GUI_VKBD_PEN_V3_MOVE_LEFT,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa45b",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 19 */
	 /* file_index: skb_phn_en_1_1 */ 
		46,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa455",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 20 */
	 /* file_index: skb_phn_en_1_2 */ 
		GUI_VKBD_PEN_ALPHANUMERIC_KEY_4,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"4",			/* label */
		L"ghi",			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 21 */
	 /* file_index: skb_phn_en_1_3 */ 
		GUI_VKBD_PEN_ALPHANUMERIC_KEY_5,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"5",			/* label */
		L"jkl",			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 22 */
	 /* file_index: skb_phn_en_1_4 */ 
		GUI_VKBD_PEN_ALPHANUMERIC_KEY_6,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"6",			/* label */
		L"mno",			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 23 */
	 /* file_index: skb_phn_en_1_5 */ 
		GUI_VKBD_PEN_V3_MOVE_RIGHT,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa465",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 24 */
	 /* file_index: skb_phn_en_2_1 */ 
		GUI_VKBD_PEN_V3_SHIFT ,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa467",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		toggleStructTable+8			/* toggle_index */
	},	

	{
		/* index 25 */
	 /* file_index: skb_phn_en_2_2 */ 
		GUI_VKBD_PEN_ALPHANUMERIC_KEY_7,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"7",			/* label */
		L"pqrs",			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 26 */
	 /* file_index: skb_phn_en_2_3 */ 
		GUI_VKBD_PEN_ALPHANUMERIC_KEY_8,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"8",			/* label */
		L"tuv",			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 27 */
	 /* file_index: skb_phn_en_2_4 */ 
		GUI_VKBD_PEN_ALPHANUMERIC_KEY_9,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"9",			/* label */
		L"wxyz",			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 28 */
	 /* file_index: skb_phn_en_2_5 */ 
		GUI_VKBD_PEN_V3_DELETE,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa454",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 29 */
	 /* file_index: skb_phn_en_3_1 */ 
		GUI_VKBD_PEN_V3_HIDE,			/* code */
		3,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa451",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 30 */
	 /* file_index: skb_phn_en_3_2 */ 
		GUI_VKBD_PEN_V3_CHANGE_MODE,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa45a",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 31 */
	 /* file_index: skb_phn_en_3_3 */ 
		GUI_VKBD_PEN_ALPHANUMERIC_KEY_0,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"0",			/* label */
		L"\xa46c",			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		48,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		toggleStructTable+9			/* toggle_index */
	},	

	{
		/* index 32 */
	 /* file_index: skb_phn_en_3_4 */ 
		GUI_VKBD_PEN_V3_SYMBPICKER,			/* code */
		3,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa46e",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		keyBoardTable+14,			/* popup_skb */
		toggleStructTable+10			/* toggle_index */
	},	

	{
		/* index 33 */
	 /* file_index: skb_phn_en_3_5 */ 
		GUI_VKBD_PEN_V3_ENTER,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa456",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		toggleStructTable+11			/* toggle_index */
	},	

	{
		/* index 34 */
	 /* file_index: skb_phn_123sym_1_en_0_1 */ 
		34,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\"",			/* label */
		L"'",			/* label_aux */
		L"\"",			/* label_balloon */
		0,			/* icon_balloon */
		39,			/* code_longpress */
		L"'",			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 35 */
	 /* file_index: skb_phn_123sym_1_en_0_2 */ 
		49,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"1",			/* label */
		L"#",			/* label_aux */
		L"1",			/* label_balloon */
		0,			/* icon_balloon */
		35,			/* code_longpress */
		L"#",			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 36 */
	 /* file_index: skb_phn_123sym_1_en_0_3 */ 
		50,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"2",			/* label */
		L"$",			/* label_aux */
		L"2",			/* label_balloon */
		0,			/* icon_balloon */
		36,			/* code_longpress */
		L"$",			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 37 */
	 /* file_index: skb_phn_123sym_1_en_0_4 */ 
		51,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"3",			/* label */
		L"%",			/* label_aux */
		L"3",			/* label_balloon */
		0,			/* icon_balloon */
		37,			/* code_longpress */
		L"%",			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 38 */
	 /* file_index: skb_phn_123sym_1_en_0_5 */ 
		95,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"_",			/* label */
		L"-",			/* label_aux */
		L"_",			/* label_balloon */
		0,			/* icon_balloon */
		45,			/* code_longpress */
		L"-",			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 39 */
	 /* file_index: skb_phn_123sym_1_en_1_1 */ 
		63,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\?",			/* label */
		L"!",			/* label_aux */
		L"\?",			/* label_balloon */
		0,			/* icon_balloon */
		33,			/* code_longpress */
		L"!",			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 40 */
	 /* file_index: skb_phn_123sym_1_en_1_2 */ 
		52,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"4",			/* label */
		L"@",			/* label_aux */
		L"4",			/* label_balloon */
		0,			/* icon_balloon */
		64,			/* code_longpress */
		L"@",			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 41 */
	 /* file_index: skb_phn_123sym_1_en_1_3 */ 
		53,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"5",			/* label */
		L"&",			/* label_aux */
		L"5",			/* label_balloon */
		0,			/* icon_balloon */
		38,			/* code_longpress */
		L"&",			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 42 */
	 /* file_index: skb_phn_123sym_1_en_1_4 */ 
		54,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"6",			/* label */
		L"*",			/* label_aux */
		L"6",			/* label_balloon */
		0,			/* icon_balloon */
		42,			/* code_longpress */
		L"*",			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 43 */
	 /* file_index: skb_phn_123sym_1_en_1_5 */ 
		58,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L":",			/* label */
		L";",			/* label_aux */
		L":",			/* label_balloon */
		0,			/* icon_balloon */
		59,			/* code_longpress */
		L";",			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 44 */
	 /* file_index: skb_phn_123sym_1_en_2_1 */ 
		GUI_VKBD_PEN_V3_123SYM_SWITCH,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa47b",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 45 */
	 /* file_index: skb_phn_123sym_1_en_2_2 */ 
		55,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"7",			/* label */
		L"/",			/* label_aux */
		L"7",			/* label_balloon */
		0,			/* icon_balloon */
		47,			/* code_longpress */
		L"/",			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 46 */
	 /* file_index: skb_phn_123sym_1_en_2_3 */ 
		56,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"8",			/* label */
		L"(",			/* label_aux */
		L"8",			/* label_balloon */
		0,			/* icon_balloon */
		40,			/* code_longpress */
		L"(",			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 47 */
	 /* file_index: skb_phn_123sym_1_en_2_4 */ 
		57,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"9",			/* label */
		L")",			/* label_aux */
		L"9",			/* label_balloon */
		0,			/* icon_balloon */
		41,			/* code_longpress */
		L")",			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 48 */
	 /* file_index: skb_phn_123sym_1_en_2_5 */ 
		GUI_VKBD_PEN_V3_DELETE,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa454",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 49 */
	 /* file_index: skb_phn_123sym_1_en_3_1 */ 
		GUI_VKBD_PEN_V3_HIDE,			/* code */
		3,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa451",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 50 */
	 /* file_index: skb_phn_123sym_1_en_3_2 */ 
		215,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xd7",			/* label */
		L"\xf7",			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		247,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 51 */
	 /* file_index: skb_phn_123sym_1_en_3_3 */ 
		48,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"0",			/* label */
		L"\xa46c",			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		GUI_VKBD_PEN_V3_SPACE ,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 52 */
	 /* file_index: skb_phn_123sym_1_en_3_4 */ 
		GUI_VKBD_PEN_V3_123SYM,			/* code */
		4,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa47a",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 53 */
	 /* file_index: skb_phn_123sym_1_en_3_5 */ 
		GUI_VKBD_PEN_V3_ENTER,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa456",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		toggleStructTable+12			/* toggle_index */
	},	

	{
		/* index 54 */
	 /* file_index: skb_phn_123sym_2_en_0_1 */ 
		183,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xb7",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 55 */
	 /* file_index: skb_phn_123sym_2_en_0_2 */ 
		60,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"<",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 56 */
	 /* file_index: skb_phn_123sym_2_en_0_3 */ 
		62,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L">",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 57 */
	 /* file_index: skb_phn_123sym_2_en_0_4 */ 
		123,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"{",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 58 */
	 /* file_index: skb_phn_123sym_2_en_0_5 */ 
		125,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"}",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 59 */
	 /* file_index: skb_phn_123sym_2_en_1_1 */ 
		43,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"+",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 60 */
	 /* file_index: skb_phn_123sym_2_en_1_2 */ 
		61,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"=",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 61 */
	 /* file_index: skb_phn_123sym_2_en_1_3 */ 
		94,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"^",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 62 */
	 /* file_index: skb_phn_123sym_2_en_1_4 */ 
		91,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"[",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 63 */
	 /* file_index: skb_phn_123sym_2_en_1_5 */ 
		93,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"]",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 64 */
	 /* file_index: skb_phn_123sym_2_en_2_1 */ 
		GUI_VKBD_PEN_V3_123SYM_SWITCH,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa47c",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 65 */
	 /* file_index: skb_phn_123sym_2_en_2_2 */ 
		124,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"|",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 66 */
	 /* file_index: skb_phn_123sym_2_en_2_3 */ 
		92,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\\",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 67 */
	 /* file_index: skb_phn_123sym_2_en_2_4 */ 
		126,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"~",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 68 */
	 /* file_index: skb_phn_123sym_2_en_2_5 */ 
		GUI_VKBD_PEN_V3_DELETE,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa454",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 69 */
	 /* file_index: skb_phn_123sym_2_en_3_1 */ 
		GUI_VKBD_PEN_V3_HIDE,			/* code */
		3,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa451",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 70 */
	 /* file_index: skb_phn_123sym_2_en_3_2 */ 
		177,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xb1",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 71 */
	 /* file_index: skb_phn_123sym_2_en_3_3 */ 
		GUI_VKBD_PEN_V3_SPACE ,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa46b",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 72 */
	 /* file_index: skb_phn_123sym_2_en_3_4 */ 
		GUI_VKBD_PEN_V3_123SYM,			/* code */
		4,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa47a",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 73 */
	 /* file_index: skb_phn_123sym_2_en_3_5 */ 
		GUI_VKBD_PEN_V3_ENTER,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa456",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		toggleStructTable+13			/* toggle_index */
	},	

	{
		/* index 74 */
	 /* file_index: skb_phn_symbol_1_en_0_1 */ 
		34,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\"",			/* label */
		L"'",			/* label_aux */
		L"\"",			/* label_balloon */
		0,			/* icon_balloon */
		39,			/* code_longpress */
		L"'",			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 75 */
	 /* file_index: skb_phn_symbol_1_en_0_2 */ 
		49,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"1",			/* label */
		L"#",			/* label_aux */
		L"1",			/* label_balloon */
		0,			/* icon_balloon */
		35,			/* code_longpress */
		L"#",			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 76 */
	 /* file_index: skb_phn_symbol_1_en_0_3 */ 
		50,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"2",			/* label */
		L"$",			/* label_aux */
		L"2",			/* label_balloon */
		0,			/* icon_balloon */
		36,			/* code_longpress */
		L"$",			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 77 */
	 /* file_index: skb_phn_symbol_1_en_0_4 */ 
		51,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"3",			/* label */
		L"%",			/* label_aux */
		L"3",			/* label_balloon */
		0,			/* icon_balloon */
		37,			/* code_longpress */
		L"%",			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 78 */
	 /* file_index: skb_phn_symbol_1_en_0_5 */ 
		95,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"_",			/* label */
		L"-",			/* label_aux */
		L"_",			/* label_balloon */
		0,			/* icon_balloon */
		45,			/* code_longpress */
		L"-",			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 79 */
	 /* file_index: skb_phn_symbol_1_en_1_1 */ 
		63,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\?",			/* label */
		L"!",			/* label_aux */
		L"\?",			/* label_balloon */
		0,			/* icon_balloon */
		33,			/* code_longpress */
		L"!",			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 80 */
	 /* file_index: skb_phn_symbol_1_en_1_2 */ 
		52,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"4",			/* label */
		L"@",			/* label_aux */
		L"4",			/* label_balloon */
		0,			/* icon_balloon */
		64,			/* code_longpress */
		L"@",			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 81 */
	 /* file_index: skb_phn_symbol_1_en_1_3 */ 
		53,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"5",			/* label */
		L"&",			/* label_aux */
		L"5",			/* label_balloon */
		0,			/* icon_balloon */
		38,			/* code_longpress */
		L"&",			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 82 */
	 /* file_index: skb_phn_symbol_1_en_1_4 */ 
		54,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"6",			/* label */
		L"*",			/* label_aux */
		L"6",			/* label_balloon */
		0,			/* icon_balloon */
		42,			/* code_longpress */
		L"*",			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 83 */
	 /* file_index: skb_phn_symbol_1_en_1_5 */ 
		58,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L":",			/* label */
		L";",			/* label_aux */
		L":",			/* label_balloon */
		0,			/* icon_balloon */
		59,			/* code_longpress */
		L";",			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 84 */
	 /* file_index: skb_phn_symbol_1_en_2_1 */ 
		GUI_VKBD_PEN_V3_SYMBOLE_SWITCH,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa460",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 85 */
	 /* file_index: skb_phn_symbol_1_en_2_2 */ 
		55,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"7",			/* label */
		L"/",			/* label_aux */
		L"7",			/* label_balloon */
		0,			/* icon_balloon */
		47,			/* code_longpress */
		L"/",			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 86 */
	 /* file_index: skb_phn_symbol_1_en_2_3 */ 
		56,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"8",			/* label */
		L"(",			/* label_aux */
		L"8",			/* label_balloon */
		0,			/* icon_balloon */
		40,			/* code_longpress */
		L"(",			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 87 */
	 /* file_index: skb_phn_symbol_1_en_2_4 */ 
		57,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"9",			/* label */
		L")",			/* label_aux */
		L"9",			/* label_balloon */
		0,			/* icon_balloon */
		41,			/* code_longpress */
		L")",			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 88 */
	 /* file_index: skb_phn_symbol_1_en_2_5 */ 
		GUI_VKBD_PEN_V3_DELETE,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa454",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 89 */
	 /* file_index: skb_phn_symbol_1_en_3_1 */ 
		GUI_VKBD_PEN_V3_HIDE,			/* code */
		3,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa451",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 90 */
	 /* file_index: skb_phn_symbol_1_en_3_2 */ 
		GUI_VKBD_PEN_V3_SYMBOL_FULL_HALF,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa450",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		toggleStructTable+14			/* toggle_index */
	},	

	{
		/* index 91 */
	 /* file_index: skb_phn_symbol_1_en_3_3 */ 
		48,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"0",			/* label */
		L"\xa46c",			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		GUI_VKBD_PEN_V3_SPACE ,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 92 */
	 /* file_index: skb_phn_symbol_1_en_3_4 */ 
		GUI_VKBD_PEN_V3_SYMBPICKER,			/* code */
		4,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa46e",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 93 */
	 /* file_index: skb_phn_symbol_1_en_3_5 */ 
		GUI_VKBD_PEN_V3_ENTER,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa456",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		toggleStructTable+15			/* toggle_index */
	},	

	{
		/* index 94 */
	 /* file_index: skb_phn_symbol_2_en_0_1 */ 
		183,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xb7",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 95 */
	 /* file_index: skb_phn_symbol_2_en_0_2 */ 
		60,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"<",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 96 */
	 /* file_index: skb_phn_symbol_2_en_0_3 */ 
		62,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L">",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 97 */
	 /* file_index: skb_phn_symbol_2_en_0_4 */ 
		123,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"{",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 98 */
	 /* file_index: skb_phn_symbol_2_en_0_5 */ 
		125,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"}",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 99 */
	 /* file_index: skb_phn_symbol_2_en_1_1 */ 
		43,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"+",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 100 */
	 /* file_index: skb_phn_symbol_2_en_1_2 */ 
		61,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"=",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 101 */
	 /* file_index: skb_phn_symbol_2_en_1_3 */ 
		94,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"^",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 102 */
	 /* file_index: skb_phn_symbol_2_en_1_4 */ 
		91,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"[",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 103 */
	 /* file_index: skb_phn_symbol_2_en_1_5 */ 
		93,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"]",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 104 */
	 /* file_index: skb_phn_symbol_2_en_2_1 */ 
		GUI_VKBD_PEN_V3_SYMBOLE_SWITCH,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa461",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 105 */
	 /* file_index: skb_phn_symbol_2_en_2_2 */ 
		124,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"|",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 106 */
	 /* file_index: skb_phn_symbol_2_en_2_3 */ 
		92,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\\",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 107 */
	 /* file_index: skb_phn_symbol_2_en_2_4 */ 
		126,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"~",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 108 */
	 /* file_index: skb_phn_symbol_2_en_2_5 */ 
		GUI_VKBD_PEN_V3_DELETE,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa454",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 109 */
	 /* file_index: skb_phn_symbol_2_en_3_1 */ 
		GUI_VKBD_PEN_V3_HIDE,			/* code */
		3,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa451",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 110 */
	 /* file_index: skb_phn_symbol_2_en_3_2 */ 
		GUI_VKBD_PEN_V3_SYMBOL_FULL_HALF,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa450",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		toggleStructTable+16			/* toggle_index */
	},	

	{
		/* index 111 */
	 /* file_index: skb_phn_symbol_2_en_3_3 */ 
		GUI_VKBD_PEN_V3_SPACE ,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa46b",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 112 */
	 /* file_index: skb_phn_symbol_2_en_3_4 */ 
		GUI_VKBD_PEN_V3_SYMBPICKER,			/* code */
		4,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa46e",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 113 */
	 /* file_index: skb_phn_symbol_2_en_3_5 */ 
		GUI_VKBD_PEN_V3_ENTER,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa456",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		toggleStructTable+17			/* toggle_index */
	},	

	{
		/* index 114 */
	 /* file_index: skb_phn_symbol_3_en_0_1 */ 
		GUI_VKBD_PEN_V3_CHAR_I_STRING,			/* code */
		9,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L":)",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 115 */
	 /* file_index: skb_phn_symbol_3_en_0_2 */ 
		GUI_VKBD_PEN_V3_CHAR_I_STRING,			/* code */
		9,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L":(",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 116 */
	 /* file_index: skb_phn_symbol_3_en_0_3 */ 
		GUI_VKBD_PEN_V3_CHAR_I_STRING,			/* code */
		9,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L";)",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 117 */
	 /* file_index: skb_phn_symbol_3_en_0_4 */ 
		GUI_VKBD_PEN_V3_CHAR_I_STRING,			/* code */
		9,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L":D",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 118 */
	 /* file_index: skb_phn_symbol_3_en_0_5 */ 
		GUI_VKBD_PEN_V3_CHAR_I_STRING,			/* code */
		9,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L":P",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 119 */
	 /* file_index: skb_phn_symbol_3_en_1_1 */ 
		GUI_VKBD_PEN_V3_CHAR_I_STRING,			/* code */
		9,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L":$",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 120 */
	 /* file_index: skb_phn_symbol_3_en_1_2 */ 
		GUI_VKBD_PEN_V3_CHAR_I_STRING,			/* code */
		9,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L":S",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 121 */
	 /* file_index: skb_phn_symbol_3_en_1_3 */ 
		GUI_VKBD_PEN_V3_CHAR_I_STRING,			/* code */
		9,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"^_^",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 122 */
	 /* file_index: skb_phn_symbol_3_en_1_4 */ 
		GUI_VKBD_PEN_V3_CHAR_I_STRING,			/* code */
		9,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L":<",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 123 */
	 /* file_index: skb_phn_symbol_3_en_1_5 */ 
		GUI_VKBD_PEN_V3_CHAR_I_STRING,			/* code */
		9,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L":>",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 124 */
	 /* file_index: skb_phn_symbol_3_en_2_1 */ 
		GUI_VKBD_PEN_V3_SYMBOLE_SWITCH,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa462",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 125 */
	 /* file_index: skb_phn_symbol_3_en_2_2 */ 
		GUI_VKBD_PEN_V3_CHAR_I_STRING,			/* code */
		9,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"><",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 126 */
	 /* file_index: skb_phn_symbol_3_en_2_3 */ 
		GUI_VKBD_PEN_V3_CHAR_I_STRING,			/* code */
		9,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"~~",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 127 */
	 /* file_index: skb_phn_symbol_3_en_2_4 */ 
		GUI_VKBD_PEN_V3_CHAR_I_STRING,			/* code */
		9,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"Orz",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 128 */
	 /* file_index: skb_phn_symbol_3_en_2_5 */ 
		GUI_VKBD_PEN_V3_DELETE,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa454",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 129 */
	 /* file_index: skb_phn_symbol_3_en_3_1 */ 
		GUI_VKBD_PEN_V3_HIDE,			/* code */
		3,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa451",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 130 */
	 /* file_index: skb_phn_symbol_3_en_3_2 */ 
		GUI_VKBD_PEN_V3_SYMBOL_FULL_HALF,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa450",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		toggleStructTable+18			/* toggle_index */
	},	

	{
		/* index 131 */
	 /* file_index: skb_phn_symbol_3_en_3_3 */ 
		GUI_VKBD_PEN_V3_SPACE ,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa46b",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 132 */
	 /* file_index: skb_phn_symbol_3_en_3_4 */ 
		GUI_VKBD_PEN_V3_SYMBPICKER,			/* code */
		4,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa46e",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 133 */
	 /* file_index: skb_phn_symbol_3_en_3_5 */ 
		GUI_VKBD_PEN_V3_ENTER,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa456",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		toggleStructTable+19			/* toggle_index */
	},	

	{
		/* index 134 */
	 /* file_index: skb_phn_symbol_custom_1_en_0_1 */ 
		35,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"#",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 135 */
	 /* file_index: skb_phn_symbol_custom_1_en_0_2 */ 
		49,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"1",			/* label */
		L"?",			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		63,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 136 */
	 /* file_index: skb_phn_symbol_custom_1_en_0_3 */ 
		50,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"2",			/* label */
		L"$",			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		36,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 137 */
	 /* file_index: skb_phn_symbol_custom_1_en_0_4 */ 
		51,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"3",			/* label */
		L"%",			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		37,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 138 */
	 /* file_index: skb_phn_symbol_custom_1_en_0_5 */ 
		95,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"_",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 139 */
	 /* file_index: skb_phn_symbol_custom_1_en_1_1 */ 
		61,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"=",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 140 */
	 /* file_index: skb_phn_symbol_custom_1_en_1_2 */ 
		52,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"4",			/* label */
		L"+",			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		43,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 141 */
	 /* file_index: skb_phn_symbol_custom_1_en_1_3 */ 
		53,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"5",			/* label */
		L"&",			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		38,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 142 */
	 /* file_index: skb_phn_symbol_custom_1_en_1_4 */ 
		54,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"6",			/* label */
		L"*",			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		42,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 143 */
	 /* file_index: skb_phn_symbol_custom_1_en_1_5 */ 
		45,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"-",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 144 */
	 /* file_index: skb_phn_symbol_custom_1_en_2_1 */ 
		GUI_VKBD_PEN_V3_CUSTOM_SYMBOLE_SWITCH,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa47b",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 145 */
	 /* file_index: skb_phn_symbol_custom_1_en_2_2 */ 
		55,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"7",			/* label */
		L"/",			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		47,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 146 */
	 /* file_index: skb_phn_symbol_custom_1_en_2_3 */ 
		56,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"8",			/* label */
		L"\\",			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		92,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 147 */
	 /* file_index: skb_phn_symbol_custom_1_en_2_4 */ 
		57,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"9",			/* label */
		L"~",			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		126,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 148 */
	 /* file_index: skb_phn_symbol_custom_1_en_2_5 */ 
		GUI_VKBD_PEN_V3_DELETE,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa454",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 149 */
	 /* file_index: skb_phn_symbol_custom_1_en_3_1 */ 
		GUI_VKBD_PEN_V3_HIDE,			/* code */
		3,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa451",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 150 */
	 /* file_index: skb_phn_symbol_custom_1_en_3_2 */ 
		58,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L":",			/* label */
		L";",			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		59,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 151 */
	 /* file_index: skb_phn_symbol_custom_1_en_3_3 */ 
		48,			/* code */
		6,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"0",			/* label */
		L"!",			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		33,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 152 */
	 /* file_index: skb_phn_symbol_custom_1_en_3_4 */ 
		GUI_VKBD_PEN_V3_SYMBPICKER,			/* code */
		4,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa47a",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 153 */
	 /* file_index: skb_phn_symbol_custom_1_en_3_5 */ 
		GUI_VKBD_PEN_V3_ENTER,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa456",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		toggleStructTable+20			/* toggle_index */
	},	

	{
		/* index 154 */
	 /* file_index: skb_phn_symbol_custom_2_en_0_1 */ 
		34,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\"",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 155 */
	 /* file_index: skb_phn_symbol_custom_2_en_0_2 */ 
		60,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"<",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 156 */
	 /* file_index: skb_phn_symbol_custom_2_en_0_3 */ 
		62,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L">",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 157 */
	 /* file_index: skb_phn_symbol_custom_2_en_0_4 */ 
		123,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"{",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 158 */
	 /* file_index: skb_phn_symbol_custom_2_en_0_5 */ 
		44,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L",",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 159 */
	 /* file_index: skb_phn_symbol_custom_2_en_1_1 */ 
		39,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"'",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 160 */
	 /* file_index: skb_phn_symbol_custom_2_en_1_2 */ 
		125,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"}",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 161 */
	 /* file_index: skb_phn_symbol_custom_2_en_1_3 */ 
		91,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"[",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 162 */
	 /* file_index: skb_phn_symbol_custom_2_en_1_4 */ 
		93,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"]",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 163 */
	 /* file_index: skb_phn_symbol_custom_2_en_1_5 */ 
		96,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"`",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 164 */
	 /* file_index: skb_phn_symbol_custom_2_en_2_1 */ 
		GUI_VKBD_PEN_V3_CUSTOM_SYMBOLE_SWITCH,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa47c",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 165 */
	 /* file_index: skb_phn_symbol_custom_2_en_2_2 */ 
		40,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"(",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 166 */
	 /* file_index: skb_phn_symbol_custom_2_en_2_3 */ 
		41,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L")",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 167 */
	 /* file_index: skb_phn_symbol_custom_2_en_2_4 */ 
		94,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"^",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 168 */
	 /* file_index: skb_phn_symbol_custom_2_en_2_5 */ 
		GUI_VKBD_PEN_V3_DELETE,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa454",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 169 */
	 /* file_index: skb_phn_symbol_custom_2_en_3_1 */ 
		GUI_VKBD_PEN_V3_HIDE,			/* code */
		3,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa451",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 170 */
	 /* file_index: skb_phn_symbol_custom_2_en_3_2 */ 
		124,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"|",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 171 */
	 /* file_index: skb_phn_symbol_custom_2_en_3_3 */ 
		64,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"@",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 172 */
	 /* file_index: skb_phn_symbol_custom_2_en_3_4 */ 
		GUI_VKBD_PEN_V3_SYMBPICKER,			/* code */
		4,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa47a",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 173 */
	 /* file_index: skb_phn_symbol_custom_2_en_3_5 */ 
		GUI_VKBD_PEN_V3_ENTER,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa456",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		toggleStructTable+21			/* toggle_index */
	},	

	{
		/* index 174 */
	 /* file_index: skb_phone_en_0_1 */ 
		112,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa45f",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		toggleStructTable+22			/* toggle_index */
	},	

	{
		/* index 175 */
	 /* file_index: skb_phone_en_0_2 */ 
		49,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"1",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 176 */
	 /* file_index: skb_phone_en_0_3 */ 
		50,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"2",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 177 */
	 /* file_index: skb_phone_en_0_4 */ 
		51,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"3",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 178 */
	 /* file_index: skb_phone_en_0_5 */ 
		43,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa463",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		toggleStructTable+23			/* toggle_index */
	},	

	{
		/* index 179 */
	 /* file_index: skb_phone_en_1_1 */ 
		119,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa472",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		toggleStructTable+24			/* toggle_index */
	},	

	{
		/* index 180 */
	 /* file_index: skb_phone_en_1_2 */ 
		52,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"4",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 181 */
	 /* file_index: skb_phone_en_1_3 */ 
		53,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"5",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 182 */
	 /* file_index: skb_phone_en_1_4 */ 
		54,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"6",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 183 */
	 /* file_index: skb_phone_en_1_5 */ 
		45,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa45c",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		toggleStructTable+25			/* toggle_index */
	},	

	{
		/* index 184 */
	 /* file_index: skb_phone_en_2_1 */ 
		GUI_VKBD_PEN_V3_SYMBPICKER,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa46d",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		toggleStructTable+26			/* toggle_index */
	},	

	{
		/* index 185 */
	 /* file_index: skb_phone_en_2_2 */ 
		55,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"7",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 186 */
	 /* file_index: skb_phone_en_2_3 */ 
		56,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"8",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 187 */
	 /* file_index: skb_phone_en_2_4 */ 
		57,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"9",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 188 */
	 /* file_index: skb_phone_en_2_5 */ 
		GUI_VKBD_PEN_V3_DELETE,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa454",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 189 */
	 /* file_index: skb_phone_en_3_1 */ 
		GUI_VKBD_PEN_V3_HIDE,			/* code */
		3,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa451",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 190 */
	 /* file_index: skb_phone_en_3_2 */ 
		42,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"*",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		toggleStructTable+27			/* toggle_index */
	},	

	{
		/* index 191 */
	 /* file_index: skb_phone_en_3_3 */ 
		48,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"0",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 192 */
	 /* file_index: skb_phone_en_3_4 */ 
		35,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"#",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		toggleStructTable+28			/* toggle_index */
	},	

	{
		/* index 193 */
	 /* file_index: skb_phone_en_3_5 */ 
		GUI_VKBD_PEN_V3_ENTER,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa456",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		toggleStructTable+29			/* toggle_index */
	},	

	{
		/* index 194 */
	 /* file_index: skb_phone_sym_en_0_1 */ 
		65536,			/* code */
		11,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L" ",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 195 */
	 /* file_index: skb_phone_sym_en_0_2 */ 
		40,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"(",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 196 */
	 /* file_index: skb_phone_sym_en_0_3 */ 
		47,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"/",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 197 */
	 /* file_index: skb_phone_sym_en_0_4 */ 
		41,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L")",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 198 */
	 /* file_index: skb_phone_sym_en_0_5 */ 
		GUI_VKBD_PEN_V3_MOVE_LEFT,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa45b",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		2,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 199 */
	 /* file_index: skb_phone_sym_en_1_1 */ 
		59,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L";",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 200 */
	 /* file_index: skb_phone_sym_en_1_2 */ 
		45,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa45c",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 201 */
	 /* file_index: skb_phone_sym_en_1_3 */ 
		112,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa45f",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 202 */
	 /* file_index: skb_phone_sym_en_1_4 */ 
		110,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa45d",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 203 */
	 /* file_index: skb_phone_sym_en_1_5 */ 
		GUI_VKBD_PEN_V3_MOVE_RIGHT,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa465",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		36,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 204 */
	 /* file_index: skb_phone_sym_en_2_1 */ 
		GUI_VKBD_PEN_V3_SYMBPICKER,			/* code */
		4,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa46d",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 205 */
	 /* file_index: skb_phone_sym_en_2_2 */ 
		43,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa463",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 206 */
	 /* file_index: skb_phone_sym_en_2_3 */ 
		119,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa472",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 207 */
	 /* file_index: skb_phone_sym_en_2_4 */ 
		63,			/* code */
		0,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"?",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 208 */
	 /* file_index: skb_phone_sym_en_2_5 */ 
		GUI_VKBD_PEN_V3_DELETE,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa454",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		70,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 209 */
	 /* file_index: skb_phone_sym_en_3_1 */ 
		GUI_VKBD_PEN_V3_HIDE,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa451",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		3,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 210 */
	 /* file_index: skb_phone_sym_en_3_2 */ 
		44,			/* code */
		10,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L",",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 211 */
	 /* file_index: skb_phone_sym_en_3_3 */ 
		GUI_VKBD_PEN_V3_SPACE ,			/* code */
		10,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa46b",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		93,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 212 */
	 /* file_index: skb_phone_sym_en_3_4 */ 
		46,			/* code */
		10,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L".",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		146,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		53,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 213 */
	 /* file_index: skb_phone_sym_en_3_5 */ 
		GUI_VKBD_PEN_V3_ENTER,			/* code */
		2,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa456",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		199,			/* pos_x */
		104,			/* pos_y */
		34,			/* height */
		37,			/* width */
		0,			/* popup_skb */
		toggleStructTable+30			/* toggle_index */
	},	

	{
		/* index 214 */
	 /* file_index: skb_popup_123sym_en_0_1 */ 
		GUI_VKBD_PEN_V3_123SYM_PAGE1,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa47b",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		6,			/* pos_x */
		4,			/* pos_y */
		34,			/* height */
		30,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 215 */
	 /* file_index: skb_popup_123sym_en_0_2 */ 
		GUI_VKBD_PEN_V3_123SYM_PAGE2,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa47c",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		36,			/* pos_x */
		4,			/* pos_y */
		34,			/* height */
		30,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 216 */
	 /* file_index: skb_popup_qwerty_com_en_0_1 */ 
		GUI_VKBD_PEN_V3_DOT_NET,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa47e",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		6,			/* pos_x */
		4,			/* pos_y */
		34,			/* height */
		34,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 217 */
	 /* file_index: skb_popup_qwerty_com_en_0_2 */ 
		GUI_VKBD_PEN_V3_DOT_EDU,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa47d",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		40,			/* pos_x */
		4,			/* pos_y */
		34,			/* height */
		34,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 218 */
	 /* file_index: skb_popup_qwerty_com_en_0_3 */ 
		GUI_VKBD_PEN_V3_DOT_ORG,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa47f",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		74,			/* pos_x */
		4,			/* pos_y */
		34,			/* height */
		34,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 219 */
	 /* file_index: skb_popup_qwerty_com_en_0_4 */ 
		GUI_VKBD_PEN_V3_DOT_COM,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa452",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		108,			/* pos_x */
		4,			/* pos_y */
		34,			/* height */
		34,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 220 */
	 /* file_index: skb_popup_qwerty_fullstop_en_0_1 */ 
		63,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\?",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		6,			/* pos_x */
		4,			/* pos_y */
		34,			/* height */
		24,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 221 */
	 /* file_index: skb_popup_qwerty_fullstop_en_0_2 */ 
		33,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"!",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		30,			/* pos_x */
		4,			/* pos_y */
		34,			/* height */
		24,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 222 */
	 /* file_index: skb_popup_qwerty_fullstop_en_0_3 */ 
		59,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L";",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		54,			/* pos_x */
		4,			/* pos_y */
		34,			/* height */
		24,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 223 */
	 /* file_index: skb_popup_qwerty_fullstop_en_0_4 */ 
		58,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L":",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		78,			/* pos_x */
		4,			/* pos_y */
		34,			/* height */
		24,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 224 */
	 /* file_index: skb_popup_qwerty_fullstop_en_0_5 */ 
		47,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"/",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		102,			/* pos_x */
		4,			/* pos_y */
		34,			/* height */
		24,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 225 */
	 /* file_index: skb_popup_qwerty_fullstop_en_0_6 */ 
		46,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L".",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		126,			/* pos_x */
		4,			/* pos_y */
		34,			/* height */
		24,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 226 */
	 /* file_index: skb_popup_symbol_en_0_1 */ 
		GUI_VKBD_PEN_V3_SYMBOL_PAGE1,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa460",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		6,			/* pos_x */
		4,			/* pos_y */
		34,			/* height */
		30,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 227 */
	 /* file_index: skb_popup_symbol_en_0_2 */ 
		GUI_VKBD_PEN_V3_SYMBOL_PAGE2,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa461",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		36,			/* pos_x */
		4,			/* pos_y */
		34,			/* height */
		30,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 228 */
	 /* file_index: skb_popup_symbol_en_0_3 */ 
		GUI_VKBD_PEN_V3_SYMBOL_PAGE3,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa462",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		66,			/* pos_x */
		4,			/* pos_y */
		34,			/* height */
		30,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 229 */
	 /* file_index: skb_popup_symbol_custom_en_0_1 */ 
		GUI_VKBD_PEN_V3_CUSTOM_SYMBOL_PAGE1,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa47b",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		6,			/* pos_x */
		4,			/* pos_y */
		34,			/* height */
		30,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	

	{
		/* index 230 */
	 /* file_index: skb_popup_symbol_custom_en_0_2 */ 
		GUI_VKBD_PEN_V3_CUSTOM_SYMBOL_PAGE2,			/* code */
		5,			/* key_type */
		0,			/* icon */
		0,			/* icon_aux */
		0,			/* icon_hl */
		0,			/* icon_aux_hl */
		L"\xa47c",			/* label */
		0,			/* label_aux */
		0,			/* label_balloon */
		0,			/* icon_balloon */
		0,			/* code_longpress */
		0,			/* label_balloon_longpress */
		0,			/* icon_balloon_longpress */
		36,			/* pos_x */
		4,			/* pos_y */
		34,			/* height */
		30,			/* width */
		0,			/* popup_skb */
		0			/* toggle_index */
	},	
};

const gui_virtual_keyboard_keytype_struct	keyTypeTable[] = 
{
	{
		/* index 0 */
		IMG_ID_CHARACTER_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		0,			/*balloon_bg*/
		1.4f,			/*balloon_ratio_height*/
		1.35f,			/*balloon_ratio_width*/
		0xff000000,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(25*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(25*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		0,			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 1 */
		IMG_ID_CHARACTER_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		0,			/*balloon_bg*/
		1.4f,			/*balloon_ratio_height*/
		1.35f,			/*balloon_ratio_width*/
		0xff000000,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(25*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(25*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		0,			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 2 */
		IMG_ID_FUNCTION_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		0,			/*balloon_bg*/
		1.4f,			/*balloon_ratio_height*/
		1.35f,			/*balloon_ratio_width*/
		0xffFFFFFF,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(24*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(24*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		0,			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 3 */
		IMG_ID_FUNCTION_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		0,			/*balloon_bg*/
		1.4f,			/*balloon_ratio_height*/
		1.35f,			/*balloon_ratio_width*/
		0xffFFFFFF,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(24*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(24*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		0,			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 4 */
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		0,			/*balloon_bg*/
		1.4f,			/*balloon_ratio_height*/
		1.35f,			/*balloon_ratio_width*/
		0xffFFFFFF,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(24*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(24*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		0,			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 5 */
		IMG_ID_CHARACTER_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		0,			/*balloon_bg*/
		1.4f,			/*balloon_ratio_height*/
		1.35f,			/*balloon_ratio_width*/
		0xff494949,			/*text_color1*/
		0xff000000,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0xffFFFFFF,			/*hltext_color2*/
		0,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		-25,			/*main_regy*/
		0,			/*aux_regx*/
		10,			/*aux_regy*/
		(U8)(15*120/160),			/*text_size1*/
		(U8)(19*120/160),			/*text_size2*/
		(U8)(15*120/160),			/*hltext_size1*/
		(U8)(19*120/160),			/*hltext_size2*/
		0,			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 6 */
		IMG_ID_CHARACTER_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		0,			/*balloon_bg*/
		1.4f,			/*balloon_ratio_height*/
		1.35f,			/*balloon_ratio_width*/
		0xff000000,			/*text_color1*/
		0xff494949,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0xffFFFFFF,			/*hltext_color2*/
		0,			/*bltext_color1*/
		0,			/*bltext_color2*/
		-20,			/*main_regx*/
		0,			/*main_regy*/
		20,			/*aux_regx*/
		5,			/*aux_regy*/
		(U8)(23*120/160),			/*text_size1*/
		(U8)(18*120/160),			/*text_size2*/
		(U8)(23*120/160),			/*hltext_size1*/
		(U8)(18*120/160),			/*hltext_size2*/
		0,			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 7 */
		IMG_ID_CHARACTER_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		0,			/*balloon_bg*/
		1.4f,			/*balloon_ratio_height*/
		1.35f,			/*balloon_ratio_width*/
		0xff494949,			/*text_color1*/
		0xff000000,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0xffFFFFFF,			/*hltext_color2*/
		0,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		-25,			/*main_regy*/
		0,			/*aux_regx*/
		10,			/*aux_regy*/
		(U8)(15*120/160),			/*text_size1*/
		(U8)(15*120/160),			/*text_size2*/
		(U8)(15*120/160),			/*hltext_size1*/
		(U8)(15*120/160),			/*hltext_size2*/
		0,			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 8 */
		IMG_ID_CHARACTER_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		0,			/*balloon_bg*/
		1.4f,			/*balloon_ratio_height*/
		1.35f,			/*balloon_ratio_width*/
		0xff000000,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(16*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(16*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		0,			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 9 */
		IMG_ID_CHARACTER_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		0,			/*balloon_bg*/
		1.4f,			/*balloon_ratio_height*/
		1.35f,			/*balloon_ratio_width*/
		0xff000000,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(20*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(20*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		0,			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 10 */
		IMG_ID_CHARACTER_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		0,			/*balloon_bg*/
		1.4f,			/*balloon_ratio_height*/
		1.35f,			/*balloon_ratio_width*/
		0xff000000,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(25*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(25*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		0,			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 11 */
		IMG_ID_DISABLE_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		0,			/*balloon_bg*/
		1.4f,			/*balloon_ratio_height*/
		1.35f,			/*balloon_ratio_width*/
		0xff767676,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(25*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(25*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		0,			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 12 */
		IMG_ID_FUNCTION_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		0,			/*balloon_bg*/
		1.4f,			/*balloon_ratio_height*/
		1.35f,			/*balloon_ratio_width*/
		0xffFFFFFF,			/*text_color1*/
		0xffFFFFFF,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0xffFFFFFF,			/*hltext_color2*/
		0,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		-10,			/*main_regy*/
		0,			/*aux_regx*/
		10,			/*aux_regy*/
		(U8)(24*120/160),			/*text_size1*/
		(U8)(24*120/160),			/*text_size2*/
		(U8)(24*120/160),			/*hltext_size1*/
		(U8)(24*120/160),			/*hltext_size2*/
		0,			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 13 */
		IMG_ID_FUNCTION_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		0,			/*balloon_bg*/
		1.4f,			/*balloon_ratio_height*/
		1.35f,			/*balloon_ratio_width*/
		0xFF6EC1F0,			/*text_color1*/
		0xffFFFFFF,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0xffFFFFFF,			/*hltext_color2*/
		0,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		-10,			/*main_regy*/
		0,			/*aux_regx*/
		10,			/*aux_regy*/
		(U8)(24*120/160),			/*text_size1*/
		(U8)(24*120/160),			/*text_size2*/
		(U8)(24*120/160),			/*hltext_size1*/
		(U8)(24*120/160),			/*hltext_size2*/
		0,			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 14 */
		IMG_ID_CHARACTER_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		IMG_ID_BALLOON_BKG_9SLICE,			/*balloon_bg*/
		1.5f,			/*balloon_ratio_height*/
		1.9f,			/*balloon_ratio_width*/
		0xff000000,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0xff000000,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(22*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(22*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		(U8)(30*120/160),			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 15 */
		IMG_ID_CHARACTER_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		IMG_ID_BALLOON_BKG_9SLICE,			/*balloon_bg*/
		1.5f,			/*balloon_ratio_height*/
		1.9f,			/*balloon_ratio_width*/
		0xff000000,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0xff000000,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(22*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(22*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		(U8)(30*120/160),			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 16 */
		IMG_ID_FUNCTION_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		IMG_ID_BALLOON_BKG_9SLICE,			/*balloon_bg*/
		1.3f,			/*balloon_ratio_height*/
		1.4f,			/*balloon_ratio_width*/
		0xffFFFFFF,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0xff000000,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(24*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(24*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		(U8)(30*120/160),			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 17 */
		IMG_ID_FUNCTION_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		IMG_ID_BALLOON_BKG_9SLICE,			/*balloon_bg*/
		1.3f,			/*balloon_ratio_height*/
		1.4f,			/*balloon_ratio_width*/
		0xffFFFFFF,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0xff000000,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(24*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(24*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		(U8)(30*120/160),			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 18 */
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		IMG_ID_BALLOON_BKG_9SLICE,			/*balloon_bg*/
		1.3f,			/*balloon_ratio_height*/
		1.4f,			/*balloon_ratio_width*/
		0xffFFFFFF,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0xff000000,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(24*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(24*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		(U8)(30*120/160),			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 19 */
		IMG_ID_CHARACTER_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		0,			/*balloon_bg*/
		1.5f,			/*balloon_ratio_height*/
		1.9f,			/*balloon_ratio_width*/
		0xff000000,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0xff000000,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(18*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(18*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		(U8)(18*120/160),			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 20 */
		IMG_ID_CHARACTER_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		0,			/*balloon_bg*/
		1.5f,			/*balloon_ratio_height*/
		1.9f,			/*balloon_ratio_width*/
		0xff000000,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0xff000000,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(16.5*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(16.5*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		(U8)(16.5*120/160),			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 21 */
		IMG_ID_CHARACTER_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		IMG_ID_BALLOON_BKG_9SLICE,			/*balloon_bg*/
		1.5f,			/*balloon_ratio_height*/
		1.9f,			/*balloon_ratio_width*/
		0xff000000,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0xff000000,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(22*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(22*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		(U8)(30*120/160),			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 22 */
		IMG_ID_CHARACTER_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		IMG_ID_BALLOON_BKG_9SLICE,			/*balloon_bg*/
		1.5f,			/*balloon_ratio_height*/
		1.9f,			/*balloon_ratio_width*/
		0xff000000,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0xff000000,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(14*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(14*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		(U8)(20*120/160),			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 23 */
		IMG_ID_CHARACTER_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		IMG_ID_BALLOON_BKG_9SLICE,			/*balloon_bg*/
		1.5f,			/*balloon_ratio_height*/
		1.9f,			/*balloon_ratio_width*/
		0xff000000,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0xff000000,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(11*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(11*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		(U8)(15*120/160),			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 24 */
		IMG_ID_CHARACTER_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		IMG_ID_BALLOON_BKG_9SLICE,			/*balloon_bg*/
		1.5f,			/*balloon_ratio_height*/
		1.9f,			/*balloon_ratio_width*/
		0xff000000,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0xff000000,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(20*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(20*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		(U8)(30*120/160),			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 25 */
		IMG_ID_FUNCTION_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		0,			/*balloon_bg*/
		1.5f,			/*balloon_ratio_height*/
		1.9f,			/*balloon_ratio_width*/
		0xffFFFFFF,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0xff000000,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(24*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(24*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		(U8)(30*120/160),			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 26 */
		IMG_ID_FUNCTION_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		IMG_ID_BALLOON_BKG_9SLICE,			/*balloon_bg*/
		1.5f,			/*balloon_ratio_height*/
		1.9f,			/*balloon_ratio_width*/
		0xffFFFFFF,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0xff000000,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(24*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(24*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		(U8)(30*120/160),			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 27 */
		IMG_ID_FUNCTION_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		IMG_ID_BALLOON_BKG_9SLICE,			/*balloon_bg*/
		1.3f,			/*balloon_ratio_height*/
		1.4f,			/*balloon_ratio_width*/
		0xffFFFFFF,			/*text_color1*/
		0xffFFFFFF,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0xffFFFFFF,			/*hltext_color2*/
		0,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		-10,			/*main_regy*/
		0,			/*aux_regx*/
		10,			/*aux_regy*/
		(U8)(24*120/160),			/*text_size1*/
		(U8)(24*120/160),			/*text_size2*/
		(U8)(24*120/160),			/*hltext_size1*/
		(U8)(24*120/160),			/*hltext_size2*/
		(U8)(30*120/160),			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 28 */
		IMG_ID_FUNCTION_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		IMG_ID_BALLOON_BKG_9SLICE,			/*balloon_bg*/
		1.3f,			/*balloon_ratio_height*/
		1.4f,			/*balloon_ratio_width*/
		0xFF6EC1F0,			/*text_color1*/
		0xffFFFFFF,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0xffFFFFFF,			/*hltext_color2*/
		0,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		-10,			/*main_regy*/
		0,			/*aux_regx*/
		10,			/*aux_regy*/
		(U8)(24*120/160),			/*text_size1*/
		(U8)(24*120/160),			/*text_size2*/
		(U8)(24*120/160),			/*hltext_size1*/
		(U8)(24*120/160),			/*hltext_size2*/
		(U8)(30*120/160),			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 29 */
		IMG_ID_CHARACTER_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		IMG_ID_BALLOON_BKG_9SLICE,			/*balloon_bg*/
		1.5f,			/*balloon_ratio_height*/
		1.9f,			/*balloon_ratio_width*/
		0xff000000,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0xff000000,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(20*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(20*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		(U8)(27*120/160),			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 30 */
		IMG_ID_CHARACTER_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		IMG_ID_BALLOON_BKG_9SLICE,			/*balloon_bg*/
		1.5f,			/*balloon_ratio_height*/
		1.9f,			/*balloon_ratio_width*/
		0xff000000,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0xff000000,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(15*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(15*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		(U8)(22*120/160),			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 31 */
		IMG_ID_CHARACTER_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		IMG_ID_BALLOON_BKG_9SLICE,			/*balloon_bg*/
		1.5f,			/*balloon_ratio_height*/
		1.9f,			/*balloon_ratio_width*/
		0xff000000,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0xff000000,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(12*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(12*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		(U8)(18*120/160),			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 32 */
		IMG_ID_CHARACTER_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		IMG_ID_BALLOON_BKG_9SLICE,			/*balloon_bg*/
		1.5f,			/*balloon_ratio_height*/
		1.9f,			/*balloon_ratio_width*/
		0xff000000,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0xff000000,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(25*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(30*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		(U8)(30*120/160),			/*bltext_size1*/
		0			/*bltext_size2*/
	},

	{
		/* index 33 */
		IMG_ID_CHARACTER_BKG_9SLICE,			/*bg*/
		IMG_ID_HIGHLIGHT_BKG_9SLICE,			/*hlbg*/
		IMG_ID_BALLOON_BKG_9SLICE,			/*balloon_bg*/
		1.5f,			/*balloon_ratio_height*/
		1.9f,			/*balloon_ratio_width*/
		0xff000000,			/*text_color1*/
		0,			/*text_color2*/
		0xffFFFFFF,			/*hltext_color1*/
		0,			/*hltext_color2*/
		0xff000000,			/*bltext_color1*/
		0,			/*bltext_color2*/
		0,			/*main_regx*/
		0,			/*main_regy*/
		0,			/*aux_regx*/
		0,			/*aux_regy*/
		(U8)(25*120/160),			/*text_size1*/
		0,			/*text_size2*/
		(U8)(30*120/160),			/*hltext_size1*/
		0,			/*hltext_size2*/
		(U8)(30*120/160),			/*bltext_size1*/
		0			/*bltext_size2*/
	},

};

const gui_virtual_keyboard_row_struct		rowTable[] = 
{
		/* index 0 */
	{	1,	2,	keyTable+0	},		/* hwkb_halfscreen_en_0 */
		/* index 1 */
	{	2,	2,	keyTable+2	},		/* hwkb_halfscreen_en_1 */
		/* index 2 */
	{	-1,	2,	keyTable+4	},		/* hwkb_halfscreen_en_2 */
		/* index 3 */
	{	-1,	2,	keyTable+6	},		/* hwkb_halfscreen_en_3 */
		/* index 4 */
	{	1,	2,	keyTable+8	},		/* hwkb_halfscreen_en_4 */
		/* index 5 */
	{	2,	2,	keyTable+10	},		/* hwkb_halfscreen_en_5 */
		/* index 6 */
	{	-1,	2,	keyTable+12	},		/* hwkb_halfscreen_en_6 */
		/* index 7 */
	{	-1,	5,	keyTable+14	},		/* skb_phn_en_0 */
		/* index 8 */
	{	-1,	5,	keyTable+19	},		/* skb_phn_en_1 */
		/* index 9 */
	{	-1,	5,	keyTable+24	},		/* skb_phn_en_2 */
		/* index 10 */
	{	-1,	5,	keyTable+29	},		/* skb_phn_en_3 */
		/* index 11 */
	{	-1,	5,	keyTable+34	},		/* skb_phn_123sym_1_en_0 */
		/* index 12 */
	{	-1,	5,	keyTable+39	},		/* skb_phn_123sym_1_en_1 */
		/* index 13 */
	{	-1,	5,	keyTable+44	},		/* skb_phn_123sym_1_en_2 */
		/* index 14 */
	{	-1,	5,	keyTable+49	},		/* skb_phn_123sym_1_en_3 */
		/* index 15 */
	{	-1,	5,	keyTable+54	},		/* skb_phn_123sym_2_en_0 */
		/* index 16 */
	{	-1,	5,	keyTable+59	},		/* skb_phn_123sym_2_en_1 */
		/* index 17 */
	{	-1,	5,	keyTable+64	},		/* skb_phn_123sym_2_en_2 */
		/* index 18 */
	{	-1,	5,	keyTable+69	},		/* skb_phn_123sym_2_en_3 */
		/* index 19 */
	{	-1,	5,	keyTable+74	},		/* skb_phn_symbol_1_en_0 */
		/* index 20 */
	{	-1,	5,	keyTable+79	},		/* skb_phn_symbol_1_en_1 */
		/* index 21 */
	{	-1,	5,	keyTable+84	},		/* skb_phn_symbol_1_en_2 */
		/* index 22 */
	{	-1,	5,	keyTable+89	},		/* skb_phn_symbol_1_en_3 */
		/* index 23 */
	{	-1,	5,	keyTable+94	},		/* skb_phn_symbol_2_en_0 */
		/* index 24 */
	{	-1,	5,	keyTable+99	},		/* skb_phn_symbol_2_en_1 */
		/* index 25 */
	{	-1,	5,	keyTable+104	},		/* skb_phn_symbol_2_en_2 */
		/* index 26 */
	{	-1,	5,	keyTable+109	},		/* skb_phn_symbol_2_en_3 */
		/* index 27 */
	{	-1,	5,	keyTable+114	},		/* skb_phn_symbol_3_en_0 */
		/* index 28 */
	{	-1,	5,	keyTable+119	},		/* skb_phn_symbol_3_en_1 */
		/* index 29 */
	{	-1,	5,	keyTable+124	},		/* skb_phn_symbol_3_en_2 */
		/* index 30 */
	{	-1,	5,	keyTable+129	},		/* skb_phn_symbol_3_en_3 */
		/* index 31 */
	{	-1,	5,	keyTable+134	},		/* skb_phn_symbol_custom_1_en_0 */
		/* index 32 */
	{	-1,	5,	keyTable+139	},		/* skb_phn_symbol_custom_1_en_1 */
		/* index 33 */
	{	-1,	5,	keyTable+144	},		/* skb_phn_symbol_custom_1_en_2 */
		/* index 34 */
	{	-1,	5,	keyTable+149	},		/* skb_phn_symbol_custom_1_en_3 */
		/* index 35 */
	{	-1,	5,	keyTable+154	},		/* skb_phn_symbol_custom_2_en_0 */
		/* index 36 */
	{	-1,	5,	keyTable+159	},		/* skb_phn_symbol_custom_2_en_1 */
		/* index 37 */
	{	-1,	5,	keyTable+164	},		/* skb_phn_symbol_custom_2_en_2 */
		/* index 38 */
	{	-1,	5,	keyTable+169	},		/* skb_phn_symbol_custom_2_en_3 */
		/* index 39 */
	{	-1,	5,	keyTable+174	},		/* skb_phone_en_0 */
		/* index 40 */
	{	-1,	5,	keyTable+179	},		/* skb_phone_en_1 */
		/* index 41 */
	{	-1,	5,	keyTable+184	},		/* skb_phone_en_2 */
		/* index 42 */
	{	-1,	5,	keyTable+189	},		/* skb_phone_en_3 */
		/* index 43 */
	{	-1,	5,	keyTable+194	},		/* skb_phone_sym_en_0 */
		/* index 44 */
	{	-1,	5,	keyTable+199	},		/* skb_phone_sym_en_1 */
		/* index 45 */
	{	-1,	5,	keyTable+204	},		/* skb_phone_sym_en_2 */
		/* index 46 */
	{	-1,	5,	keyTable+209	},		/* skb_phone_sym_en_3 */
		/* index 47 */
	{	-1,	2,	keyTable+214	},		/* skb_popup_123sym_en_0 */
		/* index 48 */
	{	-1,	4,	keyTable+216	},		/* skb_popup_qwerty_com_en_0 */
		/* index 49 */
	{	-1,	6,	keyTable+220	},		/* skb_popup_qwerty_fullstop_en_0 */
		/* index 50 */
	{	-1,	3,	keyTable+226	},		/* skb_popup_symbol_en_0 */
		/* index 51 */
	{	-1,	2,	keyTable+229	},		/* skb_popup_symbol_custom_en_0 */
};

const wgui_virtual_keyboard_layout_struct		keyBoardTable[] = 
{
		/* index 0 : hwkb_halfscreen_en */
	{
		143,			/*keyboard height*/
		240,			/*keyboard width*/
		IMG_ID_KEYBOARD_BACKGROUND_9SLICE,			/*skb_bg*/
		1,			/*key_xmargin*/
		1,			/*key_ymargin*/
		7,			/*row_num*/
		rowTable+0,			/*rowlist_pointer*/
		GUI_VIRTUAL_KEYBOARD_TRAY,			/*gui_virtual_keyboard_language_enum*/
		3,			/*vk_attribute*/
		MMI_FALSE,			/*is_rotate*/
		MMI_FALSE,			/*is_shift_spport*/
		MMI_FALSE,			/*is_cache*/
		keyTypeTable+0			/*skb_template_phn_port0*/
	},
		/* index 1 : skb_phn_en */
	{
		140,			/*keyboard height*/
		240,			/*keyboard width*/
		IMG_ID_KEYBOARD_BACKGROUND_9SLICE,			/*skb_bg*/
		1,			/*key_xmargin*/
		2,			/*key_ymargin*/
		4,			/*row_num*/
		rowTable+7,			/*rowlist_pointer*/
		GUI_VIRTUAL_KEYBOARD_EN,			/*gui_virtual_keyboard_language_enum*/
		2,			/*vk_attribute*/
		MMI_FALSE,			/*is_rotate*/
		MMI_FALSE,			/*is_shift_spport*/
		MMI_FALSE,			/*is_cache*/
		keyTypeTable+0			/*skb_template_phn_port0*/
	},
		/* index 2 : skb_phn_123sym_1_en */
	{
		140,			/*keyboard height*/
		240,			/*keyboard width*/
		IMG_ID_KEYBOARD_BACKGROUND_9SLICE,			/*skb_bg*/
		1,			/*key_xmargin*/
		2,			/*key_ymargin*/
		4,			/*row_num*/
		rowTable+11,			/*rowlist_pointer*/
		GUI_VIRTUAL_KEYBOARD_EN_123SYM_1,			/*gui_virtual_keyboard_language_enum*/
		2,			/*vk_attribute*/
		MMI_FALSE,			/*is_rotate*/
		MMI_FALSE,			/*is_shift_spport*/
		MMI_FALSE,			/*is_cache*/
		keyTypeTable+0			/*skb_template_phn_port0*/
	},
		/* index 3 : skb_phn_123sym_2_en */
	{
		140,			/*keyboard height*/
		240,			/*keyboard width*/
		IMG_ID_KEYBOARD_BACKGROUND_9SLICE,			/*skb_bg*/
		1,			/*key_xmargin*/
		2,			/*key_ymargin*/
		4,			/*row_num*/
		rowTable+15,			/*rowlist_pointer*/
		GUI_VIRTUAL_KEYBOARD_EN_123SYM_2,			/*gui_virtual_keyboard_language_enum*/
		2,			/*vk_attribute*/
		MMI_FALSE,			/*is_rotate*/
		MMI_FALSE,			/*is_shift_spport*/
		MMI_FALSE,			/*is_cache*/
		keyTypeTable+0			/*skb_template_phn_port0*/
	},
		/* index 4 : skb_phn_symbol_1_en */
	{
		140,			/*keyboard height*/
		240,			/*keyboard width*/
		IMG_ID_KEYBOARD_BACKGROUND_9SLICE,			/*skb_bg*/
		1,			/*key_xmargin*/
		2,			/*key_ymargin*/
		4,			/*row_num*/
		rowTable+19,			/*rowlist_pointer*/
		GUI_VIRTUAL_KEYBOARD_EN_SYMBOL_1,			/*gui_virtual_keyboard_language_enum*/
		2,			/*vk_attribute*/
		MMI_FALSE,			/*is_rotate*/
		MMI_FALSE,			/*is_shift_spport*/
		MMI_FALSE,			/*is_cache*/
		keyTypeTable+0			/*skb_template_phn_port0*/
	},
		/* index 5 : skb_phn_symbol_2_en */
	{
		140,			/*keyboard height*/
		240,			/*keyboard width*/
		IMG_ID_KEYBOARD_BACKGROUND_9SLICE,			/*skb_bg*/
		1,			/*key_xmargin*/
		2,			/*key_ymargin*/
		4,			/*row_num*/
		rowTable+23,			/*rowlist_pointer*/
		GUI_VIRTUAL_KEYBOARD_EN_SYMBOL_2,			/*gui_virtual_keyboard_language_enum*/
		2,			/*vk_attribute*/
		MMI_FALSE,			/*is_rotate*/
		MMI_FALSE,			/*is_shift_spport*/
		MMI_FALSE,			/*is_cache*/
		keyTypeTable+0			/*skb_template_phn_port0*/
	},
		/* index 6 : skb_phn_symbol_3_en */
	{
		140,			/*keyboard height*/
		240,			/*keyboard width*/
		IMG_ID_KEYBOARD_BACKGROUND_9SLICE,			/*skb_bg*/
		1,			/*key_xmargin*/
		2,			/*key_ymargin*/
		4,			/*row_num*/
		rowTable+27,			/*rowlist_pointer*/
		GUI_VIRTUAL_KEYBOARD_EN_SYMBOL_3,			/*gui_virtual_keyboard_language_enum*/
		2,			/*vk_attribute*/
		MMI_FALSE,			/*is_rotate*/
		MMI_FALSE,			/*is_shift_spport*/
		MMI_FALSE,			/*is_cache*/
		keyTypeTable+0			/*skb_template_phn_port0*/
	},
		/* index 7 : skb_phn_symbol_custom_1_en */
	{
		140,			/*keyboard height*/
		240,			/*keyboard width*/
		IMG_ID_KEYBOARD_BACKGROUND_9SLICE,			/*skb_bg*/
		1,			/*key_xmargin*/
		2,			/*key_ymargin*/
		4,			/*row_num*/
		rowTable+31,			/*rowlist_pointer*/
		GUI_VIRTUAL_KEYBOARD_EN_SYMBOL_CUSTOM_1,			/*gui_virtual_keyboard_language_enum*/
		2,			/*vk_attribute*/
		MMI_FALSE,			/*is_rotate*/
		MMI_FALSE,			/*is_shift_spport*/
		MMI_FALSE,			/*is_cache*/
		keyTypeTable+0			/*skb_template_phn_port0*/
	},
		/* index 8 : skb_phn_symbol_custom_2_en */
	{
		140,			/*keyboard height*/
		240,			/*keyboard width*/
		IMG_ID_KEYBOARD_BACKGROUND_9SLICE,			/*skb_bg*/
		1,			/*key_xmargin*/
		2,			/*key_ymargin*/
		4,			/*row_num*/
		rowTable+35,			/*rowlist_pointer*/
		GUI_VIRTUAL_KEYBOARD_EN_SYMBOL_CUSTOM_2,			/*gui_virtual_keyboard_language_enum*/
		2,			/*vk_attribute*/
		MMI_FALSE,			/*is_rotate*/
		MMI_FALSE,			/*is_shift_spport*/
		MMI_FALSE,			/*is_cache*/
		keyTypeTable+0			/*skb_template_phn_port0*/
	},
		/* index 9 : skb_phone_en */
	{
		140,			/*keyboard height*/
		240,			/*keyboard width*/
		IMG_ID_KEYBOARD_BACKGROUND_9SLICE,			/*skb_bg*/
		1,			/*key_xmargin*/
		2,			/*key_ymargin*/
		4,			/*row_num*/
		rowTable+39,			/*rowlist_pointer*/
		GUI_VIRTUAL_KEYBOARD_EN_PHONE,			/*gui_virtual_keyboard_language_enum*/
		2,			/*vk_attribute*/
		MMI_FALSE,			/*is_rotate*/
		MMI_FALSE,			/*is_shift_spport*/
		MMI_FALSE,			/*is_cache*/
		keyTypeTable+0			/*skb_template_phn_port0*/
	},
		/* index 10 : skb_phone_sym_en */
	{
		140,			/*keyboard height*/
		240,			/*keyboard width*/
		IMG_ID_KEYBOARD_BACKGROUND_9SLICE,			/*skb_bg*/
		1,			/*key_xmargin*/
		2,			/*key_ymargin*/
		4,			/*row_num*/
		rowTable+43,			/*rowlist_pointer*/
		GUI_VIRTUAL_KEYBOARD_EN_PHONE_SYMBOL,			/*gui_virtual_keyboard_language_enum*/
		2,			/*vk_attribute*/
		MMI_FALSE,			/*is_rotate*/
		MMI_FALSE,			/*is_shift_spport*/
		MMI_FALSE,			/*is_cache*/
		keyTypeTable+0			/*skb_template_phn_port0*/
	},
		/* index 11 : skb_popup_123sym_en */
	{
		48,			/*keyboard height*/
		72,			/*keyboard width*/
		IMG_ID_POPUP_KEYBOARD_BACKGROUND_9SLICE,			/*skb_bg*/
		1,			/*key_xmargin*/
		2,			/*key_ymargin*/
		1,			/*row_num*/
		rowTable+47,			/*rowlist_pointer*/
		GUI_VIRTUAL_KEYBOARD_MAX_LANG,			/*gui_virtual_keyboard_language_enum*/
		0,			/*vk_attribute*/
		MMI_FALSE,			/*is_rotate*/
		MMI_FALSE,			/*is_shift_spport*/
		MMI_FALSE,			/*is_cache*/
		keyTypeTable+14			/*skb_template_qwerty_port0*/
	},
		/* index 12 : skb_popup_qwerty_com_en */
	{
		48,			/*keyboard height*/
		148,			/*keyboard width*/
		IMG_ID_POPUP_KEYBOARD_BACKGROUND_9SLICE,			/*skb_bg*/
		1,			/*key_xmargin*/
		2,			/*key_ymargin*/
		1,			/*row_num*/
		rowTable+48,			/*rowlist_pointer*/
		GUI_VIRTUAL_KEYBOARD_MAX_LANG,			/*gui_virtual_keyboard_language_enum*/
		0,			/*vk_attribute*/
		MMI_FALSE,			/*is_rotate*/
		MMI_FALSE,			/*is_shift_spport*/
		MMI_FALSE,			/*is_cache*/
		keyTypeTable+14			/*skb_template_qwerty_port0*/
	},
		/* index 13 : skb_popup_qwerty_fullstop_en */
	{
		48,			/*keyboard height*/
		156,			/*keyboard width*/
		IMG_ID_POPUP_KEYBOARD_BACKGROUND_9SLICE,			/*skb_bg*/
		1,			/*key_xmargin*/
		2,			/*key_ymargin*/
		1,			/*row_num*/
		rowTable+49,			/*rowlist_pointer*/
		GUI_VIRTUAL_KEYBOARD_MAX_LANG,			/*gui_virtual_keyboard_language_enum*/
		0,			/*vk_attribute*/
		MMI_FALSE,			/*is_rotate*/
		MMI_FALSE,			/*is_shift_spport*/
		MMI_FALSE,			/*is_cache*/
		keyTypeTable+14			/*skb_template_qwerty_port0*/
	},
		/* index 14 : skb_popup_symbol_en */
	{
		48,			/*keyboard height*/
		102,			/*keyboard width*/
		IMG_ID_POPUP_KEYBOARD_BACKGROUND_9SLICE,			/*skb_bg*/
		1,			/*key_xmargin*/
		2,			/*key_ymargin*/
		1,			/*row_num*/
		rowTable+50,			/*rowlist_pointer*/
		GUI_VIRTUAL_KEYBOARD_MAX_LANG,			/*gui_virtual_keyboard_language_enum*/
		0,			/*vk_attribute*/
		MMI_FALSE,			/*is_rotate*/
		MMI_FALSE,			/*is_shift_spport*/
		MMI_FALSE,			/*is_cache*/
		keyTypeTable+14			/*skb_template_qwerty_port0*/
	},
		/* index 15 : skb_popup_symbol_custom_en */
	{
		48,			/*keyboard height*/
		72,			/*keyboard width*/
		IMG_ID_POPUP_KEYBOARD_BACKGROUND_9SLICE,			/*skb_bg*/
		1,			/*key_xmargin*/
		2,			/*key_ymargin*/
		1,			/*row_num*/
		rowTable+51,			/*rowlist_pointer*/
		GUI_VIRTUAL_KEYBOARD_MAX_LANG,			/*gui_virtual_keyboard_language_enum*/
		0,			/*vk_attribute*/
		MMI_FALSE,			/*is_rotate*/
		MMI_FALSE,			/*is_shift_spport*/
		MMI_FALSE,			/*is_cache*/
		keyTypeTable+14			/*skb_template_qwerty_port0*/
	},

  {
    0,  //height
    0,  //width
    0,  //background image id
    0,  //margin_x x
    0,  //margin_y y
    0,  //row num
    NULL,    //row_list
    GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY,    //keyboard type
    0,  //vk_attribute
    MMI_FALSE,  //is rotate
    MMI_FALSE,  //is shift support
    MMI_FALSE,  //is chache
    NULL    //key type list
  },
};

const U8	stateListTable[] = 
{
	14,		/*index 0*/
	14,		/*index 1*/
	14,		/*index 2*/
	14,		/*index 3*/
	14,		/*index 4*/
	14,		/*index 5*/
	2,		/*index 6*/
	5,		/*index 7*/
	12,		/*index 8*/
	13,		/*index 9*/
	20,		/*index 10*/
	21,		/*index 11*/
	10,		/*index 12*/
	11,		/*index 13*/
	20,		/*index 14*/
	21,		/*index 15*/
	20,		/*index 16*/
	21,		/*index 17*/
	1,		/*index 18*/
	2,		/*index 19*/
	5,		/*index 20*/
	2,		/*index 21*/
	5,		/*index 22*/
	2,		/*index 23*/
	5,		/*index 24*/
	9,		/*index 25*/
	2,		/*index 26*/
	5,		/*index 27*/
	9,		/*index 28*/
	2,		/*index 29*/
	5,		/*index 30*/
	9,		/*index 31*/
	2,		/*index 32*/
	5,		/*index 33*/
	2,		/*index 34*/
	5,		/*index 35*/
	2,		/*index 36*/
	5,		/*index 37*/
	7,		/*index 38*/
	7,		/*index 39*/
	7,		/*index 40*/
	7,		/*index 41*/
	7,		/*index 42*/
	7,		/*index 43*/
	7,		/*index 44*/
	2,		/*index 45*/
	5,		/*index 46*/
	2,		/*index 47*/
	5,		/*index 48*/
};

const gui_virtual_keyboard_key_struct	 toggleKeyTable[] = 
{
	{
		/* index 0, state id 14 */ 
		65292,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xff0c",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 1, state id 14 */ 
		65281,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xff01",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 2, state id 14 */ 
		65292,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xff0c",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 3, state id 14 */ 
		12290,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\x3002",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 4, state id 14 */ 
		65311,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xff1f",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 5, state id 14 */ 
		65281,		 /*code*/ 
		3,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xff01",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 6, state id 2 */ 
		GUI_VKBD_PEN_V3_ENTER,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa459",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 7, state id 5 */ 
		GUI_VKBD_PEN_V3_ENTER,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa45e",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 8, state id 12 */ 
		44,		 /*code*/ 
		13,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa469",		 /*label*/ 
		 L"\xa453",		 /*label_aux*/ 
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		GUI_VKBD_PEN_V3_CHANGE_MODE_BETWEEN_SMART_AND_MULTITAP,		 /*code_longpress*/ 
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 9, state id 13 */ 
		44,		 /*code*/ 
		12,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa469",		 /*label*/ 
		 L"\xa453",		 /*label_aux*/ 
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		GUI_VKBD_PEN_V3_CHANGE_MODE_BETWEEN_SMART_AND_MULTITAP,		 /*code_longpress*/ 
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 10, state id 20 */ 
		GUI_VKBD_PEN_V3_DOT_COM,		 /*code*/ 
		3,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa452",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
keyBoardTable+12,			 /*popup_skb*/		0 			  /*toggle_index*/
	},

	{
		/* index 11, state id 21 */ 
		GUI_VKBD_PEN_V3_DOT_COM,		 /*code*/ 
		3,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa452",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
keyBoardTable+12,			 /*popup_skb*/		0 			  /*toggle_index*/
	},

	{
		/* index 12, state id 10 */ 
		GUI_VKBD_PEN_V3_SHIFT ,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa468",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		15,		 /*width*/ 
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 13, state id 11 */ 
		GUI_VKBD_PEN_V3_SHIFT ,		 /*code*/ 
		4,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa468",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		15,		 /*width*/ 
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 14, state id 20 */ 
		64,		 /*code*/ 
		5,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"0",		 /*label*/ 
		 L"@",		 /*label_aux*/ 
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		48,		 /*code_longpress*/ 
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 15, state id 21 */ 
		47,		 /*code*/ 
		5,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"0",		 /*label*/ 
		 L"/",		 /*label_aux*/ 
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		48,		 /*code_longpress*/ 
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 16, state id 20 */ 
		GUI_VKBD_PEN_V3_SYMBPICKER,		 /*code*/ 
		3,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa47a",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
keyBoardTable+15,			 /*popup_skb*/		0 			  /*toggle_index*/
	},

	{
		/* index 17, state id 21 */ 
		GUI_VKBD_PEN_V3_SYMBPICKER,		 /*code*/ 
		3,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa47a",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
keyBoardTable+15,			 /*popup_skb*/		0 			  /*toggle_index*/
	},

	{
		/* index 18, state id 1 */ 
		GUI_VKBD_PEN_V3_123SYM,		 /*code*/ 
		3,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa47a",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
keyBoardTable+11,			 /*popup_skb*/		0 			  /*toggle_index*/
	},

	{
		/* index 19, state id 2 */ 
		GUI_VKBD_PEN_V3_ENTER,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa459",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 20, state id 5 */ 
		GUI_VKBD_PEN_V3_ENTER,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa45e",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 21, state id 2 */ 
		GUI_VKBD_PEN_V3_ENTER,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa459",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 22, state id 5 */ 
		GUI_VKBD_PEN_V3_ENTER,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa45e",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 23, state id 2 */ 
		GUI_VKBD_PEN_V3_ENTER,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa459",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 24, state id 5 */ 
		GUI_VKBD_PEN_V3_ENTER,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa45e",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 25, state id 9 */ 
		215,		 /*code*/ 
		6,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xd7",		 /*label*/ 
		 L"\xf7",		 /*label_aux*/ 
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		247,		 /*code_longpress*/ 
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 26, state id 2 */ 
		GUI_VKBD_PEN_V3_ENTER,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa459",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 27, state id 5 */ 
		GUI_VKBD_PEN_V3_ENTER,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa45e",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 28, state id 9 */ 
		177,		 /*code*/ 
		0,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xb1",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 29, state id 2 */ 
		GUI_VKBD_PEN_V3_ENTER,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa459",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 30, state id 5 */ 
		GUI_VKBD_PEN_V3_ENTER,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa45e",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 31, state id 9 */ 
		GUI_VKBD_PEN_V3_CHAR_I_STRING,		 /*code*/ 
		9,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"o_O",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 32, state id 2 */ 
		GUI_VKBD_PEN_V3_ENTER,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa459",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 33, state id 5 */ 
		GUI_VKBD_PEN_V3_ENTER,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa45e",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 34, state id 2 */ 
		GUI_VKBD_PEN_V3_ENTER,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa459",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 35, state id 5 */ 
		GUI_VKBD_PEN_V3_ENTER,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa45e",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 36, state id 2 */ 
		GUI_VKBD_PEN_V3_ENTER,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa459",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 37, state id 5 */ 
		GUI_VKBD_PEN_V3_ENTER,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa45e",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 38, state id 7 */ 
		65536,		 /*code*/ 
		11,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L" ",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 39, state id 7 */ 
		GUI_VKBD_PEN_V3_MOVE_LEFT,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa45b",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 40, state id 7 */ 
		65536,		 /*code*/ 
		11,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L" ",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 41, state id 7 */ 
		GUI_VKBD_PEN_V3_MOVE_RIGHT,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa465",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 42, state id 7 */ 
		65536,		 /*code*/ 
		11,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L" ",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 43, state id 7 */ 
		45,		 /*code*/ 
		0,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa45c",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 44, state id 7 */ 
		46,		 /*code*/ 
		0,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L".",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 45, state id 2 */ 
		GUI_VKBD_PEN_V3_ENTER,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa459",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 46, state id 5 */ 
		GUI_VKBD_PEN_V3_ENTER,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa45e",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 47, state id 2 */ 
		GUI_VKBD_PEN_V3_ENTER,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa459",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

	{
		/* index 48, state id 5 */ 
		GUI_VKBD_PEN_V3_ENTER,		 /*code*/ 
		2,		 /*key_type*/ 
		0,			  /*icon*/
		0,			  /*icon_aux*/
		0,			  /*icon_hl*/
		0,			  /*icon_aux_hl*/
		 L"\xa45e",		 /*label*/ 
		0,			  /*label_aux*/
		0,			  /*label_balloon*/
		0,			  /*icon_balloon*/
		0,			  /*code_longpress*/
		0,			  /*label_balloon_longpress*/
		0,			  /*icon_balloon_longpress*/
		0,			  /*pos_x*/
		0,			  /*pos_y*/
		0,			  /*height*/
		0,			  /*width*/
		0,			  /*popup_skb*/
		0 			  /*toggle_index*/
	},

};

const gui_virtual_keyboard_key_struct*	toggleKeyPtrTable[] = 
{
			/*index:0*/
	toggleKeyTable+0,
			/*index:1*/
	toggleKeyTable+1,
			/*index:2*/
	toggleKeyTable+2,
			/*index:3*/
	toggleKeyTable+3,
			/*index:4*/
	toggleKeyTable+4,
			/*index:5*/
	toggleKeyTable+5,
			/*index:6*/
	toggleKeyTable+6,
			/*index:7*/
	toggleKeyTable+8,
			/*index:8*/
	toggleKeyTable+12,
			/*index:9*/
	toggleKeyTable+14,
			/*index:10*/
	toggleKeyTable+16,
			/*index:11*/
	toggleKeyTable+19,
			/*index:12*/
	toggleKeyTable+21,
			/*index:13*/
	toggleKeyTable+23,
			/*index:14*/
	toggleKeyTable+25,
			/*index:15*/
	toggleKeyTable+26,
			/*index:16*/
	toggleKeyTable+28,
			/*index:17*/
	toggleKeyTable+29,
			/*index:18*/
	toggleKeyTable+31,
			/*index:19*/
	toggleKeyTable+32,
			/*index:20*/
	toggleKeyTable+34,
			/*index:21*/
	toggleKeyTable+36,
			/*index:22*/
	toggleKeyTable+38,
			/*index:23*/
	toggleKeyTable+39,
			/*index:24*/
	toggleKeyTable+40,
			/*index:25*/
	toggleKeyTable+41,
			/*index:26*/
	toggleKeyTable+42,
			/*index:27*/
	toggleKeyTable+43,
			/*index:28*/
	toggleKeyTable+44,
			/*index:29*/
	toggleKeyTable+45,
			/*index:30*/
	toggleKeyTable+47,
};

 const gui_virtual_keyboard_togglekey_struct	toggleStructTable[] = 
{
	{
/* index: 0 */
		1,			/* state_num */
		stateListTable+0,			/* toggle_stateid pointer */
		toggleKeyPtrTable+0			/* toggle_key pointer */
	},

	{
/* index: 1 */
		1,			/* state_num */
		stateListTable+1,			/* toggle_stateid pointer */
		toggleKeyPtrTable+1			/* toggle_key pointer */
	},

	{
/* index: 2 */
		1,			/* state_num */
		stateListTable+2,			/* toggle_stateid pointer */
		toggleKeyPtrTable+2			/* toggle_key pointer */
	},

	{
/* index: 3 */
		1,			/* state_num */
		stateListTable+3,			/* toggle_stateid pointer */
		toggleKeyPtrTable+3			/* toggle_key pointer */
	},

	{
/* index: 4 */
		1,			/* state_num */
		stateListTable+4,			/* toggle_stateid pointer */
		toggleKeyPtrTable+4			/* toggle_key pointer */
	},

	{
/* index: 5 */
		1,			/* state_num */
		stateListTable+5,			/* toggle_stateid pointer */
		toggleKeyPtrTable+5			/* toggle_key pointer */
	},

	{
/* index: 6 */
		2,			/* state_num */
		stateListTable+6,			/* toggle_stateid pointer */
		toggleKeyPtrTable+6			/* toggle_key pointer */
	},

	{
/* index: 7 */
		4,			/* state_num */
		stateListTable+8,			/* toggle_stateid pointer */
		toggleKeyPtrTable+7			/* toggle_key pointer */
	},

	{
/* index: 8 */
		2,			/* state_num */
		stateListTable+12,			/* toggle_stateid pointer */
		toggleKeyPtrTable+8			/* toggle_key pointer */
	},

	{
/* index: 9 */
		2,			/* state_num */
		stateListTable+14,			/* toggle_stateid pointer */
		toggleKeyPtrTable+9			/* toggle_key pointer */
	},

	{
/* index: 10 */
		3,			/* state_num */
		stateListTable+16,			/* toggle_stateid pointer */
		toggleKeyPtrTable+10			/* toggle_key pointer */
	},

	{
/* index: 11 */
		2,			/* state_num */
		stateListTable+19,			/* toggle_stateid pointer */
		toggleKeyPtrTable+11			/* toggle_key pointer */
	},

	{
/* index: 12 */
		2,			/* state_num */
		stateListTable+21,			/* toggle_stateid pointer */
		toggleKeyPtrTable+12			/* toggle_key pointer */
	},

	{
/* index: 13 */
		2,			/* state_num */
		stateListTable+23,			/* toggle_stateid pointer */
		toggleKeyPtrTable+13			/* toggle_key pointer */
	},

	{
/* index: 14 */
		1,			/* state_num */
		stateListTable+25,			/* toggle_stateid pointer */
		toggleKeyPtrTable+14			/* toggle_key pointer */
	},

	{
/* index: 15 */
		2,			/* state_num */
		stateListTable+26,			/* toggle_stateid pointer */
		toggleKeyPtrTable+15			/* toggle_key pointer */
	},

	{
/* index: 16 */
		1,			/* state_num */
		stateListTable+28,			/* toggle_stateid pointer */
		toggleKeyPtrTable+16			/* toggle_key pointer */
	},

	{
/* index: 17 */
		2,			/* state_num */
		stateListTable+29,			/* toggle_stateid pointer */
		toggleKeyPtrTable+17			/* toggle_key pointer */
	},

	{
/* index: 18 */
		1,			/* state_num */
		stateListTable+31,			/* toggle_stateid pointer */
		toggleKeyPtrTable+18			/* toggle_key pointer */
	},

	{
/* index: 19 */
		2,			/* state_num */
		stateListTable+32,			/* toggle_stateid pointer */
		toggleKeyPtrTable+19			/* toggle_key pointer */
	},

	{
/* index: 20 */
		2,			/* state_num */
		stateListTable+34,			/* toggle_stateid pointer */
		toggleKeyPtrTable+20			/* toggle_key pointer */
	},

	{
/* index: 21 */
		2,			/* state_num */
		stateListTable+36,			/* toggle_stateid pointer */
		toggleKeyPtrTable+21			/* toggle_key pointer */
	},

	{
/* index: 22 */
		1,			/* state_num */
		stateListTable+38,			/* toggle_stateid pointer */
		toggleKeyPtrTable+22			/* toggle_key pointer */
	},

	{
/* index: 23 */
		1,			/* state_num */
		stateListTable+39,			/* toggle_stateid pointer */
		toggleKeyPtrTable+23			/* toggle_key pointer */
	},

	{
/* index: 24 */
		1,			/* state_num */
		stateListTable+40,			/* toggle_stateid pointer */
		toggleKeyPtrTable+24			/* toggle_key pointer */
	},

	{
/* index: 25 */
		1,			/* state_num */
		stateListTable+41,			/* toggle_stateid pointer */
		toggleKeyPtrTable+25			/* toggle_key pointer */
	},

	{
/* index: 26 */
		1,			/* state_num */
		stateListTable+42,			/* toggle_stateid pointer */
		toggleKeyPtrTable+26			/* toggle_key pointer */
	},

	{
/* index: 27 */
		1,			/* state_num */
		stateListTable+43,			/* toggle_stateid pointer */
		toggleKeyPtrTable+27			/* toggle_key pointer */
	},

	{
/* index: 28 */
		1,			/* state_num */
		stateListTable+44,			/* toggle_stateid pointer */
		toggleKeyPtrTable+28			/* toggle_key pointer */
	},

	{
/* index: 29 */
		2,			/* state_num */
		stateListTable+45,			/* toggle_stateid pointer */
		toggleKeyPtrTable+29			/* toggle_key pointer */
	},

	{
/* index: 30 */
		2,			/* state_num */
		stateListTable+47,			/* toggle_stateid pointer */
		toggleKeyPtrTable+30			/* toggle_key pointer */
	},

};



#ifdef __IMEHW_DCM_SUPPORT__
#pragma arm section rodata
#endif

#endif    
#endif //__MMI_IME_V3__   