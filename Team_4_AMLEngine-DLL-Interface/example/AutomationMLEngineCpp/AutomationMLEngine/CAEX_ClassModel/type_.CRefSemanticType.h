#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CRefSemanticType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CRefSemanticType

#include "CAEXBasicObject.h"


namespace CAEX_ClassModel
{

class RefSemanticType : public CAEXBasicObject
{
public:
	CAEX_ClassModel_EXPORT RefSemanticType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT RefSemanticType(RefSemanticType const& init);
	void operator=(RefSemanticType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_RefSemanticType); }
	MemberAttribute<string_type,_altova_mi_altova_RefSemanticType_altova_CorrespondingAttributePath> CorrespondingAttributePath;	// CorrespondingAttributePath Cstring
};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CRefSemanticType
