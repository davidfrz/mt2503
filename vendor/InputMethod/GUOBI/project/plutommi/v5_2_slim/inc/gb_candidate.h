/***************************************************************************
 * \file        :  gb_candidate.h
 * Corporation  :  Guobi Technology Ltd. GuangZhou China
 * Copyright    :  Copyright Guobi Technology Ltd. And Subject to Confidentiality 
 *                 Restrictions. This document is the confidential and proprietary 
 *                 property of Guobi Technology Ltd.It is neither the document                  
 *                 itself nor any part of it can be shared with any party  without 
 *                 the written  permission. 
 * Purpose      :  �������뷨��ѡ����ʾģ��ͷ�ļ�
 * Version      :  V1.0
 * Last Changed List
 * Name         |   date   |  Discription
 ****************************************************************************/
#ifndef __GB_CANDIDATE_H__
#define __GB_CANDIDATE_H__

#include "Gbtype.h"
#include "mmi_include.h"
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief ���ú�ѡ����(����: ��ͳ�ĵ��к�ѡ �� �����Ķ��к�ѡ)
 */
#define SL_INPUT_CAND_ROW_COUNT	 	1 ///<����С�� <= MAX_CANDIDATES / GB_CN_CANDIDATE_COUNT
#define SL_ASSOCIATE_CAND_ROW_COUNT 2 ///<����С�� <= MAX_CANDIDATES / GB_CN_CANDIDATE_COUNT
#define ML_INPUT_CAND_ROW_COUNT	 	2 ///<����С�� <= MAX_CANDIDATES / GB_CN_CANDIDATE_COUNT
#define ML_ASSOCIATE_CAND_ROW_COUNT 3 ///<����С�� <= MAX_CANDIDATES / GB_CN_CANDIDATE_COUNT

/*!
 * \brief UI��صĺ궨�� , ���沿�ַǳ���Ҫ������΢�����ص��޸Ĵ˴�
 * \note ��Ҫ����LCD�ߴ����������뷨UI
 */

 #if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X240__)
		#define UP_DOWN_TIPS_HEIGHT				4 ///<���·����ͷ�ĸ߶�
		#define UP_DOWN_TIPS_WIDTH				8 ///<���·����ͷ�Ŀ��
		#define LEFT_RIGHT_TIPS_HEIGHT				8 ///<���ҷ����ͷ�ĸ߶�
		#define LEFT_RIGHT_TIPS_WIDTH				4 ///<���ҷ����ͷ�Ŀ��
		#define UP_DOWN_TIPS_INTERVAL				2 ///<���·����ͷ֮��ļ��(���к�ѡʱʹ��)
		#define LEFT_RIGHT_TIPS_INTERVAL			2 ///<���ҷ����ͷ֮��ļ��
         

		#define GB_CN_CANDIDATE_COUNT	        	9  ///<һ�����ĺ�ѡ�ֵĸ���,���㷽��: (��Ļ�Ŀ��-ͼ��-������������)/�������ֵĿ��
		#define GB_SYMBOL_CANDIDATE_COUNT       	9  ///<һ�����ķ�����ʾ����,����ͺ�ѡ����һ��
		#define GB_LATIN_CANDIDATE_COUNT			9  ///<һ��Ӣ������ʾ����,���㷽��������һ��(�ȿ����)	
		#define GB_LATIN_CANDIDATE_LEN			14 ///<һ��Ӣ��������ʾ���ַ��ĸ���

		#define CHINESE_FONT_HEIGHT				20
		#define CAND_FONT_PADDING					5  ///<�ַ���Ҫ��ֱ������ʾ������������϶
		#define CAND_LINE_HEIGHT					(CHINESE_FONT_HEIGHT+CAND_FONT_PADDING*2) ///<���ʺ�ѡ��ÿһ���ĸ߶�(�������ͺ�ѡ���ȸ�)
		#define CAND_BOTTOM						(MMI_content_y + MMI_content_height-1) ///<����������������ײ���ʼ�����ʺ�ѡ��
		#define CAND_TOP							(CAND_BOTTOM - CAND_LINE_HEIGHT)///<��ѡ�򶥲�	

		#define CAND_LEFT							0
		#define CAND_RIGHT							(UI_DEVICE_WIDTH) ///<���ʺ�ѡ����ұ�λ��		
		#define CAND_WIDTH							(UI_DEVICE_WIDTH - 3) ///<���ʺ�ѡ�������ʾ��ȡ�����

		#define INPUT_AREA_WIDTH 					(CAND_WIDTH - LEFT_RIGHT_TIPS_WIDTH * 2 - LEFT_RIGHT_TIPS_INTERVAL - 2) ///<�������������(����2����ʾ��ͷ��λ��)������
		#define INPUT_AREA_HEIGHT 					CAND_LINE_HEIGHT///<�����������߶ȡ�����
		#define CAND_AREA_WIDTH  					INPUT_AREA_WIDTH///<���ʺ�ѡ����ȡ�����

		#define SELECTOR_WIDTH						8  ///<�����������ֵĿ��
		#define SELECTOR_HEIGHT					12 ///<�����������ֵĸ߶�
		#define COMP_WIDTH							16 ///<���ʲ��׵Ŀ��
		#define COMP_HEIGHT						16 ///<���ʲ��׵ĸ߶�

