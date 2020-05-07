include Makefile.common

all:
	$(MAKE) -C minilang

clean:
	$(MAKE) -C minilang clean

sources:
	slg -v minilang/Minilang.lexer
	spg -v minilang/MinilangParsers.spg

prefix := /usr/local

install:
	mkdir -p $(prefix)/bin
	cp ../bin/* $(prefix)/bin
