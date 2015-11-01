
#pragma once

class CRow;

class CBoard
{
public:
	CBoard();
	CBoard(unsigned int uRows, unsigned int uCols);
	CBoard(const CBoard& cBoard);
	~CBoard();

	/* overloading operator */
	ostream&				operator << (ostream& cOut) const;		// extraction operator
	CRow*					operator [] (unsigned int nIndex);		// index operator
	CBoard&					operator = (const CBoard& cBoard);		// assignment operator

	/* methods */
	inline int				GetRows() const;						// get rows
	inline void				SetRows(const unsigned int uRows);		// set rows

	inline int				GetCols() const;						// get cols
	inline void				SetCols(const unsigned int uCols);		// set cols

	inline CRow*			GetAt(const unsigned int uRow) const;	// get item at index
	inline void				SetAt(const unsigned int uRow,
								CRow* const pRow);					// set item at index

	inline int				GetAt(const unsigned int uRow,
								const unsigned int uCol) const;		// get item at index row's column
	inline void				SetAt(const unsigned int uRow,
								const unsigned int uCol,
								const int nValue);					// set value at index row's column

	void					Display() const;						// display data

private:
	void					Init();									// initialize memory
	void					Release();								// free memory
	void					Display(ostream& cOut) const;			// display the data

	inline bool				IsValid() const;						// check for valid pointer
	inline bool				IsValid(const unsigned int uRow) const;	// check for index valid pointer

	void					CopyData(const CBoard& cBoard);			// copy the data

private:
	unsigned int m_uRows;											// number of rows
	unsigned int m_uCols;											// number of cols
	CRow** m_ppRow;													// rows
};

