// XListViewDoc.h : interface of the CXListViewDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_XLISTVIEWDOC_H__6633ADBF_C936_48B9_9013_A15096363124__INCLUDED_)
#define AFX_XLISTVIEWDOC_H__6633ADBF_C936_48B9_9013_A15096363124__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CXListViewDoc : public CDocument
{
protected: // create from serialization only
	CXListViewDoc();
	DECLARE_DYNCREATE(CXListViewDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXListViewDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CXListViewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CXListViewDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XLISTVIEWDOC_H__6633ADBF_C936_48B9_9013_A15096363124__INCLUDED_)
