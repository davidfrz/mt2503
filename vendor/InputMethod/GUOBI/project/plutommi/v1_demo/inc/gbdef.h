/***************************************************************************
* File Name    :  gbdef.h
* Corporation  :  Guobi Technology Ltd. GuangZhou China
* Copyright    :  Copyright Guobi Technology Ltd. And Subject to Confidentiality 
*                 Restrictions. This document is the confidential and proprietary 
*                 property of Guobi Technology Ltd.It is neither the document                  
*                 itself nor any part of it can be shared with any party  without 
*                 the written  permission. 
* Author       :  chenbinghui
* Date         :  2009-6-18
* Purpose      :  v5 GB API ���⹫�������к궨��
* Version      :  V1.0
* Last Changed List
* Name         |   date   |  Discription
****************************************************************************/

#ifndef __GBDEF_H__
#define __GBDEF_H__

/*!
* \addtogroup Output	����Ľṹ���ö�ٶ���
*/
/*@{*/

/*!
 * \brief ���뵥Ԫ�ڲ�ʹ�õĺ���
 */
#define GBLOCAL		static
/*!
 * \brief ȫ��ʹ�ã��������⹫���ĺ���
 */
#define GBGLOBAL 
/*!
 * \brief ���⹫���ĺ���
 */
#define GBEXPORT 

/*!
 * \brief ������󳤶�
 */
#define GB_INPUT_MAX_LEN		31
#define GB_INPUT_BUFFER_LEN		(GB_INPUT_MAX_LEN + 1)

/*!
 * \brief ��ѡ������ַ�����
 */
#define GB_CAND_MAX_LEN			31
#define GB_CAND_BUFFER_LEN		(GB_CAND_MAX_LEN + 1)

/*!
 * \brief ���׸������ֵ
 */
#define GB_COMPONET_MAX_LEN		5
#define GB_COMPONET_BUFFER_LEN	(GB_COMPONET_MAX_LEN + 1)

/*!
 * \brief ÿһ����ú�ѡ��������
 */
#define GB_MAX_CANDIDATES			32	  /**@brief ��ѡ��������Ŀ */

/*!
 * \brief �������ڸ���
 */
#define GB_MAX_SYLLABLES			32

/*!
 * \brief Ĭ�ϵĺ�ѡBuffer����
 */
#define GB_DEFAULT_CAND_BUFFER_LEN	(128 * 2)

/*!
 * \brief �����ѡ���ʱ����������
 */
#define GB_CAND_MAX_LINE_COUNT		15

/** \brief ����¼���ٸ�ҳ�߽� */
#define GB_BUFFER_BOUND_BUFFER_LEN	64


/*!
 * \brief GBGetDesireOutput�е�option�����Ķ��壬ֻ��ѡ������һ����
 */
enum GBAlpOutputOption {
	GBA_OUTPUT_NORMAL		= 0		///<���Ĭ�ϵĴ�С״̬�ĵ���
	, GBA_OUTPUT_FCC		= 0x02  ///<�������ĸ��д�ĺ�ѡ����
	, GBA_OUTPUT_CAPITAL	= 0x04	///<�����д�ĺ�ѡ����
	, GBA_OUTPUT_LOWER		= 0x06	///<���Сд�ĺ�ѡ����
	, GBA_OUTPUT_TOGGLE_FCC	= 0x08	///<�ı䵱ǰ������׸���ĸ�Ĵ�С״̬
};
/** \brief Ĭ�ϵ����ĺ�ѡ����, ����ͨ��\ref GBSetPageOption��\ref GBGetPageOption�鿴������������ */
#define DEFAULT_CHN_CAND_COUNT				6

/** \brief Ĭ�ϵ����ں�ѡ����, ����ͨ��\ref GBSetPageOption��\ref GBGetPageOption�鿴������������ */
#define DEFAULT_SYLLABLE_CAND_COUNT			2

/** \brief Ĭ�ϵ�Alphabetic��ѡ����, ����ͨ��\ref GBSetPageOption��\ref GBGetPageOption�鿴������������ */
#define DEFAULT_ALP_CAND_COUNT				1

/** \brief ���Ը��������ֵ */
#define GB_LDB_MAX_COUNT					100

/** \brief Ĭ�ϵ�\ref GBGetCandidatesCount�������ص����ֵ */
#define GB_CAND_MAX_COUNT					100

/** \brief MDB�������� */
#define GB_MDB_MAX_COUNT					5

/** \brief �ʿ����Ƶ�� */
#define GB_UDB_UPDATE_FREQ					5

/** \brief GBMDBInit�������Buffer����Сֵ */
#define GB_MDB_BUFFER_MIN_LEN				(16 * 1024)

/** \brief GBMMI����л����� */
#define GB_MMI_SWITCH_LEVEL		2

#ifndef __GB_CHN_CONFIG_ENUM__
#define __GB_CHN_CONFIG_ENUM__
	/** \brief ��������ö�� */
#ifndef _C166
    enum GBChnConfigEnum {
        GBCFG_PINYIN_FUZZY_H_F = 0x0008,	///<ƴ����h��f��ģ��ƥ��(*)
        GBCFG_PINYIN_FUZZY_N_L = 0x0010,	///<ƴ����n��l��ģ��ƥ��(*)
        GBCFG_PINYIN_FUZZY_NG_N = 0x0020,	///<ƴ����ǰ�����ͺ������ģ��ƥ��(*)
        GBCFG_PINYIN_FUZZY_XH_X = 0x0040,	///<ƴ����ƽ�����ģ��ƥ��(*)
        GBCFG_PINYIN_FUZZY_K_G = 0x0080,	///<ƴ����k��g��ģ��ƥ��(*)
		///�رմ��鹦��, ���д��鹦�ܵ�����Ĭ�ϴ򿪴��鹦�ܣ��رմ��鹦��֮��
		///�������µ���EBEngineConfig(GBCFG_CLOSE_PHRASE, 0)�������鹦��
		///������ͬʱ�Զ��رմ������빦��
		GBCFG_CLOSE_PHRASE = 0x0100,
		///ƴ����������ƴ��ƥ��������,��֧��ģ����ƴ��ƥ��
		GBCFG_PY_1_MATCH_FUNC = 0x0200,
		///ֻƥ�������Ĵ��������ִ���һ��ĺ�ѡ
		GBCFG_ONLY_ENTIRE_PHRASE_CAND = 0x0400,
		///ʹ�ý�������״̬
		GBCFG_SYNTAX = 0x0800,
		///�ҵ�һҳ��ʱ���EBIS�ĵ�һ����ѡ��Ϊ������뵽��ѡ
		GBCFG_FIRST_PAGE_ADD_PHRASE = 0x1000,
		///���õ�һ����ѡ���ڵ���EBFindFirstPageC���ã���ʱ��pEBIS������ڵ�һ����ѡ����Ϣ
		GBCFG_SET_FIRST_CANDIDATE = 0x2000,
		///��������ʹ���ĸ��ַ���, 
		///optionΪGBChnCharset�е�һ��ֵ
		GBCFG_CHARSET_SET = 0x4000,

		///���÷ָ����ŵ���ʾ�ַ����ڶ�������Ϊһ��Unicode, 
		///optionΪһ���ַ�����'\''
		GBCFG_SET_PHRASE_SPLIT_CHAR = 0x4001,

		///���ñʻ�ͨ������ţ��ڶ�������Ϊһ��Unicode
		///optionΪһ���ַ�����'#'��������GBCFG_SET_PHRASE_SPLIT_CHAR��ͻ
		GBCFG_SET_STROKE_WILDCARD_CHAR = 0x4002,

		//���ñʻ�ͨ�������ʾ�ַ�����"��"��"/"��
		GBCFG_SET_STROKE_WILDCHAR_SHOW = 0x4003,

		///���ô������󳤶�����. 0��ʾ�������κδ���
		///optionΪ2-10��һ������
		GBCFG_SET_PHRASE_LEN_LIMIT ,

		//���ü�ƴʱ��βƥ��������
		GBCFG_SET_JP_MAX_TAIL_MATCH_COUNT,

		///ģ����r �� l
		GBCFG_PINYIN_FUZZY_R_L = 0x8000,

		///�Ƿ��ȡĬ�ϸ�Ƶ��
		GBCFG_INIT_GET_HIGHEST_FREQ_WORD = 0x00010000,

		///�����ʱ������Ƶ�֣�Ĭ�����
		GBCFG_ASSOC_NOT_FILL_HIGHEST_FREQ_WORD = 0x00020000,

		///�ʻ��ͺ������뷨���棬���봮����֮���Ƿ��ٳ�����ѡ
		GBCFG_NOT_ALLOW_USELESS_STROKE = 0x00040000,

		///�رմ������빦��
		GBCFG_CLOSE_ASSOC_PHRASE = 0x00080000,

		///ֻ��������ƥ��İ������еĴ����ѡ
		GBCFG_FIND_ONLY_FULL_MATCHING = 0x00100000,

		///�Ƿ�֧�ֱ����Ŵ�������
		GBCFG_ASSOCIATE_INTEPCT = 0x00200000,

		///��ģ��״̬(Amb Pinyin��Bopomofo��Jyutping)�Ƿ������ַ���ת��Ϊƴ����
		GBCFG_TRANSLATE_INPUT_STRING = 0x00400000,

		///<��������ֻ����ֵ�ƴ�������������ƴ����
		GBCFG_OUT_ZI_SYLLABLE  = 0x00800000,

		///<�رտ�ݲ��׹��ܡ�
		GBCFG_CLOSE_COMPONENT = 0x01000000,

		///��ת��֮����ַ�������ƴ�������б�
		GBCFG_ADD_TRANSLATE_INPUT_STRING_TO_SYLLABLE = 0x02000000,//(1 << 25)

		///�����ʱ���Ƿ�����Ƶ��
		GBCFG_ASSOCIATE_HIGH_FREQ = 0x04000000,

		//modified by ZhaoKun at 2010-2-23 13:52:52</add>
		//note : 
		///�Զ���ƴ
		GBCFG_AUTO_JIANPIN = 0x08000000,
		//modified by ZhaoKun end
		// start add [2011-8-22 Zhaokun]
		// �Ծ�ȷ���ڽ��в��
		GBCFG_SPLIT_ACC_SYLLABLE = 0x10000000,
		// ��β��ȷƥ��
		GBCFG_TAIL_ACC_MATCH = 0x20000000
		// end add [2011-8-22 Zhaokun]
    };
