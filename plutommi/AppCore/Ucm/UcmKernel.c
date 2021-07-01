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
 *  UcmKernel.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  UCM kernel source file
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_UCM__
#include "mdi_audio.h"
#include "ProfilesSrvGprot.h"
#include "CallSetSrvGprot.h" /* srv_callset_call_time_display_get_mode, srv_callset_ctr_get_mode */
#include "BootupSrvGprot.h"  /* srv_bootup_is_booting */
#ifdef __DRM_SUPPORT__
#include "drm_gprot.h"
#endif /* __DRM_SUPPORT__ */
#include "app_usedetails.h" /* applib_ss_string_parsing */

#include "mmi_rp_core_ucm_def.h"
#include "UcmCoreProt.h"
#include "UcmSrvGProt.h"
#ifdef __MMI_VIDEO_TELEPHONY__
#include "app_datetime.h" /* applib_time_struct */
#endif /* __MMI_VIDEO_TELEPHONY__ */
#ifdef __DM_LAWMO_SUPPORT__
#include "DmSrvGprot.h"
#endif /* __DM_LAWMO_SUPPORT__ */
#ifdef  __MMI_FTE_SUPPORT__
#include "ScrLockerGprot.h"   /* Only for mmi_scr_locker_is_locked */
#endif /* __MMI_FTE_SUPPORT__ */
#include "Resource_audio.h"
#include "string.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "custom_srv_prof_defs.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "GpioSrvGprot.h"
#include "kal_public_api.h"
#include "Unicodexdcl.h"
#include "sim_common_enums.h"
#include "ps_public_enum.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#ifdef __DRM_SUPPORT__
#include "drm_def.h"
#endif /* __DRM_SUPPORT__ */
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
#include "wgui_categories_multimedia.h"
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "nvram_common_defs.h"
#include "GlobalConstants.h"
#include "CustDataRes.h"
#if (defined(__OP01_3G__) || defined(__OP02__)) && defined(OPERA_BROWSER)
#include "browser_api.h"
#endif /* (defined(__OP01_3G__) || defined(__OP02__)) && defined(OPERA_BROWSER) */
#include "SimCtrlSrvGprot.h"

#ifdef __MMI_BT_SUPPORT__
#include "BtcmSrvGprot.h"
#endif /* __MMI_BT_SUPPORT__ */
#ifdef __MMI_BT_CALL_SUPPORT__
#include "UcmProtBT.h"
#endif /* __MMI_BT_CALL_SUPPORT__ */
#ifdef  __GENERAL_TTS__
#include "TTSSettingGprot.h"
#endif /* __GENERAL_TTS__ */
#ifdef IFLY_TTS
#include "SSCStringHandle.h"    /* SSC_ENGLISH, ... defination */
#endif /* IFLY_TTS */
#include "mmi_frm_utility_gprot.h"   /* For MMI_SIM_TOTAL & MMI_SIM_ALL */
#include "NetSetSrvGprot.h"
#include "NwInfoSrvGprot.h"
#include "NwUsabSrvGprot.h"

#ifdef __COSMOS_MMI_PACKAGE__
#undef __MMI_FTE_SUPPORT__
#endif

#ifdef IFLY_TTS
extern sLanguageDetails *gLanguageArray;
extern U16 gCurrLangIndex;
#endif /* IFLY_TTS */

mmi_core_ucm_cntx_struct g_mmi_core_ucm_cntx;
mmi_core_ucm_cntx_struct *mmi_core_ucm_p = &g_mmi_core_ucm_cntx;


static const mmi_ucm_call_type_single_sim_struct g_call_type_mapping_table[] =
{
    {SRV_UCM_SIM1_CALL_TYPE_ALL, SRV_UCM_VOICE_CALL_TYPE, SRV_UCM_VIDEO_CALL_TYPE},
#if (MMI_MAX_SIM_NUM >= 2)
    {SRV_UCM_SIM2_CALL_TYPE_ALL, SRV_UCM_VOICE_CALL_TYPE_SIM2, SRV_UCM_VIDEO_CALL_TYPE_SIM2},
#if (MMI_MAX_SIM_NUM >= 3)
    {SRV_UCM_SIM3_CALL_TYPE_ALL, SRV_UCM_VOICE_CALL_TYPE_SIM3, SRV_UCM_CALL_TYPE_END_OF_ENUM},
#if (MMI_MAX_SIM_NUM == 4)
    {SRV_UCM_SIM4_CALL_TYPE_ALL, SRV_UCM_VOICE_CALL_TYPE_SIM4, SRV_UCM_CALL_TYPE_END_OF_ENUM},
#endif /* (MMI_MAX_SIM_NUM == 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */
};


/*****************************************************************************
 * FUNCTION
 *  mmi_core_ucm_init_context
 * DESCRIPTION
 *  Initialize UCM app core context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_core_ucm_init_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_MIC_SUPPORT__
    S16 errorCode = 0;
    U8 mode = 0;
#endif /* __MMI_DUAL_MIC_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_core_ucm_reset_index_list();
    mmi_core_ucm_p->call_misc.hilite_group_index = -1;
#ifdef __DRM_SUPPORT__
    mmi_core_ucm_p->call_misc.drm_consume_id = -1;
#endif /* __DRM_SUPPORT__ */

#ifdef __MMI_DUAL_MIC_SUPPORT__
    ReadValue(NVRAM_UCM_DUAL_MIC_MODE, &mode, DS_BYTE, &errorCode);
    if (mode > 1)
    {
        mode = 0;
        WriteValue(NVRAM_UCM_DUAL_MIC_MODE, &mode, DS_BYTE, &errorCode);
    }
    mmi_core_ucm_p->call_misc.is_noice_reduction = mode;
#endif /* __MMI_DUAL_MIC_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_core_ucm_reset_index_list
 * DESCRIPTION
 *  Reset index list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_core_ucm_reset_index_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&mmi_core_ucm_p->call_misc.index_list, -1, (SRV_UCM_MAX_CALL * sizeof(srv_ucm_index_info_struct)));
}


/* ==================================================================================== */
/* =============kernel tone related=========================================================== */
/* ==================================================================================== */

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_play_inband_tone
 * DESCRIPTION
 *  play inband tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_play_inband_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_ring_type_enum ring_type = SRV_PROF_RING_TYPE_ONCE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_RING_TYPE, &ring_type);

    srv_prof_play_tone_with_id(
            SRV_PROF_TONE_INCOMING_CALL,
            TONE_RINGING_CALL_GSM,
            ring_type,
            NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_stop_inband_tone
 * DESCRIPTION
 *  stop inband tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_stop_inband_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_prof_stop_tone(SRV_PROF_TONE_INCOMING_CALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_play_waiting_tone
 * DESCRIPTION
 *  play waiting tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_play_waitingtone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_ring_type_enum ring_type = SRV_PROF_RING_TYPE_ONCE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_RING_TYPE, &ring_type);

    srv_prof_play_tone_with_id(
            SRV_PROF_TONE_WAITING_CALL,
            TONE_CALL_WAITING,
            ring_type,
            NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_stop_waiting_tone
 * DESCRIPTION
 *  stop waiting tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_stop_waitingtone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_prof_stop_tone(SRV_PROF_TONE_WAITING_CALL);
}

#ifdef __MMI_CALLSET_CALLTIME_REMINDER__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_call_time_reminder
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_call_time_reminder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_ctr_struct ctr_info;
    srv_callset_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_callset_ctr_get_mode(&ctr_info);
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_CALL_TIME_REMINDER_P1, ctr_info.mode);
    if ((result != SRV_CALLSET_RESULT_OK) ||
        (ctr_info.mode == SRV_CALLSET_CTR_MODE_OFF))
    {
        return;
    }

    if (srv_ucm_query_call_count((srv_ucm_call_state_enum)(SRV_UCM_ACTIVE_STATE | SRV_UCM_HOLD_STATE), SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
        srv_prof_play_tone(SRV_PROF_TONE_CALL_REMINDER, NULL);

        if (ctr_info.mode == SRV_CALLSET_CTR_MODE_PERIODIC)
        {
            StartTimer(CM_CTR_TIMER, (1000 * ctr_info.time), mmi_ucm_call_time_reminder);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_call_time_reminder_hdlr
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_call_time_reminder_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_ctr_struct ctr_info;
    srv_callset_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_callset_ctr_get_mode(&ctr_info);
    if ((result == SRV_CALLSET_RESULT_OK) &&
        (ctr_info.mode != SRV_CALLSET_CTR_MODE_OFF) &&
        (IsMyTimerExist(CM_CTR_TIMER) == MMI_FALSE))
    {
        StartTimer(CM_CTR_TIMER, (1000 * ctr_info.time), mmi_ucm_call_time_reminder);
    }
}

#endif

#ifdef __MMI_CONNECT_NOTICE__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_play_connect_notice_with_vib
 * DESCRIPTION
 *  play connect notice tone and vibration
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_play_connect_notice_with_vib(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL connect_notice_is_on;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    connect_notice_is_on = srv_callset_connect_notice_get_mode();

    if (connect_notice_is_on)
    {
        srv_vibrator_on();
        srv_prof_play_tone(SRV_PROF_TONE_CONNECT, NULL);
        StartTimer(CM_VIB_NOTIFYDURATION_TIMER, MMI_UCM_VIB_WHEN_CONNECT_DURATION, mmi_ucm_stop_connect_vibration);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_play_connect_notice
 * DESCRIPTION
 *  Play connect notice tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_play_connect_notice(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL connect_notice_is_on;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    connect_notice_is_on = srv_callset_connect_notice_get_mode();

    if (connect_notice_is_on)
    {
        srv_prof_play_tone(SRV_PROF_TONE_CONNECT, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_stop_connect_vibration
 * DESCRIPTION
 *  Stop the vibration when connected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_stop_connect_vibration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(CM_VIB_NOTIFYDURATION_TIMER);
    srv_vibrator_off();
}
#endif /* __MMI_CONNECT_NOTICE__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_play_tone_with_text
 * DESCRIPTION
 *  play text tone, it's for intelligent call alert feature
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_play_tone_with_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __GENERAL_TTS__
	srv_ucm_call_info_struct call_info;
    MMI_BOOL setting_type = MMI_FALSE;
    S32 string_len;
    S32 symbol_len = 0;
#endif /* __GENERAL_TTS__ */
    srv_ucm_id_info_struct call_uid;
    srv_ucm_caller_res_struct* res_info = NULL;
    srv_prof_ring_type_enum ring_type = SRV_PROF_RING_TYPE_ONCE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GENERAL_TTS__
    setting_type = mmi_tts_setting_is_call_tts_enabled();

    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL,  mmi_core_ucm_p->call_misc.index_list) != 1)
    {
        MMI_ASSERT(0);
    }
    srv_ucm_query_call_data(mmi_core_ucm_p->call_misc.index_list[0], &call_info);

    if ((MMI_TRUE == setting_type) && (mmi_ucs2strlen((CHAR*)call_info.remote_info.disp_name) > 0))
    {
        string_len = mmi_ucs2strlen(GetString(STR_ID_UCM_VOICE_INCOMING));

        if (mmi_core_ucm_p->call_misc.speechText!= NULL)
        {
            OslMfree(mmi_core_ucm_p->call_misc.speechText);
        }

    #ifdef IFLY_TTS
        symbol_len = mmi_ucs2strlen((CHAR*)L"[n1]");
    #endif /* IFLY_TTS */

        mmi_core_ucm_p->call_misc.speechText = OslMalloc((SRV_UCM_MAX_DISP_NAME_LEN + string_len + symbol_len * 2 + 1) * ENCODING_LENGTH);

    #ifdef IFLY_TTS
        mmi_ucs2ncpy(
            (CHAR*)(mmi_core_ucm_p->call_misc.speechText),
            (CHAR*) L"[n1]",
            symbol_len);

        if (!strcmp((CHAR*) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_ENGLISH))
        {
            mmi_ucs2ncat(
                (CHAR*)(mmi_core_ucm_p->call_misc.speechText),
                (CHAR*) L"[g2]",
                symbol_len);
        }
    #endif /* IFLY_TTS */

        mmi_ucs2ncat(
            (CHAR*)(mmi_core_ucm_p->call_misc.speechText),
            (CHAR*) call_info.remote_info.disp_name,
            mmi_ucs2strlen((CHAR*)call_info.remote_info.disp_name));

        mmi_ucs2ncat(
            (CHAR*)(mmi_core_ucm_p->call_misc.speechText), 
            GetString(STR_ID_UCM_VOICE_INCOMING),
            (U32)string_len);

        srv_prof_play_tone_with_text(SRV_PROF_TONE_INCOMING_CALL,
                                     mmi_core_ucm_p->call_misc.speechText,
                                     100,
                                     mmi_ucm_play_tone_with_text_callback);

    }
    else
#endif /* __GENERAL_TTS__ */
    {
        if (MMI_FALSE == mmi_ucm_get_call_id_by_call_state_and_type(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, &call_uid))
        {
            return;
        }
        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_RING_TYPE, &ring_type);

        res_info = OslMalloc(sizeof(srv_ucm_caller_res_struct));
        res_info->res_type = (srv_ucm_res_type_enum)0;
        srv_ucm_get_caller_res_info(call_uid, res_info);

        if (SRV_UCM_RES_TYPE_TONE_PATH & res_info->res_type)
        {
            srv_prof_play_tone_with_filepath(
                SRV_PROF_TONE_INCOMING_CALL, 
                res_info->tone_path,
                ring_type,
                NULL);
        }
        else
        {
            srv_prof_play_tone_with_id(
                    SRV_PROF_TONE_INCOMING_CALL,
                    res_info->tone_id,
                    ring_type,
                    NULL);
        }
        
        OslMfree(res_info);
    }
}


#ifdef __GENERAL_TTS__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_play_tone_with_text_callback
 * DESCRIPTION
 *  play tone with call text callback
 * PARAMETERS
 *  result          [IN]            Play text result
 * RETURNS
 *  void
 *****************************************************************************/
srv_prof_ret mmi_ucm_play_tone_with_text_callback(srv_prof_ret result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PLAY_TONE_WITH_TEXT_CALLBACK, result);

    if (result == SRV_PROF_RET_PLAY_FINISHED)
    {
        if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, mmi_core_ucm_p->call_misc.index_list) != 1 ||
            (mmi_core_ucm_p->replay_query.query_callback != NULL &&
             mmi_core_ucm_p->replay_query.query_callback() != MMI_UCM_TTS_REPLAY_QUERY_YES))
        {
            return SRV_PROF_RET_NO;
        }
        mmi_ucm_play_tone_with_text();
    }
    else if (result == SRV_PROF_RET_TRY_TO_RECOVER)
    {
        return SRV_PROF_RET_YES;
    }

    /* prof won't care this return value . only care return value for SRV_PROF_RET_TRY_TO_RECOVER case */
    return SRV_PROF_RET_NO;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_tts_replay_query_callback
 * DESCRIPTION
 *  Set TTS replay query callback function
 * PARAMETERS
 *  func                 [IN]    TTS replay query callback function
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_tts_replay_query_callback(mmi_ucm_core_tts_replay_query_callback func)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_core_ucm_p->replay_query.query_callback = func;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_free_speechText
 * DESCRIPTION
 *  Free speechText
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_free_speechText(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_core_ucm_p->call_misc.speechText!= NULL)
    {
        OslMfree(mmi_core_ucm_p->call_misc.speechText);
        mmi_core_ucm_p->call_misc.speechText = NULL;
    }
}
#endif /* __GENERAL_TTS__ */


/* ==================================================================================== */
/* =============Permit related========================================================= */
/* ==================================================================================== */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_pass_answer_permit
 * DESCRIPTION
 *  check answer related permit (SRV_UCM_ACCEPT_ACT-> SRV_UCM_HOLD_AND_ACCEPT_ACT -> SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT)
 * PARAMETERS
 *  check_act_req          [IN]           information for permit check
 *  first_pass_act_op          [IN]       the first passed OP code (action). if all answer permit op code are not passed, will keep its original value.
 *  first_result          [IN]            the return result for first passed op code. if all answer permit op code are not passed, will keep its original value.
 * RETURNS
 *  return MMI_TRUE means that the permit is passed
 *****************************************************************************/