#elif defined(__MMI_MAINLCD_176X220__) //LCD 176��x220��
		#define UP_DOWN_TIPS_HEIGHT				4 ///<���·����ͷ�ĸ߶�
		#define UP_DOWN_TIPS_WIDTH				8 ///<���·����ͷ�Ŀ��
		#define LEFT_RIGHT_TIPS_HEIGHT				8 ///<���ҷ����ͷ�ĸ߶�
		#define LEFT_RIGHT_TIPS_WIDTH				4 ///<���ҷ����ͷ�Ŀ��
		#define UP_DOWN_TIPS_INTERVAL				2 ///<���·����ͷ֮��ļ��(���к�ѡʱʹ��)
		#define LEFT_RIGHT_TIPS_INTERVAL			2 ///<���ҷ����ͷ֮��ļ��
         

		#define GB_CN_CANDIDATE_COUNT	        	9  ///<һ�����ĺ�ѡ�ֵĸ���,���㷽��: (��Ļ�Ŀ��-ͼ��-������������)/�������ֵĿ��
		#define GB_SYMBOL_CANDIDATE_COUNT       	9  ///<һ�����ķ�����ʾ����,����ͺ�ѡ����һ��
		#define GB_LATIN_CANDIDATE_COUNT			9  ///<һ��Ӣ������ʾ����,���㷽��������һ��(�ȿ����)	
		#define GB_LATIN_CANDIDATE_LEN			14 ///<һ��Ӣ��������ʾ���ַ��ĸ���

		#define CHINESE_FONT_HEIGHT				16
		#define CAND_FONT_PADDING					3  ///<�ַ���Ҫ��ֱ������ʾ������������϶
		#define CAND_LINE_HEIGHT					(CHINESE_FONT_HEIGHT+CAND_FONT_PADDING*2) ///<���ʺ�ѡ��ÿһ���ĸ߶�(�������ͺ�ѡ���ȸ�)
		#define CAND_BOTTOM						(MMI_content_y + MMI_content_height - 1) ///<����������������ײ���ʼ�����ʺ�ѡ��
		#define CAND_TOP							(CAND_BOTTOM - CAND_LINE_HEIGHT)///<��ѡ�򶥲�	

		#define CAND_LEFT							1
		#define CAND_RIGHT							(UI_DEVICE_WIDTH - 2) ///<���ʺ�ѡ����ұ�λ��		
		#define CAND_WIDTH							(UI_DEVICE_WIDTH - 3) ///<���ʺ�ѡ�������ʾ��ȡ�����

		#define INPUT_AREA_WIDTH 					(CAND_WIDTH - LEFT_RIGHT_TIPS_WIDTH * 2 - LEFT_RIGHT_TIPS_INTERVAL - 2) ///<�������������(����2����ʾ��ͷ��λ��)������
		#define INPUT_AREA_HEIGHT 					CAND_LINE_HEIGHT///<�����������߶ȡ�����
		#define CAND_AREA_WIDTH  					INPUT_AREA_WIDTH///<���ʺ�ѡ����ȡ�����

		#define SELECTOR_WIDTH						8  ///<�����������ֵĿ��
		#define SELECTOR_HEIGHT					12 ///<�����������ֵĸ߶�
		#define COMP_WIDTH							16 ///<���ʲ��׵Ŀ��
		#define COMP_HEIGHT						16 ///<���ʲ��׵ĸ߶�

