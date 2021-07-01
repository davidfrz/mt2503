
//#include "mmi_rp_all_defs.h"
//#include "GlobalMenuItems.h"
#include "MMI_include.h"
#include "Wgui_categories_util.h"
#include "NwUsabSrvGprot.h"
#include "nvram_common_defs.h"
#include "mmi_rp_app_gb_winguo_def.h"

#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
#include "appmgrsrvgprot.h"
#endif

#include "GB_WG_Common.h"


/************************************************************************/
/*                     ���ع���                                        */
/************************************************************************/


typedef struct 
{
	GB_BOOL winguo_state;  //����״̬����һЩ�������д���������˫��״̬�µȵȣ�
	GB_USHORT winguo_menuid;

}winguo_item_struct;

#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)

//static mmi_app_package_name_struct gb_wg_AppNmeList[100] = {0};
//static GB_UINT gb_wg_nAppCount = 0;
#define GB_WG_DEFAULTAPP_MAX_COUNT  8
#define GB_WG_APPNMELIST_MAX_COUNT  100
typedef struct
{
	GB_U32                      ndefaultAppCount;
	mmi_app_package_name_struct defaultApp[GB_WG_DEFAULTAPP_MAX_COUNT];
	GB_U32                      nappNmeLisCount;
	mmi_app_package_name_struct appNmeList[GB_WG_APPNMELIST_MAX_COUNT];
}GB_WG_AppInfo;
static GB_WG_AppInfo *gb_wg_AppInfo = GB_NULL;

const unsigned short GBMD_Winguo_FunList[] = {0};
const winguo_item_struct GBMD_FlaotAPP_FunList[]={0};

#else

const unsigned short GBMD_Winguo_FunList[]={
	MITEM101_PBOOK_SEARCH_ENTRY,//��������
	MITEM102_PBOOK_NEW_ENTRY,//��Ӻ���

#if defined(GB_MTK_09APLAT) || defined(GB_MTK_09BPLAT)
	MITEM109_PBOOK_CALLER_GROUPS,
	MITEM1101_PBOOK_MEMORY_STATUS,//pbook�ڴ�״̬
#elif defined(GB_MTK_10APLAT)
	0,
	0,
#endif

	//	MENU9146_WELCOME_TEXT,
	MENU_VOLUME_LEVEL,//������С
#ifndef GB_MTK_10APLAT
	MENU_SETTING_PREFERED_INPUT_METHOD,//Ԥ�����뷨
#endif
	MENU_SETTING_WALLPAPER,
	MENU_SETTING_SCR_SVR,
	MENU_SETTING_SCHEDULE_POWER,//��ʱ���ػ�
	0,
	0,
	//	MENU9165_PHONE_LOCK,//�ֻ���
	//	MENU3101_THEMES,//����
	MAIN_MENU_PROFILES_MENUID,//�龰ģʽ
	MENU_MT_CALL_ALERT_TYPE,
	MENU_TONE_SETUP,
	ORGANIZER_CALENDER_MENU,//����
	ORGANIZER_TODOLIST_MENU,//����
	ORGANIZER_ALARM_MENU,//����
	EXTRA_CALCULATOR_MENU,//������
	//	EXTRA_CURRENCYCONVERTOR_MENU,//���ʻ���
	0,
	MITEM_WORLDCLOCK_BROWSECITY,
	MESSAGES_MENU_WMESSAGE_MENU_ID,
	MESSAGES_MENU_INBOX_MENUID,
	MESSAGES_MENU_OUTBOX_MENUID,

#if defined(GB_MTK_09APLAT) || defined(GB_MTK_09BPLAT)
	AUDIO_PLAYER_MAIN_MENUID,//���ֲ�����
#elif defined(GB_MTK_10APLAT)
	0,
#endif

	MENU_CONN_BT_MAIN,//����
	SERVICES_WAP_MENU_ID,//��������
	MESSAGES_MENU_MMS_MENUID,//����

#if defined(GB_MTK_09APLAT) || defined(GB_MTK_09BPLAT)
	MENU_ID_VDOREC_APP,//�����
#elif defined(GB_MTK_10APLAT)
#if defined(__MMI_CAMCORDER__)
	MENU_ID_CAMCORDER_APP,
#else
	0,
#endif
#endif

	MENU_ID_VDOPLY_APP,//��Ƶ������
	MENU_ID_SNDREC_MAIN,//¼��
	MENU_ID_IMGVIEW_APP,//���

#if defined(GB_MTK_09APLAT) || defined(GB_MTK_09BPLAT)
	MENU_ID_CAMERA_APP,//�����
#elif defined(GB_MTK_10APLAT)
#if defined(__MMI_CAMCORDER__)
	MENU_ID_CAMCORDER_APP,
#else
	0,
#endif
#endif
#ifdef __MMI_EBOOK_READER__
	MAIN_MENU_EBOOK_MENUID//������
#else
	0
#endif
};

