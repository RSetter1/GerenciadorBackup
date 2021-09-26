#include "StdAfx.h"
#include "FolderEdit.h"

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
    ON_WM_CREATE       ()
    ON_WM_LBUTTONDBLCLK()
    ON_CONTROL_REFLECT (EN_KILLFOCUS, &CFolderEdit::OnEnKillfocus)
END_MESSAGE_MAP()

int CFolderEdit::OnCreate(LPCREATESTRUCT lpCS)
{
    int iReturn = __super::OnCreate(lpCS);

    return iReturn;
}

void CFolderEdit::OnLButtonDblClk(UINT nFlags, CPoint point)
{
    __super::OnLButtonDblClk(nFlags, point);

    CFolderPickerDialog dlgPicker;
    INT_PTR iResult = dlgPicker.DoModal();

    if (iResult == IDOK)
        m_sDiretorio = dlgPicker.GetFolderPath();

    PostMessage(WM_KILLFOCUS);
}

void CFolderEdit::OnEnKillfocus()
{
    // todo: tratar isso aqui direito. se o user digitar nunca vai alterar m_sDiretorio.

    if (m_sDiretorio.IsEmpty())
        return;

    SetWindowText(m_sDiretorio);
}
