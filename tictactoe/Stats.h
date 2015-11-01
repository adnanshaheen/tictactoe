
#pragma once

#include <iostream>
using namespace std;

class CStats
{
public:
	/* constructor/destructor */
	CStats();													// constructor
	CStats(const unsigned int uWin, const unsigned int uLoss, const unsigned int uTie);
	CStats(const CStats& cStats);								// copy constructor
	~CStats();													// destructor

	/* operator overloading */
	CStats& operator = (const CStats cStats);					// assignment operator
	ostream& operator << (ostream& cOut) const;					// extraction operator

	/* methods */
	inline int GetWins() const;									// get number of wins
	inline void SetWins(const unsigned int uWin = 1);			// set wins

	inline int GetLosses() const;								// get number of losses
	inline void SetLosses(const unsigned int uLoss = 1);		// set losses

	inline int GetTies() const;									// get number of ties
	inline void SetTies(const unsigned int uTies = 1);			// set ties

	void Display() const;										// display

private:
	void Display(ostream& cOut) const;							// display

private:
	unsigned int m_uWin;										// wins
	unsigned int m_uLoss;										// losses
	unsigned int m_uTie;										// ties
};

