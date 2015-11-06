
#include "Deck.h"

CDeck::CDeck() : m_nBoardSize(3)
{
	m_pBoard = new CBoard(m_nBoardSize, m_nBoardSize);
	m_cPlayerOChoice.clear();
	m_cPlayerXChoice.clear();
}

CDeck::~CDeck()
{
	if (m_pBoard) {
		delete m_pBoard;
		m_pBoard = NULL;
	}
	m_cPlayerOChoice.clear();
	m_cPlayerXChoice.clear();
}

CDeck::CDeck(const CDeck& cDeck) : m_nBoardSize(3)
{
	m_pBoard = cDeck.m_pBoard;
	m_cPlayerOChoice = cDeck.m_cPlayerOChoice;
	m_cPlayerXChoice = cDeck.m_cPlayerXChoice;
}

CDeck& CDeck::operator = (const CDeck& cDeck)
{
	if (this != &cDeck) {
		m_pBoard = cDeck.m_pBoard;
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
	cOut << *m_pBoard << endl;
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
