/*=========================================================================
��  ��Ȩ������
*  --------------------
* ��Ȩ���й㶫���ʿƼ��ɷ����޹�˾��δ����Ȩ��ֹ���˺��κ���֯������ʹ�ã�Υ���ؾ���
*
*
*
*
*  ---------���ʿƼ��ɷ����޹�˾-----------
*
*�ļ�˵��: gb_wrapper.h
*�������뷨��MTKƽ̨�Խӵ�MMI����
*
*=============================================================================*/


#ifndef __GB_WRAPPER_H__
#define __GB_WRAPPER_H__

#include "gbtype.h"
#include "gui_data_types.h"
#include "wgui_include.h"
#if defined(__MMI_TOUCH_SCREEN__)
#include "TouchScreenGprot_Int.h"
#endif
/*===============���뷨��������===================================*/

//����:��� ��Ok��֧��ѡ��, �رգ��� Ok��֧��ѡ��  
#define  __GB_INPUTMETHOD_SELECT_CANDIDATE_USE_LEFT_SORFKEY__


/*�������뷨��ѡ����֧��"�����"ѡ�� */
#ifdef  __GB_INPUTMETHOD_SELECT_CANDIDATE_USE_LEFT_SORFKEY__
    #define   __GB_LEFT_SOFTKEY_SELECT_CANDIDATE__ 
#endif
/*end*/
extern void (*g_imc_key_inputbox_LSK_function) (void);

#if defined(__MMI_WGUI_CSK_ENABLE__)
	extern void (*g_imc_key_inputbox_CSK_function) (void);
#endif

extern void wgui_set_EMS_inputbox_RSK(void);
extern void register_EMS_inputbox_keys(void);

extern void GBChangeInputModeForInputBox(int inputMethod);
extern void GBClearAllKeyHandler(void); 
extern void GBInputMethodReset(void); 
extern void GBSetAllKeyHandler(void); 
extern void GBInputMethodInit(void); 
extern void GBInputMethodExit(void); 
extern void GBCloseCand(void);
extern void GBCheckCandWnd(void);
extern void GBDrawCandWnd(void);
extern int   GbIsInputEmpty(void);
extern void GBKeyPoundPressHandlerForInputBox(void);

extern void GBUpdateSoftkey(void);
extern void GBSetFuncKey(void);

extern void GBUpScreen(void);
extern int GBEventHandler(GBINT evtType, GBINT param);
extern int GBGetCharInfo(unsigned short  wc, unsigned short * pCharInfoBuffer, unsigned char MaxInfoBuffer,unsigned short inputMode);
extern void GBHandleTouchEvent(U16 x, U16 y, mmi_pen_event_type_enum pen_event);
extern void GBSetAllArrowHandler(void);
extern int IsGbInputMode();


//��¼ϵͳ�������ͼ�꣬���ڻָ�ʱʹ��
extern UI_string_type Old_left_softkey_label;
extern UI_string_type Old_right_softkey_label;

#endif
