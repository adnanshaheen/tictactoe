/**
 * Deck.h
 *
 * Author:      Adnan Shaheen
 * Description: Responsible to display Deck, and keep players choices
 */

#pragma once

/**
 * Headers
 */
#include <iostream>
#include <list>
#include "Board.h"

using namespace std;

namespace tictactoe {

	/**
	 * Defining type
	 */
	typedef list<int> PLAYER_CHOICES;

	/**
	 * CDeck class
	 */
	class CDeck
	{
	public:
		/* constructor/destructor */
		CDeck() throw();												// constructor
		CDeck(const CDeck& cDeck) throw();								// copy constructor
		~CDeck();														// destructor

		/* operator overloading */
		CDeck&			operator = (const CDeck& cDeck);				// assignment operator
		friend ostream&	operator << (ostream& cOut,
									const CDeck& cDeck);				// extraction operator

		/* methods */
		void		Display() const throw();							// display

		void		InsertChoice(bool bSymbol, unsigned int nIndex);	// insert choice

		void		ClearBoard();										// clear the board for another game

		int			GetBoardSize() const;								// get board size

		bool		IsMoveAvailable(int nIndex) const throw();			// check if move is already done

		bool		PlayerXWins() const;								// Player with symbol X wins game?
		bool		PlayerOWins() const;								// Player with symbol O wins game?

		bool		IsGameOver() const throw();							// Is game over?

	private:
		void		Display(ostream& cOut) const;						// display

		void		ClearChoices();										// clear player choices

	private:
		CBoard* m_pBoard;												// board
		const int m_nBoardSize;											// board size
		PLAYER_CHOICES m_cPlayerOChoice;								// player one choices
		PLAYER_CHOICES m_cPlayerXChoice;								// player two choices
	};
}
