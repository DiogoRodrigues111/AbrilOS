#ifndef TYPES_H
#define TYPES_H

#define UNSIGNED 	unsigned
#define SIGNED		signed
#define CONST 		const

enum _BOOLEAN {
	false  = 0,
	true = 1
};
typedef enum _BOOLEAN BOOLEAN;
typedef BOOLEAN BOOL;
typedef BOOL KERNELSTATUS;

typedef UNSIGNED char UCHAR;
typedef UNSIGNED short USHORT;
typedef UNSIGNED int UINT;
typedef void VOID;
typedef void* PVOID;
typedef short SHORT;
typedef UNSIGNED long ULONG;
typedef long int LONG;
typedef long long LONGLONG;
typedef LONG DWORD;
typedef USHORT WORD;
typedef UCHAR BYTE;
typedef int INT;
typedef double DOUBLE;
typedef char CHAR;
typedef const char* WCHAR;

typedef UNSIGNED char uchar;
typedef UNSIGNED short ushort;
typedef UNSIGNED int uint_t;
typedef void void_t;
typedef void* pvoid;
typedef short short_t;
typedef UNSIGNED long ulong_t;
typedef long long_t;
typedef unsigned long int dword_t;
typedef USHORT word_t;
typedef UCHAR byte;
typedef int int_t;
typedef double double_t;
typedef char char_t;
typedef const char* wchar_pt;

#endif


