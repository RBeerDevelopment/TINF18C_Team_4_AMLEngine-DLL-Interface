//
// C++ Interface: FrameAttributeType
//
// Description:
//
//
// Author: Christian Simon-Klar <csk@zuehlke.com>, (C) 2009
//
//
//
#ifndef _FRAME_ATTRIBUTE_TYPE_H_
#define _FRAME_ATTRIBUTE_TYPE_H_

#include "AttributeType.h"
#include "FrameValues.h"

namespace CAEX_ClassModel
{

class FrameAttributeType : public AttributeType
{
public:
    CAEX_ClassModel_EXPORT FrameAttributeType(xercesc::DOMNode* const& init);
    CAEX_ClassModel_EXPORT FrameAttributeType(FrameAttributeType const& init);

    Property<FrameValues> Frame;
    /**
    internal Callback functions for Frame to bind the frame values to FrameAttribute
    */
    static void setFrame(void *, FrameValues&);
    //static FrameValues getFrame(void*);
};

}

#endif // _FRAME_ATTRIBUTE_TYPE_H_