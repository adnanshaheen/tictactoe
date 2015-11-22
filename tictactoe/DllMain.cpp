/**
 * DllMain.cpp
 *
 * Entry point to dll
 */

/**
 * Headers
 */
#include <Windows.h>
#include "AbstractTicTacToe.h"
#include "TicTacToeDll.h"

/**
 * DLL Entry
 */
bool APIENTRY DllMain(HANDLE hModule,
					  DWORD  ul_reason_for_call,
					  LPVOID lpReserved)
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    return true;
}

/**
 * Create CTicTacToeDll class object
 */
extern "C" TICTACTOE_DLL CAbstractTicTacToe* CreateInterface()
{
	return new CTicTacToeDll();
}

/**
 * Delete CTicTacToeDll class object
 */
extern "C" TICTACTOE_DLL void DeleteInterface(CAbstractTicTacToe* pInterface)
{
	if (pInterface)
		delete pInterface;
}
