#include "StdAfx.h"
#include "ButtonBackup.h"

using _base = CButton; // Usado apenas quando não dá pra usar __super.

IMPLEMENT_DYNAMIC(CButtonBackup, _base)

CButtonBackup::CButtonBackup()
    : m_psDirOrigem (nullptr)
    , m_psDirDestino(nullptr)
{
}

CButtonBackup::~CButtonBackup()
{
}

void CButtonBackup::SetDirOrigem(const CString& sDir)
{
    m_psDirOrigem = &sDir;
}

void CButtonBackup::SetDirDestino(const CString& sDir)
{
    m_psDirDestino = &sDir;
}

BEGIN_MESSAGE_MAP(CButtonBackup, _base)
    ON_CONTROL_REFLECT(BN_CLICKED, &CButtonBackup::OnBnClicked)
END_MESSAGE_MAP()

void CButtonBackup::OnBnClicked()
{
    if (!ConsisteDiretorios())
        return;

    EfetuaBackup();
}

void CButtonBackup::EfetuaBackup()
{
    WCHAR szDirWin32[MAX_PATH] {};
    GetSystemDirectory(szDirWin32, MAX_PATH);

    CString sCallParametro;
    sCallParametro.Format(
        _T("%s\\%s \"%s\" \"%s\" /mir"),
        szDirWin32                     ,
        _T("Robocopy.exe")             ,
        m_psDirOrigem ->GetString()    ,
        m_psDirDestino->GetString()    
    );

    STARTUPINFO info {};
    info.cb = sizeof(info);

    PROCESS_INFORMATION processInfo {};

    BOOL bOK = CreateProcess(
        NULL,
        (LPWSTR) sCallParametro.GetString(),
        NULL,
        NULL,
        TRUE,
        NORMAL_PRIORITY_CLASS | CREATE_NEW_CONSOLE | CREATE_NEW_PROCESS_GROUP,
        NULL,
        NULL,
        &info,
        &processInfo
    );

    if (bOK)
    {
        WaitForSingleObject(processInfo.hProcess, INFINITE);
        CloseHandle(processInfo.hProcess);
        CloseHandle(processInfo.hThread);
    }
}

BOOL CButtonBackup::ConsisteDiretorios()
{
    ASSERT(m_psDirOrigem  != nullptr);
    ASSERT(m_psDirDestino != nullptr);

    return (!m_psDirOrigem->IsEmpty() || !m_psDirDestino->IsEmpty());
}
