include ../Makefile.common

OBJECTS = Comment.o Keyword.o Lexeme.o Lexer.o Span.o Token.o Value.o

%o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
	
../../lib/libsnglexer.a: $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $(OBJECTS)

clean:
	rm -f *.o
	rm -f ../../lib/libsnglexer.a
