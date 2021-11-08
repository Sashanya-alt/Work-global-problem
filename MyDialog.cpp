// MyDialog.cpp: файл реализации
//

//#include <string>
#include "pch.h"
#include "MFCApplication5.h"
#include "MyDialog.h"
#include "MyDialog2.cpp"
#include "afxdialogex.h"
#include "Struct.h"

// Диалоговое окно MyDialog

IMPLEMENT_DYNAMIC(MyDialog, CDialogEx)

//struct Data
//{
//	bool Visible;
//	char Name;
//};

//struct Data data;

MyDialog::MyDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MAIN, pParent)
{

}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialogEx)
	//ON_BN_CLICKED(IDC_BUTTON1, &MyDialog::OnBnClickedButton1)
	ON_WM_CREATE()
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()


// Обработчики сообщений MyDialog

int MyDialog::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;
	return 0;
}


BOOL MyDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Добавить дополнительную инициализацию

	auto listctrl = GetDlgItem(IDC_LIST4);

	LV_COLUMN col;
	col.mask = LVCF_TEXT | LVCF_WIDTH;
	col.pszText = _T("Column 1");
	col.cx = 100;
	auto ret = ListView_InsertColumn(listctrl->m_hWnd, 0, &col);

	//LV_COLUMN col;
	col.mask = LVCF_TEXT | LVCF_WIDTH;
	col.pszText = _T("Column 2");
	col.cx = 100;
	ret = ListView_InsertColumn(listctrl->m_hWnd, 1, &col);

	col.mask = LVCF_TEXT | LVCF_WIDTH;
	col.pszText = _T("Column 3");
	col.cx = 100;
	ret = ListView_InsertColumn(listctrl->m_hWnd, 2, &col);

	//myData.Visible = TRUE;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // Исключение: страница свойств OCX должна возвращать значение FALSE
}

void MyDialog::OnContextMenu(CWnd* pWnd/*pWnd*/, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений
	CMenu menu, * pMenu;
	auto listctrl = GetDlgItem(IDC_LIST4);
	if (menu.LoadMenu(IDR_MENU1) && (pMenu = menu.GetSubMenu(0)) != NULL)
	{
		CString strObjName;
		// get clicked object (for Rename & Current Representation commands)
		LV_HITTESTINFO htInfo;
		htInfo.pt = point;
		ScreenToClient(&htInfo.pt);
		int iContextItem = ListView_HitTest(m_hWnd, &htInfo);

		// find rep submenu
		CMenu* pRepMenu = NULL;
		int nRepMenuPos = -1;
		for (int i = 0; i < pMenu->GetMenuItemCount(); i++)
			if (pMenu->GetMenuItemID(i) == -1)
			{
				nRepMenuPos = i;
				pRepMenu = pMenu->GetSubMenu(i);
			}

		//// Отображаем меню
		//UINT uCmd = pMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON | TPM_RIGHTBUTTON | TPM_NONOTIFY | TPM_RETURNCMD,
		//	point.x, point.y, this);

		//if ((::GetWindowRect(but, &rect))== (ScreenToClient(&pos)))

		HWND dHeader = ListView_GetHeader(listctrl->m_hWnd);

		RECT rcWnd;
		//	GetClientRect(&rcWnd);	
		CPoint MyPoint;

		if ((::ScreenToClient(dHeader, &point)) && (::GetClientRect(dHeader, &rcWnd)))
		{
			MyPoint.x = rcWnd.right;
			MyPoint.y = rcWnd.bottom;
			//::ScreenToClient(dHeader, &MyPoint);
			bool a = (rcWnd.left < point.x);
			bool b = (point.x < MyPoint.x);
			bool c = rcWnd.top < point.y;
			bool d = point.y < MyPoint.y;
			if (a && b && c && d)
			{
				::ClientToScreen(dHeader, &point);
				// Отображаем меню
				UINT uCmd = pMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON | TPM_RIGHTBUTTON | TPM_NONOTIFY | TPM_RETURNCMD,
					point.x, point.y, this);

				switch (uCmd)
				{
					case ID_MENUE_SETTINGS:
					{

						MyDialog2 Dlg;

						// Create and show the dialog box
						INT_PTR nRet = -1;
						nRet = Dlg.DoModal();

						auto listctrl = GetDlgItem(IDC_LIST4);
						LV_COLUMN col;
						

						//надо чтобы сюда заходилось после нажатия на ок в диалоге 2
						ListView_DeleteColumn(listctrl->m_hWnd, 0);
						ListView_DeleteColumn(listctrl->m_hWnd, 1);
						ListView_DeleteColumn(listctrl->m_hWnd, 0);//удаление column 2
						//ListView_DeleteColumn(listctrl->m_hWnd, 2);
						//auto ret = ListView_SetColumnWidth(listctrl->m_hWnd, 0, 0);
						//ret = ListView_SetColumnWidth(listctrl->m_hWnd, 1, 0);
						TCHAR szBuffer[1024];
						TCHAR szBuffer2[1024];
						DWORD cchBuf(1024);
						CString strCol;
						
						int t = MyData.subsequence[1];

						col.cx = 100;
						col.mask = LVCF_TEXT | LVCF_WIDTH;
						col.pszText = szBuffer;
						col.cchTextMax = cchBuf;
						//strCol.Format (_T("Column %d"),  data.subsequence[1]);

						for (int i = 0; i < 3; i++)
						{
							strCol.Format(_T("Column  %d"), MyData.subsequence[i]);
							auto ret = ListView_InsertColumn(listctrl->m_hWnd, i, &col);
							col.pszText = (LPTSTR)(LPCTSTR)(strCol);
						}



						//auto ret = ListView_InsertColumn(listctrl->m_hWnd, 0, &col);

					/*	for (int i = 0; i < 3; i++)
						{
							strCol.Format(_T("Column  %d"), data.subsequence[i] );
							auto ret = ListView_InsertColumn(listctrl->m_hWnd, i, &col);
						}*/

	
						//auto ret = ListView_InsertColumn(listctrl->m_hWnd, 1, &col);
						//// Выясняем текущее состояние chechbox'а.
						//LRESULT res = SendMessage(IDC_CHECK1, BM_GETCHECK, 0);

						//struct Data data;

						//// Если галочка стоит.
						//if (res == BST_CHECKED)
						//{
						//	//data.Visible = TRUE;
						//	auto ret = ListView_SetColumnWidth(listctrl->m_hWnd, 0, 40);
						//}
						//// Если галочка не стоит.
						//if (res == BST_UNCHECKED)
						//{
						//	auto ret = ListView_SetColumnWidth(listctrl->m_hWnd, 0, 0);
						//	//data.Visible = FALSE;
						//}			

						///*if (data.Visible == TRUE)
						//{
						//	ret = ListView_SetColumnWidth(listctrl->m_hWnd, 0, 40);
						//	
						//}*/

						break;
					}
				}
			}
		}
	}
}