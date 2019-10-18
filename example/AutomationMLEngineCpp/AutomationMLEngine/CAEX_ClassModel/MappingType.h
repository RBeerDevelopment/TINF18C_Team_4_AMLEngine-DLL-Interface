#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CMappingType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CMappingType

#include "CAEXBasicObject.h"


namespace CAEX_ClassModel
{

class MappingType : public CAEXBasicObject
{
public:
	CAEX_ClassModel_EXPORT MappingType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT MappingType(MappingType const& init);
	void operator=(MappingType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_MappingType); }
	MemberElement<AttributeNameMappingType, _altova_mi_altova_MappingType_altova_AttributeNameMapping> AttributeNameMapping;
	struct AttributeNameMapping { typedef Iterator<AttributeNameMappingType> iterator; };
	MemberElement<InterfaceNameMappingType, _altova_mi_altova_MappingType_altova_InterfaceNameMapping> InterfaceNameMapping;
	struct InterfaceNameMapping { typedef Iterator<InterfaceNameMappingType> iterator; };

    // added

public:
    /// Adding a new AttributeNameMapping to this MappingObject. An AttributeNameMapping allows the definition of the mapping between attribute names of corresponding RoleClasses and SystemUnitClasses.
    /// @param systemUnitAttributeName The attribute name of the SystemUnitClass
    /// @param roleAttributeName The attribute name of the RoleClass
    /// @return The new AttributeNameMapping element
    /// @note The user is responsible to delete the object the returned pointer is pointing to!
    CAEX_ClassModel_EXPORT AttributeNameMappingType *New_AttributeNameMapping(string_type systemUnitAttributeName, string_type roleAttributeName);

private:
    /// Adding an AttributeNameMappingNode internally
    /// @param attributeNameMappingNode
    void InsertAttributeNameMappingInternal(xercesc::DOMNode *attributeNameMappingNode);

public:
    CAEX_ClassModel_EXPORT void Insert_AttributeNameMapping(AttributeNameMappingType *attributeNameMapping);

    /// Mapping of interface names of corresponding RoleClasses and SystemUnitClasses.
    /// @param systemUnitInterfaceName The name of the interface in the SystemUnitClass
    /// @param roleInterfaceName The name of the interface in the RoleClass
    /// @return The new InterfaceNameMapping element
    /// @note The user is responsible to delete the object the returned pointer is pointing to!
    CAEX_ClassModel_EXPORT InterfaceNameMappingType *New_InterfaceNameMapping(string_type systemUnitInterfaceName, string_type roleInterfaceName);

    CAEX_ClassModel_EXPORT void Insert_InterfaceNameMapping(InterfaceNameMappingType *interfaceNameMapping);


    /// Inserting an element generically to this object.
    /// @param elementToInsert
    /// @return
    CAEX_ClassModel_EXPORT bool Insert_Element(TypeBase *elementToInsert);

};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CMappingType
