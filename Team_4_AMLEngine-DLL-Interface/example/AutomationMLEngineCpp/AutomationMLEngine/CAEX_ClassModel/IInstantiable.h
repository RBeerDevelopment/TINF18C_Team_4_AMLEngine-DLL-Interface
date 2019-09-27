#ifndef _IINSTANTIABLE_H_
#define _IINSTANTIABLE_H_


namespace CAEX_ClassModel
{

class IInstantiable
{
public:
    /// Creates an instance of this class and returns the instance as a new InternalElement.
    /// @return An instance of this class as a new InternalElement
    virtual TypeBase *CreateClassInstance() = 0;
};


}	// namespace CAEX_ClassModel

#endif // _INSTANTIABLE_H_
