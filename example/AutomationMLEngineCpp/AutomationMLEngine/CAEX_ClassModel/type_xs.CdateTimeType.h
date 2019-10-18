#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA_xs_ALTOVA_CdateTimeType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA_xs_ALTOVA_CdateTimeType



namespace CAEX_ClassModel
{

namespace xs
{	

class CdateTimeType : public TypeBase
{
public:
	CAEX_ClassModel_EXPORT CdateTimeType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT CdateTimeType(CdateTimeType const& init);
	void operator=(CdateTimeType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_xs_altova_CdateTimeType); }
	CAEX_ClassModel_EXPORT void operator=(const altova::DateTime& value);
	CAEX_ClassModel_EXPORT operator altova::DateTime();
};



} // namespace xs

}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA_xs_ALTOVA_CdateTimeType
