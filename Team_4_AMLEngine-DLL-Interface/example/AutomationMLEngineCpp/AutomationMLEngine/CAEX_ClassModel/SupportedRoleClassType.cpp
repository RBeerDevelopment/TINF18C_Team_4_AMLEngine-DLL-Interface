//
// C++ Implementation: SupportedRoleClassType
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


    SupportedRoleClassType::SupportedRoleClassType(xercesc::DOMNode* const& node)
            : CAEXBasicObject(node)
            , RefRoleClassPath(*this)   // "@RefRoleClassPath"
            , MappingObject(*this)  // "MappingObject"
    {
    }

    SupportedRoleClassType::SupportedRoleClassType(SupportedRoleClassType const& other)
            : CAEXBasicObject(other.GetNode())
            , RefRoleClassPath(*this)   // "@RefRoleClassPath"
            , MappingObject(*this)  // "MappingObject"
    {
    }

    MappingType *SupportedRoleClassType::New_MappingObject()
    {

        if (MappingObject.exists())
        {
            throw SchemaConformanceException("A MappingObject node is already existent. It is not allowed to add more than one MappingObject node to current element according to CAEX Schema");
        }
        else
        {
            return new MappingType(MappingObject.append());
        }
    }

    void SupportedRoleClassType::Insert_MappingObject(MappingType *mappingObject)
    {

        if (MappingObject.exists())
        {
            throw SchemaConformanceException("A MappingObject node is already existent. It is not allowed to add more than one MappingObject node to current element according to CAEX Schema");
        }
        else
        {
            GetNode()->appendChild(mappingObject->GetNode());
        }
    }

    bool SupportedRoleClassType::Insert_Element(TypeBase *elementToInsert)
    {
        bool successfullyInserted = true;

        if (dynamic_cast<MappingType*>(elementToInsert) != NULL)
        {
            Insert_MappingObject(static_cast<MappingType*>(elementToInsert));
        }
        else
        {
            successfullyInserted = false;
        }

        return successfullyInserted;
    }

}
