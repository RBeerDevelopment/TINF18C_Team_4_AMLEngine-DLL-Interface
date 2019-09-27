//
// C++ Interface: XMLTools
//
// Description:
//
//
// Author: Christian Simon-Klar <csk@zuehlke.com>, (C) 2009
//
//
//
#ifndef _XMLTOOLS_H_
#define _XMLTOOLS_H_

#include "StdAfx.h"
#include "CAEX_ClassModel.h"

namespace CAEX_ClassModel
{

    /// searches the node which has the given path inside the dom structure where node belongs to
    /// The specification of the path is as follows:
    /// - the elements of the path are the xml tag names and are seperated by pathSeperator (usually it is a slash)
    /// - if it starts with double 'pathSeparator' the first node with following tag name path from root of the xml document is returned
    /// - if it starts with a single 'pathSeparator' the node with exact match of path from the root of the xml document is returned
    /// - if it starts with a dot followed by a 'pathSeparator' the node with exact match of path from current node of the xml document is returned
    /// - if it starts with other characters than 'pathSeparator' the node with exact match of path from current node of the xml document is returned
    /// A check of matching attributes is performed by giving the attribute's name and its value to match in the parameters attributeName and attributeValue respectively.
    ///
    /// @param node a node from a dom structure in which an element with given path will be selected
    /// @param path the path of tag names to which a corresponding element will be returned
    /// @param pathSeparator the separator for elements in the path
    /// @param attributeName name of the attribute whose value must match attributeValue. If not provided the attribute check will be skipped
    /// @param attributeValue the value the attributes value must match
    /// @return if a node with the given path is found the node is returned, otherwise 0
    xercesc::DOMNode *selectNode(xercesc::DOMNode *node, string_type path, string_type pathSeparator, string_type attributeName="", string_type attributeValue="");

    /// gets the value of the named attribute of node
    /// @param node the node of which the value of the attribute given by name will be returned
    /// @param name the name of the attribute whose value will be returned
    /// @return the value of the named attribute from node
    string_type getNamedAttributeValue(xercesc::DOMNode *node, string_type name);

    /// returns the name of the node
    /// @param node the node whose name will be returned
    /// @return the name of the node
    string_type getNodeName(xercesc::DOMNode *node);

    /// converts an XMLCh (not implemented)
    //string_type XMLCh2string(const XMLCh *xml);
}

#endif // !_XMLTOOLS_H_