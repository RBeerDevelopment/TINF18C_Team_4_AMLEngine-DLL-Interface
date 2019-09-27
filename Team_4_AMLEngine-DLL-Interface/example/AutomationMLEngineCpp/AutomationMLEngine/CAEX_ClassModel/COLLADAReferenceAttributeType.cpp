//
// C++ Implementation: COLLADAReferenceAttributeType
//
// Description:
//
//
// Author: Christian Simon-Klar <csk@zuehlke,com>, (C) 2009
//
//
//
#include "StdAfx.h"
#include "CAEX_ClassModel.h"
#include "COLLADAReferenceAttributeType.h"

namespace CAEX_ClassModel
{

    COLLADAReferenceAttributeType::COLLADAReferenceAttributeType(xercesc::DOMNode *init) : AttributeType(init)
    {

    }

    string_type COLLADAReferenceAttributeType::getFilePath()
    {
        return parseFileValue();
    }

    string_type COLLADAReferenceAttributeType::getReferencedNode()
    {
        return parseReferencedNode();
    }

    string_type COLLADAReferenceAttributeType::parseReferencedNode()
    {

        if (Value.exists() != 0)
        {
            string_type v = Value.first();

            string_type::size_type index = v.find("#");

            if (index != string_type::npos)
            {
                return v.substr(index);
            }
            else
            {
                return 0;
            }
        }
        return 0;

    }

    string_type COLLADAReferenceAttributeType::parseFileValue()
    {
        if (Value.exists() != 0)
        {
            string_type v = Value.first();

            string_type::size_type index = v.find("#");

            if (index != string_type::npos)
            {
                return v.substr(0, index);
            }
            else
            {
                return v;
            }
        }
        return 0;
    }


}
