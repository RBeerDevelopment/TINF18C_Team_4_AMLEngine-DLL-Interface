#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CAttributeDataTypeType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CAttributeDataTypeType



namespace CAEX_ClassModel
{

class AttributeDataTypeType : public TypeBase
{
public:
	CAEX_ClassModel_EXPORT AttributeDataTypeType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT AttributeDataTypeType(AttributeDataTypeType const& init);
	void operator=(AttributeDataTypeType const& other) { m_node = other.m_node; }
	static altova::meta::SimpleType StaticInfo() { return altova::meta::SimpleType(types + _altova_ti_altova_AttributeDataTypeType); }
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

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CAttributeDataTypeType