MMI_BOOL mmi_ucm_pass_answer_permit(srv_ucm_single_call_act_req_struct *check_act_req, srv_ucm_act_opcode_enum *first_pass_act_op, srv_ucm_result_enum *first_result)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum permit_result = SRV_UCM_RESULT_UNSPECIFIED_ERROR;
    srv_ucm_hold_and_accept_act_req_struct hold_and_accept_req;
    S32 group_index_array[SRV_UCM_MAX_GROUP];
    srv_ucm_group_info_struct group_info;
    MMI_BOOL is_checked = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* 1. check if it's ECC, not allow accept when ECC exists */
    /* disallow user to answer incoming call when ECC exists */
    if (MMI_TRUE == srv_ucm_is_emergency_call())  
    {
        *first_pass_act_op = SRV_UCM_NO_ACT;
        *first_result = SRV_UCM_RESULT_SOS_CALL_EXISTS;
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PASS_ANSWER_PERMIT_P3, MMI_FALSE, *first_pass_act_op, *first_result);
        return MMI_FALSE;
    }

    /*2. Check Accept first*/
    if (!(check_act_req->action_uid.call_type & MMI_UCM_CALL_TYPE_FOR_SOLE_EXISTENCE) ||
        ((check_act_req->action_uid.call_type & MMI_UCM_CALL_TYPE_FOR_SOLE_EXISTENCE) && (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 1))
       )
    {
        if ((permit_result = srv_ucm_query_act_permit(SRV_UCM_ACCEPT_ACT, check_act_req)) == SRV_UCM_RESULT_OK)
        {
            *first_pass_act_op = SRV_UCM_ACCEPT_ACT;
            *first_result = permit_result;

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PASS_ANSWER_PERMIT_P3, MMI_TRUE, *first_pass_act_op, *first_result);
            return MMI_TRUE;        
        }
        *first_result = permit_result;
        is_checked = MMI_TRUE;   
    }
    
    /* 2. Check Hold and accept */
    /* because hold and accept need active call parameter, so need query info here */
    if (!(check_act_req->action_uid.call_type & MMI_UCM_CALL_TYPE_FOR_SOLE_EXISTENCE) &&
        (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, MMI_UCM_CALL_TYPE_FOR_SOLE_EXISTENCE, NULL) == 0) &&  /* Check existed call status */
        srv_ucm_query_group_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, group_index_array) == 1)
    {
        if( srv_ucm_query_group_data(group_index_array[0], &group_info) <= 0)
        {
            MMI_ASSERT(0);
        }
                
        hold_and_accept_req.active_call_type = group_info.call_type;
        hold_and_accept_req.active_group = group_info.group_id;
        memcpy(&hold_and_accept_req.mt_call_uid, &(check_act_req->action_uid), sizeof(srv_ucm_id_info_struct));

        if ((permit_result = srv_ucm_query_act_permit(SRV_UCM_HOLD_AND_ACCEPT_ACT, &hold_and_accept_req)) == SRV_UCM_RESULT_OK)
        {
            *first_pass_act_op = SRV_UCM_HOLD_AND_ACCEPT_ACT;
            *first_result = permit_result;
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PASS_ANSWER_PERMIT_P3, MMI_TRUE, *first_pass_act_op, *first_result);
            return MMI_TRUE;   
        }

        if (MMI_FALSE == is_checked)
        {
            *first_result = permit_result;
            is_checked = MMI_TRUE;
        }        
    }

    /* for CSD < voice */    
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, MMI_UCM_EXIST_CALL_TYPE_FOR_CHECK_END_ALL, NULL) > 0)
    {
        /* 3. Check end all active and accept */
        if ((permit_result = srv_ucm_query_act_permit(SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT, check_act_req)) == SRV_UCM_RESULT_OK)
        {
            *first_pass_act_op = SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT;
            *first_result = permit_result;
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PASS_ANSWER_PERMIT_P3, MMI_TRUE, *first_pass_act_op, *first_result);
            return MMI_TRUE;   
        }

        /* 4. Check end all and accept */
        if ((permit_result = srv_ucm_query_act_permit(SRV_UCM_END_ALL_AND_ACCEPT_ACT, check_act_req)) == SRV_UCM_RESULT_OK)
        {
            *first_pass_act_op = SRV_UCM_END_ALL_AND_ACCEPT_ACT;
            *first_result = permit_result;
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PASS_ANSWER_PERMIT_P3, MMI_TRUE, *first_pass_act_op, *first_result);
            return MMI_TRUE;      
        }

        if (MMI_FALSE == is_checked)
        {
            *first_result = permit_result;
        }
    } 
    /* not assign first_pass_act_op, keep the op as previous ones */
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PASS_ANSWER_PERMIT_P3, MMI_FALSE, *first_pass_act_op, *first_result);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_pass_dial_permit
 * DESCRIPTION
 *  check dial related permit (SRV_UCM_DIAL_ACT-> ECC SRV_UCM_END_ALL_AND_DIAL_ACT-> SRV_UCM_HOLD_AND_DIAL_ACT -> SRV_UCM_END_ALL_AND_DIAL_ACT)
 * PARAMETERS
 *  check_act_req          [IN]           information for permit check
 *  first_pass_act_op          [IN]       the first passed OP code (action). if all dial permit op code are not passed, will keep its original value.
 *  first_result          [IN]            the return result for first passed op code. if all dial permit op code are not passed, will keep its original value.
 * RETURNS
 *  return MMI_TRUE means that the permit is passed
 *****************************************************************************/
MMI_BOOL mmi_ucm_pass_dial_permit(srv_ucm_dial_act_req_struct *check_act_req, srv_ucm_act_opcode_enum *first_pass_act_op, srv_ucm_result_enum *first_result)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum permit_result = SRV_UCM_RESULT_UNSPECIFIED_ERROR;
    MMI_BOOL is_checked = MMI_FALSE;
    srv_ucm_hold_and_dial_act_req_struct hold_and_dial_req;
    S32 group_index_array[SRV_UCM_MAX_GROUP];
    srv_ucm_group_info_struct group_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* first_pass_act_op: if any one permit is passed, this para will keep the 1st pass op. but if all fail to pass. will keep its original value */
    /* first_result: should return the first fail result. */
    
    /* 1. Check Dial first */
    /* if there is already held call, */
    if (!(check_act_req->call_type & MMI_UCM_CALL_TYPE_FOR_SOLE_EXISTENCE) ||
        ((check_act_req->call_type & MMI_UCM_CALL_TYPE_FOR_SOLE_EXISTENCE) && (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0))
       )
    {

        if ((permit_result = srv_ucm_query_act_permit(SRV_UCM_DIAL_ACT, check_act_req)) == SRV_UCM_RESULT_OK)
        {
            *first_pass_act_op = SRV_UCM_DIAL_ACT;
            *first_result = permit_result;
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PASS_DIAL_PERMIT_P3, check_act_req->call_type, *first_pass_act_op, *first_result);
            return MMI_TRUE;        
        }
        *first_result = permit_result;
        is_checked = MMI_TRUE;
    }
    
    /* 2. Check End all and dial */
    /* check ECC here is just for  double-confirm, should filter in call launch steps beofre this api is called*/
    if (mmi_ucm_is_emergency_number(check_act_req->call_type, check_act_req->num_uri))
    {
        if ((permit_result = srv_ucm_query_act_permit(SRV_UCM_END_ALL_AND_DIAL_ACT, check_act_req)) == SRV_UCM_RESULT_OK)
        {
            *first_pass_act_op = SRV_UCM_END_ALL_AND_DIAL_ACT;
            *first_result = permit_result;
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PASS_DIAL_PERMIT_P3, check_act_req->call_type, *first_pass_act_op, *first_result);
            return MMI_TRUE;         
        }
        if (MMI_FALSE == is_checked)
        {
            *first_result = permit_result;
            is_checked = MMI_TRUE;
        }
    }

    /* 3. Check Hold and dial */
    /* because hold and dila need active call parameter, so need query info here*/
    if (!(check_act_req->call_type & MMI_UCM_CALL_TYPE_FOR_SOLE_EXISTENCE) &&  /* Check MO call type */
        (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, MMI_UCM_CALL_TYPE_FOR_SOLE_EXISTENCE, NULL) == 0) &&  /* Check existed call status */
        (srv_ucm_query_group_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, group_index_array) == 1))
    {
        if( srv_ucm_query_group_data(group_index_array[0], &group_info) <= 0)
        {
            MMI_ASSERT(0);
        }
    
        memset(&hold_and_dial_req, 0, sizeof(srv_ucm_hold_and_dial_act_req_struct));
        hold_and_dial_req.active_call_type = group_info.call_type;
        hold_and_dial_req.active_group = group_info.group_id;
        hold_and_dial_req.dial_call_type = check_act_req->call_type;
        hold_and_dial_req.is_ip_dial = check_act_req->is_ip_dial;
        hold_and_dial_req.module_id = check_act_req->module_id;
        hold_and_dial_req.phb_data = check_act_req->phb_data;
        mmi_ucs2cpy((CHAR*)hold_and_dial_req.num_uri, (CHAR*)check_act_req->num_uri);
        
        if ((permit_result = srv_ucm_query_act_permit(SRV_UCM_HOLD_AND_DIAL_ACT, &hold_and_dial_req)) == SRV_UCM_RESULT_OK)
        {
            *first_pass_act_op = SRV_UCM_HOLD_AND_DIAL_ACT;
            *first_result = permit_result;
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PASS_DIAL_PERMIT_P3, check_act_req->call_type, *first_pass_act_op, *first_result);
            return MMI_TRUE;                 
        }              

        if (MMI_FALSE == is_checked)
        {
            *first_result = permit_result;
            is_checked = MMI_TRUE;
        }
    }

    /* 4. Check end all and dial */
    /* CSD < voice call -- when CSD exist, will allow to dial a voice/VT call*/  
     
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, MMI_UCM_EXIST_CALL_TYPE_FOR_CHECK_END_ALL, NULL) > 0)
    {
        if ((permit_result = srv_ucm_query_act_permit(SRV_UCM_END_ALL_AND_DIAL_ACT, check_act_req)) == SRV_UCM_RESULT_OK)
        {
            *first_pass_act_op = SRV_UCM_END_ALL_AND_DIAL_ACT;
            *first_result = permit_result;
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PASS_DIAL_PERMIT_P3, check_act_req->call_type, *first_pass_act_op, *first_result);
            return MMI_TRUE;         
        }
        if (MMI_FALSE == is_checked)
        {
            *first_result = permit_result;
        }
    }
    /* if all not ok, return no act and the last error result */
    /* not assign first_pass_act_op, keep the op as previous ones */
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PASS_DIAL_PERMIT_P3, check_act_req->call_type, *first_pass_act_op, *first_result);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_query_sndrec_permit
 * DESCRIPTION
 *  Check if Sound Recorder is permitted during call(Check if exist any call can be Recorded).
 * PARAMETERS
 *  void
 * RETURNS
 *  SRV_UCM_RESULT_OK means Sound Recorder is permitted during call;
 *  else means that is not permitted.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_query_sndrec_permit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_index_info_struct index;
    srv_ucm_call_info_struct call_info;
    srv_ucm_id_info_struct call_uid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_NO_DATA_CSD, mmi_core_ucm_p->call_misc.index_list) > 0)
    {
        index.group_index = mmi_core_ucm_p->call_misc.index_list[0].group_index;
        index.call_index = mmi_core_ucm_p->call_misc.index_list[0].call_index;

        if (srv_ucm_query_call_data(index, &call_info))
        {
            memcpy(&call_uid, &(call_info.uid_info), sizeof(srv_ucm_id_info_struct));

            if (MMI_TRUE == srv_ucm_query_sndrec_permit(call_uid))
            {
                return SRV_UCM_RESULT_OK;
            }
        }
    }
    return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
}


