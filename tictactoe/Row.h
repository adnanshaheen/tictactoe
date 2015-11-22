/**
 * Board.h
 *
 * Author:      Adnan Shaheen
 * Description: Responsible to create and work on int array
 */

#pragma once

/**
 * Headers
 */
#include <iostream>
using namespace std;

namespace tictactoe {

	/**
	 * CBoard class
	 */
	class CRow
	{
	public:
		/** constructor/destructor */
		CRow() throw();													// constructor
		CRow(unsigned int uSize) throw();								// constructor
		CRow(const CRow& cRow) throw();									// copy constructor
		~CRow();														// destructor

		/* overloading operator */
		friend ostream&		operator << (ostream& cOut,
										const CRow& cRow);				// extraction operator
		int					operator [] (unsigned int nIndex) throw();	// index operator
		CRow&				operator = (const CRow& cRow);				// assignment operator

		/* methods */
		void				Display() const throw();					// display data

		void				CopyData(const CRow& cRow);					// copy data

		/* inline functions */
		// get rows
		inline int* GetRow() const
		{
			return m_pRow;
		}

		// set rows
		inline void SetRow(int* const pRow)
		{
			m_pRow = pRow;
		}

		// get size
		inline unsigned int GetSize() const
		{
			return m_uCols;
		}

		// set size
		inline void SetSize(const unsigned int uSize)
		{
			m_uCols = uSize;
		}

		// get item at index
		inline int GetAt(const unsigned int uIndex) const
		{
			return IsValid() && uIndex < GetSize() ? m_pRow[uIndex] : -1;
		}

		// set value at index
		inline void SetAt(const unsigned int uIndex,
			const int nValue)
		{
			if (IsValid() && uIndex < GetSize())
				m_pRow[uIndex] = nValue;
		}

	private:
		void					InitRow();								// initialize memory
		void					ReleaseRow();							// free memory
		void					Display(ostream& cOut) const;			// display the data

		// check for valid pointer
		inline bool IsValid() const
		{
			return m_pRow != NULL ? true : false;
		}

	private:
		unsigned int m_uCols;											// number of items in one row
		int* m_pRow;													// row of board
	};
}
