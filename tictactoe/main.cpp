
#include <iostream>
#include <string>
#include <list>
using namespace std;

#include "TicTacToe.h"
using namespace tictactoe;

int main()
{
	int nRes = 0;
	try {
		CTicTacToe cTicTacToe;
		nRes = cTicTacToe.StartGame();
	}
	catch (exception)
	{
	}
	return nRes;
}
