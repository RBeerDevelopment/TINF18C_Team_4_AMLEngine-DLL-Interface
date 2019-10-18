#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CAttributeValueRequirementType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CAttributeValueRequirementType

#include "CAEXBasicObject.h"


namespace CAEX_ClassModel
{

class AttributeValueRequirementType : public CAEXBasicObject
{
public:
	CAEX_ClassModel_EXPORT AttributeValueRequirementType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT AttributeValueRequirementType(AttributeValueRequirementType const& init);
	void operator=(AttributeValueRequirementType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_AttributeValueRequirementType); }
	MemberAttribute<string_type,_altova_mi_altova_AttributeValueRequirementType_altova_Name> Name;	// Name Cstring
	MemberElement<OrdinalScaledTypeType, _altova_mi_altova_AttributeValueRequirementType_altova_OrdinalScaledType> OrdinalScaledType;
	struct OrdinalScaledType { typedef Iterator<OrdinalScaledTypeType> iterator; };
	MemberElement<NominalScaledTypeType, _altova_mi_altova_AttributeValueRequirementType_altova_NominalScaledType> NominalScaledType;
	struct NominalScaledType { typedef Iterator<NominalScaledTypeType> iterator; };
	MemberElement<UnknownTypeType, _altova_mi_altova_AttributeValueRequirementType_altova_UnknownType> UnknownType;
	struct UnknownType { typedef Iterator<UnknownTypeType> iterator; };

    // added TODO irgendwas
    /// A new unknown type is added to this constraint.
    /// @note The user is responsible to delete the object the returned pointer is pointing to!
    /// @exception SchemaConformanceException element is already existent
    /// @returns A new unknown constraint
    CAEX_ClassModel_EXPORT UnknownTypeType *New_UnknownType();

    /// A new nominal type is added to this constraint.
    /// @note The user is responsible to delete the object the returned pointer is pointing to!
    /// @exception SchemaConformanceException element is already existent
    /// @return A new nominal constraint
    CAEX_ClassModel_EXPORT NominalScaledTypeType *New_NominalType();

    /// A new nominal type is added to this constraint.
    /// @note The user is responsible to delete the object the returned pointer is pointing to!
    /// @exception SchemaConformanceException element is already existent
    /// @return A new nominal constraint
    CAEX_ClassModel_EXPORT OrdinalScaledTypeType *New_OrdinalType();

};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CAttributeValueRequirementType
