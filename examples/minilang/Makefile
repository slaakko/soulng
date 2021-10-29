include ../Makefile.common

OBJECTS = ClassMap.o ConsoleUnicode.o ExpressionParser.o FunctionParser.o IdentifierParser.o \
LiteralParser.o Main.o MinilangKeywords.o MinilangLexer.o MinilangTokens.o PrinterVisitor.o \
SourceFileParser.o StatementParser.o TokenValueParser.o Tree.o TypeParser.o Visitor.o

LIBRARIES = ../../lib/libsngutil.a ../../lib/libsnglexer.a ../../lib/libsngparser.a

%o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
	
ifeq ($(config),debug)
exename=minilangd
else
exename=minilang
endif

../../bin/$(exename): $(OBJECTS) $(LIBRARIES)
	$(CXX) $(CXXFLAGS) -o ../../bin/$(exename) $(OBJECTS) \
-lsngparser -lsnglexer -lsngutil -lboost_filesystem -lboost_iostreams -lboost_system
	
clean:
	rm -f *.o
	rm -f ../../bin/$(exename)
