#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CCAEXObject
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CCAEXObject

#include "CAEXBasicObject.h"


namespace CAEX_ClassModel
{

class CAEXObject : public CAEXBasicObject
{
public:
	CAEX_ClassModel_EXPORT CAEXObject(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT CAEXObject(CAEXObject const& init);
	void operator=(CAEXObject const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CAEXObject); }
	MemberAttribute<string_type,_altova_mi_altova_CAEXObject_altova_ID> ID;	// ID Cstring
	MemberAttribute<string_type,_altova_mi_altova_CAEXObject_altova_Name> Name;	// Name Cstring

    // ADDED
    static const string_type GUID_FORMAT;

    string_type ToString() { return Name; }
};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CCAEXObject