#ifndef __MMI_DUAL_SIM_MASTER__
const winguo_item_struct GBMD_FlaotAPP_FunList[]={
	{0,MAIN_MENU_PHONEBOOK_MENUID},//�绰��
	//{0,MENU_ID_PHB_QUICK_SEARCH},//���ٲ���
	{0,MITEM101_PBOOK_SEARCH_ENTRY},//��������
	{0,MITEM102_PBOOK_NEW_ENTRY},//��Ӻ��롢
	{0,MAIN_MENU_MESSAGES_MENUID},//��Ϣ����
	{0,MENU_ID_UM_WRITE_MSG},//�½���Ϣ
	{0,MENU_ID_UM_INBOX},//�ռ���
	{0,MENU_ID_UM_DRAFT},//�ݸ���
	{0,MENU_ID_UM_UNSENT},//������
	{0,MENU_ID_UM_SENT},//�ѷ���Ϣ
	{0,MENU_ID_UM_ARCHIVE},//�ļ���
	{0,MENU_ID_UM_DELETE_FOLDER},//ɾ����Ϣ
	{0,MENU_ID_EMAIL_MAIN},//�����ʼ�
	{0,MENU_ID_UM_SETTING},//��Ϣ����
	{0,MENU_ID_UM_CB_MAIN},//С���㲥
	{0,MENU_ID_UM_SETTING_SMS},//����
	{0,MENU_ID_UM_SETTING_MMS},//����
	{0,MENU_ID_UM_SETTING_PUSH},//������Ϣ

	{0,MAIN_MENU_CALL_CENTER},//ͨ������
	{0,MAIN_MENU_CALL_LOG},//ͨ����¼
	{0,MENU_ID_CLOG_MISSED_CALL},//δ�ӵ绰
	{0,MENU_ID_CLOG_DIALED_CALL},//�Ѳ��绰
	{0,MENU_ID_CLOG_RECVED_CALL},//�ѽӵ绰
	{0,MENU_ID_CLOG_DELETE_BOX},//ɾ��ͨ����¼
	{0,MENU_ID_CLOG_CALL_TIME},//ͨ����ʱ
	{0,MENU_ID_CLOG_CALL_COST},//ͨ���Ʒ�
	{0,MENU_ID_CLOG_SMS_COUNT},//���ż�����

	{0,MAIN_MENU_FUNANDGAMES_MENUID},//Ӧ�ú�����
	{0,MAIN_MENU_VRE_MENUID},//��������

	{0,MAIN_MENU_MULTIMEDIA_MENUID},//��ý��
	{0,MENU_ID_CAMCORDER_APP},//��¼���
	//{0,MENU_ID_CAMERA_APP},//�����
	{0,MENU_ID_IMGVIEW_APP},//���
	//{0,MENU_ID_MEDPLY_MAIN},//ý�岥����
	{0,MENU_ID_PHOEDT_APP},//��Ƭ�༭��
	{0,MENU_ID_SNDREC_MAIN},//¼��
	{0,MENU_ID_FMRDO_MAIN},//��Ƶ�㲥
	//{0,MENU3103_RINGTONE_COMPOSER},//�Ա�����
	//{0,MENU_ID_SLIDSHOW_APP},//�õ�Ƭ

	{0,MAIN_MENU_FILE_MNGR_MENUID},//�ҵ�����

	{0,MAIN_MENU_SERVICES_MENUID},//�������
	{0,SERVICES_WAP_MENU_ID},//��������
	{0,MENU_ID_SEARCH_WEB_BAIDU_ENTRY},//�ٶ�����
#ifdef __MMI_RMGR__
	{0,MENU_ID_RMGR},//Ȩ�޹���
#endif
	{0,SERVICES_DATA_CONNECT_MAIN_MENU_ID},//�����ʻ�
	{0,MAIN_MENU_PROFILES_MENUID},//�龰ģʽ
	{0,MAIN_MENU_PROFILES_GENERAL},//һ��ģʽ
	{0,MAIN_MENU_PROFILES_MEETING},//����ģʽ
	{0,MAIN_MENU_PROFILES_OUTDOOR},//����ģʽ
	{0,MAIN_MENU_PROFILES_INDOOR},//����ģʽ
	{0,MAIN_MENU_PROFILES_HEADSET},//����ģʽ
	{0,MAIN_MENU_PROFILES_BT},//����ģʽ
	{0,MAIN_MENU_ORGANIZER_MENUID},//������

	{0,ORGANIZER_CALENDER_MENU},//����
	{0,ORGANIZER_TODOLIST_MENU},//����
	{0,ORGANIZER_ALARM_MENU},//����
	{0,MENU_ID_AZAAN_ALARM},//������
	{0,ORGANIZER_WORLDCLOCK_MENU},//����ʱ��
	{0,MENU_ID_NOTE_APP_MAIN},//��ע
	{0,MENU_ID_SYNCML_MAIN},//ͬ��
	{0,MENU_ID_SYNCML_DEV_MAIN},//�ֻ�ͬ��
	//{0,MENU_STOPWATCH},//���

	{0,MAIN_MENU_SETTINGS_MENUID},//����
	{0,MENU_ID_MODE_SWITCH_TYPE},//ģʽ���÷�ʽ
	{0,MENU_ID_MODE_SWITCH_SETTING},//ģʽ����
#if defined(__MMI_TOUCH_SCREEN__)
	{0,MENU_SETTING_CALIBRATION},//����У׼
#endif
	{0,MENU9102_INITIAL_SETUP},//�ֻ�����
	{0,MENU_ID_NETSET_MAIN},//��������
	//{0,MENU_MTPNP_DM_SECURITY_SETTING},//��ȫ����
	{0,MENU9165_PHONE_LOCK},//�ֻ���
	{0,MENU9170_CHANGE_PASSWORD},//��������
	{0,MENU_ID_CONNECTIVITY},//�ⲿ����
	{0,MENU_CONN_BT_MAIN},//����
	{0,MENU_SETTING_RESTORE},//�ָ���������
	{0,MENU_SETTING_SOUND_EFFECT},//��Ч
	{0,MENU_IDLE_SCR_DISP},//��ʾ����
	{0,MENU9141_TIME_AND_DATE},//ʱ��������
	{0,MENU_SETTING_SCHEDULE_POWER},//��ʱ���ػ�
	{0,MENU_SETTING_LANGUAGE},//����ѡ��
	//{0,MENU_ID_PHNSET_PREFERED_WRITING_LANG},
	//{0,MENU_SETTING_PREFERED_INPUT_METHOD},//Ԥ�����뷨
	{0,MENU_SETTING_DEF_ENCODING_TYPE},//���뷽ʽ
	{0,MENU_IDLE_SCR_DISP},//�����˵���ʾ
	{0,MENU3101_THEMES},//����
	{0,EXTRA_SHORTCUTS_MENUID},//��ݹ���
#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__) && !defined(__DISABLE_SHORTCUTS_MENU__)
	{0,MENU_SETTING_DEDICATED_KEYS},//ָ�����ܼ�
#endif
	{0,MENU_ID_PHNSET_UART_SETUP},//���нӿ�
	//{0,MENU_ID_UCM_CALL_SETTING},//ͨ������
	{0,MENU_SETTING_SPEED_DIAL},//���ٲ���
	{0,MENU_CONNECT_NOTICE},//��ͨ��
	//{0,MENU_MTPNP_DM_NETWORK_SETUP},//��������


	//		{0,MENU_SETTING_PRIVACY},//��Ϣ����
	//		{0,MENU_ID_REMOTE_TRACK},//����׷��

	{0,MAIN_MENU_EXTRA_MENUID},//���ӹ���
	{0,EXTRA_CALCULATOR_MENU},//������
	{0,EXTRA_UNITCONVERTOR_MENU},//��λ����
	{0,EXTRA_CURRENCYCONVERTOR_MENU},//���ʻ���
	{0,MENU_STOPWATCH},//���
	{0,MAIN_MENU_EBOOK_MENUID},//������
#if defined(__MMI_AUTO_ANSWER_MACHINE__)
	{0,MENU_ID_AUTOAM_MAIN},//��¼��
#endif
#if defined(__MMI_GAME__)
	{0,MENU3105_GAMES},//��Ϸ
#endif

	{0,MENU_ID_ZAKAT_CALCULATOR}//��μ�����
};
#else // __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_CAMCORDER__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_RMGR__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__) && !defined(__DISABLE_SHORTCUTS_MENU__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_EBOOK_READER__
/* under construction !*/
#endif
#if defined(__MMI_AUTO_ANSWER_MACHINE__)
/* under construction !*/
#endif
#if defined(__MMI_GAME__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // __MMI_DUAL_SIM_MASTER__


