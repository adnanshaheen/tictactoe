
#include <string>

#include "TicTacToe.h"
#include "Player.h"
#include "Deck.h"

CTicTacToe::CTicTacToe() : m_bSymbolX(true)
{
	Init();
}

CTicTacToe::~CTicTacToe()
{
	Release();
}

CTicTacToe::CTicTacToe(const CTicTacToe& cTicTacToe)
{
	Init();
	m_bSymbolX = cTicTacToe.m_bSymbolX;
	m_pPlayerOne = cTicTacToe.m_pPlayerOne;
	m_pPlayerTwo = cTicTacToe.m_pPlayerTwo;
}

CTicTacToe& CTicTacToe::operator = (const CTicTacToe& cTicTacToe)
{
	if (this != &cTicTacToe) {
		Init();
		m_bSymbolX = cTicTacToe.m_bSymbolX;
		m_pPlayerOne = cTicTacToe.m_pPlayerOne;
		m_pPlayerTwo = cTicTacToe.m_pPlayerTwo;
	}
	return *this;
}

void CTicTacToe::Init()
{
	Release();
	m_pPlayerOne = new CPlayer();
	m_pPlayerTwo = new CPlayer();
}

void CTicTacToe::Release()
{
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
}

void CTicTacToe::Display(ostream& cOut) const
{
}

bool CTicTacToe::IsValidMove() const
{
	return false;
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
	while (true) {

		if (!bSamePlayer) {
			cout << "Player 1 name: ";
			cin >> *m_pPlayerOne;
		}
		m_pPlayerOne->SetSymbol(m_bSymbolX);
		cout << *m_pPlayerOne;

		m_bSymbolX = !m_bSymbolX;				// change the symbol for next player, and game

		if (!bSamePlayer) {
			cout << "Player 2 name: ";
			cin >> *m_pPlayerTwo;
		}
		m_pPlayerTwo->SetSymbol(m_bSymbolX);
		cout << *m_pPlayerTwo;

		CDeck cDeck;
		cout << cDeck;

		cout << (m_pPlayerOne->IsSymbolX() ? m_pPlayerOne->GetPlayerName() : m_pPlayerTwo->GetPlayerName())
			<< " to make the first move" << endl;

		cout << "Same players? Y/N ";
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
			bSamePlayer = true;
	}
	return res;
}

bool CTicTacToe::IsDraw() const
{
	return false;
}

bool CTicTacToe::IsGameOver() const
{
	return false;
}

void CTicTacToe::GetPlayerMove()
{
}

ostream& operator << (ostream& cOut, const CTicTacToe& cTicTacToe)
{
	cTicTacToe.Display(cOut);
	return cOut;
}

istream& operator >> (istream& cIn, CTicTacToe& cTicTacToe)
{
	cTicTacToe.Input(cIn);
	return cIn;
}
