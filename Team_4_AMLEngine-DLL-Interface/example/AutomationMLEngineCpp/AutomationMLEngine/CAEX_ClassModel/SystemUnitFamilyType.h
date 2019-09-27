#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CSystemUnitFamilyType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CSystemUnitFamilyType

#include "SystemUnitClassType.h"
#include "IInstantiable.h"


namespace CAEX_ClassModel
{

class SystemUnitFamilyType : public SystemUnitClassType, IInstantiable
{
public:
	CAEX_ClassModel_EXPORT SystemUnitFamilyType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT SystemUnitFamilyType(SystemUnitFamilyType const& init);
	void operator=(SystemUnitFamilyType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_SystemUnitFamilyType); }
	MemberAttribute<string_type,_altova_mi_altova_SystemUnitFamilyType_altova_RefBaseClassPath> RefBaseClassPath;	// RefBaseClassPath Cstring
	MemberElement<SystemUnitFamilyType, _altova_mi_altova_SystemUnitFamilyType_altova_SystemUnitClass> SystemUnitClass;
	struct SystemUnitClass { typedef Iterator<SystemUnitFamilyType> iterator; };

    // added
    /// Adding a new SystemUnitClass to this SystemUnitClass
    /// @param name The name of the new SystemUnitClass
    /// @return The new SystemUnitClass
    CAEX_ClassModel_EXPORT SystemUnitFamilyType *New_SystemUnitClass(string_type name);

    /// Inserting an SystemUnitFamily type object into this object.
    /// @param systemUnitFamilyType
    CAEX_ClassModel_EXPORT void Insert_SystemUnitFamilyType(SystemUnitFamilyType *systemUnitFamilyType);

private:
    /// Merging a class with the elements of its referenced base class. Header elements are not merged!
    /// @param clonedClass The class to insert the base class elements to
    /// @param baseClass The base class to merge with
    static void MergeClasses(SystemUnitFamilyType *clonedClass, SystemUnitFamilyType *baseClass);

    /// Method used to recursivly add all elements of the referenced classes hierarchy to the cloned class
    /// @param clonedClass The current class to create an instance for
    /// @param referncedBaseClass The referenced class in the class inhertance hierachy whose elements should be copied to the cloned class
    /// @exception ClassInstantiationException throws this exception if a cyclic class reference is found
    void ResolveClassReferences(SystemUnitFamilyType *clonedClass, SystemUnitFamilyType *referencedBaseClass, std::vector<string_type> &referencedClassesList);

    /// Creating an instance of a given class and returns that instance as an InternalElement. An instance is created by copying all
    /// information of referenced base classes to the class to instantiate and finally creating an InternalElement with this information.
    /// @param classToInstantiate The class to create an instance for
    /// @param referencedClassesList Empty list, that is filled with referenced class pathes to avoid cyclic referencing
    /// @return An instance of the given class as an InternalElement
    /// @exception altova::Exception* may throw an Exception of this type
    static InternalElementType *CreateInstance(SystemUnitFamilyType *classToInstantiate, std::vector<string_type> &referencedClassesList);



public:
    /// Creates an instance of this class and returns the instance as a new InternalElement.
    /// @return An instance of this class as a new InternalElement
    CAEX_ClassModel_EXPORT TypeBase *CreateClassInstance();

    ///  Creates an instance of this class and returns the instance as a new InternalElement. The list parameter contains
    ///  class references that are already visited and are forbidden to be referenced again to aviod cyclic references
    /// @param referencedInternalClassesList A list with already referenced classes that are not allowed to be instantiated again. Otherwise cyclic intantiation occurs.
    /// @return An instance of this class as an internal element.
    TypeBase *InternalCreateClassInstance(std::vector<string_type> &referencedInternalClassesList);


public:
    /// Getting the class for a given path. The path value is evaluated via an XPath search through the document.
    /// @param referencedClassPath Full path to the desired class. Hierarchies are separated via slash "/"
    /// @return The SystemUnitFamilyType class which is denoted by the given path, or null if no class is found at the given path
    //[Obsolete("Use getReferencedSystemUnitClass of base class CAEXBasicObject instead")]
    CAEX_ClassModel_EXPORT SystemUnitFamilyType *getClassForPath(string_type referencedClassPath);

    /// Inserting an element generically to this object.
    /// @param elementToInsert
    /// @return
    CAEX_ClassModel_EXPORT bool Insert_Element(TypeBase *elementToInsert);

};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CSystemUnitFamilyType
