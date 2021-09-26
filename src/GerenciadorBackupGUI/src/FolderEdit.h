#pragma once

class CFolderEdit : public CEdit
{
    DECLARE_DYNAMIC(CFolderEdit)

public:
    CFolderEdit();
    virtual ~CFolderEdit();

    const CString& GetDiretorio();

private:
    DECLARE_MESSAGE_MAP()

    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
    afx_msg void OnEnKillfocus  ();

private:
    BOOL ConsisteDiretorio   (CString& sDir);
    void TrataStringDiretorio(CString& sDir);

private:
    CString m_sDiretorio;
};
