#pragma once

class CButtonBackup : public CButton
{
    DECLARE_DYNAMIC(CButtonBackup)

public:
    CButtonBackup();
    virtual ~CButtonBackup();

    void SetDirOrigem (const CString& sDir);
    void SetDirDestino(const CString& sDir);

private:
    DECLARE_MESSAGE_MAP()

    afx_msg void OnBnClicked();

private:
    void EfetuaBackup      ();
    BOOL ConsisteDiretorios();

private:
    const CString* m_psDirOrigem ;
    const CString* m_psDirDestino;
};
