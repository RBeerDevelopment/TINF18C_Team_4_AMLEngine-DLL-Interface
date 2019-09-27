INCLUDES = -I$(top_srcdir)/Altova -I$(top_srcdir)/AltovaXML \
	-I$(top_srcdir)/CAEX_ClassModel -I../../xerces-c-src_2_8_0/src
METASOURCES = AUTO
bin_PROGRAMS = CAEX_ClassModelTest
CAEX_ClassModelTest_SOURCES = CAEX_ClassModelTest.cpp CAEX_ClassModelTest.h \
	Resource.h StdAfx.cpp StdAfx.h testcases.cpp testcases.h
CAEX_ClassModelTest_LDADD = -luuid -L../../xerces-c-src_2_8_0/lib/ -L../Altova \
	-L../AltovaXML -L../CAEX_ClassModel -lAltova -lAltovaXML -lCAEX_ClassModel -lxerces-c
