
#pragma once

#include <iostream>
using namespace std;

class CPlayer;

class CTicTacToe
{
public:
	CTicTacToe();
	CTicTacToe(const CTicTacToe& cTicTacToe);
	~CTicTacToe();

	CTicTacToe& operator = (const CTicTacToe& cTicTacToe);

	friend ostream& operator << (ostream& cOut, const CTicTacToe& cTicTacToe);
	friend istream& operator >> (istream& cIn, CTicTacToe& cTicTacToe);

	void Input();

	void Display() const;

	int StartGame();

private:
	void Init();
	void Release();

	void Input(istream& cIn);

	void Display(ostream& cOut) const;

	bool IsValidMove() const;

	bool ValidateInput(istream& cIn, int nMove) const;

	bool IsDraw() const;

	bool IsGameOver() const;

	void GetPlayerMove();

private:
	bool m_bSymbolX;
	CPlayer* m_pPlayerOne;
	CPlayer* m_pPlayerTwo;
};

