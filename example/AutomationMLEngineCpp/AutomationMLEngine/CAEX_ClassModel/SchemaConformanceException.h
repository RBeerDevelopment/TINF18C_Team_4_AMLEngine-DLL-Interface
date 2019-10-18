#include "StdAfx.h"
#include "CAEX_ClassModel_common.h"

namespace CAEX_ClassModel
{
    /// Exception for violations agains the CAEX Schema. An example for a violation is the insertion of more than one
    /// RoleRequirement object into an InternalElement.
    class SchemaConformanceException
    {
    private:
        string_type msg;

    public:
        CAEX_ClassModel_EXPORT SchemaConformanceException();

        CAEX_ClassModel_EXPORT SchemaConformanceException(string_type message);

        CAEX_ClassModel_EXPORT string_type what();
    };
}
