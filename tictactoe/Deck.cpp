
#include "Deck.h"

CDeck::CDeck() : m_nBoardSize(3)
{
	m_cBoard.SetRows(m_nBoardSize);
	m_cBoard.SetCols(m_nBoardSize);
}

CDeck::~CDeck()
{
}

CDeck::CDeck(const CDeck& cDeck) : m_nBoardSize(3)
{
}

CDeck& CDeck::operator = (const CDeck& cDeck)
{
	if (this != &cDeck) {
		m_cBoard = cDeck.m_cBoard;
		m_cPlayerOChoice = cDeck.m_cPlayerOChoice;
		m_cPlayerXChoice = cDeck.m_cPlayerXChoice;
	}
	return *this;
}


void CDeck::Display() const
{
	Display(cout);
}

void CDeck::Display(ostream& cOut) const
{
	cOut << m_cBoard << endl;
}

void CDeck::InsertChoice(bool bSymbolX, unsigned int nIndex)
{
	if (bSymbolX)
		m_cPlayerXChoice.push_back(nIndex);
	else
		m_cPlayerOChoice.push_back(nIndex);
}

ostream& operator << (ostream& cOut, const CDeck& cDeck)
{
	cDeck.Display(cOut);
	return cOut;
}
