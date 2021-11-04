// XListView.h : main header file for the XLISTVIEW application
//

#if !defined(AFX_XLISTVIEW_H__B3F664B6_467E_42BF_BAC6_226E9C1335A4__INCLUDED_)
#define AFX_XLISTVIEW_H__B3F664B6_467E_42BF_BAC6_226E9C1335A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CXListViewApp:
// See XListView.cpp for the implementation of this class
//

class CXListViewApp : public CWinApp
{
public:
	CXListViewApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXListViewApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CXListViewApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XLISTVIEW_H__B3F664B6_467E_42BF_BAC6_226E9C1335A4__INCLUDED_)
