#ifndef _T_DEFINES_H_
#define _T_DEFINES_H_

#ifdef _WIN32

#include <tchar.h>

#else   // not _WIN32

#define __T(x)   x
#define _T(x)    __T(x)

// what here follows are name substitutions for some string functions in non-unicode mode
#define _tcscat    strcat
#define _tcscmp    strcmp
#define _tcschr    strchr
#define _tcslen    strlen
#define _ttoi      atoi
#define _tcstol    strtol
#define _istspace  isspace
#define _tcstoul   strtoul
#define _tcstod    strtod
#define _tcsicmp   strcasecmp
#define _sntprintf snprintf
#define _stprintf  sprintf
#define _itoa      itoa
#define _totupper  toupper

#define _tfopen    fopen

#define _ttoi64(x) strtoll( (x), NULL, 0)

// now include all the substituted functions
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// these are function wrappers:
// the radix parameters are ignored and assumed to be 10
char * itoa(    int       value, char *str, int radix );
char * _i64toa( long long value, char *str, int radix );

// until here was non-unicode code

#endif  // _WIN32

#endif
