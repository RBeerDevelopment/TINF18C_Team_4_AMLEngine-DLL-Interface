#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CCopyrightType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CCopyrightType

#include "type_xs.CstringType.h"


namespace CAEX_ClassModel
{

class CopyrightType : public xs::CstringType
{
public:
	CAEX_ClassModel_EXPORT CopyrightType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT CopyrightType(CopyrightType const& init);
	void operator=(CopyrightType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CopyrightType); }
	CAEX_ClassModel_EXPORT void operator=(const string_type& value);
	MemberAttribute<string_type,_altova_mi_altova_CopyrightType_altova_ChangeMode> ChangeMode;	// ChangeMode CChangeMode
};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CCopyrightType
