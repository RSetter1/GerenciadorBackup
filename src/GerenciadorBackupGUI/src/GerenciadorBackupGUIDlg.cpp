#include "StdAfx.hpp"
#include "GerenciadorBackupGUI.hpp"
#include "GerenciadorBackupGUIDlg.hpp"
#include "AboutDlg.hpp"

using _base = CDialogEx; // Usado apenas quando não dá pra usar __super.

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CGerenciadorBackupGUIDlg::CGerenciadorBackupGUIDlg(CWnd* pParent /*=nullptr*/)
    : _base            (CGerenciadorBackupGUIDlg::IDD, pParent)
    , flagQuemAtualizar(EQuemAtualizar::eDestino              )
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGerenciadorBackupGUIDlg::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);

    DDX_Control(pDX, IDC_EDT_PASTA_ORIGEM , m_edtPastaOrigem  );
    DDX_Control(pDX, IDC_EDT_PASTA_DESTINO, m_edtPastaDestino );
    DDX_Control(pDX, IDC_BTN_EFETUARBKP   , m_btnEfetuarBackup);
    DDX_Control(pDX, IDC_BTN_QUEMATUALIZAR, m_btnQuemAtualizar);
}

BEGIN_MESSAGE_MAP(CGerenciadorBackupGUIDlg, _base)
    ON_WM_SYSCOMMAND    ()
    ON_WM_PAINT         ()
    ON_WM_QUERYDRAGICON ()
    ON_BN_CLICKED       (IDC_BTN_QUEMATUALIZAR, &CGerenciadorBackupGUIDlg::OnBnClickedBtnQuemAtualizar)
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

    m_edtPastaOrigem .SetCueBanner(TEXT("Informe o diretório de origem" ));
    m_edtPastaDestino.SetCueBanner(TEXT("Informe o diretório de destino"));

    flagQuemAtualizar = EQuemAtualizar::eDestino;
    m_btnQuemAtualizar.SetWindowText(TEXT("---->"));

    m_btnEfetuarBackup.SetDirOrigem (m_edtPastaOrigem .GetDiretorio());
    m_btnEfetuarBackup.SetDirDestino(m_edtPastaDestino.GetDiretorio());

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

void CGerenciadorBackupGUIDlg::OnBnClickedBtnQuemAtualizar()
{
    switch (flagQuemAtualizar)
    {
        case EQuemAtualizar::eOrigem:
            flagQuemAtualizar = EQuemAtualizar::eDestino;
            m_btnQuemAtualizar.SetWindowText(TEXT("---->"));
            break;

        case EQuemAtualizar::eDestino:
            flagQuemAtualizar = EQuemAtualizar::eOrigem;
            m_btnQuemAtualizar.SetWindowText(TEXT("<----"));
            break;
    }
}
