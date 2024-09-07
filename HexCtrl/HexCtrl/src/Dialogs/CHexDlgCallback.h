/****************************************************************************************
* Copyright © 2018-present Jovibor https://github.com/jovibor/                          *
* Hex Control for Windows applications.                                                 *
* Official git repository: https://github.com/jovibor/HexCtrl/                          *
* This software is available under "The HexCtrl License", see the LICENSE file.         *
****************************************************************************************/
#pragma once
#include <afxdialogex.h>
#include <string>

namespace HEXCTRL::INTERNAL {
	class CHexDlgCallback final : public CDialogEx {
	public:
		explicit CHexDlgCallback(std::wstring_view wsvOperName, std::wstring_view wsvCountName,
			ULONGLONG ullProgBarMin, ULONGLONG ullProgBarMax, CWnd* pParent = nullptr);
		[[nodiscard]] bool IsCanceled()const;
		void OnCancel()override;
		void SetCount(ULONGLONG ullCount);
		void SetProgress(ULONGLONG ullProgCurr);
	private:
		void DoDataExchange(CDataExchange* pDX)override;
		afx_msg void OnClose();
		afx_msg auto OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) -> HBRUSH;
		BOOL OnInitDialog()override;
		afx_msg void OnTimer(UINT_PTR nIDEvent);
		DECLARE_MESSAGE_MAP();
	private:
		static constexpr UINT_PTR m_uTimerCancelCheck { 0x1 };
		static constexpr auto m_iElapse { 100 }; //Milliseconds for the timer.
		CProgressCtrl m_stProgBar;
		std::wstring m_wstrOperName;
		std::wstring m_wstrCountName;   //Count name (e.g. Found, Replaced, etc...).
		ULONGLONG m_ullProgBarMin { };
		ULONGLONG m_ullProgBarPrev { }; //Previous timer tick progress.
		ULONGLONG m_ullProgBarCurr { };
		ULONGLONG m_ullProgBarMax { };
		ULONGLONG m_ullThousandth { };  //One thousandth part.
		ULONGLONG m_ullCount { };       //Count of found/replaced items.
		bool m_fCancel { false };
	};
}