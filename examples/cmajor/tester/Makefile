include ../../Makefile.common

OBJECTS = Main.o

LIBRARIES = ../../../lib/libcmajorast.a ../../../lib/libcmajorlexer.a ../../../lib/libcmajorparser.a \
../../../lib/libsngutil.a ../../../lib/libsnglexer.a ../../../lib/libsngparser.a

%o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
	
ifeq ($(config),debug)
exename=cmajortesterd
else
exename=cmajortester
endif

../../../bin/$(exename): $(OBJECTS) $(LIBRARIES)
	$(CXX) $(CXXFLAGS) -o ../../../bin/$(exename) $(OBJECTS) -lcmajorparser -lcmajorlexer -lcmajorast -lsngparser -lsnglexer -lsngutil -lboost_filesystem -lboost_iostreams -lboost_system
	
clean:
	rm -f *.o
	rm -f ../../bin/$(exename)
