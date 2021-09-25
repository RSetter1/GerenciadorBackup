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

BEGIN_MESSAGE_MAP(CFolderEdit, _base)
    ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

void CFolderEdit::OnLButtonDblClk(UINT nFlags, CPoint point)
{
    __super::OnLButtonDblClk(nFlags, point);
}
