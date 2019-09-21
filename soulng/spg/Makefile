include ../Makefile.common

OBJECTS = CodeEvaluationVisitor.o CodeGeneratorVisitor.o CodeModifyVisitor.o CppDeclarationParser.o CppDeclaratorParser.o CppExpressionParser.o CppIdentifierParser.o \
CppLiteralParser.o CppStatementParser.o Domain.o LinkerVisitor.o Main.o NonterminalInfo.o Parser.o ParserFile.o ParserFileClassMap.o ParserFileKeywords.o ParserFileLexer.o \
ParserFileParser.o ParserFileTokens.o ProjectFile.o ProjectFileClassMap.o ProjectFileKeywords.o ProjectFileLexer.o ProjectFileParser.o ProjectFileTokens.o TokenValueParsers.o \
Visitor.o

LIBRARIES = ../../lib/libsngcppcode.a ../../lib/libsngutil.a ../../lib/libsnglexer.a ../../lib/libsngparser.a

%o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
	
ifeq ($(config),debug)
exename=spgd
else
exename=spg
endif

../../bin/$(exename): $(OBJECTS) $(LIBRARIES)
	$(CXX) $(CXXFLAGS) -o ../../bin/$(exename) $(OBJECTS) -lsngcppcode -lsngparser -lsnglexer -lsngutil -lboost_filesystem -lboost_iostreams -lboost_system
	
clean:
	rm -f *.o
	rm -f ../../bin/$(exename)
