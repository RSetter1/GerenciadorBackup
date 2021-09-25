#pragma once

class CFolderEdit : public CEdit
{
    DECLARE_DYNAMIC(CFolderEdit)

public:
    CFolderEdit();
    virtual ~CFolderEdit();

protected:
    DECLARE_MESSAGE_MAP()

private:
    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};
