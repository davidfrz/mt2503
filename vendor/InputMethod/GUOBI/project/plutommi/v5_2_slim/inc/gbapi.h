/***************************************************************************
 * \file        :  gbapi.h
 * Corporation  :  Guobi Technology Ltd. GuangZhou China
 * Copyright    :  Copyright Guobi Technology Ltd. And Subject to Confidentiality 
 *                 Restrictions. This document is the confidential and proprietary 
 *                 property of Guobi Technology Ltd.It is neither the document                  
 *                 itself nor any part of it can be shared with any party  without 
 *                 the written  permission. 
 * Author       :  chenbinghui
 * Date         :  2009��6��18
 * Purpose      :  v5 GB API �ⲿʹ��ͷ�ļ�����������API������
 * Version      :  V0.1
 * Last Changed List
 * Name  fanbo       |   date  2010-03-16 |  Discription �淶ע������
 ****************************************************************************/

#ifndef __GB_API_H__
#define __GB_API_H__

#include "gbdef.h"
#include "gbtype.h"
#include "gbim.h"

#ifndef GBAPI
#ifdef GBIMPORT
#define GBAPI  __declspec(dllimport)
#elif defined(Win32_DLL)
#define GBAPI  __declspec(dllexport)
#else
#define GBAPI	extern
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

	/*!
	 * \defgroup Initialization �����ʼ��
	 */
	/*@{*/
	
	/*! \example GBInputStructGetPrivateBufferUsedSize
	 */
	/*!
	 * \brief ���������pGBIS->engine_private_buffer����Ҫ�ĳ��ȣ�in byte��
	 * \return pGBIS->engine_private_buffer����Ҫ�ֽڳ���
	 * \note ע�⣺pGBIS->engine_private_bufferΪunsigned long���ͣ����ô����鳤��ʱӦ�ý��ֽڳ��ȳ���4
	 * \author chenbinghui
	 * \date 2009��11��19��
	 */
	GBAPI GBINT GBInputStructGetPrivateBufferUsedSize(void);
	
	/*! \example GBInitialize
	 */
	/*!
	 * \brief ����Guobi���뷨���棬�����ڵ��ù���API�ӿ�ǰ�����ã������н������һ��
	 * \param pGBIS (in)����ΪNULL���������е�engine_private_buffer�Լ�outputInfo�����������Ҫ�󽫷���ʧ��
	 * \param pLDBs (in)����ΪNULL����GBInitialize������ÿһ��LDBָ������ݵ������Ƿ���Ч
	 * \param nLDBCount (in)���ܳ���GB_LDB_MAX_COUNT��Ҳ����С�ڵ���0
	 * \return 
		- GBOK���ɹ���ʼ��
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_INVALID_PARAM����������
		- GBE_API_ALREADY_INIT���ظ���ʼ��
		- GBE_API_ENGINE_BUFFER_NOT_ENOUGH���ռ䲻��
	 * \note ����Ҫ�������뷨����һ�Σ����������й���APIʹ��ǰ������
	 * \author chenbinghui
	 * \date 2009��7��17��
	 */
	GBAPI GBRETURN GBInitialize(pGBInputStruct pGBIS, lpcGBLDB pLDBs, GBINT nLDBCount);

	/*! \example GBIsInited
	 */
	/*!
	 * \brief �����������Ƿ������ɹ�
	 * \param pGBIS (in)pGBInputStruct����
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBOK���Ѿ���ʼ��
		- GB_Failed��û�г�ʼ��
	 * \author chenbinghui
	 * \date 2009��7��17��
	 */
	GBAPI GBRETURN GBIsInited(pGBInputStruct pGBIS);

	/*! \example GBTerminate
	 */
	/*!
	 * \brief �رչ������뷨���档���ô˽ӿں���������������������棬����API�ӿڽ�������
	 * \param pGBIS (in)pGBInputStruct����
	 * \return 
		- GBOK���ɹ��ر�
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
	 * \note �رչ�������ʱ������ϸ���ʿ�(MDB)������ʿ�(UDB)�����Ƴ������������������±�����
	 * \author chenbinghui
	 * \date 2009��7��17��
	 */
	GBAPI GBRETURN GBTerminate(pGBInputStruct pGBIS);

	/*! \example GBReset
	 */
	/*!
	 * \brief ���ù������뷨�����ڲ�״̬��ж���޷��л���װ�����ָ�Ĭ�Ϻ�ѡ��ʽ
	 * \param pGBIS (in)pGBInputStruct����
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBOK���ɹ�����
	 * \note ����������API��ε�״̬����GBMMI���״̬��Ч
	 * \author chenbinghui
	 * \date 2009��7��17��
	 */
	GBAPI GBRETURN GBReset(pGBInputStruct pGBIS);

	/*! \example GBSetCurLanguage
	 */
	/*!
	 * \brief ���ù������뷨���浱ǰʹ������
	 * \param pGBIS (in)pGBInputStruct����
	 * \param nLangID (in)��Ҫ���õ����ԣ��������Ͳο�gbim.h�ļ���GBLanguageEnum����
	 * \param nSubLangID (in)��Ҫ���õ���������Ŀǰֻ��������Ҫ��������������������ο�gbim.h�ļ���GBSubLanguageEnum����
	 * \return
		- GBOK���ɹ����õ�ǰʹ������
		- other���ο�gbdef.h�ļ���GBReturnEnum����
	 * \note nSubLangIDĬ��ֵΪ0����ʾ����Ҫ������������
	 * \author chenbinghui
	 * \date 2009��7��17��
	 */
	GBAPI GBRETURN GBSetCurLanguage(pGBInputStruct pGBIS, GBINT nLangID, GBINT nSubLangID);

	/*! \example GBSetInputMode
	 */
	/*!
	 * \brief ���ù������뷨���浱ǰʹ�õ�����ģʽ,�����GBMMI�㣬��ͬ��GBMMI״̬
	 * \param pGBIS (in)pGBInputStruct����
	 * \param nInputMode (in)���õ�ǰ����ģʽ������ģʽ���Ͳο�gbim.h�ļ���GBInputModeEnum����
	 * \note ����MultiTap���뷨���뽫pGBIS->nCandType����Ϊ��ȷ�ķ�ʽ���ٵ��ô˺�������InputModeΪ��Ӧ�ļ�������ģʽ���磺
		  - ����NumPad������Сд���д�����뷨��ʽ 
		  - pGBIS->nCandType = GBCT_MultiTap_Lower_Cap;
		  - GBSetInputMode(pGBIS, GBIM_Predictive);
		  - �������˳�򲻶ԣ��ᵼ��GBMMI����ȷ
	 * \return
		 - GBOK��success
		 - GB_NO_LDB�������б���û�в����ڸ�nLangID������
		 - other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \author chenbinghui
	 * \date 2009��7��17��
	 */
	GBAPI GBRETURN GBSetInputMode(pGBInputStruct pGBIS, GBINT nInputMode);

	/*! \example GBMMISetInputMode
	 */
	/*!
	 * \brief ���ù������뷨���浱ǰʹ�õ�����ģʽ��
	 * \param pGBIS (in)pGBInputStruct����
	 * \param nInputMode (in)���õ�ǰ����ģʽ������ģʽ���Ͳο�gbim.h�ļ���GBInputModeEnum����
	 * \note ����ӿڽ���GBMMIʹ��
		  - ����MultiTap���뷨���뽫pGBIS->nCandType����Ϊ��ȷ�ķ�ʽ���ٵ��ô˺�������InputModeΪ��Ӧ�ļ�������ģʽ���磺
		  - ����NumPad������Сд���д�����뷨��ʽ 
		  - pGBIS->nCandType = GBCT_MultiTap_Lower_Cap;
		  - GBSetInputMode(pGBIS, GBIM_Predictive);
		  - �������˳�򲻶ԣ��ᵼ��GBMMI����ȷ
	 * \return
		 - GBOK��success
		 - GB_NO_LDB�������б���û�в����ڸ�nLangID������
		 - other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \author huanjin
	 * \date 2009��7��17��
	 */
	GBAPI GBRETURN GBMMISetInputMode(pGBInputStruct pGBIS, GBINT nInputMode);


	/*@}*/

	/*!
	 * \defgroup Configuration	API��������
	 */
	/*@{*/
	/*! \example GBSetCandidateMaxCount
	 */
	/*!
	 * \brief ���ù������뷨��������ѡ��
	 * \param pGBIS (in)pGBInputStruct����
	 * \param nCandidateMaxConut (in)������󷵻غ�ѡ������ָ������������ĺ�ѡ���������
	 * \note ����GBGetCandidatesCount()�����ص�ǰ����ʵ��ƥ���ѡ����Ĭ��Ϊ100��ָ��������ѡ�����ܴ��ں�ѡ��������������������쳣
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBOK���ɹ���������ѡ��
	 * \author chenbinghui
	 * \date 2009��7��17��
	 */
	GBAPI GBRETURN GBSetCandidateMaxCount(pGBInputStruct pGBIS, GBINT nCandidateMaxConut);

	/*! \example GBGetCandidateMaxCount
	 */
	/*!
	 * \brief ��ȡ�������뷨��������ѡ��
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pCandidateMaxConut (out)������󷵻غ�ѡ��
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_INVALID_PARAM��pCandidateMaxConutΪ��
		- GBOK���ɹ�����
	 * \note ����GBGetCandidatesCount()�����ص�ǰ����ʵ��ƥ���ѡ����Ĭ��Ϊ100
	 * \author chenbinghui
	 * \date 2009��7��17��
	*/
	GBAPI GBRETURN GBGetCandidateMaxCount(pGBInputStruct pGBIS, GBINT * pCandidateMaxConut);

	/*! \example GBSetLanguageSymbols
	 */
	/*!
	 * \brief ���ù������뷨���浱ǰ���Ա�����
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pOEMSymobls (in)OEM�Զ���ı����ţ�Ӧ��ָ��һ��ȫ����Ч�ĵ�ַ�������Ǿֲ���ַ
	 * \return 
	 	- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_LANG_DIDNOT_SUPPORT_API����ǰ���Բ�֧�ֵĺ���
		- EB_OK���ɹ����ñ�����
	 * \note pOEMSymobls��һ��ȫ�ֱ������б�ÿһ���ַ�Ϊһ�������ţ�������֮��û�зָ����
	 * \author chenbinghui
	 * \date 2009��7��17��
	 */
	GBAPI GBRETURN GBSetLanguageSymbols(pGBInputStruct pGBIS, GBLPCWCHAR pOEMSymobls);

	/*! \example GBSetPageOption
	 */
	/*!
	 * \brief ���ù������뷨�����ҳ������������ƴ��ע������ѡ��Alphabetic��ÿҳ���غ�ѡ��
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pOptions (in)�û��ķ�ҳ����
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_INVALID_GET_STR_WIDTH_FP���ַ�����Ȼ�ȡ��������
		- GBE_API_INVALID_ALP_PO��Alphabetic��ѡ��ҳѡ����Ч
		- GBE_API_INVALID_CHN_PO�����ĺ�ѡ��ҳѡ����Ч
		- GBOK���ɹ����÷�ҳ����
	 * \note Ĭ����������һҳ����6����ѡ��Alphabeticһҳ����1����ѡ��ƴ��ע���ȷ���2����ѡ�����ֻ��Ҫ�޸Ĳ������ã�������ʹ��GBGetPageOption��ȡ��ǰ������
	 * \author chenbinghui
	 * \date 2009��7��17��
	 */
	GBAPI GBRETURN GBSetPageOption(pGBInputStruct pGBIS, const GBGlobalPageOption * pOptions);

	/*! \example GBGetPageOption
	 */
	/*!
	 * \brief ��ȡ�������뷨���浱ǰ��ҳ����
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pOptions (out)��ǰ��ҳ����
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBOK��success
	 * \sa GBSetPageOption
	 * \author chenbinghui
	 * \date 2009��7��17��
	 */
	GBAPI GBRETURN GBGetPageOption(pGBInputStruct pGBIS, GBGlobalPageOption * pOptions);

	/*! \example GBSetMaxTotalPages
	 */
	/*!
	 * \brief ���ù������뷨��������ѡҳ��
	 * \param pGBIS (in)pGBInputStruct����
	 * \param nMaxPageCount (in)���ķ�ҳ����
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBOK���ɹ�����
	 * \note ����GBGetCandPageCount()�������ص����ֵ��Ĭ��Ϊ0����ʾ�������е�ҳ��������Ҫע����ǣ����������GBMMI�Ķ��к�ѡ���ܣ��������ʵ�ʷ��ص�����������
	 * \author chenbinghui
	 * \date 2009��7��17��
	 */
	GBAPI GBRETURN GBSetMaxTotalPages(pGBInputStruct pGBIS, GBINT nMaxPageCount);

	/*! \example GBGetMaxTotalPages
	 */
	/*!
	 * \brief ��ȡ�������뷨���浱ǰ����ѡҳ��
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pMaxPageCount (out)���ķ�ҳ����
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_INVALID_PARAM����������
		- GBOK���ɹ�����
	 * \note Ĭ��Ϊ0����ʾ�������е�ҳ������
	 * \author chenbinghui
	 * \date 2009��7��17��
	 */
	GBAPI GBRETURN GBGetMaxTotalPages(pGBInputStruct pGBIS, GBINT * pMaxPageCount);

	/*! \example GBSetCandidateMaxWordLength
	 */
	/*!
	 * \brief ���ù������뷨���浱ǰ���Ժ�ѡ�ʵ���󳤶�
	 * \param pGBIS (in)pGBInputStruct����
	 * \param nMaxWordLength (in)��ǰ���Ժ�ѡ����󳤶�
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_LANG_DIDNOT_SUPPORT_API����Ч�����ӿ�
		- GBOK���ɹ�����
	 * \note ���ĺ�ѡ����󳤶Ȳ�����10��Alphabetic����󳤶Ȳ��ᳬ��31���������ֵ�������ߴ�ʵ����Ϊ��Ч�����á�
	 * \author chenbinghui
	 * \date 2009��7��17��
	 */
	GBAPI GBRETURN GBSetCandidateMaxWordLength(pGBInputStruct pGBIS, GBINT nMaxWordLength);

	/*! \example GBSetInputString
	 */
	/*!
	 * \brief ֱ�������������봮����ȡ��Ӧ��ѡ
	 * \param pGBIS (in)pGBInputStruct���� 
	 * \param pInputString (in)���봮
	 * \return 
		- GBE_API_GBIS_IS_NULL: pGBISΪ��
		- GBE_API_INVALID_PARAM: ����һ����Ч����,����pInputStringΪ�գ���pInputString���봮����Ϊ0
		- GBE_API_INPUT_STRING_TO_LONG: ���봮�����Ѿ��ﵽ���ֵ
		- Othors: ��ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \author weizhiping
	 * \date 2010-6-21 11:45:23
	 */
	GBAPI GBRETURN GBSetInputString(pGBInputStruct pGBIS, GBLPCWCHAR pInputString);

	/*! \example GBHelperAddInputChar
	 */
	/*!
	 * \brief ���һ�������ַ�
	 * \param pGBIS (in) pGBInputStruct����
	 * \param chr (in) �����ַ�
	 * \return 
		- GBE_API_GBIS_IS_NULL: pGBISΪ��
		- GBE_API_INVALID_PARAM: chr��һ����Ч����
		- GBE_API_INPUT_STRING_TO_LONG: ���봮�����Ѿ��ﵽ���ֵ
		- GBOK: ����ַ��ɹ�
	 * \note 
	 * \sa GBNextPageCandidate
	 * \author huanjin
	 * \date 2010-7-21
	 */
	GBAPI GBRETURN GBHelperAddInputChar(pGBInputStruct pGBIS, GBWCHAR chr);

	/*! \example GBHelperAddInputString
	 */
	/*!
	 * \brief ׷�������ַ���
	 * \param pGBIS (in) pGBInputStruct����
	 * \param pInputString (in) ���봮
	 * \return 
		- GBE_API_GBIS_IS_NULL: pGBISΪ��
		- GBE_API_INVALID_PARAM: ����һ����Ч����,����pInputStringΪ�գ���pInputString���봮����Ϊ0
		- GBE_API_INPUT_STRING_TO_LONG: ���봮�����Ѿ��ﵽ���ֵ
		- GBOK: ���������ַ����ɹ�
	 * \note ��APIֻ���������ַ��������������Ҫ��ȡ�µĺ�ѡ����Ҫ����GBNextPageCandidate
	 * \sa GBNextPageCandidate
	 * \author huanjin
	 * \date 2010-7-21
	 */
	GBAPI GBRETURN GBHelperAddInputString(pGBInputStruct pGBIS, GBLPCWCHAR pInputString);

	/*! \example GBGetWordsSpellCorrection
	 */
	/*!
	 * \brief ͨ��ѡ��Ĵʻ�ȡ�ôʵľ������ݣ���ֻ֧��������
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pClickWords �û�����Ĵ�	 
	 * \param nMatchType ƥ�����ͣ��μ�enum GB_WORDS_SPELL_CORRECTION_MATCH_TYPE
	 * \note �˽ӿڴ���3������ֱ���©�����ఴ�ʹ�����Ե�����ʳ�ͷβ��ĸ��ľ���
	 *		����luk-luck��©������lucck-luck���ఴ����luek-luck������
	 *		nMatchType����Ϊ����������ϣ�0Ϊƥ��ȫ��
	 *		����������ȷ���Ժ����ʹ�ã�����Ӣ�ģ���ǰ������ʱ����Ҫ���л���Ӣ��
	 *		�ýӿڻ�ʹ��GBNextPageCandidate��ȡһҳ��ѡ
	 * \sa GBNextPageCandidate
	 * \return 
		- GBE_API_GBIS_IS_NULL������pGBISΪNULL
		- GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч����
		- GBE_API_LANG_DIDNOT_SUPPORT_API����ǰ�����Բ�֧�ִ�API
		- GBOK���ɹ�����
	 * \author Zhaokun
	 * \date 2012��3��28��
	 */
	GBAPI GBRETURN GBGetWordsSpellCorrection(pGBInputStruct pGBIS, GBLPCWCHAR pClickWords, GBUINT32 nMatchType);

	/*@}*/

	/*!
	 * \defgroup Chinese ����ר�ŵĺ���
	 */
	/*@{*/
	/*! \example GBGetAllSyllableCount
	 */
	/*!
	 * \brief ��ù������뷨����Ambiguous��������ģʽ������Ambiguousƴ����ע������ƴ�ȣ�����ƴ���ĸ�����
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pSyllableCount (out)��ǰ���ڸ���
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_INVALID_PARAM����������
		- GBE_API_SYLLABLE_NOT_EXISTS����ǰ״̬����������
		- GBE_API_UNSUPPORT_CHINESE���˰汾��֧����������
		- GBOK���ɹ���ȡ���ڸ���
	 * \note ������봮�Ѿ����£������GBUpdateSyllable����ƴ���б�֮���ٵ��ô˺������ƴ���ĸ���
	 * \author chenbinghui
	 * \date 2009��7��17��
	 */
	GBAPI GBRETURN GBGetAllSyllableCount(pGBInputStruct pGBIS, GBINT * pSyllableCount);

	/*! \example GBGetSyllable
	 */
	/*!
	 * \brief ��ȡ�������뷨���������б���ָ������������
	 * \param pGBIS (in)pGBInputStruct����
	 * \param nSyllableIndex (in)��Ҫ�������ڵ����������벻����GBGetAllSyllableCount���ص��������������ЧֵΪ��1-���ڸ�����
	 * \param pSyllable (out)�洢�������ڵĻ�����������ΪNULL
	 * \param nSyllableBufferLen (in)���ڻ���������
	 * \note �����ص�ǰ�����б���ָ���±��ĳһ������
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_SYLLABLE_NOT_EXISTS����ǰ״̬����������
		- GBE_API_INVALID_SYLLABLE_INDEX����ǰ�����±겻����Ч��Χ��
		- GBE_API_UNSUPPORT_CHINESE���˰汾��֧����������
		- GBOK���ɹ���ȡָ������������
	 * \author chenbinghui
	 * \date 2009��7��16��
	 */
	GBAPI GBRETURN GBGetSyllable(pGBInputStruct pGBIS, GBINT nSyllableIndex, GBWCHAR * pSyllable, GBINT nSyllableBufferLen);

	/*! \example GBSelectSyllable
	 */
	/*!
	 * \brief ѡ��������뷨���浱ǰָ�����������ڣ�Ҫ��ǰΪAmbiguous Chineseģʽ
	 * \param pGBIS (in)pGBInputStruct����
	 * \param nSyllableIndex (in)��ǰ��Ҫѡ�����ڵ�������0��ʾģ��ƥ�����е����ڣ�ĳһ������ЧֵΪ��1-���ڸ�����
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_SYLLABLE_NOT_EXISTS����ǰ״̬����������
		- GBOK���ɹ�����
		- other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \note ��Ҫ����GBUpdateOutputInfo����������Ϣ����̵���GBGetCandidate ����GBGetCandidateEx�Ȼ�ȡ��ѡ�ĺ������Ը��¶�Ӧ�ĺ�ѡ�б�
	 * \sa GBGetAllSyllableCount GBGetSyllables GBGetSyllable GBSelectSyllableEx GBSelectSyllable
	 * \author chenbinghui
	 * \date 2009��7��17��
	 */
	GBAPI GBRETURN GBSelectSyllable(pGBInputStruct pGBIS, GBINT nSyllableIndex);

	/*! \example GBSelectSyllableEx
	*/
	/*!
	 * \brief ѡ��������뷨���浱ǰָ�������ڣ�Ҫ��ǰΪAmbiguous Chineseģʽ
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pSyllable (in)��ǰָ���������ַ�����NULL��ʾ��ѡ���κ�ƴ������ǰ���봮��Ӧ���ڵĺ�ѡ������ʾ
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_SYLLABLE_NOT_EXISTS����ǰ״̬����������
		- GBE_API_UNSUPPORT_LANGUAGE���˰汾��֧����������
		- GBOK���ɹ�����
		- other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \note ��̵���GBGetCandidate����GBGetCandidateEx�Ȼ�ȡ��ѡ�ĺ������Ը��¶�Ӧ�ĺ�ѡ�б�
	 * \sa GBGetAllSyllableCount GBGetSyllables GBGetSyllable GBSelectSyllableEx GBSelectSyllable
	 * \author chenbinghui
	 * \date 2009��9��29��
	 */
	GBAPI GBRETURN GBSelectSyllableEx(pGBInputStruct pGBIS, GBLPCWCHAR pSyllable);

	/*! \example GBGetSyllables
	 */
	/*!
	 * \brief ��ȡ�������뷨����Ambiguous��������ģʽ������Ambiguousƴ����ע������ƴ�ȣ������ƴ���б�
	 * \param pGBIS (in)pGBInputStruct����
	 * \param nStartIndex (in)��ȡ���ڵĿ�ʼ�±꣬һ��Ĭ��Ϊ0
	 * \param ppSyllables (out)�����б��������洢���淵�ص������б�����ΪNULL
	 * \param nArrayLength (in)�����б������ĳ���
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_UNSUPPORT_CHINESE���˰汾��֧����������
		- GBE_API_SYLLABLE_NOT_EXISTS����ǰ״̬����������
		- GBE_API_INVALID_SYLLABLE_INDEX����ǰ�����±겻����Ч��Χ��
		- GBOK���ɹ�����
	 * \sa GBGetAllSyllableCount GBGetSyllables GBGetSyllable GBSelectSyllableEx GBSelectSyllable
	 * \author chenbinghui
	 * \date 2009��7��16��
	 */
	GBAPI GBRETURN GBGetSyllables(pGBInputStruct pGBIS, GBINT nStartIndex, GBWCHAR ** ppSyllables,GBINT nArrayLength);

	/*! \example GBUpdateSyllable
	 */
	/*!
	 * \brief ���¹������뷨��������ں�ѡ�����봮�ı�����
	 * \param pGBIS (in)pGBInputStruct����
	 * \return
	 	- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_SYLLABLE_NOT_EXISTS����ǰ״̬����������
		- GBE_API_UNSUPPORT_CHINESE���˰汾��֧����������
		- GBOK���ɹ�����
		- other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \note �û�����ͨ������;�����������ڵĺ�ѡ������GBUpdateSyllable֮�⣬
	 - ����GBGetCandidateҲ���Ը������ڵ��б�ÿһ���û����밴����ʱ�������Ȱѵ�ǰ���ڵ�ѡ���±�����Ϊ0��
	 - ������ܷ���GBE_CHN_INVALID_SYLLABLE_INDEX�����⣬GBUpdateSyllable������ѵ�ǰ�����±�����Ϊ0��
	 * \sa GBGetAllSyllableCount GBGetSyllables GBGetSyllable GBSelectSyllableEx GBSelectSyllable
	 * \author chenbinghui
	 * \date 2009��7��21��
	 */
	GBAPI GBRETURN GBUpdateSyllable(pGBInputStruct pGBIS);

	/*! \example GBGeSyllablePageCount
	*/
	/*!
	 * \brief �������ƥ������ڵ�ҳ��
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pPageCount (in/out)���ڵ�ҳ��
	 * \return
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_INVALID_PARAM�� �����Ĳ������ٰ���һ����Ч����
		- GBE_API_NOT_CHINESE����ǰ�Ĺ������������ԵĹ��ܣ����ǵ�ǰ�����Բ�������
		- GBOK���ɹ�����
		- other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \note 
	 * \sa GBGetAllSyllableCount GBGetSyllables GBGetSyllable GBSelectSyllableEx GBSelectSyllable
	 * \author zhonghuajin
	 * \date 2010��9��6��
	 */
	GBAPI GBRETURN GBGeSyllablePageCount(pGBInputStruct pGBIS,  GBINT * pPageCount);

	/*! \example GBGetCurrentSyllablePageIndex
	*/
	/*!
	 * \brief ���ص�ǰ����ҳ������
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pPageIndex (in/out)ҳ������
	 * \return
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_INVALID_PARAM�� �����Ĳ������ٰ���һ����Ч����
		- GBE_API_NOT_CHINESE����ǰ�Ĺ������������ԵĹ��ܣ����ǵ�ǰ�����Բ�������
		- GBOK���ɹ�����
		- other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \note ֻ����������ȡ����ѡ��ǰ���£�ʹ������ӿڲ�������
	 * \sa GBGetAllSyllableCount GBGetSyllables GBGetSyllable GBSelectSyllableEx GBSelectSyllable
	 * \author zhonghuajin
	 * \date 2010��9��6��
	 */
	GBAPI GBRETURN GBGetCurrentSyllablePageIndex(pGBInputStruct pGBIS, GBINT * pPageIndex);

	/*! \example GBSetFuzzy
	 */
	/*!
	 * \brief ���ù������뷨����ģ��ƴ���Ĺ���
	 * \param pGBIS (in)pGBInputStruct����
	 * \param config (in)��ѡ��һ�����߶�������ͨ����|�����Ӷ��������ɲο�GBChnConfigEnum
	 * \param on (in)1��ʾ������0��ʾ�ر�
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_NOT_CHINESE����ǰ�Ĺ������������ԵĹ��ܣ����ǵ�ǰ�����Բ�������
		- GBE_API_UNSUPPORT_CHINESE���˰汾��֧����������
		- GBOK���ɹ�����
	 * \note
		- GBCFG_PINYIN_FUZZY_H_F = 0x0008,	//ƴ����h��f��ģ��ƥ��(*)
		- GBCFG_PINYIN_FUZZY_N_L = 0x0010,	//ƴ����n��l��ģ��ƥ��(*)
		- GBCFG_PINYIN_FUZZY_NG_N = 0x0020,	//ƴ����ǰ�����ͺ������ģ��ƥ��(*)
		- GBCFG_PINYIN_FUZZY_XH_X = 0x0040,	//ƴ����ƽ�����ģ��ƥ��(*)
		- GBCFG_PINYIN_FUZZY_K_G = 0x0080,	//ƴ����k��g��ģ��ƥ��(*)
	 * \author chenbinghui
	 * \date 2009��7��21��
	 */
	GBAPI GBRETURN GBSetFuzzy(pGBInputStruct pGBIS, GBU32 config, GBINT on);

	/*! \example GBWord2CodesByInputmod
	 */
	/*!
	 * \brief ѡ��������뷨ģʽ����һ��������ת��Ϊ�������
	 * \param pGBIS (in)pGBInputStruct����
	 * \param nInputmod (in)��ǰ����ģʽ���磺GBIM_Pinyin,�ɲο�GBInputModeEnum
	 * \param isn (in)�����ֵ�Unicode����
	 * \param indexMulPron ָʾ���صڼ�������������,����ֻ���������뷨��Ч���������뷨ȱʡΪ0��
	 * \param pBuff (out)������������û���Ҫ��֤������������32���ֽڵĿռ�
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��	
		- GBE_API_UNSUPPORT_LANGUAGE����֧�ָ�����
		- EB_INPUTSTRUCT_IS_NULL��INPUTSTRUCTΪ��
		- EB_NOTINIT��û�е���EBStartup
		- EB_METHOD_INVALID�����뷨���ʹ���
		- GBOK����ʾ�ɹ���
	 * \note Ҫ��ǰΪAmbiguous Chineseģʽ
		- ��ע�����뷨��EB_INPUT_METHOD_BPMF��EB_INPUT_METHOD_EXP_BPMF������BufferӦ��Ϊunsigned short �����飬��������Ϊ6�������ΪUnicode ע���ַ��������������
		- �ڱʻ����뷨�����Ϊ1-5����������
		- ������뷨�����Ϊa-z����ĸ����
		- ƴ�����뷨���������뷨��Ϊa-z����ĸ���У������������
		- �������뷨�����Ϊ1-9����ĸ����
	 * \author lijingping
	 * \date 2009��9��28��
	 */
	GBAPI GBRETURN GBWord2CodesByInputmod(pGBInputStruct pGBIS, GBINT nInputmod, unsigned short isn,
											GBINT indexMulPron, GBPWCHAR pBuff);


	/*! \example GBTranslateInputStringToSyllable
	 */
	/*!
	 * \brief ��ȡ�������뷨����Ambiguousģʽ��������봮����ɶ�Ӧ��ƴ��\ע��\����
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pTranslateBuffer (out)������������洢���ص�ת�����������ΪNULL
	 * \param nBufferLen (in)�������������Ч����
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��	
		- GBE_API_UNSUPPORT_CHINESE���˰汾��֧����������
		- GBE_API_NOT_CHINESE����ǰ�Ĺ������������ԵĹ��ܣ����ǵ�ǰ�����Բ�������
		- EB_FAILED��ʧ��
		- EB_OK���ɹ�
	 * \author chenbinghui
	 * \date 2009��7��21��
	 */
	GBAPI GBRETURN GBTranslateInputStringToSyllable(pGBInputStruct pGBIS, 
		GBLPWCHAR pTranslateBuffer, 
		GBI32 nBufferLen);

	/*! \example GBChnGetAfterChar
	 */
	/*!
	 * \brief ������ǰ�������ƴ���ַ����ؿ��ܼ������������
	 * \param pGBIS (in)pGBInputStruct����
	 * \param nInputMode (in)��ǰ����ģʽ����ο�GBInputModeEnum
	 * \param pPreString (in)�Ѿ�������ַ���a-z����ע����ĸ����ϡ�
	 * \param pAfterChars (out)�������������ַ�����ƴ������zh�����ܳ��� a o u e i����ôpAfterChars����"aouei"
	 * \param nBufferLen (in)�����������Ч����
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��	
		- GBOK���ɹ�
		- GBE_API_NOT_CHINESE����ǰ�Ĺ������������ԵĹ��ܣ����ǵ�ǰ�����Բ�������
		- GBE_API_UNSUPPORT_CHINESE���˰汾��֧����������
	 * \note �˺���������Qwerty��ƴ����������Explicit��ע����
	 * \author chenbinghui
	 * \date 2009��7��21��
	 */
	GBAPI GBRETURN GBChnGetAfterChar(pGBInputStruct pGBIS, 
		GBINT nInputMode,
		GBLPCWCHAR pPreString, 
		GBLPWCHAR pAfterChars, 
		GBINT nBufferLen);

	/*! \example GBSetEngineOption
	 */
	/*!
	 * \brief ���ù������뷨���������
	 * \param pGBIS (in)pGBInputStruct����
	 * \param engine_id (in)��������ģ�飬��ο�gbdef.h�ļ���EngineIDEnum����
	 * \param config (in)����������뵱ǰ����ģ����أ���ο�gbdef.h�ļ���GBChnConfigEnum��GBChnCharset��GBAlp_Config��GBS_Config��GB_Function_Option��
	 * \param option (in)�������ò������뵱ǰ��������أ����ܵ�ֵ�����ǲ����͡��ַ��͡��ַ����͵ȣ���ϸ��ο����˵���ĵ�
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBOK���ɹ�
		- GBE_API_UNSUPPORT_CHINESE���˰汾��֧����������
		- GBE_API_UNSUPPORT_SYNTAX����֧����������
		- GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч����
	 * \note option����ǲ����ͣ�BOOL��������ʹ�û�|�������������������ϸ����档���������ԡ�����ģʽ������ɺ��ٵ��ã���������Ч�ĵ��ã�
	 * \author chenbinghui
	 * \date 2009��7��21��
	 */
	GBAPI GBRETURN GBSetEngineOption(pGBInputStruct pGBIS, GBINT engine_id, GBU32 config, GBU32 option);

	/*! \example GBGetEngineOption
	 */
	/*!
	 * \brief ��ȡ�������뷨����ָ�������������ֵ
	 * \param pGBIS (in)pGBInputStruct����
	 * \param engine_id (in)��������ģ�飬��ο�EngineIDEnum
	 * \param config (in)����������뵱ǰ����ģ����أ���ο�gbdef.h�ļ���GBChnConfigEnum��GBChnCharset��GBAlp_Config��GBS_Config��GB_Function_Option��
	 * \param option (out)��ȡ��ǰ����ѡ�������ֵ������ֵ����������ѡ�����������
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBOK���ɹ�����
		- GBE_API_UNSUPPORT_CHINESE���˰汾��֧����������
		- GBE_API_UNSUPPORT_SYNTAX����֧����������
		- GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч����
	 * \note ��Ҫ��ȷ��ǰ�������ֵ���ͣ����������BOOL�ͣ�����ֵΪ0���0ֵ����ο������ṩ����ϸ˵���ĵ�
	 * \author chenbinghui
	 * \date 2009��7��21��
	 */
	GBAPI GBRETURN GBGetEngineOption(pGBInputStruct pGBIS, GBINT engine_id, GBU32 config, GBU32 *option);

	enum GB_Syllable_Page_Enum {
		GBPS_CURRENT_PAGE,	///<��ǰҳ
		GBPS_PREV_PAGE,		///<��һҳ
		GBPS_NEXT_PAGE,		///<��һҳ
		GBPS_FIRST_PAGE		///<��һҳ
	};

	/*! \example GBGetPagedSyllable
	 */
	/*!
	 * \brief ��ȡ�������뷨����ָ��ҳ���ƴ����ѡ
	 * \param pGBIS (in)pGBInputStruct����
	 * \param nWhichPage (in)��Ҫ������һҳ��ƴ����ѡ����ο�GB_Syllable_Page_Enum
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_AUX_INFO_IS_NULL��tagGBInputStruct::pAuxInfo Ϊ��
		- GBE_API_PREV_NOT_EXISTS����������һҳ
		- GBE_API_NEXT_NOT_EXISTS����������һҳ
		- GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч����
		- GBOK���ɹ�����
		- GB_API_NOT_MORE_PAGE��û������ҳ�ĺ�ѡ
		- GBE_API_SYLLABLE_NOT_EXISTS����ǰ״̬����������
		- GBE_API_UNSUPPORT_CHINESE���˰汾��֧����������
	 * \note �������������ı�ƴ����ѡ������ĳһ��ƴ���������\ref GBSelectSyllable ��������ķ��ؽ����GBFO_Chn_Up_To_Input_Key_Sequence �����йأ��������������ã���ô���봮����Ϊ��һ��ƴ����ʾ��
	 * \author chenbinghui
	 * \date 2009��7��23��
	 */
	GBAPI GBRETURN GBGetPagedSyllable(pGBInputStruct pGBIS, GBINT nWhichPage);

	/*! \example GBChnGetComponents
	 */
	/*!
	 * \brief ��ȡ�������뷨���浱ǰ״̬�µĲ����б��������ݴ����pGBInputStruct�����pAuxInfo�ֶ���
	 * \param pGBIS (in)pGBInputStruct����
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBOK���ɹ�
		- GBE_API_AUX_INFO_IS_NULL��tagGBInputStruct::pAuxInfo Ϊ��
		- GBE_API_COMPONENTS_NOT_EXISTS����ǰ״̬�����ڲ���
		- GBE_API_UNSUPPORT_CHINESE���˰汾��֧����������
	 * \note pGBInputStruct�����pAuxInfo�ֶ���Ҫ��������������ǰָ�������û����ѷ���ռ䣬������Ϊ��ʱ������һ��Ϊ����Ϊȫ�ֱ�������ȡ�����б�Ҳ����ͨ������GBUpdateOutputInfo�������Զ����ز���ֵ
	 * \author chenbinghui
	 * \date 2009��7��25��
	 */
	GBAPI GBRETURN GBChnGetComponents(pGBInputStruct pGBIS);

   /*! \example GBSetAssocWord
    */
   /*!
	* \brief ���ù������뷨����������ַ���(Ŀǰֻ֧������)
	* \param pGBIS (in)pGBInputStruct����
	* \param pConfirmedWord (in)��ǰ�Ѿ��������ַ�
	* \param bReset (in)�ڵ��ô˺���ǰ���Ƿ����֮ǰ�������
	* \return 
		- GBE_API_LANG_DIDNOT_SUPPORT_API����ǰ�����Բ�֧�ִ�API
		- EB_OK���ɹ�����
		- GBE_API_UNSUPPORT_CHINESE���˰汾��֧����������
	* \note  ���GBSetAssocWord(pGBIS, L"��", GBTrue)֮�󣬵���GBSetAssocWord(pGBIS, L"��", GBFalse)�������ѡ����֡�������һ��������룬����������ƥ�ˡ���������GBSetAssocWord(pGBIS, L"��", GBTure)����ֻ�á��֡��������룬��ô����Ϳ����ǡ������ȡ�
	* \author chenbinghui
	* \date 2009��7��25��
	*/
	GBAPI GBRETURN GBSetAssocWord(pGBInputStruct pGBIS, GBLPCWCHAR pConfirmedWord, GBBOOL bReset);

	/*! \example GBGetAssocWord
	*/
	/*!
	 * \brief ��ȡ�����ַ���(Ŀǰֻ֧������)
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pConfirmedWord �Ѿ��������ַ�
	 * \param bReset �Ƿ�������ô˺���֮ǰ�������
	 * \note �˽ӿڶ�GBSetAssocWord�����˷�װ���������������״̬����������ѡ��[ϣ��ͨ��GBAPI�ӿ�ʵ�����빦������ô��½ӿ�]
	 * \return 
	 * \author weizhiping
	 * \date 2010��6��2��
	 */
	GBAPI GBRETURN GBGetAssocWord(pGBInputStruct pGBIS, GBLPCWCHAR pConfirmedWord, GBBOOL bReset);

	/*! \example GBSetSyllableTone
	*/
	/*!
	* \brief ��������
	* \param pGBIS (in)pGBInputStruct����
	* \param tone ��Чֵ:GB_CHN_TONE_NULL-GB_CHN_TONE_6
	* \note	
	* \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_NOT_CHINESE����ǰ�����Բ�������
		- GBE_API_UNSUPPORT_CHINESE���˰汾��֧����������
		- GBE_CHN_INVALID_TONE���Ƿ�������
	* \author Zhaokun
	* \date 2010��11��29��
	*/
	GBAPI GBRETURN GBSetSyllableTone(pGBInputStruct pGBIS, GBU8 tone);
	
	/*! \example GBSetQwertyBopomofoMap
	*/
	/*!
	* \brief ����ע��Qwerty���̵�ӳ��
	* \param pGBIS (in)pGBInputStruct����
	* \param pQwertyBopomofoMap (in)����ӳ��
	* \note	ӳ��ķ�ΧGBKEY_BPMF_B - GBKEY_BPMF_IU��0x3105 �� 0x3105 +36��
	* \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_NOT_CHINESE����ǰ�����Բ�������
		- GBE_API_UNSUPPORT_CHINESE���˰汾��֧����������
		- GBE_CHN_UNSUPPORT_INPUT_METHOD���Ƿ�������
	* \author Zhaokun
	* \date 2010��11��29��
	*/
	GBAPI GBRETURN GBSetQwertyBopomofoMap(pGBInputStruct pGBIS, GBLPCACHAR pQwertyBopomofoMap);

	/*@}*/

	/*!
	 * \defgroup Alphabetic Alphabeticר�ŵĺ���
	 */
	/*@{*/
	/*! \example GBGetDesireOutput
	 */
    /*!
	 * \brief ���������뷨���浱ǰ��ѡ���ַ�����Сд��ʽ�ı䣬����alphabetic������Ч
	 * \param pGBIS (in)pGBInputStruct����
	 * \param option (in)�û�ָ���������ĸ���ͣ���ο�GBAlpOutputOption
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_LANG_DIDNOT_SUPPORT_API����ǰ�����Բ�֧�ִ�API
		- GBE_API_ALP_NOT_SUPPORT��Alphabetic��֧�ִ˹���
		- GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч����
		- GBOK���ɹ�����
	 * \note ���øýӿ�֮ǰ����Ҫ���ȵ�����ӦAPI�ӿڻ�ȡ��ѡ������ýӿ��ȱ����ã�ʵ����Ϊ��Ч�ĵ���
	 * \author chenbinghui
	 * \date 2009��7��25��
	 */
	GBAPI GBRETURN GBGetDesireOutput(pGBInputStruct pGBIS, GBU32 option);

	/*! \example GBConvertChar
	 */
	/*!
	 * \brief ���������뷨����ĵ�ǰ��ѡ����ĸ��Сд��ʽ�ı䣬����alphabetic������Ч
	 * \param pGBIS (in)pGBInputStruct����
	 * \param chr (out)��ĸ���������
	 * \param nConvertOption (in)�û�ָ���������ĸ���ͣ���ο�GBAlpOutputOption
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч����
		- GBE_API_LANG_DIDNOT_SUPPORT_API����ǰ�����Բ�֧�ִ�API
		- GBE_API_ALP_NOT_SUPPORT��Alphabetic��֧�ִ˹���
		- GBOK���ɹ�����
	 * \note ���øýӿ�֮ǰ����Ҫ���ȵ�����ӦAPI�ӿڻ�ȡ��ѡ������ýӿ��ȱ����ã�ʵ����Ϊ��Ч�ĵ���
	 * \author chenbinghui
	 * \date 2009��7��25��
	 */
	GBAPI GBRETURN GBConvertChar(pGBInputStruct pGBIS, GBWCHAR * chr, GBI32 nConvertOption);

	/*! \example GBConvertString
	 */
	/*!
	 * \brief ���������뷨����ĵ�ǰ��ѡ���ַ�����Сд��ʽ�ı䣬����alphabetic������Ч
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pWString (out)�ַ������������
	 * \param nConvertOption (in)�û�ָ���������ĸ���ͣ���ο�GBAlpOutputOption
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч����
		- GBE_API_LANG_DIDNOT_SUPPORT_API����ǰ�����Բ�֧�ִ�API
		- GBE_API_ALP_NOT_SUPPORT��Alphabetic��֧�ִ˹���
		- GBOK���ɹ�����
	 * \note ���øýӿ�֮ǰ����Ҫ���ȵ�����ӦAPI�ӿڻ�ȡ��ѡ������ýӿ��ȱ����ã�ʵ����Ϊ��Ч�ĵ���
	 * \author chenbinghui
	 * \date 2009��7��25��
	 */
	GBAPI GBRETURN GBConvertString(pGBInputStruct pGBIS, GBWCHAR * pWString, GBINT nConvertOption);

	/*! \example GBConvertStringToNumPadKeySequence
	 */
	/*!
	 * \brief ���������뷨���浱ǰ�����ַ���ת��Ϊ��Ӧ�����ּ��̰������У�����alphabetic������Ч
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pWString (in)��ǰ����������ַ���
	 * \param pKeySequence (out)�������ּ��̰�������
	 * \param nBufferLen (in)��������С
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_LANG_DIDNOT_SUPPORT_API����ǰ�����Բ�֧�ִ�API
		- GBE_API_ALP_NOT_SUPPORT��Alphabetic��֧�ִ˹���
		- GBOK���ɹ�����
	 * \note 
	 * \author chenbinghui
	 * \date 2009��7��25��
	 */
	GBAPI GBRETURN GBConvertStringToNumPadKeySequence(pGBInputStruct pGBIS, 
		GBLPCWCHAR pWString, 
		GBLPWCHAR pKeySequence,
		GBINT nBufferLen);

	/*! \example GBTransform
	 */
	/*!
	 * \brief ���������뷨����Ĵ���ת��Ϊ��Ӧ����ʾģʽ
	 * \param languageID (in)��ǰ����ѡ�õ����ԣ���ο��ļ�gbim.h��GBLanguageEnum����
	 * \param words 
	 * \param forms 
	 * \param bufLen 
	 * \return 
	 * \note Ŀǰ֧��Խ�����ά����
			��Խ�������棬�˺��������Խ�����������ź���ĸ�ϲ�Ϊһ��Unicode����0x0041+ 0x0300 -> 0x00C0
	 		��ά��������棬�˺��������ά����������ĸ��Ϊ����Unicode���� 0xFBEA -> 0x0626 + 0x0627
	 		Ŀǰ֧��0xFBEA, 0xFBEE, 0xFBF9, 0xFBF2, 0xFBF0, 0xFBF4, 0xFBF6, 0xFBEC���ַ���
	 * \author chenbinghui
	 * \date 2009��7��25��
	 */
	GBAPI GBINT GBTransform(GBINT languageID,
					GBLPCWCHAR words,
					GBLPWCHAR forms,
					GBUINT bufLen);

	/*! \example GBTransformReverse
	 */
	/*!
	 * \brief \ref GBTransform�����������
	 * \param languageID
	 * \param forms
	 * \param words
	 * \param bufLen
	 * \return words����������ַ�����
	 * \note Ŀǰ֧��Խ�����ά����
	 ��Խ�������棬�˺��������Խ����ϲ��ַ��ֲ�Ϊ��ĸ+���꣬ ��0x00C0 -> 0x0041+ 0x0300
	 ��ά��������棬�˺��������ά����������ĸ�ϲ��� �� 0x0626 + 0x0627 -> 0xFBEA
	 Ŀǰ֧��0xFBEA, 0xFBEE, 0xFBF9, 0xFBF2, 0xFBF0, 0xFBF4, 0xFBF6, 0xFBEC���ַ���
	 * \author chenbinghui
	 * \date 2009��7��25��
	 */
	GBAPI GBINT GBTransformReverse(GBINT languageID,
		GBLPCWCHAR forms,
		GBLPWCHAR words,
		GBUINT bufLen);


	/*! \example GBSetShiftCap
	 */
	/*!
	 * \brief ���ù������뷨����Ŀ��Ƽ�״̬������alphabetic������Ч
	 * \param pGBIS (in)pGBInputStruct����
	 * \param bShiftDown (in)�Ƿ�Shift��������
	 * \param bCapsLockToggle (in)�Ƿ�CapsLock��������Ч״̬
	 * \return �ɹ�����GBOK���������زο�GBReturnEnum
	 * \note Shift��CapsLock��Ӱ��Alphabetic����������Shift��Ч��ʱ�򣬵���Ϊ����ĸ��д��
			CapsLock��Ч��ʱ�򣬵���Ϊ��д״̬�����CapsLock��Shiftͬʱ��Ч������Ϊ��д״̬
	 * \author chenbinghui
	 * \date 2009��9��10
	 */
	GBAPI GBRETURN GBSetShiftCap(pGBInputStruct pGBIS, GBINT bShiftDown, GBINT bCapsLockToggle);

	/*! \example GBAlpGetValidInputStr
	 */
	/*!
	 * \brief ��ȡ������ָ������ģʽ��ָ����ѡ�����µ���Ч��������
	 * \param pGBIS 
	 * \param nInputMethod (in������ģʽ�� �μ�GBInputModeEnum
	 * \param nCandType (in����ѡ���ͣ��μ�GBCandTypeEnum
	 * \param validStr (in/out����Ч��������
	 * \return 
		- GBE_API_GBIS_IS_NULL������pGBISΪNULL
		- GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч����
		- GBE_API_LANG_DIDNOT_SUPPORT_API����ǰ�����Բ�֧�ִ�API
		- GBOK���ɹ�����
		- other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \author Zhaokun
	 * \date 2011-03-04
	 */
	GBAPI GBRETURN GBAlpGetValidInputStr(pGBInputStruct pGBIS, GBUINT8 nInputMethod, GBUINT8 nCandType, GBLPCCHAR *validStr);

	/*! \example GBAlpGetValidInputStr
	 */
	/*!
	 * \brief ��ȡ�ɶ�����Ϊһ��������ĸ�ַ���
	 * \param pGBIS 
	 * \param ppPreferenceChars (out)�ɶ�����Ϊһ��������ĸ�ַ���
	 * \note
	 * \return 
	 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
	 - GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч����
	 - GBE_API_LANG_DIDNOT_SUPPORT_API����ǰ�����Բ�֧�ִ�API
	 - GBOK���ɹ�����
	 - other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \author haj
	 * \date 2011-9-16
	 */
	GBAPI GBRETURN GBAlpGetPreferenceChars(pGBInputStruct pGBIS, GBLPCCHAR * ppPreferenceChars);

	/*@}*/


	/*!
	* \defgroup Candidate ��ȡ��ѡ��API
	*/
	/*@{*/

	/*! \example GBHaveNextPage
	 */
	/*!
	 * \brief �жϹ������뷨�����Ƿ�����һҳ��ѡ
	 * \param pGBIS (in)pGBInputStruct����
	 * \return 
		- GBOK������һҳ��ѡ
		- GB_Failed��û����һҳ��ѡ
	 * \note �Ƿ�����һҳҲ����ͨ����GBIS_HaveNextPage�ж�
	 * \author chenbinghui
	 * \date 2009��9��10
	 */
	GBAPI GBRETURN GBHaveNextPage(pGBInputStruct pGBIS);

	/*! \example GBHavePrevPage
	 */
	/*!
	 * \brief �жϹ������뷨�����Ƿ�����һҳ��ѡ
	 * \param pGBIS (in)pGBInputStruct����
	 * \return 
		 - GBOK������һҳ��ѡ
		 - GB_Failed��û����һҳ��ѡ
	 * \note �Ƿ�����һҳҲ����ͨ����GBIS_HavePrevPage�ж�
	 * \author chenbinghui
	 * \date 2009��9��10
	 */
	GBAPI GBRETURN GBHavePrevPage(pGBInputStruct pGBIS);

	/*! \example GBNextPageCandidate
	 */
	/*!
	 * \brief ��ȡ�������뷨����ĺ�ѡ��ʹ�ø�API����������pGBInputStruct�����outputInfo�ֶεĺ�ѡ�б�
	 * \param pGBIS (in)pGBInputStruct����
	 * \param nStartIndex (in)ָ����ѡ���Ŀ�ʼλ�ã�����ѡ��䵽outputInfo�ֶεĺ�ѡ�б���
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_NEED_TO_CALL_FIRST_PAGE������GBGetACand����֮ǰ����Ҫ���ȳɹ�����GBFirstPage
		- GBE_API_PREV_NOT_EXISTS����������һҳ
		- GBE_API_INPUT_STRING_TO_LONG�����봮����̫��
		- GBOK���ɹ�����
		- GBE_API_NULL_FUNCTION_POINTER���պ���ָ��
		- other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \note ��õ�һҳ��ѡ��ʱ������nStartIndexΪ0�������һҳ�Ŀ�ʼλ��ΪnStartIndex = pGBIS->outputInfo.nCandNum + pGBIS->outputInfo.nFirstCandIndex
	 * \author chenbinghui
	 * \date 2009��9��10
	 */
	GBAPI GBRETURN GBNextPageCandidate(pGBInputStruct pGBIS, GBINT nStartIndex);

   /*! \example GBNextPageCandidateEx	
    */
   /*!
	* \brief ��ȡ�������뷨����ĺ�ѡ��ʹ�ø�API����������pGBInputStruct�����outputInfo�ֶεĺ�ѡ�б�
	* \param pGBIS (in)pGBInputStruct����
	* \param nStartIndex (in)ָ����ѡ���Ŀ�ʼλ�ã�����ѡ��䵽outputInfo�ֶεĺ�ѡ�б���
	* \param bAppendToCandList �Ƿ������еĺ�ѡ�������
	* \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_NEED_TO_CALL_FIRST_PAGE������GBGetACand����֮ǰ����Ҫ���ȳɹ�����GBFirstPage
		- GBE_API_PREV_NOT_EXISTS����������һҳ
		- GBE_API_INPUT_STRING_TO_LONG�����봮����̫��
		- GBOK���ɹ�����
		- GBE_API_NULL_FUNCTION_POINTER���պ���ָ��
		- other���ο�gbdef.h�ļ��е�GBReturnEnum����
	* \note ��õ�һҳ��ѡ��ʱ������nStartIndexΪ0�������һҳ�Ŀ�ʼλ��ΪnStartIndex = pGBIS->outputInfo.nCandNum + pGBIS->outputInfo.nFirstCandIndex
	* \author chenbinghui
	* \date 2009��9��10
	*/
	GBAPI GBRETURN GBNextPageCandidateEx(pGBInputStruct pGBIS, 
		GBINT nStartIndex, 
		GBINT bAppendToCandList);

	/*! \example GBPrevPageCandidate
	 */
	/*!
	 * \brief  ��ȡ�������뷨�������һҳ��ѡ��ʹ�ø�API����������pGBInputStruct�����outputInfo�ֶεĺ�ѡ�б�
	 * \param pGBIS (in)pGBInputStruct����
	 * \param nStartIndex (in)ָ��ĺ�ѡΪ��ú�ѡ�����һ����ѡ
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_NEED_TO_CALL_FIRST_PAGE����Ҫ���ȵ���GBFirstPage
		- GBE_API_PREV_NOT_EXISTS����������һҳ
		- GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч����
		- GBOK���ɹ�����
		- other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \note �������������һҳ������nStartIndex = pGBIS->outputInfo.nFirstCandIndex - 1
	 * \author chenbinghui
	 * \date 2009��9��10
	 */
	GBAPI GBRETURN GBPrevPageCandidate(pGBInputStruct pGBIS, GBINT nStartIndex);

	/*! \example GBCurPageCandidateEx
	 */
	/*!
	* \brief ���ݵ�ǰ�ķ�ҳ����, ��nStartCandIndex��ʼ����õ�ǰҳ�ĺ�ѡ��
	* \param pGBIS (in)pGBInputStruct����
	* \param nStartIndex (in)
	* - ��õ�һҳ��ѡ��ʱ��, nStartIndex Ϊ 0;
	* - �����һҳ�Ŀ�ʼλ��ΪnStartIndex = pGBIS->outputInfo.nFirstCandIndex
	* \param bAppendToCandList (in)�Ƿ������еĺ�ѡ�������
	* \note  ��ѡ����Ϣ�����outputInfo�ֶ���
	* \author fanbo
	* \date 2010-03-05
	*/
	GBAPI GBRETURN GBCurPageCandidateEx(pGBInputStruct pGBIS, 
		GBINT nStartIndex, 
		GBINT bAppendToCandList);

	/*! \example GBCurPageCandidate
	 */
	/*!
	* \brief ���ݵ�ǰ�ķ�ҳ��������õ�ǰҳ�ĺ�ѡ�������·�ҳ��û�к�ѡ�����ط�ҳʱ�����ô˺���
	* \param pGBIS (in)pGBInputStruct����
	* \param nStartIndex (in)ָ��ĺ�ѡΪ��ú�ѡ�����һ����ѡ��һ����˵��nStartIndex = pGBIS->outputInfo.nCandStartIndex; ��ѡ����Ϣ�����pGBIS->outputInfo
	* \note 
	* \author fanbo
	* \date 2010-03-05
	*/
	GBAPI GBRETURN GBCurPageCandidate(pGBInputStruct pGBIS, 
		GBINT nStartIndex);

	/*! \example GBSelectCandidate
	 */
	/*!
	 * \brief ѡ��������뷨�����һ����ѡ��һ��������ʹ�����ʹ��
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pCand (in)�û�ѡ����ַ���
	 * \return 
	 - GBE_API_GBIS_IS_NULL��pGBISΪ��
	 - GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч����
	 - GBE_API_INVALID_LANGUAGE����Ч������
	 - GBOK���ɹ�����
	 - other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \note ������״̬���ж��û��Ƿ��������״̬������������״̬���û����컹û����ɵĻ���
	 - ����GBR_UAW_CONTINUE�������ͬʱ����pGBInputStruct����ĺ�ѡ��
	 - ���������״̬�£�������ɣ�������Զ�����GBUDBAddPhrase�������������ͬʱ���޸�pGBInputStruct�����outputInfo�����pUpScreenStr��
	 - ������ֱ��ѡ��������������������֮�󣬻����ǰ�������������������ҵ���GBAddUsedWord�������е�Ƶ��
	 - ��Alphabetic״̬���棬GBSelectCandidate�����GBAddUsedWord�������е�Ƶ
	 * \author chenbinghui
	 * \date 2009��9��10
	 */
	GBAPI GBRETURN GBSelectCandidate(pGBInputStruct pGBIS, GBLPCWCHAR pCand);

	/*! \example GBSelectCandidateEx
	 */
	/*!
	* \brief ѡ��������뷨�����һ����ѡ��һ��������ʹ�����ʹ��
	* \param pGBIS (in)pGBInputStruct����
	* \param pCand (in)�û�ѡ����ַ���
	* \param nInputLen (in)��ѡ��Ӧ�����볤�ȣ�0��ʾ�������봮
	* \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч����
		- GBE_API_INVALID_LANGUAGE����Ч������
		- GBOK���ɹ�����
		- other���ο�gbdef.h�ļ��е�GBReturnEnum����
	* \note ������״̬���ж��û��Ƿ��������״̬������������״̬���û����컹û����ɵĻ���
	- ����GBR_UAW_CONTINUE�������ͬʱ����pGBInputStruct����ĺ�ѡ��
	- ���������״̬�£�������ɣ�������Զ�����GBUDBAddPhrase�������������ͬʱ���޸�pGBInputStruct�����outputInfo�����pUpScreenStr��
	- ������ֱ��ѡ��������������������֮�󣬻����ǰ�������������������ҵ���GBAddUsedWord�������е�Ƶ��
	- ��Alphabetic״̬���棬GBSelectCandidate�����GBAddUsedWord�������е�Ƶ
	* \author chenbinghui
	* \date 2009��9��10
	*/
	GBAPI GBRETURN GBSelectCandidateEx(pGBInputStruct pGBIS, GBLPCWCHAR pCand, GBINT nInputLen);

	/*! \example GBCancelSelectCandidate
	 */
	/*!
	 * \brief ȡ����ǰ�û�ѡ�񣬽�����������ʹ�����ʹ�á�
	 * \param pGBIS (in)pGBInputStruct����
	 * \return
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_INVALID_LANGUAGE����Ч������
		- GBOK���ɹ�����
		- other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \note ����һ��GBSelectCandidate�ķ���GB_UAW_CONTINUE֮�󣬿��Ե���GBCancelSelectCandidate��ȡ��ѡ��
	 * \author chenbinghui
	 * \date 2009��9��10
	 */
	GBAPI GBRETURN GBCancelSelectCandidate(pGBInputStruct pGBIS);

	/*! \example GBSetCandBuffer
	 */
	/*!
	 * \brief ���ù������뷨�����Զ���ĺ�ѡ�����������û������ռ�Ϊ128��WCHAR
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pBuffer (in)�û�ָ���ĺ�ѡ�������ռ�
	 * \param nBufferLen (in)�û�ָ���ĺ�ѡ��������С
	 * \return
		 - GBE_API_GBIS_IS_NULL��pGBISΪ��
		 - GBE_API_INVALID_LANGUAGE����Ч������
		 - GBOK���ɹ�����
		 - other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \note 
	 * \author chenbinghui
	 * \date 2009��7��22��
	 */
	GBAPI GBRETURN GBSetCandBuffer(pGBInputStruct pGBIS, GBWCHAR * pBuffer, GBI32 nBufferLen);

	/*! \example GBGetCandBufferLen
	 */
	/*!
	 * \brief ��ȡ�������뷨�����ѡ�������Ĵ�С�����㵥λΪWCHAR
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pBufferLen (out)���ػ������Ĵ�С
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBOK���ɹ�����
		- GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч���� 
	 * \note 
	 * \author chenbinghui
	 * \date 2009��7��22��
	 */
	GBAPI GBRETURN GBGetCandBufferLen(pGBInputStruct pGBIS, GBI32 * pBufferLen);

	/*! \example GBGetCandidate
	*/
	/*!
	* \brief ��ȡ�������뷨����ĺ�ѡ���˺���ʹ��GBSetCandBuffer���õ�Buffer����ź�ѡ����õĺ�ѡ������pGBInputStruct����outputInfo�ֶεĺ�ѡ�б����档
	- ���û�е���GBSetCandBuffer����ô����ʹ��128��WCHAR��Buffer����ź�ѡ���ݡ�
	* \param pGBIS (in)pGBInputStruct����
	* \param nStartIndex (in)��ѡ�Ŀ�ʼλ��
	* \param nWantCount (in)��Ҫ�õ��ĺ�ѡ����
	* \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч���� 
		- GBOK���ɹ�����
		- other���ο�gbdef.h�ļ��е�GBReturnEnum����
	* \note ���صĺ�ѡ��������pGBInputStruct����outputInfo�ֶε�nCandNum�У�ͬʱ����pGBInputStruct����outputInfo�ֶ�nFirstCandIndexֵ��
	- GBCT_Associate��GBV5��������ֻ֧�����ģ��˺�������ܵõ�32����ѡ��Ҫ��õ�����ĺ�ѡ������GBGetCandidateEx
	* \author chenbinghui
	* \date 2009��7��22��
	*/
	GBAPI GBRETURN GBGetCandidate(pGBInputStruct pGBIS, GBINT nStartIndex, GBINT nWantCount);

	/*! \example GBGetCandidateEx
	 */
	/*!
	 * \brief ��ȡ�������뷨����ĺ�ѡ���˺���ʹ��GBSetCandBuffer���õ�Buffer����ź�ѡ����õĺ�ѡ������pGBInputStruct����outputInfo�ֶεĺ�ѡ�б����档
	 - ���û�е���GBSetCandBuffer����ô����ʹ��128��WCHAR��Buffer����ź�ѡ���ݡ�
	 * \param pGBIS (in)pGBInputStruct����
	 * \param nStartIndex (in)��ѡ�Ŀ�ʼλ��
	 * \param pBuffer (out)��ѡ�Ĵ�ŵ�Buffer��ÿ������ѡ֮��ʹ��\0�ָ���������������󣬿��ܻ����Ʒ��غ�ѡ�ĸ������û�Ӧ��ʹ��pCandArray����������õ�������ѡ��ָ�룬������������顣
	 * \param nBufferLen (in)Buffer����Ч����
	 * \param pCandInfos (out)���ظ�����ѡ��Ӧ���봮���ȣ�������ʱ��ʹ�ã� ����Ҫ��֤������nWantCandCount��Ԫ�ء�
	 * \param pCandArray (out)���ظ�����ѡ��ָ�룬pCandArray����Ҫ��֤������nWantCandCount��Ԫ�ء�
	 * \param nWantCandCount (in)�û���Ҫ�ĺ�ѡ���������pBuffer�ռ䲻�����ߺ�ѡ���㣬���صĺ�ѡ��������Ҫ�����ֵ�١�
	 * \return 
		 - GBE_API_GBIS_IS_NULL��pGBISΪ��
		 - GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч���� 
		 - GBOK���ɹ�����
		 - GBE_API_INPUT_STRING_TO_LONG�����봮����̫��
		 - GBE_API_INVALID_LANGUAGE����Ч������
		 - other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \note ʵ�ʷ��صĺ�ѡ��������pGBInputStruct����outputInfo�ֶε�nCandNum��
	 * \author chenbinghui
	 * \date 2009��7��22��
	 */
	GBAPI GBRETURN GBGetCandidateEx(pGBInputStruct pGBIS, 
		GBINT nStartIndex, 
		GBWCHAR * pBuffer, 
		GBI32 nBufferLen,
		GBU8 * pCandInfos, 
		GBWCHAR * * pCandArray,
		GBI32 nWantCandCount);

	/*! \example GBGetCandidatesCount
	 */
	/*!
	 * \brief ��ù������뷨��������ƥ��ĺ�ѡ�ĸ�����Ĭ�����ֵΪ100������ͨ��GBSetCandidateMaxCount�޸Ĵ�Ĭ��ֵ��
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pCandidateCount (out)ʵ�ʷ��صĺ�ѡ��
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч���� 
		- GBOK���ɹ�����
		- other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \note 
	 * \author chenbinghui
	 * \date 2009��7��22��
	 */
	GBAPI GBRETURN GBGetCandidatesCount(pGBInputStruct pGBIS, GBINT * pCandidateCount);

	/*! \example GBGetCandidatePageCount
	 */
	/*!
	 * \brief ��ù������뷨��������ƥ��ĺ�ѡ��ҳ������ҳ��Ϣ����ͨ��GBSetPageOption�������ã�Ĭ������һҳ6����ѡ��Alphabeticһҳ1����ѡ��
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pPageCount (out)ʵ�ʷ��صĺ�ѡҳ��
	 * \return 
		 - GBE_API_GBIS_IS_NULL��pGBISΪ��
		 - GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч���� 
		 - GBOK���ɹ�����
		 - other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \author chenbinghui
	 * \date 2009��7��22��
	 */
	GBAPI GBRETURN GBGetCandidatePageCount(pGBInputStruct pGBIS, GBINT * pPageCount);

	/*! \example GBGetCurrentCandidatePageIndex
	 */
	/*!
	 * \brief ���ع������뷨���浱ǰҳ�±ꡣ����GBGetCurrentCandidatePageIndex֮ǰ������ú�ѡ��ҳ����������ȷ���ص�ǰ��ҳ�±ꡣ���򣬷���-1��
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pPageIndex (out)ʵ�ʷ��ص�ҳ�±�
	 * \return 
		- GBE_API_GBIS_IS_NULL��pGBISΪ��
		- GBE_API_NO_PAGE_INVOLVE��û�е���GBGet***PageCandiate����
		- GBOK���ɹ�����
	 * \note ���ʹ����GBMMI�Ķ��к�ѡ���ܣ������������ÿһҳ�����һ�������к�ѡ���е��±꣬���ÿһҳ��Ҫ3�к�ѡ�������ڶ�ҳ��ʱ�������������5��
	 * \author chenbinghui
	 * \date 2009��7��22��
	 */
	GBAPI GBRETURN GBGetCurrentCandidatePageIndex(pGBInputStruct pGBIS, GBINT * pPageIndex);
	
   /*! \example GBUpscreenChar
	*/
   /*!
	* \brief ���������뷨�����һ����ѡ�ַ�������Ӱ��pGBInputStruct����outputInfo�ֶ�pUpScreenStrֵ
	* \param pGBIS (in)pGBInputStruct����
	* \param cCand (in)��Ҫ�������ַ�
	* \return
		- GBOK���ɹ�����
		- other���ο�gbdef.h�ļ��е�GBReturnEnum����
	* \note һ����GBMMI�ڲ�ʹ��
	* \author chenbinghui
	* \date 2009��12��2
	*/
    GBAPI GBRETURN  GBUpscreenChar(pGBInputStruct pGBIS, GBINT cCand);

	/*! \example GBTransFormat
	*/
	/*!
	 * \brief ���ݵ�ǰ��SHIFT CAPLOCK��־ת����ѡ��ʽ(����Alp������Ч)
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pCand (in & out)��Ҫת����ת��������ĺ�ѡ
	 * \return 
	 * \note ����Alp������Ч
	 * \author �ӻ���
	 * \date 2010-4-27
	 */
	GBAPI GBRETURN GBTransFormat(pGBInputStruct pGBIS, GBLPWCHAR pCand);

	/*! \example GBUpscreenString
	 */
	/*!
	 * \brief ���������뷨�����һ����ѡ�ַ���������Ӱ��pGBInputStruct����outputInfo�ֶ�pUpScreenStrֵ
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pCand (in)��Ҫ�������ַ���
	 * \return 
		- GBE_API_UPSCREEN_STRING_POINT_NULL������ָ��Ϊ��
		- GBOK���ɹ�����
		- GBE_API_UPSCREEN_STRING_FULL������Buffer����
	 * \note һ����GBMMI�ڲ�ʹ��
	 * \author chenbinghui
	 * \date 2009��12��2
	*/
	GBAPI GBRETURN GBUpscreenString(pGBInputStruct pGBIS, GBLPCWCHAR pCand);

	
	/*! \example GBAlpGetEmbeddedInterpunctionKey
	 */
	/*!
	 * \brief ��ȡ�������뷨������Ƕ�����Ű�����ֵ
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pEmbeddedInterpunctionKey (out)��Ƕ�����ż�ֵ 
	 * \return 
		 - GBIngore�����ԣ�������
		 - GBOK���ɹ�����
	 * \note ���õ���Ƕ��ֵΪ0��1
	 * \author chenbinghui
	 * \date 2009��12��2
	 */
	GBAPI GBRETURN GBAlpGetEmbeddedInterpunctionKey(pGBInputStruct pGBIS,GBCHAR *pEmbeddedInterpunctionKey);

	/*! \example GBChnControlChar
	 */
	/*!
	 * \brief  ��ȡ�������뷨�������ĵĴ���ָ����Լ�ͨ���
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pPhraseInput (out)���Ĵ���ָ���
	 * \param pWildCard (out)����ͨ���
	 * \return 
		- GBOK���ɹ�����
	 * \author chenbinghui
	 * \date 2009��12��2
	 */
	GBAPI GBRETURN GBChnControlChar(pGBInputStruct pGBIS,GBWCHAR * pPhraseInput,GBWCHAR * pWildCard);

	/*! \example GBInputResetNoHook
	 */
	/*!
	 * \brief �ָ��������뷨����ΪĬ��״̬��ж���޷��л���װ��
	 * \param pGBIS (in)pGBInputStruct����
	 * \return 
		- GBE_API_GBIS_IS_NULL������pGBISΪNULL
		- GBOK���ɹ�����
	 * \note һ����GBMMI�ڲ�ʹ��
	 * \author chenbinghui
	 * \date 2009��12��2
	 */
	GBAPI GBRETURN GBInputResetNoHook(pGBInputStruct pGBIS);

   /*! \example GBSetCandType
	*/
   /*!
	* \brief ���ù������뷨����ĺ�ѡ���ͣ���Ӱ���û������ѡ�ķ�ʽ
	* \param pGBIS (in)pGBInputStruct����
	* \param CandType (in)��Ҫ���õĺ�ѡ���ͣ���ο�GBCandTypeEnum
	* \return 
		- GBE_API_GBIS_IS_NULL������pGBISΪNULL
		- GBOK���ɹ�����
	* \author lijingping
	* \date 2009��12��3��
	*/
	GBAPI GBRETURN GBSetCandType(pGBInputStruct pGBIS,GBINT CandType);

	/*! \example GBUpdateOutputInfo
	 */
	/*!
	 * \brief ���¹������뷨��������������Ϣ����ҪӰ��pGBInputStruct����outputInfo�ֶ�
	 * \param pGBIS (in)pGBInputStruct����
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBOK���ɹ�����
		 - GBE_API_LANG_DIDNOT_SUPPORT_API����ǰ�����Բ�֧�ִ�API
		 - other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \author chenbinghui
	 * \date 2009��7��22��
	 */
	GBAPI GBRETURN GBUpdateOutputInfo(pGBInputStruct pGBIS);
	
	/*! \example GBGetFullInputString
	 */
	/*!
	 * \brief ���������������봮
	 * \param pGBIS (in)pGBInputStruct����
	 * \param ppFullInputString (out) �������봮
	 * \return 
		 - GBOK���ɹ�����
	 * \note 
	 * \author Zhaokun
	 * \date 2011��4��26��
	 */
	GBAPI GBRETURN GBGetFullInputString(pGBInputStruct pGBIS, GBLPCWCHAR* ppFullInputString);
	/*@}*/


