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

#ifndef __GBIM_H__
#define __GBIM_H__

#include "gbdef.h"
#include "gbtype.h"

//remove start[2010-4-15 zhj]
//typedef GBU16							GBLANG;
//typedef GBU16							GBSUBLANG;
//typedef GBINT							GBEVENT;
//remove end[2010-4-15 zhj]

/*!
 * \defgroup Output	����Ľṹ���ö�ٶ���
 */
/*@{*/
/** 
 * \brief ����InputStructʹ�õ�˽�пռ� 16KB 
 * \note ���ֵ������������ò�һ���������û��޸�
 * - GB_ENGINE_PRIVATE_BUFFER_SIZE = max(Latin, Chn) + Syntax + Mars + �ڲ�buf
 * - Latin = 1344
 * - Chn = 3752
 * - Syntax = 6240
 * - Mars = 2480

 * - �ڲ�buf = ���� + MMI + ������ + ����
 * - ���� = 1360
 * - MMI = 704
 * - ������ = 4
 * - ���� =  4

 * - GB_ENGINE_PRIVATE_BUFFER_SIZE 8λ����
 */
#define GB_ENGINE_PRIVATE_BUFFER_SIZE		(11960)//(6 * 1024)	

/** 
 * \brief ��Ӣ������Ľ���������ʹ�õĿռ䣬1.5KB��
 * \note ���ֻʹ��Alphabetic�����������Ը�Ϊ256��
		����OEM���̲����޸�ֻ���ɹ��ʹ�˾�޸Ĳ������±�������
 */
//#define GB_INPUT_STRUCT_PRIVATE_BUFFER_SIZE	(1024 + 512)
//#define GB_INPUT_STRUCT_PRIVATE_BUFFER_SIZE	(256)//latin
#define GB_INPUT_STRUCT_PRIVATE_BUFFER_SIZE	(1024 + 512)//chn+latin

