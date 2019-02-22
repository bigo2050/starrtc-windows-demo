// CFaceFeatureRegisterDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "starrtcdemo.h"
#include "CFaceFeatureRegisterDlg.h"
#include "afxdialogex.h"


// CFaceFeatureRegisterDlg 对话框

IMPLEMENT_DYNAMIC(CFaceFeatureRegisterDlg, CDialogEx)

CFaceFeatureRegisterDlg::CFaceFeatureRegisterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_USER_REGISTER, pParent)
{
	m_nId = 0;
	m_strName = "";
	m_strPath = "";
	//m_FindFace.init();
}

CFaceFeatureRegisterDlg::~CFaceFeatureRegisterDlg()
{
	//m_FindFace.finalize();
}

void CFaceFeatureRegisterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_FEATURE_ID, m_EditId);
	DDX_Control(pDX, IDC_EDIT_REGISTER_USER_NAME, m_EditName);
	DDX_Control(pDX, IDC_EDIT_REGISTER_PIC_PATH, m_EditPath);
}


BEGIN_MESSAGE_MAP(CFaceFeatureRegisterDlg, CDialogEx)

	ON_BN_CLICKED(IDC_BUTTON_SELECT_REGISTER_PIC, &CFaceFeatureRegisterDlg::OnBnClickedButtonSelectRegisterPic)
END_MESSAGE_MAP()


// CFaceFeatureRegisterDlg 消息处理程序




void CFaceFeatureRegisterDlg::OnBnClickedButtonSelectRegisterPic()
{
	CString filter;
	filter = "图片(*.jpg)||";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, filter);
	if (dlg.DoModal() == IDOK)
	{
		CString path = dlg.GetPathName();
		m_EditPath.SetWindowText(path);
	}
}


void CFaceFeatureRegisterDlg::OnOK()
{
	/*if (!m_FindFace.m_bInit)
	{
		AfxMessageBox("初始化人脸识别失败");
		return;
	}
	CString strId = "";
	CString strName = "";
	CString strPath = "";
	m_EditId.GetWindowText(strId);
	if (strId.IsEmpty())
	{
		AfxMessageBox("请输出id");
		return;
	}
	int nId = atoi(strId);
	m_EditName.GetWindowText(strName);
	if (strName.IsEmpty())
	{
		AfxMessageBox("请输出用户名");
		return;
	}

	m_EditPath.GetWindowText(strPath);
	if (strPath.IsEmpty())
	{
		AfxMessageBox("请选择图片路径");
		return;
	}

	int result = m_FindFace.userRegister(nId, strName, strPath);
	if (result == 1)
	{
		AfxMessageBox("注册成功");
	}
	else
	{
		AfxMessageBox("注册失败");
	}*/

	CDialogEx::OnOK();
}
