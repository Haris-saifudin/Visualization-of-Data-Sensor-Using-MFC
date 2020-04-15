
// SPK_1_SerialComDlg.cpp : implementation file
//
#include "stdafx.h"
#include "SPK_1_SerialCom.h"
#include "SPK_1_SerialComDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
	EnableActiveAccessibility();
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSPK_1_SerialComDlg dialog


IMPLEMENT_DYNAMIC(CSPK_1_SerialComDlg, CDialogEx);

CSPK_1_SerialComDlg::CSPK_1_SerialComDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSPK_1_SerialComDlg::IDD, pParent)
	//, m_chart(0)
	, m_edit_1(_T(""))
	, m_edit_2(_T(""))
	// m_intEdit(0)
	, m_setPoint(_T(""))
	, m_pid(_T(""))
	, m_pwm(_T(""))
{
	EnableActiveAccessibility();
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CSPK_1_SerialComDlg::~CSPK_1_SerialComDlg()
{
	// If there is an automation proxy for this dialog, set
	//  its back pointer to this dialog to NULL, so it knows
	//  the dialog has been deleted.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CSPK_1_SerialComDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TCHART1, m_chart);
	DDX_Control(pDX, IDC_MSCOMM1, m_comm);
	//  DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT1, m_edit_1);
	DDX_Text(pDX, IDC_EDIT2, m_edit_2);
	//	DDX_Text(pDX, IDC_EDIT3, m_intEdit);
	DDX_Control(pDX, IDC_LIST1, m_listBox);
	DDX_Text(pDX, IDC_EDIT3, m_setPoint);
	DDX_Text(pDX, IDC_EDIT4, m_pid);
	DDX_Text(pDX, IDC_EDIT5, m_pwm);
}

BEGIN_MESSAGE_MAP(CSPK_1_SerialComDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_BN_CLICKED(IDC_BUTTON1, &CSPK_1_SerialComDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSPK_1_SerialComDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CSPK_1_SerialComDlg::OnBnClickedButton3)
	ON_LBN_SELCHANGE(IDC_LIST1, &CSPK_1_SerialComDlg::OnLbnSelchangeList1)
	ON_EN_CHANGE(IDC_EDIT2, &CSPK_1_SerialComDlg::OnEnChangeEdit2)
	ON_WM_TIMER()
	ON_EN_CHANGE(IDC_EDIT3, &CSPK_1_SerialComDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CSPK_1_SerialComDlg::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_BUTTON4, &CSPK_1_SerialComDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CSPK_1_SerialComDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CSPK_1_SerialComDlg message handlers

BOOL CSPK_1_SerialComDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//menambahkan fungsi list box
	LoadListBox();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSPK_1_SerialComDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSPK_1_SerialComDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSPK_1_SerialComDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// Automation servers should not exit when a user closes the UI
//  if a controller still holds on to one of its objects.  These
//  message handlers make sure that if the proxy is still in use,
//  then the UI is hidden but the dialog remains around if it
//  is dismissed.

void CSPK_1_SerialComDlg::OnClose()
{
	if (CanExit())
		CDialogEx::OnClose();
}

void CSPK_1_SerialComDlg::OnOK()
{
	if (CanExit())
		CDialogEx::OnOK();
}

void CSPK_1_SerialComDlg::OnCancel()
{
	if (CanExit())
		CDialogEx::OnCancel();
}

BOOL CSPK_1_SerialComDlg::CanExit()
{
	// If the proxy object is still around, then the automation
	//  controller is still holding on to this application.  Leave
	//  the dialog around, but hide its UI.
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}


//fungsi button yang digunakan untuk mengirimkan data serial komunikasi
void CSPK_1_SerialComDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	CString sSatu(_T("\n"));
	UpdateData(TRUE);
	//mengirim data
	CString sSend = sSatu + m_edit_1;
	UpdateData(FALSE);

	char strPass[256];
	strcpy_s(strPass, CStringA(sSend).GetString());

	CByteArray hexdata;
	//kirim data per karakter
	hexdata.SetSize(sSend.GetLength());
	for (int i = 0; i < sSend.GetLength();i++){
		hexdata[i] = strPass[i];
	}

	UpdateData(TRUE);
	m_comm.put_Output(COleVariant(hexdata));
	UpdateData(FALSE);
}

//generate port serial komunikasi 
void CSPK_1_SerialComDlg::OnBnClickedButton2()
{
	CString sSetting = _T("115200,N,8,1");
	//mengatur port
	m_comm.put_CommPort(COM);
	//mengatur data bouterate , No parity, 8bit data, 1 stop bit
	m_comm.put_Settings(sSetting);
	m_comm.put_InputMode(0);
	//memberitahu untuk membaca input seluruhnya ketika input digunakan
	m_comm.put_InputLen(30);
	//RTS(request to send) dapat terkoneksi dan mengirimkan data.
	m_comm.put_RTSEnable(TRUE);
	m_comm.put_RThreshold(1);
	//membuka port
	m_comm.put_PortOpen(TRUE);

	
}


void CSPK_1_SerialComDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	//for (int i = 0; i < 20; i++){
	//	((CSeries)(m_chart.get_Series(0))).AddXY(i, Val[i], NULL, NULL);
	//}


}

//mengaktifkan serial komunikasi
BEGIN_EVENTSINK_MAP(CSPK_1_SerialComDlg, CDialogEx)
	ON_EVENT(CSPK_1_SerialComDlg, IDC_MSCOMM1, 1, CSPK_1_SerialComDlg::OnCommMscomm1, VTS_NONE)
END_EVENTSINK_MAP()




int time_x = 0;
int prevSP = 0;
int prevPID = 0;
int prevPWM = 0;

void CSPK_1_SerialComDlg::OnCommMscomm1()
{

	int i = 0;
	int pos = 0;
	CString space = _T(" ");
	//mendapatkan data serial arduino
	if (m_comm.get_CommEvent() == 2){
		VARIANT bytesReceived = m_comm.get_Input();
		CString strInput(bytesReceived.bstrVal);
		CString token[15];

		strInput.Trim();

		token[i] = strInput.Tokenize(space, pos);
		while (!token[i].IsEmpty()){
			i++;
			if (i == 4)
				break;
			token[i] = strInput.Tokenize(space, pos);
			m_edit_2 = strInput;
			
		}

		UpdateData(TRUE);

		if (i == 3){
			if (prevSP - _ttoi(token[0]) <= 400 && prevSP - _ttoi(token[0]) >= -400 ){
				m_edit_2 = strInput;
				m_setPoint = token[0];

				prevSP = _ttoi(m_setPoint);
			}
			if (prevPID - _ttoi(token[1]) <= 400 && prevPID - _ttoi(token[1]) >= -400){
				m_edit_2 = strInput;
				m_pid = token[1];
				prevPID = _ttoi(m_pid);
			}
			if (prevPWM - _ttoi(token[2]) <= 50 && prevPWM - _ttoi(token[2]) >= -50){
				m_edit_2 = strInput;
				m_pwm = token[2];
				prevPWM = _ttoi(m_pwm);
			}
		}

		UpdateData(FALSE);
	}
}

	//
	//sscanf((CT2A)strInput, "%c", &in);
	//UpdateData(TRUE);
	////mengisi history data
	//m_edit_2 += in; 


	//// Parsing data, membaca data serial dari arduino dengan format "#data_pwm$data_rpm@data_tegangan\n"
	////jika in merupakan karakter '#' sebagai format awal data. pointer ptr = alamat data awal pwm
	//if (in == '#'){
	//	
	//		ptr = &data_pwm[0];
	//}

	//else if (in == '$'){
	//	ptr = &rpm_frekuensi[0];
	//}
	//else if (in == '@'){
	//	ptr = &rpm_periode[0];
	//}
	//else if (in == '%'){
	//	ptr = &data_tegangan[0];
	//}

	////enkapsulasi data akhir 
	//else if (in == '\n'){
	//	//menampilkan grafik pada window
	//	//atof "asci to float" mengkonversi type data ke float
	//	((CSeries)(m_chart.get_Series(0))).AddXY(time_x, atof(data_pwm), NULL, 536870912);
	//	((CSeries)(m_chart.get_Series(1))).AddXY(time_x, atof(rpm_frekuensi), NULL, 536870912);
	//	((CSeries)(m_chart.get_Series(2))).AddXY(time_x, atof(rpm_periode), NULL, 536870912);
	//	((CSeries)(m_chart.get_Series(3))).AddXY(time_x, atof(data_tegangan), NULL, 536870912);
	//	//((CSeries)(m_chart.get_Series(0))).
	//	//posisi x
	//	time_x++;
	//}
	//else{
	//	//memilih data
	//	*ptr = in;
	//	ptr++;
	//}

	//
	//UpdateData(FALSE);
//}

//fungsi pada listBox
void CSPK_1_SerialComDlg::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here
	//memilih data port serial komunikasi 
	m_listBox.GetText(m_listBox.GetCurSel(), m_edit_2);
	COM = m_listBox.GetCurSel();
	UpdateData(FALSE);
}

