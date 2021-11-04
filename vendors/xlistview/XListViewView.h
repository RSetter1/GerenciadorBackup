// XListViewView.h : interface of the CXListViewView class
//
/////////////////////////////////////////////////////////////////////////////

#ifndef XLISTVIEWVIEW_H
#define XLISTVIEWVIEW_H

#include "XListCtrl.h"

class CXListViewView : public CView
{
protected: // create from serialization only
	CXListViewView();
	DECLARE_DYNCREATE(CXListViewView)

// Attributes
public:
	CXListViewDoc* GetDocument();
	CXListCtrl * m_pList;
	CStringArray m_sa1, m_sa2;

// Operations
public:
	void FillListCtrl(CXListCtrl& list);
	void InitListCtrl(CXListCtrl& list);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXListViewView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CXListViewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CXListViewView)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDestroy();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	afx_msg void OnStart();
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in XListViewView.cpp
inline CXListViewDoc* CXListViewView::GetDocument()
   { return (CXListViewDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif //XLISTVIEWVIEW_H
