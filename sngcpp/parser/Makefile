include ../Makefile.common

OBJECTS = Class.o Declaration.o Declarator.o Enumeration.o Expression.o Function.o Identifier.o \
Literal.o ParsingContext.o SimpleType.o SourceFile.o SourceLineParser.o Statement.o Template.o \
TokenValueParsers.o TypeExpr.o

%o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
	
../../lib/libsngcppparser.a: $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $(OBJECTS)

clean:
	rm -f *.o
	rm -f ../../lib/libsngcppparser.a
