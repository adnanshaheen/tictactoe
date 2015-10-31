
#pragma once

#include <iostream>
using namespace std;

class CPlayer
{
public:
	CPlayer();
	CPlayer(const CPlayer& cPlayer);
	~CPlayer();

	CPlayer& operator = (const CPlayer& cPlayer);
	ostream& operator << (ostream& cOut);
};