/* ==================================================================================== */
/* =============Option related========================================================= */
/* ==================================================================================== */
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_act_request_callback
 * DESCRIPTION
 *  Set action request callback function
 * PARAMETERS
 *  func                 [IN]    Action request callback function
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_act_request_callback(mmi_proc_func func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_core_ucm_p->act_request.act_req_callback = func;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_act_request_dial_user_data
 * DESCRIPTION
 *  Set action request dial user data
 * PARAMETERS
 *  user_data                 [IN]    Dial user data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_act_request_dial_user_data(void *user_data)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_core_ucm_p->act_request.dial_user_data = user_data;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_number_info
 * DESCRIPTION
 *  Set number
 * PARAMETERS
 *  num_uri                 [IN]    number pointer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_number_info(U16 *num_uri)
{
    if (num_uri != NULL)
    {
        mmi_ucs2ncpy((CHAR*)mmi_core_ucm_p->num_info.num_uri, (CHAR*)num_uri, SRV_UCM_MAX_NUM_URI_LEN);       
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_dial_option
 * DESCRIPTION
 *  Check if dial action can be executed or not.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK    
 * RETURNS
 *  SRV_UCM_RESULT_OK means dial action can be executed
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_dial_option(srv_ucm_dial_act_req_struct *check_act_req, mmi_ucm_check_type_enum exec_act_flag)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum temp_result = SRV_UCM_RESULT_OK;
    srv_ucm_act_opcode_enum first_permit_act_op = SRV_UCM_NO_ACT;
    srv_ucm_result_enum first_permit_result = SRV_UCM_RESULT_UNSPECIFIED_ERROR;
    srv_ucm_hold_and_dial_act_req_struct hold_and_dial_req;
    S32 group_index_array[SRV_UCM_MAX_GROUP];
    srv_ucm_group_info_struct group_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* first_pass_act_op: if any one permit is passed, this para will keep the 1st pass op. but if all fail to pass. will keep its original value */
    /* first_result: should return the first fail result. */

    do
    {   /* 1. Check Dial first */
        /* if there is already held call, */
    #ifdef __MMI_VIDEO_TELEPHONY__
        if (!(check_act_req->call_type & MMI_UCM_CALL_TYPE_FOR_SOLE_EXISTENCE) ||
            ((check_act_req->call_type & MMI_UCM_CALL_TYPE_FOR_SOLE_EXISTENCE) && (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0)))
    #endif /* __MMI_VIDEO_TELEPHONY__ */
        {
            if ((first_permit_result = srv_ucm_query_act_permit(SRV_UCM_DIAL_ACT, check_act_req)) == SRV_UCM_RESULT_OK)
            {
                first_permit_act_op = SRV_UCM_DIAL_ACT;
                break;
            }
            temp_result = first_permit_result;
        }

    #ifdef __MMI_UCM_ECC_BEST_EFFORT__
        /* 2. Check End all and dial */
        /* check ECC here is just for  double-confirm, should filter in call launch steps beofre this api is called*/
        if (mmi_ucm_is_emergency_number(check_act_req->call_type, check_act_req->num_uri))
        {
            if ((first_permit_result = srv_ucm_query_act_permit(SRV_UCM_END_ALL_AND_DIAL_ACT, check_act_req)) == SRV_UCM_RESULT_OK)
            {
                first_permit_act_op = SRV_UCM_END_ALL_AND_DIAL_ACT;
                break;
            }

            if (SRV_UCM_RESULT_OK != temp_result)
            {
                first_permit_result = temp_result;
            }
            else
            {
                temp_result = first_permit_result;
            }
        }
    #endif /* __MMI_UCM_ECC_BEST_EFFORT__ */

        /* 3. Check Hold and dial */
        /* because hold and dila need active call parameter, so need query info here*/
        if (
        #ifdef __MMI_VIDEO_TELEPHONY__
            !(check_act_req->call_type & MMI_UCM_CALL_TYPE_FOR_SOLE_EXISTENCE) &&  /* Check MO call type */
            (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, MMI_UCM_CALL_TYPE_FOR_SOLE_EXISTENCE, NULL) == 0) &&  /* Check existed call status */
        #endif /* __MMI_VIDEO_TELEPHONY__ */
            (srv_ucm_query_group_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, group_index_array) == 1)
           )
        {
            if( srv_ucm_query_group_data(group_index_array[0], &group_info) <= 0)
            {
                MMI_ASSERT(0);
            }
        
            hold_and_dial_req.active_call_type = group_info.call_type;
            hold_and_dial_req.active_group = group_info.group_id;
            hold_and_dial_req.dial_call_type = check_act_req->call_type;
            hold_and_dial_req.is_ip_dial = check_act_req->is_ip_dial;
            hold_and_dial_req.module_id = check_act_req->module_id;
            hold_and_dial_req.phb_data = check_act_req->phb_data;
            mmi_ucs2cpy((CHAR*)hold_and_dial_req.num_uri, (CHAR*)check_act_req->num_uri);
            
            if ((first_permit_result = srv_ucm_query_act_permit(SRV_UCM_HOLD_AND_DIAL_ACT, &hold_and_dial_req)) == SRV_UCM_RESULT_OK)
            {
                first_permit_act_op = SRV_UCM_HOLD_AND_DIAL_ACT;
                break;
            }

            if (SRV_UCM_RESULT_OK != temp_result)
            {
                first_permit_result = temp_result;
            }
            else
            {
                temp_result = first_permit_result;
            }
        }

        /* 4. Check end all and dial */
        /* CSD < voice call -- when CSD exist, will allow to dial a voice/VT call*/

        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, MMI_UCM_EXIST_CALL_TYPE_FOR_CHECK_END_ALL, NULL) > 0)
        {
            if ((first_permit_result = srv_ucm_query_act_permit(SRV_UCM_END_ALL_AND_DIAL_ACT, check_act_req)) == SRV_UCM_RESULT_OK)
            {
                first_permit_act_op = SRV_UCM_END_ALL_AND_DIAL_ACT;
                break;
            }
            if (SRV_UCM_RESULT_OK != temp_result)
            {
                first_permit_result = temp_result;
            }
        }
    }while(0);


    if ((MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag) && (SRV_UCM_RESULT_OK == first_permit_result))
    {
        if (SRV_UCM_HOLD_AND_DIAL_ACT == first_permit_act_op)
        {
            srv_ucm_act_request(first_permit_act_op, &hold_and_dial_req, mmi_core_ucm_p->act_request.dial_user_data, mmi_core_ucm_p->act_request.act_req_callback);
        }
        else
        {
            srv_ucm_act_request(first_permit_act_op, check_act_req, mmi_core_ucm_p->act_request.dial_user_data, mmi_core_ucm_p->act_request.act_req_callback);
        }
    }
    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PASS_DIAL_PERMIT_P3, check_act_req->call_type, first_permit_act_op, first_permit_result);
    return first_permit_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_outgoing_dialer_option
 * DESCRIPTION
 *  Check if dialer option can be displayed in the outgoing call option.
 * PARAMETERS
 *     
 * RETURNS
 *  SRV_UCM_RESULT_OK means dialer option should show;
 *  else the menu should be hidden.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_outgoing_dialer_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_VOIP_CALL_TYPE | SRV_UCM_VIDEO_CALL_TYPE_ALL), NULL) > 0)
    {
        return SRV_UCM_RESULT_OK;
    }
    return SRV_UCM_RESULT_UNSPECIFIED_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_answer_option
 * DESCRIPTION
 *  Check if answer option can be displayed in the incoming call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK    
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_answer_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_single_call_act_req_struct check_act_req;
    srv_ucm_hold_and_accept_act_req_struct hold_and_accept_req;
    S32 group_index_array[SRV_UCM_MAX_GROUP];
    srv_ucm_group_info_struct group_info;
    srv_ucm_act_opcode_enum first_permit_act_op = SRV_UCM_NO_ACT;
    srv_ucm_result_enum temp_result = SRV_UCM_RESULT_OK;
    srv_ucm_result_enum first_permit_result = SRV_UCM_RESULT_UNSPECIFIED_ERROR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check there is a incoming call */
    if (MMI_FALSE == mmi_ucm_get_call_id_by_call_state_and_type(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, &check_act_req.action_uid))
    {
        return SRV_UCM_RESULT_UNSPECIFIED_ERROR;
    }

    /* Check if it's ECC, not allow accept when ECC exists */
    if (MMI_TRUE == srv_ucm_is_emergency_call())
    {
        first_permit_result = SRV_UCM_RESULT_SOS_CALL_EXISTS;
    }
    else
    {
        do
        {
            /* 1. Check Accept first */
        #ifdef __MMI_VIDEO_TELEPHONY__
            if (!(check_act_req.action_uid.call_type & MMI_UCM_CALL_TYPE_FOR_SOLE_EXISTENCE) ||
                ((check_act_req.action_uid.call_type & MMI_UCM_CALL_TYPE_FOR_SOLE_EXISTENCE) && (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 1)))
        #endif /* __MMI_VIDEO_TELEPHONY__ */
            {
                if ((first_permit_result = srv_ucm_query_act_permit(SRV_UCM_ACCEPT_ACT, &check_act_req)) == SRV_UCM_RESULT_OK)
                {
                    first_permit_act_op = SRV_UCM_ACCEPT_ACT;
                    break;
                }
                temp_result = first_permit_result;
            }

            /* 2. Check Hold and accept */
            /* because hold and accept need active call parameter, so need query info here */
            if (
            #ifdef __MMI_VIDEO_TELEPHONY__
                !(check_act_req.action_uid.call_type & MMI_UCM_CALL_TYPE_FOR_SOLE_EXISTENCE) &&
                (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, MMI_UCM_CALL_TYPE_FOR_SOLE_EXISTENCE, NULL) == 0) &&  /* Check existed call status */
            #endif /* __MMI_VIDEO_TELEPHONY__ */
                (srv_ucm_query_group_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, group_index_array) == 1)
               )
            {
                if( srv_ucm_query_group_data(group_index_array[0], &group_info) <= 0)
                {
                    MMI_ASSERT(0);
                }

                hold_and_accept_req.active_call_type = group_info.call_type;
                hold_and_accept_req.active_group = group_info.group_id;
                memcpy(&hold_and_accept_req.mt_call_uid, &(check_act_req.action_uid), sizeof(srv_ucm_id_info_struct));

                if ((first_permit_result = srv_ucm_query_act_permit(SRV_UCM_HOLD_AND_ACCEPT_ACT, &hold_and_accept_req)) == SRV_UCM_RESULT_OK)
                {
                    first_permit_act_op = SRV_UCM_HOLD_AND_ACCEPT_ACT;
                    break;
                }
                if (SRV_UCM_RESULT_OK != temp_result)
                {
                    first_permit_result = temp_result;
                }
                else
                {
                    temp_result = first_permit_result;
                }
            }

            /* for CSD < voice */
            if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, MMI_UCM_EXIST_CALL_TYPE_FOR_CHECK_END_ALL, NULL) > 0)
            {
                /* 3. Check end all active and accept */
                if ((first_permit_result = srv_ucm_query_act_permit(SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT, &check_act_req)) == SRV_UCM_RESULT_OK)
                {
                    first_permit_act_op = SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT;
                    break;
                }

                /* 4. Check end all and accept */
                if ((first_permit_result = srv_ucm_query_act_permit(SRV_UCM_END_ALL_AND_ACCEPT_ACT, &check_act_req)) == SRV_UCM_RESULT_OK)
                {
                    first_permit_act_op = SRV_UCM_END_ALL_AND_ACCEPT_ACT;
                    break;
                }

                if (SRV_UCM_RESULT_OK != temp_result)
                {
                    first_permit_result = temp_result;
                }
            }
        }while (0);
    }

    if ((MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag) && (SRV_UCM_RESULT_OK == first_permit_result))
    {
        if (SRV_UCM_HOLD_AND_ACCEPT_ACT == first_permit_act_op)
        {
            srv_ucm_act_request(first_permit_act_op, &hold_and_accept_req, NULL, mmi_core_ucm_p->act_request.act_req_callback);
        }
        else
        {
            srv_ucm_act_request(first_permit_act_op, &check_act_req, NULL, mmi_core_ucm_p->act_request.act_req_callback);
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, first_permit_act_op, first_permit_result);
    return first_permit_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_incoming_dialer_option
 * DESCRIPTION
 *  Check if dialer option can be displayed in the incoming call option.
 * PARAMETERS
 *     
 * RETURNS
 *  SRV_UCM_RESULT_OK means dialer option should show;
 *  else the menu should be hidden.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_incoming_dialer_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_VOIP_CALL_TYPE), NULL) > 1)
    {
        return SRV_UCM_RESULT_OK;
    }
    return SRV_UCM_RESULT_UNSPECIFIED_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_multiple_group_option
 * DESCRIPTION
 *  Check if multiple group related action can be executed. Include related action:
 *  SRV_UCM_SWAP_ACT/SRV_UCM_CONFERENCE_ACT
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK 
 * RETURNS
 *  SRV_UCM_RESULT_OK means multiple group related action can be executed;
 *  else means can not be executed.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_multiple_group_option(srv_ucm_act_opcode_enum opcode, mmi_ucm_check_type_enum exec_act_flag, MMI_BOOL *is_act_executed)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_ucm_multiple_group_act_req_struct check_act_req_multiple;
	srv_ucm_group_info_struct group_info;
	srv_ucm_index_info_struct index;
	srv_ucm_call_info_struct call_info;
    srv_ucm_call_type_enum call_type = SRV_UCM_CALL_TYPE_NO_DATA_CSD;
	S32 group_count;
	S32 group_index_array[SRV_UCM_MAX_GROUP];
	srv_ucm_result_enum permit_result;
	S32 i;
    
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	MMI_ASSERT(is_act_executed != NULL);
	
	permit_result = SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
	*is_act_executed = MMI_FALSE;

	/* 1. get hilite call info */
	index.group_index = mmi_core_ucm_p->call_misc.hilite_group_index;
	index.call_index = mmi_core_ucm_p->call_misc.hilite_call_index;
	MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_UID_INFO_P4, opcode, index.group_index, index.call_index, 0);
	
	if (MMI_TRUE == srv_ucm_query_call_data(index, &call_info))
	{
		/* 1. if hilited call is active, find all held calls.  check each's permit. */
		if (call_info.call_state == SRV_UCM_ACTIVE_STATE)
		{
			check_act_req_multiple.active_call_type = call_info.uid_info.call_type;
			check_act_req_multiple.active_group = call_info.uid_info.group_id;
			if (SRV_UCM_CONFERENCE_ACT == opcode)
            {
                call_type = check_act_req_multiple.active_call_type;
            }
			group_count = srv_ucm_query_group_count(SRV_UCM_HOLD_STATE, call_type, MMI_FALSE, group_index_array);	
			
			i = 0;
			while (i < group_count)
			{
				srv_ucm_query_group_data(group_index_array[i], &group_info);           
				check_act_req_multiple.other_call_type = group_info.call_type;
				check_act_req_multiple.other_group = group_info.group_id;
				
				if ((permit_result = srv_ucm_query_act_permit(opcode, &check_act_req_multiple)) == SRV_UCM_RESULT_OK)
				{
				    break;   /* if any one is passed, swap option will be shown */
				}
				i++;
			}

			if ((MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag) &&
				(group_count == 1) &&
				(SRV_UCM_RESULT_OK == permit_result))
			{
				*is_act_executed = MMI_TRUE;
				srv_ucm_act_request(opcode, &check_act_req_multiple, NULL, mmi_core_ucm_p->act_request.act_req_callback);
			}
			else if ((SRV_UCM_RESULT_OK == permit_result) && group_count >= 2)
			{
			    *is_act_executed = MMI_FALSE;
			}
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, opcode, permit_result); 
			return permit_result;
		}
		/*2. if hilite call is hold, find active call group */
		else if (call_info.call_state == SRV_UCM_HOLD_STATE)
		{
			check_act_req_multiple.other_call_type = call_info.uid_info.call_type;
			check_act_req_multiple.other_group = call_info.uid_info.group_id;

			if (SRV_UCM_CONFERENCE_ACT == opcode)
            {
                call_type = check_act_req_multiple.other_call_type;
            } 
			/* 3-1. 1A1H in voice call, cannot allow to swap in different call type */
			if (srv_ucm_query_group_count(SRV_UCM_ACTIVE_STATE, call_type, MMI_FALSE, group_index_array) > 0)
			{
				srv_ucm_query_group_data(group_index_array[0], &group_info);
		
				check_act_req_multiple.active_call_type = group_info.call_type;
				check_act_req_multiple.active_group = group_info.group_id;
				permit_result = srv_ucm_query_act_permit(opcode, &check_act_req_multiple);  
		
				if ((MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag) && (SRV_UCM_RESULT_OK == permit_result))
				{
					*is_act_executed = MMI_TRUE;
					srv_ucm_act_request(opcode, &check_act_req_multiple, NULL, mmi_core_ucm_p->act_request.act_req_callback);
				}
			}
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, opcode, permit_result); 
			return permit_result;
		}   		
	}
	else
	{
	    if (MMI_UCM_PERMIT_ONLY != exec_act_flag)  /* because VT will call option check in preview mode */
        {
            MMI_ASSERT(0);
        }      
	}
	return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_single_group_option
 * DESCRIPTION
 *  Check if single group related action can be executed. Include related action:
 *  SRV_UCM_HOLD_ACT/SRV_UCM_RETRIEVE_ACT/SRV_UCM_END_CONFERENCE_ACT
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK 
 * RETURNS
 *  SRV_UCM_RESULT_OK means single group related action can be executed;
 *  else means can not be executed.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_single_group_option(srv_ucm_act_opcode_enum opcode, mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_single_group_act_req_struct check_act_req;
    srv_ucm_group_info_struct group_info;
    srv_ucm_result_enum permit_result = SRV_UCM_RESULT_ACTION_NOT_ALLOWED;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_ucm_query_group_data(mmi_core_ucm_p->call_misc.hilite_group_index, &group_info) > 0)
    {
        check_act_req.action_group = group_info.group_id;
        check_act_req.call_type = group_info.call_type;   
            
        permit_result = srv_ucm_query_act_permit(opcode, &check_act_req);

        if ((MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag) && (SRV_UCM_RESULT_OK == permit_result))
        {
            srv_ucm_act_request(opcode, &check_act_req, NULL, mmi_core_ucm_p->act_request.act_req_callback);
        }
    }
    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, opcode, permit_result); 
    return permit_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_single_call_option
 * DESCRIPTION
 *  Check if single call related action can be executed. Include related action:
 *  SRV_UCM_END_SINGLE_ACT/SRV_UCM_SPLIT_ACT/SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT/SRV_UCM_END_ALL_AND_ACCEPT_ACT
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK 
 * RETURNS
 *  SRV_UCM_RESULT_OK means single call related action can be executed;
 *  else means can not be executed. 
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_single_call_option(srv_ucm_act_opcode_enum opcode, srv_ucm_call_state_enum call_state, mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_single_call_act_req_struct check_act_req_signle;
    srv_ucm_result_enum permit_result = SRV_UCM_RESULT_ACTION_NOT_ALLOWED;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_ucm_get_call_id_by_call_state_and_type(call_state, SRV_UCM_CALL_TYPE_ALL, &(check_act_req_signle.action_uid)))
    {
        permit_result = srv_ucm_query_act_permit(opcode, &check_act_req_signle);

        if ((MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag) && (SRV_UCM_RESULT_OK == permit_result))
        {
            srv_ucm_act_request(opcode, &check_act_req_signle, NULL, mmi_core_ucm_p->act_request.act_req_callback);
        }
    }
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, opcode, permit_result); 
    return permit_result;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_simple_option
 * DESCRIPTION
 *  Check if simple option can be executed. Include related action:
 *  SRV_UCM_END_ALL_ACT/SRV_UCM_END_ALL_ACTIVE_ACT/SRV_UCM_END_ALL_HELD_ACT/SRV_UCM_END_ALL_PROCESSING_ACT
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK 
 * RETURNS
 *  SRV_UCM_RESULT_OK means simple option can be executed;
 *  else means simple option can not be executed. 
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_simple_option(srv_ucm_act_opcode_enum opcode, mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum permit_result;   
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1. Permit check */
    permit_result = srv_ucm_query_act_permit(opcode, NULL);

    /* 2. execute action if necessary */
    if ((MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag) && (SRV_UCM_RESULT_OK == permit_result))
    {
        srv_ucm_act_request(opcode, NULL, NULL, mmi_core_ucm_p->act_request.act_req_callback);
    }
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, opcode, permit_result);
    return permit_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_replace_option
 * DESCRIPTION
 *  Check if replace option can be displayed in the incoming call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK 
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden. 
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_replace_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* replace function only allow in the following casse: */
    /* i. 1 incoming + 1 A for every call type + x held calls, x>=0 */
    /* ii. 1 incoming VT + 1 H MMI_UCM_CALL_TYPE_NO_DATA_CSD */

    /* 1. in no incoming call -- no replace funciton */
    if (srv_ucm_query_group_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_DATA_CSD, MMI_FALSE, NULL) != 1)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, -1, SRV_UCM_RESULT_ACTION_NOT_ALLOWED);
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }

    /* for if 2H1A+MT voice, still show replace */
    if (srv_ucm_query_group_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_NO_DATA_CSD, MMI_FALSE, NULL) != 1)
    {
        /*2. held call exist but incoming is not VT  -- no replace funciton*/
    #ifdef __MMI_VIDEO_TELEPHONY__    
        if (srv_ucm_query_group_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_NO_DATA_CSD, MMI_FALSE, NULL) > 0 &&
            srv_ucm_query_group_count(SRV_UCM_INCOMING_STATE, SRV_UCM_VIDEO_CALL_TYPE_ALL, MMI_FALSE, NULL) == 0)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, -1, SRV_UCM_RESULT_ACTION_NOT_ALLOWED);
            return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
        }
    #else /* __MMI_VIDEO_TELEPHONY__ */
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    #endif /* __MMI_VIDEO_TELEPHONY__ */
    }

    /* 3. disallow user to answer incoming call when ECC exists */
    if (MMI_TRUE == srv_ucm_is_emergency_call())
    {
        return SRV_UCM_RESULT_SOS_CALL_EXISTS;
    }

    /* 4. Permit check */
    /* 4.1 check permit for UCM_SRV_END_ALL_ACTIVE_AND_ACCEPT_ACT first */
    result = mmi_ucm_single_call_option(SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT, SRV_UCM_INCOMING_STATE, exec_act_flag);

    if (SRV_UCM_RESULT_OK != result)
    {
        result = mmi_ucm_single_call_option(SRV_UCM_END_ALL_AND_ACCEPT_ACT, SRV_UCM_INCOMING_STATE, exec_act_flag);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_conference_option
 * DESCRIPTION
 *  Check if end conference option can be displayed in the in-call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden. 
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_end_conference_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum permit_result;   
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_group_data(mmi_core_ucm_p->call_misc.hilite_group_index, NULL) < 2)
    {
        permit_result = SRV_UCM_RESULT_ACTION_NOT_ALLOWED; /*it's NOT a conf call or no call*/
    }
    else
    {
        permit_result = mmi_ucm_single_group_option(SRV_UCM_END_CONFERENCE_ACT, exec_act_flag);
    }

    return permit_result;
}


#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_answer_by_voice_option
 * DESCRIPTION
 *  Check if answer by voice option can be displayed in the incoming call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK    
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer by option option should show;
 *  else the menu should be hidden.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_answer_by_voice_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum permit_result = SRV_UCM_RESULT_ACTION_NOT_ALLOWED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) == srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL))
    {
        permit_result = mmi_ucm_single_call_option(SRV_UCM_VT_FALLTO_VOICE_ACT, SRV_UCM_INCOMING_STATE, exec_act_flag);
    }
    return permit_result;
}
#endif /* (defined(__OP01__) || defined(__MMI_VIDEO_TELEPHONY__)) */


