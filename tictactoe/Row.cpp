
#include "Row.h"

CRow::CRow() : m_pRow(NULL), m_uSize(0)
{
}

CRow::CRow(unsigned int uSize) : m_uSize(uSize)
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

ostream& CRow::operator << (ostream& cOut)
{
	Display(cOut);
	return cOut;
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
	return m_uSize;
}

inline void CRow::SetSize(const unsigned int uSize)
{
	m_uSize = uSize;
}

inline int CRow::GetAt(const unsigned int uIndex) const
{
	return m_pRow != NULL && uIndex < GetSize() ? m_pRow[uIndex] : -1;
}

void CRow::SetAt(const unsigned int uIndex, const int nValue)
{
	if (m_pRow != NULL && uIndex < GetSize())
		m_pRow[uIndex] = nValue;
}

void CRow::Display() const
{
	Display(cout);
}

void CRow::InitRow()
{
	ReleaseRow();
	m_pRow = new int [m_uSize];
}

void CRow::ReleaseRow()
{
	if (m_pRow != NULL) {
		delete []m_pRow;
		m_pRow = NULL;
	}
}

void CRow::CopyData(const CRow& cRow)
{
	if (m_pRow != NULL && GetSize() == cRow.GetSize()) {
		for (int nIndex = 0; nIndex < GetSize(); ++ nIndex)
			m_pRow[nIndex] = cRow.GetAt(nIndex);
	}
}

void CRow::Display(ostream& cOut) const
{
	cOut << "| ";
	for (int nIndex = 0; nIndex < GetSize(); ++ nIndex)
		cOut << "{ " << GetAt(nIndex) << "} | ";
	cOut << endl;
}
