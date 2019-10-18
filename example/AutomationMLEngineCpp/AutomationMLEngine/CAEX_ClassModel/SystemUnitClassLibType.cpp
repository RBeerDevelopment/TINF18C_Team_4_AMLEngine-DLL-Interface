//
// C++ Implementation: SystemUnitClassLibType
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

    SystemUnitClassLibType::SystemUnitClassLibType(xercesc::DOMNode* const& node)
            : CAEXObject(node)
            , SystemUnitClass(*this)    // "SystemUnitClass"
    {
    }

    SystemUnitClassLibType::SystemUnitClassLibType(SystemUnitClassLibType const& other)
            : CAEXObject(other.GetNode())
            , SystemUnitClass(*this)    // "SystemUnitClass"
    {
    }

    SystemUnitFamilyType *SystemUnitClassLibType::New_SystemUnitClass(string_type name)
    {
        SystemUnitFamilyType *systemUnitClass = new SystemUnitFamilyType(SystemUnitClass.append());
        systemUnitClass->Name = name;
        return systemUnitClass;
    }

    void SystemUnitClassLibType::Insert_SystemUnitClass(SystemUnitFamilyType *systemUnitClass)
    {
        GetNode()->appendChild(systemUnitClass->GetNode());
    }

    bool SystemUnitClassLibType::Insert_Element(TypeBase *elementToInsert)
    {
        bool successfullyInserted = true;

        if (dynamic_cast<SystemUnitFamilyType*>(elementToInsert) != NULL)
        {
            Insert_SystemUnitClass(static_cast<SystemUnitFamilyType*>(elementToInsert));
        }
        else
        {
            successfullyInserted = false;
        }
        return successfullyInserted;
    }


}