#else
#define GBCFG_PINYIN_FUZZY_H_F	((unsigned long)0x0008)
#define GBCFG_PINYIN_FUZZY_N_L	((unsigned long)0x0010)
#define GBCFG_PINYIN_FUZZY_NG_N	((unsigned long)0x0020)
#define GBCFG_PINYIN_FUZZY_XH_X	((unsigned long)0x0040)
#define GBCFG_PINYIN_FUZZY_K_G	((unsigned long)0x0080)
#define GBCFG_CLOSE_PHRASE	((unsigned long)0x0100)
#define GBCFG_PY_1_MATCH_FUNC	((unsigned long)0x0200)
#define GBCFG_ONLY_ENTIRE_PHRASE_CAND	((unsigned long)0x0400)
#define GBCFG_SYNTAX	((unsigned long)0x0800)
#define GBCFG_FIRST_PAGE_ADD_PHRASE	((unsigned long)0x1000)
#define GBCFG_SET_FIRST_CANDIDATE	((unsigned long)0x2000)
#define GBCFG_CHARSET_SET	((unsigned long)0x4000)
#define GB_CHARSET_BIGSET   0	
#define GB_CHARSET_GB2312   1
#define GB_CHARSET_BIG5     2
#define GBCFG_SET_PHRASE_SPLIT_CHAR	((unsigned long)0x4001)
#define GBCFG_SET_STROKE_WILDCARD_CHAR	((unsigned long)0x4002)
#define GBCFG_SET_STROKE_WILDCHAR_SHOW	((unsigned long)0x4003)
#define GBCFG_SET_PHRASE_LEN_LIMIT	((unsigned long)0x4004)
#define GBCFG_SET_JP_MAX_TAIL_MATCH_COUNT	((unsigned long)0x4005)
#define GBCFG_PINYIN_FUZZY_R_L	((unsigned long)0x8000)
#define GBCFG_INIT_GET_HIGHEST_FREQ_WORD	((unsigned long)0x00010000)
#define GBCFG_ASSOC_NOT_FILL_HIGHEST_FREQ_WORD	((unsigned long)0x00020000)
#define GBCFG_NOT_ALLOW_USELESS_STROKE	((unsigned long)0x00040000)
#define GBCFG_CLOSE_ASSOC_PHRASE	((unsigned long)0x00080000)
#define GBCFG_FIND_ONLY_FULL_MATCHING	((unsigned long)0x00100000)
#define GBCFG_ASSOCIATE_INTEPCT	((unsigned long)0x00200000)
#define GBCFG_TRANSLATE_INPUT_STRING	((unsigned long)0x00400000)
#define GBCFG_OUT_ZI_SYLLABLE	((unsigned long)0x00800000)
#define GBCFG_CLOSE_COMPONENT	((unsigned long)0x01000000)
#define GBCFG_ADD_TRANSLATE_INPUT_STRING_TO_SYLLABLE	((unsigned long)0x02000000)
#define GBCFG_ASSOCIATE_HIGH_FREQ	((unsigned long)0x04000000)
#define GBCFG_AUTO_JIANPIN	((unsigned long)0x08000000)
#define GBCFG_SPLIT_ACC_SYLLABLE ((unsigned long)0x10000000)
#define GBCFG_TAIL_ACC_MATCH ((unsigned long)0x20000000)
#endif
#define GBCFG_PINYIN_FUZZY_H    GBCFG_PINYIN_FUZZY_XH_X
#endif

	/** \brief  */
	enum EngineIDEnum
	{
		GB_ENGINE_CHINESE			///<����������������ã���Ӧ������ѡ��ΪGBChnConfigEnum
		, GB_ENGINE_ALPHABETIC		///<Alphabetic������������ã���Ӧ������ѡ��ΪGBAlp_Config
		, GB_ENGINE_SYNTAX			///<���������������ã���Ӧ������ѡ��ΪGBS_Config
		, GB_ENGINE_FUNCTION		///<���ܷ�������ã���Ӧ������ѡ��ΪGB_Function_Option
		//added by weizhiping at 2010-7-7 15:32:07
		//note : ���Ӻ�������ID����		
		, GB_ENGINE_KOREAN			///<��������ID		
		//added by weizhiping end
		// start add [2011-5-24 haj]
		, GB_ENGINE_MARS			///<����������ID
		// end add [2011-5-24 haj]
		, GB_ENGINE_COUNT			///<�������
	};

#ifndef __GB_CHN_CHARSET_ENUM__
#define __GB_CHN_CHARSET_ENUM__
	/** \brief �����ַ��� */
	enum GBChnCharset {
		GB_CHARSET_ALL				///<���еĺ��ֺʹ��ﶼ������Ϊ��ѡ
		, GB_CHARSET_ONLY_GB2312	///<ֻ��GB2312�ĺ��ֺʹ��������Ϊ��ѡ
		, GB_CHARSET_ONLY_BIG5		///<ֻ��BIG5�ĺ��ֺʹ��������Ϊ��ѡ
		///<haj chg ���������������������ģ�
		///<#define CHARSETDATA_TYPE_GBK	 0x0004			///< 0x4e00 + 20901
		, GB_CHARSET_ONLY_GBK=4		///<ֻ��GBK�ĺ��ֺʹ��������Ϊ��ѡ
		///<GB18030������������û�п��ǣ���ʱ��GB18030��GBK(GB2312)����
		, GB_CHARSET_ONLY_GB18030	///<ֻ��GB18030�ĺ��ֺʹ��������Ϊ��ѡ
	};
#endif

#ifndef __GB_ALP_CONFIG_ENUM__
#define __GB_ALP_CONFIG_ENUM__
#ifndef _C166
enum GBAlp_Config {
	GBALP_AUTO_CORRECTION = 0x0010 //���Զ�ģ��ƥ��
	, GBALP_CLOSE_AUTO_COMPLETION = 0x0020 //�ر��Զ���ɹ���
	, GBALP_INPUTSTRING_IS_FIRST_CANDIDATE = (1 << 6) ///<��Explicit ģʽ����, ���봮��Ϊ��һ����ѡ
	, GBALP_QWERTY_OUTPUT_DEFAULT_STRING = (1 << 7) ///<��Qwertyģʽ����, ���һ��Ĭ�ϵ��ַ�����Ϊ��ѡ
	, GBALP_FIRST_KEY_ASSOC = (1 << 8)	///<Explicitģʽ��Qwerty���棬��һ�������Ϳ�ʼ�Զ���ɹ��ܣ�
	                                    ///<���ͬʱ����GBALP_CLOSE_AUTO_COMPLETION���ܣ��˹�����Ч
	, GBALP_ASSOC_NO_DERIVE = (1 << 9)			///<�Ƿ����������
	//start[2010-4-20 zhj]
	, GBALP_KEEP_ALL_HEADER = (((unsigned long)1) << 10)			///<�Ƿ��ȡ���ǵ��ʵ�header
	//end[2010-4-20 zhj]
	//start[2010-4-26 zhj]
	, GBALP_SET_AVOID_PATENT_SYMBOL = (((unsigned long)1) << 11)			///<���ù��ר����ʹ�õķ���
	//end[2010-4-26 zhj]
	//start[2010-5-4 zhj]
	, GBALP_CUSTOM_SYMBOL_TABLE = (((unsigned long)1) << 12)	///<�Ƿ�������û��Զ��������
	//end[2010-5-4 zhj]
	//start[2010-5-12 zhj]
	, GBALP_SET_EMBEDDED_INTERPUNCTION_KEY = (((unsigned long)1) << 13)	///<�������ܱ�����
	//end[2010-5-12 zhj]
	// Start Add [2011-7-15 haj]
	,GBALP_CLOSE_AVOID_PATENT = (((unsigned long)1) << 14)	///<�򿪹��ר�����ܣ�Ĭ�Ͽ���	
	// end [2011-7-15 haj]

};
#else
#define GBALP_AUTO_CORRECTION	((unsigned long)0x0010)
#define GBALP_CLOSE_AUTO_COMPLETION	((unsigned long)0x0020)
#define GBALP_INPUTSTRING_IS_FIRST_CANDIDATE	(((unsigned long)1) << 6)
#define GBALP_QWERTY_OUTPUT_DEFAULT_STRING	(((unsigned long)1) << 7)
#define GBALP_FIRST_KEY_ASSOC	(((unsigned long)1) << 8)
#define GBALP_ASSOC_NO_DERIVE	(((unsigned long)1) << 9)
#define GBALP_KEEP_ALL_HEADER	(((unsigned long)1) << 10)
#define GBALP_SET_AVOID_PATENT_SYMBOL	(((unsigned long)1) << 11)
#define GBALP_CUSTOM_SYMBOL_TABLE	(((unsigned long)1) << 12)
#define GBALP_SET_EMBEDDED_INTERPUNCTION_KEY	(((unsigned long)1) << 13)
#define GBALP_CLOSE_AVOID_PATENT	(((unsigned long)1) << 14)
#endif
#endif

