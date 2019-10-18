//
// C++ Implementation: InternalElementType
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
#include "SchemaConformanceException.h"
#include "GlobalUID.h"
#include "XMLTools.h"
#include "XercesString.h"
#include "ClassInstantiationException.h"

#include <algorithm>

namespace CAEX_ClassModel
{


InternalElementType::InternalElementType(xercesc::DOMNode* const& node)
    : SystemUnitClassType(node)
    , RefBaseSystemUnitPath(*this)  // "@RefBaseSystemUnitPath"
    , RoleRequirements(*this)   // "RoleRequirements"
    , MappingObject(*this)  // "MappingObject"
{
}

InternalElementType::InternalElementType(InternalElementType const& other)
    : SystemUnitClassType(other.GetNode())
    , RefBaseSystemUnitPath(*this)  // "@RefBaseSystemUnitPath"
    , RoleRequirements(*this)   // "RoleRequirements"
    , MappingObject(*this)  // "MappingObject"
{
}

RoleRequirementsType *InternalElementType::New_RoleRequirements()
{

    if (this->RoleRequirements.exists())
    {
        throw SchemaConformanceException("A RoleRequirements node is already existent. It is not allowed to add more than one RoleRequirements node to current element according to CAEX Schema");
    }
    else
    {
        xercesc::DOMNode *newRoleRequirementNode = XercesTreeOperations::CreateElement(GetNode(), (const altova::MemberInfo*)(RoleRequirements.memberInfo()));

        InsertRoleRequirementsNodeInternal(newRoleRequirementNode);

        return new RoleRequirementsType(newRoleRequirementNode);
    }
}

void InternalElementType::InsertRoleRequirementsNodeInternal(xercesc::DOMNode *roleRequirementsElementNode)
{
    if (this->MappingObject.exists())
    {
        GetNode()->insertBefore(roleRequirementsElementNode, this->MappingObject.first().GetNode());
    }
    else
    {
        GetNode()->appendChild(roleRequirementsElementNode);
    }
}

void InternalElementType::Insert_RoleRequirements(RoleRequirementsType *roleRequirement)
{
        //throw an exception when a rolerequirement is already existent
    if (this->RoleRequirements.exists())
    {
        throw SchemaConformanceException("A RoleRequirements node is already existent. It is not allowed to add more than one RoleRequirements node to current element according to CAEX Schema");
    }
    else
    {
        InsertRoleRequirementsNodeInternal(roleRequirement->GetNode());
    }
}

MappingType *InternalElementType::New_MappingObject()
{

    if (this->MappingObject.exists())
    {
        throw SchemaConformanceException("A MappingObject node is already existent. It is not allowed to add more than one MappingObject node to current element according to CAEX Schema");
    }
    else
    {
        return new MappingType(MappingObject.append());
    }
}

void InternalElementType::Insert_MappingObject(MappingType mappingObject)
{
    if (MappingObject.exists())
    {
        throw SchemaConformanceException("A MappingObject node is already existent. It is not allowed to add more than one MappingObject node to current element according to CAEX Schema");
    }
    else
    {
        GetNode()->appendChild(mappingObject.GetNode());
    }
}

bool InternalElementType::Insert_NewInstance(TypeBase *newInstanceObject)
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
    else if (dynamic_cast<RoleRequirementsType*>(newInstanceObject) != 0)
    {
        this->Insert_RoleRequirements(static_cast<RoleRequirementsType*>(newInstanceObject));
        insertionOk = true;
    }

    return insertionOk;
}

InternalElementType *InternalElementType::Create_UniqueCopy()
{
    xercesc::DOMNode *cloneCopy = GetNode()->cloneNode(true);
    InternalElementType *newInternalElement = new InternalElementType(cloneCopy);

    AssignNewGUID(newInternalElement);

    return newInternalElement;
}

void InternalElementType::AssignNewGUID(InternalElementType *internalElement)
{
        //assigning a GUID to the new InternalElement
        //create a new guid for the instance
    string_type instanceGuid = GlobalUID::newGuid()->toString(CAEXObject::GUID_FORMAT);
        //assign guid to instance
    internalElement->ID = instanceGuid;

        //assigning a new guid to each sub InternalElement also
    for (InternalElement::iterator childInternalElement = internalElement->InternalElement.all(); childInternalElement == true; ++childInternalElement)
    {
        AssignNewGUID(&childInternalElement);
    }
}

