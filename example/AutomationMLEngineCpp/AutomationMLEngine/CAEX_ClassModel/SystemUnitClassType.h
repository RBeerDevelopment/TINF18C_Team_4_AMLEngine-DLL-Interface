#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CSystemUnitClassType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CSystemUnitClassType

#include "type_.CCAEXObject.h"
#include "Property.h"
#include "COLLADAReferenceAttributeType.h"
#include "LogicReferenceAttributeType.h"
#include "FrameAttributeType.h"
#include <xercesc/util/XMLUri.hpp>
#include "IObjectWithAttributes.h"

namespace CAEX_ClassModel
{

class SystemUnitClassType : public CAEXObject, IObjectWithAttributes
{
public:
	CAEX_ClassModel_EXPORT SystemUnitClassType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT SystemUnitClassType(SystemUnitClassType const& init);
	void operator=(SystemUnitClassType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_SystemUnitClassType); }
	MemberElement<AttributeType, _altova_mi_altova_SystemUnitClassType_altova_Attribute> Attribute;
	struct Attribute { typedef Iterator<AttributeType> iterator; };
	MemberElement<InterfaceClassType, _altova_mi_altova_SystemUnitClassType_altova_ExternalInterface> ExternalInterface;
	struct ExternalInterface { typedef Iterator<InterfaceClassType> iterator; };
	MemberElement<InternalElementType, _altova_mi_altova_SystemUnitClassType_altova_InternalElement> InternalElement;
	struct InternalElement { typedef Iterator<InternalElementType> iterator; };
	MemberElement<SupportedRoleClassType, _altova_mi_altova_SystemUnitClassType_altova_SupportedRoleClass> SupportedRoleClass;
	struct SupportedRoleClass { typedef Iterator<SupportedRoleClassType> iterator; };
	MemberElement<InternalLinkType, _altova_mi_altova_SystemUnitClassType_altova_InternalLink> InternalLink;
	struct InternalLink { typedef Iterator<InternalLinkType> iterator; };

    // added
    /// Gets and sets the GeometryReference defined for this object
    Property<COLLADAReferenceAttributeType*> geometryReferenceAttribute;
    /// internal getter function for geometryReferenceAttribute
    static COLLADAReferenceAttributeType* getGeometryReferenceAttribute(void *instance);

    /// Reference to the attribute that contains the logic reference for this object
    Property<LogicReferenceAttributeType*> logicReferenceAttribute;
    /// internal getter function for logicReferenceAttribute
    static LogicReferenceAttributeType* getLogicReferenceAttribute(void *instance);
    // void setLogicReferenceAttribute(LogicReferenceAttributeType *value);

    /// Reference to the attribute that contains the frame attribute for this object
    Property<FrameAttributeType*> frameAttribute;
    /// internal getter function for frameAttribute
    static FrameAttributeType* getFrameAttribute(void *instance);
    // void setFrameAttribute(FrameAttributeType *value);


private:
    /// Inserting an Attribute node internally
    /// @param attributeNode the attribute node to insert
    void InsertAttributeNodeInternal(xercesc::DOMNode *attributeNode);

public:
    /// A new attribute is added to this object
    /// @param AttributeName The name of the new attribute.
    /// @return The new attribute element
    CAEX_ClassModel_EXPORT AttributeType *New_Attribute(string_type attributeName);

    /// Inserting an attribute element to this class
    /// @param attributeElement The attribute to insert
    CAEX_ClassModel_EXPORT void Insert_Attribute(AttributeType *attributeElement);



    /// Add a new logic reference attribute to this SystemUnitClass.
    /// @param uri The URI of the reference
    /// @return A new logic reference attribute
    CAEX_ClassModel_EXPORT LogicReferenceAttributeType *New_LogicReference(xercesc::XMLUri *uri);


    /// Adding a new GeometryReference attribute to this object.
    /// @param uri The URI of the reference
    /// @return A new attribute
    CAEX_ClassModel_EXPORT COLLADAReferenceAttributeType *New_COLLADAReference(xercesc::XMLUri *uri);