#ifdef __MMI_UCM_DEFLECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_deflect_option
 * DESCRIPTION
 *  Check if deflect option can be displayed in the incoming call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK    
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden. 
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_deflect_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_cd_or_ct_act_req_struct deflect_check_req;
    srv_ucm_result_enum permit_result = SRV_UCM_RESULT_ACTION_NOT_ALLOWED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    if (MMI_TRUE == mmi_ucm_get_call_id_by_call_state_and_type(SRV_UCM_INCOMING_STATE, SRV_UCM_VOICE_CALL_TYPE_ALL, &(deflect_check_req.action_uid)))
    {
        if (MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag)
        {
            mmi_ucs2ncpy((CHAR*)deflect_check_req.num_uri, (CHAR*)mmi_core_ucm_p->num_info.num_uri, SRV_UCM_MAX_NUM_URI_LEN);
        }

        permit_result = srv_ucm_query_act_permit(SRV_UCM_DEFLECT_ACT, &deflect_check_req);

        if ((MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag) && (SRV_UCM_RESULT_OK == permit_result))
        {
            srv_ucm_act_request(SRV_UCM_DEFLECT_ACT, &deflect_check_req, NULL, mmi_core_ucm_p->act_request.act_req_callback);
        }
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, SRV_UCM_DEFLECT_ACT, permit_result);    
    }
    
    return permit_result;
}
#endif /* __MMI_UCM_DEFLECT__ */


#ifdef __MMI_BG_SOUND_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_bk_sound_incoming_option
 * DESCRIPTION
 *  Check if background sound option can be displayed in the incoming call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK  
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden. 
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_bk_sound_incoming_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_id_info_struct call_uid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(exec_act_flag == MMI_UCM_PERMIT_ONLY);

    if (mmi_ucm_get_call_id_by_call_state_and_type(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_DATA_CSD, &call_uid))
    {
        if (MMI_TRUE == srv_ucm_query_bgs_incoming_call_permit(call_uid))
        {
            return SRV_UCM_RESULT_OK;
        }
    }    
    return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
}
#endif /* __MMI_BG_SOUND_EFFECT__ */


#ifdef __MMI_UCM_REDIAL_FROM_OTHER_SIM__    
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_redial_from_other_sim_option
 * DESCRIPTION
 *  Check if redial from other sim option can be displayed in the incoming call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_redial_from_other_sim_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_dial_act_req_struct check_act_req;
    srv_ucm_call_info_struct call_info;    
    srv_ucm_result_enum permit_result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* 1. only allow this when there in only one incoming call and no other call exists */
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) != 1)
    {
        return SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL;
    }
    
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, mmi_core_ucm_p->call_misc.index_list) != 1)
    {
        return SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL;
    }

    /* 2. get original type -- the call type of incoming call, only allow for voice */
    memset(&check_act_req, 0, sizeof(srv_ucm_dial_act_req_struct));
    srv_ucm_query_call_data(mmi_core_ucm_p->call_misc.index_list[0], &call_info);

    if (call_info.uid_info.call_type & SRV_UCM_SIM1_CALL_TYPE_ALL) 
    {
        check_act_req.call_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
    }
    else if (call_info.uid_info.call_type & SRV_UCM_SIM2_CALL_TYPE_ALL) 
    {
        check_act_req.call_type = SRV_UCM_VOICE_CALL_TYPE;
    }
    else
    {
        return SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL;
    }
    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_REDIAL_FROM_OTHER_SIM_OPT_P2, check_act_req.call_type, call_info.remote_info.num_uri);
        
    check_act_req.is_ip_dial = MMI_FALSE;
    check_act_req.module_id = SRV_UCM_MODULE_ORIGIN_COMMON;
    check_act_req.phb_data = NULL;
    mmi_asc_to_ucs2((CHAR*) check_act_req.num_uri, (CHAR*)call_info.remote_info.num_uri);

    /* 3. Permit check */
    permit_result = srv_ucm_query_act_permit(SRV_UCM_END_ALL_AND_DIAL_ACT, &check_act_req);
    
    /* 4. execute action if necessary */
    if ((MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag) && (SRV_UCM_RESULT_OK == permit_result))
    {
        srv_ucm_act_request(SRV_UCM_END_ALL_AND_DIAL_ACT, &check_act_req, mmi_core_ucm_p->act_request.dial_user_data, mmi_core_ucm_p->act_request.act_req_callback);
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, SRV_UCM_END_ALL_AND_DIAL_ACT, permit_result); 
    return permit_result;
}
#endif /* __MMI_UCM_REDIAL_FROM_OTHER_SIM__ */


#if defined(__MMI_UCM_TRANSFER__) || defined(__MMI_UCM_ECT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_transfer_option
 * DESCRIPTION
 *  Check if transfer option can be displayed in the in-call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden. 
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_transfer_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_index_info_struct index;
    srv_ucm_call_info_struct call_info;
    srv_ucm_result_enum permit_result;
#ifdef __MMI_UCM_ECT__  
	srv_ucm_group_info_struct second_group_info;
    S32 group_index_array[SRV_UCM_MAX_GROUP];
    srv_ucm_ect_act_req_struct check_act_req_ect; /* VOICE */
    MMI_BOOL second_group_exist = MMI_FALSE;
#endif /* __MMI_UCM_ECT__ */     
#ifdef __MMI_UCM_TRANSFER__
    srv_ucm_cd_or_ct_act_req_struct check_act_req_transfer; /* VOIP */    
