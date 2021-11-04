// XListViewDoc.cpp : implementation of the CXListViewDoc class
//

#include "stdafx.h"
#include "XListView.h"

#include "XListViewDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CXListViewDoc

IMPLEMENT_DYNCREATE(CXListViewDoc, CDocument)

BEGIN_MESSAGE_MAP(CXListViewDoc, CDocument)
	//{{AFX_MSG_MAP(CXListViewDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXListViewDoc construction/destruction

CXListViewDoc::CXListViewDoc()
{
	// TODO: add one-time construction code here

}

CXListViewDoc::~CXListViewDoc()
{
}

BOOL CXListViewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CXListViewDoc serialization

void CXListViewDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CXListViewDoc diagnostics

#ifdef _DEBUG
void CXListViewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CXListViewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CXListViewDoc commands
