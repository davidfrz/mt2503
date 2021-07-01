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
/*	Include: MMI header file */
#include "MMI_features.h"

#include "BTNotiSrvGprot.h"
#include "Mmi_frm_scenario_gprot.h"
#include "AudioPlayerBTSrcSpp.h"
#include "audioplayerbtnowplaying.h"
#include "BTNotiSrvGprot.h"
#include "AudioPlayerBTProt.h"
#include "mmi_media_app_trc.h"
#include "DebugInitDef.h"
#include "MMI_trc_int.h"
#ifdef __MMI_WEARABLE_DEVICE__
#if (!defined(__MMI_A2DP_SUPPORT__) && defined(__MMI_BT_NOTI_SRV__))

/***************************************************************************** 
* Public Functions Declaration
*****************************************************************************/


/***************************************************************************** 
* Global Variable
*****************************************************************************/

mmi_bt_music_get_data_struct g_app_notify_cb;



/***************************************************************************** 
* static Variable
*****************************************************************************/

/***************************************************************************** 
* Static Functions Declaration
*****************************************************************************/
static void mmi_wr_bt_music_by_spp_cb(void * data);
static MMI_BOOL mmi_wr_bt_music_by_spp_parse_data(U8 *data, U16 len, mmi_wr_bt_result_by_spp_struct *data_result);
static U16 mmi_wr_bt_music_by_spp_get_cmd(char *cmd_type, S32 cmd);


/***************************************************************************** 
* function implement
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_music_check_role_by_addr
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  u8
 *****************************************************************************/

MMI_BOOL mmi_wr_bt_music_by_spp_check_connection(srv_bt_cm_bt_addr *bt_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL  result = MMI_FALSE;  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/       
#ifdef __MMI_BT_NOTI_SRV__
    result = srv_bt_noti_check_sync_connection_ext_by_source(bt_addr, SRV_BT_NOTIFY_DATA_SOURCE_SPP);
 	if (result)
	{
		result =  g_app_notify_cb.is_match;
 	}
#endif
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BT_MUSIC_BY_SPP_CHECK_CONNECT, result, g_app_notify_cb.is_match);
    return result;
}


MMI_BOOL srv_bt_noti_send_cmd_ext(srv_bt_cm_bt_addr *bt_addr, 
                                  const char *cmd, 
                                  const char *data, 
                                  U16 data_len);
mmi_ret mmi_wr_bt_music_by_spp_register_hdlr(srv_bt_cm_bt_addr *dev_addr, 
                                        mmi_bt_music_app_cb cb_ptr)
{
    g_app_notify_cb.app_cb = cb_ptr;
}


static void mmi_wr_bt_music_by_spp_cb(void * data)
{
    mmi_wr_bt_result_by_spp_struct data_result;
    MMI_BOOL ret = MMI_TRUE;
	srv_bt_noti_callback_struct *cb_data = (srv_bt_noti_callback_struct*)data;
  
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BT_MUSIC_NOWPLAYING_PAGE_BY_SPP_CB, cb_data->err_code, -1);
    if (cb_data->err_code == SRV_BT_NOTIFY_RET_NO_ERROR)
    {

    #ifndef __MTK_TARGET__
        char data[40];
        sprintf(data,"D 00 00 31 2 mv 30  1 3 32 1 FF");
        mmi_wr_bt_music_by_spp_parse_data(data, 40, &data_result);

    #else
        ret = mmi_wr_bt_music_by_spp_parse_data(
            cb_data->data.buffer.data, 
            cb_data->data.buffer.len,
            &data_result);
    #endif
    }
    else if (cb_data->err_code == SRV_BT_NOTIFY_RET_LINK_DISCONNECTED)
    {
        //g_app_notify_cb.is_match = 0;//can't clear
    }
    if (g_app_notify_cb.app_cb != NULL)
    {
        g_app_notify_cb.app_cb(&data_result, cb_data->err_code);

    }
}


