#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CRoleFamilyType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CRoleFamilyType

#include "RoleClassType.h"
#include "IInstantiable.h"


namespace CAEX_ClassModel
{

class RoleFamilyType : public RoleClassType, IInstantiable
{
public:
	CAEX_ClassModel_EXPORT RoleFamilyType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT RoleFamilyType(RoleFamilyType const& init);
	void operator=(RoleFamilyType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_RoleFamilyType); }
	MemberElement<RoleFamilyType, _altova_mi_altova_RoleFamilyType_altova_RoleClass> RoleClass;
	struct RoleClass { typedef Iterator<RoleFamilyType> iterator; };

    // added

public:
    /// Adding a new RoleClass to this object.
    /// @param  name The name of the new role class
    /// @return The new RoleClass
    /// @note The user is responsible to delete the object the returned pointer is pointing to!
    CAEX_ClassModel_EXPORT RoleFamilyType *New_RoleClass(string_type name);

    CAEX_ClassModel_EXPORT void Insert_RoleClass(RoleClassType *roleClass);
    CAEX_ClassModel_EXPORT void Insert_RoleFamilyClass(RoleFamilyType *roleClass);

private:
    /// Merging a class with the elements of its referenced base class. Header elements are not merged!
    /// @param  roleClass The class to insert the base class elements to
    /// @param  baseClass The path to the referenced base class
    static void MergeClasses(RoleFamilyType *roleClass, RoleFamilyType *baseClass);


    /// @exception ClassInstantiationException throws this exception if a cyclic class reference is found
    void ResolveClassReferences(RoleFamilyType *roleFamilyClass, RoleFamilyType *referencedBaseClass, std::vector<string_type> &referencedClassesList);



    /// Creating an instance of contained externalInterfaces that have a reference to a base class. There is no need to
    /// recursive call this method, because interface are not allowed to contain sub-interfaces
    /// @param  roleRequirement The RoleRequirementsType with interfaces, that should be replaced by there clas instances
    static void ResolveExternalInterfaceReferences(RoleRequirementsType *roleRequirement);


    RoleRequirementsType *CreateInstance(RoleFamilyType *classToInstantiate);


public:
    /// Creating a instance of this roleclass. The created instance is of type RoleRequirements and can be added to an InternalElement.
    /// @return An instance of this RoleClass as type RoleRequirements
    CAEX_ClassModel_EXPORT TypeBase *CreateClassInstance();


    /// Resolving a reference to a base class if this rolefamily type has a reference to a base class
    /// @param  referencedClassPath
    /// @return
    CAEX_ClassModel_EXPORT RoleFamilyType *getClassForPath(string_type referencedClassPath);

    /// Inserting an element generically to this object.
    /// @param  elementToInsert
    /// @return
    CAEX_ClassModel_EXPORT bool Insert_Element(TypeBase *elementToInsert);

};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CRoleFamilyType