#endif // #if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)




GB_INT GB_SMD_Platform_GetAppName(GB_U32 nId, GB_WCHAR *pstrBuff, GB_U16 nBuffLen)
{
	GB_INT ret = 0;
	if (pstrBuff && nBuffLen)
	{
		*pstrBuff = 0;
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
		if (gb_wg_AppInfo)
		{
			if (nId < gb_wg_AppInfo->nappNmeLisCount)
			{
				mmi_app_package_name_struct tempAppNmeABuff;
				srv_appmgr_get_app_package_name((mmi_app_package_char*)gb_wg_AppInfo->appNmeList[nId], (WCHAR*)tempAppNmeABuff);
				pstrBuff[nBuffLen-1] = 0;
				gb_wg_wcsncpy(pstrBuff, (const GB_WCHAR*)tempAppNmeABuff, nBuffLen-1);
				ret = 1;
			}
		}
#else
		if (nId < GB_SMD_Platform_GetLocalAppListSize())
		{
			const GB_WCHAR* pString = (const GB_WCHAR*)get_string(GetStringIdOfItem(GBMD_FlaotAPP_FunList[nId].winguo_menuid));
			if (pString)
			{
				pstrBuff[nBuffLen-1] = 0;
				gb_wg_wcsncpy(pstrBuff, pString, nBuffLen-1);
				ret = 1;
			}
		}
#endif
	}
	return ret;
}

