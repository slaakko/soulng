include Makefile.common

all:
	$(MAKE) -C util
	$(MAKE) -C lexer
	$(MAKE) -C parser
	$(MAKE) -C cppcode
	$(MAKE) -C slg
	$(MAKE) -C spg

clean:
	$(MAKE) -C util clean
	$(MAKE) -C lexer clean
	$(MAKE) -C parser clean
	$(MAKE) -C cppcode clean
	$(MAKE) -C slg clean
	$(MAKE) -C spg clean

install:
	mkdir -p $(prefix)/bin
	mkdir -p $(prefix)/lib
	mkdir -p $(prefix)/include/soulng/lexer
	mkdir -p $(prefix)/include/soulng/parser
	cp ../bin/* $(prefix)/bin
	cp ../lib/* $(prefix)/lib
	cp lexer/*.hpp $(prefix)/include/soulng/lexer
	cp parser/*.hpp $(prefix)/include/soulng/parser
