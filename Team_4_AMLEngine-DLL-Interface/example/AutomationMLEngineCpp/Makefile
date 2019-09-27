# -*- Makefile -*-
# This is the toplevel Makefile for AutomationML

all: xerces-lib aml-engine

xerces-lib:
	cd ./xerces-c-src_2_8_0 && \
	export XERCESCROOT=`pwd` && \
	cd ./src/xercesc/ && \
	echo $$XERCESCROOT && \
	./runConfigure -p linux && \
	make

# in der folgenden Rule ist ein Bugfix in der Zeile mv libtool .... eingebaut: libtool wird erzeugt
# mit der Variable ECHO="echo", allerdings wird nur $echo verwendet. Diesen Fehler korrigiert die
# mv libtool .... Zeile
aml-engine:
	cd ./AutomationMLEngine &&\
	aclocal &&\
	autoheader &&\
	automake &&\
	autoconf &&\
	./configure &&\
	mv libtool libtool.old && sed s/ECHO=/echo=/ libtool.old > libtool && rm libtool.old &&\
	make
