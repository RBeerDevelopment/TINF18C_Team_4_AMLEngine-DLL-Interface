//
// C++ Implementation: NominalScaledTypeType
//
// Description:
//
//
// Author: Christian Simon-Klar <csk@zuehlke,com>, (C) 2009
//
//
//
#include "StdAfx.h"
#include "NominalScaledTypeType.h"

namespace CAEX_ClassModel
{

    NominalScaledTypeType::NominalScaledTypeType(xercesc::DOMNode* const& node)
            : TypeBase(node)
            , RequiredValue(*this)  // "RequiredValue"
    {
    }

    NominalScaledTypeType::NominalScaledTypeType(NominalScaledTypeType const& other)
            : TypeBase(other.GetNode())
            , RequiredValue(*this)  // "RequiredValue"
    {
    }

    xs::CanyType *NominalScaledTypeType::New_RequiredValue()
    {
        xercesc::DOMNode *newValueNode = XercesTreeOperations::AddElement(GetNode(), members + _altova_mi_altova_NominalScaledTypeType_altova_RequiredValue);

        return new xs::CanyType(newValueNode);
    }

}
