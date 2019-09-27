//
// C++ Interface: LogicReferenceAttributeType
//
// Description:
//
//
// Author: Christian Simon-Klar <csk@zuehlke.com>, (C) 2009
//
//
//
#ifndef _LOGICREFERENCEATTRIBUTETYPE_H_
#define _LOGICREFERENCEATTRIBUTETYPE_H_

#include "AttributeType.h"

namespace CAEX_ClassModel
{

    class LogicReferenceAttributeType : AttributeType
    {
    public:
        CAEX_ClassModel_EXPORT LogicReferenceAttributeType(xercesc::DOMNode *init): AttributeType(init) {}
    };

}

#endif // not _LOGICREFERENCEATTRIBUTETYPE_H_