#elif (defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_128X128__))    //LCD 128��x160�� LCD 128X128  
		#define UP_DOWN_TIPS_HEIGHT				4 ///<���·����ͷ�ĸ߶�
		#define UP_DOWN_TIPS_WIDTH				8 ///<���·����ͷ�Ŀ��
		#define LEFT_RIGHT_TIPS_HEIGHT				8 ///<���ҷ����ͷ�ĸ߶�
		#define LEFT_RIGHT_TIPS_WIDTH				4 ///<���ҷ����ͷ�Ŀ��
		#define UP_DOWN_TIPS_INTERVAL				2 ///<���·����ͷ֮��ļ��(���к�ѡʱʹ��)
		#define LEFT_RIGHT_TIPS_INTERVAL			2 ///<���ҷ����ͷ֮��ļ��
         

		#define GB_CN_CANDIDATE_COUNT	        	9  ///<һ�����ĺ�ѡ�ֵĸ���,���㷽��: (��Ļ�Ŀ��-ͼ��-������������)/�������ֵĿ��
		#define GB_SYMBOL_CANDIDATE_COUNT       	9  ///<һ�����ķ�����ʾ����,����ͺ�ѡ����һ��
		#define GB_LATIN_CANDIDATE_COUNT			9  ///<һ��Ӣ������ʾ����,���㷽��������һ��(�ȿ����)	
		#define GB_LATIN_CANDIDATE_LEN			14 ///<һ��Ӣ��������ʾ���ַ��ĸ���

		#define CHINESE_FONT_HEIGHT				14
		#define CAND_FONT_PADDING					3  ///<�ַ���Ҫ��ֱ������ʾ������������϶
		#define CAND_LINE_HEIGHT					(CHINESE_FONT_HEIGHT+CAND_FONT_PADDING*2) ///<���ʺ�ѡ��ÿһ���ĸ߶�(�������ͺ�ѡ���ȸ�)
		#define CAND_BOTTOM						(MMI_content_y + MMI_content_height - 1) ///<����������������ײ���ʼ�����ʺ�ѡ��
		#define CAND_TOP							(CAND_BOTTOM - CAND_LINE_HEIGHT)///<��ѡ�򶥲�	

		#define CAND_LEFT							1
		#define CAND_RIGHT							(UI_DEVICE_WIDTH - 2) ///<���ʺ�ѡ����ұ�λ��		
		#define CAND_WIDTH							(UI_DEVICE_WIDTH - 3) ///<���ʺ�ѡ�������ʾ��ȡ�����

		#define INPUT_AREA_WIDTH 					(CAND_WIDTH - LEFT_RIGHT_TIPS_WIDTH * 2 - LEFT_RIGHT_TIPS_INTERVAL - 2) ///<�������������(����2����ʾ��ͷ��λ��)������
		#define INPUT_AREA_HEIGHT 					CAND_LINE_HEIGHT///<�����������߶ȡ�����
		#define CAND_AREA_WIDTH  					INPUT_AREA_WIDTH///<���ʺ�ѡ����ȡ�����

		#define SELECTOR_WIDTH						8  ///<�����������ֵĿ��
		#define SELECTOR_HEIGHT					12 ///<�����������ֵĸ߶�
		#define COMP_WIDTH							14 ///<���ʲ��׵Ŀ��
		#define COMP_HEIGHT						14 ///<���ʲ��׵ĸ߶�
