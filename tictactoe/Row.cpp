
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
		for (unsigned int nIndex = 0; nIndex < GetSize(); ++ nIndex)
			m_pRow[nIndex] = cRow.GetAt(nIndex);
	}
}

void CRow::Display(ostream& cOut) const
{
	cOut << "| ";
	for (unsigned int nIndex = 0; nIndex < GetSize(); ++ nIndex)
		cOut << "{" << GetAt(nIndex) << "} | ";
	cOut << endl;
}

ostream& operator << (ostream& cOut, const CRow& cRow)
{
	cRow.Display(cOut);
	return cOut;
}
