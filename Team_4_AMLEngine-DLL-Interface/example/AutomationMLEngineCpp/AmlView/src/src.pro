SOURCES += amlview.cpp \
           main.cpp \
 treeitem.cpp \
 treemodel.cpp
HEADERS += amlview.h \
 treeitem.h \
 treemodel.h
TEMPLATE = app
CONFIG += warn_on \
	  thread \
          qt
TARGET = amlview
DESTDIR = ../bin
RESOURCES = application.qrc
LIBS += -L/home/csk/work/automationml/cpp/src/xerces-c-src_2_8_0/lib \
  -L/home/csk/work/automationml/cpp/src/AutomationMLEngine/AltovaXML \
  -L/home/csk/work/automationml/cpp/src/AutomationMLEngine/Altova \
  -L/home/csk/work/automationml/cpp/src/AutomationMLEngine/CAEX_ClassModel \
  -lxerces-c \
  -lAltovaXML \
  -lAltova \
  -lCAEX_ClassModel

INCLUDEPATH += /home/csk/work/automationml/cpp/src/AutomationMLEngine/CAEX_ClassModel

