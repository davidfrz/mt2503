
#ifndef __GB_WG_SYSAPP_H__
#define __GB_WG_SYSAPP_H__

#include "GB_DataTypeDef.h"

/************************************************************************************/
/* �ӿ�˵����																		*/
/*																					*/
/*    ���ⲿʹ��WINGUO������														*/
/*																					*/
/* ʹ�����ӣ�																		*/
/*	void mmi_um_highlight_write_msg(void)											*/
/*	{																				*/
/*		...																			*/
/*		#ifdef __GB_WINGUO_4__														*/
/*		SetLeftSoftkeyFunction(GB_WG_Entry_SMS, KEY_EVENT_UP);						*/
/*		SetCenterSoftkeyFunction(GB_WG_Entry_SMS, KEY_EVENT_UP);					*/
/*		#else																		*/
/*		SetLeftSoftkeyFunction(mmi_uc_pre_entry_write_msg, KEY_EVENT_UP);			*/
/*		SetKeyHandler(mmi_uc_pre_entry_write_msg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);	*/
/*		#endif																		*/
/*		...																			*/
/*	}																				*/
/*																					*/
/************************************************************************************/
/*GB_VOID GB_WG_Entry_SMS(GB_VOID);*/

/************************************************************************************/
/* �ӿ�˵����																		*/
/*																					*/
/*    ���ⲿ��ӡ������ʹ������ز˵�												*/
/*																					*/
/* ʹ�÷�����																		*/
/*																					*/
/*	1������GlobalMenuItems.h����MENU_ID_GB_WG�˵�ID									*/
/*	2����MENU_ID_GB_WG�ӵ�ĳ���˵�������											*/
/*	3��ADD_APPLICATION_MENUITEM((MENU_ID_GB_WG, MAIN_MENU_SERVICES_MENUID, 0,		*/
/*					SHOW, NONMOVEABLE, 1, STR_GB_WINGUO, IMG_WG_WINGUO_LOGO_OUT));	*/
/*	ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_GB_WG,							*/
/*					GB_WG_mmi_entry_Winguo_highlight_hdlr);							*/
/*																					*/
/* ע��ط���																		*/
/*																					*/
/*	���в˵����ƺ�ͼ�����ʹ��STR_GB_WINGUO��IMG_WG_WINGUO_LOGO_OUT					*/
/*																					*/
/************************************************************************************/
GB_VOID GB_WG_mmi_entry_Winguo_highlight_hdlr(GB_VOID);

// ����SMARTDIALӦ�ò˵� [6/8/2011 yaobicai]
GB_VOID GB_WG_Entry_Winguo(GB_VOID);

extern GB_VOID GB_WG_ExitApp(GB_VOID);
extern GB_VOID GB_WG_RegisterKeyHandle(GB_BOOL bCareEnd);
// ֪ͨϵͳ���滭ָ������
extern GB_VOID GB_WG_ReDrawScreen(GB_Rect *RedrawRect);

extern GB_VOID GB_WG_RegisterControlKeyHandle(void);			//modify by zhangchenglong 2011_11_10
extern GB_VOID GB_WG_HandleKey(GB_VOID);						//modify by zhangchenglong 2011_11_10

extern GB_BOOL GB_WG_Is_In_Winguo(GB_VOID);
extern GB_BOOL GB_WG_Is_In_Idle(GB_VOID);
extern GB_BOOL GB_WG_Is_In_SSC(GB_VOID);
extern GB_BOOL GB_WG_Is_Calling();

// �ж��Ƿ��������widget������ [5/15/2012 liangchuanhui]
// #ifdef GBWG_VIRTUAL_KEY
// GB_BOOL GB_WG_IS_Widget(GB_VOID);
// GB_BOOL GB_WG_IS_InputData(GB_VOID);
// #endif


GB_VOID GB_WG_Handle_In_SSC(GB_VOID);

// ���͹㲥��Ϣ
extern GB_BOOL GBBroadcaset_SendMessage(GB_INT event,GB_VOID* param);

GB_VOID GB_WG_send_msg(GB_INT MSG_ID, GB_VOID *Prama);
GB_VOID GB_WG_Entry(GB_U16 Keycode, GB_U16 Keytype);
GB_VOID GB_WG_GotoIdleScreen(GB_VOID);

GB_VOID GB_WG_GroupScreenCreat(GB_U16 Keycode, GB_U16 Keytype);	//modify by zhangchenglong 2011_11_18

#endif
