//
// C++ Interface: guid
//
// Description:
//
//
// Author: Christian Simon-Klar <csk@zuehlke,com>, (C) 2009
//
//
//
#ifndef _GLOBALUID_H_
#define _GLOBALUID_H_

#include "StdAfx.h"

namespace CAEX_ClassModel
{

class GlobalUID
{
private:
    unsigned char bytes[16];

public:
    GlobalUID();

    static GlobalUID* newGuid();
    string_type toString(const string_type format="") const;
};

}

#endif // !_GLOBALUID_H_