#define CUSTOM_LANGUGE_ID		0xE000
/** \enum GBLanguage
\brief language codes supported
*/	
#ifndef _C166
enum GBLanguageEnum
{
	GBL_NULL					     = 0x00,
	GBL_Afrikaans                    = 0x36,    ///< Afrikaans       �ϷǺ�����
	GBL_Albanian                     = 0x1C,    ///< Albanian        ������������
	GBL_Arabic                       = 0x01,    ///< Arabic          ��������
	GBL_Bengali                      = 0x0445,  ///< Bengali �ϼ�����
	GBL_Basque                       = 0x2D,    ///< Basque          ��˹����
	GBL_Belarusian                   = 0x23,    ///< Belarusian/Belorussian      �׶���˹��
	GBL_Bulgarian                    = 0x02,    ///< Bulgarian       ����������
	GBL_Catalan                      = 0x03,    ///< Catalan         ��̩��������
	GBL_Chinese                      = 0x04,    ///< Chinese         ��������
	GBL_Croatian                     = 0x041a,  ///< haj chg ����������������һ�� 0x1A,    ///< Croatian        ���޵�����
	GBL_Czech                        = 0x05,    ///< Czech           �ݿ���
	GBL_Danish                       = 0x06,    ///< Danish          ������
	GBL_Dutch                        = 0x13,    ///< Dutch           ������
	GBL_English                      = 0x09,    ///< English         Ӣ��
	GBL_Estonian                     = 0x25,    ///< Estonian        ��ɳ������
	GBL_Faeroese                     = 0x38,    ///< Faeroese        ������
	GBL_Farsi                        = 0x29,    ///< Farsi/Persian ��˹��
	GBL_Finnish                      = 0x0B,    ///< Finnish         ������
	GBL_French                       = 0x0C,    ///< French          ����
	GBL_Gaelic                       = 0x3C,    ///< Gaelic          �Ƕ���
	GBL_German                       = 0x07,    ///< German          ����
	GBL_Greek                        = 0x08,    ///< Greek           ϣ����
	GBL_Gujarati                     = 0x0447,  ///< Gujarati �ż�������
	GBL_Hebrew                       = 0x0D,    ///< Hebrew          ϣ������
	GBL_Hindi                        = 0x39,    ///< Hindi           ӡ����
	GBL_Hungarian                    = 0x0E,    ///< Hungarian       ��������
	GBL_Icelandic                    = 0x0F,    ///< Icelandic       ������
	GBL_Indonesian                   = 0x21,    ///< Indonesian      ӡ����������
	GBL_Italian                      = 0x10,    ///< Italian         �������
	GBL_Kannada                      = 0x044b,  ///< Kannada ���ɴ���
	GBL_Japanese                     = 0x11,    ///< Japanese        �ձ���
	GBL_Korean                       = 0x12,    ///< Korean          ����
	GBL_Khmer                        = 0x0453,  ///< Khmer ������/����կ��
	GBL_Kirgiz                       = 0x1001,//0x0440,  ///< Kirgiz �¶�������(��������ĸ)
	GBL_Kyrgyz                       = 0x0440,//CUSTOM_LANGUGE_ID + 1,  ///< Kyrgyz ������˹��(������ĸ)
	GBL_Lao                          = 0x0454,  ///< Lao ������
	GBL_Latvian                      = 0x26,    ///< Latvian         ����ά����
	GBL_Lithuanian                   = 0x27,    ///< Lithuanian      ��������
	GBL_Macedonian                   = 0x2F,    ///< Macedonian      �������
	GBL_Malayalam                    = 0x044c,  ///< Malayalam ��������ķ��
	GBL_Malaysian                    = 0x3E,    ///< Malaysian       ������
	GBL_Marathi                      = 0x044e,  ///< Marathi ��������
	GBL_Myanmar                      = 0x0455,  ///< Myanmar/Burmese �����
	GBL_Maltese                      = 0x3A,    ///< Maltese         �������
	GBL_Norwegian                    = 0x14,    ///< Norwegian       Ų����
	GBL_Pashto                       = 0x0463,  ///< Pashto ��ʲͼ��
	GBL_Polish                       = 0x15,    ///< Polish          ������
	GBL_Portuguese                   = 0x16,    ///< Portuguese      ��������
	GBL_Portuguese_SA                = 0x0416,  ///< Portuguese(South America) ������������
	GBL_Punjabi                      = 0x0446,  ///< Punjabi ��������
	GBL_Romanian                     = 0x18,    ///< Romanian        ����������
	GBL_Russian                      = 0x19,    ///< Russian         ����
	GBL_Serbian                      = 0x081a,  ///< haj chg ����������������һ��0x1A,    ///< Serbian         ����ά����
	GBL_Slovak                       = 0x1B,    ///< Slovak          ˹�工����
	GBL_Slovenian                    = 0x24,    ///< Slovenian       ˹����������
	GBL_Sorbian                      = 0x2E,    ///< Sorbian         ������
	GBL_Spanish                      = 0x0A,    ///< Spanish         ��������
	GBL_Spanish_SA                   = 0x2c0a,  ///< Spanish(South America) ������������
	GBL_Sutu                         = 0x30,    ///< Sutu            
	GBL_Swahili                      = 0x0441,  ///< Swahili ˹��������,̹ɣ���ǵĹٷ�����
	GBL_Swedish                      = 0x1D,    ///< Swedish         �����
	GBL_Tagalog                      = 0x3409,  ///< Tagalog/Philipino ���ɱ���
	GBL_Tamil                        = 0x0449,  ///< Tamil ̩�׶���
	GBL_Telugu                       = 0x044a,  ///< Telugu ̩¬����
	GBL_Thai                         = 0x1E,    ///< Thai            ̩��
	GBL_Tibetan                      = 0x0451,  ///< Tibetan ����
	GBL_Traditional_Chinese          = 0x0404,  ///< Traditional Chinese ��������(̨��)
	GBL_Tsonga                       = 0x31,    ///< Tsonga/Xitsonga      ��ϼ���
	GBL_Tswana                       = 0x32,    ///< Tswana          ��������
	GBL_Turkish                      = 0x1F,    ///< Turkish         ��������
	GBL_Uighur                       = 0x0480,  ///< Uighur ά�����
	GBL_Ukrainian                    = 0x22,    ///< Ukrainian       �ڿ�����
	GBL_Urdu                         = 0x20,    ///< Urdu            �ڶ�����
	GBL_Vietnamese                   = 0x2A,    ///< Vietnamese      Խ����
	GBL_Xhosa                        = 0x34,    ///< Xhosa           ������
	GBL_Yiddish                      = 0x3D,    ///< Yiddish         �������
	GBL_Zulu                         = 0x35,    ///< Zulu            ��³��
	GBL_Hausa                        = 0x0468,  ///< Hausa ������
	GBL_Uzbek                        = 0x0443,  ///< Uzbek ���ȱ����(Latin��ĸ)
	GBL_Yi                           = 0x0478,  ///< Yi ����
	GBL_Zhuang                       = 0x1000,//CUSTOM_LANGUGE_ID,  ///< Zhuang ׳��
	GBL_Traditional_Chinese_HK       = 0x0C04,  ///< Traditional Chinese ��������(���)
	GBL_Singapore_Chinese			 = 0x1004,  ///< Singapore Chinese ��������(�¼���)
	///<add haj ��������������
	GBL_Oriya						= 0x0448,  ///< Oriya ��������
	GBL_Assamese                    = 0x044D,  ///< Assamese ����ķ��
	GBL_Kazakh						= 0x043f,	///< ��������(˹�����ַ�)	Kazakh(Cyrillic)	
	GBL_Irish                       = 0x083c, ///< ��������	Irish / Gaelic
	GBL_Galician                    = 0x0456, ///< ����������	Galician
	GBL_Nepali                      = 0x0461, ///< �Ჴ����	Nepali
	GBL_MongolianCyrl               = 0x0450, ///< �ɹ���(˹�����ַ�)	Mongolian
	GBL_MongolianMong               = 0x0850, ///< �ɹ���(�ɹ���)
	GBL_Armenian                    = 0x042b, ///< ����������	Armenian
	GBL_Bosnian						= (CUSTOM_LANGUGE_ID+2),	///<��˹������
	GBL_Hinglish					= (CUSTOM_LANGUGE_ID+3),	///<ӡ��Ӣ��
	GBL_Kazakh_Arabic				= (CUSTOM_LANGUGE_ID+4),	///<��������������ַ���	
	GBL_Mars         				= (CUSTOM_LANGUGE_ID+5),	///<������	
	///<end haj ��������������
	// start add [2011-8-10 Zhaokun]
	GBL_Oromo				= (CUSTOM_LANGUGE_ID+6), ///<����Ī��
	GBL_Kurdish_Latin		= (CUSTOM_LANGUGE_ID+7), ///<�������
	GBL_Kurdish_Arabic		= (CUSTOM_LANGUGE_ID+8), ///<�������
	GBL_Malagasy			= (CUSTOM_LANGUGE_ID+9), ///<������˹��
	GBL_Twi					= (CUSTOM_LANGUGE_ID+10), ///<��ά��
	GBL_Kongo				= (CUSTOM_LANGUGE_ID+11), ///<�չ���
	GBL_Luganda				= (CUSTOM_LANGUGE_ID+12), ///<¬�ɴ���
	GBL_Sindhi				= (CUSTOM_LANGUGE_ID+13), ///<�ŵ���
	GBL_Azerbaijan_Latin	= 0x042c, ///<�����ݽ���
	GBL_Igbo				= 0x0470, ///<������
	GBL_Amharic				= 0x045e, ///<��ķ������
	GBL_Turkmen				= 0x0442, ///<��������
	GBL_Yoruba				= 0x046a, ///<Լ³����
	GBL_Quechua_Bolivia		= 0x046b, ///<�������Z
	GBL_Quechua_Ecuador		= 0x086b, ///<�������Z
	GBL_Kinyarwanda			= 0x0487, ///<¬������
	// end add [2011-8-10 Zhaokun]

	
	GBL_Last						 = CUSTOM_LANGUGE_ID + 0xFFF
};
#else
#define GBL_NULL					     0x00
#define GBL_Afrikaans                    0x36    ///< Afrikaans       �ϷǺ�����
#define GBL_Albanian                     0x1C    ///< Albanian        ������������
#define GBL_Arabic                       0x01    ///< Arabic          ��������
#define GBL_Bengali                      0x0445  ///< Bengali �ϼ�����
#define GBL_Basque                       0x2D    ///< Basque          ��˹����
#define GBL_Belarusian                   0x23    ///< Belarusian/Belorussian      �׶���˹��
#define GBL_Bulgarian                    0x02    ///< Bulgarian       ����������
#define GBL_Catalan                      0x03    ///< Catalan         ��̩��������
#define GBL_Chinese                      0x04    ///< Chinese         ��������
#define GBL_Croatian                     0x041a  ///< haj chg ����������������һ�� 0x1A    ///< Croatian        ���޵�����
#define GBL_Czech                        0x05    ///< Czech           �ݿ���
#define GBL_Danish                       0x06    ///< Danish          ������
#define GBL_Dutch                        0x13    ///< Dutch           ������
#define GBL_English                      0x09    ///< English         Ӣ��
#define GBL_Estonian                     0x25    ///< Estonian        ��ɳ������
#define GBL_Faeroese                     0x38    ///< Faeroese        ������
#define GBL_Farsi                        0x29    ///< Farsi/Persian ��˹��
#define GBL_Finnish                      0x0B    ///< Finnish         ������
#define GBL_French                       0x0C    ///< French          ����
#define GBL_Gaelic                       0x3C    ///< Gaelic          �Ƕ���
#define GBL_German                       0x07    ///< German          ����
#define GBL_Greek                        0x08    ///< Greek           ϣ����
#define GBL_Gujarati                     0x0447  ///< Gujarati �ż�������
#define GBL_Hebrew                       0x0D    ///< Hebrew          ϣ������
#define GBL_Hindi                        0x39    ///< Hindi           ӡ����
#define GBL_Hungarian                    0x0E    ///< Hungarian       ��������
#define GBL_Icelandic                    0x0F    ///< Icelandic       ������
#define GBL_Indonesian                   0x21    ///< Indonesian      ӡ����������
#define GBL_Italian                      0x10    ///< Italian         �������
#define GBL_Kannada                      0x044b  ///< Kannada ���ɴ���
#define GBL_Japanese                     0x11    ///< Japanese        �ձ���
#define GBL_Korean                       0x12    ///< Korean          ����
#define GBL_Khmer                        0x0453  ///< Khmer ������/����կ��
#define GBL_Kirgiz                       0x1001//0x0440  ///< Kirgiz �¶�������(��������ĸ)
#define GBL_Kyrgyz                       0x0440//CUSTOM_LANGUGE_ID + 1  ///< Kyrgyz ������˹��(������ĸ)
#define GBL_Lao                          0x0454  ///< Lao ������
#define GBL_Latvian                      0x26    ///< Latvian         ����ά����
#define GBL_Lithuanian                   0x27    ///< Lithuanian      ��������
#define GBL_Macedonian                   0x2F    ///< Macedonian      �������
#define GBL_Malayalam                    0x044c  ///< Malayalam ��������ķ��
#define GBL_Malaysian                    0x3E    ///< Malaysian       ������
#define GBL_Marathi                      0x044e  ///< Marathi ��������
#define GBL_Myanmar                      0x0455  ///< Myanmar/Burmese �����
#define GBL_Maltese                      0x3A    ///< Maltese         �������
#define GBL_Norwegian                    0x14    ///< Norwegian       Ų����
#define GBL_Pashto                       0x0463  ///< Pashto ��ʲͼ��
#define GBL_Polish                       0x15    ///< Polish          ������
#define GBL_Portuguese                   0x16    ///< Portuguese      ��������
#define GBL_Portuguese_SA                0x0416  ///< Portuguese(South America) ������������
#define GBL_Punjabi                      0x0446  ///< Punjabi ��������
#define GBL_Romanian                     0x18    ///< Romanian        ����������
#define GBL_Russian                      0x19    ///< Russian         ����
#define GBL_Serbian                      0x081a  ///< haj chg ����������������һ��0x1A    ///< Serbian         ����ά����
#define GBL_Slovak                       0x1B    ///< Slovak          ˹�工����
#define GBL_Slovenian                    0x24    ///< Slovenian       ˹����������
#define GBL_Sorbian                      0x2E    ///< Sorbian         ������
#define GBL_Spanish                      0x0A    ///< Spanish         ��������
#define GBL_Spanish_SA                   0x2c0a  ///< Spanish(South America) ������������
#define GBL_Sutu                         0x30    ///< Sutu            
#define GBL_Swahili                      0x0441  ///< Swahili ˹��������̹ɣ���ǵĹٷ�����
#define GBL_Swedish                      0x1D    ///< Swedish         �����
#define GBL_Tagalog                      0x3409  ///< Tagalog/Philipino ���ɱ���
#define GBL_Tamil                        0x0449  ///< Tamil ̩�׶���
#define GBL_Telugu                       0x044a  ///< Telugu ̩¬����
#define GBL_Thai                         0x1E    ///< Thai            ̩��
#define GBL_Tibetan                      0x0451  ///< Tibetan ����
#define GBL_Traditional_Chinese          0x0404  ///< Traditional Chinese ��������(̨��)
#define GBL_Tsonga                       0x31    ///< Tsonga/Xitsonga      ��ϼ���
#define GBL_Tswana                       0x32    ///< Tswana          ��������
#define GBL_Turkish                      0x1F    ///< Turkish         ��������
#define GBL_Uighur                       0x0480  ///< Uighur ά�����
#define GBL_Ukrainian                    0x22    ///< Ukrainian       �ڿ�����
#define GBL_Urdu                         0x20    ///< Urdu            �ڶ�����
#define GBL_Vietnamese                   0x2A    ///< Vietnamese      Խ����
#define GBL_Xhosa                        0x34    ///< Xhosa           ������
#define GBL_Yiddish                      0x3D    ///< Yiddish         �������
#define GBL_Zulu                         0x35    ///< Zulu            ��³��
#define GBL_Hausa                        0x0468  ///< Hausa ������
#define GBL_Uzbek                        0x0443  ///< Uzbek ���ȱ����(Latin��ĸ)
#define GBL_Yi                           0x0478  ///< Yi ����
#define GBL_Zhuang                       0x1000//CUSTOM_LANGUGE_ID  ///< Zhuang ׳��
#define GBL_Traditional_Chinese_HK       0x0C04  ///< Traditional Chinese ��������(���)
#define GBL_Singapore_Chinese			 0x1004  ///< Singapore Chinese ��������(�¼���)
#define GBL_Oriya						0x0448  ///< Oriya ��������
#define GBL_Assamese                    0x044D  ///< Assamese ����ķ��
#define GBL_Kazakh						0x043f	///< ��������(˹�����ַ�)	Kazakh(Cyrillic)	
#define GBL_Irish                       0x083c ///< ��������	Irish / Gaelic
#define GBL_Galician                    0x0456 ///< ����������	Galician
#define GBL_Nepali                      0x0461 ///< �Ჴ����	Nepali
#define GBL_MongolianCyrl               0x0450 ///< �ɹ���(˹�����ַ�)	Mongolian
#define GBL_MongolianMong               0x0850 ///< �ɹ���(�ɹ���)
#define GBL_Armenian                    0x042b ///< ����������	Armenian
#define GBL_Bosnian						(CUSTOM_LANGUGE_ID+2)	///<��˹������
#define GBL_Hinglish					(CUSTOM_LANGUGE_ID+3)	///<ӡ��Ӣ��
#define GBL_Kazakh_Arabic				(CUSTOM_LANGUGE_ID+4)	///<��������������ַ���	
#define GBL_Mars         				(CUSTOM_LANGUGE_ID+5)	///<������
// start add [2011-8-10 Zhaokun]
#define GBL_Oromo				(CUSTOM_LANGUGE_ID+6) ///<����Ī��
#define GBL_Kurdish_Latin		(CUSTOM_LANGUGE_ID+7) ///<�������
#define GBL_Kurdish_Arabic		(CUSTOM_LANGUGE_ID+8) ///<�������
#define GBL_Malagasy			(CUSTOM_LANGUGE_ID+9) ///<������˹��
#define GBL_Twi					(CUSTOM_LANGUGE_ID+10) ///<��ά��
#define GBL_Kongo				(CUSTOM_LANGUGE_ID+11) ///<�չ���
#define GBL_Luganda				(CUSTOM_LANGUGE_ID+12) ///<¬�ɴ���
#define GBL_Sindhi				(CUSTOM_LANGUGE_ID+13) ///<�ŵ���
#define GBL_Azerbaijan_Latin	0x042c///<�����ݽ���
#define GBL_Igbo				0x0470///<������
#define GBL_Amharic				0x045e///<��ķ������
#define GBL_Turkmen				0x0442///<
#define GBL_Yoruba				0x046a///<Լ³����
#define GBL_Quechua_Bolivia		0x046b///<�������Z
#define GBL_Quechua_Ecuador		0x086b///<�������Z
#define GBL_Kinyarwanda			0x0487///<¬������
// end add [2011-8-10 Zhaokun]

