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
 * GPSSetting.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   The AGPS setting 
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
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"

#if defined(__GPS_SUPPORT__) && defined(__GPS_ADAPTOR_SUPPORT__) && defined(__AGPS_SUPPORT__)

#include "Agps_adaptor.h"
#include "agps_setting.h"
#include "nvram_interface.h"
#include "kal_trace.h"
#include "mmi_gps_nvram_def.h"
#include "kal_general_types.h"
#include "kal_public_api.h"

#include "DtcntSrvIprot.h"

#ifdef __IOT_CUSTOMIZE__
#include "mdi_gps.h"
#endif


static const srv_dtcnt_prof_gprs_struct g_agps_config_account_gprs = 
{    
    {
        0,  0,
        SRV_DTCNT_PROF_TYPE_USER_CONF, /* type */ 
        SRV_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
        (const kal_uint8*)L"AGPS", /* Account Name */
        "http://www.spirent-lcs.com", /* Home page */
        {
            SRV_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
            "", ""  /* username, password */
        },
        0,
        SRV_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
        80, /* proxy port */
        "", /* proxy address, domain name */
        "", "",  /* proxy username, password */
        "", "", "", "", "", "",
        DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MRE_WAP | DTCNT_APPTYPE_DEF | DTCNT_APPTYPE_GPS, /* app type */
        "00101" /* SIM ID */
    },
    
    (const kal_uint8*)"spirent.com"
};

/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_set_agps_on_off
* DESCRIPTION
*  save GPS setting and (mmi_void_funcptr_type)mmi_frm_scrn_close_active_id
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void gpsadaptor_agps_setting_set_agps_on_off(U8 on_off)
{
	S32 ret_value = 0;
    nvram_ef_gps_mmi_settings_struct gps_setting;
    gps_setting.agps_on_off = on_off;
	nvram_external_write_data(NVRAM_EF_GPS_MMI_SETTING_DATA_LID, 1, (kal_uint8*)&gps_setting, NVRAM_EF_GPS_MMI_SETTING_DATA_SIZE);
	kal_prompt_trace(MOD_GPSADAPTOR, "[agps Set agps on off = %d", gps_setting.agps_on_off);
}

void gpsadaptor_agps_setting_set_profile(nvram_ef_agps_profile_struct *profile)
{
	nvram_external_write_data(NVRAM_EF_AGPS_PROFILE_LID, 1, (kal_uint8*)profile, NVRAM_EF_AGPS_PROFILE_SIZE);
}
void gpsadaptor_agps_setting_set_up_setting(nvram_em_minigps_up_setting_struct* setting)
{
	nvram_external_write_data(NVRAM_EM_MINIGPS_UP_SETTING_LID, 1, (kal_uint8*)setting, NVRAM_EM_MINIGPS_UP_SETTING_SIZE);
}

/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_get_is_agps_on
* DESCRIPTION
*  save GPS setting and (mmi_void_funcptr_type)mmi_frm_scrn_close_active_id
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
MMI_BOOL gpsadaptor_agps_setting_get_is_agps_on(void)
{
    nvram_ef_gps_mmi_settings_struct gps_setting;
	nvram_external_read_data( NVRAM_EF_GPS_MMI_SETTING_DATA_LID, 1, (kal_uint8 *)&gps_setting, NVRAM_EF_GPS_MMI_SETTING_DATA_SIZE);
    return (MMI_BOOL)gps_setting.agps_on_off;
}

void gpsadaptor_agps_setting_get_profile(nvram_ef_agps_profile_struct *profile)
{
	nvram_external_read_data( NVRAM_EF_AGPS_PROFILE_LID, 1, (kal_uint8 *)profile, NVRAM_EF_AGPS_PROFILE_SIZE);
}

#ifdef __IOT_CUSTOMIZE__
void gpsadaptor_agps_supl_setting(nvram_em_minigps_up_setting_struct* setting)
{
    nvram_external_read_data( NVRAM_EM_MINIGPS_UP_SETTING_LID, 1, (kal_uint8 *)setting, NVRAM_EM_MINIGPS_UP_SETTING_SIZE);
    
    setting->payload = GPSADAPTOR_AGPS_UP_PAYLOAD_RRLP;
    setting->use_tls = agps_adaptor_get_supl_use_tls();
    if (setting->ut_timer > 255)
    {
        /* invalid setting, set to default */
        setting->ut_timer = 10;
    }
}
#endif

