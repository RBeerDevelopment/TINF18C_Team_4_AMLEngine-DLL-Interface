//
// C++ Implementation: FrameValues
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
#include "FrameValues.h"
#include "XercesString.h"

namespace CAEX_ClassModel
{

    FrameValues::FrameValues(xercesc::DOMNode* node)
            : X(this, getX, setX)
            , Y(this, getY, setY)
            , Z(this, getZ, setZ)
            , RX(this, getRX, setRX)
            , RY(this, getRY, setRY)
            , RZ(this, getRZ, setRZ)
            , xAttribute(0)
            , yAttribute(0)
            , zAttribute(0)
            , rxAttribute(0)
            , ryAttribute(0)
            , rzAttribute(0)
            , parentNode(node)
            , savedX(0)
            , savedY(0)
            , savedZ(0)
            , savedRX(0)
            , savedRY(0)
            , savedRZ(0)
    {
    }

    FrameValues::~FrameValues()
    {
        if (xAttribute != 0) delete xAttribute;
        if (yAttribute != 0) delete yAttribute;
        if (zAttribute != 0) delete zAttribute;
        if (rxAttribute != 0) delete rxAttribute;
        if (ryAttribute != 0) delete ryAttribute;
        if (rzAttribute != 0) delete rzAttribute;
    }

    void FrameValues::setParentNode(xercesc::DOMNode * node)
    {
        if (parentNode == 0 && node != 0)
        {
            parentNode = node;

            X  = savedX;
            Y  = savedY;
            Z  = savedZ;
            RX = savedRX;
            RY = savedRY;
            RZ = savedRZ;
        }
    }

    double FrameValues::getAttribute(AttributeType *attr, double value)
    {
        if (attr != 0)
        {
            return CastAs<double>::Do(attr->Value.first().GetNode(), attr->Value.memberInfo());
        }
        else
        {
            return value;
        }
    }

    void FrameValues::setAttribute(AttributeType **attr, double value, string_type name)
    {
        if (*attr == 0)
        {
            if (parentNode == 0)
            {
                return;
            }

            // check if Node with name name is existent
            xercesc::DOMNodeList *childs = parentNode->getChildNodes();
            for (int i = 0; i < childs->getLength(); i++)
            {
                if (name.compare(XercesUnstringTemp(childs->item(i)->getNodeName())) == 0) // TODO check attribute name not tag name
                {
                    (*attr) = new AttributeType(childs->item(i));
                    //(*attr)->Name = name; // TODO maybe setting the name of this aml attribute is not necessary
                    break;
                }
            }

            // if node with name name is not existent add it
            if (*attr == 0)
            {
                xercesc::DOMElement *node = parentNode->getOwnerDocument()->createElement(XercesStringTemp("Attribute"));
                parentNode->appendChild(node);
                (*attr) = new AttributeType(node);
                (*attr)->Name = name;
            }
        }
        altova::XmlFormatter* Formatter = static_cast<altova::XmlFormatter*>(altova::DoubleFormatter);
        (*attr)->setValue(Formatter->Format(value));
    }

    double FrameValues::getX(void *instance)
    {
        FrameValues *obj = static_cast<FrameValues *>(instance);

        if (obj)
        {
            return obj->getAttribute(obj->xAttribute, obj->savedX);
        }

        return 0;
    }

    void FrameValues::setX(void *instance, double &value)
    {
        FrameValues *obj = static_cast<FrameValues *>(instance);

        if (obj)
        {
            obj->savedX = value;
            obj->setAttribute(&(obj->xAttribute), value, AttributeType::X_Name);
        }
    }

    double FrameValues::getY(void *instance)
    {
        FrameValues *obj = static_cast<FrameValues *>(instance);

        if (obj)
        {
            return obj->getAttribute(obj->yAttribute, obj->savedY);
        }

        return 0;
    }

    void FrameValues::setY(void *instance, double &value)
    {
        FrameValues *obj = static_cast<FrameValues *>(instance);

        if (obj)
        {
            obj->savedY = value;
            obj->setAttribute(&(obj->yAttribute), value, AttributeType::Y_Name);
        }
    }

    double FrameValues::getZ(void *instance)
    {
        FrameValues *obj = static_cast<FrameValues *>(instance);

        if (obj)
        {
            return obj->getAttribute(obj->zAttribute, obj->savedZ);
        }

        return 0;
    }

    void FrameValues::setZ(void *instance, double &value)
    {
        FrameValues *obj = static_cast<FrameValues *>(instance);

        if (obj)
        {
            obj->savedZ = value;
            obj->setAttribute(&(obj->zAttribute), value, AttributeType::Z_Name);
        }
    }

    double FrameValues::getRX(void *instance)
    {
        FrameValues *obj = static_cast<FrameValues *>(instance);

        if (obj)
        {
            return obj->getAttribute(obj->rxAttribute, obj->savedRX);
        }

        return 0;
    }

    void FrameValues::setRX(void *instance, double &value)
    {
        FrameValues *obj = static_cast<FrameValues *>(instance);

        if (obj)
        {
            obj->savedRX = value;
            obj->setAttribute(&(obj->rxAttribute), value, AttributeType::RX_Name);
        }
    }

    double FrameValues::getRY(void *instance)
    {
        FrameValues *obj = static_cast<FrameValues *>(instance);

        if (obj)
        {
            return obj->getAttribute(obj->ryAttribute, obj->savedRY);
        }

        return 0;
    }

    void FrameValues::setRY(void *instance, double &value)
    {
        FrameValues *obj = static_cast<FrameValues *>(instance);

        if (obj)
        {
            obj->savedRY = value;
            obj->setAttribute(&(obj->ryAttribute), value, AttributeType::RY_Name);
        }
    }

    double FrameValues::getRZ(void *instance)
    {
        FrameValues *obj = static_cast<FrameValues *>(instance);

        if (obj)
        {
            return obj->getAttribute(obj->rzAttribute, obj->savedRZ);
        }

        return 0;
    }

    void FrameValues::setRZ(void *instance, double &value)
    {
        FrameValues *obj = static_cast<FrameValues *>(instance);

        if (obj)
        {
            obj->savedRZ = value;
            obj->setAttribute(&(obj->rzAttribute), value, AttributeType::RZ_Name);
        }
    }

}
