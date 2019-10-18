#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CAttributeType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CAttributeType

#include "type_.CCAEXObject.h"
#include "type_xs.CanyType.h"
#include "Property.h"
//#include "COLLADAReferenceAttributeType.h"
#include "IObjectWithAttributes.h"

namespace CAEX_ClassModel
{

class LogicReferenceAttributeType; // TODO Remove this if implemented
class FrameAttributeType; // TODO Remove this if implemented

// forward declaration
class COLLADAReferenceAttributeType;
//class IObjectWithAttributes;

class AttributeType : public CAEXObject, IObjectWithAttributes
{
public:
	CAEX_ClassModel_EXPORT AttributeType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT AttributeType(AttributeType const& init);
	void operator=(AttributeType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_AttributeType); }
	MemberAttribute<string_type,_altova_mi_altova_AttributeType_altova_Unit> Unit;	// Unit Cstring
	MemberAttribute<string_type,_altova_mi_altova_AttributeType_altova_AttributeDataType> AttributeDataType;	// AttributeDataType CAttributeDataTypeType
	MemberElement<xs::CanyType, _altova_mi_altova_AttributeType_altova_DefaultValue> DefaultValue;
	struct DefaultValue { typedef Iterator<xs::CanyType> iterator; };
	MemberElement<xs::CanyType, _altova_mi_altova_AttributeType_altova_Value> Value;
	struct Value { typedef Iterator<xs::CanyType> iterator; };
	MemberElement<RefSemanticType, _altova_mi_altova_AttributeType_altova_RefSemantic> RefSemantic;
	struct RefSemantic { typedef Iterator<RefSemanticType> iterator; };
	MemberElement<AttributeValueRequirementType, _altova_mi_altova_AttributeType_altova_Constraint> Constraint;
	struct Constraint { typedef Iterator<AttributeValueRequirementType> iterator; };
	MemberElement<AttributeType, _altova_mi_altova_AttributeType_altova_Attribute> Attribute;
	struct Attribute { typedef Iterator<AttributeType> iterator; };

    // added
    /// sets the value of Value
    /// @param value the value to assign to Value
    void setValue(string_type value);
    /// gets the value of Value
    /// @return the value assigned to Value
    string_type getValue();

    /// sets the value of DefaultValue
    /// @param value the value to assign to DefaultValue
    void setDefaultValue(string_type value);
    /// gets the value of DefaultValue
    /// @return the value assigned to DefaultValue
    string_type getDefaultValue();

    static const string_type COLLADA_REFERENCE;
    static const string_type COLLADA_INTERFACE_REFERENCE;
    static const string_type LOGIC_REFERENCE;
    static const string_type FRAME_NAME;
    static const string_type X_Name;
    static const string_type Y_Name;
    static const string_type Z_Name;
    static const string_type RX_Name;
    static const string_type RY_Name;
    static const string_type RZ_Name;

    /// A new DefaultValue is added to this attribute.
    /// @return The new DefaultValue element
    /// @note The user is responsible to delete the object the returned pointer references!
    /// @exception SchemaConformanceException element is already existent
    CAEX_ClassModel_EXPORT xs::CanyType *New_DefaultValue();

    /// Add a new Value element to this attribute.
    /// @return The new Value element.
    /// @note The user is responsible to delete the object the returned pointer references!
    /// @exception SchemaConformanceException element is already existent
    CAEX_ClassModel_EXPORT xs::CanyType *New_Value();

    /// Adding a new RefSemantic node to this attribute.
    /// @param CorrespondingAttributePath The corresponding attribute path for the semantic reference
    /// @return The new RefSemantic element.
    /// @note The user is responsible to delete the object the returned pointer references!
    CAEX_ClassModel_EXPORT RefSemanticType *New_RefSemantic(string_type CorrespondingAttributePath);

    /// A new ordinal scaled constraint is added to this attribute.
    /// @param ConstraintName The name of this constraint
    /// @return A new ordinal scaled constraint
    /// @note The user is responsible to delete the object the returned pointer references!
    CAEX_ClassModel_EXPORT OrdinalScaledTypeType *New_OrdinalScaledConstraint(string_type constraintName);


    /// A new nominal scaled constraint is added to this attribute.
    /// @param ConstraintName The name of this constraint
    /// @return A new nominal scaled constraint
    /// @note The user is responsible to delete the object the returned pointer references!
    CAEX_ClassModel_EXPORT NominalScaledTypeType *New_NominalScaledConstraint(string_type constraintName);

    /// A new unknown constraint is added to this attribute.
    /// @param ConstraintName The name of this constraint
    /// @return A new unknown constraint
    /// @note The user is responsible to delete the object the returned pointer references!
    CAEX_ClassModel_EXPORT UnknownTypeType *New_UnknownConstraint(string_type constraintName);

    /// Adding a Constraint node to this attribute. Use this method with caution. A constraint node has to be further specified by one of the three types:
    /// OrdinalScaledType, NominalScaledType or UnknownType. You can use the appropriate methods New_OrdinalScaledConstraint, New_NominalScaledConstraint or New_UnknownConstraint to
    /// add a constraint with the desired type in one step.
    /// If you forget to add a type to this constraint you will be no more conform to the schema!
    /// @param name The name of the constraint
    /// @return The new constraint node
    /// @note The user is responsible to delete the object the returned pointer references!
    CAEX_ClassModel_EXPORT AttributeValueRequirementType *New_Constraint(string_type name);

    /// Adding a new attribute child node to this attribute.
    /// @param name The name of the new attribute
    /// @return The new attribute
    /// @note The user is responsible to delete the object the returned pointer references!
    CAEX_ClassModel_EXPORT AttributeType *New_Attribute(string_type name);

    /// Inserting an attribute element to this class
    /// @param attributeElement The attribute to insert
    CAEX_ClassModel_EXPORT void Insert_Attribute(AttributeType *attributeElement);

    /// Inserting an element generically to this object.
    /// @param elementToInsert
    /// @return true on success and false on failure
    CAEX_ClassModel_EXPORT bool Insert_Element(TypeBase *elementToInsert);

    //MemberElement_Attribute *getAttributeField(); // TODO implement getAttributeField


    //#pragma region IObjectWithAttributes Members


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
    /// Getting the logic reference attribute of this object. A single attribute of type LogicReferenceAttributeType is returned.
    /// @return The LogicReferenceAttribute of this object, or null if non found
    LogicReferenceAttributeType *getLogicReference();


    /// Gets the first GeometryReference attribute of this object. Only a singe object is returned.
    /// @return The GeometryReferenceAttribut if present, null else
    COLLADAReferenceAttributeType *getGeometryReference();

    /// Initializes the FrameAttriubte internally.
    /// @return
    FrameAttributeType *getFrameAttribute();

};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CAttributeType
