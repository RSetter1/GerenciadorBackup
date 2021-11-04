// XListViewView.cpp : implementation of the CXListViewView class
//

#include "stdafx.h"
#include "XListView.h"
#include "XListViewDoc.h"
#include "XListViewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CXListViewView

IMPLEMENT_DYNCREATE(CXListViewView, CView)

BEGIN_MESSAGE_MAP(CXListViewView, CView)
	//{{AFX_MSG_MAP(CXListViewView)
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_START, OnStart)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXListViewView construction/destruction

CXListViewView::CXListViewView()
{
	m_pList = NULL;
}

CXListViewView::~CXListViewView()
{
}

BOOL CXListViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CXListViewView drawing

void CXListViewView::OnDraw(CDC* /*pDC*/)
{
	CXListViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
}

/////////////////////////////////////////////////////////////////////////////
// CXListViewView printing

BOOL CXListViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CXListViewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CXListViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

/////////////////////////////////////////////////////////////////////////////
// CXListViewView diagnostics

#ifdef _DEBUG
void CXListViewView::AssertValid() const
{
	CView::AssertValid();
}

void CXListViewView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CXListViewDoc* CXListViewView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CXListViewDoc)));
	return (CXListViewDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CXListViewView message handlers

///////////////////////////////////////////////////////////////////////////////
// OnCreate
int CXListViewView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	DWORD dwStyle = LVS_REPORT | LVS_SINGLESEL | LVS_SHOWSELALWAYS |
		WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP;

	CRect rect(0,0,100,100);

	m_pList = new CXListCtrl();
	ASSERT(m_pList);
	VERIFY(m_pList->CreateEx(WS_EX_CLIENTEDGE, dwStyle, rect, this, IDC_LIST));
	CFont *pFont = GetFont();
	if (pFont)
		m_pList->SetFont(pFont);

	m_pList->SetExtendedStyle(LVS_EX_FULLROWSELECT);// | LVS_EX_TRACKSELECT);

	return 0;
}

///////////////////////////////////////////////////////////////////////////////
// OnActivateView
void CXListViewView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView)
{
	CView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}

///////////////////////////////////////////////////////////////////////////////
// OnSize
void CXListViewView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	if (m_pList)
		m_pList->MoveWindow(0, 0, cx, cy);

	int w = cx - 2;
	int colwidths[6] = { 8, 14, 12, 9, 8, 13 };	// sixty-fourths

	int total_cx = 0;
	int n = m_pList->GetColumns();

	// adjust columns
	for (int i = 0; i < n; i++)
	{
		int colwidth = (i == (n - 1)) ? w - total_cx - 2 : (w * colwidths[i]) / 64;
		total_cx += colwidth;
		m_pList->SetColumnWidth(i, colwidth);
	}
}

///////////////////////////////////////////////////////////////////////////////
// InitListCtrl
void CXListViewView::InitListCtrl(CXListCtrl& list)
{
	// set column width according to window rect
	CRect rect;
	list.GetWindowRect(&rect);

	int w = rect.Width() - 2;
	int colwidths[6] = { 8, 14, 12, 9, 8, 13 };	// sixty-fourths

	TCHAR *	lpszHeaders[] = { _T("Enable"),
							  _T("Some Text"),
							  _T("Item"),
							  _T("Pct"),
							  _T("Status"),
							  _T("Some More Text"),
							  NULL };
	int i;
	int total_cx = 0;
	LV_COLUMN lvcolumn;
	memset(&lvcolumn, 0, sizeof(lvcolumn));

	// add columns
	for (i = 0; ; i++)
	{
		if (lpszHeaders[i] == NULL)
			break;

		lvcolumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
		lvcolumn.fmt = (i == 1 || i == 5) ? LVCFMT_LEFT : LVCFMT_CENTER;
		lvcolumn.pszText = lpszHeaders[i];
		lvcolumn.iSubItem = i;
		lvcolumn.cx = (lpszHeaders[i+1] == NULL) ? w - total_cx - 2 : (w * colwidths[i]) / 64;
		total_cx += lvcolumn.cx;
		list.InsertColumn(i, &lvcolumn);
	}

	// create the image list from bitmap resource
	VERIFY(list.m_cImageList.Create(IDB_CHECKBOXES, 16, 3, RGB(255, 0, 255)));
	list.m_HeaderCtrl.SetImageList(&list.m_cImageList);

	// iterate through header items and attach the image list
	HDITEM hditem;

	for (i = 0; i < list.m_HeaderCtrl.GetItemCount(); i++)
	{
		list.m_HeaderCtrl.GetItem(i, &hditem);
		hditem.fmt |=  HDF_IMAGE;
		hditem.mask |= HDI_IMAGE | HDI_FORMAT;
		if (i == 0 || i == 4)
			hditem.iImage = 1;
		else
			hditem.iImage = 0;

		list.m_HeaderCtrl.SetItem(i, &hditem);
	}

	memset(&lvcolumn, 0, sizeof(lvcolumn));

	// set the format again - must do this twice or first column does not get set
	for (i = 0; ; i++)
	{
		if (lpszHeaders[i] == NULL)
			break;

		lvcolumn.mask = LVCF_FMT | LVCF_SUBITEM;
		lvcolumn.fmt = (i == 1 || i == 5) ? LVCFMT_LEFT : LVCFMT_CENTER;
		lvcolumn.iSubItem = i;
		list.SetColumn(i, &lvcolumn);
	}
}