static MMI_BOOL mmi_wr_bt_music_by_spp_parse_data(U8 *data, U16 len, mmi_wr_bt_result_by_spp_struct *data_result)
{
    /*not come true*/
    U32 i=0,j, k ;
    S32 start_pos = 0;
    U32 sub_length;
    MMI_BOOL ret = MMI_FALSE;
    U8 event_count = 3;
    U8 get_data[256];
    memset(data_result,0x00,sizeof(mmi_wr_bt_result_by_spp_struct));
    memcpy(get_data, data, len);
    get_data[len-1]= '\0';
    MMI_PRINT(MOD_MMI_CONN_APP, 
              TRACE_GROUP_7,
              "[AUDPLY]mmi_wr_bt_music_by_spp_parse_data: get_data = %s", get_data);
    if (len <= 2) /*the first 2 bytes is wrong.cmd type id and seq id*/
    {
        return ret;
    }
    do 
    {
            for (; i < len; ++i)
            {
                if (data[i] == ' ')
                {
                   data[i] = '\0';
                   break;
                }
            }
           
           if (i >= len - 1)
           {
               break;
           }
            if (data[start_pos] == 'E')/*SP has bt music control app*/
			{
				data_result->cmd_type = 15;
				g_app_notify_cb.is_match = 1;
				break;
			}
			else if (data[start_pos] == 'D')
			{
			    data_result->cmd_type = 13;
			}
			else
			{
			    data_result->cmd_type = (U32)atoi((const char*)&(data[start_pos]));
			}

           ++i;
           start_pos = i;
           MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BT_MUSIC_BY_SPP_PARSE_DATA, data_result->cmd_type, 0, start_pos);    
        
            for (; i < len; ++i)
            {
               if (data[i] == ' ')
               {
                   data[i] = '\0';
                   break;
               }
            }
            if (i >= len - 1)
            {
                break;
            }
        
            data_result->seq_id = (U32)atoi((const char*)&(data[start_pos]));
            ++i;
            start_pos = i;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BT_MUSIC_BY_SPP_PARSE_DATA, data_result->seq_id, 1, start_pos);
            for (; i < len; ++i)
            {
               if (data[i] == ' ')
               {
                   data[i] = '\0';
                   break;
               }
            }
           
            if (i >= len - 1)
            {
                break;
            }
        
            data_result->error_code = (U8)atoi((const char*)&(data[start_pos]));
            if (data_result->error_code != BM_SUCCESS)
            {
                return ret;
            }
            ++i;
            start_pos = i;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BT_MUSIC_BY_SPP_PARSE_DATA,  data_result->error_code, 2, start_pos);

           for (j = 0; j < event_count; j++, i++)// if it needs 
           {
                for (; i < len; ++i)
                {
                   if (data[i] == ' ')
                   {
                       data[i] = '\0';
                       break;
                   }
                }
                if (i >= len - 1)
                {
                     break;
                }
                data_result->element[j].event_type = (U8)atoi((const char*)&(data[start_pos]));
                ++i;
                start_pos = i;
                for (; i < len; ++i)
                {
                   if (data[i] == ' ')
                   {
                       data[i] = '\0';
                       break;
                   }
                }
                if (i >= len - 1)
                {
                     break;
                }
                sub_length =  (U8)atoi((const char*)&(data[start_pos]));
                data_result->element[j].subtype_length = sub_length;
                ++i;
                start_pos = i;
                if (data_result->element[j].event_type == 31)// title
                {
                    
                    memcpy(data_result->element[1].element_data , &data[start_pos], sub_length);

                }
                else if (data_result->element[j].event_type == 30)// playstatus
                {
                    data_result->element[0].element_data[0] = (U8)atoi((const char*)&(data[start_pos]));

                }else if(data_result->element[j].event_type == 32)//volume
                {
                    data_result->element[2].element_data[0] = (U8)atoi((const char*)&(data[start_pos]));
                }
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_SPP_PARSE_DATA_BY_S, data_result->element[j].event_type, sub_length, i);

               i += sub_length;
               ++i;
               start_pos = i;
               ret = MMI_TRUE;
           }
     }while (0);
    return ret;

}


void mmi_wr_bt_music_by_spp_send_cmd(srv_bt_cm_bt_addr *dev_addr, S32 cmd)
{
	char base_cmd[32];
	U8 data[40] = {0};
    U16 len;
    U8 count = 1;
    char cmd_type[40];

    sprintf(base_cmd, "%s", BT_MUSIC_CONTROL_VIA_SPP_CMD);
    len = mmi_wr_bt_music_by_spp_get_cmd(cmd_type, cmd);
    sprintf(data, "%s %s 0 %d %s %d %s",BT_MUSIC_CONTROL_VIA_SPP_SENDERR, 
    BT_MUSIC_CONTROL_VIA_SPP_RECEIVED,  len, cmd_type, (count++), "FF");/*type + datalen + data*/
    /*need do some transfer*/
    #ifdef  __MTK_TARGET__
    #ifdef __MMI_BT_NOTI_SRV__
    srv_bt_noti_send_cmd_ext(dev_addr, base_cmd, data, strlen(data));
    #endif
   #endif
   #if  0
/* under construction !*/
   #endif
}


static U16 mmi_wr_bt_music_by_spp_get_cmd(char *cmd_type, S32 cmd)
{
    mmi_bt_music_send_cmd_struct cmd_para;
    memset(&cmd_para, 0x00, sizeof (mmi_bt_music_send_cmd_struct));
    app_ucs2_itoa(cmd, cmd_para.cmd_type, 16);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BT_MUSIC_NOWPLAYING_PAGE_BY_SPP_GET_PARA, cmd,cmd_para.cmd_type[0], 
    cmd_para.cmd_type[1],cmd_para.cmd_type[2] );
    sprintf(cmd_type, "%s", cmd_para.cmd_type);
    return strlen(cmd_type);
}


void mmi_wr_bt_reset_match_flag()
{
    g_app_notify_cb.is_match = 0;
}
#endif /*(!defined(__MMI_A2DP_SUPPORT__) && defined(__MMI_BT_NOTI_SRV__))*/
#endif /*__MMI_WEARABLE_DEVICE__*/

#ifdef __MMI_WEARABLE_DEVICE__
void mmi_wr_bt_by_spp_int(void)
{
#if (!defined(__MMI_A2DP_SUPPORT__))&& (defined (__MMI_BT_NOTI_SRV__))

    srv_bt_notify_register_result_enum ret;

    ret = srv_bt_noti_register_callback_ext(BT_MUSIC_CONTROL_VIA_SPP_CMD, 
                                        BT_MUSIC_CONTROL_VIA_SPP_SENDERR,
                                        mmi_wr_bt_music_by_spp_cb);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_BM_SPP_CLIENT_REGISTER, ret);
#endif
}
#endif /*__MMI_WEARABLE_DEVICE__*/
/*by BLE charateristic*/


