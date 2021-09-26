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
    CString sParametros;
    sParametros.Format(_T("\"%s\", \"%s\" /mir"), m_psDirOrigem->GetString(), m_psDirDestino->GetString());

    STARTUPINFO info {};
    info.cb = sizeof(info);

    PROCESS_INFORMATION processInfo {};

    CString sDirWin32;

    GetSystemDirectory(sDirWin32.GetBuffer(), MAX_PATH);

    sDirWin32.Format(L"%s", sDirWin32.GetBuffer());
    sDirWin32.ReleaseBuffer();

    sDirWin32 += L"\\Robocopy.exe";

    BOOL bOK = CreateProcess(sDirWin32.GetString(),
                             (LPWSTR) sParametros.GetString(),
                             NULL,
                             NULL,
                             TRUE,
                             0,
                             NULL,
                             NULL,
                             &info,
                             &processInfo);


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

    bool bPossuiDirOrig = !m_psDirOrigem ->IsEmpty();
    bool bPossuiDirDest = !m_psDirDestino->IsEmpty();

    if (!bPossuiDirOrig || !bPossuiDirDest)
    {
        if (!bPossuiDirOrig)
            AfxMessageBox(IDS_DIR_ORIG_DEVE_SER_INFORMADO);
        else
            AfxMessageBox(IDS_DIR_DEST_DEVE_SER_INFORMADO);

        return FALSE;
    }

    return TRUE;
}
