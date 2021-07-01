#ifndef __BTOSAPI_H__
#define __BTOSAPI_H__

#include "btostypes.h"

#include "btosapi_int.h"

// TODO: to add more descriptions
void *OS_MemSet(U8 *ptr, U8 value, U32 size);

// TODO: to add more descriptions
void *OS_MemCpy(U8 *dest, const U8 *src, U32 len);

// TODO: to add more descriptions
BOOL OS_MemCmpExt(const U8 *src1, U32 len1, const U8 *src2, U32 len2);
S32 OS_MemCmp(const U8 *src1, const U8 *src2, U32 len);


// TODO: to add more descriptions
void *OS_MemAlloc(U32 size);

// TODO: to add more descriptions
void OS_MemFree(void *ptr);





// TODO: to add more descriptions
S8 *OS_StrCpy(S8 *dest, const S8 *src);

// TODO: to add more descriptions
S8 *OS_StrnCpy(S8 *dest, const S8 *src, U32 len);

// TODO: to add more descriptions
S32 OS_StrCmp(const S8 *str1, const S8 *str2);

// TODO: to add more descriptions
S32 OS_StrnCmp(const S8 *str1, const S8 *str2, U32 len);

// TODO: to add more descriptions
S32 OS_StriCmp(const S8 *str1, const S8 *str2);

// TODO: to add more descriptions
S32 OS_StrniCmp(const S8 *str1, const S8 *str2, U32 len);

// TODO: to add more descriptions
U32 OS_StrLen(const S8 *str);

// TODO: to add more descriptions
S8 *OS_StrCat(S8 *dest, const S8 *src);

// TODO: to add more descriptions
S8 *OS_StrFind(const S8 *str, const S8 *sub);

// TODO: to add more descriptions
S8 OS_ToLower(S8 chr);

// TODO: to add more descriptions
S8 OS_ToUpper(S8 chr);

// TODO: to add more descriptions
S32 OS_Atoi(const S8 *str);

// TODO: to add more descriptions
S8 *OS_StrDup(const S8 *str);

// TODO: to add more descriptions
S8 *OS_StrTok(S8 *str, const S8 *delim);

// TODO: to add more descriptions
S8 *OS_StrChr(const S8 *str, S8 c);

// TODO: to add more descriptions
WCHAR *OS_StrCpy_UCS2(WCHAR *dest, const WCHAR *src);

// TODO: to add more descriptions
WCHAR *OS_StrnCpy_UCS2(WCHAR *dest, const WCHAR *src, U32 len);

// TODO: to add more descriptions
S32 OS_StriCmp_UCS2(const WCHAR *str1, const WCHAR *str2);

// TODO: to add more descriptions
S32 OS_StrniCmp_UCS2(const WCHAR *str1, const WCHAR *str2, U32 len);

// TODO: to add more descriptions
U32 OS_StrLen_UCS2(const WCHAR *str);

// TODO: to add more descriptions
WCHAR *OS_StrCat_UCS2(WCHAR *dest, const WCHAR *src);

// TODO: to add more descriptions
WCHAR *OS_StrFind_UCS2(const WCHAR *str, const WCHAR *sub);

// TODO: to add more descriptions
WCHAR *OS_StrTok_UCS2(WCHAR *str, const WCHAR *delim, WCHAR **ptr);



// TODO: to add more descriptions
S32 OS_UTF8ToUCS2(WCHAR *dest, U32 dest_size, const U8 *src);

// TODO: to add more descriptions
S32 OS_UCS2ToUTF8(U8 *dest, U32 dest_size, const WCHAR *src);


// TODO: to add more descriptions
#ifndef OS_Sprintf
void OS_Sprintf(S8 *str, const S8 *format, ...);
#endif

// TODO: to add more descriptions
void OS_InitRand(U32 seed);

// TODO: to add more descriptions
S32 OS_Rand();





// TODO: to add more descriptions
// Marked just for now.
// void OS_Trace(trace_class_enum trc_class, U32 msg_idx, const S8 *arg_type, ...);

// TODO: to add more descriptions
// Marked just for now.
// void OS_Report(const S8 *format, ...);





// TODO: to add more descriptions
U8 *OS_AllocShareMemory(U8 *name, U32 size);

