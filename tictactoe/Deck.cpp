/**
 * Deck.cpp
 *
 * Implementation details of CDeck class
 */

/**
 * Headers
 */
#include <algorithm>
#include "Deck.h"

using namespace tictactoe;

/**
 * Constructor
 *
 * Default Constructor, set board size
 * Clear choices
 * Create new CBoard of 3*3
 *
 * Throws any exception raised
 */
CDeck::CDeck() throw() : m_nBoardSize(3)
{
	m_pBoard = new CBoard(m_nBoardSize, m_nBoardSize);
	ClearChoices();
}

/**
 * Destructor
 *
 * Destructor, Release the board and clear choices
 *
 * Catches any exception
 */
CDeck::~CDeck()
{
	try {
		if (m_pBoard) {
			delete m_pBoard;
			m_pBoard = NULL;
		}
		ClearChoices();
	}
	catch (...) {
		// never throw exception from destructor
	}
}

/**
 * Copy Constructor
 *
 * @param: cDeck, to copy from
 *
 * Creates a new copy of object
 * Initialize all data members using cDeck
 *
 * Throws any exception raised
 */
CDeck::CDeck(const CDeck& cDeck) throw() : m_nBoardSize(3)
{
	m_pBoard = new CBoard();
	*m_pBoard = *cDeck.m_pBoard;
	ClearChoices();
	m_cPlayerOChoice = cDeck.m_cPlayerOChoice;
	m_cPlayerXChoice = cDeck.m_cPlayerXChoice;
}

/**
 * Assignment operator
 *
 * @params: cDeck, to copy data from
 *
 * Initialize all data members using cDeck
 *
 * Catches exception, and throws them back to caller
 */
CDeck& CDeck::operator = (const CDeck& cDeck)
{
	try {
		if (this != &cDeck) {
			*m_pBoard = *cDeck.m_pBoard;
			ClearChoices();
			m_cPlayerOChoice = cDeck.m_cPlayerOChoice;
			m_cPlayerXChoice = cDeck.m_cPlayerXChoice;
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
 * @params: none
 *
 * Display status of the deck
 *
 * Throws any exception raised
 */
void CDeck::Display() const throw()
{
	Display(cout);
}

/**
 * Display
 *
 * return: void
 *
 * @params: cOut
 *
 * Display the status of deck
 *
 * Catches and Throws any exception raised
 */
void CDeck::Display(ostream& cOut) const
{
	try {
		cOut << *m_pBoard << endl;
	}
	catch (exception e) {
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
 * InsertChoice
 *
 * return: void
 *
 * @param: bSymbolX
 * @param: nIndex
 *
 * Insert nIndex to it's relative list based on bSymbolX
 *
 * Catches and Throws any exception raised
 */
void CDeck::InsertChoice(bool bSymbolX, unsigned int nIndex)
{
	try {
		m_pBoard->SetAt(nIndex / 3, nIndex % 3, bSymbolX == true ? 88 : 79);
		if (bSymbolX)
			m_cPlayerXChoice.push_back(nIndex);
		else
			m_cPlayerOChoice.push_back(nIndex);
	}
	catch (exception e) {
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
 * ClearBoard
 *
 * return: void
 *
 * @param: none
 *
 * Clear choices and initialize board again
 *
 * Catches and Throws any exception raised
 */
void CDeck::ClearBoard()
{
	try {
		ClearChoices();
		m_pBoard->InitData();
	}
	catch (exception e) {
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
 * ClearChoices
 *
 * return: void
 *
 * @param: none
 *
 * Clear the X/O lists
 *
 * Catches and Throws any exception raised
 */
void CDeck::ClearChoices()
{
	try {
		m_cPlayerOChoice.clear();
		m_cPlayerXChoice.clear();
	}
	catch (exception e) {
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
 * GetBoardSize
 *
 * return: int
 *
 * @param: none
 *
 * Get board size, it should be 9
 */
int CDeck::GetBoardSize() const
{
	return m_nBoardSize * m_nBoardSize;
}

/**
 * IsMoveAvailable
 *
 * return: bool
 *
 * @param: nIndex
 *
 * Check if nIndex is available
 *
 * Catches and Throws any exception raised
 */
bool CDeck::IsMoveAvailable(int nIndex) const throw()
{
	return find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), nIndex) == m_cPlayerOChoice.end() &&
		find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), nIndex) == m_cPlayerXChoice.end();
}

/**
 * PlayerXWins
 *
 * return: bool
 *
 * @param: none
 *
 * Player with symbol X wins the game?
 *
 * Catches and Throws any exception raised
 */
bool CDeck::PlayerXWins() const
{
	bool bRes = false;
	try {
		if ((find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 0) != m_cPlayerXChoice.end() &&
			find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 1) != m_cPlayerXChoice.end() &&
			find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 2) != m_cPlayerXChoice.end()) ||

			(find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 0) != m_cPlayerXChoice.end() &&
			find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 3) != m_cPlayerXChoice.end() &&
			find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 6) != m_cPlayerXChoice.end()) ||

			(find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 0) != m_cPlayerXChoice.end() &&
			find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 4) != m_cPlayerXChoice.end() &&
			find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 8) != m_cPlayerXChoice.end()) ||

			(find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 1) != m_cPlayerXChoice.end() &&
			find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 4) != m_cPlayerXChoice.end() &&
			find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 7) != m_cPlayerXChoice.end()) ||

			(find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 2) != m_cPlayerXChoice.end() &&
			find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 5) != m_cPlayerXChoice.end() &&
			find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 8) != m_cPlayerXChoice.end()) ||

			(find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 3) != m_cPlayerXChoice.end() &&
			find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 4) != m_cPlayerXChoice.end() &&
			find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 5) != m_cPlayerXChoice.end()) ||

			(find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 6) != m_cPlayerXChoice.end() &&
			find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 7) != m_cPlayerXChoice.end() &&
			find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 8) != m_cPlayerXChoice.end()) ||

			(find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 2) != m_cPlayerXChoice.end() &&
			find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 4) != m_cPlayerXChoice.end() &&
			find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 6) != m_cPlayerXChoice.end()))
			bRes = true;
	}
	catch (exception e) {
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

	return bRes;
}

