include ../Makefile.common

OBJECTS = CppClassMap.o CppKeywords.o CppLexer.o CppTokenLexer.o CppTokenLexerClassMap.o CppTokenLexerKeywords.o CppTokenLexerTokens.o CppTokens.o

%o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
	
../../lib/libsngcpplexer.a: $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $(OBJECTS)

clean:
	rm -f *.o
	rm -f ../../lib/libsngcpplexer.a
