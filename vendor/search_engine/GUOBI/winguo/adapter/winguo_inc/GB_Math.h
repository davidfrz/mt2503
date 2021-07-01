
#ifndef GBMATH_DEFINE_FOR_PLATFORM_KNIGHTNIU_2008_03_04_H
#define GBMATH_DEFINE_FOR_PLATFORM_KNIGHTNIU_2008_03_04_H
#include "GB_DataTypeDef.h"

#define GB_STRICMP  GB_PlatStrICmp
#define GB_STRNICMP GB_PlatStrNICmp

#define GB_MIN(a,b)  ((a)<=(b)?(a):(b))
#define GB_MAX(a,b)  ((a)>=(b)?(a):(b))
#define GB_MED(a,b)  (((a)-(b))/2)
#define GB_ABS(a)     ((a)>=0?(a):-(a))
#define GB_POW2(a)    ((a)*(a))

#define GB_WG_ASSERT1(a) ((a==GB_NULL)? GB_FALSE:GB_TRUE)

#define GB_WG_ASSERT2(a,b) (GB_WG_ASSERT1(a)? GB_WG_ASSERT1(a->b):GB_FALSE)

#define GB_WG_ASSERT3(a,b,c) (GB_WG_ASSERT2(a,b)? GB_WG_ASSERT1(a->b->c):GB_FALSE)

#define GB_WG_ASSERT4(a,b,c,d) (GB_WG_ASSERT3(a,b,c)? GB_WG_ASSERT1(a->b->c->d):GB_FALSE)


#define GB_MD5_STRING_LENGTH   (32+1)
#define GB_MD5_DIGEST_LENGTH	16
#define GB_ENCRYPT_PADLEN		18
#define	GB_CRYPT_KEY_SIZE		16

#ifdef _DEBUG
GB_BOOL GBPLATMd5Test(GB_VOID); /*����MD5�����Ƿ���rfc1321����*/
#endif


								/************************************************************************************************
								MD5���ݽṹ
************************************************************************************************/

#define GB_MD5_LBLOCK	16
typedef struct MD5state_st
{
	GB_ULONG A,B,C,D;
	GB_ULONG Nl,Nh;
	GB_ULONG data[GB_MD5_LBLOCK];
	GB_INT num;
} GB_MD5_CTX;

GB_VOID GBPLATMD5_Init(GB_MD5_CTX *c);
GB_VOID GBPLATMD5_Update(GB_MD5_CTX *c, const register GB_BYTE *data, GB_ULONG len);
GB_VOID GBPLATMD5_Final(GB_BYTE *md, GB_MD5_CTX *c);

/************************************************************************************************
Hash����
************************************************************************************************/
/*
����const BYTE *inBuffer��int length
���BYTE *outBuffer
����length��Ϊ0,outBuffer�ĳ���ΪMD5_DIGEST_LENGTH(16byte)
*/

GB_VOID GBPLATMd5HashBuffer(GB_BYTE *outBuffer, const GB_BYTE *inBuffer, GB_INT length);

GB_VOID GBPLATMd5HashString(GB_CHAR *outString, const GB_BYTE *inBuffer, GB_INT length);

GB_BOOL GB_WG_Base64Decode(GB_CHAR* pszIn, GB_CHAR* pszOut,GB_INT pszOutSize);

GB_INT GB_WG_Base64DecodeGetSize(GB_CHAR* pszIn);

//GB_BYTE* GB_base64Decode(GB_BYTE* in, GB_UINT* resultSize, GB_BOOL trimTrailingZeros);
GB_BYTE* GB_base64Decode(GB_BYTE* in, GB_INT size, GB_UINT* resultSize, GB_BOOL trimTrailingZeros);

GB_INT   GB_Hex(GB_CHAR nByte);
GB_LONG GB_HexString2Long(GB_CHAR* pData);

