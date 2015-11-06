
#include "Stats.h"

CStats::CStats() : m_uWin(0), m_uLoss(0), m_uTie(0)
{
}

CStats::CStats(const unsigned int uWin, const unsigned int uLoss, const unsigned int uTie)
{
	m_uWin = uWin;
	m_uLoss = uLoss;
	m_uTie = uTie;
}

CStats::CStats(const CStats& cStats)
{
	SetWins(cStats.GetWins());
	SetLosses(cStats.GetLosses());
	SetTies(cStats.GetTies());
}

CStats::~CStats()
{
}

CStats& CStats::operator = (const CStats cStats)
{
	if (this != &cStats) {
		SetWins(cStats.GetWins());
		SetLosses(cStats.GetLosses());
		SetTies(cStats.GetTies());
	}
	return *this;
}

void CStats::Display() const
{
	Display(cout);
}

void CStats::Display(ostream& cOut) const
{
	cOut << "Wins   :) : " << GetWins() << endl;
	cOut << "Losses :( : " << GetLosses() << endl;
	cOut << "Ties   :\\ : " << GetTies() << endl;
}

ostream& operator << (ostream& cOut, const CStats& cStats)
{
	cStats.Display(cOut);
	return cOut;
}
