/**
 * ITicTacToe.h
 *
 * Author:      Adnan Shaheen
 * Description: Interface TicTacToe
 */

#pragma once

/**
 * Interface
 */
class ITicTacToe
{
public:
	virtual ~ITicTacToe() {}

	virtual int StartGame() = 0;
};
