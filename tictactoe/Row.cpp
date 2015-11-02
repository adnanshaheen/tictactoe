
#include "Row.h"

CRow::CRow() : m_pRow(NULL), m_uCols(0)
{
}

CRow::CRow(unsigned int uSize) : m_uCols(uSize)
{
	InitRow();
}

CRow::CRow(const CRow& cRow)
{
	SetSize(cRow.GetSize());

	if (GetSize() > 0 && cRow.GetRow() != NULL) {
		InitRow();
		CopyData(cRow);
	}
}

CRow::~CRow()
{
	ReleaseRow();
}

int CRow::operator [] (unsigned int nIndex)
{
	return GetAt(nIndex);
}

CRow& CRow::operator = (const CRow& cRow)
{
	if (this != &cRow) {
		SetSize(cRow.GetSize());

		if (GetSize() > 0 && cRow.GetRow() != NULL) {
			InitRow();
			CopyData(cRow);
		}
	}
	return *this;
}

inline int* CRow::GetRow() const
{
	return m_pRow;
}

inline void CRow::SetRow(int* const pRow)
{
	m_pRow = pRow;
}

inline unsigned int CRow::GetSize() const
{
	return m_uCols;
}

inline void CRow::SetSize(const unsigned int uSize)
{
	m_uCols = uSize;
}

inline int CRow::GetAt(const unsigned int uIndex) const
{
	return IsValid() && uIndex < GetSize() ? m_pRow[uIndex] : -1;
}

void CRow::SetAt(const unsigned int uIndex, const int nValue)
{
	if (IsValid() && uIndex < GetSize())
		m_pRow[uIndex] = nValue;
}

void CRow::Display() const
{
	Display(cout);
}

void CRow::InitRow()
{
	ReleaseRow();
	m_pRow = new int [m_uCols];
}

void CRow::ReleaseRow()
{
	if (IsValid()) {
		delete []m_pRow;
		m_pRow = NULL;
	}
}

void CRow::CopyData(const CRow& cRow)
{
	if (IsValid() && GetSize() == cRow.GetSize()) {
#pragma warning(disable: 4018)
		for (int nIndex = 0; nIndex < GetSize(); ++ nIndex)
#pragma warning(default : 4018)
			m_pRow[nIndex] = cRow.GetAt(nIndex);
	}
}

void CRow::Display(ostream& cOut) const
{
	cOut << "| ";
#pragma warning(disable: 4018)
	for (int nIndex = 0; nIndex < GetSize(); ++ nIndex)
#pragma warning(default: 4018)
		cOut << "{ " << GetAt(nIndex) << "} | ";
	cOut << endl;
}

inline bool CRow::IsValid() const
{
	return m_pRow != NULL ? true : false;
}

ostream& operator << (ostream& cOut, const CRow& cRow)
{
	cRow.Display(cOut);
	return cOut;
}