#ifndef __GB_SYNTAX_CONFIG_ENUM__
#define __GB_SYNTAX_CONFIG_ENUM__

/** \brief ������������ú���*/
enum GBS_Config{ 
	GBS_Config_CompStr = 1	///<ʹ��CompStr, ��pGBIS->pAuxInfo->pCompStr�л������ǰ��Ԥ���ַ���
	, GBS_Config_CompStr_From_Beginning = 2 ///<ʹ��CompStr, Ĭ�ϵĺ�ѡ�����봮��ͷ���ң�������
};
#endif


/** \brief GBAPI/GBMMI�������� */
#ifndef _C166
enum GB_Function_Option{
	/*GBFO_Display_Key_Sequence  = 1          //(default 0)������Alphabetic�������Ƿ���ʾ��������
	, */
	//!����Alp��Up�Ƿ�ʵ��������������, ��������ܵ�ʱ��,Ҫ��ͻ���Alphabetic״̬��Ҫ��ʾ�������С�
	GBFO_Alp_Up_To_Input_Key_Sequence = 1    
	//!����Up�Ƿ�ʵ��������������, ��������ܵ�ʱ��,Ҫ��ͻ�������״̬��Ҫ��ʾ�������С�
	, GBFO_Chn_Up_To_Input_Key_Sequence = (1 << 1)    
	//change start[2010-4-8 zhj]
	//, GBFO_No_Response_When_Key_No_Cand = (1 << 2) //!<��������а���û�к�ѡ��ʱ�򣬲���Ӧ���޺�ѡʱ�Զ����˹���
	, GBFO_Chn_No_Response_When_Key_No_Cand = (1 << 2) //!<������������а���û�к�ѡ��ʱ�򣬲���Ӧ���޺�ѡʱ�Զ����˹���
	//change end[2010-4-8 zhj]
	, GBFO_Alp_Add_Space_After_Cand_Confirmed = (1 << 3) ///<alphabetic ѡ������֮�����һ���ո�
	/*!��MMI����֧���û�����ʹ��ܣ�Ҫ��OEM�û���Ҫ�������״̬ ʵ��һ����ѡ�� ��ʾ��������
	1. �û��Ѿ�ѡ�����ĸ
	2. ��ǰ�û��Ѿ�����ģ����ǻ�û��ƥ���Ӧ��ĸ�İ�������*/
	, GBFO_Alp_UAW = (1 << 4)      
	, GBFO_OK_Enter_Selected	= (1 << 6)			///<��û�н����ѡ״̬���棬OK������ѡ��״̬��ֻ���
	, GBFO_Chn_Syntex_Key_Sequence_Edit = (1 << 7)  ///<����ƴ�����뷨: ֧�ְ��������޸�
	, GBFO_Chn_Switch_Alp	= (1 << 9)				///<���������뷨�У��Ƿ�ʹ����Ӣ�л��Ĺ���
	, GBFO_API_Stop_Log = (1 << 10)
	, GBFO_Alp_UAW_Confirm = (1 << 11)				///<��Alphabetic Predictive/HalfQwerty ģʽ�´�����ʵ�ȷ������
	, GBFO_Multi_Tap_Show_Cand_Wnd = (1 << 12)		///<��MultiTap״̬������Ȼ�򿪺�ѡ���ڣ�Ĭ�Ϲر�, ��ʱ�ĺ�ѡ��ҳ�����뵱ǰ���Ե�һ��
	, GBFO_Scroll_Cand_By_Row = (1 << 13)			///<һ��һ�еضԺ�ѡ���з�ҳ��Ĭ����һҳһҳ(����֧��)
	, GBFO_Tch_Scr	= (1 << 14)						///<Alp�����״̬���棬֧�ִ�������ʹ��GBCL_ROW_TCH_SCR��ѡ��
	, GBFO_Alp_Qwerty_Spell	= (1 << 15)				///<Alp�����״̬���棬֧�ִ�������ʹ��GBCL_ROW_TCH_SCR��ѡ��
	, GBFO_Alp_UAW_Support_Tchscr = (1<<16)			///<Alp�����״̬���棬֧�ִ�������ʹ��GBCL_Row_TchScr��ѡ��. 
	//start[2010-3-15 zhj]
	/*!GBFO_Chn_All_Num_Can_Continuously_Input����Ӱ��multitap�������棬��˵�����Ͽ�wrapper������api��
	�ģ�������������ǿ���Ӱ��gbmmi���api��ġ������������ã���ע������ż���ʱ��
	�����ñ�����֧��GBIKO_Input_Status_Confirm_Candidate�Ĺ���*/
	, GBFO_Chn_All_Num_Can_Continuously_Input = (1<<17)	///<ƴ��ģʽ���Ƿ�������������κ����ִ�
	//end[2010-3-15 zhj]
	//start[2010-3-8 zhj]
	, GBFO_Chn_Display_Input_Key_Sequence = (1<<18)	///�������ּ���ƴ�����뷨����������Ƿ���ʾ���ְ�������
	//end[2010-3-8 zhj]
	//start[2010-3-24 zhj]
	, GBFO_Alp_All_Num_Can_Continuously_Input = (1<<19)	///Ӣ�����ּ�����������ģʽ���Ƿ��ܹ�������������
	//end[2010-3-24 zhj]
	//start[2010-4-8 zhj]
	, GBFO_Alp_No_Response_When_Key_No_Cand = (1 <<20) ///<Ӣ����������а���û�к�ѡ��ʱ�򣬲���Ӧ���޺�ѡʱ�Զ����˹���
	//end[2010-4-8 zhj]

	//start[2010-4-26 zhj]
	,GBFO_Alp_Paging_By_Lower = (1<<21)	///<��ʹ��Сд��ѡ���з�ҳ�������û������ĺ�ѡ���з�ҳ
	//end[2010-4-26 zhj]
	
	//start[2010-10-14 zhj]
	,GBFO_Alp_Use_AbbrWordTree_When_Seamless_Switch = (1<<22)	///<�޷��л�ʱ��һ������д�ʱ�ĺ�ѡ
	//end[2010-10-14 zhj]

