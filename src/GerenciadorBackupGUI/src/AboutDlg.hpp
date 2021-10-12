#pragma once

class CAboutDlg : public CDialogEx
{
public:
    CAboutDlg();

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

protected:
    DECLARE_MESSAGE_MAP()

private:
    enum { IDD = IDD_ABOUTBOX };
};
