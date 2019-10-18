#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CNominalScaledTypeType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CNominalScaledTypeType

#include "CAEX_ClassModel.h"

namespace CAEX_ClassModel
{

class NominalScaledTypeType : public TypeBase
{
public:
	CAEX_ClassModel_EXPORT NominalScaledTypeType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT NominalScaledTypeType(NominalScaledTypeType const& init);
	void operator=(NominalScaledTypeType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_NominalScaledTypeType); }
	MemberElement<xs::CanyType, _altova_mi_altova_NominalScaledTypeType_altova_RequiredValue> RequiredValue;
	struct RequiredValue { typedef Iterator<xs::CanyType> iterator; };

    // added
    /// @note The user is responsible to delete the object the returned pointer is pointing to!
    CAEX_ClassModel_EXPORT xs::CanyType *New_RequiredValue();
};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CNominalScaledTypeType
