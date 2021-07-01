/***************************************************************************
 * \file        :  Gb_platform.h
 * Corporation  :  Guobi Technology Ltd. GuangZhou China
 * Copyright    :  Copyright Guobi Technology Ltd. And Subject to Confidentiality 
 *                 Restrictions. This document is the confidential and proprietary 
 *                 property of Guobi Technology Ltd.It is neither the document                  
 *                 itself nor any part of it can be shared with any party  without 
 *                 the written  permission. 
 * Author       :  weizhiping
 * Date         :  2010-1-5
 * Purpose      :  �������뷨��Ŀ����ֲƽ̨���ܹ����Ĵ���ʵ��
 * Version      :  V0.1
 * Last Changed List
 * Name         |   date   |  Discription
 * weizhiping    2010-1-5    ��GBV5������ֲ����뻮��Ϊƽ̨��غ�ƽ̨�޹�������
 ****************************************************************************/
#ifndef __GB_PLATFORM_H__
#define __GB_PLATFORM_H__

#include "GlobalConstants.h"
#include "gui_data_types.h"
#include "IMERes.h"
#include "ImeGprot.h"
#include "Word_engine.h"  
#include "Imc_symbol.h"
#include "Imc_config.h"
#include "ImmProt.h"
#include "PixtelDataTypes.h"
#include "MMI_features.h"
#include "oslmemory.h"
#include "GlobalConstants.h"
#include "Eventsdef.h"
#include "Frameworkstruct.h"
#include "EventsDef.h"
#include "Wgui.h"
#include "Timerevents.h"
#include "DebugInitDef.h"
#include "CustDataRes.h"
#include "MessagesResourceData.h"
#include "GlobalDefs.h"
#include "Gui_config.h"
#include "gdi_lcd_config.h"
#include "gui_ems.h"
#include "wgui_categories_inputs.h"
#include "gui.h"
#include "gui_themes.h"
#include "Wgui_softkeys.h"
#include "wgui_categories_defs.h"
#include "wgui_categories_util.h"
#include "gui_virtual_keyboard.h"
#include "wgui_virtual_keyboard.h"
#include "MMI_features.h"
#include "imc.h"
#include "CommonScreens.h"
#include "Multitap_engine.h"
#include "GBEngine.h"
#include "gb_wrapper.h"

