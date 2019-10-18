#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CUnknownTypeType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CUnknownTypeType



namespace CAEX_ClassModel
{

class UnknownTypeType : public TypeBase
{
public:
	CAEX_ClassModel_EXPORT UnknownTypeType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT UnknownTypeType(UnknownTypeType const& init);
	void operator=(UnknownTypeType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_UnknownTypeType); }
	MemberElement<xs::CstringType, _altova_mi_altova_UnknownTypeType_altova_Requirements> Requirements;
	struct Requirements { typedef Iterator<xs::CstringType> iterator; };

    // added
    /// @note The user is responsible to delete the object the returned pointer is pointing to!
    /// @exception SchemaConformanceException element is already existent
    CAEX_ClassModel_EXPORT xs::CstringType *New_Requirements();  // throws a SchemaConformanceExeption if element already exists
};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CUnknownTypeType
