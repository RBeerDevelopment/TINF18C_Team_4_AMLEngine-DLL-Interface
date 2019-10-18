#ifndef _IOBJECTWITHATTRIBUTES_H_
#define _IOBJECTWITHATTRIBUTES_H_

#include "type_.CCAEXObject.h"
//#include "COLLADAReferenceAttributeType.h"
//#include "LogicReferenceAttributeType.h"
//#include "FrameAttributeType.h"

namespace CAEX_ClassModel
{

	// forward declaration of AttributeType
class AttributeType;

class IObjectWithAttributes
{

public:
    /// A new attribute is added to this object
    /// @param attributeName The name of the new attribute.
    /// @return The new attribute element
    /// @note The user is responsible to delete the object the returned pointer is pointing to!
    virtual AttributeType *New_Attribute(string_type attributeName) = 0;

public:
    /// Inserting an attribute element to this class
    /// @param attributeElement The attribute to insert
    virtual void Insert_Attribute(AttributeType *attributeElement) = 0;

	// TODO Enable getAttributeField() if all 
    /// Getting the attribute collection of this class
    /// @return
    //virtual std::vector<AttributeType*> *getAttributeField() = 0;


public:
    /// Gets and sets the GeometryReference defined for this object
    //Property<COLLADAReferenceAttributeType*> geometryReferenceAttribute;

    /// Reference to the attribute that contains the logic reference for this object
    //Property<LogicReferenceAttributeType*> logicReferenceAttribute;

    /// Reference to the attribute that contains the frame attribute for this object
    //Property<FrameAttributeType*> frameAttribute;

};


}	// namespace CAEX_ClassModel

#endif // _IOBJECTWITHATTRIBUTES_H_
