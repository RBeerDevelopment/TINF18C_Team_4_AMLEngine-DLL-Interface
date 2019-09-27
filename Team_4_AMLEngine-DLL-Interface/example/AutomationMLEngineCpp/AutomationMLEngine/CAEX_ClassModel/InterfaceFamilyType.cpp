//
// C++ Implementation: InterfaceFamilyType
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
#include "ClassInstantiationException.h"
#include "GlobalUID.h"
#include "XercesString.h"

#include <algorithm>

namespace CAEX_ClassModel
{

std::vector<string_type> InterfaceFamilyType::referencedClassesList;

InterfaceFamilyType::InterfaceFamilyType(xercesc::DOMNode* const& node)
    : InterfaceClassType(node)
    , InterfaceClass(*this) // "InterfaceClass"
{
}

InterfaceFamilyType::InterfaceFamilyType(InterfaceFamilyType const& other)
    : InterfaceClassType(other.GetNode())
    , InterfaceClass(*this) // "InterfaceClass"
{
}

InterfaceFamilyType *InterfaceFamilyType::New_InterfaceClass(string_type name)
{
    InterfaceFamilyType *interfaceClass = new InterfaceFamilyType(InterfaceClass.append());
    interfaceClass->Name = name;
    return interfaceClass;
}

void InterfaceFamilyType::Insert_InterfaceClass(InterfaceFamilyType *interfaceClass)
{
    GetNode()->appendChild(interfaceClass->GetNode());
}

void InterfaceFamilyType::MergeClasses(InterfaceFamilyType *clonedClass, InterfaceFamilyType *baseClass)
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
                clonedClass->Insert_Attribute(new AttributeType(clone)); // FIXME possible memory leak
            }
        }
    }
    catch (Exception *ex)
    {
        throw;
    }

}

void InterfaceFamilyType::ResolveClassReferences(InterfaceFamilyType *clonedClass, InterfaceFamilyType *referencedBaseClass)
{
    if (referencedBaseClass != 0)
    {
        //mergeing classes
        MergeClasses(clonedClass, referencedBaseClass);

        //check if referenced class is derived from another class, too
        if (referencedBaseClass->RefBaseClassPath.exists())
        {
            string_type referencedBaseClassPath = referencedBaseClass->RefBaseClassPath;
                //check if refernced class path is already in inheritance chain
            if (std::find(referencedClassesList.begin(), referencedClassesList.end(), referencedBaseClassPath) == referencedClassesList.end())
            {
                    //adding path to list to avoid cyclic inheritance
                referencedClassesList.push_back(referencedBaseClassPath);
                InterfaceFamilyType *referencedInterfaceFamilyType = getClassForPath(referencedBaseClassPath);
                if (referencedInterfaceFamilyType != 0)
                {
                    try
                    {
                        ResolveClassReferences(clonedClass, referencedInterfaceFamilyType);
                    }
                    catch (ClassInstantiationException e)
                    {
                        throw e;
                    }
                }
            }
            else
            {
                    //throw exception
                    //A class should not contain an InternalElement that references this class
                    //throw classinstantiation exception
                // TODO Text fuer die Exception ist moeglicherweise falsch
                ClassInstantiationException classInstantiationException = ClassInstantiationException(string_type("Cannot create an instance of class: ").append(getFullNodePath(GetNode())).append("!\nClass reference: ").append(referencedBaseClassPath).append(" in class: ").append(referencedBaseClass->Name).append(" points back to an already referenced class. This is a cross reference."));

                throw classInstantiationException;
            }
        }
    }

}