// ��ȡApp��ע����Ϣ
GB_INT GB_SMD_Platform_GetAppNote(GB_U32 nAppId, GB_WCHAR *pstrBuff, GB_U16 nBuffLen)
{
	GB_INT ret = 0;
	if (pstrBuff && nBuffLen)
	{
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
		const GB_WCHAR* pString = (const GB_WCHAR*)get_string(STR_GB_WINGUO_APP);
		if (pString)
		{
			pstrBuff[nBuffLen-1] = 0;
			gb_wg_wcsncpy(pstrBuff, pString, nBuffLen-1);
			ret = 1;
		}
#else
		const GB_WCHAR* pString = (const GB_WCHAR*)get_string(STR_GB_WINGUO_APP);
		if (pString)
		{
			pstrBuff[nBuffLen-1] = 0;
			gb_wg_wcsncpy(pstrBuff, pString, nBuffLen-1);
			ret = 1;
		}
#endif
	}
	return ret;
}

// ��ȡApp��Icon
GB_INT GB_SMD_Platform_GetAppIcon(GB_U32 nAppId, GB_PU8 *img_buff_p)
{
#if (defined(__MMI_APP_MANAGER_SUPPORT__) && !defined(__MMI_FTE_SUPPORT__)) || defined(__COSMOS_MMI_PACKAGE__)
	mmi_image_src_struct imageSrc;
	mmi_ret ret;
	
	ret = srv_appmgr_get_app_package_image((mmi_app_package_char*)gb_wg_AppInfo->appNmeList[nAppId], &imageSrc);
	if (ret == MMI_RET_OK)
	{
		if (imageSrc.type == MMI_IMAGE_SRC_TYPE_RES_ID)
		{
			*img_buff_p  = (GB_PU8)get_image(imageSrc.data.res_id);
			return 1;
		}
	}
	*img_buff_p  = (GB_PU8)get_image(IMG_GB_SMARTWINGUO_APPLICATIOM);
#else
	*img_buff_p  = (GB_PU8)get_image(IMG_GB_SMARTWINGUO_APPLICATIOM);
#endif
	return 1;
}



