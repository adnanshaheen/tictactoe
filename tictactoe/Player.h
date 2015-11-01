
#pragma once

#include <iostream>
#include "Stats.h"

using namespace std;

class CPlayer
{
public:
	/* constructor/destructor */
	CPlayer();														// constructor
	CPlayer(string csName, bool bSymbolXO);							// constructor
	CPlayer(const CPlayer& cPlayer);								// copy constructor
	~CPlayer();														// destructor

	/* operator overloading */
	CPlayer&			operator = (const CPlayer& cPlayer);		// assignment operator
	ostream&			operator << (ostream& cOut) const;			// extraction operator
	bool				operator > (const CPlayer& cPlayer) const;	// greater than operator
	bool				operator < (const CPlayer& cPlayer) const;	// less than operator
	bool				operator == (const CPlayer& cPlayer) const;	// equal-to operator

	/* methods */
	inline string		GetPlayerName() const;						// get player name
	inline void			SetPlayerName(const string csName);			// set player name

	inline bool			GetSymbol() const;							// get player symbol
	inline void			SetSymbol(const bool bSymbolXO);			// set player symbol

	inline bool			IsSymbolO() const;							// symbol is O
	inline bool			IsSymbolX() const;							// symbol is X

	inline unsigned int	GetWins() const;							// get wins
	inline void			SetWins(const unsigned int uWin = 1);		// wins the game

	inline unsigned int	GetLosses() const;							// get losses
	inline void			SetLosses(const unsigned int uLoss = 1);	// losses the game

	inline unsigned int	GetTies() const;							// get ties
	inline void			SetTies(const unsigned int uTie = 1);		// its a tie

	int					GetScore() const;							// get score

	void				Display() const;							// display

private:
	void				Display(ostream& cOut) const;				// display

private:
	string m_csName;												// player name
	bool m_bSymbolXO;												// symbol type (true=X/false=O)
	CStats m_cStatistics;											// player statistics
};

