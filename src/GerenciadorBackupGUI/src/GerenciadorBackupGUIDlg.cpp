#include "StdAfx.h"
#include "GerenciadorBackupGUI.h"
#include "GerenciadorBackupGUIDlg.h"
#include "AboutDlg.h"

using _base = CDialogEx; // Usado apenas quando não dá pra usar __super.

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CGerenciadorBackupGUIDlg::CGerenciadorBackupGUIDlg(CWnd* pParent /*=nullptr*/)
    : _base(CGerenciadorBackupGUIDlg::IDD, pParent)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGerenciadorBackupGUIDlg::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGerenciadorBackupGUIDlg, _base)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()

BOOL CGerenciadorBackupGUIDlg::OnInitDialog()
{
    __super::OnInitDialog();

    ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
    ASSERT(IDM_ABOUTBOX < 0xF000);

    CMenu* pSysMenu = GetSystemMenu(FALSE);
    if (pSysMenu != nullptr)
    {
        BOOL bNameValid;
        CString strAboutMenu;
        bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
        ASSERT(bNameValid);
        if (!strAboutMenu.IsEmpty())
        {
            pSysMenu->AppendMenu(MF_SEPARATOR);
            pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
        }
    }

    SetIcon(m_hIcon, TRUE);

    return TRUE;
}

void CGerenciadorBackupGUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
    if ((nID & 0xFFF0) == IDM_ABOUTBOX)
    {
        CAboutDlg dlgAbout;
        dlgAbout.DoModal();
    }
    else
    {
        __super::OnSysCommand(nID, lParam);
    }
}

void CGerenciadorBackupGUIDlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this);

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        __super::OnPaint();
    }
}

HCURSOR CGerenciadorBackupGUIDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}