#endif /* __MMI_UCM_TRANSFER__ */    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* 1. Conference call can not use transfer function */
    if (srv_ucm_query_group_data(mmi_core_ucm_p->call_misc.hilite_group_index, NULL) > 1)
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }

    /* 2. get hilite call information */
    index.group_index = mmi_core_ucm_p->call_misc.hilite_group_index;
    index.call_index = mmi_core_ucm_p->call_misc.hilite_call_index;

    memset(&call_info, 0, sizeof(srv_ucm_call_info_struct));
    if (MMI_TRUE == srv_ucm_query_call_data(index, &call_info))
    {
    #ifdef __MMI_UCM_ECT__
        /* 3. if hilited call is voice call, ECT */
        if (call_info.uid_info.call_type & SRV_UCM_VOICE_CALL_TYPE_ALL)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_UID_INFO_P4, SRV_UCM_EXPLICIT_CALL_TRANSFER_ACT, index.group_index , index.call_index, call_info.call_state);
            /* 3-1. Current design: ECT only supports MO, Active and Held */
            if (call_info.call_state != SRV_UCM_OUTGOING_STATE &&
                call_info.call_state != SRV_UCM_ACTIVE_STATE &&
                call_info.call_state != SRV_UCM_HOLD_STATE)
            {
                return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
            }
            
            /* 3-2. fill first call info - hilited call */
            check_act_req_ect.first_call_type = call_info.uid_info.call_type;
            check_act_req_ect.first_group = call_info.uid_info.group_id;

            /* 3-3. get 2nd call info based on 1st call's state */
            second_group_exist = MMI_FALSE;
            
            switch (call_info.call_state)
            {              
                case SRV_UCM_OUTGOING_STATE:
                {
                    /* 1 MO + 1 A */
                    if (srv_ucm_query_group_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VOICE_CALL_TYPE, MMI_FALSE, group_index_array) == SRV_UCM_MAX_ACTIVE_GROUP)
                    {
                        second_group_exist = MMI_TRUE; 
                    }
                    /* 1 MO + 1 H */     /* use 1 here : gsm 1 A/outgoing, 1 H rule */
                    else if (srv_ucm_query_group_count(SRV_UCM_HOLD_STATE, SRV_UCM_VOICE_CALL_TYPE_ALL, MMI_FALSE, group_index_array) == 1)
                    {
                        second_group_exist = MMI_TRUE;   
                    }
                }
                break;
                case SRV_UCM_ACTIVE_STATE:
                {
                    /* 1 A + 1 MO */
                    if (srv_ucm_query_group_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_VOICE_CALL_TYPE, MMI_FALSE, group_index_array) == 1)
                    {
                        second_group_exist = MMI_TRUE;   
                    }
                    /* 1 A + 1 H */     /* use 1 here : gsm 1 A/outgoing, 1 H rule */
                    else if (srv_ucm_query_group_count(SRV_UCM_HOLD_STATE, SRV_UCM_VOICE_CALL_TYPE_ALL, MMI_FALSE, group_index_array) == 1)
                    {
                        second_group_exist = MMI_TRUE;   
                    }  

                }
                break;    
                
                case SRV_UCM_HOLD_STATE:
                {
                    /* 1 H + 1 MO */
                    if (srv_ucm_query_group_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_VOICE_CALL_TYPE, MMI_FALSE, group_index_array) == 1)
                    {
                        second_group_exist = MMI_TRUE;     
                    }
                    /* 1 H + 1 A */     /* use 1 here : gsm 1 A/outgoing, 1 H rule */
                    else if (srv_ucm_query_group_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VOICE_CALL_TYPE_ALL, MMI_FALSE, group_index_array) == SRV_UCM_MAX_ACTIVE_GROUP)
                    {
                        second_group_exist = MMI_TRUE;  
                    }  
                }
                break;    
                
                default: 
                { 
                   MMI_ASSERT(0);
                } 
                break; 
            }

            if (second_group_exist == MMI_TRUE)
            {
                srv_ucm_query_group_data(group_index_array[0], &second_group_info);
                
                check_act_req_ect.second_call_type = second_group_info.call_type;
                check_act_req_ect.second_group = second_group_info.group_id;   
                
                /* 2-3. permit check */
                permit_result = srv_ucm_query_act_permit(SRV_UCM_EXPLICIT_CALL_TRANSFER_ACT, &check_act_req_ect);

                if ((MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag) && (SRV_UCM_RESULT_OK == permit_result))
                {
                    srv_ucm_act_request(SRV_UCM_EXPLICIT_CALL_TRANSFER_ACT, &check_act_req_ect, NULL, mmi_core_ucm_p->act_request.act_req_callback);
                }
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, SRV_UCM_EXPLICIT_CALL_TRANSFER_ACT, permit_result); 
                return permit_result;
            }
            else
            {
                return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
            }
        }
        /* 3. if hilited call is voip call, TRANSFER */
    #endif /* __MMI_UCM_ECT__ */
    
    #ifdef __MMI_UCM_TRANSFER__
        if (call_info.uid_info.call_type == SRV_UCM_VOIP_CALL_TYPE)
        {
            memset(&check_act_req_transfer, 0, sizeof(srv_ucm_cd_or_ct_act_req_struct));
            memcpy(&(check_act_req_transfer.action_uid), &(call_info.uid_info), sizeof(srv_ucm_id_info_struct));

            /* in permit, number won't be considered and in action, number will be considered */
            if (MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag)
            {
                mmi_ucs2ncpy((CHAR*)check_act_req_transfer.num_uri, (CHAR*)mmi_core_ucm_p->num_info.num_uri, SRV_UCM_MAX_NUM_URI_LEN);
            }

            /* permit check */
            permit_result =  srv_ucm_query_act_permit(SRV_UCM_TRANSFER_ACT, &check_act_req_transfer);

            if ((MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag) && (SRV_UCM_RESULT_OK == permit_result))
            {
                srv_ucm_act_request(SRV_UCM_TRANSFER_ACT, &check_act_req_transfer, NULL, mmi_core_ucm_p->act_request.act_req_callback);
            }
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, SRV_UCM_TRANSFER_ACT, permit_result); 
            return permit_result;   
        }
    #endif /* __MMI_UCM_TRANSFER__ */
    
    }
    else
    {
        if (MMI_UCM_PERMIT_ONLY != exec_act_flag)  /* because VT will call option check in preview mode */
        {
            MMI_ASSERT(0);
        }     
    }
    return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
}
#endif /* defined(__MMI_UCM_TRANSFER__) || defined(__MMI_UCM_ECT__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_new_call_option
 * DESCRIPTION
 *  Check if new call option can be displayed in the in-call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden. 
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_new_call_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    srv_ucm_group_info_struct group_info;
    srv_ucm_call_type_enum call_type = (srv_ucm_call_type_enum)0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	MMI_ASSERT(exec_act_flag == MMI_UCM_PERMIT_ONLY);
	
    if (srv_ucm_query_group_data(mmi_core_ucm_p->call_misc.hilite_group_index, &group_info) > 0)
    {
        /* disallow data call to new , the reason still need confirm */
        if (group_info.call_type & SRV_UCM_DATA_CALL_TYPE_ALL)
        {
            return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
        }

        /* decide checked call type */
        if (group_info.call_type & SRV_UCM_SIM1_CALL_TYPE_ALL)
        {
            call_type = SRV_UCM_VOICE_CALL_TYPE;
        }
    #if (MMI_MAX_SIM_NUM >= 2)
        else if (group_info.call_type & SRV_UCM_SIM2_CALL_TYPE_ALL)
        {
            call_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
        }
    #if (MMI_MAX_SIM_NUM >= 3)
        else if (group_info.call_type & SRV_UCM_SIM3_CALL_TYPE_ALL)
        {
            call_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
        }
    #if (MMI_MAX_SIM_NUM == 4)
        else if (group_info.call_type & SRV_UCM_SIM4_CALL_TYPE_ALL)
        {
            call_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;
        }
    #endif /* (MMI_MAX_SIM_NUM == 4) */ 
    #endif /* (MMI_MAX_SIM_NUM >= 3) */ 
    #endif /* (MMI_MAX_SIM_NUM >= 2) */  

    #ifdef __MMI_VOIP__
        else if (group_info.call_type &  SRV_UCM_VOIP_CALL_TYPE)
        {
            call_type = SRV_UCM_VOIP_CALL_TYPE;
        }
    #endif /* __MMI_VOIP__ */
        else    
        {
            return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
        }
        /* available check */
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_CALL_SRV_IS_AVAILABLE_P2, SRV_UCM_END_ALL_HELD_ACT, call_type, srv_ucm_is_call_srv_available(call_type)); 

        if (MMI_TRUE == srv_ucm_is_call_srv_available(call_type))
        {
            return SRV_UCM_RESULT_OK;
        }
        else
        {
            return SRV_UCM_RESULT_NETWORK_NOT_AVAILABLE;
        }
    }
    return SRV_UCM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_all_active_option
 * DESCRIPTION
 *  Check if end all active calls option can be displayed in the incoming call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK 
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden. 
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_end_all_active_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum permit_result;   
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1. Permit check */
    permit_result = srv_ucm_query_act_permit(SRV_UCM_END_ALL_ACTIVE_ACT, NULL);

    /* 2. execute action if necessary */
    if ((MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag) && (SRV_UCM_RESULT_OK == permit_result))
    {
        srv_ucm_act_request(SRV_UCM_END_ALL_ACTIVE_ACT, NULL, NULL, mmi_core_ucm_p->act_request.act_req_callback);
    }
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, SRV_UCM_END_ALL_ACTIVE_ACT, permit_result);
    return permit_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_all_held_option
 * DESCRIPTION
 *  Check if end all held calls option can be displayed in the incoming call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden. 
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_end_all_held_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum permit_result;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* 1. Permit check */
    permit_result = srv_ucm_query_act_permit(SRV_UCM_END_ALL_HELD_ACT, NULL);

    /* 2. execute action if necessary */
    if ((MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag) && (SRV_UCM_RESULT_OK == permit_result))
    {
        srv_ucm_act_request(SRV_UCM_END_ALL_HELD_ACT, NULL, NULL, mmi_core_ucm_p->act_request.act_req_callback);
    }
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, SRV_UCM_END_ALL_HELD_ACT, permit_result);
    return permit_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_hold_single_option
 * DESCRIPTION
 *  Check if hold single option can be displayed in the in-call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden. 
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_hold_single_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_single_group_act_req_struct check_act_req;
    srv_ucm_group_info_struct group_info;
    srv_ucm_result_enum permit_result;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* 1. Permit check */
    if (srv_ucm_query_group_data(mmi_core_ucm_p->call_misc.hilite_group_index, &group_info) != 1)
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED; /*it's a conf call or no call*/
    }   
    
    check_act_req.action_group = group_info.group_id;
    check_act_req.call_type = group_info.call_type;
          
    permit_result = srv_ucm_query_act_permit(SRV_UCM_HOLD_ACT, &check_act_req);

    /* 2. execute action if necessary */
    if ((MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag) && (SRV_UCM_RESULT_OK == permit_result))
    {
        srv_ucm_act_request(SRV_UCM_HOLD_ACT, &check_act_req, NULL, mmi_core_ucm_p->act_request.act_req_callback);
    }
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, SRV_UCM_HOLD_ACT, permit_result); 
    return permit_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_hold_conference_option
 * DESCRIPTION
 *  Check if hold conference option can be displayed in the in-call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_hold_conference_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_single_group_act_req_struct check_act_req;
    srv_ucm_group_info_struct group_info;
    srv_ucm_result_enum permit_result;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (srv_ucm_query_group_data(mmi_core_ucm_p->call_misc.hilite_group_index, &group_info) < 2)
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED; /*it's a conf call or no call*/
    }   
    check_act_req.action_group = group_info.group_id;
    check_act_req.call_type = group_info.call_type;

    permit_result = srv_ucm_query_act_permit(SRV_UCM_HOLD_ACT, &check_act_req);
    
    if ((MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag) && (SRV_UCM_RESULT_OK == permit_result))
    {
        srv_ucm_act_request(SRV_UCM_HOLD_ACT, &check_act_req, NULL, mmi_core_ucm_p->act_request.act_req_callback);
    }
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, SRV_UCM_HOLD_ACT, permit_result); 
    return permit_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_retrieve_single_option
 * DESCRIPTION
 *  Check if retrieve single option can be displayed in the in-call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_retrieve_single_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_single_group_act_req_struct check_act_req;
    srv_ucm_group_info_struct group_info;
    srv_ucm_result_enum permit_result;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_group_data(mmi_core_ucm_p->call_misc.hilite_group_index, &group_info) != 1)
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED; /*it's a conf call or no call*/
    }   
    
    check_act_req.action_group = group_info.group_id;
    check_act_req.call_type = group_info.call_type;   
        
    permit_result = srv_ucm_query_act_permit(SRV_UCM_RETRIEVE_ACT, &check_act_req);

    if ((MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag) && (SRV_UCM_RESULT_OK == permit_result))
    {
        srv_ucm_act_request(SRV_UCM_RETRIEVE_ACT, &check_act_req, NULL, mmi_core_ucm_p->act_request.act_req_callback);
    }
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, SRV_UCM_RETRIEVE_ACT, permit_result); 
    return permit_result;  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_retrieve_conference_option
 * DESCRIPTION
 *  Check if retrieve conference option can be displayed in the in-call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_retrieve_conference_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_single_group_act_req_struct check_act_req;
    srv_ucm_group_info_struct group_info;
    srv_ucm_result_enum permit_result;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_group_data(mmi_core_ucm_p->call_misc.hilite_group_index, &group_info) < 2)
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED; /*it's NOT a conf call or no call*/
    }   
    
    check_act_req.action_group = group_info.group_id;
    check_act_req.call_type = group_info.call_type;     
    permit_result = srv_ucm_query_act_permit(SRV_UCM_RETRIEVE_ACT, &check_act_req);

    if ((MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag) && (SRV_UCM_RESULT_OK == permit_result))
    {
        srv_ucm_act_request(SRV_UCM_RETRIEVE_ACT, &check_act_req, NULL, mmi_core_ucm_p->act_request.act_req_callback);
    }
    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, SRV_UCM_RETRIEVE_ACT, permit_result); 
    return permit_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_swap_option
 * DESCRIPTION
 *  Check if swap option can be displayed in the in-call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 *  is_act_executed          [OUT]       is the action executed or not
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_swap_option(mmi_ucm_check_type_enum exec_act_flag, MMI_BOOL *is_act_executed)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_ucm_multiple_group_act_req_struct check_act_req_multiple;
	srv_ucm_group_info_struct group_info;
	srv_ucm_index_info_struct index;
	srv_ucm_call_info_struct call_info;
	S32 group_count;
	S32 group_index_array[SRV_UCM_MAX_GROUP];
	srv_ucm_result_enum swap_result;
	S32 i;
    
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	MMI_ASSERT(is_act_executed != NULL);
	
	swap_result = SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
	*is_act_executed = MMI_FALSE;

	/* 1. get hilite call info */
	index.group_index = mmi_core_ucm_p->call_misc.hilite_group_index;
	index.call_index = mmi_core_ucm_p->call_misc.hilite_call_index;
	MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_UID_INFO_P4, SRV_UCM_SWAP_ACT, index.group_index, index.call_index, 0);
	
	memset(&call_info, 0, sizeof(srv_ucm_call_info_struct));
	if (MMI_TRUE == srv_ucm_query_call_data(index, &call_info))
	{
		/* 1. if hilited call is active, find all held calls.  check each's permit. */
		if (call_info.call_state == SRV_UCM_ACTIVE_STATE)
		{
			check_act_req_multiple.active_call_type = call_info.uid_info.call_type;
			check_act_req_multiple.active_group = call_info.uid_info.group_id;
			
			group_count = srv_ucm_query_group_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_NO_DATA_CSD, MMI_FALSE, group_index_array);	
			
			i = 0;
			while (i < group_count)
			{
				srv_ucm_query_group_data(group_index_array[i], &group_info);           
				check_act_req_multiple.other_call_type = group_info.call_type;
				check_act_req_multiple.other_group = group_info.group_id;
				
				if ((swap_result = srv_ucm_query_act_permit(SRV_UCM_SWAP_ACT, &check_act_req_multiple)) == SRV_UCM_RESULT_OK)
				{
				    break;   /* if any one is passed, swap option will be shown */
				}
				i++;
			}

			if ((MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag) && 
				(group_count == 1) &&
				(SRV_UCM_RESULT_OK == swap_result))
			{
				*is_act_executed = MMI_TRUE;
				srv_ucm_act_request(SRV_UCM_SWAP_ACT, &check_act_req_multiple, NULL, mmi_core_ucm_p->act_request.act_req_callback);
			}
			else if ((SRV_UCM_RESULT_OK == swap_result) && group_count >= 2)
			{
			    *is_act_executed = MMI_FALSE;
			}
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, SRV_UCM_SWAP_ACT, swap_result); 
			return swap_result;
		}
		/*2. if hilite call is hold, find active call group */
		else if (call_info.call_state == SRV_UCM_HOLD_STATE)
		{
			check_act_req_multiple.other_call_type = call_info.uid_info.call_type;
			check_act_req_multiple.other_group = call_info.uid_info.group_id;
			
			/* 3-1. 1A1H in voice call, cannot allow to swap in different call type */
			if (srv_ucm_query_group_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_NO_DATA_CSD, MMI_FALSE, group_index_array) > 0)
			{
				srv_ucm_query_group_data(group_index_array[0], &group_info);
		
				check_act_req_multiple.active_call_type = group_info.call_type;
				check_act_req_multiple.active_group = group_info.group_id;
				swap_result = srv_ucm_query_act_permit(SRV_UCM_SWAP_ACT, &check_act_req_multiple);  
		
				if ((MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag) && (SRV_UCM_RESULT_OK == swap_result))
				{
					*is_act_executed = MMI_TRUE;
					srv_ucm_act_request(SRV_UCM_SWAP_ACT, &check_act_req_multiple, NULL, mmi_core_ucm_p->act_request.act_req_callback);
				}
			}
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, SRV_UCM_SWAP_ACT, swap_result); 
			return swap_result;
		}   		
	}
	else
	{
	    if (MMI_UCM_PERMIT_ONLY != exec_act_flag)  /* because VT will call option check in preview mode */
        {
            MMI_ASSERT(0);
        }      
	}
	return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_conference_option
 * DESCRIPTION
 *  Check if conference option can be displayed in the in-call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 *  is_act_executed          [OUT]       is the action executed or not
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_conference_option(mmi_ucm_check_type_enum exec_act_flag, MMI_BOOL *is_act_executed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_multiple_group_act_req_struct check_act_req_multiple;
    srv_ucm_group_info_struct query_call_info;
    srv_ucm_index_info_struct index;
    srv_ucm_call_info_struct call_info;
    S32 group_count;
    S32 group_index_array[SRV_UCM_MAX_GROUP];
    srv_ucm_result_enum conf_result;
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(is_act_executed != NULL);
    
    conf_result = SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    *is_act_executed = MMI_FALSE;
    
    /*1. Get hilited call type, state, group id*/
    index.group_index = mmi_core_ucm_p->call_misc.hilite_group_index;
    index.call_index = mmi_core_ucm_p->call_misc.hilite_group_index;

    memset(&call_info, 0, sizeof(srv_ucm_call_info_struct));
    if (MMI_TRUE == srv_ucm_query_call_data(index, &call_info))
    {
        if (SRV_UCM_ACTIVE_STATE == call_info.call_state)
        {
            check_act_req_multiple.active_group = call_info.uid_info.group_id;
            check_act_req_multiple.active_call_type = call_info.uid_info.call_type;
        }
        else if (SRV_UCM_HOLD_STATE == call_info.call_state)
        {
            check_act_req_multiple.other_group = call_info.uid_info.group_id;
            check_act_req_multiple.other_call_type = call_info.uid_info.call_type;
        }
        else
        {
            return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
        }
    }
    else
    {
        if (MMI_UCM_PERMIT_ONLY != exec_act_flag)  /*because VT will call option check in preview mode*/
        {
            MMI_ASSERT(0);
        }          
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_UID_INFO_P4, SRV_UCM_CONFERENCE_ACT, index.group_index, index.call_index, call_info.call_state);

    /*2. Hilite on active - check permit for all held call with same type*/
    if (SRV_UCM_ACTIVE_STATE == call_info.call_state)
    {
        group_count = srv_ucm_query_group_count(SRV_UCM_HOLD_STATE, check_act_req_multiple.active_call_type, MMI_FALSE, group_index_array);
        
        i = 0;
        while(i < group_count)       
        {
            srv_ucm_query_group_data(group_index_array[i], &query_call_info);
                       
            check_act_req_multiple.other_call_type = query_call_info.call_type;
            check_act_req_multiple.other_group = query_call_info.group_id;
            if ((conf_result = srv_ucm_query_act_permit(SRV_UCM_CONFERENCE_ACT, &check_act_req_multiple)) == SRV_UCM_RESULT_OK)
            {
                break;   /* if any one is passed, swap option will be shown */
            }
            i++;
        }
        
        if ((MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag) && 
            (group_count == 1) &&
            (SRV_UCM_RESULT_OK == conf_result))
        {
            *is_act_executed = MMI_TRUE;
            srv_ucm_act_request(SRV_UCM_CONFERENCE_ACT, &check_act_req_multiple, NULL, mmi_core_ucm_p->act_request.act_req_callback);
        }
        else if ((SRV_UCM_RESULT_OK == conf_result) && group_count >= 2)
        {
            *is_act_executed = MMI_FALSE;
        }
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, SRV_UCM_CONFERENCE_ACT, conf_result); 
        return conf_result;
    }
    else
    {
        if (srv_ucm_query_group_count(SRV_UCM_ACTIVE_STATE, check_act_req_multiple.other_call_type, MMI_FALSE, group_index_array) > 0)
        {
            srv_ucm_query_group_data(group_index_array[0], &query_call_info);          
            check_act_req_multiple.active_call_type = query_call_info.call_type;
            check_act_req_multiple.active_group = query_call_info.group_id;
            conf_result = srv_ucm_query_act_permit(SRV_UCM_CONFERENCE_ACT, &check_act_req_multiple);   
        }
        if ((MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag) && (SRV_UCM_RESULT_OK == conf_result))
        {
            *is_act_executed = MMI_TRUE;
            srv_ucm_act_request(SRV_UCM_CONFERENCE_ACT, &check_act_req_multiple, NULL, mmi_core_ucm_p->act_request.act_req_callback);
        }
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, SRV_UCM_CONFERENCE_ACT, conf_result); 
        return conf_result;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_split_option
 * DESCRIPTION
 *  Check if split option can be displayed in the in-call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden. 
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_split_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_single_call_act_req_struct check_act_req_signle;
    srv_ucm_index_info_struct index;
    srv_ucm_call_info_struct call_info;
    srv_ucm_result_enum permit_result;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index.group_index = mmi_core_ucm_p->call_misc.hilite_group_index;
    index.call_index = mmi_core_ucm_p->call_misc.hilite_call_index;

    memset(&call_info, 0, sizeof(srv_ucm_call_info_struct));
    if (MMI_TRUE == srv_ucm_query_call_data(index, &call_info))    
    {
        memcpy (&(check_act_req_signle.action_uid), &(call_info.uid_info), sizeof(srv_ucm_id_info_struct));
        permit_result = srv_ucm_query_act_permit(SRV_UCM_SPLIT_ACT, &check_act_req_signle);
    }
    else
    {
        permit_result = SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }
    
    if ((MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag) && (SRV_UCM_RESULT_OK == permit_result))
    {
        srv_ucm_act_request(SRV_UCM_SPLIT_ACT, &check_act_req_signle, NULL, mmi_core_ucm_p->act_request.act_req_callback);
    }    

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, SRV_UCM_SPLIT_ACT, permit_result); 
    return permit_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_single_option
 * DESCRIPTION
 *  Check if end single option can be displayed in the in-call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden. 
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_end_single_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_single_call_act_req_struct check_act_req;
    srv_ucm_call_info_struct call_info;
    srv_ucm_index_info_struct index;
    srv_ucm_result_enum permit_result;   
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    index.group_index = mmi_core_ucm_p->call_misc.hilite_group_index;
    index.call_index = mmi_core_ucm_p->call_misc.hilite_call_index;

    memset(&call_info, 0, sizeof(srv_ucm_call_info_struct));
    if (MMI_TRUE == srv_ucm_query_call_data(index, &call_info))
    {
        memcpy (&(check_act_req.action_uid), &(call_info.uid_info), sizeof(srv_ucm_id_info_struct));
        permit_result = srv_ucm_query_act_permit(SRV_UCM_END_SINGLE_ACT, &check_act_req);
    }
    else
    {
        permit_result = SRV_UCM_RESULT_ACTION_NOT_ALLOWED;

    }
    
    if ((MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag) && (SRV_UCM_RESULT_OK == permit_result))
    {
        srv_ucm_act_request(SRV_UCM_END_SINGLE_ACT, &check_act_req, NULL, mmi_core_ucm_p->act_request.act_req_callback);
    }
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, SRV_UCM_END_SINGLE_ACT, permit_result); 
    return permit_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_all_option
 * DESCRIPTION
 *  Check if end all option can be displayed in the in-call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden. 
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_end_all_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum permit_result;   
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    permit_result = srv_ucm_query_act_permit(SRV_UCM_END_ALL_ACT, NULL);
    
    if ((MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag) && (SRV_UCM_RESULT_OK == permit_result))
    {
        srv_ucm_act_request(SRV_UCM_END_ALL_ACT, NULL, NULL, mmi_core_ucm_p->act_request.act_req_callback);
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, SRV_UCM_END_ALL_ACT, permit_result); 
    return permit_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_main_menu_option
 * DESCRIPTION
 *  Check if main menu option can be displayed in the in-call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden. 
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_main_menu_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BACKGROUND_CALL__
    S32 i;
    MMI_BOOL is_puk = MMI_FALSE;
    mmi_sim_enum sim_id;
#endif /* __MMI_BACKGROUND_CALL__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BACKGROUND_CALL__
#ifdef __DM_LAWMO_SUPPORT__
    if (srv_dm_lawmo_is_locked())
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }
#endif /* __DM_LAWMO_SUPPORT__ */

    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {
        if (srv_sim_ctrl_get_unavailable_cause(sim_id) == SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED)
        {
            is_puk = MMI_TRUE;
            break;
        }
    }

    if ((srv_ucm_is_emergency_call() == MMI_TRUE) || 
        (srv_bootup_is_booting() == MMI_TRUE) ||
        (is_puk == MMI_TRUE))
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }

    return SRV_UCM_RESULT_OK;
#else /* __MMI_BACKGROUND_CALL__ */
    return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
#endif /* __MMI_BACKGROUND_CALL__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_phonebook_option
 * DESCRIPTION
 *  Check if phonebook option can be displayed in the in-call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden. 
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_phonebook_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    MMI_BOOL is_puk = MMI_FALSE;
    mmi_sim_enum sim_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(exec_act_flag == MMI_UCM_PERMIT_ONLY);

    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {
        if (srv_sim_ctrl_get_unavailable_cause(sim_id) == SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED)
        {
            is_puk = MMI_TRUE;
            break;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PHB_OPTION_P4, srv_ucm_is_emergency_call(),
        srv_bootup_is_booting(), 1, is_puk);

#ifdef __DM_LAWMO_SUPPORT__
    if (srv_dm_lawmo_is_locked())
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }
#endif /* __DM_LAWMO_SUPPORT__ */
    
    if ((srv_ucm_is_emergency_call() == MMI_TRUE) || 
        (srv_bootup_is_booting() == MMI_TRUE) ||
        (is_puk == MMI_TRUE))
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }
    return SRV_UCM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_calllog_option
 * DESCRIPTION
 *  Check if calllog option can be displayed in the in-call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_calllog_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    MMI_BOOL is_puk = MMI_FALSE;
    mmi_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(exec_act_flag == MMI_UCM_PERMIT_ONLY);

    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {
        if (srv_sim_ctrl_get_unavailable_cause(sim_id) == SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED)
        {
            is_puk = MMI_TRUE;
            break;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_CLOG_OPTION_P4, srv_ucm_is_emergency_call(),
        srv_bootup_is_booting(), 1, is_puk);

#ifdef __DM_LAWMO_SUPPORT__
    if (srv_dm_lawmo_is_locked())
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }
#endif /* __DM_LAWMO_SUPPORT__ */
	
    if ((srv_ucm_is_emergency_call() == MMI_TRUE) || 
        (srv_bootup_is_booting() == MMI_TRUE) ||
        (is_puk == MMI_TRUE))
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }
    return SRV_UCM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_sms_option
 * DESCRIPTION
 *  Check if sms option can be displayed in the in-call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_message_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    MMI_BOOL is_puk = MMI_FALSE;
    mmi_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(exec_act_flag == MMI_UCM_PERMIT_ONLY);

    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {
        if (srv_sim_ctrl_get_unavailable_cause(sim_id) == SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED)
        {
            is_puk = MMI_TRUE;
            break;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_MSG_OPTION_P4, srv_ucm_is_emergency_call(),
        srv_bootup_is_booting(), 1, is_puk);

#ifdef __DM_LAWMO_SUPPORT__
    if (srv_dm_lawmo_is_locked())
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }
#endif /* __DM_LAWMO_SUPPORT__ */
	
    if ((srv_ucm_is_emergency_call() == MMI_TRUE) || 
        (srv_bootup_is_booting() == MMI_TRUE) ||
        (is_puk == MMI_TRUE))
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }
    return SRV_UCM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_general_app_option
 * DESCRIPTION
 *  Check if sms/phb/calllog/main menu option can be displayed in the in-call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means sms/phb/calllog/main menu option should show;
 *  else the menu should be hidden.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_enter_general_app_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    MMI_BOOL is_puk = MMI_FALSE;
    mmi_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(exec_act_flag == MMI_UCM_PERMIT_ONLY);

    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {
        if (srv_sim_ctrl_get_unavailable_cause(sim_id) == SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED)
        {
            is_puk = MMI_TRUE;
            break;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENTER_GENERAL_APP_OPTION_P4, srv_ucm_is_emergency_call(),
        srv_bootup_is_booting(), 1, is_puk);

#if !defined(__COSMOS_MMI_PACKAGE__) && !defined(__MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT__)
	return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
#else


#ifdef __DM_LAWMO_SUPPORT__
    if (srv_dm_lawmo_is_locked())
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }
#endif /* __DM_LAWMO_SUPPORT__ */
	
    if ((srv_ucm_is_emergency_call() == MMI_TRUE) || 
        (srv_bootup_is_booting() == MMI_TRUE) ||
        (is_puk == MMI_TRUE))
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }
    return SRV_UCM_RESULT_OK;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_browser_option
 * DESCRIPTION
 *  Check if browswer option can be displayed in the in-call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_browser_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(exec_act_flag == MMI_UCM_PERMIT_ONLY);

