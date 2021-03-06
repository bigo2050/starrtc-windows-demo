#pragma once
#include <list>
#include <map>
#include <vector>

using namespace std;

#include "IWhitePanelCallback.h"

class CDrawLineData {
public:
	list<CPoint> points;
	int lineColor;
};

class CUserDrawInfo
{
public:
	list<CDrawLineData> drawData;
};
// CWhitePanelDlg 对话框

class CWhitePanelDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CWhitePanelDlg)

public:
	CWhitePanelDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CWhitePanelDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_WHITE_PANEL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
public:
	void setWhitePanelCallback(IWhitePanelCallback* pWhitePanelCallback, string strTarget);
	void setAction(string strTarget, vector<CWhitePanelInfo>& info);
	//打开激光笔
	void laserPenOn();
	//关闭激光笔
	void laserPenOff();

	void isGetData(bool bGetData);

	void setLineColor(int nColor);

	void revoke(string strTarget);

	void clear();
private:
	bool m_bGetData;
	bool m_bDraw;
	bool m_bLaserOn;
	int m_lineColor;
	CPoint m_StartPoint;
	list<CPoint> points;
	map<string, CPoint> m_LaserPen;
	string m_strTarget;
	map<string, CUserDrawInfo> m_DrawLineData;
	IWhitePanelCallback* m_pWhitePanelCallback;
public:
	afx_msg void OnPaint();
};
