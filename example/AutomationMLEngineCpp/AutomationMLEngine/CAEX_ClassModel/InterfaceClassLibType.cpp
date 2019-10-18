//
// C++ Implementation: InterfaceClassLibType
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


    InterfaceClassLibType::InterfaceClassLibType(xercesc::DOMNode* const& node)
            : CAEXObject(node)
            , InterfaceClass(*this) // "InterfaceClass"
    {
    }

    InterfaceClassLibType::InterfaceClassLibType(InterfaceClassLibType const& other)
            : CAEXObject(other.GetNode())
            , InterfaceClass(*this) // "InterfaceClass"
    {
    }

    InterfaceFamilyType *InterfaceClassLibType::New_InterfaceClass(string_type name)
    {
        InterfaceFamilyType *interfaceClass = new InterfaceFamilyType(InterfaceClass.append());
        interfaceClass->Name = name;
        return interfaceClass;
    }

    void InterfaceClassLibType::Insert_InterfaceClass(InterfaceFamilyType *interfaceFamilyType)
    {
        GetNode()->appendChild(interfaceFamilyType->GetNode());
    }

    bool InterfaceClassLibType::Insert_Element(TypeBase *elementToInsert)
    {
        bool successfullyInserted = true;

        if (dynamic_cast<InterfaceFamilyType*>(elementToInsert) != NULL)
        {
            Insert_InterfaceClass(static_cast<InterfaceFamilyType*>(elementToInsert));
        }
        else
        {
            successfullyInserted = false;
        }

        return successfullyInserted;
    }


}
