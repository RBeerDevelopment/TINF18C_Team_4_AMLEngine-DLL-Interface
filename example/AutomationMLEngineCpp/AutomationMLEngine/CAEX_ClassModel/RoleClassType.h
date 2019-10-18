#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CRoleClassType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CRoleClassType

#include "type_.CCAEXObject.h"
#include "COLLADAReferenceAttributeType.h"
#include "LogicReferenceAttributeType.h"
#include "FrameAttributeType.h"
#include "IObjectWithAttributes.h"

namespace CAEX_ClassModel
{

class RoleClassType : public CAEXObject, IObjectWithAttributes
{
public:
	CAEX_ClassModel_EXPORT RoleClassType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT RoleClassType(RoleClassType const& init);
	void operator=(RoleClassType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_RoleClassType); }
	MemberAttribute<string_type,_altova_mi_altova_RoleClassType_altova_RefBaseClassPath> RefBaseClassPath;	// RefBaseClassPath Cstring
	MemberElement<AttributeType, _altova_mi_altova_RoleClassType_altova_Attribute> Attribute;
	struct Attribute { typedef Iterator<AttributeType> iterator; };
	MemberElement<ExternalInterfaceType, _altova_mi_altova_RoleClassType_altova_ExternalInterface> ExternalInterface;
	struct ExternalInterface { typedef Iterator<ExternalInterfaceType> iterator; };

    // added

public:
    /// A new attribute is added to this object
    /// @param attributeName The name of the new attribute.
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


private:
    /// Moving externalinterface node to the correct child node position
    /// @param interfaceNode The xml node to insert
    void InsertExternalInterfaceNodeInternal(xercesc::DOMNode *interfaceNode);

public:
    /// Inserting an externalInterface to this class.
    /// @param interfaceElement
    CAEX_ClassModel_EXPORT void Insert_ExternalInterface(InterfaceClassType *interfaceElement);

    /// Adding a new ExternalInterface to this object.
    /// @param name The name of the new ExternalInterface
    /// @return The new ExternalInterface
    /// @note The user is responsible to delete the object the returned pointer is pointing to!
    CAEX_ClassModel_EXPORT InterfaceClassType *New_ExternalInterface(string_type name);


    // TODO Implement getAttributeField()
    /// Getting the attribute collection of this class
    /// @return
    //MemberElement_Attribute *getAttributeField();


public:
    /// Gets and sets the GeometryReference defined for this object
    Property<COLLADAReferenceAttributeType*> geometryReferenceAttribute;
    /// internal getter callback function for geometryReferenceAttribute
    static COLLADAReferenceAttributeType* getGeometryReferenceAttribute(void *instance);

    /// Reference to the attribute that contains the logic reference for this object
    Property<LogicReferenceAttributeType*> logicReferenceAttribute;
    /// internal getter callback function for logicReferenceAttribute
    static LogicReferenceAttributeType* getLogicReferenceAttribute(void *instance);
    // void setLogicReferenceAttribute(LogicReferenceAttributeType *value);

    /// Reference to the attribute that contains the frame attribute for this object
    Property<FrameAttributeType*> frameAttribute;
    /// internal getter callback function for frameAttribute
    static FrameAttributeType* getFrameAttribute(void *instance);
    // void setFrameAttribute(FrameAttributeType *value);

private:
    /// Getting the logic reference attribute of this object. A single attribute of type LogicReferenceAttributeType is returned.
    /// @return The LogicReferenceAttribute of this object, or null if none found
    LogicReferenceAttributeType *getLogicReference();

    /// Gets the first GeometryReference attribute of this object. Only a singe object is returned.
    /// @return The GeometryReferenceAttribut if present, null else
    COLLADAReferenceAttributeType *getGeometryReference();

    /// Initializes the FrameAttriubte internally.
    /// @return the first available FrameAttribute if present, null else
    /// @exception altova::Exception* may throw an exception of this type
    FrameAttributeType *getFrameAttribute();

};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CRoleClassType
