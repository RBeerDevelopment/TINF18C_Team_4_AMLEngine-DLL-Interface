//
// C++ Implementation: OrdinalScaledTypeType
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


    OrdinalScaledTypeType::OrdinalScaledTypeType(xercesc::DOMNode* const& node)
            : TypeBase(node)
            , RequiredMaxValue(*this)   // "RequiredMaxValue"
            , RequiredValue(*this)  // "RequiredValue"
            , RequiredMinValue(*this)   // "RequiredMinValue"
    {
    }

    OrdinalScaledTypeType::OrdinalScaledTypeType(OrdinalScaledTypeType const& other)
            : TypeBase(other.GetNode())
            , RequiredMaxValue(*this)   // "RequiredMaxValue"
            , RequiredValue(*this)  // "RequiredValue"
            , RequiredMinValue(*this)   // "RequiredMinValue"
    {
    }

    xs::CanyType *OrdinalScaledTypeType::New_RequiredMaxValue()
    {
        if (RequiredMaxValue.exists())
        {
            throw SchemaConformanceException("A RequiredMaxValue node is already existent. It is not allowed to add more than one RequiredMaxValue nodes to current element according to CAEX Schema");
        }
        else
        {
            xercesc::DOMNode *newMaxValueNode = XercesTreeOperations::CreateElement(GetNode(), members + _altova_mi_altova_OrdinalScaledTypeType_altova_RequiredMaxValue);

            GetNode()->insertBefore(newMaxValueNode, GetNode()->getFirstChild());
            return new xs::CanyType(newMaxValueNode);
        }

    }

    xs::CanyType *OrdinalScaledTypeType::New_RequiredValue()
    {
        if (RequiredValue.exists())
        {
            throw SchemaConformanceException("A RequiredValue node is already existent. It is not allowed to add more than one RequiredValue nodes to current element according to CAEX Schema");
        }
        else
        {
            xercesc::DOMNode *newValueNode = XercesTreeOperations::CreateElement(GetNode(), members + _altova_mi_altova_OrdinalScaledTypeType_altova_RequiredValue);

            if (RequiredMaxValue.exists())
            {
                if (RequiredMinValue.exists())
                    GetNode()->insertBefore(newValueNode, RequiredMinValue.first().GetNode());
                else
                    GetNode()->appendChild(newValueNode);
            }
            else
            {
                GetNode()->insertBefore(newValueNode, GetNode()->getFirstChild());
            }
            return new xs::CanyType(newValueNode);
        }
    }

    xs::CanyType *OrdinalScaledTypeType::New_RequiredMinValue()
    {
        if (RequiredMinValue.exists())
        {
            throw SchemaConformanceException("A RequiredMinValue node is already existent. It is not allowed to add more than one RequiredMinValue nodes to current element according to CAEX Schema");
        }
        else
        {
            xercesc::DOMNode *newMinValueNode = XercesTreeOperations::AddElement(GetNode(), members + _altova_mi_altova_OrdinalScaledTypeType_altova_RequiredMinValue);

            return new xs::CanyType(newMinValueNode);
        }
    }

}