void InternalElementType::AssignNewGUIDs()
{
    AssignNewGUID(this);
}

InternalElementType *InternalElementType::MergeContent(InternalElementType *contentToMergeWith, bool mergeRole)
{
    try
    {
        if (contentToMergeWith != 0)
        {
                ///copying all child elements of the given element by iterating through each child type and
                ///creating a clone of that child element. Then insert cloned element in this class
            for (Attribute::iterator attributeChild = contentToMergeWith->Attribute.all(); attributeChild == true; ++attributeChild)
            {
                    //create copy of base attribute and insert it into clonedclass
                xercesc::DOMNode *clone = attributeChild->GetNode()->cloneNode(true);
                AttributeType element(clone);
                this->Insert_Attribute(&element);
            }
            for (ExternalInterface::iterator externalInterface = contentToMergeWith->ExternalInterface.all(); externalInterface == true; ++externalInterface)
            {
                xercesc::DOMNode *clone = externalInterface->GetNode()->cloneNode(true);
                this->Insert_ExternalInterface(new InterfaceClassType(clone)); // FIXME this might be a memory leak
            }
            for (InternalElement::iterator internalElement = contentToMergeWith->InternalElement.all(); internalElement == true; ++internalElement)
            {
                xercesc::DOMNode *clone = internalElement->GetNode()->cloneNode(true);
                this->Insert_InternalElement(new InternalElementType(clone)); // FIXME this might be a memory leak
            }
            for (SupportedRoleClass::iterator supportedRoleClass = contentToMergeWith->SupportedRoleClass.all(); supportedRoleClass == true; ++supportedRoleClass)
            {
                xercesc::DOMNode *clone = supportedRoleClass->GetNode()->cloneNode(true);
                this->Insert_SupportedRoleClass(new SupportedRoleClassType(clone)); // FIXME this might be a memory leak

            }
            for (InternalLink::iterator internalLink = contentToMergeWith->InternalLink.all(); internalLink == true; ++internalLink)
            {
                xercesc::DOMNode *clone = internalLink->GetNode()->cloneNode(true);
                this->Insert_InternalLink(new InternalLinkType(clone)); // FIXME this might be a memory leak
            }
                //Rolerequirements and mappingobject can only occur once.
                //if true, copy rolerequirements and mapping object
            if (mergeRole)
            {
                if (this->RoleRequirements.exists())
                {
                    this->RoleRequirements.remove();
                }
                    //if rolerequirements element is contained in given class copy it,
                    //else just remove
                if (contentToMergeWith->RoleRequirements.exists())
                {
                    this->Insert_RoleRequirements(new RoleRequirementsType(contentToMergeWith->RoleRequirements.first().GetNode()->cloneNode(true))); // FIXME this might be a memory leak
                }


                if (this->MappingObject.exists())
                {
                    this->MappingObject.remove();
                }
                    //if rolerequirements element is contained in given class copy it,
                    //else just remove
                if (contentToMergeWith->MappingObject.exists())
                {
                    this->Insert_MappingObject(MappingType(contentToMergeWith->MappingObject.first().GetNode()->cloneNode(true)));
                }

            }
        }
    }
    catch (Exception *ex)
    {
        throw;
    }
    return this;
}

