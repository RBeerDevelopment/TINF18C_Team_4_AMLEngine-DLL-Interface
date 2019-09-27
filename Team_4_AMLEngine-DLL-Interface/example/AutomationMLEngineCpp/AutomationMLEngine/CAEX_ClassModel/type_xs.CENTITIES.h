#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA_xs_ALTOVA_CENTITIES
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA_xs_ALTOVA_CENTITIES



namespace CAEX_ClassModel
{

namespace xs
{	

class CENTITIES : public TypeBase
{
public:
	CAEX_ClassModel_EXPORT CENTITIES(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT CENTITIES(CENTITIES const& init);
	void operator=(CENTITIES const& other) { m_node = other.m_node; }
	static altova::meta::SimpleType StaticInfo() { return altova::meta::SimpleType(types + _altova_ti_xs_altova_CENTITIES); }
};



} // namespace xs

}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA_xs_ALTOVA_CENTITIES
