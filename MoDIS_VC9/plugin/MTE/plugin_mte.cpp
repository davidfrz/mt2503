// plugin_mte.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "plugin_mte.h"
#include "DialogTheme.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// Cplugin_mteApp

BEGIN_MESSAGE_MAP(Cplugin_mteApp, CWinApp)
END_MESSAGE_MAP()


// Cplugin_mteApp construction

Cplugin_mteApp::Cplugin_mteApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	//_CrtSetBreakAlloc(1430);
}


// The one and only Cplugin_mteApp object

Cplugin_mteApp theApp;

// Cplugin_mteApp initialization

BOOL Cplugin_mteApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

CDialogTheme * g_pThemeDlg = NULL;
__declspec(dllexport) void WINAPI OpenPlugin(HWND hParent, HWND* phWnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	g_pThemeDlg = new CDialogTheme( CWnd::FromHandle(hParent));
	if(NULL !=  g_pThemeDlg)
	{
		BOOL ret = g_pThemeDlg->Create(IDD_DIALOG_THEME, CWnd::FromHandle(hParent));
		g_pThemeDlg->ShowWindow(SW_SHOW);
		if(NULL != phWnd)
			*phWnd = g_pThemeDlg->GetSafeHwnd();
	}
	return;
}

__declspec(dllexport) void WINAPI ClosePlugin(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if(NULL != g_pThemeDlg && ::IsWindow(g_pThemeDlg->GetSafeHwnd()))
	{
		//g_pThemeDlg->OnDestroy();
		g_pThemeDlg->SendMessage(WM_CLOSE);
		//g_pThemeDlg->SendMessage(WM_DESTROY);
		delete g_pThemeDlg;
		g_pThemeDlg = NULL;
	}
	return;
}

/************************************************************************
 ����PreTranslateMessage��һ�������������������йأ�
 �����д��һ��MFC DLL���������һ��MFC������֮�е������MFC DLL�е�Modeless Dialog�Ļ���
 Modeless Dialog��PreTranslateMessage���ᱻ����
 ��ΪMFC DLL�����MFC����ӵ�в�ͬ��AfxModuleThreadState��
 �����MFC DLL�д�����modeless CDialog������MFC���̵ľ������
 ��CWnd::FromhandlePermanent����NULL���������ȻMFC�������е�CWinApp��Pretranslatemessage�ᱻ��
 ��ע���ʱDialog����Ϣѭ����MFC���������棩�����ǲ������MFC DLL�д������Ǹ�modeless CDialog
 ��PreTranslateMessage�����������Ҫ���⴦��һ�������ַ�����
 1. ֱ����MFC�������е�CWinApp::PreTranslatemessage�������MFC DLL��CWinApp::PreTranslateMessage
 (����ר����MFC DLL��exportһ��ר�ŵĺ��������������)
 2. ʹ�ù��ӣ��ڹ�����Ϣ������֮�У��ж�Ŀ�괰���Ƿ��ǵ�ǰ���н���Ĵ��ڣ�
 ����ǣ���ֱ�ӵ���Ŀ�괰�ڵ�PreTranslateMessage������ǰ��������Ҫ������������ָ�룩��                                                 
/************************************************************************/
__declspec(dllexport) BOOL WINAPI PluginPreTranslateMessage(MSG* pMsg)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return theApp.PreTranslateMessage(pMsg);
}
