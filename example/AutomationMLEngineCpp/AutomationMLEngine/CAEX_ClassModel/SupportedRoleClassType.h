#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CSupportedRoleClassType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CSupportedRoleClassType

#include "CAEXBasicObject.h"


namespace CAEX_ClassModel
{

class SupportedRoleClassType : public CAEXBasicObject
{
public:
	CAEX_ClassModel_EXPORT SupportedRoleClassType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT SupportedRoleClassType(SupportedRoleClassType const& init);
	void operator=(SupportedRoleClassType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_SupportedRoleClassType); }
	MemberAttribute<string_type,_altova_mi_altova_SupportedRoleClassType_altova_RefRoleClassPath> RefRoleClassPath;	// RefRoleClassPath Cstring
	MemberElement<MappingType, _altova_mi_altova_SupportedRoleClassType_altova_MappingObject> MappingObject;
	struct MappingObject { typedef Iterator<MappingType> iterator; };

    // added
    /// Adds a new MappingObject element to this SupportedRoleClass. It is only allowed to add one RoleRequirements node.
    /// @note The user is responsible to delete the object the returned pointer references!
    /// @exception SchemaConformanceException element is already existent
    /// @return The new MappingObject element
    CAEX_ClassModel_EXPORT MappingType *New_MappingObject();

    /// Inserts a MappingObject into this SupportedRoleClass
    /// @param mappingObject the MappingObject to insert
    /// @exception SchemaConformanceException element is already existent
    CAEX_ClassModel_EXPORT void Insert_MappingObject(MappingType *mappingObject);

    /// Inserts an element generically to this object.
    /// @param elementToInsert the element to insert
    /// @return true on success false on failure
    CAEX_ClassModel_EXPORT bool Insert_Element(TypeBase *elementToInsert);
};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CSupportedRoleClassType
