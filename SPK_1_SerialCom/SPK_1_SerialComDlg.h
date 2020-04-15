
// SPK_1_SerialComDlg.h : header file
//

#pragma once
#include "tchart1.h"
#include "mscomm1.h"
#include "afxwin.h"
#include "CAxes.h"
#include "CAxis.h"
#include "CSeries.h"
#include "CDMSCommEvents.h"
#include "CMSComm.h"
#include <string.h>


class CSPK_1_SerialComDlgAutoProxy;


// CSPK_1_SerialComDlg dialog
class CSPK_1_SerialComDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSPK_1_SerialComDlg);
	friend class CSPK_1_SerialComDlgAutoProxy;

// Construction
public:
	CSPK_1_SerialComDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CSPK_1_SerialComDlg();

// Dialog Data
	enum { IDD = IDD_SPK_1_SERIALCOM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	CSPK_1_SerialComDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
	CTchart1 m_chart;
	CMscomm1 m_comm;
	char in;
	int COM;
	CString m_edit_1;
	CString m_edit_2;
//	int m_intEadit;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	DECLARE_EVENTSINK_MAP()
	void OnCommMscomm1();
//	int m_intEdit;
	afx_msg void OnLbnSelchangeList1();
	CListBox m_listBox;
	void LoadListBox();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	CString m_setPoint;
	CString m_pid;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	CString m_pwm;
};
