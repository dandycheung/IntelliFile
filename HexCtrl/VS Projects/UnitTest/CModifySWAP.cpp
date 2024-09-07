#include "stdafx.h"
#include "CHexCtrlInit.h"
#include "CppUnitTest.h"

namespace TestHexCtrl {
	TEST_CLASS(CModifySWAP) {
private:
	static constexpr auto m_iRangeToTest = 18; //How many elements of given type to test.
	IHexCtrl* m_pHex { GetHexCtrl() };
public:
	template<typename T>
	void OperTData(T tData, HEXSPAN hsp) {
		ModifyOperTData(OPER_SWAP, tData, hsp);
	}

	//Test methods.

	TEST_METHOD(OperInt16) {
		constexpr std::int16_t i16Set = 1234;
		constexpr std::int16_t i16Oper = 0;
		constexpr std::int16_t i16Result = ByteSwap(i16Set);
		const HEXSPAN hss { 0, m_pHex->GetDataSize() };
		AssignTData(i16Set, hss);
		OperTData(i16Oper, hss);
		const auto spnData = m_pHex->GetData(hss);
		for (auto i = 0; i < sizeof(std::int16_t) * m_iRangeToTest; i += sizeof(std::int16_t)) {
			Assert::AreEqual(i16Result, GetTData<std::int16_t>(&spnData[i]));
		}
	}
	TEST_METHOD(OperUInt16) {
		constexpr std::uint16_t ui16Set = 1234;
		constexpr std::uint16_t ui16Oper = 0;
		constexpr std::uint16_t ui16Result = ByteSwap(ui16Set);
		const HEXSPAN hss { 0, m_pHex->GetDataSize() };
		AssignTData(ui16Set, hss);
		OperTData(ui16Oper, hss);
		const auto spnData = m_pHex->GetData(hss);
		for (auto i = 0; i < sizeof(std::uint16_t) * m_iRangeToTest; i += sizeof(std::uint16_t)) {
			Assert::AreEqual(ui16Result, GetTData<std::uint16_t>(&spnData[i]));
		}
	}
	TEST_METHOD(OperInt32) {
		constexpr std::int32_t i32Set = 12345678;
		constexpr std::int32_t i32Oper = 0;
		constexpr std::int32_t i32Result = ByteSwap(i32Set);
		const HEXSPAN hss { 0, m_pHex->GetDataSize() };
		AssignTData(i32Set, hss);
		OperTData(i32Oper, hss);
		const auto spnData = m_pHex->GetData(hss);
		for (auto i = 0; i < sizeof(std::int32_t) * m_iRangeToTest; i += sizeof(std::int32_t)) {
			Assert::AreEqual(i32Result, GetTData<std::int32_t>(&spnData[i]));
		}
	}
	TEST_METHOD(OperUInt32) {
		constexpr std::uint32_t ui32Set = 12345678;
		constexpr std::uint32_t ui32Oper = 0;
		constexpr std::uint32_t ui32Result = ByteSwap(ui32Set);
		const HEXSPAN hss { 0, m_pHex->GetDataSize() };
		AssignTData(ui32Set, hss);
		OperTData(ui32Oper, hss);
		const auto spnData = m_pHex->GetData(hss);
		for (auto i = 0; i < sizeof(std::uint32_t) * m_iRangeToTest; i += sizeof(std::uint32_t)) {
			Assert::AreEqual(ui32Result, GetTData<std::uint32_t>(&spnData[i]));
		}
	}
	TEST_METHOD(OperInt64) {
		constexpr std::int64_t i64Set = 12345678987;
		constexpr std::int64_t i64Oper = 0;
		constexpr std::int64_t i64Result = ByteSwap(i64Set);
		const HEXSPAN hss { 0, m_pHex->GetDataSize() };
		AssignTData(i64Set, hss);
		OperTData(i64Oper, hss);
		const auto spnData = m_pHex->GetData(hss);
		for (auto i = 0; i < sizeof(std::int64_t) * m_iRangeToTest; i += sizeof(std::int64_t)) {
			Assert::AreEqual(i64Result, GetTData<std::int64_t>(&spnData[i]));
		}
	}
	TEST_METHOD(OperUInt64) {
		constexpr std::uint64_t ui64Set = 12345678987;
		constexpr std::uint64_t ui64Oper = 0;
		constexpr std::uint64_t ui64Result = ByteSwap(ui64Set);
		const HEXSPAN hss { 0, m_pHex->GetDataSize() };
		AssignTData(ui64Set, hss);
		OperTData(ui64Oper, hss);
		const auto spnData = m_pHex->GetData(hss);
		for (auto i = 0; i < sizeof(std::uint64_t) * m_iRangeToTest; i += sizeof(std::uint64_t)) {
			Assert::AreEqual(ui64Result, GetTData<std::uint64_t>(&spnData[i]));
		}
	}
	TEST_METHOD(OperFloat) {
		constexpr float flSet = 123456789.87654321F;
		constexpr float flOper = 0.0F;
		constexpr float flResult = ByteSwap(flSet);
		const HEXSPAN hss { 0, m_pHex->GetDataSize() };
		AssignTData(flSet, hss);
		OperTData(flOper, hss);
		const auto spnData = m_pHex->GetData(hss);
		for (auto i = 0; i < sizeof(float) * m_iRangeToTest; i += sizeof(float)) {
			Assert::AreEqual(flResult, GetTData<float>(&spnData[i]), std::numeric_limits<float>::epsilon());
		}
	}
	TEST_METHOD(OperDouble) {
		constexpr double dblSet = 1234567898765.87654321;
		constexpr double dblOper = 0.0;
		constexpr double dblResult = ByteSwap(dblSet);
		const HEXSPAN hss { 0, m_pHex->GetDataSize() };
		AssignTData(dblSet, hss);
		OperTData(dblOper, hss);
		const auto spnData = m_pHex->GetData(hss);
		for (auto i = 0; i < sizeof(double) * m_iRangeToTest; i += sizeof(double)) {
			Assert::AreEqual(dblResult, GetTData<double>(&spnData[i]), std::numeric_limits<double>::epsilon());
		}
	}
	};
}