#ifdef __cplusplus
extern "C" {
#endif

#define GB_SYSTEM_PATH      L"c:\\@gb\\" // ����ϵͳ�ļ���

/*!
 * \brief ӳ��ƽ̨���ļ�ϵͳ�ӿڹ����ʷ�װʵ�ֵ���
 */
#define FILE_HANDLE          	FS_HANDLE
#define PFS_READ           		FS_READ_ONLY
#define PFS_WRITE          		FS_READ_WRITE|FS_CREATE_ALWAYS
#define pfopen(x,y)        		FS_Open((U16 *)x,y)
#define pfclose(x)         		{ FS_Commit(x); FS_Close(x); }
#define pfwrite(x1,x2,x3,x4,x5) FS_Write(x4,x1,x3,(U32 *)x5)
#define pfread(x1,x2,x3,x4,x5)  FS_Read(x4,x1,x3,(U32 *)x5)

// �ַ����ӿ�
#define GBStrLen 				wcslen

#define ARRAY_DIM(a)			(sizeof(a) / sizeof((a)[0])) ///<��ȡ����Ԫ����Ŀ

/*!
 * \brief ���ʰ������Ͷ���
 */
enum KeyType {
	gbKeyNum = 1,
	gbKeyArrow = 2,
	gbKeyStar = 4,
	gbKeyPound = 8,
	gbKeyStarPound = gbKeyStar + gbKeyPound,
	gbKeyOK = 16,
	gbKeyAll = (U16)-1
};

/*!
 * \brief ���ӳ��Ĺ��ʰ���������
 * \param type �μ�KeyType
 * \return
 * \note
 * \author weizhiping
 * \date 2009��12��11��
 */
extern void GBClearKeyHandler(U16 type);

/*!
 * \brief ����������õİ���������
 * \param 
 * \return 
 * \note 
 * \author weizhiping
 * \date 2009��12��11��
 */
extern void GBClearAllKeyHandler(void);

/*!
 * \brief ���ù��ʰ����������״̬(�ָ�ΪϵͳĬ��״̬)
 * \param 
 * \return 
 * \note 
 * \author weizhiping
 * \date 2009��12��16��
 */
extern void GBResetFuncKey(void);

// ���ʴ����������
#ifdef __MMI_TOUCH_SCREEN__
#define GB_MAX_REGION_COUNT 32

/*!
 * \brief ���ʴ�������������ֵö�� 
 */
typedef enum
{
	GBTOUCH_REGION_INVALID
	,GBTOUCH_REGION_PEN_DOWN
	,GBTOUCH_REGION_PEN_UP
}GBTouchRegionRet;

typedef struct __GB_Touch_Region
{
	GBU16 left, top, right, bottom;
    GBINT gbEvent;
    GBU32 param;
}GBTouchRegion;

typedef struct __GB_Touch_Regions
{
	GBTouchRegion regions[GB_MAX_REGION_COUNT];
	GBINT regionsCount;
	GBBOOL bInvertCandidateFlag; ///<��ѡ����
	GBINT pressCandidateRow; ///<���Ժ�ѡ���±�
	GBINT pressCandidateCol; ///<���Ժ�ѡ���±�
}GBTouchRegions;

/*!
 * \brief ����һ�����ʴ�����
 * \param 
 * \return GBTrue: �ɹ���GBFalse: ʧ��
 * \note ֻ�д������ռ䲻���Ż᷵��ʧ��, ����GB_MAX_REGION_COUNT��С
 * \author weizhiping
 * \date 2010��3��3��
 */
extern GBBOOL GBTouchRegion_Insert(GBU16 left, GBU16 top, GBU16 right, GBU16 bottom, GBINT gbEvent, GBU32 param);

/*!
 * \brief ���ʴ����������⺯��
 * \param point: ���Ե�
 * \param pHittedRegion: ��������ɹ��򽫱����������Ϣ�����ڴ��������
 * \return �Ƿ����ɹ�
 * \note ����������ʧ�ܣ�pHittedRegion�����ֵ��Ч������ʹ��
 */
extern GBTouchRegionRet GBTouchRegion_HitTest(mmi_pen_event_type_enum pen_event, mmi_pen_point_struct point, GBTouchRegion * pHittedRegion);

/*!
 * \brief ��չ��ʴ�����
 * \param 
 * \return 
 * \note 

 */
extern void GBTouchRegion_ResetRegionData(void);

/*!
 * \brief ���ù��ʴ��������Ժ�ѡ���
 * \param 
 * \return 
 * \note 

 */
extern void GBTouchRegion_ResetInvertCandidateFlag(void);

/*!
 * \brief ��ȡ���������Ժ�ѡ���
 * \param oid 
 * \return 
 * \note 
 *\example
 */
extern GBBOOL GBTouchRegion_GetInvertCandidateFlag(void);

/*!
 * \brief ��ȡ���������Ժ�ѡ������
 * \param void 
 * \return 
 * \note 
 *\example

 */
extern GBINT GBTouchRegion_GetPressCandidateRow(void);

/*!
 * \brief ��ȡ���������Ժ�ѡ������
 * \param void 
 * \return 
 * \note 
 *\example

 */
extern GBINT GBTouchRegion_GetPressCandidateCol(void);

#define Point_Is_In_Region(x, y, pRegion) \
	((x) >= (pRegion)->left && (x) <= (pRegion)->right \
	&& (y) >= (pRegion)->top && (y) <= (pRegion)->bottom)

	extern void mmi_pen_editor_handler_before_show_guobi(void);
	extern int mmi_pen_guobi_is_handle_writing(void);
	extern int mmi_pen_guobi_is_multiblock_hw(void);
	extern void mmi_pen_editor_guobi_touch_cand_show(void);
	extern int mmi_pen_guobi_is_vk_show(void);
	extern void mmi_pen_editor_guobi_vk_hide(void);
	extern int  mmi_pen_guobi_is_in_vk_cand(void);
#endif
	extern void wgui_hide_right_softkey(void);
	extern mmi_imm_input_mode_enum g_mmi_imm_current_input_mode;
	extern void (*g_imc_key_inputbox_LSK_function) (void);
#if defined(UI_EMS_SUPPORT)
	extern UI_EMS_input_box MMI_EMS_inputbox;
#endif
extern single_line_input_box MMI_inline_singleline_inputbox;
extern void wgui_set_EMS_inputbox_RSK(void);
extern void register_EMS_inputbox_keys(void);
extern void wgui_hide_left_softkey(void);
extern MMI_BOOL EMS_inputbox_multitap_input(UI_character_type c);
extern void EMS_inputbox_multitap_input_complete(void);
extern void redraw_EMS_inputbox(void);

/*!
 * \brief ���� char ���͵��ַ���ռ���ٵ���
 * \param str Դ�ַ���
 * \return ��Ascii�ַ��������ؿ��
 * \note

 */
extern long GB_GetAsciiStringWidth(char * str);

/*!
 * \brief ���� Unicode  ���͵��ַ���ռ���ٵ���
 * \param pParam �μ�GBGlobalPageOption.pGetStringWidthParam������
 * \param str Դ�ַ���
 * \return ��Unicode�ַ��������ؿ��
 * \note ���÷���
 	GBGlobalPageOption pageOption;
 	GBGetPageOption(pGbis, &pageOption);
	pageOption.fpGetWStringWidth = GB_GetWStringWidth;
	GBSetPageOption(pGbis, &pageOption);

 */
extern int GB_GetWStringWidth(void * pParam, GBLPCWCHAR str);

/*!
 * \brief ��MTK ƽ̨IMC���Ͱ�����Ϣ
 * \param msg_id: ��Ϣid
 * \param param_0: ����1, ͨ��Ϊ����
 * \param param_1: ����2, ͨ��Ϊ�ַ����ַ���ͷָ���ַ
 * \return
 * \note

 */
extern U32  GB_imc_key_send_message(U8 msg_id, U32 param_0, U32 param_1);


/*!
 * \brief �������������
 */
enum GBInputBoxType
{
	GBSinglineInputBox,
	GBMultilineInputBox,
	GBEMSInputBox,
	GBInlineInputBox
};

/*!
 * \brief ���������
 */
typedef struct __IInputBox {
	MMI_BOOL (*pfUpscreen)(UI_character_type c); ///<�����ص�
	void (*pfSetRSK)(void); ///<����RSK��Ӧ�����Ļص�(�����)
	void (*pfSetArrowKey)(void); ///<���÷������Ӧ�����Ļص�
	void (*pfDeleteAll)(void); ///<������ջص�
	U8 (*pfInputBoxIsEmtpy)(void); ///<�ж�������Ƿ�յĻص�
	void (*pfChangeInputMode)(void); ///<���뷨�л��ص�
	enum GBInputBoxType type;
} GBIInputBox;
extern GBIInputBox gbCurInputBox;

/*!
 * \brief ���ù��������
 * \param pIInputBox ���������ṹ��
 * \return
 * \note

 */
extern void GBSetCurInputBox(const GBIInputBox * pIInputBox);

/*!
 * \brief �жϵ����ı�����������Ƿ�Ϊ��
 * \param
 * \return
 * \note

 */
extern BOOL GBSinglineInputBoxIsEmpty(void);

/*!
 * \brief �ж϶����ı�����������Ƿ�Ϊ��
 * \param
 * \return
 * \note

 */
extern BOOL GBEMSInputBoxIsEmpty(void);

/*!
 * \brief �ж�Inline����������Ƿ�Ϊ��
 * \param void 
 * \return 
 * \note 
 *\example

 */
 #ifndef __MMI_INLINE_SLIM__
extern BOOL GBInlineInputBoxIsEmpty(void);
#endif

/*!
 * \brief �������뷨Ĭ�ϵ���������(�������Ϣ�ṹ���е������ַ���ֱ����ʾ��ƽ̨�����)
 * \param 
 * \return 
 * \note

 */
void GBInputBox_UpScreen(void);

/*!
 * \brief ����ļ����Ƿ���ڣ�����������򴴽�֮
 * \param
 * \return
 * \note 

 */
GBBOOL GB_check_folder(GBPCWCHAR pFoldPath);

/*!
 * \brief ʹ�ܿ��ӻ���ʾ�ո񡢻س��ȷ��Ź���
 * \param void 
 * \return 
 * \note 
 *\example

 */
void GB_EnableProprietarySymbolDisplay(void);

/*!
 * \brief ���ÿ��ӻ���ʾ�ո񡢻س��ȷ��Ź���
 * \param void 
 * \return 
 * \note 
 *\example

 */
void GB_DisableProprietarySymbolDisplay(void);

/*!
 * \brief �������ַ����л�����Ҫ��Կո񡢻س����ʻ�
 * \param pOldStr ԭ�ַ���
 * \param pNewStr 
 * \param font �����С
 * \return ���ظ��ַ����Ŀ��
 * \note �ú������Դ�����������ֽڼ�飬����ʱ��Ҫע��,pOldStr�������ַ�����pNewStr�ռ�����㹻
 *\example

 */
GBINT GB_ProprietarySymbolSwitch(GBPCWCHAR pOldStr, GBPWCHAR pNewStr);

#ifdef __cplusplus
};
#endif

#endif
