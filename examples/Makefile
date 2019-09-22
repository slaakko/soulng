include Makefile.common

all:
	$(MAKE) -C cmajor
	$(MAKE) -C minilang

clean:
	$(MAKE) -C cmajor clean
	$(MAKE) -C minilang clean

sources:
	slg -v cmajor/lexer/CmajorLexer.lexer
	slg -v cmajor/lexer/ContainerFileLexer.lexer
	slg -v minilang/Minilang.lexer
	spg -v cmajor/parser/CmajorParsers.spg
	spg -v minilang/MinilangParsers.spg

prefix := /usr/local

install:
	mkdir -p $(prefix)/bin
	cp ../bin/* $(prefix)/bin