void gpsadaptor_agps_setting_get_up_setting(nvram_em_minigps_up_setting_struct* setting)
{
    MMI_BOOL need_store = MMI_FALSE;
	nvram_ef_agps_profile_struct profile;
	
	nvram_external_read_data( NVRAM_EM_MINIGPS_UP_SETTING_LID, 1, (kal_uint8 *)setting, NVRAM_EM_MINIGPS_UP_SETTING_SIZE);
	nvram_external_read_data( NVRAM_EF_AGPS_PROFILE_LID, 1, (kal_uint8 *)&profile, NVRAM_EF_AGPS_PROFILE_SIZE);

	 if (setting->payload != GPSADAPTOR_AGPS_UP_PAYLOAD_RRLP)
    {
        setting->payload = GPSADAPTOR_AGPS_UP_PAYLOAD_RRLP;
        need_store = KAL_TRUE;
    }

    if (setting->use_tls != KAL_TRUE && profile.port == 7275)
    {
        setting->use_tls = KAL_TRUE;
        need_store = KAL_TRUE;
    }

	if (setting->use_tls == KAL_TRUE && profile.port == 7276)
    {
        setting->use_tls = KAL_FALSE;
        need_store = KAL_TRUE;
    } 

    if (setting->ut_timer > 255)
    {
        /* invalid setting, set to default */
        setting->ut_timer = 10;
        need_store = MMI_TRUE;
    }

    if (need_store == KAL_TRUE)
    {
        gpsadaptor_agps_setting_set_up_setting(setting);
    }
}

void gpsadaptor_agps_setting_test_handler( ilm_struct *ilm_ptr )
{
    tst_module_string_inject_struct* tst_inject = (tst_module_string_inject_struct*)ilm_ptr->local_para_ptr;
	kal_uint32 sub_command=0;

    if(strlen(tst_inject->string)){
        sscanf(tst_inject->string, "%d", &sub_command); 
	}
		
	if (20 == tst_inject->index)
    {	
    	if (sub_command == 1){
            srv_dtcnt_store_prof_data_struct prof_info;
            U32 acct_id;
            srv_dtcnt_result_enum result = SRV_DTCNT_RESULT_TOTAL;
			
            prof_info.prof_type = SRV_DTCNT_BEARER_GPRS;	
            prof_info.prof_fields = SRV_DTCNT_PROF_FIELD_ALL;
				
            prof_info.prof_data = (void *)&g_agps_config_account_gprs;
			
            result = srv_dtcnt_store_add_prof(&prof_info, &acct_id);
					
            kal_prompt_trace(MOD_GPSADAPTOR, "[agps Set set dataaccount:result %d", result);

		}
		else if (sub_command == 2){
			
            nvram_em_minigps_up_setting_struct setting;

            gpsadaptor_agps_setting_get_up_setting(&setting);
			
            if (setting.molr_prefer != GPSADAPTOR_AGPS_WORK_MODE_MB)
            {
                setting.molr_prefer = GPSADAPTOR_AGPS_WORK_MODE_MB;
				gpsadaptor_agps_setting_set_up_setting(&setting);
            }
			
            kal_prompt_trace(MOD_GPSADAPTOR, "[agps set set mb mode!");
		}
		else if (sub_command == 3){
			
            nvram_em_minigps_up_setting_struct setting;

            gpsadaptor_agps_setting_get_up_setting(&setting);
			
            if (setting.molr_prefer != GPSADAPTOR_AGPS_WORK_MODE_MA)
            {
                setting.molr_prefer = GPSADAPTOR_AGPS_WORK_MODE_MA;
				gpsadaptor_agps_setting_set_up_setting(&setting);
            }
			
            kal_prompt_trace(MOD_GPSADAPTOR, "[agps set set MA mode!");
		}
    	
    }
}

#endif 

