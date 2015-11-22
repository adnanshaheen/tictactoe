/**
 * ITicTacToe.h
 *
 * Author:      Adnan Shaheen
 * Description: Interface TicTacToe
 */

#pragma once

/**
 * Forward decls
 */
class ITicTacToe;

/**
 * Class to create TicTacToe
 */
class CAbstractTicTacToe
{
public:
	/** Destructor */
	virtual ~CAbstractTicTacToe() { }

	/** Create TicTacToe */
	virtual ITicTacToe*	CreateTicTacToe() = 0;

	/** Delete TicTacToe */
	virtual void		DeleteTicTacToe(ITicTacToe* pTicTacToe) = 0;
};

/**
 * Import/export
 */
#ifdef	TICTACTOE
#	define	TICTACTOE_DLL		__declspec(dllexport)
#else	// TICTACTOE_DLL
#	define	TICTACTOE_DLL		__declspec(dllimport)
#endif	// TICTACTOE_DLL

/**
 * Create new TicTacToe Interface.
 */
extern "C" TICTACTOE_DLL CAbstractTicTacToe* CreateInterface();
typedef CAbstractTicTacToe* (__cdecl *pCreateInterface)();

/**
 * Delete Disk Board Interface.
 */
extern "C" TICTACTOE_DLL void DeleteInterface(CAbstractTicTacToe* pInterface);
typedef void (__cdecl *pDeleteInterface)(CAbstractTicTacToe* pInterface);
