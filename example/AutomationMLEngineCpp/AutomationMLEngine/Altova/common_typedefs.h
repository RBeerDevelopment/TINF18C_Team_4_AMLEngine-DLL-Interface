/**************************************************************************
 *   Copyright (C) 2009 by Christian Simon-Klar   *
 *   csk@zuehlke,com   *
 *                                                                        *
 *   This program is free software; you can redistribute it and/or modify *
 *   it under the terms of the GNU General Public License as published by *
 *   the Free Software Foundation; either version 2 of the License, or    *
 *   (at your option) any later version.                                  *
 *                                                                        *
 *   This program is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of       *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        *
 *   GNU General Public License for more details.                         *
 *                                                                        *
 *   You should have received a copy of the GNU General Public License    *
 *   along with this program; if not, write to the                        *
 *   Free Software Foundation, Inc.,                                      *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.            *
 **************************************************************************/
#ifndef _COMMON_TYPEDEFS_H_
#define _COMMON_TYPEDEFS_H_

#if defined( __GNUC__ )

#if defined(UNICODE) || defined(_UNICODE)
//typedef std::wstring string_type;
typedef wchar_t      TCHAR;
#else
//typedef std::string  string_type;
typedef char         TCHAR;
#endif // defined UNICODE or _UNICODE

#define __int64 long long
//typedef long long    __int64;


// number constants
#include <climits>
// plus the following defines
#define _I32_MIN    (-2147483647l - 1) /* minimum signed 32 bit value */
#define _I32_MAX      2147483647l /* maximum signed 32 bit value */
#define _UI32_MAX     0xfffffffful /* maximum unsigned 32 bit value */
/* minimum signed 64 bit value */
#define _I64_MIN    (-9223372036854775807ll - 1)
/* maximum signed 64 bit value */
#define _I64_MAX      9223372036854775807ll
/* maximum unsigned 64 bit value */
#define _UI64_MAX     0xffffffffffffffffull

#endif // __GNUC__

#endif // _COMMON_TYPEDEFS_H_
