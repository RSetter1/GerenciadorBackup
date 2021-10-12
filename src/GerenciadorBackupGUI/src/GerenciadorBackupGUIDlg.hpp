#pragma once

class CGerenciadorBackupGUIDlg : public CDialogEx
{
public:
    CGerenciadorBackupGUIDlg(CWnd* pParent = nullptr);

protected: // funções herdadas
    virtual void DoDataExchange(CDataExchange* pDX) override;
    virtual BOOL OnInitDialog  ()                   override;

private: // estruturas
    enum { IDD = IDD_GERENCIADORBACKUPGUI_DIALOG };

    enum class EQuemAtualizar
    {
        eOrigem  = 0,
        eDestino = 1,
    };

private: // controles
    CFolderEdit   m_edtPastaOrigem  ;
    CFolderEdit   m_edtPastaDestino ;
    CButtonBackup m_btnEfetuarBackup;
    CButton       m_btnQuemAtualizar;

private: // message handlers
    DECLARE_MESSAGE_MAP()

    afx_msg void    OnSysCommand               (UINT nID, LPARAM lParam);
    afx_msg void    OnPaint                    ();
    afx_msg HCURSOR OnQueryDragIcon            ();
    afx_msg void    OnBnClickedBtnQuemAtualizar();

private: // funções diversas

private: // membros
    HICON          m_hIcon          ;
    EQuemAtualizar flagQuemAtualizar;
};
