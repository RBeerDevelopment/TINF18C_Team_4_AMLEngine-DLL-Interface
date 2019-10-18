//
// C++ Implementation: LinkedObjects
//
// Description:
//
//
// Author: Christian Simon-Klar <csk@zuehlke.com>, (C) 2009
//
//
//

#include "StdAfx.h"
#include "LinkedObjects.h"

namespace CAEX_ClassModel
{

    string_type LinkedObjects::ToString()
    {
        return string_type("RefSideA: ").append(RefPartnerSideAElement->Name).append(", RefSideB: ").append(RefPartnerSideBElement->Name);
    }

}
