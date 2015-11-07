
#include <algorithm>
#include "Deck.h"

CDeck::CDeck() : m_nBoardSize(3)
{
	m_pBoard = new CBoard(m_nBoardSize, m_nBoardSize);
	ClearChoices();
}

CDeck::~CDeck()
{
	if (m_pBoard) {
		delete m_pBoard;
		m_pBoard = NULL;
	}
	ClearChoices();
}

CDeck::CDeck(const CDeck& cDeck) : m_nBoardSize(3)
{
	m_pBoard = cDeck.m_pBoard;
	ClearChoices();
	m_cPlayerOChoice = cDeck.m_cPlayerOChoice;
	m_cPlayerXChoice = cDeck.m_cPlayerXChoice;
}

CDeck& CDeck::operator = (const CDeck& cDeck)
{
	if (this != &cDeck) {
		m_pBoard = cDeck.m_pBoard;
		ClearChoices();
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
	m_pBoard->SetAt(nIndex / 3, nIndex % 3, bSymbolX == true ? 88 : 79);
	if (bSymbolX)
		m_cPlayerXChoice.push_back(nIndex);
	else
		m_cPlayerOChoice.push_back(nIndex);
}

void CDeck::ClearChoices()
{
	m_cPlayerOChoice.clear();
	m_cPlayerXChoice.clear();
}

int CDeck::GetBoardSize() const
{
	return m_nBoardSize * m_nBoardSize;
}

bool CDeck::IsMoveAvailable(int nIndex) const
{
	return find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), nIndex) == m_cPlayerOChoice.end() &&
		find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), nIndex) == m_cPlayerXChoice.end();
}

ostream& operator << (ostream& cOut, const CDeck& cDeck)
{
	cDeck.Display(cOut);
	return cOut;
}
