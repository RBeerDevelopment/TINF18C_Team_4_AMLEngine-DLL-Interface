#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CInterfaceClassType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CInterfaceClassType

#include "type_.CCAEXObject.h"
#include "Property.h"
#include "COLLADAReferenceAttributeType.h"
#include "LogicReferenceAttributeType.h"
#include "FrameAttributeType.h"
#include "IObjectWithAttributes.h"

namespace CAEX_ClassModel
{

class FrameAttributeType; // TODO Remove this if implemented
class FrameValues; // TODO Remove this if implemented

class InterfaceClassType : public CAEXObject, IObjectWithAttributes
{
public:
	CAEX_ClassModel_EXPORT InterfaceClassType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT InterfaceClassType(InterfaceClassType const& init);
	void operator=(InterfaceClassType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_InterfaceClassType); }
	MemberAttribute<string_type,_altova_mi_altova_InterfaceClassType_altova_RefBaseClassPath> RefBaseClassPath;	// RefBaseClassPath Cstring
	MemberElement<AttributeType, _altova_mi_altova_InterfaceClassType_altova_Attribute> Attribute;
	struct Attribute { typedef Iterator<AttributeType> iterator; };

    // added
public:
    static const string_type COLLADAINTERFACE_TYPE;

    /// A new attribute is created and returned.
    /// @param AttributeName The name of the new attribute.
    /// @return The new attribute element
    /// @note user is responsible to free returned object after use
    CAEX_ClassModel_EXPORT AttributeType *New_Attribute(string_type attributeName);

    /// Inserting an attribute element to this class
    /// @param attributeElement The attribute to insert
    CAEX_ClassModel_EXPORT void Insert_Attribute(AttributeType *attributeElement);


    // TODO implement getAttributeField
    /// Getting this Attributes collection
    /// @return
    //MemberElement_Attribute *getAttributeField();



public:
    /// Reference to the attribute that contains the logic reference for this object
    Property<LogicReferenceAttributeType *> logicReferenceAttribute;
    static LogicReferenceAttributeType *getLogicReferenceAttribute(void*);
    //void setLogicReferenceAttribute(LogicReferenceAttributeType *value);
private:
    /// Getting the logic reference attribute of this object. A single attribute of type LogicReferenceAttributeType is returned.
    /// @return The LogicReferenceAttribute of this object, or null if non found
    LogicReferenceAttributeType *getLogicReference();

public:
    Property<COLLADAReferenceAttributeType *> geometryReferenceAttribute;
    /// Gets and sets the GeometryReference definied for this object.
    static COLLADAReferenceAttributeType *getGeometryReferenceAttribute(void*);
    //void setGeometryReferenceAttribute(COLLADAReferenceAttributeType *value);
private:
    /// Gets the first GeometryRefernce attribute of this object. Only a singe object is returned.
    /// @return The GeometryReferenceAttribut if present, null else
    COLLADAReferenceAttributeType *getGeometryReference();

public:
    Property<FrameAttributeType *> frameAttribute;
    static FrameAttributeType *getFrameAttribute(void*);
    //void setFrameAttribute(FrameAttributeType *value);
private:
    /// Initializes the FrameAttriubte internally.
    /// @return
    /// @exception Exception
    FrameAttributeType *getFrameAttribute();



public:
    /// Merging the content of this interface class with the given interface class by copying all
    /// attributes.
    /// @param classToMergeContentWith
    /// @return
    /// @exception Exception
    CAEX_ClassModel_EXPORT InterfaceClassType *MergeContent(InterfaceClassType *classToMergeContentWith);


public:
    /// Does the same as getReferencedCOLLADAAttribute.
    /// @return
    /// @note user is responsible to free returned object after use
    CAEX_ClassModel_EXPORT COLLADAReferenceAttributeType *getRefCOLLADAInterface();

private:
    /// Getting the COLLADAReference attribute if this interface is of type COLLADAInterface
    /// @return The COLLADAReference attribute
    /// @note user is responsible to free returned object after use
    COLLADAReferenceAttributeType *getReferencedCOLLADAAttribute();

public:
    /// Inserting an element generically to this object.
    /// @param elementToInsert
    /// @return
    CAEX_ClassModel_EXPORT bool Insert_Element(TypeBase *elementToInsert);

};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CInterfaceClassType
