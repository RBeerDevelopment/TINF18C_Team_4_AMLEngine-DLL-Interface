#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CInternalLinkType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CInternalLinkType

#include "type_.CCAEXObject.h"
#include "Property.h"
#include "LinkedObjects.h"

namespace CAEX_ClassModel
{

class InternalLinkType : public CAEXObject
{
public:
	CAEX_ClassModel_EXPORT InternalLinkType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT InternalLinkType(InternalLinkType const& init);
	void operator=(InternalLinkType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_InternalLinkType); }
	MemberAttribute<string_type,_altova_mi_altova_InternalLinkType_altova_RefPartnerSideA> RefPartnerSideA;	// RefPartnerSideA Cstring
	MemberAttribute<string_type,_altova_mi_altova_InternalLinkType_altova_RefPartnerSideB> RefPartnerSideB;	// RefPartnerSideB Cstring

    // added
    static const string_type LINK_SEPARATOR;

    LinkedObjects *linkedObjects;

    /// Property that contains additional information about an validation error of this link. It is empty when the link is valid
    Property<string_type> validationErrorText;

    /// Tests if this link is a valid link. For example if referenced classes are found.
    /// Detailed information of an invalid link can be found in property ValidationErrorText after validating this link.
    /// @return true, if this link is valid. Fals else
    CAEX_ClassModel_EXPORT bool IsValidLink();

private:
    /// Resolve the link and return an LinkedObject.
    /// @return The linked objects
    LinkedObjects *ResolveLink();

};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CInternalLinkType
