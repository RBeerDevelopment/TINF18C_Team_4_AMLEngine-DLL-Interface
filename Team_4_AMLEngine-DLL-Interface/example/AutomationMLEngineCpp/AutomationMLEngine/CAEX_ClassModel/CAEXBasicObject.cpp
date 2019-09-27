//
// C++ Implementation: CAEXBasicObject
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
#include "XMLTools.h"

namespace CAEX_ClassModel
{

    const string_type CAEXBasicObject::PATH_SEPARATOR = "/";

    const string_type CAEXBasicObject::NAME_ATTRIBUTE = "Name";

    // -----------------------------------------------------------------------
    CAEXBasicObject::CAEXBasicObject(xercesc::DOMNode* const& node)
            : TypeBase(node)
            , ChangeMode(*this) // "@ChangeMode"
            , Description(*this)    // "Description"
            , Version(*this)    // "Version"
            , Revision(*this)   // "Revision"
            , Copyright(*this)  // "Copyright"
            , AdditionalInformation(*this)  // "AdditionalInformation"
    {
    }

    // -----------------------------------------------------------------------
    CAEXBasicObject::CAEXBasicObject(CAEXBasicObject const& other)
            : TypeBase(other.GetNode())
            , ChangeMode(*this) // "@ChangeMode"
            , Description(*this)    // "Description"
            , Version(*this)    // "Version"
            , Revision(*this)   // "Revision"
            , Copyright(*this)  // "Copyright"
            , AdditionalInformation(*this)  // "AdditionalInformation"
    {
    }

    // -----------------------------------------------------------------------
    DescriptionType *CAEXBasicObject::getDescription()
    {
        if (this->Description.exists())
        {
            return new DescriptionType(this->Description.first());
        }
        else
        {
            return 0;
        }
    }

    // -----------------------------------------------------------------------
    VersionType *CAEXBasicObject::getVersion()
    {
        if (this->Version.exists())
        {
            return new VersionType(this->Version.first());
        }
        else
        {
            return 0;
        }
    }

    // -----------------------------------------------------------------------
    CopyrightType *CAEXBasicObject::getCopyright()
    {
        if (this->Copyright.exists())
        {
            return new CopyrightType(this->Copyright.first());
        }
        else
        {
            return 0;
        }
    }

    // -----------------------------------------------------------------------
    xercesc::DOMNode *CAEXBasicObject::getLastHeaderNode()
    {

        if (this->AdditionalInformation.exists())
        {
            return this->AdditionalInformation.last().GetNode();
        }
        else if (this->Copyright.exists())
        {
            return this->Copyright.last().GetNode();
        }
        else if (this->Revision.exists())
        {
            return this->Revision.last().GetNode();
        }
        else if (this->Version.exists())
        {
            return this->Version.first().GetNode();
        }
        else if (this->Description.exists())
        {
            return this->Description.last().GetNode();
        }
        else
        {
            return 0;
        }
    }

    // -----------------------------------------------------------------------
    DescriptionType *CAEXBasicObject::New_Description()
    {
        if (Description.exists())
        {
            throw SchemaConformanceException("A description node is already existent. It is not allowed to add more than one description node to current element according to CAEX Schema");
        }
        else
        {
            xercesc::DOMNode *newDescriptionNode = XercesTreeOperations::CreateElement(GetNode(), members + _altova_mi_altova_CAEXObject_altova_Description);
            GetNode()->insertBefore(newDescriptionNode, GetNode()->getFirstChild());
            return new DescriptionType(newDescriptionNode);
        }
    }