	//start[2010-12-28 zhj]
	,GBFO_Alp_Get_Only_Lower = (1<<23)	///<ֻȡСд��ʽ�ĵ���ĸ��ѡ
	,GBFO_Alp_Get_Only_Cap = (1<<24)	///<ֻȡ��д��ʽ�ĵ���ĸ��ѡ
	//end[2010-12-28 zhj]
	// start[2011-3-8 haj for Alpha GBCT_Associate]
	, GBFO_Alp_Open_Associat = (1<<25)	///<����Alpha�������빦��
	// end[2011-3-8 haj]
	// Start add [2011-5-31 haj]
	, GBFO_Open_Chn_2_Mars = (1<<26)	///<���������л��������Ĺ���	
	// end [2011-5-31 haj]
	// Start Add [2011-7-22 haj]
	, GBFO_Mars_Char_Random_Cand = (1<<27)	///<��������������ֻ�ȡ��ѡ
	, GBFO_Mars_Word_Random_Cand = (1<<28)	///<��������������ʻ�ȡ��ѡ
	// end [2011-7-22 haj]
	//start[2010-4-15 zhj]
	//���������TASKING�б���ͨ��������֪��Ϊʲô
	,GBFO_END
	//[2010-4-15 zhj]
};
#else
#define GBFO_Alp_Up_To_Input_Key_Sequence		1    
#define GBFO_Chn_Up_To_Input_Key_Sequence		((unsigned long)1 << 1)    
#define GBFO_Chn_No_Response_When_Key_No_Cand		((unsigned long)1 << 2)
#define GBFO_Alp_Add_Space_After_Cand_Confirmed		((unsigned long)1 << 3)
#define GBFO_Alp_UAW		((unsigned long)1 << 4)      
#define GBFO_OK_Enter_Selected		((unsigned long)1 << 6)
#define GBFO_Chn_Syntex_Key_Sequence_Edit		((unsigned long)1 << 7)
#define GBFO_Chn_Switch_Alp		((unsigned long)1 << 9)
#define GBFO_API_Stop_Log		((unsigned long)1 << 10)
#define GBFO_Alp_UAW_Confirm		((unsigned long)1 << 11)
#define GBFO_Multi_Tap_Show_Cand_Wnd		((unsigned long)1 << 12)
#define GBFO_Scroll_Cand_By_Row		((unsigned long)1 << 13)
#define GBFO_Tch_Scr		((unsigned long)1 << 14)
#define GBFO_Alp_Qwerty_Spell		((unsigned long)1 << 15)
#define GBFO_Alp_UAW_Support_Tchscr		((unsigned long)1<<16)	
#define GBFO_Chn_All_Num_Can_Continuously_Input		((unsigned long)1<<17)	
#define GBFO_Chn_Display_Input_Key_Sequence		((unsigned long)1<<18)	
#define GBFO_Alp_All_Num_Can_Continuously_Input		((unsigned long)1<<19)
#define GBFO_Alp_No_Response_When_Key_No_Cand		((unsigned long)1 <<20) 
//start[2010-4-26 zhj]
#define GBFO_Alp_Paging_By_Lower ((unsigned long)1 <<21) 
//end[2010-4-26 zhj]

//start[2010-10-14 zhj]
#define GBFO_Alp_Use_AbbrWordTree_When_Seamless_Switch ((unsigned long)1<<22)
//end[2010-10-14 zhj]

//start[2010-12-28 zhj]
#define GBFO_Alp_Get_Only_Lower ((unsigned long)1<<23)	///<ֻȡСд��ʽ�ĵ���ĸ��ѡ
#define GBFO_Alp_Get_Only_Cap ((unsigned long)1<<24)	///<ֻȡ��д��ʽ�ĵ���ĸ��ѡ
//end[2010-12-28 zhj]
// start[2011-3-8 haj for Alpha GBCT_Associate]
#define GBFO_Alp_Open_Associat ((unsigned long)1<<25)	///<����Alpha�������빦��
// end[2011-3-8 haj]
// Start add [2011-5-31 haj]
#define GBFO_Open_Chn_2_Mars   ((unsigned long)1<<26)	///<���������л��������Ĺ���	
// end [2011-5-31 haj]
// Start Add [2011-7-22 haj]
#define GBFO_Mars_Char_Random_Cand   ((unsigned long)1<<27)	///<��������������ֻ�ȡ��ѡ	
#define GBFO_Mars_Word_Random_Cand   ((unsigned long)1<<28)	///<��������������ʻ�ȡ��ѡ	
// end [2011-7-22 haj]
#endif

/*!
* \brief Ĭ�ϵ�GBMMI����
*/
#define GBMMI_FUNCTION_OPTION_DEFAULT		\
	(GBFO_Alp_Up_To_Input_Key_Sequence  \
	| GBFO_Chn_Up_To_Input_Key_Sequence \
	| GBFO_Alp_Add_Space_After_Cand_Confirmed \
	| GBFO_Alp_UAW)

//#define GBMMI_NOKIA_FUNCTION (GBFO_No_Response_When_Key_No_Cand)


/*!
* \brief ������Ϣ�Ķ��壬����Key��Ϣ��Event��Ϣ���֣�
*  Key��Ϣû�в�����Event��Ϣ���Դ���һ�����ݲ�ͬ����Ϣ�����unsigned long����
*/
enum GBEventEnum{
	GBEvent_None = 0
	, GBKEY_BACK	= 0x9
	, GBKEY_RETURN	= 0xA
	, GBKEY_SPACE   = 0x20
	, GBKEY_COMMA	= 0x2c
	, GBKEY_PERIOD	= 0x2e

	, GBKEY_0 = '0'
	, GBKEY_1
	, GBKEY_2
	, GBKEY_3
	, GBKEY_4
	, GBKEY_5
	, GBKEY_6
	, GBKEY_7
	, GBKEY_8
	, GBKEY_9

	, GBKEY_A = 'a'
	, GBKEY_B
	, GBKEY_C
	, GBKEY_D
	, GBKEY_E
	, GBKEY_F
	, GBKEY_G
	, GBKEY_H
	, GBKEY_I
	, GBKEY_J
	, GBKEY_K
	, GBKEY_L
	, GBKEY_M
	, GBKEY_N
	, GBKEY_O
	, GBKEY_P
	, GBKEY_Q
	, GBKEY_R
	, GBKEY_S
	, GBKEY_T
	, GBKEY_U
	, GBKEY_V
	, GBKEY_W
	, GBKEY_X
	, GBKEY_Y
	, GBKEY_Z

	, GBKEY_AMB_SPECIAL_A = 0x80	///< ע������ţ�������ʱ������ģʽ��������ָ���
	, GBKEY_AMB_SPECIAL_B			///< ��Alphabetic�ı��Сд
	, GBKEY_AMB_SPECIAL_C			///< �����������༭�������
	, GBKEY_AMB_SPECIAL_D			///< Latinֱ�ӽ�������״̬��������
	, GBKEY_AMB_SPECIAL_E			///< ������ģʽע���޷��л���
	, GBKEY_AMB_SPECIAL_F			///< Ĭ�ϲ�����
	, GBKEY_AMB_SPECIAL_G			///< Ĭ�ϲ�����
	, GBKEY_AMB_SPECIAL_H			///< Ĭ�ϲ�����

	, GBKEY_OK			  = 0x90
	, GBKEY_LEFT
	, GBKEY_RIGHT
	, GBKEY_UP
	, GBKEY_DOWN

	, GBKEY_NEXT_PAGE_CANDIATE  ///<�����һҳ�ĺ�ѡ�����Ұ�ѡ��λ�ö�Ϊҳ�ĵ�һ����ѡ, ��ҳʧ��Ҳ����GBOK
	, GBKEY_PREV_PAGE_CANDIATE	///<�����һҳ�ĺ�ѡ�����Ұ�ѡ��λ�ö�Ϊҳ�ĵ�һ����ѡ, ��ҳʧ��Ҳ����GBOK
	, GBKEY_NEXT_CANDIDATE		///<ѡ����������һ����ѡ
	, GBKEY_PREV_CANDIDATE		///<ѡ������ǰ��һ����ѡ
	, GBKEY_NEXT_ROW_CANDIDATE  ///<�ڶ��к�ѡ��ʵ����:��һ�к�ѡ, ��ҳʧ��Ҳ����GBOK
	, GBKEY_PREV_ROW_CANDIDATE	///<�ڶ��к�ѡ��ʵ����:��һ�к�ѡ, ��ҳʧ��Ҳ����GBOK


	, GBKEY_NEXT_PAGE_SYLLABLE	///<�����һҳ��ƴ�������Ұѵ�ǰѡ���ƴ����Ϊҳ�ĵ�һ��, ��ҳʧ��Ҳ����GBOK
	, GBKEY_PREV_PAGE_SYLLABLE	///<���ǰһҳ��ƴ�������Ұѵ�ǰѡ���ƴ����Ϊҳ�ĵ�һ��, ��ҳʧ��Ҳ����GBOK
	, GBKEY_NEXT_SYLLABLE		///<�ѵ�ǰѡ���ƴ�������ƶ�һ��
	, GBKEY_PREV_SYLLABLE		///<�ѵ�ǰѡ���ƴ����ǰ�ƶ�һ��

//	, GBKEY_START_MULTITAP_SYMBOLS		///<���ݵ�ǰ������ģʽ����ʼMultitap ���(chn/alp)
//	, GBKEY_START_FULL_SCREEN_SYMBOLS	///<��ʼȫ�����ģʽ

	, GBEVENT_SELECT_SYLLABLE_PAGED		///<ѡ��ǰ��ҳ������, ������ЧֵΪ0����ǰҳ���ڵĸ���
	, GBEVENT_SELECT_SYLLABLE			///<ѡ��ȫ�ֵ�����, ������ЧֵΪ0���������ڵ�����

	, GBEVENT_SELECT_CANDIDATE			///<ѡ��һ����ѡ��param�����ĵ�16λ��ʾѡ����У���16λ��ʾѡ����С�
	, GBEVENT_SET_CANDIDATE_SELECTED	///<����һ����ѡ��Ϊѡ��״̬��param�����ĵ�16λ��ʾѡ����У���16λ��ʾѡ����С�

	, GBEVENT_INPUT_UNICODE				///<����һ��Unicodeֵ
	, GBEVENT_UPDATE_CANDIDATE			///<���º�ѡ���û����ⲿʹ��GBSelectSyllable����������ʽ
										///<�ı��������״̬������û�иı�����ģʽ
	
