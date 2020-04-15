
// DlgProxy.h: header file
//

#pragma once

class CSPK_1_SerialComDlg;


// CSPK_1_SerialComDlgAutoProxy command target

class CSPK_1_SerialComDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CSPK_1_SerialComDlgAutoProxy)

	CSPK_1_SerialComDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CSPK_1_SerialComDlg* m_pDialog;

// Operations
public:

// Overrides
	public:
	virtual void OnFinalRelease();

// Implementation
protected:
	virtual ~CSPK_1_SerialComDlgAutoProxy();

	// Generated message map functions

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CSPK_1_SerialComDlgAutoProxy)

	// Generated OLE dispatch map functions

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