// ��ʼ����ϵͳ�ӿڵ�App����
static GB_VOID _InitAppList(GB_VOID)
{
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
	if (gb_wg_AppInfo)
	{	
		GB_U8 SHORTCUT_APP_COUNT, MAIN_MENU_APP_COUNT;
		
		SHORTCUT_APP_COUNT = srv_appmgr_get_app_package_num(SRV_APPMGR_SHORTCUT_APP_PACKAGE_FLAG_TYPE);
		MAIN_MENU_APP_COUNT = srv_appmgr_get_app_package_num(SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE);
		gb_wg_AppInfo->nappNmeLisCount = SHORTCUT_APP_COUNT+MAIN_MENU_APP_COUNT;
		srv_appmgr_get_app_package_list(SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE, gb_wg_AppInfo->appNmeList, MAIN_MENU_APP_COUNT);
		srv_appmgr_get_app_package_list(SRV_APPMGR_SHORTCUT_APP_PACKAGE_FLAG_TYPE, gb_wg_AppInfo->appNmeList+MAIN_MENU_APP_COUNT, SHORTCUT_APP_COUNT);
		GB_SMD_AppAddSearchData();			
	}
#endif
}

// �����ʹ��Appд��NVROM
static GB_VOID _WriteDefaultAppToSystem(GB_WG_AppInfo *pAppInfo)
{
	S16 error = 0;
	WriteRecord(NVRAM_EF_GB_WG_V4_DEFAULT_APPNAME_LID, 1, pAppInfo, NVRAM_EF_GB_WG_V4_DEFAULT_APPNAME_SIZE, &error);
}

// ��NVROM�ж������ʹ��App
static GB_BOOL _ReadDefaultAppFromSystem(GB_WG_AppInfo *pAppInfo)
{
	S16 error = 0;
	ReadRecord(NVRAM_EF_GB_WG_V4_DEFAULT_APPNAME_LID, 1, pAppInfo, NVRAM_EF_GB_WG_V4_DEFAULT_APPNAME_SIZE, &error);
	return GB_TRUE;
}


static GB_INT _SetDefaultApp(GB_U32 menu_id)
{
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
	if (gb_wg_AppInfo)
	{
		if (menu_id < gb_wg_AppInfo->nappNmeLisCount)
		{
			GB_UINT i;
			GB_INT pos = -1;
			for (i = 0; i < gb_wg_AppInfo->ndefaultAppCount; i++)
			{
				if (GB_STRCMP(gb_wg_AppInfo->appNmeList[menu_id], gb_wg_AppInfo->defaultApp[i]) == 0)
				{
					pos = i;
					break;
				}
			}
			if (pos < 0)
			{
				gb_wg_AppInfo->ndefaultAppCount++;
				gb_wg_AppInfo->ndefaultAppCount = GB_MIN(gb_wg_AppInfo->ndefaultAppCount, GB_WG_DEFAULTAPP_MAX_COUNT);
				pos = GB_MIN(gb_wg_AppInfo->ndefaultAppCount, GB_WG_DEFAULTAPP_MAX_COUNT);
			}
			pos = GB_MIN(pos, GB_WG_DEFAULTAPP_MAX_COUNT-1);
			if (pos > 0)
			{
				GB_MEMMOVE(&gb_wg_AppInfo->defaultApp[1], &gb_wg_AppInfo->defaultApp[0], pos*sizeof(gb_wg_AppInfo->defaultApp[0]));
			}
			GB_MEMCPY(gb_wg_AppInfo->defaultApp[0], gb_wg_AppInfo->appNmeList[menu_id], sizeof(gb_wg_AppInfo->defaultApp[0]));
		}
	}
#endif
	return 1;
}

