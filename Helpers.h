#pragma once

#define LOBYTE(x)   (*((BYTE*)&(x)))   // low byte
#define LOWORD(x)   (*((WORD*)&(x)))   // low word
#define LODWORD(x)  (*((DWORD*)&(x)))  // low dword
#define HIBYTE(x)   (*((BYTE*)&(x)+1))
#define HIWORD(x)   (*((WORD*)&(x)+1))
#define HIDWORD(x)  (*((DWORD*)&(x)+1))
#define BYTEn(x, n)   (*((BYTE*)&(x)+n))
#define WORDn(x, n)   (*((WORD*)&(x)+n))

inline bool DoesFileExist(char const* path)
{
	struct stat buffer;
	return (stat(path, &buffer) == 0);
}