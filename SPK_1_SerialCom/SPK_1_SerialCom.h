
// SPK_1_SerialCom.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CSPK_1_SerialComApp:
// See SPK_1_SerialCom.cpp for the implementation of this class
//

class CSPK_1_SerialComApp : public CWinApp
{
public:
	CSPK_1_SerialComApp();

// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CSPK_1_SerialComApp theApp;