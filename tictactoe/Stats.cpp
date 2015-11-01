
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
}

ostream& CStats::operator << (ostream& cOut) const
{
	Display(cOut);
	return cOut;
}

inline int CStats::GetWins() const
{
	return m_uWin;
}

inline void CStats::SetWins(const unsigned int uWin/* = 1*/)
{
	m_uWin += uWin;
}

inline int CStats::GetLosses() const
{
	return m_uLoss;
}

inline void CStats::SetLosses(const unsigned int uLoss/* = 1*/)
{
	m_uLoss += uLoss;
}

inline int CStats::GetTies() const
{
	return m_uTie;
}

inline void CStats::SetTies(const unsigned int uTies/* = 1*/)
{
	m_uTie += uTies;
}

void CStats::Display() const
{
	Display(cout);
}

void CStats::Display(ostream& cOut) const
{
	cOut << "Wins   :) : " << GetWins() << endl;
	cOut << "Losses :( : " << GetLosses() << endl;
	cOut << "Ties   :\ : " << GetTies() << endl;
}
