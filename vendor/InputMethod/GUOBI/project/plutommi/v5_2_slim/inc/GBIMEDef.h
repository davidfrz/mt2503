/***************************************************************************
* File Name    :  GBIMEDef.h
* Corporation  :  Guobi Technology Ltd. GuangZhou China
* Copyright    :  Copyright Guobi Technology Ltd. And Subject to Confidentiality 
*                 Restrictions. This document is the confidential and proprietary 
*                 property of Guobi Technology Ltd.It is neither the document                  
*                 itself nor any part of it can be shared with any party  without 
*                 the written  permission. 
* Author       :  weizhiping
* Date         :  2010-06-08
* Purpose      :  ���뷨����ⲿ��������
* Version      :  V1.0
* Last Changed List
* Name         |   date   |  Discription
****************************************************************************/
#ifndef __GBIME_DEF_H_
#define __GBIME_DEF_H_

#include "gbtype.h"
#include "gbdef.h"
#include "mmi_include.h"
#include "mmi_features.h"

#define GBIME_CFG_STATIC_DB					1	// ʹ�þ�̬����
#define GBIME_CFG_UDB_SUPPORT					1	// UDB���������ģ��<
//#define GBIME_USE_GBK_DB						1    // ʹ��GBK�ַ�������


#define __GB_0KEY_SPACE__


#ifndef GB_MICRO_OPTIMIZATION
#define GB_MICRO_OPTIMIZATION       1
#endif

#ifndef GBIMEAPI
#ifdef GBIMPORT
#define GBIMEAPI  __declspec(dllimport)
#else
#define GBIMEAPI	extern
#endif
#endif

/*!
 * \brief ���뵥Ԫ�ڲ�ʹ�õĺ���
 */
#define GBIMELOCAL		static
/*!
 * \brief ȫ��ʹ�ã��������⹫���ĺ���
 */
#define GBIMEGLOBAL 
/*!
 * \brief ���⹫���ĺ���
 */
#define GBIMEEXPORT 

#define GBIME_MAX_DB_COUNT							50	///<����������ݸ���
#define GBIME_DEF_MAX_CAND_WORD				    		9	///<Ĭ������ѡ�ʸ��� < GB_MAX_CANDIDATES
#define GBIME_DEF_CHN_MAX_CAND_WORD				9	///<Ĭ������ѡ�ʸ��� < GB_MAX_CANDIDATES
#define GBIME_DEF_SYLLABLE_MAX_CAND_WORD			9	///<Ĭ������ѡ�ʸ��� < GB_MAX_CANDIDATES
#define GBIME_DEF_ENGINSH_MAX_CAND_WORD			9	///<Ĭ������ѡ�ʸ��� < GB_MAX_CANDIDATES
	
///<���뷨�����������(��Ҫ)
#ifdef GBIME_CFG_UDB_SUPPORT
	#define GBIME_UDB_UPDATE_FREQ		 				20 ///<����Ƶ�ʣ����ݵ��޸Ĵ����������ֵ��ʱ������ͻ����fpUpdateFunction��һ����˵���ֵ����Ϊ10
#endif/*GBIME_CFG_UDB_SUPPORT*/

#define GBIME_FILENAME_LEN 							256

/*!
 * \brief GB��������ѡ��궨��
 */
#define GBIME_SWITCH_KEY								GBKEY_AMB_SPECIAL_B ///<GB�޷��л�����
#define GBIME_INTERPUNCTION_KEY						GBKEY_AMB_SPECIAL_A ///<GB�����Ű���
#define GBIME_INTERPUNCTION_CAND_DESIRE_ROW		2 ///<GB�����ż���ѡ����
#define GBIME_INTERPUNCTION_CAND_COUNT_PER_ROW	(GBIME_DEF_MAX_CAND_WORD - 1) ///<GB�����ż�ÿ�к�ѡ����

#endif //__GBIME_DEF_H_
