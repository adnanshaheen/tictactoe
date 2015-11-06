
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
	bool				operator > (const CPlayer& cPlayer) const;	// greater than operator
	bool				operator < (const CPlayer& cPlayer) const;	// less than operator
	bool				operator == (const CPlayer& cPlayer) const;	// equal-to operator

	friend ostream&		operator << (ostream& cOut,
									const CPlayer& cPlayer);		// extraction operator
	friend istream&		operator >> (istream& cIn,
									CPlayer& cPlayer);				// insertion operator

	/* methods */
	int					GetScore() const;							// get score

	void				Display() const;							// display

	/* inline functions */
	// get player name
	inline string GetPlayerName() const
	{
		return m_csName;
	}

	// set player name
	inline void SetPlayerName(const string csName)
	{
		m_csName = csName;
	}

	// get player symbol
	inline bool GetSymbol() const
	{
		return m_bSymbolXO;
	}

	// set player symbol
	inline void SetSymbol(const bool bSymbolXO)
	{
		m_bSymbolXO = bSymbolXO;
	}

	// symbol is O
	inline bool IsSymbolO() const
	{
		return m_bSymbolXO == false;
	}

	// symbol is X
	inline bool IsSymbolX() const
	{
		return m_bSymbolXO == true;
	}

	// get wins
	inline unsigned int GetWins() const
	{
		return m_cStatistics.GetWins();
	}

	// wins the game
	inline void SetWins(const unsigned int uWin = 1)
	{
		m_cStatistics.SetWins(uWin);
	}

	// get losses
	inline unsigned int GetLosses() const
	{
		return m_cStatistics.GetLosses();
	}

	// losses the game
	inline void SetLosses(const unsigned int uLoss = 1)
	{
		m_cStatistics.SetLosses(uLoss);
	}

	// get ties
	inline unsigned int GetTies() const
	{
		return m_cStatistics.GetTies();
	}

	// its a tie
	inline void SetTies(const unsigned int uTie = 1)
	{
		m_cStatistics.SetTies(uTie);
	}

private:
	void				Display(ostream& cOut) const;				// display

	// get symbol
	inline char GetSymbolChar() const
	{
		return IsSymbolX() ? 'X' : 'O';
	}

private:
	string m_csName;												// player name
	bool m_bSymbolXO;												// symbol type (true=X/false=O)
	CStats m_cStatistics;											// player statistics
};

