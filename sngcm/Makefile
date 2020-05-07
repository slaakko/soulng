include Makefile.common

all:
	$(MAKE) -C ast
	$(MAKE) -C cmlexer
	$(MAKE) -C cmparser
	$(MAKE) -C tester
	
clean:
	$(MAKE) -C ast clean
	$(MAKE) -C cmlexer clean
	$(MAKE) -C cmparser clean
	$(MAKE) -C tester clean

sources:
	slg -v cmlexer/CmajorLexer.lexer
	slg -v cmlexer/ContainerFileLexer.lexer
	slg -v cmlexer/LexerFileTokenLexer.lexer
	slg -v cmlexer/ParserFileTokenLexer.lexer
	slg -v cmlexer/TokenLexer.lexer
	spg -v cmparser/CmajorParsers.spg

prefix := /usr/local

install:
	mkdir -p $(prefix)/bin
	mkdir -p $(prefix)/lib
	mkdir -p $(prefix)/include/sngcm/ast
	mkdir -p $(prefix)/include/sngcm/cmlexer
	mkdir -p $(prefix)/include/sngcm/cmparser
	cp ../bin/* $(prefix)/bin
	cp ../lib/* $(prefix)/lib
	cp ast/*.hpp $(prefix)/include/sngcm/ast
	cp cmlexer/*.hpp $(prefix)/include/sngcm/cmlexer
	cp cmparser/*.hpp $(prefix)/include/sngcm/cmparser
