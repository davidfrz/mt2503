
#ifndef __GB_SMD_PLATFORMELEMENTCALLLOG_H__
#define __GB_SMD_PLATFORMELEMENTCALLLOG_H__

#include "GB_WG_DataTypeDef.h"


// �������봮����������ƥ���callLog
extern GB_INT GB_SMD_Platform_SearchCallLogByString(GB_U16 * key_input);

// ��ȡCallLog��Icon
extern GB_INT GB_SMD_Platform_GetCallLogIcon(GB_U32 index, GB_PU8 *img_buff_p);

// ����ID��ȡCallLog�ĺ���
extern GB_INT GB_SMD_Platform_GetCallLogNumByIndex(GB_U32 id, GB_U16* pstrBuf, GB_INT bufLen);

// ��ȡCallLog��ע����Ϣ
extern GB_INT GB_SMD_Platform_GetCallLogNote(GB_U32 id, GB_U16* pstrBuf, GB_INT bufLen);


#endif // __GB_SMD_PLATFORMELEMENTCALLLOG_H__

