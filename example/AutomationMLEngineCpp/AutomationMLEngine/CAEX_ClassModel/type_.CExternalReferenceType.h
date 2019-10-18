#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CExternalReferenceType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CExternalReferenceType

#include "CAEXBasicObject.h"


namespace CAEX_ClassModel
{

class ExternalReferenceType : public CAEXBasicObject
{
public:
	CAEX_ClassModel_EXPORT ExternalReferenceType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT ExternalReferenceType(ExternalReferenceType const& init);
	void operator=(ExternalReferenceType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_ExternalReferenceType); }
	MemberAttribute<string_type,_altova_mi_altova_ExternalReferenceType_altova_Path> Path;	// Path Cstring
	MemberAttribute<string_type,_altova_mi_altova_ExternalReferenceType_altova_Alias> Alias;	// Alias Cstring
};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CExternalReferenceType
