include ../Makefile.common

OBJECTS = ClassTemplateSpecializationSymbol.o ClassTypeSymbol.o ContainerSymbol.o \
DeclarationBlockSymbol.o DerivedTypeSymbol.o EnumerationSymbol.o ExternalTypeSymbol.o \
FunctionSymbol.o GrammarSymbol.o IntegerLiteralTypeSymbol.o LambdaExpressionSymbol.o \
NamespaceSymbol.o ParameterSymbol.o RuleSymbol.o Scope.o SimpleTypeSymbol.o Symbol.o \
SymbolCreator.o SymbolTable.o TemplateSymbol.o TypeSymbol.o TypedefSymbol.o VariableSymbol.o

%o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
	
../../lib/libsngcppsymbols.a: $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $(OBJECTS)

clean:
	rm -f *.o
	rm -f ../../lib/libsngcppsymbols.a
