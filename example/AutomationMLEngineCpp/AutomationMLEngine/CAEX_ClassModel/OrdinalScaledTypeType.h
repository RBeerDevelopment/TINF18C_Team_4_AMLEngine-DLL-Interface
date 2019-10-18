#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_COrdinalScaledTypeType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_COrdinalScaledTypeType



namespace CAEX_ClassModel
{

class OrdinalScaledTypeType : public TypeBase
{
public:
	CAEX_ClassModel_EXPORT OrdinalScaledTypeType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT OrdinalScaledTypeType(OrdinalScaledTypeType const& init);
	void operator=(OrdinalScaledTypeType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_OrdinalScaledTypeType); }
	MemberElement<xs::CanyType, _altova_mi_altova_OrdinalScaledTypeType_altova_RequiredMaxValue> RequiredMaxValue;
	struct RequiredMaxValue { typedef Iterator<xs::CanyType> iterator; };
	MemberElement<xs::CanyType, _altova_mi_altova_OrdinalScaledTypeType_altova_RequiredValue> RequiredValue;
	struct RequiredValue { typedef Iterator<xs::CanyType> iterator; };
	MemberElement<xs::CanyType, _altova_mi_altova_OrdinalScaledTypeType_altova_RequiredMinValue> RequiredMinValue;
	struct RequiredMinValue { typedef Iterator<xs::CanyType> iterator; };

    // added
    /// Adds a new RequiredMaxValue to this ordinal scaled constraint
    /// @note The user is responsible to delete the object the returned pointer is pointing to!
    /// @exception SchemaConformanceException element is already existent
    /// @return The new RequiredMaxValue element
    CAEX_ClassModel_EXPORT xs::CanyType *New_RequiredMaxValue();

    /// Adds a new RequiredValue to this ordinal scaled constraint
    /// @note The user is responsible to delete the object the returned pointer is pointing to!
    /// @exception SchemaConformanceException element is already existent
    /// @return The new RequiredValue element
    CAEX_ClassModel_EXPORT xs::CanyType *New_RequiredValue();

    /// Adds a new requiredMinValue to this ordinal scaled constraint
    /// @note The user is responsible to delete the object the returned pointer is pointing to!
    /// @exception SchemaConformanceException element is already existent
    /// @return The new RequiredMinValue element
    CAEX_ClassModel_EXPORT xs::CanyType *New_RequiredMinValue();

};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_COrdinalScaledTypeType
