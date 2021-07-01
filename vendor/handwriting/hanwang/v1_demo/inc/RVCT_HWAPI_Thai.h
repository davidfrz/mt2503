/* ------------------------------------------------------------
  Copyright (C) �����Ƽ��ɷ����޹�˾, 2006
  
  File:       HWAPI.h

  �����ߣ��ؽ��� jhqin@hanwang.com.cn

  ���ڣ�2006��8��8��

  �ؼ��֣�Ӣ�ģ�̩�İ� UNICODE���� �����ֵ伯��
------------------------------------------------------------ */

#ifndef __THAI_HWAPI_H
#define __THAI_HWAPI_H
//#define HANWANG_DICINTEGRATION				//�ֵ伯��
#define HANWANG_DEMO  

/* -----------ʶ��Χ--------------- */
#define ALC_THAICON			0x00000001     // Thai Consonant 0x0E01 ~ 0x0E2E
#define ALC_THAIVOW			0x00000002     // Thai Vowel     0x0E30 ~ 0x0E3A, 0X0E40 ~0x0E44, 0x0E47
#define ALC_THAISIGN		0x00000004     // Thai Sign      0x0E2F, 0x0E45, 0x0E46, 0x0E5A, 0x0E5B, 0x0E4C ~ 0x0E4F
#define ALC_THAIDIGI		0x00000008     // Thai Digit     0x0E50 ~ 0x0E59
#define ALC_THAITONE		0x00000010     // Thai ToneMark  0x0E48 ~ 0x0E4B 
#define ALC_THAICUR			0x00000020     // Thai Currency  0x0E3F

#if !defined(ALC_UCALPHA)
#define ALC_UCALPHA			0x00000040		//Uppercase Latin characters ( A-Z ) 
#endif
#if !defined(ALC_LCALPHA)
#define ALC_LCALPHA			0x00000080		//Lowercase Latin characters ( a-z ) 	
#endif

#if !defined(ALC_NUMERIC)
#define ALC_NUMERIC			0x00000100		//Number ( 0-9 ) 	
#endif

#define ALC_PUNCTUATION		0x00000200		/* punctuation marks 
                                                !	0021	Exclamation����̾�ţ�
                                                "	0022	Double Quotation Marks��˫���ţ�
                                                ,	002C	Comma�����ţ�
                                                ��	003A	Colon��ð�ţ�
                                                ��	003B	Semicolon���ֺţ�
                                                ?	003F	Question Mark���ʺţ�
                                                '	0027	Single Quotation Marks�������ţ�
                                                (	0028	Left Bracket����Բ���ţ�
                                                )	0029	Right Bracket����Բ���ţ�
                                                */
