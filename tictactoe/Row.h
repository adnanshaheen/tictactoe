
#pragma once
#include <iostream>
using namespace std;

class CRow
{
public:
	/* constructor/destructor */
	CRow();															// constructor
	CRow(unsigned int uSize);										// constructor
	CRow(const CRow& cRow);											// copy constructor
	~CRow();														// destructor

	/* overloading operator */
	ostream&				operator << (ostream& cOut);			// extraction operator
	int						operator [] (unsigned int nIndex);		// index operator
	CRow&					operator = (const CRow& cRow);			// assignment operator

	/* methods */
	inline int*				GetRow() const;							// get rows
	inline void				SetRow(int* const pRow);				// set rows

	inline unsigned int		GetSize() const;						// get size
	inline void				SetSize(const unsigned int uSize);		// set size

	inline int				GetAt(const unsigned int uIndex) const;	// get item at index
	inline void				SetAt(const unsigned int uIndex,
								const int nValue);					// set value at index

	void					Display() const;						// display data

private:
	void					InitRow();								// initialize memory
	void					ReleaseRow();							// free memory
	void					CopyData(const CRow& cRow);				// copy data
	void					Display(ostream& cOut) const;			// display the data

private:
	unsigned int m_uSize;											// number of items in one row
	int* m_pRow;													// row of board
};

