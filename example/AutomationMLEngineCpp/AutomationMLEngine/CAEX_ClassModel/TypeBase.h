#ifndef _TYPEBASE_H_
#define _TYPEBASE_H_

#include "CAEX_ClassModel_common.h"
//#include "../Altova/xs-types.h"
//#include "../AltovaXML/Node.h"
//#include "CAEX_ClassModel-typeinfo.h"


namespace CAEX_ClassModel
{
    class TypeBase
    {
    protected:
        xercesc::DOMNode* m_node;
    public:
        TypeBase(xercesc::DOMNode* const& node) : m_node(node) {}
        xercesc::DOMNode* GetNode() const { return m_node; }

        CAEX_ClassModel_EXPORT xercesc::DOMNode* GetElementNth(const altova::MemberInfo* member, unsigned index);
        CAEX_ClassModel_EXPORT xercesc::DOMNode* GetElementLast(const altova::MemberInfo* member);
        CAEX_ClassModel_EXPORT unsigned CountElement(const altova::MemberInfo* member);
        CAEX_ClassModel_EXPORT void RemoveElement(const altova::MemberInfo* member);

        // added
        virtual void makeThisClassPolymorphic() { /* empty */ }

    };
}

#endif // _TYPE_BASE_H
