
#include <algorithm>
#include "Deck.h"

using namespace tictactoe;

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

void CDeck::ClearBoard()
{
	ClearChoices();
	m_pBoard->InitData();
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

bool CDeck::PlayerXWins() const
{
	bool bRes = false;
	if ((find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 0) != m_cPlayerXChoice.end() &&
		find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 1) != m_cPlayerXChoice.end() &&
		find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 2) != m_cPlayerXChoice.end()) ||

		(find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 0) != m_cPlayerXChoice.end() &&
		find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 3) != m_cPlayerXChoice.end() &&
		find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 6) != m_cPlayerXChoice.end()) ||

		(find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 0) != m_cPlayerXChoice.end() &&
		find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 4) != m_cPlayerXChoice.end() &&
		find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 8) != m_cPlayerXChoice.end()) ||

		(find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 1) != m_cPlayerXChoice.end() &&
		find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 4) != m_cPlayerXChoice.end() &&
		find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 7) != m_cPlayerXChoice.end()) ||

		(find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 2) != m_cPlayerXChoice.end() &&
		find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 5) != m_cPlayerXChoice.end() &&
		find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 8) != m_cPlayerXChoice.end()) ||

		(find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 3) != m_cPlayerXChoice.end() &&
		find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 4) != m_cPlayerXChoice.end() &&
		find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 5) != m_cPlayerXChoice.end()) ||

		(find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 6) != m_cPlayerXChoice.end() &&
		find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 7) != m_cPlayerXChoice.end() &&
		find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 8) != m_cPlayerXChoice.end()) ||

		(find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 2) != m_cPlayerXChoice.end() &&
		find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 4) != m_cPlayerXChoice.end() &&
		find(m_cPlayerXChoice.begin(), m_cPlayerXChoice.end(), 6) != m_cPlayerXChoice.end()))
		bRes = true;

	return bRes;
}

bool CDeck::PlayerOWins() const
{
	bool bRes = false;
	if ((find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 0) != m_cPlayerOChoice.end() &&
		find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 1) != m_cPlayerOChoice.end() &&
		find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 2) != m_cPlayerOChoice.end()) ||

		(find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 0) != m_cPlayerOChoice.end() &&
		find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 3) != m_cPlayerOChoice.end() &&
		find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 6) != m_cPlayerOChoice.end()) ||

		(find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 0) != m_cPlayerOChoice.end() &&
		find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 4) != m_cPlayerOChoice.end() &&
		find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 8) != m_cPlayerOChoice.end()) ||

		(find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 1) != m_cPlayerOChoice.end() &&
		find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 4) != m_cPlayerOChoice.end() &&
		find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 7) != m_cPlayerOChoice.end()) ||

		(find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 2) != m_cPlayerOChoice.end() &&
		find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 5) != m_cPlayerOChoice.end() &&
		find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 8) != m_cPlayerOChoice.end()) ||

		(find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 3) != m_cPlayerOChoice.end() &&
		find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 4) != m_cPlayerOChoice.end() &&
		find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 5) != m_cPlayerOChoice.end()) ||

		(find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 6) != m_cPlayerOChoice.end() &&
		find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 7) != m_cPlayerOChoice.end() &&
		find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 8) != m_cPlayerOChoice.end()) ||

		(find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 2) != m_cPlayerOChoice.end() &&
		find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 4) != m_cPlayerOChoice.end() &&
		find(m_cPlayerOChoice.begin(), m_cPlayerOChoice.end(), 6) != m_cPlayerOChoice.end()))
		bRes = true;

	return bRes;
}

bool CDeck::IsGameOver() const
{
	return m_cPlayerXChoice.size() + m_cPlayerOChoice.size() == GetBoardSize();
}

ostream& tictactoe::operator << (ostream& cOut, const CDeck& cDeck)
{
	cDeck.Display(cOut);
	return cOut;
}