/**
 * PlayerOWins
 *
 * return: bool
 *
 * @param: none
 *
 * Player with symbol O wins the game?
 *
 * Catches and Throws any exception raised
 */
bool CDeck::PlayerOWins() const
{
	bool bRes = false;
	try {
		if ((find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 0) != m_cPlayerOChoice.end() &&
			find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 1) != m_cPlayerOChoice.end() &&
			find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 2) != m_cPlayerOChoice.end()) ||

			(find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 0) != m_cPlayerOChoice.end() &&
			find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 3) != m_cPlayerOChoice.end() &&
			find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 6) != m_cPlayerOChoice.end()) ||

			(find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 0) != m_cPlayerOChoice.end() &&
			find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 4) != m_cPlayerOChoice.end() &&
			find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 8) != m_cPlayerOChoice.end()) ||

			(find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 1) != m_cPlayerOChoice.end() &&
			find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 4) != m_cPlayerOChoice.end() &&
			find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 7) != m_cPlayerOChoice.end()) ||

			(find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 2) != m_cPlayerOChoice.end() &&
			find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 5) != m_cPlayerOChoice.end() &&
			find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 8) != m_cPlayerOChoice.end()) ||

			(find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 3) != m_cPlayerOChoice.end() &&
			find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 4) != m_cPlayerOChoice.end() &&
			find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 5) != m_cPlayerOChoice.end()) ||

			(find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 6) != m_cPlayerOChoice.end() &&
			find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 7) != m_cPlayerOChoice.end() &&
			find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 8) != m_cPlayerOChoice.end()) ||

			(find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 2) != m_cPlayerOChoice.end() &&
			find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 4) != m_cPlayerOChoice.end() &&
			find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 6) != m_cPlayerOChoice.end()))
			bRes = true;
	}
	catch (exception e) {
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

	return bRes;
}

/**
 * IsGameOver
 *
 * return: bool
 *
 * @param: none
 *
 * Check if game is over by checking moves played so far
 *
 * Catches and Throws any exception raised
 */
bool CDeck::IsGameOver() const throw()
{
	return m_cPlayerXChoice.size() + m_cPlayerOChoice.size() == GetBoardSize();
}

/**
 * operator <<
 *
 * return: ostream
 *
 * @params: cOut
 *
 * Display the current status of deck
 *
 * Catches and Throws any exception raised
 */
ostream& tictactoe::operator << (ostream& cOut, const CDeck& cDeck)
{
	try {
		cDeck.Display(cOut);
	}
	catch (exception e) {
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
