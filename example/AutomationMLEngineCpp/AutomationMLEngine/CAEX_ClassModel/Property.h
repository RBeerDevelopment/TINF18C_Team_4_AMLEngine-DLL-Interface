//
// C++ Interface: Property
//
// Description:
//
//
// Author: Christian Simon-Klar <csk@zuehlke,com>, (C) 2009
//
//
//

#ifndef _PROPERTY_H_
#define _PROPERTY_H_

#include <stdlib.h>  // this is only used for having NULL defined

namespace CAEX_ClassModel
{

    /** @class Property A property class
    The property instantiated with class is settable using the assignment operator
    and readable by using the return type operator. Both operator can call a function
    from the instantiating class, function, or program, if the value of the property
    needs to be calculated or generated elsewhere in case of read access or the setting
    of the value has impact on the instantiating class, function, or program. The value
    is also stored inside the property class.
    */
    template <typename CapsuledType>
    class Property
    {

    public:
        typedef const CapsuledType& InType;
        typedef CapsuledType OutType;

    private:
        CapsuledType value;                           ///< local copy of the data of value
        CapsuledType(*ReadCallback)(void *);          ///< pointer to callback function handling read accesses in instantiating class or NULL if handling is not necessary
        void (*WriteCallback)(void *, CapsuledType&); ///< pointer to callback function handling write accesses in instantiating class or NULL if handling is not necessary
        void *instantiatingClass;                     ///< pointer to instantiating class. Not NULL if one of the above callback function is needed.

    public:
        /** default constructor
        Can be used if no handling of read or write accesses in instantiating class is necessary.
        */
        Property() :
                ReadCallback(NULL), WriteCallback(NULL), instantiatingClass(NULL) {}

        /** constructor
        Sets also the callbacks to write or read access handling in instantiating class.
        @param[in] classPointer Pointer to instantiating class itself. Necessary for callback functions.
        @param[in] readFunc Callback function pointer for read access handling. NULL if not needed.
        @param[in] writeFung Callback function pointer for write access handling. NULL if not needed.
        */
        Property(void *classPointer, CapsuledType(*readFunc)(void*), void (*writeFunc)(void*, CapsuledType&)) :
                ReadCallback(readFunc), WriteCallback(writeFunc), instantiatingClass(classPointer) {}

        /** Assignment operator
        */
        void operator=(InType val)
        {
            value = val;

            if ((WriteCallback != NULL) && (instantiatingClass != NULL))
            {
                WriteCallback(instantiatingClass, value);
            }
        }

        /** Return operator
        @return the value of the capsuled data
        */
        operator OutType()
        {
            if ((ReadCallback!=NULL) && (instantiatingClass != NULL))
            {
                value = ReadCallback(instantiatingClass);
            }

            return value;
        }

        /** member pointer operator
        @note this is only usefull for CapsuledType being a pointer, because the capsuled object is returned
        @return the capsuled object
        */
        CapsuledType operator->()
        {
            return value;
        }

        /** assignment operator for Property itself
        */
        void operator=(const Property &prop)
        {
            value=prop.value;
        }
    };

}

#endif // !_PROPERTY_H_
