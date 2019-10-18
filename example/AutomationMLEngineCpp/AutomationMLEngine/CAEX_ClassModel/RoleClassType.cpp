//
// C++ Implementation: RoleClassType
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

RoleClassType::RoleClassType(xercesc::DOMNode* const& node)
    : CAEXObject(node)
    , RefBaseClassPath(*this)   // "@RefBaseClassPath"
    , Attribute(*this)  // "Attribute"
    , ExternalInterface(*this)  // "ExternalInterface"
    , geometryReferenceAttribute(this, getGeometryReferenceAttribute, NULL)
    , logicReferenceAttribute(this, getLogicReferenceAttribute, NULL)
    , frameAttribute(this, getFrameAttribute, NULL)
{
}

RoleClassType::RoleClassType(RoleClassType const& other)
    : CAEXObject(other.GetNode())
    , RefBaseClassPath(*this)   // "@RefBaseClassPath"
    , Attribute(*this)  // "Attribute"
    , ExternalInterface(*this)  // "ExternalInterface"
    , geometryReferenceAttribute(this, getGeometryReferenceAttribute, NULL)
    , logicReferenceAttribute(this, getLogicReferenceAttribute, NULL)
    , frameAttribute(this, getFrameAttribute, NULL)
{
}

AttributeType *RoleClassType::New_Attribute(std::string attributeName)
{
    xercesc::DOMNode *newAttributeNode = XercesTreeOperations::CreateElement(GetNode(), Attribute.memberInfo());

    InsertAttributeNodeInternal(newAttributeNode);

    AttributeType *newAttribute = new AttributeType(newAttributeNode);
    newAttribute->Name = attributeName;
    return newAttribute;
}

void RoleClassType::InsertAttributeNodeInternal(xercesc::DOMNode *attributeNode)
{
    xercesc::DOMNode *lastHeaderNode = this->getLastHeaderNode();
    if (lastHeaderNode != 0)
    {
        GetNode()->insertBefore(attributeNode, lastHeaderNode->getNextSibling());
    }
    else
    {
        GetNode()->insertBefore(attributeNode, GetNode()->getFirstChild());
    }
}

void RoleClassType::Insert_Attribute(AttributeType *attributeElement)
{
    this->InsertAttributeNodeInternal(attributeElement->GetNode());
}

void RoleClassType::InsertExternalInterfaceNodeInternal(xercesc::DOMNode *interfaceNode)
{
    if (this->Attribute.exists())
    {
        GetNode()->insertBefore(interfaceNode, Attribute.last().GetNode()->getNextSibling());
    }
    else
    {
        xercesc::DOMNode *lastHeaderNode = this->getLastHeaderNode();
        if (lastHeaderNode != 0)
        {
            GetNode()->insertBefore(interfaceNode, lastHeaderNode->getNextSibling());
        }
        else
        {
            GetNode()->insertBefore(interfaceNode, GetNode()->getFirstChild());
        }
    }
}

void RoleClassType::Insert_ExternalInterface(InterfaceClassType *interfaceElement)
{
    InsertExternalInterfaceNodeInternal(interfaceElement->GetNode());
}

InterfaceClassType *RoleClassType::New_ExternalInterface(std::string name)
{
    xercesc::DOMNode *newExternalInterfaceNode = XercesTreeOperations::CreateElement(GetNode(), ExternalInterface.memberInfo());

    InsertExternalInterfaceNodeInternal(newExternalInterfaceNode);

    InterfaceClassType *newExternalInterface = new InterfaceClassType(newExternalInterfaceNode);
    newExternalInterface->Name = name;
    return newExternalInterface;
}

// TODO implement getAttributeField()
//MemberElement_Attribute *RoleClassType::getAttributeField()
//{
//    return this->Attribute;
//}

COLLADAReferenceAttributeType* RoleClassType::getGeometryReferenceAttribute(void *instance)
{
    RoleClassType *object = static_cast<RoleClassType*>(instance);
    return object->getGeometryReference();
}


LogicReferenceAttributeType *RoleClassType::getLogicReferenceAttribute(void *instance)
{
    RoleClassType *object = static_cast<RoleClassType*>(instance);
    return object->getLogicReference();
}


FrameAttributeType *RoleClassType::getFrameAttribute(void *instance)
{
    RoleClassType *object = static_cast<RoleClassType*>(instance);
    return object->getFrameAttribute();
}

LogicReferenceAttributeType *RoleClassType::getLogicReference()
{
    LogicReferenceAttributeType *logicReference = 0;

    for (Attribute::iterator attribute = Attribute.all(); attribute; ++attribute)
    {
        if (attribute->Name.exists())
        {
                //an attribute is found with name value set to "LogicReference"
                //this one is returned as geometryReference attribute
            if (string_type(attribute->Name).compare(AttributeType::LOGIC_REFERENCE) == 0)
            {
                logicReference = new LogicReferenceAttributeType(attribute->GetNode());
                break;
            }
        }
    }
    logicReferenceAttribute = logicReference;

    return logicReference;
}

COLLADAReferenceAttributeType *RoleClassType::getGeometryReference()
{
    COLLADAReferenceAttributeType *geometryReference = 0;

    for (Attribute::iterator attribute = Attribute.all(); attribute; ++attribute)
    {
        if (attribute->Name.exists())
        {
                //an attribute is found with name value set to "GeometryReference"
                //this one is returned as geometryReference attribute
            if (string_type(attribute->Name).compare(AttributeType::COLLADA_REFERENCE) == 0)
            {
                geometryReference = new COLLADAReferenceAttributeType(attribute->GetNode());
                break;
            }
        }
    }
    geometryReferenceAttribute = geometryReference;

    return geometryReference;
}

FrameAttributeType *RoleClassType::getFrameAttribute()
{
    try
    {
        FrameAttributeType *frameAttributeTemp = 0;

        for (Attribute::iterator attribute = Attribute.all(); attribute; ++attribute)
        {
            if (attribute->Name.exists())
            {
                    //an attribute is found with name value set to "Frame"
                if (string_type(attribute->Name).compare(AttributeType::FRAME_NAME) == 0)
                {
                    frameAttributeTemp = new FrameAttributeType(attribute->GetNode());
                    break;
                }
            }
        }
        frameAttribute = frameAttributeTemp;

        return frameAttributeTemp;
    }
    catch (Exception *ex)
    {
        throw;
    }
}

}