    //added by weizhiping at 2010-6-21 15:17:24										
	, GBEVENT_SET_INPUT_STRING			///<�����û�ͨ��GBMMIֱ�������������봮��ȡ��Ӧ��ѡ
	//added by weizhiping end
	, GBEVENT_SET_SYLLABLE_TONE					///<������������Χ�μ�GBChnToneEnum
	// Start Add [2011-7-20 haj]
	, GBEVENT_SELECT_CANDIDATE_BY_INDEX ///<ͨ��index��0-9����ѡ���ѡ
	// end [2011-7-20 haj]
	//ע���¼�
	, GBKEY_BPMF_TONE_NULL			//ע��������ȱʡƥ���������{
	, GBKEY_BPMF_TONE_1 = 0x02C9	//ע��������1��
	, GBKEY_BPMF_TONE_2 = 0x02CA	//ע��������2��
	, GBKEY_BPMF_TONE_3 = 0x02C7	//ע��������3��
	, GBKEY_BPMF_TONE_4 = 0x02CB	//ע��������4��
	, GBKEY_BPMF_TONE_5 = 0x02D9	//ע������������

	, GBKEY_BPMF_B = 0x3105   
	, GBKEY_BPMF_P    
	, GBKEY_BPMF_M    
	, GBKEY_BPMF_F    
	, GBKEY_BPMF_D    
	, GBKEY_BPMF_T    
	, GBKEY_BPMF_N    
	, GBKEY_BPMF_L    
	, GBKEY_BPMF_G    
	, GBKEY_BPMF_K    
	, GBKEY_BPMF_H    
	, GBKEY_BPMF_J    
	, GBKEY_BPMF_Q    
	, GBKEY_BPMF_X    
	, GBKEY_BPMF_ZH   
	, GBKEY_BPMF_CH   
	, GBKEY_BPMF_SH   
	, GBKEY_BPMF_R    
	, GBKEY_BPMF_Z    
	, GBKEY_BPMF_C    
	, GBKEY_BPMF_S    
	, GBKEY_BPMF_A    
	, GBKEY_BPMF_O    
	, GBKEY_BPMF_E    
	, GBKEY_BPMF_EH   
	, GBKEY_BPMF_AI   
	, GBKEY_BPMF_EI   
	, GBKEY_BPMF_AU   
	, GBKEY_BPMF_OU   
	, GBKEY_BPMF_AN   
	, GBKEY_BPMF_EN   
	, GBKEY_BPMF_ANG  
	, GBKEY_BPMF_ENG  
	, GBKEY_BPMF_ER   
	, GBKEY_BPMF_I    
	, GBKEY_BPMF_U    
	, GBKEY_BPMF_IU 

};
/*!
* \brief GB����API�ķ���ֵ����
*/
enum GBReturnEnum{
	GBOK										///<�¼�����ɹ�
	, GBIngore								///<�¼�������
	, GB_NOT_HANDLED					///<GBMMIû�д������Ϣ������ǰ�����Ϣ����ҪOEM��������
	, GB_Failed							///<ֻ���һЩӦ�÷���True��False����Ϣ����ʾFalse.

	, GBR_UAW_CONTINUE					///<����ѡ������ʵ�״̬
	, GBR_SELECTED_TIPS					///<ѡ��ĺ�ѡ����ʾ�ַ���

	, GB_Message_Start = 0x1000
	, GB_API_NO_MORE_SELECTION			///<�����ĵ��������棬�Ѿ�û���û���ѡ��
	, GB_API_UDB_NO_MORE_PHRASE			///<�Ѿ�û���������������
	, GB_API_CAND_BUFFER_FULL			///<��ѡ�Ĵ�ŵ�Buffer����
	, GB_API_NOT_MORE_PAGE				///<û������ҳ�ĺ�ѡ
	, GB_API_GET_LAST_ERROR_NULL_PARAM	///<GBGetLastError��������ΪNULL
	, GB_API_CHN_CONTINUE_SELECTION = GBR_UAW_CONTINUE		///<�������������
	, GB_API_MARS_CONTINUE_SELECTION = GB_API_CHN_CONTINUE_SELECTION		///<��������������
	, GB_API_CHN_2_MARS	= GB_API_GET_LAST_ERROR_NULL_PARAM+1           		///<�����л���������
	, GB_API_MARS_FINISH_SELECT                             ///<��������������
	, GB_API_MARS_OUTPUT_BUFFER_FULL                        ///<�����л���������
	, GB_API_MARS_NO_OPEN                                   ///<����������û�д�
	, GB_API_CHN_SELECT_INTERPUNCTION_CHAR                  ///<����ѡ����һ��������
	, GBM_Alp_Message_Start = 0x2000
	, GBM_Chn_Message_Start = 0x3000
	, GBM_MMI_Message_Start = 0x4000
	, GBM_MMI_NO_SUCH_INTER_KEY			///<GBMMIUnregisterInterpunctionKey����û���ҵ���Ӧ�ļ�ֵ

	, GBW_Warning_Start = 0x5000
	, GBW_ALP_Warning_Start = GBW_Warning_Start
	, GBW_CHN_Warning_Start = 0x6000
	, GBW_MMI_Warning_Start = 0x7000
	, GBW_MMI_STACK_NOTIFY_IS_NULL			///<mSwitchStack��fpNotifyΪNULL

	, GBE_Error_Start = -0x1000
	, GBE_ALP_Error_Start = GBE_Error_Start
	, GBE_ALP_FAILED                     = GBE_ALP_Error_Start + 1	//!<alp�������ʧ��
	, GBE_ALP_INVALID_INDEX              = GBE_ALP_Error_Start + 100	//!<����ĺ�ѡ����
	, GBE_ALP_NOTINIT					 = GBE_ALP_Error_Start + 2 //!<û�е���GBLtStartup()!
	, GBE_ALP_PEBIS_NULL				 = GBE_ALP_Error_Start + 3 //!<pEBISΪ��.
	, GBE_ALP_INVALID_INPUT_LEN          = GBE_ALP_Error_Start + 4	//!<�������г��ȴ���
	, GBE_ALP_INVALID_DESIRE_LEN         = GBE_ALP_Error_Start + 5	//!<���������
	, GBE_ALP_INVALID_STATUS             = GBE_ALP_Error_Start + 7	//!<�����״̬
	, GBE_ALP_NO_MATCH                   = GBE_ALP_Error_Start + 8 //!<û�ҵ�ƥ�䴮
	, GBE_ALP_INVALID_INVOKE             = GBE_ALP_Error_Start + 9 //!<�Ƿ�����
	, GBE_ALP_NO_WORD                    = GBE_ALP_Error_Start + 10 //!<���ʱ�����û���κε���
	, GBE_ALP_INVALID_DESIRE             = GBE_ALP_Error_Start + 12	//!<���������
	, GBE_ALP_INVALID_DESIRE_COUNT       = GBE_ALP_Error_Start + 13	//!<���������
	, GBE_ALP_NO_DATA_FILE               = GBE_ALP_Error_Start + 14	//!<û������uwenjian
	, GBE_ALP_INVALID_DATA_FORMAT        = GBE_ALP_Error_Start + 15	//!<��������ݸ�ʽ
	, GBE_ALP_FAILED_ALLOC_MEM           = GBE_ALP_Error_Start + 16	//!<�����ڴ����
	, GBE_ALP_CORRUPTED_DATA_FILE        = GBE_ALP_Error_Start + 17	//!<�����ļ����Ǵʱ��ļ�
	, GBE_ALP_MISS_DATA                  = GBE_ALP_Error_Start + 18	//!<ȱ������
	, GBE_ALP_INVALID_CHAR               = GBE_ALP_Error_Start + 19	//!<������ַ�
	, GBE_ALP_WORD_TOO_LONG              = GBE_ALP_Error_Start + 20	//!<����̫��
	, GBE_ALP_NULL_WORD                  = GBE_ALP_Error_Start + 21	//!<���ǿյ�
	, GBE_ALP_SH_NO_SPACE                = GBE_ALP_Error_Start + 22	//!<����ʿռ䲻��
	, GBE_ALP_WORD_EXISTS                = GBE_ALP_Error_Start + 23	//!<������Ѿ�����
	, GBE_ALP_INVALID_VALIDCHAR          = GBE_ALP_Error_Start + 24 //!<�����е��ַ���������
	, GBE_ALP_DATA_MISMATCH              = GBE_ALP_Error_Start + 25 //!<����������汾��ƥ��
	//��������ݴ���
	, GBE_ALP_SH_BUFFER_TO_SMALL         = GBE_ALP_Error_Start + 26 //!<����EBShDataInit��ʱ��, �������ĳ��Ȳ���
	, GBE_ALP_SH_CORRUPT_DATA            = GBE_ALP_Error_Start + 27 //!<��������������
	, GBE_ALP_SH_INVALID_ADDRESS         = GBE_ALP_Error_Start + 28 //!<��������ݵ�ͷ��ַ���ܱ�4����
	, GBE_ALP_SH_NOT_INIT                = GBE_ALP_Error_Start + 30 //!<����ʺʹ����Ƶ����û�г�ʼ��
	, GBE_ALP_SH_INVALID_WORD            = GBE_ALP_Error_Start + 32 //!<����������а����Ƿ�����ĸ
	, GBE_ALP_SH_SPACE_NOT_ENOUGH        = GBE_ALP_Error_Start + 33 //!<�ռ䲻��
	, GBE_ALP_SH_DUPLICATE               = GBE_ALP_Error_Start + 34 //!<�Ѿ�����һ����ȫ��ͬ�ĵ���
	, GBE_ALP_SH_PHRASE_INVALID_LENGTH   = GBE_ALP_Error_Start + 35 //!<�����̫����
	, GBE_ALP_Failed_To_Init //!<�����ʼ��ʧ��
	, GBE_ALP_Failed_To_Attach_UDB	//!<UDB����ʧ��
	, GBE_CHN_Error_Start = -0x2000
	, GBE_CHN_FAILED					 = GBE_CHN_Error_Start + 1 //!<ʧ��
	, GBE_CHN_NOTINIT					 = GBE_CHN_Error_Start + 2 //!<û�е���EBStartup()!
	, GBE_CHN_PEBIS_NULL				 = GBE_CHN_Error_Start + 3 //!<pEBISΪ��.
	, GBE_CHN_METHOD_INVALID			 = GBE_CHN_Error_Start + 4 //!<���뷨���ʹ���
	, GBE_CHN_DESIRE_LEN_INVALID		 = GBE_CHN_Error_Start + 5 //!<�û���Ҫ�ĳ��ȴ���.
	, GBE_CHN_KEY_INVALID				 = GBE_CHN_Error_Start + 6 //!<����EBTestKeyʱ�İ������Ϸ�
	, GBE_CHN_STATUS_ERROR				 = GBE_CHN_Error_Start + 7 //!<pEBIS->status����ȷ�����ܵ���.
	, GBE_CHN_ASSOC_ISN_ERROR			 = GBE_CHN_Error_Start + 8 //!<AssociateISN == GBE_CHN_NULL

