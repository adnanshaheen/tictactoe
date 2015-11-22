/**
 * TicTacToe.cpp
 *
 * Implementation details of class
 */

/**
 * Headers
 */
#include <string>
#include <fstream>

#include "TicTacToe.h"
#include "Player.h"

using namespace tictactoe;

/**
 * Constructor
 *
 * Default Constructor, set initial symbol
 * Create two players using CPlayer*
 * Throws any exception raised
 */
CTicTacToe::CTicTacToe() throw()
{
	m_bSymbolX = true;
	m_bXO = true;
	Init();
}

/**
 * Destructor
 *
 * Destructor, Release the memory allocated
 *
 * Catches any exception
 */
CTicTacToe::~CTicTacToe()
{
	try {
		Release();
	}
	catch (...) {
		// Can't throw you dear :)
	}
}

/**
 * Copy Constructor
 *
 * @params: cTicTacToe, to copy from
 *
 * Creates a new copy of object
 * Initialize all data members using cTicTacToe
 * Throws any exception raised
 */
CTicTacToe::CTicTacToe(const CTicTacToe& cTicTacToe) throw()
{
	Init();
	InitList(cTicTacToe.m_cDeckList);
	m_bXO = cTicTacToe.m_bXO;
	m_bSymbolX = cTicTacToe.m_bSymbolX;
	*m_pPlayerOne = *cTicTacToe.m_pPlayerOne;
	*m_pPlayerTwo = *cTicTacToe.m_pPlayerTwo;
}

/**
 * Assignment operator
 *
 * @params: cTicTacToe, to copy data from
 *
 * Initialize all data members using cTicTacToe
 * Catches exception, and throws them back to caller
 */