#ifdef __DM_LAWMO_SUPPORT__
    if (srv_dm_lawmo_is_locked())
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }
#endif /* __DM_LAWMO_SUPPORT__ */

    if (srv_ucm_is_emergency_call() == MMI_TRUE)
    {
        return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
    }
    return SRV_UCM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_sound_recorder_option
 * DESCRIPTION
 *  Check if sound recorder option can be displayed in the in-call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_sound_recorder_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_id_info_struct call_uid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(exec_act_flag == MMI_UCM_PERMIT_ONLY);

    if(MMI_TRUE == mmi_ucm_get_call_id_by_call_state_and_type(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_CALL_TYPE_ALL, &call_uid))
    {
        if (MMI_TRUE == srv_ucm_query_sndrec_permit(call_uid))
        {
            return SRV_UCM_RESULT_OK;
        }
    }
    return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
}


#ifdef __MMI_BG_SOUND_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_bk_sound_in_call_option
 * DESCRIPTION
 *  Check if background sound option can be displayed in the in-call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_bk_sound_in_call_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_id_info_struct call_uid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(exec_act_flag == MMI_UCM_PERMIT_ONLY);	

    if(MMI_TRUE == mmi_ucm_get_call_id_by_call_state_and_type(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_CALL_TYPE_ALL, &call_uid))
    {
        if (MMI_TRUE == srv_ucm_query_bgs_in_call_permit(call_uid))
        {
            return SRV_UCM_RESULT_OK;
        }
    }
    return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
}
#endif /* __MMI_BG_SOUND_EFFECT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_loud_option
 * DESCRIPTION
 *  Check if loud speaker option can be displayed in the in-call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_loud_option(srv_ucm_call_state_enum check_call_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_id_info_struct call_uid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_TRUE == mmi_ucm_get_call_id_by_call_state_and_type(check_call_state, SRV_UCM_CALL_TYPE_ALL, &call_uid))
    {
        if (MMI_TRUE == srv_ucm_query_loudspeaker_permit(call_uid))
        {   
            return SRV_UCM_RESULT_OK;
        }
    }
    return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_mute_option
 * DESCRIPTION
 *  Check if mute option can be displayed in the in-call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_mute_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_id_info_struct call_uid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(exec_act_flag == MMI_UCM_PERMIT_ONLY);

    if (MMI_TRUE == mmi_ucm_get_call_id_by_call_state_and_type(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_CALL_TYPE_ALL, &call_uid))
    {
        if (MMI_TRUE == srv_ucm_query_mute_permit(call_uid))
        {
            return SRV_UCM_RESULT_OK;
        }
    }
    return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_dtmf_option
 * DESCRIPTION
 *  Check if dtmf option can be displayed in the in-call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_dtmf_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_DTMF_OPTION); 
	MMI_ASSERT(exec_act_flag == MMI_UCM_PERMIT_ONLY);
    return mmi_ucm_mute_option(MMI_UCM_PERMIT_ONLY);
}


#ifdef __MMI_BT_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_swap_bt_audio_path_option
 * DESCRIPTION
 *  Check if swap bluetooth audio path option can be displayed in the in-call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 *  check_call_state          [IN]       checked call state
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_swap_bt_audio_path_option(mmi_ucm_check_type_enum exec_act_flag, srv_ucm_call_state_enum check_call_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_id_info_struct call_uid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(exec_act_flag == MMI_UCM_PERMIT_ONLY);

    if (MMI_TRUE == mmi_ucm_get_call_id_by_call_state_and_type(check_call_state, SRV_UCM_CALL_TYPE_ALL, &call_uid))
    {
        if (MMI_TRUE == srv_ucm_query_switch_bt_audio_path_permit(call_uid))
        {
            return SRV_UCM_RESULT_OK;
        }
    }

    return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
}
#endif /* __MMI_BT_SUPPORT__ */


#ifdef __CTM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_ctm_option
 * DESCRIPTION
 *  Check if ctm can connect
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_ctm_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_id_info_struct call_uid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(exec_act_flag == MMI_UCM_PERMIT_ONLY);

    if (MMI_TRUE == mmi_ucm_get_call_id_by_call_state_and_type(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_CALL_TYPE_ALL, &call_uid))
    {
        if (MMI_TRUE == srv_ucm_query_connect_ctm_permit(call_uid))
        {
            return SRV_UCM_RESULT_OK;
        }
    }
    return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_ctm_option
 * DESCRIPTION
 *  Check if ctm setting is allowed
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means option should show;
 *  else the menu should be hidden.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_ctm_setting_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(exec_act_flag == MMI_UCM_PERMIT_ONLY);

    if (srv_callset_ctm_permit_switch_setting() == SRV_CALLSET_RESULT_OK)
    {
        return SRV_UCM_RESULT_OK;
    }

    return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
}
#endif /* __CTM_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_switch_to_video_call_option
 * DESCRIPTION
 *  Check if can use switch to video call
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_switch_to_video_call_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VIDEO_TELEPHONY__
    srv_ucm_index_info_struct index;
    srv_ucm_call_info_struct call_info;
    srv_ucm_result_enum permit_result;
    srv_ucm_dial_act_req_struct check_act_req;
#endif /* __MMI_VIDEO_TELEPHONY__ */    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VIDEO_TELEPHONY__
    /* hide swtich to video call menu when sos call exists */
    if (srv_ucm_is_emergency_call())  
    {
    	 return SRV_UCM_RESULT_SOS_CALL_EXISTS;
    }

    /* only can switch to video call when there is only one active/held voice call, no other calls */
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 1)
    {
        memset(mmi_core_ucm_p->call_misc.index_list, 0, sizeof(srv_ucm_index_info_struct) * SRV_UCM_MAX_CALL);

        if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VOICE_CALL_TYPE_ALL, mmi_core_ucm_p->call_misc.index_list) == 1 ||
            srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_VOICE_CALL_TYPE_ALL, mmi_core_ucm_p->call_misc.index_list) == 1)
        {
            memcpy(&index, &(mmi_core_ucm_p->call_misc.index_list[0]), sizeof(srv_ucm_index_info_struct));
            memset(&call_info, 0, sizeof(srv_ucm_call_info_struct));

            if (MMI_TRUE == srv_ucm_query_call_data(index, &call_info))
            {
                /* if not support video call in one SIM or the vidoe call service is not available, hidden this menu */
                check_act_req.call_type = mmi_ucm_convert_voice_to_video(call_info.uid_info.call_type);
                if (check_act_req.call_type >= SRV_UCM_CALL_TYPE_END_OF_ENUM)
                {
                    return SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL;
                }
                else if (srv_ucm_is_call_srv_available(check_act_req.call_type) != MMI_TRUE)
                {
                    return SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL;
                }

                /* if the remote is unknown number, hidden this menu */
                if (strlen((char*)call_info.remote_info.num_uri) == 0)
                {
                    return SRV_UCM_RESULT_EMPTY_NUMBER;
                }
            }
            else
            {
                MMI_ASSERT(0);
            }

            /* end all and dial permit check */
            check_act_req.is_ip_dial = MMI_FALSE;
            check_act_req.module_id = SRV_UCM_MODULE_ORIGIN_COMMON;
            check_act_req.phb_data  = NULL;

            mmi_asc_to_ucs2((CHAR*)check_act_req.num_uri, (CHAR*) call_info.remote_info.num_uri);  

            permit_result = srv_ucm_query_act_permit(SRV_UCM_END_ALL_AND_DIAL_ACT, &check_act_req);
			
            if ((MMI_UCM_EXEC_IF_PERMIT_PASS == exec_act_flag) && (SRV_UCM_RESULT_OK == permit_result))
            {
                mmi_ucm_vt_set_is_switch_action(MMI_TRUE);
                mmi_ucm_vt_set_switch_call_type(check_act_req.call_type);
                /* not use mmi_core_ucm_p->act_request.dial_user_data here, because it's ucm trigger behavior, not launch */
                srv_ucm_act_request(SRV_UCM_END_ALL_AND_DIAL_ACT, &check_act_req, NULL, mmi_core_ucm_p->act_request.act_req_callback);
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, SRV_UCM_END_ALL_AND_DIAL_ACT, permit_result);
            return permit_result;
        }

    }
#endif /*__MMI_VIDEO_TELEPHONY__*/
    return SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL;
}


#ifdef __MMI_UCM_REJECT_BY_SMS__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_rej_by_sms_option
 * DESCRIPTION
 *  Check if reject by sms option can be displayed in the incoming call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means answer option should show;
 *  else the menu should be hidden.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_rej_by_sms_option(mmi_ucm_check_type_enum exec_act_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_single_call_act_req_struct check_act_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* can not execute here, becaues have sms screens */
    MMI_ASSERT(exec_act_flag == MMI_UCM_PERMIT_ONLY);
    
    if (MMI_TRUE == mmi_ucm_get_call_id_by_call_state_and_type(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, &(check_act_req.action_uid)))
    {
        if (MMI_TRUE == srv_ucm_query_reject_by_sms_permit(check_act_req))
        {
            return SRV_UCM_RESULT_OK;
        }
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_OPTION_CHECK_P2, -8, 0);
    }
    return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
}
#endif /* __MMI_UCM_REJECT_BY_SMS__ */


#ifdef __MMI_DUAL_MIC_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_dual_mic_nr_status
 * DESCRIPTION
 *  Get dual mic noice reduction status
 * PARAMETERS
 *  void
 * RETURNS
 *  noice reduction state
 *****************************************************************************/
MMI_BOOL mmi_ucm_get_dual_mic_nr_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_core_ucm_p->call_misc.is_noice_reduction;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_dual_mic_nr_status
 * DESCRIPTION
 *  Set dual mic noice reduction status and store it
 * PARAMETERS
 *  status:     [IN] noice reduction state
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_dual_mic_nr_status(MMI_BOOL status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 errorCode = 0;
    U8 mode = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (status != mmi_core_ucm_p->call_misc.is_noice_reduction)
    {
        mode = status ? 1 : 0;
        mmi_core_ucm_p->call_misc.is_noice_reduction = status;
        WriteValue(NVRAM_UCM_DUAL_MIC_MODE, &mode, DS_BYTE, &errorCode);
        mdi_audio_set_dual_mic_nr(status);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_noice_reduction_option
 * DESCRIPTION
 *  Check if nocie reduction option can be displayed in the in call option.
 * PARAMETERS
 *  exec_act_flag          [IN]       execute this action if permit result is SRV_UCM_RESULT_OK   
 * RETURNS
 *  SRV_UCM_RESULT_OK means noice reduction option should show;
 *  else the menu should be hidden.
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_noice_reduction_option(mmi_ucm_check_type_enum exec_act_flag)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_index_info_struct index;
    srv_ucm_call_info_struct call_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(exec_act_flag == MMI_UCM_PERMIT_ONLY);

    index.group_index = mmi_core_ucm_p->call_misc.hilite_group_index;
    index.call_index = mmi_core_ucm_p->call_misc.hilite_call_index;

    if (MMI_TRUE == srv_ucm_query_call_data(index, &call_info))
    {
        if (call_info.call_state & SRV_UCM_CALL_STATE_CONNECTED)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_UID_INFO_P4, -1, index.group_index, index.call_index, -1);
            return SRV_UCM_RESULT_OK;
        }
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_UID_INFO_P4, -1, index.group_index, index.call_index, -2);
    }
    return SRV_UCM_RESULT_ACTION_NOT_ALLOWED;
}
#endif /* __MMI_DUAL_MIC_SUPPORT__ */


/* ==================================================================================== */
/* =============Misc ================================================================== */
/* ==================================================================================== */
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_hilight_index
 * DESCRIPTION
 *  Set highlight group and call
 * PARAMETERS
 *  hilite_group_index       [IN] hilight group
 *  hilite_call_index        [IN] hilight call
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_hilight_index(S32 hilite_group_index, S32 hilite_call_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_core_ucm_p->call_misc.hilite_group_index = hilite_group_index;
    mmi_core_ucm_p->call_misc.hilite_call_index = hilite_call_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_all_processing_action
 * DESCRIPTION
 *  check end all processing permit and execute it if permit is ok
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_end_all_processing_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum permit_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    permit_result = mmi_ucm_simple_option(SRV_UCM_END_ALL_PROCESSING_ACT, MMI_UCM_EXEC_IF_PERMIT_PASS);
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_IGNORE_END_ALL_PROCESSING_ACTION_P1,permit_result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_convert_voice_to_video
 * DESCRIPTION
 *  Convert voice call type to video call type in the same SIM
 * PARAMETERS
 *  call_type_voice:      [IN]    Call type, cannot use bitwise value to query
 *                                multiple call types
 * RETURNS
 *  Return video call type according to the voice call type in the same SIM
 *****************************************************************************/
srv_ucm_call_type_enum mmi_ucm_convert_voice_to_video(srv_ucm_call_type_enum call_type_voice)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if (g_call_type_mapping_table[i].call_type_voice & call_type_voice)
        {
            return g_call_type_mapping_table[i].call_type_video;
        }
    }
    return SRV_UCM_CALL_TYPE_END_OF_ENUM;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_convert_video_to_voice
 * DESCRIPTION
 *  Convert video call type to voice call type in the same SIM
 * PARAMETERS
 *  call_type_video:      [IN]    Call type, cannot use bitwise value to query
 *                                multiple call types
 * RETURNS
 *  Return voice call type according to the video call type in the same SIM
 *****************************************************************************/
srv_ucm_call_type_enum mmi_ucm_convert_video_to_voice(srv_ucm_call_type_enum call_type_video)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if (g_call_type_mapping_table[i].call_type_video & call_type_video)
        {
            return g_call_type_mapping_table[i].call_type_voice;
        }
    }
    return SRV_UCM_CALL_TYPE_END_OF_ENUM;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_convert_to_valid_ecc_call_type
 * DESCRIPTION
 *  Get valid ECC call type if the number is ECC number
 * PARAMETERS
 *  call_type:         [IN]    Call type, can use bitwise value to query multiple call types 
 *  call_number:       [IN]    Number, ascii
 * RETURNS
 *  Return valid ecc call type if the number is ecc number, otherwise return
 *  orginal call type
 *****************************************************************************/
srv_ucm_call_type_enum mmi_ucm_convert_to_valid_ecc_call_type(srv_ucm_call_type_enum call_type, U8 *call_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* The number must ecc number for one SIM at least */
    if (!srv_ucm_is_emergency_number(call_type, call_number))
    {
        return call_type;
    }

    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if (call_type & g_call_type_mapping_table[i].call_type_all)
        {
            /* If the number is ECC number for one SIM, should change the call type to 
               this SIM's available ECC call type, otherwise should change to NONE. */
            call_type &= ~(g_call_type_mapping_table[i].call_type_all);
            if (MMI_TRUE == srv_ucm_is_emergency_number(g_call_type_mapping_table[i].call_type_all, call_number))
            {
                call_type |= g_call_type_mapping_table[i].call_type_voice;
            }
        }
    }
    return call_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_convert_call_type_to_sim
 * DESCRIPTION
 *  Convert call type to SIM
 * PARAMETERS
 *  call_type            [IN]            Call type 
 * RETURNS
 *  SIM id
 *****************************************************************************/
mmi_sim_enum mmi_ucm_convert_call_type_to_sim(srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if (call_type & g_call_type_mapping_table[i].call_type_all)
        {
            return (mmi_sim_enum)(1 << i);
        }
    }
    return MMI_SIM_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_convert_index_to_voice_type
 * DESCRIPTION
 *  Convert index to voice call type
 * PARAMETERS
 *  index            [IN]            index
 * RETURNS
 *  call type
 *****************************************************************************/
srv_ucm_call_type_enum mmi_ucm_convert_index_to_voice_type(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < MMI_SIM_TOTAL)
    {
        return g_call_type_mapping_table[index].call_type_voice;
    }
    return SRV_UCM_CALL_TYPE_END_OF_ENUM;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_check_post_action_about_sim
 * DESCRIPTION
 *  Check if cannot execute post action caused by SIM
 * PARAMETERS
 *  call_type            [IN]            Call type
 *  num_uri              [IN]            Number (ASCII)
 * RETURNS
 *  MMI_FALSE means cannot execute post action caused by sim;
 *  otherwise means can execute post action.
 *****************************************************************************/
