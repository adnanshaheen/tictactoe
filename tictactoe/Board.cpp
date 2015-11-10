
#include "Board.h"
#include "Row.h"

using namespace tictactoe;

CBoard::CBoard() : m_ppRow(NULL), m_uRows(0), m_uCols(0)
{
}

CBoard::CBoard(unsigned int uRows, unsigned int uCols) : m_uRows(uRows), m_uCols(uCols)
{
	Init();
	InitData();
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
				delete m_ppRow[nIndex];
		}
		delete[] m_ppRow;
	}
}

void CBoard::Display(ostream& cOut) const
{
	cOut << " -----------------" << endl;
	for (int nIndex = 0; nIndex < GetRows(); ++ nIndex) {
		if (IsValid(nIndex)) {
			cOut << "|     |     |     |" << endl;
			cOut << *m_ppRow[nIndex];
			cOut << "|     |     |     |" << endl;
			cOut << " -----------------" << endl;
		}
	}
}

int CBoard::GetAt(const unsigned int uRow, const unsigned int uCol) const
{
	return IsValid(uRow) ? m_ppRow[uRow]->GetAt(uCol) : -1;
}

void CBoard::SetAt(const unsigned int uRow, const unsigned int uCol, const int nValue)
{
	if (IsValid(uRow))
		m_ppRow[uRow]->SetAt(uCol, nValue);
}

void CBoard::CopyData(const CBoard& cBoard)
{
	for (int nIndex = 0; nIndex < cBoard.GetRows(); ++ nIndex)
		GetAt(nIndex)->CopyData(*cBoard.GetAt(nIndex));
}


void CBoard::InitData()
{
	int nIndex = 48;		// initialize with ascii value of 0
	for (int uRow = 0; uRow < GetRows(); ++ uRow)
		for (int uCol = 0; uCol < GetCols(); ++ uCol)
			SetAt(uRow, uCol, nIndex ++);
}

ostream& tictactoe::operator << (ostream& cOut, const CBoard& cBoard)
{
	cBoard.Display(cOut);
	return cOut;
}
