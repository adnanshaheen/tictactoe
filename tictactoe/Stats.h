
#pragma once

#include <iostream>
using namespace std;

namespace tictactoe {

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
		friend ostream& operator << (ostream& cOut,
									const CStats& cStats);			// extraction operator

		/* methods */
		void Display() const;										// display

		/* inline functions */
		// get number of wins
		inline int GetWins() const
		{
			return m_uWin;
		}

		// set wins
		inline void SetWins(const unsigned int uWin = 1)// set wins
		{
			m_uWin += uWin;
		}

		// get number of losses
		inline int GetLosses() const
		{
			return m_uLoss;
		}

		inline void SetLosses(const unsigned int uLoss = 1)
		{
			m_uLoss += uLoss;
		}

		// get number of ties
		inline int GetTies() const
		{
			return m_uTie;
		}

		// set ties
		inline void SetTies(const unsigned int uTies = 1)
		{
			m_uTie += uTies;
		}

	private:
		void Display(ostream& cOut) const;							// display

	private:
		unsigned int m_uWin;										// wins
		unsigned int m_uLoss;										// losses
		unsigned int m_uTie;										// ties
	};
}