MMI_BOOL mmi_ucm_check_post_action_about_sim(srv_ucm_call_type_enum call_type, U8 *num_uri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_id = mmi_ucm_convert_call_type_to_sim(call_type);
    if (!srv_sim_ctrl_is_available(sim_id))
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_CHECK_POST_ACTION_ABOUT_SIM);
        if (MMI_FALSE == srv_ucm_is_emergency_number(call_type, num_uri))
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_CHECK_POST_ACTION_ABOUT_SIM);
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_is_emergency_number
 * DESCRIPTION
 *  Check if reject by sms option can be displayed in the incoming call option.
 * PARAMETERS
 *  call_type          [IN]       call type
 *  ucs2_number          [IN]       checked number (UCS2) 
 * RETURNS
 *  MMI_TRUE means the given number is an ECC number
 *****************************************************************************/
MMI_BOOL mmi_ucm_is_emergency_number(srv_ucm_call_type_enum call_type, U16 *ucs2_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 unicodeLen = 0;
    U8* ascii_num = NULL;
    MMI_BOOL is_ecc_num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    unicodeLen = (SRV_UCM_MAX_NUM_URI_LEN > mmi_ucs2strlen((CHAR*)ucs2_number)) ? (mmi_ucs2strlen((CHAR*)ucs2_number)) : (SRV_UCM_MAX_NUM_URI_LEN);
    ascii_num = OslMalloc(unicodeLen + 1);
    memset(ascii_num, 0, unicodeLen + 1);
    mmi_ucs2_n_to_asc((CHAR*)ascii_num, (CHAR*)ucs2_number, unicodeLen * ENCODING_LENGTH);
    is_ecc_num = srv_ucm_is_emergency_number(call_type , (U8 *)ascii_num);
	OslMfree(ascii_num);

    return is_ecc_num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_ecc_check_handler
 * DESCRIPTION
 *  emergency call check handler, dial it directly if any dial permit is passed
 * PARAMETERS
 *  dial_type:     [IN] given dial type
 *  make_call_para:            [IN]      Make call parameter.
 * RETURNS
 *  MMI_UCM_ECC_HDLR_PASS_AND_DIALED means it's a ECC and dial it directly
 *  MMI_UCM_ECC_HDLR_ALL_PASS means the number is ECC for all given types, but can not allow to dial
 *  MMI_UCM_ECC_HDLR_NOT_PASS means the number is not ECC for all given types
 *****************************************************************************/
mmi_ucm_ecc_hdlr_enum mmi_ucm_ecc_check_handler(srv_ucm_call_type_enum dial_type, srv_ucm_dial_act_req_struct *check_act_req, MMI_BOOL consider_temp_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_ecc_num = MMI_FALSE;
    S32 i = 0;
    srv_ucm_act_opcode_enum opcode;
    U8 permit_num = 0;
    srv_ucm_call_type_enum ECC_call_type = SRV_UCM_CALL_TYPE_END_OF_ENUM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ECC_CHECK_HDLR_P2, dial_type, consider_temp_status);

    /* only use the given dial type, not use the dial_tupe in make_call_para structure */
    /* 1. check if the number = ECC for EVERY given types. Only try to dial directly when this number is ECC for all given types */

    is_ecc_num = mmi_ucm_is_emergency_number(dial_type, check_act_req->num_uri);

    if (MMI_TRUE == is_ecc_num)
    {
        if (dial_type & (SRV_UCM_SIM1_CALL_TYPE_ALL))
        {
            dial_type &= ~(SRV_UCM_SIM1_CALL_TYPE_ALL);
            dial_type |= SRV_UCM_VOICE_CALL_TYPE;
        }
    #if (MMI_MAX_SIM_NUM >= 2)
        if (dial_type & SRV_UCM_SIM2_CALL_TYPE_ALL)
        {
            dial_type &= ~(SRV_UCM_SIM2_CALL_TYPE_ALL);
            dial_type |= SRV_UCM_VOICE_CALL_TYPE_SIM2;
        }
    #if (MMI_MAX_SIM_NUM >= 3)
        if (dial_type & SRV_UCM_SIM3_CALL_TYPE_ALL)
        {
            dial_type &= ~(SRV_UCM_SIM3_CALL_TYPE_ALL);
            dial_type |= SRV_UCM_VOICE_CALL_TYPE_SIM3;
        }
    #if (MMI_MAX_SIM_NUM == 4)
        if (dial_type & SRV_UCM_SIM4_CALL_TYPE_ALL)
        {
            dial_type &= ~(SRV_UCM_SIM4_CALL_TYPE_ALL);
            dial_type |= SRV_UCM_VOICE_CALL_TYPE_SIM4;
        }
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */

        /* if there is any call, use end_all_and_dial. */
        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0)
        {
            opcode = SRV_UCM_DIAL_ACT;
        }
        else
        {
            opcode = SRV_UCM_END_ALL_AND_DIAL_ACT;
        }

        /* only SRV_UCM_VOICE_CALL_TYPE, SRV_UCM_VOICE_CALL_TYPE_SIM2, SRV_UCM_VOIP_CALL_TYPE left */

        for (i = 0; i < SRV_UCM_TOTAL_CALL_TYPE ; i++)
        {
            if (dial_type & (1 << i))
            {
                if (mmi_ucm_is_emergency_number((srv_ucm_call_type_enum)(1 << i) , check_act_req->num_uri) == MMI_TRUE)
                {
                    check_act_req->call_type = (srv_ucm_call_type_enum)(1 << i);

                    if (SRV_UCM_RESULT_OK == srv_ucm_query_act_permit(opcode, check_act_req))
                    {
                        if (consider_temp_status && (MMI_TRUE == srv_ucm_is_call_srv_tmp_unavailable(check_act_req->call_type)))
                        {
                            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ECC_CHECK_HDLR_P1, check_act_req->call_type);
                        }
                        else
                        {
                            ECC_call_type = check_act_req->call_type;
                            permit_num++;
                        }
                    }
                }
            }
        }

        if (1 == permit_num)
        {
            check_act_req->call_type = ECC_call_type;
            srv_ucm_act_request(opcode, check_act_req, mmi_core_ucm_p->act_request.dial_user_data, mmi_core_ucm_p->act_request.act_req_callback);
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ECC_CHECK_HDLR_P3, opcode, check_act_req->call_type, MMI_UCM_ECC_HDLR_PASS_AND_DIALED);
            return MMI_UCM_ECC_HDLR_PASS_AND_DIALED;
        }

        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ECC_CHECK_HDLR_P3, SRV_UCM_NO_ACT, permit_num, MMI_UCM_ECC_HDLR_ALL_PASS);
        return MMI_UCM_ECC_HDLR_ALL_PASS;
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ECC_CHECK_HDLR_P3, SRV_UCM_NO_ACT, 0, MMI_UCM_ECC_HDLR_NOT_PASS);
        return MMI_UCM_ECC_HDLR_NOT_PASS;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_is_ss_string
 * DESCRIPTION
 *  The function to check if the string is SS or CC
 *  Need to phase out
 * PARAMETERS
 *  call_type            [IN]            Call type 
 *  num_uri              [IN]            Number (ASCII)
 * RETURNS
 *  TRUE means the given number is ss string; 
 *  FALSE means the given number is not ss string.
 *****************************************************************************/
MMI_BOOL mmi_ucm_is_ss_string(srv_ucm_call_type_enum call_type, U8 *num_uri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num_len = 0;
    MMI_BOOL in_call = MMI_FALSE;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num_len = strlen((char*)num_uri);

    if (num_len == 0)
    {
        return MMI_FALSE;
    }

    if (call_type & SRV_UCM_SIM1_CALL_TYPE_ALL)
    {
        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_SIM1_CALL_TYPE_ALL, NULL) > 0)
        {
            in_call = MMI_TRUE;
        }

        if (applib_ss_string_parsing((U8*)num_uri, (U8)num_len, SIM1, in_call) == SS_OPERATION)
        {
            return MMI_TRUE;
        }
   }
   else if  (call_type & SRV_UCM_SIM2_CALL_TYPE_ALL)
   {
        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_SIM2_CALL_TYPE_ALL, NULL) > 0)
        {
            in_call = MMI_TRUE;
        }

        if (applib_ss_string_parsing((U8*)num_uri, (U8)num_len, SIM2, in_call) == SS_OPERATION)
        {
            return MMI_TRUE;
        }
   }
   return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_group_index_by_call_state
 * DESCRIPTION
 *  Get group index by given call state (will return the 1st matched group index)
 * PARAMETERS 
 *  call_state            [IN]            Call state 
 * RETURNS
 *  Group index or -1 if call with the specified state does not exist.
 *****************************************************************************/
S32 mmi_ucm_get_group_index_by_call_state(srv_ucm_call_state_enum call_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_group_info_struct group_info;
    S32 group_index_array[SRV_UCM_MAX_GROUP];
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL,  MMI_FALSE, group_index_array) > SRV_UCM_MAX_GROUP)
    {
        MMI_ASSERT(0);
        return -1;
    }
        
    for (i = 0; i < srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL,  MMI_FALSE, group_index_array); i++)
    {
        MMI_ASSERT(i < SRV_UCM_MAX_GROUP);
        
        srv_ucm_query_group_data(group_index_array[i], &group_info);
        
        if (group_info.call_state == call_state)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_GET_GROUP_INDEX_BY_CALL_STATE, call_state, group_index_array[i]);
            return group_index_array[i];
        }
    }
    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_GET_GROUP_INDEX_BY_CALL_STATE_NO_CALL,call_state);
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_group_index_by_call_state_and_type
 * DESCRIPTION
 *  get group index based on given call state and call type
 * PARAMETERS 
 *  call_state            [IN]            Call state 
 *  call_type            [IN]            Call type 
 * RETURNS
 *  Group index or -1 if call with the specified state does not exist.
 *****************************************************************************/
S32 mmi_ucm_get_group_index_by_call_state_and_type(srv_ucm_call_state_enum call_state, srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    S32 group_index_array[SRV_UCM_MAX_GROUP];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_ucm_query_group_count(call_state, call_type, MMI_FALSE, group_index_array) == 0)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_GET_GROUP_INDEX_BY_CALL_STATE_AND_TYPE_NO_CALL,call_state, call_type);
        return -1;
    }
    else
    {
        return group_index_array[0];
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_call_id_by_call_state_and_type
 * DESCRIPTION
 *  get call id based on given call state and call type
 * PARAMETERS 
 *  call_state            [IN]            Call state 
 *  call_type             [IN]            Call type
 *  call_uid              [OUT]           Call id
 * RETURNS
 *  MMI_TRUE means get call id successfully
 *  MMI_FALSE means can not get call id 
 *****************************************************************************/
MMI_BOOL mmi_ucm_get_call_id_by_call_state_and_type(srv_ucm_call_state_enum call_state, srv_ucm_call_type_enum call_type, srv_ucm_id_info_struct *call_uid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_call_info_struct call_info;
    srv_ucm_index_info_struct index;
    MMI_BOOL result = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    memset(&index, 0xff, sizeof(srv_ucm_index_info_struct));

    do
    {
        /* hilite is meamingless for MO/MT cases */
        if (SRV_UCM_OUTGOING_STATE == call_state || SRV_UCM_INCOMING_STATE == call_state)
        {
            if (srv_ucm_query_call_count(call_state, call_type, mmi_core_ucm_p->call_misc.index_list) != 1)
            {
               break;
            }
            index.group_index = mmi_core_ucm_p->call_misc.index_list[0].group_index;
            index.call_index = mmi_core_ucm_p->call_misc.index_list[0].call_index;
        }
        else
        {
            index.group_index = mmi_core_ucm_p->call_misc.hilite_group_index;
            index.call_index = mmi_core_ucm_p->call_misc.hilite_call_index;
        }

        if (MMI_FALSE == srv_ucm_query_call_data(index, &call_info))    
        {
           break;
        }
        
        if (call_uid != NULL)
        {
            memcpy(call_uid, &(call_info.uid_info), sizeof(srv_ucm_id_info_struct));
            result = MMI_TRUE;
        }
        
    }while(0);

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_UID_INFO_P4, result, index.group_index, index.call_index, call_state);      
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_incoming_call_info
 * DESCRIPTION
 *  get call info of incoming call
 * PARAMETERS 
 *  check_act_req            [OUT]             incoming call information
 * RETURNS
 *  MMI_TRUE means get incoming call info successfully.
 *  if no incoming call exist, will return MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_ucm_get_incoming_call_info(srv_ucm_single_call_act_req_struct *check_act_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_call_info_struct call_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, mmi_core_ucm_p->call_misc.index_list) != 1)
    {   
        /* when this api is called, should make sure there is incoming call */
        MMI_ASSERT(0);
        return MMI_FALSE; 
    }

    srv_ucm_query_call_data(mmi_core_ucm_p->call_misc.index_list[0], &call_info);
    check_act_req->action_uid = call_info.uid_info;

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_call_index_list_by_group_index
 * DESCRIPTION
 *  get call index list based on given group index
 * PARAMETERS 
 *  group_index            [IN]            group index 
 *  call_index_list            [OUT]            call index for given group index 
 * RETURNS
 *  call number in this given group
 *****************************************************************************/
S32 mmi_ucm_get_call_index_list_by_group_index(S32 group_index, S32 *call_index_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 total_call_count;
    S32 i = 0;
    S32 j = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    total_call_count = srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, mmi_core_ucm_p->call_misc.index_list);

    for (i =0; i < total_call_count; i++)
    {
        if (mmi_core_ucm_p->call_misc.index_list[i].group_index == group_index)
        {
            call_index_list[j++] = mmi_core_ucm_p->call_misc.index_list[i].call_index;

            MMI_ASSERT(j <= SRV_UCM_MAX_CALL_IN_GROUP);
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_GET_CALL_INDEX_LIST_BY_GROUP_INDEX_P3, group_index, total_call_count, j);
    
    return j;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_no_counter_status
 * DESCRIPTION
 *  set no count flag
 * PARAMETERS
 *  no_counter            [BOOL]            no_counter flag
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_no_counter_status(MMI_BOOL no_counter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_SET_NO_COUNTER_STATUS_P1, no_counter);
    mmi_core_ucm_p->call_misc.no_counter = no_counter;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_no_counter_status
 * DESCRIPTION
 *  get no count flag
 * PARAMETERS
 *  void
 * RETURNS
 *  no_counter flag, if return MMI_TRUE, means should not start counter
 *****************************************************************************/
MMI_BOOL mmi_ucm_get_no_counter_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_GET_NO_COUNTER_STATUS_P1, mmi_core_ucm_p->call_misc.no_counter);
    return mmi_core_ucm_p->call_misc.no_counter;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_is_file_valid
 * DESCRIPTION
 *  Check if file is valid
 * PARAMETERS
 *  file_path            [IN]            file path
 *  type            [IN]            file type
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_ucm_is_file_valid(U16* file_path, U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh = 0;
#ifdef __DRM_SUPPORT__
    FS_HANDLE drm_fh = 0;
    U8 permission = 0;
#endif /* __DRM_SUPPORT__ */
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((CHAR*)file_path))
    {
        fh = FS_Open((U16*) file_path, FS_READ_ONLY);
        
        if (fh > FS_NO_ERROR)
        {
            FS_Close(fh);
            
        #ifndef __DRM_SUPPORT__
            result = MMI_TRUE;
        #else /* __DRM_SUPPORT__ */

            switch (type)
            {
                case SRV_UCM_RES_TYPE_IMAGE_PATH:
                {
                    permission = DRM_PERMISSION_DISPLAY;
                }
                break;
                
            #ifdef __MMI_PHB_CALLER_VIDEO__
                case SRV_UCM_RES_TYPE_VIDEO_PATH:
                {
                    permission = DRM_PERMISSION_PLAY;
                }
                break;
            #endif /* __MMI_PHB_CALLER_VIDEO__ */

                default:
                {
                    MMI_ASSERT(0);
                }
                break;
            }

            drm_fh = DRM_open_file((kal_wchar *)file_path, FS_READ_ONLY, permission);

            if (drm_fh >= FS_NO_ERROR)
            {
                if (DRM_validate_forward_rule(drm_fh, permission) == KAL_TRUE)
                {
                    result = MMI_TRUE;
                }
                DRM_close_file(drm_fh);
            }
        #endif /* __DRM_SUPPORT__ */
        }
    }

    return result;
}


