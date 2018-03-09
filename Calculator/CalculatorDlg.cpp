// CalculatorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "Token.h"
#include "Data.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalculatorDlg dialog

CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCalculatorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCalculatorDlg)
	m_List = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCalculatorDlg)
	DDX_Text(pDX, IDC_EDIT1, m_List);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialog)
	//{{AFX_MSG_MAP(CCalculatorDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON00, OnButton00)
	ON_BN_CLICKED(IDC_BUTTON0, OnButton0)
	ON_BN_CLICKED(IDC_BUTTON11, OnButton11)
	ON_BN_CLICKED(IDC_BUTTON22, OnButton22)
	ON_BN_CLICKED(IDC_BUTTON33, OnButton33)
	ON_BN_CLICKED(IDC_BUTTON44, OnButton44)
	ON_BN_CLICKED(IDC_BUTTON55, OnButton55)
	ON_BN_CLICKED(IDC_BUTTON66, OnButton66)
	ON_BN_CLICKED(IDC_BUTTON77, OnButton77)
	ON_BN_CLICKED(IDC_BUTTON88, OnButton88)
	ON_BN_CLICKED(IDC_BUTTON99, OnButton99)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_CUT, OnCut)
	ON_BN_CLICKED(IDC_RIDE, OnRide)
	ON_BN_CLICKED(IDC_REMOVE, OnRemove)
	ON_BN_CLICKED(IDC_CLEAR, OnClear)
	ON_BN_CLICKED(IDC_BACKSPACE, OnBackspace)
	ON_BN_CLICKED(IDC_EQUAL, OnEqual)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalculatorDlg message handlers

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalculatorDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		//CDialog::OnPaint();
		 CPaintDC   dc(this);   
           CRect   rect;   
           GetClientRect(&rect);   
           CDC   dcMem;   
           dcMem.CreateCompatibleDC(&dc);   
           CBitmap   bmpBackground;   
           bmpBackground.LoadBitmap(IDB_Bg);   //IDB_BITMAP是你自己的图对应的ID   ，由于我刚刚加入的位图资源 
                                                                             //被我命名成了IDB_Bg，因而我这句就是bmpBackground.LoadBitmap(IDB_Bg);  
                  
           BITMAP   bitmap;   
           bmpBackground.GetBitmap(&bitmap);   
           CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);   
           dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,   
         bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);

	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
CString  strCtrl,strCtr3;
char strCtr2;
Data a[100];
int i=-1;
double num1,num2,num3;
//Status InitStack(){};
void CCalculatorDlg::OnButton00() 
{
	// TODO: Add your control notification handler code here
	CString  str;
	GetDlgItemText(IDC_BUTTON00, str);
	strCtrl=strCtrl+str;
	SetDlgItemText(IDC_EDIT1,strCtrl);
	str="";
	
}

void CCalculatorDlg::OnButton0() 
{
	// TODO: Add your control notification handler code here
	CString  str;
	GetDlgItemText(IDC_BUTTON0, str);
	strCtrl=strCtrl+str;
	SetDlgItemText(IDC_EDIT1,strCtrl);
    str="";
}




void CAboutDlg::OnOK() 
{
	// TODO: Add extra validation here
	SetDlgItemText(IDC_EDIT1,strCtrl);
	
	CDialog::OnOK();
}

void CCalculatorDlg::OnButton11() 
{
	// TODO: Add your control notification handler code here
		CString  str;
	GetDlgItemText(IDC_BUTTON11, str);
	strCtrl=strCtrl+str;
	SetDlgItemText(IDC_EDIT1,strCtrl);
	str="";
	
}

void CCalculatorDlg::OnButton22() 
{
	// TODO: Add your control notification handler code here
		CString  str;
	GetDlgItemText(IDC_BUTTON22, str);
	strCtrl=strCtrl+str;
	SetDlgItemText(IDC_EDIT1,strCtrl);
	str="";
	
}

void CCalculatorDlg::OnButton33() 
{
	// TODO: Add your control notification handler code here
		CString  str;
	GetDlgItemText(IDC_BUTTON33, str);
	strCtrl=strCtrl+str;
	SetDlgItemText(IDC_EDIT1,strCtrl);
	str="";
}

void CCalculatorDlg::OnButton44() 
{
	// TODO: Add your control notification handler code here
		CString  str;
	GetDlgItemText(IDC_BUTTON44, str);
	strCtrl=strCtrl+str;
	SetDlgItemText(IDC_EDIT1,strCtrl);
	str="";
	
}

void CCalculatorDlg::OnButton55() 
{
	// TODO: Add your control notification handler code here
		CString  str;
	GetDlgItemText(IDC_BUTTON55, str);
	strCtrl=strCtrl+str;
	SetDlgItemText(IDC_EDIT1,strCtrl);
	str="";
	
}

void CCalculatorDlg::OnButton66() 
{
	// TODO: Add your control notification handler code here
		CString  str;
	GetDlgItemText(IDC_BUTTON66, str);
	strCtrl=strCtrl+str;
	SetDlgItemText(IDC_EDIT1,strCtrl);
	str="";
}