	, GBE_CHN_INVALID_CHAR             = GBE_CHN_Error_Start + 9 //!<�Ƿ����ַ�
	, GBE_CHN_INVALID_TONE             = GBE_CHN_Error_Start + 10 //!<�Ƿ�������
	, GBE_CHN_INVALID_INPUT_LEN        = GBE_CHN_Error_Start + 11 //!<���봮�ĳ��ȹ���
	, GBE_CHN_FIRST_IS_WILDCARD        = GBE_CHN_Error_Start + 12 //!<��һ��������ַ���ͨ���
	, GBE_CHN_NO_MATCH_WORD            = GBE_CHN_Error_Start + 13 //!<û��ƥ�����
	, GBE_CHN_NO_MATCH_COMPONENT       = GBE_CHN_Error_Start + 14 //!<û��ƥ��Ĳ���
	, GBE_CHN_INVALID_SYLLABLE         = GBE_CHN_Error_Start + 15 //!<�Ƿ�������
	, GBE_CHN_INVALID_SYLLABLE_INDEX   = GBE_CHN_Error_Start + 16 //!<�Ƿ��������±�
	, GBE_CHN_INPUT_STRING_NULL        = GBE_CHN_Error_Start + 17 //!<���봮Ϊ��
	, GBE_CHN_DATA_FILE_NOT_FOUND      = GBE_CHN_Error_Start + 18 //!<�Ҳ��������ļ�
	, GBE_CHN_INVALID_DATA_FORMAT      = GBE_CHN_Error_Start + 19 //!<�Ƿ������ݸ�ʽ
	, GBE_CHN_FAILED_TO_ALLOC_MEMORY   = GBE_CHN_Error_Start + 20 //!<�ڴ����ʧ��
	, GBE_CHN_MISS_DATA                = GBE_CHN_Error_Start + 21 //!<ȱ������
	, GBE_CHN_STROKE_LEN_MISMATCH      = GBE_CHN_Error_Start + 22 //!<����ıʻ��������ݵıʻ�����һ��
	, GBE_CHN_INVALID_SYLLLABLES_COUNT = GBE_CHN_Error_Start + 23	//!<���ڸ�������
	, GBE_CHN_SH_BUFFER_TO_SMALL       = GBE_CHN_Error_Start + 24 //!<����EBShDataInit��ʱ��, �������ĳ��Ȳ���
	, GBE_CHN_SH_CORRUPT_DATA          = GBE_CHN_Error_Start + 25 //!<��������������
	, GBE_CHN_SH_INVALID_ADDRESS       = GBE_CHN_Error_Start + 26 //!<��������ݵ�ͷ��ַ���ܱ�4����
	, GBE_CHN_SH_NOT_ENOUGH_SPACE      = GBE_CHN_Error_Start + 28	//!<����ʿռ䲻��
	, GBE_CHN_SH_NOT_INIT              = GBE_CHN_Error_Start + 30 //!<����ʺʹ����Ƶ����û�г�ʼ��
	, GBE_CHN_SH_INVALID_WORD          = GBE_CHN_Error_Start + 32 //!<����������а����Ƿ�����ĸ
	, GBE_CHN_SH_SPACE_NOT_ENOUGH      = GBE_CHN_Error_Start + 33 //!<�ռ䲻��
	, GBE_CHN_SH_DUPLICATE             = GBE_CHN_Error_Start + 34 //!<�����Ѿ�����һ����ȫ��ͬ�ĵ���
	, GBE_CHN_SH_PHRASE_INVALID_LENGTH = GBE_CHN_Error_Start + 35 //!<�����̫���ˣ�������10������
	, GBE_CHN_TO_INPUT_PHRASE          = GBE_CHN_Error_Start + 36 //!<��������

	, GBE_CHN_DIALECT_DATA_MISSMATCH	= GBE_CHN_Error_Start + 37 //�������������������ݲ�ƥ��
	, GBE_CHN_INVALID_SYLLABLE_TABLE	= GBE_CHN_Error_Start + 38	//�����ƴ�������ݣ���Ҫ��ƴ����ʽ����������ʹ��

	, GBE_CHN_ERR_CLOSE_PHRASE_FUNC		= GBE_CHN_Error_Start + 39 //!<���鹦���Ѿ��ر�, ��EBFindFirstPageC���淵�أ�
	, GBE_CHN_NEED_EXTRA_PACK4_DATA		= GBE_CHN_Error_Start + 40 //!<����Ľṹ���С��ǿ��4���������������еĽṹ���Сû��Pack��4������	
	, GBE_CHN_NEED_NO_EXTRA_PACK4_DATA	= GBE_CHN_Error_Start + 41 //!<����Ľṹ���С������ǿ��4���������������еĽṹ���С�Ѿ�Pack��4������		
	, GBE_CHN_INPUTSTRUCT_IS_NULL		= GBE_CHN_Error_Start + 42 //!<û���������潻�����ݣ�
	, GBE_CHN_F_NO_SPACE				= GBE_CHN_Error_Start + 100 ///<MDB���ܣ�RAM Buffer����
	, GBE_CHN_TOO_MANY_MDB_FILE			= GBE_CHN_Error_Start + 101 ///<MDB����������GB_MDB_MAX_COUNT

	//start[2010-10-20 zhj]
	, GBE_CHN_DUPLICATE_FILE	= GBE_CHN_Error_Start +102	///<ϸ���ʿ��ظ�
	, GBE_CHN_NO_FILE_DATA_BUFFER	= GBE_CHN_Error_Start +103	///<ϸ���ʿ�EBFileDataInitû�д��뻺������Ϣ������ʹ��GBFT_DATA_IN_FILE
	, GBE_CHN_CPU_TYPE_FAILED	= GBE_CHN_Error_Start +104	///<PC ���ݲ��ñ�ʹ�õ���PC ����
	, GBE_CHN_INDEX_MORE_MAX_MUL_PRON  = GBE_CHN_Error_Start +105	///<PC ���ڷ�����Ŵ��ڶ�һ�ָ���
	//end[2010-10-20 zhj]
	, GBE_CHN_TEST_IS_MAX_COUNT      = GBE_CHN_Error_Start + 1000 //!<���԰棬���Դ����Ѿ��������涨����
	, GBE_CHN_FAILED_TO_INIT			///<Chinese Module failed to initialize.
	, GBE_CHN_FAILED_TO_ATTACH_UDB		///<Chinese Module failed to attach UDB.

