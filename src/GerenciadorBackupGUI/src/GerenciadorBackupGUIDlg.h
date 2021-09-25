#pragma once

class CGerenciadorBackupGUIDlg : public CDialogEx
{
public:
    CGerenciadorBackupGUIDlg(CWnd* pParent = nullptr);

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_GERENCIADORBACKUPGUI_DIALOG };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

protected:
    HICON m_hIcon;

    virtual BOOL OnInitDialog();
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    DECLARE_MESSAGE_MAP()
};
