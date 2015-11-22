/**
 * TicTacToeDll.cpp
 *
 * Implementation CTicTacToeDll class
 */

/**
 * Headers
 */
#include <iostream>
#include "TicTacToeDll.h"
#include "TicTacToe.h"

using namespace std;
using namespace tictactoe;


/**
 * Constructor
 *
 * Default Constructor
 *
 * Throws any exception raised
 */
CTicTacToeDll::CTicTacToeDll() throw()
{
}

/**
 * Destructor
 *
 * Destructor, Release any memory created
 */
CTicTacToeDll::~CTicTacToeDll()
{
}

/**
 * CreateTicTacToe
 *
 * Create ITicTacToe interface
 *
 * Catches and throws any exception
 */
ITicTacToe* CTicTacToeDll::CreateTicTacToe()
{
	ITicTacToe* pTicTacToe = NULL;
	try {
		pTicTacToe = new CTicTacToe();
	}
	catch (exception e)
	{
		cerr << e.what() << endl;
		throw e;
	}
	catch (...)
	{
		cerr << "Something bad happened!!!" << endl;
		cerr << "File: " << __FILE__ << endl;
		cerr << "Line: " << __LINE__ << endl;
		throw;
	}
	return pTicTacToe;
}

/**
 * CreateTicTacToe
 *
 * Delete ITicTacToe interface
 *
 * Catches and throws any exception
 */
void CTicTacToeDll::DeleteTicTacToe(ITicTacToe* pTicTacToe)
{
	try {
		if (pTicTacToe)
			delete pTicTacToe;
	}
	catch (exception e) {
		cerr << e.what() << endl;
		throw e;
	}
	catch (...)
	{
		cerr << "Something bad happened!!!" << endl;
		cerr << "File: " << __FILE__ << endl;
		cerr << "Line: " << __LINE__ << endl;
		throw;
	}
}
