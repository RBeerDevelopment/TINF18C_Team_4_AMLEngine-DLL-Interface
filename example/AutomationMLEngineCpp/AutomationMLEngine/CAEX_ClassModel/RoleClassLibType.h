#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CRoleClassLibType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CRoleClassLibType

#include "type_.CCAEXObject.h"


namespace CAEX_ClassModel
{

class RoleClassLibType : public CAEXObject
{
public:
	CAEX_ClassModel_EXPORT RoleClassLibType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT RoleClassLibType(RoleClassLibType const& init);
	void operator=(RoleClassLibType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_RoleClassLibType); }
	MemberElement<RoleFamilyType, _altova_mi_altova_RoleClassLibType_altova_RoleClass> RoleClass;
	struct RoleClass { typedef Iterator<RoleFamilyType> iterator; };

    // added

    /// Generates a new RoleClass and inserts it in this RoleClassLib
    /// @param name the name of the new RoleClass
    /// @note The user is responsible to delete the object the returned pointer is pointing to!
    /// @return a pointer to the new RoleClass is returned
    CAEX_ClassModel_EXPORT RoleFamilyType *New_RoleClass(string_type name);

    /// Inserts a RoleClass in this RoleClassLib
    /// @param roleClass the RoleFamilyType to insert
    CAEX_ClassModel_EXPORT void Insert_RoleClass(RoleFamilyType *roleClass);

    /// Inserting an element generically to this object.
    /// @param elementToInsert the element to insert in this RoleClassLib
    /// @return true on success and false on failure
    CAEX_ClassModel_EXPORT bool Insert_Element(TypeBase *elementToInsert);

};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CRoleClassLibType
