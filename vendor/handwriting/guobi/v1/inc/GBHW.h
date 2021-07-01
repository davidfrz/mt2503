#ifndef __GBHW_H__
#define __GBHW_H__

//�������Ա�������(ǰ5����Ϊ�˺����ļ���)
#define GBHW_LATIN_RANGE_NUMBER					0x00010000
#define GBHW_LATIN_RANGE_EN_LOWER				0x00020000
#define GBHW_LATIN_RANGE_EN_UPPER				0x00040000
#define GBHW_LATIN_RANGE_ASC_PUNCTUATION		0x00080000
#define GBHW_LATIN_RANGE_CONTROL_CHAR			0x20000000
#define GBHW_LATIN_RANGE_EN_SPACING				0x10000000
#define GBHW_LATIN_RANGE_A		(GBHW_LATIN_RANGE_EN_LOWER | GBHW_LATIN_RANGE_EN_UPPER | GBHW_LATIN_RANGE_EN_SPACING)
#define GBHW_LATIN_RANGE_B						0x00100000
#define GBHW_LATIN_RANGE_C						0x00200000
#define GBHW_LATIN_RANGE_D						0x00400000
#define GBHW_LATIN_RANGE_E						0x00800000
#define GBHW_LATIN_RANGE_F						0x01000000
#define GBHW_LATIN_RANGE_G						0x02000000
#define GBHW_LATIN_RANGE_H						0x04000000
#define GBHW_LATIN_RANGE_I						0x08000000
#define GBHW_LATIN_RANGE_J						0x40000000
#define GBHW_LATIN_RANGE_K						0x80000000

//[��������]
//ʶ��Χ������
#define GBHW_OPT_RANGE_NUMBER				0x1
//ʶ��Χ��Сд��ĸ
#define GBHW_OPT_RANGE_LOWER_CHAR			0x2
//ʶ��Χ����д��ĸ
#define GBHW_OPT_RANGE_UPPER_CHAR			0x4
//ʶ��Χ����Ǳ�����
#define GBHW_OPT_RANGE_ASC_PUNCTUATION		0x8
//ʶ��Χ��ASCII�룬�������֡�Сд��ĸ����д��ĸ�Ͱ�Ǳ�����
#define GBHW_OPT_RANGE_ASCII				(GBHW_OPT_RANGE_NUMBER | GBHW_OPT_RANGE_LOWER_CHAR | GBHW_OPT_RANGE_UPPER_CHAR | GBHW_OPT_RANGE_ASC_PUNCTUATION)
//ʶ��Χ��GB2312����
#define GBHW_OPT_RANGE_GB2312				0x8000 
//ʶ��Χ��BIG5����
#define GBHW_OPT_RANGE_BIG5					0x200
//ʶ��Χ��GBK����
#define GBHW_OPT_RANGE_GBK					0x400
//ʶ��Χ�����ı�����
#define GBHW_OPT_RANGE_CHN_PUNCTUATION		0x800
//ʶ��Χ��GB18030-2003���涨�ĺ���
#define GBHW_OPT_RANGE_GB18030				0x1000
//ʶ��Χ���ո񡢻س��Լ�ɾ�������������ַ�
#define GBHW_OPT_RANGE_CONTROL_CHAR			0x2000

#define GBHW_OPT_RANGE_PUNCTUATION	(GBHW_OPT_RANGE_ASC_PUNCTUATION | GBHW_OPT_RANGE_CHN_PUNCTUATION)

//ʶ��Χ��Ĭ��ʶ��Χ��ΪGB2312���֡����֡���ĸ�ͱ����š����������Ʒ���
#define GBHW_OPT_RANGE_DEFAULT				(GBHW_OPT_RANGE_GB2312 | GBHW_OPT_RANGE_ASCII | GBHW_OPT_RANGE_PUNCTUATION)

/*************************************************����ע���**********************************************/
//ע�⣺�������ϵĸ���[ʶ��Χ]�� ��Ӧ�����������ݡ���ʹ����������ʱ����ѡ�����ϵ�ѡ�������������ѡ�ķ�Χ����ʱ���治�����16λ��
//ע�⣺�������µĸ���[ʶ��Χ]�� ��Ӧ�����������ݡ���ʹ����������ʱ����ѡ�����µ�ѡ�������������ѡ�ķ�Χ����ʱ���治�����16λ��

