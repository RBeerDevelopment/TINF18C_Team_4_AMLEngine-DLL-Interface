//
// C++ Implementation: AttributeValueRequirementType
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


    AttributeValueRequirementType::AttributeValueRequirementType(xercesc::DOMNode* const& node)
            : CAEXBasicObject(node)
            , Name(*this)   // "@Name"
            , OrdinalScaledType(*this)  // "OrdinalScaledType"
            , NominalScaledType(*this)  // "NominalScaledType"
            , UnknownType(*this)    // "UnknownType"
    {
    }

    AttributeValueRequirementType::AttributeValueRequirementType(AttributeValueRequirementType const& other)
            : CAEXBasicObject(other.GetNode())
            , Name(*this)   // "@Name"
            , OrdinalScaledType(*this)  // "OrdinalScaledType"
            , NominalScaledType(*this)  // "NominalScaledType"
            , UnknownType(*this)    // "UnknownType"
    {
    }

    UnknownTypeType *AttributeValueRequirementType::New_UnknownType()
    {
        if (UnknownType.exists())
        {
            throw SchemaConformanceException("A UnknownType node is already existent. It is not allowed to add more than one UnknownType node to current element according to CAEX Schema");
        }
        else if (NominalScaledType.exists())
        {
            throw SchemaConformanceException("A NominalScaledType node is already existent. It is not allowed to add more than one child node to current element according to CAEX Schema");
        }
        else if (OrdinalScaledType.exists())
        {
            throw SchemaConformanceException("A OrdinalScaledType node is already existent. It is not allowed to add more than one child node to current element according to CAEX Schema");
        }
        else
        {
            return new UnknownTypeType(UnknownType.append());
        }

    }

    NominalScaledTypeType *AttributeValueRequirementType::New_NominalType()
    {
        if (UnknownType.exists())
        {
            throw SchemaConformanceException("A UnknownType node is already existent. It is not allowed to add more than one child node to current element according to CAEX Schema");
        }
        else if (NominalScaledType.exists())
        {
            throw SchemaConformanceException("A NominalScaledType node is already existent. It is not allowed to add more than one child node to current element according to CAEX Schema");
        }
        else if (OrdinalScaledType.exists())
        {
            throw SchemaConformanceException("A OrdinalScaledType node is already existent. It is not allowed to add more than one child node to current element according to CAEX Schema");
        }
        else
        {
            return new NominalScaledTypeType(NominalScaledType.append());
        }

    }

    OrdinalScaledTypeType *AttributeValueRequirementType::New_OrdinalType()
    {
        if (UnknownType.exists())
        {
            throw SchemaConformanceException("A UnknownType node is already existent. It is not allowed to add more than one child node to current element according to CAEX Schema");
        }
        else if (NominalScaledType.exists())
        {
            throw SchemaConformanceException("A NominalScaledType node is already existent. It is not allowed to add more than one child node to current element according to CAEX Schema");
        }
        else if (OrdinalScaledType.exists())
        {
            throw SchemaConformanceException("A OrdinalScaledType node is already existent. It is not allowed to add more than one child node to current element according to CAEX Schema");
        }
        else
        {
            return new OrdinalScaledTypeType(OrdinalScaledType.append());
        }

    }


}