#define ALC_SYMBOL          0x00000400      /* Symbols
                                                #	0023	Number�����ţ�
                                                $	0024	Dollar����Ԫ���ţ�
                                                %	0025	Percent Sign ���ٷֱȷ��ţ�
                                                &	0026	Ampersand������ţ�
                                                *	002A	Asterisk ���Ǻţ�
                                                +	002B	Plus Sign���Ӻţ�
                                                -	002D	Subtraction Sign�����ţ�
                                                .	002E	Dot���㣩
                                                /	002F	Virgule��б�ߺţ�
                                                <	003C	Is less than Sign��С�ںţ�
                                                =	003D	Is less than�����ںţ�
                                                >	003E	Is more than�����ںţ�
                                                @	0040	AT�����ۺţ�
                                                ��	005B	Left square brackets�������ţ�
                                                ��	005D	Right square brackets���ҷ����ţ�
                                                \	005C	Backlash����б�ߣ�
                                                _	005F	Underline���»��ߣ�
                                                `	0060	Apostrophe�����и���ţ�
                                                ��	007B	��������ţ�
                                                ��	007D	���Ҵ����ţ�
                                                |	007C	
                                                ~	007E	Swung dash�����ֺţ�
                                                */
#if !defined(ALC_GESTURE)                                                
#define	ALC_GESTURE			0x00000800		/* Control gesture
											  Space(0x20), Carriage Return(0x0d), 
                                              Backspace(0x08), Toggle 0x0010	*/
#endif

//-----------------����Զ�ת��-------------------------------------
#if !defined(OUT_LOWERCASE)
#define OUT_LOWERCASE		0x20000000	//output Lowercase character 
#endif
#if !defined(OUT_UPPERCASE)
#define OUT_UPPERCASE		0x40000000	//output Uppercase character 
#endif
#if !defined(OUT_FULLWIDTH)
#define OUT_FULLWIDTH		0x80000000	//output SBC case 
#endif
#if !defined(OUT_ASSISTANT)
#define OUT_ASSISTANT		(OUT_LOWERCASE | OUT_UPPERCASE | OUT_FULLWIDTH)
#endif

//-----------------�������-----------------------------------------
#if !defined(CHARSET_ENGLISH)
#define CHARSET_ENGLISH			(ALC_UCALPHA | ALC_LCALPHA)			//Latin characters 
#endif
#define CHARSET_THAILAND		(ALC_THAICON | ALC_THAIVOW | ALC_THAISIGN | ALC_THAIDIGI | ALC_THAITONE | ALC_THAICUR) //Thai characters 

/* ----------------�������Ʊ���ֵ------------------------------- */
#if !defined(CODE_BACKSPACE)
#define CODE_BACKSPACE			0x0008	//Backspace 
#endif
#if !defined(CODE_TOGGLE)
#define CODE_TOGGLE				0x0010	//Toggle 
#endif
#if !defined(CODE_RETURN)
#define CODE_RETURN				0x000D	//Return 
#endif
#if !defined(CODE_SPACE)
#define CODE_SPACE				0x0020	//Space 
#endif

//---------------��������----------------------------
#if !defined(MAXCANDNUM)
#define MAXCANDNUM				10			// maximal number of candidates 
#endif
#if !defined(HWRERAMSIZE)
#define HWRERAMSIZE				(14*1024)	// RAM needed by recognition engine for running 
#endif

//------------�ʼ��ṹ����-------------------
#define STROKEENDMARK			(-1)		// ����ʻ��������ֵ
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
//------------ʶ�����Զ���------------------
typedef struct Thai_tagTHWAttribute
{
	unsigned long	dwRange;	// Range of Recognize 
	int	iCandidateNum;	// number of candidates to be returned 
	int	iBoxWidth;		// Width of handwriting frame,set a value less than or equal to Zero if not use.
	int	iBoxHeight;		// Height of handwriting frame,set a value less than or equal to Zero if not use.
	unsigned char*	pRam;		// RAM needed by recognition engine for running. It may be HWRERAMSIZE Bytes ,and align by 4 bytes .
	unsigned char*  pRom;		//address of dictionary, align by 4 bytes.
} Thai_THWAttribute;

#ifdef __cplusplus
extern "C" {
#endif

/*
���ܣ��ʼ�ʶ��
����˵����
	pTrace���ʼ����ݣ����ʽΪ(x1,y1),(x2,y2),...,(STROKEENDMARK,0),...,
	        (STROKEENDMARK,0),(STROKEENDMARK,STROKEENDMARK)��
			����(STROKEENDMARK,0)Ϊ�ʻ�������־��
			(STROKEENDMARK,STROKEENDMARK)Ϊ�ֽ�����־��
	pAttr��ʶ�����ԡ�
	pResult��ʶ�������仺������СΪ HWRESULTBUFSIZE��	
����ֵ��
	=-1:���������ռ�
	= 0:��ʶ
	> 0:��ѡ�ָ���
*/
int THAI_HWRecognize( const THWPoint* pTrace, const Thai_THWAttribute* pAttr, unsigned short* pResult );

#ifdef __cplusplus
}
#endif

#endif