//MDB 
	/*!
	* \defgroup MDB ϸ�����ݿ⣨MDB��
	*/
	/*@{*/

	/*! \example fpGBMDBReadData_t
	 */
   /*!
	* \brief ����fread�ĺ���ָ�룬��һ��MDB/ϸ���ʿ��������һ��������
	* \param buffer (out)��Ŷ�ȡ��������
	* \param size (in)��ȡ��Ԫ�ĳ���
	* \param count (in)��ȡ��Ԫ�ĸ���
	* \param hFileHandle (in)��GBMDBAttachFile���������hFileHandle
	* \return 
		- ����ʵ�ʶ���ĵ�Ԫ�������������������ڵ����ļ�βʱ��û�дﵽ����countֵ����ʵ�ʶ��뵥Ԫ������С�ڲ���countֵ
	* \author chenbinghui
	* \date 2009��7��27��
	*/
	typedef GBU32 (* fpGBMDBReadData_t)(void * buffer, GBU32 size, GBU32 count, void * hFileHandle);

	/*! \example fpGBMDBFileSeek_t
	 */
	/*!
	 * \brief ����fseek�ĺ���ָ�룬��λMDB/ϸ���ʿ��е�λ��
	 * \param hFileHandle (in)�ļ�ָ��
	 * \param offset (in)�ƶ���ƫ��ֵ
	 * \param origin (in)��Ե�ԭ��
	 * \return 
		- 0 ��ʾ�ɹ���
		- !0 ��ʾʧ��
	 * \note 
		- originȡֵ��
		- 0 ///< like SEEK_SET�� λ�ô�ͷ��ʼ
		- 1 ///< like SEEK_CUR���ӵ�ǰ��λ�ÿ�ʼ
		- 2 ///< like SEEK_END���ӽ�����λ�ÿ�ʼ
	 * \author chenbinghui
	 * \date 2009��10��12��
	 */
	typedef GBINT (* fpGBMDBFileSeek_t)(GBLPVOID hFileHandle, GBI32 offset, GBINT origin);

	/*! \example fpGBMDBWriteData_t
	 */
	/*!
	* \brief ����fwrite�ĺ���ָ�룬������д�뵽MDB/ϸ���ʿ���
	* \param buffer (in)ָ����Ҫд�������
	* \param size (in)д�뵥Ԫ�ĳ���
	* \param count (in)д�뵥Ԫ��������
	* \param hFileHandle (in)���
	* \return 
		- ����ʵ��д��MDB/ϸ���ʿ��еĵ�Ԫ������������ִ���ʱ����ֵ���ܻ�С�ڲ���countֵ
	* \author chenbinghui
	* \date 2009��10��12��
	*/
	typedef GBU32 (* fpGBMDBWriteData_t)(const void * buffer, GBU32 size, GBU32 count, GBLPVOID hFileHandle);

	/*! \example GBMDBInit
	 */
	/*!
	 * \brief �������뷨����ϸ���ʿ��ʼ����ʹ��ϸ���ʿ�APIǰ�ȵ��øýӿڣ�����Ϊ��Ч�ĵ���
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pRamBuffer (in)����MDB��������Ҫ��RAM�ռ�
	 * \param nRamBufferLen (in)����Ҫ��������С
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBOK���ɹ�����
		 - other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \note �������ҪGBMDBAttachFile���ܣ��˿ռ����ΪNULL����ʱ�����ʹ��GBMDBAttach��ʹ��MDB/ϸ���ʿ⹦�ܡ������ҪGBMDBAttachFile���ܣ��˿ռ�Ϊ48KB��������ܵ���GBMDBAttachFileʧ�ܡ�Alphabetic���Բ�֧��GBMDBAttachFile���ܣ���֧��GBMDBAttach
	 * \author chenbinghui
	 * \date 2009��7��27��
	 */
	GBAPI GBRETURN GBMDBInit(pGBInputStruct pGBIS, GBLPVOID pRamBuffer, GBU32 nRamBufferLen);

	/*! \example GBMDBAttach
	 */
	/*!
	 * \brief ��װ�������뷨�����ϸ���ʿ�����
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pMDBData (in)ϸ���ʿ������
	 * \param nLang (in)ϸ���ʿ����ݵ����ԣ���ο�GBLanguageEnum
	 * \param nMDBDataLen (in)���ݵĴ�С
	 * \param pID (out)����һ��MDB/ϸ���ʿ��ID����ID��������GBMDBDetach����ID����ΪNULL����ʾ�����MDB/ϸ���ʿ��ID
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч����
		 - GBOK���ɹ�����
		 - other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \note Ŀǰ���֧��5��(GB_MDB_MAX_COUNT)MDB/ϸ���ʿ�
	 * \author chenbinghui
	 * \date 2009��7��22��
	 */
	GBAPI GBRETURN GBMDBAttach(pGBInputStruct pGBIS, 
		GBLPCVOID pMDBData, 
		GBU32 nLang,
		GBU32 nMDBDataLen, 
		GBINT * pID);

	/*! \example GBMDBAttachFile
	 */
	/*!
	 * \brief ��װ�������뷨�����MDBϸ���ʿ��ļ�
	 * \param pGBIS (in)pGBInputStruct����
	 * \param hFileHandle (in)ϸ���ʿ��ļ����
	 * \param nLang (in)(in)ϸ���ʿ����ݵ����ԣ���ο�GBLanguageEnum
	 * \param fpRead (in)��ȡ�ļ����ݵĻص�����������ʵ����ƽ̨��أ�Win32ƽֱ̨��ʹ��fread
	 * \param fpSeek (in)��λ�ļ����ݵĻص�����������ʵ����ƽ̨��أ�Win32ƽֱ̨��ʹ��fseek
	 * \param pID (out)����һ��MDB/ϸ���ʿ��ID����ID��������GBMDBDetach����ID����ΪNULL����ʾ�����MDB/ϸ���ʿ��ID
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч����
		 - GBOK���ɹ�����
		 - other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \note Ŀǰֻ����������֧�ִ˹��ܣ����֧��5��(GB_MDB_MAX_COUNT)MDB/MDB/ϸ���ʿ⡣�˳�ʱ���û�Ӧ�����ȵ���GBMDBDetach������Ȼ���ٹرմ򿪵��ļ���
	 * \author chenbinghui
	 * \date 2009��7��27��
	 */
	GBAPI GBRETURN GBMDBAttachFile(pGBInputStruct pGBIS, 
		GBLPVOID hFileHandle, 
		GBU32 nLang,
		fpGBMDBReadData_t fpRead, 
		fpGBMDBFileSeek_t fpSeek, 
		GBINT * pID);

 	/*! \example GBMDBDetach
	 */
	/*!
	 * \brief ж�ع������뷨����ϸ���ʿ�
	 * \param pGBIS (in)pGBInputStruct����
	 * \param nID (in)MDB/ϸ���ʿ��ID����IDӦ��ΪGBMDBAttach/GBMDBAttachFile������ֵ
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBE_API_NULL_FUNCTION_POINTER���պ���ָ��
		 - GBOK���ɹ�����
		 - GBE_API_MDB_INVALID_ID��MDB��ID��Ч
		 - other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \note �ı����Ե�ʱ�򣬲�����Detach��Ӧ���Ե�MDB��֮ǰ�Ѿ����úõ�MDB���������
	 * \author chenbinghui
	 * \date 2009��7��22��
	 */
	GBAPI GBRETURN GBMDBDetach(pGBInputStruct pGBIS, GBINT nID);

	/*! \example GBMDBCheckPhrase
	 */
	/*!
	 * \brief ���һ��MDB�����Ƿ����ĳ����
	 * \param pGBIS (in)pGBInputStruct����
	 * \param nMDBID (in)MDB/ϸ���ʿ��ID����IDӦ��ΪGBMDBAttach/GBMDBAttachFile������ֵ
	 * \param phrase (in)��Ҫ��������ַ���
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч����
		 - GB_Failed��ʧ��
		 - GBOK���ɹ�����
		 - GBE_API_MDB_INVALID_ID��MDB��ID��Ч
		 - GBE_API_UNSUPPORT_LANGUAGE����֧�ָ�����
		 - other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \note Ŀǰֻ֧�����Ĵ���˺�������������ģʽ�������
	 * \author chenbinghui
	 * \date 2009��10��12��
	 */
	GBAPI GBRETURN GBMDBCheckPhrase(pGBInputStruct pGBIS, 
		GBINT nMDBID,
		GBLPCWCHAR phrase);

	/*! \example GBMDBAddPhrase
	 */
	/*!
	 * \brief ���������뷨����󶨵�MDB�����ļ�������һ������
	 * \param pGBIS (in)pGBInputStruct����
	 * \param fp (in)�Ѿ��򿪵��ļ����
	 * \param fpSeek (in)��λ�ļ����ݵĻص�����������ʵ����ƽ̨��أ�Win32ƽֱ̨��ʹ��fseek
	 * \param fpWrite (in)д�ļ����ݵĻص�����������ʵ����ƽ̨��أ�Win32ƽֱ̨��ʹ��fwrite
	 * \param fpRead (in)��ȡ�ļ����ݵĻص�����������ʵ����ƽ̨��أ�Win32ƽֱ̨��ʹ��fread
	 * \param phrase (in)��Ҫд��MDB�ļ��Ĵ����ַ���
	 * \param syllable (in)�����Ӧ�������ַ���
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч����
		 - GBE_API_UNSUPPORT_LANGUAGE����֧�ָ�����
		 - GBOK���ɹ�����
  		 - other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \note ���������Ҫ300�ֽ����ҵ�Stack�ռ䣬��Ҫ����MDBʱ������Detch��MDB��Ȼ��ʹ��r+bģʽ���´��ļ����ٵ���GBMDBAddPhrase����Attach MDB���˺�������������ģʽ�������
	 * \author chenbinghui
	 * \date 2009��10��12��
	 */
	GBAPI GBRETURN GBMDBAddPhrase(pGBInputStruct pGBIS, 
		GBLPVOID fp,
		fpGBMDBFileSeek_t fpSeek,
		fpGBMDBWriteData_t fpWrite,
		fpGBMDBReadData_t fpRead,
		GBLPCWCHAR phrase,
		GBLPCWCHAR syllable);
	/*@}*/

	/*!
	 * \defgroup UDB �û�����ʺ���
	 */
	/*@{*/
	/*
	 * \brief ���ĳһ�������Ƿ��ڵ�ǰ��LDB��UDB���档
	 */
