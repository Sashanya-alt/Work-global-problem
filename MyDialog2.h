#pragma once


// Диалоговое окно MyDialog2

class MyDialog2 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDialog2)

public:
	MyDialog2(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~MyDialog2();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETTINGS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	
	afx_msg void OnClickedUP();
	afx_msg void OnHdnItemclickList2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnKeydownList2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclickList2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemdblclickList2(NMHDR* pNMHDR, LRESULT* pResult);
	CListCtrl MyListCtrl;
	afx_msg void OnClickedTest();
	afx_msg void OnBnClickedOk();
};
