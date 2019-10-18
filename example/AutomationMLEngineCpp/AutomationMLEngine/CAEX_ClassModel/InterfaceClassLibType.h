#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CInterfaceClassLibType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CInterfaceClassLibType

#include "type_.CCAEXObject.h"


namespace CAEX_ClassModel
{

class InterfaceClassLibType : public CAEXObject
{
public:
	CAEX_ClassModel_EXPORT InterfaceClassLibType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT InterfaceClassLibType(InterfaceClassLibType const& init);
	void operator=(InterfaceClassLibType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_InterfaceClassLibType); }
	MemberElement<InterfaceFamilyType, _altova_mi_altova_InterfaceClassLibType_altova_InterfaceClass> InterfaceClass;
	struct InterfaceClass { typedef Iterator<InterfaceFamilyType> iterator; };

    // added

    /// Adding a new Interface class to this object.
    /// @param name The name of the InterfaceClass
    /// @note The user is responsible to delete the object the returned pointer is pointing to!
    /// @return The new InterfaceClass
    CAEX_ClassModel_EXPORT InterfaceFamilyType *New_InterfaceClass(string_type name);

    /// inserts an InterfaceFamilyType object into this InterfaceClassLib
    /// @param interfaceFamilyType the object to insert
    CAEX_ClassModel_EXPORT void Insert_InterfaceClass(InterfaceFamilyType *interfaceFamilyType);


    /// Inserting an element generically to this object.
    /// @param elementToInsert element to insert
    /// @return true on success and false on failure
    CAEX_ClassModel_EXPORT bool Insert_Element(TypeBase *elementToInsert);

};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CInterfaceClassLibType
