
#pragma once

#include <iostream>
#include "Deck.h"
using namespace std;

namespace tictactoe {

	class CPlayer;

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
		CDeck* m_pDeck;
		CPlayer* m_pPlayerOne;
		CPlayer* m_pPlayerTwo;
	};
}
