//
// C++ Implementation: InterfaceClassType
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

namespace CAEX_ClassModel
{

    const string_type InterfaceClassType::COLLADAINTERFACE_TYPE = "AutomationMLInterfaceClassLib/COLLADAInterface";


    InterfaceClassType::InterfaceClassType(xercesc::DOMNode* const& node)
            : CAEXObject(node)
            , RefBaseClassPath(*this)   // "@RefBaseClassPath"
            , Attribute(*this)  // "Attribute"
    {
    }

    InterfaceClassType::InterfaceClassType(InterfaceClassType const& other)
            : CAEXObject(other.GetNode())
            , RefBaseClassPath(*this)   // "@RefBaseClassPath"
            , Attribute(*this)  // "Attribute"
    {
    }

    AttributeType *InterfaceClassType::New_Attribute(string_type attributeName)
    {
        AttributeType *newAttribute = new AttributeType(Attribute.append());
        newAttribute->Name = attributeName;
        return newAttribute;
    }

    void InterfaceClassType::Insert_Attribute(AttributeType *attributeElement)
    {
        //attributes are always appended at the end of a interfaceclass
        GetNode()->appendChild(attributeElement->GetNode());
    }

// TODO implement getAttributeField
//CAEX_ClassModel::MemberElement_Attribute *InterfaceClassType::getAttributeField()
//{
//    return this->Attribute;
//}

    COLLADAReferenceAttributeType* InterfaceClassType::getGeometryReferenceAttribute(void *instance)
    {
        InterfaceClassType *object = static_cast<InterfaceClassType*>(instance);
        return object->getGeometryReference();
    }


    LogicReferenceAttributeType *InterfaceClassType::getLogicReferenceAttribute(void *instance)
    {
        InterfaceClassType *object = static_cast<InterfaceClassType*>(instance);
        return object->getLogicReference();
    }


    FrameAttributeType *InterfaceClassType::getFrameAttribute(void *instance)
    {
        InterfaceClassType *object = static_cast<InterfaceClassType*>(instance);
        return object->getFrameAttribute();
    }


    LogicReferenceAttributeType *InterfaceClassType::getLogicReference()
    {
        LogicReferenceAttributeType *logicReference = 0;

        for (Attribute::iterator attribute = this->Attribute.all(); attribute; ++attribute)
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



    COLLADAReferenceAttributeType *InterfaceClassType::getGeometryReference()
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

    FrameAttributeType *InterfaceClassType::getFrameAttribute()
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

            return frameAttribute;
        }
        catch (Exception *ex)
        {
            throw;
        }
    }

    InterfaceClassType *InterfaceClassType::MergeContent(InterfaceClassType *classToMergeContentWith)
    {

        try
        {
            if (classToMergeContentWith != 0)
            {
                ///copying all child elements of the given element by iterating through each child type and
                ///creating a clone of that child element. Then insert cloned element in this class
                for (Attribute::iterator attributeChild = classToMergeContentWith->Attribute.all(); attributeChild; ++attributeChild)
                {
                    //create copy of base attribute and insert it into clonedclass
                    xercesc::DOMNode *clone = attributeChild->GetNode()->cloneNode(true);
                    this->Insert_Attribute(new AttributeType(clone));
                }
            }
        }
        catch (Exception *ex)
        {
            throw;
        }
        return this;
    }


    COLLADAReferenceAttributeType *InterfaceClassType::getRefCOLLADAInterface()
    {
        return getReferencedCOLLADAAttribute();
    }

    COLLADAReferenceAttributeType *InterfaceClassType::getReferencedCOLLADAAttribute()
    {
        //check if an attribute with name "refCOLLADAInterface" exists
        for (Attribute::iterator attribute = Attribute.all(); attribute; ++attribute)
        {
            if (string_type(attribute->Name).compare(AttributeType::COLLADA_INTERFACE_REFERENCE) == 0)
            {
                return new COLLADAReferenceAttributeType(attribute->GetNode());
            }
        }
        //if no  attribute with name refColladaInterface. return null;
        return 0;
    }

    bool InterfaceClassType::Insert_Element(TypeBase *elementToInsert)
    {
        bool successfullyInserted = true;

        if (dynamic_cast<AttributeType*>(elementToInsert) != 0)
        {
            Insert_Attribute(static_cast<AttributeType*>(elementToInsert));
        }
        else
        {
            successfullyInserted = false;
        }

        return successfullyInserted;
    }

}
