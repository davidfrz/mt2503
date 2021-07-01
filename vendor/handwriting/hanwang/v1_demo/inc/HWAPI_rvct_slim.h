/* --------------------------------------------------------
  Copyright (c) 2010 �����Ƽ��ɷ����޹�˾
  
  File��       HWAPI.h

  Author��John Lee  
  		lzh@hanwang.com.cn

  �ؼ��֣�
		GB2312 , BIG5
------------------------------------------------------------ */

#ifndef __HWAPI_H_S
#define __HWAPI_H_S
	
//#define  HANWANG_INTEGRATED_DICT  0  //commented as prom of E_THWAttribute got undefined      
/* ------------------ʶ��Χ����---------------------- */
#define ALC_SC_COMMON		0x00000001		/* ����һ���� */
#define ALC_SC_RARE			0x00000002		/* ��������� */
#define ALC_SC_RADICAL		0x00000080		/* ƫ�Բ��ף�ֻ�����ڼ���� */
#define ALC_NUMERIC			0x00000100		/* ���� 0-9 ) */
#define ALC_UCALPHA			0x00000200		/* ��д��ĸ( A-Z ) */
#define ALC_LCALPHA			0x00000400		/* Сд��ĸ ( a-z ) */

#define ALC_PUNC_COMMON		0x00000800		/* ���ñ�� 
												0021 !     0022 "     201C ��     201D ��  
												002C ,     003A :     003B ;     003F ?     
                                                3001 ��    3002 �� */
#define ALC_PUNC_RARE		0x00001000		/* ��չ��� 
												0027 '    0028  (    0029 )    2014 ��    
												2026 ��     3008 ��   3009 ��   300A ��   
												300B ��   */
#define ALC_SYM_COMMON		0x00002000		/* ���÷��� 
												0023 #    0024 $     0025 %      0026 &    
												002A *    002B +     002D -      002E  .    
												002F /    003C <     003D =      003E >   
												0040 @    FFE1 ��    FFE5 ��     20AC �     */
#define ALC_SYM_RARE		0x00004000		/* ��չ����
												005B  [   005C \   005D  ]     005E  ^      
                                                005F  _   0060 `   007B  {     007C  |      
                                                007D  }   007E ~   */
#define	ALC_GESTURE			0x00008000		/* ��������
											  Space(0x20), Carriage Return(0x0d), 
                                              Backspace(0x08), Table 0x0009	*/
#define ALC_CS_CURSIVE      0x00010000      /* �в��� */


/* -----------------�������----------------------------- */
#define CHARSET_CNDEFAULT		(ALC_SC_COMMON | ALC_SC_RARE)//ȱʡ��������ʶ��
#define CHARSET_SYMPUNC			(ALC_PUNC_COMMON | ALC_PUNC_RARE)//���ű��
#define CHARSET_ENGLISH			(ALC_UCALPHA | ALC_LCALPHA)//Ӣ��ʶ��

/* ----------------�������Ʊ���ֵ-------------------------- */
#define CODE_BACKSPACE			0x0008	//��ɾ
#define CODE_TAB					0x0009	//Tab
#define CODE_RETURN				0x000D	//�س�
#define CODE_SPACE				0x0020	//�ո�

/* ---------------��������---------------------------- */
#define MAXCANDNUM				10			// �����������ѡ�ָ���
#define HWRERAMSIZE				(10*1024)	// ������Ҫ����ʱ����ռ��С

/* ------------�ʼ��ṹ����------------------- */
#define STROKEENDMARK			(-1)		// ����ʻ��������ֵ

typedef struct tagTHWPoint
{
	short x; // �ʼ� X ����
	short y; // �ʼ� Y ����
} THWPoint;

typedef struct tagTHWAttribute
{
 	int				iCandidateNum;	// �û���Ҫ�ĺ�ѡ�ָ��� number of candidate
	unsigned long		dwRange;		// ʶ��Χ����		recognize range
	unsigned char*	pRam;			// ����ռ䣬��СΪ HWRERAMSIZE��Ҫ����ʼ��ַ4�ֽڶ���, ram needed, align by four bytes
	unsigned char*	pRom;	
} THWAttribute;

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
	 -1:��������
	= 0:��ʶ
	> 0:��ѡ�ָ���
*/
int HWRecognize( const THWPoint* pTrace, const THWAttribute* pAttr, unsigned short* pResult );

#ifdef __cplusplus
}
#endif

#endif
