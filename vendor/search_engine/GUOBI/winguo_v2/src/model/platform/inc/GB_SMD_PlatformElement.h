
#ifndef __GB_SMD_PLATFORMELEMENT_H__
#define __GB_SMD_PLATFORMELEMENT_H__

#include "GB_WG_DataTypeDef.h"

// 添加搜索所支持的语言
extern GB_VOID GB_SMD_LanguageAdd(GB_VOID);

// smartdial数据模块的malloc函数
GB_VOID *GB_SMD_Mode_Malloc(GB_U32 size);

// smartdial数据模块的memFree函数
GB_VOID GB_SMD_Mode_Free(GB_VOID *p);

#endif // __GB_SMD_PLATFORMELEMENT_H__