void InternalElementType::ResolveRoleReferences()
{
        //list that contains interfaceelements that can be removed after iterating through child elements
    std::vector<RoleRequirementsType*> toBeRemovedRoleRequirementElements = std::vector<RoleRequirementsType*>();
    std::vector<RoleRequirementsType*> toBeInsertedRoleElements = std::vector<RoleRequirementsType*>();

        //check if a role reference exists
    if (this->RoleRequirements.exists())
    {

        RoleRequirementsType *roleRequirement = new RoleRequirementsType(this->RoleRequirements.first());
            //check if the rolerequirements element has a role class reference.
        if (roleRequirement->RefBaseRoleClassPath.exists())
        {

            xercesc::DOMNode *referencedRoleClassNode = this->getReferencedClass(roleRequirement->RefBaseRoleClassPath);
            if (referencedRoleClassNode != 0)
            {
                    //resolve references to externalinterface classes before creating an instance of roleclass and mergin content
                    //because externalinterface references of the instance are already resolved when creating that instance
                    //and it would be resolved twice, when calling this method after merging
                roleRequirement->ResolveExternalInterfaceReferences();

                RoleFamilyType *referencedRoleClass = new RoleFamilyType(referencedRoleClassNode);

                RoleRequirementsType *instanceOfReference = static_cast<RoleRequirementsType*>(referencedRoleClass->CreateClassInstance());

                instanceOfReference->MergeContent(roleRequirement);

                    //mark the current iterated internalelement node to be removed from this class. if removing now, the iteration behaviour
                    // would be undefined because an element of the iteration collection would be removed.
                toBeRemovedRoleRequirementElements.push_back(roleRequirement);

                    //add to a list of elements that are inserted after this iteration. inserting here would modify the
                    //iteration
                toBeInsertedRoleElements.push_back(instanceOfReference);

            }
        }
    }


        //remove marked internalElements that can be removed (this are internalelements that refernced another class. And an instance of that
        //referenced class were already inserted into this class.
    if (toBeRemovedRoleRequirementElements.size() > 0)
    {
        for (std::vector<RoleRequirementsType*>::const_iterator child = toBeRemovedRoleRequirementElements.begin(); child != toBeRemovedRoleRequirementElements.end(); child++)
        {
            this->GetNode()->removeChild((*child)->GetNode());
        }
    }
    if (toBeInsertedRoleElements.size() > 0)
    {
        for (std::vector<RoleRequirementsType*>::const_iterator child = toBeInsertedRoleElements.begin(); child != toBeInsertedRoleElements.end(); child++)
        {
            this->Insert_RoleRequirements(*child);
        }
    }
    // TODO falls der Destuktor der vectors toBeInserted... und toBeRemoved.. die Speicherbereiche auf die die enthaltenen Pointer verweisen selber frei raeumt ist die Gefahr eines Memory-Leaks gering! Ansonsten muss noch aufgeraeumt werden!
}

void InternalElementType::ResolveExternalInterfaceReferences()
{
        //list that contains interfaceelements that can be removed after iterating through child elements
    std::vector<InterfaceClassType*> toBeRemovedInterfaceElements = std::vector<InterfaceClassType*>();
    std::vector<InterfaceClassType*> toBeInsertedInterfaceElements = std::vector<InterfaceClassType*>();

    for (ExternalInterface::iterator externalInterface = this->ExternalInterface.all(); externalInterface == true; ++externalInterface)
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
    // TODO falls der Destuktor der vectors toBeInserted... und toBeRemoved.. die Speicherbereiche auf die die enthaltenen Pointer verweisen selber frei raeumt ist die Gefahr eines Memory-Leaks gering! Ansonsten muss noch aufgeraeumt werden!
}