    // -----------------------------------------------------------------------
    VersionType *CAEXBasicObject::New_Version()
    {
        if (Version.exists())
        {
            throw SchemaConformanceException("A version node is already existent. It is not allowed to add more than one version node to current element according to CAEX Schema");
        }
        else
        {
            xercesc::DOMNode *newVersionNode = XercesTreeOperations::CreateElement(GetNode(), members + _altova_mi_altova_CAEXBasicObject_altova_Version);
            //insert version node always after description node to be schema conform
            if (Description.exists())
            {
                //this->Node->InsertAfter(newVersionNode, this->Description2->First.Node);
                GetNode()->insertBefore(newVersionNode, Description.first().GetNode()->getNextSibling());
            }
            else
            {
                //this->Node->PrependChild(newVersionNode);
                GetNode()->insertBefore(newVersionNode, GetNode()->getFirstChild());
            }

            return new VersionType(newVersionNode);
        }
    }

    // -----------------------------------------------------------------------
    RevisionType *CAEXBasicObject::New_Revision(altova::DateTime *date, string_type author)
    {
        {
            xercesc::DOMNode *newRevisionNode = XercesTreeOperations::CreateElement(GetNode(), members + _altova_mi_altova_CAEXBasicObject_altova_Revision);
            //insert revision nodes always after version and description nodes to be schema conform
            if (Version.exists())
            {
                //this->Node->InsertAfter(newRevisionNode, this->Version2->First.Node);
                GetNode()->insertBefore(newRevisionNode, Version.first().GetNode()->getNextSibling());
            }
            else if (Description.exists())
            {
                //this->Node->InsertAfter(newRevisionNode, this->Description2->First.Node);
                GetNode()->insertBefore(newRevisionNode, Description.first().GetNode()->getNextSibling());
            }
            else
            {
                //this->Node->PrependChild(newRevisionNode);
                GetNode()->insertBefore(newRevisionNode, GetNode()->getFirstChild());
            }

            //a revision type must have subelements RevisionDate and AuthorName
            RevisionType *revision = new RevisionType(newRevisionNode);
            xs::CdateTimeType *dt = new xs::CdateTimeType(revision->RevisionDate.append());
            //setting a default value for revisionDate
            *dt = *date;

            xs::CstringType *authorName = new xs::CstringType(revision->AuthorName.append());
            *authorName = author;

            return revision;
        }
    }

    // -----------------------------------------------------------------------
    CopyrightType *CAEXBasicObject::New_Copyright()
    {

        if (this->Copyright.exists())
        {
            throw SchemaConformanceException("A copyright node is already existent. It is not allowed to add more than one copyright node to current element according to CAEX Schema");
        }
        else
        {
            xercesc::DOMNode *newCopyrightNode = XercesTreeOperations::CreateElement(GetNode(), members + _altova_mi_altova_CAEXBasicObject_altova_Copyright);
            //insert revision nodes always after version and description nodes to be schema conform

            //if revision exists insert after the last revision node
            if (this->Revision.exists())
            {
                //this->Node->InsertAfter(newCopyrightNode, this->Revision.Last.Node);
                GetNode()->insertBefore(newCopyrightNode, Revision.first().GetNode()->getNextSibling());
            }
            else if (this->Version.exists())
            {
                //this->Node->InsertAfter(newCopyrightNode, this->Version2->First.Node);
                GetNode()->insertBefore(newCopyrightNode, Version.first().GetNode()->getNextSibling());
            }
            else if (this->Description.exists())
            {
                //this->Node->InsertAfter(newCopyrightNode, this->Description2->First.Node);
                GetNode()->insertBefore(newCopyrightNode, Description.first().GetNode()->getNextSibling());
            }
            else
            {
                //this->Node->PrependChild(newCopyrightNode);
                GetNode()->insertBefore(newCopyrightNode, GetNode()->getFirstChild());
            }
            return new CopyrightType(newCopyrightNode);
        }
    }

