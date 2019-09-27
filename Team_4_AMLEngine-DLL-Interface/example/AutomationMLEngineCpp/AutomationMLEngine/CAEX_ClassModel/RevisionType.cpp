//
// C++ Implementation: RevisionType
//
// Description:
//
//
// Author: Christian Simon-Klar <csk@zuehlke,com>, (C) 2009
//
//
//
#include "StdAfx.h"
#include "CAEX_ClassModel.h"
#include "SchemaConformanceException.h"

namespace CAEX_ClassModel
{


RevisionType::RevisionType(xercesc::DOMNode* const& node)
    : CAEXBasicObject(node)
    , Copyright(*this)  // "Copyright"
    , AdditionalInformation(*this)  // "AdditionalInformation"
    , RevisionDate(*this)   // "RevisionDate"
    , OldVersion(*this) // "OldVersion"
    , NewVersion(*this) // "NewVersion"
    , AuthorName(*this) // "AuthorName"
    , Comment(*this)    // "Comment"
{
}

RevisionType::RevisionType(RevisionType const& other)
    : CAEXBasicObject(other.GetNode())
    , Copyright(*this)  // "Copyright"
    , AdditionalInformation(*this)  // "AdditionalInformation"
    , RevisionDate(*this)   // "RevisionDate"
    , OldVersion(*this) // "OldVersion"
    , NewVersion(*this) // "NewVersion"
    , AuthorName(*this) // "AuthorName"
    , Comment(*this)    // "Comment"
{
}

xs::CstringType *RevisionType::New_OldVersion()
{
    if (OldVersion.exists())
    {
        throw SchemaConformanceException("A oldVersion node is already existent. It is not allowed to add more than one oldVersion nodes to current element according to CAEX Schema");
    }
    else
    {
        xercesc::DOMNode *newOldVersionNode = XercesTreeOperations::CreateElement(GetNode(), members + _altova_mi_altova_RevisionType_altova_OldVersion);
            //insert oldversion node always after revisiondate node to be schema conform
        if (RevisionDate.exists())
        {
            // insertAfter(newOldVersionNode, RevisionDate) :
            GetNode()->insertBefore(newOldVersionNode, RevisionDate.first().GetNode()->getNextSibling());
        }
        else
        {
            // prependChild(newOldVersionNode, GetNode())
            GetNode()->insertBefore(newOldVersionNode,GetNode()->getFirstChild());
        }
        return new xs::CstringType(newOldVersionNode);
    }
}

xs::CstringType *RevisionType::New_NewVersion()
{
    if (NewVersion.exists())
    {
        throw new SchemaConformanceException("A NewVersion node is already existent. It is not allowed to add more than one NewVersion nodes to current element according to CAEX Schema");
    }
    else
    {
        xercesc::DOMNode *newNewVersionNode = XercesTreeOperations::CreateElement(GetNode(), members + _altova_mi_altova_RevisionType_altova_NewVersion);

        if (OldVersion.exists())
        {
            GetNode()->insertBefore(newNewVersionNode, OldVersion.first().GetNode()->getNextSibling());
        }
        else if (RevisionDate.exists())
        {
            GetNode()->insertBefore(newNewVersionNode, RevisionDate.first().GetNode()->getNextSibling());
        }
        else
        {
            GetNode()->insertBefore(newNewVersionNode,GetNode()->getFirstChild());
        }
        return new xs::CstringType(newNewVersionNode);
    }
}

xs::CstringType *RevisionType::New_Comment()
{
        //comment nodes are always at the end of revision child list
    xs::CstringType *comment = new xs::CstringType(Comment.append());
    return comment;
}


}
