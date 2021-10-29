include ../Makefile.common

OBJECTS = Main.o

LIBRARIES = ../../lib/libsngxmlxml.a ../../lib/libsngxmldom.a ../../lib/libsngxmlxpath.a ../../lib/libsngutil.a \
../../lib/libsnglexer.a

%o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
	
ifeq ($(config),debug)
exename=sngxmltesterd
else
exename=sngxmltester
endif

../../bin/$(exename): $(OBJECTS) $(LIBRARIES)
	$(CXX) $(CXXFLAGS) -o ../../bin/$(exename) $(OBJECTS) \
-lsngxmlxpath -lsngxmldom -lsngxmlxml -lsnglexer -lsngutil -lboost_filesystem -lboost_iostreams -lboost_system
	
clean:
	rm -f *.o
	rm -f ../../bin/$(exename)
