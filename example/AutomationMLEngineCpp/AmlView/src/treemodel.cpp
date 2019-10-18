/***************************************************************************
 *   Copyright (C) 2009 by Christian Simon-Klar,,,,   *
 *   csk@litu-vm   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/****************************************************************************
 **
 ** Copyright (C) 2005-2008 Trolltech ASA. All rights reserved.
 **
 ** This file is part of the documentation of the Qt Toolkit.
 **
 ** This file may be used under the terms of the GNU General Public
** License versions 2.0 or 3.0 as published by the Free Software
** Foundation and appearing in the files LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file.  Alternatively you may (at
** your option) use any later version of the GNU General Public
** License if such license has been publicly approved by Trolltech ASA
** (or its successors, if any) and the KDE Free Qt Foundation. In
** addition, as a special exception, Trolltech gives you certain
** additional rights. These rights are described in the Trolltech GPL
** Exception version 1.2, which can be found at
** http://www.trolltech.com/products/qt/gplexception/ and in the file
** GPL_EXCEPTION.txt in this package.
**
** Please review the following information to ensure GNU General
** Public Licensing requirements will be met:
** http://trolltech.com/products/qt/licenses/licensing/opensource/. If
** you are unsure which license is appropriate for your use, please
** review the following information:
** http://trolltech.com/products/qt/licenses/licensing/licensingoverview
** or contact the sales department at sales@trolltech.com.
**
** In addition, as a special exception, Trolltech, as the sole
** copyright holder for Qt Designer, grants users of the Qt/Eclipse
** Integration plug-in the right for the Qt/Eclipse Integration to
** link to functionality provided by Qt Designer and its related
** libraries.
**
** This file is provided "AS IS" with NO WARRANTY OF ANY KIND,
** INCLUDING THE WARRANTIES OF DESIGN, MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE. Trolltech reserves all rights not expressly
** granted herein.
 **
 ** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 ** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 **
 ****************************************************************************/

 /*
     treemodel.cpp

     Provides a simple tree model to show how to create and use hierarchical
     models.
 */

#include <QtGui>
#include <QString>

#include <string>

#include <StdAfx.h>
#include <CAEX_ClassModel.h>
#include <CAEXDocument.h>

#include "treeitem.h"
#include "treemodel.h"

 TreeModel::TreeModel()
    : QAbstractItemModel(0)
{
    QList<QVariant> rootData;
    rootData << "Name" << "Values";
    rootItem = new TreeItem(rootData);
}

TreeModel::TreeModel(const QString &data, QObject *parent)
    : QAbstractItemModel(parent)
{
    QList<QVariant> rootData;
    rootData << "Name" << "Values";
    rootItem = new TreeItem(rootData);
    //setupModelData(data.split(QString("\n")), rootItem);
    setupModelCAEXData(data, rootItem);
}

 TreeModel::~TreeModel()
{
    delete rootItem;
}

 int TreeModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return static_cast<TreeItem*>(parent.internalPointer())->columnCount();
    else
        return rootItem->columnCount();
}

 QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    TreeItem *item = static_cast<TreeItem*>(index.internalPointer());

    return item->data(index.column());
}

 Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;

    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

 QVariant TreeModel::headerData(int section, Qt::Orientation orientation,
                                int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}

 QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent)
         const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    TreeItem *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    TreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

 QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    TreeItem *childItem = static_cast<TreeItem*>(index.internalPointer());
    TreeItem *parentItem = childItem->parent();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

 int TreeModel::rowCount(const QModelIndex &parent) const
{
    TreeItem *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    return parentItem->childCount();
}

void TreeModel::setupModelData(const QStringList &lines, TreeItem *parent)
{
    QList<TreeItem*> parents;
    QList<int> indentations;
    parents << parent;
    indentations << 0;

    int number = 0;

    while (number < lines.count()) {
        int position = 0;
        while (position < lines[number].length()) {
            if (lines[number].mid(position, 1) != " ")
                break;
            position++;
        }

        QString lineData = lines[number].mid(position).trimmed();

        if (!lineData.isEmpty()) {
             // Read the column data from the rest of the line.
            QStringList columnStrings = lineData.split("\t", QString::SkipEmptyParts);
            QList<QVariant> columnData;
            for (int column = 0; column < columnStrings.count(); ++column)
                columnData << columnStrings[column];

            if (position > indentations.last()) {
                 // The last child of the current parent is now the new parent
                 // unless the current parent has no children.

                if (parents.last()->childCount() > 0) {
                    parents << parents.last()->child(parents.last()->childCount()-1);
                    indentations << position;
                }
            } else {
                while (position < indentations.last() && parents.count() > 0) {
                    parents.pop_back();
                    indentations.pop_back();
                }
            }

             // Append a new item to the current parent's list of children.
            parents.last()->appendChild(new TreeItem(columnData, parents.last()));
        }

        number++;
    }
}

void printAttributes(xercesc::DOMNamedNodeMap *map)
{
    XMLSize_t i;
    char *tr1, *tr2;
    for (i=0; i<map->getLength(); i++)
    {
        tr1=xercesc::XMLString::transcode(map->item(i)->getNodeName());
        tr2=xercesc::XMLString::transcode(map->item(i)->getNodeValue());
        std::cout << "  Attribute: " << tr1 << " = " << tr2 << std::endl;
        delete tr1;
        delete tr2;
    }
}

void printNodes(xercesc::DOMNode *node)
{
    static int level=0;
    level++;
    char *tr;

    tr=xercesc::XMLString::transcode(node->getNodeName());
    std::cout << level << ": NodeName: " << tr << " Type = " << node->getNodeType() << std::endl;
    delete tr;

    tr=xercesc::XMLString::transcode(node->getNodeValue());
    if(tr!=0 && tr[0]!='\012')
    {
        std::cout << " Value = " << tr << std::endl;
    }
    delete tr;

    if (node->hasAttributes())
    {
        // list all attributes
        xercesc::DOMNamedNodeMap *att=node->getAttributes();
        printAttributes(att);
    }

    if (node->hasChildNodes())
    {
        xercesc::DOMNodeList *ls=node->getChildNodes();
        XMLSize_t i;
        for (i=0; i<ls->getLength(); i++)
        {
            printNodes(ls->item(i));
        }
    }

    level--;
}

void TreeModel::setupModelCAEXData(const QString &fname, TreeItem *parent)
{
    QList<TreeItem*> parents;
    QList<int> indentations;
    parents << parent;
    indentations << 0;

    if (!fname.isEmpty())
    {
        std::cout << fname.toStdString()<<std::endl;
        CAEX_ClassModel::CAEXDocument *doc = CAEX_ClassModel::CAEXDocument::LoadFromFile(fname.toStdString());
        if (doc==NULL) return;
        CAEX_ClassModel::CAEXFileType *file = doc->getCAEXFile();
        if (file==NULL) return;

        xercesc::DOMNode * node=file->GetNode();
        printNodes(node);

                //CountElement(_altova_mi_altova_CAEX_ClassModel_altova_CAEXFile);
        QList<QVariant> columnData;
        columnData << QString("CAEXFile");
        QString str="FileName=\"";
        str.append(std::string(file->FileName).c_str());
        str.append("\" SchemaVersion=");
        str.append(std::string(file->SchemaVersion).c_str());
        columnData << str;

        parents.last()->appendChild(new TreeItem(columnData, parents.last()));
    }
}