///////////////////////////////////////////////////////////////////////////////
// FillListCtrl
void CXListViewView::FillListCtrl(CXListCtrl& list)
{
	CString str;

	/////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////
	//
	// Note - the string arrays must persist for life of list control
	//
	/////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////


	// a list of some of my favorite things
	m_sa1.RemoveAll();
	m_sa1.Add(_T("apple"));
	m_sa1.Add(_T("banana"));
	m_sa1.Add(_T("blueberry"));
	m_sa1.Add(_T("cherry"));
	m_sa1.Add(_T("cranberry"));
	m_sa1.Add(_T("grape"));
	m_sa1.Add(_T("lemon"));
	m_sa1.Add(_T("lime"));
	m_sa1.Add(_T("orange"));
	m_sa1.Add(_T("peach"));
	m_sa1.Add(_T("pear"));
	m_sa1.Add(_T("plum"));
	m_sa1.Add(_T("raspberry"));
	m_sa1.Add(_T("strawberry"));
	m_sa1.Add(_T("tangerine"));

	// a list of some more of my favorite things
	m_sa2.RemoveAll();
	m_sa2.Add(_T("Aidi"));
	m_sa2.Add(_T("Akbas"));
	m_sa2.Add(_T("Ariegeois"));
	m_sa2.Add(_T("Boerboel"));
	m_sa2.Add(_T("Boolomo"));
	m_sa2.Add(_T("Borzoi"));
	m_sa2.Add(_T("Broholmer"));
	m_sa2.Add(_T("Caniche"));
	m_sa2.Add(_T("Charplaninatz"));
	m_sa2.Add(_T("Drok"));
	m_sa2.Add(_T("Elo"));
	m_sa2.Add(_T("Farou"));
	m_sa2.Add(_T("Godo"));
	m_sa2.Add(_T("Groenendael"));
	m_sa2.Add(_T("Hahoavu"));
	m_sa2.Add(_T("Heidewachtel"));
	m_sa2.Add(_T("Hovawart"));
	m_sa2.Add(_T("Juzak"));
	m_sa2.Add(_T("Kai"));
	m_sa2.Add(_T("Kangal"));
	m_sa2.Add(_T("Karabash"));
	m_sa2.Add(_T("Kishu"));
	m_sa2.Add(_T("Kuvasz"));
	m_sa2.Add(_T("Landseer"));
	m_sa2.Add(_T("Levesque"));
	m_sa2.Add(_T("Licaon"));
	m_sa2.Add(_T("Maliki"));
	m_sa2.Add(_T("Mechelaar"));
	m_sa2.Add(_T("Mirigung"));
	m_sa2.Add(_T("Mudi"));
	m_sa2.Add(_T("Noggum"));
	m_sa2.Add(_T("Ocherese"));
	m_sa2.Add(_T("Phalene"));
	m_sa2.Add(_T("Pocadan"));
	m_sa2.Add(_T("Podhalan"));
	m_sa2.Add(_T("Poitevin"));
	m_sa2.Add(_T("Saluki"));
	m_sa2.Add(_T("Samojedskaja"));
	m_sa2.Add(_T("Samoyed"));
	m_sa2.Add(_T("Spion"));
	m_sa2.Add(_T("Stichelhaar"));
	m_sa2.Add(_T("Taygan"));
	m_sa2.Add(_T("Telomian"));
	m_sa2.Add(_T("Tornjak"));
	m_sa2.Add(_T("Virelade"));
	m_sa2.Add(_T("Warrigal"));


	list.LockWindowUpdate();	// ***** lock window updates while filling list *****

	// insert the items and subitems into the list
	for (int nItem = 0; nItem < 10; nItem++)
	{
		for (int nSubItem = 0; nSubItem < 6; nSubItem++)
		{
			if (nSubItem == 0)			// checkbox
				str = _T("");
			if (nSubItem == 1)			// text
				str = _T("This is some text");
			if (nSubItem == 2)			// combo
				str = _T("");
			if (nSubItem == 3)			// progress
				str = _T("Complete");
			if (nSubItem == 4)			// checkbox
				str = _T("");
			if (nSubItem == 5)			// text
				str = _T("This is some more text");

			if (nSubItem == 0)
				list.InsertItem(nItem, str);
			else if (nItem == 0 && nSubItem == 1)
				list.SetItemText(nItem, nSubItem, str, RGB(0,0,0), RGB(0,255,255));
			else if (nItem == 1 && nSubItem == 1)
				list.SetItemText(nItem, nSubItem, str, RGB(0,0,0), RGB(0,255,0));
			else
				list.SetItemText(nItem, nSubItem, str);

			if (nSubItem == 0)
				list.SetCheckbox(nItem, nSubItem, 0);
			if (nSubItem == 2 && ((nItem & 1) == 1))
				list.SetComboBox(nItem, nSubItem, 1, &m_sa1, 5, nItem);
			if (nSubItem == 2 && ((nItem & 1) == 0))
				list.SetComboBox(nItem, nSubItem, 1, &m_sa2, 10, nItem*4);
			if (nSubItem == 4)
				list.SetCheckbox(nItem, nSubItem, 1);
		}
	}

	list.UnlockWindowUpdate();	// ***** unlock window updates *****
}

