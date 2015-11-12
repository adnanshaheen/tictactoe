
#include <string>

#include "TicTacToe.h"
#include "Player.h"

using namespace tictactoe;

CTicTacToe::CTicTacToe() throw()
{
	m_bSymbolX = true;
	m_bXO = true;
	Init();
}

CTicTacToe::~CTicTacToe()
{
	Release();
}

CTicTacToe::CTicTacToe(const CTicTacToe& cTicTacToe)
{
	Init();
	m_bXO = cTicTacToe.m_bXO;
	m_bSymbolX = cTicTacToe.m_bSymbolX;
	m_pPlayerOne = cTicTacToe.m_pPlayerOne;
	m_pPlayerTwo = cTicTacToe.m_pPlayerTwo;
}

CTicTacToe& CTicTacToe::operator = (const CTicTacToe& cTicTacToe)
{
	if (this != &cTicTacToe) {
		Init();
		m_bXO = cTicTacToe.m_bXO;
		m_bSymbolX = cTicTacToe.m_bSymbolX;
		m_pPlayerOne = cTicTacToe.m_pPlayerOne;
		m_pPlayerTwo = cTicTacToe.m_pPlayerTwo;
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
	}
}

void CTicTacToe::Release()
{
	if (m_pDeck) {
		delete m_pDeck;
		m_pDeck = NULL;
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

void CTicTacToe::Input()
{
	Input(cin);
}

void CTicTacToe::Display() const
{
	Display(cout);
}

void CTicTacToe::Input(istream& cIn)
{
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

void CTicTacToe::Display(ostream& cOut) const
{
}

bool CTicTacToe::IsValidMove(int nIndex) const
{
	return m_pDeck->IsMoveAvailable(nIndex) &&
		(nIndex >= 0 && nIndex < m_pDeck->GetBoardSize() ? true : false);
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
	int res = 0;
	bool bSamePlayer = false;
	char ch = 'Y';
	CPlayer* pWinner = NULL;
	CPlayer* pLooser = NULL;

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
	}
	return res;
}

bool CTicTacToe::IsDraw() const
{
	return !m_pDeck->PlayerXWins() && !m_pDeck->PlayerOWins();
}

bool CTicTacToe::IsGameOver() const
{
	return m_pDeck->IsGameOver() || m_pDeck->PlayerXWins() || m_pDeck->PlayerOWins();
}

void CTicTacToe::GetPlayerMove()
{
	cin >> *this;

	// update player move
	m_bXO  = !m_bXO;
}

ostream& tictactoe::operator << (ostream& cOut, const CTicTacToe& cTicTacToe)
{
	cTicTacToe.Display(cOut);
	return cOut;
}

istream& tictactoe::operator >> (istream& cIn, CTicTacToe& cTicTacToe)
{
	cTicTacToe.Input(cIn);
	return cIn;
}
