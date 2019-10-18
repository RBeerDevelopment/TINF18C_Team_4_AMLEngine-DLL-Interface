#ifndef _CAEX_CLASSMODEL_COMMON_H_
#define _CAEX_CLASSMODEL_COMMON_H_


#ifdef _WIN32 // defined in windows

#ifdef CAEX_ClassModel_EXPORTS
#define CAEX_ClassModel_EXPORT	__declspec(dllexport)
#else
#define CAEX_ClassModel_EXPORT	__declspec(dllimport)
#endif

#else // !_WIN32

#define CAEX_ClassModel_EXPORT

#endif // _WIN32


#endif // _CEAX_CLASSMODEL_COMMON_H_
