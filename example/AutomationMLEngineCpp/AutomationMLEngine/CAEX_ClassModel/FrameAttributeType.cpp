//
// C++ Implementation: FrameAttributeType
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
#include "FrameAttributeType.h"

namespace CAEX_ClassModel
{

FrameAttributeType::FrameAttributeType(xercesc::DOMNode* const& node)
    : AttributeType(node)
    , Frame(this, NULL, setFrame)
{
}

FrameAttributeType::FrameAttributeType(FrameAttributeType const& other)
    : AttributeType(other)
    , Frame(this, NULL, setFrame)
{
}

void FrameAttributeType::setFrame(void *instance, FrameValues &values)
{
    FrameAttributeType *obj = static_cast<FrameAttributeType *>(instance);

    if (obj)
    {
        values.setParentNode(obj->GetNode());
    }
}

}
