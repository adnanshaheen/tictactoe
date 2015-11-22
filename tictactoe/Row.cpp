/**
 * Row.cpp
 *
 * Implementation details of CRow class
 */

/**
 * Headers
 */
#include "Row.h"
using namespace tictactoe;

/**
 * Constructor
 *
 * Default Constructor
 *
 * Throws any exception raised
 */
CRow::CRow() throw() : m_pRow(NULL), m_uCols(0)
{
}

/**
 * Constructor
 *
 * Constructor that creates an array
 *
 * Throws any exception raised
 */
CRow::CRow(unsigned int uSize) throw() : m_uCols(uSize)
{
	InitRow();
}

/**
 * Copy Constructor
 *
 * @param: cRow, to copy from
 *
 * Creates a new copy of object
 * Initialize all data members using cRow
 *
 * Throws any exception raised
 */
CRow::CRow(const CRow& cRow) throw()
{
	SetSize(cRow.GetSize());

	if (GetSize() > 0 && cRow.GetRow() != NULL) {
		InitRow();
		CopyData(cRow);
	}
}

/**
 * Destructor
 *
 * Destructor, Release memory created by CRows
 *
 * Catches any exception
 */
CRow::~CRow()
{
	try {
		ReleaseRow();
	}
	catch (...) {
		// Don't throw exception from Destructor
	}
}

/**
 * operator []
 *
 * return: int, item
 *
 * @param: nIndex
 *
 * Find the item at nIndex, and return it
 *
 * Throws any exception
 */
int CRow::operator [] (unsigned int nIndex) throw()
{
	return GetAt(nIndex);
}

/**
 * operator =
 *
 * return: CRow&
 *
 * @param: cRow, to copy data from
 *
 * Initialize all data members using cRow
 *
 * Catches and throws any exception
 */
CRow& CRow::operator = (const CRow& cRow)
{
	try {
		if (this != &cRow) {
			SetSize(cRow.GetSize());

			if (GetSize() > 0 && cRow.GetRow() != NULL) {
				InitRow();
				CopyData(cRow);
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
 * Display current row
 *
 * Throws any exception raised
 */
void CRow::Display() const throw()
{
	Display(cout);
}

/**
 * InitRow
 *
 * return: void
 *
 * @param: none
 *
 * Release any memory if created
 * Create CRows
 *
 * Catches and Throws any exception raised
 */
void CRow::InitRow()
{
	try {
		ReleaseRow();
		m_pRow = new int [m_uCols];
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
 * ReleaseRow
 *
 * return: void
 *
 * @param: none
 *
 * Release any memory if created
 *
 * Catches and Throws any exception raised
 */
void CRow::ReleaseRow()
{
	try {
		if (IsValid()) {
			delete []m_pRow;
			m_pRow = NULL;
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
 * CopyData
 *
 * return: void
 *
 * @param: cRow
 *
 * Copy the data from cRow
 *
 * Catches and Throws any exception raised
 */
void CRow::CopyData(const CRow& cRow)
{
	try {
		if (IsValid() && GetSize() == cRow.GetSize()) {
			for (unsigned int nIndex = 0; nIndex < GetSize(); ++ nIndex)
				m_pRow[nIndex] = cRow.GetAt(nIndex);
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
 * Display the CRow
 *
 * Catches and Throws any exception raised
 */
void CRow::Display(ostream& cOut) const
{
	try {
		cOut << "| ";
		for (unsigned int nIndex = 0; nIndex < GetSize(); ++ nIndex)
			cOut << "{" << (char) GetAt(nIndex) << "} | ";
		cOut << endl;
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
 * Display the CRow
 *
 * Catches and Throws any exception raised
 */
ostream& tictactoe::operator << (ostream& cOut, const CRow& cRow)
{
	try {
		cRow.Display(cOut);
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
