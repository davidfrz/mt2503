
#ifndef __GB_SMD_ELEMENTCALLLOG_H__
#define __GB_SMD_ELEMENTCALLLOG_H__

#include "GB_WG_Common.h"

// ����CallLog��ID����ȡCallLog�ַ���
GB_INT GB_SMD_CallLogGetCachIdSting(GB_U16 *pKeyStr, GB_U16 *nkeystrLen, GB_U16 nKeyStrBuffLen, GB_U32 nId);

//����CallLog��ID���Ƚ�CallLog��С������ʱʹ�ã�
GB_INT GB_SMD_CallLogCachIdCompare(GB_UINT nId1, GB_UINT nId2);

// ��ʼ��ͨ����¼ģ��
GB_VOID GB_SMD_CallLogElementInit(GB_VOID);

// �ͷ�ͨ����¼ģ��
GB_VOID GB_SMD_CallLogElementRelease(GB_VOID);

// �������봮����������ƥ���callLog
GB_INT GB_SMD_CallLogSearchString(GB_U16* pSearch);

// ����CallLog��ID����ȡ��ʾ����
GB_INT GB_SMD_CallLogGetCachShowDataByIndex(GB_U32 nId, GB_SMD_ElementShowInfoStr *pShowInfo);

// ��ȡָ��CallLog Id�ĵ绰����
GB_INT GB_SMD_CallLogGetPhoneNumByIndex(GB_U32 nId, GB_U16 *pNumBuff, GB_U16 nBuffLen);

#endif // __GB_SMD_ELEMENTCALLLOG_H__