GB_U32 GB_SMD_Platform_GetDefaultAppCount(GB_VOID)
{
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
	if (gb_wg_AppInfo)
	{
		return gb_wg_AppInfo->ndefaultAppCount;
	}
#endif
	return 0;
}

GB_INT GB_SMD_Platform_GetDefaultApp(GB_U32 Index)
{
	GB_INT ret = -1;
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
	while(gb_wg_AppInfo)
	{
		GB_U32 i;
		if (Index > gb_wg_AppInfo->ndefaultAppCount)
		{
			break;
		}
		for (i = 0; i < gb_wg_AppInfo->nappNmeLisCount; i++)
		{
			if (GB_STRCMP(gb_wg_AppInfo->appNmeList[i], gb_wg_AppInfo->defaultApp[Index]) == 0)
			{
				ret = i;
				break;
			}
		}
		break;
	};
#endif
	return ret;
}

// �Ƚ�������ʷʹ�ù���app��ID
GB_INT GB_SMD_Platform_DefaultAppCmp(GB_U32 Index1, GB_U32 Index2)
{
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
	if (Index1 != Index2 && gb_wg_AppInfo)
	{
		GB_U32 i;
		for(i = 0; i < gb_wg_AppInfo->ndefaultAppCount; i++)
		{
			if (GB_STRCMP(gb_wg_AppInfo->appNmeList[Index1], gb_wg_AppInfo->defaultApp[i]) == 0)
			{
				return -1;
			}
			if (GB_STRCMP(gb_wg_AppInfo->appNmeList[Index2], gb_wg_AppInfo->defaultApp[i]) == 0)
			{
				return 1;
			}
		}
	}
#endif
	return 0;
}

// ��ȡApp�ĸ���
GB_U32 GB_SMD_Platform_GetLocalAppListSize(GB_VOID)
{
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
	if (gb_wg_AppInfo)
	{
		return gb_wg_AppInfo->nappNmeLisCount;
	}
	return 0;
#else
	return sizeof(GBMD_FlaotAPP_FunList)/sizeof(GBMD_FlaotAPP_FunList[0]);
#endif
}


GB_INT GB_GetAppMenuCardFlog(GB_U16 nMenuId)
{
	GB_INT i;
	for(i = 0; i < sizeof(GBMD_FlaotAPP_FunList)/sizeof(GBMD_FlaotAPP_FunList[0]) 
		&& GBMD_FlaotAPP_FunList[i].winguo_state > 0 ; i++)
	{
		if(nMenuId == GBMD_FlaotAPP_FunList[i].winguo_menuid)
		{
			return GBMD_FlaotAPP_FunList[i].winguo_state;
		}
	}
	return 0;
}

GB_INT GB_SMD_JudgeAppMenuvalid(GB_U32 usIndex)
{
	int CardFlog;
	if(!(
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
#endif
#if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
#endif
#else // __MMI_DUAL_SIM_MASTER__
		mmi_bootup_is_sim_valid() == MMI_TRUE
#endif // __MMI_DUAL_SIM_MASTER__
		))
	{
		return 0;
	}
	CardFlog = GB_GetAppMenuCardFlog(GBMD_FlaotAPP_FunList[usIndex].winguo_menuid);
	//����AB��ʱ��Ҫ�������ǵ���Ч��
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	return 1;
}

