include ../Makefile.common

OBJECTS = Algorithm.o CppDeclarationParser.o CppDeclaratorParser.o CppExpressionParser.o CppIdentifierParser.o CppLiteralParser.o CppStatementParser.o Dfa.o Identifier.o \
LexerContext.o LexerFileClassMap.o LexerFileKeywords.o LexerFileLexer.o LexerFileParser.o LexerFileTokens.o Main.o Model.o Nfa.o RegExClassMap.o RegExLexer.o RegExParser.o \
RegExTokens.o RegularExpressionParser.o Symbol.o TokenValueParsers.o Visitor.o

LIBRARIES = ../../lib/libsngcppcode.a ../../lib/libsngutil.a ../../lib/libsnglexer.a ../../lib/libsngparser.a

%o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
	
ifeq ($(config),debug)
exename=slgd
else
exename=slg
endif

../../bin/$(exename): $(OBJECTS) $(LIBRARIES)
	$(CXX) $(CXXFLAGS) -o ../../bin/$(exename) $(OBJECTS) -lsngcppcode -lsngparser -lsnglexer -lsngutil -lboost_filesystem -lboost_iostreams -lboost_system
	
clean:
	rm -f *.o
	rm -f ../../bin/$(exename)