#define GBL_Last						 CUSTOM_LANGUGE_ID + 0xFFF
#endif

/** \brief ����ö�� */
enum GBSubLanguageEnum{
	GBL_Sub_Not_Spec							///<���Ƿ�������
	, GBL_Sub_Chinese							///<��½����������
	, GBL_Sub_Chinese_TW						///<����̨�����������
	, GBL_Sub_Chinese_HK						///<������۵���������
	, GBL_Sub_Chinese_Singapore					///<�¼��µ�������
	, GBL_Sub_Chinese_App						///<Ϊĳ��Ӧ��ָ���ķ�������
	, GBL_Sub_Alphabetic_MDB = 0x40				///<Alphabetic��MDB
	, GBL_Sub_Chinese_Syntax = 0x80				///<��������ݣ������������뷨����
};

#ifndef __GBInputModeEnum__
#define __GBInputModeEnum__
/*!
* \brief ���뷨ģʽ
*/
enum GBInputModeEnum 
{
	GBIM_Null
	, GBIM_Pinyin = 1							///<���ּ���ƴ�����뷨
	, GBIM_Stroke = 2							///<�ʻ����뷨
	, GBIM_Cangjie = 3							///<Qwerty���̵Ĳ�����뷨
	, GBIM_Bopomofo = 4							///<���ּ���ע�����뷨
	, GBIM_Jyutping = 5							///<���ּ����������뷨
	, GBIM_Qwerty_Pinyin						///<Qwerty���̵�ƴ�����뷨
	, GBIM_Explicit_Bopomofo					///<����Ϊע����ĸ��ע�����뷨
	, GBIM_Qwerty_Jyutping						///<Qwerty���̵��������뷨
	, GBIM_Syntax_Amb_Pinyin					///<���ּ��̵�����ƴ��
	, GBIM_Syntax_Exp_Pinyin					///<ȫ���̵�����ƴ��
	, GBIM_Half_Qwerty_Pinyin					///<Half Qwerty���̵�ƴ�����뷨
	, GBIM_Qwerty_Bopomofo						///<Qwerty���̵�ע�����뷨
	, GBIM_Chn_reserved1
	, GBIM_Chn_reserved2
	, GBIM_Chn_reserved3
	, GBIM_Chn_reserved4	
	, GBIM_Predictive							///<Numpad Predictive Alphabetic
	, GBIM_Explicit_Alphabetic					///<Explicit Alphabetic
	, GBIM_Qwerty_Alphabetic					///<Qwerty Alphabetic
	, GBIM_Half_Qwerty_Alphabetic				///<Half Qwerty Alphabetic, add by zhj 2009-8-21
	, GBIM_Alp_reserved1
	, GBIM_Alp_reserved2
	, GBIM_Alp_reserved3
	, GBIM_Alp_reserved4
	, GBIM_Alp_reserved5
	, GBIM_Number

