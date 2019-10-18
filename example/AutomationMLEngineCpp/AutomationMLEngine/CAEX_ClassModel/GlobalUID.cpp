//
// C++ Implementation: GlobalUID
//
// Description:
//
//
// Author: Christian Simon-Klar <csk@zuehlke,com>, (C) 2009
//
//
//

#include "StdAfx.h"
#include "GlobalUID.h"

#include <sstream>

#ifdef _WIN32
#include <rpc.h>
#else
#include <uuid/uuid.h>
#endif

namespace CAEX_ClassModel
{

GlobalUID::GlobalUID()
{
#ifdef _WIN32
    UUID uuid;
    UuidCreate(&uuid);
    bytes[0]=(uuid.Data1>>24)&0xff;
    bytes[1]=(uuid.Data1>>16)&0xff;
    bytes[2]=(uuid.Data1>>8)&0xff;
    bytes[3]=uuid.Data1&0xff;
    bytes[4]=(uuid.Data2>>8)&0xff;
    bytes[5]=uuid.Data2&0xff;
    bytes[6]=(uuid.Data3>>8)&0xff;
    bytes[7]=uuid.Data3&0xff;
    for(int i=0; i<8; i++)
    {
        bytes[8+i]=uuid.Data4[i];
    }
#else
    uuid_generate(bytes);
#endif
}

GlobalUID* GlobalUID::newGuid()
{
    return new GlobalUID;
}

string_type GlobalUID::toString(const string_type format) const
{
#ifdef _WIN32
    UUID uuid;
    uuid.Data1=(bytes[0]<<24) | (bytes[1]<<16) | (bytes[2]<8) | (bytes[3]);
    uuid.Data2=(bytes[4]<<16) | bytes[5];
    uuid.Data3=(bytes[6]<<16) | bytes[7];
    for (int i=0; i<8; i++)
    {
        uuid.Data4[i]=bytes[8+i];
    }
    RPC_CSTR uuid_string;
    UuidToString(&uuid,&uuid_string);
    string_type s((char*)uuid_string);
    RpcStringFree(&uuid_string);

#else
    char str[37];
    uuid_unparse(bytes,str);
    string_type s(str);
#endif

    std::ostringstream ost;
    switch (format[0])
    {
    case 'N':
        // remove the four hyphens in s;
        s.erase(s.find("-"),1);
        s.erase(s.find("-"),1);
        s.erase(s.find("-"),1);
        s.erase(s.find("-"),1);
        ost << s;
        break;
    case 'P':
        ost << "(" << s << ")";
        break;
    case 'B':
        ost << "{" << s << "}";
        break;
    case 'D':
    default:
        ost << s;
    }
    return ost.str();
}


}
