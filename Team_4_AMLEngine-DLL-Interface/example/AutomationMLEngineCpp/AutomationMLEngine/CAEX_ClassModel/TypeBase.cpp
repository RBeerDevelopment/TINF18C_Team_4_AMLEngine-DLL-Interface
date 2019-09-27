#include "StdAfx.h"
#include "TypeBase.h"

namespace CAEX_ClassModel
{
    xercesc::DOMNode* TypeBase::GetElementNth(const altova::MemberInfo* member, unsigned index)
    {
        for (XercesTreeOperations::MemberIterator it = XercesTreeOperations::GetElements(m_node, member); it; ++it)
        {
            if (index-- == 0)
                return *it;
        }
        return 0;
    }

    xercesc::DOMNode* TypeBase::GetElementLast(const altova::MemberInfo* member)
    {
        xercesc::DOMNode* p;
        for (XercesTreeOperations::MemberIterator it = XercesTreeOperations::GetElements(m_node, member); it; ++it)
        {
            p = *it;
        }
        return p;
    }

    unsigned TypeBase::CountElement(const altova::MemberInfo* member)
    {
        unsigned count = 0;
        for (XercesTreeOperations::MemberIterator it = XercesTreeOperations::GetElements(m_node, member); it; ++it)
        {
            ++count;
        }
        return count;
    }

    void TypeBase::RemoveElement(const altova::MemberInfo* member)
    {
        XercesTreeOperations::RemoveElements(m_node, member);
    }



}