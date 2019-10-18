#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CInstanceHierarchyType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CInstanceHierarchyType

#include "type_.CCAEXObject.h"


namespace CAEX_ClassModel
{

class InstanceHierarchyType : public CAEXObject
{
public:
	CAEX_ClassModel_EXPORT InstanceHierarchyType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT InstanceHierarchyType(InstanceHierarchyType const& init);
	void operator=(InstanceHierarchyType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_InstanceHierarchyType); }
	MemberElement<InternalElementType, _altova_mi_altova_InstanceHierarchyType_altova_InternalElement> InternalElement;
	struct InternalElement { typedef Iterator<InternalElementType> iterator; };

    // added
    /// Adding a new InternalElement to this InstanceHierarchy.;
    /// @param internalElementName The name of the new InternalElement
    /// @note The user is responsible to delete the object the returned pointer references!
    /// @return A new InternalElement
    CAEX_ClassModel_EXPORT InternalElementType *New_InternalElement(string_type internalElementName);

    /// Inserting an InternalElement to this InstanceHierarchy.
    /// @param internalElement The InternalElement to insert
    CAEX_ClassModel_EXPORT void Insert_InternalElement(InternalElementType *internalElement);

    /// Inserting an class instance object to this hierarchy. Only instance objects of type InternalElementType
    /// are inserted. This is an alternative call for Insert_Element(TypeBase);
    /// @note The insertion of arbitrary classes inherited from TypeBase is possible. Use with care, because schema conformance is not preserved
    /// @param newInstanceObject A class instance.
    CAEX_ClassModel_EXPORT void Insert_NewInstance(TypeBase *newInstanceObject);

    /// Inserting an element generically to this object.
    /// @param elementToInsert the element to insert
    /// @return true on success and false on failure
    CAEX_ClassModel_EXPORT bool Insert_Element(TypeBase *elementToInsert);

};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CInstanceHierarchyType