	, GBIM_Korean							///<���ּ��̺������뷨
	//start[2010-7-27 zhj]
	, GBIM_Explicit_Korean					///<Explicit Korean
	, GBIM_Qwerty_Korean					///<Qwerty Korean
	, GBIM_Half_Qwerty_Korean				///<Half Qwerty Korean
	, GBIM_Korean_reserved1
	, GBIM_Korean_reserved2
	//end[2010-7-27 zhj]
	// Start  [2011-5-25 haj]
	, GBIM_Mars             				///<���������뷨
	, GBIM_Mars_reserved1
	, GBIM_Mars_reserved2
	// end [2011-5-25 haj]
	, GBIM_Max
};
#endif

/*!
 * \brief ��ѡ���м�ͷ��ָʾ���λ����
 */
enum GBTipArrow
{
	GBTA_Down					= 1			///<��ʾ �� ��ͷ
	, GBTA_Up					= 2			///<��ʾ �� ��ͷ
	, GBTA_Left					= 4			///<��ʾ �� ��ͷ
	, GBTA_Right				= 8			///<��ʾ �� ��ͷ
	, GBTA_Syllable_Left		= 0x10		///<Ambiguous Chinese only, ƴ����ҳ��ʾ���ͷ
	, GBTA_Syllable_Right		= 0x20		///<Ambiguous Chinese only, ƴ����ҳ��ʾ�Ҽ�ͷ
//	, GBTA_Show_Syllable_Arrow	= 0x40		///<Ambiguous Chinese only, Ŀǰƴ����ѡ��������1
	//start[2010-9-7 zhj]
	, GBTA_Syllable_Up		= 0x40		///<Ambiguous Chinese only, ƴ����ҳ��ʾ�ϼ�ͷ
	, GBTA_Syllable_Down		= 0x80		///<Ambiguous Chinese only, ƴ����ҳ�����Ҽ�ͷ
	//end[2010-9-7 zhj]
};

/*! ��ǰ����״̬ */
enum InputModeStatusFlag
{
	GBSF_Selected		= 1				///<(GBMMI)Ŀǰ��ѡ���±�״̬��API�㲻����˱��
	, GBSF_Shift		= 2				///<��ǰShift�������£�
	, GBSF_Caplock		= 4				///<��ǰCaplock�������£�
	, GBSF_OpenCand		= 8				///<��ǰ��ѡ���ڴ򿪣�API�㲻����˱��
	, GBSF_MoreCand		= 0x10			///<���и���ĺ�ѡ
	, GBSF_MoreSyllable = (1 << 5)		///<���и���ƴ������GBGetPagedSyllable API����
	, GBSF_MultiTap		= (1 << 6)		///<��ǰ����MultiTap״̬
	, GBSF_Switch_Lang  = (1 << 7)      ///<��ǰ�����޷��л�״̬ ljp

