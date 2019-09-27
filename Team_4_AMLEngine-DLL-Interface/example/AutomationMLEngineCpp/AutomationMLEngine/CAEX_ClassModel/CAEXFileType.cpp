#include "StdAfx.h"
#include "CAEX_ClassModel.h"
//#include "CAEXFileType.h"

namespace CAEX_ClassModel
{
    // -----------------------------------------------------------------------
    CAEXFileType::CAEXFileType(xercesc::DOMNode* const& node)
            : CAEXBasicObject(node)
            , FileName(*this)   // "@FileName"
            , SchemaVersion(*this)  // "@SchemaVersion"
            , ExternalReference(*this)  // "ExternalReference"
            , InstanceHierarchy(*this)  // "InstanceHierarchy"
            , InterfaceClassLib(*this)  // "InterfaceClassLib"
            , RoleClassLib(*this)   // "RoleClassLib"
            , SystemUnitClassLib(*this) // "SystemUnitClassLib"
            , CaexSchemaLocation(this, ReadCaexSchemaLocation, WriteCaexSchemaLocation)  // "CAEXSchemaLocation"
    {
    }

    // -----------------------------------------------------------------------
    CAEXFileType::CAEXFileType(CAEXFileType const& other)
            : CAEXBasicObject(other.GetNode())
            , FileName(*this)   // "@FileName"
            , SchemaVersion(*this)  // "@SchemaVersion"
            , ExternalReference(*this)  // "ExternalReference"
            , InstanceHierarchy(*this)  // "InstanceHierarchy"
            , InterfaceClassLib(*this)  // "InterfaceClassLib"
            , RoleClassLib(*this)   // "RoleClassLib"
            , SystemUnitClassLib(*this) // "SystemUnitClassLib"
            , CaexSchemaLocation(this, ReadCaexSchemaLocation, WriteCaexSchemaLocation)  // "CAEXSchemaLocation"
    {
    }

    // -----------------------------------------------------------------------
    string_type CAEXFileType::ReadCaexSchemaLocation(void *instance)
    {
        CAEXFileType *fileType = static_cast<CAEXFileType*>(instance);
        string_type value("CAEX_ClassModel.xsd");
        if (instance != NULL)
        {
            // TODO CaexSchemaLocation aus xml DOMTree aus lesen und debug output entfernen
            std::cout << "Success: read access in class @ " << fileType << " for CaexSchemaLocation @ " << &fileType->CaexSchemaLocation << std::endl;
        }
        else
        {
            std::cout << "Error: no instance given" << std::endl;
        }
        return value;
    }

    // -----------------------------------------------------------------------
    void CAEXFileType::WriteCaexSchemaLocation(void *instance, string_type &value)
    {
        CAEXFileType *fileType = static_cast<CAEXFileType*>(instance);
        if (fileType != NULL)
        {
            // TODO CaexSchemaLocation in xml DomTree einfuegen und debug output entfernen
            std::cout << "Success: Write access in class @ " << fileType << " for CaexSchemaLocation @ " << &fileType->CaexSchemaLocation << std::endl;
        }
        else
        {
            std::cout << "Error: no instance given" << std::endl;
        }
    }

    // -----------------------------------------------------------------------
    InstanceHierarchyType *CAEXFileType::New_InstanceHierarchy(string_type name)
    {
        xercesc::DOMNode* instanceHierarchyNode = XercesTreeOperations::CreateElement(GetNode(), members + _altova_mi_altova_CAEXFileType_altova_InstanceHierarchy);

        xercesc::DOMNode* node = GetNode();

        if (this->InterfaceClassLib.exists())
        {
            node->insertBefore(instanceHierarchyNode, this->InterfaceClassLib.first().GetNode());
        }
        else if (this->RoleClassLib.exists())
        {
            node->insertBefore(instanceHierarchyNode, this->RoleClassLib.first().GetNode());
        }
        else if (this->SystemUnitClassLib.exists())
        {
            node->insertBefore(instanceHierarchyNode, this->SystemUnitClassLib.first().GetNode());
        }
        else
        {
            node->appendChild(instanceHierarchyNode);
        }

        InstanceHierarchyType *newInstanceHierarchyType = new InstanceHierarchyType(instanceHierarchyNode);
        newInstanceHierarchyType->Name = name;
        return newInstanceHierarchyType;
    }