ExternalInterfaceType *InterfaceFamilyType::CreateInstance(InterfaceFamilyType *classToInstantiate)
{
        ///first create a clone of this class
    InterfaceFamilyType *clonedInterfaceFamilyClass = new InterfaceFamilyType(classToInstantiate->GetNode()->cloneNode(true));

    referencedClassesList = std::vector<string_type>();
        //check if this class is derived from another class, if so copy all elements of the base class to
        //this clone class
    if (clonedInterfaceFamilyClass->RefBaseClassPath.exists())
    {
        string_type referencedBaseClassPath = clonedInterfaceFamilyClass->RefBaseClassPath;
              //check if this class refereneces itself. do not merge classes then!
        if (classToInstantiate->getFullNodePath(classToInstantiate->GetNode()).compare(referencedBaseClassPath)!=0)
        {
                //adding path to list to avoid cyclic inheritance
            referencedClassesList.push_back(referencedBaseClassPath);

            classToInstantiate->ResolveClassReferences(clonedInterfaceFamilyClass, classToInstantiate->getClassForPath(referencedBaseClassPath));


        }
    }

    //remove all child interfaceclasses. A hierarchical structure of interfaceclasses has no semantic!
    //inheritence is realized via refbaseclasspath attributes!
    clonedInterfaceFamilyClass->InterfaceClass.remove();

    //remove header
    //(static_cast<CAEXBasicObject*>(clonedInterfaceFamilyClass))->RemoveHeader();
    clonedInterfaceFamilyClass->RemoveHeader();

    //remove attributes
    //clonedInterfaceFamilyClass->Node->Attributes->RemoveAll();
    xercesc::DOMNamedNodeMap *nodes=clonedInterfaceFamilyClass->GetNode()->getAttributes();
    for (int i=nodes->getLength()-1; i>=0; i--)
    {
        nodes->removeNamedItem(nodes->item(i)->getNodeName());
    }

    //rename the xmlnode tag name from InterfaceClass to ExternalInterface
    xercesc::DOMNode *clonedXmlNode = clonedInterfaceFamilyClass->GetNode();
    xercesc::DOMElement *renamedXmlNode = clonedXmlNode->getOwnerDocument()->createElement(XercesStringTemp((members + _altova_mi_altova_InternalElementType_altova_ExternalInterface)->LocalName));
    //copy all child nodes from clonednode to renamed node (interfaceclass childs are already deleteted)
    xercesc::DOMNodeList *childNode = clonedXmlNode->getChildNodes();
    for (int i = 0; i<childNode->getLength(); i++)
    {
        renamedXmlNode->appendChild(childNode->item(i)->cloneNode(true));
    }

//create new internal element with renamed xml node
    ExternalInterfaceType *newExternalInterface = new ExternalInterfaceType(renamedXmlNode);
        //set name of instance element
    if (this->Name.exists())
    {
        newExternalInterface->Name = string_type("new").append(classToInstantiate->Name);
    }
        //if no name attribute exists (which is not valid for a systemunitclass according to CAEX schema) take xml tag name instead
    else
    {
        newExternalInterface->Name = string_type("new").append(XercesUnstringTemp(classToInstantiate->GetNode()->getNodeName()));
    }
        //set referenced class path
    newExternalInterface->RefBaseClassPath = classToInstantiate->getFullNodePath(classToInstantiate->GetNode());

        //create a new guid for the instance
    string_type instanceGuid = GlobalUID::newGuid()->toString(CAEXObject::GUID_FORMAT);
        //assign guid to instance
    newExternalInterface->ID = instanceGuid;

    return newExternalInterface;
}

TypeBase *InterfaceFamilyType::CreateClassInstance()
{
    ExternalInterfaceType *newExternalInterface = CreateInstance(this);

    return newExternalInterface;

}

InterfaceFamilyType *InterfaceFamilyType::getClassForPath(string_type referencedClassPath)
{
    try
    {
        xercesc::DOMNode *referencedClass = this->getReferencedClass(referencedClassPath);

        if (referencedClass != 0)
        {
            InterfaceFamilyType *referencedInterfaceFamilyClass = new InterfaceFamilyType(referencedClass);
            return referencedInterfaceFamilyClass;
        }
        else
        {
                //no such class found
            return 0;
        }
    }
    catch (Exception *ex)
    {
            //throwing back to caller
        throw;
    }
}

bool InterfaceFamilyType::Insert_Element(TypeBase *elementToInsert)
{
    bool successfullyInserted = true;

    if (dynamic_cast<AttributeType*>(elementToInsert) != 0)
    {
        Insert_Attribute(static_cast<AttributeType*>(elementToInsert));
    }
    else if (dynamic_cast<InterfaceFamilyType*>(elementToInsert) != 0)
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
