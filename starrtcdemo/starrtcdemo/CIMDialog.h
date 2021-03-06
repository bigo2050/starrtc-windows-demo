#pragma once
#include "CUserManager.h"
#include "CConfigManager.h"

// CIMDialog 对话框

class CIMDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CIMDialog)

public:
	CIMDialog(CUserManager* pUserManager, CConfigManager* pConfig, CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CIMDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_IM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonImOneToOne();
	CUserManager* m_pUserManager;
	afx_msg void OnBnClickedButtonChatroom();
	afx_msg void OnBnClickedButtonImGroup();
private:
	CConfigManager* m_pConfig;
};
