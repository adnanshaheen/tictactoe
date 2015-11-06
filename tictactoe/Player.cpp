
#include <string>
#include "Player.h"

CPlayer::CPlayer() : m_bSymbolXO(true)
{
}

CPlayer::CPlayer(string csName, bool bSymbolXO) : m_csName(csName), m_bSymbolXO(bSymbolXO)
{
}

CPlayer::~CPlayer()
{
}

CPlayer::CPlayer(const CPlayer& cPlayer)
{
	SetPlayerName(cPlayer.GetPlayerName());
	SetSymbol(cPlayer.GetSymbol());
	SetWins(cPlayer.GetWins());
	SetLosses(cPlayer.GetLosses());
	SetTies(cPlayer.GetTies());
}

CPlayer& CPlayer::operator = (const CPlayer& cPlayer)
{
	if (this != &cPlayer) {
		SetPlayerName(cPlayer.GetPlayerName());
		SetSymbol(cPlayer.GetSymbol());
		SetWins(cPlayer.GetWins());
		SetLosses(cPlayer.GetLosses());
		SetTies(cPlayer.GetTies());
	}
	return *this;
}

bool CPlayer::operator > (const CPlayer& cPlayer) const
{
	return GetScore() > cPlayer.GetScore() ? true : false;
}

bool CPlayer::operator < (const CPlayer& cPlayer) const
{
	return GetScore() < cPlayer.GetScore() ? true : false;
}

bool CPlayer::operator == (const CPlayer& cPlayer) const
{
	return GetScore() == cPlayer.GetScore() ? true : false;
}

int CPlayer::GetScore() const
{
	return (m_cStatistics.GetWins() * 2) + m_cStatistics.GetTies() - m_cStatistics.GetLosses();
}

void CPlayer::Display() const
{
	Display(cout);
}

void CPlayer::Display(ostream& cOut) const
{
	cOut << "Player name   : " << GetPlayerName() << endl;
	cOut << "Player Symbol : " << GetSymbolChar() << endl;
	cOut << "Player score  : " << GetScore() << endl;
	cOut << m_cStatistics << endl;
}

ostream& operator << (ostream& cOut, const CPlayer& cPlayer)
{
	cPlayer.Display(cOut);
	return cOut;
}

istream& operator >> (istream& cIn, CPlayer& cPlayer)
{
	cIn >> cPlayer.m_csName;
	return cIn;
}
