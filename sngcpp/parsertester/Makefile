include ../Makefile.common

OBJECTS = Main.o

LIBRARIES = ../../lib/libsngcppast.a ../../lib/libsngcpplexer.a ../../lib/libsngcppparser.a ../../lib/libsngcpppp.a ../../lib/libsnglexer.a ../../lib/libsngparser.a \
../../lib/libsngutil.a

%o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

ifeq ($(config),debug)
exename=sngcppparsertesterd
else
exename=sngcppparsertester
endif

../../bin/$(exename): $(OBJECTS) $(LIBRARIES)
	$(CXX) $(CXXFLAGS) -o ../../bin/$(exename) $(OBJECTS) -lsngcpppp -lsngcppparser -lsngcpplexer -lsngcppast -lsngparser -lsnglexer -lsngutil -lboost_filesystem -lboost_iostreams -lboost_system

clean:
	rm -f *.o
	rm -f ../../bin/$(exename)