///////////////////////////////////////////////////////////////////////////////
// OnInitialUpdate
void CXListViewView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	InitListCtrl(*m_pList);
	UpdateWindow();
}

///////////////////////////////////////////////////////////////////////////////
// OnStart
void CXListViewView::OnStart()
{
	FillListCtrl(*m_pList);
	m_pList->SetEnabled(3, FALSE);
	m_pList->SetItemText(3, 1, _T("This row is disabled"));
	SetTimer(1, 1000, NULL);
}

///////////////////////////////////////////////////////////////////////////////
// OnTimer
void CXListViewView::OnTimer(UINT nIDEvent)
{
	static int nPct = 0;
	static int nItem = -1;
	static int nBlink = 0;

	if (nIDEvent == 1)
	{
		KillTimer(nIDEvent);
		m_pList->SetProgress(1, 3);
		nPct = 0;
		SetTimer(2, 80, NULL);
		SetTimer(4, 400, NULL);
	}
	else if (nIDEvent == 2)
	{
		nPct += 10;
		m_pList->UpdateProgress(1, 3, nPct);
		if (nPct >= 100)
		{
			KillTimer(nIDEvent);
			SetTimer(3, 2000, NULL);
		}
	}
	else if (nIDEvent == 3)
	{
		CString str;
		str = m_pList->GetComboText(0, 2);

		KillTimer(nIDEvent);
		m_pList->DeleteProgress(1, 3);
		SetTimer(1, 2000, NULL);
	}
	else if (nIDEvent == 4)
	{
		if (nItem != -1)
		{
			// remove previous color & bold from columns 1 and 5
			m_pList->SetItemText(nItem, 5, NULL, (COLORREF)-1, (COLORREF)-1);
			m_pList->SetBold(nItem, 1, FALSE);
		}

		// blink item 4
		if (nItem == 4)
		{
			nBlink++;
			if (nBlink >= 12)
			{
				nBlink = 0;
				nItem++;
				m_pList->SetItemText(nItem, 5, NULL, RGB(255,255,255), RGB(255,0,0));
				m_pList->SetBold(nItem, 1, TRUE);
			}
			else
			{
				if (nBlink & 1)		// blink every other time
				{
					m_pList->SetItemText(nItem, 5, NULL, RGB(255,255,255), RGB(255,0,0));
					m_pList->SetBold(nItem, 1, TRUE);
				}
			}
		}
		else
		{
			nItem++;
			if (nItem >= m_pList->GetItemCount())
				nItem = 0;
			m_pList->SetItemText(nItem, 5, NULL, RGB(255,255,255), RGB(255,0,0));
			m_pList->SetBold(nItem, 1, TRUE);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
// OnDestroy
void CXListViewView::OnDestroy()
{
	KillTimer(1);
	KillTimer(2);
	KillTimer(3);
	KillTimer(4);
	CView::OnDestroy();
}