//[��������]
//ʶ��Χ������
#define GBHW_OPT_RANGE_LATIN_NUMBER					(GBHW_LATIN_RANGE_NUMBER)
//ʶ��Χ����Ǳ�����
#define GBHW_OPT_RANGE_LATIN_ASC_PUNCTUATION		(GBHW_LATIN_RANGE_ASC_PUNCTUATION)
//ʶ��Χ���ո񡢻س��Լ�ɾ�������������ַ�
#define GBHW_OPT_RANGE_LATIN_CONTROL_CHAR			(GBHW_LATIN_RANGE_CONTROL_CHAR)
//ʶ��Χ��English	Kurdish		Malagasy	Kinyarwanda		Irish		Zulu	  Zhuang	Oromo	Indonesian
//          Ӣ��    �������    �������    ������¬������  ��������   ��³��	  ׳��      ����Ī	ӡ��������
#define GBHW_OPT_RANGE_A_LANGUAGES					(GBHW_LATIN_RANGE_A)
//ʶ��Χ��GBHW_OPT_RANGE_A_LANGUAGES��Ӧ���Ե�Сд
#define GBHW_OPT_RANGE_A_LANGUAGES_LOWER			(GBHW_LATIN_RANGE_EN_LOWER)
//ʶ��Χ��GBHW_OPT_RANGE_A_LANGUAGES��Ӧ���ԵĴ�д
#define GBHW_OPT_RANGE_A_LANGUAGES_UPPER			(GBHW_LATIN_RANGE_EN_UPPER)
//ʶ��Χ��Portuguese	portuguese_sa	Finnish	Swedish	Tagalog
//          ��������    ��������(sa)	������	���	���ɱ���
#define GBHW_OPT_RANGE_B_LANGUAGES					(GBHW_LATIN_RANGE_A | GBHW_LATIN_RANGE_H)
//ʶ��Χ��Vietnamese	Azerbaijiani
//          Խ��		�����ݽ�
#define GBHW_OPT_RANGE_C_LANGUAGES					(GBHW_LATIN_RANGE_A | GBHW_LATIN_RANGE_H | GBHW_LATIN_RANGE_I | \
													 GBHW_LATIN_RANGE_J | GBHW_LATIN_RANGE_K)
//ʶ��Χ��Croatian	Czech	Polish	Romanian	Serbian		Yoruba
//          ���޵���	�ݿ���	������	��������	����ά��	Լ³��
#define GBHW_OPT_RANGE_D_LANGUAGES					(GBHW_LATIN_RANGE_A | GBHW_LATIN_RANGE_I | GBHW_LATIN_RANGE_J)
//ʶ��Χ��French	Afrikaans
//			����	�Ϸ���
#define GBHW_OPT_RANGE_E_LANGUAGES					(GBHW_LATIN_RANGE_A | GBHW_LATIN_RANGE_B | GBHW_LATIN_RANGE_F | \
	                                                 GBHW_LATIN_RANGE_G | GBHW_LATIN_RANGE_H | GBHW_LATIN_RANGE_I)
//ʶ��Χ��Hinglish	Bosnian		Uzbek		Catalan		Malaysian
//						��˹����	���ȱ��	��̩������	��������
#define GBHW_OPT_RANGE_F_LANGUAGES					(GBHW_LATIN_RANGE_A | GBHW_LATIN_RANGE_B | GBHW_LATIN_RANGE_C)
//ʶ��Χ��Danish	Duch	Estonian	German	Spanish	Spanish_sa	Swahili
//			����	�ź�	��ɳ������	����	������	������(sa)	˹��ϣ��
//			Norwegian	Hausa	Basque	Italian	Albanian	Turkmen	Turkish
//			Ų��		����	��˹��	�����	����������	������	������
#define GBHW_OPT_RANGE_G_LANGUAGES					(GBHW_LATIN_RANGE_A | GBHW_LATIN_RANGE_B | GBHW_LATIN_RANGE_C | \
	                                                 GBHW_LATIN_RANGE_D | GBHW_LATIN_RANGE_E | GBHW_LATIN_RANGE_F | \
	                                                 GBHW_LATIN_RANGE_G | GBHW_LATIN_RANGE_H)
//ʶ��Χ��Hungarian	Latvian
//			������		����ά��
#define GBHW_OPT_RANGE_H_LANGUAGES					(GBHW_LATIN_RANGE_A | GBHW_LATIN_RANGE_B | GBHW_LATIN_RANGE_C | \
													 GBHW_LATIN_RANGE_D | GBHW_LATIN_RANGE_E | GBHW_LATIN_RANGE_F | \
													 GBHW_LATIN_RANGE_G | GBHW_LATIN_RANGE_H | GBHW_LATIN_RANGE_I | \
													 GBHW_LATIN_RANGE_J)
//ʶ��Χ��Lithuanian	Slovak		Slovenian
//			������		˹�工��	˹��������
#define GBHW_OPT_RANGE_I_LANGUAGES					(GBHW_LATIN_RANGE_A | GBHW_LATIN_RANGE_B | GBHW_LATIN_RANGE_C | \
													 GBHW_LATIN_RANGE_I | GBHW_LATIN_RANGE_J)
//ʶ��Χ��Icelandic
//			����
#define GBHW_OPT_RANGE_J_LANGUAGES					(GBHW_LATIN_RANGE_A | GBHW_LATIN_RANGE_B | GBHW_LATIN_RANGE_C | \
													 GBHW_LATIN_RANGE_D | GBHW_LATIN_RANGE_E | GBHW_LATIN_RANGE_F | \
													 GBHW_LATIN_RANGE_G | GBHW_LATIN_RANGE_H | GBHW_LATIN_RANGE_I | \
													 GBHW_LATIN_RANGE_J | GBHW_LATIN_RANGE_K)


