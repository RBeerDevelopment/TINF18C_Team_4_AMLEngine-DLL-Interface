//
// C++ Implementation: InternalLinkType
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


namespace CAEX_ClassModel
{

    const string_type InternalLinkType::LINK_SEPARATOR = ":";

    InternalLinkType::InternalLinkType(xercesc::DOMNode* const& node)
            : CAEXObject(node)
            , RefPartnerSideA(*this)    // "@RefPartnerSideA"
            , RefPartnerSideB(*this)    // "@RefPartnerSideB"
    {
    }

    InternalLinkType::InternalLinkType(InternalLinkType const& other)
            : CAEXObject(other.GetNode())
            , RefPartnerSideA(*this)    // "@RefPartnerSideA"
            , RefPartnerSideB(*this)    // "@RefPartnerSideB"
    {
    }

    bool InternalLinkType::IsValidLink()
    {
        LinkedObjects *linkedObj = this->ResolveLink();
        //this->setLinkedObjects(linkedObj);
        string_type errorString("");

        bool sideAElementPresent = true;
        bool sideAExternalInterfacePresent = true;

        bool sideBElementPresent = true;
        bool sideBExternalInterfacePresent = true;

        if (linkedObj != 0)
        {
            if (linkedObj->RefPartnerSideAElement == 0)
            {
                errorString = "Link side A is not valid.";
                sideAElementPresent = false;
            }
            if (linkedObj->RefPartnerSideAExternalInterface == 0)
            {
                errorString = errorString + " Referenced Interface of side A is not valid.";
                sideAExternalInterfacePresent = false;
            }
            //if internal element and external interface of link side a exists check if link is inside a combined
            //kinematic. but only if the external interface is of type colladaInterface
            if (sideAElementPresent && sideAExternalInterfacePresent)
            {

                if (linkedObj->RefPartnerSideAExternalInterface->RefBaseClassPath.exists())
                {
                    if (string_type(linkedObj->RefPartnerSideAExternalInterface->RefBaseClassPath).compare(InterfaceClassType::COLLADAINTERFACE_TYPE)==0)
                    {
                        bool isInKinematik = linkedObj->RefPartnerSideAElement->IsPartOfCombinedKinematik();
                        if (isInKinematik)
                        {
                            errorString = errorString + " Referenced side A is part of a combined kinematic.";
                        }
                    }

                }
            }

            if (linkedObj->RefPartnerSideBElement == 0)
            {
                errorString = errorString + " Link side B is not valid.";
                sideBElementPresent = false;
            }

            if (linkedObj->RefPartnerSideBExternalInterface == 0)
            {
                errorString = errorString + " Referenced Interface of side B is not valid.";
                sideBExternalInterfacePresent = false;
            }
            if (sideBElementPresent && sideBExternalInterfacePresent)
            {

                if (linkedObj->RefPartnerSideBExternalInterface->RefBaseClassPath.exists())
                {
                    if (string_type(linkedObj->RefPartnerSideBExternalInterface->RefBaseClassPath).compare(InterfaceClassType::COLLADAINTERFACE_TYPE)==0)
                    {

                        bool isInKinematik = linkedObj->RefPartnerSideBElement->IsPartOfCombinedKinematik();
                        if (isInKinematik)
                        {
                            errorString = errorString + " Referenced side B is part of a combined kinematic.";
                        }
                    }
                }
            }
        }
        else
        {
            errorString = errorString + " Could not resolve link";
        }
        validationErrorText = errorString;

        if (((string_type)validationErrorText).empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    LinkedObjects *InternalLinkType::ResolveLink()
    {
        try
        {
            if (RefPartnerSideA.exists() && RefPartnerSideB.exists())
            {
                LinkedObjects *linkedObjects = new LinkedObjects();

                string_type guidRefA = getReferencedGUID(RefPartnerSideA);
                string_type guidRefB = getReferencedGUID(RefPartnerSideB);

                InternalElementType *refA = this->findInternalElement(guidRefA);
                InternalElementType *refB = this->findInternalElement(guidRefB);
                linkedObjects->RefPartnerSideAElement = refA;
                linkedObjects->RefPartnerSideBElement = refB;
                if (refA != 0)
                {
                    string_type interfaceNameRefA = this->getReferencedInterfaceName(this->RefPartnerSideA);

                    ExternalInterfaceType *externalInterfaceA = refA->findExternalInterface(interfaceNameRefA);
                    if (externalInterfaceA != 0)
                    {
                        linkedObjects->RefPartnerSideAExternalInterface = externalInterfaceA;
                        //check if it is an colladainterface
                        if (externalInterfaceA->RefBaseClassPath.exists())
                        {
                            if (((string_type)externalInterfaceA->RefBaseClassPath).compare(InterfaceClassType::COLLADAINTERFACE_TYPE) == 0)
                            {
                                //get referenced collada attribute
                                linkedObjects->RefPartnerSideACOLLADAReferenceAttribute = externalInterfaceA->getRefCOLLADAInterface();
                            }
                        }
                    }
                }
                if (refB != 0)
                {
                    string_type interfaceNameRefB = this->getReferencedInterfaceName(this->RefPartnerSideB);

                    ExternalInterfaceType *externalInterfaceB = refB->findExternalInterface(interfaceNameRefB);
                    if (externalInterfaceB != 0)
                    {
                        linkedObjects->RefPartnerSideBExternalInterface = externalInterfaceB;
                        //check if it is an colladainterface
                        if (externalInterfaceB->RefBaseClassPath.exists())
                        {
                            if (((string_type)externalInterfaceB->RefBaseClassPath).compare(InterfaceClassType::COLLADAINTERFACE_TYPE) == 0)
                            {
                                //get referenced collada attribute
                                linkedObjects->RefPartnerSideBCOLLADAReferenceAttribute = externalInterfaceB->getRefCOLLADAInterface();
                            }
                        }
                    }
                }

                return linkedObjects;

            }
            else
            {
                return 0;
            }
        }
        catch (Exception *ex)
        {
            throw;
        }
    }

}