	, GBE_MMI_Error_Start = -0x3000		
	, GBE_MMI_NOT_INIT					///<invoke MMI function before Invoke GBMMIHandlerInit();
	, GBE_MMI_INITED                    ///< GBMMI�ѳ�ʼ��      
	, GBE_MMI_TOO_MANY_MULTITAP_KEY ///<��ǰ����ģʽ�����Ѿ�������̫���MultiTap����
	, GBE_MMI_INPUT_STRING_FULL			///<��ǰ����������
	, GBE_MMI_INVALID_CAND_LIST_TYPE	///<��ǰ��״̬�²���ʹ���������ģʽ
	, GBE_MMI_NO_SUCH_CAND				///<û�ж�Ӧ�ĺ�ѡ
	, GBE_MMI_ENGINE_STATUS_ERR			///<����״̬����
	, GBE_MMI_SWITCH_STACK_FULL			///<�л��Ķ�ջ����
	, GBE_MMI_INVALID_STACK_INDEX		///<������޷��л���ջ����
	, GBE_MMI_INVALID_EVENT				///<�Ƿ�����Ϣ����
	, GBE_MMI_INVALID_SEL_INDEX			///<��ѡѡ���±�����
	, GBE_MMI_INVALID_CAND_LIST			///<�趨�ĺ�ѡ��������Ч
	, GBE_MMI_UNSUPPORT					///<����û��GBMMIģ��
	, GBE_MMI_NOT_SWITCH_LANG_STATUS	///<��ǰ��û�д����޷��л�״̬��add by zhj
	//start[2010-7-28 zhj]
	, GBE_MMI_IGNORE_EVENT				///<��������ż������ó���������в��ܴ������������״̬,�������������¼�
	, GBE_MMI_WRONG_STATUS				///<GBMMI���ڴ����״̬
	, GBE_MMI_NOT_ASSOCIATE_STATUS_NO_ASSOCIATE_CANDIDATE	///<��������״̬�޷���ȡ�����ѡ
	//end[2010-7-28 zhj]
	, GBE_MMI_SYMBOL_KEY_ALREADY_CONSUMED		///<���Ű����Ѿ�������
	// Start add [2011-4-25 haj]
	,GBE_MMI_NOT_SET_QWERTY_MAP_ARRAY   ///>û������Qwerty����ӳ������
	,GBE_MMI_CONVERT_QWERTY_MAP_FAIL    ///>ת��Qwerty����ӳ��ʧ��
	// end [2011-4-25 haj]



	, GBE_API_Error_Start = -0x4000		
	, GBE_API_ALREADY_INIT				///<�Ѿ���ʼ��֮���ֵ���\ref GBInitialize�������\ref GBTerminate
	, GBE_API_MMI_BUFFER_NOT_ENOUGH		///<\ref tagGBInputStruct ::mmi_private_buffer�ռ䲻��
	, GBE_API_ENGINE_BUFFER_NOT_ENOUGH		///<\ref tagGBInputStruct ::engine_private_buffer�ռ䲻��
	//	, GBE_API_OUTPUT_INFO_IS_NULL		///<\ref tagGBInputStruct ::pOutputInfoΪ��
	, GBE_API_INVALID_PARAM				///<�����Ĳ������ٰ���һ����Ч����
	, GBE_API_GBIS_IS_NULL				///<�����Ĳ���pGBISΪNULL
	, GBE_API_MISS_LDB					///<��\ref GBSetCurLanguage�������棬�����ڶ�Ӧ���Ե�LDB
	, GBE_API_MISS_MAIN_LBD				///<��\ref GBSetCurLanguage�������棬����SubLangû�ж�Ӧ����������
	, GBE_API_ALP_DONT_SUPPORT_SUB_LANG ///<Alphabetic���治֧��Sub Language
	, GBE_API_UNSUPPORT_INPUT_MODE		///<��֧�ֵ�����ģʽ
	, GBE_API_UNSUPPORT_CHINESE			///<�˰汾��֧����������
	, GBE_API_INVALID_INPUT_MODE		///<��ǰ����������ģʽ��ƥ�䣬����Alphabetic״̬������ƴ������ģʽ
	, GBE_API_INVALID_KOREAN_INPUT_MODE ///<���ú�������ģʽ��ʱ�򣬲�ΪGBIM_Korean
	, GBE_API_INVALID_SYLLABLE_PO		///<Syllable��ѡ��ҳѡ����Ч
	, GBE_API_INVALID_CHN_PO			///<���ĺ�ѡ��ҳѡ����Ч
	, GBE_API_INVALID_ALP_PO			///<Alphabetic��ѡ��ҳѡ����Ч
	, GBE_API_INVALID_GET_STR_WIDTH_FP	///<\ref GBSetPageOption�����fpGetWStringWidth����ʹ���ַ�����ȡ��ȵ�ʱ�򷵻�0���߸�ֵ
	, GBE_API_SYLLABLE_NOT_EXISTS		///<��ǰ״̬����������
	, GBE_API_INVALID_SYLLABLE_INDEX	///<��ǰ�����±겻����Ч��Χ��
	, GBE_API_NOT_CHINESE				///<��ǰ�Ĺ������������ԵĹ��ܣ����ǵ�ǰ�����Բ�������
	, GBE_API_CAND_NOT_FOUND			///<��ѡû���ҵ�
	, GBE_API_LANG_DIDNOT_SUPPORT_API	///<��ǰ�����Բ�֧�ִ�API
	, GBE_API_UNSUPPORT_ALP				///<�˰汾��֧��Alphabetic����
	, GBE_API_AUX_INFO_IS_NULL			///<\ref tagGBInputStruct ::pAuxInfo Ϊ��
	, GBE_API_PREV_NOT_EXISTS			///<��������һҳ
	, GBE_API_NEXT_NOT_EXISTS			///<��������һҳ
	, GBE_API_GET_STRING_WIDTH_ERROR	///<��ȡ�ַ������Ⱥ������ظ�ֵ
	, GBE_API_FAILED_TO_GET_CAND		///<��ȡ��ѡʧ��
	, GBE_API_INVALID_ENGINE_STATUS		///<����״̬����ȷ
	, GBE_API_INVALID_CAND_INDEX		///<��ȡ��ǰ�ĺ�ѡ�±�ĺ�������ֵ����
	, GBE_API_NO_SUCH_CAND				///<û�ж�Ӧ�ĺ�ѡ
	, GBE_API_ALP_NOT_SUPPORT			///<Alphabetic��֧�ִ˹���
	, GBE_API_CHN_NOT_SUPPORT			///<���Ĳ�֧�ִ˹���
	, GBE_API_NEED_TO_CALL_FIRST_PAGE	///<����GBGetACand����֮ǰ����Ҫ���ȳɹ�����GBFirstPage
	, GBE_API_CHN_SELECT_FAILED			///<����EBHelperSelect����EBHelperSelectExʧ��
	, GBE_API_COMPONENTS_NOT_EXISTS		///<��ǰ״̬�����ڲ���
	, GBE_API_INVALID_LANGUAGE			///<��Ч������
	, GBE_API_NULL_FUNCTION_POINTER		///<�պ���ָ��
	, GBE_API_NO_PAGE_INVOLVE			///<û�е���GBGet***PageCandiate����
	, GBE_API_NO_MATCH_CAND				///<û���ҵ���Ӧ�ĺ�ѡ
	, GBE_API_INVALID_MDB				///<��Ч��MDB����
	, GBE_API_MDB_READ_AFTER_EOF		///<MDB���ܣ������λ���Ѿ������ļ���β
	, GBE_API_MDB_BUFFER_NOT_ENOUPH		///<\ref GBMDBInit������Ŀռ䲻����С����
	, GBE_API_MDB_INVALID_ID			///<MDB��ID��Ч
	, GBE_API_MDB_INVALID_READ_FP		///<GBMDBAttachFile�����ṩ��fpRead�ص�������Ч
	, GBE_API_To_Many_UDB				///<UDB�ĸ������������ƣ�seen function GBUDBAttach
	, GBE_API_INVALID_UDB_ID			///<��Ч��UDB ID
	, GBE_API_LANG_UDB_EXISTS			///<�����Ե�UDB�Ѿ�����
	, GBE_API_UNSUPPORT_LANGUAGE		///<��֧�ָ�����
	, GBE_API_INVALID_SYNATX_DATA		///<����������Ч
	, GBE_API_SYNTAX_SELECT_FAILED		///<��������GBSyntaxSelectCandidate2����ʧ��
	, GBE_API_SYNTAX_UDB_ATTACH_FAILED	///<GBSyntaxAttachUDBʧ��
	, GBE_API_UNSUPPORT_SYNTAX			///<��֧����������
	, GBE_API_TOO_MANY_MDB				///<MDB̫��
	, GBE_API_SYNTAX_CHANGE_INPUT_FAILED ///<GBSyntaxAttachUDBʧ��
	, GBE_API_INPUT_STRING_TO_LONG		///<���봮����̫��
	, GBE_API_NEED_FILE_MDB				///<��ҪGBMDBAttachFile��Ӧ��MDB
	, GBE_API_UPSCREEN_STRING_FULL		///<����Buffer����
	, GBE_API_UPSCREEN_STRING_POINT_NULL///����ָ��Ϊ��
	, GBE_API_NO_ENGINE					///<û���κ�һ��������Ч
	// start [2011-4-22 Zhaokun]
	//, GBE_API_WRONG_STRING_IN_WRONG_STATUS	///<��ǰ״̬��ʹ�õ�ǰ���봮��������Ч��add by zhj
	, GBE_API_INPUT_STRING_IS_NULL		///<���봮ΪNULL
	// end [2011-4-22 Zhaokun]
	, GBE_API_MDB_INVALID_SEEK_FP		///<GBMDBAttachFile�����ṩ��fpSeek�ص�������Ч
	, GBE_API_THIS_INPUT_MODE_NOT_TONE		///<��ǰ����ģʽû������

