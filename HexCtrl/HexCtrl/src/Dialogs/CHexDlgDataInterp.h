/****************************************************************************************
* Copyright © 2018-present Jovibor https://github.com/jovibor/                          *
* Hex Control for Windows applications.                                                 *
* Official git repository: https://github.com/jovibor/HexCtrl/                          *
* This software is available under "The HexCtrl License", see the LICENSE file.         *
****************************************************************************************/
#pragma once
#include "../../HexCtrl.h"
#include <afxcontrolbars.h>
#include <afxdialogex.h>

import HEXCTRL.HexUtility;

namespace HEXCTRL::INTERNAL {
	constexpr auto WM_PROPGRID_PROPERTY_SELECTED = WM_USER + 0x1U; //Message to the parent, when new property is selected.
	class CHexPropGridCtrl final : public CMFCPropertyGridCtrl {
	private:
		void OnChangeSelection(CMFCPropertyGridProperty* pNewProp, CMFCPropertyGridProperty* /*pOldProp*/)override {
			GetParent()->SendMessageW(WM_PROPGRID_PROPERTY_SELECTED, GetDlgCtrlID(), reinterpret_cast<LPARAM>(pNewProp));
		}
		void OnSize(UINT /*f*/, int /*cx*/, int /*cy*/) {
			EndEditItem();
			AdjustLayout();
		}
		DECLARE_MESSAGE_MAP();
	};

	//CHexDlgDataInterp.
	class CHexDlgDataInterp final : public CDialogEx {
	public:
		CHexDlgDataInterp();
		~CHexDlgDataInterp();
		[[nodiscard]] auto GetDlgItemHandle(EHexDlgItem eItem)const->HWND;
		[[nodiscard]] auto GetHglDataSize()const->DWORD;
		void Initialize(IHexCtrl* pHexCtrl);
		[[nodiscard]] bool HasHighlight()const;
		void SetDlgProperties(std::uint64_t u64Flags);
		BOOL ShowWindow(int nCmdShow);
		void UpdateData();
	private:
		union UMSDOSDateTime; //Forward declarations.
		union UDTTM;
		enum class EGroup : std::uint8_t;
		enum class EName : std::uint8_t;
		enum class EDataSize : std::uint8_t;
		struct GRIDDATA;
		void DoDataExchange(CDataExchange* pDX)override;
		[[nodiscard]] auto GetGridData(EName eName)const->const GRIDDATA*;
		[[nodiscard]] auto GetGridData(EName eName) -> GRIDDATA*; //Non-const overload.
		[[nodiscard]] bool IsBigEndian()const;
		[[nodiscard]] bool IsNoEsc()const;
		[[nodiscard]] bool IsShowAsHex()const;
		afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
		void OnCancel()override;
		afx_msg void OnCheckHex();
		afx_msg void OnCheckBigEndian();
		afx_msg void OnClose();
		afx_msg void OnDestroy();
		BOOL OnInitDialog()override;
		void OnOK()override;
		auto OnPropertyDataChanged(WPARAM wParam, LPARAM lParam) -> LRESULT;
		auto OnPropertySelected(WPARAM wParam, LPARAM lParam) -> LRESULT;
		void RedrawHexCtrl()const;
		[[nodiscard]] bool SetDataBinary(std::wstring_view wsv)const;
		template<typename T> requires TSize1248<T>
		[[nodiscard]] bool SetDataNUMBER(std::wstring_view wsv)const;
		[[nodiscard]] bool SetDataTime32(std::wstring_view wsv)const;
		[[nodiscard]] bool SetDataTime64(std::wstring_view wsv)const;
		[[nodiscard]] bool SetDataFILETIME(std::wstring_view wsv)const;
		[[nodiscard]] bool SetDataOLEDATETIME(std::wstring_view wsv)const;
		[[nodiscard]] bool SetDataJAVATIME(std::wstring_view wsv)const;
		[[nodiscard]] bool SetDataMSDOSTIME(std::wstring_view wsv)const;
		[[nodiscard]] bool SetDataMSDTTMTIME(std::wstring_view wsv)const;
		[[nodiscard]] bool SetDataSYSTEMTIME(std::wstring_view wsv)const;
		[[nodiscard]] bool SetDataGUID(std::wstring_view wsv)const;
		[[nodiscard]] bool SetDataGUIDTIME(std::wstring_view wsv)const;
		void SetGridRedraw(bool fRedraw);
		template <TSize1248 T> void SetTData(T tData)const;
		template <TSize1248 T> void ShowValueBinary(T tData)const;
		void ShowValueInt8(BYTE byte)const;
		void ShowValueUInt8(BYTE byte)const;
		void ShowValueInt16(WORD word)const;
		void ShowValueUInt16(WORD word)const;
		void ShowValueInt32(DWORD dword)const;
		void ShowValueUInt32(DWORD dword)const;
		void ShowValueInt64(QWORD qword)const;
		void ShowValueUInt64(QWORD qword)const;
		void ShowValueFloat(DWORD dword)const;
		void ShowValueDouble(QWORD qword)const;
		void ShowValueTime32(DWORD dword)const;
		void ShowValueTime64(QWORD qword)const;
		void ShowValueFILETIME(QWORD qword)const;
		void ShowValueOLEDATETIME(QWORD qword)const;
		void ShowValueJAVATIME(QWORD qword)const;
		void ShowValueMSDOSTIME(DWORD dword)const;
		void ShowValueMSDTTMTIME(DWORD dword)const;
		void ShowValueSYSTEMTIME(SYSTEMTIME stSysTime)const;
		void ShowValueGUID(GUID stGUID)const;
		void ShowValueGUIDTIME(GUID stGUID)const;
		DECLARE_MESSAGE_MAP();
	private:
		std::vector<GRIDDATA> m_vecGrid;
		IHexCtrl* m_pHexCtrl { };
		CHexPropGridCtrl m_gridCtrl;
		CButton m_btnHex;             //Check-box "Hex numbers".
		CButton m_btnBE;              //Check-box "Big endian".
		ULONGLONG m_ullOffset { };
		std::uint64_t m_u64Flags { }; //Data from SetDlgProperties.
		DWORD m_dwHglDataSize { };    //Size of the data to highlight in the HexCtrl.
		DWORD m_dwDateFormat { };     //Date format.
		wchar_t m_wchDateSepar { };   //Date separator.
	};
}