
#pragma once


#include <iostream>
using namespace std;

class CDeck
{
public:
	CDeck();
	CDeck(const CDeck& cDeck);
	~CDeck();

	CDeck& operator = (const CDeck& cDeck);
	ostream& operator << (ostream& cOut);
};