#define GB_CURRENT_UDB_ID		(-1)

	/*! \example GBAddUsedWord
	 */
	/*!
	 * \brief ���ӹ������뷨��������ʿ�Ĵ�������Զ�������ѡ����ĳ��ִ���
	 * \param pGBIS (in)pGBInputStruct����
	 * \param nUDBID (in)��Ч�������ID
	 * \param pPhrase (in)��Ҫ���ӵĴ����ַ���
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBE_API_INVALID_LANGUAGE����Ч������
		 - GBOK���ɹ�����
		 - other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \note ���ʹ����GBSelectCandidate����GBSelectCandidateEx������������Զ�������������������ֹ����á�
	 * \author chenbinghui
	 * \date 2009��7��27��
	 */
	GBAPI GBRETURN GBAddUsedWord(pGBInputStruct pGBIS, GBI32 nUDBID, GBLPCWCHAR pPhrase);

	/*! \example fpGBUDBUpdate_t
	 */
	/*!
	 * \brief ����UDB�Ļص�������
	 * \param nUDBID UDB ID
	 * \param pData UDB����
	 * \param len ���ݳ���
	 * \param pOEMUpdateParam pOEMUpdateParam��OEM��ֲ������GBUDBAttach�����addin����
	 * \author chenbinghui
	 * \date 2009��7��27��
	 */
	typedef void _gb_far (* fpGBUDBUpdate_t)(GBI32 nUDBID, GBLPVOID pData, GBU32 len, GBLPVOID pOEMUpdateParam);

	/*! \example GBUDBAttach
	 */
	/*!
	 * \brief Ϊ�������뷨����ָ����������UDB���ܣ�һ������ֻ֧��һ��UDB
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pUDBBuffer (in)���������Ļ�������������С��Ҫ5KB�Ŀռ䣻Alphabetic������Ҫ2KB���ϵĿռ䡣
	 * \param nUDBBufferLen (in)����ʻ�������С��byte��
	 * \param lang (in)UDB��Ӧ�����ԣ���ο�GBLanguageEnum
	 * \param subLang (in)UDB��Ӧ�ĵ����������ͣ���ο�GBSubLanguageEnum
	 * \param pUDBID (out)������óɹ��������ض�Ӧ��ID�����ݴ�ID���û����Խ���GBUDBDataReset��GBUDBDetach�Ȳ�����
	 * \return �ɹ�����GBOK�����ó����������Ե�UDB����GBE_API_To_Many_UDB���������زο�GBReturnEnum
	 * \return 
		- GBE_API_GBIS_IS_NULL������pGBISΪNULL
		- GBOK���ɹ�����
		- GBE_API_To_Many_UDB��UDB�ĸ�������������
		- GBE_API_LANG_UDB_EXISTS�������Ե�UDB�Ѿ�����
		- other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \note 1. һ�����������浱ǰ���Գɹ���������UDB���ܣ�
	 *       2. �������뷨����V5�汾��֧�ֲ�����2�����Ե�UDB���������2��������Ҫ����Detachһ��UDB��Ȼ����Attach��
	 *		 3. GBSetCurLanguage���������Զ��Ѷ�Ӧ�����Ե�UDB Detach��
	 *		 4. �û���Ҫ����֧���޷��л����ܣ���Ҫͬʱ��������������ԣ�һ��Ϊ���ĺ�Ӣ�ģ���UDB���ܣ������޷��л�����е�����ʽ��������档
	 * \author chenbinghui
	 * \date 2009��7��27��
	 */
	GBAPI GBRETURN GBUDBAttach(pGBInputStruct pGBIS, 
		GBLPVOID pUDBBuffer, 
		GBU32 nUDBBufferLen,
		GBINT lang,
		GBINT subLang,
		GBI32 * pUDBID);

	/*! \example GBChnUDBAttach
	 */
	/*!
	 * \brief Ϊ�������뷨����ָ����������UDB���ܣ�һ������ֻ֧��һ��UDB��
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pUDBBuffer (in)���������Ļ�������������С��Ҫ5KB�Ŀռ䣻Alphabetic������Ҫ2KB���ϵĿռ䡣
	 * \param nUDBBufferLen (in)����ʻ�������С��byte��
	 * \param pUpContentBuffer (in)�������ִ�������������ִʡ���������Ļ���������С��Ҫ256B�Ŀռ䡣
	 * \param nUpContentBufferLen (in)�������ִ�������������ִʡ����ܻ�������С��byte��
	 * \param lang (in)UDB��Ӧ�����ԣ���ο�GBLanguageEnum
	 * \param subLang (in)UDB��Ӧ�ĵ����������ͣ���ο�GBSubLanguageEnum
	 * \param pUDBID (out)������óɹ��������ض�Ӧ��ID�����ݴ�ID���û����Խ���GBUDBDataReset��GBUDBDetach�Ȳ�����
	 * \return �ɹ�����GBOK�����ó����������Ե�UDB����GBE_API_To_Many_UDB���������زο�GBReturnEnum
	 * \return 
		- GBE_API_GBIS_IS_NULL������pGBISΪNULL
		- GBOK���ɹ�����
		- GBE_API_To_Many_UDB��UDB�ĸ�������������
		- GBE_API_LANG_UDB_EXISTS�������Ե�UDB�Ѿ�����
		- other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \note 1. һ�����������浱ǰ���Գɹ���������UDB���ܣ�
	 *       2. �������뷨����V5�汾��֧�ֲ�����2�����Ե�UDB���������2��������Ҫ����Detachһ��UDB��Ȼ����Attach��
	 *		 3. GBSetCurLanguage���������Զ��Ѷ�Ӧ�����Ե�UDB Detach��
	 *		 4. �û���Ҫ����֧���޷��л����ܣ���Ҫͬʱ��������������ԣ�һ��Ϊ���ĺ�Ӣ�ģ���UDB���ܣ������޷��л�����е�����ʽ��������档
	 *       5. �������ִ�������������ִʡ����ܽ��������������棬���Է���������pUpContentBuffer����Ϊ��
	 * \author huanjin
	 * \date 2010��10��14��
	 */
	GBAPI GBRETURN GBChnUDBAttach(pGBInputStruct pGBIS, 
		GBLPVOID pUDBBuffer, 
		GBU32 nUDBBufferLen,
		GBLPVOID pUpContentBuffer, 
		GBU32 nUpContentBufferLen,
		GBINT lang,
		GBINT subLang,
		GBI32 * pUDBID);

	/*! \example GBChnUDBDetach
	 */
	/*!
	 * \brief ж�ع������뷨�����UDB���������ִ�������������ִʡ�����
	 * \param pGBIS (in)pGBInputStruct����
	 * \param nUDBID (in)��Ч����UDB�󷵻ص�ID
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBE_API_INVALID_UDB_ID����Ч��UDB ID
		 - GBOK���ɹ�����
	 * \note ���ͨ��GBUDBSetUpdateParam���������˸��º�������ôGBUDBDetach���Զ�����Ӧ��UDB�����UDB���޸��ˣ����Զ����ö�Ӧ�ĸ��º�����
	 *       ���û�����ø��º�������ô��GBUDBDetach֮ǰ��Ҫ����GBUDBGetModifiedCount���������UDB�Ƿ��и��£���������¹�������ʽ�����Ӧ��UDB���ݡ�
	 * \author huanjin
	 * \date 2010��10��15��
	 */
	GBAPI GBRETURN GBChnUDBDetach(pGBInputStruct pGBIS, GBI32 nUDBID);

	/*! \example GBChnUDBDataReset
	 */
	/*!
	 * \brief ��չ������뷨���浱ǰ����������ʼ��������ִ�������������ִʡ�����
	 * \param pGBIS (in)pGBInputStruct����
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBE_API_INVALID_LANGUAGE����Ч������
		 - GBOK���ɹ�����
		 - other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \author huanjin
	 * \date 2010��10��15��
	 */
	GBAPI GBRETURN GBChnUDBDataReset(pGBInputStruct pGBIS);

	/*! \example GBChnUDBSetUpdateParam
	 */
	/*!
	 * \brief ����UDB ���ݸ��µĲ���
	 * \param pGBIS 
	 * \param nUDBID ��Ч��UDB ID
	 * \param nUpdateFreq ���µ�Ƶ�ʣ����ݵ��޸Ĵ����������ֵ��ʱ������ͻ����fpUpdateFunction��һ����˵���ֵ����Ϊ10��
	 * \param fpUpdateFunction ���µĻص�����
	 * \param fpUpContentUpdateFunction ��������ʸ��»ص�
	 * \param pOEMUpdateParam OEMָ����һ���������ڻص���������ش���OEM��ֲ����
	 * \return 
	 * \note �������ֻ��Ҫʵ�����˳���ʱ�򱣴�����ʣ���ô��ʹ��\ref GBUDBGetModifiedCount�����UDB�Ƿ��޸Ĺ�
	 * \author chenbinghui
	 * \date 2009��7��28��
	 */
	GBAPI GBRETURN GBChnUDBSetUpdateParam(pGBInputStruct pGBIS, 
										  GBI32 nUDBID,
										  GBINT nUpdateFreq,
										  fpGBUDBUpdate_t fpUDBUpdateFunction,
										  fpGBUDBUpdate_t fpUpContentUpdateFunction,
										  GBLPVOID pOEMUDBUpdateParam);

	/*! \example GBUDBSetUpdateParam
	 */
	/*!
	 * \brief ���ù������뷨����UDB���ݸ��²���
	 * \param pGBIS (in)pGBInputStruct����
	 * \param nUDBID (in)��Ч����UDB�󷵻ص�ID
	 * \param nUpdateFreq (in)���µ�Ƶ�ʣ����ݵ��޸Ĵ����������ֵ��ʱ������ͻ����fpUpdateFunction��һ����˵���ֵ����Ϊ10��
	 * \param fpUpdateFunction (in)���µĻص�����
	 * \param pOEMUpdateParam (in)OEMָ����һ���������ڻص���������ش���OEM��ֲ����
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBE_API_INVALID_UDB_ID����Ч��UDB ID
		 - GBOK���ɹ�����
	 * \note �������ֻ��Ҫʵ�����˳���ʱ�򱣴�����ʣ���ô��ʹ��GBUDBGetModifiedCount�����UDB�Ƿ��޸Ĺ�
	 * \author chenbinghui
	 * \date 2009��7��28��
	 */
	GBAPI GBRETURN GBUDBSetUpdateParam(pGBInputStruct pGBIS, 
		GBI32 nUDBID,
		GBINT nUpdateFreq,
		fpGBUDBUpdate_t fpUpdateFunction,
		GBLPVOID pOEMUpdateParam);

	/*! \example GBUDBGetModifiedCount
	 */
	/*!
	 * \brief ���ĳһ��UDB��ʹ�ù����б��޸Ĺ����ٴ�
	 * \param pGBIS (in)pGBInputStruct����
	 * \param nUDBID (in)��Ч����UDB�󷵻ص�ID
	 * \param pModifiedCount (out)���޸ĵĴ���
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч����
		 - GBE_API_INVALID_UDB_ID����Ч��UDB ID
		 - GBOK���ɹ�����
	 * \sa GBUDBSetUpdateParam GBUDBDataReset GBUDBDetach
	 * \author chenbinghui
	 * \date 2009��7��28��
	 */
	GBAPI GBRETURN GBUDBGetModifiedCount(pGBInputStruct pGBIS, 
		GBI32 nUDBID,
		GBINT * pModifiedCount);

	/*! \example GBUDBDataReset
	 */
	/*!
	 * \brief ��չ������뷨���浱ǰ�����������
	 * \param pGBIS (in)pGBInputStruct����
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBE_API_INVALID_LANGUAGE����Ч������
		 - GBOK���ɹ�����
		 - other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \author chenbinghui
	 * \date 2009��7��28��
	 */
	GBAPI GBRETURN GBUDBDataReset(pGBInputStruct pGBIS);

	/*! \example GBUDBDetach
	 */
	/*!
	 * \brief ж�ع������뷨�����UDB
	 * \param pGBIS (in)pGBInputStruct����
	 * \param nUDBID (in)��Ч����UDB�󷵻ص�ID
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBE_API_INVALID_UDB_ID����Ч��UDB ID
		 - GBOK���ɹ�����
	 * \note ���ͨ��GBUDBSetUpdateParam���������˸��º�������ôGBUDBDetach���Զ�����Ӧ��UDB�����UDB���޸��ˣ����Զ����ö�Ӧ�ĸ��º�����
	 *       ���û�����ø��º�������ô��GBUDBDetach֮ǰ��Ҫ����GBUDBGetModifiedCount���������UDB�Ƿ��и��£���������¹�������ʽ�����Ӧ��UDB���ݡ�
	 * \author chenbinghui
	 * \date 2009��7��28��
	 */
	GBAPI GBRETURN GBUDBDetach(pGBInputStruct pGBIS, GBI32 nUDBID);

	/*! \example GBUDBAddPhrase
	 */
	/*!
	 * \brief ���������뷨����UDB����һ�������
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pWord (in)��Ҫ��������ʿ�Ĵ����ַ���
	 * \param syllable_together (in) Ambiguous���ĵ�ʱ��ʹ�ã������������ĵĶ����֡�������������棬�˲���Ӧ��ΪNULL��
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBE_API_INVALID_LANGUAGE����Ч������
		 - GBOK���ɹ�����
		 - other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \author chenbinghui
	 * \date 2009��7��28��
	 */
	GBAPI GBRETURN GBUDBAddPhrase(pGBInputStruct pGBIS, 
		GBLPCWCHAR pWord, 
		GBLPCWCHAR syllable_together);

	/*! \example GBUDBDeletePhrase
	 */
	/*!
	 * \brief ɾ���������뷨����UDB�е�һ�������
	 * \param pGBIS (in)pGBInputStruct����
	 * \param phrase (in)�û�ָ���Ĵ����ַ���
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBE_API_INVALID_LANGUAGE����Ч������
		 - GBOK���ɹ�����
	 * \author chenbinghui
	 * \date 2009��7��28��
	 */
	GBAPI GBRETURN GBUDBDeletePhrase(pGBInputStruct pGBIS, GBLPCWCHAR phrase);

	/*! \example GBUDBGetNextPhrase
	 */
	/*!
	 * \brief ö�ٹ������뷨�����е������
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pParamItem (in/out) ��һ�ε�ʱ��pParamItem����OEM����Ϊ0���˺�������Զ�����
	 * \param pBuffer (out)��Ż�ô���Ļ�������Buffer�ĳ���Ӧ�ò�С��GB_INPUT_BUFFER_LEN��
	 * \param nBuffLen (in)�������Ĵ�С
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBE_API_INVALID_LANGUAGE����Ч������
		 - GBOK���ɹ�����
		 - other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \author chenbinghui
	 * \date 2009��7��28��
	 */
	GBAPI GBRETURN GBUDBGetNextPhrase(pGBInputStruct pGBIS, GBUINT32 * pParamItem, GBLPWCHAR pBuffer, GBINT nBuffLen);
	/*@}*/

	/*!
	 * \defgroup Auxiliary	����API
	 */
	/*@{*/

	/*! \example GBIsInDatabase
	 */
	/*!
	 * \brief ���������뷨�������LDB��UDB�Ƿ����ָ���Ĵ���
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pPhrase (in)��Ҫ���Ĵ����ַ���
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч����
		 - GBE_API_INVALID_LANGUAGE����Ч������
		 - GBOK���ɹ�����
		 - other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \note ��������ֻ����UDB����
	 * \author chenbinghui
	 * \date 2009��7��28��
	 */
	GBAPI GBRETURN GBIsInDatabase(pGBInputStruct pGBIS, GBLPCWCHAR pPhrase);

	/*! \example GBGetLastError
	 */
	/*!
	 * \brief ������ù������뷨�������API�����������󣬻�ȡ���һ��ʧ�ܵ�ֵ
	 * \param pGBIS (in)pGBInputStruct����
	 * \return 
		- GB_API_GET_LAST_ERROR_NULL_PARAM������ΪNULL
		- other�������ڲ���¼�Ĵ���ֵ
	 * \note �ܹ����صĴ���ֵ��������ɿص�
	 * \author chenbinghui
	 * \date 2009��7��28��
	 */
	GBAPI GBRETURN GBGetLastError(pGBInputStruct pGBIS);

	/*! \example GBSetLastError
	 */
	/*!
	 * \brief ���ù������뷨���淢�����һ�δ���ʱ��ֵ
	 * \param pGBIS (in)pGBInputStruct����
	 * \param error (in)���������룬��ο�GBReturnEnum
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBOK���ɹ�����
	 * \note ���õ�errorֵֻ��С��0���ſ��ܱ�GBGetLastError���أ�
	     - �����Debug�汾����Win32ƽ̨VS2005�����µ�ǰ������Ϣֱ�������Output�Ի����У�������printf��ʽ���������Ϣ��
		 - ����û�ͨ��GBAttachLogRecorder�ӿ������Զ�����־��¼���������Ѿ�������GBFO_API_Stop_Log���ã�������Ϣ��ͨ����¼�������
	 * \author chenbinghui
	 * \date 2009��7��21��
	 */
	GBAPI GBRETURN GBSetLastError(pGBInputStruct pGBIS, GBRETURN error);

	/*! \example GBSetLastErrorEx
	 */
	/*!
	 * \brief ���ù������뷨���淢�����һ�δ���ʱ��ֵ
	 * \param pGBIS (in)pGBInputStruct����
	 * \param file (in)��ǰ���õ��ļ�
	 * \param line (in)ʹ�øýӿ�����Դ����к�
	 * \param pErr (in)�����˵��
	 * \param error (in)�������
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBOK���ɹ�����
	 * \note ���õ�errorֵֻ��С��0���ſ��ܱ�GBGetLastError���أ�
		 - �����Debug�汾����Win32ƽ̨VS2005�����µ�ǰ������Ϣֱ�������Output�Ի����У�������printf��ʽ���������Ϣ��
		 - ����û�ͨ��GBAttachLogRecorder�ӿ������Զ�����־��¼���������Ѿ�������GBFO_API_Stop_Log���ã�������Ϣ��ͨ����¼�������
	 * \author chenbinghui
	 * \date 2009��7��21��
	 */
	GBAPI GBRETURN GBSetLastErrorEx(pGBInputStruct pGBIS, 
		const char * file, 
		GBINT line, 
		const char * pErr, 
		GBRETURN error);

	/*! \example GBWriteLog1Param
	 */
	/*!
	 * \brief �������뷨�����ṩ��һ������Log��Ϣ�ĺ���
	 * \param pGBIS (in)pGBInputStruct����
	 * \param file (in)��ǰ���õ��ļ�
	 * \param line (in)ʹ�øýӿ�����Դ����к�
	 * \param msg (in)�����Ϣ�ַ���
	 * \param value (in)�������ֵ
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBOK���ɹ�����
	 * \note ���õ�errorֵֻ��С��0���ſ��ܱ�GBGetLastError���أ�
		 - �����Debug�汾����Win32ƽ̨VS2005�����µ�ǰ������Ϣֱ�������Output�Ի����У�������printf��ʽ���������Ϣ��
		 - ����û�ͨ��GBAttachLogRecorder�ӿ������Զ�����־��¼���������Ѿ�������GBFO_API_Stop_Log���ã�������Ϣ��ͨ����¼�������
	 * \author chenbinghui
	 * \date 2009��7��21��
	 */
	GBAPI GBRETURN GBWriteLog1Param(pGBInputStruct pGBIS, 
		const char * file, 
		GBINT line,	
		const char * msg, 
		GBU32 value);

	/*! \example fpLogRecorder_t
	 */
	/*!
	 * \brief ����һ��Log�ļ�¼���ص�����
	 * \param pOEMData OEM�������������fpLogRecorder_t��Ӧ�Ļص������ش���OEM��
	 * \param format ��ʽ����������printf�ĺ����ĸ�ʽ
	 * \param p1 ����ĵ�1������
	 * \param p2 ����ĵ�2������ 
	 * \param p3 ����ĵ�3������ 
	 * \param p4 ����ĵ�4������ 
	 * \return ����
	 * \author chenbinghui
	 * \date 2009��7��23��
	 */
