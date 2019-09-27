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


#include <QtGui>
#include "amlview.h"

#include <QTextEdit>
#include <QTextStream>
#include <QCloseEvent>
#include <QFileDialog>

#include <StdAfx.h>
#include <CAEX_ClassModel.h>
#include <CAEXDocument.h>

AmlView::AmlView()
{
      createActions();
      createMenus();
      createToolBars();
      createStatusBar();

      readSettings();

      setCurrentFile("");

      model = new TreeModel("");
      view = new QTreeView();
      view->setModel(model);
      setCentralWidget(view);
      xercesc::XMLPlatformUtils::Initialize();

}

void AmlView::closeEvent(QCloseEvent *event)
{
    closeFile();
    event->accept();
}

void AmlView::open()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty())
    {
        closeFile();
        loadFile(fileName);
    }
}

void AmlView::closeFile()
{
    if(!curFile.isEmpty())
    {
        TreeModel *m=new TreeModel("");
        view->setModel(m);
        if (model) delete model;
        model = m;
    }
    setCurrentFile("");
}

void AmlView::about()
{
      QMessageBox::about(this, tr("About Application"),
            tr("The <b>Application</b> example demonstrates how to "
                  "write modern GUI applications using Qt, with a menu bar, "
                  "toolbars, and a status bar."));
}

void AmlView::createActions()
{
      openAct = new QAction(QIcon(":/fileopen.xpm"), tr("&Open..."), this);
      openAct->setShortcut(tr("Ctrl+O"));
      openAct->setStatusTip(tr("Open an existing file"));
      connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

      closeAct = new QAction(tr("C&lose"), this);
      closeAct->setShortcut(tr("Ctrl+W"));
      closeAct->setStatusTip(tr("Close currently opened file"));
      connect(closeAct, SIGNAL(triggered()), this, SLOT(closeFile()));

      exitAct = new QAction(tr("E&xit"), this);
      exitAct->setShortcut(tr("Ctrl+Q"));
      exitAct->setStatusTip(tr("Exit the application"));
      connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

      aboutAct = new QAction(tr("&About"), this);
      aboutAct->setStatusTip(tr("Show the application's About box"));
      connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

      aboutQtAct = new QAction(tr("About &Qt"), this);
      aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
      connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void AmlView::createMenus()
{
      fileMenu = menuBar()->addMenu(tr("&File"));
      fileMenu->addAction(openAct);
      fileMenu->addAction(closeAct);
      fileMenu->addSeparator();
      fileMenu->addAction(exitAct);

      menuBar()->addSeparator();

      helpMenu = menuBar()->addMenu(tr("&Help"));
      helpMenu->addAction(aboutAct);
      helpMenu->addAction(aboutQtAct);
}

void AmlView::createToolBars()
{
      fileToolBar = addToolBar(tr("File"));
      fileToolBar->addAction(openAct);
}

void AmlView::createStatusBar()
{
      statusBar()->showMessage(tr("Ready"));
}

void AmlView::readSettings()
{
      QSettings settings("Trolltech", "Application Example");
      QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
      QSize size = settings.value("size", QSize(400, 400)).toSize();
      resize(size);
      move(pos);
}

void AmlView::writeSettings()
{
      QSettings settings("Trolltech", "Application Example");
      settings.setValue("pos", pos());
      settings.setValue("size", size());
}

void AmlView::loadFile(const QString &fileName)
{
      QFile file(fileName);
      if (!file.open(QFile::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, tr("Application"),
                              tr("Cannot read file %1:\n%2.")
                              .arg(fileName)
                              .arg(file.errorString()));
            return;
      }

      QTextStream in(&file);
      QApplication::setOverrideCursor(Qt::WaitCursor);
      TreeModel *m = new TreeModel(fileName);
      view->setModel(m);
      if(model) delete model;
      model = m;
      QApplication::restoreOverrideCursor();

      setCurrentFile(fileName);
      statusBar()->showMessage(tr("File loaded"), 2000);
}

void AmlView::setCurrentFile(const QString &fileName)
{
      curFile = fileName;
      setWindowModified(false);

      QString shownName;
      if (curFile.isEmpty())
            shownName = "untitled.txt";
      else
            shownName = strippedName(curFile);

      setWindowTitle(tr("%1[*] - %2").arg(shownName).arg(tr("Application")));
}

QString AmlView::strippedName(const QString &fullFileName)
{
      return QFileInfo(fullFileName).fileName();
}

AmlView::~AmlView()
{
      xercesc::XMLPlatformUtils::Terminate();
}