void InternalElementType::ResolveInternalElementReferences(std::vector<string_type> &referencedClassesList)
{

        //list that contains internalelements that can be removed after iterating through child elements
    std::vector<InternalElementType*> toBeRemovedInternalElements = std::vector<InternalElementType*>();

        // list with internalElements that should be inserted into this InternalElement (that are instances of referenced classes)
    std::vector<InternalElementType*> toBeInsertedInternalElements = std::vector<InternalElementType*>();

        //resolving possible references to interface classes
    this->ResolveExternalInterfaceReferences();
        //resolve possible references to role classes
    this->ResolveRoleReferences();

        //resolving all class references of sub-InternalElements of this created class instance. If a child
        //internalElement of this instance references a class, then replace the child InternalElement with a new
        //intance of the refernced class
    for (InternalElement::iterator internalElementChild = this->InternalElement.all(); internalElementChild == true; ++internalElementChild)
    {
            //check if child element has a reference to a base class
        if (internalElementChild->RefBaseSystemUnitPath.exists())
        {
                //getting referenced class of the internal element child
            xercesc::DOMNode *referencedClassNode = this->getReferencedClass(internalElementChild->RefBaseSystemUnitPath);
            if (referencedClassNode != 0)
            {

                SystemUnitFamilyType *referencedClass = new SystemUnitFamilyType(referencedClassNode);

                    //check if the referenced class is the same class as this class. that means that a class contains an
                    //InternalElement that references this class. You will get in an infinite recurisive createClassInstance call
                    //if not checking this!
                string_type newClassReference = referencedClass->getFullNodePath(referencedClass->GetNode());

                    //test if referenced class is already in referenced classes list. If so, a cyclus is found
                if (std::find(referencedClassesList.begin(), referencedClassesList.end(), newClassReference) == referencedClassesList.end())
                {

                        //resolving possible references to interface classes
                    internalElementChild->ResolveExternalInterfaceReferences();
                        //resolve possible references to role classes
                    internalElementChild->ResolveRoleReferences();

                        ///Creating a new list and copy all elements from current referenced classes list to it.
                        ///This is done, because the current InternalElement references another class. That class may
                        ///also contain sub-InternalElements that reference other classes. For every "jump" to the next
                        ///referenced class, a new list is created and all classes that are used so far are copied to it
                    std::vector<string_type> newInternalClassReferencesList = std::vector<string_type>(referencedClassesList);
                        //add to reference list
                    newInternalClassReferencesList.push_back(newClassReference);

                        ///creating an instance of the referced class and uses the list with already referenced classes to avoid cyclic references
                    InternalElementType *newClassInstance = static_cast<InternalElementType*>(referencedClass->InternalCreateClassInstance(newInternalClassReferencesList));

                        //merge content of current InternalElement with class instance content.
                    newClassInstance->MergeContent(&internalElementChild, true);

                        //marke the current iterated internalelement node to be removed from this class. if removing now, the iteration behaviour
                        // would be undefined because an element of the iteration collection would be removed.
                    toBeRemovedInternalElements.push_back(&internalElementChild);

                        //inserte elements after iteration
                    toBeInsertedInternalElements.push_back(newClassInstance);
                        //                      this.Insert_InternalElement(newClassInstance);

                        //assigning "old" name to class instance object. do not use the standardname for instances "new..."
                    (string_type)(newClassInstance->Name) = internalElementChild->Name;

                }
                else
                {
                        //A class should not contain an InternalElement that references this class
                        //throw classinstantiation exception
                    //ClassInstantiationException *classInstantiationException = ClassInstantiationException
                    // TODO Text der Exception ist moeglicherweise nicht korrekt
                    string_type classInstantiationException(string_type("Cannot create an instance of class: ") + this->getFullNodePath(this->GetNode()) + string_type("!\n") + string_type("Class reference: ") + newClassReference + string_type(" in InternalElement: ") + string_type(internalElementChild->Name) + string_type(" is a cyclic reference."));

                    throw classInstantiationException;
                }
            }
                //recursive call, if the current sub-internalelement has a non valid reference to a base class and may
                //contain sub-internalelement nodes, that may contain class references
            else
            {
                    //maybe save this non valid references

                internalElementChild->ResolveInternalElementReferences(referencedClassesList);
            }
        }
            //recursive call, if the current sub-internalelement has not reference to a base class for itself, but may
            //contain sub-internalelement nodes, that may contain class references
        else
        {
            internalElementChild->ResolveInternalElementReferences(referencedClassesList);
        }

    }
        //remove marked internalElements that can be removed (this are internalelements that refernced another class. And an instance of that
        //referenced class were already inserted into this class.
    if (toBeRemovedInternalElements.size() > 0)
    {
        for (std::vector<InternalElementType*>::const_iterator child = toBeRemovedInternalElements.begin(); child != toBeRemovedInternalElements.end(); child++)
        {
            GetNode()->removeChild((*child)->GetNode());
        }
    }
    if (toBeInsertedInternalElements.size() > 0)
    {
        for (std::vector<InternalElementType*>::const_iterator child = toBeInsertedInternalElements.begin(); child != toBeInsertedInternalElements.end(); child++)
        {
            this->Insert_InternalElement(*child);

        }
    }
}

bool InternalElementType::IsPartOfCombinedKinematik()
{
    return stepUpDomTree(GetNode()->getParentNode());
}

