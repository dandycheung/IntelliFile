/****************************************************************************************
* Copyright © 2018-present Jovibor https://github.com/jovibor/                          *
* Hex Control for Windows applications.                                                 *
* Official git repository: https://github.com/jovibor/HexCtrl/                          *
* This software is available under "The HexCtrl License", see the LICENSE file.         *
****************************************************************************************/
#pragma once
#include "../../HexCtrl.h"
#include <afxdialogex.h>
#include <memory>

namespace HEXCTRL::INTERNAL {
	class CHexDlgOpers;    //Forward declarations.
	class CHexDlgFillData;
	class CHexDlgModify final : public CDialogEx {
	public:
		CHexDlgModify();
		~CHexDlgModify();
		[[nodiscard]] auto GetDlgItemHandle(EHexDlgItem eItem)const->HWND;
		void Initialize(IHexCtrl* pHexCtrl);
		void SetDlgProperties(std::uint64_t u64Flags);
		BOOL ShowWindow(int nCmdShow, int iTab);
	private:
		void DoDataExchange(CDataExchange* pDX)override;
		[[nodiscard ]] bool IsNoEsc()const;
		afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
		void OnCancel()override;
		afx_msg void OnClose();
		afx_msg void OnDestroy();
		BOOL OnInitDialog()override;
		afx_msg void OnTabSelChanged(NMHDR* pNMHDR, LRESULT* pResult);
		void SetCurrentTab(int iTab);
		DECLARE_MESSAGE_MAP();
	private:
		IHexCtrl* m_pHexCtrl { };
		CTabCtrl m_tabMain;
		std::uint64_t m_u64Flags { }; //Data from SetDlgProperties.
		std::unique_ptr<CHexDlgOpers> m_pDlgOpers;       //"Operations" tab dialog.
		std::unique_ptr<CHexDlgFillData> m_pDlgFillData; //"Fill with" tab dialog.
	};
}