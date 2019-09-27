//
// C++ Implementation: RoleRequirementsType
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
#include "LogicReferenceAttributeType.h"

namespace CAEX_ClassModel
{

RoleRequirementsType::RoleRequirementsType(xercesc::DOMNode* const& node)
    : CAEXBasicObject(node)
    , RefBaseRoleClassPath(*this)   // "@RefBaseRoleClassPath"
    , Attribute(*this)  // "Attribute"
    , ExternalInterface(*this)  // "ExternalInterface"
    , geometryReferenceAttribute(this, getGeometryReferenceAttribute, NULL)
    , logicReferenceAttribute(this, getLogicReferenceAttribute, NULL)
    , frameAttribute(this, getFrameAttribute, NULL)
{
}

RoleRequirementsType::RoleRequirementsType(RoleRequirementsType const& other)
    : CAEXBasicObject(other.GetNode())
    , RefBaseRoleClassPath(*this)   // "@RefBaseRoleClassPath"
    , Attribute(*this)  // "Attribute"
    , ExternalInterface(*this)  // "ExternalInterface"
    , geometryReferenceAttribute(this, getGeometryReferenceAttribute, NULL)
    , logicReferenceAttribute(this, getLogicReferenceAttribute, NULL)
    , frameAttribute(this, getFrameAttribute, NULL)
{
}

AttributeType *RoleRequirementsType::New_Attribute(std::string attributeName)
{
    xercesc::DOMNode *newAttributeNode = XercesTreeOperations::CreateElement(GetNode(), Attribute.memberInfo());

    InsertAttributeNodeInternal(newAttributeNode);

    AttributeType *newAttribute = new AttributeType(newAttributeNode);
    newAttribute->Name = attributeName;
    return newAttribute;
}

void RoleRequirementsType::InsertAttributeNodeInternal(xercesc::DOMNode *attributeNode)
{
    xercesc::DOMNode *lastHeaderNode = this->getLastHeaderNode();
    if (lastHeaderNode != 0)
    {
        GetNode()->insertBefore(attributeNode, lastHeaderNode->getNextSibling());
    }
    else
    {
        GetNode()->insertBefore(attributeNode, GetNode());
    }

}

void RoleRequirementsType::Insert_Attribute(AttributeType *attributeElement)
{
    this->InsertAttributeNodeInternal(attributeElement->GetNode());
}

InterfaceClassType *RoleRequirementsType::New_ExternalInterface(std::string name)
{
    InterfaceClassType *newExternalInterface = new InterfaceClassType(ExternalInterface.append());
    newExternalInterface->Name = name;
    return newExternalInterface;
}

void RoleRequirementsType::Insert_ExternalInterface(InterfaceClassType *interfaceElement)
{
    GetNode()->appendChild(interfaceElement->GetNode());
}

// TODO implement getAttributeField()
//CAEX_ClassModel::MemberElement_Attribute *RoleRequirementsType::getAttributeField()
//{
//    return this->Attribute;
//}


LogicReferenceAttributeType *RoleRequirementsType::getLogicReference()
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

COLLADAReferenceAttributeType *RoleRequirementsType::getGeometryReference()
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

FrameAttributeType *RoleRequirementsType::getFrameAttribute()
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

        return frameAttribute;
    }
    catch (Exception *ex)
    {
        throw ex;
    }
}

// begin of static Property accessor functions
COLLADAReferenceAttributeType* RoleRequirementsType::getGeometryReferenceAttribute(void *instance)
{
    RoleRequirementsType *object=static_cast<RoleRequirementsType*>(instance);
    return object->getGeometryReference();
}


LogicReferenceAttributeType *RoleRequirementsType::getLogicReferenceAttribute(void *instance)
{
    RoleRequirementsType *object=static_cast<RoleRequirementsType*>(instance);
    return object->getLogicReference();
}


FrameAttributeType *RoleRequirementsType::getFrameAttribute(void *instance)
{
    RoleRequirementsType *object=static_cast<RoleRequirementsType*>(instance);
    return object->getFrameAttribute();
}
// end of static Property accessor functions


