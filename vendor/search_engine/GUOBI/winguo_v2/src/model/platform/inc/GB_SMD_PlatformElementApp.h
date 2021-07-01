
#ifndef __GB_SMD_PLATFORMELEMENTAPP_H__
#define __GB_SMD_PLATFORMELEMENTAPP_H__

#include "GB_WG_DataTypeDef.h"


// ��ȡApp������
extern GB_INT GB_SMD_Platform_GetAppName(GB_U32 nAppId, GB_WCHAR *pstrBuff, GB_U16 nBuffLen);

// ��ȡApp��ע����Ϣ
extern GB_INT GB_SMD_Platform_GetAppNote(GB_U32 nAppId, GB_WCHAR *pstrBuff, GB_U16 nBuffLen);

// ��ȡApp��Icon
extern GB_INT GB_SMD_Platform_GetAppIcon(GB_U32 nAppId, GB_PU8 *img_buff_p);

// ����app��Id�Ƿ���Ч
extern GB_BOOL GB_SMD_Platform_CheckAppId(GB_U32 nAppId);

// ��ȡApp�ĸ���
extern GB_U32 GB_SMD_Platform_GetLocalAppListSize(GB_VOID);

// �Ƚ�������ʷʹ�ù���app��ID
extern GB_INT GB_SMD_Platform_DefaultAppCmp(GB_U32 Index1, GB_U32 Index2);

// ��ȡ��ʷʹ�ù���app�ĸ���
extern GB_U32 GB_SMD_Platform_GetDefaultAppCount(GB_VOID);

// ��ȡָ��index��ʷʹ�ù���app ID
extern GB_INT GB_SMD_Platform_GetDefaultApp(GB_U32 Index);

// ��ʼ��App�����Ļ���
extern GB_VOID GB_SMD_Platform_AppElementInit(GB_VOID);

// �ͷ�App�����Ļ���
extern GB_VOID GB_SMD_Platform_AppElementRelease(GB_VOID);

// ����ָ����App, �����smartdail��ȡ����funapp���飬����������̨��Ӧ������ҳ��
extern GB_INT GB_SMD_Platform_RunApp(GB_U32 usIndex,GB_BOOL isSmartDail);

#endif // __GB_SMD_PLATFORMELEMENTAPP_H__

