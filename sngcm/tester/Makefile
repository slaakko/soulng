include ../Makefile.common

OBJECTS = Main.o

LIBRARIES = ../../lib/libsngcmast.a ../../lib/libsngcmcmlexer.a ../../lib/libsngcmcmparser.a \
../../lib/libsngutil.a ../../lib/libsngcppcode.a ../../lib/libsnglexer.a ../../lib/libsngparser.a ../../lib/libsngrex.a

%o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
	
ifeq ($(config),debug)
exename=sngcmtesterd
else
exename=sngcmtester
endif

../../bin/$(exename): $(OBJECTS) $(LIBRARIES)
	$(CXX) $(CXXFLAGS) -o ../../bin/$(exename) $(OBJECTS) -lsngcmcmparser -lsngcmcmlexer -lsngcmast -lsngrex -lsngparser -lsnglexer -lsngcppcode -lsngutil -lboost_filesystem -lboost_iostreams -lboost_system
	
clean:
	rm -f *.o
	rm -f ../../bin/$(exename)
