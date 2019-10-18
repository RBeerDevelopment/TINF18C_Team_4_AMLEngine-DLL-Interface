//
// C++ Interface: LinkedObjects
//
// Description:
//
//
// Author: Christian Simon-Klar <csk@zuehlke.com>, (C) 2009
//
//
//
#ifndef _LINKEDOBJECTS_H_
#define _LINKEDOBJECTS_H_

#include "StdAfx.h"
#include "CAEX_ClassModel.h"
#include "Property.h"
#include "COLLADAReferenceAttributeType.h"

namespace CAEX_ClassModel
{

    /// Class that holds references to the concrete objects that are linked via an InternalLink.
class LinkedObjects
{
public:
    LinkedObjects() { /* empty constructor */ }

    Property<InternalElementType*>   RefPartnerSideAElement;
    Property<ExternalInterfaceType*> RefPartnerSideAExternalInterface;

    Property<InternalElementType*>   RefPartnerSideBElement;
    Property<ExternalInterfaceType*> RefPartnerSideBExternalInterface;

        /// Reference to the referenced COLLADA file of refPartnerSideA if this link references ColladaInterfaces
    Property<COLLADAReferenceAttributeType*> RefPartnerSideACOLLADAReferenceAttribute;
    Property<COLLADAReferenceAttributeType*> RefPartnerSideBCOLLADAReferenceAttribute;

    virtual std::string ToString();
};


} // namespace CAEX_ClassModel

#endif // _LINKEDOBJECTS_H_