RoleRequirementsType *RoleRequirementsType::MergeContent(RoleRequirementsType *roleRequirementToMergeContentWith)
{

    try
    {
        if (roleRequirementToMergeContentWith != 0)
        {
                ///copying all child elements of the given element by iterating through each child type and
                ///creating a clone of that child element. Then insert cloned element in this class
            for (RoleRequirementsType::Attribute::iterator attributeChild = roleRequirementToMergeContentWith->Attribute.all(); attributeChild; ++attributeChild)
            {
                    //create copy of base attribute and insert it into clonedclass
                xercesc::DOMNode *clone = attributeChild->GetNode()->cloneNode(true);
                this->Insert_Attribute(new AttributeType(clone)); // FIXME possible memory leak
            }
            for (RoleRequirementsType::ExternalInterface::iterator externalInterface = roleRequirementToMergeContentWith->ExternalInterface.all(); externalInterface; ++externalInterface)
            {
                    //create copy  and insert it into clonedclass
                xercesc::DOMNode *clone = externalInterface->GetNode()->cloneNode(true);
                this->Insert_ExternalInterface(new ExternalInterfaceType(clone)); // FIXME possible memory leak

            }

        }
    }
    catch (Exception *ex)
    {
        throw;
    }
    return this;
}

void RoleRequirementsType::ResolveExternalInterfaceReferences()
{
        //list that contains interfaceelements that can be removed after iterating through child elements
    std::vector<InterfaceClassType*> toBeRemovedInterfaceElements = std::vector<InterfaceClassType*>();
    std::vector<InterfaceClassType*> toBeInsertedInterfaceElements = std::vector<InterfaceClassType*>();

    for (ExternalInterface::iterator externalInterface = this->ExternalInterface.all(); externalInterface; ++externalInterface)
    {
        if (externalInterface->RefBaseClassPath.exists())
        {
            xercesc::DOMNode *referencedClassNode = externalInterface->getReferencedClass(externalInterface->RefBaseClassPath);
            if (referencedClassNode != 0)
            {
                InterfaceFamilyType *referencedInterfaceClass = new InterfaceFamilyType(referencedClassNode);

                InterfaceClassType *instanceOfReference = static_cast<InterfaceClassType*>(referencedInterfaceClass->CreateClassInstance());

                instanceOfReference->MergeContent(&externalInterface);

                    //mark the current iterated internalelement node to be removed from this class. if removing now, the iteration behaviour
                    // would be undefined because an element of the iteration collection would be removed.
                toBeRemovedInterfaceElements.push_back(&externalInterface);

                    //add to a list of elements that are inserted after this iteration. inserting here would modify the
                    //iteration
                toBeInsertedInterfaceElements.push_back(instanceOfReference);

                    //assigning "old" name to class instance object. do not use the standardname for instances "new..."
                (string_type)(instanceOfReference->Name) = externalInterface->Name;

            }
        }
    }


        //remove marked internalElements that can be removed (this are internalelements that refernced another class. And an instance of that
        //referenced class were already inserted into this class.
    if (toBeRemovedInterfaceElements.size() > 0)
    {
        for (std::vector<InterfaceClassType*>::const_iterator child = toBeRemovedInterfaceElements.begin(); child != toBeRemovedInterfaceElements.end(); child++)
        {
            GetNode()->removeChild((*child)->GetNode());
        }
    }
    if (toBeInsertedInterfaceElements.size() > 0)
    {
        for (std::vector<InterfaceClassType*>::const_iterator child = toBeInsertedInterfaceElements.begin(); child != toBeInsertedInterfaceElements.end(); child++)
        {
            this->Insert_ExternalInterface(*child);
        }
    }
}

bool RoleRequirementsType::Insert_Element(TypeBase *elementToInsert)
{
    bool successfullyInserted = true;
    if (dynamic_cast<InterfaceClassType*>(elementToInsert) != 0)
    {
        Insert_ExternalInterface(static_cast<InterfaceClassType*>(elementToInsert));
    }
    else if (dynamic_cast<AttributeType*>(elementToInsert) != 0)
    {
        Insert_Attribute(static_cast<AttributeType*>(elementToInsert));
    }
    else
    {
        successfullyInserted = false;
    }
    return successfullyInserted;
}

}