    // -----------------------------------------------------------------------
    SystemUnitClassLibType *CAEXFileType::New_SystemUnitClassLibHierarchy(string_type name)
    {
        xercesc::DOMNode* newSystemUnitClassLibHierarchyNode = XercesTreeOperations::AddElement(GetNode(), members + _altova_mi_altova_CAEXFileType_altova_SystemUnitClassLib);

        SystemUnitClassLibType *newSystemUnitClassLib = new SystemUnitClassLibType(newSystemUnitClassLibHierarchyNode);
        newSystemUnitClassLib->Name = name;
        return newSystemUnitClassLib;
    }

    // -----------------------------------------------------------------------
    void CAEXFileType::Import_SystemUnitClassLibHierarchy(SystemUnitClassLibType *systemUnitClassLib)
    {
        xercesc::DOMNode *systemClassNode = GetNode()->getOwnerDocument()->importNode(systemUnitClassLib->GetNode(), true);
        SystemUnitClassLibType *importedSystemClass = new SystemUnitClassLibType(systemClassNode);
        Insert_SystemUnitClassLibHierarchy(importedSystemClass);
    }

    // -----------------------------------------------------------------------
    void CAEXFileType::Insert_SystemUnitClassLibHierarchy(SystemUnitClassLibType *systemUnitClassLib)
    {
        GetNode()->appendChild(systemUnitClassLib->GetNode());
    }

    // -----------------------------------------------------------------------
    RoleClassLibType *CAEXFileType::New_RoleClassLibHierarchy(string_type name)
    {
        xercesc::DOMNode* newRoleClassLibHierarchyNode = XercesTreeOperations::CreateElement(GetNode(), members + _altova_mi_altova_CAEXFileType_altova_RoleClassLib);

        InsertRoleClassLibInternal(newRoleClassLibHierarchyNode);

        RoleClassLibType *newRoleClassLib = new RoleClassLibType(newRoleClassLibHierarchyNode);
        newRoleClassLib->Name = name;
        return newRoleClassLib;
    }

    // -----------------------------------------------------------------------
    void CAEXFileType::InsertRoleClassLibInternal(xercesc::DOMNode *roleClassLibNode)
    {
        xercesc::DOMNode* node = GetNode();

        if (this->SystemUnitClassLib.exists())
        {
            node->insertBefore(roleClassLibNode, this->SystemUnitClassLib.first().GetNode());
        }
        else
        {
            node->appendChild(roleClassLibNode);
        }
    }

    // -----------------------------------------------------------------------
    void CAEXFileType::Insert_RoleClassLibHierarchy(RoleClassLibType *roleClassLib)
    {

        InsertRoleClassLibInternal(roleClassLib->GetNode());
    }

    // -----------------------------------------------------------------------
    void CAEXFileType::Import_RoleClassLibHierarchy(RoleClassLibType *roleClassLib)
    {
        xercesc::DOMNode *roleClassNode = GetNode()->getOwnerDocument()->importNode(roleClassLib->GetNode(), true);
        RoleClassLibType *importedRoleClass = new RoleClassLibType(roleClassNode);
        Insert_RoleClassLibHierarchy(importedRoleClass);
    }

    // -----------------------------------------------------------------------
    ExternalReferenceType *CAEXFileType::New_ExternalReferenceHierarchy(string_type path, string_type alias)
    {
        xercesc::DOMNode *node = GetNode();
        xercesc::DOMNode *newExternalReferenceHierarchyNode = XercesTreeOperations::CreateElement(node, members + _altova_mi_altova_CAEXFileType_altova_ExternalReference);

        if (this->InstanceHierarchy.exists())
        {
            node->insertBefore(newExternalReferenceHierarchyNode, this->InstanceHierarchy.first().GetNode());
        }
        else if (this->InterfaceClassLib.exists())
        {
            node->insertBefore(newExternalReferenceHierarchyNode, this->InterfaceClassLib.first().GetNode());
        }
        else if (this->RoleClassLib.exists())
        {
            node->insertBefore(newExternalReferenceHierarchyNode, this->RoleClassLib.first().GetNode());
        }
        else if (this->SystemUnitClassLib.exists())
        {
            node->insertBefore(newExternalReferenceHierarchyNode, this->SystemUnitClassLib.first().GetNode());
        }
        else
        {
            node->appendChild(newExternalReferenceHierarchyNode);
        }

        ExternalReferenceType *newExternalReference = new ExternalReferenceType(newExternalReferenceHierarchyNode);
        newExternalReference->Path = path;
        newExternalReference->Alias = alias;

        return newExternalReference;
    }

