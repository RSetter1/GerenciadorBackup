#include "StdAfx.hpp"
#include "GerenciadorBackupGUI.hpp"
#include "GerenciadorBackupGUIDlg.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CGerenciadorBackupGUIApp, CWinApp)
    ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

CGerenciadorBackupGUIApp::CGerenciadorBackupGUIApp()
{
}

CGerenciadorBackupGUIApp theApp;

BOOL CGerenciadorBackupGUIApp::InitInstance()
{
    INITCOMMONCONTROLSEX InitCtrls {};
    InitCtrls.dwSize = sizeof(InitCtrls);
    InitCtrls.dwICC = ICC_WIN95_CLASSES;
    InitCommonControlsEx(&InitCtrls);

    CWinApp::InitInstance();

    CShellManager *pShellManager = new CShellManager;
    CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

    SetRegistryKey(TEXT("GerenciadorBackupGUI"));

    CGerenciadorBackupGUIDlg dlg;
    m_pMainWnd = &dlg;
    dlg.DoModal();

    if (pShellManager != nullptr)
        delete pShellManager;

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
    ControlBarCleanUp();
#endif

    return FALSE;
}