    // -----------------------------------------------------------------------
    xs::CanyType *CAEXBasicObject::New_AdditionalInformation()
    {
        xercesc::DOMNode *newAdditionalInformationNode = XercesTreeOperations::CreateElement(GetNode(), members + _altova_mi_altova_CAEXBasicObject_altova_AdditionalInformation);

        xercesc::DOMNode *lastHeaderNode = this->getLastHeaderNode();
        if (lastHeaderNode != 0)
        {
            //this->Node->InsertAfter(newAdditionalInformationNode, lastHeaderNode);
            GetNode()->insertBefore(newAdditionalInformationNode, Description.first().GetNode()->getNextSibling());
        }
        else
        {
            //this->Node->PrependChild(newAdditionalInformationNode);
            GetNode()->insertBefore(newAdditionalInformationNode, GetNode()->getFirstChild());
        }

        return new xs::CanyType(newAdditionalInformationNode);
    }

    // -----------------------------------------------------------------------
    void CAEXBasicObject::RemoveHeader()
    {
        if (this->AdditionalInformation.exists())
        {
            this->AdditionalInformation.remove();
        }
        if (this->Description.exists())
        {
            this->Description.remove();
        }
        if (this->ChangeMode.exists())
        {
            this->ChangeMode.remove();
        }
        if (this->Copyright.exists())
        {
            this->Copyright.remove();
        }
        if (this->Version.exists())
        {
            this->Version.remove();
        }
        if (this->Revision.exists())
        {
            this->Revision.remove();
        }
    }

    // -----------------------------------------------------------------------
    string_type CAEXBasicObject::getFullNodePath(xercesc::DOMNode *xmlNode)
    {
        string_type pathString;
        //if a attribute "Name" exist take the value as pathname
        if (xmlNode->getAttributes()->getNamedItem(xercesc::XMLString::transcode(NAME_ATTRIBUTE.c_str())) != 0)
        {
            pathString = getNamedAttributeValue(xmlNode, NAME_ATTRIBUTE);
        }
        //else take xml tag name as name
        else
        {
            pathString = getNodeName(xmlNode);
        }

        if (xmlNode->getParentNode() != 0)
        {
            //no more recursive calls if document root is reached
            if (xmlNode->getParentNode() == xmlNode->getOwnerDocument()->getDocumentElement())
            {
                return pathString;
            }
            else
            {
                return getFullNodePath(xmlNode->getParentNode()) + PATH_SEPARATOR + pathString;
            }
        }
        else
        {
            return pathString;
        }

    }

    // -----------------------------------------------------------------------
    RoleFamilyType *CAEXBasicObject::getReferencedRoleClass(string_type roleClassReference)
    {
        xercesc::DOMNode *classReferenceNode = getReferencedClass(roleClassReference);
        if (classReferenceNode != 0)
        {
            const altova::MemberInfo* memberInfo = members + _altova_mi_altova_RoleFamilyType_altova_RoleClass;
            if (XercesTreeOperations::IsMember(classReferenceNode, memberInfo) == true)
            {
                return new RoleFamilyType(classReferenceNode);
            }
        }
        return 0;
    }

    // -----------------------------------------------------------------------
    SystemUnitFamilyType *CAEXBasicObject::getReferencedSystemUnitClass(string_type systemUnitClassReference)
    {

        xercesc::DOMNode *classReferenceNode = getReferencedClass(systemUnitClassReference);
        if (classReferenceNode != 0)
        {
            const altova::MemberInfo* memberInfo = members + _altova_mi_altova_SystemUnitFamilyType_altova_SystemUnitClass;
            if (XercesTreeOperations::IsMember(classReferenceNode, memberInfo) == true)
            {
                return new SystemUnitFamilyType(classReferenceNode);
            }
        }
        return 0;

    }

    // -----------------------------------------------------------------------
    InterfaceFamilyType *CAEXBasicObject::getReferencedInterfaceClass(string_type interfaceClassReference)
    {

        xercesc::DOMNode *classReferenceNode = getReferencedClass(interfaceClassReference);
        if (classReferenceNode != 0)
        {
            const altova::MemberInfo* memberInfo = members + _altova_mi_altova_InterfaceFamilyType_altova_InterfaceClass;
            if (XercesTreeOperations::IsMember(classReferenceNode, memberInfo) == true)
            {
                return new InterfaceFamilyType(classReferenceNode);
            }
        }
        return 0;

    }

