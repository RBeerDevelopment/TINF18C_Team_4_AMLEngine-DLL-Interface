//
// C++ Implementation: AttributeType
//
// Description:
//
//
// Author: Christian Simon-Klar <csk@zuehlke.com>, (C) 2009
//
//
//
#include "StdAfx.h"
#include "CAEX_ClassModel.h"
#include "SchemaConformanceException.h"
#include "LogicReferenceAttributeType.h"
#include "FrameAttributeType.h"

namespace CAEX_ClassModel
{


    const string_type AttributeType::COLLADA_REFERENCE = "COLLADAReference";
    const string_type AttributeType::COLLADA_INTERFACE_REFERENCE = "refCOLLADAInterface";
    const string_type AttributeType::LOGIC_REFERENCE = "LogicReference";
    const string_type AttributeType::FRAME_NAME = "Frame";
    const string_type AttributeType::X_Name = "x";
    const string_type AttributeType::Y_Name = "y";
    const string_type AttributeType::Z_Name = "z";
    const string_type AttributeType::RX_Name = "rx";
    const string_type AttributeType::RY_Name = "ry";
    const string_type AttributeType::RZ_Name = "rz";


    AttributeType::AttributeType(xercesc::DOMNode* const& node)
            : CAEXObject(node)
            , Unit(*this)   // "@Unit"
            , AttributeDataType(*this)  // "@AttributeDataType"
            , DefaultValue(*this)   // "DefaultValue"
            , Value(*this)  // "Value"
            , RefSemantic(*this)    // "RefSemantic"
            , Constraint(*this) // "Constraint"
            , Attribute(*this)  // "Attribute"
            , geometryReferenceAttribute(this, getGeometryReferenceAttribute, NULL)
            , logicReferenceAttribute(this, getLogicReferenceAttribute, NULL)
            , frameAttribute(this, getFrameAttribute, NULL)
    {
    }

    AttributeType::AttributeType(AttributeType const& other)
            : CAEXObject(other.GetNode())
            , Unit(*this)   // "@Unit"
            , AttributeDataType(*this)  // "@AttributeDataType"
            , DefaultValue(*this)   // "DefaultValue"
            , Value(*this)  // "Value"
            , RefSemantic(*this)    // "RefSemantic"
            , Constraint(*this) // "Constraint"
            , Attribute(*this)  // "Attribute"
            , geometryReferenceAttribute(this, getGeometryReferenceAttribute, NULL)
            , logicReferenceAttribute(this, getLogicReferenceAttribute, NULL)
            , frameAttribute(this, getFrameAttribute, NULL)
    {
    }

    void AttributeType::setValue(string_type value)
    {
        if (Value.exists())
        {
            xs::CanyType v(Value.first());
            v = value;
            Value.first() = v;
        }
        else
        {
            xs::CanyType v(Value.append());
            v = value;
            Value.first() = v;
        }
    }

    string_type AttributeType::getValue()
    {
        if (Value.exists())
        {
            return Value.first();
        }
        else
        {
            return 0;
        }
    }

    void AttributeType::setDefaultValue(string_type value)
    {
        if (DefaultValue.exists())
        {
            xs::CanyType v(DefaultValue.first());
            v = value;
            DefaultValue.first() = v;
        }
        else
        {
            xs::CanyType v(DefaultValue.append());
            v = value;
            DefaultValue.first() = v;
        }
    }

    string_type AttributeType::getDefaultValue()
    {
        if (DefaultValue.exists())
        {
            return DefaultValue.first();
        }
        else
        {
            return 0;
        }
    }

    xs::CanyType *AttributeType::New_DefaultValue()
    {
        if (this->DefaultValue.exists())
        {
            throw SchemaConformanceException("A DefaultValue node is already existent. It is not allowed to add more than one DefaultValue node to current element according to CAEX Schema");
        }
        else
        {

            xercesc::DOMNode *newDefaultValueNode = XercesTreeOperations::CreateElement(GetNode(), DefaultValue.memberInfo());

            xercesc::DOMNode *lastHeaderNode = this->getLastHeaderNode();

            if (lastHeaderNode != 0)
            {
                GetNode()->insertBefore(newDefaultValueNode, lastHeaderNode->getNextSibling());
            }
            else
            {
                GetNode()->insertBefore(newDefaultValueNode, GetNode()->getFirstChild());
            }

            return new xs::CanyType(newDefaultValueNode);
        }
    }

