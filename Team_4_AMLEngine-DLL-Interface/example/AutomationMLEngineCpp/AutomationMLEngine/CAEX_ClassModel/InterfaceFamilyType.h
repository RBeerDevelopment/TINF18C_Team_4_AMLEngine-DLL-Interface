#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CInterfaceFamilyType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CInterfaceFamilyType

#include "InterfaceClassType.h"
#include "IInstantiable.h"


namespace CAEX_ClassModel
{

class InterfaceFamilyType : public InterfaceClassType, IInstantiable
{
public:
	CAEX_ClassModel_EXPORT InterfaceFamilyType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT InterfaceFamilyType(InterfaceFamilyType const& init);
	void operator=(InterfaceFamilyType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_InterfaceFamilyType); }
	MemberElement<InterfaceFamilyType, _altova_mi_altova_InterfaceFamilyType_altova_InterfaceClass> InterfaceClass;
	struct InterfaceClass { typedef Iterator<InterfaceFamilyType> iterator; };

    //added

private:
    static std::vector<string_type> referencedClassesList;

public:
    /// Adding a new Interface class to this object.
    /// @param name The name of the InterfaceClass
    /// @return The new InterfaceClass
    /// @note user is responsible to free returned object
    CAEX_ClassModel_EXPORT InterfaceFamilyType *New_InterfaceClass(string_type name);
    CAEX_ClassModel_EXPORT void Insert_InterfaceClass(InterfaceFamilyType *interfaceClass);


private:
    /// Merging a class with the elements of its referenced base class. Header elements are not merged!
    /// @param clonedClass The class to insert the base class elements to
    /// @param baseClass the referenced base class
    static void MergeClasses(InterfaceFamilyType *clonedClass, InterfaceFamilyType *baseClass);

    /// Method used to recursivly add all elements of the referenced classes hierarchy to the cloned class
    /// @param clonedClass The current class to create an instance for
    /// @param referncedBaseClass The referenced class in the class inhertance hierachy whose elements should be copied to the cloned class
    /// @exception ClassInstantiationException 
    void ResolveClassReferences(InterfaceFamilyType *clonedClass, InterfaceFamilyType *referencedBaseClass);


    /// Creating an instance of this class
    /// @return
    ExternalInterfaceType *CreateInstance(InterfaceFamilyType *classToInstantiate);

public:
    /// Creates an instance of this class and returns the instance as an new InterfaceClassType.
    /// @return An instance of this class as a new external interface of type InterfaceClassType
    //public InterfaceClassType CreateClassInstance()
    CAEX_ClassModel_EXPORT TypeBase *CreateClassInstance();


    /// Resolving a reference to a base class if this interface class has a reference to a base class
    /// @param referencedClassPath
    /// @return
    CAEX_ClassModel_EXPORT InterfaceFamilyType *getClassForPath(string_type referencedClassPath);

    /// Inserting an element generically to this object.
    /// @param elementToInsert
    /// @return
    CAEX_ClassModel_EXPORT bool Insert_Element(TypeBase *elementToInsert);

};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CInterfaceFamilyType
