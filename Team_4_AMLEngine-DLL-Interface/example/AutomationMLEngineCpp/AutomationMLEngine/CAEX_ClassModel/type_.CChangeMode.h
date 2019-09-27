#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CChangeMode
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CChangeMode



namespace CAEX_ClassModel
{

class ChangeMode : public TypeBase
{
public:
	CAEX_ClassModel_EXPORT ChangeMode(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT ChangeMode(ChangeMode const& init);
	void operator=(ChangeMode const& other) { m_node = other.m_node; }
	static altova::meta::SimpleType StaticInfo() { return altova::meta::SimpleType(types + _altova_ti_altova_ChangeMode); }
	void operator= (const string_type& value) 
	{
		altova::XmlFormatter* Formatter = static_cast<altova::XmlFormatter*>(altova::AnySimpleTypeFormatter);
		XercesTreeOperations::SetValue(GetNode(), Formatter->Format(value));
	}	
		
	operator string_type()
	{
		return CastAs<string_type >::Do(GetNode(), 0);
	}
};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CChangeMode
