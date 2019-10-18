//
// C++ Implementation: SystemUnitFamilyType
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
#include "ClassInstantiationException.h"

#include <algorithm>

namespace CAEX_ClassModel
{

SystemUnitFamilyType::SystemUnitFamilyType(xercesc::DOMNode* const& node)
    : SystemUnitClassType(node)
    , RefBaseClassPath(*this)   // "@RefBaseClassPath"
    , SystemUnitClass(*this)    // "SystemUnitClass"
{
}

SystemUnitFamilyType::SystemUnitFamilyType(SystemUnitFamilyType const& other)
    : SystemUnitClassType(other.GetNode())
    , RefBaseClassPath(*this)   // "@RefBaseClassPath"
    , SystemUnitClass(*this)    // "SystemUnitClass"
{
}

SystemUnitFamilyType *SystemUnitFamilyType::New_SystemUnitClass(string_type name)
{
    SystemUnitFamilyType *systemUnitClass = new SystemUnitFamilyType(SystemUnitClass.append());
    systemUnitClass->Name = name;
    return systemUnitClass;
}

void SystemUnitFamilyType::Insert_SystemUnitFamilyType(SystemUnitFamilyType *systemUnitFamilyType)
{
    GetNode()->appendChild(systemUnitFamilyType->GetNode());
}

void SystemUnitFamilyType::MergeClasses(SystemUnitFamilyType *clonedClass, SystemUnitFamilyType *baseClass)
{
    try
    {

            //if the reference to the base class could be solved, baseClass is != null
        if (baseClass != 0)
        {
                ///copying all child elements of the base class by iterating through each child type and
                ///creating a clone of that child element. Then insert cloned element in cloned class
            for (Attribute::iterator attributeChild = baseClass->Attribute.all(); attributeChild; ++attributeChild)
            {
                    //create copy of base attribute and insert it into clonedclass
                xercesc::DOMNode *clone = attributeChild->GetNode()->cloneNode(true);
                clonedClass->Insert_Attribute(new AttributeType(clone));
            }
            for (ExternalInterface::iterator externalInterface = baseClass->ExternalInterface.all(); externalInterface; ++externalInterface)
            {
                xercesc::DOMNode *clone = externalInterface->GetNode()->cloneNode(true);
                    //externalInterfaceType is derived from InterfaceType and contains the same information as the base class.
                clonedClass->Insert_ExternalInterface(new ExternalInterfaceType(clone));
            }
            for (InternalElement::iterator internalElement = baseClass->InternalElement.all(); internalElement; ++internalElement)
            {
                xercesc::DOMNode *clone = internalElement->GetNode()->cloneNode(true);
                clonedClass->Insert_InternalElement(new InternalElementType(clone));
            }
            for (SupportedRoleClass::iterator supportedRoleClass = baseClass->SupportedRoleClass.all(); supportedRoleClass; ++supportedRoleClass)
            {
                xercesc::DOMNode *clone = supportedRoleClass->GetNode()->cloneNode(true);
                clonedClass->Insert_SupportedRoleClass(new SupportedRoleClassType(clone));

            }
            for (InternalLink::iterator internalLink = baseClass->InternalLink.all(); internalLink; ++internalLink)
            {
                xercesc::DOMNode *clone = internalLink->GetNode()->cloneNode(true);
                clonedClass->Insert_InternalLink(new InternalLinkType(clone));
            }
        }
    }
    catch (Exception *ex)
    {
        throw;
    }
}

void SystemUnitFamilyType::ResolveClassReferences(SystemUnitFamilyType *clonedClass, SystemUnitFamilyType *referencedBaseClass, std::vector<string_type> &referencedClassesList)
{
    if (referencedBaseClass != 0)
    {
            //mergin classes
        MergeClasses(clonedClass, referencedBaseClass);

            //check if referenced class is derived from another class, too
        if (referencedBaseClass->RefBaseClassPath.exists())
        {
            string_type referencedBaseClassPath = referencedBaseClass->RefBaseClassPath;
                //check if refernced class path is already in inheritance chain
            if (std::find(referencedClassesList.begin(), referencedClassesList.end(), referencedBaseClassPath) == referencedClassesList.end())
            {
                    //if refernce is empty do nothing
         //                   if (!referencedBaseClassPath.Equals(""))
        //                    {
                        //adding path to list to avoid cyclic inheritance
                referencedClassesList.push_back(referencedBaseClassPath);
                SystemUnitFamilyType *referencedSystemUnitFamilyType = getClassForPath(referencedBaseClassPath);
                if (referencedSystemUnitFamilyType != 0)
                {
                    ResolveClassReferences(clonedClass, referencedSystemUnitFamilyType, referencedClassesList);
                }
       //                     }
            }
            else
            {
                    //throw exception
                    //A class should not contain an InternalElement that references this class
                    //throw classinstantiation exception
                ClassInstantiationException classInstantiationException = ClassInstantiationException(string_type("Cannot create an instance of class: ").append(getFullNodePath(this->GetNode())).append("!\nClass reference: ").append(referencedBaseClassPath).append(" in class: ").append(referencedBaseClass->Name).append(" points back to an already referenced class. This is a cross reference."));

                throw classInstantiationException;
            }
        }
    }

}

InternalElementType *SystemUnitFamilyType::CreateInstance(SystemUnitFamilyType *classToInstantiate, std::vector<string_type> &referencedClassesList)
{
    try
    {
            ///first create a clone of this class
        SystemUnitFamilyType *clonedSystemUnitClass = new SystemUnitFamilyType(classToInstantiate->GetNode()->cloneNode(true));

            //check if this class is derived from another class, if so copy all elements of the base class to
            //this clone class
        if (clonedSystemUnitClass->RefBaseClassPath.exists())
        {
            string_type referencedBaseClassPath = clonedSystemUnitClass->RefBaseClassPath;
            string_type classToInstantiatePath = classToInstantiate->getFullNodePath(classToInstantiate->GetNode());
                //check if this class refereneces itself. do not merge classes then!
            if (classToInstantiatePath.compare(referencedBaseClassPath)!=0)
            {
                     //if refernce is empty do nothing
         //                   if (!referencedBaseClassPath.Equals(""))
         //                   {
                        //adding path to list to avoid cyclic inheritance
                        //   referencedClassesList.Add(referencedBaseClassPath);
                referencedClassesList.push_back(classToInstantiatePath);

                classToInstantiate->ResolveClassReferences(clonedSystemUnitClass, classToInstantiate->getClassForPath(referencedBaseClassPath), referencedClassesList);
        //                    }
            }
        }

            //remove all child systemunitclasses. A hierarchical structure of systemunitclasses has no semantic!
            //inheritence is realized via refbaseclasspath attributes!
        clonedSystemUnitClass->SystemUnitClass.remove();
            //remove header
        //(static_cast<CAEXBasicObject*>(clonedSystemUnitClass))->RemoveHeader();
        clonedSystemUnitClass->RemoveHeader();

        //remove xml attributes (not CAEX attributes!)
        //clonedSystemUnitClass->GetNode()->Attributes->RemoveAll();
        xercesc::DOMNamedNodeMap *nodes=clonedSystemUnitClass->GetNode()->getAttributes();
        for (int i=nodes->getLength(); i>0; i--)
        {
            nodes->removeNamedItem(nodes->item(i-1)->getNodeName());
        }

        //rename the xmlnode tag name from systemunitclass to internalelement
        xercesc::DOMNode *clonedXmlNode = clonedSystemUnitClass->GetNode();
        xercesc::DOMElement *renamedXmlNode = clonedXmlNode->getOwnerDocument()->createElement(XercesStringTemp((members + _altova_mi_altova_SystemUnitClassType_altova_InternalElement)->LocalName));
            //copy all child nodes from clonednode to renamed node (systemunitclass childs are already deleteted)
        xercesc::DOMNodeList *childNode = clonedXmlNode->getChildNodes();
        for (int i = 0; i<childNode->getLength(); i++)
        {
            renamedXmlNode->appendChild(childNode->item(i)->cloneNode(true));
        }
            //create new internal element with renamed xml node
        InternalElementType *newInternalElement = new InternalElementType(renamedXmlNode);
            //set name of instance element
        if (classToInstantiate->Name.exists())
        {
            newInternalElement->Name = string_type("new").append(classToInstantiate->Name);
        }
            //if no name attribute exists (which is not valid for a systemunitclass according to CAEX schema) take xml tag name instead
        else
        {
            newInternalElement->Name = string_type("new").append(string_type(XercesUnstringTemp(classToInstantiate->GetNode()->getNodeName())));
        }
            //set referenced class path
        newInternalElement->RefBaseSystemUnitPath = classToInstantiate->getFullNodePath(classToInstantiate->GetNode());

            //creating new GUIDs for all internal elements of this class instance
        newInternalElement->AssignNewGUIDs();

        return newInternalElement;
    }
    catch (Exception *ex)
    {
        throw;
    }
}

TypeBase *SystemUnitFamilyType::CreateClassInstance()
{
        //list that holds pathes to referenced base classes. The list ist used to avoid
        //cyclic class inheritance, e.g. class B is derived from class A, A is derived from class C and
        //class C is derived from B.
    std::vector<string_type> referencedClassesList = std::vector<string_type>();
    InternalElementType *newInternalElement = CreateInstance(this, referencedClassesList);

        /// same as above list, for internal sub-elements of a class. InternalElements can also refernce classes. To avoid
        /// cyclic refernces, hold already referenced classes of an sub-InternalElement in this list
    std::vector<string_type> referencedInternalClassesList = std::vector<string_type>();
        //initially put this systemunit class into the list, in case of a child InternalElement references back to this class
    referencedInternalClassesList.push_back(this->getFullNodePath(this->GetNode()));
    newInternalElement->ResolveInternalElementReferences(referencedInternalClassesList);

    return newInternalElement;
}

TypeBase *SystemUnitFamilyType::InternalCreateClassInstance(std::vector<string_type> &referencedInternalClassesList)
{
        //list that holds pathes to referenced base classes. The list ist used to avoid
        //cyclic class inheritance, e.g. class B is derived from class A, A is derived from class C and
        //class C is derived from B.
    std::vector<string_type> referencedClassesList = std::vector<string_type>();
    InternalElementType *newInternalElement = CreateInstance(this, referencedClassesList);

         //initially put this systemunit class into the list, in case of a child InternalElement references back to this class
    referencedInternalClassesList.push_back(this->getFullNodePath(this->GetNode()));
    newInternalElement->ResolveInternalElementReferences(referencedInternalClassesList);

    return newInternalElement;
}

SystemUnitFamilyType *SystemUnitFamilyType::getClassForPath(string_type referencedClassPath)
{

    xercesc::DOMNode *referencedClass = this->getReferencedClass(referencedClassPath);

    if (referencedClass != 0)
    {
        SystemUnitFamilyType *referencedSystemUnitFamilyClass = new SystemUnitFamilyType(referencedClass);
        return referencedSystemUnitFamilyClass;
    }
    else
    {
            //no such class found
        return 0;
    }

}

bool SystemUnitFamilyType::Insert_Element(TypeBase *elementToInsert)
{
    bool successfullyInserted = true;

    if (dynamic_cast<InternalElementType*>(elementToInsert) != 0)
    {
        Insert_InternalElement(static_cast<InternalElementType*>(elementToInsert));
    }
    else if (dynamic_cast<SystemUnitFamilyType*>(elementToInsert) != 0)
    {
        Insert_SystemUnitFamilyType(static_cast<SystemUnitFamilyType*>(elementToInsert));
    }
    else if (dynamic_cast<InterfaceFamilyType*>(elementToInsert) != 0)
    {
            //do nothing. it is not allowed to add inface family types
        successfullyInserted = false;
    }
    else if (dynamic_cast<InterfaceClassType*>(elementToInsert) != 0)
    {
        Insert_ExternalInterface(static_cast<InterfaceClassType*>(elementToInsert));
    }
    else if (dynamic_cast<AttributeType*>(elementToInsert) != 0)
    {
        Insert_Attribute(static_cast<AttributeType*>(elementToInsert));
    }
    else if (dynamic_cast<InternalLinkType*>(elementToInsert) != 0)
    {
        Insert_InternalLink(static_cast<InternalLinkType*>(elementToInsert));
    }
    else if (dynamic_cast<SupportedRoleClassType*>(elementToInsert) != 0)
    {
        Insert_SupportedRoleClass(static_cast<SupportedRoleClassType*>(elementToInsert));
    }
    else
    {
        successfullyInserted = false;
    }
    return successfullyInserted;

}

}