GB_INT GB_PlatCharICmp(GB_CHAR ch1,GB_CHAR  ch2);
GB_INT GB_PlatStrICmp(const GB_CHAR *str1,GB_CHAR * str2);
GB_INT GB_PlatStrICmpEx(const GB_CHAR *str1,GB_CHAR * str2,GB_INT nSize);
GB_INT GB_PlatStrNICmp(GB_CHAR *str1,GB_CHAR * str2,GB_INT nSize);

GB_INT GB_free_ex(GB_VOID**pStr);

GB_CHAR *GB_STRISTR(GB_CHAR *str1,GB_CHAR *str2);

GB_BOOL  GB_STRLOW(GB_CHAR *strIn,GB_CHAR *strOut,GB_INT len);
GB_BOOL  GB_WSTRLOW(const GB_WCHAR *strIn,GB_WCHAR *strOut,GB_INT len);
GB_WCHAR GB_WCHARLOW(const GB_WCHAR strIn);
GB_BOOL  GB_STRENDWITH(GB_CHAR *str,GB_CHAR *endStr);
GB_BOOL  GB_STRSTARTWITH(GB_CHAR* str,GB_CHAR* startStr);
GB_CHAR* GB_STRLASTSTR(GB_CHAR *str1,GB_INT str1Len,GB_CHAR *str2);
GB_CHAR* GB_STRREPLACE(GB_CHAR* string,GB_CHAR* replaceStr,GB_CHAR* targetStr);// �ǵ��ͷ�Ŷ

// ��ȡ��������Ľ���
GB_BOOL GB_Rectint(GB_Rect* rect1,GB_Rect* rect2,GB_Rect* rectint);
// ��������
GB_BOOL GB_RectCopy(GB_Rect* targetRect,GB_Rect* sourceRect);
// �����Ƿ��ཻ
GB_BOOL GB_IsRectIntersecting(GB_Rect* rect1,GB_Rect* rect2);
// ����rect2�Ƿ������rect1��
GB_BOOL GB_IsRectContain(GB_Rect* rect1,GB_Rect* rect2);
// ������
GB_INT GB_POWER(GB_INT x,GB_INT n);

typedef enum __GB_ACEESSURL_TYPE__
{
	GB_ACCESSURLTYPE_NONE = 0,
		GB_ACCESSURLTYPE_HTTP,
		GB_ACCESSURLTYPE_FILE
		
} GB_ACCESSURLTYPE;

// �ж�·���ķ�������
GB_ACCESSURLTYPE 
GB_GetAccessUrlType(GB_CHAR* accessUrl);
// ��ȡ�����ķ���·������Ҫ�ͷ�
GB_CHAR* GB_GetFullUrl(GB_CHAR* accessUrl);
// �Ƿ�Ϊ��Ч���ַ�
GB_BOOL GB_IsValidChar(GB_CHAR character);
// �Ƿ�����Ч�������ַ�
GB_BOOL GB_WG_IsNumberChar(GB_CHAR character);
// �Ƿ�����Ч�����ִ�
GB_BOOL GB_WG_IsNumberString(GB_CHAR *string);
GB_BOOL GB_WG_IsLetterString(GB_CHAR *string,GB_INT strLen);
// �Ƿ�����Ч�ַ�
GB_BOOL GB_IsAllValidWChar(GB_WCHAR* str,GB_INT strLen);
GB_BOOL GB_IsAllValidChar(GB_CHAR* str,GB_INT strLen);
// �ж���Ч��url
GB_BOOL GB_WG_IsUrlValid(GB_CHAR* url);
// ���ݷ���url��ԭʼ��url�������µ�url
GB_CHAR* GB_WG_GetAccessUrl(GB_CHAR* accessUrl,GB_CHAR* paramUrl);
// ��ȡ������
GB_BOOL GB_WG_StreamReadBytes(GB_CHAR** streamBuff,GB_INT streamLen,GB_CHAR* readBuff,GB_INT readLen);
// ���ǵ�������ȡ����λ��
GB_BOOL GB_StreamReadString(GB_CHAR** pStream,GB_CHAR* targetString,GB_CHAR* result,GB_INT resultSize);

#endif

