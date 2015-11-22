/**
 * TicTacToe.h
 *
 * Author:      Adnan Shaheen
 * Description: Responsible to play TicTacToe
 */
#pragma once

/**
 * Headers
 */
#include <iostream>
#include "Deck.h"
using namespace std;

namespace tictactoe {

	/**
	 * Forward declarations
	 */
	class CPlayer;
	typedef list<CDeck*> DECK_LIST;
	typedef DECK_LIST::iterator DeckIter;
	typedef DECK_LIST::const_iterator cDeckIter;

	/**
	 * CTicTacToe class
	 */
	class CTicTacToe
	{
	public:
		/** Constructors/Destructors */
		CTicTacToe() throw();									// Default Constrcutor
		CTicTacToe(const CTicTacToe& cTicTacToe) throw();		// Copy Constructor
		~CTicTacToe();											// Destructor

		CTicTacToe& operator = (const CTicTacToe& cTicTacToe);	// Assignment operator

		friend ostream& operator << (ostream& cOut, const CTicTacToe& cTicTacToe);	// overloaded extraction operator
		friend istream& operator >> (istream& cIn, CTicTacToe& cTicTacToe);			// overloaded insertion operator

		void Input() throw();									// Take user input

		void Display() const throw();							// Display all the decks in list

		int StartGame();										// Initialize the game

	private:
		void Init();											// Init class members
		void Release();											// Release memory

		void InitList(DECK_LIST cDeckList);						// Initialize new list, used in copyCtor and assignment operator
		void ReleaseList();

		void Input(istream& cIn);								// Take user input

		void Display(ostream& cOut) const;						// Display all the decks in list

		bool IsValidMove(int nIndex) const;						// Is move valid?

		bool ValidateInput(istream& cIn, int nMove) const;		// Validate number

		bool IsDraw() const;									// Is game a draw

		bool IsGameOver() const;								// Is game over

		void GetPlayerMove();									// Which players move is it?

	private:
		bool m_bXO;												// current symbol
		bool m_bSymbolX;										// symbol for first player
		CDeck* m_pDeck;											// Current Deck
		DECK_LIST m_cDeckList;									// Deck list
		CPlayer* m_pPlayerOne;									// Player one
		CPlayer* m_pPlayerTwo;									// Player two
	};
}