	//remove start[2010-7-28 zhj]
	//�ᵽ����ȥ������GBMMI�Ĵ��󣬲���GBAPI�Ĵ���
	////start[2010-4-12 zhj]
	//,GBE_API_IGNORE_EVENT				///<��������ż������ó���������в��ܴ������������״̬,�������������¼�
	////end[2010-4-12 zhj]
	//remove end[2010-7-28 zhj]
	// Start add [2011-6-16 haj]
	, GBE_API_VERIFY_WINGUO_FAILE		///<��֤Winguoʧ��	
	// end [2011-6-16 haj]
	, GBE_API_NOT_LOAD_CHN_DATA			///<û�м�����������
	, GBE_API_NO_INIT					///<û�г�ʼ��
	//start[2010-7-19 zhj]
	,GBE_KOREAN_Error_Start=-0x5000
	, GBE_KOREAN_FAILED                     = GBE_KOREAN_Error_Start + 1
	, GBE_KOREAN_INVALID_INDEX              = GBE_KOREAN_Error_Start + 100
	, GBE_KOREAN_NOTINIT					 = GBE_KOREAN_Error_Start + 2 //!<û�е���EBStartup()!
	, GBE_KOREAN_PEBIS_NULL				 = GBE_KOREAN_Error_Start + 3 //!<pEBISΪ��.
	, GBE_KOREAN_INVALID_INPUT_LEN          = GBE_KOREAN_Error_Start + 4 //

	, GBE_KOREAN_NO_MATCH                   = GBE_KOREAN_Error_Start + 8 //!<û�ҵ�ƥ�䴮
	, GBE_KOREAN_INVALID_INVOKE             = GBE_KOREAN_Error_Start + 9 //!<�Ƿ�����
	, GBE_KOREAN_NO_DATA_FILE               = GBE_KOREAN_Error_Start + 14
	, GBE_KOREAN_INVALID_DATA_FORMAT        = GBE_KOREAN_Error_Start + 15
	, GBE_KOREAN_INVALID_CHAR               = GBE_KOREAN_Error_Start + 19
	, GBE_KOREAN_WORD_TOO_LONG              = GBE_KOREAN_Error_Start + 20
	, GBE_KOREAN_NULL_WORD                  = GBE_KOREAN_Error_Start + 21
	, GBE_KOREANP_INVALID_VALIDCHAR          = GBE_KOREAN_Error_Start + 24 //!<�����е��ַ���������
	, GBE_KOREAN_DATA_MISMATCH              = GBE_KOREAN_Error_Start + 25 //!<����������汾��ƥ��
	//end[2010-7-19 zhj]

	// start add [2011-5-24 haj]
	, GBE_Mars_Error_Start = -0x6000
	// end add [2011-5-24 haj]
};

#define CHN_ENGINE_TO_API_ERR(err)		(GBE_CHN_Error_Start - (err))
#define ALP_ENGINE_TO_API_ERR(err)		(GBE_ALP_Error_Start - (err))
//start[2010-7-19 zhj]
#define KOREAN_ENGINE_TO_API_ERR(err)		(GBE_KOREAN_Error_Start - (err))
//end[2010-7-19 zhj]
// start add [2011-5-24 haj]
#define MARS_ENGINE_TO_API_ERR(err)		(GBE_Mars_Error_Start - (err))
// end  [2011-5-24 haj]

/** \brief ����ṹ���Flag (input) */
enum GBInputStructFlag
{
	GBIS_INPUT_STRING_UPDATED = (1 << 0)		///<���봮�Ѿ�����
	, GBIS_SYLLABLE_INDEX_UPDATED = (1 << 1)	///<�����Ѿ����£������ڲ�ʹ��
	, GBIS_SELECTED_CANDIDATE = (1 << 2)		///<ѡ���˺�ѡ
	//Change by ZhaoKun at 2011/1/12 9:29:54 [Start]
	, GBIS_SYLLABLE_TONE_UPDATED = (1 << 3)		///<����������
	//Change by ZhaoKun at 2011/1/12 9:29:54 [End]
};

/** \brief GBMMIRegisterMultiTapSymbols �����ܹ�������ö��ٸ�Key */
#define GB_MAX_MULTI_TAP_SYMBOLS	4

/** \brief ��ѡ������ */
enum GBCandListType
{
	GBCL_INVALID
	, GBCL_ROW_KEYBD			///<���еĺ�ѡ�����̣�, ������Chn��Alp
	, GBCL_ROW_TCH_SCR			///<���еĺ�ѡ����������, ������Chn��Alp
	, GBCL_SINGLE_CAND			///<������ѡ(��ѡ����ʾ)����������Alp
	, GBCL_ROW_MULTITAP			///<����ѡ���MultiTap��ѡ��������������, ֻ�����ڱ�����
	, GBCL_MULTITAP				///<MultiTap��ѡ(��ѡ����ʾ)��
	//start[2010-3-9 zhj]
	, GBCL_ROW_MULTITAP_WITH_TIMER	///������ʾmultitap��ѡ�ĺ�ѡ�򣬴���ʱ��			
	//end[2010-3-9 zhj]
};

/** \brief �������ú�ѡ������Enum */
enum GBCandStatusEnum 
{
	GBCS_INPUT						///<����״̬, ����������״̬, ���������, Alphabetic����ʵ�״̬
	, GBCS_ASSOCIATE				///<����״̬
};

/** \brief Alphabetic��ͨ�ĺ�ѡ�б� */
#define GBCL_ALP_NORMAL(cl)		((cl) == GBCL_ROW_KEYBD || (cl) == GBCL_ROW_TCH_SCR \
	|| (cl) == GBCL_SINGLE_CAND)
/** \brief ������ͨ�ĺ�ѡ�б�*/
#define GBCL_CHN_NORMAL(cl)		((cl) == GBCL_ROW_KEYBD || (cl) == GBCL_ROW_TCH_SCR)

/** \brief GBHRESULT����ֵ������ */
enum GBHandleResultEnum 
{
	GB_CONSUMED = 0				///<������Ѿ������洦���ⲿ���账��
	, GB_NOT_CONSUMED = GB_NOT_HANDLED				///<���������û�д�����Ҫ�ⲿ����
	//start[2010-4-12 zhj]
	,GB_IGNORE						///<���������û�д���Ҳ����Ҫ�ⲿ����
	//end[2010-4-12 zhj]
};
/*@}*/

/** \brief ���뷨״̬ */
enum GBInputModeStatusEnum
{
	GBIMS_INITIAL				///<��ʼ��
	, GBIMS_INPUT				///<����״̬
	, GBIMS_CHN_UAW				///<���������ѡ�������
	, GBIMS_ALP_UAW_NO_MORE_CAND///<û��������ѡ��ʱ���·�
	, GBIMS_ALP_UAW_BEGIN		///<Alphabetic��ʼ�����
	, GBIMS_ALP_UAW				///<Alphabetic����ʹ�����
	, GBIMS_ALP_UAW_Confirm		///<����ʽ������û�ȷ�ϼ��룬���״̬���Թر�
	, GBIMS_ASSOCIATE			///<����״̬�������Ӧ������û�����빦�ܣ�
	////���������֮���Զ���ΪGBIMS_INITIAL
	, GBIMS_SELECTED			///<ѡ���ѡ״̬
	//	, GBIMS_Interpunction		///<���������״̬
	, GBIMS_MULTITAP_INTERPUNCTION	///<MultiTap������ģʽ
	//	, GBIMS_Full_Scr_Symbol		///<ȫ��������״̬
	//start[2010-3-15 zhj]
	//���GBFO_Chn_All_Num_Can_Continuously_Input�����ĸĶ�
	, GBIMS_MULTITAP_INTERPUNCTION_BEGIN	///<׼����ʼ������ģʽ
	//end[2010-3-15 zhj]
	, GBIMS_STATUS_COUNT		///<���뷨״̬����
};

#ifndef __GB_CHN_TONE_ENUM__
#define __GB_CHN_TONE_ENUM__
enum GBChnToneEnum{
	GB_CHN_TONE_NULL = 0
	,GB_CHN_TONE_1 = 1	//����: 
	,GB_CHN_TONE_2		//����: 
	,GB_CHN_TONE_3		//����: 
	,GB_CHN_TONE_4		//����: 
	,GB_CHN_TONE_5		//����: ��
	,GB_CHN_TONE_6		//����: ��������
};
#endif

#endif
