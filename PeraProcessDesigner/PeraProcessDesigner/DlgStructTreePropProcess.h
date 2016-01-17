#pragma once
#include "CxStructTreeNodeFlow.h"

// CDlgStructTreePropProcess �Ի���

class CDlgStructTreePropProcess : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgStructTreePropProcess)

public:
	CDlgStructTreePropProcess(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgStructTreePropProcess();

// �Ի�������
	enum { IDD = IDD_STRUCTTREE_PROP_PROCESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedStppOk();
	afx_msg void OnBnClickedStppCancel();
	DECLARE_MESSAGE_MAP()
	// Edit�ؼ��ִ�����
	enum STRATEGY  //���ģʽ
	{
		STRATEGY_NODE,  //�ڵ�
		STRATEGY_DIR,   //Ŀ¼
		STRATEGY_NAME, //����
		STRATEGY_VERSION, //�汾
		STRATEGY_DEFAULT //Ĭ��
	};	
	bool CheckEdit( CEdit& edit, STRATEGY strategy = STRATEGY_DEFAULT , CString cName = "",int nLenLimit = 20);
public:
	CEdit m_wndName;
	CEdit m_wndAuthor;
	CEdit m_wndCreated;
	CEdit m_wndVersion;
	CEdit m_wndDescrp;
	CButton m_wndOk;
	CButton m_wndCancel;

	CCxStructTreeNodeFlow * m_pNode;
};