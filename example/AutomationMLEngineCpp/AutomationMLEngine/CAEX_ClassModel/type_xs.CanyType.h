#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA_xs_ALTOVA_CanyType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA_xs_ALTOVA_CanyType



namespace CAEX_ClassModel
{

namespace xs
{	

class CanyType : public TypeBase
{
public:
	CAEX_ClassModel_EXPORT CanyType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT CanyType(CanyType const& init);
	void operator=(CanyType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_xs_altova_CanyType); }
	CAEX_ClassModel_EXPORT void operator=(const string_type& value);
	CAEX_ClassModel_EXPORT operator string_type();
};



} // namespace xs

}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA_xs_ALTOVA_CanyType