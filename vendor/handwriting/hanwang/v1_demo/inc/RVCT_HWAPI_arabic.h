/* --------------------------------------------------------
  Copyright (c) 2006 �����Ƽ��ɷ����޹�˾
  
  File��       HWAPI.h

  �ؼ��֣��������� Unicode���� LittleEndian
------------------------------------------------------------ */

#ifndef __HWAPI_ARABIC
#define __HWAPI_ARABIC

#define HANWANG_DEMO  	//Release �汾
//#define HANWANG_DICINTEGRATION 		//�ֵ伯��
#if !defined(HANWANG_LITTLEENDIAN)
#define HANWANG_LITTLEENDIAN	1	//littleendian
#endif
/* ------------------ʶ��Χ����---------------------- */

#define ALC_ARABIC_BASIC				0x0020	// 28�������������ַ�
#define ALC_ARABIC_EXTEND				0x0040	// ��չ�������ַ�
#define ALC_ARABIC_NUMERIC				0x0080	// ������������
#define	ALC_ARABIC_SYMBOLS				0x0200  // �������ı�����


/*typedef struct tagTHWPoint
{
	short x; // �ʼ� X ����
	short y; // �ʼ� Y ����
} THWPoint;*/

/* ------------ʶ�����Զ���------------------ */
typedef struct tagTHWAttributeArabic
{
	int				iCandidateNum;	// �û���Ҫ�ĺ�ѡ�ָ���
	unsigned long	dwRange;		// ʶ��Χ����		
	unsigned char*	pRam;			// ����ռ䣬��СΪ HWRERAMSIZE��Ҫ����ʼ��ַ4�ֽڶ���
	unsigned char*	pRom;			//ʶ�����ݿ���ʼ��ַ��Ҫ��4�ֽڶ���
}THWAttributeArabic;

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
	pResult��ʶ�������������СΪ 2*MAXCANDNUM��	
����ֵ��
	= 0:��ʶ
	> 0:��ѡ�ָ���
*/
int HWRecognizeArabic( const THWPoint* pTrace, const THWAttributeArabic* pAttr, unsigned short* pResult );

#ifdef __cplusplus
}
#endif

#endif
