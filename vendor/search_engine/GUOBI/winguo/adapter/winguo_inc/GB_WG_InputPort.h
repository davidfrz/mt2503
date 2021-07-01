
#ifndef __GB_WG_INPUTPORT_H__
#define __GB_WG_INPUTPORT_H__


#include "GB_DataTypeDef.h"


#define GB_WG_UP_SCREEN_STRING_MAX_LEN    32

typedef enum
{
	GB_WG_IME_InputType_SINGLELINE = 0,   // ����
	GB_WG_IME_InputType_SMD_SINGLELINE,   // SMD����
	GB_WG_IME_InputType_MULTILINE,        // ����
	GB_WG_IME_InputType_PASSWORD          // �����
}GB_WG_IME_EditorType;

typedef enum
{
	GB_WG_IME_InputType_NONE = 0,         // ��
	GB_WG_IME_InputType_NUMERIC,          // ����
	GB_WG_IME_InputType_PHONE_NUMBER,     // ��������
	GB_WG_IME_InputType_SENTENCE,         // �ı�
	GB_WG_IME_InputType_ALPHANUMERIC,     // �Ǻ���
	GB_WG_IME_InputType_ASCII_CHAR,       // ��Ascii�ı�
	GB_WG_IME_InputType_QUICK_SEARCH,     // ����
	GB_WG_IME_InputType_URL,              // URL
	GB_WG_IME_InputType_EMAIL            // email
}GB_WG_IME_InputType;


GB_INT GB_WG_Ime_EditorDeleteAChar(GB_VOID);
GB_INT GB_WG_Ime_EditorInsertString(GB_WCHAR *pString);
GB_INT GB_WG_Ime_EditorAllChar(GB_VOID);
GB_INT GB_WG_Ime_GetEditorRect(GB_Rect *prect);
GB_INT GB_WG_Ime_GetHwRect(GB_Rect *prect);
GB_INT GB_WG_Ime_ResizeEditor(GB_INT width, GB_INT high);
GB_VOID GB_WG_Ime_ShowContext(GB_VOID);
GB_INT GB_WG_Ime_EditorIsEmpty(GB_VOID);
GB_INT GB_WG_Ime_StartSelect(GB_VOID);
GB_INT GB_WG_Ime_CancelSelect(GB_VOID);
GB_INT GB_WG_Ime_IsSelectState(GB_VOID);
GB_VOID GB_WG_Ime_ShowImeBackground(GB_LONG x1, GB_LONG y1, GB_LONG x2, GB_LONG y2);
GB_INT GB_WG_Ime_GetText(GB_WCHAR **pText);
GB_VOID GB_WG_Ime_SetInputmodData(GB_INT InputmodeData);
GB_VOID GB_WG_Ime_ShowSoftKeyBackUp(GB_VOID);
GB_INT GB_WG_Ime_VkHide_CallBack(GB_BOOL isHide);
GB_INT GB_WG_Ime_SetRedrawRect(GB_Rect *prect);
GB_U16* GB_WG_Ime_GetRightSoftKeyString(GB_VOID);
GB_INT GB_WG_Ime_MoveCursorLeft(GB_VOID);
GB_INT GB_WG_Ime_MoveCursorRight(GB_VOID);
GB_INT GB_WG_Ime_GetCursorPos(GB_UINT *nPos);

#endif // #ifndef __GB_WG_INPUTPORT_H__

