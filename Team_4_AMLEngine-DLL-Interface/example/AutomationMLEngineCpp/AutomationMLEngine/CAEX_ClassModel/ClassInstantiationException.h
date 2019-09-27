#include "StdAfx.h"


namespace CAEX_ClassModel
{
    /// User defined exception that is thrown when an error occurs during intantiation of a class.
    class ClassInstantiationException
    {
    private:
        string_type msg;

    public:
        ClassInstantiationException();

        ClassInstantiationException(string_type message);

        string_type what();
    };
}
