#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CRoleRequirementsType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CRoleRequirementsType

#include "CAEXBasicObject.h"
#include "LogicReferenceAttributeType.h"
#include "IObjectWithAttributes.h"


namespace CAEX_ClassModel
{

class RoleRequirementsType : public CAEXBasicObject, IObjectWithAttributes
{
public:
	CAEX_ClassModel_EXPORT RoleRequirementsType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT RoleRequirementsType(RoleRequirementsType const& init);
	void operator=(RoleRequirementsType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_RoleRequirementsType); }
	MemberAttribute<string_type,_altova_mi_altova_RoleRequirementsType_altova_RefBaseRoleClassPath> RefBaseRoleClassPath;	// RefBaseRoleClassPath Cstring
	MemberElement<AttributeType, _altova_mi_altova_RoleRequirementsType_altova_Attribute> Attribute;
	struct Attribute { typedef Iterator<AttributeType> iterator; };
	MemberElement<InterfaceClassType, _altova_mi_altova_RoleRequirementsType_altova_ExternalInterface> ExternalInterface;
	struct ExternalInterface { typedef Iterator<InterfaceClassType> iterator; };

    // added
public:
    /// A new attribute is created and returned.
    /// @param AttributeName The name of the new attribute.
    /// @return The new attribute element
    /// @note The user is responsible to delete the object the returned pointer is pointing to!
    CAEX_ClassModel_EXPORT AttributeType *New_Attribute(string_type attributeName);


private:
    /// Inserting an Attribute node internally
    /// @param attributeNode
    void InsertAttributeNodeInternal(xercesc::DOMNode *attributeNode);

public:
    /// Inserting an attribute element to this class
    /// @param attributeElement The attribute to insert
    CAEX_ClassModel_EXPORT void Insert_Attribute(AttributeType *attributeElement);


    /// Adding a new ExternalInterface.
    /// @param name The name of the ExternalInterface
    /// @return The new ExternalInterface
    /// @note The user is responsible to delete the object the returned pointer is pointing to!
    CAEX_ClassModel_EXPORT InterfaceClassType *New_ExternalInterface(string_type name);

    /// Inserting an externalInterface to this class.
    /// @param interfaceElement
    CAEX_ClassModel_EXPORT void Insert_ExternalInterface(InterfaceClassType *interfaceElement);


    // TODO implement getAttributeField
    //MemberElement_Attribute *getAttributeField();


public:
    /// Reference to the attribute that contains the logic reference for this object
    Property<LogicReferenceAttributeType *> logicReferenceAttribute;
    /// Internal callback function for Property logicReferenceAttribute that gets the LogicReference definied for this object.
    static LogicReferenceAttributeType *getLogicReferenceAttribute(void *);
private:
    /// Getting the logic reference attribute of this object. A single attribute of type LogicReferenceAttributeType is returned.
    /// @return The LogicReferenceAttribute of this object, or null if non found
    LogicReferenceAttributeType *getLogicReference();

public:
    /// Reference to the attribute that contains the geometry reference for this object
    Property<COLLADAReferenceAttributeType *> geometryReferenceAttribute;
    /// Internal callback function for Property geometryReferenceAttribute that gets the GeometryReference definied for this object.
    static COLLADAReferenceAttributeType *getGeometryReferenceAttribute(void *);
private:
    /// Gets the first GeometryRefernce attribute of this object. Only a singe object is returned.
    /// @return The GeometryReferenceAttribut if present, null else
    COLLADAReferenceAttributeType *getGeometryReference();

private:
    /// Reference to the attribute that contains the frame Attribute for this object
    Property<FrameAttributeType *> frameAttribute;
public:
    /// Internal callback function for Property geometryReferenceAttribute that gets the GeometryReference definied for this object.
    static FrameAttributeType *getFrameAttribute(void *);
private:
    /// Initializes the FrameAttriubte internally.
    /// @return
    /// @exception altova::Exception* may throw an exception of this type
    FrameAttributeType *getFrameAttribute();


public:
    /// Merging the content of this RoleRequirement class with the given RoleRequirement class by copying all
    /// attributes and externalinterfaces.
    /// @param classToMergeContentWith
    /// @return
    CAEX_ClassModel_EXPORT RoleRequirementsType *MergeContent(RoleRequirementsType *roleRequirementToMergeContentWith);


    /// Resolving references to ExternalInterfaces that are contained in this class. ExternalInterface with class
    /// references in this class are replaced with instances of the referenced interface classes. There is no need to
    /// recursive call this method, because interface are not allowed to contain sub-interfaces
    /// @param newInternalElement
    CAEX_ClassModel_EXPORT void ResolveExternalInterfaceReferences();


    /// Inserting an element generically to this object.
    /// @param elementToInsert The element to insert
    /// @return True if insertion was successful. False else.
    CAEX_ClassModel_EXPORT bool Insert_Element(TypeBase *elementToInsert);

};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CRoleRequirementsType