    // -----------------------------------------------------------------------
    xercesc::DOMNode *CAEXBasicObject::getReferencedClass(string_type referencedClassPath)
    {
        try
        {
            ///Trim or no trim of referenced class name? When trimmed and the referenced class name contains a space at the
            ///end of its name, the refrence will not be found!
            //            string referencedClassName = referencedClassPath.Trim();
            xercesc::DOMNode *referencedClass = GetNode();

            string_type path(referencedClassPath);
            string_type rootPath(PATH_SEPARATOR);

            if (path.find(PATH_SEPARATOR)!=string_type::npos)
            {
                string_type::size_type index;
                string_type subpath;
                
                do
                {
                    index = path.find(PATH_SEPARATOR);
                    subpath = path.substr(0, index);
                    path.erase(0, index+1);
                    if (referencedClass != 0)
                    {
                        referencedClass=selectNode(referencedClass, rootPath, PATH_SEPARATOR, "Name", subpath);
                    }
                    else
                    {
                        return 0;
                    }
                    rootPath="./";
                }
                while (path.find(PATH_SEPARATOR)!=string_type::npos);
                
            }

            if (!path.empty() && referencedClass!=0)
            {
                referencedClass=selectNode(referencedClass, rootPath, PATH_SEPARATOR, "Name", path);
            }
                    
            return referencedClass;

        }
        catch (Exception *ex)
        {
            //throwing back to caller
            throw;
        }
    }

    // -----------------------------------------------------------------------
    string_type CAEXBasicObject::getReferencedInterfaceName(string_type reference)
    {
        string_type interfaceName = "";
        int separatorIndex;
        //parsing the referencedclasspath
        if ((int)(reference.find(InternalLinkType::LINK_SEPARATOR)) > -1)
        {
            separatorIndex = reference.find(InternalLinkType::LINK_SEPARATOR);
            interfaceName = reference.substr(separatorIndex + 1);
        }
        return interfaceName;
    }

    // -----------------------------------------------------------------------
    string_type CAEXBasicObject::getReferencedGUID(string_type reference)
    {

        string_type guid = "";
        int separatorIndex;
        //parsing the referencedclasspath
        if ((int)(reference.find(InternalLinkType::LINK_SEPARATOR)) > -1)
        {
            separatorIndex = reference.find(InternalLinkType::LINK_SEPARATOR);
            guid = reference.substr(0, separatorIndex);

        }
        return guid;
    }

    // -----------------------------------------------------------------------
    InternalElementType *CAEXBasicObject::findInternalElement(string_type referenceGUID)
    {
        //string_type xPathSearchString = "//InternalElement[@ID='" + referenceGUID + "']";

        xercesc::DOMNode *referencedClass = selectNode(GetNode(), "//InternalElement", PATH_SEPARATOR, "ID", referenceGUID);

        if (referencedClass != 0)
        {
            return new InternalElementType(referencedClass);
        }
        else
        {
            return 0;
        }

    }

    // -----------------------------------------------------------------------
    bool CAEXBasicObject::ConsistencyCheck_ClassReference(string_type classPath)
    {
        bool pathValid = false;
        xercesc::DOMNode *xmlNode = getReferencedClass(classPath);
        if (xmlNode != 0)
        {
            pathValid = true;
        }

        return pathValid;
    }

