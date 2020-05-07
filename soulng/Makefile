include Makefile.common

all:
	$(MAKE) -C util
	$(MAKE) -C lexer
	$(MAKE) -C parser
	$(MAKE) -C cppcode
	$(MAKE) -C rex
	$(MAKE) -C slg
	$(MAKE) -C spg

clean:
	$(MAKE) -C util clean
	$(MAKE) -C lexer clean
	$(MAKE) -C parser clean
	$(MAKE) -C cppcode clean
	$(MAKE) -C rex clean
	$(MAKE) -C slg clean
	$(MAKE) -C spg clean

sources:
	slg -v slg/LexerFileLexer.lexer
	slg -v slg/RegExLexer.lexer
	slg -v rex/RexLexer.lexer
	slg -v spg/ParserFileLexer.lexer
	slg -v spg/ProjectFileLexer.lexer
	spg -v slg/Parsers.spg
	spg -v spg/Parsers.spg
	spg -v rex/RexParser.spg

prefix := /usr/local

install:
	mkdir -p $(prefix)/bin
	mkdir -p $(prefix)/lib
	mkdir -p $(prefix)/include/soulng/lexer
	mkdir -p $(prefix)/include/soulng/parser
	mkdir -p $(prefix)/include/soulng/rex
	mkdir -p $(prefix)/include/soulng/util
	cp ../bin/* $(prefix)/bin
	cp ../lib/* $(prefix)/lib
	cp lexer/*.hpp $(prefix)/include/soulng/lexer
	cp parser/*.hpp $(prefix)/include/soulng/parser
	cp rex/*.hpp $(prefix)/include/soulng/rex
	cp util/*.hpp $(prefix)/include/soulng/util