    xs::CanyType *AttributeType::New_Value()
    {
        if (this->Value.exists())
        {
            throw SchemaConformanceException("A Value node is already existent. It is not allowed to add more than one Value node to current element according to CAEX Schema");
        }
        else
        {
            xercesc::DOMNode *newValueNode = XercesTreeOperations::CreateElement(GetNode(), Value.memberInfo());

            if (this->DefaultValue.exists())
            {
                GetNode()->insertBefore(newValueNode, DefaultValue.last().GetNode()->getNextSibling());
            }
            else
            {
                xercesc::DOMNode *lastHeaderNode = this->getLastHeaderNode();

                if (lastHeaderNode != 0)
                {
                    GetNode()->insertBefore(newValueNode, lastHeaderNode->getNextSibling());
                }
                else
                {
                    GetNode()->insertBefore(newValueNode, GetNode()->getFirstChild());
                }
            }
            return new xs::CanyType(newValueNode);
        }
    }

    RefSemanticType *AttributeType::New_RefSemantic(string_type CorrespondingAttributePath)
    {
        xercesc::DOMNode *newRefSemanticNode = XercesTreeOperations::CreateElement(GetNode(), RefSemantic.memberInfo());

        if (this->Constraint.exists())
        {
            GetNode()->insertBefore(newRefSemanticNode, Constraint.first().GetNode());
        }
        else if (this->Attribute.exists())
        {
            GetNode()->insertBefore(newRefSemanticNode, Attribute.first().GetNode());
        }
        else
        {
            GetNode()->appendChild(newRefSemanticNode);
        }
        RefSemanticType *newRefSemantic = new RefSemanticType(newRefSemanticNode);
        newRefSemantic->CorrespondingAttributePath = CorrespondingAttributePath;
        return newRefSemantic;
    }

    OrdinalScaledTypeType *AttributeType::New_OrdinalScaledConstraint(string_type constraintName)
    {
        ///first a constraint node has to be added.
        xercesc::DOMNode *newConstraintNode = XercesTreeOperations::CreateElement(GetNode(), Constraint.memberInfo());

        AttributeValueRequirementType *newConstraint = new AttributeValueRequirementType(newConstraintNode);
        newConstraint->Name = constraintName;

        ///add a ordinalscaled node to the constraint node
        xercesc::DOMNode *newOrdinalScaledNode = XercesTreeOperations::AddElement(newConstraintNode, members + _altova_mi_altova_AttributeValueRequirementType_altova_OrdinalScaledType);


        if (this->Attribute.exists())
        {
            GetNode()->insertBefore(newConstraintNode, Attribute.first().GetNode());
        }
        else
        {
            GetNode()->appendChild(newConstraintNode);
        }
        return new OrdinalScaledTypeType(newOrdinalScaledNode);
    }

    NominalScaledTypeType *AttributeType::New_NominalScaledConstraint(string_type constraintName)
    {
        ///first a constraint node has to be added.
        xercesc::DOMNode *newConstraintNode = XercesTreeOperations::CreateElement(GetNode(), Constraint.memberInfo());

        AttributeValueRequirementType *newConstraint = new AttributeValueRequirementType(newConstraintNode);
        newConstraint->Name = constraintName;

        ///add a ordnialscaled node to the constraint node
        xercesc::DOMNode *newNominalScaledNode = XercesTreeOperations::AddElement(newConstraintNode, members + _altova_mi_altova_AttributeValueRequirementType_altova_NominalScaledType);

        if (this->Attribute.exists())
        {
            GetNode()->insertBefore(newConstraintNode, Attribute.first().GetNode());
        }
        else
        {
            GetNode()->appendChild(newConstraintNode);
        }
        return new NominalScaledTypeType(newNominalScaledNode);
    }

    UnknownTypeType *AttributeType::New_UnknownConstraint(string_type constraintName)
    {
        ///first a constraint node has to be added.
        xercesc::DOMNode *newConstraintNode = XercesTreeOperations::CreateElement(GetNode(), Constraint.memberInfo());

        AttributeValueRequirementType *newConstraint = new AttributeValueRequirementType(newConstraintNode);
        newConstraint->Name = constraintName;

        ///add a ordnialscaled node to the constraint node
        xercesc::DOMNode *newUnknownNode = XercesTreeOperations::AddElement(newConstraintNode, members + _altova_mi_altova_AttributeValueRequirementType_altova_UnknownType);

        if (this->Attribute.exists())
        {
            GetNode()->insertBefore(newConstraintNode, Attribute.first().GetNode());
        }
        else
        {
            GetNode()->appendChild(newConstraintNode);
        }
        return new UnknownTypeType(newUnknownNode);
    }

