include Makefile.common

all:
	$(MAKE) -C ast
	$(MAKE) -C binder
	$(MAKE) -C lexer
	$(MAKE) -C parser
	$(MAKE) -C parsertester
	$(MAKE) -C pp
	$(MAKE) -C pptester
	$(MAKE) -C symbols

clean:
	$(MAKE) -C ast clean
	$(MAKE) -C binder clean
	$(MAKE) -C lexer clean
	$(MAKE) -C parser clean
	$(MAKE) -C parsertester clean
	$(MAKE) -C pp clean
	$(MAKE) -C pptester clean
	$(MAKE) -C symbols clean

sources:
	slg -v lexer/CppLexer.lexer
	slg -v lexer/CppTokenLexer.lexer
	spg -v parser/CppParsers.spg
	slg -v pp/PPLexer.lexer
	spg -v pp/PPParser.spg
	slg -v pp/TextLexer.lexer

prefix := /usr/local

install:
	mkdir -p $(prefix)/bin
	mkdir -p $(prefix)/lib
	mkdir -p $(prefix)/include/sngcpp/ast
	mkdir -p $(prefix)/include/sngcpp/binder
	mkdir -p $(prefix)/include/sngcpp/lexer
	mkdir -p $(prefix)/include/sngcpp/parser
	mkdir -p $(prefix)/include/sngcpp/pp
	mkdir -p $(prefix)/include/sngcpp/symbols
	cp ../bin/* $(prefix)/bin
	cp ../lib/* $(prefix)/lib
	cp ast/*.hpp $(prefix)/include/sngcpp/ast
	cp binder/*.hpp $(prefix)/include/sngcpp/binder
	cp lexer/*.hpp $(prefix)/include/sngcpp/lexer
	cp parser/*.hpp $(prefix)/include/sngcpp/parser
	cp pp/*.hpp $(prefix)/include/sngcpp/pp
	cp symbols/*.hpp $(prefix)/include/sngcpp/symbols