    // -----------------------------------------------------------------------
    bool CAEXBasicObject::Insert_TypeBaseElement(TypeBase *elementToInsert)
    {
        bool successfullyInserted = true;

        //cases when this object is of type internal element
        if (dynamic_cast<InternalElementType*>(this) != 0)
        {
            InternalElementType *internalElement = static_cast<InternalElementType*>(this);
            successfullyInserted = internalElement->Insert_Element(elementToInsert);
        }
        else if (dynamic_cast<InstanceHierarchyType*>(this) != 0)
        {
            InstanceHierarchyType *instanceHierarchyType = static_cast<InstanceHierarchyType*>(this);
            successfullyInserted = instanceHierarchyType->Insert_Element(elementToInsert);
        }
        else if (dynamic_cast<SystemUnitFamilyType*>(this) != 0)
        {
            SystemUnitFamilyType *systemUnitFamilyElement = static_cast<SystemUnitFamilyType*>(this);
            successfullyInserted = systemUnitFamilyElement->Insert_Element(elementToInsert);
        }
        else if (dynamic_cast<SystemUnitClassLibType*>(this) != 0)
        {
            SystemUnitClassLibType *systemUnitClassLib = static_cast<SystemUnitClassLibType*>(this);
            successfullyInserted = systemUnitClassLib->Insert_Element(elementToInsert);
        }
        else if (dynamic_cast<RoleFamilyType*>(this) != 0)
        {
            RoleFamilyType *roleFamilyType = static_cast<RoleFamilyType*>(this);
            successfullyInserted = roleFamilyType->Insert_Element(elementToInsert);
        }
        else if (dynamic_cast<RoleRequirementsType*>(this) != 0)
        {
            RoleRequirementsType *roleRequirementsType = static_cast<RoleRequirementsType*>(this);
            successfullyInserted = roleRequirementsType->Insert_Element(elementToInsert);
        }
        //interfacefamily type has to be checked before InterfaceClassType!
        else if (dynamic_cast<InterfaceFamilyType*>(this) != 0)
        {
            InterfaceFamilyType *interfaceFamilyType = static_cast<InterfaceFamilyType*>(this);
            successfullyInserted = interfaceFamilyType->Insert_Element(elementToInsert);
        }
        else if (dynamic_cast<InterfaceClassType*>(this) != 0)
        {
            InterfaceClassType *interfaceClassType = static_cast<InterfaceClassType*>(this);
            successfullyInserted = interfaceClassType->Insert_Element(elementToInsert);
        }

        else if (dynamic_cast<InterfaceClassLibType*>(this) != 0)
        {
            InterfaceClassLibType *interfaceClassLibType = static_cast<InterfaceClassLibType*>(this);
            successfullyInserted = interfaceClassLibType->Insert_Element(elementToInsert);
        }

        //            else if (this is CAEX_ClassModel.ExternalInterfaceType)
        //            {
        //            }
        else if (dynamic_cast<AttributeType*>(this) != 0)
        {
            AttributeType *attributeType = static_cast<AttributeType*>(this);
            successfullyInserted = attributeType->Insert_Element(elementToInsert);
        }
        else if (dynamic_cast<RoleClassLibType*>(this) != 0)
        {
            RoleClassLibType *roleClassLibType = static_cast<RoleClassLibType*>(this);
            successfullyInserted = roleClassLibType->Insert_Element(elementToInsert);
        }
        else if (dynamic_cast<SupportedRoleClassType*>(this) != 0)
        {
            SupportedRoleClassType *supportedRoleClassType = static_cast<SupportedRoleClassType*>(this);
            successfullyInserted = supportedRoleClassType->Insert_Element(elementToInsert);
        }
        else if (dynamic_cast<MappingType*>(this) != 0)
        {
            MappingType *mappingType = static_cast<MappingType*>(this);
            successfullyInserted = mappingType->Insert_Element(elementToInsert);
        }
        else
        {
            successfullyInserted = false;
        }

        return successfullyInserted;
    }

    // -----------------------------------------------------------------------
    TypeBase *CAEXBasicObject::clone()
    {
        if (dynamic_cast<InternalElementType*>(this) != 0)
        {
            return (static_cast<InternalElementType*>(this))->Create_UniqueCopy();
        }
        else
        {
            //Type *type = this->GetType();
            //object *obj = Activator::CreateInstance(type, new object[] { this->Node->Clone() });
            //return static_cast<TypeBase*>(obj);

            // TODO clone objects derived from this class
            return new CAEXBasicObject(GetNode()->cloneNode(true));
        }
    }

}
