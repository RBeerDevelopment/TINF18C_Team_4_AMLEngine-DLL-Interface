//
// C++ Implementation: RoleFamilyType
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
#include "XercesString.h"

#include <algorithm>

namespace CAEX_ClassModel
{

    RoleFamilyType::RoleFamilyType(xercesc::DOMNode* const& node)
            : RoleClassType(node)
            , RoleClass(*this)  // "RoleClass"
    {
    }

    RoleFamilyType::RoleFamilyType(RoleFamilyType const& other)
            : RoleClassType(other.GetNode())
            , RoleClass(*this)  // "RoleClass"
    {
    }

    RoleFamilyType *RoleFamilyType::New_RoleClass(string_type name)
    {
        RoleFamilyType *roleClass = new RoleFamilyType(RoleClass.append());
        roleClass->Name = name;
        return roleClass;
    }

    void RoleFamilyType::Insert_RoleClass(RoleClassType *roleClass)
    {
        GetNode()->appendChild(roleClass->GetNode());
    }

    void RoleFamilyType::Insert_RoleFamilyClass(RoleFamilyType *roleClass)
    {
        GetNode()->appendChild(roleClass->GetNode());
    }

    void RoleFamilyType::MergeClasses(RoleFamilyType *roleClass, RoleFamilyType *baseClass)
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
                    roleClass->Insert_Attribute(new AttributeType(clone));
                }
                for (ExternalInterface::iterator externalInterface = baseClass->ExternalInterface.all(); externalInterface; ++externalInterface)
                {
                    //create copy of base attribute and insert it into clonedclass
                    xercesc::DOMNode *clone = externalInterface->GetNode()->cloneNode(true);
                    roleClass->Insert_ExternalInterface(new ExternalInterfaceType(clone));
                }
            }
        }
        catch (Exception *ex)
        {
            throw;
        }

    }

    void RoleFamilyType::ResolveClassReferences(RoleFamilyType *roleFamilyClass, RoleFamilyType *referencedBaseClass, std::vector<string_type> &referencedClassesList)
    {

        if (referencedBaseClass != 0)
        {
            //mergin classes
            MergeClasses(roleFamilyClass, referencedBaseClass);

            //check if referenced class is derived from another class, too
            if (referencedBaseClass->RefBaseClassPath.exists())
            {
                string_type referencedBaseClassPath = referencedBaseClass->RefBaseClassPath;
                //check if refernced class path is already in inheritance chain
                if (std::find(referencedClassesList.begin(), referencedClassesList.end(), referencedBaseClassPath) == referencedClassesList.end())
                {
                    //if not add path to list to avoid cyclic inheritance
                    referencedClassesList.push_back(referencedBaseClassPath);
                    RoleFamilyType *referencedRoleFamilyType = getClassForPath(referencedBaseClassPath);
                    if (referencedRoleFamilyType != 0)
                    {
                        ResolveClassReferences(roleFamilyClass, referencedRoleFamilyType, referencedClassesList);
                    }
                }
                else
                {
                    //throw exception
                    //A class should not contain an InternalElement that references this class
                    //throw classinstantiation exception
                    ClassInstantiationException classInstantiationException = ClassInstantiationException(string_type("Cannot create an instance of class: ").append(getFullNodePath(GetNode())).append("!\nClass reference: ").append(referencedBaseClassPath).append(" in class: ").append(referencedBaseClass->Name).append(" points back to an already referenced class. This is a cross reference."));

                    throw classInstantiationException;
                }
            }
        }
    }

    void RoleFamilyType::ResolveExternalInterfaceReferences(RoleRequirementsType *roleRequirement)
    {
        //list that contains interfaceelements that can be removed after iterating through child elements
        std::vector<InterfaceClassType*> toBeRemovedInterfaceElements = std::vector<InterfaceClassType*>();
        std::vector<InterfaceClassType*> toBeInsertedInterfaceElements = std::vector<InterfaceClassType*>();

        for (RoleRequirementsType::ExternalInterface::iterator externalInterface = roleRequirement->ExternalInterface.all(); externalInterface; ++externalInterface)
        {
            if (externalInterface->RefBaseClassPath.exists())
            {
                xercesc::DOMNode *referencedClassNode = externalInterface->getReferencedClass(externalInterface->RefBaseClassPath);
                if (referencedClassNode != 0)
                {
                    InterfaceFamilyType *referencedInterfaceClass = new InterfaceFamilyType(referencedClassNode);

                    InterfaceClassType *instanceOfReference = static_cast<InterfaceClassType*>(referencedInterfaceClass->CreateClassInstance());

                    instanceOfReference->MergeContent(&externalInterface);

                    //marke the current iterated internalelement node to be removed from this class. if removing now, the iteration behaviour
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
                roleRequirement->GetNode()->removeChild((*child)->GetNode());
            }
        }
        //insert elements
        if (toBeInsertedInterfaceElements.size() > 0)
        {
            for (std::vector<InterfaceClassType*>::const_iterator child = toBeInsertedInterfaceElements.begin(); child != toBeInsertedInterfaceElements.end(); child++)
            {
                roleRequirement->Insert_ExternalInterface(*child);
            }
        }

    }

    RoleRequirementsType *RoleFamilyType::CreateInstance(RoleFamilyType *classToInstantiate)
    {

        ///first create a clone of this class
        RoleFamilyType *clonedRoleFamilyClass = new RoleFamilyType(GetNode()->cloneNode(true));


        //check if this class is derived from another class, if so copy all elements of the base class to
        //this clone class
        if (clonedRoleFamilyClass->RefBaseClassPath.exists())
        {
            string_type referencedBaseClassPath = clonedRoleFamilyClass->RefBaseClassPath;
            //check if this class refereneces itself. do not merge classes then!
            if (string_type(classToInstantiate->getFullNodePath(classToInstantiate->GetNode())).compare(referencedBaseClassPath) != 0)
            {
                //list that holds pathes to referenced base classes. The list ist used to avoid
                //cyclic class inheritance, e.g. class B is derived from class A, A is derived from class C and
                //class C is derived from B.
                std::vector<string_type> referencedClassesList = std::vector<string_type>();

                //adding path to list to avoid cyclic inheritance
                referencedClassesList.push_back(referencedBaseClassPath);

                classToInstantiate->ResolveClassReferences(clonedRoleFamilyClass, classToInstantiate->getClassForPath(referencedBaseClassPath), referencedClassesList);

            }
        }


        //remove all child roleclasses. A hierarchical structure of roleclasses has no semantic!
        //inheritence is realized via refbaseclasspath attributes!
        clonedRoleFamilyClass->RoleClass.remove();
        //remove header
        clonedRoleFamilyClass->RemoveHeader();

        //remove tag attributes. These are not the CAEX AttributeTypes
        //clonedRoleFamilyClass->GetNode()->Attributes->RemoveAll();
        xercesc::DOMNamedNodeMap *nodes = clonedRoleFamilyClass->GetNode()->getAttributes();
        for (int i = nodes->getLength() - 1; i >= 0; i--)
        {
            nodes->removeNamedItem(nodes->item(i)->getNodeName());
        }

        //rename the xmlnode tag name from RoleClass to RoleRequirements
        xercesc::DOMNode *clonedXmlNode = clonedRoleFamilyClass->GetNode();
        xercesc::DOMElement *renamedXmlNode = clonedXmlNode->getOwnerDocument()->createElement(XercesStringTemp((members + _altova_mi_altova_InternalElementType_altova_RoleRequirements)->LocalName));
        //copy all child nodes from clonednode to renamed node (interfaceclass childs are already deleteted)
        xercesc::DOMNodeList *childNode = clonedXmlNode->getChildNodes();
        for (int i = 0; i<childNode->getLength(); i++)
        {
            renamedXmlNode->appendChild(childNode->item(i)->cloneNode(true));
        }
        //create new rolerequirement element with renamed xml node
        RoleRequirementsType *newRoleRequirements = new RoleRequirementsType(renamedXmlNode);
        //set name of instance element
        //A rolerequirement does not have "name" and "id" attributes
        //set referenced class path
            newRoleRequirements->RefBaseRoleClassPath = this->getFullNodePath(GetNode());

        return newRoleRequirements;
    }

    TypeBase *RoleFamilyType::CreateClassInstance()
    {

        RoleRequirementsType *newRoleRequirements = CreateInstance(this);
        ResolveExternalInterfaceReferences(newRoleRequirements);

        return newRoleRequirements;
    }

    RoleFamilyType *RoleFamilyType::getClassForPath(string_type referencedClassPath)
    {
        try
        {
            xercesc::DOMNode *referencedClass = this->getReferencedClass(referencedClassPath);

            if (referencedClass != 0)
            {
                RoleFamilyType *referencedRoleFamilyClass = new RoleFamilyType(referencedClass);
                return referencedRoleFamilyClass;
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

    bool RoleFamilyType::Insert_Element(TypeBase *elementToInsert)
    {
        bool successfullyInserted = true;

        if (dynamic_cast<ExternalInterfaceType*>(elementToInsert) != 0)
        {
            Insert_ExternalInterface(static_cast<ExternalInterfaceType*>(elementToInsert));
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
        else if (dynamic_cast<RoleClassType*>(elementToInsert) != 0)
        {
            Insert_RoleClass(static_cast<RoleClassType*>(elementToInsert));

        }
        else if (dynamic_cast<RoleFamilyType*>(elementToInsert) != 0)
        {
            Insert_RoleFamilyClass(static_cast<RoleFamilyType*>(elementToInsert));
        }
        else
        {
            successfullyInserted = false;
        }

        return successfullyInserted;
    }

}
