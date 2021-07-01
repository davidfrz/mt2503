/*------------------------------------------------------------
  Copyright (c) 2006-2007 �����Ƽ��ɷ����޹�˾
  
  �ļ�����:
		HWAPI.h

  �����ˣ�
		�ؽ��� jhqin@hanwang.com.cn

  ��������:
		2007��1��23��

  �ؼ���:
		������ ������ OEM
------------------------------------------------------------*/
#ifndef __MTL_HWAPI_H
#define __MTL_HWAPI_H

//#define HANWANG_INTEGRATED_DICT			// �Ƿ�����ֵ伯��
#if !defined(HANWANG_LITTLEENDIAN)
#define HANWANG_LITTLEENDIAN		1	// LittleEndian or BigEndian
#endif
#define HANWANG_DEMO		//�Ƿ���ʾ�汾
/* -------------------ʶ���ַ���------------------------ */
#define ALC_LATIN_LOWERCASE				0x00000001	// Сд������ĸ
#define ALC_LATIN_UPPERCASE				0x00000002	// ��д������ĸ

#define ALC_GREEK_LOWERCASE				0x00000004	// Сдϣ����ĸ
#define ALC_GREEK_UPPERCASE				0x00000008  // ��дϣ����ĸ

#define ALC_CYRILLIC_LOWERCASE			0x00000010	// Сд�������ĸ
#define ALC_CYRILLIC_UPPERCASE			0x00000020	// ��д�������ĸ

#define ALC_COMMON_PUNCTUATION			0x00000040	// ���ñ��
#define ALC_EXTEND_PUNCTUATION			0x00000080	// ��չ���

#define ALC_COMMON_SYMBOLS				0x00000100	// ���÷���
#define ALC_EXTEND_SYMBOLS				0x00000200	// ��չ����

#define ALC_COMMON_NUMERALS				0x00000400	// ��������
#define ALC_EXTEND_NUMERALS				0x00000800	// ��չ����

#if !defined(ALC_GESTURE)
#define ALC_GESTURE						0x00001000	// Gesture 
#endif
#define ALC_EDITCOMMAND					0x00002000	// �༭������� ���� ճ�� ������

/* ----------------����Զ�ת��-------------------------- */
#define	OUT_INVERT						0x10000000	// Not used 
#if !defined(OUT_UPPERCASE)
#define OUT_UPPERCASE					0x20000000	// output Uppercase character 
#endif
#if !defined(OUT_LOWERCASE)
#define OUT_LOWERCASE					0x40000000	// output Lowercase character 
#endif
#define OUT_FULLWIDTH					0x80000000	// output SBC case 

#define ALC_LATIN		(ALC_LATIN_LOWERCASE | ALC_LATIN_UPPERCASE)			// ������ĸ
#define ALC_GREEK		(ALC_GREEK_LOWERCASE | ALC_GREEK_UPPERCASE)			// ϣ����ĸ
#define ALC_CYRILLIC	(ALC_CYRILLIC_LOWERCASE | ALC_CYRILLIC_UPPERCASE)	// �������ĸ

#define ALC_ALPHABET	(ALC_LATIN | ALC_GREEK | ALC_CYRILLIC)
#define ALC_UPPER_ALPHA (ALC_LATIN_UPPERCASE | ALC_GREEK_UPPERCASE | ALC_CYRILLIC_UPPERCASE) // ��д��ĸ
#define ALC_LOWER_ALPHA (ALC_LATIN_LOWERCASE | ALC_GREEK_LOWERCASE | ALC_CYRILLIC_LOWERCASE) // Сд��ĸ

/* ----------------define Gesture ---------------------- */
#if !defined(CODE_BACKSPACE)
#define CODE_BACKSPACE		0x0008	//BackSpace 
#endif
#if !defined(CODE_TAB)
#define CODE_TAB			0x0009	//Tab
#endif
#if !defined(CODE_RETURN)
#define CODE_RETURN			0x000D	//Return 
#endif
#if !defined(CODE_SPACE)
#define CODE_SPACE			0x0020	//Space 
#endif