// ����app��Id�Ƿ���Ч
GB_BOOL GB_SMD_Platform_CheckAppId(GB_U32 nAppId)
{
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
	if (gb_wg_AppInfo)
	{
		if (GB_STRCMP(gb_wg_AppInfo->appNmeList[nAppId], "native.mtk.cosmos_mainmenu") == 0)
		{
			return GB_FALSE;
		}
	}
	return GB_TRUE;
#else
	if(GB_SMD_JudgeAppMenuvalid(nAppId) && mmi_frm_get_hilite_hdlr(GBMD_FlaotAPP_FunList[nAppId].winguo_menuid))
	{
		return GB_TRUE;
	}
	else
	{
		return GB_FALSE;
	}
#endif
}


// �����smartdail��ȡ����funapp���飬����������̨��Ӧ������ҳ��
GB_INT GB_SMD_Platform_RunApp(GB_U32 usIndex,GB_BOOL isSmartDail)
{
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
	mmi_app_package_name_struct tempappNmeList;
	if (isSmartDail && gb_wg_AppInfo)
	{
		if (usIndex < gb_wg_AppInfo->nappNmeLisCount)
		{
			_SetDefaultApp(usIndex);

			strcpy(tempappNmeList, gb_wg_AppInfo->appNmeList[usIndex]);

			if (strncmp(tempappNmeList, "native.mtk.home", MMI_APP_NAME_MAX_LEN) == 0 ||
				strncmp(tempappNmeList, "native.mtk.launcher", MMI_APP_NAME_MAX_LEN) == 0)
			{
				 MMI_ID id = mmi_frm_group_get_active_id();
				mmi_frm_group_close(id);
			}
			else
			{
				//  [9/17/2012 Liyong]����APP�رյ�ǰ�����APP���ٽ�����APP
				//MMI_ID id = srv_appmgr_query_instance_single_id("native.guobi.winguo");
				//srv_appmgr_query_instance_id("native.guobi.winguo", &id, 1);
				//srv_appmgr_close_app(id);
                MMI_ID id = mmi_frm_group_get_active_id();
			    mmi_frm_group_close(id);
				srv_appmgr_launch(tempappNmeList);
			}

			return 1;
		}
	}
#else // #if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
	GB_U16 nMenuId = 0;
	if (isSmartDail)
	{
		nMenuId = GBMD_FlaotAPP_FunList[usIndex].winguo_menuid;
	}
	else
	{
		nMenuId = GBMD_Winguo_FunList[usIndex];
	}
	if (mmi_frm_get_hilite_hdlr(nMenuId))
	{
		GB_WG_FuncPtr pFun;
		// û����APP֮ǰ���� [lzp 2012-1-6]
		gui_lock_double_buffer();
		(mmi_frm_get_hilite_hdlr(nMenuId))();
		pFun = (GB_WG_FuncPtr)get_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
		gui_unlock_double_buffer();
		if (pFun)
		{
			pFun();
			return 1;
		}
	}
#endif // #if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
	return 0;
}

// ��ʼ��App�����Ļ���
GB_VOID GB_SMD_Platform_AppElementInit(GB_VOID)
{
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
	if (!gb_wg_AppInfo)
	{
		gb_wg_AppInfo = (GB_WG_AppInfo*)GB_WG_Malloc(sizeof(GB_WG_AppInfo));
		GB_MEMSET(gb_wg_AppInfo, 0, (GB_UINT)&((GB_WG_AppInfo*)0)->nappNmeLisCount);
	}
	if (!gb_wg_AppInfo)
	{
		return;
	}
	// �����ʹ�õ�App����buffer
	_ReadDefaultAppFromSystem(gb_wg_AppInfo);
	// ��ϵͳApp�б����buffer
	_InitAppList();
#endif
}

// �ͷ�App�����Ļ���
GB_VOID GB_SMD_Platform_AppElementRelease(GB_VOID)
{
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
	if (gb_wg_AppInfo)
	{
		// �������ʹ�õ�app��nvrom
		_WriteDefaultAppToSystem(gb_wg_AppInfo);
		// �ͷŴ洢ϵͳApp��buffer
		GB_WG_Free(gb_wg_AppInfo);
		gb_wg_AppInfo = GB_NULL;
	}
#endif
}

