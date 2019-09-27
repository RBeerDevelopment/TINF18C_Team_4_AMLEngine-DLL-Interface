#include "StdAfx.h"
#include "ClassInstantiationException.h"

namespace CAEX_ClassModel
{

    ClassInstantiationException::ClassInstantiationException()
    {
        msg = "Exception reason or message not set!";
    }

    ClassInstantiationException::ClassInstantiationException(string_type message)
    {
        msg = message;
    }

    string_type ClassInstantiationException::what()
    {
        return msg;
    }

}
