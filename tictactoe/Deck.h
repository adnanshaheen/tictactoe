
#pragma once


#include <iostream>
#include <vector>
#include "Board.h"

using namespace std;

typedef vector<int> PLAYER_CHOICES;
typedef PLAYER_CHOICES::iterator PLAYER_ITER;
typedef PLAYER_CHOICES::const_iterator PLAYER_CITER;

class CDeck
{
public:
	/* constructor/destructor */
	CDeck();														// constructor
	CDeck(const CDeck& cDeck);										// copy constructor
	~CDeck();														// destructor

	/* operator overloading */
	CDeck&			operator = (const CDeck& cDeck);				// assignment operator
	friend ostream&	operator << (ostream& cOut,
								const CDeck& cDeck);				// extraction operator

	/* methods */
	void		Display() const;									// display

	void		InsertChoice(bool bSymbol, unsigned int nIndex);	// insert choice

	void		ClearChoices();										// clear the choices for another game

	int			GetBoardSize() const;								// get board size

	bool		IsMoveAvailable(int nIndex) const;					// check if move is already done

private:
	void		Display(ostream& cOut) const;						// display

private:
	CBoard* m_pBoard;												// board
	const int m_nBoardSize;											// board size
	PLAYER_CHOICES m_cPlayerOChoice;								// player one choices
	PLAYER_CHOICES m_cPlayerXChoice;								// player two choices
};
