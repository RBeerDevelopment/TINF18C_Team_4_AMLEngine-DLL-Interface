#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CInternalElementType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CInternalElementType

#include "SystemUnitClassType.h"
#include <list>

namespace CAEX_ClassModel
{

class LinkedObjects; // TODO remove this line if LinkedObjects is implemented

class InternalElementType : public SystemUnitClassType
{
public:
	CAEX_ClassModel_EXPORT InternalElementType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT InternalElementType(InternalElementType const& init);
	void operator=(InternalElementType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_InternalElementType); }
	MemberAttribute<string_type,_altova_mi_altova_InternalElementType_altova_RefBaseSystemUnitPath> RefBaseSystemUnitPath;	// RefBaseSystemUnitPath Cstring
	MemberElement<RoleRequirementsType, _altova_mi_altova_InternalElementType_altova_RoleRequirements> RoleRequirements;
	struct RoleRequirements { typedef Iterator<RoleRequirementsType> iterator; };
	MemberElement<MappingType, _altova_mi_altova_InternalElementType_altova_MappingObject> MappingObject;
	struct MappingObject { typedef Iterator<MappingType> iterator; };

    // added
    /// Adding a new RoleRequirements element to this InternalElement. It is only allowed to add one RoleRequirements node.
    /// @return The new RoleRequirements element
    /// @exception SchemaConformanceException element is already existent
    CAEX_ClassModel_EXPORT RoleRequirementsType *New_RoleRequirements();

    /// Inserting an RoleRequirements node at the correct child position of this node according to CAEX Schema.
    /// @param roleRequirementsElementNode The InternalElement node to insert.
private:
    void InsertRoleRequirementsNodeInternal(xercesc::DOMNode *roleRequirementsElementNode);

public:
    /// Inserting a RoleRequirement to this InternalElement. An exception is thrown if a RoleRequirements is already existent.
    /// @param roleRequirement The RoleRequirement ot insert
    /// @exception SchemaConformanceException element is already existent
    CAEX_ClassModel_EXPORT void Insert_RoleRequirements(RoleRequirementsType *roleRequirement);


    /// Adding a new MappingObject element to this InternalElement. It is only allowed to add one RoleRequirements node.
    /// @return The new MappingObject element
    /// @exception SchemaConformanceException element is already existent
    CAEX_ClassModel_EXPORT MappingType *New_MappingObject();

    /// Adding a MappingObject element to this InternalElement. It is only allowed to add one MappingObject node.
    /// @return The MappingObject element
    /// @exception SchemaConformanceException element is already existent
    CAEX_ClassModel_EXPORT void Insert_MappingObject(MappingType mappingObject);

    /// Inserting a new class instance to this object.
    /// @param newInstanceObject The instance of a class to be inserted at this object. The instance can be of type
    /// InternelElementType, InterfaceClassType or RoleRequirementsType
    CAEX_ClassModel_EXPORT virtual bool Insert_NewInstance(TypeBase *newInstanceObject);


    /// Creates a copy of this InternalElement with a new GUID.
    /// @return A copy of this InternalElement with a unique GUID
    CAEX_ClassModel_EXPORT InternalElementType *Create_UniqueCopy();

    /// Recursively assigning new GUID to the given InternalElement and all of its child InternalElements
    /// @param internalElement
private:
    void AssignNewGUID(InternalElementType *internalElement);

    /// Public method to assing new guids to this InternalElement and all of its child InternalElements
public:
    CAEX_ClassModel_EXPORT void AssignNewGUIDs();


    /// Merging an InternalElement with the elements of another InternalElement. Header elements are not merged!
    /// @param contentToMergeWith The InternalElement to merge content with
    /// @param mergeRole If true, RoleRequirements and MappingObject are copied from given InternalElement to this InternalElement
    /// @return The object with merged content.
    /// @exception altova::Exception* may throw an exception of this type
    CAEX_ClassModel_EXPORT InternalElementType *MergeContent(InternalElementType *contentToMergeWith, bool mergeRole);



    /// Resolving references to RoleClasses and replacing that reference with an instance of the referenced role class.
    /// For an internalElement it is only allowed to contain one role reference due to schema.
    CAEX_ClassModel_EXPORT void ResolveRoleReferences();



    /// Creating an instance of contained externalInterfaces that have a reference to a base class. There is no need to
    /// recursive call this method, because interface are not allowed to contain sub-interfaces
    /// @param newInternalElement
    CAEX_ClassModel_EXPORT void ResolveExternalInterfaceReferences();


    /// Resolving all class references of sub-InternalElements of a this InternalElement and replacing them with instances of referenced classes.
    /// @param referencedClassesList A list with already referenced classes. This list is used to avoid cyclic class referencing
    /// @exception ClassInstantiationException throws an exception of this kind if a cyclic reference is detected
    CAEX_ClassModel_EXPORT void ResolveInternalElementReferences(std::vector<string_type> &referencedClassesList);

    /// Check if this InternalElement is part of a combined kinematic.
    /// @return True if this is part of a combined kinematik, false else
    CAEX_ClassModel_EXPORT bool IsPartOfCombinedKinematik();

    /// Moving up the hierarchy recursively to check if this internalelement is part of a comined kinematik
    /// @param xmlNode
    /// @return true on success and false on failure TODO uberpruefen ob's stimmt
private:
    bool stepUpDomTree(xercesc::DOMNode *xmlNode);

    /// Getting a list of LinkedObjects object of this InternalElement containing references to the concrete referenced InternalElements via an InternalLink.
    /// @return A list of linkedObjects for this InternalElement. This list is empty if no InternalLink exists
public:
    CAEX_ClassModel_EXPORT std::vector<LinkedObjects*> *getLinkedObjects();

    /// Searches for an ExternalInterface in this InternalElement
    /// @param interfaceName Name of the ExternalInterface to search for
    /// @return An ExternalInterface of the given InternalElement with name attribute equal to interfaceName
    CAEX_ClassModel_EXPORT ExternalInterfaceType *findExternalInterface(string_type interfaceName);

    /// Inserting an element of base type TypeBase to this object.
    /// @param elementToInsert
    /// @return true on success and false on failure
    CAEX_ClassModel_EXPORT bool Insert_Element(TypeBase *elementToInsert);

};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CInternalElementType
