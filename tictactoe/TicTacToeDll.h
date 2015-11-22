/**
 * TicTacToeDll.h
 *
 * Author:      Adnan Shaheen
 * Description: TicTacToeDll
 */
#pragma once

/**
 * Headers
 */
#include "AbstractTicTacToe.h"

/**
 * CTicTacToeDll class
 */
class CTicTacToeDll : public CAbstractTicTacToe
{
public:
	CTicTacToeDll() throw();
	virtual ~CTicTacToeDll();

	/** Create TicTacToe */
	virtual ITicTacToe*	CreateTicTacToe();

	/** Delete TicTacToe */
	virtual void		DeleteTicTacToe(ITicTacToe* pTicTacToe);
};