    /// Creates a new frame attribute for this object. Position information is internally stored in more than one CAEX attribute.
    /// @param frameValues
    /// @return
    CAEX_ClassModel_EXPORT FrameAttributeType *New_FrameAttribute(FrameValues *frameValues);


    /// Adding a new ExternalInterface to this object.
    /// @param name The name of the new ExternalInterface
    /// @return The new ExternalInterface
    CAEX_ClassModel_EXPORT InterfaceClassType *New_ExternalInterface(string_type name);

private:
    /// Inserting an ExternalInterface node at the correct child position of this node according to CAEX Schema.
    /// @param internalElementNode The InternalElement node to insert.
    void InsertExternalInterfaceNodeInternal(xercesc::DOMNode *externalInterfaceElementNode);


public:
    /// Adding a new InternalElement to this object.
    /// @param name The name of the new InternalElement
    /// @return The new InternalElement
    CAEX_ClassModel_EXPORT InternalElementType *New_InternalElement(string_type name);

private:
    /// Inserting an InternalElement node at the correct child position of this node according to CAEX Schema.
    /// @param internalElementNode The InternalElement node to insert.
    void InsertInternalElementNodeInternal(xercesc::DOMNode *internalElementNode);

public:
    /// Adding an InternalElement to this object. Remark: When inserting the same object at different positions, it is only inserted at
    /// the last desired position. If you want to insert the same element more than once, you have to create a clone copy of the object.
    /// @param internalElement The InternalElement to insert.
    CAEX_ClassModel_EXPORT void Insert_InternalElement(InternalElementType *internalElement);

    /// Inserting an externalInterface to this class.
    /// @param interfaceElement
    CAEX_ClassModel_EXPORT void Insert_ExternalInterface(InterfaceClassType *interfaceElement);


    /// Inserting a new class instance to this object. This method can be overriden in derived classes
    /// @param newInstanceObject The instance of a class to be inserted at this object. The instance can be of type
    /// InternelElementType, InterfaceClassType
    /// @return True if insertion was successful, else false.
    CAEX_ClassModel_EXPORT virtual bool Insert_NewInstance(TypeBase *newInstanceObject);

private:
    /// Inserting an supportedroleclass at the correct child node position
    /// @param newSupportedRoleClassNode
    void InsertSupportedRoleClassNodeInternal(xercesc::DOMNode *newSupportedRoleClassNode);

public:
    CAEX_ClassModel_EXPORT void Insert_SupportedRoleClass(SupportedRoleClassType *supportedRoleClassElement);

    /// Adding a new SupportedRoleClass to this object.
    /// @param refencedRoleClassPath The path to the role class that is referenced
    /// @return The new SupportedRoleClass
    CAEX_ClassModel_EXPORT SupportedRoleClassType *New_SupportedRoleClass(string_type refencedRoleClassPath);

private:
    /// Inserting an internalLink node at the correct child node position.
    /// @param newInternalLinkNode
    void InsertInternalLinkNodeInternal(xercesc::DOMNode *newInternalLinkNode);

public:
    /// Inserting an internal link to this class
    /// @param internalLink The internal link to insert
    CAEX_ClassModel_EXPORT void Insert_InternalLink(InternalLinkType *internalLinkElement);


    /// Adding a new InternalLink to this object.
    /// @param name The name of the InternalLink
    /// @return The new InternalLink element
    CAEX_ClassModel_EXPORT InternalLinkType *New_InternalLink(string_type name);


private:
    /// Getting the logic reference attribute of this object. A single attribute of type LogicReferenceAttributeType is returned.
    /// @return The LogicReferenceAttribute of this object, or null if non found
    LogicReferenceAttributeType *getLogicReference();


    /// Gets the first GeometryReference attribute of this object. Only a singe object is returned.
    /// @return The GeometryReferenceAttribut if present, null else
    COLLADAReferenceAttributeType *getGeometryReference();

    /// Initializes the FrameAttriubte internally.
    /// @return
    FrameAttributeType *getFrameAttribute();


public:
    //MemberElement_Attribute *getAttributeField(); // TODO implement getAttributeField

};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CSystemUnitClassType
