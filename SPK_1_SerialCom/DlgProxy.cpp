
// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "SPK_1_SerialCom.h"
#include "DlgProxy.h"
#include "SPK_1_SerialComDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSPK_1_SerialComDlgAutoProxy

IMPLEMENT_DYNCREATE(CSPK_1_SerialComDlgAutoProxy, CCmdTarget)

CSPK_1_SerialComDlgAutoProxy::CSPK_1_SerialComDlgAutoProxy()
{
	EnableAutomation();
	
	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CSPK_1_SerialComDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CSPK_1_SerialComDlg)))
		{
			m_pDialog = reinterpret_cast<CSPK_1_SerialComDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CSPK_1_SerialComDlgAutoProxy::~CSPK_1_SerialComDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CSPK_1_SerialComDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CSPK_1_SerialComDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSPK_1_SerialComDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// Note: we add support for IID_ISPK_1_SerialCom to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .IDL file.

// {8C40C9C0-1E15-4B1A-B158-61F9D3C2F369}
static const IID IID_ISPK_1_SerialCom =
{ 0x8C40C9C0, 0x1E15, 0x4B1A, { 0xB1, 0x58, 0x61, 0xF9, 0xD3, 0xC2, 0xF3, 0x69 } };

BEGIN_INTERFACE_MAP(CSPK_1_SerialComDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CSPK_1_SerialComDlgAutoProxy, IID_ISPK_1_SerialCom, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {220D4446-60C3-4481-881A-06C32B40CF0B}
IMPLEMENT_OLECREATE2(CSPK_1_SerialComDlgAutoProxy, "SPK_1_SerialCom.Application", 0x220d4446, 0x60c3, 0x4481, 0x88, 0x1a, 0x6, 0xc3, 0x2b, 0x40, 0xcf, 0xb)


// CSPK_1_SerialComDlgAutoProxy message handlers
