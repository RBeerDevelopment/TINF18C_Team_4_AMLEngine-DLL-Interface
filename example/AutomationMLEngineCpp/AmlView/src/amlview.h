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


#ifndef AMLVIEW_H
#define AMLVIEW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QtGui>

#include "treemodel.h"

class QAction;
class QMenu;
class QTextEdit;

class AmlView:public QMainWindow
{
      Q_OBJECT

public:
      AmlView();
      ~AmlView();

protected:
      void closeEvent(QCloseEvent *event);

private slots:
      void open();
      void closeFile();
      void about();

private:
      void createActions();
      void createMenus();
      void createToolBars();
      void createStatusBar();
      void readSettings();
      void writeSettings();
      void loadFile(const QString &fileName);
      void setCurrentFile(const QString &fileName);
      QString strippedName(const QString &fullFileName);

      QString curFile;

      QMenu *fileMenu;
      QMenu *helpMenu;
      QToolBar *fileToolBar;
      QAction *openAct;
      QAction *closeAct;
      QAction *exitAct;
      QAction *aboutAct;
      QAction *aboutQtAct;

      TreeModel *model;
      QTreeView *view;
};

#endif
