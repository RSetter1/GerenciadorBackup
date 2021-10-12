#include "StdAfx.hpp"
#include "FolderEdit.hpp"

using _base = CEdit; // Usado apenas quando não dá pra usar __super.

IMPLEMENT_DYNAMIC(CFolderEdit, _base)

CFolderEdit::CFolderEdit()
{
}

CFolderEdit::~CFolderEdit()
{
}

const CString& CFolderEdit::GetDiretorio()
{
    return m_sDiretorio;
}

BEGIN_MESSAGE_MAP(CFolderEdit, _base)
    ON_WM_LBUTTONDBLCLK()
    ON_CONTROL_REFLECT (EN_KILLFOCUS, &CFolderEdit::OnEnKillfocus)
END_MESSAGE_MAP()

void CFolderEdit::OnLButtonDblClk(UINT nFlags, CPoint point)
{
    __super::OnLButtonDblClk(nFlags, point);

    CFolderPickerDialog dlgPicker(L"C:\\");
    INT_PTR iResult = dlgPicker.DoModal();

    if (iResult != IDOK)
        return;

    CString sDir = dlgPicker.GetPathName();
    sDir.Trim();

    TrataStringDiretorio(sDir);

    SetWindowText(sDir);

    if (ConsisteDiretorio(sDir))
        m_sDiretorio = sDir;
}

void CFolderEdit::OnEnKillfocus()
{
    CString sDir;
    GetWindowText(sDir);

    sDir.Trim();

    TrataStringDiretorio(sDir);

    SetWindowText(sDir);

    if (ConsisteDiretorio(sDir))
        m_sDiretorio = sDir;
}

BOOL CFolderEdit::ConsisteDiretorio(CString& sDir)
{
    if (sDir.IsEmpty())
        return FALSE;

    if (!PathFileExists(sDir))
    {
        AfxMessageBox(IDS_INFORME_DIR_VALIDO);
        SetSel(0, sDir.GetLength());
        SetFocus();
        return FALSE;
    }

    return TRUE;
}

void CFolderEdit::TrataStringDiretorio(CString& sDir)
{
    if (sDir.IsEmpty())
        return;

    sDir.Trim();

    if (sDir.GetLength() && sDir[0] == L'"')
        sDir.Delete(0, 1);

    if (sDir.GetLength() && sDir[sDir.GetLength() - 1] == L'"')
        sDir.Delete(sDir.GetLength() - 1, 1);

    if (sDir.GetLength() && sDir[sDir.GetLength() - 1] == L'\\')
        sDir.Delete(sDir.GetLength() - 1, 1);
}
