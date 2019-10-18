//
// C++ Interface: COLLADAReferenceAttributeType
//
// Description:
//
//
// Author: Christian Simon-Klar <csk@zuehlke,com>, (C) 2009
//
//
//
#ifndef _COLLADAREFERENCEATTRIBUTETYPE_H_
#define _COLLADAREFERENCEATTRIBUTETYPE_H_

#include "StdAfx.h"
#include "CAEX_ClassModel.h"

namespace CAEX_ClassModel
{

//class AttributeType;

    class COLLADAReferenceAttributeType : public AttributeType
    {
    public:
        CAEX_ClassModel_EXPORT COLLADAReferenceAttributeType(xercesc::DOMNode *init);

        // TODO implement teh following with Property
        /// Gets the pure filepath of this geometry reference attribute without the identifier.
        /// @return the filepath
        string_type getFilePath();

        string_type getReferencedNode();
    private:
        string_type parseReferencedNode();

        string_type parseFileValue();

    };

}
#endif // !_COLLADAREFERENCEATTRIBUTETYPE_H_
