
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

ostream& CPlayer::operator << (ostream& cOut) const
{
	Display(cOut);
	return cOut;
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

inline string CPlayer::GetPlayerName() const
{
	return m_csName;
}

inline void CPlayer::SetPlayerName(const string csName)
{
	m_csName = csName;
}

inline bool CPlayer::GetSymbol() const
{
	return m_bSymbolXO;
}

inline void CPlayer::SetSymbol(const bool bSymbolXO)
{
	m_bSymbolXO = bSymbolXO;
}

inline bool CPlayer::IsSymbolO() const
{
	return m_bSymbolXO == false;
}

inline bool CPlayer::IsSymbolX() const
{
	return m_bSymbolXO == true;
}

inline unsigned int CPlayer::GetWins() const
{
	return m_cStatistics.GetWins();
}
inline void CPlayer::SetWins(const unsigned int uWin/* = 1*/)
{
	m_cStatistics.SetWins(uWin);
}

inline unsigned int CPlayer::GetLosses() const
{
	return m_cStatistics.GetLosses();
}
inline void CPlayer::SetLosses(const unsigned int uLoss/* = 1*/)
{
	m_cStatistics.SetLosses(uLoss);
}

inline unsigned int CPlayer::GetTies() const
{
	return m_cStatistics.GetTies();
}
inline void CPlayer::SetTies(const unsigned int uTie/* = 1*/)
{
	m_cStatistics.SetTies(uTie);
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
	cOut << "Player Symbol : " << GetSymbol() << endl;
	cOut << "Player score  : " << GetScore() << endl;
	cOut << const_cast<CStats*> (&m_cStatistics) << endl;
}
