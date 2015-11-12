
#include <string>

#include "TicTacToe.h"
#include "Player.h"

using namespace tictactoe;

CTicTacToe::CTicTacToe() throw()
{
	m_bSymbolX = true;
	m_bXO = true;
	Init();
	m_cDeckList.push_back(m_pDeck);
}

CTicTacToe::~CTicTacToe()
{
	try {
		Release();
	}
	catch (...) {
		// Can't throw you dear :)
	}
}

CTicTacToe::CTicTacToe(const CTicTacToe& cTicTacToe) throw()
{
	Init();
	InitList(cTicTacToe.m_cDeckList);
	m_bXO = cTicTacToe.m_bXO;
	m_bSymbolX = cTicTacToe.m_bSymbolX;
	*m_pPlayerOne = *cTicTacToe.m_pPlayerOne;
	*m_pPlayerTwo = *cTicTacToe.m_pPlayerTwo;
}

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

void CTicTacToe::Init()
{
	try {
		Release();
		m_pDeck = new CDeck();
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

void CTicTacToe::InitList(DECK_LIST cDeckList)
{
	try {
		DeckIter Iter;
		for (Iter = cDeckList.begin(); Iter != cDeckList.end(); ++ Iter) {
			if (*Iter) {
				CDeck* pDeck =  new CDeck(**Iter);
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

void CTicTacToe::Input() throw()
{
	Input(cin);
}

void CTicTacToe::Display() const throw()
{
	Display(cout);
}

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

		cout << csName << " enter your move ";
		while (true) {
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

bool CTicTacToe::ValidateInput(istream& cIn, int nMove) const
{
	if (cIn.fail() || nMove < 0) {
		cIn.clear();
		cIn.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input! Try again ..." << endl;
		return false;
	}
	return true;
}

int CTicTacToe::StartGame()
{
	int nRes = 0;
	bool bSamePlayer = false;
	char ch = 'Y';
	CPlayer* pWinner = NULL;
	CPlayer* pLooser = NULL;

	try {
		while (ch != 'q') {

			pWinner = NULL;
			pLooser = NULL;

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

				pWinner->SetWins();
				pLooser->SetLosses();
			}
			else {
				cout << "Game Draw :\\" << endl;
				m_pPlayerOne->SetTies();
				m_pPlayerTwo->SetTies();

				pWinner = m_pPlayerOne;
				pLooser = m_pPlayerTwo;
			}

			cout << *pWinner;
			cout << *pLooser;

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

	return nRes;
}

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
