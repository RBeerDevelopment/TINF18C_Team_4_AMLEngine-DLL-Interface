#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CSystemUnitClassLibType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CSystemUnitClassLibType

#include "type_.CCAEXObject.h"


namespace CAEX_ClassModel
{

    class SystemUnitClassLibType : public CAEXObject
    {
    public:
        CAEX_ClassModel_EXPORT SystemUnitClassLibType(xercesc::DOMNode* const& init);
        CAEX_ClassModel_EXPORT SystemUnitClassLibType(SystemUnitClassLibType const& init);
        void operator=(SystemUnitClassLibType const& other)
        {
            m_node = other.m_node;
        }
        static altova::meta::ComplexType StaticInfo()
        {
            return altova::meta::ComplexType(types + _altova_ti_altova_SystemUnitClassLibType);
        }
        MemberElement<SystemUnitFamilyType, _altova_mi_altova_SystemUnitClassLibType_altova_SystemUnitClass> SystemUnitClass;
        struct SystemUnitClass
        {
            typedef Iterator<SystemUnitFamilyType> iterator;
        };

        // added
        /// Adding a new SystemUnitClass to this hierarchy.
        /// @param name The name of the new SystemUnitClass
        /// @note The user is responsible to delete the object the returned pointer references!
        /// @return A new SystemUnitClass with type SystemUnitFamilyType!
        CAEX_ClassModel_EXPORT SystemUnitFamilyType *New_SystemUnitClass(string_type name);

        /// Insert a SystemUnitClass to this class library
        /// @param systemUnitClass The SystemUnitClass to insert
        CAEX_ClassModel_EXPORT void Insert_SystemUnitClass(SystemUnitFamilyType *systemUnitClass);

        /// Inserting an element generically to this object.
        /// @param elementToInsert
        /// @return true on success and false on failure
        CAEX_ClassModel_EXPORT bool Insert_Element(TypeBase *elementToInsert);

    };


} // namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CSystemUnitClassLibType
