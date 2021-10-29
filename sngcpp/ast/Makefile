include ../Makefile.common

OBJECTS = Class.o Declaration.o Declarator.o Enumeration.o Expression.o Function.o InitDone.o Literal.o \
Namespace.o Node.o Reader.o SimpleType.o Solution.o SourceCodeWriter.o SourceFile.o Specifier.o Statement.o \
Template.o TypeExpr.o Visitor.o Writer.o

%o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
	
../../lib/libsngcppast.a: $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $(OBJECTS)

clean:
	rm -f *.o
	rm -f ../../lib/libsngcppast.a