	////start[2010-4-26 zhj]
	//, GBSF_Keep_Shift_When_Input = (1<<8)		///<��ҳ���̱�������ĸ��д״̬
	//, GBSF_Keep_Cap_When_Input =  (1<<9)		///<��ҳ�����б���ȫ��д״̬
	////end[2010-4-26 zhj]
};

#ifndef __GBCandTypeEnum__
#define __GBCandTypeEnum__
enum GBCandTypeEnum{
	GBCT_Normal			///<���ݰ������еõ��ĺ�ѡ
	, GBCT_Associate	///<������
	, GBCT_Symbol		///<������
	, GBCT_MultiTap_Lower_Cap	///<MultiTap Сд����д��ĸ��ѡ
	, GBCT_MultiTap_Cap			///<��д����ĸ��ѡ
	, GBCT_MultiTap_Lower		///<Сд����ĸ��ѡ
};
#endif

/*!
 * \brief Struct to output necessary information to OEM.
 * \note After each event function invoke, engine automatically update pOutputInfo.
 */
typedef struct tagGBOutputInfo
{
	GBU16							size;			///< �ṹ��Ĵ�С
	GBU16							nFirstCandIndex;///< ��ѡ��Ӧ�ĵ�һ����ѡ�����к�ѡ���±�, Ϊ0xFFFF��ʾ�Ƿ�ֵ
	GBU16 							nCandNum;		/**< ��ѡ��ĸ��� */
	/**< ��Ҫ�������ַ���, ָ����ַ�����ʱ���ʾû����Ҫ�������ַ�, 
	�û��������֮������մ��ַ��� */
	GBWCHAR	*						pUpScreenStr;	
	GBU32							nStatusFlag;	///<���浱ǰ��״̬,  com	
	GBLPCWCHAR 						pCandidates[GB_MAX_CANDIDATES];/** (output)��ѡ�ִ�*/
} GBOutputInfo, *pGBOutputInfo;
typedef GBOutputInfo _gb_far * lpGBOutputInfo;


/*!
 * \brief ���������Ϣ�Ľṹ�� 
 */
typedef struct tagGBAuxInfo
{
	GBU16							size;		///< �ṹ��Ĵ�С
	GBU8 							nSyllableNum;/**< ��ǰҳƴ�����ڵĸ�����ƴ�������GBSetPageOption
												 ����ƴ���ķ�ҳ��Ϣ����ҳ�� �����Ҫ�������е�ƴ����ѡ��
												 ��ֻ��Ҫ��GBSetPageOption ��ƴ���ķ�ҳ����Ϊ����GB_MAX_SYLLABLES��ƴ������*/	
	GBU8 							nSyllableIndex;			/**< Ϊѡ�е�ƴ�����ڵ�ȫ������, ��ǰѡ��ƴ�����±�ΪnSyllableIndex - nSyllablePageStartIndex */	
	GBU8 							nSyllablePageStartIndex;/**< ��ǰҳ��ƴ����ʼλ��, 1��ʾ��һ��ƴ����0��ʾģ��ƥ�䣬������ЧֵΪ���ڸ���  */	
	GBU8							nUnselectedInputStringLen; ///<���Ļ�û�ж�Ӧ��ѡ�����봮���ȣ�����gb_wcslen(pUnselectedInputString)
	GBU8							nStatus ;		///< ����ģʽ�ľ���״̬,��GBMMI��API�������
	GBLPCWCHAR						pSyllables[GB_MAX_SYLLABLES];/**< (GBMMI)ƴ������ ֻ�Ǹ��ݷ�ҳ��Ϣ, (GBAPI)���п��ܵ�ƴ��*/
	GBWCHAR 						wStroke[GB_INPUT_BUFFER_LEN];/**< �ʻ������봮 */
	GBWCHAR 						wComponents[GB_COMPONET_BUFFER_LEN];/**< ���������봮 */
	GBLPCWCHAR						pOutputString;			///<�������뷨����ʵ�ʱ���Ѿ�ѡ���˵Ĵ����Լ���������봮
	GBLPCWCHAR						pUnselectedInputString;	///<�������뷨����ʵ�ʱ��û��ѡ���������봮
	///(GBMMI)Ӧ����ʾΪInline Edit�ĺ�ѡ, һ����MultiTap��MultiTap Symbols�Լ��޺�ѡ���Alphabeticģʽ��Ч
	GBLPCWCHAR						pCompStr;	
															///<����pAuxInfo->pOutputString + pAuxInfo->nSelZiCount;

	GBU32							nArrowFlags; ///<��Ǹ��ݵ�ǰ�������Ǹ�Arrow������ʾ һ�����߶��\ref GBTipArrow��ֵ��

	//������������ڶ��к�ѡ�����, ��ȫ��������
	///ÿ���к�ѡ�Ŀ�ʼλ��, pRowStart ָ��һ������ΪGB_CAND_MAX_LINE_COUNT + 1��Byte����\ref GB_CAND_MAX_LINE_COUNT
	GBPBYTE							pRowStart; //GBMMIʹ��	
	GBI8							nSelCol;		///<��ǰѡ����� GBMMIʹ��
	GBI8							nSelRow;		///<��ǰѡ����� GBMMIʹ��
	GBU8							nRowCount;		///<��ǰҳ��Ч������ GBMMIʹ��

	GBU8							nCandInputLen[GB_MAX_CANDIDATES];	///<���ĺ�ѡ�Ķ�Ӧ�İ������г���
	GBU8							nSelZiCount;    ///<�������뷨����ʵ�ʱ���Ѿ�ѡ���˵Ĵ����������Ҳ����pOutputString�ַ������ֲ��ֵĳ���

	//start[2010-6-17 zhj]
	  GBU8							nExitSelectedStatus;	///<����ѡ��״̬֮ǰ��ʲô״̬
	//end[2010-6-17 zhj]
	  //start[2010-8-16 zhj]
	  GBI16							mCurSyllableRowIndex;		///<��¼��ǰ�Ѿ��������ȡ����������
	  //end[2010-8-16 zhj]
	  // Start  [2011-4-26 haj]
	  GBLPCWCHAR						pszOutQwertyMap;        ///< Qwerty���̴洢����������ת������ַ�����		  
	  // end [2011-4-26 haj]
}GBAuxInfo, *pGBAuxInfo;
typedef GBAuxInfo _gb_far * lpGBAuxInfo;

