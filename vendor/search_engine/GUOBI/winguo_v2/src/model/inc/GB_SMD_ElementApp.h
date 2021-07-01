
#ifndef __GB_SMD_ELEMENTAPP_H__
#define __GB_SMD_ELEMENTAPP_H__

#include "GB_WG_Common.h"

// ����App��ID����ȡApp�ַ���
GB_INT GB_SMD_AppGetCachIdSting(GB_U16 *pKeyStr, GB_U16 *nkeystrLen, GB_U16 nKeyStrBuffLen, GB_U32 nId);

// ����App��ID���Ƚ�ID��С������ʱʹ�ã�
GB_INT GB_SMD_AppCachIdCompare(GB_UINT nId1, GB_UINT nId2);


// ��App������������
GB_VOID GB_SMD_AppAddSearchData(GB_VOID);


// ����App��ID����ȡ��ʾ����
GB_INT GB_SMD_AppGetCachShowDataByIndex(GB_U32 nId, GB_SMD_ElementShowInfoStr *pShowInfo);


// �����ʹ�õ�APP���뵽�����������ȥ
GB_INT GB_SMD_AppAddDefaultItem(GB_VOID);

// ��ʼ��App�����Ļ���
GB_VOID GB_SMD_AppElementInit(GB_VOID);

// �ͷ�App�����Ļ���
GB_VOID GB_SMD_AppElementRelease(GB_VOID);

// ����֪��ID��App
GB_VOID GB_SMD_RunApp(GB_U32 nId);

#endif // __GB_SMD_ELEMENTAPP_H__