#else //����LCD size ģʽ ���ƽ̨��makefile��MAIN_LCD_SIZE��һ��Ҫ�����
		#define UP_DOWN_TIPS_HEIGHT				4 ///<���·����ͷ�ĸ߶�
		#define UP_DOWN_TIPS_WIDTH				8 ///<���·����ͷ�Ŀ��
		#define LEFT_RIGHT_TIPS_HEIGHT				8 ///<���ҷ����ͷ�ĸ߶�
		#define LEFT_RIGHT_TIPS_WIDTH				4 ///<���ҷ����ͷ�Ŀ��
		#define UP_DOWN_TIPS_INTERVAL				2 ///<���·����ͷ֮��ļ��(���к�ѡʱʹ��)
		#define LEFT_RIGHT_TIPS_INTERVAL			2 ///<���ҷ����ͷ֮��ļ��
         

		#define GB_CN_CANDIDATE_COUNT	        	9  ///<һ�����ĺ�ѡ�ֵĸ���,���㷽��: (��Ļ�Ŀ��-ͼ��-������������)/�������ֵĿ��
		#define GB_SYMBOL_CANDIDATE_COUNT       	9  ///<һ�����ķ�����ʾ����,����ͺ�ѡ����һ��
		#define GB_LATIN_CANDIDATE_COUNT			9  ///<һ��Ӣ������ʾ����,���㷽��������һ��(�ȿ����)	
		#define GB_LATIN_CANDIDATE_LEN			14 ///<һ��Ӣ��������ʾ���ַ��ĸ���

		#define CHINESE_FONT_HEIGHT				20
		#define CAND_FONT_PADDING					5  ///<�ַ���Ҫ��ֱ������ʾ������������϶
		#define CAND_LINE_HEIGHT					(CHINESE_FONT_HEIGHT+CAND_FONT_PADDING*2) ///<���ʺ�ѡ��ÿһ���ĸ߶�(�������ͺ�ѡ���ȸ�)
		#define CAND_BOTTOM						(MMI_content_y + MMI_content_height ) ///<����������������ײ���ʼ�����ʺ�ѡ��
		#define CAND_TOP							(CAND_BOTTOM - CAND_LINE_HEIGHT)///<��ѡ�򶥲�	

		#define CAND_LEFT							1
		#define CAND_RIGHT							(UI_DEVICE_WIDTH - 2) ///<���ʺ�ѡ����ұ�λ��		
		#define CAND_WIDTH							(UI_DEVICE_WIDTH - 3) ///<���ʺ�ѡ�������ʾ��ȡ�����

		#define INPUT_AREA_WIDTH 					(CAND_WIDTH - LEFT_RIGHT_TIPS_WIDTH * 2 - LEFT_RIGHT_TIPS_INTERVAL - 2) ///<�������������(����2����ʾ��ͷ��λ��)������
		#define INPUT_AREA_HEIGHT 					CAND_LINE_HEIGHT///<�����������߶ȡ�����
		#define CAND_AREA_WIDTH  					INPUT_AREA_WIDTH///<���ʺ�ѡ����ȡ�����

		#define SELECTOR_WIDTH						8  ///<�����������ֵĿ��
		#define SELECTOR_HEIGHT					12 ///<�����������ֵĸ߶�
		#define COMP_WIDTH							16 ///<���ʲ��׵Ŀ��
		#define COMP_HEIGHT						16 ///<���ʲ��׵ĸ߶�
#endif //end  __MMI_MAINLCD_240x320__



#define CAND_LINE_SPLIT_WIDTH 					(SELECTOR_WIDTH + 2) ///<��ѡ���ּ��
#define ALL_COMP_COUNT							29 ///<���ʲ��׵ĸ���
#define GB_VKBD_CAND_HEIGHT					(CAND_LINE_HEIGHT * 2) ///<���ʺ�ѡ���ڸ߶�(����MTKƽ̨),�ڻ��Ƶ�ʱ������ʵ�ʸ߶ȵ���content�ĸ߶�

/*!
* \brief UI���(���ܸ��ݲ�ͬ��Ŀ��Ҫ����)
*/
#define GB_SYLLABLE_SPACE						10 ///<��������֮��ļ��
#define GB_FONT_COLOR_HOT						UI_COLOR_BLACK ///<HOTʱ������ɫ
#define GB_BG_COLOR_HOT						gui_color(147, 147, 147)//gui_color(200, 200, 255) ///<HOTʱ������ɫ
#define GB_FONT_COLOR_SELECTED				UI_COLOR_WHITE ///<ѡ��ʱ������ɫ
#define GB_BG_COLOR_SELECTED					UI_COLOR_BLACK	//gui_color(0, 128, 255) ///<ѡ��ʱ������ɫ
#define GB_FONT_COLOR_NORMAL					UI_COLOR_BLACK ///<δѡ��ʱ������ɫ
#define GB_BG_COLOR_NORMAL					UI_COLOR_WHITE ///<δѡ��ʱ������ɫ
#define	GB_ARROW_COLOR						gdi_act_color_from_rgb(255, 0, 0, 0)//gdi_act_color_from_rgb(255, 180, 180, 180)//�����ͷ��ɫ

