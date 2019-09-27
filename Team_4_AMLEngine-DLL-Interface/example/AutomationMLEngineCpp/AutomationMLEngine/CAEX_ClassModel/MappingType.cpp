//
// C++ Implementation: MappingType
//
// Description:
//
//
// Author: Christian Simon-Klar <csk@zuehlke.com>, (C) 2009
//
//
//
#include "StdAfx.h"
#include "CAEX_ClassModel.h"

namespace CAEX_ClassModel
{

MappingType::MappingType(xercesc::DOMNode* const& node)
: CAEXBasicObject(node)
, AttributeNameMapping(*this)   // "AttributeNameMapping"
, InterfaceNameMapping(*this)   // "InterfaceNameMapping"
{
}

MappingType::MappingType(MappingType const& other)
: CAEXBasicObject(other.GetNode())
, AttributeNameMapping(*this)   // "AttributeNameMapping"
, InterfaceNameMapping(*this)   // "InterfaceNameMapping"
{
}

AttributeNameMappingType *MappingType::New_AttributeNameMapping(string_type systemUnitAttributeName, string_type roleAttributeName)
{
    xercesc::DOMNode *newAttributeNameMappingNode = XercesTreeOperations::CreateElement(GetNode(), AttributeNameMapping.memberInfo());

    InsertAttributeNameMappingInternal(newAttributeNameMappingNode);

    AttributeNameMappingType *newAttributeNameMapping = new AttributeNameMappingType(newAttributeNameMappingNode);
    newAttributeNameMapping->SystemUnitAttributeName = systemUnitAttributeName;
    newAttributeNameMapping->RoleAttributeName = roleAttributeName;
    return newAttributeNameMapping;
}

void MappingType::InsertAttributeNameMappingInternal(xercesc::DOMNode *attributeNameMappingNode)
{
    if (this->InterfaceNameMapping.exists())
    {
        GetNode()->insertBefore(attributeNameMappingNode, InterfaceNameMapping.first().GetNode()->getNextSibling());
    }
    else
    {
        GetNode()->appendChild(attributeNameMappingNode);
    }
}

void MappingType::Insert_AttributeNameMapping(AttributeNameMappingType *attributeNameMapping)
{
    InsertAttributeNameMappingInternal(attributeNameMapping->GetNode());
}

InterfaceNameMappingType *MappingType::New_InterfaceNameMapping(string_type systemUnitInterfaceName, string_type roleInterfaceName)
{
    InterfaceNameMappingType *newInterfaceNameMapping = new InterfaceNameMappingType(InterfaceNameMapping.append());
    newInterfaceNameMapping->SystemUnitInterfaceName = systemUnitInterfaceName;
    newInterfaceNameMapping->RoleInterfaceName = roleInterfaceName;

    return newInterfaceNameMapping;
}

void MappingType::Insert_InterfaceNameMapping(InterfaceNameMappingType *interfaceNameMapping)
{
    GetNode()->appendChild(interfaceNameMapping->GetNode());
}

bool MappingType::Insert_Element(TypeBase *elementToInsert)
{
    bool successfullyInserted = true;

    if (dynamic_cast<InterfaceNameMappingType*>(elementToInsert) != 0)
    {
        Insert_InterfaceNameMapping(static_cast<InterfaceNameMappingType*>(elementToInsert));
    }
    else if (dynamic_cast<AttributeNameMappingType*>(elementToInsert) != 0)
    {

        Insert_AttributeNameMapping(static_cast<AttributeNameMappingType*>(elementToInsert));
    }
    else
    {
        successfullyInserted = false;
    }
    return successfullyInserted;
}

}