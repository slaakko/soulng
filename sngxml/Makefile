include Makefile.common

all:
	$(MAKE) -C xml
	$(MAKE) -C dom
	$(MAKE) -C xpath
	$(MAKE) -C tester
	
clean:
	$(MAKE) -C xml clean
	$(MAKE) -C dom clean
	$(MAKE) -C xpath clean
	$(MAKE) -C tester clean

sources:
	spg -v xml/XmlParser.spg
	slg -vn xpath/XPathLexer.lexer
    spg -v xpath/XPathParser.spg

prefix := /usr/local

install:
	mkdir -p $(prefix)/bin
	mkdir -p $(prefix)/lib
	mkdir -p $(prefix)/include/sngxml/xml
	mkdir -p $(prefix)/include/sngxml/dom
	mkdir -p $(prefix)/include/sngxml/xpath
	cp ../bin/* $(prefix)/bin
	cp ../lib/* $(prefix)/lib
	cp xml/*.hpp $(prefix)/include/sngxml/xml
	cp dom/*.hpp $(prefix)/include/sngxml/dom
	cp xpath/*.hpp $(prefix)/include/sngxml/xpath
