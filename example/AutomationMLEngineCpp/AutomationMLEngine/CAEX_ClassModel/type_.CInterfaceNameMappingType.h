#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CInterfaceNameMappingType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CInterfaceNameMappingType

#include "CAEXBasicObject.h"


namespace CAEX_ClassModel
{

class InterfaceNameMappingType : public CAEXBasicObject
{
public:
	CAEX_ClassModel_EXPORT InterfaceNameMappingType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT InterfaceNameMappingType(InterfaceNameMappingType const& init);
	void operator=(InterfaceNameMappingType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_InterfaceNameMappingType); }
	MemberAttribute<string_type,_altova_mi_altova_InterfaceNameMappingType_altova_SystemUnitInterfaceName> SystemUnitInterfaceName;	// SystemUnitInterfaceName Cstring
	MemberAttribute<string_type,_altova_mi_altova_InterfaceNameMappingType_altova_RoleInterfaceName> RoleInterfaceName;	// RoleInterfaceName Cstring
};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CInterfaceNameMappingType
