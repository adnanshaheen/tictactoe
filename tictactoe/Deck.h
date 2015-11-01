
#pragma once


#include <iostream>
#include "Board.h"

using namespace std;

class CDeck
{
public:
	CDeck();
	CDeck(const CDeck& cDeck);
	~CDeck();

	CDeck&		operator = (const CDeck& cDeck);
	ostream&	operator << (ostream& cOut) const;

private:
	CBoard m_cBoard;
	const int m_nBoardSize = 3;
};

