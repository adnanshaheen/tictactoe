
#include <iostream>
#include <string>
#include <Windows.h>
#include <tchar.h>

#include "AbstractTicTacToe.h"
#include "ITicTacToe.h"
using namespace std;

int main()
{
	int nRes = 0;
	HMODULE hModule	= NULL;
	ITicTacToe* pTicTacToe = NULL;
	CAbstractTicTacToe* pInterface = NULL;
	pDeleteInterface pTicTacToeDelete = NULL;

	try {

		wstring csLibrary = _T("TicTacToe.dll");

		hModule = LoadLibrary(csLibrary.c_str());
		if (hModule == NULL || hModule == INVALID_HANDLE_VALUE)
		{
			// Library could not be loaded
			cerr << "Error " << GetLastError() << " occured while opening library TicTacToe.dll" << endl;
			return -1;
		}

		// get module 'createInterface' function pointer
		pCreateInterface pTicTacToeCreate =
			(pCreateInterface) GetProcAddress(hModule, "CreateInterface");

		pTicTacToeDelete =
			(pDeleteInterface) GetProcAddress(hModule, "DeleteInterface");

		// create interface, using function pointer
		if (pTicTacToeCreate)
			pInterface = pTicTacToeCreate();
		if (pInterface) {

			// valid, create ITicTacToe interface
			pTicTacToe = pInterface->CreateTicTacToe();
			if (pTicTacToe) {

				// valid, start game
				nRes = pTicTacToe->StartGame();

				// done, delete ITicTacToe
				pInterface->DeleteTicTacToe(pTicTacToe);
			}
			else {
				// error message, can't load interface ITicTacToe
				cerr << "Couldn't create TicTacToe, contact owner :)" << endl;
			}
		}
		else {
			// error message, can't create TicTacToe abstract class
			cerr << "Couldn't create TicTacToe Interface, contact owner :)" << endl;
		}
	}
	catch (exception)
	{
	}

	if (pTicTacToeDelete)
		pTicTacToeDelete(pInterface);

	FreeLibrary(hModule);

	return nRes;
}
