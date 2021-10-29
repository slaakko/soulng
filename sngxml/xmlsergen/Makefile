include ../Makefile.common

OBJECTS = Main.o

LIBRARIES = ../../lib/libsngutil.a ../../lib/libsnglexer.a ../../lib/libsngparser.a ../../lib/libsngcppcode.a \
../../lib/libsngrex.a ../../lib/libsngxmlxml.a ../../lib/libsngxmldom.a ../../lib/libserialization.a

%o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
	
ifeq ($(config),debug)
exename=xmlsergend
else
exename=xmlsergen
endif

../../bin/$(exename): $(OBJECTS) $(LIBRARIES)
	$(CXX) $(CXXFLAGS) -o ../../bin/$(exename) $(OBJECTS) \
-lserialization -lsngxmldom -lsngxmlxml -lsngrex \
-lsngcppcode -lsngparser -lsnglexer -lsngutil \
-lboost_filesystem -lboost_iostreams -lboost_system
	
clean:
	rm -f *.o
	rm -f ../../bin/$(exename)
