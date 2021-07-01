
#ifndef __GB_SMD_ELEMENTPHONENUM_H__
#define __GB_SMD_ELEMENTPHONENUM_H__

#include "GB_WG_Common.h"
#include "GB_SMD_Element.h"

// �����Ƿ������绰���루ֻ������ϵ�����֣�
GB_VOID GB_SMD_PhoneNumSetSearchNoNum(GB_BOOL Flag);

// ����PhoneNum��ID����ȡPhoneNum�ַ���
GB_INT GB_SMD_PhoneNumGetCachIdSting(GB_U16 *pKeyStr, GB_U16 *nkeystrLen, GB_U16 nKeyStrBuffLen, GB_U32 nId);

// �Ƚϵ绰����ID�Ĵ�С������ʱʹ�ã�
GB_INT GB_SMD_PhoneNumCachIdCompare(GB_UINT nId1, GB_UINT nId2);

// ��ȡָ���绰PhoneNum ID����ʾ��Ϣ
GB_INT GB_SMD_PhoneNumGetCachShowDataByIndex(GB_U32 nId, GB_SMD_ElementShowInfoStr *pShowInfo);

// ��ȡָ��Id�ĵ绰����
GB_INT GB_SMD_PhoneNumGetNumById(GB_U32 nId, GB_U16 *pNumBuff, GB_U16 nBuffLen);

// ��ȡָ��Id�ĵ绰�������
GB_INT GB_SMD_PhoneNumGetCountById(GB_U32 nId);

// ����������������ɾ��ָ��Phone Id 
GB_INT GB_SMD_PhoneNumDleletAStringCach(GB_U16 indexType, GB_U32 store_index, GB_U16 *pString);

// ���ָ����Phone Id ��������������
GB_INT GB_SMD_PhoneNumAddAStringCach(GB_U16 indexType, GB_U32 store_index, GB_U16 *pString);


// ��ӵ绰������������
GB_VOID GB_SMD_PhoneNumAddSearchData(GB_VOID);

// ��ȡ�绰�������ʵID������Ĳ���Ӧ����nId��GB_SMD_GetCachDataByIndex���ú�ʹ��
GB_U32 GB_SMD_PhoneNumGetRealId(GB_U32 nId);



#endif // __GB_SMD_ELEMENTPHONENUM_H__


