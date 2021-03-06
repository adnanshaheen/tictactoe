/**
 * Board.h
 *
 * Author:      Adnan Shaheen
 * Description: Responsible to display and keep board
 */

#pragma once

/**
 * Headers
 */
#include <iostream>
using namespace std;

namespace tictactoe {

	/**
	 * Forward declarations
	 */
	class CRow;

	/**
	 * CBoard class
	 */
	class CBoard
	{
	public:
		/** Constructors/Destructors */
		CBoard() throw();											// Ctor
		CBoard(unsigned int uRows, unsigned int uCols) throw();		// Ctor, args
		CBoard(const CBoard& cBoard) throw();						// Copy Ctor
		~CBoard();													// Destructor

		/* overloading operator */
		friend ostream&			operator << (ostream& cOut,
											const CBoard& cBoard);	// extraction operator
		CRow*					operator [] (unsigned int nIndex) throw();	// index operator
		CBoard&					operator = (const CBoard& cBoard);	// assignment operator

		/* methods */
		void					Display() const throw();			// display data

		void					InitData();							// initialize data

		int GetAt(const unsigned int uRow,
			const unsigned int uCol) const throw();					// get item at index row's column

		void SetAt(const unsigned int uRow,
			const unsigned int uCol,
			const int nValue);										// set value at index row's column

		/* inline functions */
		// get rows
		inline int GetRows() const
		{
			return m_uRows;
		}

		// set rows
		inline void SetRows(const unsigned int uRows)
		{
			m_uRows = uRows;
		}

		// get cols
		inline int GetCols() const
		{
			return m_uCols;
		}

		// set cols
		inline void SetCols(const unsigned int uCols)
		{
			m_uCols = uCols;
		}

		// get item at index
		inline CRow* GetAt(const unsigned int uRow) const
		{
			return IsValid() ? m_ppRow[uRow] : NULL;
		}

		// set item at index
		inline void SetAt(const unsigned int uRow, CRow* const pRow)
		{
			if (IsValid())
				m_ppRow[uRow] = pRow;
		}

	private:
		void					Init();								 // initialize memory
		void					Release();							 // free memory
		void					Display(ostream& cOut) const;		 // display the data

		void					CopyData(const CBoard& cBoard);		 // copy the data

		// check for valid pointer
		inline bool IsValid() const
		{
			return m_ppRow != NULL ? true : false;
		}

		// check for index valid pointer
		inline bool IsValid(const unsigned int uRow) const
		{
			return IsValid() && m_ppRow[uRow] != NULL ? true : false;
		}

	private:
		unsigned int m_uRows;										 // number of rows
		unsigned int m_uCols;										 // number of cols
		CRow** m_ppRow;												 // rows
	};
}
