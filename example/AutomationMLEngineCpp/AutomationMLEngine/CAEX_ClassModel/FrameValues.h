//
// C++ Interface: FrameValues
//
// Description:
//
//
// Author: Christian Simon-Klar <csk@zuehlke.com>, (C) 2009
//
//
//
#ifndef _FRAME_VALUES_H_
#define _FRAME_VALUES_H_

#include "StdAfx.h"
#include "CAEX_ClassModel.h"
#include "Property.h"

namespace CAEX_ClassModel
{

class FrameValues
{
public:
    CAEX_ClassModel_EXPORT FrameValues(xercesc::DOMNode *node=0);
    CAEX_ClassModel_EXPORT ~FrameValues();

    void setParentNode(xercesc::DOMNode* node);

public:
    Property<double> X;
    Property<double> Y;
    Property<double> Z;
    Property<double> RX;
    Property<double> RY;
    Property<double> RZ;

private:
    AttributeType *xAttribute;
    AttributeType *yAttribute;
    AttributeType *zAttribute;
    AttributeType *rxAttribute;
    AttributeType *ryAttribute;
    AttributeType *rzAttribute;

    double savedX;
    double savedY;
    double savedZ;
    double savedRX;
    double savedRY;
    double savedRZ;

    xercesc::DOMNode *parentNode;

    double getAttribute(AttributeType *, double);
    void setAttribute(AttributeType **, double, string_type);

public:
    static void setX(void *, double&);
    static void setY(void *, double&);
    static void setZ(void *, double&);
    static void setRX(void *, double&);
    static void setRY(void *, double&);
    static void setRZ(void *, double&);
    static double getX(void *);
    static double getY(void *);
    static double getZ(void *);
    static double getRX(void *);
    static double getRY(void *);
    static double getRZ(void *);
};

}

#endif // _FRAME_VALUES_H_
