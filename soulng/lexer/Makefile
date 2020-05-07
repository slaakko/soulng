include ../Makefile.common

OBJECTS = Keyword.o Lexeme.o Lexer.o ParsingException.o ParsingLog.o Span.o Token.o TrivialLexer.o XmlParsingLog.o

%o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
	
../../lib/libsnglexer.a: $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $(OBJECTS)

clean:
	rm -f *.o
	rm -f ../../lib/libsnglexer.a
