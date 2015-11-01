
#include "Deck.h"

CDeck::CDeck()
{
	m_cBoard.SetRows(m_nBoardSize);
	m_cBoard.SetCols(m_nBoardSize);
}

CDeck::~CDeck()
{
}

CDeck::CDeck(const CDeck& cDeck)
{
}

CDeck& CDeck::operator = (const CDeck& cDeck)
{
	if (this != &cDeck) {
	}
	return *this;
}

ostream& CDeck::operator << (ostream& cOut) const
{
	//TODO: insert return statement here
	return cOut;
}
