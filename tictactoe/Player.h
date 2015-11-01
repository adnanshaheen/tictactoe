
#pragma once

#include <iostream>
using namespace std;

class CPlayer
{
public:
	/* constructor/destructor */
	CPlayer();												// constructor
	CPlayer(string csName, bool bSymbolXO);					// constructor
	CPlayer(const CPlayer& cPlayer);						// copy constructor
	~CPlayer();												// destructor

	/* operator overloading */
	CPlayer&		operator = (const CPlayer& cPlayer);	// assignment operator
	ostream&		operator << (ostream& cOut);			// extraction operator
	bool			operator > (const CPlayer& cPlayer);	// greater than operator
	bool			operator < (const CPlayer& cPlayer);	// less than operator
	bool			operator == (const CPlayer& cPlayer);	// equal-to operator

	inline string	GetPlayerName() const;					// get player name
	inline void		SetPlayerName(const string csName);		// set player name

	inline bool		GetSymbol() const;						// get player symbol
	inline void		SetSymbol(const bool bSymbolXO);		// set player symbol

	inline bool		IsSymbolO() const;						// symbol is O
	inline bool		IsSymbolX() const;						// symbol is X

private:
	string m_csName;										// player name
	bool m_bSymbolXO;										// symbol type (X/O)
};

