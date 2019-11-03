include ../Makefile.common

OBJECTS = BoundSourceFile.o ExpressionBinder.o StatementBinder.o TypeBinder.o TypeResolver.o VirtualBinder.o

%o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
	
../../lib/libsngcppbinder.a: $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $(OBJECTS)

clean:
	rm -f *.o
	rm -f ../../lib/libsngcppbinder.a