//tampilan listBox
void CSPK_1_SerialComDlg::LoadListBox()
{
	CString str = _T(" ");
	for (int i = 1; i <= 10; i++){
		str.Format(_T("COM %d"),i);
		m_listBox.AddString(str);
		
	}
}


void CSPK_1_SerialComDlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CSPK_1_SerialComDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	UpdateData(TRUE);
	((CSeries)(m_chart.get_Series(0))).AddXY(time_x, _ttof(m_setPoint), NULL, 536870912);
	((CSeries)(m_chart.get_Series(1))).AddXY(time_x, _ttof(m_pid), NULL, 536870912);
	((CSeries)(m_chart.get_Series(2))).AddXY(time_x, _ttof(m_pwm), NULL, 536870912);
	time_x++;
	/*if (time_x == 1000){
		time_x = 0;
		((CSeries)(m_chart.get_Series(0))).Clear();
		((CSeries)(m_chart.get_Series(1))).Clear();
	}*/
	m_edit_2 = _T(" ");
	CDialogEx::OnTimer(nIDEvent);
}


void CSPK_1_SerialComDlg::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CSPK_1_SerialComDlg::OnEnChangeEdit4()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CSPK_1_SerialComDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString sendCommand = _T("-");
	m_comm.put_Output(COleVariant(sendCommand));
	KillTimer(0);
	prevSP = 0;
	prevPID = 0;
	prevPWM = 0;
	m_setPoint = "0";
	m_pid = "0";
	m_pwm = "0";
	//strInput =" ";

	UpdateData(FALSE);
}


void CSPK_1_SerialComDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString sendCommand = _T("+");
	m_comm.put_Output(COleVariant(sendCommand));
	SetTimer(0, 50, NULL);
	UpdateData(FALSE);
}
