
#include <Windows.h>
#include "File.h"

using namespace tictactoe;

CFile::CFile() : m_hFile(NULL)
{
}

CFile::CFile(wstring csFilePath)
{
	m_hFile = NULL;
	m_csFilePath = csFilePath;
}

CFile::CFile(const CFile& cFile)
{
}

CFile::~CFile()
{
	// Make sure that the file is closed.
	CloseFile();
}

int CFile::CreateFile(DWORD dwDesiredAccess,
					  DWORD dwShareMode,
					  DWORD dwCreationDisposition,
					  DWORD dwFlagsAndAttributes)
{
	// Make sure that the file is closed.
	CloseFile();

	m_hFile = ::CreateFile(m_csFilePath.c_str(), dwDesiredAccess, dwShareMode, NULL, dwCreationDisposition, dwFlagsAndAttributes, NULL);
	m_hFile = (m_hFile == INVALID_HANDLE_VALUE) ? NULL: m_hFile;

	if (!m_hFile)
		cerr << "Error " << GetLastError() << " occured while creating file ..." << endl;

	return m_hFile ? 0 : -1;
}

int CFile::ReadFile(LPVOID lpBuffer, DWORD dwNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead)
{
	if (!m_hFile || !lpBuffer || dwNumberOfBytesToRead == 0) {
		cerr << "Invalid parameter ... " << endl;
		return -1;
	}

	DWORD dwNumberOfBytesRead = 0;
	lpNumberOfBytesRead = lpNumberOfBytesRead ? lpNumberOfBytesRead : &dwNumberOfBytesRead;
	BOOL bRet = ::ReadFile(m_hFile, lpBuffer, dwNumberOfBytesToRead, lpNumberOfBytesRead, NULL);
	if (!bRet)
		cerr << "Couldn't read from file due to error " << GetLastError() << endl;

	return bRet ? 0: -1;
}

int CFile::WriteFile(LPCVOID lpBuffer, DWORD dwNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten)
{
	if (!m_hFile || !lpBuffer || dwNumberOfBytesToWrite == 0) {
		cerr << "Invalid parameter ... " << endl;
		return -1;
	}

	DWORD dwNumberOfBytesWritten = 0;
	lpNumberOfBytesWritten = lpNumberOfBytesWritten ? lpNumberOfBytesWritten : &dwNumberOfBytesWritten;
	BOOL bRet = ::WriteFile(m_hFile, lpBuffer, dwNumberOfBytesToWrite, lpNumberOfBytesWritten, NULL);

	if (!bRet)
		cerr << "Couldn't write to file due to error " << GetLastError() << endl;

	return bRet ? 0: -1;
}

bool CFile::CloseFile()
{
	bool bRet = false;
	if (m_hFile) {
		bRet = ::CloseHandle(m_hFile) ? true : false;
		m_hFile = NULL;
	}
	return bRet;
}

bool CFile::DeleteFile()
{
	if (!::DeleteFile(GetFilePath().c_str())) {

		cerr << "Couldn't delete file due to error " << GetLastError() << endl;
		return false;
	}

	return true;
}

bool CFile::SetEndOfFile()
{
	// Is file open?
	if (!IsFileOpen()) {
		cerr << "File is not open ..." << endl;
		return false;
	}

	bool bRes = ::SetEndOfFile(m_hFile) ? true : false;
	if (!bRes)
		cerr << "Couldn't set EOF due to error " << GetLastError() << endl;
	return bRes;
}
