
#ifndef __GB_SMD_PLATFORMELEMENTOTHER_H__
#define __GB_SMD_PLATFORMELEMENTOTHER_H__

#include "GB_WG_DataTypeDef.h"


// ��ȡWinguoFun��ע����Ϣ
extern GB_INT GB_SMD_Platform_GetWinguoFunNote(GB_U32 id, GB_U16* pstrBuf, GB_INT bufLen);

extern GB_INT GB_SMD_Platform_GetWinguoFunIcon(GB_U32 nAppId, GB_PU8 *img_buff_p);

extern GB_INT GB_SMD_Platform_GetEncyptFunIcon(GB_U32 nAppId, GB_PU8 *img_buff_p);

// �Ƿ��ǵ绰������ģʽ
extern GB_BOOL GB_SMD_IsEncyptMode(GB_VOID);

#endif // __GB_SMD_PLATFORMELEMENTOTHER_H__