/*!
 * \brief A necessary parameter to almost all GB API.
 */
typedef struct tagGBInputStruct 
{
	GBLANG					nLang;			///<(out)��ǰ����������. �����Ա��Ҫͨ������\ref GBSetCurLanguage���ã�
	                                        /// �ھ��󲿷ֵĺ�������֮ǰ����Ҫ���ú����Ե���Ϣ������ᵼ�²�ȷ����Ч��
	GBSUBLANG				nSubLang;		///<(out)��ǰ�ĵ��� 
	GBWCHAR					inputString[GB_INPUT_BUFFER_LEN];	///<(in)��������
	GBU8					inputStringLen;	///<(in)�������еĳ���
	GBU8					nInputMode;		///<(out)��ǰ����ģʽ
	GBU8					nCandType;		///<(in)��Ҫ�ĺ�ѡ����
	GBLPVOID				private_data;	///<(internal use)�����ڲ���Buffer���û��������
	GBU32					is_private_buffer[GB_INPUT_STRUCT_PRIVATE_BUFFER_SIZE / sizeof(GBU32)];
	GBU16					flags;			///<������λ
	GBU16					engine_private_buffer_size;		///<(in)engine_private_bufferʵ�ʵ��ֽڴ�С
	GBOutputInfo 			outputInfo;	///<(out)basic output info
	lpGBAuxInfo				pAuxInfo;		///<(out)GBMMI and Chinese additional output information.
	GBU32					engine_private_buffer[GB_ENGINE_PRIVATE_BUFFER_SIZE / sizeof(GBU32)];
} GBInputStruct;
typedef struct tagGBInputStruct _gb_far * pGBInputStruct;

//  [6/16/2009 abing]

/*!
 * \brief (�ص�����)�����ַ��������ȵĺ���
 * \param pParam �û������������GBSetPageOption�����д���
 * \param pWString ��Ҫ�����ַ�����ȵ��ַ���
 * \return �ַ����Ŀ�ȣ�0����С�����ʾʧ��
 * \author chenbinghui
 * \date 2009��7��20��
 */
typedef GBINT (* fpGetWStringWidth_t)(void * pParam, GBLPCWCHAR pWString);

/*!
 * \brief ���ĳһ���ҳ��ز���
 */
typedef struct tagGBPageOption 
{
	GBU16					nTotalWidthInPixel;		///<�ܹ���ʾ����Ŀ��
	GBU8					nCharWidthInPixel;		///<�ַ���ȣ���ͬʱ����fpGetWStringWidth��nTotalWidthInPixel�����ƣ�
													///<�Լ�fpGetWStringWidth��nCharWidthInPixel��������������ʱ������ʹ��fpGetWStringWidth��
	GBU8					nSplitWidthInPixel;		///<�ָ����Ŀ��
	GBU16					nMaxCandCountPerPage;   ///<ÿһҳ��ѡ��������
}GBPageOption;
typedef GBPageOption _gb_far * lpGBPageOption;
typedef const GBPageOption _gb_far * lpcGBPageOption;

/*!
 * \brief ����������ҳ�йصĲ���
 * \note ������Ϊ0��ʱ�򣬱�ʾ�ò�����Ч����ҳ��ʱ�򽫲����Ǹò���
 */
typedef struct tagGBGlobalPageOption 
{
	fpGetWStringWidth_t		fpGetWStringWidth;				///<�����ַ�����ȵĺ���ָ��
	GBPVOID					pGetStringWidthParam;			///<�����ַ�����ȵĺ���ָ���Ӧ�ĵ�һ��������ֵ���û��Լ�����   
	GBPageOption			mPageOption;					///<Alphabetic��ҳ����
	GBPageOption			mChnCandPageOption;				///<���ķ�ҳ����, ֻ��֧�����ĵİ汾��Ч
	GBPageOption			mSyllablePageOption;			///<Ambiguous�������ڷ�ҳ����, ֻ��֧�����ĵİ汾��Ч
}GBGlobalPageOption;
typedef GBGlobalPageOption _gb_far * lpGBGlobalPageOption;

/*!
 * \brief GBHandleEvent�����Ĳ���֮һ
 */
typedef GBU32 GBEventParam;

/*!
 * \brief ��ʾһ����������. ��nSubLang ����0��ʱ��˵�����������Ҫ������
 *        nLang ��Ӧ���������ݡ�
 */
typedef struct tagGBLDB
{
	GBLANG				nLang;		///<lang id
	GBSUBLANG			nSubLang;	///<sub lang id
	GBLPCVOID			pData;		///<data pointer
}GBLDB;

typedef GBLDB * pGBLDB;
typedef const GBLDB * pcGBLDB;
typedef const GBLDB _gb_far * lpcGBLDB;

/*!
 * \brief GBͳһ�İ汾�ţ�Ϊ4��2λ��������
 */
typedef struct tagGBVersion
{
	GBU8				v1;		///<�汾�ŵĵ�1������
	GBU8				v2;		///<�汾�ŵĵ�2������
	GBU8				v3;		///<�汾�ŵĵ�3������
	GBU8				v4;		///<�汾�ŵĵ�4������
}GBVersion;

/** \brief �������Ե��������ʾ�� */
typedef struct tagGBAlpUAWTip
{
	GBLANG				nLang;				///<Tips������
	GBLPCWCHAR			pszOKToSpell;		///<��ʾ�û��Ƿ�ʼƴд���ʣ����Ȳ��ܳ���31��Unicode
	GBLPCWCHAR			pszAddConfirm;		///<�û�ƴ�굥�ʣ���ʾ�û��Ƿ���ӣ����Ȳ��ܳ���31��Unicode
} GBAlpUAWTip;
typedef GBAlpUAWTip _gb_far * lpGBAlpUAWTip;
typedef const GBAlpUAWTip _gb_far * lpcGBAlpUAWTip;

//change start[2010-7-12 zhj]
///** \brief �����Ƿ�ʹ���������� */
//#define LANG_USE_CHINESE_ENGINE(l)		\
//	((l) == GBL_Chinese || (l) == GBL_Traditional_Chinese \
//	|| (l) == GBL_Korean || (l) == GBL_Traditional_Chinese_HK || (l) == GBL_Singapore_Chinese)

/** \brief �����Ƿ�ʹ���������� */
#define LANG_USE_CHINESE_ENGINE(l)		\
	((l) == GBL_Chinese || (l) == GBL_Traditional_Chinese \
	|| (l) == GBL_Traditional_Chinese_HK || (l) == GBL_Singapore_Chinese)
//change end[2010-7-12 zhj]

//start[2010-7-12 zhj]
/** \brief �����Ƿ�ʹ�ú������� */
#define LANG_USE_KOREAN_ENGINE(l)		\
	((l) == GBL_Korean)