#define CODE_SHIFT			0x0010	// Shift �ڲ��ı䵱ǰ�ַ��Ĵ�Сд״̬���ⲿ�������л�ʶ��Χ
#define CODE_CAPSLOCK		0x000A	// Caps Lock ���øı�����ַ��Ĵ�Сд״̬

/* ---------------�༭��������������--------------------- */
#define COMMAND_UNDO		0x1201	// ���� CTRL+Z
#define COMMAND_COPY		0x1202	// ���� CTRL+C
#define COMMAND_PASTE		0x1203	// ճ�� CTRL+V
#define COMMAND_CUT			0x1204	// ���� CTRL+X

//---------------��������----------------------------
#define HWMAXCANDNUM		10			// ���ṩ������ѡ����

#if !defined(__HWAPI_H_S)
#define HWRERAMSIZE			(14*1024)
#endif

//------------�ʼ��ṹ����-------------------
#define STROKEENDMARK		(-1)		// ����ʻ��������ֵ
#if !defined(__HWAPI_H) && !defined(__HWAPI_H_S)
typedef struct tagTHWPoint
{
	short x;//�ʼ� X ����
	short y;//�ʼ� Y ����
} THWPoint;
#endif

//------------��д��ṹ����-------------------
typedef struct tagE_THWFrame{
	short left;		// X of top left coner of handwriting frame 
	short top;		// Y of top left coner of handwriting frame 
	short width;	// width of handwriting frame 
	short height;	// Height of handwriting frame 
} E_THWFrame;

//------------����״̬����------------------
#define MODE_SINGLECHAR		1	// ����ʶ��

//------------ʶ�����Զ���------------------
#ifdef HANWANG_INTEGRATED_DICT
	typedef struct tagE_THWAttribute
	{
		unsigned short	wMode;		
		unsigned short	wLanguage;	
		unsigned long	dwRange; 
		int				iCandidateNum;	
		unsigned char*	pRam;	
		E_THWFrame		*pFrame;	
		unsigned short	*pCharSet;	
	} E_THWAttribute;
#else
	typedef struct tagE_THWAttribute
	{
		unsigned short	wMode;		// only MODE_SINGLECHAR is valid   
		unsigned short	wLanguage;	// Language which you want to recognize 
		unsigned long	dwRange; // Range,  ALC_ALPHABET is not approved because of similar 
		int				iCandidateNum;	// the number of candidate to be returned  	
		unsigned char*	pRam;	// address of RAM needed by recognition engine ,Four-byte alignment is required 
		unsigned char*	pRom;	// address of dictionary ,Four-byte alignment is required  
		E_THWFrame		*pFrame;	// handwriting frame ,set to NULL when not use frame
		unsigned short	*pCharSet;	// extended Range for current language 
	} E_THWAttribute;
#endif

//----------------������������-----------------------
#ifdef __cplusplus
extern "C" {
#endif

/*
���ܣ��ʼ�ʶ��
����˵����
	pTrace���ʼ����ݣ����ʽΪ(x1,y1),(x2,y2),...,(STROKEENDMARK,0),...,(STROKEENDMARK,0),
			(STROKEENDMARK,STROKEENDMARK)������(STROKEENDMARK,0)Ϊ�ʻ�������־��
			(STROKEENDMARK,STROKEENDMARK)Ϊ�ֽ�����־��
	pAttr��ʶ�����ԡ�
	pResult��ʶ�������������СΪ 2*HWMAXCANDNUM��ÿ����ѡ��ռ2���ֽڡ�	
����ֵ��
	-2������δ����Ȩ
	-1����������
	 0����ʶ
    >0����ѡ�ָ���	
*/
int MTL_HWRecognize( const THWPoint* pTrace, const E_THWAttribute* pAttr, unsigned short* pResult );

#ifdef __cplusplus
}
#endif

#endif