void CCalculatorDlg::OnButton77() 
{
	// TODO: Add your control notification handler code here
		CString  str;
	GetDlgItemText(IDC_BUTTON77, str);
	strCtrl=strCtrl+str;
	SetDlgItemText(IDC_EDIT1,strCtrl);
	str="";
	
}

void CCalculatorDlg::OnButton88() 
{
	// TODO: Add your control notification handler code here
		CString  str;
	GetDlgItemText(IDC_BUTTON88, str);
	strCtrl=strCtrl+str;
	SetDlgItemText(IDC_EDIT1,strCtrl);
	str="";
	
}

void CCalculatorDlg::OnButton99() 
{
	// TODO: Add your control notification handler code here
		CString  str;
	GetDlgItemText(IDC_BUTTON99, str);
	strCtrl=strCtrl+str;
	SetDlgItemText(IDC_EDIT1,strCtrl);
	str="";
	
}

void CCalculatorDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	num1=atof(strCtrl);
	++i;
	a[i].ch='+';
	a[i].volue=num1;
	CEdit* pedt = (CEdit*)GetDlgItem(IDC_EDIT1);
    pedt->SetWindowText("");
    strCtrl="";
	strCtr2='+';
	
}

void CCalculatorDlg::OnCut() 
{
	// TODO: Add your control notification handler code here
	num1=atof(strCtrl);
	++i;
	a[i].ch='-';
	a[i].volue=num1;
	CEdit* pedt = (CEdit*)GetDlgItem(IDC_EDIT1);
    pedt->SetWindowText("");
    strCtrl="";
	strCtr2='-';
}

void CCalculatorDlg::OnRide() 
{
	// TODO: Add your control notification handler code here
	num1=atof(strCtrl);
	++i;
	a[i].ch='*';
	a[i].volue=num1;
	CEdit* pedt = (CEdit*)GetDlgItem(IDC_EDIT1);
    pedt->SetWindowText("");
    strCtrl="";
	strCtr2='*';
}

void CCalculatorDlg::OnRemove() 
{
	// TODO: Add your control notification handler code here
	num1=atof(strCtrl);
	++i;
	a[i].ch='/';
	a[i].volue=num1;
	CEdit* pedt = (CEdit*)GetDlgItem(IDC_EDIT1);
    pedt->SetWindowText("");
    strCtrl="";
	strCtr2='/';
}

void CCalculatorDlg::OnClear() 
{
	// TODO: Add your control notification handler code here
	CEdit* pedt = (CEdit*)GetDlgItem(IDC_EDIT1);
    pedt->SetWindowText("");
	strCtrl="";
}

void CCalculatorDlg::OnBackspace() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE); 
	strCtrl = strCtrl.Left(strCtrl.GetLength()-1);
    SetDlgItemText(IDC_EDIT1,strCtrl);
	
}

double term(Data a[]);
double First(Data a[])
{
	i=0;
	double left=a[i].volue;
	while(a[i].ch!=' ')
	{
		switch(a[i].ch)
		{
		case'+':left+=term(a);
			break;
		case'-':left-=term(a);
			break;
        case'*'://left*=term(a);
			if((a[i+1].volue==0)&&(a[i+1].ch=='-'))
				{
					left*=(a[i+1].volue-a[i+2].volue);
					i=i+2;
					break;
				}
			else
			{
			left*=a[++i].volue;
			break;
			}
		case'/'://left/=term(a);
			if((a[i+1].volue==0)&&(a[i+1].ch=='-'))
				{
					left/=(a[i+1].volue-a[i+2].volue);
					i=i+2;
					break;
				}
			else
			{
			left/=a[++i].volue;
			break;
			}
			
		default:return left;
		}
	}
	return left;
}
double term(Data a[])
{
	double left=a[++i].volue;
	while(a[i].ch=='*'||a[i].ch=='/')
	{
        switch(a[i].ch)
		{
		case'*':if((a[i+1].volue==0)&&(a[i+1].ch=='-'))
				{
					left*=(a[i+1].volue-a[i+2].volue);
					i=i+2;
					break;
				}
		    	else
				{
			        left*=a[++i].volue;
			        break;
				}
		case'/':if((a[i+1].volue==0)&&(a[i+1].ch=='-'))
				{
					left/=(a[i+1].volue-a[i+2].volue);
					i=i+2;
					break;
				}
			   else
			   {
		    	left/=a[++i].volue;
			    break;
			   }
		//default:return left;
		}
	}
		return left;
}
void CCalculatorDlg::OnEqual() 
{
	// TODO: Add your control notification handler code here
	num2=atof(strCtrl);
	++i;
	a[i].ch=' ';
	a[i].volue=num2;
   	num3=First(a);
	strCtr3.Format("%0.2f",num3); 
	SetDlgItemText(IDC_EDIT1,strCtr3);
	strCtrl="";
	strCtr2=' ';
	strCtr3="";
    i=-1;
	num3=0;
}
