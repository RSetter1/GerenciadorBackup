#include "StdAfx.hpp"
#include "GerenciadorBackupGUI.hpp"
#include "GerenciadorBackupGUIDlg.hpp"
#include "AboutDlg.hpp"
#include "Macros.h"

using _base = CDialogEx; // Usado apenas quando não dá pra usar __super.

#ifdef _DEBUG
    #define new DEBUG_NEW
#endif

CGerenciadorBackupGUIDlg::CGerenciadorBackupGUIDlg(CWnd* pParent /*=nullptr*/)
    : _base            (CGerenciadorBackupGUIDlg::IDD, pParent)
    , flagQuemAtualizar(EQuemAtualizar::eDestino              )
{
    m_hIcon             = AfxGetApp()->LoadIcon(IDR_MAINFRAME   );

    m_hIconAdd          = AfxGetApp()->LoadIcon(IDI_ADD         );
    m_hIconEdit         = AfxGetApp()->LoadIcon(IDI_EDIT        );
    m_hIconRemove       = AfxGetApp()->LoadIcon(IDI_REMOVE      );
    m_hIconSearchFolder = AfxGetApp()->LoadIcon(IDI_SEARCHFOLDER);
}

void CGerenciadorBackupGUIDlg::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);

    DDX_Control(pDX, IDC_EDT_PASTA_ORIGEM     , m_edtPastaOrigem        );
    DDX_Control(pDX, IDC_EDT_PASTA_DESTINO    , m_edtPastaDestino       );
    DDX_Control(pDX, IDC_BTN_EFETUARBKP       , m_btnEfetuarBackup      );
    DDX_Control(pDX, IDC_BTN_QUEMATUALIZAR    , m_btnQuemAtualizar      );

    DDX_Control(pDX, IDC_LIST_ORIGEM          , m_listOrigem            );
    DDX_Control(pDX, IDC_EDT_ORIGEM           , m_edtDiretorioOrigem    );
    DDX_Control(pDX, IDC_BTN_FOLDERVIEWORIGEM , m_btnSearchFolderOrigem );
    DDX_Control(pDX, IDC_BTN_ADDORIGEM        , m_btnAddOrigem          );
    DDX_Control(pDX, IDC_BTN_CHANGEORIGEM     , m_btnChangeOrigem       );
    DDX_Control(pDX, IDC_BTN_REMOVEORIGEM     , m_btnRemoveOrigem       );

    DDX_Control(pDX, IDC_LIST_DESTINO         , m_listDestino           );
    DDX_Control(pDX, IDC_EDT_DESTINO          , m_edtDiretorioDestino   );
    DDX_Control(pDX, IDC_BTN_FOLDERVIEWDESTINO, m_btnSearchFolderDestino);
    DDX_Control(pDX, IDC_BTN_ADDDESTINO       , m_btnAddDestino         );
    DDX_Control(pDX, IDC_BTN_CHANGEDESTINO    , m_btnChangeDestino      );
    DDX_Control(pDX, IDC_BTN_REMOVEDESTINO    , m_btnRemoveDestino      );
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

    InicializaControlesLista();

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

void CGerenciadorBackupGUIDlg::InicializaControlesLista()
{
    INICIALIZA_CONTROLES_LISTA(Origem);

    INICIALIZA_CONTROLES_LISTA(Destino);
}
