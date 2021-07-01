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
#ifndef ___BT_MUSIC_CONTROL_VIA_SPP_PROT_H__
#define ___BT_MUSIC_CONTROL_VIA_SPP_PROT_H__
#include "mmi_features.h"
#include "Btnotisrvgprot.h"
#include "custom_btcm_config.h"
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#ifdef __MMI_WEARABLE_DEVICE__
#if (!defined(__MMI_A2DP_SUPPORT__) && defined(__MMI_BT_NOTI_SRV__))
/***************************************************************************** 
* Structures
*****************************************************************************/
#define BT_MUSIC_CONTROL_VIA_SPP_SENDERR     "mtk_msctrl"
#define BT_MUSIC_CONTROL_VIA_SPP_CMD "EXCD"
#define BT_MUSIC_CONTROL_VIA_SPP_RECEIVED "msctrl_apk"

#define BT_MUSIC_OP_LAUNCH 0X01
#define BT_MUSIC_OP_EXIT 0X02
#define BT_MUSIC_OP_PLAY 0X03
#define BT_MUSIC_OP_PAUSE 0X04
#define BT_MUSIC_OP_VOLUME_UP 0X05
#define BT_MUSIC_OP_VOLUME_DOWN 0X06
#define BT_MUSIC_OP_PREV 0X07
#define BT_MUSIC_OP_NEXT 0X08
#define BT_MUSIC_OP_GET_INFO 0X09
#define BT_MUSIC_NOTIFY 0X0D
#define BT_NOTI_ELEM_DATA_SIZE 256
#define BT_MUSIC_CONTROL_BY_SPP 15
typedef enum
{
    BT_MUSIC_PLAYSTATUS = 30,
    BT_MUSIC_SONGTITLE = 31,
    BT_MUSIC_VOLUME = 32,
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
}mmi_wr_bt_event_type_enum;

typedef enum
{
    BM_PLAY_STATUS_STOPPED = 0X01,
    BM_PLAY_STATUS_PLAYING = 0X01,
    BM_PLAY_STATUS_PAUSED = 0X02,
    BM_PLAY_STATUS_ERROR = 0X03,
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}mmi_wr_bt_music_playstatus_enum;

typedef enum
{
    BM_SUCCESS = 0X00,
    BM_NO_FOUND_SONG = 0X01,
    BT_TIME_OUT = 0X02,
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}mmi_wr_bt_music_error_code_enum;

typedef struct
{
    mmi_wr_bt_event_type_enum event_type;
    U16 subtype_length;
    U8 element_data[BT_NOTI_ELEM_DATA_SIZE];
}mmi_wr_bt_music_element_data_struct;

typedef struct
{
    srv_bt_cm_bt_addr bt_addr;
    S32 cmd_type;
    U32 seq_id;
    mmi_wr_bt_music_error_code_enum error_code;
    mmi_wr_bt_music_element_data_struct element[3];
}mmi_wr_bt_result_by_spp_struct;

typedef struct
{
    char cmd_type[3];
}mmi_bt_music_send_cmd_struct;


/***************************************************************************** 
* External Function
*****************************************************************************/
typedef void (*mmi_bt_music_app_cb)(mmi_wr_bt_result_by_spp_struct*, S32);


typedef struct
{
	mmi_bt_music_app_cb app_cb;
	MMI_BOOL is_match;

}mmi_bt_music_get_data_struct;
/***************************************************************************** 
* public function
*****************************************************************************/
MMI_BOOL mmi_wr_bt_music_by_spp_check_connection(srv_bt_cm_bt_addr *bt_addr);

mmi_ret mmi_wr_bt_music_by_spp_register_hdlr(srv_bt_cm_bt_addr *dev_addr, 
                                        mmi_bt_music_app_cb cb_ptr);
void mmi_wr_bt_music_by_spp_send_cmd(srv_bt_cm_bt_addr *dev_addr, S32 cmd);
MMI_BOOL mmi_wr_bt_music_by_spp_check_connection(srv_bt_cm_bt_addr *bt_addr);
#endif /*!defined(__MMI_A2DP_SUPPORT__) && defined(__MMI_BT_NOTI_SRV__)*/
#endif /*__MMI_WEARABLE_DEVICE__*/
#endif//#ifndef ___BT_MUSIC_CONTROL_VIA_SPP_PROT_H__