#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA_xs_ALTOVA_Cint
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA_xs_ALTOVA_Cint



namespace CAEX_ClassModel
{

namespace xs
{	

class Cint : public TypeBase
{
public:
	CAEX_ClassModel_EXPORT Cint(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT Cint(Cint const& init);
	void operator=(Cint const& other) { m_node = other.m_node; }
	static altova::meta::SimpleType StaticInfo() { return altova::meta::SimpleType(types + _altova_ti_xs_altova_Cint); }
	void operator= (const int& value) 
	{
		altova::XmlFormatter* Formatter = static_cast<altova::XmlFormatter*>(altova::IntegerFormatter);
		XercesTreeOperations::SetValue(GetNode(), Formatter->Format(value));
	}	
		
	operator int()
	{
		return CastAs<int >::Do(GetNode(), 0);
	}
};



} // namespace xs

}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA_xs_ALTOVA_Cint
