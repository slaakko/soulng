include ../Makefile.common

OBJECTS = Evaluator.o File.o InitDone.o PP.o PPClassMap.o PPKeywords.o PPLexer.o PPParser.o PPTokens.o TextClassMap.o TextLexer.o TextTokens.o

%o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
	
../../lib/libsngcpppp.a: $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $(OBJECTS)

clean:
	rm -f *.o
	rm -f ../../lib/libsngcpppp.a