CTicTacToe& CTicTacToe::operator = (const CTicTacToe& cTicTacToe)
{
	try {
		if (this != &cTicTacToe) {
			Init();
			InitList(cTicTacToe.m_cDeckList);
			m_bXO = cTicTacToe.m_bXO;
			m_bSymbolX = cTicTacToe.m_bSymbolX;
			*m_pPlayerOne = *cTicTacToe.m_pPlayerOne;
			*m_pPlayerTwo = *cTicTacToe.m_pPlayerTwo;
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
 * Init
 *
 * return: void
 *
 * @params: none
 *
 * Release any memory if created
 * Create two new CPlayer
 *
 * Catches and Throws any exception raised
 */
void CTicTacToe::Init()
{
	try {
		Release();
		m_pPlayerOne = new CPlayer();
		m_pPlayerTwo = new CPlayer();
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
 * @params: none
 *
 * Release any memory if created
 * Delete all members from deck list
 * Delete CPlayer
 *
 * Catches and Throws any exception raised
 */
void CTicTacToe::Release()
{
	try {
		if (!m_cDeckList.empty()) {
			ReleaseList();
			m_cDeckList.clear();
		}
		if (m_pPlayerOne) {
			delete m_pPlayerOne;
			m_pPlayerOne = NULL;
		}
		if (m_pPlayerTwo) {
			delete m_pPlayerTwo;
			m_pPlayerTwo = NULL;
		}
	}
	catch (exception e) {
		cerr << e.what() << endl;
		throw e;
	}
	catch (...) {
		cerr << "Something went wrong while releasing data" << endl;
		cerr << "File: " << __FILE__ << endl;
		cerr << "Line: " << __LINE__ << endl;
		throw;
	}
}

/**
 * InitList
 *
 * return: void
 *
 * @params: cDeckList list of deck
 *
 * Copy the cDeckList
 *
 * Catches and Throws any exception raised
 */
void CTicTacToe::InitList(DECK_LIST cDeckList)
{
	try {
		DeckIter Iter;
		for (Iter = cDeckList.begin(); Iter != cDeckList.end(); ++ Iter) {
			if (*Iter) {
				CDeck* pDeck = new CDeck(**Iter);
				m_cDeckList.push_back(pDeck);
			}
		}
	}
	catch (exception e) {
		cerr << e.what() << endl;
		throw e;
	}
	catch (...) {
		cerr << "Something went wrong while releasing data" << endl;
		cerr << "File: " << __FILE__ << endl;
		cerr << "Line: " << __LINE__ << endl;
		throw;
	}
}

/**
 * ReleaseList
 *
 * return: void
 *
 * @params: none
 *
 * Release all deck from list
 *
 * Catches and Throws any exception raised
 */
void CTicTacToe::ReleaseList()
{
	try {
		cDeckIter cIter;
		for (cIter = m_cDeckList.begin(); cIter != m_cDeckList.end(); ++ cIter) {
			CDeck* pDeck = *cIter;
			if (pDeck)
				delete pDeck;
		}
	}
	catch (exception e) {
		cerr << e.what() << endl;
		throw e;
	}
	catch (...) {
		cerr << "Something went wrong while releasing data" << endl;
		cerr << "File: " << __FILE__ << endl;
		cerr << "Line: " << __LINE__ << endl;
		throw;
	}
}

/**
 * Input
 *
 * return: void
 *
 * @params: none
 *
 * Take user input for next move
 *
 * Throws any exception raised
 */
void CTicTacToe::Input() throw()
{
	Input(cin);
}

/**
 * Display
 *
 * return: void
 *
 * @params: none
 *
 * Display all the decks in list
 *
 * Throws any exception raised
 */
void CTicTacToe::Display() const throw()
{
	Display(cout);
}

/**
 * Input
 *
 * return: void
 *
 * @params: cIn
 *
 * Get user input using cIn
 *
 * Catches and Throws any exception raised
 */
void CTicTacToe::Input(istream& cIn)
{
	try {
		int nIndex = -1;
		string csName;
		if (m_bXO) {
			csName = m_pPlayerOne->IsSymbolX() ?
				m_pPlayerOne->GetPlayerName() : m_pPlayerTwo->GetPlayerName();
		}
		else {
			csName = m_pPlayerOne->IsSymbolO() ?
				m_pPlayerOne->GetPlayerName() : m_pPlayerTwo->GetPlayerName();
		}

		while (true) {
			cout << csName << " enter your move ";
			cIn >> nIndex;
			if (!ValidateInput(cIn, nIndex))
				continue;

			if (!IsValidMove(nIndex))
				cout << "Invalid move ..." << endl;
			else
				break;
		}
		m_pDeck->InsertChoice(m_bXO, nIndex);
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
 * @params: cOut
 *
 * Display the deck in list on cOut
 *
 * Catches and Throws any exception raised
 */
void CTicTacToe::Display(ostream& cOut) const
{
	try {
		cDeckIter cIter;
		for (cIter = m_cDeckList.begin(); cIter != m_cDeckList.end(); ++ cIter) {
			CDeck* pDeck = *cIter;
			if (pDeck)
				cout << *pDeck << endl;
		}
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
 * IsValidMove
 *
 * return: bool
 *
 * @params: nIndex
 *
 * Check if nIndex is already taken in Deck
 * Check if nIndex is valid for Deck
 *
 * Catches and Throws any exception raised
 */
bool CTicTacToe::IsValidMove(int nIndex) const
{
	bool bRes = false;
	try {
		bRes = m_pDeck->IsMoveAvailable(nIndex) &&
		(nIndex >= 0 && nIndex < m_pDeck->GetBoardSize() ? true : false);
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
	return bRes;
}

/**
 * ValidateInput
 *
 * return: bool
 *
 * @params: cIn
 * @params: nMove
 *
 * Validate if nMove is an integer
 *
 * Catches and Throws any exception raised
 */
bool CTicTacToe::ValidateInput(istream& cIn, int nMove) const
{
	bool bRes = true;
	try {
		if (cIn.fail() || nMove < 0) {
			cIn.clear();
			cIn.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input! Try again ..." << endl;
			return false;
		}
	}
	catch (exception e) {
		cerr << e.what() << endl;
		throw e;
	}
	catch (...) {
		cerr << "Something bad happened!!!" << endl;
		cerr << "File: " << __FILE__ << endl;
		cerr << "Line: " << __LINE__ << endl;
		throw;
	}

	return bRes;
}

/**
 * StartGame
 *
 * return: int
 *
 * @params: none
 *
 * Start the game
 * Get player names, assign their symbols
 * Take user input and display the current Deck status
 * Change symbol for next game, dump deck to a file at the end of game
 *
 * Catches and Throws any exception raised
 */
int CTicTacToe::StartGame()
{
	int nRes = 0;
	bool bSamePlayer = false;
	char ch = 'Y';
	CPlayer* pWinner = NULL;
	CPlayer* pLooser = NULL;

	ofstream cFile("tictactoe.txt", ios::out | ios::app);

	try {
		while (ch != 'q') {

			pWinner = NULL;
			pLooser = NULL;
			m_pDeck = new CDeck();					// NOTE: Don't delete me
			m_cDeckList.push_back(m_pDeck);

			if (!bSamePlayer) {
				cout << "Player 1 name: ";
				cin >> *m_pPlayerOne;
			}
			m_pPlayerOne->SetSymbol(m_bSymbolX);
			cout << *m_pPlayerOne;

			m_bXO = true;
			m_bSymbolX = !m_bSymbolX;				// change the symbol for next player, and game

			if (!bSamePlayer) {
				cout << "Player 2 name: ";
				cin >> *m_pPlayerTwo;
			}
			m_pPlayerTwo->SetSymbol(m_bSymbolX);
			cout << *m_pPlayerTwo;

			m_pDeck->ClearBoard();					// clear board for new game

			cout << *m_pDeck;

			cout << (m_pPlayerOne->IsSymbolX() ? m_pPlayerOne->GetPlayerName() : m_pPlayerTwo->GetPlayerName())
				<< " to make the first move" << endl;

			while (!IsGameOver()) {
				GetPlayerMove();

				cout << *m_pDeck;
			}

			if (!IsDraw()) {
				if (m_pDeck->PlayerXWins()) {
					pWinner = m_pPlayerOne->IsSymbolX() ? m_pPlayerOne : m_pPlayerTwo;
					pLooser = m_pPlayerOne->IsSymbolO() ? m_pPlayerOne : m_pPlayerTwo;
				}
				else if (m_pDeck->PlayerOWins()) {
					pWinner = m_pPlayerOne->IsSymbolO() ? m_pPlayerOne : m_pPlayerTwo;
					pLooser = m_pPlayerOne->IsSymbolX() ? m_pPlayerOne : m_pPlayerTwo;
				}

				cout << pWinner->GetPlayerName() << " Wins :)" << endl;

				if (!cFile.bad())
					cFile << pWinner->GetPlayerName() << " Wins :)" << endl;

				pWinner->SetWins();
				pLooser->SetLosses();
			}
			else {
				cout << "Game Draw :\\" << endl;

				if (!cFile.bad())
					cFile << "Game Draw :\\" << endl;

				m_pPlayerOne->SetTies();
				m_pPlayerTwo->SetTies();

				pWinner = m_pPlayerOne;
				pLooser = m_pPlayerTwo;
			}

			cout << *pWinner;
			cout << *pLooser;

			if (!cFile.bad()) {
				cFile << m_cDeckList.size() << endl;
				cFile << *m_pDeck;

				cFile.flush();
			}

			cout << "Same players (press q to exit)? Y/N ";
			cin >> ch;
			if (ch == 'y' || ch == 'Y')
				bSamePlayer = true;
			else
				bSamePlayer = false;
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

	cFile.close();

	return nRes;
}

/**
 * IsDraw
 *
 * return: bool
 *
 * @params: none
 *
 * Check if game is a draw or not
 *
 * Catches and Throws any exception raised
 */
bool CTicTacToe::IsDraw() const
{
	bool bRes = false;
	try {
		bRes = !m_pDeck->PlayerXWins() && !m_pDeck->PlayerOWins();
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
	return bRes;
}

/**
 * IsGameOver
 *
 * return: bool
 *
 * @params: none
 *
 * Check if game is over or not
 *
 * Catches and Throws any exception raised
 */
bool CTicTacToe::IsGameOver() const
{
	bool bRes = false;
	try {
		bRes = m_pDeck->IsGameOver() || m_pDeck->PlayerXWins() || m_pDeck->PlayerOWins();
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
	return bRes;
}

/**
 * GetPlayerMove
 *
 * return: void
 *
 * @params: none
 *
 * Get player input, set who's next
 *
 * Catches and Throws any exception raised
 */
void CTicTacToe::GetPlayerMove()
{
	try {
		cin >> *this;

		// update player move
		m_bXO  = !m_bXO;
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
 * @params: cOut
 * @params: cTicTacToe
 *
 * display the deck list
 *
 * Catches and Throws any exception raised
 */
ostream& tictactoe::operator << (ostream& cOut, const CTicTacToe& cTicTacToe)
{
	try {
		cTicTacToe.Display(cOut);
	}
	catch (exception e)
	{
		cerr << e.what() << endl;
	}
	catch (...)
	{
		cerr << "Something bad happened!!!" << endl;
		cerr << "File: " << __FILE__ << endl;
		cerr << "Line: " << __LINE__ << endl;
	}

	return cOut;
}

/**
 * operator >>
 *
 * return: istream
 *
 * @params: cIn
 * @params: cTicTacToe
 *
 * Take user input
 *
 * Catches and Throws any exception raised
 */
istream& tictactoe::operator >> (istream& cIn, CTicTacToe& cTicTacToe)
{
	try {
		cTicTacToe.Input(cIn);
	}
	catch (exception e)
	{
		cerr << e.what() << endl;
	}
	catch (...)
	{
		cerr << "Something bad happened!!!" << endl;
		cerr << "File: " << __FILE__ << endl;
		cerr << "Line: " << __LINE__ << endl;
	}

	return cIn;
}
