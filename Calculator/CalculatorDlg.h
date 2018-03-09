// CalculatorDlg.h : header file
//

#if !defined(AFX_CALCULATORDLG_H__4581F2AE_5B8C_4A36_B999_E7BA3F7A5F1C__INCLUDED_)
#define AFX_CALCULATORDLG_H__4581F2AE_5B8C_4A36_B999_E7BA3F7A5F1C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCalculatorDlg dialog

class CCalculatorDlg : public CDialog
{
// Construction
public:
	CCalculatorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCalculatorDlg)
	enum { IDD = IDD_CALCULATOR_DIALOG };
	CString	m_List;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalculatorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCalculatorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton00();
	afx_msg void OnButton0();
	afx_msg void OnButton11();
	afx_msg void OnButton22();
	afx_msg void OnButton33();
	afx_msg void OnButton44();
	afx_msg void OnButton55();
	afx_msg void OnButton66();
	afx_msg void OnButton77();
	afx_msg void OnButton88();
	afx_msg void OnButton99();
	afx_msg void OnAdd();
	afx_msg void OnCut();
	afx_msg void OnRide();
	afx_msg void OnRemove();
	afx_msg void OnClear();
	afx_msg void OnBackspace();
	afx_msg void OnEqual();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALCULATORDLG_H__4581F2AE_5B8C_4A36_B999_E7BA3F7A5F1C__INCLUDED_)