    AttributeValueRequirementType *AttributeType::New_Constraint(string_type name)
    {
        xercesc::DOMNode *newConstraintNode = XercesTreeOperations::CreateElement(GetNode(), Constraint.memberInfo());

        if (this->Attribute.exists())
        {
            GetNode()->insertBefore(newConstraintNode, Attribute.first().GetNode());
        }
        else
        {
            GetNode()->appendChild(newConstraintNode);
        }
        AttributeValueRequirementType *newConstraint = new AttributeValueRequirementType(newConstraintNode);
        newConstraint->Name = name;
        return newConstraint;

    }

    AttributeType *AttributeType::New_Attribute(string_type name)
    {
        AttributeType *attribute = new AttributeType(Attribute.append());
        attribute->Name = name;
        return attribute;
    }

    void AttributeType::Insert_Attribute(AttributeType *attributeElement)
    {
        GetNode()->appendChild(attributeElement->GetNode());
    }

    bool AttributeType::Insert_Element(TypeBase *elementToInsert)
    {
        bool successfullyInserted = true;

        if (dynamic_cast<AttributeType*>(elementToInsert) != 0)
        {
            Insert_Attribute(static_cast<AttributeType*>(elementToInsert));

        }
        else if (dynamic_cast<RefSemanticType*>(elementToInsert) != 0)
        {
            //TODO: insert refSemantic types
            successfullyInserted = false;
        }
        else
        {
            successfullyInserted = false;
        }

        return successfullyInserted;
    }

//CAEX_ClassModel::MemberElement_Attribute *AttributeType::getAttributeField()
//{
//    return this->Attribute;
//}


    COLLADAReferenceAttributeType* AttributeType::getGeometryReferenceAttribute(void *instance)
    {
        AttributeType *object = static_cast<AttributeType*>(instance);
        return object->getGeometryReference();
    }


    LogicReferenceAttributeType *AttributeType::getLogicReferenceAttribute(void *instance)
    {
        AttributeType *object = static_cast<AttributeType*>(instance);
        return object->getLogicReference();
    }


    FrameAttributeType *AttributeType::getFrameAttribute(void *instance)
    {
        AttributeType *object = static_cast<AttributeType*>(instance);
        return object->getFrameAttribute();
    }

    LogicReferenceAttributeType *AttributeType::getLogicReference()
    {
        LogicReferenceAttributeType *logicReference = 0;

        for (Attribute::iterator attribute = Attribute.all(); attribute; ++attribute)
        {
            if (attribute->Name.exists())
            {
                //an attribute is found with name value set to "LogicReference"
                //this one is returned as geometryReference attribute
                if (string_type(attribute->Name).compare(AttributeType::LOGIC_REFERENCE) == 0)
                {
                    logicReference = new LogicReferenceAttributeType(attribute->GetNode());
                    break;
                }
            }
        }
        logicReferenceAttribute = logicReference;

        return logicReference;
    }

    COLLADAReferenceAttributeType *AttributeType::getGeometryReference()
    {
        COLLADAReferenceAttributeType *geometryReference = 0;

        for (Attribute::iterator attribute = Attribute.all(); attribute; ++attribute)
        {
            if (attribute->Name.exists())
            {
                //an attribute is found with name value set to "GeometryReference"
                //this one is returned as geometryReference attribute
                if (string_type(attribute->Name).compare(AttributeType::COLLADA_REFERENCE) == 0)
                {
                    geometryReference = new COLLADAReferenceAttributeType(attribute->GetNode());
                    break;
                }
            }
        }
        geometryReferenceAttribute = geometryReference;

        return geometryReference;
    }

    FrameAttributeType *AttributeType::getFrameAttribute()
    {
        try
        {
            FrameAttributeType *frameAttributeTemp = 0;

            for (Attribute::iterator attribute = Attribute.all(); attribute; ++attribute)
            {
                if (attribute->Name.exists())
                {
                    //an attribute is found with name value set to "Frame"
                    if (string_type(attribute->Name).compare(AttributeType::FRAME_NAME) == 0)
                    {
                        frameAttributeTemp = new FrameAttributeType(attribute->GetNode());
                        break;
                    }
                }
            }
            frameAttribute = frameAttributeTemp;

            return frameAttributeTemp;
        }
        catch (Exception *ex)
        {
            throw;
        }
    }


} // end of namespace
