
#ifndef __GB_WG_PLATFORMFUN_H__
#define __GB_WG_PLATFORMFUN_H__

#include "GB_WG_DataTypeDef.h"

GB_VOID *GB_WG_Platform_MallocFun(GB_ULONG size);
GB_VOID GB_WG_Platform_FreeFun(GB_VOID *p);
GB_BOOL GB_WG_Platform_Is_Winguo();


#endif // __GB_WG_PLATFORMFUN_H__