#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_drm_stop_consume
 * DESCRIPTION
 *  UCM stop consume DRM right
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_drm_stop_consume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_core_ucm_p->call_misc.drm_consume_id >= 0)
    {
        DRM_stop_consume(mmi_core_ucm_p->call_misc.drm_consume_id);
        mmi_core_ucm_p->call_misc.drm_consume_id = -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_drm_callback
 * DESCRIPTION
 *  UCM DRM consume callback
 * PARAMETERS
 *  res       [IN]  
 *  id        [IN]  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_drm_callback(S32 res, S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_drm_stop_consume();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_consume_drm_right
 * DESCRIPTION
 *  Consume DRM right
 * PARAMETERS
 *  file_path            [IN]            file path
 *  type            [IN]            file type
 * RETURNS
 *  consume_id
 *****************************************************************************/
S32 mmi_ucm_drm_start_consume(U16* file_path, U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE drm_fh = 0;
    U8 permission = DRM_PERMISSION_DISPLAY;
    S32 consume_id = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case SRV_UCM_RES_TYPE_IMAGE_PATH:
        {
            permission = DRM_PERMISSION_DISPLAY;
            drm_fh = DRM_open_file((kal_wchar *)file_path, FS_READ_ONLY, permission);
            MMI_ASSERT(drm_fh >= FS_NO_ERROR);
            consume_id = DRM_consume_rights(drm_fh, permission, mmi_ucm_drm_callback);
            DRM_close_file(drm_fh);
        }
        break;
        
    #ifdef __MMI_PHB_CALLER_VIDEO__
        case SRV_UCM_RES_TYPE_VIDEO_PATH:
        {
        #ifdef __MMI_VIDEO_PLAY_SUPPORT__
            wgui_catvdo_set_drm_flag(WGUI_CATVDO_DRM_DISABLE_CONSUME_TIME_LIMIT_STOP); /*x*/
        #endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
        }
        break;
    #endif /* __MMI_PHB_CALLER_VIDEO__ */

        default:
        {
            MMI_ASSERT(0);
        }
        break;
    }
    mmi_core_ucm_p->call_misc.drm_consume_id = consume_id;
    return consume_id;
}
#endif /* __DRM_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_is_caller_video_sound
 * DESCRIPTION
 *  Check if caller video sould should be played
 * PARAMETERS
 *  image            [IN]            image info
 * RETURNS
 *  MMI_TRUE means it's a valid file to play
 *****************************************************************************/
MMI_BOOL mmi_ucm_is_caller_video_sound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_id_info_struct call_uid;
    srv_ucm_caller_res_struct* res_info = NULL;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_FALSE == mmi_ucm_get_call_id_by_call_state_and_type(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, &call_uid))
    {
        return MMI_FALSE;
    }
    res_info = OslMalloc(sizeof(srv_ucm_caller_res_struct));
    memset(res_info, 0x00, sizeof(srv_ucm_caller_res_struct));

    srv_ucm_get_caller_res_info(call_uid, res_info);
    
    if ((res_info->res_type & SRV_UCM_RES_TYPE_VIDEO_ID) && 
        (res_info->is_video_sound == MMI_TRUE))
    {
        result = MMI_TRUE;
    }
    else if ((res_info->res_type & SRV_UCM_RES_TYPE_VIDEO_PATH) &&
        (res_info->is_video_sound == MMI_TRUE))
    {
        if (mmi_ucm_is_file_valid((U16*)res_info->video_path, SRV_UCM_RES_TYPE_VIDEO_PATH) == MMI_TRUE)
        {
            result = MMI_TRUE;
        }
    }
    
    OslMfree(res_info);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_decide_visual_type
 * DESCRIPTION
 *  decide the wanted visual type by given res_type, current, video > image
 * PARAMETERS
 *  res_type:     [IN] given res_type, bitwise
 *  filtered_res_type:  [IN] the filtered res_type based on priority. not bitwise
 * RETURNS
 *  return MMI_FALSE means the given type has no visual related value 
 *****************************************************************************/
MMI_BOOL mmi_ucm_decide_visual_type(srv_ucm_res_type_enum res_type, srv_ucm_res_type_enum* filtered_res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_FALSE)
    {
    }
#ifdef __MMI_PHB_CALLER_VIDEO__
    else if (res_type & SRV_UCM_RES_TYPE_VIDEO_PATH)
    {
        *filtered_res_type = SRV_UCM_RES_TYPE_VIDEO_PATH;
    }
    else if (res_type & SRV_UCM_RES_TYPE_VIDEO_ID)
    {
        *filtered_res_type = SRV_UCM_RES_TYPE_VIDEO_ID;
    }
#endif /* __MMI_PHB_CALLER_VIDEO__ */
    else if (res_type & SRV_UCM_RES_TYPE_IMAGE_PATH)
    {
        *filtered_res_type = SRV_UCM_RES_TYPE_IMAGE_PATH;
    } 
    else if (res_type & SRV_UCM_RES_TYPE_IMAGE_ID)
    {
        *filtered_res_type = SRV_UCM_RES_TYPE_IMAGE_ID;
    }
    else
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__PLUTO_MMI_PACKAGE__) && !defined(__PXS_APP_ENABLE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_auto_lock_state
 * DESCRIPTION
 *  get auto lock state
 * PARAMETERS
 *  void
 * RETURNS
 *  Auto lock state
 *****************************************************************************/
mmi_ucm_auto_lock_state_enum mmi_ucm_get_auto_lock_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_core_ucm_p->auto_lock_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_auto_lock_fsm_hdlr
 * DESCRIPTION
 *  a FSM fpr auto lock mechanism. it will base on trigger event and original state and current existed calls situation
 *  to decide the next lock state
 * PARAMETERS
 *  event:     [IN] trigger event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_auto_lock_fsm_hdlr(mmi_ucm_auto_lock_trigger_event_enum event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_auto_lock_state_enum orig_state = mmi_core_ucm_p->auto_lock_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_AL_FSM_HDLR_P2, event, orig_state);

    switch(event)
    {
        case MMI_UCM_AL_OUTGOING_EVENT:
        {
            switch (orig_state)
            {
                case MMI_UCM_UNLOCK_STATE:
                case MMI_UCM_WTL_STATE:     
                case MMI_UCM_LOCK_STATE:
                {
                    mmi_core_ucm_p->auto_lock_state = MMI_UCM_LOCK_STATE;
                }
                break;
                
                default:
                {
                    MMI_ASSERT(0);
                }
                break;
            }       	  
        }    	
        break;       
        
        case MMI_UCM_AL_INCOMING_EVENT:
        {
            switch (orig_state)
            {
                case MMI_UCM_UNLOCK_STATE:
                {
                    /* If incoming call -- device's lock status, if waiting call -- call lock's status (keep) */
                    /* for CSD call, because no incall screen, therefore 1CSD + 1 MT, for user feeling, treat waiting call to incoming call--> apply phone lock */
                    if (srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, MMI_FALSE, NULL) == srv_ucm_query_group_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, MMI_FALSE, NULL))
                    {
                        if (MMI_TRUE == mmi_scr_locker_is_locked())
                        {
                            mmi_core_ucm_p->auto_lock_state = MMI_UCM_LOCK_STATE; /* Todo: phone device lock status */
                        }
                    #ifdef __MMI_BT_CALL_SUPPORT__
                        else if (mmi_ucm_get_auto_lock_state_bt() == MMI_UCM_BT_LOCK_STATE)
                        {
                            mmi_core_ucm_p->auto_lock_state = MMI_UCM_LOCK_STATE;
                        }
                    #endif /* __MMI_BT_CALL_SUPPORT__ */
                    }
                }
                break;
                
                case MMI_UCM_WTL_STATE:
                {
                    mmi_core_ucm_p->auto_lock_state = MMI_UCM_UNLOCK_STATE;
                }
                break;

                case MMI_UCM_LOCK_STATE:
                {
                    mmi_core_ucm_p->auto_lock_state = MMI_UCM_LOCK_STATE;
                }
                break;
                
                default:
                {
                    MMI_ASSERT(0);
                }
                break;
            }       	  
        }    	
        break; 
        
        case MMI_UCM_AL_ACCEPT_EVENT:
        {
            switch (orig_state)
            {
                case MMI_UCM_UNLOCK_STATE:
                case MMI_UCM_LOCK_STATE:
                {
                    mmi_core_ucm_p->auto_lock_state = MMI_UCM_LOCK_STATE;
                }
                break;
                
                case MMI_UCM_WTL_STATE:
                {
                    MMI_ASSERT(0);  /* because MT only have unlock or lock state */
                }
                break;

                default:
                {
                    MMI_ASSERT(0);
                }
                break;
            }       	  
        }    	
        break; 

        case MMI_UCM_AL_CONNECT_EVENT:
        {
            switch (orig_state)
            {
                case MMI_UCM_UNLOCK_STATE:
                {
                    MMI_ASSERT(0); /* MO must be in WTL or Lock */
                }
                break;
                
                case MMI_UCM_WTL_STATE:
                case MMI_UCM_LOCK_STATE:
                {
                    mmi_core_ucm_p->auto_lock_state = MMI_UCM_LOCK_STATE;
                }
                break;

                default:
                {
                    MMI_ASSERT(0);
                }
                break;
            }       	  
        }    	
        break;     

        case MMI_UCM_AL_RELEASE_EVENT:
        {
            switch (orig_state)
            {
                case MMI_UCM_UNLOCK_STATE:
                {
                    if (0 == srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, MMI_FALSE, NULL))
                    {
                        mmi_core_ucm_p->auto_lock_state = MMI_UCM_UNLOCK_STATE;
                    }
                    else
                    {
                        if (0 == srv_ucm_query_group_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, MMI_FALSE, NULL))
                        {
                            mmi_core_ucm_p->auto_lock_state = MMI_UCM_WTL_STATE; 
                        }
                        else
                        {
                            /* Keep orig state if there is MT */
                        }
                    }
                }
                break;
                
                case MMI_UCM_WTL_STATE:
                {
                    if (0 == srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, MMI_FALSE, NULL))
                    {
                        mmi_core_ucm_p->auto_lock_state = MMI_UCM_UNLOCK_STATE;
                    }
                    else 
                    {
                        if (0 == srv_ucm_query_group_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, MMI_FALSE, NULL))
                        {
                            /* Keep orig state */
                        }
                        else
                        {
                            MMI_ASSERT(0); /* if MT exist, it's impossible that the orig state is WTL */
                        }                        
                    }
                }
                break;

                case MMI_UCM_LOCK_STATE:
                {
                    if (0 == srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, MMI_FALSE, NULL))
                    {
                        mmi_core_ucm_p->auto_lock_state = MMI_UCM_UNLOCK_STATE;
                    }
                    else 
                    {
                        /* Keep orig state if any call exist */                      
                    }
                }
                break;
                
                default:
                {
                    MMI_ASSERT(0);
                }
                break;
            }       	  
        }    	
        break; 

        /* User press unlock key on call screen to unlock */
        case MMI_UCM_AL_UNLOCK_EVENT: 
        {
            switch (orig_state)
            {
                case MMI_UCM_UNLOCK_STATE:
                case MMI_UCM_WTL_STATE:     
                {
                    MMI_ASSERT(0); /* it's impossible to get unlock event when orignal is not in lock state */
                }
                break;
               
                case MMI_UCM_LOCK_STATE:
                {
                    if (0 == srv_ucm_query_group_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, MMI_FALSE, NULL))
                    {
                        mmi_core_ucm_p->auto_lock_state = MMI_UCM_WTL_STATE;
                    }
                    else
                    {
                        mmi_core_ucm_p->auto_lock_state = MMI_UCM_UNLOCK_STATE;
                    }                        
                }
                break;
                
                default:
                {
                    MMI_ASSERT(0);
                }
                break;
            }       	  
        }    	
        break; 

        case MMI_UCM_AL_WTL_TIMEOUT_EVENT:
        {
            switch (orig_state)
            {
                case MMI_UCM_UNLOCK_STATE:
                case MMI_UCM_LOCK_STATE:    
                {
                    MMI_ASSERT(0);
                }
                break;
                
                case MMI_UCM_WTL_STATE:
                {
                    mmi_core_ucm_p->auto_lock_state = MMI_UCM_LOCK_STATE;
                }
                break;
                
                default:
                {
                    MMI_ASSERT(0);
                }
                break;
            }       	  
        }    	
        break;

        case MMI_UCM_AL_FORCE_LOCK_EVENT:
        {
            switch (orig_state)
            {
                case MMI_UCM_UNLOCK_STATE:
                case MMI_UCM_WTL_STATE:
                {
                    mmi_core_ucm_p->auto_lock_state = MMI_UCM_LOCK_STATE;
                }
                break;

                case MMI_UCM_LOCK_STATE:
                {
                    /* Keep orig state if already lock */
                }
                break;

                default:
                {
                    MMI_ASSERT(0);
                }
                break;
            }
        }
        break;

        default:
        {
            MMI_ASSERT(0);
        }
        break;    		
    }    
    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_AL_FSM_HDLR_P1, mmi_core_ucm_p->auto_lock_state);
}
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__PLUTO_MMI_PACKAGE__) && !defined(__PXS_APP_ENABLE__) */


#ifdef __PXS_APP_ENABLE__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_pxs_need_to_process
 * DESCRIPTION
 *  Check if it is need to process the pxs detect object event
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means it is need to process the pxs detect object event
 *****************************************************************************/
MMI_BOOL mmi_ucm_pxs_need_to_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* pxs is no need to effect incoming call, outgoing data/CSD call and active data/CSD/VT call */
    if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_VOICE_CALL_TYPE_ALL, NULL) > 0 || 
        srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_VOICE_CALL_TYPE_ALL, NULL) > 0)
    {
        if (srv_earphone_is_plug_in() ||
        #ifdef __MMI_BT_SUPPORT__
            srv_bt_cm_is_incall_aud_swap2bt() == MMI_TRUE ||
        #endif /* __MMI_BT_SUPPORT__ */
            AUD_MODE_LOUDSPK == mdi_audio_get_audio_mode())
        {
            return MMI_FALSE;
        }
        else
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PXS_NEED_TO_PROCESS_P1, MMI_TRUE);
            return MMI_TRUE;
        }  
    }
    return MMI_FALSE;
}

#endif /* __PXS_APP_ENABLE__ */


#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_one_sim_behavior_is_needed
 * DESCRIPTION
 *  Check if only one SIM mode
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means it is only one SIM mode
 *****************************************************************************/
MMI_BOOL mmi_ucm_one_sim_behavior_is_needed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 insert_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    insert_num = srv_sim_ctrl_get_num_of_inserted();

    if (1 == insert_num || 0 == insert_num)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */


/* ==================================================================================== */
/* =============VT related============================================================= */
/* ==================================================================================== */
#ifdef __MMI_VIDEO_TELEPHONY__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_set_is_switch_action
 * DESCRIPTION
 *  Set the result of the action is video voice call switch action or not
 * PARAMETERS
 *  is_switch_action    [IN] The result of the action is video voice switch action or not
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_set_is_switch_action(MMI_BOOL is_switch_action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_core_ucm_p->vt_switch.is_voice_vt_switch_act = is_switch_action;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_get_is_switch_action
 * DESCRIPTION
 *  Get the result of the action is video voice call switch action or not
 * PARAMETERS
 *  void
 * RETURNS
 *  Return MMI_TRUE if the action is video voice call switch action;
 *  otherwise, MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_ucm_vt_get_is_switch_action(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_core_ucm_p->vt_switch.is_voice_vt_switch_act;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_set_switch_call_type
 * DESCRIPTION
 *  Set the call type should be switched to
 * PARAMETERS
 *  call_type           [IN] The call type will be switched to
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_set_switch_call_type(srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_core_ucm_p->vt_switch.switch_to_call_type = call_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_get_switch_call_type
 * DESCRIPTION
 *  Get the call type should be switched to
 * PARAMETERS
 *  void
 * RETURNS
 *  Return the call type should be switched to
 *****************************************************************************/
srv_ucm_call_type_enum mmi_ucm_vt_get_switch_call_type(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_core_ucm_p->vt_switch.switch_to_call_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_check_protocol_usable
 * DESCRIPTION
 *  Check if exist any protocol usable sim for video call
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means exist at least one protocol usable sim for video call
 *  otherwise means not
 *****************************************************************************/
MMI_BOOL mmi_ucm_vt_check_protocol_usable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum check_sim = MMI_SIM1;
    mmi_sim_enum sim_id;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_3G_SWITCH__
    check_sim = srv_netset_get_3g_capability_sim();
#endif /* __MMI_3G_SWITCH__ */

    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {
        if ((check_sim & sim_id) &&
            (MMI_WCDMA == srv_nw_info_get_protocol(sim_id)))
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_check_nw_usable
 * DESCRIPTION
 *  Check if exist any network usable sim for video call
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means exist at least one network usable sim for video call
 *  otherwise means not
 *****************************************************************************/
MMI_BOOL mmi_ucm_vt_check_nw_usable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum check_sim = MMI_SIM1;
    mmi_sim_enum sim_id;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_3G_SWITCH__
    check_sim = srv_netset_get_3g_capability_sim();
#endif /* __MMI_3G_SWITCH__ */

    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {
        if ((check_sim & sim_id) &&
            (srv_nw_usab_is_usable(sim_id)))
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_get_valid_video_call_type
 * DESCRIPTION
 *  Get the valid sim that support video call
 * PARAMETERS
 *  void
 * RETURNS
 *  Valid video call type
 *****************************************************************************/
srv_ucm_call_type_enum mmi_ucm_vt_get_valid_video_call_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_3G_SWITCH__
    U32 i;
    mmi_sim_enum sim_id;
    mmi_sim_enum supported_3g_sim = MMI_SIM1;
#endif /* __MMI_3G_SWITCH__ */
    srv_ucm_call_type_enum vt_call_type = (srv_ucm_call_type_enum)0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_3G_SWITCH__
    supported_3g_sim = srv_netset_get_3g_capability_sim();

    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {
        if (supported_3g_sim & sim_id)
        {
            vt_call_type |= g_call_type_mapping_table[i].call_type_video;
        }
    }
#else /* __MMI_3G_SWITCH__ */
    vt_call_type = SRV_UCM_VIDEO_CALL_TYPE;
#endif /* __MMI_3G_SWITCH__ */
    return vt_call_type;
}

#endif /*__MMI_VIDEO_TELEPHONY__*/

#endif /* __MMI_UCM__ */