// TODO: to add more descriptions
void OS_FreeShareMemory(U8 *name);
void *OS_GetShareMemory(U8 *name);




// TODO: to add more descriptions
void OS_StartTimer(OS_TIMER *timer, U32 ms, OS_Timer_Cb);

// TODO: to add more descriptions
void OS_CancelTimer(OS_TIMER *timer);






// TODO: to add more descriptions
U8 OS_SendMsg(U32 msgid, U8 destmod, U8 saptype, U8 *ptr, U16 size);




// TODO: to add more descriptions
OS_FS_HANDLE OS_FileOpen(const U8 *filename, U32 mode);

// TODO: to add more descriptions
OS_FS_STATUS OS_FileClose(OS_FS_HANDLE handle);

// TODO: to add more descriptions
OS_FS_STATUS OS_Delete(const U8 *path);

// TODO: to add more descriptions
OS_FS_STATUS OS_MakeDir(const U8 *path);

// TODO: to add more descriptions
OS_FS_STATUS OS_GetFileSize(OS_FS_HANDLE handle, U32 *size);

OS_FS_STATUS OS_GetFileSizeByPath(const U8 *path, U32 *size);

// TODO: to add more descriptions
OS_FS_STATUS OS_RenameFile(const U8 *old, const U8 *newname);

// TODO: to add more descriptions
OS_FS_STATUS OS_GetCurrentDir(U8 *buf, U32 size);

// TODO: to add more descriptions
BOOL OS_IsValidFSHandle(OS_FS_HANDLE handle);

// TODO: to add more descriptions
BOOL OS_FileExist(const U8 *path);

// TODO: to add more descriptions
BOOL OS_DirExist(const U8 *path);

// TODO: to add more descriptions
S32 OS_FileRead(OS_FS_HANDLE handle, U8 *buf, U32 bytes);

// TODO: to add more descriptions
S32 OS_FileWrite(OS_FS_HANDLE handle, const U8 *buf, U32 size);

// TODO: to add more descriptions
S32 OS_FileSeek(OS_FS_HANDLE handle, U32 offset, U32 mode);

// TODO: to add more descriptions
OS_FS_HANDLE OS_FileOpen_UCS2(const WCHAR *filename, U32 mode);

// TODO: to add more descriptions
OS_FS_STATUS OS_FileClose_UCS2(OS_FS_HANDLE handle);

// TODO: to add more descriptions
OS_FS_STATUS OS_Delete_UCS2(const WCHAR *path);

// TODO: to add more descriptions
OS_FS_STATUS OS_MakeDir_UCS2(const WCHAR *path);

// TODO: to add more descriptions
OS_FS_STATUS OS_RenameFile_UCS2(const WCHAR *old, const WCHAR *rename);

// TODO: to add more descriptions
OS_FS_STATUS OS_GetCurrentDir_UCS2(WCHAR *buf, U32 size);

OS_FS_STATUS OS_GetFileSizeByPath_UCS2(const WCHAR *buf, U32 *size);

// TODO: to add more descriptions
BOOL OS_FileExist_UCS2(const WCHAR *path);

// TODO: to add more descriptions
BOOL OS_DirExist_UCS2(const WCHAR *path);

// TODO: to add more descriptions
S32 OS_FileRead_UCS2(OS_FS_HANDLE handle, U8 *buf, U32 bytes);

// TODO: to add more descriptions
S32 OS_FileWrite_UCS2(OS_FS_HANDLE handle, const U8 *buf, U32 size);

// TODO: to add more descriptions
S32 OS_FileSeek_UCS2(OS_FS_HANDLE handle, U32 offset, U32 mode);

// TODO: to add more descriptions
S32 OS_FileMove_UCS2(const WCHAR *src, const WCHAR *dest, U32 mode);





// TODO: to add more descriptions
U32 OS_GetSystemTime();

// TODO: to add more descriptions
U32 OS_SetSystemPropertyUint(const S8 *name, U32 val, U8 persist);

// TODO: to add more descriptions
U32 OS_GetSystemPropertyUint(const S8 *name, U32 *val, U8 persist);





// TODO: to add more descriptions
void OS_Assert_Impl(S32 expr, S8 *file, S32 line);
#define OS_Assert(expr) OS_Assert_Impl((S32) expr, __FILE__, __LINE__)


#endif /* __BTOSAPI_H__ */