bool InternalElementType::stepUpDomTree(xercesc::DOMNode *xmlNode)
{
    if (dynamic_cast<xercesc::DOMElement*>(xmlNode) != 0)
    {
        if (string_type(XercesUnstringTemp(xmlNode->getNodeName())).compare(((const altova::MemberInfo*)InternalElement.memberInfo())->LocalName)==0)
        {
                //check for rolereuqirements node
            string_type xPathSearchString("./");
            xPathSearchString.append(RoleRequirements.memberInfo()->LocalName);
 //"[@"+CAEX_CLASSModel_TagNames::ATTRIBUTE_NAME_REFBASEROLECLASSPATH+ "='" + CAEX_CLASSModel_TagNames::ROLE_COMBINEDKINEMATIC + "']";

            xercesc::DOMNode *node = selectNode(xmlNode,xPathSearchString,"/",(members + _altova_mi_altova_RoleRequirementsType_altova_RefBaseRoleClassPath)->LocalName,"AutomationMLRoleClassLib/AutomationMLBaseRole/CombinedKinematic"); // TODO korrekten such string und Pfad erstellen

            if (node != 0)
            {
                return true;
            }
        }
    }
    if (xmlNode->getParentNode() != 0)
    {
        return stepUpDomTree(xmlNode->getParentNode());
    }
    else
    {
        return false;
    }


}

std::vector<LinkedObjects*> *InternalElementType::getLinkedObjects()
{
    std::vector<LinkedObjects*> *linkedObjectsList = new std::vector<LinkedObjects*>();
    if (this->InternalLink.exists())
    {
        for (InternalLink::iterator link = this->InternalLink.all(); link == true; ++link)
        {

            LinkedObjects *linkedObjects = link->linkedObjects;

                    //do not add an empty linkedobject
            if (linkedObjects!= 0)
            {
                linkedObjectsList->push_back(linkedObjects);
            }
        }
    }
    return linkedObjectsList;
}

ExternalInterfaceType *InternalElementType::findExternalInterface(string_type interfaceName)
{

    string_type xPathSearchString("./");
    xPathSearchString.append(((const altova::MemberInfo*)ExternalInterface.memberInfo())->LocalName);
    xPathSearchString.append("/").append(interfaceName);
    //+CAEX_CLASSModel_TagNames::EXTERNALINTERFACE_STRING+"[@Name='" + interfaceName + "']";

    xercesc::DOMNode *referencedInterface = selectNode(GetNode(),xPathSearchString,"/"); // TODO korrekten such string und Pfad erstellen

    if (referencedInterface != 0)
    {
        return new ExternalInterfaceType(referencedInterface);
    }
    else
    {
        return 0;
    }
}

bool InternalElementType::Insert_Element(TypeBase *elementToInsert)
{
    bool successfullyInserted = true;

    if (dynamic_cast<InternalElementType*>(elementToInsert) != 0)
    {
        Insert_InternalElement(static_cast<InternalElementType*>(elementToInsert));
    }
    else if (dynamic_cast<ExternalInterfaceType*>(elementToInsert) != 0)
    {
        Insert_ExternalInterface(static_cast<ExternalInterfaceType*>(elementToInsert));
    }
    else if (dynamic_cast<InterfaceFamilyType*>(elementToInsert) != 0)
    {
            //it is not allowed to add inface family types
        successfullyInserted = false;
    }
    else if (dynamic_cast<InterfaceClassType*>(elementToInsert) != 0)
    {
        Insert_ExternalInterface(static_cast<InterfaceClassType*>(elementToInsert));
    }
    else if (dynamic_cast<SupportedRoleClassType*>(elementToInsert) != 0)
    {
        Insert_SupportedRoleClass(static_cast<SupportedRoleClassType*>(elementToInsert));
    }
    else if (dynamic_cast<RoleRequirementsType*>(elementToInsert) != 0)
    {
        Insert_RoleRequirements(static_cast<RoleRequirementsType*>(elementToInsert));
    }
    else if (dynamic_cast<MappingType*>(elementToInsert) != 0)
    {
        Insert_MappingObject(*(static_cast<MappingType*>(elementToInsert)));
    }
    else if (dynamic_cast<InternalLinkType*>(elementToInsert) != 0)
    {
        Insert_InternalLink(static_cast<InternalLinkType*>(elementToInsert));
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
