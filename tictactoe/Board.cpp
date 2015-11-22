/**
 * Board.cpp
 *
 * Implementation details of CBoard class
 */

/**
 * Headers
 */
#include "Board.h"
#include "Row.h"

using namespace tictactoe;

/**
 * Constructor
 *
 * Default Constructor
 *
 * Throws any exception raised
 */
CBoard::CBoard() throw() : m_ppRow(NULL), m_uRows(0), m_uCols(0)
{
}

/**
 * Constructor
 *
 * Create uRow number of Rows
 *
 * Throws any exception raised
 */
CBoard::CBoard(unsigned int uRows, unsigned int uCols) throw() : m_uRows(uRows), m_uCols(uCols)
{
	Init();
	InitData();
}

/**
 * Copy Constructor
 *
 * @param: cBoard, to copy from
 *
 * Creates a new copy of object
 * Initialize all data members using cBoard
 *
 * Throws any exception raised
 */
CBoard::CBoard(const CBoard& cBoard) throw()
{
	SetRows(cBoard.GetRows());
	SetCols(cBoard.GetCols());
	if (cBoard.IsValid()) {
		Init();
		CopyData(cBoard);
	}
}

/**
 * Destructor
 *
 * Destructor, Release memory created by CRows
 *
 * Catches any exception
 */
CBoard::~CBoard()
{
	try {
		Release();
	}
	catch (...) {
		// never throw exception from destructor
	}
}

/**
 * operator []
 *
 * return: CRow*, one complete array
 *
 * @param: nIndex
 *
 * Find the CRow* at nIndex, and return it
 *
 * Throws any exception
 */
CRow* CBoard::operator [] (unsigned int nIndex) throw()
{
	return GetAt(nIndex);
}

/**
 * operator =
 *
 * return: CBoard&
 *
 * @param: cBoard, to copy data from
 *
 * Initialize all data members using cBoard
 *
 * Catches and throws any exception
 */
CBoard& CBoard::operator = (const CBoard& cBoard)
{
	try {
		if (this != &cBoard) {
			SetRows(cBoard.GetRows());
			SetCols(cBoard.GetCols());
			if (cBoard.IsValid()) {
				Init();
				CopyData(cBoard);
			}
		}
	}
	catch (exception e)
	{
		cerr << e.what() << endl;
		throw e;
	}
	catch (...)
	{
		cerr << "Something bad happened!!!" << endl;
		cerr << "File: " << __FILE__ << endl;
		cerr << "Line: " << __LINE__ << endl;
		throw;
	}

	return *this;
}

/**
 * Display
 *
 * return: void
 *
 * @param: none
 *
 * Display current board layout
 *
 * Throws any exception raised
 */
void CBoard::Display() const throw()
{
	Display(cout);
}

/**
 * Init
 *
 * return: void
 *
 * @param: none
 *
 * Release any memory if created
 * Create Arrays of CRows
 *
 * Catches and Throws any exception raised
 */
void CBoard::Init()
{
	try {
		Release();
		m_ppRow = new CRow* [GetRows()];
		for (int nIndex = 0; nIndex < GetRows(); ++ nIndex)
			m_ppRow[nIndex] = new CRow(GetCols());
	}
	catch (exception e)
	{
		cerr << e.what() << endl;
		throw e;
	}
	catch (...)
	{
		cerr << "Something bad happened!!!" << endl;
		cerr << "File: " << __FILE__ << endl;
		cerr << "Line: " << __LINE__ << endl;
		throw;
	}
}

/**
 * Release
 *
 * return: void
 *
 * @param: none
 *
 * Release any memory if created
 * Delete all CRows
 *
 * Catches and Throws any exception raised
 */
void CBoard::Release()
{
	try {
		if (IsValid()) {
			for (int nIndex = 0; nIndex < GetRows(); ++ nIndex) {
				if (IsValid(nIndex))
					delete m_ppRow[nIndex];
			}
			delete[] m_ppRow;
		}
	}
	catch (exception e)
	{
		cerr << e.what() << endl;
		throw e;
	}
	catch (...)
	{
		cerr << "Something bad happened!!!" << endl;
		cerr << "File: " << __FILE__ << endl;
		cerr << "Line: " << __LINE__ << endl;
		throw;
	}
}

