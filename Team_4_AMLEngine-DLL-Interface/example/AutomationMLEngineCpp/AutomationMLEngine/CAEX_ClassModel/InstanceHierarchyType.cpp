//
// C++ Implementation: InstanceHierarchyType
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
#include "GlobalUID.h"

namespace CAEX_ClassModel
{


    InstanceHierarchyType::InstanceHierarchyType(xercesc::DOMNode* const& node)
            : CAEXObject(node)
            , InternalElement(*this)    // "InternalElement"
    {
    }

    InstanceHierarchyType::InstanceHierarchyType(InstanceHierarchyType const& other)
            : CAEXObject(other.GetNode())
            , InternalElement(*this)    // "InternalElement"
    {
    }

    InternalElementType *InstanceHierarchyType::New_InternalElement(string_type internalElementName)
    {

        InternalElementType *internalElement = new InternalElementType(InternalElement.append());
        internalElement->Name = internalElementName;
        //create a new guid for the instance
        string_type instanceGuid = GlobalUID::newGuid()->toString(CAEXObject::GUID_FORMAT);
        //assign guid to instance
        internalElement->ID = instanceGuid;

        return internalElement;
    }

    void InstanceHierarchyType::Insert_InternalElement(InternalElementType *internalElement)
    {
        GetNode()->appendChild(internalElement->GetNode());

    }

    void InstanceHierarchyType::Insert_NewInstance(TypeBase *newInstanceObject)
    {
        if (newInstanceObject != NULL)
        {
            GetNode()->appendChild(newInstanceObject->GetNode());

        }
    }

    bool InstanceHierarchyType::Insert_Element(TypeBase *elementToInsert)
    {
        bool successfullyInserted = true;
        if (dynamic_cast<InternalElementType*>(elementToInsert) != NULL)
        {
            Insert_InternalElement(static_cast<InternalElementType*>(elementToInsert));
        }
        else
        {
            successfullyInserted = false;
        }
        return successfullyInserted;

    }

}