#ifndef FPLOGRECORDER_T_DEF
#define FPLOGRECORDER_T_DEF
	typedef GBINT (* fpLogRecorder_t)(GBLPVOID pOEMData, const char * format, unsigned long p1, unsigned long p2, unsigned long p3, unsigned long p4);
#endif

	/*! \example GBAttachLogRecorder
	 */
	/*!
	 * \brief Ϊ�������뷨���氲װһ��Log�Ĺ۲��ߣ����������ڳ����ʱ����Ը�����ϸ�ĳ�����Ϣ
	 * \param pGBIS (in)pGBInputStruct����
	 * \param viewer (in)��־����Ļص�����
	 * \param pOEMData (in)OME���뵽�ص�����������Ҫ�Ĳ���
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч����
		 - GBOK���ɹ�����
	 * \note Debug�汾�������ܹ������ϸ����Ϣ����VC�汾�Ŀ��У�������Զ�����Ϣ�����Output�Ӵ������档
	 * \author chenbinghui
	 * \date 2009��11��19��
	 */
	GBAPI GBRETURN GBAttachLogRecorder(pGBInputStruct pGBIS, fpLogRecorder_t viewer, GBLPVOID pOEMData);

	/*! \example GBGetDataLanguage
	 */
	/*!
	 * \brief ��ȡ�������뷨�������������Ϣ
	 * \param pData (in)��Ӧ�������ݣ������ļ��������256���ֽڵ�������Ϣ
	 * \param pLang (out)���������е�����ID����ο�GBLanguageEnum
	 * \param pSubLang (out)���������еĵ�������ο�GBSubLanguageEnum
	 * \param pSize (out)�����������ݵĴ�С
	 * \return 
		 - GB_Failed��ʧ��
		 - GBOK���ɹ�����
	 * \author chenbinghui
	 * \date 2009-09-08
	 */
	GBAPI GBRETURN GBGetDataLanguage(GBLPCVOID pData, GBLANG * pLang, GBSUBLANG * pSubLang, GBU32 * pSize);
	
	/*@}*/
