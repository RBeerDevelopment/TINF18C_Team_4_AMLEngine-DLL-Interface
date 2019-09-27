//
// C++ Implementation: RoleClassLibType
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

namespace CAEX_ClassModel
{


    RoleClassLibType::RoleClassLibType(xercesc::DOMNode* const& node)
            : CAEXObject(node)
            , RoleClass(*this)  // "RoleClass"
    {
    }

    RoleClassLibType::RoleClassLibType(RoleClassLibType const& other)
            : CAEXObject(other.GetNode())
            , RoleClass(*this)  // "RoleClass"
    {
    }

    RoleFamilyType *RoleClassLibType::New_RoleClass(string_type name)
    {
        RoleFamilyType *roleClass = new RoleFamilyType(RoleClass.append());
        roleClass->Name = name;
        return roleClass;
    }

    void RoleClassLibType::Insert_RoleClass(RoleFamilyType *roleClass)
    {
        GetNode()->appendChild(roleClass->GetNode());
    }

    bool RoleClassLibType::Insert_Element(TypeBase *elementToInsert)
    {
        bool successfullyInserted = true;

        if (dynamic_cast<RoleFamilyType*>(elementToInsert) != NULL)
        {
            Insert_RoleClass(static_cast<RoleFamilyType*>(elementToInsert));
        }
        else
        {
            successfullyInserted = false;
        }

        return successfullyInserted;
    }


}
