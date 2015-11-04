
#include "TicTacToe.h"
#include "Player.h"

CTicTacToe::CTicTacToe()
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
	m_pPlayerOne = cTicTacToe.m_pPlayerOne;
	m_pPlayerTwo = cTicTacToe.m_pPlayerTwo;
}

CTicTacToe& CTicTacToe::operator = (const CTicTacToe& cTicTacToe)
{
	if (this != &cTicTacToe) {
		Init();
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
