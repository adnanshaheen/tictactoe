
#include "Player.h"

CPlayer::CPlayer() : m_bSymbolXO(true)
{
}

CPlayer::~CPlayer()
{
}

CPlayer::CPlayer(const CPlayer& cPlayer)
{
}

CPlayer& CPlayer::operator = (const CPlayer& cPlayer)
{
	if (this != &cPlayer) {
	}
	return *this;
}

ostream& CPlayer::operator << (ostream& cOut)
{
	//TODO: insert return statement here
	return cOut;
}

bool CPlayer::operator > (const CPlayer& cPlayer)
{
	return false;
}


bool CPlayer::operator < (const CPlayer& cPlayer)
{
	return false;
}

bool CPlayer::operator == (const CPlayer& cPlayer)
{
	return false;
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
