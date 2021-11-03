#pragma once

class CGerenciadorBackupGUIDlg : public CDialogEx
{
public:
    CGerenciadorBackupGUIDlg(CWnd* pParent = nullptr);

public: // estruturas
    enum { IDD = IDD_GERENCIADORBACKUPGUI_DIALOG };

    enum class EQuemAtualizar
    {
        eOrigem  = 0,
        eDestino = 1,
    };

protected: // funções herdadas
    virtual void DoDataExchange(CDataExchange* pDX) override;
    virtual BOOL OnInitDialog  ()                   override;

protected: // message handlers
    DECLARE_MESSAGE_MAP()

    afx_msg void    OnSysCommand               (UINT nID, LPARAM lParam);
    afx_msg void    OnPaint                    ();
    afx_msg HCURSOR OnQueryDragIcon            ();
    afx_msg void    OnBnClickedBtnQuemAtualizar();

private: // controles
    CFolderEdit   m_edtPastaOrigem  ;
    CFolderEdit   m_edtPastaDestino ;
    CButtonBackup m_btnEfetuarBackup;
    CButton       m_btnQuemAtualizar;



    CListCtrl m_listOrigem ;
    CListCtrl m_listDestino;

    CButton m_btnAddOrigem   ;
    CButton m_btnChangeOrigem;
    CButton m_btnRemoveOrigem;



private: // funções diversas

private: // membros
    HICON          m_hIcon          ;
    EQuemAtualizar flagQuemAtualizar;

    HICON          m_hIconAdd       ;
    HICON          m_hIconEdit      ;
    HICON          m_hIconRemove    ;
};
