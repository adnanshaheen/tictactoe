
#pragma once

#include <iostream>
#include <string>

using namespace std;

namespace tictactoe
{
	class CFile
	{
	public:
		// Construction / Destruction
		CFile();
		CFile(wstring pFilePath);
		CFile(const CFile& cFile);
		~CFile();

		// assignment operator
		CFile&			operator = (const CFile& cFile);

		/* inline functions */
		// Returns the stored file path associated with this file.
		inline wstring		GetFilePath() const
		{
			return m_csFilePath;
		}

		// Sets the file path for file.
		inline void		SetFilePath(wstring csFilePath)
		{
			m_csFilePath = csFilePath;
		}

		// Check if the file is currently Open
		inline bool		IsFileOpen() const
		{
			return m_hFile ? true : false;
		}

		/* methods */
		// To Create the file
		int				CreateFile(DWORD dwDesiredAccess,
								DWORD dwShareMode,
								DWORD dwCreationDisposition,
								DWORD dwFlagsAndAttributes);

		// To Read from file
		int				ReadFile(LPVOID lpBuffer,
								DWORD dwNumberOfBytesToRead,
								LPDWORD lpNumberOfBytesRead = NULL);

		// To write into the file
		int				WriteFile(LPCVOID lpBuffer,
								DWORD dwNumberOfBytesToWrite,
								LPDWORD lpNumberOfBytesWritten = NULL);

		// Close currently opened file
		bool			CloseFile();

		// To delete the file from a given path
		bool			DeleteFile();

		// Set the end of file to the current position of the file pointer.
		bool			SetEndOfFile();

	protected:
		HANDLE			m_hFile;			// Handle to the file
		wstring			m_csFilePath;		// Current file path
	};
}