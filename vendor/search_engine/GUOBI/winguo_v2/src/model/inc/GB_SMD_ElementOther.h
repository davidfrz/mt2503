
#ifndef __GB_SMD_ELEMENTOTHER_H__
#define __GB_SMD_ELEMENTOTHER_H__

#include "GB_WG_Common.h"

/**************** �ʹ�����Ӧ������  *******************/

// ����WinguoFun��ID����ȡWinguoFun�ַ���
GB_INT GB_SMD_WinguoFunGetCachIdSting(GB_U16 *pKeyStr, GB_U16 *nkeystrLen, GB_U16 nKeyStrBuffLen, GB_U32 nId);

//����WinguoFun��ID���Ƚ�WinguoFun��С������ʱʹ�ã�
GB_INT GB_SMD_WinguoFunCachIdCompare(GB_UINT nId1, GB_UINT nId2);

// ��WinguoFun������������
GB_VOID GB_SMD_WinguoFunAddSearchData(GB_VOID);

// ����WinguoFun��ID����ȡ��ʾ����
GB_INT GB_SMD_WinguoFunGetCachShowDataByIndex(GB_U32 nId, GB_SMD_ElementShowInfoStr *pShowInfo);

// ����WinguoFun
GB_VOID GB_SMD_WinguoFunRun(GB_U16 id);





/**************** �绰��������ʾ  *******************/

// ���������������ʾ
GB_INT GB_SMD_EncyptGetCachIdSting(GB_U16 *pKeyStr, GB_U16 *nkeystrLen, GB_U16 nKeyStrBuffLen, GB_U32 nId);

// ���������ıȽ�
GB_INT GB_SMD_EncyptCachIdCompare(GB_UINT nId1, GB_UINT nId2);

// ������������ʾ�����ѡ
GB_INT GB_SMD_EncyptSearchString(GB_U16* pSearch);

// ����WinguoFun��ID����ȡ��ʾ����
GB_INT GB_SMD_EncyptGetCachShowDataByIndex(GB_U32 nId, GB_SMD_ElementShowInfoStr *pShowInfo);

// ����������ʾ
GB_VOID GB_SMD_EncyptFunRun(GB_VOID);


#endif // __GB_SMD_ELEMENTOTHER_H__


