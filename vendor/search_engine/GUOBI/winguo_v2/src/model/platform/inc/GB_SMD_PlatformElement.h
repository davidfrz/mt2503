
#ifndef __GB_SMD_PLATFORMELEMENT_H__
#define __GB_SMD_PLATFORMELEMENT_H__

#include "GB_WG_DataTypeDef.h"

// ���������֧�ֵ�����
extern GB_VOID GB_SMD_LanguageAdd(GB_VOID);

// smartdial����ģ���malloc����
GB_VOID *GB_SMD_Mode_Malloc(GB_U32 size);

// smartdial����ģ���memFree����
GB_VOID GB_SMD_Mode_Free(GB_VOID *p);

#endif // __GB_SMD_PLATFORMELEMENT_H__