    // -----------------------------------------------------------------------
    InterfaceClassLibType *CAEXFileType::New_InterfaceClassLibHierarchy(string_type name)
    {
        xercesc::DOMNode *newInterfaceClassLibHierarchyNode = XercesTreeOperations::CreateElement(GetNode(), members + _altova_mi_altova_CAEXFileType_altova_InterfaceClassLib);

        InsertInterfaceClassLibInternal(newInterfaceClassLibHierarchyNode);

        InterfaceClassLibType *newInterfaceClassLib = new InterfaceClassLibType(newInterfaceClassLibHierarchyNode);
        newInterfaceClassLib->Name = name;
        return newInterfaceClassLib;
    }

    // -----------------------------------------------------------------------
    void CAEXFileType::InsertInterfaceClassLibInternal(xercesc::DOMNode *newInterfaceClassLibHierarchyNode)
    {
        xercesc::DOMNode *node = GetNode();

        if (this->RoleClassLib.exists())
        {
            node->insertBefore(newInterfaceClassLibHierarchyNode, this->RoleClassLib.first().GetNode());
        }
        else if (this->SystemUnitClassLib.exists())
        {
            node->insertBefore(newInterfaceClassLibHierarchyNode, this->SystemUnitClassLib.first().GetNode());
        }
        else
        {
            node->appendChild(newInterfaceClassLibHierarchyNode);
        }

    }

    // -----------------------------------------------------------------------
    void CAEXFileType::Import_InterfaceClassLibHierarchy(InterfaceClassLibType *interfaceClassLib)
    {
        xercesc::DOMNode *interfaceClassNode = GetNode()->getOwnerDocument()->importNode(interfaceClassLib->GetNode(), true);
        InterfaceClassLibType *importedInterfaceClassLib = new InterfaceClassLibType(interfaceClassNode);
        Insert_InterfaceClassLibHierarchy(importedInterfaceClassLib);

    }

    // -----------------------------------------------------------------------
    void CAEXFileType::Insert_InterfaceClassLibHierarchy(InterfaceClassLibType *interfaceClassLibNode)
    {
        InsertInterfaceClassLibInternal(interfaceClassLibNode->GetNode());
    }

    // -----------------------------------------------------------------------
    std::vector<InternalElementType> CAEXFileType::getAllInternalElementsWithInternalLinks()
    {
        std::vector<InternalElementType> internalElementsList = std::vector<InternalElementType>();

        //iterating through all instance hierarchies and check all internal element childs
        for (InstanceHierarchy::iterator instanceHierarchy(InstanceHierarchy.all()); bool(instanceHierarchy); ++instanceHierarchy)
        {
            string_type name=instanceHierarchy->Name;
            std::cout << "iterating inside " << name << std::endl;
            for (InstanceHierarchyType::InternalElement::iterator internalElement(instanceHierarchy->InternalElement.all()); bool(internalElement); ++internalElement)
            {
                name=instanceHierarchy->Name;
                std::cout << "checking " << name << " for more internal elements" << std::endl;
                IterateInternalElementsForLinks(&internalElement, internalElementsList);
            }
        }
        std::cout << "returning list" << std::endl;
        return internalElementsList;
    }

    // -----------------------------------------------------------------------
    void CAEXFileType::IterateInternalElementsForLinks(InternalElementType *internalElement, std::vector<InternalElementType> &internalElementsList)
    {
        string_type name=internalElement->Name;
        std::cout << "checking " << name << std::endl;

        if (internalElement->InternalLink.exists())
        {
            std::cout << "InternalLink found: adding " << name << " to list" << std::endl;
            internalElementsList.push_back(*internalElement);
        }

        //recursive call for child internal elements
        for (InternalElementType::InternalElement::iterator childInternalElement = internalElement->InternalElement.all(); bool(childInternalElement); ++childInternalElement)
        {
            name=childInternalElement->Name;
            std::cout << "checking " << name << " for more internal elements" << std::endl;
            IterateInternalElementsForLinks(&childInternalElement, internalElementsList);
        }
        std::cout << "finished with this sub tree" << std::endl;
    }

}