//end[2010-7-12 zhj]

// Start add [2011-5-25 haj]
/** \brief �����Ƿ�ʹ�û��������� */
#define LANG_USE_MARS_ENGINE(l)		\
	((l) == GBL_Mars)
// end [2011-5-25 haj]

/** \brief �����Ƿ�ʹ��Alphabetic���� */
//change start[2010-7-12 zhj]
//#define LANG_USE_ALP_ENGINE(l)	(!LANG_USE_CHINESE_ENGINE(l))
// Start modify [2011-5-25 haj]
//#define LANG_USE_ALP_ENGINE(l)	(!LANG_USE_CHINESE_ENGINE(l) && !LANG_USE_KOREAN_ENGINE(l))
#define LANG_USE_ALP_ENGINE(l)	(!LANG_USE_CHINESE_ENGINE(l) && !LANG_USE_KOREAN_ENGINE(l) && !LANG_USE_MARS_ENGINE(l))
// end [2011-5-25 haj]
//change end[2010-7-12 zhj]

/** \brief ����ģʽ�Ƿ�ʹ��Alphabetic���� */
#define INPUT_MODE_USE_ALP_ENGINE(im)	\
	((im) == GBIM_Predictive || (im) == GBIM_Explicit_Alphabetic \
	 || (im) == GBIM_Qwerty_Alphabetic ||(im) == GBIM_Half_Qwerty_Alphabetic)

/** \brief ����ģʽ�Ƿ�ʹ���������� */
#define INPUT_MODE_USE_CHN_ENGINE(im)	\
	((im) == GBIM_Pinyin || (im) == GBIM_Stroke || (im) == GBIM_Cangjie \
	 || (im) == GBIM_Bopomofo || (im) == GBIM_Jyutping /* haj del 20110622|| (im) == GBIM_Korean*/ \
	 || (im) == GBIM_Qwerty_Pinyin || (im) == GBIM_Explicit_Bopomofo || (im) == GBIM_Qwerty_Jyutping \
	 || (im) == GBIM_Syntax_Exp_Pinyin || (im) == GBIM_Half_Qwerty_Pinyin \
	 || (im) == GBIM_Qwerty_Bopomofo \
	 || (im) == GBIM_Syntax_Amb_Pinyin /*!haj add 20110622*/)

/** \brief ����ģʽ�Ƿ���ģ�����������뷨��ģ�����������뷨�Ŵ���ƴ���ĺ�ѡ */
#define INPUT_MODE_IS_AMB_CHN(im)	\
	((im) == GBIM_Pinyin || (im) == GBIM_Bopomofo || (im) == GBIM_Jyutping \
	|| (im) == GBIM_Syntax_Amb_Pinyin || (im) == GBIM_Half_Qwerty_Pinyin \
	|| (im) == GBIM_Qwerty_Bopomofo)

/** \brief ����ģʽ�Ƿ���QWERTY���������뷨��QWERTY���������뷨��Ҫ��ʾfullOutputString���� */
#define INPUT_MODE_IS_QWERTY_CHN(im)	\
	((im) == GBIM_Cangjie || (im) == GBIM_Syntax_Exp_Pinyin || (im) == GBIM_Qwerty_Pinyin \
	|| (im) == GBIM_Explicit_Bopomofo || (im) == GBIM_Qwerty_Jyutping || (im) == GBIM_Qwerty_Bopomofo)

/** \brief ����ģʽ�Ƿ���qwerty����explicit */
#define INPUT_MODE_IS_QWERTY_OR_EXPLICIT(im)	\
	(INPUT_MODE_IS_QWERTY_CHN(im) \
	|| (im) == GBIM_Qwerty_Alphabetic || (im) == GBIM_Explicit_Alphabetic)

/** \brief ��ǰ��pGBIS����������Լ�����ģʽ�Ƿ���ʹ��Alphabetic���� */
#define GBIS_USE_ALP_ENGINE(p)		\
	(LANG_USE_ALP_ENGINE((p)->nLang) && INPUT_MODE_USE_ALP_ENGINE((p)->nInputMode))

/** \brief ��ǰ��pGBIS����������Լ�����ģʽ�Ƿ���ʹ��Chinese���� */
#define GBIS_USE_CHN_ENGINE(p)		\
	(LANG_USE_CHINESE_ENGINE((p)->nLang) && INPUT_MODE_USE_CHN_ENGINE((p)->nInputMode))

/** \brief ��ǰ״̬������������Ƿ��и����ѡ */
#define GBIS_HAVE_MORE_CAND(p)	\
	((p)->outputInfo.nStatusFlag & GBSF_MoreCand)

/** \brief ���뷨�Ƿ�ʹ���������� */
#define GBIS_USE_SYNTAX_ENGINE(im)	\
	((im) == GBIM_Syntax_Amb_Pinyin || (im) == GBIM_Syntax_Exp_Pinyin)


/** \brief ��ͨ���ַ����� */
#define EVENT_IS_NORMAL_CHAR_KEY(e)	\
	(((e) >= GBKEY_0 && (e) <= GBKEY_9) \
	|| ((e) >= GBKEY_A && (e) <= GBKEY_Z) \
	|| ((e) >= GBKEY_BPMF_B && (e) <= GBKEY_BPMF_IU))


/** \brief ��ǰ״̬���Ƿ���ܴ������ں�ѡ */
#define GBIS_HaveSyllableSelection(p) \
	((p)->nCandType == GBCT_Normal && (p)->inputStringLen > 0 && INPUT_MODE_IS_AMB_CHN((p)->nInputMode))

/** \brief ���봮�Ƿ��Ѿ����� */
#define GBIS_InputStringUpdated(p)		((p)->flags & GBIS_INPUT_STRING_UPDATED)

/** \brief ����GBIS��Updated Flags������pGBIS->inputString��Ҫ���� */
#define GBIS_SetInputStringUpdated(p)	((p)->flags |= GBIS_INPUT_STRING_UPDATED)

/** \brief ���GBIS��Updated Flags */
#define GBIS_ClearInputStringUpdated(p)	((p)->flags &= ~(GBU16)GBIS_INPUT_STRING_UPDATED)

/** \brief �û�ʹ��SelectSyllable�����������ѡ�� */
#define GBIS_SyllableIndexUpdated(p)	((p)->flags & GBIS_SYLLABLE_INDEX_UPDATED)

//Add by ZhaoKun at 2011/1/12 9:31:05 [Start]
/** \brief ������������ */
#define GBIS_SetSyllableToneUpdated(p)	((p)->flags |= GBIS_SYLLABLE_TONE_UPDATED)
//Add by ZhaoKun at 2011/1/12 9:31:05 [End]