//GB Event API

	/*!
	 * \defgroup GBMMI	GBMMI����
	 */
	/*@{*/
	/*! \example GBMMIHandleKeyEvent
	 */
	/*!
	 * \brief ���������Ϣ��MMI����
	 * \param pGBIS (in)pGBInputStruct����
	 * \param evt (in)�¼��������ͣ���ο�GBEventEnum
	 * \param param (in) ��Ϣ�Ĳ���
	 * \return 
		- GBE_API_GBIS_IS_NULL������pGBISΪNULL
		- GBE_API_AUX_INFO_IS_NULL��tagGBInputStruct::pAuxInfo Ϊ��
		- GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч����
		- GBOK���ɹ�����
		- other���ο�gbdef.h�ļ��е�GBReturnEnum����
	 * \note ���ô˺���֮ǰ������GBInitialize��GBSetCurLanguage��GBSetInputMode����������������ʹ��GBGetLastError��֪��������͡�
	 * \sa GBInitialize GBSetCurLanguage GBSetInputMode GBGetLastError
	 * \author chenbinghui
	 * \date 2009��8��5��
	 */
	GBAPI GBRETURN GBMMIHandleKeyEvent(pGBInputStruct pGBIS, GBINT evt, GBU32 param);

	/*! \example GBMMISetCandRowCount
	 */
	/*!
	 * \brief ���ù������뷨�����ѡ����
	 * \param pGBIS (in)pGBInputStruct����
	 * \param nStatus (in)��Ҫ���õ�״̬��ΪGBInputModeStatusEnum�е�ֵ
	 * \param nRowCount (in)��ѡ����
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч����
		 - GBOK���ɹ�����
	 * \author chenbinghui
	 * \date 2009��11��13��
	 */
	GBAPI GBRETURN GBMMISetCandRowCount(pGBInputStruct pGBIS, GBINT nStatus, GBINT nRowCount);
	

	/*! \example GBMMIGetCandRowCount
	 */
	/*!
	 * \brief ��ȡ����״̬��ѡ������
	 * \param pGBIS (in)pGBInputStruct����
	 * \param nStatus (in)��ǰ״̬��ΪGBInputModeStatusEnum�е�ֵ
	 * \param pCandRowCount (out)���غ�ѡ����
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч����
		 - GBOK���ɹ�����
	 * \note pRowCountForEachStatus һ������ΪGBIMS_STATUS_COUNT�����飬�����ÿһ��Ԫ�ر�ʾ��Ӧ����״̬�ĺ�ѡ������0��ʾ�ڸ�״̬����رպ�ѡ��
	 * \sa GBInputModeStatusEnum
	 * \author chenbinghui
	 * \date 2009��11��13��
	*/
	GBAPI GBRETURN GBMMIGetCandRowCount(pGBInputStruct pGBIS, GBINT nStatus,GBINT *pCandRowCount);

	/** \brief ����������Ĺ���ѡ�� */
	enum GBInterpunctionKeyOption
	{
		///��ǰ���ں�ѡ�������GBMMI��������ǰѡ���ѡ��Ȼ��ʼ����������
		GBIKO_Input_Status_Confirm_Candidate = 1		
	};

	/*! \example GBMMIRegisterInterpunctionKeyEx
	 */
	/*!
	 * \brief ���ù������뷨�������������ѡ��
	 * \param pGBIS (in)pGBInputStruct����
	 * \param cKey (in)�����İ������ο�GBEventEnum
	 * \param pSymbols (in)�����ţ�������Ҫ��ȫ�ֱ��������Ե���Unicode�ı����ţ�Ҳ����Ϊ���Unicode�ı�����
					- ���õ���Unicode�ı����ţ������еı�������Ϊһ���ַ�����cSplit��������Ϊ0����
					- ���ö��Unicode�ı����ţ���:-( :-)�ȣ���ͬ�ķ���֮��ʹ�÷ָ����ŷָ���Ȼ��ѷָ���ͨ��cSplit����
					- NULL��ʱ���ʾʹ�õ�ǰ���Ե�Ĭ�ϱ�����
	 * \param cSplit (in)��ʾpSymbols�����еķָ���������ָ���Ϊ0����ʾ�����Ŷ��ǵ�����ĸ�ı�㡣
	 * \param nCandListType (in)��ѡ�б�����࣬���Բ�ȡ���º�ѡ�б����ͣ��ο�GBCandListType
					- GBCL_MULTITAP ��ȡMultiTap�ķ�ʽ���������
					- GBCL_ROW_MULTITAP ���к�ѡ(֧�ּ���)��nCandDesireRow�����������ú�ѡ������
					- GBCL_ROW_TCH_SCR ���к�ѡ(������)��nCandDesireRow�����������ú�ѡ������
	 * \param nCandDesireRow (in)����ѡ������ΪGBCL_ROW_KEYBD����GBCL_ROW_TCH_SCRʱ��ÿһҳ��Ҫ��ѡ����
	 * \param nCandCountPerRow (in)����ѡ������ΪGBCL_ROW_KEYBD����GBCL_ROW_TCH_SCRʱ��ÿһ����Ҫ��ѡ����
	 * \param nOption (in)���ñ����������ѡ��
					- 0 ��ʾֻ��������״̬���߳�ʼ��״̬����Ӧ�İ����ſ��Կ�ʼ�������
					- GBIKO_Input_Status_Confirm_Candidate ��ʾ��ǰ���ں�ѡ�������GBMMI��������ǰѡ���ѡ��Ȼ��ʼ����������
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч����
		 - GBOK���ɹ�����
		 - GBE_MMI_TOO_MANY_MULTITAP_KEY����ǰ����ģʽ�����Ѿ�������̫���MultiTap����
	 * \sa GBMMIRegisterInterpunctionKey
	 * \author chenbinghui
	 * \date 2009��11��17��
	*/
	GBAPI GBRETURN GBMMIRegisterInterpunctionKeyEx(pGBInputStruct pGBIS, 
		GBINT cKey,
		GBLPCWCHAR pSymbols,
		GBINT cSplit,
		GBINT nCandListType,
		GBINT nCandDesireRow,
		GBINT nCandCountPerRow,
		GBUINT nOption);

	/*! \example GBMMIRegisterInterpunctionKey
	 */
	/*!
	* \brief ���ù������뷨�������������ѡ��
	* \param pGBIS (in)pGBInputStruct����
	* \param cKey (in)�����İ������ο�GBEventEnum
	* \param pSymbols (in)�����ţ�������Ҫ��ȫ�ֱ��������Ե���Unicode�ı����ţ�Ҳ����Ϊ���Unicode�ı�����
		- ���õ���Unicode�ı����ţ������еı�������Ϊһ���ַ�����cSplit��������Ϊ0���ɡ�
		- ���ö��Unicode�ı����ţ���:-( :-)�ȣ���ͬ�ķ���֮��ʹ�÷ָ����ŷָ���Ȼ��ѷָ���ͨ��cSplit����
		- NULL��ʱ���ʾʹ�õ�ǰ���Ե�Ĭ�ϱ�����
	* \param nCandDesireCount (in)ÿһ����Ҫ��ѡ����	
	* \return 
		- GBE_API_GBIS_IS_NULL������pGBISΪNULL
		- GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч����
		- GBOK���ɹ�����
		- GBE_MMI_TOO_MANY_MULTITAP_KEY����ǰ����ģʽ�����Ѿ�������̫���MultiTap����
	* \sa GBMMIRegisterInterpunctionKey
	* \author chenbinghui
	* \date 2009��11��17��
	*/

	GBAPI GBRETURN GBMMIRegisterInterpunctionKey(pGBInputStruct pGBIS, 
		GBINT cKey,
		GBLPCWCHAR pSymbols,
		GBINT nCandDesireCount);

	/*! \example GBMMIUnregisterInterpunctionKey
	 */
	/*!
	 * \brief ȡ��Interpunction Key������
	 * \param pGBIS (in)pGBInputStruct����
	 * \param cKey (in)�����İ������ο�GBEventEnum�����cKeyΪ0����ȡ�����е�key����
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBOK���ɹ�����
	 * \author chenbinghui
	 * \date 2009��11��17��
	*/
	GBAPI GBRETURN GBMMIUnregisterInterpunctionKey(pGBInputStruct pGBIS, GBINT cKey);


	/*! \example GBMMISetAlphabeticUAWTips
	 */
	/*!
	 * \brief �����û�����ʵ���ʾ
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pUAWTips (in)��ʾ�û�����ʵ��ı�
	 * \param count (in)�������ʾ����Ч����
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBOK���ɹ�����
	 * \note �ڴ�Alphabetic ��������̵�����£��û�����û�ж�Ӧ��ѡ
	 * \sa GB_Function_Option GBSetEngineOption
	 * \author chenbinghui
	 * \date 2009��10��13��
	 */
	GBAPI GBRETURN GBMMISetAlphabeticUAWTips(pGBInputStruct pGBIS, 
		lpcGBAlpUAWTip pUAWTips,
		GBINT count);

	/*! \example GBMMIGetInputModeBeforeSwitchLang
	 */
	/*!
	* \brief �����޷��л��е�һ����ջ�����뷨ģʽ
	* \param pGBIS (in)pGBInputStruct����
	* \param inputMode (out)����ģʽ
	* \return 
		- GBE_API_GBIS_IS_NULL������pGBISΪNULL
		- GBE_MMI_NOT_SWITCH_LANG_STATUS����ǰ��û�д����޷��л�״̬
		- GBOK���ɹ�����
		* \note 
	* \author zhj
	* \date 2010��3��2��
	*/
	GBAPI GBRETURN GBMMIGetInputModeBeforeSwitchLang(pGBInputStruct pGBIS, GBINT *inputMode);

	/*! \example GBMMIReset
	 */
	/*!
	* \brief GBMMI��reset�ӿ�
	* \param pGBIS (in)pGBInputStruct����
	* \return 
	- GBE_API_GBIS_IS_NULL:  pGBIS Ϊ��
	- GBOK: �ɹ�
	* \note �����뷨����ΪInitial״̬; �����봮���; ���һ��ʼ��AuxInfo; ���֧���޷��л������Ҵ����޷��л�״̬���ỹԭ���л�֮ǰ��״̬��
	* 		  �������GBL_Chinese���ԣ�������Shift��CapsLock״̬Ϊ0
	* \author zhonghuajin
	* \date	2010��3��4��
	*/
	GBAPI GBRETURN GBMMIReset(pGBInputStruct pGBIS);

	/*! \example fpFirstPage_t
	 */
	/*!
	 * \brief ���ݵ�ǰ���밴�����л�ȡ��һҳ�ĺ�ѡ
	 * \param pGBIS (in)pGBInputStruct����
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBOK���ɹ�����
	 * \author chenbinghui
	 * \date 2009��10��12��
	 */
	typedef GBRETURN (* fpFirstPage_t)(pGBInputStruct pGBIS);	

	/*! \example fpGetACand_t
	 */
	/*!
	 * \brief ��ȡһ����ѡ������֮ǰ����ɹ�����fpGBFirstPage
	 * \param pGBIS (in)pGBInputStruct����
	 * \param index ��ѡ���±�
	 * \param pCand (out) ָ���ѡ��ָ��
	 * \param pInputLen (in)���봮����
	 * \param pMoreCand (out) �Ƿ��и���ĺ�ѡ
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBOK���ɹ�����
	 * \author chenbinghui
	 * \date 2009��10��12��
	 */
	typedef GBRETURN (* fpGetACand_t)(pGBInputStruct pGBIS, GBINT index, GBWCHAR * * pCand, GBU8 * pInputLen, GBBOOL * pMoreCand);

	/*! \example fpGetCandidateIndex_t
	 */
	/*!
	 * \brief ������浱ǰ�ĺ�ѡ�±꣬Alphabetic����Ϊ��ȷ�ģ���������Ϊ��ǰҳ�ĵ�һ����ѡ��Index
	 * \param pGBIS (in) pGBInputStruct����
	 * \param pIndex (out) ��ѡ�±�
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBOK���ɹ�����
	 * \author chenbinghui
	 * \date 2009��10��12��
	 */
	typedef GBRETURN (* fpGetCandidateIndex_t)(pGBInputStruct pGBIS, GBINT * pIndex);

	/*! \example fpSelectCandidate_t
	 */
	/*!
	 * \brief ѡ��һ����ѡ
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pCand (in)ѡ��ĺ�ѡ
	 * \param nInputLen (in)���봮����
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBOK���ɹ�����
	 * \author chenbinghui
	 * \date 2009��10��12��
	 */
	typedef GBRETURN (* fpSelectCandidate_t)(pGBInputStruct pGBIS, GBLPCWCHAR pCand, GBINT nInputLen);

	/*! \example fpNormalHandler_t
	 */
	/*!
	 * \brief ȡ��һ����ѡѡ��
	 * \param pGBIS (in)pGBInputStruct����
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBOK���ɹ�����
	 * \author chenbinghui
	 * \date 2009��10��12��
	 */
	typedef GBRETURN (* fpNormalHandler_t)(pGBInputStruct pGBIS);

	/** \brief ����Wrapper��������ʱ�ı�����ĺ�ѡ��úʹ���ʽ���κ������ΪNULL����ʾ���滻��Ӧ��ֵ */
	    
	typedef struct tagGBEngineWrapper
	{
		///���ݵ�ǰ���밴�����л�ȡ��һҳ�ĺ�ѡ
		fpFirstPage_t				fpFirstPage;
		///��ȡһ����ѡ������֮ǰ����ɹ�����fpGBFirstPage
		fpGetACand_t				fpGetACand;
		///������浱ǰ�ĺ�ѡ�±꣬Alphabetic����Ϊ��ȷ�ģ���������Ϊ��ǰҳ�ĵ�һ����ѡ��Index
		fpGetCandidateIndex_t		fpGetCandidateIndex;
		///ѡ��һ����ѡ
		fpSelectCandidate_t			fpSelectCandidate;
		///ȡ��һ����ѡѡ��, һ��ֻ��Ҫ����GB_API_NO_MORE_SELECTION����
		fpNormalHandler_t			fpCancelSelectCandidate;
		///Wrapper Flag
		//start[2010-3-15 zhj]
		//���GBFO_Chn_All_Num_Can_Continuously_Input�����ĸĶ�
		fpNormalHandler_t			fpUpateOutputInfo;
		//end[2010-3-15 zhj]	

		GBU32						lWrapperFlag;
		GBPageOption *				pPageOption;
	} GBEngineWrapper;

	/*! \example GBInstallEngineWrapper
	 */
	/*!
	 * \brief ��װ����Wrapper��������ʱ�ı�����ĺ�ѡ��úʹ���ʽ
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pWrapper (in)����Wrapper��ΪNULL��ʱ���ʾReset���еĺ���ָ��
	 * \param pOldFunc (out, optional)����֮ǰʹ�ú���ָ�룬����ΪNULL
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBOK���ɹ�����
	 * \note ��Ҫж�ص�ʱ��ֻ��Ҫ����GBInstallEngineWrapper(pGBIS, NULL, NULL)�Ϳ�����
	 * \sa GBEngineWrapper GBSetInputMode
	 * \author chenbinghui
	 * \date 2009��10��13��
	*/
	GBAPI GBRETURN GBInstallEngineWrapper(pGBInputStruct pGBIS, 
		const GBEngineWrapper * pWrapper, 
		GBEngineWrapper * pOldFunc);

