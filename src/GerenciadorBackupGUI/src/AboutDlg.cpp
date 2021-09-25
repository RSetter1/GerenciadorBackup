#include "StdAfx.h"

#include "AboutDlg.h"

using _base = CDialogEx; // Usado apenas quando não dá pra usar __super.

BEGIN_MESSAGE_MAP(CAboutDlg, _base)
END_MESSAGE_MAP()

CAboutDlg::CAboutDlg()
    : _base(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
}