#define GBIS_UpdateFlags (GBIS_INPUT_STRING_UPDATED | GBIS_SYLLABLE_INDEX_UPDATED | GBIS_SELECTED_CANDIDATE | GBIS_SYLLABLE_TONE_UPDATED)
#define GBIS_ClearUpdatedFlags(p)		\
	((p)->flags &= ~(GBU16)GBIS_UpdateFlags)

#define GBIS_HaveUpdateFlag(p)	((p)->flags & GBIS_UpdateFlags)

/** \brief �����±��Ƿ��Ѿ������� */
#define GBIS_HaveUpdateSyllableFlag(p)		((p)->flags & (GBIS_INPUT_STRING_UPDATED | GBIS_SELECTED_CANDIDATE))

/** \brief ��ǰ�Ƿ�MultiTap���뷨 */
#define GBIS_IsMultiTapInputMode(p)			((p)->nCandType == GBCT_MultiTap_Lower_Cap \
		|| (p)->nCandType == GBCT_MultiTap_Cap \
		|| (p)->nCandType == GBCT_MultiTap_Lower)
/** \brief �Ƿ���ڸ���ĺ�ѡ */
#define GBIS_HaveMoreCand(p)		((p)->outputInfo.nStatusFlag & GBSF_MoreCand)
/** \brief �Ƿ���ڸ�������� */
#define GBIS_HaveMoreSyllable(p)	((p)->outputInfo.nStatusFlag & GBSF_MoreSyllable)
/** \brief ����GBNextPageCandidate�ĵڶ������� */
#define GBIS_GetNextPageStart(p)	((p)->outputInfo.nFirstCandIndex + (p)->outputInfo.nCandNum)
/** \brief ����GBPrevPageCandidate�ĵڶ������� */
#define GBIS_GetPrevPageEnd(p)		((p)->outputInfo.nFirstCandIndex - 1)

/** \brief ��ǰ״̬�Ƿ��ܹ��·�ҳ */
#define GBIS_HaveNextPage(p)			GBIS_HaveMoreCand(p)
/** \brief ��ǰ״̬�Ƿ��ܹ��Ϸ�ҳ */
#define GBIS_HavePrevPage(p)			((p)->outputInfo.nFirstCandIndex > 0 && (p)->outputInfo.nFirstCandIndex != 0xFFFF)

/** \brief ��������ģʽ */
#define GBIS_Is_Chn_IM(p)			((p)->nInputMode >= GBIM_Pinyin && (p)->nInputMode <= GBIM_Chn_reserved4)

/** \brief Alphabetic����ģʽ */
#define GBIS_Is_Alp_IM(p)			((p)->nInputMode >= GBIM_Predictive && (p)->nInputMode <= GBIM_Alp_reserved5)

/** \brief Alphabetic����ģʽ */
#define GBIS_Is_Korean_IM(p)			((p)->nInputMode >= GBIM_Korean && (p)->nInputMode <= GBIM_Half_Qwerty_Korean)

/** \brief ��ǰ״̬�Ƿ���ʾ��ѡ�� */
#define GBIS_IS_CAND_OPEN(p)		((p)->outputInfo.nStatusFlag & GBSF_OpenCand)

/** \brief ��ѡ�Ƿ���ѡ��״̬ */
#define GBIS_IS_CAND_SELECTED(p) ((p)->outputInfo.nStatusFlag & GBSF_Selected)

/** \brief �жϵ�ǰ�����Ƿ���ע���������� Zhaokun 2011-1-12 add */
#define IS_BPMF_TONE_KEY(evt)	((evt) == GBKEY_BPMF_TONE_NULL \
	|| (evt) == GBKEY_BPMF_TONE_1 \
	|| (evt) == GBKEY_BPMF_TONE_2 \
	|| (evt) == GBKEY_BPMF_TONE_3 \
	|| (evt) == GBKEY_BPMF_TONE_4 \
	|| (evt) == GBKEY_BPMF_TONE_5)

// start add [ 2011-3-8 haj for Alpha GBCT_Associate]
/** \brief �жϵ�ǰ�Ƿ���Alpha���뷨����״̬��*/
#define GBIS_IS_ALP_ASSOCIATE(p) \
	(GBIS_USE_ALP_ENGINE((p)) && GBCT_Associate == (p)->nCandType)

/** \brief �жϵ�ǰ�Ƿ���Alpha���뷨���빦���Ƿ��*/
#define GBIS_ALP_ASSOCIATE_OPEN(p) \
	(GBIS_USE_ALP_ENGINE((p)) && HAVE_OPTION((p), GBFO_Alp_Open_Associat))

/** \brief ������봮���� */
#define GBIS_CLEAR_INPUT_STRING(p) \
	(p)->inputString[0] = 0; \
	(p)->inputStringLen = 0;	
// end add [ 2011-3-8 haj ]
// start add [2011-5-10 haj]
/*!
  * \brief �Ƿ���ҪAlpha����ĸ��ѡ����
  * \brief ��ΪExplicit��ѡ�в����ڵ�����ĸ��ѡ��Сдͬʱ���ڵ��������Ӧ��GBFO_Alp_Get_Only_Lower �� GBFO_Alp_Get_Only_Cap���ÿ���
  */
	// start add [2011-3-10 haj for Alpha GBCT_Associate]
	// start GBIM_Explicit_Alphabetic ���봮����Ϊ1�ʹ���1��Ӧ�������Сд�л� [2011-5-10 haj]
#define GBIS_IS_NEED_ALP_ONLY_CONFIG(p) \
	(!GBIS_IS_ALP_ASSOCIATE(p) \
	&& (p)->nInputMode != GBIM_Explicit_Alphabetic \
	&& (p)->inputStringLen == 1)
	// end add [2011-3-10 haj]
	// end  [2011-5-10 haj]
// end [2011-5-10 haj]
// Start add [2011-5-31 haj]
/** \brief �жϵ�ǰ�Ƿ���Alpha���뷨���빦���Ƿ��*/
#define GBIS_IS_OPEN_CHN_2_MARS(p) \
	(INPUT_MODE_USE_CHN_ENGINE((p)->nInputMode) && (HAVE_OPTION((p), GBFO_Open_Chn_2_Mars)))
// end [2011-5-31 haj]
// Start Add [2011-8-2 haj]
/** \brief ���outputInfo.pUpScreenStr ���ݣ�ͬ�����EHF_UPSCREEN��־ */
#define GBIS_CLEAN_UPSCREENSTR(p) \
	(p)->outputInfo.pUpScreenStr = NULL; \
	IMS(p)->nEventHandleFlag &= ~EHF_UPSCREEN;
// end [2011-8-2 haj]
/*@}*/

#endif