#define GBUninstallEngineWrapper(pGBIS)		GBInstallEngineWrapper((pGBIS), NULL, NULL)

	/*! \example GBMMISetDefaultCandListType
	 */
	/*!
	 * \brief ���õ�ǰ����״̬�ĺ�ѡ��ʽ
	 * \param pGBIS (in)pGBInputStruct����
	 * \param nCandListType (in)ֻ����GBCL_ROW_KEYBD/GBCL_ROW_TCH_SCR/GBCL_SINGLE_CAND��һ��
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBE_MMI_INVALID_CAND_LIST_TYPE����ǰ��״̬�²���ʹ���������ģʽ
		 - GBOK���ɹ�����
	 * \note �˺�����Ҫ������֮ǰ���ã�һ����\ref GBSetInputMode֮����ã��������뷨����ѡ��GBCL_ROW_KEYBD��GBCL_Row_Touchscr Alphabetic����ѡ��GBCL_ROW_KEYBD��GBCL_Row_Touchscr��GBCL_SINGLE_CAND Alphabeticѡ����GBCL_SINGLE_CAND֮�󣬷�ҳѡ�����ÿһҳֻ��Ҫ1����ѡ
	 * \author chenbinghui
	 * \date 2009��10��15��
	*/
	GBAPI GBRETURN GBMMISetDefaultCandListType(pGBInputStruct pGBIS, GBINT nCandListType);

	/*! \example GBMMISetSwitchOption
	 */
	/*!
	 * \brief �����޷��л��Ĳ���
	 * \param pGBIS (in)pGBInputStruct����
	 * \param nGBKey (in) �޷��л��Ĵ�������
	 * \param nLang (in)Ŀ�����뷨���������ͣ��ο�GBLanguageEnum��Ĭ��ΪGBL_English
	 * \param nSubLang (in)Ŀ�����뷨�ĵ������ο�GBSubLanguageEnum
	 * \param nInputMode (in)Ŀ������ģʽ��GBInputModeEnum
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBOK���ɹ�����
	 * \author chenbinghui
	 * \date 2009��10��21��
	 */
	GBAPI GBRETURN GBMMISetSwitchOption(pGBInputStruct pGBIS, 
		GBINT nGBKey, 
		GBINT nLang, 
		GBINT nSubLang, 
		GBINT nInputMode);


	/*! \example GBMMISetSpecialKeyMapping
	 */
	/*!
	 * \brief ����GBKEY_SPECIAL_A �ȼ���Ӧ��KeyMapping
	 * \param pGBIS (in)pGBInputStruct����
	 * \param cSpecialAKey (in)�����水��GBKEY_AMB_SPECIAL_A��Ӧ��ƽ̨����������ʱ��Ӧ�ü��뵽inputstring���ַ�,ͨ��Ϊ��#��
	 * \param cSPecialBKey (in)�����水��GBKEY_AMB_SPECIAL_B��Ӧ��ƽ̨����������ʱ��Ӧ�ü��뵽inputstring���ַ�,ͨ��Ϊ��*��
	 * \param cSPecialCKey (in)�����水��GBKEY_AMB_SPECIAL_C��Ӧ��ƽ̨����������ʱ��Ӧ�ü��뵽inputstring���ַ�
	 * \param cSPecialDKey (in)�����水��GBKEY_AMB_SPECIAL_D��Ӧ��ƽ̨����������ʱ��Ӧ�ü��뵽inputstring���ַ�
	 * \return 
		 - GBE_API_GBIS_IS_NULL������pGBISΪNULL
		 - GBOK���ɹ�����
	 * \note �������ֻ����Alphabetic���Ե�KeyMapping����Щ*����#������ĸ����²���Ҫʹ�ã�������Mapping֮����Щ����ԭ���İ������彫��ʧЧ�����Խ���Ӧ�Ĳ�������Ϊ0���رմ˹���
	 * \author chenbinghui
	 * \date 2009��11��4��
	 */
	GBAPI GBRETURN GBMMISetSpecialKeyMapping(pGBInputStruct pGBIS, 
		GBINT cSpecialAKey,
		GBINT cSPecialBKey,
		GBINT cSPecialCKey,
		GBINT cSPecialDKey);

	/*! \example GBMMISetQwertyMapArray
	 */
	/*!
	 * \brief ����Qwerty����ӳ������
	 * \param pGBIS ������⽻������
	 * \param ppcQwertyMapArray ��in��Qwerty���̰���ӳ��2ά����
	 * \param cQwertyMapNum ��in��Qwerty���̰���ӳ��2ά����Ԫ�ظ���
	 * \return 
		 - GBOK ���óɹ�
		 - GBE_API_GBIS_IS_NULL �����Ĳ���pGBISΪNULL
	 * \note
		 - ppcQwertyMapArray[0] ΪQwerty�����ַ�����ͨ��Ϊ��a-z"
		 - ppcQwertyMapArray[1] Ϊ�����ַ�����Ӧ���ַ�����ͨ��Ϊ��0-9"��Ҳ���԰����κζ�Ӧ���ַ�
	 * \author haj
	 * \date 2011-4-25
	 */
	GBAPI GBRETURN GBMMISetQwertyMapArray(pGBInputStruct pGBIS, GBLPCWCHAR * ppcQwertyMapArray,	const GBU32 cQwertyMapNum);


	/*@}*/

	/*!
	 * \defgroup Version ���ʰ汾����غ���
	 */
	/*@{*/

	/*! \example GBGetOEMID
	 */
	/*!
	 * \brief  ��ô������OEMID��ţ��ñ��Ψһָ����ÿһ��OEM
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pOEMID (out)��ȡOEM ID
	 * \return 
		 - GBOK���ɹ�����
	 * \author chenbinghui
	 * \date 2009��11��4��
	 */
	GBAPI GBRETURN GBGetOEMID(pGBInputStruct pGBIS, GBI32 * pOEMID);

	/*! \example GBGetBuildID
	 */
	/*!
	 * \brief ��ô������Build��ţ��ñ��Ψһָ����ÿһ��Release
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pBuildID (out)��ȡBuild ID
	 * \return 
		 - GBOK���ɹ�����
	 * \author chenbinghui
	 * \date 2009��11��4��
	 */
	GBAPI GBRETURN GBGetBuildID(pGBInputStruct pGBIS, GBI32 * pBuildID);

	/*! \example GBGetEngineVersion
	 */
	/*!
	 * \brief ��ô�����Ĺ��ܰ汾
	 * \param pGBIS (in)pGBInputStruct����
	 * \param pEnginVersion (out)��ȡ�汾��
	 * \return 
		 - GBOK���ɹ�����
	 * \author chenbinghui
	 * \date 2009��11��4��
	 */
	GBAPI GBRETURN GBGetEngineVersion(pGBInputStruct pGBIS, GBVersion * pEnginVersion);
	/*@}*/


	/*!
	* \defgroup Timer	MultiTap��ʱ��
	*/
	/*@{*/

	enum GBTimerTypeEnum 
	{
		GBTT_MultiTap = 100		///<MultiTap
	};

	/*! \example fpGBRequestTimer_t
	 */
	/*!
	 * \brief OEM�ṩ��һ������һ��Timer�Ĺ��ܵĻص�������
	 * \param nTimerType Timer�����ͣ�ΪGBTimerTypeEnum�е�һ��
	 * \param pOEMPrivateData \ref GBMMIAttachTimerFunction������Ӧ
	 * \return һ��32λ����������ʾ���Timer����ID����ΪkillTimer�Ĳ���ʹ��
	 * \note ������MultiTap��ʼ��ʱ�򽫻���ô˺�������һ��Timer����Timer������ʱ��
	 *       OEM��Ҫͨ��GBMMIHandleKeyEvent������GBMMI����һ��GBKEY_Ok����Ϣ���Ա�
	 *       MultiTap����ģʽ����������������pOEMPrivateDataΪOEM����\ref GBMMIAttachTimerFunction
	 *       ������pOEMPrivateData������ֵ��OEM�Լ����á�ά����
	 * \author chenbinghui
	 * \date 2009��7��31��
	 */
	typedef GBU32 (* fpGBRequestTimer_t)(GBLPVOID pOEMPrivateData, GBINT nTimerType);

	/*! \example fpGBRequestKillTimer_t
	*/
	/*!
	 * \brief OEM�ṩ��һ���ص��������ú����ṩȡ��Timer�Ĺ��ܡ�
	 * \param nTimerID fpGBRequestTimer�ĺ�������ֵ
	 * \param pOEMPrivateData \ref GBMMIAttachTimerFunction�����Ĵ���Ĳ���
	 * \return 1��ʾ�ɹ���0��ʾʧ�ܡ�
	 * \note ������pOEMPrivateDataΪOEM����\ref GBMMIAttachTimerFunction
	 *       ������pOEMPrivateData������ֵ��OEM�Լ����á�ά����
	 *       ����1��ʱ���ʾ�ɹ�������0��ʧ��
	 * \author chenbinghui
	 * \date 2009��7��31��
	 */
	typedef GBU32 (* fpGBRequestKillTimer_t)(GBLPVOID pOEMPrivateData, GBU32 nTimerID);


	/*! \example GBMMIAttachTimerFunction
	 */
	/*!
	 * \brief OEMΪ��������Timer��صĺ����Ͳ���
	 * \param pGBIS (in)pGBInputStruct����
	 * \param requestTimer (in)�û�ָ��timer�ص���������ƽ̨���
	 * \param killTimer (in)�û�����timer�ص���������ƽ̨���
	 * \param pOEMPrivateData (in)�û��Զ�����������
	 * \return 
		- GBOK���ɹ�����
		- GBE_API_GBIS_IS_NULL��pGBISΪNULL
		- GBE_API_INVALID_PARAM�������Ĳ������ٰ���һ����Ч����
	 * \note ��ʱ��������ʱ���û���Ҫ����GBMMIHandleKeyEvent����һ��OK���İ�����Ϣ�������MultiTap����
	 * \author chenbinghui
	 * \date 2009��7��31��
	 */
	GBAPI GBRETURN GBMMIAttachTimerFunction(pGBInputStruct pGBIS, 
		fpGBRequestTimer_t requestTimer,
		fpGBRequestKillTimer_t killTimer,
		GBLPVOID pOEMPrivateData);

	/*! \example GBALPSetAbbreviateWordTreeEnable
	*/
	/*!
	* \brief �����Ƿ�������д�ʱ���
	* \param pGBIS (in) pGBInputStruct����
	* \param enable (in) 0:��������д�ʱ�����1��������д�ʱ���
	* \return 
	* \note return 0��ʾ�ɹ��������ʾʧ�ܡ�
		-���޷��л���ʱ��Ӧ��������������ʱ��������
	* \author zhonghuajin
	* \date 2010-10-14
	*/
	GBAPI GBRETURN GBALPSetAbbreviateWordTreeEnable(pGBInputStruct pGBIS, GBINT enable);
#ifdef __cplusplus
};
#endif

#endif
