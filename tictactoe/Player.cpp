#include "Player.h"


CPlayer::CPlayer()
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
