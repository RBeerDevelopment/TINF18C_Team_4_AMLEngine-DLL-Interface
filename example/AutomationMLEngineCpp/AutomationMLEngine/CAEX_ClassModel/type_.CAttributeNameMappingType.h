#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CAttributeNameMappingType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CAttributeNameMappingType

#include "CAEXBasicObject.h"


namespace CAEX_ClassModel
{

class AttributeNameMappingType : public CAEXBasicObject
{
public:
	CAEX_ClassModel_EXPORT AttributeNameMappingType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT AttributeNameMappingType(AttributeNameMappingType const& init);
	void operator=(AttributeNameMappingType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_AttributeNameMappingType); }
	MemberAttribute<string_type,_altova_mi_altova_AttributeNameMappingType_altova_SystemUnitAttributeName> SystemUnitAttributeName;	// SystemUnitAttributeName Cstring
	MemberAttribute<string_type,_altova_mi_altova_AttributeNameMappingType_altova_RoleAttributeName> RoleAttributeName;	// RoleAttributeName Cstring
};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CAttributeNameMappingType
