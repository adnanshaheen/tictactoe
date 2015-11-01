
#include "Board.h"
#include "Row.h"

CBoard::CBoard() : m_ppRow(NULL), m_uRows(0), m_uCols(0)
{
}

CBoard::CBoard(unsigned int uRows, unsigned int uCols) : m_uRows(uRows), m_uCols(uCols)
{
	Init();
}

CBoard::CBoard(const CBoard& cBoard)
{
	SetRows(cBoard.GetRows());
	SetCols(cBoard.GetCols());
	if (cBoard.IsValid()) {
		Init();
		CopyData(cBoard);
	}
}

CBoard::~CBoard()
{
	Release();
}

ostream& CBoard::operator << (ostream& cOut)
{
	Display(cOut);
	return cOut;
}

CRow* CBoard::operator [] (unsigned int nIndex)
{
	return GetAt(nIndex);
}

CBoard& CBoard::operator = (const CBoard& cBoard)
{
	if (this != &cBoard) {
		SetRows(cBoard.GetRows());
		SetCols(cBoard.GetCols());
		if (cBoard.IsValid()) {
			Init();
			CopyData(cBoard);
		}
	}
	return *this;
}

inline int CBoard::GetRows() const
{
	return m_uRows;
}

inline void CBoard::SetRows(const unsigned int uRows)
{
	m_uRows = uRows;
}

inline int CBoard::GetCols() const
{
	return m_uCols;
}

inline void CBoard::SetCols(const unsigned int uCols)
{
	m_uCols = uCols;
}

inline CRow* CBoard::GetAt(const unsigned int uRow) const
{
	return IsValid() ? m_ppRow[uRow] : NULL;
}

inline void CBoard::SetAt(const unsigned int uRow, CRow* const pRow)
{
	if (IsValid())
		m_ppRow[uRow] = pRow;
}

inline int CBoard::GetAt(const unsigned int uRow, const unsigned int uCol) const
{
	return IsValid(uRow) ? m_ppRow[uRow]->GetAt(uCol) : -1;
}

inline void CBoard::SetAt(const unsigned int uRow, const unsigned int uCol, const int nValue)
{
	if (IsValid(uRow))
		m_ppRow[uRow]->SetAt(uCol, nValue);
}

void CBoard::Display() const
{
	Display(cout);
}

void CBoard::Init()
{
	Release();
	m_ppRow = new CRow* [GetRows()];
	for (int nIndex = 0; nIndex < GetRows(); ++ nIndex)
		m_ppRow[nIndex] = new CRow(GetCols());
}

void CBoard::Release()
{
	if (IsValid()) {
		for (int nIndex = 0; nIndex < GetRows(); ++ nIndex) {
			if (IsValid(nIndex))
				delete[] m_ppRow[nIndex];
		}
		delete[] m_ppRow;
	}
}

void CBoard::Display(ostream& cOut) const
{
	// FIXME: print messages missing for board
	for (int nIndex = 0; nIndex < GetRows(); ++ nIndex) {
		if (IsValid(nIndex))
			cOut << m_ppRow[nIndex];
	}
}

inline bool CBoard::IsValid() const
{
	return m_ppRow != NULL ? true : false;
}

inline bool CBoard::IsValid(const unsigned int uRow) const
{
	return IsValid() && m_ppRow[uRow] != NULL ? true : false;
}

void CBoard::CopyData(const CBoard& cBoard)
{
	for (int nIndex = 0; nIndex < cBoard.GetRows(); ++ nIndex)
		GetAt(nIndex)->CopyData(*cBoard.GetAt(nIndex));
}
