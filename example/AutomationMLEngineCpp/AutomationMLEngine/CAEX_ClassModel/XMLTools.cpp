//
// C++ Implementation: XMLTools
//
// Description:
//
//
// Author: Christian Simon-Klar <csk@zuehlke.com>, (C) 2009
//
//
//
#include "StdAfx.h"
#include "CAEX_ClassModel.h"
#include "XMLTools.h"
#include <string>

namespace CAEX_ClassModel
{

xercesc::DOMNode *selectNode(xercesc::DOMNode *node, string_type path, string_type pathSeparator, string_type attributeName, string_type attributeValue)
    {
        xercesc::DOMNodeList* nodeList = 0;
        XMLCh *xmlPath;
        string_type prefix;

        // Fall path = "//N1[/...]":
        prefix.clear();
        prefix.append(pathSeparator).append(pathSeparator);
        if (path.find(prefix)==0)
        {
            // "//" prefix found
            // erase prefix from path
            path.erase(0,prefix.size());

            if (path.empty())
            {
                return selectNode(node, pathSeparator, pathSeparator, attributeName, attributeValue);
            }

            // get first element of path
            string_type::size_type index = path.find(pathSeparator);
            if (index==string_type::npos) index=path.size();
            string_type subpath = path.substr(0, index);

            // finde alle Elemente im Tree deren Tagname == subpath ist
            xmlPath = xercesc::XMLString::transcode(subpath.c_str());
            nodeList=node->getOwnerDocument()->getElementsByTagName(xmlPath);
            xercesc::XMLString::release(&xmlPath);

            if (nodeList != 0) // sanity check
            {
                // iteriere ueber liste bis ein passender Node gefunden wurde
                xercesc::DOMNode *returnNode = 0;
                int i = 0;
                while (i < nodeList->getLength() && returnNode == 0)
                {
                    // recursive call
                    returnNode = selectNode(nodeList->item(i), path, pathSeparator, attributeName, attributeValue);
                }
                return returnNode;
            }

            // falls kein passender Node gefunden wurde gebe null zurueck
            return 0;
        }

        // Fall path = "./N1[/...]"
        prefix.clear();
        prefix.append(".").append(pathSeparator);
        if (path.find(prefix)==0)
        {
            // "//" prefix found
            // erase prefix from path
            path.erase(0,prefix.size());
            // finde alle Child Nodes von node
            nodeList = node->getChildNodes();
        }

        // Fall path = "/N1[/...]"
        prefix.clear();
        prefix.append(pathSeparator);
        if (path.find(prefix)==0)
        {
            // "//" prefix found
            // erase prefix from path
            path.erase(0,prefix.size());
            // finde alle Child Nodes vom Root Node
            xmlPath = xercesc::XMLString::transcode("*");
            nodeList=node->getOwnerDocument()->getElementsByTagName(xmlPath);
            xercesc::XMLString::release(&xmlPath);
        }

        // fuer Fall path = "./N1[/...]" und path = "/N1[/...]"
        if (nodeList!=0)
        {
            // iteriere ueber liste aller Child Nodes vom current bzw. root Node
            xercesc::DOMNode *resultNode;
            for (int i=0; i<nodeList->getLength(); i++)
            {
                resultNode = selectNode(nodeList->item(i), path, pathSeparator, attributeName, attributeValue);
                if (resultNode!=0) return resultNode;
            }
            return 0;
        }


        // Fall path = "N1[/...]":
        if (path.find(pathSeparator) != string_type::npos)
        {
            // pathSeparator wurde in path gefunden --> hierarchies

            // extrahiere fuehrenden Pfadteil und loesche ihn aus path
            string_type::size_type index = path.find(pathSeparator);
            string_type subpath = path.substr(0, index);
            path.erase(0, index+1);

            string_type nodeName = getNodeName(node);
            if (nodeName.compare(subpath)==0)
            {
                nodeList = node->getChildNodes();
                xercesc::DOMNode *resultNode;
                for (int i=0; i<nodeList->getLength(); i++)
                {
                    resultNode = selectNode(nodeList->item(i), path, pathSeparator, attributeName, attributeValue);
                    if (resultNode!=0) return resultNode;
                }
                return 0;
            }
        }
        else
        {
            // pathSeparator wurde nicht in path gefunden --> direkter element name

            // wenn path nicht leer, vergleiche path mit Tagname vom Knoten
            if (!path.empty())
            {
                if (getNodeName(node).compare(path)!=0)
                {
                    // falls Tagname nicht passt, Knoten nicht gefunden
                    return 0;
                }
            }
            // zusaetzliche Pruefung auf attribute uebereinstimmung
            // falls attributeName not empty dann vergleiche jeweils den attributeValue von attributeName
            if ( !attributeName.empty() )
            {
                if (getNamedAttributeValue(node,attributeName).compare(attributeValue)!=0)
                {
                    // falls Atribut mit Name attributeName nicht den Wert attributeValue hat dann nicht gefunden
                    return 0;
                }
            }
            return node;
        }

        return 0;
    }


string_type getNamedAttributeValue(xercesc::DOMNode *node, string_type name)
{
    // convert attribute name
    XMLCh *attributeName=xercesc::XMLString::transcode(name.c_str());

    // convert named attribute value
    char *value=0;
    if (node->getAttributes()!=0)
    {
        if (node->getAttributes()->getNamedItem(attributeName) != 0)
        {
            try
            {
                value = xercesc::XMLString::transcode(node->getAttributes()->getNamedItem(attributeName)->getNodeValue());
                // getNodeValue throws an exception when node is readonly
            }
            catch (xercesc::DOMException)
            {
            }
        }
    }

    // release temporaries
    xercesc::XMLString::release(&attributeName);

    if (value!=0)
    {
        // copy it to return string
        string_type returnValue(value);

        // release temporaries
        xercesc::XMLString::release(&value);

        return returnValue;
    }

    return string_type();
}


string_type getNodeName(xercesc::DOMNode *node)
{
    // convert node name
    char *name=xercesc::XMLString::transcode(node->getNodeName());

    // copy it to return string
    string_type returnName(name);

    // release temporary
    xercesc::XMLString::release(&name);

    return returnName;
}


}
