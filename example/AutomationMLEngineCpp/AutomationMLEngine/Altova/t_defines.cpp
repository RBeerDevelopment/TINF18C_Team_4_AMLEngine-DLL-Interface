/***************************************************************************
 *   Copyright (C) 2009 by Christian Simon-Klar   *
 *   csk@zuehlke,com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "t_defines.h"

// these are a function wrappers:
// the radix parameters are ignored and assumed to be 10
char * itoa(int value,char *str,int radix)
{
    sprintf(str,"%i",value); return str;
}

char * _i64toa(long long value, char *str, int radix )
{
     sprintf(str,"%lli",value); return str;
}
