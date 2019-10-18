#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA_xs_ALTOVA_CIDREFS
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA_xs_ALTOVA_CIDREFS



namespace CAEX_ClassModel
{

namespace xs
{	

class CIDREFS : public TypeBase
{
public:
	CAEX_ClassModel_EXPORT CIDREFS(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT CIDREFS(CIDREFS const& init);
	void operator=(CIDREFS const& other) { m_node = other.m_node; }
	static altova::meta::SimpleType StaticInfo() { return altova::meta::SimpleType(types + _altova_ti_xs_altova_CIDREFS); }
};



} // namespace xs

}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA_xs_ALTOVA_CIDREFS