/**
 * Display
 *
 * return: void
 *
 * @param: cOut
 *
 * Display the CRows to make a board
 *
 * Catches and Throws any exception raised
 */
void CBoard::Display(ostream& cOut) const
{
	try {
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
	catch (exception e)
	{
		cerr << e.what() << endl;
		throw e;
	}
	catch (...)
	{
		cerr << "Something bad happened!!!" << endl;
		cerr << "File: " << __FILE__ << endl;
		cerr << "Line: " << __LINE__ << endl;
		throw;
	}
}

/**
 * GetAt
 *
 * return: int
 *
 * @param: uRow
 * @param: uCol
 *
 * return the item at uRow and uCol
 *
 * Throws any exception raised
 */
int CBoard::GetAt(const unsigned int uRow, const unsigned int uCol) const throw()
{
	return IsValid(uRow) ? m_ppRow[uRow]->GetAt(uCol) : -1;
}

/**
 * SetAt
 *
 * return: void
 *
 * @param: uRow
 * @param: uCol
 * @param: nValue
 *
 * Set the nValue at uRow, uCol position
 *
 * Catches and Throws any exception raised
 */
void CBoard::SetAt(const unsigned int uRow, const unsigned int uCol, const int nValue)
{
	try {
		if (IsValid(uRow))
			m_ppRow[uRow]->SetAt(uCol, nValue);
	}
	catch (exception e)
	{
		cerr << e.what() << endl;
		throw e;
	}
	catch (...)
	{
		cerr << "Something bad happened!!!" << endl;
		cerr << "File: " << __FILE__ << endl;
		cerr << "Line: " << __LINE__ << endl;
		throw;
	}
}

/**
 * CopyData
 *
 * return: void
 *
 * @param: cBoard
 *
 * Copy the data from board
 *
 * Catches and Throws any exception raised
 */
void CBoard::CopyData(const CBoard& cBoard)
{
	try {
		for (int nIndex = 0; nIndex < cBoard.GetRows(); ++ nIndex)
			GetAt(nIndex)->CopyData(*cBoard.GetAt(nIndex));
	}
	catch (exception e)
	{
		cerr << e.what() << endl;
		throw e;
	}
	catch (...)
	{
		cerr << "Something bad happened!!!" << endl;
		cerr << "File: " << __FILE__ << endl;
		cerr << "Line: " << __LINE__ << endl;
		throw;
	}
}

/**
 * InitData
 *
 * return: void
 *
 * @param: none
 *
 * Initialize the data for board
 *
 * Catches and Throws any exception raised
 */
void CBoard::InitData()
{
	try {
		int nIndex = 48;		// initialize with ascii value of 0
		for (int uRow = 0; uRow < GetRows(); ++ uRow)
			for (int uCol = 0; uCol < GetCols(); ++ uCol)
				SetAt(uRow, uCol, nIndex ++);
	}
	catch (exception e)
	{
		cerr << e.what() << endl;
		throw e;
	}
	catch (...)
	{
		cerr << "Something bad happened!!!" << endl;
		cerr << "File: " << __FILE__ << endl;
		cerr << "Line: " << __LINE__ << endl;
		throw;
	}
}

/**
 * operator <<
 *
 * return: ostream
 *
 * @param: cOut
 *
 * Display the board
 *
 * Catches and Throws any exception raised
 */
ostream& tictactoe::operator << (ostream& cOut, const CBoard& cBoard)
{
	try {
		cBoard.Display(cOut);
	}
	catch (exception e)
	{
		cerr << e.what() << endl;
		throw e;
	}
	catch (...)
	{
		cerr << "Something bad happened!!!" << endl;
		cerr << "File: " << __FILE__ << endl;
		cerr << "Line: " << __LINE__ << endl;
		throw;
	}
	return cOut;
}
