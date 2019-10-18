//
// C++ Implementation: SystemUnitClassType
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
#include "XercesString.h"
#include "GlobalUID.h"
//#include "LogicReferenceAttributeType.h"

namespace CAEX_ClassModel
{

SystemUnitClassType::SystemUnitClassType(xercesc::DOMNode* const& node)
    : CAEXObject(node)
    , Attribute(*this)  // "Attribute"
    , ExternalInterface(*this)  // "ExternalInterface"
    , InternalElement(*this)    // "InternalElement"
    , SupportedRoleClass(*this) // "SupportedRoleClass"
    , InternalLink(*this)   // "InternalLink"
    , geometryReferenceAttribute(this, getGeometryReferenceAttribute, NULL)
    , logicReferenceAttribute(this, getLogicReferenceAttribute, NULL)
    , frameAttribute(this, getFrameAttribute, NULL)
{
}

SystemUnitClassType::SystemUnitClassType(SystemUnitClassType const& other)
    : CAEXObject(other.GetNode())
    , Attribute(*this)  // "Attribute"
    , ExternalInterface(*this)  // "ExternalInterface"
    , InternalElement(*this)    // "InternalElement"
    , SupportedRoleClass(*this) // "SupportedRoleClass"
    , InternalLink(*this)   // "InternalLink"
    , geometryReferenceAttribute(this, getGeometryReferenceAttribute, NULL)
    , logicReferenceAttribute(this, getLogicReferenceAttribute, NULL)
    , frameAttribute(this, getFrameAttribute, NULL)
{
}

COLLADAReferenceAttributeType* SystemUnitClassType::getGeometryReferenceAttribute(void *instance)
{
    SystemUnitClassType *object=static_cast<SystemUnitClassType*>(instance);
    return object->getGeometryReference();
}


LogicReferenceAttributeType *SystemUnitClassType::getLogicReferenceAttribute(void *instance)
{
    SystemUnitClassType *object=static_cast<SystemUnitClassType*>(instance);
    return object->getLogicReference();
}


FrameAttributeType *SystemUnitClassType::getFrameAttribute(void *instance)
{
    SystemUnitClassType *object=static_cast<SystemUnitClassType*>(instance);
    return object->getFrameAttribute();
}


void SystemUnitClassType::InsertAttributeNodeInternal(xercesc::DOMNode *attributeNode)
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

AttributeType *SystemUnitClassType::New_Attribute(string_type attributeName)
{
    xercesc::DOMNode *newAttributeNode = XercesTreeOperations::CreateElement(GetNode(), Attribute.memberInfo());

    InsertAttributeNodeInternal(newAttributeNode);

    AttributeType *newAttribute = new AttributeType(newAttributeNode);
    newAttribute->Name = attributeName;
    return newAttribute;
}

void SystemUnitClassType::Insert_Attribute(AttributeType *attributeElement)
{
    this->InsertAttributeNodeInternal(attributeElement->GetNode());
}

LogicReferenceAttributeType *SystemUnitClassType::New_LogicReference(xercesc::XMLUri *uri)
{

    AttributeType *logicAttribute = New_Attribute(AttributeType::LOGIC_REFERENCE);

    if (uri != 0)
    {
        logicAttribute->setValue(string_type(XercesUnstringTemp(uri->getUriText())));
    }
    else
    {
        logicAttribute->setValue("Specified URI not valid!");
    }

    LogicReferenceAttributeType *logicReferenceAttributeTemp = new LogicReferenceAttributeType(logicAttribute->GetNode());

    logicReferenceAttribute=logicReferenceAttributeTemp;

    return logicReferenceAttributeTemp;
}

COLLADAReferenceAttributeType *SystemUnitClassType::New_COLLADAReference(xercesc::XMLUri *uri)
{

    AttributeType *geometryAttribute = this->New_Attribute(AttributeType::COLLADA_REFERENCE);

    if (uri != 0)
    {
        geometryAttribute->setValue(string_type(XercesUnstringTemp(uri->getUriText())));
    }
    else
    {
        geometryAttribute->setValue("Specified URI not valid!");
    }

    COLLADAReferenceAttributeType *geometryReferenceAttributeTemp = new COLLADAReferenceAttributeType(geometryAttribute->GetNode());

    geometryReferenceAttribute=geometryReferenceAttributeTemp;

    return geometryReferenceAttribute;
}

FrameAttributeType *SystemUnitClassType::New_FrameAttribute(FrameValues *frameValues)
{
    xercesc::DOMNode *newAttributeNode = XercesTreeOperations::CreateElement(GetNode(), Attribute.memberInfo());

    xercesc::DOMNode *lastHeaderNode = this->getLastHeaderNode();
    if (lastHeaderNode != 0)
    {
        GetNode()->insertBefore(newAttributeNode, lastHeaderNode->getNextSibling());
    }
    else
    {
        GetNode()->insertBefore(newAttributeNode, GetNode()->getFirstChild());
    }

    FrameAttributeType *frameAttributeType = new FrameAttributeType(newAttributeNode);
    frameAttributeType->Frame = *frameValues;
    frameAttributeType->Name = AttributeType::FRAME_NAME;

    // store the new created frame attribute to get quick access
    frameAttribute=frameAttributeType;

    return frameAttributeType;

}

InterfaceClassType *SystemUnitClassType::New_ExternalInterface(string_type name)
{
    xercesc::DOMNode *newExternalInterfaceNode = XercesTreeOperations::CreateElement(GetNode(), ExternalInterface.memberInfo());

    InsertExternalInterfaceNodeInternal(newExternalInterfaceNode);

    InterfaceClassType *newExternalInterface = new InterfaceClassType(newExternalInterfaceNode);
    newExternalInterface->Name = name;
    return newExternalInterface;
}

void SystemUnitClassType::InsertExternalInterfaceNodeInternal(xercesc::DOMNode *externalInterfaceElementNode)
{
    if (this->Attribute.exists())
    {
        GetNode()->appendChild(externalInterfaceElementNode);
    }
    else
    {
        xercesc::DOMNode *lastHeaderNode = this->getLastHeaderNode();
        if (lastHeaderNode != 0)
        {
            GetNode()->insertBefore(externalInterfaceElementNode, lastHeaderNode->getNextSibling());
        }
        else
        {
            GetNode()->insertBefore(externalInterfaceElementNode, GetNode()->getFirstChild());
        }
    }
}

InternalElementType *SystemUnitClassType::New_InternalElement(string_type name)
{
    xercesc::DOMNode *newInternalElementNode = XercesTreeOperations::CreateElement(GetNode(), InternalElement.memberInfo());

    InsertInternalElementNodeInternal(newInternalElementNode);

    InternalElementType *newInternalElement = new InternalElementType(newInternalElementNode);
    newInternalElement->Name = name;
        //assigning a GUID to the new InternalElement
        //create a new guid for the instance
    string_type instanceGuid = GlobalUID::newGuid()->toString(CAEXObject::GUID_FORMAT);
        //assign guid to instance
    newInternalElement->ID = instanceGuid;

    return newInternalElement;
}

void SystemUnitClassType::InsertInternalElementNodeInternal(xercesc::DOMNode *internalElementNode)
{
    if (this->ExternalInterface.exists())
    {
        //GetParent(ExternalInterface.last())->appendChild(internalElementNode);
        GetNode()->insertBefore(internalElementNode, ExternalInterface.last().GetNode()->getNextSibling());
    }
    else if (this->Attribute.exists())
    {
        //GetNode()->InsertAfter(internalElementNode, this->Attribute->Last.Node);
        //GetParent(Attribute.last())->appendChild(internalElementNode);
        GetNode()->insertBefore(internalElementNode, Attribute.last().GetNode()->getNextSibling());
    }
    else
    {
        xercesc::DOMNode *lastHeaderNode = this->getLastHeaderNode();
        if (lastHeaderNode != 0)
        {
            GetNode()->insertBefore(internalElementNode, lastHeaderNode->getNextSibling());
        }
        else
        {
            GetNode()->insertBefore(internalElementNode,GetNode()->getFirstChild());
        }
    }
}

void SystemUnitClassType::Insert_InternalElement(InternalElementType *internalElement)
{
    InsertInternalElementNodeInternal(internalElement->GetNode());
}

void SystemUnitClassType::Insert_ExternalInterface(InterfaceClassType *interfaceElement)
{
    InsertExternalInterfaceNodeInternal(interfaceElement->GetNode());
}

bool SystemUnitClassType::Insert_NewInstance(TypeBase *newInstanceObject)
{
    bool insertionOk = false;

        //check type of object
    if (dynamic_cast<InternalElementType*>(newInstanceObject) != 0)
    {
        this->Insert_InternalElement(static_cast<InternalElementType*>(newInstanceObject));
        insertionOk = true;
    }
    else if (dynamic_cast<InterfaceClassType*>(newInstanceObject) != 0)
    {
        this->Insert_ExternalInterface(static_cast<InterfaceClassType*>(newInstanceObject));
        insertionOk = true;
    }

    return insertionOk;

}

void SystemUnitClassType::InsertSupportedRoleClassNodeInternal(xercesc::DOMNode *newSupportedRoleClassNode)
{

    if (this->InternalElement.exists())
    {
        //GetNode()->InsertAfter(newSupportedRoleClassNode, this->InternalElement->Last.Node);
        //GetParent(InternalElement.last())->appendChild(newSupportedRoleClassNode);
        GetNode()->insertBefore(newSupportedRoleClassNode, InternalElement.last().GetNode()->getNextSibling());
    }
    else if (this->ExternalInterface.exists())
    {
        //GetNode()->InsertAfter(newSupportedRoleClassNode, this->ExternalInterface->Last.Node);
        //GetParent(ExternalInterface.last())->appendChild(newSupportedRoleClassNode);
        GetNode()->insertBefore(newSupportedRoleClassNode, ExternalInterface.last().GetNode()->getNextSibling());
    }
    else if (this->Attribute.exists())
    {
        //GetNode()->InsertAfter(newSupportedRoleClassNode, this->Attribute->Last.Node);
        GetNode()->insertBefore(newSupportedRoleClassNode, Attribute.last().GetNode()->getNextSibling());
    }
    else
    {
        xercesc::DOMNode *lastHeaderNode = this->getLastHeaderNode();
        if (lastHeaderNode != 0)
        {
            GetNode()->insertBefore(newSupportedRoleClassNode, lastHeaderNode->getNextSibling());
        }
        else
        {
            GetNode()->insertBefore(newSupportedRoleClassNode, GetNode()->getFirstChild());
        }
    }
}

void SystemUnitClassType::Insert_SupportedRoleClass(SupportedRoleClassType *supportedRoleClassElement)
{

    this->InsertSupportedRoleClassNodeInternal(supportedRoleClassElement->GetNode());

}

SupportedRoleClassType *SystemUnitClassType::New_SupportedRoleClass(string_type refencedRoleClassPath)
{
    xercesc::DOMNode *newSupportedRoleClassNode = XercesTreeOperations::CreateElement(GetNode(), SupportedRoleClass.memberInfo());

    InsertSupportedRoleClassNodeInternal(newSupportedRoleClassNode);

    SupportedRoleClassType *newSupportedRoleClass = new SupportedRoleClassType(newSupportedRoleClassNode);
    newSupportedRoleClass->RefRoleClassPath = refencedRoleClassPath;
    return newSupportedRoleClass;
}

void SystemUnitClassType::InsertInternalLinkNodeInternal(xercesc::DOMNode *newInternalLinkNode)
{

    if (this->SupportedRoleClass.exists())
    {
        GetNode()->insertBefore(newInternalLinkNode, SupportedRoleClass.last().GetNode()->getNextSibling());
    }
    else if (this->InternalElement.exists())
    {
        GetNode()->insertBefore(newInternalLinkNode, InternalElement.last().GetNode()->getNextSibling());
    }
    else if (this->ExternalInterface.exists())
    {
        GetNode()->insertBefore(newInternalLinkNode, ExternalInterface.last().GetNode()->getNextSibling());
    }
    else if (this->Attribute.exists())
    {
        GetNode()->insertBefore(newInternalLinkNode, Attribute.last().GetNode()->getNextSibling());
    }
    else
    {
        xercesc::DOMNode *lastHeaderNode = this->getLastHeaderNode();
        if (lastHeaderNode != 0)
        {
            GetNode()->insertBefore(newInternalLinkNode, lastHeaderNode->getNextSibling());
        }
        else
        {
            GetNode()->insertBefore(newInternalLinkNode, GetNode()->getFirstChild());
        }
    }
}

void SystemUnitClassType::Insert_InternalLink(InternalLinkType *internalLinkElement)
{

    this->InsertInternalLinkNodeInternal(internalLinkElement->GetNode());
}

InternalLinkType *SystemUnitClassType::New_InternalLink(string_type name)
{
    xercesc::DOMNode *newInternalLinkNode = XercesTreeOperations::CreateElement(GetNode(), InternalLink.memberInfo());

    InsertInternalLinkNodeInternal(newInternalLinkNode);

    InternalLinkType *newInternalLink = new InternalLinkType(newInternalLinkNode);
    newInternalLink->Name = name;
    return newInternalLink;
}

LogicReferenceAttributeType *SystemUnitClassType::getLogicReference()
{
    LogicReferenceAttributeType *logicReference = 0;

    for (Attribute::iterator attribute = Attribute.all(); attribute; ++attribute)
    {
        if (attribute->Name.exists())
        {
                //an attribute is found with name value set to "LogicReference"
                //this one is returned as geometryReference attribute
            if (string_type(attribute->Name).compare(AttributeType::LOGIC_REFERENCE)==0)
            {
                logicReference = new LogicReferenceAttributeType(attribute->GetNode());
                break;
            }
        }
    }
    logicReferenceAttribute=logicReference;

    return logicReference;
}

COLLADAReferenceAttributeType *SystemUnitClassType::getGeometryReference()
{

    COLLADAReferenceAttributeType *geometryReference = 0;

    for (Attribute::iterator attribute = Attribute.all(); attribute; ++attribute)
    {
        if (attribute->Name.exists())
        {
                //an attribute is found with name value set to "GeometryReference"
                //this one is returned as geometryReference attribute
            if (string_type(attribute->Name).compare(AttributeType::COLLADA_REFERENCE)==0)
            {
                geometryReference = new COLLADAReferenceAttributeType(attribute->GetNode());
                break;
            }
        }
    }
    geometryReferenceAttribute=geometryReference;

    return geometryReference;
}

FrameAttributeType *SystemUnitClassType::getFrameAttribute()
{
    try
    {
        FrameAttributeType *frameAttributeTemp = 0;

        for (Attribute::iterator attribute = Attribute.all(); attribute; ++attribute)
        {
            if (attribute->Name.exists())
            {
                //an attribute is found with name value set to "Frame"
                if (string_type(attribute->Name).compare(AttributeType::FRAME_NAME)==0)
                {
                    frameAttributeTemp = new FrameAttributeType(attribute->GetNode());
                    break;
                }
            }
        }
        frameAttribute=frameAttributeTemp;

        return frameAttributeTemp;
    }
    catch (Exception *ex)
    {
        throw;
    }
}

    // TODO implement getAttributeField
//AttributeType SystemUnitClassType::getAttributeField()
//{
//    return this->Attribute;
//}

}