
#pragma once

#include <iostream>
#include "Deck.h"
using namespace std;

namespace tictactoe {

	class CPlayer;
	typedef list<CDeck*> DECK_LIST;
	typedef DECK_LIST::iterator DeckIter;
	typedef DECK_LIST::const_iterator cDeckIter;

	class CTicTacToe
	{
	public:
		CTicTacToe() throw();
		CTicTacToe(const CTicTacToe& cTicTacToe);
		~CTicTacToe();

		CTicTacToe& operator = (const CTicTacToe& cTicTacToe);

		friend ostream& operator << (ostream& cOut, const CTicTacToe& cTicTacToe);
		friend istream& operator >> (istream& cIn, CTicTacToe& cTicTacToe);

		void Input() throw();

		void Display() const throw();

		int StartGame();

	private:
		void Init();
		void Release();

		void InitList(DECK_LIST cDeckList);
		void ReleaseList();

		void Input(istream& cIn);

		void Display(ostream& cOut) const;

		bool IsValidMove(int nIndex) const;

		bool ValidateInput(istream& cIn, int nMove) const;

		bool IsDraw() const;

		bool IsGameOver() const;

		void GetPlayerMove();

	private:
		bool m_bXO;					// current symbol
		bool m_bSymbolX;			// symbol for first player
		CDeck* m_pDeck;				// Current Deck
		DECK_LIST m_cDeckList;		// Deck list
		CPlayer* m_pPlayerOne;		// Player one
		CPlayer* m_pPlayerTwo;		// Player two
	};
}
