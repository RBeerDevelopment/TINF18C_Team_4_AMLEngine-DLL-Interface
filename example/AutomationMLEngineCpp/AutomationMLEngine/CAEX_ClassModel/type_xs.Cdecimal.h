#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA_xs_ALTOVA_Cdecimal
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA_xs_ALTOVA_Cdecimal



namespace CAEX_ClassModel
{

namespace xs
{	

class Cdecimal : public TypeBase
{
public:
	CAEX_ClassModel_EXPORT Cdecimal(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT Cdecimal(Cdecimal const& init);
	void operator=(Cdecimal const& other) { m_node = other.m_node; }
	static altova::meta::SimpleType StaticInfo() { return altova::meta::SimpleType(types + _altova_ti_xs_altova_Cdecimal); }
	void operator= (const double& value) 
	{
		altova::XmlFormatter* Formatter = static_cast<altova::XmlFormatter*>(altova::DecimalFormatter);
		XercesTreeOperations::SetValue(GetNode(), Formatter->Format(value));
	}	
		
	operator double()
	{
		return CastAs<double >::Do(GetNode(), 0);
	}
};



} // namespace xs

}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA_xs_ALTOVA_Cdecimal