//����6����Ϊ�˼�����ǰ�汾��2012��08��16��֮���벻Ҫ��ʹ������6��
#define GBHW_OPT_FRENCH				GBHW_OPT_RANGE_E_LANGUAGES//0x10000	//����
#define GBHW_OPT_GERMAN				GBHW_OPT_RANGE_G_LANGUAGES//0x20000	//����
#define GBHW_OPT_SPANISH			GBHW_OPT_RANGE_G_LANGUAGES//0x30000	//������
#define GBHW_OPT_ITALIAN			GBHW_OPT_RANGE_G_LANGUAGES//0x40000	//��̫��
#define GBHW_OPT_TURKISH			GBHW_OPT_RANGE_G_LANGUAGES//0x50000	//������
#define GBHW_OPT_PORTUGUESE			GBHW_OPT_RANGE_B_LANGUAGES//0x60000	//������

#ifndef GBAPI
#ifdef GBIMPORT
#define GBAPI  __declspec(dllimport)
#else
#define GBAPI	extern
#endif
#endif

#ifdef __cplusplus
extern "C"{
#endif

enum GB_HW_Fail {
	GBHW_OK = 0
		, GBHW_Err_Begin = -1000
		, GBHW_Err_Not_Init
		, GBHW_Err_Init_Null_Data //������
		, GBHW_Err_Init_Invalid_Data //���ݸ�ʽ����
		, GBHW_Err_Recg_Invalid_Result_Len //Ҫ��ĺ�ѡ��Ŀ����
		, GBHW_Err_Init_Invalid_Dim //���������ݵ�ά��������Χ
		, GBHW_Err_Option_Invalid_Speed //GBHWSetOption��������GBHW_Index_Set_Speed��ʱ��param����������Чֵ
		, GBHW_Err_Option_Invalid_Index //GBHWSetOption����index������Ч
		, GBHW_Err_Winguo_Verify_No_Match//GBHWNew(��GBHWNewFile)�������أ���ʾ�ʹ���֤�����
		, GBHW_Err_Cluster_Prototypes //GBHWNewFile�������أ���ʾ������������Ŀ������������ֵ
};

enum GB_HW_Option_Index {
	GBHW_Invalid_Index = 0
		/*
		valueΪ0��ʱ������ΪĬ�ϵ��ٶ�
		valueֵԽ�����ٶ�Խ����׼ȷ��Խ�ߣ�
		��֮�ٶ�Խ�죬׼ȷ��Խ�ͣ�
		��Ч����Ϊ[5, 30]
		���������Ҫ����������֮��(GBHWNew)���ã�������Ч��
		*/
		, GBHW_Index_Set_Speed 
};

// ʶ�������ʼ��
// ����ʶ������ǰ������øú������г�ʼ��
// ����0��ʾ�ɹ� 
#ifdef _C166
GBAPI int GBHWNew(const void _huge * data,void* param);
#else
GBAPI int GBHWNew(const void * data,void* param);
#endif

//ʶ��������Ҫ�ĺ���
//pbTrace (in) �ֹ켣��Ϊ�˽�ʡ�ռ䣬������޸���������ֵ
//result (out) Unicode �������
//candNum (in)��Ҫ�ĺ�ѡ����������ܳ���MAX_RESULT_COUNT
//option (in)ʶ�������GB_OPT�в�ֵͬ�����
//prob (out)ʶ��������, ȡֵ��Χ��(0-1000), ʵ��ֵ��1000����
//���ؽ���ĸ���
GBAPI int GBHWRecognize(short* pbTrace, unsigned short * result, int candNum, unsigned long option);
GBAPI int GBHWRecognizeEx(short* pbTrace, unsigned short * result, int candNum, unsigned long option,long *prob);

/*!
 * \brief ����ʶ������ʶ�����
 * \param index ��Χ��GB_HW_Option_Index�����ֵ
 * \param value ����index���岻ͬ����ϸ�����ÿһ��index��˵��
 * \ret ���indexΪ�Ƿ�ֵ���򷵻�GBHW_Err_Option_Invalid_Index 
 *      �ɹ�����GBHW_OK
 *      ��������ֵ��鿴ÿһ������ֵ��˵��
 */
GBAPI int GBHWSetOption(int index, unsigned long value);


#ifdef GBHW_DATA_FROM_FILE
enum GB_STREAM_FLAG
{
   GB_SEEK_SET,
   GB_SEEK_CUR,
   GB_SEEK_END,
   GB_SEEK_NOMOVE
};

enum GB_STREAM_ERROR
{
   GB_FSEEK_FUNC_NOT_SET,
   GB_FREAD_FUNC_NOT_SET
};

typedef int (*pfGBHWFreadT)(void * ptr,int size,int nmemb,void * stream,int offset,int whence);
int GBHWNewFile(const void * stream,void* param);
void GBHWSetRequireRam(void *buffer,int lth);
void GBHWSetDataSource(void* stream);
void GBHWSetFread(pfGBHWFreadT pf);
int GBHWGetLastError();

#endif

#ifdef __cplusplus
}
#endif

#endif
