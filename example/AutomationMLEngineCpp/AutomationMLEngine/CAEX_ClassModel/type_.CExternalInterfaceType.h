#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CExternalInterfaceType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CExternalInterfaceType

#include "InterfaceClassType.h"


namespace CAEX_ClassModel
{

class ExternalInterfaceType : public InterfaceClassType
{
public:
	CAEX_ClassModel_EXPORT ExternalInterfaceType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT ExternalInterfaceType(ExternalInterfaceType const& init);
	void operator=(ExternalInterfaceType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_ExternalInterfaceType); }
};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CExternalInterfaceType