/*!
* \brief �������ܺ궨��
*/
#define INDEX_TO_CHAR(i)		('0' + ((i) + 1) % 10) 
#ifndef min
#define min(a,b) 			((a)<(b)?(a):(b))
#endif

/*!
 * \brief ���ʼ�ͷ�������Ͷ���
 */
typedef enum
{
	GBARROW_UP
	,GBARROW_DOWN
	,GBARROW_LEFT
	,GBARROW_RIGHT
}GBArrowDirType;

/*!
 * \brief ���ʺ�ѡ��������Ϣ(���ݺ�ѡ������̬����)
 */
typedef struct tagGBRECT {
	GBINT left;
	GBINT top;
	GBINT right;
	GBINT bottom;
} GBRECT;

typedef struct tagGBCandCoordInfo {	
	GBRECT candWin; 			///<��ѡ��������
	GBINT candWinHeight;		///<��ѡ��������߶�
	GBINT backupCandWinHeight;	///<���ݺ�ѡ���ڸ߶�, ���߶ȱ�Сʱ��Ҫˢ�¶������Ч��ʾ����	
	GBRECT inputArea;			///<������(��ǰ�û��������ʾ����������������ʾ������Ӧ�ıʻ����С�ƴ�����л��߰�������)
	GBRECT candArea;			///<��ѡ��(��ʾ�û�������Ӧ���ı���ѡ)
	GBINT candAreaHeight;		///<��ѡ���߶�
	GBRECT leftArrow;			///<��
	GBRECT rightArrow;			///<��
	GBRECT upArrow;				///<��
	GBRECT downArrow;			///<��
} GBCandCoordInfo;

/*!
 * \brief ������ʺ�ѡ����������Ϣ
 * \param
 * \return
 * \note
 */
extern void GBResetCandCoordInfo(void);

/*!
 * \brief ����������Ƿ��ڼ���״̬
 * \param 
 * \return
 * \note
 */
extern GBBOOL GBCand_IsActive(void);

/*!
 * \brief �����л����뷨֮�������ǵ�Virtual Keyboard��û����ʾ����
 * \param 
 * \return
 * \note
 */
extern void GBCheckCandWnd(void);

/*!
 * \brief ��ʾ�������뷨��ѡ��
 * \param 
 * \return
 * \note
 */
extern void GBDrawCandWnd(void);

/*!
 * \brief �رչ������뷨��ѡ��
 * \param 
 * \return
 * \note
 */
extern void GBCloseCand(void);

/*!
 * \brief ��ȡ���ʺ�ѡ���ڸ߶�
 * \param 
 * \return g_CandCoordInfo.candWinHeight
 * \note
 */
extern GBINT GB_GetCandWinHeight(void);

/*!
 * \brief ��ȡ���ʺ�ѡ����topλ��
 * \param 
 * \return g_CandCoordInfo.candWin.top
 * \note
 */
extern GBINT GB_GetCandWinTop(void);

/*!
 * \brief ��ȡ��ѡ���ڸ߶�У׼��ֵ
 * \param void
 * \return 
 */
GBINT GB_GetCandWinAjustHeight(void);

/*!
 * \brief ���µ���������ʾ����ߴ�
 * \param changed_height �����߶�: > 0 �����������߶ȣ�< 0�����������߶�
 * \return 
 * \note changed by xyg 080312 for lefrkeys disappeared
 */
void GBResizeContentArea(int changed_height);

/*!
 * \brief ���ʴ�ӡ�ַ����ĺ���,֧��ʸ���ֿ⣬ϵͳ��gui_print_text����ֶ�������
 * \param void
 * \
 */

extern void GB_print_text(S32 x, S32 y, const UI_string_type str_ptr);

/*!
 * \brief ���������Ű���
 * \param void 
 * \return 
 * \note 
 *\example
 */
 extern BOOL r2lMMIFlag;

extern GBBOOL GB_GetR2LCompositionFlag(void);


/*!
 * \brief ���������Ű��ǵĹ������뷨ģʽ
 * \param void 
 * \return 
 * \note 
 *\example
 */
extern GBBOOL GB_IsR2LInputmode(void);


/*!
 * \brief  ���ʺ�ѡ��߶ȱ仯flag
 * \param void 
 * \return 
 * \note 
 *\example
 */
extern MMI_BOOL GBCandHeightChanged();


#ifdef __cplusplus
};
#endif

#endif
