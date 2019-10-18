//
// C++ Implementation: UnknownTypeType
//
// Description:
//
//
// Author: Christian Simon-Klar <csk@zuehlke,com>, (C) 2009
//
//
//
#include "StdAfx.h"
#include "CAEX_ClassModel.h"
#include "SchemaConformanceException.h"

namespace CAEX_ClassModel
{

    UnknownTypeType::UnknownTypeType(xercesc::DOMNode* const& node)
            : TypeBase(node)
            , Requirements(*this)   // "Requirements"
    {
    }

    UnknownTypeType::UnknownTypeType(UnknownTypeType const& other)
            : TypeBase(other.GetNode())
            , Requirements(*this)   // "Requirements"
    {
    }

    xs::CstringType *UnknownTypeType::New_Requirements()
    {
        if (Requirements.exists())
        {
            throw SchemaConformanceException("A Requirements node is already existent. It is not allowed to add more than one Requirements nodes to current element according to CAEX Schema");
        }
        else
        {
            xercesc::DOMNode *newReqNode = XercesTreeOperations::AddElement(GetNode(), members + _altova_mi_altova_UnknownTypeType_altova_Requirements);

            return new xs::CstringType(newReqNode);
        }

    }

}
