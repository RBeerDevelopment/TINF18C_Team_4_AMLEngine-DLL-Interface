#include "StdAfx.h"
#include "SchemaConformanceException.h"

namespace CAEX_ClassModel
{

    SchemaConformanceException::SchemaConformanceException()
    {
        msg = "Exception reason or message not set!";
    }

    SchemaConformanceException::SchemaConformanceException(string_type message)
    {
        msg = message;
    }

    string_type SchemaConformanceException::what()
    {
        return msg;
    }

}
